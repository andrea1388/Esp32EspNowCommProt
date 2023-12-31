#include "Msg.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

void Msg::setMsg(uint8_t cmd,uint8_t datalen, const void*_data)
{
    len=datalen;
    data=(uint8_t*)malloc(len);
    memcpy(data,_data,datalen);
}


Msg& Msg::operator=(const Msg &m)
{
    data=(uint8_t*)malloc(m.len);
    memcpy(data,m.data,m.len);
    len=m.len;
    cmd=m.cmd;
    return *this;
}

Msg::~Msg()
{
    if(data) free(data);
    std::cout << "~Msg\n";
}
