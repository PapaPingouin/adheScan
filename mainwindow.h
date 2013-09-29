#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDateTime>
#include <QTextStream>
#include <QMediaPlayer>
#include <QModelIndex>
#include <QTimer>

#define ONLINE_ON 1
#define ONLINE_OFF 0

#define INFO_DECHARGE 1
#define INFO_INSCRIPTION 2
#define INFO_PAIEMENT 4
#define INFO_AUTORISATION 8



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
    void receive(const QString &str);
    void updateTime();

private slots:
    void on_actionQuitter_triggered();

    void on_buttonForgot_clicked();

    void on_buttonNoBadge_clicked();



    void on_cancelAssoc_clicked();

    void on_listeAdh_clicked(const QModelIndex &index);

    void on_listeAdh_itemSelectionChanged();

private:
    Ui::MainWindow *ui;

    QSqlDatabase localDB;
    QSqlDatabase onlineDB;
    int onlineMode;

    QMediaPlayer *bip;
    QMediaPlayer *bop;
    QMediaPlayer *bilip;

    void initBDD();
    void initBDDSQLite();

    int nbrPassages;

    void refreshStatusBar();
    void startupSync();

    int getAdhIdFromBadge( QString str );
    QString getBadgeIdFromAdh( int adh_id );
    int getInfosFromAdh( int adh_id );
    int getSelectedAdh();
    void logScan( int adh_id, QString badge_id );
    void displayLoggingName( int adh_id );

    QString assocBadge( QString str );
    int adhAttenteAssocBadge;

    void showAttente( int adh_id );
};

#endif // MAINWINDOW_H
