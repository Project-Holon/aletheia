/*
 * function: GIMMICK_INIT_ResetGimmick46Panels
 * address:  0x021F3800
 * packet:   pkt_ov037_021F3800
 * region:   ov037
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 */

#include "../unit_021F36C0_types.h"

typedef unsigned int   u32;
struct GameSystem;
struct GameData;
struct GimmickWork;
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct GimmickWork *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern void *GIMMICK_WORK_GetSaveArea(struct GimmickWork *gimmick, u32 gimmickId);

/* Fills the three panel rows of gimmick 46 with their starting values. */
void GIMMICK_INIT_ResetGimmick46Panels(unsigned int gameSystem)
{
    Gimmick46Work *work = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct GameSystem *)gameSystem)), 10);
    int *firstRow = work->panel[0];
    int *secondRow;
    int *thirdRow;

    firstRow[0] = 3;
    firstRow[1] = 0;
    firstRow[2] = 1;
    secondRow = work->panel[1];
    secondRow[0] = 1;
    secondRow[1] = 1;
    secondRow[2] = 1;
    thirdRow = work->panel[2];
    thirdRow[0] = 2;
    thirdRow[1] = 1;
    thirdRow[2] = 0;
}
