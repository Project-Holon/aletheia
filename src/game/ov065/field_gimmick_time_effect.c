/*
 * file:     field_gimmick_time_effect.c
 * unit:     yes
 * function: GIMMICK65_Init, GIMMICK65_Exit, GIMMICK65_Update, GIMMICK65_StartEffect, GIMMICK65_CallWaitEvent, GIMMICK65_WaitEffectEventMain
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
 *   sGimmick65UnitDescNight     0x021F3918  data  a4
 *   sGimmick65UnitDescDay     0x021F38F8  data  a4
 *   sGimmick65EffectPosition     0x021F3970  data  a4
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
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
 *   func_020122C0 0x020122C0 thumb
 *   GIMMICK65_WaitEffectEventMain 0x021F38D0 thumb ov065
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 */
#include "field_gimmick_time_effect_types.h"

struct GameData;
struct FieldSave;

extern void *FIELDMAP_GetGameSystem(void *fieldMap);
extern void *GAMESYSTEM_GetGameData(void *gameSystem);
extern struct FieldSave *GAME_DATA_GetFieldSave(void *gameData);
extern Gimmick65Save *GIMMICK_WORK_GetSaveArea(struct FieldSave *fieldSave, u32 blockId);
extern void *FIELDMAP_GetExpObj(void *fieldMap);
extern u16 FIELDMAP_GetHeapId(u8 *fieldMap);
extern void *FIELDMAP_AllocCommonWork(unsigned char *fieldMap, int id, int a, int size);
extern Gimmick65Work *FIELDMAP_GetCommonWork(void *fieldMap, int id);
extern u8 GAME_DATA_GetSeason(void *gameData);
extern u32 TIMEZONE_GetNowTimeZone(u32 season);
extern void FLD_EXP_OBJ_AddUnitFromArchive(void *expObj, void *unitDesc, int b);
extern VecFx32 *FLD_EXP_OBJ_GetModelStatus(void *expObj, int unit, u16 model);
extern void FLD_EXP_OBJ_SetModelCullDraw(void *expObj, int unit, int model, int visible);
extern void FLD_EXP_OBJ_SetModelHidden(void *expObj, int unit, int model, int hidden);
extern void *FLD_EXP_OBJ_GetAnime(void *expObj, int unit, unsigned int model, int animeIdx);
extern void FLD_EXP_OBJ_SetAnimeLoop(unsigned char *anime, int loop);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *anime, int paused);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *expObj, int unit, u16 model, u16 animeIdx, int enabled);
extern void FLD_EXP_OBJ_RemoveUnit(unsigned char *expObj, unsigned short unit);
extern void FIELDMAP_FreeCommonWork(unsigned char *fieldMap, int id);
extern void FLD_EXP_OBJ_UpdateAnimes(int expObj);
extern int FLD_EXP_OBJ_GetAnimeFrame(int expObj, int unit, int model, int animeIdx);
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);
extern int FLD_EXP_OBJ_IsAnimeStopped(void *anime);
extern void *func_020122C0(void *owner, void *a, void *eventFunc, u32 size);
extern int GIMMICK65_WaitEffectEventMain(void *event);
void GIMMICK65_Init(void *fieldMap);
void GIMMICK65_Exit(unsigned char *fieldMap);
void GIMMICK65_Update(int fieldMap);
void GIMMICK65_StartEffect(int fieldMap);
void *GIMMICK65_CallWaitEvent(void *gameSystem);
extern char sGimmick65UnitDescNight[];
extern char sGimmick65UnitDescDay[];
extern VecFx32 sGimmick65EffectPosition;
extern void *GAME_EVENT_GetGameSystem(void *event);
extern void *GAMESYSTEM_GetFieldMap(void *gameSystem);

void GIMMICK65_Init(void *fieldMap)
{
    void *gameData;
    Gimmick65Save *save;
    Gimmick65Work *work;
    int i;
    void *anime;
    void *expObj;

    gameData = GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap));
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(gameData), GIMMICK65_SAVE_BLOCK);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_AllocCommonWork(fieldMap, 1, FIELDMAP_GetHeapId(fieldMap), sizeof(Gimmick65Work));
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    work->isPlaying = 0;
    if (TIMEZONE_GetNowTimeZone(GAME_DATA_GetSeason(gameData)) - GIMMICK65_FIRST_NIGHT_TIME_ZONE <= 1) {
        FLD_EXP_OBJ_AddUnitFromArchive(expObj, sGimmick65UnitDescNight, 0);
        work->isNight = 1;
    } else {
        FLD_EXP_OBJ_AddUnitFromArchive(expObj, sGimmick65UnitDescDay, 0);
        work->isNight = 0;
    }
    *FLD_EXP_OBJ_GetModelStatus(expObj, 0, 0) = sGimmick65EffectPosition;
    FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, 0, 1);
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, 0, save->isEffectPending == 0);
    for (i = 0; i < GIMMICK65_ANIME_COUNT; i++) {
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, (u16)0, (u16)i);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0, i, save->isEffectPending != 0);
    }
}


void GIMMICK65_Exit(unsigned char *fieldMap)
{
    FLD_EXP_OBJ_RemoveUnit(FIELDMAP_GetExpObj(fieldMap), 0);
    FIELDMAP_FreeCommonWork(fieldMap, 1);
}


void GIMMICK65_Update(int fieldMap)
{
    int expObj;
    Gimmick65Work *work;

    expObj = (int)FIELDMAP_GetExpObj((void *)fieldMap);
    work = FIELDMAP_GetCommonWork((void *)fieldMap, 1);
    if (work->isPlaying != 0) {
        FLD_EXP_OBJ_UpdateAnimes(expObj);
        if (work->isNight == 0) {
            if (FLD_EXP_OBJ_GetAnimeFrame(expObj, 0, 0, 0) == GIMMICK65_PEAK_FRAME)
                GFL_USE_PlaySeDefaultVolume(GIMMICK65_SE_DAY_PEAK);
        }
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime((void *)expObj, 0, 0, 0)) != 0) {
            FLD_EXP_OBJ_SetModelHidden((void *)expObj, 0, 0, 1);
            work->isPlaying = 0;
            GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)fieldMap))), GIMMICK65_SAVE_BLOCK)->isEffectPending = 0;
        }
    }
}


void GIMMICK65_StartEffect(int fieldMap)
{
    int i;
    int expObj;
    Gimmick65Work *work;

    expObj = (int)FIELDMAP_GetExpObj((void *)fieldMap);
    work = FIELDMAP_GetCommonWork((void *)fieldMap, 1);
    work->isPlaying = 1;
    FLD_EXP_OBJ_SetModelHidden((void *)expObj, 0, 0, 0);
    for (i = 0; i < GIMMICK65_ANIME_COUNT; i++)
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((void *)expObj, 0, 0, (unsigned short)i), 0);
    if (work->isNight != 0)
        GFL_USE_PlaySeDefaultVolume(GIMMICK65_SE_START_NIGHT);
    else
        GFL_USE_PlaySeDefaultVolume(GIMMICK65_SE_START_DAY);
}


void *GIMMICK65_CallWaitEvent(void *gameSystem)
{
    return func_020122C0(gameSystem, 0, (void *)GIMMICK65_WaitEffectEventMain, 0);
}

int GIMMICK65_WaitEffectEventMain(void *event)
{
    void *fieldMap;
    int isDone;
    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    isDone = 1;
    if (FIELDMAP_GetCommonWork(fieldMap, 1)->isPlaying != 0)
        isDone = 0;
    return isDone;
}
