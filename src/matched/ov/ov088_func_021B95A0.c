/*
 * function: STARTMENU_TitleDemoInit
 * address:  0x021B95A0
 * packet:   pkt_ov088_021B95A0
 * region:   ov088
 * compiler: dsi/1.1p1
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
#include "../include/Obj20810.h"

typedef unsigned short u16;

extern void GFL_HEAP_CreateChildHeap(unsigned int a, unsigned int heap, unsigned int size);
typedef unsigned int   u32;
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void  MI_CpuFill8(void *p, int v, int n);

int STARTMENU_TitleDemoInit(struct Proc *a0)
{
    char *p;

    GFL_HEAP_CreateChildHeap(1, 0x16, 0x120000);
    p = PROCSYS_AllocProcWork(a0, 0x98, 0x16);
    MI_CpuFill8(p, 0, 0x98);
    ((struct Obj20810 *)p)->f2 = 0x16;
    return 1;
}
