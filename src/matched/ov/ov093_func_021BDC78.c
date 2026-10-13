/*
 * function: BTL_SERVER_FLOW_PushMemberOutCmd
 * address: 0x021BDC78
 * packet: pkt_ov093_021BDC78
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 func_021B8DDC(u32 x);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
void BTL_SERVER_FLOW_PushMemberOutCmd(u8 *p, u8 *a)
{
    u8 id;
    int value;
    id = BTL_POKEPARAM_GetPokeId(a);
    value = func_021B8DDC(id);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x3b, value, id);
}
