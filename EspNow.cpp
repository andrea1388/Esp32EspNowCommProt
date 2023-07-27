#include "EspNow.h"
#include "Msg.h"

void EspNow::begin(uint8_t _nid)
{
    nodeid=_nid;
}

void EspNow::cbNewPacket(void cbrx(const Msg &msg))
{
}

true EspNow::tx(const Msg &msg)
{
    if(packetstosend.size()>MAXPKTSTOSENDSIZE) return false;
    Packet p;
    p.sender=nodeid;
    p.number=pktnumber++;
    p.retransmission=0;
    p.setMsg(msg);
    packetstosend.push_back(std::move(p));
    Packet p1;
    p1.sender=nodeid;
    p1.number=p.number;
    p1.retransmission=p.retransmission+1;
    p1.setMsg(msg);
    packetstosend.push_back(std::move(p1));
    return true;
}
