/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: GIMMICK45_Init, GIMMICK46_InitModel, GIMMICK46_InitUnitPose, GIMMICK46_Exit, GIMMICK46_Update, GIMMICK46_StartButtonEvent, GIMMICK46_StartLeverEvent, GIMMICK46_StartRotateEvent, GIMMICK46_StartHopEvent, GIMMICK46_CalcUnitPose, GIMMICK46_GetRotateAnim, GIMMICK46_ButtonEventProc, GIMMICK46_LeverEventProc, GIMMICK46_RotateEventProc, GIMMICK46_PlayAnimEventProc, GIMMICK46_HopEventProc, GIMMICK46_SetExteriorHidden, GIMMICK46_FindMmdlByObjId, GIMMICK46_SetMmdlVanish, GIMMICK46_ApplyPoseLines, GIMMICK46_IsPosInside
 * address:  0x021F36C0
 * region:   ov046
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
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   GIMMICK46_IsPosInside  0x021F40D8  thumb  ov046
 *   sGimmick46ExpUnitDesc     0x021F4120  data  a4
 *   sGimmick46UnitAngles     0x021F4108  data  a2
 *   sGimmick46BodyPos     0x021F4194  data  a4
 *   sGimmick46LeverPos     0x021F4170  data  a4
 *   sGimmick46ButtonPos     0x021F4204  data  a4
 *   sGimmick46ExtraModelPos     0x021F41B8  data  a4
 *   d_020A1B38     0x020A1B38  data  a2
 *   func_0207AF1C  0x0207AF1C  thumb
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeLastFrame  0x021BE748  thumb  ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   FLD_EXP_OBJ_RemoveUnit 0x021BE418 thumb ov021
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   sGimmick46RotateAnimTable  0x021F41C4  data  a4
 *   func_020124E4  0x020124E4  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   sGimmick46HopHeights  0x021F4130  data  a4
 *   func_021BE4B4  0x021BE4B4  thumb  ov203
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   FLDMMDL_SetStatusBitVanish 0x0216DAC8 thumb ov010
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELD_NOGRID_MAPPER_SetLineEnable  0x021BB3DC  thumb  ov021
 *   sGimmick46PoseLines  0x021F4430  data  ov046  a4
 */
#include "unit_021F36C0_types.h"

struct FieldMap;
struct GameSystem;
struct GameData;
struct FieldSave;
struct FldExpObj;
struct FldExpAnime;
struct FldExpUnitDesc;
struct FieldPlayer;
struct FldMmdlSys;
struct Mmdl;
struct NogridMapper;
struct GameEvent;

typedef int (*GameEventFunc)(struct GameEvent *event, int *state);

