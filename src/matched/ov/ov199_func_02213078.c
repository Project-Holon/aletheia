/*
 * function: WIFIBATTLEMATCH_SYS_BuildSyncCommand
 * address: 0x02213078
 * packet: pkt_ov199_02213078
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   d_02213D04 0x02213D04 data ov199 a1
 */
#include "../include/Obj10858.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *, int, unsigned int);
extern const char d_02213D04[];
void *WIFIBATTLEMATCH_SYS_BuildSyncCommand(void *unused, int heap, char *p)
{
    unsigned int *work = func_02030734(heap, 0x1c, 0, d_02213D04, 0x5dc);
    MI_CpuFill8(work, 0, 0x1c);
    work[0] = (unsigned int)(p + 4);
    work[3] = ((struct Obj10858 *)p)->f30;
    work[4] = ((struct Obj10858 *)p)->f34;
    work[5] = (unsigned int)(p + 0x7d4);
    work[6] = (unsigned int)(p + 0x8a8);
    if (((struct Obj10858 *)p)->f1C == 1)
        work[1] = 1;
    else
        work[1] = 0;
    return work;
}
