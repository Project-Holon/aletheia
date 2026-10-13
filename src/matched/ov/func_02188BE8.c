/*
 * function: FIELDMAP_IsReady
 * address:  0x02188BE8
 * packet:   pkt_02188BE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17857.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int FIELDMAP_IsReady(void *a)
{
if (((struct Obj17857 *)a)->fC0 == 1) {
    return 1;
}
return 0;
}

