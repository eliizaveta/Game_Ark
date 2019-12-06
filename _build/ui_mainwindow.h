/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStart_Game;
    QAction *actionAbout_control;
    QAction *actionAbout_win;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuArkanoid;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(333, 333);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionStart_Game = new QAction(MainWindow);
        actionStart_Game->setObjectName(QString::fromUtf8("actionStart_Game"));
        actionAbout_control = new QAction(MainWindow);
        actionAbout_control->setObjectName(QString::fromUtf8("actionAbout_control"));
        actionAbout_win = new QAction(MainWindow);
        actionAbout_win->setObjectName(QString::fromUtf8("actionAbout_win"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 60, 231, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("courier"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        font.setKerning(true);
        pushButton->setFont(font);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: #8ec12d;\n"
"font-family: courier;\n"
"border: 1px solid powderblue;\n"
"padding: 30px;\n"
"border: 2px solid rgba(0,0,0,0.05);\n"
"border-radius: 8px;\n"
""));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 160, 231, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("courier"));
        font1.setPointSize(10);
        pushButton_2->setFont(font1);
        pushButton_2->setAutoFillBackground(false);
        pushButton_2->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: #8ec12d;\n"
"font-family: courier;\n"
"border: 1px solid powderblue;\n"
"padding: 30px;\n"
"border: 2px solid rgba(0,0,0,0.05);\n"
"border-radius: 8px;\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 341, 311));
        label->setStyleSheet(QString::fromUtf8("background-color: #DEB8A0;\n"
"box-shadow: 0 0 0 1px #a27b62;\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        pushButton->raise();
        pushButton_2->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 333, 26));
        menubar->setStyleSheet(QString::fromUtf8(""));
        menuArkanoid = new QMenu(menubar);
        menuArkanoid->setObjectName(QString::fromUtf8("menuArkanoid"));
        menuHelp = new QMenu(menuArkanoid);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuArkanoid->menuAction());
        menuArkanoid->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionAbout_control);
        menuHelp->addAction(actionAbout_win);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionStart_Game->setText(QApplication::translate("MainWindow", "Start Game", nullptr));
        actionAbout_control->setText(QApplication::translate("MainWindow", "About control", nullptr));
        actionAbout_win->setText(QApplication::translate("MainWindow", "About victory", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Start Game", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        label->setText(QString());
        menuArkanoid->setTitle(QApplication::translate("MainWindow", "Arkanoid", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
