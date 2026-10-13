/*
 * function: BTL_SERVER_FLOW_GetOpponentResistedCount
 * address:  0x021C7CE8
 * packet:   pkt_021C7CE8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetOpponentResistedCount   0x021C7CE8  thumb ov093
 *
 * ldrh at #0x1f86 (pool constant)
 */
#include "../include/Obj18323.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u16 BTL_SERVER_FLOW_GetOpponentResistedCount(u8 *p)
{
    return ((struct Obj18323 *)p)->f1F86;
}
