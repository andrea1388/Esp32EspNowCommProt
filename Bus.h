//
//  Bus.h
//  test
//
//  Created by Andrea Carrara on 18/07/23.
//  Copyright © 2023 Andrea Carrara. All rights reserved.
//


#ifndef Bus_h
#define Bus_h
#include<vector>
#include "Node.h"
#include "Packet.h"
using namespace std;
class Node;
class Packet;
class Bus {
    public:
    vector<Node> nodes;
    void send(Packet& p);
};
#endif /* Bus_h */


