/********************************************************************************
** Form generated from reading UI file 'arptablewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARPTABLEWINDOW_H
#define UI_ARPTABLEWINDOW_H

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

class Ui_ArpTableWindow
{
public:
    QWidget *centralwidget;
    QFrame *interfaceFrame;
    QLabel *interfaceText;
    QTableWidget *arpTable;
    QFrame *frame;
    QComboBox *portNumberComboBox;
    QPushButton *searchPushButton;
    QPushButton *searchTotalPushButton;
    QLabel *label;
    QFrame *titleFrame;
    QLabel *titleText;
    QLabel *subtitleText;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ArpTableWindow)
    {
        if (ArpTableWindow->objectName().isEmpty())
            ArpTableWindow->setObjectName("ArpTableWindow");
        ArpTableWindow->resize(934, 583);
        centralwidget = new QWidget(ArpTableWindow);
        centralwidget->setObjectName("centralwidget");
        interfaceFrame = new QFrame(centralwidget);
        interfaceFrame->setObjectName("interfaceFrame");
        interfaceFrame->setGeometry(QRect(70, 190, 791, 311));
        QFont font;
        font.setFamilies({QString::fromUtf8("Cantarell")});
        font.setPointSize(9);
        interfaceFrame->setFont(font);
        interfaceFrame->setFrameShape(QFrame::Shape::StyledPanel);
        interfaceFrame->setFrameShadow(QFrame::Shadow::Raised);
        interfaceText = new QLabel(interfaceFrame);
        interfaceText->setObjectName("interfaceText");
        interfaceText->setGeometry(QRect(10, 0, 71, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cantarell Extra Bold")});
        font1.setPointSize(9);
        font1.setBold(true);
        interfaceText->setFont(font1);
        interfaceText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        arpTable = new QTableWidget(interfaceFrame);
        if (arpTable->columnCount() < 4)
            arpTable->setColumnCount(4);
        QFont font2;
        font2.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font2);
        arpTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        arpTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font2);
        arpTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font2);
        arpTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        arpTable->setObjectName("arpTable");
        arpTable->setGeometry(QRect(0, 20, 791, 291));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Cantarell")});
        font3.setPointSize(9);
        font3.setBold(false);
        arpTable->setFont(font3);
        arpTable->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        arpTable->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        arpTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        arpTable->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        arpTable->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        arpTable->horizontalHeader()->setDefaultSectionSize(198);
        arpTable->verticalHeader()->setVisible(false);
        arpTable->verticalHeader()->setMinimumSectionSize(25);
        arpTable->verticalHeader()->setDefaultSectionSize(25);
        arpTable->verticalHeader()->setHighlightSections(true);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(70, 130, 791, 41));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        portNumberComboBox = new QComboBox(frame);
        portNumberComboBox->addItem(QString());
        portNumberComboBox->setObjectName("portNumberComboBox");
        portNumberComboBox->setGeometry(QRect(110, 10, 79, 21));
        searchPushButton = new QPushButton(frame);
        searchPushButton->setObjectName("searchPushButton");
        searchPushButton->setGeometry(QRect(640, 10, 61, 21));
        QFont font4;
        font4.setPointSize(10);
        searchPushButton->setFont(font4);
        searchTotalPushButton = new QPushButton(frame);
        searchTotalPushButton->setObjectName("searchTotalPushButton");
        searchTotalPushButton->setGeometry(QRect(710, 10, 61, 21));
        searchTotalPushButton->setFont(font4);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 10, 61, 18));
        label->setFont(font4);
        titleFrame = new QFrame(centralwidget);
        titleFrame->setObjectName("titleFrame");
        titleFrame->setGeometry(QRect(70, 40, 791, 71));
        titleFrame->setFrameShape(QFrame::Shape::StyledPanel);
        titleFrame->setFrameShadow(QFrame::Shadow::Raised);
        titleText = new QLabel(titleFrame);
        titleText->setObjectName("titleText");
        titleText->setGeometry(QRect(10, 0, 331, 41));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Cantarell Extra Bold")});
        font5.setPointSize(15);
        font5.setBold(true);
        titleText->setFont(font5);
        titleText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        subtitleText = new QLabel(titleFrame);
        subtitleText->setObjectName("subtitleText");
        subtitleText->setGeometry(QRect(10, 20, 151, 51));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Cantarell")});
        font6.setPointSize(14);
        font6.setBold(true);
        subtitleText->setFont(font6);
        subtitleText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);\n"
""));
        ArpTableWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ArpTableWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 934, 23));
        ArpTableWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ArpTableWindow);
        statusbar->setObjectName("statusbar");
        ArpTableWindow->setStatusBar(statusbar);

        retranslateUi(ArpTableWindow);

        QMetaObject::connectSlotsByName(ArpTableWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ArpTableWindow)
    {
        ArpTableWindow->setWindowTitle(QCoreApplication::translate("ArpTableWindow", "ARP\355\205\214\354\235\264\353\270\224", nullptr));
        interfaceText->setText(QCoreApplication::translate("ArpTableWindow", "ARP \355\205\214\354\235\264\353\270\224", nullptr));
        QTableWidgetItem *___qtablewidgetitem = arpTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ArpTableWindow", "\355\217\254\355\212\270 \353\262\210\355\230\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = arpTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ArpTableWindow", "IP Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = arpTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ArpTableWindow", "MAC \354\243\274\354\206\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = arpTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ArpTableWindow", "\355\203\200\354\236\205", nullptr));
        portNumberComboBox->setItemText(0, QString());

        searchPushButton->setText(QCoreApplication::translate("ArpTableWindow", "\354\241\260\355\232\214", nullptr));
        searchTotalPushButton->setText(QCoreApplication::translate("ArpTableWindow", "\354\240\204\354\262\264\354\241\260\355\232\214", nullptr));
        label->setText(QCoreApplication::translate("ArpTableWindow", "\355\217\254\355\212\270\353\262\210\355\230\270", nullptr));
        titleText->setText(QCoreApplication::translate("ArpTableWindow", "Network Monitoring System  ", nullptr));
        subtitleText->setText(QCoreApplication::translate("ArpTableWindow", "Netman_labs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArpTableWindow: public Ui_ArpTableWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARPTABLEWINDOW_H
