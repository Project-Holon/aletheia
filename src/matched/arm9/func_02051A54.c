/*
 * function: BUTTON_MAN_AppendList0
 * address:  0x02051A54
 * packet:   pkt_02051A54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The caller's registered handler (the function pointer in the clact.c global
 * 0x020A8140) is invoked with the two incoming arguments and a literal 0 in
 * r2; r1 is never written, so the callee takes at least two arguments and the
 * third is a constant zero.
 *
 * The result is appended to the current context's u32 table: the count
 * halfword at base+0x25c is loaded once, incremented and stored back, and the
 * value is written to base+0x58+count*4 - the store uses the OLD count, so the
 * table is indexed before the increment.  The return value is the low
 * halfword of the result scaled by eight, which the compiler writes as the
 * fused unequal shift pair lsl #16 / lsr #13 (a u16 cast folded into the
 * multiply, see
 * docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 *
 * The twin at 0x02051AB8 is the same shape over the parallel table 0x100
 * higher (count at +0x25e, elements at +0x158).
 *
 * symbols:
 *   g_020A8140   0x020A8140  data
 *   g_pParticleMan   0x02146A88  data
 */
#include "../include/Obj11459.h"
#include "../include/G_02146A88.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 (*g_020A8140)(u32 a, u32 b, u32 c);
extern struct G_02146A88 *g_pParticleMan;

u32 BUTTON_MAN_AppendList0(u32 a, u32 b)
{
    u32 v = g_020A8140(a, b, 0);
    u8 *base = g_pParticleMan->base;
    u16 n = ((struct Obj11459 *)base)->f25C;

    ((struct Obj11459 *)base)->f25C = n + 1;
    *(u32 *)(base + 0x58 + n * 4) = v;

    return (u16)v * 8;
}
