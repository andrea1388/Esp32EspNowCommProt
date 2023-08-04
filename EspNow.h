#ifndef EspNow_h
#define EspNow_h
#include <vector>
#include "Packet.h"
#define MAXPKTSTOSENDSIZE 10
#define NUMBEROFRETRANSMISSION 1

using namespace std;
class EspNow
{
    public:
        void begin(uint8_t);
        bool tx(const Msg& msg);
            vector<Packet> packetstosend;
    private:
        uint8_t nodeid; // node address
        uint8_t pktnumber=0; // pkt sequence number
        void (*cbNewMsg)(Msg&)=0;
        vector<Packet> receivedpackets;
};
#endif
