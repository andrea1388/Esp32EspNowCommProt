Bus::tx(Packet p) {
    for (int i=0;i<node.Lenght;i++) {
        if(rnd()>RXERROR) node[i].rx(p);
    }
}

class Bus {
    // create a list of integer type
    list<Node> node;
}