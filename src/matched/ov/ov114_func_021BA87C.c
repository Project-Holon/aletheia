/*
 * function: NHTTPi_SetSSLError
 * address:  0x021BA87C
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Word setter at +0x10.
 */
#include "../include/Obj22575.h"

typedef unsigned char u8;
typedef unsigned int u32;
void NHTTPi_SetSSLError(u8 *p, int v)
{
    ((struct Obj22575 *)p)->f10 = v;
}
