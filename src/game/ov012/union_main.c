/*
 * file:     union_main.c
 * unit:     yes
 * function: UNION_MAIN_StartComm, UNION_MAIN_UpdateField, UNION_MAIN_IsFieldReady, UNION_MAIN_FieldCreateCallback, UNION_MAIN_FieldDeleteCallback, UNION_MAIN_GetFieldRequest, UNION_MAIN_IsExitStarted, UNION_MAIN_SetAppealNo, UNION_MAIN_GetAppealNo, UNION_MAIN_IsIdle
 * address:  0x02173744
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from union_main.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   UNION_SCENE_IsScenePending  0x02174268  thumb  ov012
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   COLOSSEUM_Delete  0x0217505C  thumb  ov012
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GF_PANIC_Fail  0x02034714  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_COMM_Start  0x020263D8  thumb
 *   GAME_BEACON_SEARCH_SetFieldEvent  0x021653C4  thumb  ov010
 *   sUnionMainAssertText     0x02175610  data   ov012  a1
 *   sUnionMainFile     0x02175614  data   ov012  a1
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetFieldMapState  0x0201212C  thumb
 *   GAME_EVENT_IsRunning  0x020123C4  thumb
 *   UNION_ONESELF_RunPlayCategory  0x0217B840  thumb  ov019
 *   UNION_CHARA_ProcessBeaconUpdates  0x0217B75C  thumb  ov019
 *   UNION_CHARA_Main  0x0217B264  thumb  ov019
 *   GAMESYSTEM_IsFieldMapActive 0x02012114 thumb
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_IsReady 0x02188BE8 thumb ov021
 *   FIELDMAP_CTRL_GRID_SetBusy  0x021A2E44  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   ZONEDATA_IsUnionRoom  0x02013CC8  thumb
 *   UNION_CHARA_RefreshParentMarks  0x0217B440  thumb  ov019
 *   COMM_PLAYER_Resume  0x021676E4  thumb  ov010
 *   COMM_PLAYER_Suspend  0x02167688  thumb  ov010
 */
#include "../sdk_fx.h"

#include "union_comm_types.h"

#include "../arm9/gfl_heap_wrap.h"

#include "union_scene.h"

#include "../arm9/gamesystem.h"
struct ColosseumWork;

#include "colosseum.h"


#include "../arm9/game_comm.h"

#include "../arm9/gf_panic.h"

#include "../arm9/game_data.h"


#include "../ov010/game_beacon_set.h"

struct FieldMap;

#include "../ov021/fieldmap.h"


#include "../arm9/game_event.h"

#include "../ov019/union_oneself.h"

typedef int Bool;
#include "../ov019/union_chara.h"





#include "../ov021/fieldmap_ctrl_grid.h"


#include "../arm9/zonedata.h"

struct CommPlayerWork;

#include "../ov010/comm_player.h"


void UNION_MAIN_StartComm(struct GameSystem *gameSystem);

void UNION_MAIN_UpdateField(struct GameComm *gameComm, void *fieldMap);

int UNION_MAIN_IsFieldReady(UnionRoomWork *work);

void UNION_MAIN_FieldCreateCallback(void *gameSystem, UnionRoomWork *work, void *fieldMap);

void UNION_MAIN_FieldDeleteCallback(void *gameSystem, UnionRoomWork *work);

int UNION_MAIN_GetFieldRequest(UnionRoomWork *work);

int UNION_MAIN_IsExitStarted(UnionRoomWork *work);

void UNION_MAIN_SetAppealNo(UnionRoomWork *work, int appealNo);

u8 UNION_MAIN_GetAppealNo(UnionRoomWork *work);

int UNION_MAIN_IsIdle(struct GameSystem *gameSystem);

extern char sUnionMainAssertText[];

extern char sUnionMainFile[];

/* ---- union_main.c ---- */
void UNION_MAIN_StartComm(struct GameSystem *gameSystem)
{
    struct GameComm *gameComm;
    struct GameData *gameData;
    UnionParentWork *parent;

    gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    if (GAME_COMM_GetKind(gameComm) != 0) {
        GF_PANIC_Fail(sUnionMainAssertText, 0, sUnionMainAssertText);
    }
    parent = GFL_HEAP_Alloc(5, sizeof(UnionParentWork), 1, sUnionMainFile, 0x37);
    parent->myStatus = GAME_DATA_GetMyStatus(gameData);
    parent->gameComm = gameComm;
    parent->gameData = gameData;
    parent->gameSystem = gameSystem;
    GAME_COMM_Start(gameComm, (u32)3, (uptr)parent);
    GAME_BEACON_SEARCH_SetFieldEvent();
}

