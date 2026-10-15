/*
 * function: NNSi_GfdInitTexVramManager
 * address:  0x02062114
 * packet:   pkt_02061D0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Closed 2026-09-22 (wave 7, pseudo-family pkt_02061D0C).  The two sites that
 * blocked it are both resolved now: NNS_GfdAllocTexVram was filed EXACT this lane
 * (../2.0/sp2) and the PC24 to NNSi_GfdInitTexVramHeap carries on sole-ref/code, the
 * class widened 2026-09-21.  The two callback globals 0x020A8140 / 0x020A8144
 * were simply missing from the symbols: block and resolve as literal x20 each.
 *
 * Register-argument save hook: park r0-r3 in the 0x02146B94 block, run the
 * real body NNSi_GfdInitTexVramHeap (which is handed the same four values), and when
 * the fifth (stack) argument is non-zero also install the two callbacks in
 * the clact.c handler slots 0x020A8140 / 0x020A8144.
 *
 * The 0x02146B94 block is written through its own address - a plain global
 * struct, not a pointer variable - so there is exactly one pool word for it.
 * The fifth argument is read at [sp, #8], the caller's first stack slot, past
 * the 8-byte {r3, lr} frame.
 *
 * symbols:
 *   g_02146B94   0x02146B94  data
 *   NNS_GfdDefaultFuncAllocTexVram   0x020A8140  data
 *   NNS_GfdDefaultFuncFreeTexVram   0x020A8144  data
 *   NNSi_GfdInitTexVramHeap   0x02062270  arm
 *   NNS_GfdAllocTexVram   0x0206216C  arm
 *   NNS_GfdFreeTexVram   0x020621FC  arm
 */

#include "../include/G_Cfg.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern struct Cfg g_02146B94;

extern void (*NNS_GfdDefaultFuncAllocTexVram)(void);
extern void (*NNS_GfdDefaultFuncFreeTexVram)(void);

extern void NNSi_GfdInitTexVramHeap(u32 a, u32 b, u32 c, u32 d);
extern u32 NNS_GfdAllocTexVram(u32 size, u32 flag);
extern u32 NNS_GfdFreeTexVram(u32 h);

void NNSi_GfdInitTexVramManager(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    g_02146B94.f0c = a;
    g_02146B94.f10 = b;
    g_02146B94.f14 = c;
    g_02146B94.f18 = d;

    NNSi_GfdInitTexVramHeap(a, b, c, d);

    if (e != 0) {
        NNS_GfdDefaultFuncAllocTexVram = (void (*)(void))NNS_GfdAllocTexVram;
        NNS_GfdDefaultFuncFreeTexVram = (void (*)(void))NNS_GfdFreeTexVram;
    }
}
