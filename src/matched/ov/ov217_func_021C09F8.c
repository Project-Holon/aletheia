/*
 * function: RESEARCH_COMMON_GetInputFlag
 * address:  0x021C09F8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +0x3c.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25982.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 RESEARCH_COMMON_GetInputFlag(void *p)
{
    return ((struct Obj25982 *)p)->f3C;
}
