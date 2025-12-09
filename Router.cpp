#include "RouteWorker.h"
#include "Router.h"

#include <QDebug>

Router* Router::routerPtr = nullptr;

quint32 Router::getSnmpInteger(netsnmp_session* ss, const oid* oidArr, size_t oidLen) {
    netsnmp_pdu* pdu = snmp_pdu_create(SNMP_MSG_GET);
    snmp_add_null_var(pdu, const_cast<oid*>(oidArr), oidLen);

    netsnmp_pdu* response = nullptr;
    snmp_synch_response(ss, pdu, &response);

    quint32 value = *(response->variables->val.integer);

    snmp_free_pdu(response);
    return value;
}
QString Router::getSnmpString(netsnmp_session* ss, const oid* oidArr, size_t oidLen) {
    netsnmp_pdu* pdu = snmp_pdu_create(SNMP_MSG_GET);
    snmp_add_null_var(pdu, const_cast<oid*>(oidArr), oidLen);

    netsnmp_pdu* response = nullptr;
    snmp_synch_response(ss, pdu, &response);

    QString result = QString::fromUtf8((char*)response->variables->val.string, response->variables->val_len);

    snmp_free_pdu(response);
    return result;
}



void Router::fetchRouterInfo() {

    snmp_session session;
    snmp_sess_init(&session);

    session.peername = strdup(routerIP.toStdString().c_str());
    session.version = SNMP_VERSION_2c;
    session.community = (u_char*)strdup(routerCommunity.toStdString().c_str());
    session.community_len = routerCommunity.length();


    snmp_session *ss = snmp_open(&session);

    oid sysNameOID[] = {1,3,6,1,2,1,1,5,0}; // 라우터 이름
    oid cpuOID[] = {1,3,6,1,4,1,9,2,1,58,0}; // CPU부하율
    oid timeOID[] = {1,3,6,1,2,1,1,3,0};     // 장비 작동 시간
    oid usedMemoryOID[] = {1,3,6,1,4,1,9,9,48,1,1,1,5,1}; // 사용한 메모리
    oid freeMemoryOID[] = {1,3,6,1,4,1,9,9,48,1,1,1,6,1};

    Router::routerPtr->routerName = getSnmpString(ss, sysNameOID, OID_LENGTH(sysNameOID));
    Router::routerPtr->cpu = getSnmpInteger(ss, cpuOID, OID_LENGTH(cpuOID));
    Router::routerPtr->time = getSnmpInteger(ss, timeOID, OID_LENGTH(timeOID));
    quint32 usedMemory = getSnmpInteger(ss, usedMemoryOID, OID_LENGTH(usedMemoryOID));
    quint32 freeMemory = getSnmpInteger(ss, freeMemoryOID, OID_LENGTH(freeMemoryOID));
    Router::routerPtr->memory = usedMemory * 100.0 / (usedMemory + freeMemory);



    snmp_close(ss);
    SOCK_CLEANUP;
}


void Router::createPort() {
    qDebug() <<"###";
    snmp_session session;
    snmp_sess_init(&session);

    session.peername = strdup(routerIP.toStdString().c_str());
    session.version = SNMP_VERSION_2c;
    session.community = (u_char*)strdup(routerCommunity.toStdString().c_str());
    session.community_len = routerCommunity.length();
    snmp_session *ss = snmp_open(&session);


    //인터페이스 이름
    oid ifDescrOID[] = {1,3,6,1,2,1,2,2,1,2};
    size_t ifDescrOIDLength = OID_LENGTH(ifDescrOID);
    oid currentOID[MAX_OID_LEN];
    size_t currentOIDLength = ifDescrOIDLength;

    memcpy(currentOID, ifDescrOID, ifDescrOIDLength * sizeof(oid));

    while(true) {
        netsnmp_pdu* pdu = snmp_pdu_create(SNMP_MSG_GETNEXT);
        snmp_add_null_var(pdu, currentOID, currentOIDLength);
        netsnmp_pdu* response = nullptr;
        snmp_synch_response(ss, pdu, &response);


        if (snmp_oid_compare(ifDescrOID, ifDescrOIDLength, response->variables->name, ifDescrOIDLength) != 0) {
            snmp_free_pdu(response);
            break;
        }

        Port port;
        port.portName = QString::fromUtf8((char*)response->variables->val.string, response->variables->val_len);
        port.ifIndex = response->variables->name[response->variables->name_length - 1];

        ports.append(port);

        memcpy(currentOID, response->variables->name, sizeof(oid)*response->variables->name_length);
        currentOIDLength = response->variables->name_length;
        snmp_free_pdu(response);
    }


    snmp_close(ss);
    SOCK_CLEANUP;
}
























