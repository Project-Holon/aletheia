/*
 * function: RESEARCH_LIST_GetActive
 * address:  0x021BAC98
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +0x168.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25842.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 RESEARCH_LIST_GetActive(void *p)
{
    return ((struct Obj25842 *)p)->f168;
}