extern struct FldExpObj *FIELDMAP_GetExpObj(struct FieldMap *fieldMap);
extern struct GameSystem *FIELDMAP_GetGameSystem(struct FieldMap *fieldMap);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct FieldSave *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern Gimmick46Save *GIMMICK_WORK_GetSaveArea(struct FieldSave *fieldSave, u32 blockId);
extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern Gimmick46Work *FIELDMAP_AllocCommonWork(struct FieldMap *fieldMap, int workId, int heapId, int size);
extern void FLD_EXP_OBJ_AddUnitFromArchive(struct FldExpObj *expObj, struct FldExpUnitDesc *desc, int unitIndex);
extern void FLD_EXP_OBJ_SetAnimeEnabled(struct FldExpObj *expObj, int unitIndex, u16 modelIndex, u16 animIndex, int enabled);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);
extern void FIELD_PLAYER_GetPos(struct FieldPlayer *player, Vec3Fx *outPos);
extern FldExpModel *FLD_EXP_OBJ_GetModelStatus(struct FldExpObj *expObj, unsigned int unitIndex, int modelIndex);
extern void FLD_EXP_OBJ_SetModelCullDraw(struct FldExpObj *expObj, int unitIndex, u16 modelIndex, int cullDraw);
extern struct FldExpAnime *FLD_EXP_OBJ_GetAnime(struct FldExpObj *expObj, int unitIndex, u16 modelIndex, u16 animIndex);
extern void FLD_EXP_OBJ_SetAnimeLoop(struct FldExpAnime *anime, int loop);
extern void FLD_EXP_OBJ_SetAnimePaused(struct FldExpAnime *anime, int paused);
extern void func_0207AF1C(int *matrix, int sinValue, int cosValue);
extern void FLD_EXP_OBJ_SetAnimeFrame(struct FldExpObj *expObj, int unitIndex, u16 modelIndex, u16 animIndex, int frame);
extern int FLD_EXP_OBJ_GetAnimeLastFrame(struct FldExpAnime *anime);
extern Gimmick46Work *FIELDMAP_GetCommonWork(struct FieldMap *fieldMap, int workId);
extern void FIELDMAP_FreeCommonWork(struct FieldMap *fieldMap, int workId);
extern void FLD_EXP_OBJ_RemoveUnit(struct FldExpObj *expObj, u16 unitIndex);
extern void FLD_EXP_OBJ_UpdateAnimes(struct FldExpObj *expObj);
extern struct FieldMap *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc proc, u32 size);
extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);
extern int FLD_EXP_OBJ_IsAnimeStopped(struct FldExpAnime *anime);
extern void func_020061E4(u32 se);
extern void GFL_USE_StopAllSe(void);
extern void FIELD_PLAYER_SetPos(struct FieldPlayer *player, Vec3Fx *pos);
extern void func_021BE4B4(struct FldExpObj *expObj, int unitIndex, int modelIndex, u32 hidden);
extern struct FldMmdlSys *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);
extern int FLDMMDL_SysSearchUseMmdl(struct FldMmdlSys *mmdlSys, struct Mmdl **outMmdl, u32 *iterator);
extern u16 FLDMMDL_GetObjId(struct Mmdl *mmdl);
extern void FLDMMDL_SetStatusBitVanish(struct Mmdl *mmdl, u32 vanish);
extern struct NogridMapper *FIELDMAP_GetNogridMapper(struct FieldMap *fieldMap);
extern void FIELD_NOGRID_MAPPER_SetLineEnable(struct NogridMapper *mapper, int lineIndex, int enabled);

void GIMMICK45_Init(struct FieldMap *fieldMap);
void GIMMICK46_InitModel(struct FldExpObj *expObj, int modelIndex, Vec3Fx *pos, u16 *angle, int animCount, int cullDraw);
void GIMMICK46_InitUnitPose(Gimmick46Save *save, struct FldExpObj *expObj, int unitIndex);
void GIMMICK46_Exit(struct FieldMap *fieldMap);
void GIMMICK46_Update(struct FieldMap *fieldMap);
void GIMMICK46_StartButtonEvent(struct GameSystem *gameSystem, int unitIndex, int side);
void GIMMICK46_StartLeverEvent(struct GameSystem *gameSystem, int unitIndex, int side);
void GIMMICK46_StartRotateEvent(struct GameSystem *gameSystem, int unitIndex);
struct GameEvent *GIMMICK46_StartHopEvent(struct GameSystem *gameSystem, int direction);
int GIMMICK46_CalcUnitPose(Gimmick46Unit *unit);
int GIMMICK46_GetRotateAnim(Gimmick46Unit *unit, int newPose);
int GIMMICK46_ButtonEventProc(struct GameEvent *event, int *state);
int GIMMICK46_LeverEventProc(struct GameEvent *event, int *state);
int GIMMICK46_RotateEventProc(struct GameEvent *event, int *state);
int GIMMICK46_PlayAnimEventProc(struct GameEvent *event, int *state);
int GIMMICK46_HopEventProc(struct GameEvent *event, int *state);
void GIMMICK46_SetExteriorHidden(struct FldExpObj *expObj, struct FieldMap *fieldMap, u32 hidden);
struct Mmdl *GIMMICK46_FindMmdlByObjId(struct FieldMap *fieldMap, int objId);
void GIMMICK46_SetMmdlVanish(struct FieldMap *fieldMap, int objId, u32 vanish);
void GIMMICK46_ApplyPoseLines(struct FieldMap *fieldMap, int unitIndex, int pose);
int GIMMICK46_IsPosInside(Vec3Fx *pos);

