/*
 * function: RESEARCH_COMMON_SetScreen
 * address:  0x021C09BC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Shift the two u32 fields at +0x30/+0x34 and store the new value at +0x34.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10963.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void RESEARCH_COMMON_SetScreen(void *p, u32 v)
{
    ((struct Obj10963 *)p)->f30 = ((struct Obj10963 *)p)->f34;
    ((struct Obj10963 *)p)->f34 = v;
}
