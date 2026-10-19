/*
 * file:     field_gimmick_button_states.c
 * unit:     yes
 * function: FIELD_GIMMICK_BUTTON_STATES_Init, FIELD_GIMMICK_BUTTON_STATES_Exit, FIELD_GIMMICK_BUTTON_STATES_Update, FIELD_GIMMICK_BUTTON_STATES_CreateStateEvent, FIELD_GIMMICK_BUTTON_STATES_CreateOneShotEvent, FIELD_GIMMICK_BUTTON_STATES_EventSetState, FIELD_GIMMICK_BUTTON_STATES_EventPlayOneShot
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
 *   gButtonStatesUnitSetup     0x021F3A58  data  a4
 *   gButtonStatesStatePos     0x021F3AD4  data  a4
 *   gButtonStatesOneShotPos     0x021F3A68  data  a4
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetWork  0x0200B3A4  thumb
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
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   FIELD_GIMMICK_BUTTON_STATES_EventPlayOneShot  0x021F3980  thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 */
#include "../ov021/fld_exp_obj_types.h"
#include "../ov037/gimmick_save_types.h"
#include "field_gimmick_button_states_types.h"

void FIELD_GIMMICK_BUTTON_STATES_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_BUTTON_STATES_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_BUTTON_STATES_Update(struct FieldMap *fieldMap);
struct GameEvent *FIELD_GIMMICK_BUTTON_STATES_CreateStateEvent(struct GameSystem *gameSystem, u32 stateModel, u32 showLastFrame);
struct GameEvent *FIELD_GIMMICK_BUTTON_STATES_CreateOneShotEvent(struct GameSystem *gameSystem, u32 oneShotIndex);
int FIELD_GIMMICK_BUTTON_STATES_EventSetState(struct GameEvent *event, int *seq, void *work);

/* Model positions; the tables are read in full, the gimmick uses a prefix of them. */
typedef struct FieldGimmickButtonStatesPosTable {
    VecFx32 pos[FIELD_GIMMICK_BUTTON_STATES_STATE_MODEL_COUNT];
} FieldGimmickButtonStatesPosTable;

extern G3dUtilSetup gButtonStatesUnitSetup;
extern FieldGimmickButtonStatesPosTable gButtonStatesStatePos;
extern FieldGimmickButtonStatesPosTable gButtonStatesOneShotPos;

/* Load the models, place them, and show the one-shot models at their last frame when they were played. */
void FIELD_GIMMICK_BUTTON_STATES_Init(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;
    FieldGimmickButtonStatesSave *save;
    FldExpObjAnime *anime;
    u32 i;
    u8 modelIndex;
    FieldGimmickButtonStatesPosTable statePos;
    FieldGimmickButtonStatesPosTable oneShotPos;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    save = GIMMICK_WORK_GetWork(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 4);
    FIELDMAP_AllocCommonWork(fieldMap, 1, FIELDMAP_GetHeapId(fieldMap), 4);
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, &gButtonStatesUnitSetup, 0);
    statePos = gButtonStatesStatePos;
    for (i = 0; i < FIELD_GIMMICK_BUTTON_STATES_STATE_MODEL_COUNT; i = (u8)(i + 1)) {
        FLD_EXP_OBJ_GetModelStatus(expObj, 0, (u8)i)->trans = statePos.pos[i];
        FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, (u8)i, 1);
    }
    oneShotPos = gButtonStatesOneShotPos;
    for (i = 0; i < FIELD_GIMMICK_BUTTON_STATES_ONE_SHOT_COUNT; i = (u8)(i + 1)) {
        FLD_EXP_OBJ_GetModelStatus(expObj, 0, (u8)(i + FIELD_GIMMICK_BUTTON_STATES_ONE_SHOT_FIRST_MODEL))->trans = oneShotPos.pos[i];
        FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, (u8)(i + FIELD_GIMMICK_BUTTON_STATES_ONE_SHOT_FIRST_MODEL), 1);
    }
    for (i = 0; i < FIELD_GIMMICK_BUTTON_STATES_ONE_SHOT_COUNT; i = (u8)(i + 1)) {
        if (save->oneShotPlayed[i]) {
            modelIndex = i + FIELD_GIMMICK_BUTTON_STATES_ONE_SHOT_FIRST_MODEL;
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, modelIndex, 0, 1);
            anime = FLD_EXP_OBJ_GetAnime(expObj, 0, modelIndex, 0);
            FLD_EXP_OBJ_SetAnimePaused(anime, 0);
            FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
            FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, modelIndex, 0, FLD_EXP_OBJ_GetAnimeLastFrame(anime));
        }
    }
}

