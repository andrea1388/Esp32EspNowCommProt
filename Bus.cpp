#include "Bus.h"
#include "Packet.h"

void Bus::send(Packet& p)
{
    for(int i=0;i<nodes.size();i++)
    {
        nodes[i].rx(p);
    }
}
