/*
 * file:     field_gimmick_gauge_effect.c
 * unit:     yes
 * function: FIELD_GIMMICK_GAUGE_EFFECT_Init, FIELD_GIMMICK_GAUGE_EFFECT_Exit, FIELD_GIMMICK_GAUGE_EFFECT_Update, FIELD_GIMMICK_GAUGE_EFFECT_StartEffectAt, FIELD_GIMMICK_GAUGE_EFFECT_IsEffectActive, FIELD_GIMMICK_GAUGE_EFFECT_PlaceModels, FIELD_GIMMICK_GAUGE_EFFECT_HideGaugeModels, FIELD_GIMMICK_GAUGE_EFFECT_ToGaugeStep, FIELD_GIMMICK_GAUGE_EFFECT_ShowGauges, FIELD_GIMMICK_GAUGE_EFFECT_GetIntrudeCommSys, FIELD_GIMMICK_GAUGE_EFFECT_SetupEffect, FIELD_GIMMICK_GAUGE_EFFECT_ShowEffect, FIELD_GIMMICK_GAUGE_EFFECT_UpdateEffect
 * address:  0x021F36C0
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FLD_EXP_OBJ_AddUnit  0x021BE310  thumb  ov021
 *   gGaugeEffectUnitSetup     0x021F3A34  data  a4
 *   FLD_EXP_OBJ_RemoveUnit  0x021BE418  thumb  ov021
 *   FIELDMAP_FreeCommonWork  0x021897A0  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 *   FIELD_GIMMICK_GAUGE_EFFECT_UpdateEffect  0x021F39F4  thumb  ov060
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   _s32_div_f  0x0209C0A4  arm
 *   GAME_DATA_GetIntrudeId  0x02012B80  thumb
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   GAME_DATA_GetEnterMode  0x02012B40  thumb
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   GAME_DATA_GetBattleRecSlot  0x020127AC  thumb
 *   INTRUDE_GetMissionScore  0x0200BDF8  thumb
 *   INTRUDE_GetMissionBonusScore  0x0200BDFC  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 */
#include "field_gimmick_gauge_effect_types.h"
#include "../ov011/intrude_comm_types.h"

struct GameData;
struct GameSystem;
struct GameComm;
struct BattleRec;

