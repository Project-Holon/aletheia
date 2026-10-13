/*
 * function: BTL_MAIN_GetLimitTimeCommand
 * address:  0x021BA5C4
 * packet:   pkt_021BA5C4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetLimitTimeCommand   0x021BA5C4  thumb ov093
 *
 * ldrh at #0x442 (pool constant)
 */
#include "../include/Obj18159.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u16 BTL_MAIN_GetLimitTimeCommand(u8 *p)
{
    return ((struct Obj18159 *)p)->f442;
}
