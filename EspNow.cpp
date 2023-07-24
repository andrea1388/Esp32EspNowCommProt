class EspNow
{
    public:
        begin();
        void cbNewPacket(void cbrx(const Packet& pkt));
        void tx(Packet);
}