/*
 * function: RESEARCH_LIST_SetMomentumDirection
 * address:  0x021BC2B8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sign of +0x4c into +0x50: 1 when negative, -1 otherwise.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00025.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void RESEARCH_LIST_SetMomentumDirection(void *p)
{
    if (((struct Obj00025 *)p)->f4C < 0) {
        ((struct Obj00025 *)p)->f50 = 1;
    } else {
        ((struct Obj00025 *)p)->f50 = -1;
    }
}
