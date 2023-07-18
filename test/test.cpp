#define NUMNODE 3
#define TXRNDTIME 10 //ms
#define RXERROR 0.5
#include<list>
using namespace std;


int main() {
    Bus bus;
    Node* node[];
    for (int i=0;i<NUMNODE;i++) {
        node[i]=new Node(i,bus); //node id, bus
    }
    Packet p;
    node[0]->tx(p);
    while(true) {
        for (int i=0;i<NUMNODE;i++) {
            node[i]
        }
    }
}







