#include "EspNow.h"
#include "Msg.h"

void EspNow::begin(uint8_t _nid)
{
    nodeid=_nid;
}

void EspNow::cbNewPacket(void cbrx(const Msg &msg))
{
}

bool EspNow::tx(const Msg &pp)
{
    if(packetstosend.size()>MAXPKTSTOSENDSIZE) return false;

    fo(uint8_t i=0;i<NUMBEROFRETRANSMISSION;i++)
    {
        Packet p;
        p.sender=nodeid;
        p.number=pktnumber++;
        p.retransmission=0;
        p.msg.setMsg(pp.cmd,pp.len,pp.data);
        p.txtime=now()+delay[i]+randomDelayInMs();
        packetstosend.push_back(std::move(p));
    }
    pktnumber++;
    return true;
}
