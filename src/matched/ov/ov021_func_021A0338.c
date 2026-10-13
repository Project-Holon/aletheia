/*
 * function: FIELD_ZONEFOG_SetUp
 * address:  0x021A0338
 * packet:   pkt_ov021_021A0338
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07486.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

void FIELD_ZONEFOG_SetUp(u8 *p, u32 id, u32 c, u8 d)
{
    if (id != 0x0FFFFFFF) {
        p[0] = 1;
        ((struct Obj07486 *)p)->f2 = id;
        p[1] = d;
    }
    ((struct Obj07486 *)p)->f8 = c;
}
