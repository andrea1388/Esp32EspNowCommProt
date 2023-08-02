#pragma once
#include "EspNow.h"
#define PANELTEMP 1

class HomeNetwork
{
private:
    /* data */
    EspNow espnow;

public:
    HomeNetwork(/* args */);
    ~HomeNetwork();
    void (*cbRxPanelTemp)(float);
    bool txPanelTemp(float);
    void newMsg(Msg&);
};


