/*
 * function: MUSICAL_MCSS_AllocRenderPool
 * address: 0x021F55F8
 * packet: pkt_ov112_021F55F8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_021F83D4 0x021F83D4 data a1
 *   d_02FFFC3C 0x02FFFC3C data a4
 */
#include "../include/Obj05315.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern void *GFL_HEAP_Alloc(u32, u32, int, const char *, u16);
extern const char d_021F83D4[];
extern u32 d_02FFFC3C;
void *MUSICAL_MCSS_AllocRenderPool(int count, u32 heap)
{
    char *p;
    p = GFL_HEAP_Alloc(heap, 28, 1, d_021F83D4, 132);
    ((struct Obj05315 *)p)->f0 = count;
    ((struct Obj05315 *)p)->f14 = heap;
    ((struct Obj05315 *)p)->f4 = GFL_HEAP_Alloc(heap, count * 4, 1, d_021F83D4, 137);
    ((struct Obj05315 *)p)->f18 = d_02FFFC3C;
    ((struct Obj05315 *)p)->fC = 3 << 16;
    ((struct Obj05315 *)p)->f10 = 1 << 12;
    return p;
}
