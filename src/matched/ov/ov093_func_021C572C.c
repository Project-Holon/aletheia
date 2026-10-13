/*
 * function: BTL_SERVER_FLOW_PushMoveBlockedMessage
 * address: 0x021C572C
 * packet: pkt_ov093_021C572C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 */
#include "../include/Obj07752.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_PushVariable(void *, u8, ...);
void BTL_SERVER_FLOW_PushMoveBlockedMessage(u8 *p, u8 *a, u32 v)
{
    BTL_SERVER_CMD_PushVariable(((struct Obj07752 *)p)->fC, 0x5b, 213, BTL_POKEPARAM_GetPokeId(a), 0xffff0000);
}
