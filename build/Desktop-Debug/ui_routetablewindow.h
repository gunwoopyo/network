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
    QFrame *routeFrame;
    QTableWidget *routeTable;
    QLabel *routeTableText;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *routetablewindow)
    {
        if (routetablewindow->objectName().isEmpty())
            routetablewindow->setObjectName("routetablewindow");
        routetablewindow->resize(800, 411);
        QFont font;
        font.setPointSize(11);
        routetablewindow->setFont(font);
        centralwidget = new QWidget(routetablewindow);
        centralwidget->setObjectName("centralwidget");
        routeFrame = new QFrame(centralwidget);
        routeFrame->setObjectName("routeFrame");
        routeFrame->setGeometry(QRect(30, 100, 741, 241));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cantarell")});
        font1.setPointSize(9);
        routeFrame->setFont(font1);
        routeFrame->setFrameShape(QFrame::Shape::StyledPanel);
        routeFrame->setFrameShadow(QFrame::Shadow::Raised);
        routeTable = new QTableWidget(routeFrame);
        if (routeTable->columnCount() < 5)
            routeTable->setColumnCount(5);
        QFont font2;
        font2.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font2);
        routeTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        routeTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font2);
        routeTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font2);
        routeTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font2);
        routeTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        routeTable->setObjectName("routeTable");
        routeTable->setGeometry(QRect(0, 30, 741, 221));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Cantarell")});
        font3.setPointSize(9);
        font3.setBold(false);
        routeTable->setFont(font3);
        routeTable->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
        routeTable->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        routeTable->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        routeTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        routeTable->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        routeTable->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        routeTable->horizontalHeader()->setDefaultSectionSize(145);
        routeTable->verticalHeader()->setVisible(false);
        routeTable->verticalHeader()->setMinimumSectionSize(28);
        routeTable->verticalHeader()->setDefaultSectionSize(30);
        routeTable->verticalHeader()->setHighlightSections(true);
        routeTableText = new QLabel(routeFrame);
        routeTableText->setObjectName("routeTableText");
        routeTableText->setGeometry(QRect(10, 0, 101, 21));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Cantarell Extra Bold")});
        font4.setPointSize(9);
        font4.setBold(true);
        routeTableText->setFont(font4);
        routeTableText->setStyleSheet(QString::fromUtf8("color:rgb(94, 92, 100);"));
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
        QTableWidgetItem *___qtablewidgetitem = routeTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("routetablewindow", "\353\252\251\354\240\201\354\247\200 IP \354\243\274\354\206\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = routeTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("routetablewindow", "\353\235\274\354\232\260\355\214\205 \354\235\270\355\204\260\355\216\230\354\235\264\354\212\244 \354\235\270\353\215\261\354\212\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = routeTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("routetablewindow", "\353\213\244\354\235\214 \355\231\211 IP", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = routeTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("routetablewindow", "\353\235\274\354\232\260\355\214\205 \355\203\200\354\236\205", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = routeTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("routetablewindow", "\353\235\274\354\232\260\355\214\205 \355\224\204\353\241\234\355\206\240\354\275\234", nullptr));
        routeTableText->setText(QCoreApplication::translate("routetablewindow", "\353\235\274\354\232\260\355\214\205 \355\205\214\354\235\264\353\270\224", nullptr));
    } // retranslateUi

};

namespace Ui {
    class routetablewindow: public Ui_routetablewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUTETABLEWINDOW_H
