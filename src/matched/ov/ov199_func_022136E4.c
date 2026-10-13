/*
 * function: func_022136E4
 * address: 0x022136E4
 * packet: pkt_ov199_022136E4
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   d_02213D04 0x02213D04 data ov199 a1
 */
#include "../include/Obj06661.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *, int, unsigned int);
extern void *PROCSYS_Create(int);
extern const char d_02213D04[];
void *func_022136E4(void *a, void *b, void *c, int heap)
{
    char *work = func_02030734(heap, 0x20, 0, d_02213D04, 0x846);
    MI_CpuFill8(work, 0, 0x20);
    ((struct Obj06661 *)work)->f0 = PROCSYS_Create(heap);
    ((struct Obj06661 *)work)->fC = c;
    ((struct Obj06661 *)work)->f10 = a;
    ((struct Obj06661 *)work)->f14 = b;
    ((struct Obj06661 *)work)->f8 = heap;
    return work;
}
