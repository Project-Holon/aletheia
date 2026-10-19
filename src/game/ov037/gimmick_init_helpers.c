/*
 * file:     gimmick_init_helpers.c
 * unit:     yes
 * function: GIMMICK_INIT_SetCartLanesFlags, GIMMICK_INIT_SetFlagAnimeFlag, GIMMICK_INIT_SetButtonStatesFlags, GIMMICK_INIT_RestorePlateDoorsState, GIMMICK_INIT_ResetRotatingRoomPanels
 * address:  0x021F36C0
 * region:   ov037
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetWork  0x0200B3A4  thumb
 *   GAME_DATA_GetMyPlayerWork 0x020127A4 thumb
 *   GIMMICK_WORK_GetSubWork  0x0200B3A8  thumb
 *   gPlateDoorsSwitchPlates     0x021F3840  data ov037 a1
 *   gPlateDoorsDoorPlates     0x021F3834  data a1
 */
#include "gimmick_save_types.h"

struct GameSystem;
struct GameData;
struct GimmickWork;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;

extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct GimmickWork *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern void *GAME_DATA_GetMyPlayerWork(struct GameData *gameData);
extern void *GIMMICK_WORK_GetWork(struct GimmickWork *gimmick, u32 gimmickId);
extern u16 *GIMMICK_WORK_GetSubWork(struct GimmickWork *gimmick, u32 gimmickId);
void GIMMICK_INIT_SetCartLanesFlags(unsigned int gameSystem, int setFirst, int setSecond);
void GIMMICK_INIT_SetFlagAnimeFlag(struct GameSystem *gameSystem, int enable);
void GIMMICK_INIT_SetButtonStatesFlags(unsigned int gameSystem, int buttonMask);
void GIMMICK_INIT_RestorePlateDoorsState(unsigned int gameSystem, unsigned short **foundVars);

/* Per switch: the two plates it lights (-1 for none). Per door: the two plates that open it. */
extern signed char gPlateDoorsSwitchPlates[][2];
extern unsigned char gPlateDoorsDoorPlates[][2];

/* Marks the first and second flag of gimmick 39 as set. */
void GIMMICK_INIT_SetCartLanesFlags(unsigned int gameSystem, int setFirst, int setSecond)
{
    FieldGimmickCartLanesSave *work = GIMMICK_WORK_GetWork(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct GameSystem *)gameSystem)), 2);

    if (setFirst)
        work->laneUnlocked[0] = 1;
    if (setSecond)
        work->laneUnlocked[1] = 1;
}

/* Sets the flag of gimmick 40 and its byte mirror. */
void GIMMICK_INIT_SetFlagAnimeFlag(struct GameSystem *gameSystem, int enable)
{
    struct GameData *gameData;
    FieldGimmickFlagAnimeSave *work;
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    work = GIMMICK_WORK_GetWork(GAME_DATA_GetFieldSave(gameData), 3);
    GAME_DATA_GetMyPlayerWork(gameData);
    if (enable) work->flag = 1;
    else work->flag = 0;
    if (work->flag) work->animeDone[0] = 1;
    else work->animeDone[0] = 0;
}


/* Sets the three flags of gimmick 42 from the low three bits of the mask. */
void GIMMICK_INIT_SetButtonStatesFlags(unsigned int gameSystem, int buttonMask)
{
    FieldGimmickButtonStatesSave *work = GIMMICK_WORK_GetWork(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct GameSystem *)gameSystem)), 4);
    unsigned char i;

    for (i = 0; i < 3; i++)
        work->oneShotPlayed[i] = 0;
    if (buttonMask & 1)
        work->oneShotPlayed[0] = 1;
    if ((buttonMask >> 1) & 1)
        work->oneShotPlayed[1] = 1;
    if ((buttonMask >> 2) & 1)
        work->oneShotPlayed[2] = 1;
}


/*
 * Rebuilds the state of gimmick 38 from its saved progress: every found switch
 * sets its script variable and lights its plates, and every door whose two
 * plates are lit opens.  The last door is always open.
 */
void GIMMICK_INIT_RestorePlateDoorsState(unsigned int gameSystem, unsigned short **foundVars)
{
    struct GimmickWork *gimmickSave = GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct GameSystem *)gameSystem));
    FieldGimmickPlateDoorsWork *work = GIMMICK_WORK_GetWork(gimmickSave, 6);
    u16 *progress = GIMMICK_WORK_GetSubWork(gimmickSave, 6);
    int switchIdx;
    int linkIdx;
    int plateIdx;

    for (switchIdx = 0; switchIdx < 8; switchIdx++) {
        if (progress[switchIdx] != 0) {
            work->switchFound[switchIdx] = 1;
            *foundVars[switchIdx] = 1;
            for (linkIdx = 0; linkIdx < 2; linkIdx++) {
                plateIdx = gPlateDoorsSwitchPlates[switchIdx][linkIdx];
                if (plateIdx != -1)
                    work->platePressed[plateIdx] = 1;
            }
        }
    }
    for (switchIdx = 0; switchIdx < 6; switchIdx++) {
        for (linkIdx = 0; linkIdx < 2; linkIdx++) {
            if (work->platePressed[gPlateDoorsDoorPlates[switchIdx][linkIdx]] == 0)
                break;
        }
        if (linkIdx == 2)
            work->doorOpen[switchIdx] = 1;
    }
    work->doorOpen[6] = 1;
}

/* Sets the three units of gimmick 46 to their starting pose and lever states. */
void GIMMICK_INIT_ResetRotatingRoomPanels(unsigned int gameSystem)
{
    FieldGimmickRotatingRoomSave *work = GIMMICK_WORK_GetWork(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct GameSystem *)gameSystem)), 10);
    FieldGimmickRotatingRoomUnit *unit = &work->units[0];

    unit->pose = 3;
    unit->leverOn[0] = 0;
    unit->leverOn[1] = 1;
    unit = &work->units[1];
    unit->pose = 1;
    unit->leverOn[0] = 1;
    unit->leverOn[1] = 1;
    unit = &work->units[2];
    unit->pose = 2;
    unit->leverOn[0] = 1;
    unit->leverOn[1] = 0;
}
