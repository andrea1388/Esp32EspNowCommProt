#pragma once
#include <cstdint>
#include <utility>
class Msg 
{
    public:
        uint8_t cmd=0;
        uint8_t len=0;
        uint8_t *data=0;
        void setMsg(uint8_t cmd,uint8_t datalen, const void*data);
        ~Msg();
        Msg& operator=(const Msg&);
        /*
        
        Msg() : cmd(0) {}
        Msg(Msg&& o) noexcept :
            cmd(std::move(o.cmd)),       // explicit move of a member of class type
            len(std::move(o.len)),
            data(std::move(o.data))// explicit move of a member of non-class type
    {}
         */
};
