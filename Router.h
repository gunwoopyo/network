#ifndef ROUTER_H
#define ROUTER_H
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include "Port.h"

class Router {
private:

public:
    QString routerName;
    QString routerIP;
    QString routerCommunity;
    int cpu;
    double memory;
    quint32 time;


    QVector<Port> ports;

    static Router* routerPtr;

    explicit Router(const QString &routerIPAddress, const QString &community)
        : routerIP(routerIPAddress), routerCommunity(community) { }

    void createPort();
    void fetchRouterInfo();





    static quint32 getSnmpInteger(netsnmp_session* ss, const oid* oidArr, size_t oidLen);
    static QString getSnmpString(netsnmp_session* ss, const oid* oidArr, size_t oidLen);

};



#endif // ROUTER_H
