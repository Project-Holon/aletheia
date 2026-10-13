/*
 * function: BTL_CLIENT_GetPointCounter
 * address:  0x021D3D90
 * packet:   pkt_021D3D90
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_GetPointCounter   0x021D3D90  thumb ov093
 *
 * ldrb at #0x1ab (pool constant)
 */
#include "../include/Obj18397.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u8 BTL_CLIENT_GetPointCounter(u8 *p)
{
    return ((struct Obj18397 *)p)->f1AB;
}
