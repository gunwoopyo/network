#ifndef ARPTABLEENTRY_H
#define ARPTABLEENTRY_H

#include <QString>

class ArpTableEntry {
public:
    int ifIndex;
    QString IPAddress;
    QString macAddress;
    int type;
};



#endif // ARPTABLEENTRY_H




