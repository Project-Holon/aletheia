/*
 * function: MONOLITH_TOOL_GetSlotIconStates
 * address: 0x021B6F40
 * packet: pkt_ov071_021B6F40
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetBattleRecSlotByNetId 0x021583CC thumb ov010
 */
#include "../include/Obj13167.h"
typedef unsigned char u8;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int GAME_DATA_GetBattleRecSlotByNetId(void *a0, int a1);
void *MONOLITH_TOOL_GetSlotIconStates(u8 **p)
{
    u8 *q = *p;
    return (void *)GAME_DATA_GetBattleRecSlotByNetId(GAMESYSTEM_GetGameData(((struct Obj13167 *)q)->f0), q[0x3c]);
}
