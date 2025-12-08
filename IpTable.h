#ifndef IPTABLE_H
#define IPTABLE_H


#include <QVector>
#include "IpTableEntry.h"

class IpTable {

public:
    QVector<IpTableEntry> ipTable;

    void fetchIpTableInfo();


};














#endif // IPTABLE_H
