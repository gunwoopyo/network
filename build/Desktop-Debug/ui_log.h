/********************************************************************************
** Form generated from reading UI file 'log.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_H
#define UI_LOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_log
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *log)
    {
        if (log->objectName().isEmpty())
            log->setObjectName("log");
        log->resize(800, 600);
        centralwidget = new QWidget(log);
        centralwidget->setObjectName("centralwidget");
        log->setCentralWidget(centralwidget);
        menubar = new QMenuBar(log);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        log->setMenuBar(menubar);
        statusbar = new QStatusBar(log);
        statusbar->setObjectName("statusbar");
        log->setStatusBar(statusbar);

        retranslateUi(log);

        QMetaObject::connectSlotsByName(log);
    } // setupUi

    void retranslateUi(QMainWindow *log)
    {
        log->setWindowTitle(QCoreApplication::translate("log", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class log: public Ui_log {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_H
