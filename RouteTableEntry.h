#ifndef ROUTETABLEENTRY_H
#define ROUTETABLEENTRY_H

#include <QString>

class RouteTableEntry {
public:
    int inIndex;
    QString destIPAddress;
    QString subnetMask;
    QString nextHop;
};


#endif // ROUTETABLEENTRY_H


