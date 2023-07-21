#include "Node.h"
#include "Bus.h"
#include<vector>
#include <time.h>
#include <stdlib.h>
#define MAXDELAY 100
#define TX1 60000
using namespace std;
extern uint32_t now();

Node::Node(int _id, Bus* _bus)
{
    id=_id;
    bus=_bus;
    srand(time(NULL));
}

int randomDelayInMs()
{
    return MAXDELAY*rand()/RAND_MAX;
}

void Node::sendtemp(int payload) 
{
    Packet p;
    p.payload=payload;
    p.sender=id;
    p.number=pktnumber++;
    p.retransmission=0;
    p.txtime=now()+randomDelayInMs();
    packetstosend.push_back(p);
    p.txtime=now()+TX1+randomDelayInMs();
    p.retransmission=1;
    //packetstosend.push_back(p);
    printpacketstosend();
}

void Node::printpacketstosend()
{
    printf("node: %u, packetstosend: %u\n",id,packetstosend.size());
}

void Node::printpacketreceived()
{
    printf("node: %u, receivedpackets: %u\n",id,receivedpackets.size());
}

void Node::sendPackets() {
/*     for (int i=0;i<packetstosend.size();i++) {
        if(packetstosend[i].txtime>now()) bus.send(packetstosend[i]);
        packetstosend.erase(packetstosend[i]);
    } */

    //for (vector<Packet>::iterator it = packetstosend.begin(); it != packetstosend.end(); ++it)
    vector<Packet>::iterator it=packetstosend.begin();
    while(it != packetstosend.end())
    {
        if(now() > it->txtime)
        {
            for(Node n: bus->nodes)
            {
                if(n.id!=id) n.rx(*it);
            }
            packetstosend.erase(it);
        }
    }
    printpacketreceived();
    printpacketstosend();
}
    
void Node::rx(const Packet& pr)
{
    printf("RX node: %u, packet#: %u, from: %u, retrans: %u\n",id,pr.number,pr.sender,pr.retransmission);
    for (int i=0;i<receivedpackets.size();i++) {
        Packet p=receivedpackets[i];
        if( pr.sender==p.sender && pr.number==p.number && pr.retransmission==p.retransmission) return;
    }

    packetstosend.push_back(pr);
    
    bool inlist=false;
    for (int i=0;i<receivedpackets.size();i++) {
        Packet p=receivedpackets[i];
        if(pr.sender==p.sender && pr.number==p.number) inlist=true;
    }
    if(!inlist) process(pr);
    receivedpackets.push_back(pr);
    printpacketreceived();
    printpacketstosend();
}

void Node::process(const Packet& p)
{
    printf("node: %u. Got packet#: %u from node: %u\n",id,p.number,p.sender );
    return;
}
