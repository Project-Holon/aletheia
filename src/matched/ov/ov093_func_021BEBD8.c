/*
 * function: BTL_SERVER_FLOW_PushMoveExecCmd
 * address: 0x021BEBD8
 * packet: pkt_ov093_021BEBD8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_MAIN_GetTrainerSlotOfPoke 0x021B8D8C thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 */
#include "../include/Obj09964.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_MAIN_GetTrainerSlotOfPoke(void *,void *,u32);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
void BTL_SERVER_FLOW_PushMoveExecCmd(u8 *p,u8 *a,int c,int d)
{
    int n;
    n=BTL_MAIN_GetTrainerSlotOfPoke(((struct Obj09964 *)p)->f4,((struct Obj09964 *)p)->f8,BTL_POKEPARAM_GetPokeId(a));
    BTL_SERVER_CMD_Push(((struct Obj09964 *)p)->fC,0x30,n,d,c,0);
}
