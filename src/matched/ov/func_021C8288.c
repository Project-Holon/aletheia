/*
 * function: func_021C8288
 * address:  0x021C8288
 * packet:   pkt_021C8288
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetEffectiveWeather   0x021C2AB0  thumb ov093
 *   func_021C8288   0x021C8288  thumb ov093
 *
 * tail-call thunk to BTL_SERVER_FLOW_GetEffectiveWeather
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int BTL_SERVER_FLOW_GetEffectiveWeather(u8 *p);

int func_021C8288(u8 *p)
{
    return BTL_SERVER_FLOW_GetEffectiveWeather(p);
}
