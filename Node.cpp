class Node {
    public:
        sendtemp(int);
        Node(int id, Bus bus);
        int id;
        int pktnumber=0;
}

Node::Node(int _id, Bus bus) {
    id=_id;
    bus.node.push(this);
}

Node::sendtemp(int payload) 
{
    Packet p;
    p.payload=payload;
    p.sender=id;
    p.number=pktnumber++;
    p.txtime=now()+rnd()*TXRNDTIME;
    outQueue.Add(p);
    p.txtime=now()+TX1+rnd()*TXRNDTIME;
    p.retransmission=1;
    outQueue.Add(p);
}


Node::sendPackets() {
    for (int i=0;i<outQueue.Lenght();i++) {
        if(outQueue[i].txtime>now) {
            bus.tx(outQueue[i]);
            outQueue.Remove(i);
        }   

}