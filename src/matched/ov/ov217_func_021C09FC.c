/*
 * function: RESEARCH_COMMON_SetInputFlag
 * address:  0x021C09FC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Set the u32 at +0x3c to 1.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25983.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void RESEARCH_COMMON_SetInputFlag(void *p)
{
    ((struct Obj25983 *)p)->f3C = 1;
}
