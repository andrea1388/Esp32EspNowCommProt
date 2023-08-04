#include "EspNow.h"
#include "Msg.h"
#include <cstdint>

void EspNow::begin(uint8_t _nid)
{
    nodeid=_nid;
}


bool EspNow::tx(const Msg &pp)
{
    if(packetstosend.size()>MAXPKTSTOSENDSIZE) return false;

    for(uint8_t i=0;i<NUMBEROFRETRANSMISSION;i++)
    {
        Packet p;
        p.sender=nodeid;
        p.number=pktnumber;
        p.retransmission=0;
        //p.msg.setMsg(pp.cmd,pp.len,pp.data);
        p.msg=pp;
        //p.txtime=now()+delay[i]+randomDelayInMs();
        packetstosend.push_back(p);
    }
    pktnumber++;
    return true;
}
