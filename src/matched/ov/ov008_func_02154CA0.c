/*
 * function: EVENT_BATTLE_REC_SAVE_ProcInit
 * address:  0x02154CA0
 * packet:   pkt_02154CA0
 * region:   ov008
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   PROCSYS_Create  0x02031324  arm
 */
#include "../include/Obj18644.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void  GFL_HEAP_CreateChildHeap(unsigned int a, unsigned int b, unsigned int c);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void *PROCSYS_Create(int a0);

int EVENT_BATTLE_REC_SAVE_ProcInit(void *ctx)
{
    u8 *p;

    GFL_HEAP_CreateChildHeap(1, 0x76, 0x4000);
    p = PROCSYS_AllocProcWork(ctx, 0x1c, 0x76);
    ((struct Obj18644 *)p)->f0 = (unsigned int)PROCSYS_Create(0x76);
    return 1;
}
