/*
 * function: func_021DFD0C
 * address:  0x021DFD0C
 * packet:   pkt_ov119_021DFD0C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 */
#include "../include/Obj13907.h"

typedef unsigned int u32;

extern void MCSS_SetAnmStopFlag(void *p);

void func_021DFD0C(char *p)
{
    MCSS_SetAnmStopFlag((void *)(((struct Obj13907 *)p)->f844));
    ((struct Obj13907 *)p)->f854 = 1;
}
