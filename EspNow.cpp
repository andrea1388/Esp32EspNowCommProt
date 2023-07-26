#include "EspNow.h"
#include "Msg.h"

void EspNow::begin()
{
}

void EspNow::cbNewPacket(void cbrx(const Msg &msg))
{
}

void EspNow::tx(const Msg &msg)
{
    Packet p;
    p.setMsg(msg);
    packetstosend.push_back(std::move(p));
    
}
