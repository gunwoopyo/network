
#include "Device.h"
#include "DeviceWorker.h"
#include "RouterWorker.h"
#include "Port.h"

void DeviceWorker::deviceProcess() {

    for(Port &port : RouterWorker::routerPtr->ports) {
        port.device->fetchDeviceInfo();
    }

    for (Port &port : RouterWorker::routerPtr->ports) {
        emit deviceProgress(&port);
    }

    emit finished();


}
