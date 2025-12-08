#ifndef PORT_H
#define PORT_H



#include "Traffic.h"

class Port {
public:



    int ifIndex = 0;
    QString portName;
    QString macAddress;
    int portAdminStatus = 0;
    int portOperStatus = 0;

    QVector<Traffic> trafficBuffer;

    bool secondRead = false;
    bool thirdRead = false;

    void fetchPortInfo();
    void fetchTrafficInfo();
    void calculateBPSPPS();
    void calculateLoadStatus();

};



#endif // PORT_H











