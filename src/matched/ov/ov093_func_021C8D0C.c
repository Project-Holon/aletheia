/*
 * function: BTL_SERVER_FLOW_ExecCmdAbilityPopupOut
 * address: 0x021C8D0C
 * packet: pkt_ov093_021C8D0C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: caller narrows index to u8 before BTL_SIDE_GetPokeByIdThunk.
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_SERVER_FLOW_PushAbilityPopupOut 0x021C5A34 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 pad : 8; u32 idx : 5; u32 rest : 19; } Ent;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_SERVER_FLOW_PushAbilityPopupOut(u8 *p, u8 *a);
int BTL_SERVER_FLOW_ExecCmdAbilityPopupOut(u8 *p, Ent *e)
{
    BTL_SERVER_FLOW_PushAbilityPopupOut(p, BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, (u8)e->idx));
    return 1;
}
