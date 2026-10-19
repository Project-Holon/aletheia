/*
 * function: ZUKAN_DETAIL_TOUCHBAR_FlushBar
 * address:  0x021BDCDC
 * packet:   pkt_021BDC14
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_SetPriority  0x0204047C  arm  arm9
 *   (none)

 * BLOCKED.  MATCH: the call at +0x10 targets 0204047C, an ARM address with no label and no pool witness outside the compared range, so the site stays wildcarded.
 */
#include "../include/Obj09201.h"


extern void BG_SYS_SetPriority(int idx, unsigned short val);

void ZUKAN_DETAIL_TOUCHBAR_FlushBar(int unused, char *p)
{
    if (((struct Obj09201 *)p)->f3C != 0) {
        BG_SYS_SetPriority(1, ((struct Obj09201 *)p)->f38);
        ((struct Obj09201 *)p)->f3C = 0;
    }
}

