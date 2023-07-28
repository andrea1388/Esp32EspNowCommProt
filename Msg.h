class Msg 
{
    public:
        byte cmd=0;
        byte len=0;
        byte *data=0;
        setMsg(uint8_t cmd,uint8_t datalen, const void*data);
        ~Msg();
}