void UNION_MAIN_UpdateField(struct GameComm *gameComm, void *fieldMap)
{
    UnionRoomWork *work;
    u8 status;

    if (GAME_COMM_GetKind(gameComm) != 3) {
        return;
    }
    work = GAME_COMM_GetWork(gameComm);
    if (work == 0) {
        GF_PANIC_Fail(sUnionMainAssertText, 0, sUnionMainAssertText);
    }
    if (GAMESYSTEM_GetFieldMapState(FIELDMAP_GetGameSystem(fieldMap)) == 1) {
        return;
    }
    if (GAME_EVENT_IsRunning(work->parent->gameSystem) == 1) {
        return;
    }
    if (UNION_MAIN_IsFieldReady(work) != 1) {
        return;
    }
    status = work->mySituation.status;
    if (status >= 4 && status <= 0x17) {
        if (UNION_SCENE_IsScenePending(work) != 0) {
            return;
        }
        UNION_ONESELF_RunPlayCategory(work, fieldMap);
        return;
    }
    if (status != 0 && status != 1) {
        return;
    }
    if (UNION_SCENE_IsScenePending(work) != 0) {
        return;
    }
    UNION_CHARA_ProcessBeaconUpdates(work);
    UNION_ONESELF_RunPlayCategory(work, fieldMap);
    UNION_CHARA_Main(work, work->parent->gameData, fieldMap);
}

int UNION_MAIN_IsFieldReady(UnionRoomWork *work)
{
    if (work->fieldActive == 1 && GAMESYSTEM_IsFieldMapActive(work->parent->gameSystem) == 1
        && FIELDMAP_IsReady(GAMESYSTEM_GetFieldMap(work->parent->gameSystem)) == 1)
        return 1;
    return 0;
}

void UNION_MAIN_FieldCreateCallback(void *gameSystem, UnionRoomWork *work, void *fieldMap)
{
    ColosseumWork *colosseum;

    colosseum = work->colosseum;
    work->fieldActive = 1;
    if (work->fieldBusy == 1) {
        FIELDMAP_CTRL_GRID_SetBusy(fieldMap, 1);
    }
    if (ZONEDATA_IsUnionRoom(FIELDMAP_GetZoneId(fieldMap)) == 1) {
        UNION_CHARA_RefreshParentMarks(work, GAMESYSTEM_GetGameData(work->parent->gameSystem), fieldMap);
    }
    if (colosseum != 0 && colosseum->startFlag == 1) {
        COMM_PLAYER_Resume(colosseum->commPlayer);
    }
}

void UNION_MAIN_FieldDeleteCallback(void *gameSystem, UnionRoomWork *work)
{
    ColosseumWork *colosseum;

    colosseum = work->colosseum;
    if (colosseum != 0) {
        if (colosseum->exitRequested == 1) {
            COLOSSEUM_Delete(colosseum, work->parent->gameSystem);
            work->colosseum = 0;
        } else if (colosseum->startFlag == 1) {
            COMM_PLAYER_Suspend(colosseum->commPlayer);
        }
    }
    work->fieldActive = 0;
}

int UNION_MAIN_GetFieldRequest(UnionRoomWork *work)
{
    return work->fieldRequest;
}

int UNION_MAIN_IsExitStarted(UnionRoomWork *work)
{
    return work->exitStarted;
}

void UNION_MAIN_SetAppealNo(UnionRoomWork *work, int appealNo)
{
    work->mySituation.appealNo = appealNo;
}

u8 UNION_MAIN_GetAppealNo(UnionRoomWork *work)
{
    return work->mySituation.appealNo;
}

int UNION_MAIN_IsIdle(struct GameSystem *gameSystem)
{
    UnionRoomWork *work = GAME_COMM_GetWork(GAMESYSTEM_GetGameComm(gameSystem));
    if (work == 0) return 0;
    if ((work->mySituation.playCategory == 0
         || work->mySituation.playCategory == UNION_PLAY_CATEGORY_COLOSSEUM)
        && work->fieldBusy == 0) return 1;
    return 0;
}
