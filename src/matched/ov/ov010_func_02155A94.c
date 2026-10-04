/*
 * function: func_02155A94
 * address:  0x02155A94
 * packet:   pkt_ov010_02155A94
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: reads the word at +0x4C.
 *
 * symbols:
 *   (none)
 */
#include "../include/Obj18685.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

u32 func_02155A94(u8 *p)
{
    return ((struct Obj18685 *)p)->f4C;
}
