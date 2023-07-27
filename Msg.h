class Msg 
{
    public:
        byte cmd;
        byte len;
        byte *data;
        setMsg(uint8_t cmd,uint8_t datalen, const void*data);
}