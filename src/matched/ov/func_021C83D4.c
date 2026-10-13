/*
 * function: BTL_SERVER_FLOW_CheckShowdownThunk
 * address:  0x021C83D4
 * packet:   pkt_021C83D4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_CheckShowdown   0x021BC2B0  thumb ov093
 *   BTL_SERVER_FLOW_CheckShowdownThunk   0x021C83D4  thumb ov093
 *
 * tail-call thunk to BTL_SERVER_FLOW_CheckShowdown
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int BTL_SERVER_FLOW_CheckShowdown(u8 *p);

int BTL_SERVER_FLOW_CheckShowdownThunk(u8 *p)
{
    return BTL_SERVER_FLOW_CheckShowdown(p);
}
