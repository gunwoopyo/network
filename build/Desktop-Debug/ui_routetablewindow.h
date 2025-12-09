/********************************************************************************
** Form generated from reading UI file 'routetablewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUTETABLEWINDOW_H
#define UI_ROUTETABLEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_routetablewindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *routetablewindow)
    {
        if (routetablewindow->objectName().isEmpty())
            routetablewindow->setObjectName("routetablewindow");
        routetablewindow->resize(800, 492);
        centralwidget = new QWidget(routetablewindow);
        centralwidget->setObjectName("centralwidget");
        routetablewindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(routetablewindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        routetablewindow->setMenuBar(menubar);
        statusbar = new QStatusBar(routetablewindow);
        statusbar->setObjectName("statusbar");
        routetablewindow->setStatusBar(statusbar);

        retranslateUi(routetablewindow);

        QMetaObject::connectSlotsByName(routetablewindow);
    } // setupUi

    void retranslateUi(QMainWindow *routetablewindow)
    {
        routetablewindow->setWindowTitle(QCoreApplication::translate("routetablewindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class routetablewindow: public Ui_routetablewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUTETABLEWINDOW_H