extern struct FldExpUnitDesc sGimmick46ExpUnitDesc;
extern u16 sGimmick46UnitAngles[];         /* initial angle per unit */
extern Vec3Fx sGimmick46BodyPos[];      /* body position per unit */
extern Vec3Fx sGimmick46LeverPos[];      /* lever position per unit (both levers) */
extern Vec3Fx sGimmick46ButtonPos[];      /* button position, two per unit */
extern Vec3Fx sGimmick46ExtraModelPos;        /* position of the extra model */
extern s16 d_020A1B38[];         /* sine and cosine pairs */
extern int sGimmick46RotateAnimTable[][4];      /* body animation for (old pose, new pose) plus 5 */
extern int sGimmick46HopHeights[];         /* height offsets of the hop, in tiles */
extern int sGimmick46PoseLines[][4][6];   /* walk lines (line, enabled) per (unit, pose) */


void GIMMICK45_Init(struct FieldMap *fieldMap)
{
    Vec3Fx extraPos;
    Vec3Fx playerPos;
    u16 angle;
    int unitIdx;
    struct FldExpObj *expObj;
    Gimmick46Save *save;
    Gimmick46Work *work;
    int firstModel;
    int inside;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    work = FIELDMAP_AllocCommonWork(fieldMap, 1, FIELDMAP_GetHeapId(fieldMap), sizeof(Gimmick46Work));
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, &sGimmick46ExpUnitDesc, 0);
    for (unitIdx = 0; unitIdx < GIMMICK46_UNIT_COUNT; unitIdx++) {
        /* Cleared and then set: the first store is in the original code. */
        angle = 0;
        angle = sGimmick46UnitAngles[unitIdx];
        firstModel = unitIdx * GIMMICK46_MODELS_PER_UNIT;
        GIMMICK46_InitModel(expObj, firstModel, &sGimmick46BodyPos[unitIdx], &angle, 8, 0);
        GIMMICK46_InitModel(expObj, firstModel + 1, &sGimmick46LeverPos[unitIdx], &angle, 2, 0);
        GIMMICK46_InitModel(expObj, firstModel + 2, &sGimmick46LeverPos[unitIdx], &angle, 2, 0);
        GIMMICK46_InitModel(expObj, firstModel + 3, &sGimmick46ButtonPos[unitIdx * 2], 0, 1, 1);
        GIMMICK46_InitModel(expObj, firstModel + 4, &sGimmick46ButtonPos[unitIdx * 2 + 1], 0, 1, 1);
        GIMMICK46_InitUnitPose(save, expObj, unitIdx);
    }
    /* The position is copied to a local first; passing the table row
     * directly changes the stack frame. */
    extraPos = sGimmick46ExtraModelPos;
    GIMMICK46_InitModel(expObj, GIMMICK46_MODEL_EXTRA, &extraPos, 0, 0, 0);
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, GIMMICK46_MODEL_EXTRA, 0, 1);
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos);
    inside = GIMMICK46_IsPosInside(&playerPos) != 0 ? 1 : 0;
    GIMMICK46_SetExteriorHidden(expObj, fieldMap, inside);
    work->playerInside = inside;
    for (unitIdx = 0; unitIdx < GIMMICK46_UNIT_COUNT; unitIdx++)
        GIMMICK46_ApplyPoseLines(fieldMap, unitIdx, save->units[unitIdx].pose);
}



