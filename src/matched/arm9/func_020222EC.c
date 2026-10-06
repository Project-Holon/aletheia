/*
 * function: func_020222EC
 * address:  0x020222EC
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Teardown for the dual-screen text cluster, run by func_02022174 once both
 * screen slots have gone null.  It clears the live flag at +0x14C, latches the
 * value func_02022608 returns into the sentinel colour slot at +0x150, and for
 * each of the two delegates at +0x0C and +0x10 runs the per-screen finaliser
 * func_02022670 on the matching sub-object.
 *
 * Two notes on the original's shape.  Both delegate arms retest the *same*
 * field, +0x3C, which is the top sub-object's task handle at 0x14 + 0x28; the
 * bottom arm does not use its own +0x6C.  That is the image's behaviour, not a
 * transcription slip, and it is reproduced literally.  Both flag writes also go
 * through the global rather than the incoming pointer, which the encoding
 * distinguishes: the pointer form would reuse r5, the global form spends a
 * pool word at 0x0202233C.
 *
 * 0x14C and 0x150 are both past the strh immediate reach, so the first is
 * materialised as 0x53 << 2 into a register offset and the second derived from
 * it with a single `adds r1, r4, #4`; see
 * docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md for the
 * same derivation on line-number arguments.
 *
 * symbols:
 *   g_021467A4     0x021467A4  data
 *   func_02022608  0x02022608  thumb
 *   func_02022670  0x02022670  thumb
 *   func_020226A0  0x020226A0  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020222EC.c \
 *       --func func_020222EC --addr 0x020222EC --cc 1.1p1 --thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub {
    u8    pad00[0x28];
    void *f28;
    u8    pad2C[4];
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
    u16         f150;
};

extern struct G g_021467A4;

struct Obj;
struct Screen;
extern u16 func_02022608(struct Obj *p);
extern void func_02022670(struct Screen *s);
extern void func_020226A0(u8 *p);

void func_020222EC(struct G *p)
{
    p->f14C = 0;
    p->f150 = func_02022608((struct Obj *)p);
    if (p->f0C != 0) {
        func_02022670((struct Screen *)(&p->f14));
        if (p->f14.f28 == 0)
            g_021467A4.f14E = 0;
    }
    if (p->f10 != 0) {
        func_02022670((struct Screen *)(&p->f44));
        if (p->f14.f28 == 0)
            g_021467A4.f14F = 0;
    }
    func_020226A0((u8 *)p);
}
