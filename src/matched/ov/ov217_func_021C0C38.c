/*
 * function: RESEARCH_COMMON_ClearPalAnm
 * address:  0x021C0C38
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clear the u32 at +0x28.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25989.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void RESEARCH_COMMON_ClearPalAnm(void *p)
{
    ((struct Obj25989 *)p)->f28 = 0;
}
