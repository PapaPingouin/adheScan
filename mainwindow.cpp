#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //QSound::play( "/tmp/bip.wav");

    adhAttenteAssocBadge = 0;

    ui->setupUi(this);
    initBDD();

    startupSync();

   // bip = new QSound( "/tmp/bip.wav" );

}

void MainWindow::initBDD()
{
    bool ok;

    bip = new QMediaPlayer();
    bip->setMedia(QUrl::fromLocalFile("/var/adheScan/bip.mp3"));
    bip->setVolume(100);

    bop = new QMediaPlayer();
    bop->setMedia(QUrl::fromLocalFile("/var/adheScan/bop.mp3"));
    bop->setVolume(100);

    QSqlDatabase::addDatabase("QMYSQL","online");
    onlineDB = QSqlDatabase::database( "online", false );
    //onlineDB = new QSqlDatabase();
    //onlineDB->addDatabase("QMYSQL","online");
    onlineDB.setHostName( "yoda2.golhum.com" );
    onlineDB.setPort( 336 );
    onlineDB.setDatabaseName( "MCMS_Danceornothing" );
    onlineDB.setUserName( "adheScan" );
    onlineDB.setPassword( "vUnbvYXMCZQRGKQy" );
    ok = onlineDB.open();

    if( !ok )
    {
        onlineMode = ONLINE_OFF;
        ui->debugText->append( localDB.lastError().text( ) );
        ui->debugText->append("online database not connect");
    }
    else
    {
        onlineMode = ONLINE_ON;
        ui->debugText->append("online database connect OK");
    }

//onlineMode = ONLINE_OFF;

    QSqlDatabase::addDatabase("QSQLITE","local");
    localDB = QSqlDatabase::database( "local", false );
    localDB.setDatabaseName( "/var/adheScan/adheScan.sqlite" );
    if( !localDB.isValid() ) QMessageBox::critical(0, QString::fromUtf8( "Erreur Base de Donnée" ),localDB.lastError().text( ) , QMessageBox::Ok);
    ok = localDB.open();

    if( !ok )
    {
        QMessageBox::critical(0, QString::fromUtf8( "Erreur Base de Donnée" ),localDB.lastError().text( ) , QMessageBox::Ok);
        exit( -1 );
    }


    QSqlQuery query( localDB);
    if( !query.exec("PRAGMA encoding = 'UTF-16';") )
    {
        QMessageBox::critical(0, QString::fromUtf8("PB SQLite UTF16."), localDB.lastError().text( ) , QMessageBox::Ok);
    }

    if( !query.exec("SELECT * FROM `badges` LIMIT 5" ) )
    {
        int ret = QMessageBox::critical(0, QString::fromUtf8( "Erreur Base de Donnée" ),
                              QString::fromUtf8("La base de donnée ne semble pas correctement initialisée.\n"
                                 "Cliquez sur OK pour la réinitialiser.\n "
                                 "Vous ne pouvez pas continuer sans initialiser ...") , QMessageBox::Reset | QMessageBox::Abort);
        if( ret == QMessageBox::Reset )
           initBDDSQLite();
        else
           exit( -1 );
    }
    query.clear();

    refreshStatusBar();
}

