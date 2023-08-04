#include "HomeNetwork.h"
HomeNetwork::HomeNetwork(/* args */)
{
    espnow.cbNewMsg=newMsg;
}

HomeNetwork::~HomeNetwork()
{
}

bool HomeNetwork::txPanelTemp(float temp)
{
    union {
        float f;
        unsigned char bytes[sizeof(float)];
    } u;
    u.f=temp;
    Msg m;
    m.setMsg(PANELTEMP,sizeof(float),u.bytes);
    return espnow.tx(m);
}

// receice messages from espnow layer
// extract info and call corresponding callback function of the app level
void HomeNetwork::newMsg(Msg &m)
{
    if(m.cmd==PANELTEMP)
    {
        if(rxPanelTemp) (rxPanelTemp)(t);
    }
}
