/*
 * function: BTL_POKEPARAM_GetUsedMoveTotal
 * address:  0x021D54B4
 * packet:   pkt_021D54B4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetUsedMoveTotal   0x021D54B4  thumb ov093
 *
 * ldrb at #0x143 (pool constant)
 */
#include "../include/Obj18407.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u8 BTL_POKEPARAM_GetUsedMoveTotal(u8 *p)
{
    return ((struct Obj18407 *)p)->f143;
}
