//
//  Packet.h
//  test
//
//  Created by Andrea Carrara on 18/07/23.
//  Copyright © 2023 Andrea Carrara. All rights reserved.
//

#ifndef Packet_h
#define Packet_h
#include "Msg.h"

class Packet {
public:
    uint8_t sender;
    uint8_t number;
    uint32_t txtime;
    uint8_t retransmission;
    Msg msg;
    uint16_t crc;
    setMsg(Msg&);
};

#endif /* Packet_h */