void GIMMICK46_InitModel(struct FldExpObj *expObj, int modelIndex, Vec3Fx *pos, u16 *angle, int animCount, int cullDraw)
{
    FldExpModel *model;
    struct FldExpAnime *anime;
    int animIdx;
    int tableIdx;

    model = FLD_EXP_OBJ_GetModelStatus(expObj, (int)0, (u16)modelIndex);
    model->pos = *pos;
    if (angle) {
        tableIdx = (*angle >> 4) * 2;
        func_0207AF1C(model->rotation, d_020A1B38[tableIdx], d_020A1B38[tableIdx + 1]);
    }
    FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, modelIndex, cullDraw);
    for (animIdx = 0; animIdx < animCount; animIdx++) {
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, modelIndex, animIdx);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, modelIndex, animIdx, 0);
    }
}









void GIMMICK46_InitUnitPose(Gimmick46Save *save, struct FldExpObj *expObj, int unitIdx)
{
    Gimmick46Unit *unit;
    int bodyModel;
    int bodyAnim;
    struct FldExpAnime *bodyAnime;
    int leverAnim0;
    int leverModel0;
    struct FldExpAnime *leverAnime0;
    int leverAnim1;
    int leverModel1;
    struct FldExpAnime *leverAnime1;

    unit = &save->units[unitIdx];
    switch (unit->pose) {
    case 0:
        bodyAnim = 1;
        break;
    case 1:
        bodyAnim = 5;
        break;
    case 3:
        bodyAnim = 0;
        break;
    case 2:
        bodyAnim = 2;
        break;
    default:
        bodyAnim = 1;
        break;
    }
    bodyModel = unitIdx * GIMMICK46_MODELS_PER_UNIT;
    bodyAnime = FLD_EXP_OBJ_GetAnime(expObj, 0, bodyModel, bodyAnim);
    FLD_EXP_OBJ_SetAnimePaused(bodyAnime, 0);
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, bodyModel, bodyAnim, 1);
    FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, bodyModel, bodyAnim, FLD_EXP_OBJ_GetAnimeLastFrame(bodyAnime));
    leverAnim0 = 1;
    leverModel0 = bodyModel + 1;
    if (unit->leverOn[0] == 0)
        leverAnim0 = 0;
    leverAnime0 = FLD_EXP_OBJ_GetAnime(expObj, 0, leverModel0, leverAnim0);
    FLD_EXP_OBJ_SetAnimePaused(leverAnime0, 0);
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, leverModel0, leverAnim0, 1);
    FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, leverModel0, leverAnim0, FLD_EXP_OBJ_GetAnimeLastFrame(leverAnime0));
    leverAnim1 = 1;
    leverModel1 = bodyModel + 2;
    if (unit->leverOn[1] == 0)
        leverAnim1 = 0;
    leverAnime1 = FLD_EXP_OBJ_GetAnime(expObj, 0, leverModel1, leverAnim1);
    FLD_EXP_OBJ_SetAnimePaused(leverAnime1, 0);
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, leverModel1, leverAnim1, 1);
    FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, leverModel1, leverAnim1, FLD_EXP_OBJ_GetAnimeLastFrame(leverAnime1));
}








void GIMMICK46_Exit(struct FieldMap *fieldMap)
{
    struct FldExpObj *expObj;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_GetCommonWork(fieldMap, 1);
    FIELDMAP_FreeCommonWork(fieldMap, 1);
    FLD_EXP_OBJ_RemoveUnit(expObj, 0);
}









void GIMMICK46_Update(struct FieldMap *fieldMap)
{
    Vec3Fx playerPos;
    struct FldExpObj *expObj = FIELDMAP_GetExpObj(fieldMap);
    Gimmick46Work *work = FIELDMAP_GetCommonWork(fieldMap, 1);
    int inside = 1;

    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    FLD_EXP_OBJ_UpdateAnimes(expObj);
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos);
    if (GIMMICK46_IsPosInside(&playerPos) == 0)
        inside = 0;
    if (work->playerInside != inside) {
        GIMMICK46_SetExteriorHidden(expObj, fieldMap, inside);
        work->playerInside = inside;
    }
}









