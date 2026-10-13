/*
 * function: func_021B95D0
 * address:  0x021B95D0
 * packet:   pkt_ov227_021B95D0
 * region:   ov227
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   STRBUF_Create  0x020457B0  arm
 *   PROCSYS_Create  0x02031324  arm
 */
#include "../include/Obj04655.h"

extern void GFL_HEAP_CreateChildHeap(unsigned int src, unsigned int dst, unsigned int size);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
typedef unsigned int   u32;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *PROCSYS_Create(int a0);

struct s { char pad[0x38]; };

int func_021B95D0(struct Obj0203159C *a)
{
    struct s *p;

    GFL_HEAP_CreateChildHeap(1, 0x8b, 0x1000);
    p = (struct s *)PROCSYS_AllocProcWork(a, 0x38, 0x8b);
    ((struct Obj04655 *)p)->f4 = (int)STRBUF_Create(0x20, 0x8b);
    ((struct Obj04655 *)p)->f0 = 0;
    ((struct Obj04655 *)p)->f28 = 0;
    ((struct Obj04655 *)p)->f2C = 0;
    ((struct Obj04655 *)p)->f30 = 0x8b;
    ((struct Obj04655 *)p)->f34 = (int)PROCSYS_Create(((struct Obj04655 *)p)->f30);
    return 1;
}
