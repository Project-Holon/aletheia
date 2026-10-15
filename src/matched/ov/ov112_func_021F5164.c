/*
 * function: MUSICAL_MCSS_CreateRenderObj
 * address: 0x021F5164
 * packet: pkt_ov112_021F5164
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_021F83C4 0x021F83C4 data a1
 *   MUSICAL_MCSS_AllocRenderPool 0x021F55F8 thumb ov112
 *   MUSICAL_MCSS_NoOp7 0x021F621C thumb ov112
 */
#include "../include/Obj10301.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern void *GFL_HEAP_Alloc(u32, u32, int, const char *, u16);
extern const char d_021F83C4[];
extern void *MUSICAL_MCSS_AllocRenderPool(int, u32);
extern void MUSICAL_MCSS_NoOp7(void *);
void *MUSICAL_MCSS_CreateRenderObj(u32 heap)
{
    int i;
    char *p;
    p = GFL_HEAP_Alloc(heap, 4456, 0, d_021F83C4, 76);
    ((struct Obj10301 *)p)->f0 = heap;
    ((struct Obj10301 *)p)->f4 = MUSICAL_MCSS_AllocRenderPool(8, heap);
    for (i = 0; i < 8; i++) *(u32 *)(p + i * 556 + 8) = 0;
    MUSICAL_MCSS_NoOp7(((struct Obj10301 *)p)->f4);
    return p;
}
