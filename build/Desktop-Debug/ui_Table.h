/********************************************************************************
** Form generated from reading UI file 'Table.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_H
#define UI_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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

class Ui_LogWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QFrame *tableSearchFrame;
    QLabel *deviceNameText;
    QComboBox *deviceNameComboBox;
    QPushButton *tableSearchpushButton;
    QFrame *tableSearchTableFrame;
    QTableWidget *tableSearchTable;
    QLabel *tableSearchTableText;
    QFrame *titleFrame;
    QLabel *titleText;
    QLabel *subtitleText;
    QPushButton *tableText;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LogWindow)
    {
        if (LogWindow->objectName().isEmpty())
            LogWindow->setObjectName("LogWindow");
        LogWindow->resize(1315, 776);
        centralwidget = new QWidget(LogWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(30, 130, 1231, 71));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        tableSearchFrame = new QFrame(frame);
        tableSearchFrame->setObjectName("tableSearchFrame");
        tableSearchFrame->setGeometry(QRect(0, 20, 1231, 51));
        tableSearchFrame->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        tableSearchFrame->setFrameShape(QFrame::Shape::StyledPanel);
        tableSearchFrame->setFrameShadow(QFrame::Shadow::Raised);
        deviceNameText = new QLabel(tableSearchFrame);
        deviceNameText->setObjectName("deviceNameText");
        deviceNameText->setGeometry(QRect(60, 20, 51, 18));
        QFont font;
        font.setPointSize(10);
        deviceNameText->setFont(font);
        deviceNameText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        deviceNameComboBox = new QComboBox(tableSearchFrame);
        deviceNameComboBox->setObjectName("deviceNameComboBox");
        deviceNameComboBox->setGeometry(QRect(160, 10, 101, 26));
        tableSearchpushButton = new QPushButton(tableSearchFrame);
        tableSearchpushButton->setObjectName("tableSearchpushButton");
        tableSearchpushButton->setGeometry(QRect(1140, 10, 71, 26));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        tableSearchpushButton->setFont(font1);
        tableSearchpushButton->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        tableSearchTableFrame = new QFrame(centralwidget);
        tableSearchTableFrame->setObjectName("tableSearchTableFrame");
        tableSearchTableFrame->setGeometry(QRect(20, 270, 1231, 391));
        tableSearchTableFrame->setFrameShape(QFrame::Shape::StyledPanel);
        tableSearchTableFrame->setFrameShadow(QFrame::Shadow::Raised);
        tableSearchTable = new QTableWidget(tableSearchTableFrame);
        if (tableSearchTable->columnCount() < 7)
            tableSearchTable->setColumnCount(7);
        QFont font2;
        font2.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font2);
        tableSearchTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        tableSearchTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font2);
        tableSearchTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font2);
        tableSearchTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font2);
        tableSearchTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font2);
        tableSearchTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font2);
        tableSearchTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableSearchTable->setObjectName("tableSearchTable");
        tableSearchTable->setGeometry(QRect(0, 20, 1231, 371));
        tableSearchTable->setFont(font2);
        tableSearchTable->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        tableSearchTable->horizontalHeader()->setDefaultSectionSize(173);
        tableSearchTableText = new QLabel(tableSearchTableFrame);
        tableSearchTableText->setObjectName("tableSearchTableText");
        tableSearchTableText->setGeometry(QRect(10, 0, 91, 21));
        tableSearchTableText->setFont(font1);
        tableSearchTableText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        titleFrame = new QFrame(centralwidget);
        titleFrame->setObjectName("titleFrame");
        titleFrame->setGeometry(QRect(30, 20, 1231, 71));
        titleFrame->setFrameShape(QFrame::Shape::StyledPanel);
        titleFrame->setFrameShadow(QFrame::Shadow::Raised);
        titleText = new QLabel(titleFrame);
        titleText->setObjectName("titleText");
        titleText->setGeometry(QRect(20, 0, 321, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Cantarell Extra Bold")});
        font3.setPointSize(17);
        font3.setBold(true);
        titleText->setFont(font3);
        titleText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        subtitleText = new QLabel(titleFrame);
        subtitleText->setObjectName("subtitleText");
        subtitleText->setGeometry(QRect(20, 30, 151, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Cantarell")});
        font4.setPointSize(12);
        font4.setBold(true);
        subtitleText->setFont(font4);
        subtitleText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        tableText = new QPushButton(centralwidget);
        tableText->setObjectName("tableText");
        tableText->setGeometry(QRect(30, 110, 71, 20));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Cantarell")});
        font5.setPointSize(9);
        font5.setBold(true);
        tableText->setFont(font5);
        tableText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);\n"
"border:none;"));
        LogWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LogWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1315, 23));
        LogWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LogWindow);
        statusbar->setObjectName("statusbar");
        LogWindow->setStatusBar(statusbar);

        retranslateUi(LogWindow);

        QMetaObject::connectSlotsByName(LogWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LogWindow)
    {
        LogWindow->setWindowTitle(QCoreApplication::translate("LogWindow", "MainWindow", nullptr));
        deviceNameText->setText(QCoreApplication::translate("LogWindow", "\354\236\245\353\271\204 \354\235\264\353\246\204", nullptr));
        tableSearchpushButton->setText(QCoreApplication::translate("LogWindow", "\354\213\234\354\236\221", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableSearchTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("LogWindow", "\353\252\251\354\240\201\354\247\200 ", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableSearchTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("LogWindow", "\353\213\244\354\235\214 \355\231\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableSearchTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("LogWindow", "\354\235\270\355\204\260\355\216\230\354\235\264\354\212\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableSearchTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("LogWindow", "\354\204\234\353\270\214\353\204\267\353\247\210\354\212\244\355\201\254", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableSearchTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("LogWindow", "\353\235\274\354\232\260\355\212\270 \355\203\200\354\236\205", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableSearchTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("LogWindow", "\355\224\204\353\241\234\355\206\240\354\275\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableSearchTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("LogWindow", "\353\251\224\355\212\270\353\246\255", nullptr));
        tableSearchTableText->setText(QCoreApplication::translate("LogWindow", "\354\241\260\355\232\214 \355\230\204\355\231\251", nullptr));
        titleText->setText(QCoreApplication::translate("LogWindow", "Network Mornitoring System  ", nullptr));
        subtitleText->setText(QCoreApplication::translate("LogWindow", "Netman_labs", nullptr));
        tableText->setText(QCoreApplication::translate("LogWindow", "\355\205\214\354\235\264\353\270\224 \354\241\260\355\232\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogWindow: public Ui_LogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_H
