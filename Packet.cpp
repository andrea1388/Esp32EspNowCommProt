#include "Packet.h"

Packet::Packet()
{
    retransmission=0;
}
Packet::Packet(const Packet &p)
{
    sender=p.sender;
    msg=p.msg;
    return *this;
}