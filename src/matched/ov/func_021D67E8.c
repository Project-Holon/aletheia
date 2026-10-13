/*
 * function: BTL_POKEPARAM_GetWeight
 * address:  0x021D67E8
 * packet:   pkt_021D67E8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetWeight   0x021D67E8  thumb ov093
 *
 * ldrh at #0x13e (pool constant)
 */
#include "../include/Obj18419.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u16 BTL_POKEPARAM_GetWeight(u8 *p)
{
    return ((struct Obj18419 *)p)->f13E;
}
