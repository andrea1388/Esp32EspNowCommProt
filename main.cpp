//
//  main.cpp
//  test
//
//  Created by Andrea Carrara on 18/07/23.
//  Copyright © 2023 Andrea Carrara. All rights reserved.
//

#include <iostream>
#define NUMNODE 3
#define TXRNDTIME 10 //ms
#define RXERROR 0.5
#include<list>
#include<vector>
#include <unistd.h>
#include "Bus.h"
#include "Node.h"
#include "Packet.h"

using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Comm Prot test\n";
    Bus bus;
    
    
    for (int i=0;i<NUMNODE;i++) {
        bus.nodes.push_back(*new Node(i,&bus));
        //nodelist.push_back(new Node(i,bus)); //node id, bus
    }

    bus.nodes[0].sendtemp(3);
    bus.nodes[0].sendPackets();
    bus.nodes[1].sendPackets();
    
    while(true) {
        for (int i=0;i<NUMNODE;i++) {
            bus.nodes[i].sendPackets();
        }
        sleep(1);
    }
    return 0;
}
