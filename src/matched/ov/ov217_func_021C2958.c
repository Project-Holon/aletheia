/*
 * function: PERCENTAGE_StoreUnit
 * address:  0x021C2958
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter, u32 at +0xc.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26033.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void PERCENTAGE_StoreUnit(void *p, u32 v)
{
    ((struct Obj26033 *)p)->fC = v;
}
