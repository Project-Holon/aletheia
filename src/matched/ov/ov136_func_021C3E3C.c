/*
 * function: func_021C3E3C
 * address: 0x021C3E3C
 * packet: pkt_ov136_021C3E3C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021C3E9A..021C3E9C zero alignment padding.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   func_021C409C 0x021C409C thumb ov136
 *   PROCSYS_Create 0x02031324 arm
 */
#include "../include/Obj08196.h"
#include "../include/Obj08197.h"
#include "../include/Obj23488.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void GFL_HEAP_CreateChildHeap(unsigned, unsigned, unsigned);
typedef unsigned int   u32;
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MIi_CpuClearFast(unsigned, void *, unsigned);
extern void *func_021C409C(void *, unsigned);
extern void *PROCSYS_Create(int a0);
int func_021C3E3C(void *a, void *b, u8 *p)
{
    u8 *q;
    GFL_HEAP_CreateChildHeap(1, 0x63, 0x1000);
    q = PROCSYS_AllocProcWork(a, 0x20, 0x63);
    MIi_CpuClearFast(0, q, 0x20);
    ((struct Obj08197 *)q)->f0 = 0x63;
    *(u8 * *)&((struct Obj08197 *)q)->f10 = func_021C409C(((struct Obj08196 *)p)->f14, 0x63);
    if (((struct Obj08196 *)p)->f0 == 1) (*(u8 **)(q + 0x10))[0xB] = p[0xF];
    if ((*(u8 **)(q + 0x10))[0xB] >= 0xC) (*(u8 **)(q + 0x10))[0xB] = 0;
    ((struct Obj23488 *)(*(u8 * *)&((struct Obj08197 *)q)->f10))->f0 = ((struct Obj08196 *)p)->f0;
    ((struct Obj08197 *)q)->f1C = PROCSYS_Create(0x63);
    return 1;
}
