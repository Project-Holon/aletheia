/*
 * function: CDEMO_MAIN_Create
 * address:  0x021B6100
 * packet:   pkt_021B6100
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 */
#include "../include/Obj14383.h"
typedef unsigned int u32;

extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *p, u32 v, u32 n);

int CDEMO_MAIN_Create(struct Obj0203159C *p, u32 b, u32 c)
{
    char *r;

    GFL_HEAP_CreateChildHeap(1, 0x7f, 0x80000);
    r = PROCSYS_AllocProcWork(p, (u32)((void *)0x605c), 0x7f);
    MI_CpuFill8(r, 0, 0x605c);
    ((struct Obj14383 *)r)->f0 = c;
    *(u32 *)(r + 0x605c - 4) = 0;
    return 1;
}
