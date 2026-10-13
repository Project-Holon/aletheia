/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, GIMMICK42_Exit, GIMMICK42_Update, GIMMICK42_CreateStateEvent, GIMMICK42_CreateOneShotEvent, GIMMICK42_EventSetState
 * address:  0x021F36C0
 * region:   ov042
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gGimmick42UnitSetup     0x021F3A58  data  a4
 *   d_021F3AD4     0x021F3AD4  data  a4
 *   gGimmick42OneShotPos     0x021F3A68  data  a4
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeLastFrame  0x021BE748  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   FLD_EXP_OBJ_RemoveUnit 0x021BE418 thumb ov021
 *   FLD_EXP_OBJ_UpdateAnimes 0x021BE580 thumb ov021
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   GIMMICK42_EventPlayOneShot  0x021F3980  thumb
 *   func_020124E4  0x020124E4  thumb
 */
#include "../ov021/fld_exp_obj_types.h"
#include "unit_021F36C0_types.h"

void func_021F36C0(struct FieldMap *fieldMap);
void GIMMICK42_Exit(struct FieldMap *fieldMap);
void GIMMICK42_Update(struct FieldMap *fieldMap);
struct GameEvent *GIMMICK42_CreateStateEvent(struct GameSystem *gameSystem, u32 stateModel, u32 showLastFrame);
struct GameEvent *GIMMICK42_CreateOneShotEvent(struct GameSystem *gameSystem, u32 oneShotIndex);
int GIMMICK42_EventSetState(struct GameEvent *event, int *seq, void *work);

/* Model positions; the tables are read in full, the gimmick uses a prefix of them. */
typedef struct Gimmick42PosTable {
    VecFx32 pos[GIMMICK42_STATE_MODEL_COUNT];
} Gimmick42PosTable;

extern G3dUtilSetup gGimmick42UnitSetup;
extern Gimmick42PosTable d_021F3AD4;
extern Gimmick42PosTable gGimmick42OneShotPos;

/* Load the models, place them, and show the one-shot models at their last frame when they were played. */
void func_021F36C0(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;
    Gimmick42Save *save;
    FldExpObjAnime *anime;
    u32 i;
    u8 modelIndex;
    Gimmick42PosTable statePos;
    Gimmick42PosTable oneShotPos;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 4);
    FIELDMAP_AllocCommonWork(fieldMap, 1, FIELDMAP_GetHeapId(fieldMap), 4);
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, &gGimmick42UnitSetup, 0);
    statePos = d_021F3AD4;
    for (i = 0; i < GIMMICK42_STATE_MODEL_COUNT; i = (u8)(i + 1)) {
        FLD_EXP_OBJ_GetModelStatus(expObj, 0, (u8)i)->trans = statePos.pos[i];
        FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, (u8)i, 1);
    }
    oneShotPos = gGimmick42OneShotPos;
    for (i = 0; i < GIMMICK42_ONE_SHOT_COUNT; i = (u8)(i + 1)) {
        FLD_EXP_OBJ_GetModelStatus(expObj, 0, (u8)(i + GIMMICK42_ONE_SHOT_FIRST_MODEL))->trans = oneShotPos.pos[i];
        FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, (u8)(i + GIMMICK42_ONE_SHOT_FIRST_MODEL), 1);
    }
    for (i = 0; i < GIMMICK42_ONE_SHOT_COUNT; i = (u8)(i + 1)) {
        if (save->oneShotPlayed[i]) {
            modelIndex = i + GIMMICK42_ONE_SHOT_FIRST_MODEL;
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, modelIndex, 0, 1);
            anime = FLD_EXP_OBJ_GetAnime(expObj, 0, modelIndex, 0);
            FLD_EXP_OBJ_SetAnimePaused(anime, 0);
            FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
            FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, modelIndex, 0, FLD_EXP_OBJ_GetAnimeLastFrame(anime));
        }
    }
}

void GIMMICK42_Exit(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj = FIELDMAP_GetExpObj(fieldMap);

    FIELDMAP_FreeCommonWork(fieldMap, 1);
    FLD_EXP_OBJ_RemoveUnit(expObj, 0);
}

void GIMMICK42_Update(struct FieldMap *fieldMap)
{
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
}

/* Create the event that sets the state of one of the first nine models; null for an unknown model. */
struct GameEvent *GIMMICK42_CreateStateEvent(struct GameSystem *gameSystem, u32 stateModel, u32 showLastFrame)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    Gimmick42Work *work;
    Gimmick42Save *save;
    struct GameEvent *event;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 4);
    if (stateModel >= GIMMICK42_STATE_MODEL_COUNT)
        return 0;
    event = func_020122C0(gameSystem, 0, GIMMICK42_EventSetState, 0);
    if (event != 0) {
        work->stateModel = stateModel;
        work->showLastFrame = showLastFrame;
    }
    return event;
}

/* Create the event that plays the animation of one one-shot model. */
struct GameEvent *GIMMICK42_CreateOneShotEvent(struct GameSystem *gameSystem, u32 oneShotIndex)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    Gimmick42Work *work;
    Gimmick42Save *save;
    struct GameEvent *event;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 4);
    if (oneShotIndex > GIMMICK42_ONE_SHOT_COUNT)
        return 0;
    event = func_020122C0(gameSystem, 0, GIMMICK42_EventPlayOneShot, 0);
    work->oneShotIndex = oneShotIndex;
    return event;
}

/* Event: show the model in its first or last animation frame. */
int GIMMICK42_EventSetState(struct GameEvent *event, int *seq, void *eventWork)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    Gimmick42Work *work;
    FldExpObjAnime *anime;
    int frame;
    u8 modelIndex;

    fieldMap = GAMESYSTEM_GetFieldMap(func_020124E4(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 4);
    switch (*seq) {
    case 0:
        modelIndex = work->stateModel;
        frame = 0;
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, modelIndex, 0, 1);
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, modelIndex, 0);
        if (work->showLastFrame != 0) {
            FLD_EXP_OBJ_SetAnimePaused(anime, frame);
            frame = FLD_EXP_OBJ_GetAnimeLastFrame(anime);
        } else {
            FLD_EXP_OBJ_SetAnimePaused(anime, 1);
        }
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, modelIndex, 0, frame);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        (*seq)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
