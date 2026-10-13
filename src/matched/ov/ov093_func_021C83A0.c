/*
 * function: BTL_SERVER_FLOW_CalcPokeWeight
 * address: 0x021C83A0
 * packet: pkt_ov093_021C83A0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow the 42-byte function.
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_SERVER_FLOW_QueryPokeMultiplierEvent 0x021C2AF0 thumb ov093
 *   BTL_POKEPARAM_GetWeight 0x021D67E8 thumb ov093
 *   BTL_CALC_MulRatio 0x021D7B10 thumb ov093
 */
#include "../include/Obj21119.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_SERVER_FLOW_QueryPokeMultiplierEvent(u8 *, u8 *);
extern u16 BTL_POKEPARAM_GetWeight(u8 *p);
extern u32 BTL_CALC_MulRatio(u32, u32);
u32 BTL_SERVER_FLOW_CalcPokeWeight(u8 *p, int i)
{
    u8 *a = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj21119 *)p)->f8, i);
    int b = BTL_SERVER_FLOW_QueryPokeMultiplierEvent(p, a);
    u32 r = BTL_CALC_MulRatio(BTL_POKEPARAM_GetWeight(a), b);
    if (r < 1) r = 1;
    return r;
}
