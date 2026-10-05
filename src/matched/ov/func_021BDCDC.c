/*
 * function: func_021BDCDC
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
 *   (none)

 * BLOCKED.  MATCH: the call at +0x10 targets 0204047C, an ARM address with no label and no pool witness outside the compared range, so the site stays wildcarded.
 */
#include "../include/Obj09201.h"


extern void func_0204047C(int idx, unsigned short val);

void func_021BDCDC(int unused, char *p)
{
    if (((struct Obj09201 *)p)->f3C != 0) {
        func_0204047C(1, ((struct Obj09201 *)p)->f38);
        ((struct Obj09201 *)p)->f3C = 0;
    }
}

