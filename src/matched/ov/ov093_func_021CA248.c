/*
 * function: BTL_SERVER_FLOW_ProcHandExRollFlinch
 * address: 0x021CA248
 * packet: pkt_ov093_021CA248
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_SERVER_FLOW_RollFlinch 0x021C1D60 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_SERVER_FLOW_RollFlinch(u8 *, u8 *, u32);
u8 BTL_SERVER_FLOW_ProcHandExRollFlinch(u8 *p, const u8 *q)
{
    u8 r;
    if (BTL_SERVER_FLOW_RollFlinch(p, BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, q[4]), q[5])) r = 1;
    else r = 0;
    return r;
}
