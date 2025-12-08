#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>

#include "ArpTable.h"
#include "RouterWorker.h"

void ArpTable::fetchArpTableInfo() {
    snmp_session session;
    snmp_sess_init(&session);
    session.peername = strdup(Router::routerPtr->routerIP.toStdString().c_str());
    session.version = SNMP_VERSION_2c;
    session.community = (u_char*)strdup(Router::routerPtr->routerCommunity.toStdString().c_str());
    session.community_len = Router::routerPtr->routerCommunity.length();
    snmp_session *ss = snmp_open(&session);

    oid macOID[] = {1,3,6,1,2,1,4,22,1,2};
    size_t macOIDLen = OID_LENGTH(macOID);
    oid currentMacOID[MAX_OID_LEN];
    size_t currentMacOIDLen = macOIDLen;
    memcpy(currentMacOID, macOID, macOIDLen * sizeof(oid));

    oid typeOID[] = {1,3,6,1,2,1,4,22,1,4};
    size_t typeOIDLen = OID_LENGTH(typeOID);
    oid currentTypeOID[MAX_OID_LEN];
    size_t currentTypeOIDLen = typeOIDLen;
    memcpy(currentTypeOID, typeOID, typeOIDLen * sizeof(oid));

    while(true) {
        netsnmp_pdu* macPDU = snmp_pdu_create(SNMP_MSG_GETNEXT);
        snmp_add_null_var(macPDU, currentMacOID, currentMacOIDLen);
        netsnmp_pdu* macResponse = nullptr;
        snmp_synch_response(ss, macPDU, &macResponse);

        netsnmp_pdu* typePDU = snmp_pdu_create(SNMP_MSG_GETNEXT);
        snmp_add_null_var(typePDU, currentTypeOID, currentTypeOIDLen);
        netsnmp_pdu* typeResponse = nullptr;
        snmp_synch_response(ss, typePDU, &typeResponse);



        if (snmp_oid_compare(macOID, macOIDLen, macResponse->variables->name, macOIDLen) != 0) {
            snmp_free_pdu(macResponse);
            break;
        }

        unsigned char* mac = macResponse->variables->val.string;
        QStringList macParts;
        for (int i = 0; i < 6; ++i)
            macParts << QString::asprintf("%02X", mac[i]);

        ArpTableEntry portEntry;
        portEntry.ifIndex = macResponse->variables->name[macResponse->variables->name_length - 5];




        portEntry.IPAddress = QString("%1.%2.%3.%4")
                             .arg(macResponse->variables->name[macResponse->variables->name_length - 4])
                             .arg(macResponse->variables->name[macResponse->variables->name_length - 3])
                             .arg(macResponse->variables->name[macResponse->variables->name_length - 2])
                             .arg(macResponse->variables->name[macResponse->variables->name_length - 1]);
        portEntry.macAddress = macParts.join(":");
        portEntry.type = *(typeResponse->variables->val.integer);

        arpTable.append(portEntry);

        memcpy(currentMacOID, macResponse->variables->name, macResponse->variables->name_length * sizeof(oid));
        currentMacOIDLen = macResponse->variables->name_length;

        memcpy(currentTypeOID, typeResponse->variables->name, typeResponse->variables->name_length * sizeof(oid));
        currentTypeOIDLen = typeResponse->variables->name_length;



        snmp_free_pdu(macResponse);
    }

    snmp_close(ss);
    SOCK_CLEANUP;
}







