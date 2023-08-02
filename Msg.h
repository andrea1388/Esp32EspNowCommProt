#pragma once
#include <cstdint>

class Msg 
{
    public:
        uint8_t cmd=0;
        uint8_t len=0;
        uint8_t *data=0;
        void setMsg(uint8_t cmd,uint8_t datalen, const void*data);
        ~Msg();
        Msg& operator=(const Msg&);
};
