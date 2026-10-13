/*
 * function: BTL_SERVER_FLOW_GetLastActionId
 * address:  0x021C8114
 * packet:   pkt_021C8114
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetLastActionId   0x021C8114  thumb ov093
 *
 * ldrh at #0x1f74 (pool constant)
 */
#include "../include/Obj18333.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u16 BTL_SERVER_FLOW_GetLastActionId(u8 *p)
{
    return ((struct Obj18333 *)p)->f1F74;
}
