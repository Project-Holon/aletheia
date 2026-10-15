/*
 * function: gpiPeerAcceptedCallback
 * address:  0x0218F7B8
 * packet:   pkt_ov009_0218F7B8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiPeerAcceptedCallback (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 *
 * symbols:
 *   func_0218F0E8  0x0218F0E8  arm  ov009
 *   func_0215FA9C  0x0215FA9C  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   gGpiPeerDebugNotExist  0x021A50BC  data
 *   gGpiPeerDebugConnRejected  0x021A50E4  data
 *   gGpiPeerDebugConnAccepted  0x021A5110  data
 */

struct SOCInAddr {
    unsigned int addr;
};

struct GPIPeer {
    int state;
};

extern struct GPIPeer *func_0218F0E8(void **connection, unsigned int ip, unsigned short port);
extern char *func_0215FA9C(struct SOCInAddr in);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern char gGpiPeerDebugNotExist[];
extern char gGpiPeerDebugConnRejected[];
extern char gGpiPeerDebugConnAccepted[];

void gpiPeerAcceptedCallback(unsigned int ip, unsigned short port, int unused, int rejected, void *userData)
{
    struct SOCInAddr anAddr;
    struct GPIPeer *aPeer;

    anAddr.addr = ip;
    aPeer = func_0218F0E8((void **)userData, ip, port);
    if (aPeer == 0) {
        gsDebugFormat(1, 0, 1, gGpiPeerDebugNotExist, func_0215FA9C(anAddr), port);
    } else if (rejected) {
        aPeer->state = 0x6a;
        gsDebugFormat(1, 0, 8, gGpiPeerDebugConnRejected, func_0215FA9C(anAddr), port);
        return;
    }
    gsDebugFormat(1, 0, 8, gGpiPeerDebugConnAccepted, func_0215FA9C(anAddr), port);
}
