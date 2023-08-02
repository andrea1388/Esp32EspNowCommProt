#include "HomeNetwork.h"
HomeNetwork::HomeNetwork(/* args */)
{
    //espnow.cbNewMsg=newMsg;
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
