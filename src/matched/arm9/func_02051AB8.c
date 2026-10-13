/*
 * function: BUTTON_MAN_AppendList1
 * address:  0x02051AB8
 * packet:   pkt_02051A54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Byte-for-byte the twin of BUTTON_MAN_AppendList0 over the second table: same
 * indirect call through the handler at 0x020A8140 (two arguments forwarded,
 * a literal 0 in r2), same append-and-count shape, but the count halfword is
 * at base+0x25e and the elements at base+0x158, i.e. the parallel table 0x100
 * bytes higher with its own counter.
 *
 * symbols:
 *   NNS_GfdDefaultFuncAllocPlttVram   0x020A8148  data
 *   g_pParticleMan   0x02146A88  data
 */
#include "../include/Obj11460.h"
#include "../include/G_02146A88.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 (*NNS_GfdDefaultFuncAllocPlttVram)(u32 a, u32 b, u32 c);
extern struct G_02146A88 *g_pParticleMan;

u32 BUTTON_MAN_AppendList1(u32 a, u32 b)
{
    u32 v = NNS_GfdDefaultFuncAllocPlttVram(a, b, 0);
    u8 *base = g_pParticleMan->base;
    u16 n = ((struct Obj11460 *)base)->f25E;

    ((struct Obj11460 *)base)->f25E = n + 1;
    *(u32 *)(base + 0x158 + n * 4) = v;

    return (u16)v * 8;
}
