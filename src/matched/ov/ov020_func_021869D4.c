/*
 * function: FIELD_WFBC_DATA_LOCAL_WriteValue
 * address:  0x021869D4
 * packet:   pkt_021869D4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj19470.h"

typedef unsigned short u16;

void FIELD_WFBC_DATA_LOCAL_WriteValue(char *p, u16 v)
{
    ((struct Obj19470 *)p)->f2 = v;
}
