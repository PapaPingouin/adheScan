/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Sep 15 17:38:40 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelNameChecked;
    QFrame *frame;
    QLabel *labelTime;
    QLabel *labelSeance;
    QLabel *labelNameCheckedInfos;
    QTabWidget *Tabs;
    QWidget *tabListe;
    QHBoxLayout *horizontalLayout;
    QListWidget *listeAdh;
    QGroupBox *groupBox;
    QPushButton *buttonForgot;
    QPushButton *buttonNoBadge;
    QCheckBox *checkDecharge;
    QCheckBox *checkInscription;
    QCheckBox *checkPaiement;
    QCheckBox *checkAutorisation;
    QCheckBox *checkBadge;
    QWidget *tabDebug;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *debugText;
    QWidget *tabBadge;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *labelAttente;
    QPushButton *cancelAssoc;
    QSpacerItem *verticalSpacer;
    QCheckBox *checkModeAuto;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(822, 608);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, -1, -1, -1);
        labelNameChecked = new QLabel(centralWidget);
        labelNameChecked->setObjectName(QString::fromUtf8("labelNameChecked"));
        labelNameChecked->setMinimumSize(QSize(500, 100));
        labelNameChecked->setMaximumSize(QSize(16777215, 200));
        QFont font;
        font.setPointSize(40);
        font.setBold(true);
        font.setWeight(75);
        labelNameChecked->setFont(font);
        labelNameChecked->setTextFormat(Qt::PlainText);
        labelNameChecked->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelNameChecked);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(200, 100));
        frame->setMaximumSize(QSize(200, 200));
        QPalette palette;
        QBrush brush(QColor(252, 252, 252, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(0, 170, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frame->setPalette(palette);
        frame->setAutoFillBackground(true);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        labelTime = new QLabel(frame);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        labelTime->setGeometry(QRect(10, 10, 181, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        labelTime->setPalette(palette1);
        QFont font1;
        font1.setPointSize(13);
        labelTime->setFont(font1);
        labelTime->setFrameShape(QFrame::NoFrame);
        labelTime->setAlignment(Qt::AlignCenter);
        labelSeance = new QLabel(frame);
        labelSeance->setObjectName(QString::fromUtf8("labelSeance"));
        labelSeance->setGeometry(QRect(10, 60, 181, 31));
        labelSeance->setFont(font1);
        labelSeance->setAutoFillBackground(false);
        labelSeance->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(frame);


        verticalLayout->addLayout(horizontalLayout_2);

        labelNameCheckedInfos = new QLabel(centralWidget);
        labelNameCheckedInfos->setObjectName(QString::fromUtf8("labelNameCheckedInfos"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        labelNameCheckedInfos->setFont(font2);
        labelNameCheckedInfos->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        verticalLayout->addWidget(labelNameCheckedInfos);

        Tabs = new QTabWidget(centralWidget);
        Tabs->setObjectName(QString::fromUtf8("Tabs"));
        Tabs->setMaximumSize(QSize(16777215, 16777215));
        Tabs->setFont(font1);
        Tabs->setTabPosition(QTabWidget::East);
        Tabs->setIconSize(QSize(32, 32));
        Tabs->setDocumentMode(false);
        Tabs->setTabsClosable(false);
        tabListe = new QWidget();
        tabListe->setObjectName(QString::fromUtf8("tabListe"));
        horizontalLayout = new QHBoxLayout(tabListe);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listeAdh = new QListWidget(tabListe);
        new QListWidgetItem(listeAdh);
        new QListWidgetItem(listeAdh);
        new QListWidgetItem(listeAdh);
        listeAdh->setObjectName(QString::fromUtf8("listeAdh"));
        QFont font3;
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        listeAdh->setFont(font3);
        listeAdh->setStyleSheet(QString::fromUtf8("::item{ margin: 5px 150px;\n"
"\n"
"}"));
        listeAdh->setLineWidth(1);
        listeAdh->setLayoutMode(QListView::SinglePass);
        listeAdh->setViewMode(QListView::ListMode);
        listeAdh->setModelColumn(0);
        listeAdh->setSortingEnabled(false);

        horizontalLayout->addWidget(listeAdh);

        groupBox = new QGroupBox(tabListe);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(300, 0));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(false);
        font4.setWeight(50);
        groupBox->setFont(font4);
        buttonForgot = new QPushButton(groupBox);
        buttonForgot->setObjectName(QString::fromUtf8("buttonForgot"));
        buttonForgot->setGeometry(QRect(10, 140, 281, 101));
        buttonForgot->setSizeIncrement(QSize(0, 0));
        QPalette palette2;
        QBrush brush2(QColor(85, 170, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        buttonForgot->setPalette(palette2);
        QFont font5;
        font5.setPointSize(16);
        buttonForgot->setFont(font5);
        buttonForgot->setAutoFillBackground(true);
        buttonForgot->setStyleSheet(QString::fromUtf8(""));
        buttonForgot->setAutoDefault(false);
        buttonForgot->setDefault(false);
        buttonForgot->setFlat(false);
        buttonNoBadge = new QPushButton(groupBox);
        buttonNoBadge->setObjectName(QString::fromUtf8("buttonNoBadge"));
        buttonNoBadge->setGeometry(QRect(10, 280, 281, 101));
        QPalette palette3;
        QBrush brush3(QColor(255, 170, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        buttonNoBadge->setPalette(palette3);
        buttonNoBadge->setFont(font5);
        buttonNoBadge->setAutoFillBackground(true);
        checkDecharge = new QCheckBox(groupBox);
        checkDecharge->setObjectName(QString::fromUtf8("checkDecharge"));
        checkDecharge->setGeometry(QRect(20, 20, 78, 20));
        checkDecharge->setCheckable(true);
        checkInscription = new QCheckBox(groupBox);
        checkInscription->setObjectName(QString::fromUtf8("checkInscription"));
        checkInscription->setGeometry(QRect(20, 40, 78, 20));
        checkPaiement = new QCheckBox(groupBox);
        checkPaiement->setObjectName(QString::fromUtf8("checkPaiement"));
        checkPaiement->setGeometry(QRect(20, 60, 78, 20));
        checkAutorisation = new QCheckBox(groupBox);
        checkAutorisation->setObjectName(QString::fromUtf8("checkAutorisation"));
        checkAutorisation->setGeometry(QRect(20, 80, 231, 20));
        checkBadge = new QCheckBox(groupBox);
        checkBadge->setObjectName(QString::fromUtf8("checkBadge"));
        checkBadge->setGeometry(QRect(20, 100, 231, 20));

        horizontalLayout->addWidget(groupBox);

        QIcon icon;
        icon.addFile(QString::fromUtf8("icones/trouver-recherche-icone-3783-128.png"), QSize(), QIcon::Normal, QIcon::Off);
        Tabs->addTab(tabListe, icon, QString());
        tabDebug = new QWidget();
        tabDebug->setObjectName(QString::fromUtf8("tabDebug"));
        horizontalLayout_3 = new QHBoxLayout(tabDebug);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        debugText = new QTextEdit(tabDebug);
        debugText->setObjectName(QString::fromUtf8("debugText"));

        horizontalLayout_3->addWidget(debugText);

        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icones/parametres-avances-icone-5199-128.png"), QSize(), QIcon::Normal, QIcon::Off);
        Tabs->addTab(tabDebug, icon1, QString());
        tabBadge = new QWidget();
        tabBadge->setObjectName(QString::fromUtf8("tabBadge"));
        verticalLayout_2 = new QVBoxLayout(tabBadge);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(tabBadge);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 30));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        labelAttente = new QLabel(tabBadge);
        labelAttente->setObjectName(QString::fromUtf8("labelAttente"));
        labelAttente->setMinimumSize(QSize(0, 150));
        QFont font6;
        font6.setPointSize(40);
        labelAttente->setFont(font6);
        labelAttente->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelAttente);

        cancelAssoc = new QPushButton(tabBadge);
        cancelAssoc->setObjectName(QString::fromUtf8("cancelAssoc"));

        verticalLayout_2->addWidget(cancelAssoc);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        checkModeAuto = new QCheckBox(tabBadge);
        checkModeAuto->setObjectName(QString::fromUtf8("checkModeAuto"));

        verticalLayout_2->addWidget(checkModeAuto);

        Tabs->addTab(tabBadge, QString());

        verticalLayout->addWidget(Tabs);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 822, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionQuitter);

        retranslateUi(MainWindow);

        Tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        labelNameChecked->setText(QApplication::translate("MainWindow", "Bienvenue", 0, QApplication::UnicodeUTF8));
        labelTime->setText(QApplication::translate("MainWindow", "Heure", 0, QApplication::UnicodeUTF8));
        labelSeance->setText(QApplication::translate("MainWindow", "S\303\251ance", 0, QApplication::UnicodeUTF8));
        labelNameCheckedInfos->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listeAdh->isSortingEnabled();
        listeAdh->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listeAdh->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "ligne 1", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listeAdh->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "ligne 2", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listeAdh->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "ligne 3", 0, QApplication::UnicodeUTF8));
        listeAdh->setSortingEnabled(__sortingEnabled);

        groupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", 0, QApplication::UnicodeUTF8));
        buttonForgot->setText(QApplication::translate("MainWindow", "J'ai oubli\303\251 mon badge", 0, QApplication::UnicodeUTF8));
        buttonNoBadge->setText(QApplication::translate("MainWindow", "Associer un nouveau badge", 0, QApplication::UnicodeUTF8));
        checkDecharge->setText(QApplication::translate("MainWindow", "D\303\251charge", 0, QApplication::UnicodeUTF8));
        checkInscription->setText(QApplication::translate("MainWindow", "Inscription", 0, QApplication::UnicodeUTF8));
        checkPaiement->setText(QApplication::translate("MainWindow", "Paiement", 0, QApplication::UnicodeUTF8));
        checkAutorisation->setText(QApplication::translate("MainWindow", "Autorisation Parentale", 0, QApplication::UnicodeUTF8));
        checkBadge->setText(QApplication::translate("MainWindow", "Badge", 0, QApplication::UnicodeUTF8));
        Tabs->setTabText(Tabs->indexOf(tabListe), QApplication::translate("MainWindow", "Recherche par nom", 0, QApplication::UnicodeUTF8));
        Tabs->setTabText(Tabs->indexOf(tabDebug), QApplication::translate("MainWindow", "Debug", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Attente badge pour :", 0, QApplication::UnicodeUTF8));
        labelAttente->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        cancelAssoc->setText(QApplication::translate("MainWindow", "Annuler", 0, QApplication::UnicodeUTF8));
        checkModeAuto->setText(QApplication::translate("MainWindow", "Mode association des badges automatique (passe tout seul au suivant)", 0, QApplication::UnicodeUTF8));
        Tabs->setTabText(Tabs->indexOf(tabBadge), QApplication::translate("MainWindow", "Badges", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
