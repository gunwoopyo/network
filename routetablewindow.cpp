#include <QDebug>

#include "routetablewindow.h"
#include "ui_routetablewindow.h"
#include "RouteTableWorker.h"
#include "RouteTable.h"


RouteTableWindow::RouteTableWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RouteTableWindow)
{
    ui->setupUi(this);

    routeTableWorker = new RouteTableWorker();
    routeTableThread = new QThread();
    routeTableWorker->moveToThread(routeTableThread);
    routeTableThread->start();
    QObject::connect(routeTableThread, &QThread::started, this, &RouteTableWindow::onRouteTableThreadStarted);
    QObject::connect(routeTableThread, &QThread::started, routeTableWorker, &RouteTableWorker::routeTableProcess);
    QObject::connect(routeTableWorker, &RouteTableWorker::routeTableProgress, this, &RouteTableWindow::showRouteTableInfo);
    QObject::connect(routeTableWorker, &RouteTableWorker::finished, routeTableThread, &QThread::quit);
    QObject::connect(routeTableThread, &QThread::finished, routeTableWorker, &QObject::deleteLater);
    QObject::connect(routeTableThread, &QThread::finished, routeTableThread, &QObject::deleteLater);
    QObject::connect(routeTableWorker, &RouteTableWorker::finished, this, &RouteTableWindow::onRouteTableThreadFinished);
}

void RouteTableWindow::onRouteTableThreadStarted() {
    qDebug() << "라우터 테이블 스레드 시작";
}

void RouteTableWindow::onRouteTableThreadFinished() {
    qDebug() << "라우터 테이블 스레드 종료";
}



RouteTableWindow::~RouteTableWindow()
{
    delete ui;
}



void RouteTableWindow::showRouteTableInfo(RouteTable* table) {



}
