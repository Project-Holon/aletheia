/*
 * function: func_021C83CC
 * address:  0x021C83CC
 * packet:   pkt_021C83CC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_NextSerialNumber   0x021C2E4C  thumb ov093
 *   func_021C83CC   0x021C83CC  thumb ov093
 *
 * tail-call thunk to BTL_SERVER_FLOW_NextSerialNumber
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u32 BTL_SERVER_FLOW_NextSerialNumber(u8 *p);

u32 func_021C83CC(u8 *p)
{
    return BTL_SERVER_FLOW_NextSerialNumber(p);
}
