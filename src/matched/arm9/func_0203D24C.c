/*
 * unit:     no
 * function: GFL_NET_SetTimeout
 * address:  0x0203D24C
 * packet:   pkt_0203D1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *
 * TU: net.c.
 *
 * Store a halfword pair into +0x5c/+0x5e of the network state block, if it
 * exists.  Both stores are predicated off the one null test, which is why
 * the two parameters have to survive the accessor call in r5/r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SetTimeout.c \
 *       --func GFL_NET_SetTimeout --addr 0x0203D24C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct NetState {
    u8  pad_00[0x5c];
    u16 unk_5c;
    u16 unk_5e;
};

extern void *GFL_NET_GetInitParam(void);

void GFL_NET_SetTimeout(u16 a, u16 b)
{
    struct NetState *s = GFL_NET_GetInitParam();

    if (s != 0) {
        s->unk_5c = a;
        s->unk_5e = b;
    }
}