void GIMMICK46_StartButtonEvent(struct GameSystem *gameSystem, int unitIndex, int side)
{
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    Gimmick46Save *save;
    Gimmick46Work *work;

    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    work->unitIndex = unitIndex;
    work->side = side;
    work->unit = &save->units[unitIndex];
    func_020122C0(gameSystem, 0, GIMMICK46_ButtonEventProc, 0);
}









void GIMMICK46_StartLeverEvent(struct GameSystem *gameSystem, int unitIndex, int side)
{
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    Gimmick46Save *save;
    Gimmick46Work *work;

    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    work->unitIndex = unitIndex;
    work->side = side;
    work->unit = &save->units[unitIndex];
    func_020122C0(gameSystem, 0, GIMMICK46_LeverEventProc, 0);
}









void GIMMICK46_StartRotateEvent(struct GameSystem *gameSystem, int unitIndex)
{
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    Gimmick46Save *save;
    Gimmick46Work *work;

    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    work->unitIndex = unitIndex;
    work->unit = &save->units[unitIndex];
    func_020122C0(gameSystem, 0, GIMMICK46_RotateEventProc, 0);
}









/*
 * The negation is a multiply by 0xffffffff (see the idiom on
 * multiplying by minus one), and the hop data pointer is a separate local
 * that is formed after the func_020122C0 call.
 */
struct GameEvent *GIMMICK46_StartHopEvent(struct GameSystem *gameSystem, int direction)
{
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    Gimmick46Work *work;
    Gimmick46HopEvent *hop;
    struct GameEvent *hopEvent;
    Vec3Fx playerPos;

    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    hopEvent = func_020122C0(gameSystem, 0, GIMMICK46_HopEventProc, 0);
    hop = &work->event.hop;
    hop->step = 0;
    hop->speedX = GIMMICK46_HOP_SPEED;
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos);
    hop->baseY = playerPos.y;
    if (direction == 2)
        hop->speedX = hop->speedX * 0xffffffff;
    return hopEvent;
}








int GIMMICK46_CalcUnitPose(Gimmick46Unit *unit)
{
    if (unit->leverOn[0] == 0) {
        if (unit->leverOn[1] == 0)
            return 0;
        return 3;
    }
    if (unit->leverOn[1] == 0)
        return 2;
    return 1;
}








/*
 * Unlabelled leaf (no lr push) between GIMMICK46_CalcUnitPose and GIMMICK46_ButtonEventProc.
 */
int GIMMICK46_GetRotateAnim(Gimmick46Unit *unit, int newPose)
{
    return sGimmick46RotateAnimTable[unit->pose][newPose] - 5;
}








/*
 * The 3/4 selector must be a ternary inside the sum with the ternary
 * first: an if-assigned local or `a0 * 5 + (...)` gets other registers.
 */
int GIMMICK46_ButtonEventProc(struct GameEvent *event, int *state)
{
    struct GameSystem *gameSystem = func_020124E4(event);
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    Gimmick46Work *work;

    FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        work->event.anim.modelIndex = (work->side == 0 ? GIMMICK46_MODEL_BUTTON_BASE : GIMMICK46_MODEL_BUTTON_BASE + 1) + work->unitIndex * GIMMICK46_MODELS_PER_UNIT;
        work->event.anim.startCount = 1;
        work->event.anim.animId[0] = 0;
        work->event.anim.stopCount = 1;
        work->event.anim.startSe = GIMMICK46_SE_BUTTON;
        work->event.anim.endSe = GIMMICK46_SE_NONE;
        GAME_EVENT_CallEvent(event, func_020122C0(gameSystem, 0, GIMMICK46_PlayAnimEventProc, 0));
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}






