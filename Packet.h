//
//  Packet.h
//  test
//
//  Created by Andrea Carrara on 18/07/23.
//  Copyright © 2023 Andrea Carrara. All rights reserved.
//

#ifndef Packet_h
#define Packet_h


class Packet {
public:
    int sender;
    int number;
    int txtime;
    int retransmission;
    int payload;
};

#endif /* Packet_h */
