/*
 * file:     unit_0218E3B0_p01.c
 * unit:     yes
 * function: func_0218EE48, func_0218EEC0, func_0218EF04, func_0218EFEC, func_0218F0B8
 * address:  0x0218EE48
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gpiProcessPeerInitiatingConnection  0x0218E3B0  arm
 *   gpiProcessPeerAcceptingConnection   0x0218E6DC  arm
 *   gpiProcessPeerConnected             0x0218E9E8  arm
 *   gpiCheckTimedOutPeerOperations      0x0218ED58  arm
 *   gsifree     0x0217EAE0  arm
 *   ArrayFree   0x021841B0  arm
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_021888C0  0x021888C0  arm  ov009
 *   func_0218437C  0x0218437C  arm  ov009
 *   func_0218EEC0  0x0218EEC0  arm  ov009
 *   g_021A4F4C  0x021A4F4C  data
 *   func_021814EC  0x021814EC  arm  ov009
 *   func_0218EE48  0x0218EE48  arm  ov009
 *   func_02184098  0x02184098  arm  ov009
 *   g_021A4F70  0x021A4F70  data
 */
struct DArrayImplementation;
struct GPIPeer_s_0218EE48 {
    int  state;      /* +0x00 */
    int  initiated;  /* +0x04 */
};

struct GPIBuffer {
    char *data;  /* +0x00 */
    int   len;   /* +0x04 */
    int   size;  /* +0x08 */
    int   pad;   /* +0x0c */
};

struct GPIPeer_s_0218EEC0 {
    char pad0[0x1c];
    struct GPIBuffer inputBuffer;   /* +0x1c */
    struct GPIBuffer outputBuffer;  /* +0x2c */
    struct DArrayImplementation *messages; /* +0x3c */
};

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

extern int  gpiProcessPeerInitiatingConnection(void **connection, struct GPIPeer_s_0218EE48 *peer);
extern int  gpiProcessPeerAcceptingConnection(void **connection, struct GPIPeer_s_0218EE48 *peer);
extern int  gpiProcessPeerConnected(void **connection, struct GPIPeer_s_0218EE48 *peer);
extern void gpiCheckTimedOutPeerOperations(void **connection, struct GPIPeer_s_0218EE48 *peer);
extern void gsifree(void *ptr);
extern void ArrayFree(struct DArrayImplementation *array);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern int func_021888C0(void **connection, int profileid, int type, char *message);
extern void func_0218437C(int a, int b);
extern void func_0218EEC0(void **connection, struct GPIPeer *peer);
extern int func_021814EC(void);
extern int func_0218EE48(void **connection, struct GPIPeer *peer);
extern long func_02184098(long *timer);
void gpiDestroyPeer(void **connection, struct GPIPeer_s_0218EEC0 *peer);
void func_0218EF04(void **connection, struct GPIPeer *peer);
int func_0218EFEC(void **connection);
char *func_0218F0B8(void **p, int v);
extern char g_021A4F4C[];
extern char g_021A4F70[];


static int gpiProcessPeer(void **connection, struct GPIPeer_s_0218EE48 *peer)
{
    int result = 0;

    if (peer->state == 100)
        return 3;
    if (peer->state != 0x69) {
        if (peer->initiated != 0)
            result = gpiProcessPeerInitiatingConnection(connection, peer);
        else
            result = gpiProcessPeerAcceptingConnection(connection, peer);
    }
    if (result == 0 && peer->state == 0x69) {
        result = gpiProcessPeerConnected(connection, peer);
        gpiCheckTimedOutPeerOperations(connection, peer);
    }
    return result;
}


void gpiDestroyPeer(void **connection, struct GPIPeer_s_0218EEC0 *peer)
{
    gsifree(peer->inputBuffer.data);
    peer->inputBuffer.data = 0;
    gsifree(peer->outputBuffer.data);
    peer->outputBuffer.data = 0;
    if (peer->messages != 0) {
        ArrayFree(peer->messages);
        peer->messages = 0;
    }
    gsifree(peer);
}


/*
 * sdk:      gpiRemovePeer (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 */
void func_0218EF04(void **connection, struct GPIPeer *peer)
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


/*
 * sdk:      gpiProcessPeers (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 */
int func_0218EFEC(void **connection)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;
    struct GPIPeer *nextPeer;
    struct GPIPeer *peer;
    int result;

    func_021814EC();
    peer = iconnection->peerList;
    while (peer != 0) {
        nextPeer = peer->pnext;
        if (peer->state == 0x6a) {
            func_0217D254(1, (char *)4, 8, g_021A4F70, peer->profile);
            func_0218EF04(connection, peer);
        } else {
            result = func_0218EE48(connection, peer);
            if (peer->state == 0x6a || result != 0 || func_02184098(0) > peer->timeout) {
                func_0217D254(1, (char *)4, 8, g_021A4F70, peer->profile);
                func_0218EF04(connection, peer);
            }
        }
        peer = nextPeer;
    }
    return 0;
}

/*
 * Walks the list hanging off the +0x5d8 member of the object and returns the
 * node whose +0x10 word equals v, or 0 when the list runs out.
 */
char *func_0218F0B8(void **p, int v)
{
    char *q = *(char **)(*(char **)p + 0x5d8);

    while (q != 0) {
        if (*(int *)(q + 0x10) == v) return q;
        q = *(char **)(q + 0x4c);
    }
    return 0;
}
