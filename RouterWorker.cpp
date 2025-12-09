#include "RouterWorker.h"

#include <QDebug>

void RouterWorker::routerProcess() {

    Router* routerAddress = Router::routerPtr;
    routerAddress->createPort();  //port, portName, ifIndex
    emit ready();

    routerAddress->fetchRouterInfo(); //routerName, cpu, time, memory
    emit routerProgress(routerAddress);
    emit finished();
}





