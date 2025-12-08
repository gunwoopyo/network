#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include "RouterWorker.h"
#include "Port.h"
#include <QDebug>


class Traffic;
void Port::fetchTrafficInfo() {

    snmp_session session;
    snmp_sess_init(&session);
    session.peername = strdup(Router::routerPtr->routerIP.toStdString().c_str());
    session.version = SNMP_VERSION_2c;
    session.community = (u_char*)strdup(Router::routerPtr->routerCommunity.toStdString().c_str());
    session.community_len = Router::routerPtr->routerCommunity.length();

    snmp_session *ss = snmp_open(&session);

    oid inOctetOID[] = {1,3,6,1,2,1,2,2,1,10,(oid)ifIndex};   // inOctet
    oid outOctetOID[] = {1,3,6,1,2,1,2,2,1,16,(oid)ifIndex};  // outOctet
    oid inPacketOID[] = {1,3,6,1,2,1,2,2,1,11,(oid)ifIndex};  //inPacket
    oid outPacketOID[] = {1,3,6,1,2,1,2,2,1,17,(oid)ifIndex};      //outPacket

    Traffic traffic;
    traffic.inOctet = Router::getSnmpInteger(ss, inOctetOID, OID_LENGTH(inOctetOID));
    traffic.outOctet = Router::getSnmpInteger(ss, outOctetOID, OID_LENGTH(outOctetOID));
    traffic.inPacket = Router::getSnmpInteger(ss, inPacketOID, OID_LENGTH(inPacketOID));
    traffic.outPacket = Router::getSnmpInteger(ss, outPacketOID, OID_LENGTH(outPacketOID));

    trafficBuffer.append(traffic);
    if(trafficBuffer.size() > 50) {
        trafficBuffer.removeFirst();
        }

    snmp_close(ss);
    SOCK_CLEANUP;
}

void Port::calculateBPSPPS() {
    Traffic &lastTraffic = trafficBuffer.last();   //   포트의 마지막 트래픽버퍼

    if(secondRead) {   // 포트 2바퀴에 진입
        quint32 deltaInBytes = lastTraffic.inOctet - trafficBuffer[trafficBuffer.size()-2].inOctet;
        quint32 deltaOutBytes = lastTraffic.outOctet - trafficBuffer[trafficBuffer.size()-2].outOctet;
        quint32 deltaInPackets = lastTraffic.inPacket - trafficBuffer[trafficBuffer.size()-2].inPacket;
        quint32 deltaOutPackets = lastTraffic.outPacket - trafficBuffer[trafficBuffer.size()-2].outPacket;

        lastTraffic.InBPS = (deltaInBytes * 8)  / 5.0;
        lastTraffic.OutBps = (deltaOutBytes * 8) / 5.0;
        lastTraffic.InPPS = deltaInPackets / 5.0;
        lastTraffic.OutPPS = deltaOutPackets / 5.0;

        thirdRead = true;
    }

    if(secondRead == false) {
         secondRead = true;
    }
}

void Port::calculateLoadStatus() {

    Traffic &lastTraffic = trafficBuffer.last();   //   포트의 마지막 트래픽버퍼
    if(thirdRead == true) {
        if(lastTraffic.InBPS != 0 && trafficBuffer[trafficBuffer.size() - 2].InBPS != 0) {

            if (lastTraffic.InBPS < trafficBuffer[trafficBuffer.size() - 2].InBPS * 1.25) {
                lastTraffic.loadStatus = "normal";
            }
            else if (lastTraffic.InBPS < trafficBuffer[trafficBuffer.size() - 2].InBPS * 1.5) {
                lastTraffic.loadStatus = "warning";
            }
            else
                lastTraffic.loadStatus = "danger";
        }
    }
}


void Port::fetchPortInfo() {

    snmp_session session;
    snmp_sess_init(&session);
    session.peername = strdup(Router::routerPtr->routerIP.toStdString().c_str());
    session.version = SNMP_VERSION_2c;
    session.community = (u_char*)strdup(Router::routerPtr->routerCommunity.toStdString().c_str());
    session.community_len = Router::routerPtr->routerCommunity.length();

    snmp_session *ss = snmp_open(&session);


    oid adminOID[] = {1,3,6,1,2,1,2,2,1,7,(oid)ifIndex}; // 관리자 포트관리 상태
    oid operOID[] = {1,3,6,1,2,1,2,2,1,8,(oid)ifIndex};     // 동작 상태
    oid macOID[] = {1,3,6,1,2,1,2,2,1,6,(oid)ifIndex}; // MAC 주소

    portAdminStatus = Router::getSnmpInteger(ss, adminOID, OID_LENGTH(adminOID));
    portOperStatus = Router::getSnmpInteger(ss, operOID, OID_LENGTH(operOID));

    netsnmp_pdu* macPDU = snmp_pdu_create(SNMP_MSG_GET);
    snmp_add_null_var(macPDU, macOID, OID_LENGTH(macOID));
    netsnmp_pdu* macResponse = nullptr;
    snmp_synch_response(ss, macPDU, &macResponse);
    unsigned char* mac = macResponse->variables->val.string;
    QStringList macParts;
    for (int i = 0; i < 6; ++i)
        macParts << QString::asprintf("%02X", mac[i]);
    macAddress = macParts.join(":");


    snmp_free_pdu(macResponse);


    snmp_close(ss);
    SOCK_CLEANUP;
}