extern u16 FIELDMAP_GetHeapId(void *fieldMap);
extern void *FIELDMAP_GetExpObj(void *fieldMap);
extern struct GameSystem *FIELDMAP_GetGameSystem(void *fieldMap);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern u8 *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern struct GameComm *GAMESYSTEM_GetGameComm(const struct GameSystem *gameSystem);
extern FieldGimmickGaugeEffectWork *FIELDMAP_AllocCommonWork(void *fieldMap, int id, int heapId, int size);
extern void FLD_EXP_OBJ_AddUnit(void *expObj, void *unitDesc, int b);
extern void FLD_EXP_OBJ_RemoveUnit(void *expObj, unsigned short unit);
extern void FIELDMAP_FreeCommonWork(void *fieldMap, int id);
extern FieldGimmickGaugeEffectWork *FIELDMAP_GetCommonWork(void *fieldMap, int idx);
extern void FLD_EXP_OBJ_UpdateAnimes(void *expObj);
extern void FIELD_GIMMICK_GAUGE_EFFECT_UpdateEffect(FieldGimmickGaugeEffectWork *work, void *expObj);
extern VecFx32 *FLD_EXP_OBJ_GetModelStatus(void *expObj, int unit, u16 model);
extern void FLD_EXP_OBJ_SetModelCullDraw(void *expObj, int unit, int model, int visible);
extern void FLD_EXP_OBJ_SetModelHidden(void *expObj, int unit, u16 model, int hidden);
extern u8 GAME_DATA_GetIntrudeId(const struct GameData *gameData);
extern u8 GAME_DATA_GetOwnNetId(const struct GameData *gameData);
extern u8 GAME_DATA_GetEnterMode(const struct GameData *gameData);
extern void *GAME_DATA_GetLastBattleRecSlot(struct GameData *gameData);
extern void *GAME_DATA_GetBattleRecSlot(struct GameData *gameData, u32 slot);
extern u16 INTRUDE_GetMissionScore(struct BattleRec *record);
extern u16 INTRUDE_GetMissionBonusScore(struct BattleRec *record);
extern unsigned int GAME_COMM_GetKind(struct GameComm *gameComm);
extern IntrudeCommSys *GAME_COMM_GetWork(struct GameComm *gameComm);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *expObj, int unit, int model, int animeIdx, int enabled);
extern u8 *FLD_EXP_OBJ_GetAnime(void *expObj, int unit, int model, u16 animeIdx);
extern void FLD_EXP_OBJ_SetAnimeLoop(u8 *anime, int loop);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *anime, int paused);
extern void FLD_EXP_OBJ_SetAnimeFrame(void *expObj, int unit, int model, int animeIdx, int frame);
void FIELD_GIMMICK_GAUGE_EFFECT_Init(void *fieldMap);
void FIELD_GIMMICK_GAUGE_EFFECT_Exit(void *fieldMap);
void FIELD_GIMMICK_GAUGE_EFFECT_Update(void *fieldMap);
void FIELD_GIMMICK_GAUGE_EFFECT_StartEffectAt(void *fieldMap, VecFx32 *pos);
int FIELD_GIMMICK_GAUGE_EFFECT_IsEffectActive(void *fieldMap);
void FIELD_GIMMICK_GAUGE_EFFECT_PlaceModels(FieldGimmickGaugeEffectWork *work, void *fieldMap, struct GameData *gameData, IntrudeCommSys *commSys);
void FIELD_GIMMICK_GAUGE_EFFECT_HideGaugeModels(void *expObj);
int FIELD_GIMMICK_GAUGE_EFFECT_ToGaugeStep(int count);
u8 FIELD_GIMMICK_GAUGE_EFFECT_ShowGauges(struct GameData *gameData, void *expObj, IntrudeCommSys *unusedCommSys);
IntrudeCommSys *FIELD_GIMMICK_GAUGE_EFFECT_GetIntrudeCommSys(struct GameComm *gameComm);
void FIELD_GIMMICK_GAUGE_EFFECT_SetupEffect(void *unused, void *expObj);
void FIELD_GIMMICK_GAUGE_EFFECT_ShowEffect(FieldGimmickGaugeEffectWork *work, void *expObj, VecFx32 *pos);
extern char gGaugeEffectUnitSetup[];
extern int FLD_EXP_OBJ_IsAnimeStopped(u8 *anime);

void FIELD_GIMMICK_GAUGE_EFFECT_Init(void *fieldMap)
{
    u32 heapId;
    void *expObj;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    IntrudeCommSys *commSys;
    FieldGimmickGaugeEffectWork *work;

    heapId = FIELDMAP_GetHeapId(fieldMap);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    gameSystem = FIELDMAP_GetGameSystem(fieldMap);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    GAME_DATA_GetFieldSave(gameData);
    commSys = FIELD_GIMMICK_GAUGE_EFFECT_GetIntrudeCommSys(GAMESYSTEM_GetGameComm(gameSystem));
    work = FIELDMAP_AllocCommonWork(fieldMap, 0, heapId, 4);
    FLD_EXP_OBJ_AddUnit(expObj, gGaugeEffectUnitSetup, 0);
    FIELD_GIMMICK_GAUGE_EFFECT_PlaceModels(work, fieldMap, gameData, commSys);
    FIELD_GIMMICK_GAUGE_EFFECT_SetupEffect(work, expObj);
}

void FIELD_GIMMICK_GAUGE_EFFECT_Exit(void *fieldMap)
{
    GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    FLD_EXP_OBJ_RemoveUnit(FIELDMAP_GetExpObj(fieldMap), 0);
    FIELDMAP_FreeCommonWork(fieldMap, 0);
}

