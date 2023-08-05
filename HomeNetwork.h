#pragma once
#include "EspNow.h"
#define PANELTEMP 1

class HomeNetwork
{
private:
    EspNow& espnow;

public:    
    HomeNetwork(EspNow&);
    ~HomeNetwork();
    void (*cbRxPanelTemp)(float);
    bool txPanelTemp(float);
    void (*rxPanelTemp)(float);
    void newMsg(Msg&);
};


