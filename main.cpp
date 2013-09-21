#include <qtsingleapplication.h>
#include <QApplication>
#include "mainwindow.h"
//#include <QSound>
//#include <QMediaContent>

//#include <QMediaPlayer>
//#include <qmediaplayer.h>

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    QtSingleApplication a(argc, argv);

    if (a.isRunning())
    {
        a.sendMessage( argv[1] );
        //printf("Appli déjà lancée\n");
        return 0;
    }


   /* QMediaPlayer player;
    //connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    player.setMedia(QUrl::fromLocalFile("/var/adheScan/bip.mp3"));
    player.setVolume(100);
    player.play();
    sleep( 2 );
    exit(0);
    */
/*
    if( ! QSound::isAvailable() )
        exit(1);


    QSound::play( "/tmp/bip.wav");
    exit(0);
*/
    MainWindow w;

    a.setActivationWindow(&w);

    if( argc > 1)
        w.receive( argv[1] );

    //w.show();
    w.showFullScreen();

    QObject::connect(&a, SIGNAL(messageReceived(const QString&)), &w, SLOT(receive(const QString&)));

    return a.exec();
}
