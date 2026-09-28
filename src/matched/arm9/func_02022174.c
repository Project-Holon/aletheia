/*
 * function: func_02022174
 * address:  0x02022174
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Per-frame poll for the dual-screen text cluster at 0x021467A4: while the
 * cluster is live (the u16 at +0x14C non-zero) it steps both sub-objects and,
 * when the stepper reports 1, runs the completion handler on the cluster.
 *
 * The +0x14C read costs its own pool word because 0x14C is far past the
 * ldrh immediate reach; it is g_021467A4 + 0x140 with a +0xC displacement,
 * one symbol and not a second object, see
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * The follower at 0x020221A4 is a separate leaf function with fan-in 111 and
 * is deliberately NOT folded into a unit here; it keeps its own entry, see
 * docs/idioms/a-unit-attests-only-its-own-start-address.md.  EXACT* is the
 * inferred extent running into that follower, not a byte difference.
 *
 * symbols:
 *   g_021467A4     0x021467A4  data
 *   func_02022340  0x02022340  thumb
 *   func_020222EC  0x020222EC  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022174.c \
 *       --func func_02022174 --addr 0x02022174 --cc 1.1p1 --thumb
 */
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

extern struct G g_021467A4;

extern u32  func_02022340(struct G *g, struct Sub *a, struct Sub *b);
extern void func_020222EC(struct G *g);

void func_02022174(void)
{
    struct G *g;

    g = &g_021467A4;
    if (g_021467A4.f14C != 0) {
        if (func_02022340(g, &g->f14, &g->f44) == 1)
            func_020222EC(g);
    }
}
