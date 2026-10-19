/*
 * function: ZUKAN_INFO_Task
 * address:  0x021BA864
 * packet:   pkt_021BA864
 * region:   ov206
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 */
#include "../include/Obj08387.h"

typedef unsigned int   u32;
extern void BG_SYS_ChangeScroll(u32 index, u32 a, u32 b);

void ZUKAN_INFO_Task(int unused, char *p)
{
    if (((struct Obj08387 *)p)->f39 & 1)
    {
        BG_SYS_ChangeScroll(((struct Obj08387 *)p)->f4E, 1, 1);
    }
    ((struct Obj08387 *)p)->f38 = 0;
    ((struct Obj08387 *)p)->f39 = 0;
}
