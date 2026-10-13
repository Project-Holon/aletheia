/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, GIMMICK_INIT_SetGimmick40Flag, GIMMICK_INIT_SetGimmick42Flags, GIMMICK_INIT_RestoreGimmick38State
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
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   GAME_DATA_GetMyPlayerWork 0x020127A4 thumb
 *   GIMMICK_WORK_GetProgress  0x0200B3A8  thumb
 *   d_021F3840     0x021F3840  data ov037 a1
 *   gGimmick38DoorPlates     0x021F3834  data a1
 */
#include "unit_021F36C0_types.h"

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
extern void *GIMMICK_WORK_GetSaveArea(struct GimmickWork *gimmick, u32 gimmickId);
extern u16 *GIMMICK_WORK_GetProgress(struct GimmickWork *gimmick, u32 gimmickId);
void func_021F36C0(unsigned int gameSystem, int setFirst, int setSecond);
void GIMMICK_INIT_SetGimmick40Flag(struct GameSystem *gameSystem, int enable);
void GIMMICK_INIT_SetGimmick42Flags(unsigned int gameSystem, int buttonMask);
void GIMMICK_INIT_RestoreGimmick38State(unsigned int gameSystem, unsigned short **foundVars);

/* Per switch: the two plates it lights (-1 for none). Per door: the two plates that open it. */
extern signed char d_021F3840[][2];
extern unsigned char gGimmick38DoorPlates[][2];


/* Marks the first and second flag of gimmick 39 as set. */
void func_021F36C0(unsigned int gameSystem, int setFirst, int setSecond)
{
    Gimmick39Work *work = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct GameSystem *)gameSystem)), 2);

    if (setFirst)
        work->firstFlag = 1;
    if (setSecond)
        work->secondFlag = 1;
}

/* Sets the flag of gimmick 40 and its byte mirror. */
void GIMMICK_INIT_SetGimmick40Flag(struct GameSystem *gameSystem, int enable)
{
    struct GameData *gameData;
    Gimmick40Work *work;
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    work = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(gameData), 3);
    GAME_DATA_GetMyPlayerWork(gameData);
    if (enable) work->enabled = 1;
    else work->enabled = 0;
    if (work->enabled) work->enabledByte = 1;
    else work->enabledByte = 0;
}


/* Sets the three flags of gimmick 42 from the low three bits of the mask. */
void GIMMICK_INIT_SetGimmick42Flags(unsigned int gameSystem, int buttonMask)
{
    Gimmick42Work *work = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct GameSystem *)gameSystem)), 4);
    unsigned char i;

    for (i = 0; i < 3; i++)
        work->flag[i] = 0;
    if (buttonMask & 1)
        work->flag[0] = 1;
    if ((buttonMask >> 1) & 1)
        work->flag[1] = 1;
    if ((buttonMask >> 2) & 1)
        work->flag[2] = 1;
}


/*
 * Rebuilds the state of gimmick 38 from its saved progress: every found switch
 * sets its script variable and lights its plates, and every door whose two
 * plates are lit opens.  The last door is always open.
 */
void GIMMICK_INIT_RestoreGimmick38State(unsigned int gameSystem, unsigned short **foundVars)
{
    struct GimmickWork *gimmickSave = GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct GameSystem *)gameSystem));
    Gimmick38Work *work = GIMMICK_WORK_GetSaveArea(gimmickSave, 6);
    u16 *progress = GIMMICK_WORK_GetProgress(gimmickSave, 6);
    int switchIdx;
    int linkIdx;
    int plateIdx;

    for (switchIdx = 0; switchIdx < 8; switchIdx++) {
        if (progress[switchIdx] != 0) {
            work->switchFound[switchIdx] = 1;
            *foundVars[switchIdx] = 1;
            for (linkIdx = 0; linkIdx < 2; linkIdx++) {
                plateIdx = d_021F3840[switchIdx][linkIdx];
                if (plateIdx != -1)
                    work->platePressed[plateIdx] = 1;
            }
        }
    }
    for (switchIdx = 0; switchIdx < 6; switchIdx++) {
        for (linkIdx = 0; linkIdx < 2; linkIdx++) {
            if (work->platePressed[gGimmick38DoorPlates[switchIdx][linkIdx]] == 0)
                break;
        }
        if (linkIdx == 2)
            work->doorOpen[switchIdx] = 1;
    }
    work->doorOpen[6] = 1;
}
