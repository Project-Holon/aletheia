/*
 * function: WIFIBATTLEMATCH_SYS_SetStep
 * address: 0x02213808
 * packet: pkt_ov199_02213808
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj25301.h"
void WIFIBATTLEMATCH_SYS_SetStep(char *p, int value)
{
    ((struct Obj25301 *)p)->f19 = value;
}
