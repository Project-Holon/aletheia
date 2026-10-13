/*
 * function: BTL_SERVER_FLOW_GetOpponentNoEffectCount
 * address:  0x021C7CDC
 * packet:   pkt_021C7CDC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetOpponentNoEffectCount   0x021C7CDC  thumb ov093
 *
 * ldrh at #0x1f82 (pool constant)
 */
#include "../include/Obj18322.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u16 BTL_SERVER_FLOW_GetOpponentNoEffectCount(u8 *p)
{
    return ((struct Obj18322 *)p)->f1F82;
}
