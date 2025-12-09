#include <QDebug>

#include "routetablewindow.h"
#include "ui_routetablewindow.h"
#include "RouteTableWorker.h"
#include "RouteTable.h"


routetablewindow::routetablewindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::routetablewindow)
{
    ui->setupUi(this);

    routeTableWorker = new RouteTableWorker();
    routeTableThread = new QThread();
    routeTableWorker->moveToThread(routeTableThread);
    routeTableThread->start();
    QObject::connect(routeTableThread, &QThread::started, this, &routetablewindow::onRouteTableThreadStarted);
    QObject::connect(routeTableThread, &QThread::started, routeTableWorker, &RouteTableWorker::routeTableProcess);
    QObject::connect(routeTableWorker, &RouteTableWorker::routeTableProgress, this, &routetablewindow::showRouteTableInfo);
    QObject::connect(routeTableWorker, &RouteTableWorker::finished, routeTableThread, &QThread::quit);
    QObject::connect(routeTableThread, &QThread::finished, routeTableWorker, &QObject::deleteLater);
    QObject::connect(routeTableThread, &QThread::finished, routeTableThread, &QObject::deleteLater);
    QObject::connect(routeTableWorker, &RouteTableWorker::finished, this, &routetablewindow::onRouteTableThreadFinished);
}

void routetablewindow::onRouteTableThreadStarted() {
    qDebug() << "라우터 테이블 스레드 시작";
}

void routetablewindow::onRouteTableThreadFinished() {
    qDebug() << "라우터 테이블 스레드 종료";
}



routetablewindow::~routetablewindow()
{
    delete ui;
}



void routetablewindow::showRouteTableInfo(RouteTable* table) {



}
