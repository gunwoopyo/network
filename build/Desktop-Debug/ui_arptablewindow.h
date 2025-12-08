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

class Ui_TableWindow
{
public:
    QWidget *centralwidget;
    QFrame *titleFrame;
    QPushButton *searchPushButton;
    QPushButton *searchTotalPushButton;
    QLabel *portNumberText;
    QComboBox *portNumberComboBox;
    QFrame *arpFrame;
    QLabel *arpTableText;
    QTableWidget *arpTable;
    QLabel *arpText;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TableWindow)
    {
        if (TableWindow->objectName().isEmpty())
            TableWindow->setObjectName("TableWindow");
        TableWindow->resize(1071, 753);
        centralwidget = new QWidget(TableWindow);
        centralwidget->setObjectName("centralwidget");
        titleFrame = new QFrame(centralwidget);
        titleFrame->setObjectName("titleFrame");
        titleFrame->setGeometry(QRect(50, 90, 971, 61));
        titleFrame->setFrameShape(QFrame::Shape::StyledPanel);
        titleFrame->setFrameShadow(QFrame::Shadow::Raised);
        searchPushButton = new QPushButton(titleFrame);
        searchPushButton->setObjectName("searchPushButton");
        searchPushButton->setGeometry(QRect(790, 20, 71, 26));
        searchTotalPushButton = new QPushButton(titleFrame);
        searchTotalPushButton->setObjectName("searchTotalPushButton");
        searchTotalPushButton->setGeometry(QRect(870, 20, 71, 26));
        portNumberText = new QLabel(titleFrame);
        portNumberText->setObjectName("portNumberText");
        portNumberText->setGeometry(QRect(50, 20, 66, 18));
        QFont font;
        font.setPointSize(10);
        portNumberText->setFont(font);
        portNumberComboBox = new QComboBox(titleFrame);
        portNumberComboBox->addItem(QString());
        portNumberComboBox->setObjectName("portNumberComboBox");
        portNumberComboBox->setGeometry(QRect(120, 20, 101, 26));
        arpFrame = new QFrame(centralwidget);
        arpFrame->setObjectName("arpFrame");
        arpFrame->setGeometry(QRect(50, 190, 971, 501));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cantarell")});
        font1.setPointSize(9);
        arpFrame->setFont(font1);
        arpFrame->setFrameShape(QFrame::Shape::StyledPanel);
        arpFrame->setFrameShadow(QFrame::Shadow::Raised);
        arpTableText = new QLabel(arpFrame);
        arpTableText->setObjectName("arpTableText");
        arpTableText->setGeometry(QRect(10, 0, 101, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Cantarell Extra Bold")});
        font2.setPointSize(9);
        font2.setBold(true);
        arpTableText->setFont(font2);
        arpTableText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        arpTable = new QTableWidget(arpFrame);
        if (arpTable->columnCount() < 4)
            arpTable->setColumnCount(4);
        QFont font3;
        font3.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font3);
        arpTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font3);
        arpTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font3);
        arpTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font3);
        arpTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        arpTable->setObjectName("arpTable");
        arpTable->setGeometry(QRect(0, 20, 971, 481));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Cantarell")});
        font4.setPointSize(9);
        font4.setBold(false);
        arpTable->setFont(font4);
        arpTable->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        arpTable->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        arpTable->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        arpTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        arpTable->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        arpTable->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        arpTable->horizontalHeader()->setDefaultSectionSize(242);
        arpTable->verticalHeader()->setVisible(false);
        arpTable->verticalHeader()->setMinimumSectionSize(28);
        arpTable->verticalHeader()->setDefaultSectionSize(30);
        arpTable->verticalHeader()->setHighlightSections(true);
        arpText = new QLabel(centralwidget);
        arpText->setObjectName("arpText");
        arpText->setGeometry(QRect(50, 60, 131, 21));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Cantarell Extra Bold")});
        font5.setPointSize(13);
        font5.setBold(true);
        arpText->setFont(font5);
        arpText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        TableWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TableWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1071, 23));
        TableWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TableWindow);
        statusbar->setObjectName("statusbar");
        TableWindow->setStatusBar(statusbar);

        retranslateUi(TableWindow);

        QMetaObject::connectSlotsByName(TableWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TableWindow)
    {
        TableWindow->setWindowTitle(QCoreApplication::translate("TableWindow", "\355\205\214\354\235\264\353\270\224 \354\241\260\355\232\214", nullptr));
        searchPushButton->setText(QCoreApplication::translate("TableWindow", "\354\241\260\355\232\214", nullptr));
        searchTotalPushButton->setText(QCoreApplication::translate("TableWindow", "\354\240\204\354\262\264\354\241\260\355\232\214", nullptr));
        portNumberText->setText(QCoreApplication::translate("TableWindow", " \355\217\254\355\212\270 \353\262\210\355\230\270", nullptr));
        portNumberComboBox->setItemText(0, QString());

        arpTableText->setText(QCoreApplication::translate("TableWindow", "ARP \355\205\214\354\235\264\353\270\224", nullptr));
        QTableWidgetItem *___qtablewidgetitem = arpTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TableWindow", " \355\217\254\355\212\270 \353\262\210\355\230\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = arpTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TableWindow", "IP Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = arpTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TableWindow", "MAC \354\243\274\354\206\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = arpTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("TableWindow", "\355\203\200\354\236\205", nullptr));
        arpText->setText(QCoreApplication::translate("TableWindow", "ARP \355\205\214\354\235\264\353\270\224 \354\241\260\355\232\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableWindow: public Ui_TableWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARPTABLEWINDOW_H
