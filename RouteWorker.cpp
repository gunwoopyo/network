#include "RouteWorker.h"

#include <QDebug>

void RouterWorker::routerProcess() {
    qDebug() <<Router::routerPtr->routerIP;
    qDebug() <<Router::routerPtr;
    Router* routerAddress = Router::routerPtr;
    routerAddress->createPort();  //portName, ifIndex
    emit ready();

    routerAddress->fetchRouterInfo(); //routerName, cpu, time, memory
    emit routerProgress(routerAddress);
    emit finished();
}





