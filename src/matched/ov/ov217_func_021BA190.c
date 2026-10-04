/*
 * function: func_021BA190
 * address:  0x021BA190
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +0x1c.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25810.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021BA190(void *p)
{
    return ((struct Obj25810 *)p)->f1C;
}
