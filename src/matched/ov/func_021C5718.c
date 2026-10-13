/*
 * function: BTL_SERVER_FLOW_PushMsgStdFailed
 * address:  0x021C5718
 * packet:   pkt_021C5718
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_PushMsgStdFailed   0x021C5718  thumb
 *   BTL_SERVER_CMD_PushVariable   0x021CD64C  thumb
 * 7 instructions, 16 bytes: push {r3, lr}; ldr r0, [r0, #0xc]; ldr r3, pool_021C5728; movs r1, #0x5a; movs r2, #0x47; bl BTL_SERVER_CMD_PushVariable; pop {r3, pc}.
 */
#include "../include/Obj18306.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021C5718  4-arg call, field 0xc and the pool constant 0xffff0000 */
void BTL_SERVER_FLOW_PushMsgStdFailed(u8 *p)
{
    BTL_SERVER_CMD_PushVariable(((struct Obj18306 *)p)->fC, 0x5a, 0x47, 0xffff0000);
}