int GIMMICK46_LeverEventProc(struct GameEvent *event, int *state)
{
    struct GameSystem *gameSystem = func_020124E4(event);
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    Gimmick46Work *work;
    int newLeverState;

    FIELDMAP_GetExpObj(fieldMap);
    newLeverState = 1;
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        if (work->unit->leverOn[work->side] != 0)
            newLeverState = 0;
        work->event.anim.modelIndex = (work->side == 0 ? GIMMICK46_MODEL_LEVER_BASE : GIMMICK46_MODEL_LEVER_BASE + 1) + work->unitIndex * GIMMICK46_MODELS_PER_UNIT;
        work->event.anim.startCount = 1;
        work->event.anim.animId[0] = newLeverState;
        work->event.anim.stopCount = 2;
        work->event.anim.startSe = GIMMICK46_SE_LEVER_START;
        work->event.anim.endSe = GIMMICK46_SE_LEVER_END;
        GAME_EVENT_CallEvent(event, func_020122C0(gameSystem, 0, GIMMICK46_PlayAnimEventProc, 0));
        work->unit->leverOn[work->side] = newLeverState;
        (*state)++;
        break;
    case 1:
        return newLeverState;
    }
    return 0;
}





int GIMMICK46_RotateEventProc(struct GameEvent *event, int *state)
{
    struct GameSystem *gameSystem = func_020124E4(event);
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    Gimmick46Work *work;
    int newPose;
    int bodyAnim;

    FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        newPose = GIMMICK46_CalcUnitPose(work->unit);
        bodyAnim = GIMMICK46_GetRotateAnim(work->unit, newPose);
        work->event.anim.modelIndex = work->unitIndex * GIMMICK46_MODELS_PER_UNIT;
        work->event.anim.startCount = 1;
        work->event.anim.animId[0] = bodyAnim;
        work->event.anim.stopCount = 8;
        work->event.anim.startSe = GIMMICK46_SE_ROTATE_START;
        work->event.anim.endSe = GIMMICK46_SE_ROTATE_END;
        GAME_EVENT_CallEvent(event, func_020122C0(gameSystem, 0, GIMMICK46_PlayAnimEventProc, 0));
        work->unit->pose = newPose;
        (*state)++;
        break;
    case 1:
        GIMMICK46_ApplyPoseLines(fieldMap, work->unitIndex, work->unit->pose);
        return 1;
    }
    return 0;
}




int GIMMICK46_PlayAnimEventProc(struct GameEvent *event, int *state)
{
    struct FieldMap *fieldMap;
    struct FldExpObj *expObj;
    Gimmick46AnimEvent *anim;
    u8 modelIdx;
    int i;
    u8 animIdx;

    fieldMap = GAMESYSTEM_GetFieldMap(func_020124E4(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    anim = &FIELDMAP_GetCommonWork(fieldMap, 1)->event.anim;
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        modelIdx = anim->modelIndex;
        for (i = 0; i < anim->stopCount; i++) {
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, modelIdx, i), 1);
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, modelIdx, (u8)i, 0);
        }
        for (i = 0; i < anim->startCount; i++) {
            animIdx = anim->animId[i];
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, modelIdx, animIdx), 0);
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, modelIdx, (u8)animIdx, 1);
            FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, modelIdx, animIdx, 0);
            func_020061E4(anim->startSe);
        }
        (*state)++;
        break;
    case 1:
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, anim->modelIndex, anim->animId[0]))) {
            GFL_USE_StopAllSe();
            if (anim->endSe != GIMMICK46_SE_NONE)
                func_020061E4(anim->endSe);
            return 1;
        }
        break;
    }
    return 0;
}




