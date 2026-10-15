/*
 * function: gpiPeerLeftCallback
 * address:  0x0218F5F4
 * packet:   pkt_ov009_0218F5F4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiPeerLeftCallback (gpipeer.o)
 *
 * symbols:
 *   gpiGetPeerByAddr  0x0218F0E8  arm
 *   SOC_InetNtoA      0x0215FA9C  arm
 *   gsDebugFormat     0x0217D254  arm
 *   gGpiPeerDebugLeft        0x021A5000  data
 */

struct SOCInAddr {
    unsigned long addr;  /* +0x00 */
};

struct GPIPeer_s {
    int state;       /* +0x00 */
    char pad04[0x10 - 0x04];
    int profile;     /* +0x10 */
};

extern struct GPIPeer_s *gpiGetPeerByAddr(void **connection, unsigned int ip,
                                          unsigned short port);
extern char *SOC_InetNtoA(struct SOCInAddr in);
extern void gsDebugFormat(int theCat, int theType, unsigned char theLevel,
                          char *theTokenStr, ...);
extern char gGpiPeerDebugLeft[];

void gpiPeerLeftCallback(unsigned int ip, unsigned short port, void *unused,
                         void **connection)
{
    struct SOCInAddr anAddr;
    struct GPIPeer_s *aPeer;

    anAddr.addr = ip;
    aPeer = gpiGetPeerByAddr(connection, ip, port);
    if (aPeer == 0)
        return;
    gsDebugFormat(1, 0, 8, gGpiPeerDebugLeft, SOC_InetNtoA(anAddr), port,
                  aPeer->profile);
    aPeer->state = 0x6a;
}
