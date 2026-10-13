/*
 * function: BTL_SERVER_FLOW_CalcPokeSpeedWrapper
 * address:  0x021C81C8
 * packet:   pkt_021C81C8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_CalcPokeSpeed   0x021BC948  thumb ov093
 *   BTL_SERVER_FLOW_CalcPokeSpeedWrapper   0x021C81C8  thumb ov093
 *
 * tail-call thunk to BTL_SERVER_FLOW_CalcPokeSpeed
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u16 BTL_SERVER_FLOW_CalcPokeSpeed(u8 *p, u8 *x, int flag);

u16 BTL_SERVER_FLOW_CalcPokeSpeedWrapper(u8 *p, u8 *x, int flag)
{
    return BTL_SERVER_FLOW_CalcPokeSpeed(p, x, flag);
}
