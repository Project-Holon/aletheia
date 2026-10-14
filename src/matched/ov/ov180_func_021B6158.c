/*
 * function: HALL_OF_FAME_AddVBlankTaskMon
 * address:  0x021B6158
 * packet:   pkt_021B6158
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056A0  0x020056A0  thumb
 */
#include "../include/Obj24479.h"

extern int func_020056A0(void *, int *, int);

void HALL_OF_FAME_AddVBlankTaskMon(int *p)
{
    ((struct Obj24479 *)p)->f4 = func_020056A0((void *)0x021B6195, p, 0);
}
