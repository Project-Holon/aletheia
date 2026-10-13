/*
 * function: WIPE_SYS_Main
 * address:  0x02022174
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-frame poll for the dual-screen text cluster at 0x021467A4: while the
 * cluster is live (the u16 at +0x14C non-zero) it steps both sub-objects and,
 * when the stepper reports 1, runs the completion handler on the cluster.
 *
 * The +0x14C read costs its own pool word because 0x14C is far past the
 * ldrh immediate reach; it is g_wipeSys + 0x140 with a +0xC displacement,
 * one symbol and not a second object, see
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * The follower at 0x020221A4 is a separate leaf function with fan-in 111 and
 * is deliberately NOT folded into a unit here; it keeps its own entry, see
 * docs/idioms/a-unit-attests-only-its-own-start-address.md.  EXACT* is the
 * inferred extent running into that follower, not a byte difference.
 *
 * symbols:
 *   g_wipeSys     0x021467A4  data
 *   WIPE_SYS_MainPanels  0x02022340  thumb
 *   WIPE_SYS_Finish  0x020222EC  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SYS_Main.c \
 *       --func WIPE_SYS_Main --addr 0x02022174 --cc 1.1p1 --thumb
 */

#include "../include/G_021467A4.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub {
    u8  pad00[0x0C];
    u32 f0C;
    u8  pad10[0x20];
};

struct G {
    u8          pad00[4];
    void       *f04;
    void       *f08;
    void       *f0C;
    void       *f10;
    struct Sub  f14;
    struct Sub  f44;
    u8          f74[0x18];
    u8          f8C[0xC0];
    u16         f14C;
    u8          f14E;
    u8          f14F;
};

extern struct G_021467A4 g_wipeSys;

struct Cluster;
extern u32 WIPE_SYS_MainPanels(struct Cluster *p, void *top, void *bottom);
extern void WIPE_SYS_Finish(struct G *g);

void WIPE_SYS_Main(void)
{
    struct G *g;

    g = ((struct G *)&g_wipeSys);
    if (g_wipeSys.f14C != 0) {
        if (WIPE_SYS_MainPanels((struct Cluster *)g, &g->f14, &g->f44) == 1)
            WIPE_SYS_Finish(g);
    }
}