void FIELD_GIMMICK_GAUGE_EFFECT_Update(void *fieldMap)
{
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    void *expObj;
    FieldGimmickGaugeEffectWork *work;
    IntrudeCommSys *commSys;

    gameSystem = FIELDMAP_GetGameSystem(fieldMap);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    GAME_DATA_GetFieldSave(gameData);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 0);
    commSys = FIELD_GIMMICK_GAUGE_EFFECT_GetIntrudeCommSys(GAMESYSTEM_GetGameComm(gameSystem));
    if (commSys != 0) {
        if (commSys->localPeer.intrudeId != work->shownIntrudeId) {
            FIELD_GIMMICK_GAUGE_EFFECT_HideGaugeModels(expObj);
            work->shownIntrudeId = FIELD_GIMMICK_GAUGE_EFFECT_ShowGauges(gameData, expObj, commSys);
        }
    }
    FLD_EXP_OBJ_UpdateAnimes(expObj);
    if (work->effectActive != 0) {
        FIELD_GIMMICK_GAUGE_EFFECT_UpdateEffect(work, expObj);
    }
}

/* Shows the effect model at pos; the sub display polls FIELD_GIMMICK_GAUGE_EFFECT_IsEffectActive until it ends. */
void FIELD_GIMMICK_GAUGE_EFFECT_StartEffectAt(void *fieldMap, VecFx32 *pos)
{
    FieldGimmickGaugeEffectWork *work;
    void *expObj;

    work = FIELDMAP_GetCommonWork(fieldMap, 0);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELD_GIMMICK_GAUGE_EFFECT_ShowEffect(work, expObj, pos);
}

/* Returns nonzero while the effect model plays. */
int FIELD_GIMMICK_GAUGE_EFFECT_IsEffectActive(void *fieldMap)
{
    return FIELDMAP_GetCommonWork(fieldMap, 0)->effectActive;
}

/* Hides every model, then shows the gauges of the visited player. */
void FIELD_GIMMICK_GAUGE_EFFECT_PlaceModels(FieldGimmickGaugeEffectWork *work, void *fieldMap, struct GameData *gameData, IntrudeCommSys *commSys)
{
    void *expObj;
    int model;
    VecFx32 *pos;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    for (model = 0; model < FIELD_GIMMICK_GAUGE_EFFECT_MODEL_COUNT; model++) {
        pos = FLD_EXP_OBJ_GetModelStatus(expObj, 0, model);
        pos->x = 0x1F8000;
        pos->y = 0x20000;
        pos->z = 0x1B8000;
        FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, (u16)model, 1);
        FLD_EXP_OBJ_SetModelHidden(expObj, 0, model, 1);
    }
    work->shownIntrudeId = FIELD_GIMMICK_GAUGE_EFFECT_ShowGauges(gameData, expObj, commSys);
}

void FIELD_GIMMICK_GAUGE_EFFECT_HideGaugeModels(void *expObj)
{
    int model;

    for (model = 0; model < FIELD_GIMMICK_GAUGE_EFFECT_GAUGE_MODEL_COUNT; model++) {
        FLD_EXP_OBJ_SetModelHidden(expObj, 0, (u16)model, 1);
    }
}

/* One gauge step per three counts, at most the last step. */
int FIELD_GIMMICK_GAUGE_EFFECT_ToGaugeStep(int count)
{
    int step = count / 3;

    if (step > FIELD_GIMMICK_GAUGE_EFFECT_GAUGE_STEP_COUNT - 1) {
        step = FIELD_GIMMICK_GAUGE_EFFECT_GAUGE_STEP_COUNT - 1;
    }
    return step;
}

/* Shows one step of each gauge row in the column of the visited player.
 * Returns the intrude ID that is shown. */
