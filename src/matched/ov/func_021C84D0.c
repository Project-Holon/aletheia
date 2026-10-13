/*
 * function: BTL_SERVER_FLOW_DispatchPokeEntryEventToType4Thunk
 * address:  0x021C84D0
 * packet:   pkt_021C84D0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_DispatchPokeEntryEventToType4   0x021BDBB8  thumb ov093
 *   BTL_SERVER_FLOW_DispatchPokeEntryEventToType4Thunk   0x021C84D0  thumb ov093
 *
 * tail-call thunk to BTL_SERVER_FLOW_DispatchPokeEntryEventToType4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void BTL_SERVER_FLOW_DispatchPokeEntryEventToType4(u8 *p, u8 *a);

void BTL_SERVER_FLOW_DispatchPokeEntryEventToType4Thunk(u8 *p, u8 *a)
{
    BTL_SERVER_FLOW_DispatchPokeEntryEventToType4(p, a);
}
