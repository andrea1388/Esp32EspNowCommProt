#ifndef EspNow_h
#define EspNow_h
#include <vector>
#include "Packet.h"
using namespace std;
class EspNow
{
    public:
        void begin(uint8_t);
        void cbNewPacket(void cbrx(const Msg& msg));
        bool tx(const Msg& msg);
        void txPanelTemp(float);
    private:
        uint8_t nodeid; // node address
        uint8_t pktnumber=0; // pkt sequence number
        vector<Packet> packetstosend;
        vector<Packet> receivedpackets;
};
#endif