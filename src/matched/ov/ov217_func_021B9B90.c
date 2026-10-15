/*
 * function: RESEARCH_TOP_GetListObjectMode
 * address:  0x021B9B90
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Field getter, u32 at +0x8c.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25807.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 RESEARCH_TOP_GetListObjectMode(void *p)
{
    return ((struct Obj25807 *)p)->f8C;
}