void FIELD_GIMMICK_BUTTON_STATES_Exit(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj = FIELDMAP_GetExpObj(fieldMap);

    FIELDMAP_FreeCommonWork(fieldMap, 1);
    FLD_EXP_OBJ_RemoveUnit(expObj, 0);
}

void FIELD_GIMMICK_BUTTON_STATES_Update(struct FieldMap *fieldMap)
{
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
}

/* Create the event that sets the state of one of the first nine models; null for an unknown model. */
struct GameEvent *FIELD_GIMMICK_BUTTON_STATES_CreateStateEvent(struct GameSystem *gameSystem, u32 stateModel, u32 showLastFrame)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    FieldGimmickButtonStatesWork *work;
    FieldGimmickButtonStatesSave *save;
    struct GameEvent *event;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    save = GIMMICK_WORK_GetWork(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 4);
    if (stateModel >= FIELD_GIMMICK_BUTTON_STATES_STATE_MODEL_COUNT)
        return 0;
    event = GAME_EVENT_Create(gameSystem, 0, FIELD_GIMMICK_BUTTON_STATES_EventSetState, 0);
    if (event != 0) {
        work->stateModel = stateModel;
        work->showLastFrame = showLastFrame;
    }
    return event;
}

/* Create the event that plays the animation of one one-shot model. */
struct GameEvent *FIELD_GIMMICK_BUTTON_STATES_CreateOneShotEvent(struct GameSystem *gameSystem, u32 oneShotIndex)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    FieldGimmickButtonStatesWork *work;
    FieldGimmickButtonStatesSave *save;
    struct GameEvent *event;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    save = GIMMICK_WORK_GetWork(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 4);
    if (oneShotIndex > FIELD_GIMMICK_BUTTON_STATES_ONE_SHOT_COUNT)
        return 0;
    event = GAME_EVENT_Create(gameSystem, 0, FIELD_GIMMICK_BUTTON_STATES_EventPlayOneShot, 0);
    work->oneShotIndex = oneShotIndex;
    return event;
}

/* Event: show the model in its first or last animation frame. */
int FIELD_GIMMICK_BUTTON_STATES_EventSetState(struct GameEvent *event, int *seq, void *eventWork)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    FieldGimmickButtonStatesWork *work;
    FldExpObjAnime *anime;
    int frame;
    u8 modelIndex;

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    GIMMICK_WORK_GetWork(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 4);
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

/* Event: play the animation of a one-shot model once, then record it in the save area. */
int FIELD_GIMMICK_BUTTON_STATES_EventPlayOneShot(struct GameEvent *event, int *seq, void *eventWork)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    FieldGimmickButtonStatesWork *work;
    FieldGimmickButtonStatesSave *save;
    FldExpObjAnime *anime;
    u8 modelIndex;

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    save = GIMMICK_WORK_GetWork(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 4);
    switch (*seq) {
    case 0:
        modelIndex = work->oneShotIndex + FIELD_GIMMICK_BUTTON_STATES_ONE_SHOT_FIRST_MODEL;
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, modelIndex, 0, 1);
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, modelIndex, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 0);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, modelIndex, 0, 0);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        (*seq)++;
        break;
    case 1:
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, (u8)(work->oneShotIndex + FIELD_GIMMICK_BUTTON_STATES_ONE_SHOT_FIRST_MODEL), 0))) {
            save->oneShotPlayed[work->oneShotIndex] = 1;
            return 1;
        }
        break;
    }
    return 0;
}
