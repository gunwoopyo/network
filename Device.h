#ifndef DEVICE_H
#define DEVICE_H
#include <QString>


class Device {
public:
    QString deviceIP;
    QString deviceMAC;

    void fetchDeviceInfo();

};



#endif // DEVICE_H
