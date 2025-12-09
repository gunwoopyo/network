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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_routetablewindow
{
public:
    QWidget *centralwidget;
    QFrame *routeeFrame;
    QLabel *routeTableText;
    QTableWidget *routeeTable;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *routetablewindow)
    {
        if (routetablewindow->objectName().isEmpty())
            routetablewindow->setObjectName("routetablewindow");
        routetablewindow->resize(800, 492);
        centralwidget = new QWidget(routetablewindow);
        centralwidget->setObjectName("centralwidget");
        routeeFrame = new QFrame(centralwidget);
        routeeFrame->setObjectName("routeeFrame");
        routeeFrame->setGeometry(QRect(50, 110, 691, 301));
        QFont font;
        font.setFamilies({QString::fromUtf8("Cantarell")});
        font.setPointSize(9);
        routeeFrame->setFont(font);
        routeeFrame->setFrameShape(QFrame::Shape::StyledPanel);
        routeeFrame->setFrameShadow(QFrame::Shadow::Raised);
        routeTableText = new QLabel(routeeFrame);
        routeTableText->setObjectName("routeTableText");
        routeTableText->setGeometry(QRect(10, 0, 101, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cantarell Extra Bold")});
        font1.setPointSize(9);
        font1.setBold(true);
        routeTableText->setFont(font1);
        routeTableText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        routeeTable = new QTableWidget(routeeFrame);
        if (routeeTable->columnCount() < 4)
            routeeTable->setColumnCount(4);
        QFont font2;
        font2.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font2);
        routeeTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        routeeTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font2);
        routeeTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font2);
        routeeTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        routeeTable->setObjectName("routeeTable");
        routeeTable->setGeometry(QRect(0, 20, 691, 281));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Cantarell")});
        font3.setPointSize(9);
        font3.setBold(false);
        routeeTable->setFont(font3);
        routeeTable->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        routeeTable->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        routeeTable->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        routeeTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        routeeTable->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        routeeTable->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        routeeTable->horizontalHeader()->setDefaultSectionSize(170);
        routeeTable->verticalHeader()->setVisible(false);
        routeeTable->verticalHeader()->setMinimumSectionSize(28);
        routeeTable->verticalHeader()->setDefaultSectionSize(30);
        routeeTable->verticalHeader()->setHighlightSections(true);
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
        routeTableText->setText(QCoreApplication::translate("routetablewindow", "\353\235\274\354\232\260\355\212\270 \355\205\214\354\235\264\353\270\224", nullptr));
        QTableWidgetItem *___qtablewidgetitem = routeeTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("routetablewindow", " \355\217\254\355\212\270 \353\262\210\355\230\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = routeeTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("routetablewindow", "IP Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = routeeTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("routetablewindow", "MAC \354\243\274\354\206\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = routeeTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("routetablewindow", "\355\203\200\354\236\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class routetablewindow: public Ui_routetablewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUTETABLEWINDOW_H
