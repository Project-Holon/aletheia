/*
 * function: NHTTPi_GetSSLError
 * address:  0x021BA884
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Word getter at +0x10.
 */
#include "../include/Obj22576.h"

typedef unsigned char u8;
typedef unsigned int u32;
u32 NHTTPi_GetSSLError(u8 *p)
{
    return ((struct Obj22576 *)p)->f10;
}
