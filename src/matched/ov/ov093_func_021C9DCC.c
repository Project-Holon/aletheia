/*
 * function: BTL_SERVER_FLOW_ExecCmdProcItemReaction
 * address: 0x021C9DCC
 * packet: pkt_ov093_021C9DCC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_SERVER_FLOW_ProcDamagedItemReaction 0x021C195C thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_SERVER_FLOW_ProcDamagedItemReaction(u8 *, u8 *, u32);
int BTL_SERVER_FLOW_ExecCmdProcItemReaction(u8 *p, u8 *q)
{
    u8 *a = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, q[4]);
    BTL_SERVER_FLOW_ProcDamagedItemReaction(p, a, *(u32 *)(q + 8));
    return 1;
}
