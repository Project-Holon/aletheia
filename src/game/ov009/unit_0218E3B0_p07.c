/*
 * file:     unit_0218E3B0_p07.c
 * unit:     yes
 * function: func_0218F7B8
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
 *   func_0217D254  0x0217D254  arm  ov009
 *   g_021A50BC  0x021A50BC  data
 *   g_021A50E4  0x021A50E4  data
 *   g_021A5110  0x021A5110  data
 */

struct SOCInAddr {
    unsigned int addr;
};

struct GPIPeer {
    int state;
};

extern struct GPIPeer *func_0218F0E8(void **connection, unsigned int ip, unsigned short port);
extern char *func_0215FA9C(struct SOCInAddr in);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern char g_021A50BC[];
extern char g_021A50E4[];
extern char g_021A5110[];

void func_0218F7B8(unsigned int ip, unsigned short port, int unused, int rejected, void *userData)
{
    struct SOCInAddr anAddr;
    struct GPIPeer *aPeer;

    anAddr.addr = ip;
    aPeer = func_0218F0E8((void **)userData, ip, port);
    if (aPeer == 0) {
        func_0217D254(1, 0, 1, g_021A50BC, func_0215FA9C(anAddr), port);
    } else if (rejected) {
        aPeer->state = 0x6a;
        func_0217D254(1, 0, 8, g_021A50E4, func_0215FA9C(anAddr), port);
        return;
    }
    func_0217D254(1, 0, 8, g_021A5110, func_0215FA9C(anAddr), port);
}
