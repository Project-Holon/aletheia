/*
 * function: func_02073F3C
 * address:  0x02073F3C
 * packet:   pkt_020737C0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Shutdown of the global sequence object g_0214E9FC: clear +0x1C, unbind both
 * channel handles (+0x0C and +0x10) from the owner at +0x14 through
 * func_02082A7C then func_020862F0, and finally release the channel mask built
 * from +0x2C with func_020894B4.
 *
 * PINNED ../2.0/sp2, the pin six cluster siblings now carry (func_020737C0,
 * func_02073AD0, func_02073B3C, func_02073CA0, func_020746E8, func_02074894).
 * docs/notes/pkt_02073F3C.c.txt recorded this exact body as blocked under
 * dsi/1.1p1, which pools the three separate `mov r0,#0` into one callee-saved
 * register, widens the push from {r4,lr} to {r3,r4,r5,lr}, and then under the
 * extra pressure reloads the global's address through a fresh pool word in the
 * tail: 128 bytes against 124, 94 concrete bytes out
 * (docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md).
 * Under the pin the note's own C is 124 bytes, 0 concrete mismatches, with no
 * further change to the C at all.
 *
 * The mask arm must be written condition-first (`if (f2c >= 0) m = 1u << f2c;
 * else m = 0;`) to give the image's `movge r0,#1` / `lslge r2,r0,r1` /
 * `movlt r2,#0`, the same lever docs/notes/pkt_02073BF0.c.txt records for
 * NNS_SndStartTimer; f2c is therefore signed.
 *
 * symbols:
 *   g_0214E9FC     0x0214E9FC  data
 *   func_02082A7C  0x02082A7C  arm
 *   func_020862F0  0x020862F0  arm
 *   func_020894B4  0x020894B4  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02073F3C.c \
 *       --func func_02073F3C --addr 0x02073F3C --cc ../2.0/sp2 --arm
 */

#include "../include/G_St.h"

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct G {
    u32 f00;
    u8  pad04[8];
    u32 f0c;
    u32 f10;
    u32 f14;
    u8  pad18[4];
    u32 f1c;
    u8  pad20[4];
    u32 f24;
    u32 f28;
    s32 f2c;
};

extern struct St g_0214E9FC;
extern void func_02082A7C(u32 a, u32 b, u32 c);
extern void func_020862F0(u32 a, u32 b);
extern void func_020894B4(u32 a, u32 b, u32 c, u32 d);

void func_02073F3C(void)
{
    struct G *g = ((struct G *)&g_0214E9FC);
    u32 m;

    if (g->f00 == 0) return;
    g->f1c = 0;
    func_02082A7C(0, g->f0c, g->f14);
    func_02082A7C(0, g->f10, g->f14);
    func_020862F0(g->f0c, g->f14);
    func_020862F0(g->f10, g->f14);
    if (g->f2c >= 0) m = 1u << g->f2c;
    else m = 0;
    func_020894B4(g->f24, g->f28, m, 0);
}
