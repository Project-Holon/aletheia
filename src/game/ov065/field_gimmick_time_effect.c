/*
 * file:     field_gimmick_time_effect.c
 * unit:     yes
 * function: FIELD_GIMMICK_TIME_EFFECT_Init, FIELD_GIMMICK_TIME_EFFECT_Exit, FIELD_GIMMICK_TIME_EFFECT_Update, FIELD_GIMMICK_TIME_EFFECT_StartEffect, FIELD_GIMMICK_TIME_EFFECT_CallWaitEvent, FIELD_GIMMICK_TIME_EFFECT_WaitEffectEventMain
 * address:  0x021F36C0
 * region:   ov065
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sTimeEffectUnitDescNight     0x021F3918  data  a4
 *   sTimeEffectUnitDescDay     0x021F38F8  data  a4
 *   sTimeEffectEffectPosition     0x021F3970  data  a4
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetWork  0x0200B3A4  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   TIMEZONE_GetNowTimeZone  0x020113D8  thumb
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_RemoveUnit 0x021BE418 thumb ov021
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeFrame  0x021BE6E8  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   FIELD_GIMMICK_TIME_EFFECT_WaitEffectEventMain 0x021F38D0 thumb ov065
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 */
#include "../arm9/game_data.h"
#include "field_gimmick_time_effect_types.h"

struct GameData;
struct FieldSave;

#include "../ov021/fieldmap.h"
struct GameSystem;
#include "../arm9/g3d_system_types.h"
#include "../types.h"
struct GimmickWork;
#include "../arm9/gamesystem.h"
#include "../arm9/gimmick.h"
struct FieldMap;
struct FldExpObjCnt;
#include "../arm9/timezone.h"
struct G3dUtilSetup;
#include "../ov021/fld_exp_obj.h"
struct FldExpObjAnime;
#include "../arm9/gfl_use.h"
#include "../arm9/game_event.h"
extern int FIELD_GIMMICK_TIME_EFFECT_WaitEffectEventMain(void *event);
void FIELD_GIMMICK_TIME_EFFECT_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_TIME_EFFECT_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_TIME_EFFECT_Update(struct FieldMap *fieldMap);
void FIELD_GIMMICK_TIME_EFFECT_StartEffect(struct FieldMap *fieldMap);
void *FIELD_GIMMICK_TIME_EFFECT_CallWaitEvent(void *gameSystem);
extern char sTimeEffectUnitDescNight[];
extern char sTimeEffectUnitDescDay[];
extern VecFx32 sTimeEffectEffectPosition;

void FIELD_GIMMICK_TIME_EFFECT_Init(struct FieldMap *fieldMap)
{
    void *gameData;
    FieldGimmickTimeEffectSave *save;
    FieldGimmickTimeEffectWork *work;
    int i;
    void *anime;
    void *expObj;

    gameData = GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap));
    save = (struct FieldGimmickTimeEffectSave *)GIMMICK_WORK_GetWork((struct GimmickWork *)GAME_DATA_GetFieldSave(gameData), FIELD_GIMMICK_TIME_EFFECT_SAVE_BLOCK);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_AllocCommonWork(fieldMap, 1, FIELDMAP_GetHeapId(fieldMap), sizeof(FieldGimmickTimeEffectWork));
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    work->isPlaying = 0;
    if (TIMEZONE_GetNowTimeZone(GAME_DATA_GetSeason(gameData)) - FIELD_GIMMICK_TIME_EFFECT_FIRST_NIGHT_TIME_ZONE <= 1) {
        FLD_EXP_OBJ_AddUnitFromArchive(expObj, (struct G3dUtilSetup *)sTimeEffectUnitDescNight, 0);
        work->isNight = 1;
    } else {
        FLD_EXP_OBJ_AddUnitFromArchive(expObj, (struct G3dUtilSetup *)sTimeEffectUnitDescDay, 0);
        work->isNight = 0;
    }
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, 0)->trans = sTimeEffectEffectPosition;
    FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, 0, 1);
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, 0, save->isEffectPending == 0);
    for (i = 0; i < FIELD_GIMMICK_TIME_EFFECT_ANIME_COUNT; i++) {
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, (u16)0, (u16)i);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0, i, save->isEffectPending != 0);
    }
}


void FIELD_GIMMICK_TIME_EFFECT_Exit(struct FieldMap *fieldMap)
{
    FLD_EXP_OBJ_RemoveUnit(FIELDMAP_GetExpObj(fieldMap), 0);
    FIELDMAP_FreeCommonWork(fieldMap, 1);
}


void FIELD_GIMMICK_TIME_EFFECT_Update(struct FieldMap *fieldMap)
{
    struct FldExpObjCnt *expObj;
    FieldGimmickTimeEffectWork *work;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    if (work->isPlaying != 0) {
        FLD_EXP_OBJ_UpdateAnimes(expObj);
        if (work->isNight == 0) {
            if (FLD_EXP_OBJ_GetAnimeFrame(expObj, 0, 0, 0) == FIELD_GIMMICK_TIME_EFFECT_PEAK_FRAME)
                GFL_USE_PlaySeDefaultVolume(FIELD_GIMMICK_TIME_EFFECT_SE_DAY_PEAK);
        }
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, 0, 0)) != 0) {
            FLD_EXP_OBJ_SetModelHidden(expObj, 0, 0, 1);
            work->isPlaying = 0;
            ((struct FieldGimmickTimeEffectSave *)GIMMICK_WORK_GetWork((struct GimmickWork *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_TIME_EFFECT_SAVE_BLOCK))->isEffectPending = 0;
        }
    }
}


void FIELD_GIMMICK_TIME_EFFECT_StartEffect(struct FieldMap *fieldMap)
{
    int i;
    struct FldExpObjCnt *expObj;
    FieldGimmickTimeEffectWork *work;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    work->isPlaying = 1;
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, 0, 0);
    for (i = 0; i < FIELD_GIMMICK_TIME_EFFECT_ANIME_COUNT; i++)
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, 0, (unsigned short)i), 0);
    if (work->isNight != 0)
        GFL_USE_PlaySeDefaultVolume(FIELD_GIMMICK_TIME_EFFECT_SE_START_NIGHT);
    else
        GFL_USE_PlaySeDefaultVolume(FIELD_GIMMICK_TIME_EFFECT_SE_START_DAY);
}


void *FIELD_GIMMICK_TIME_EFFECT_CallWaitEvent(void *gameSystem)
{
    return GAME_EVENT_Create(gameSystem, 0, (void *)FIELD_GIMMICK_TIME_EFFECT_WaitEffectEventMain, 0);
}

int FIELD_GIMMICK_TIME_EFFECT_WaitEffectEventMain(void *event)
{
    void *fieldMap;
    int isDone;
    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    isDone = 1;
    if (((FieldGimmickTimeEffectWork *)FIELDMAP_GetCommonWork(fieldMap, 1))->isPlaying != 0)
        isDone = 0;
    return isDone;
}
