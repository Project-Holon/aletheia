/*
 * function: NHTTPi_SetError
 * address:  0x021BA874
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Word setter at +0x14.
 */
#include "../include/Obj22574.h"

typedef unsigned char u8;
typedef unsigned int u32;
void NHTTPi_SetError(u8 *p, int v)
{
    ((struct Obj22574 *)p)->f14 = v;
}
