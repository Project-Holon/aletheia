/*
 * function: BTL_SERVER_FLOW_GetPlayerNoEffectCount
 * address:  0x021C7CBC
 * packet:   pkt_021C7CBC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetPlayerNoEffectCount   0x021C7CBC  thumb ov093
 *
 * ldrh at #0x1f7c (pool constant)
 */
#include "../include/Obj18319.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u16 BTL_SERVER_FLOW_GetPlayerNoEffectCount(u8 *p)
{
    return ((struct Obj18319 *)p)->f1F7C;
}
