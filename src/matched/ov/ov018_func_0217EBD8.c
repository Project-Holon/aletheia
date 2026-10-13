/*
 * function: INTRUDE_SUBDISP_GetTargetPlayerData
 * address: 0x0217EBD8
 * packet: pkt_ov018_0217EBD8
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x0217EC06.
 * interface: GAME_DATA_GetLastBattleRecSlot tail-forwards GAME_DATA_GetBattleRecSlot's pointer result.
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetExitMode 0x02012B58 thumb
 *   GAME_DATA_GetLastBattleRecSlot 0x020127B8 thumb
 *   GAME_DATA_GetBattleRecSlot 0x020127AC thumb
 */
#include "../include/Obj12491.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct BigObj;
struct Ctx;
struct SaveBlock;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 GAME_DATA_GetExitMode(const struct BigObj *p);
extern void *GAME_DATA_GetLastBattleRecSlot(void *);
extern void *GAME_DATA_GetBattleRecSlot(struct SaveBlock *p, u32 idx);
void *INTRUDE_SUBDISP_GetTargetPlayerData(u8 *p)
{
    void *h;
    int i;
    h = GAMESYSTEM_GetGameData(((struct Obj12491 *)p)->f0);
    i = p[0xd8];
    if (i == GAME_DATA_GetExitMode(h) || i == 0x80) {
        return GAME_DATA_GetLastBattleRecSlot(h);
    } else {
        return GAME_DATA_GetBattleRecSlot(h, i);
    }
}
