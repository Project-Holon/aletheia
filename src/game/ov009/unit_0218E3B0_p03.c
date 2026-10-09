/*
 * file:     unit_0218E3B0_p03.c
 * unit:     yes
 * function: func_0218E91C
 * address:  0x0218E91C
 * packet:   pkt_ov009_0218E91C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiPeerSendMessages (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 *
 * symbols:
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_02189A7C  0x02189A7C  arm  ov009
 *   func_0218437C  0x0218437C  arm  ov009
 */

struct GPIMessage {
    char *buffer;
    int size;
    int length;
    int pos;
};

struct GPIPeer {
    int state;
    char pad0[4];
    unsigned int ip;
    unsigned short port;
    char pad1[0x26];
    int connecting;
    char pad2[4];
    void *messages;
};

extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern int func_02189A7C(void **connection, unsigned int ip, unsigned short port, struct GPIMessage *outputBuffer, int *closed, int clipSentData);
extern void func_0218437C(int a, int b);

int func_0218E91C(void **connection, struct GPIPeer *peer)
{
    struct GPIMessage *message;
    int result;
    int connClosed;

    if (peer == 0)
        return 3;
    if (peer->connecting != 0)
        return 0;
    while (func_02184200(peer->messages) != 0) {
        message = (struct GPIMessage *)func_02184208(peer->messages, 0);
        result = func_02189A7C(connection, peer->ip, peer->port, message, &connClosed, 0);
        if (connClosed != 0 || result != 0) {
            peer->state = 0x6a;
            return 0;
        }
        if (message->pos != message->length)
            break;
        func_0218437C((int)peer->messages, 0);
    }
    return 0;
}
