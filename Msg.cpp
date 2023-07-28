#include "Msg.h"
Msg::setMsg(uint8_t cmd,uint8_t datalen, const void*_data)
{
    len=datalen;
    data=malloc(len);
    memcpy(data,_data,datalen);
}

Msg::~Msg(uint8_t cmd,uint8_t datalen, const void*_data)
{
    if(data) free(data);
}