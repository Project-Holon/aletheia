/*
 * function: func_02051AB8
 * address:  0x02051AB8
 * packet:   pkt_02051A54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Byte-for-byte the twin of func_02051A54 over the second table: same
 * indirect call through the handler at 0x020A8140 (two arguments forwarded,
 * a literal 0 in r2), same append-and-count shape, but the count halfword is
 * at base+0x25e and the elements at base+0x158, i.e. the parallel table 0x100
 * bytes higher with its own counter.
 *
 * symbols:
 *   g_020A8148   0x020A8148  data
 *   g_02146A88   0x02146A88  data
 */
#include "../include/Obj11460.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx {
    u8   pad_00[0x44];
    u8  *base;      /* 0x44 */
};

extern u32 (*g_020A8148)(u32 a, u32 b, u32 c);
extern struct Ctx *g_02146A88;

u32 func_02051AB8(u32 a, u32 b)
{
    u32 v = g_020A8148(a, b, 0);
    u8 *base = g_02146A88->base;
    u16 n = ((struct Obj11460 *)base)->f25E;

    ((struct Obj11460 *)base)->f25E = n + 1;
    *(u32 *)(base + 0x158 + n * 4) = v;

    return (u16)v * 8;
}
