#include "routingtablewindow.h"
#include "ui_routingtablewindow.h"

#include "RouteTableWorker.h"
#include "RouteTable.h"

#include "Router.h"


RoutingTableWindow::RoutingTableWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RoutingTableWindow)
{
    ui->setupUi(this);

    routeTableWorker = new RouteTableWorker();
    routeTableThread = new QThread();
    routeTableWorker->moveToThread(routeTableThread);
    routeTableThread->start();
    QObject::connect(routeTableThread, &QThread::started, this, &RoutingTableWindow::onRouteTableThreadStarted);
    QObject::connect(routeTableThread, &QThread::started, routeTableWorker, &RouteTableWorker::routeTableProcess);
    QObject::connect(routeTableWorker, &RouteTableWorker::routeTableProgress, this, &RoutingTableWindow::showRouteTableInfo);
    QObject::connect(routeTableWorker, &RouteTableWorker::finished, routeTableThread, &QThread::quit);
    QObject::connect(routeTableThread, &QThread::finished, routeTableWorker, &QObject::deleteLater);
    QObject::connect(routeTableThread, &QThread::finished, routeTableThread, &QObject::deleteLater);
    QObject::connect(routeTableWorker, &RouteTableWorker::finished, this, &RoutingTableWindow::onRouteTableThreadFinished);

}

void RoutingTableWindow::onRouteTableThreadStarted() {
    qDebug() << "라우터 테이블 스레드 시작";
}

void RoutingTableWindow::onRouteTableThreadFinished() {
    qDebug() << "라우터 테이블 스레드 종료";
}



void RoutingTableWindow::showRouteTableInfo(RouteTable* table) {
    ui->routingTable->setRowCount(0);
    for(RouteTableEntry& entry : table->routeTable) {
        int row = ui->routingTable->rowCount();
        ui->routingTable->insertRow(row);

        ui->routingTable->setItem(row, 0, new QTableWidgetItem(entry.destIPAddress));
        ui->routingTable->setItem(row, 1, new QTableWidgetItem(entry.subnetMask));
        ui->routingTable->setItem(row, 2, new QTableWidgetItem(QString::number(entry.inIndex)));
        ui->routingTable->setItem(row, 3, new QTableWidgetItem(entry.nextHop));
    }
}



RoutingTableWindow::~RoutingTableWindow()
{
    delete ui;
}
