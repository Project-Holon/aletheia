/*
 * function: func_0218F150
 * address:  0x0218F150
 * packet:   pkt_ov009_0218F150
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiAddPeer (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 *
 * symbols:
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_020923B0  0x020923B0  arm
 *   func_02184098  0x02184098  arm  ov009
 *   func_02184144  0x02184144  arm  ov009
 *   func_0218F134  0x0218F134  arm  ov009
 */

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

extern void *func_0217EAB0(unsigned long size);
typedef unsigned int   u32;
extern void *func_020923B0(void *p, int c, u32 n);
extern long func_02184098(long *timer);
extern void *func_02184144(int elemSize, int numElems, void (*freeFn)(void *));
extern void func_0218F134(void **p);

struct GPIPeer *func_0218F150(void **connection, int profileid, int initiate)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;
    struct GPIPeer *peer;

    peer = (struct GPIPeer *)func_0217EAB0(sizeof(struct GPIPeer));
    if (peer == 0)
        return 0;
    func_020923B0(peer, 0, sizeof(struct GPIPeer));
    peer->state = 0x64;
    peer->initiated = initiate;
    peer->profile = profileid;
    peer->timeout = func_02184098(0) + 10000;
    peer->pnext = iconnection->peerList;
    peer->messages = func_02184144(0x18, 0, (void (*)(void *))func_0218F134);
    iconnection->peerList = peer;
    peer->gotHeader = 0;
    peer->sizeReceived = 0;
    peer->ptype = 0;
    return peer;
}