u8 FIELD_GIMMICK_GAUGE_EFFECT_ShowGauges(struct GameData *gameData, void *expObj, IntrudeCommSys *unusedCommSys)
{
    int intrudeId;
    int column;
    int highStep;
    int lowStep;
    struct BattleRec *record;
    VecFx32 *pos;

    intrudeId = GAME_DATA_GetIntrudeId(gameData);
    column = intrudeId - GAME_DATA_GetOwnNetId(gameData);
    if (column < 0) {
        column += GAME_DATA_GetEnterMode(gameData);
    }
    if (intrudeId == GAME_DATA_GetOwnNetId(gameData)) {
        record = GAME_DATA_GetLastBattleRecSlot(gameData);
    } else {
        record = GAME_DATA_GetBattleRecSlot(gameData, intrudeId);
    }
    highStep = FIELD_GIMMICK_GAUGE_EFFECT_ToGaugeStep(INTRUDE_GetMissionScore(record));
    lowStep = FIELD_GIMMICK_GAUGE_EFFECT_ToGaugeStep(INTRUDE_GetMissionBonusScore(record));
    pos = FLD_EXP_OBJ_GetModelStatus(expObj, 0, highStep + FIELD_GIMMICK_GAUGE_EFFECT_GAUGE_STEP_COUNT);
    column = (column << 22) + 0x1F8000;
    pos->x = column;
    pos->y = 0x20000;
    pos->z = 0x1B8000;
    pos = FLD_EXP_OBJ_GetModelStatus(expObj, 0, lowStep);
    pos->x = column;
    pos->y = 0x20000;
    pos->z = 0x1B8000;
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, (u16)(highStep + FIELD_GIMMICK_GAUGE_EFFECT_GAUGE_STEP_COUNT), 0);
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, (u16)lowStep, 0);
    return intrudeId;
}

/* The intrude communication work, or 0 when the game comm is of another kind. */
IntrudeCommSys *FIELD_GIMMICK_GAUGE_EFFECT_GetIntrudeCommSys(struct GameComm *gameComm)
{
    if (GAME_COMM_GetKind(gameComm) == 2) {
        return GAME_COMM_GetWork(gameComm);
    }
    return 0;
}

/* Hides the effect model and sets its animes to run once. */
void FIELD_GIMMICK_GAUGE_EFFECT_SetupEffect(void *unused, void *expObj)
{
    int animeIdx;
    u8 *anime;

    FLD_EXP_OBJ_SetModelHidden(expObj, 0, FIELD_GIMMICK_GAUGE_EFFECT_EFFECT_MODEL, 1);
    for (animeIdx = 0; animeIdx < FIELD_GIMMICK_GAUGE_EFFECT_EFFECT_ANIME_COUNT; animeIdx++) {
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, FIELD_GIMMICK_GAUGE_EFFECT_EFFECT_MODEL, (u16)animeIdx, 1);
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, FIELD_GIMMICK_GAUGE_EFFECT_EFFECT_MODEL, (u16)animeIdx);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 0);
    }
}

/* Moves the effect model to pos, restarts its animes and shows it. */
void FIELD_GIMMICK_GAUGE_EFFECT_ShowEffect(FieldGimmickGaugeEffectWork *work, void *expObj, VecFx32 *pos)
{
    int animeIdx;

    FLD_EXP_OBJ_SetModelHidden(expObj, 0, FIELD_GIMMICK_GAUGE_EFFECT_EFFECT_MODEL, 0);
    for (animeIdx = 0; animeIdx < FIELD_GIMMICK_GAUGE_EFFECT_EFFECT_ANIME_COUNT; animeIdx++) {
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, FIELD_GIMMICK_GAUGE_EFFECT_EFFECT_MODEL, (u16)animeIdx, 0);
    }
    *FLD_EXP_OBJ_GetModelStatus(expObj, 0, FIELD_GIMMICK_GAUGE_EFFECT_EFFECT_MODEL) = *pos;
    work->effectActive = 1;
}

/* Ends the effect once its first anime has stopped: hides the model and clears the flag. */
void FIELD_GIMMICK_GAUGE_EFFECT_UpdateEffect(FieldGimmickGaugeEffectWork *work, void *expObj)
{
    if (work->effectActive != 0) {
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, FIELD_GIMMICK_GAUGE_EFFECT_EFFECT_MODEL, 0)) != 0) {
            FLD_EXP_OBJ_SetModelHidden(expObj, 0, FIELD_GIMMICK_GAUGE_EFFECT_EFFECT_MODEL, 1);
            work->effectActive = 0;
        }
    }
}