int GIMMICK46_HopEventProc(struct GameEvent *event, int *state)
{
    struct FieldMap *fieldMap;
    Gimmick46HopEvent *hop;
    int done = 1;
    struct FieldPlayer *player;
    Vec3Fx pos;

    fieldMap = GAMESYSTEM_GetFieldMap(func_020124E4(event));
    FIELDMAP_GetExpObj(fieldMap);
    hop = &FIELDMAP_GetCommonWork(fieldMap, 1)->event.hop;
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        func_020061E4(GIMMICK46_SE_HOP_START);
        (*state)++;
        break;
    case 1:
        player = FIELDMAP_GetFieldPlayer(fieldMap);
        FIELD_PLAYER_GetPos(player, &pos);
        pos.x = pos.x + hop->speedX;
        pos.y = hop->baseY + (sGimmick46HopHeights[hop->step] << 12);
        FIELD_PLAYER_SetPos(player, &pos);
        hop->step = hop->step + 1;
        if (hop->step >= GIMMICK46_HOP_STEPS) {
            func_020061E4(GIMMICK46_SE_HOP_END);
            return done;
        }
        break;
    }
    return 0;
}




void GIMMICK46_SetExteriorHidden(struct FldExpObj *expObj, struct FieldMap *fieldMap, u32 hidden)
{
    func_021BE4B4(expObj, 0, 15, hidden);
    func_021BE4B4(expObj, 0, 10, hidden);
    func_021BE4B4(expObj, 0, 11, hidden);
    func_021BE4B4(expObj, 0, 12, hidden);
    func_021BE4B4(expObj, 0, 13, hidden);
    func_021BE4B4(expObj, 0, 14, hidden);
    GIMMICK46_SetMmdlVanish(fieldMap, 4, hidden);
    GIMMICK46_SetMmdlVanish(fieldMap, 5, hidden);
    GIMMICK46_SetMmdlVanish(fieldMap, 9, hidden);
    GIMMICK46_SetMmdlVanish(fieldMap, 6, hidden);
}




struct Mmdl *GIMMICK46_FindMmdlByObjId(struct FieldMap *fieldMap, int objId)
{
    u32 iterator = 0;
    struct Mmdl *mmdl;
    struct FldMmdlSys *mmdlSys = FIELDMAP_GetMmdlSys(fieldMap);

    while (FLDMMDL_SysSearchUseMmdl(mmdlSys, &mmdl, &iterator) == 1) {
        if (objId == FLDMMDL_GetObjId(mmdl))
            return mmdl;
    }
    return 0;
}



void GIMMICK46_SetMmdlVanish(struct FieldMap *fieldMap, int objId, u32 vanish)
{
    struct Mmdl *mmdl;

    mmdl = GIMMICK46_FindMmdlByObjId(fieldMap, objId);
    if (mmdl)
        FLDMMDL_SetStatusBitVanish(mmdl, vanish);
}




/*
 * The table row is indexed inside the loop; the compiler hoists the
 * invariant row address (the register of pose is reused for it). A
 * `t = d[unit][pose]` local before the loop colours pose and the counter
 * apart. FIELD_NOGRID_MAPPER_SetLineEnable is ov021's thunk (reads r0-r2); ov214's label at the
 * same address is a different two-argument function.
 */
void GIMMICK46_ApplyPoseLines(struct FieldMap *fieldMap, int unitIndex, int pose)
{
    int lines[6];
    int enabled[6];
    struct NogridMapper *mapper = FIELDMAP_GetNogridMapper(fieldMap);
    int i;

    for (i = 0; i < 6; i++) {
        lines[i] = sGimmick46PoseLines[unitIndex][pose][i];
        enabled[i] = 0;
    }
    if (pose != 1) {
        enabled[0] = 1;
        enabled[1] = 1;
    }
    for (i = 0; i < 6; i++)
        FIELD_NOGRID_MAPPER_SetLineEnable(mapper, lines[i], enabled[i]);
}

int GIMMICK46_IsPosInside(Vec3Fx *pos)
{
    if (pos->y > 0x40000)
        return 0;
    if (pos->x >= 0x100000 && pos->z >= 0x1e0000)
        return 1;
    return 0;
}
