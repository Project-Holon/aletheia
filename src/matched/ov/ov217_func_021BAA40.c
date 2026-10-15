/*
 * function: RESEARCH_TOP_ClearActor
 * address:  0x021BAA40
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clear the u32 at +0x7c.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25837.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void RESEARCH_TOP_ClearActor(void *p)
{
    ((struct Obj25837 *)p)->f7C = 0;
}
