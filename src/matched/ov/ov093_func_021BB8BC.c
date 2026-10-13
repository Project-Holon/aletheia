/*
 * function: BTL_SERVER_NotifyLevelUp
 * address: 0x021BB8BC
 * packet: pkt_ov093_021BB8BC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_GetMon 0x021D5844 thumb ov093
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   GAME_BEACON_SetPokeLevelUp 0x02027268 thumb
 */
#include "../include/Obj13294.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void *BTL_POKEPARAM_GetMon(void *);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern void GAME_BEACON_SetPokeLevelUp(u32);
void BTL_SERVER_NotifyLevelUp(u8 *p, u32 *q) {
    POKE_TOOL_GetPartyValue(BTL_POKEPARAM_GetMon(q),0x73,((struct Obj13294 *)p)->fAC);
    GAME_BEACON_SetPokeLevelUp(((struct Obj13294 *)p)->fAC);
}
