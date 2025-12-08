/********************************************************************************
** Form generated from reading UI file 'logwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWINDOW_H
#define UI_LOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_logwindow
{
public:
    QWidget *centralwidget;
    QLabel *logSortingText;
    QComboBox *logSortingComboBox;
    QFrame *frame;
    QFrame *logSearchFrame;
    QLabel *logDateText;
    QLabel *logTypeText;
    QComboBox *logTypeComboBox;
    QLabel *deviceNameText;
    QComboBox *deviceNameComboBox;
    QLabel *logDateTextTo;
    QDateEdit *logDatefFinishing;
    QDateEdit *logDatefStarting;
    QLabel *portNameText;
    QComboBox *portComboBox;
    QLabel *logSearchText;
    QFrame *logSearchTableFrame;
    QTableWidget *logSearchTable;
    QLabel *logSearchTableText;
    QFrame *titleFrame;
    QLabel *titleText;
    QLabel *subtitleText;
    QPushButton *logText;
    QPushButton *logSearchpushButton;
    QPushButton *logAllSearchpushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *logwindow)
    {
        if (logwindow->objectName().isEmpty())
            logwindow->setObjectName("logwindow");
        logwindow->resize(1315, 776);
        centralwidget = new QWidget(logwindow);
        centralwidget->setObjectName("centralwidget");
        logSortingText = new QLabel(centralwidget);
        logSortingText->setObjectName("logSortingText");
        logSortingText->setGeometry(QRect(1100, 290, 51, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        logSortingText->setFont(font);
        logSortingText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        logSortingComboBox = new QComboBox(centralwidget);
        logSortingComboBox->setObjectName("logSortingComboBox");
        logSortingComboBox->setGeometry(QRect(1160, 290, 101, 26));
        QFont font1;
        font1.setPointSize(10);
        logSortingComboBox->setFont(font1);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(40, 130, 1231, 101));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        logSearchFrame = new QFrame(frame);
        logSearchFrame->setObjectName("logSearchFrame");
        logSearchFrame->setGeometry(QRect(0, 20, 1231, 81));
        logSearchFrame->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        logSearchFrame->setFrameShape(QFrame::Shape::StyledPanel);
        logSearchFrame->setFrameShadow(QFrame::Shadow::Raised);
        logDateText = new QLabel(logSearchFrame);
        logDateText->setObjectName("logDateText");
        logDateText->setGeometry(QRect(860, 30, 31, 31));
        logDateText->setFont(font1);
        logDateText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        logTypeText = new QLabel(logSearchFrame);
        logTypeText->setObjectName("logTypeText");
        logTypeText->setGeometry(QRect(630, 30, 51, 18));
        logTypeText->setFont(font1);
        logTypeText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        logTypeComboBox = new QComboBox(logSearchFrame);
        logTypeComboBox->setObjectName("logTypeComboBox");
        logTypeComboBox->setGeometry(QRect(690, 30, 101, 26));
        deviceNameText = new QLabel(logSearchFrame);
        deviceNameText->setObjectName("deviceNameText");
        deviceNameText->setGeometry(QRect(110, 30, 51, 18));
        deviceNameText->setFont(font1);
        deviceNameText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        deviceNameComboBox = new QComboBox(logSearchFrame);
        deviceNameComboBox->setObjectName("deviceNameComboBox");
        deviceNameComboBox->setGeometry(QRect(170, 30, 101, 26));
        logDateTextTo = new QLabel(logSearchFrame);
        logDateTextTo->setObjectName("logDateTextTo");
        logDateTextTo->setGeometry(QRect(1020, 30, 16, 31));
        QFont font2;
        font2.setPointSize(14);
        logDateTextTo->setFont(font2);
        logDateTextTo->setStyleSheet(QString::fromUtf8("color:gray;"));
        logDatefFinishing = new QDateEdit(logSearchFrame);
        logDatefFinishing->setObjectName("logDatefFinishing");
        logDatefFinishing->setGeometry(QRect(1040, 30, 110, 27));
        logDatefStarting = new QDateEdit(logSearchFrame);
        logDatefStarting->setObjectName("logDatefStarting");
        logDatefStarting->setGeometry(QRect(900, 30, 110, 27));
        portNameText = new QLabel(logSearchFrame);
        portNameText->setObjectName("portNameText");
        portNameText->setGeometry(QRect(360, 30, 61, 18));
        portNameText->setFont(font1);
        portNameText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        portComboBox = new QComboBox(logSearchFrame);
        portComboBox->setObjectName("portComboBox");
        portComboBox->setGeometry(QRect(420, 30, 101, 26));
        logSearchText = new QLabel(frame);
        logSearchText->setObjectName("logSearchText");
        logSearchText->setGeometry(QRect(10, 0, 81, 21));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        logSearchText->setFont(font3);
        logSearchText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        logSearchTableFrame = new QFrame(centralwidget);
        logSearchTableFrame->setObjectName("logSearchTableFrame");
        logSearchTableFrame->setGeometry(QRect(40, 320, 1221, 391));
        logSearchTableFrame->setFrameShape(QFrame::Shape::StyledPanel);
        logSearchTableFrame->setFrameShadow(QFrame::Shadow::Raised);
        logSearchTable = new QTableWidget(logSearchTableFrame);
        if (logSearchTable->columnCount() < 5)
            logSearchTable->setColumnCount(5);
        QFont font4;
        font4.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font4);
        logSearchTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font4);
        logSearchTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font4);
        logSearchTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font4);
        logSearchTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font4);
        logSearchTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        logSearchTable->setObjectName("logSearchTable");
        logSearchTable->setGeometry(QRect(0, 20, 1221, 371));
        logSearchTable->setFont(font4);
        logSearchTable->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        logSearchTable->horizontalHeader()->setDefaultSectionSize(240);
        logSearchTableText = new QLabel(logSearchTableFrame);
        logSearchTableText->setObjectName("logSearchTableText");
        logSearchTableText->setGeometry(QRect(10, 0, 91, 21));
        logSearchTableText->setFont(font3);
        logSearchTableText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        titleFrame = new QFrame(centralwidget);
        titleFrame->setObjectName("titleFrame");
        titleFrame->setGeometry(QRect(40, 20, 1231, 71));
        titleFrame->setFrameShape(QFrame::Shape::StyledPanel);
        titleFrame->setFrameShadow(QFrame::Shadow::Raised);
        titleText = new QLabel(titleFrame);
        titleText->setObjectName("titleText");
        titleText->setGeometry(QRect(20, 0, 321, 41));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Cantarell Extra Bold")});
        font5.setPointSize(17);
        font5.setBold(true);
        titleText->setFont(font5);
        titleText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        subtitleText = new QLabel(titleFrame);
        subtitleText->setObjectName("subtitleText");
        subtitleText->setGeometry(QRect(20, 30, 151, 41));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Cantarell")});
        font6.setPointSize(12);
        font6.setBold(true);
        subtitleText->setFont(font6);
        subtitleText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        logText = new QPushButton(centralwidget);
        logText->setObjectName("logText");
        logText->setGeometry(QRect(30, 100, 91, 31));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Cantarell")});
        font7.setPointSize(10);
        font7.setBold(true);
        logText->setFont(font7);
        logText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);\n"
"border:none;"));
        logSearchpushButton = new QPushButton(centralwidget);
        logSearchpushButton->setObjectName("logSearchpushButton");
        logSearchpushButton->setGeometry(QRect(1120, 100, 71, 26));
        logSearchpushButton->setFont(font3);
        logSearchpushButton->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        logAllSearchpushButton = new QPushButton(centralwidget);
        logAllSearchpushButton->setObjectName("logAllSearchpushButton");
        logAllSearchpushButton->setGeometry(QRect(1200, 100, 71, 26));
        logAllSearchpushButton->setFont(font3);
        logAllSearchpushButton->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        logwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(logwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1315, 23));
        logwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(logwindow);
        statusbar->setObjectName("statusbar");
        logwindow->setStatusBar(statusbar);

        retranslateUi(logwindow);

        QMetaObject::connectSlotsByName(logwindow);
    } // setupUi

    void retranslateUi(QMainWindow *logwindow)
    {
        logwindow->setWindowTitle(QCoreApplication::translate("logwindow", "MainWindow", nullptr));
        logSortingText->setText(QCoreApplication::translate("logwindow", "\354\240\225\353\240\254 \352\270\260\354\244\200", nullptr));
        logDateText->setText(QCoreApplication::translate("logwindow", "\352\270\260\352\260\204", nullptr));
        logTypeText->setText(QCoreApplication::translate("logwindow", "\353\241\234\352\267\270 \354\234\240\355\230\225", nullptr));
        deviceNameText->setText(QCoreApplication::translate("logwindow", "\354\236\245\353\271\204 \354\235\264\353\246\204", nullptr));
        logDateTextTo->setText(QCoreApplication::translate("logwindow", "~", nullptr));
        portNameText->setText(QCoreApplication::translate("logwindow", " \355\217\254\355\212\270 \354\242\205\353\245\230", nullptr));
        logSearchText->setText(QCoreApplication::translate("logwindow", "\354\241\260\355\232\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem = logSearchTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("logwindow", "\354\213\234\352\260\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = logSearchTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("logwindow", "\354\236\245\353\271\204 \354\235\264\353\246\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = logSearchTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("logwindow", "\354\236\245\353\271\204 IP \354\243\274\354\206\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = logSearchTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("logwindow", "\354\235\270\355\204\260\355\216\230\354\235\264\354\212\244\353\252\205", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = logSearchTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("logwindow", "\354\236\245\353\271\204 \354\235\264\353\262\244\355\212\270 \354\234\240\355\230\225", nullptr));
        logSearchTableText->setText(QCoreApplication::translate("logwindow", "\354\241\260\355\232\214 \355\230\204\355\231\251", nullptr));
        titleText->setText(QCoreApplication::translate("logwindow", "Network Mornitoring System  ", nullptr));
        subtitleText->setText(QCoreApplication::translate("logwindow", "Netman_labs", nullptr));
        logText->setText(QCoreApplication::translate("logwindow", "\353\241\234\352\267\270 \353\260\217 \355\212\270\353\236\251", nullptr));
        logSearchpushButton->setText(QCoreApplication::translate("logwindow", "\354\241\260\355\232\214", nullptr));
        logAllSearchpushButton->setText(QCoreApplication::translate("logwindow", "\354\240\204\354\262\264\354\241\260\355\232\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class logwindow: public Ui_logwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWINDOW_H
