#include "RouteWorker.h"
#include "PortWorker.h"



void PortWorker::portProcess() {
    Router* router = Router::routerPtr;

    for(Port &port : router->ports) {
        port.fetchPortInfo(); //portAdminStatus, portOperStatus, MAC 주소
        emit portViewProgress(router);  // by portOperStatus


        port.fetchTrafficInfo();  //inOctet, outOctet
        port.calculateBPSPPS();   //BPS,PPS,부하 계산
        emit portInfoProgress(&port);

        port.calculateLoadStatus();

    }

    emit loadInfoProgress(router);
    timer->singleShot(5000, this, &PortWorker::portProcess);
}






