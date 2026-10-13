/*
 * function: BTL_SERVER_NotifyCapture
 * address: 0x021BB8DC
 * packet: pkt_ov093_021BB8DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_GetMon 0x021D5844 thumb ov093
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   GAME_BEACON_SetPokeCapture 0x020271DC thumb
 *   BTL_MAIN_TrainerRecordAdd 0x021BA1B4 thumb ov093
 * evidence: caller narrows POKE_TOOL_GetPartyValue result to u16 before 020271DC.
 */
#include "../include/Obj13295.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *BTL_POKEPARAM_GetMon(void *);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern void GAME_BEACON_SetPokeCapture(u16);
extern void BTL_MAIN_TrainerRecordAdd(char **p, int i);
void BTL_SERVER_NotifyCapture(u8 *p, u32 *q) {
    GAME_BEACON_SetPokeCapture(POKE_TOOL_GetPartyValue(BTL_POKEPARAM_GetMon(q),5,0));
    BTL_MAIN_TrainerRecordAdd((char **)(*(u8 * *)&((struct Obj13295 *)p)->fC),7);
    BTL_MAIN_TrainerRecordAdd((char **)(*(u8 * *)&((struct Obj13295 *)p)->fC),0x54);
}
