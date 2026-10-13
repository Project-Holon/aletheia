/*
 * function: BTL_SERVER_FLOW_ProcHandExSetPokeCounter
 * address: 0x021C9F4C
 * packet: pkt_ov093_021C9F4C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_SERVER_FLOW_SetPokeCounter 0x021C0780 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_SERVER_FLOW_SetPokeCounter(u8 *, u8 *, int, u8);
int BTL_SERVER_FLOW_ProcHandExSetPokeCounter(u8 *p, u8 *q)
{
    u8 *a = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, q[4]);
    BTL_SERVER_FLOW_SetPokeCounter(p, a, q[5], q[6]);
    return 1;
}
