/*
 * function: ARROW_SetState
 * address:  0x021C218C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Set +0x20 and clear +0x24.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14763.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void ARROW_SetState(void *p, u32 v)
{
    ((struct Obj14763 *)p)->f20 = v;
    ((struct Obj14763 *)p)->f24 = 0;
}