void MainWindow::initBDDSQLite()
{
    QSqlQuery query( localDB );
    QSqlError erreur;
    QString sql ;

    sql = "CREATE TABLE IF NOT EXISTS `badges` ("
            "`badge_id` TEXT PRIMARY KEY,"
            "`adh_id` INTEGER,"
            "`insertDate` TEXT,"
            "`toSync` INTEGER"
          ");";
    if( !query.exec( sql ) )
    {
        QMessageBox::critical(0, QString::fromUtf8( "Erreur Base de Donnée" ), QString::fromUtf8("La réinitialisation à échouée : \n ")+ query.lastError().databaseText() , QMessageBox::Ok);
        exit( -1 );
    }

    sql = "CREATE TABLE IF NOT EXISTS `adherents` ("
            "`adh_id` INTEGER PRIMARY KEY,"
            "`nom` TEXT,"
            "`prenom` TEXT"
          ");";
    if( !query.exec( sql ) )
    {
        QMessageBox::critical(0, QString::fromUtf8( "Erreur Base de Donnée" ), QString::fromUtf8("La réinitialisation à échouée : \n ")+ query.lastError().databaseText() , QMessageBox::Ok);
        exit( -1 );
    }

    sql = "CREATE TABLE IF NOT EXISTS `logscans` ("
            "`log_id` INTEGER PRIMARY KEY ASC,"
            "`badge_id` INTEGER,"
            "`adh_id` INTEGER,"
            "`time` TEXT,"
            "`toSync` INTEGER"
          ");";
    if( !query.exec( sql ) )
    {
        QMessageBox::critical(0, QString::fromUtf8( "Erreur Base de Donnée" ), QString::fromUtf8("La réinitialisation à échouée : \n ")+ query.lastError().databaseText() , QMessageBox::Ok);
        exit( -1 );
    }


    query.clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshStatusBar()
{
    ui->statusBar->showMessage( "TEST" );
    ui->debugText->append( "TEST" );
}

void MainWindow::on_actionQuitter_triggered()
{
    exit(0);
}

void MainWindow::receive(const QString &str)
{
    //printf("message reçu\n");
   // ui->labeltest->setText( str );
    //ui->statusBar->showMessage( str );
    ui->debugText->append( str );

    int adh_id;

    adh_id = getAdhIdFromBadge( str );

    ui->debugText->append( "adhFromBadge : "+QString::number(adh_id) );

    if( adh_id )
    {
        displayLoggingName( adh_id );
        logScan( adh_id, str );


    }
    else
    {
        bop->play();
        ui->debugText->append( "adh non trouvé : attente badge = "+QString::number(adhAttenteAssocBadge) );
        if( adhAttenteAssocBadge )
        {
            assocBadge( str );
        }
    }

}

void MainWindow::displayLoggingName( int adh_id )
{
    QSqlQuery localQuery( localDB );
    QString sql;

    if( localQuery.exec("SELECT * FROM adherents WHERE adh_id="+QString::number(adh_id)+"") )
    {
        //int nameCol = localQuery.record().indexOf("nom");
        int prenCol = localQuery.record().indexOf("prenom");
        localQuery.next();

        bip->play();

        ui->labelNameChecked->setText( "Bienvenue "+localQuery.value( prenCol ).toString() );

    }

}

int MainWindow::getAdhIdFromBadge( QString str )
{
    QSqlQuery localQuery( localDB );
    QString sql;
    int adh_id=0;

    if( localQuery.exec("SELECT * FROM badges WHERE badge_id='"+str+"'") )
    {
        int idCol = localQuery.record().indexOf("adh_id");
        if( localQuery.next() )
            adh_id = localQuery.value( idCol ).toString().toInt();
    }
    return adh_id;
}
QString MainWindow::getBadgeIdFromAdh( int adh_id )
{
    QSqlQuery localQuery( localDB );
    QString sql;
    QString badge_id="";

    if( localQuery.exec("SELECT * FROM badges WHERE adh_id='"+QString::number(adh_id)+"'") )
    {
        int idCol = localQuery.record().indexOf("badge_id");
        if( localQuery.next() )
            badge_id = localQuery.value( idCol ).toString();
    }
    return badge_id;
}

void MainWindow::logScan( int adh_id, QString badge_id )
{
    QSqlQuery localQuery( localDB );
    QString sql;
    QString now;
    now = QDateTime::currentDateTime().toString( "yyyy-MM-dd hh:mm:ss" );

    sql = "INSERT INTO logscans ( adh_id, badge_id, time, toSync) VALUES ( "+QString::number(adh_id)+" , '"+badge_id+"' , '"+now+"' , "+(onlineMode?"0":"1")+" );" ;
    ui->debugText->append( sql );

    localQuery.exec( sql );

    if( onlineMode)
    {
        QSqlQuery onlineQuery( onlineDB );
        sql = "INSERT INTO logscans ( adh_id, badge_id, time) VALUES ( "+QString::number(adh_id)+" , '"+badge_id+"' , '"+now+"' );" ;
        ui->debugText->append("online: "+sql );
        onlineQuery.exec( sql );
    }
}

QString MainWindow::assocBadge( QString badge_id )
{
    ui->debugText->append( "assocBadge : "+badge_id );

    QSqlQuery localQuery( localDB );
    QString sql;

    if( adhAttenteAssocBadge )
    {
        QString now;
        now = QDateTime::currentDateTime().toString( "yyyy-MM-dd hh:mm:ss" );

        bip->play();

        sql = "INSERT INTO badges ( adh_id, badge_id, insertDate, toSync) VALUES ( "+QString::number(adhAttenteAssocBadge)+" , '"+badge_id+"' , '"+now+"' , "+(onlineMode?"0":"1")+" );" ;
        ui->debugText->append( sql );
        localQuery.exec( sql );

        if( onlineMode)
        {
            QSqlQuery onlineQuery( onlineDB );
            sql = "INSERT INTO badges ( adh_id, badge_id, insertDate) VALUES ( "+QString::number(adhAttenteAssocBadge)+" , '"+badge_id+"' , '"+now+"'  );" ;
            ui->debugText->append("online: "+sql );
            onlineQuery.exec( sql );
        }

        adhAttenteAssocBadge = 0;
    }

    if( ! ui->checkModeAuto->isChecked() )
        on_cancelAssoc_clicked();
    else
    {

        int adh_id=0;
        sql = "SELECT * FROM adherents WHERE adh_id NOT IN (  SELECT adh_id FROM badges ) ORDER BY nom,prenom LIMIT 1";
        if( localQuery.exec(sql) )
        {
            int idCol = localQuery.record().indexOf("adh_id");
            localQuery.next();
            adh_id = localQuery.value( idCol ).toString().toInt();
            showAttente( adh_id );
        }


    }


    return badge_id;
}

void MainWindow::on_buttonForgot_clicked()
{
    int adh_id;

    adh_id = getSelectedAdh();

    displayLoggingName( adh_id );
    logScan( adh_id, "");

}

void MainWindow::on_buttonNoBadge_clicked()
{
    int adh_id;

    adh_id = getSelectedAdh();

    showAttente( adh_id );
}

void MainWindow::showAttente( int adh_id )
{
    adhAttenteAssocBadge = adh_id;

    ui->Tabs->setCurrentIndex(2);

    QSqlQuery localQuery( localDB );
    QString sql;

    if( localQuery.exec("SELECT * FROM adherents WHERE adh_id="+QString::number(adh_id)+"") )
    {
        int nameCol = localQuery.record().indexOf("nom");
        int prenCol = localQuery.record().indexOf("prenom");
        localQuery.next();

        ui->labelAttente->setText( localQuery.value( nameCol ).toString()+" "+localQuery.value( prenCol ).toString() );

    }

}

int MainWindow::getSelectedAdh()
{
    QString item;
    int adh_id;

    item = ui->listeAdh->selectedItems().at(0)->text();
    QTextStream(&item) >> adh_id;

    return adh_id;
}

void MainWindow::startupSync()
{
    QSqlQuery localQuery( localDB );
    QString sql;

    if( onlineMode )
    {
        // 1 - Remonte toutes les données ayant un toSync
        // 2 - Récupère toutes les données à jour


        QSqlQuery onlineQuery( onlineDB );

        // 1 - Remonte toutes les données ayant un toSync

        localQuery.exec("BEGIN TRANSACTION");

        if( localQuery.exec("SELECT * FROM badges WHERE toSync=1") )
        {
            int colBadge = localQuery.record().indexOf("badge_id");
            int colAdh = localQuery.record().indexOf("adh_id");
            int colDate = localQuery.record().indexOf("insertDate");
            while( localQuery.next() )
            {
                sql = "INSERT INTO `badges` ( `badge_id`, `adh_id`, `insertDate` ) VALUES ";
                sql += " ( '"+localQuery.value( colBadge ).toString()+"' , '"+localQuery.value( colAdh ).toString()+"','"+localQuery.value( colDate ).toString()+"' ) ";
                onlineQuery.exec( sql+";" );

            }
            //ui->debugText->append( sql );
            //localQuery.exec( sql+";" );
            //ui->debugText->append( localQuery.lastError().driverText() );
        }

        if( localQuery.exec("SELECT * FROM logscans WHERE toSync=1") )
        {
            int colBadge = localQuery.record().indexOf("badge_id");
            int colAdh = localQuery.record().indexOf("adh_id");
            int colDate = localQuery.record().indexOf("time");
            while( localQuery.next() )
            {
                sql = "INSERT INTO `logscans` ( `badge_id`, `adh_id`, `time` ) VALUES ";
                sql += " ( '"+localQuery.value( colBadge ).toString()+"' , '"+localQuery.value( colAdh ).toString()+"','"+localQuery.value( colDate ).toString()+"' ) ";
                onlineQuery.exec( sql+";" );

            }
            //ui->debugText->append( sql );
            //localQuery.exec( sql+";" );
            //ui->debugText->append( localQuery.lastError().driverText() );
        }

        localQuery.exec("END TRANSACTION");


        // 2 - Récupère toutes les données à jour

        localQuery.exec("TRUNCATE TABLE `badges`;");
        localQuery.exec("TRUNCATE TABLE `adherents`;");
        localQuery.exec("TRUNCATE TABLE `logscans`;");

        localQuery.exec("BEGIN TRANSACTION");

        if( onlineQuery.exec("SELECT a.adh_id, UPPER(a.adh_nom) as nom, LOWER(a.adh_prenom) as prenom FROM Adherents as a,  xAnnees as x , Annees as an WHERE an.current=1 AND an.annee_id=x.annee_id AND a.adh_id=x.adh_id ORDER BY adh_nom, adh_prenom") )
        {
            int idCol = onlineQuery.record().indexOf("adh_id");
            int nameCol = onlineQuery.record().indexOf("nom");
            int prenCol = onlineQuery.record().indexOf("prenom");
            while( onlineQuery.next() )
            {
                sql = "INSERT INTO `adherents` ( `adh_id`, `nom`, `prenom` ) VALUES ";
                sql += " ( '"+onlineQuery.value( idCol ).toString()+"' , '"+onlineQuery.value( nameCol ).toString()+"','"+onlineQuery.value( prenCol ).toString()+"' ) ";
                localQuery.exec( sql+";" );

            }
            //ui->debugText->append( sql );
            //localQuery.exec( sql+";" );
            //ui->debugText->append( localQuery.lastError().driverText() );
        }

        if( onlineQuery.exec("SELECT * FROM badges") )
        {
            int badgeCol = onlineQuery.record().indexOf("badge_id");
            int adhCol = onlineQuery.record().indexOf("adh_id");
            //int n=0;
            while( onlineQuery.next() )
            {
                sql = "INSERT INTO `badges` ( `adh_id`, `badge_id` ) VALUES ";
                sql += " ( '"+onlineQuery.value( adhCol ).toString()+"' , '"+onlineQuery.value( badgeCol ).toString()+"' ) ";
                localQuery.exec( sql+";" );

            }
        }

        localQuery.exec("END TRANSACTION");




        /*
        QString quer;
        quer = "SELECT m.`Titre`,m.`Auteur`,m.`Album`,'Genre',m.`Annee`,m.`Comment`, m.`Duree` ,m.`Note`, m.`ID`, m.`Racine`,m.`Dossier`,m.`FileName` FROM `Mp3` as m WHERE m.`ID` = ";
        quer += id;


        QSqlQuery query;
        if( query.exec( quer ))
        {
            if( query.next() )
            {
                ui->titreTitre->setText( query.value(0).toString() );
                ui->titreAuteur->setText( query.value(1).toString() );
                ui->titreAlbum->setText( query.value(2).toString() );
                // genre
                ui->titreAnnee->setText( query.value(4).toString() );
                ui->titreCommentaire->setText( query.value(5).toString() );
                // duree
                ui->titreNote->setValue( query.value(7).toInt() );
                ui->titreID->setText( query.value(8).toString() );
                ui->titreURL->setText( convertUrl( query.value(9).toString()+query.value(10).toString()+query.value(11).toString() ) );

                ui->titreTitre2->setText( ui->titreAuteur->text() + " - " + ui->titreTitre->text() );
            }
        }
        else
            QMessageBox::critical(0, QString::fromUtf8( "Info Base de Donnée" ), quer+"\n"+query.lastError().databaseText() , QMessageBox::Ok);
*/

    }

    ui->listeAdh->clear();
    if( localQuery.exec("SELECT * FROM Adherents ORDER BY nom,prenom") )
    {
        int nameCol = localQuery.record().indexOf("nom");
        int prenCol = localQuery.record().indexOf("prenom");
        int idCol = localQuery.record().indexOf("adh_id");
        while( localQuery.next() )
        {
            QString nom = localQuery.value( idCol ).toString()+" - "+localQuery.value( nameCol ).toString()+" - "+localQuery.value( prenCol ).toString();
            ui->listeAdh->addItem( nom );
        }
    }

}




void MainWindow::on_cancelAssoc_clicked()
{
    if( !ui->checkModeAuto->isChecked() )
        ui->Tabs->setCurrentIndex(0);

    adhAttenteAssocBadge = 0;
}

void MainWindow::on_listeAdh_clicked(const QModelIndex &index)
{
    int adh_id;
    QString badge_id;
    adh_id = getSelectedAdh();
    badge_id = getBadgeIdFromAdh( adh_id );

    if( badge_id != "")
        ui->buttonForgot->setEnabled( true );
    else
        ui->buttonForgot->setEnabled( false );

}
