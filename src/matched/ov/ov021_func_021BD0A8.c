/*
 * function: FIELD_PLACE_NAME_ResetFrame
 * address:  0x021BD0A8
 * packet:   pkt_021BD0A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj20122.h"

typedef unsigned short u16;

void FIELD_PLACE_NAME_ResetFrame(char *p)
{
    ((struct Obj20122 *)p)->f42 = 0;
}
