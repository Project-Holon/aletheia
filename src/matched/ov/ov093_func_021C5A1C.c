/*
 * function: BTL_SERVER_FLOW_PushAbilityPopupIn
 * address: 0x021C5A1C
 * packet: pkt_ov093_021C5A1C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
void BTL_SERVER_FLOW_PushAbilityPopupIn(u8 *p, u8 *a)
{
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x57, BTL_POKEPARAM_GetPokeId(a));
}
