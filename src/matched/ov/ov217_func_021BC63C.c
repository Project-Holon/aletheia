/*
 * function: RESEARCH_LIST_GetOwner
 * address:  0x021BC63C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +0.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25869.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 RESEARCH_LIST_GetOwner(void *p)
{
    return ((struct Obj25869 *)p)->f0;
}
