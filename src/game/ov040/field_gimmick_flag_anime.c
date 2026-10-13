/*
 * file:     field_gimmick_flag_anime.c
 * unit:     yes
 * function: func_021F36C0, GIMMICK40_Exit, GIMMICK40_Update, GIMMICK40_SetFlag, GIMMICK40_GetFlag, GIMMICK40_CreateEvent, GIMMICK40_EventPlayAnime
 * address:  0x021F36C0
 * region:   ov040
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FLD_EXP_OBJ_AddUnit  0x021BE310  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeLastFrame  0x021BE748  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   gGimmick40ModelPos     0x021F38D4  data  a4
 *   gGimmick40UnitSetup     0x021F38EC  data  a4
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   FLD_EXP_OBJ_RemoveUnit 0x021BE418 thumb ov021
 *   FLD_EXP_OBJ_UpdateAnimes 0x021BE580 thumb ov021
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   func_020122C0 0x020122C0 thumb
 *   GIMMICK40_EventPlayAnime 0x021F381C thumb ov040
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 */
#include "../ov021/fld_exp_obj_types.h"
#include "field_gimmick_flag_anime_types.h"

void func_021F36C0(struct FieldMap *fieldMap);
void GIMMICK40_Exit(struct FieldMap *fieldMap);
void GIMMICK40_Update(struct FieldMap *fieldMap);
void GIMMICK40_SetFlag(struct FieldMap *fieldMap);
int GIMMICK40_GetFlag(struct FieldMap *fieldMap);
struct GameEvent *GIMMICK40_CreateEvent(struct GameSystem *gameSystem, u32 modelIndex);

extern Gimmick40ModelPos gGimmick40ModelPos;
extern G3dUtilSetup gGimmick40UnitSetup;

/* Set up the model and show its animation at the last frame when it was played before. */
void func_021F36C0(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;
    Gimmick40Save *save;
    FldExpObjAnime *anime;
    VecFx32 pos;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_AllocCommonWork(fieldMap, 1, FIELDMAP_GetHeapId(fieldMap), 4);
    FIELDMAP_GetCommonWork(fieldMap, 1);
    FLD_EXP_OBJ_AddUnit(expObj, &gGimmick40UnitSetup, 0);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 3);
    pos.x = gGimmick40ModelPos.x;
    pos.y = 0;
    pos.z = gGimmick40ModelPos.z;
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, 0)->trans = pos;
    anime = FLD_EXP_OBJ_GetAnime(expObj, 0, 0, 0);
    FLD_EXP_OBJ_SetAnimePaused(anime, 1);
    FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
    if (save->animeDone[0] != 0) {
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0, 0, 1);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, 0, 0, FLD_EXP_OBJ_GetAnimeLastFrame(anime));
    }
}

void GIMMICK40_Exit(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_FreeCommonWork(fieldMap, 1);
    FLD_EXP_OBJ_RemoveUnit(expObj, 0);
}

void GIMMICK40_Update(struct FieldMap *fieldMap)
{
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
}

/* Script command: set the gimmick flag. */
void GIMMICK40_SetFlag(struct FieldMap *fieldMap)
{
    Gimmick40Save *save;

    FIELDMAP_GetCommonWork(fieldMap, 1);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 3);
    save->flag = 1;
}

/*
 * extent: 34 code bytes followed by two zero alignment bytes.
 */
int GIMMICK40_GetFlag(struct FieldMap *fieldMap)
{
    Gimmick40Save *save;

    FIELDMAP_GetCommonWork(fieldMap, 1);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 3);
    return save->flag;
}

/* Create the event that plays the animation of one model; null for an unknown model. */
struct GameEvent *GIMMICK40_CreateEvent(struct GameSystem *gameSystem, u32 modelIndex)
{
    Gimmick40Work *work = FIELDMAP_GetCommonWork(GAMESYSTEM_GetFieldMap(gameSystem), 1);
    struct GameEvent *event;

    if (modelIndex >= 1)
        return 0;
    event = func_020122C0(gameSystem, 0, GIMMICK40_EventPlayAnime, 0);
    work->modelIndex = modelIndex;
    return event;
}

/* Gimmick event: play the animation of the model, then record that it was played. */
int GIMMICK40_EventPlayAnime(struct GameEvent *event, int *seq, void *work)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    Gimmick40Work *gimmickWork;
    Gimmick40Save *save;
    FldExpObjAnime *anime;
    u8 modelIndex;

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    gimmickWork = FIELDMAP_GetCommonWork(fieldMap, 1);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 3);
    switch (*seq) {
    case 0:
        modelIndex = gimmickWork->modelIndex;
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, modelIndex, 0, 1);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, modelIndex, 0), 0);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, modelIndex, 0, 0);
        (*seq)++;
        break;
    case 1:
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, (u8)gimmickWork->modelIndex, 0);
        if (FLD_EXP_OBJ_IsAnimeStopped(anime) && FLD_EXP_OBJ_IsAnimeStopped(anime)) {
            save->animeDone[gimmickWork->modelIndex] = 1;
            return 1;
        }
        break;
    }
    return 0;
}
