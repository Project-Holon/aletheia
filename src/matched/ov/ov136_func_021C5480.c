/*
 * function: func_021C5480
 * address: 0x021C5480
 * packet: pkt_ov136_021C5480
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   func_02008FEC 0x02008FEC thumb
 *   PROCSYS_Create 0x02031324 arm
 */
#include "../include/Obj06527.h"
typedef unsigned char u8;
extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);
typedef unsigned int   u32;
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MIi_CpuClearFast(int,void *,int);
struct Sub02008F80Obj;
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern void *PROCSYS_Create(int);
int func_021C5480(void *a, int unused, void **arg)
{
    u8 *p;
    GFL_HEAP_CreateChildHeap(1,101,65536);
    p = PROCSYS_AllocProcWork(a,52,101);
    MIi_CpuClearFast(0,p,52);
    ((struct Obj06527 *)p)->f4 = arg;
    ((struct Obj06527 *)p)->f0 = func_02008FEC(*arg);
    ((struct Obj06527 *)p)->f28 = 8;
    ((struct Obj06527 *)p)->f2C = 0;
    ((struct Obj06527 *)p)->f30 = PROCSYS_Create(101);
    return 1;
}
