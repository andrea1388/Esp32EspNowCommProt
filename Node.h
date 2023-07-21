//
//  Node.h
//  test
//
//  Created by Andrea Carrara on 18/07/23.
//  Copyright © 2023 Andrea Carrara. All rights reserved.
//

#ifndef Node_h
#define Node_h
#include "Bus.h"
#include <vector>
#include "Packet.h"
using namespace std;
class Bus;

class Node {
public:
    int id; // node address
    int pktnumber=0; // pkt sequence number
    Bus* bus;
    vector<Packet> packetstosend;
    vector<Packet> receivedpackets;

    Node(int, Bus*);
    void process(const Packet&);
    void sendtemp(int); // send node temp
    void sendPackets(); // process outgoing queue and transmit
    void rx(const Packet& p); // rx a new packet from the bus
    void printpacketstosend();
    void printpacketreceived();
};

#endif /* Node_h */
