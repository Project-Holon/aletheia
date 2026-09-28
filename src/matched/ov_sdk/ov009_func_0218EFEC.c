/*
 * function: func_0218EFEC
 * address:  0x0218EFEC
 * packet:   pkt_ov009_0218EFEC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessPeers (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 *
 * symbols:
 *   func_021814EC  0x021814EC  arm  ov009
 *   func_0218EE48  0x0218EE48  arm  ov009
 *   func_02184098  0x02184098  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0218EF04  0x0218EF04  arm  ov009
 *   g_021A4F70  0x021A4F70  data
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

extern int func_021814EC(void);
extern int func_0218EE48(void **connection, struct GPIPeer *peer);
extern long func_02184098(long *timer);
extern void func_0217D254(int cat, int type, int level, char *fmt, ...);
extern void func_0218EF04(void **connection, struct GPIPeer *peer);
extern char g_021A4F70[];

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
            func_0217D254(1, 4, 8, g_021A4F70, peer->profile);
            func_0218EF04(connection, peer);
        } else {
            result = func_0218EE48(connection, peer);
            if (peer->state == 0x6a || result != 0 || func_02184098(0) > peer->timeout) {
                func_0217D254(1, 4, 8, g_021A4F70, peer->profile);
                func_0218EF04(connection, peer);
            }
        }
        peer = nextPeer;
    }
    return 0;
}
