#ifndef TRAFFIC_H
#define TRAFFIC_H

#include <QString>
class Traffic {
public:
    quint32 inOctet;
    quint32 outOctet;
    quint32 inPacket;
    quint32 outPacket;


    quint32 InBPS = 0;
    quint32 OutBps = 0;
    quint32 InPPS = 0;
    quint32 OutPPS = 0;

    QString loadStatus;
};



#endif // TRAFFIC_H









