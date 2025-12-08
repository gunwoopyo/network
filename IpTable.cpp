#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <QDebug>
#include "IpTable.h"
#include "RouterWorker.h"



void IpTable::fetchIpTableInfo() {
    snmp_session session;
    snmp_sess_init(&session);
    session.peername = strdup(Router::routerPtr->routerIP.toStdString().c_str());
    session.version = SNMP_VERSION_2c;
    session.community = (u_char*)strdup(Router::routerPtr->routerCommunity.toStdString().c_str());
    session.community_len = Router::routerPtr->routerCommunity.length();
    snmp_session *ss = snmp_open(&session);

    //ip
    oid ipOID[] = {1,3,6,1,2,1,4,20,1,1};
    size_t ipOIDLen = OID_LENGTH(ipOID);
    oid currentIpOID[MAX_OID_LEN];
    size_t currentIpOIDLen = ipOIDLen;
    memcpy(currentIpOID, ipOID, ipOIDLen * sizeof(oid));

    //ifIndex
    oid ifIndexOID[] = {1,3,6,1,2,1,4,20,1,2};
    size_t ifIndexOIDLen = OID_LENGTH(ifIndexOID);
    oid currentIfIndexOID[MAX_OID_LEN];
    size_t currentIfIndexOIDLen = ifIndexOIDLen;
    memcpy(currentIfIndexOID, ifIndexOID, ifIndexOIDLen * sizeof(oid));

    //subnet
    oid subnetOID[] = {1,3,6,1,2,1,4,20,1,3};
    size_t subnetOIDLen = OID_LENGTH(subnetOID);
    oid currentSubnetOID[MAX_OID_LEN];
    size_t currentSubnetOIDLen = subnetOIDLen;
    memcpy(currentSubnetOID, subnetOID, subnetOIDLen * sizeof(oid));

    //broadcast
    oid broadcastOID[] = {1,3,6,1,2,1,4,20,1,4};
    size_t broadcastOIDLen = OID_LENGTH(broadcastOID);
    oid currentBroadcastOID[MAX_OID_LEN];
    size_t currentBroadcastOIDLen = broadcastOIDLen;
    memcpy(currentBroadcastOID, broadcastOID, broadcastOIDLen * sizeof(oid));

    while(true) {
        netsnmp_pdu* ipPDU = snmp_pdu_create(SNMP_MSG_GETNEXT);
        snmp_add_null_var(ipPDU, currentIpOID, currentIpOIDLen);
        netsnmp_pdu* ipResponse = nullptr;
        snmp_synch_response(ss, ipPDU, &ipResponse);
        netsnmp_variable_list* ipVars = ipResponse->variables;

        netsnmp_pdu* ifIndexPDU = snmp_pdu_create(SNMP_MSG_GETNEXT);
        snmp_add_null_var(ifIndexPDU, ifIndexOID, currentIfIndexOIDLen);
        netsnmp_pdu* ifIndexResponse = nullptr;
        snmp_synch_response(ss, ifIndexPDU, &ifIndexResponse);
        netsnmp_variable_list* ifIndexVars = ifIndexResponse->variables;

        netsnmp_pdu* subnetPDU = snmp_pdu_create(SNMP_MSG_GETNEXT);
        snmp_add_null_var(subnetPDU, subnetOID, currentSubnetOIDLen);
        netsnmp_pdu* subnetResponse = nullptr;
        snmp_synch_response(ss, subnetPDU, &subnetResponse);
        netsnmp_variable_list* subnetVars = subnetResponse->variables;

        netsnmp_pdu* broadcastPDU = snmp_pdu_create(SNMP_MSG_GETNEXT);
        snmp_add_null_var(broadcastPDU, broadcastOID, currentBroadcastOIDLen);
        netsnmp_pdu* broadcastResponse = nullptr;
        snmp_synch_response(ss, broadcastPDU, &broadcastResponse);
        netsnmp_variable_list* broadcastVars = broadcastResponse->variables;

        if (snmp_oid_compare(ipOID, ipOIDLen, ipVars->name, ipOIDLen) != 0) {
            snmp_free_pdu(ipResponse);
            break;
        }

        IpTableEntry ipTableEntry;
        ipTableEntry.ifIndex = *(ifIndexVars->val.integer);
        ipTableEntry.broadcast = *(broadcastVars->val.integer);
        ipTableEntry.IPAddress = QString("%1.%2.%3.%4")
                                  .arg(ipVars->name[ipVars->name_length - 4])
                                  .arg(ipVars->name[ipVars->name_length - 3])
                                  .arg(ipVars->name[ipVars->name_length - 2])
                                  .arg(ipVars->name[ipVars->name_length - 1]);
        ipTableEntry.subnetMask = QString("%1.%2.%3.%4")
                                      .arg(subnetVars->name[subnetVars->name_length - 4])
                                      .arg(subnetVars->name[subnetVars->name_length - 3])
                                      .arg(subnetVars->name[subnetVars->name_length - 2])
                                      .arg(subnetVars->name[subnetVars->name_length - 1]);

        ipTable.append(ipTableEntry);
        memcpy(currentIpOID, ipVars->name, ipVars->name_length * sizeof(oid));
        currentIpOIDLen = ipVars->name_length;

        memcpy(currentIfIndexOID, ifIndexVars->name, ifIndexVars->name_length * sizeof(oid));
        currentIfIndexOIDLen = ifIndexVars->name_length;

        memcpy(currentSubnetOID, subnetVars->name, subnetVars->name_length * sizeof(oid));
        currentSubnetOIDLen = subnetVars->name_length;

        memcpy(currentBroadcastOID, broadcastVars->name, broadcastVars->name_length * sizeof(oid));
        currentBroadcastOIDLen = broadcastVars->name_length;


        snmp_free_pdu(ipResponse);
        snmp_free_pdu(ifIndexResponse);
        snmp_free_pdu(subnetResponse);
        snmp_free_pdu(broadcastResponse);
    }

    snmp_close(ss);
    SOCK_CLEANUP


}






