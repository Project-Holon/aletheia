/*
 * function: BTL_SERVER_FLOW_Reset
 * address:  0x021BB9D0
 * packet:   pkt_021BB9D0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_InitState   0x021BB9D8  thumb ov093
 *   BTL_SERVER_FLOW_Reset   0x021BB9D0  thumb ov093
 *
 * tail-call thunk to BTL_SERVER_FLOW_InitState
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void BTL_SERVER_FLOW_InitState(u8 *p);

void BTL_SERVER_FLOW_Reset(u8 *p)
{
    BTL_SERVER_FLOW_InitState(p);
}
