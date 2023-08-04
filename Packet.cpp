#include "Packet.h"

Packet::Packet()
{
    retransmission=0;
}

Packet::Packet(const Packet &p)
{
    sender=p.sender;
    number=p.number;
    txtime=p.txtime;
    msg=p.msg;
}
