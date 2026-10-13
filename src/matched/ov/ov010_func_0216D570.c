/*
 * function: FLDMMDL_ClearMoveBit
 * address:  0x0216D570
 * packet:   pkt_0216D570
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj19125.h"

typedef unsigned int u32;

char *FLDMMDL_ClearMoveBit(char *p, u32 v)
{
    ((struct Obj19125 *)p)->f4 &= ~v;
    return p;
}
