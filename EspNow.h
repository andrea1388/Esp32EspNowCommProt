#ifndef EspNow_h
#define EspNow_h
#include <vector>
#include "esp_now.h"
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
        void (*cbNewMsg)(Msg&)=0;
    private:
        uint8_t nodeid; // node address
        uint8_t pktnumber=0; // pkt sequence number
        vector<Packet> receivedpackets;
        esp_now_recv_cb_t recv_cb;
        esp_now_send_cb_t send_cb;
};
#endif
