/*
 * function: gpiRemovePeer
 * address:  0x0218EF04
 * packet:   pkt_ov009_0218EF04
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiRemovePeer (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_021888C0  0x021888C0  arm  ov009
 *   func_0218437C  0x0218437C  arm  ov009
 *   func_0218EEC0  0x0218EEC0  arm  ov009
 *   g_021A4F4C  0x021A4F4C  data
 */

struct GPIMessage {
    char *buffer;
    char pad0[0xc];
    int type;
    int start;
};

struct GPIPeer {
    int state;
    int initiated;
    char pad0[8];
    int profile;
    int timeout;
    char pad1[0x24];
    void *messages;
    int ptype;
    int gotHeader;
    int sizeReceived;
    struct GPIPeer *pnext;
};

struct GPIConnection {
    char pad[0x5d8];
    struct GPIPeer *peerList;
};

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern int func_021888C0(void **connection, int profileid, int type, char *message);
extern void func_0218437C(int a, int b);
extern void func_0218EEC0(void **connection, struct GPIPeer *peer);
extern char g_021A4F4C[];

void gpiRemovePeer(void **connection, struct GPIPeer *peer)
{
    struct GPIMessage *message;
    struct GPIConnection *iconnection;
    struct GPIPeer *pprev;

    iconnection = (struct GPIConnection *)*connection;
    if (peer == 0 || (pprev = iconnection->peerList) == 0)
        return;
    if (pprev == peer) {
        iconnection->peerList = peer->pnext;
    } else {
        while (pprev->pnext != peer) {
            if (pprev->pnext == 0) {
                func_0217D254(1, (char *)4, 1, g_021A4F4C);
                return;
            }
            pprev = pprev->pnext;
        }
        pprev->pnext = peer->pnext;
    }
    while (func_02184200(peer->messages) != 0) {
        message = (struct GPIMessage *)func_02184208(peer->messages, 0);
        if (message->type < 100)
            func_021888C0(connection, peer->profile, message->type, message->buffer + message->start);
        func_0218437C((int)peer->messages, 0);
    }
    func_0218EEC0(connection, peer);
}
