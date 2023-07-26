#ifndef EspNow_h
#define EspNow_h
#include <vector>
#include "Packet.h"
using namespace std;
class EspNow
{
    public:
        void begin();
        void cbNewPacket(void cbrx(const Msg& msg));
        void tx(const Msg& msg);
    private:
        vector<Packet> packetstosend;
        vector<Packet> receivedpackets;
};
#endif