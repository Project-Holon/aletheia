/*
 * file:     field_gimmick_rotating_room.c
 * unit:     yes
 * function: FIELD_GIMMICK_ROTATING_ROOM_Init, FIELD_GIMMICK_ROTATING_ROOM_InitModel, FIELD_GIMMICK_ROTATING_ROOM_InitUnitPose, FIELD_GIMMICK_ROTATING_ROOM_Exit, FIELD_GIMMICK_ROTATING_ROOM_Update, FIELD_GIMMICK_ROTATING_ROOM_StartButtonEvent, FIELD_GIMMICK_ROTATING_ROOM_StartLeverEvent, FIELD_GIMMICK_ROTATING_ROOM_StartRotateEvent, FIELD_GIMMICK_ROTATING_ROOM_StartHopEvent, FIELD_GIMMICK_ROTATING_ROOM_CalcUnitPose, FIELD_GIMMICK_ROTATING_ROOM_GetRotateAnim, FIELD_GIMMICK_ROTATING_ROOM_ButtonEventProc, FIELD_GIMMICK_ROTATING_ROOM_LeverEventProc, FIELD_GIMMICK_ROTATING_ROOM_RotateEventProc, FIELD_GIMMICK_ROTATING_ROOM_PlayAnimEventProc, FIELD_GIMMICK_ROTATING_ROOM_HopEventProc, FIELD_GIMMICK_ROTATING_ROOM_SetExteriorHidden, FIELD_GIMMICK_ROTATING_ROOM_FindMmdlByObjId, FIELD_GIMMICK_ROTATING_ROOM_SetMmdlVanish, FIELD_GIMMICK_ROTATING_ROOM_ApplyPoseLines, FIELD_GIMMICK_ROTATING_ROOM_IsPosInside
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
 *   FIELD_GIMMICK_ROTATING_ROOM_IsPosInside  0x021F40D8  thumb  ov046
 *   sRotatingRoomExpUnitDesc     0x021F4120  data  a4
 *   sRotatingRoomUnitAngles     0x021F4108  data  a2
 *   sRotatingRoomBodyPos     0x021F4194  data  a4
 *   sRotatingRoomLeverPos     0x021F4170  data  a4
 *   sRotatingRoomButtonPos     0x021F4204  data  a4
 *   sRotatingRoomExtraModelPos     0x021F41B8  data  a4
 *   FX_SinCosTable_     0x020A1B38  data  a2
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
 *   sRotatingRoomRotateAnimTable  0x021F41C4  data  a4
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   sRotatingRoomHopHeights  0x021F4130  data  a4
 *   DEMO3D_ENGINE_Delete  0x021BE4B4  thumb  ov203
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   FLDMMDL_SetStatusBitVanish 0x0216DAC8 thumb ov010
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELD_NOGRID_MAPPER_SetLineEnable  0x021BB3DC  thumb  ov021
 *   sRotatingRoomPoseLines  0x021F4430  data  ov046  a4
 */
#include "../ov037/gimmick_save_types.h"
#include "field_gimmick_rotating_room_types.h"

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
extern FieldGimmickRotatingRoomSave *GIMMICK_WORK_GetSaveArea(struct FieldSave *fieldSave, u32 blockId);
extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern FieldGimmickRotatingRoomWork *FIELDMAP_AllocCommonWork(struct FieldMap *fieldMap, int workId, int heapId, int size);
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
extern FieldGimmickRotatingRoomWork *FIELDMAP_GetCommonWork(struct FieldMap *fieldMap, int workId);
extern void FIELDMAP_FreeCommonWork(struct FieldMap *fieldMap, int workId);
extern void FLD_EXP_OBJ_RemoveUnit(struct FldExpObj *expObj, u16 unitIndex);
extern void FLD_EXP_OBJ_UpdateAnimes(struct FldExpObj *expObj);
extern struct FieldMap *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc proc, u32 size);
extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);
extern int FLD_EXP_OBJ_IsAnimeStopped(struct FldExpAnime *anime);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern void GFL_USE_StopAllSe(void);
extern void FIELD_PLAYER_SetPos(struct FieldPlayer *player, Vec3Fx *pos);
extern void DEMO3D_ENGINE_Delete(struct FldExpObj *expObj, int unitIndex, int modelIndex, u32 hidden);
extern struct FldMmdlSys *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);
extern int FLDMMDL_SysSearchUseMmdl(struct FldMmdlSys *mmdlSys, struct Mmdl **outMmdl, u32 *iterator);
extern u16 FLDMMDL_GetObjId(struct Mmdl *mmdl);
extern void FLDMMDL_SetStatusBitVanish(struct Mmdl *mmdl, u32 vanish);
extern struct NogridMapper *FIELDMAP_GetNogridMapper(struct FieldMap *fieldMap);
extern void FIELD_NOGRID_MAPPER_SetLineEnable(struct NogridMapper *mapper, int lineIndex, int enabled);

void FIELD_GIMMICK_ROTATING_ROOM_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_ROTATING_ROOM_InitModel(struct FldExpObj *expObj, int modelIndex, Vec3Fx *pos, u16 *angle, int animCount, int cullDraw);
void FIELD_GIMMICK_ROTATING_ROOM_InitUnitPose(FieldGimmickRotatingRoomSave *save, struct FldExpObj *expObj, int unitIndex);
void FIELD_GIMMICK_ROTATING_ROOM_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_ROTATING_ROOM_Update(struct FieldMap *fieldMap);
void FIELD_GIMMICK_ROTATING_ROOM_StartButtonEvent(struct GameSystem *gameSystem, int unitIndex, int side);
void FIELD_GIMMICK_ROTATING_ROOM_StartLeverEvent(struct GameSystem *gameSystem, int unitIndex, int side);
void FIELD_GIMMICK_ROTATING_ROOM_StartRotateEvent(struct GameSystem *gameSystem, int unitIndex);
struct GameEvent *FIELD_GIMMICK_ROTATING_ROOM_StartHopEvent(struct GameSystem *gameSystem, int direction);
int FIELD_GIMMICK_ROTATING_ROOM_CalcUnitPose(FieldGimmickRotatingRoomUnit *unit);
int FIELD_GIMMICK_ROTATING_ROOM_GetRotateAnim(FieldGimmickRotatingRoomUnit *unit, int newPose);
int FIELD_GIMMICK_ROTATING_ROOM_ButtonEventProc(struct GameEvent *event, int *state);
int FIELD_GIMMICK_ROTATING_ROOM_LeverEventProc(struct GameEvent *event, int *state);
int FIELD_GIMMICK_ROTATING_ROOM_RotateEventProc(struct GameEvent *event, int *state);
int FIELD_GIMMICK_ROTATING_ROOM_PlayAnimEventProc(struct GameEvent *event, int *state);
int FIELD_GIMMICK_ROTATING_ROOM_HopEventProc(struct GameEvent *event, int *state);
void FIELD_GIMMICK_ROTATING_ROOM_SetExteriorHidden(struct FldExpObj *expObj, struct FieldMap *fieldMap, u32 hidden);
struct Mmdl *FIELD_GIMMICK_ROTATING_ROOM_FindMmdlByObjId(struct FieldMap *fieldMap, int objId);
void FIELD_GIMMICK_ROTATING_ROOM_SetMmdlVanish(struct FieldMap *fieldMap, int objId, u32 vanish);
void FIELD_GIMMICK_ROTATING_ROOM_ApplyPoseLines(struct FieldMap *fieldMap, int unitIndex, int pose);
int FIELD_GIMMICK_ROTATING_ROOM_IsPosInside(Vec3Fx *pos);

extern struct FldExpUnitDesc sRotatingRoomExpUnitDesc;
extern u16 sRotatingRoomUnitAngles[];         /* initial angle per unit */
extern Vec3Fx sRotatingRoomBodyPos[];      /* body position per unit */
extern Vec3Fx sRotatingRoomLeverPos[];      /* lever position per unit (both levers) */
extern Vec3Fx sRotatingRoomButtonPos[];      /* button position, two per unit */
extern Vec3Fx sRotatingRoomExtraModelPos;        /* position of the extra model */
extern s16 FX_SinCosTable_[];         /* sine and cosine pairs */
extern int sRotatingRoomRotateAnimTable[][4];      /* body animation for (old pose, new pose) plus 5 */
extern int sRotatingRoomHopHeights[];         /* height offsets of the hop, in tiles */
extern int sRotatingRoomPoseLines[][4][6];   /* walk lines (line, enabled) per (unit, pose) */


void FIELD_GIMMICK_ROTATING_ROOM_Init(struct FieldMap *fieldMap)
{
    Vec3Fx extraPos;
    Vec3Fx playerPos;
    u16 angle;
    int unitIdx;
    struct FldExpObj *expObj;
    FieldGimmickRotatingRoomSave *save;
    FieldGimmickRotatingRoomWork *work;
    int firstModel;
    int inside;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_ROTATING_ROOM_SAVE_BLOCK_ID);
    work = FIELDMAP_AllocCommonWork(fieldMap, 1, FIELDMAP_GetHeapId(fieldMap), sizeof(FieldGimmickRotatingRoomWork));
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, &sRotatingRoomExpUnitDesc, 0);
    for (unitIdx = 0; unitIdx < FIELD_GIMMICK_ROTATING_ROOM_UNIT_COUNT; unitIdx++) {
        /* Cleared and then set: the first store is in the original code. */
        angle = 0;
        angle = sRotatingRoomUnitAngles[unitIdx];
        firstModel = unitIdx * FIELD_GIMMICK_ROTATING_ROOM_MODELS_PER_UNIT;
        FIELD_GIMMICK_ROTATING_ROOM_InitModel(expObj, firstModel, &sRotatingRoomBodyPos[unitIdx], &angle, 8, 0);
        FIELD_GIMMICK_ROTATING_ROOM_InitModel(expObj, firstModel + 1, &sRotatingRoomLeverPos[unitIdx], &angle, 2, 0);
        FIELD_GIMMICK_ROTATING_ROOM_InitModel(expObj, firstModel + 2, &sRotatingRoomLeverPos[unitIdx], &angle, 2, 0);
        FIELD_GIMMICK_ROTATING_ROOM_InitModel(expObj, firstModel + 3, &sRotatingRoomButtonPos[unitIdx * 2], 0, 1, 1);
        FIELD_GIMMICK_ROTATING_ROOM_InitModel(expObj, firstModel + 4, &sRotatingRoomButtonPos[unitIdx * 2 + 1], 0, 1, 1);
        FIELD_GIMMICK_ROTATING_ROOM_InitUnitPose(save, expObj, unitIdx);
    }
    /* The position is copied to a local first; passing the table row
     * directly changes the stack frame. */
    extraPos = sRotatingRoomExtraModelPos;
    FIELD_GIMMICK_ROTATING_ROOM_InitModel(expObj, FIELD_GIMMICK_ROTATING_ROOM_MODEL_EXTRA, &extraPos, 0, 0, 0);
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, FIELD_GIMMICK_ROTATING_ROOM_MODEL_EXTRA, 0, 1);
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos);
    inside = FIELD_GIMMICK_ROTATING_ROOM_IsPosInside(&playerPos) != 0 ? 1 : 0;
    FIELD_GIMMICK_ROTATING_ROOM_SetExteriorHidden(expObj, fieldMap, inside);
    work->playerInside = inside;
    for (unitIdx = 0; unitIdx < FIELD_GIMMICK_ROTATING_ROOM_UNIT_COUNT; unitIdx++)
        FIELD_GIMMICK_ROTATING_ROOM_ApplyPoseLines(fieldMap, unitIdx, save->units[unitIdx].pose);
}



void FIELD_GIMMICK_ROTATING_ROOM_InitModel(struct FldExpObj *expObj, int modelIndex, Vec3Fx *pos, u16 *angle, int animCount, int cullDraw)
{
    FldExpModel *model;
    struct FldExpAnime *anime;
    int animIdx;
    int tableIdx;

    model = FLD_EXP_OBJ_GetModelStatus(expObj, (int)0, (u16)modelIndex);
    model->pos = *pos;
    if (angle) {
        tableIdx = (*angle >> 4) * 2;
        func_0207AF1C(model->rotation, FX_SinCosTable_[tableIdx], FX_SinCosTable_[tableIdx + 1]);
    }
    FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, modelIndex, cullDraw);
    for (animIdx = 0; animIdx < animCount; animIdx++) {
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, modelIndex, animIdx);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, modelIndex, animIdx, 0);
    }
}









void FIELD_GIMMICK_ROTATING_ROOM_InitUnitPose(FieldGimmickRotatingRoomSave *save, struct FldExpObj *expObj, int unitIdx)
{
    FieldGimmickRotatingRoomUnit *unit;
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
    bodyModel = unitIdx * FIELD_GIMMICK_ROTATING_ROOM_MODELS_PER_UNIT;
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








void FIELD_GIMMICK_ROTATING_ROOM_Exit(struct FieldMap *fieldMap)
{
    struct FldExpObj *expObj;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_GetCommonWork(fieldMap, 1);
    FIELDMAP_FreeCommonWork(fieldMap, 1);
    FLD_EXP_OBJ_RemoveUnit(expObj, 0);
}









void FIELD_GIMMICK_ROTATING_ROOM_Update(struct FieldMap *fieldMap)
{
    Vec3Fx playerPos;
    struct FldExpObj *expObj = FIELDMAP_GetExpObj(fieldMap);
    FieldGimmickRotatingRoomWork *work = FIELDMAP_GetCommonWork(fieldMap, 1);
    int inside = 1;

    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_ROTATING_ROOM_SAVE_BLOCK_ID);
    FLD_EXP_OBJ_UpdateAnimes(expObj);
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos);
    if (FIELD_GIMMICK_ROTATING_ROOM_IsPosInside(&playerPos) == 0)
        inside = 0;
    if (work->playerInside != inside) {
        FIELD_GIMMICK_ROTATING_ROOM_SetExteriorHidden(expObj, fieldMap, inside);
        work->playerInside = inside;
    }
}









void FIELD_GIMMICK_ROTATING_ROOM_StartButtonEvent(struct GameSystem *gameSystem, int unitIndex, int side)
{
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    FieldGimmickRotatingRoomSave *save;
    FieldGimmickRotatingRoomWork *work;

    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_ROTATING_ROOM_SAVE_BLOCK_ID);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    work->unitIndex = unitIndex;
    work->side = side;
    work->unit = &save->units[unitIndex];
    func_020122C0(gameSystem, 0, FIELD_GIMMICK_ROTATING_ROOM_ButtonEventProc, 0);
}









void FIELD_GIMMICK_ROTATING_ROOM_StartLeverEvent(struct GameSystem *gameSystem, int unitIndex, int side)
{
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    FieldGimmickRotatingRoomSave *save;
    FieldGimmickRotatingRoomWork *work;

    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_ROTATING_ROOM_SAVE_BLOCK_ID);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    work->unitIndex = unitIndex;
    work->side = side;
    work->unit = &save->units[unitIndex];
    func_020122C0(gameSystem, 0, FIELD_GIMMICK_ROTATING_ROOM_LeverEventProc, 0);
}









void FIELD_GIMMICK_ROTATING_ROOM_StartRotateEvent(struct GameSystem *gameSystem, int unitIndex)
{
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    FieldGimmickRotatingRoomSave *save;
    FieldGimmickRotatingRoomWork *work;

    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_ROTATING_ROOM_SAVE_BLOCK_ID);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    work->unitIndex = unitIndex;
    work->unit = &save->units[unitIndex];
    func_020122C0(gameSystem, 0, FIELD_GIMMICK_ROTATING_ROOM_RotateEventProc, 0);
}









/*
 * The negation is a multiply by 0xffffffff (see the idiom on
 * multiplying by minus one), and the hop data pointer is a separate local
 * that is formed after the func_020122C0 call.
 */
struct GameEvent *FIELD_GIMMICK_ROTATING_ROOM_StartHopEvent(struct GameSystem *gameSystem, int direction)
{
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    FieldGimmickRotatingRoomWork *work;
    FieldGimmickRotatingRoomHopEvent *hop;
    struct GameEvent *hopEvent;
    Vec3Fx playerPos;

    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_ROTATING_ROOM_SAVE_BLOCK_ID);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    hopEvent = func_020122C0(gameSystem, 0, FIELD_GIMMICK_ROTATING_ROOM_HopEventProc, 0);
    hop = &work->event.hop;
    hop->step = 0;
    hop->speedX = FIELD_GIMMICK_ROTATING_ROOM_HOP_SPEED;
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos);
    hop->baseY = playerPos.y;
    if (direction == 2)
        hop->speedX = hop->speedX * 0xffffffff;
    return hopEvent;
}








int FIELD_GIMMICK_ROTATING_ROOM_CalcUnitPose(FieldGimmickRotatingRoomUnit *unit)
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
 * Unlabelled leaf (no lr push) between FIELD_GIMMICK_ROTATING_ROOM_CalcUnitPose and FIELD_GIMMICK_ROTATING_ROOM_ButtonEventProc.
 */
int FIELD_GIMMICK_ROTATING_ROOM_GetRotateAnim(FieldGimmickRotatingRoomUnit *unit, int newPose)
{
    return sRotatingRoomRotateAnimTable[unit->pose][newPose] - 5;
}








/*
 * The 3/4 selector must be a ternary inside the sum with the ternary
 * first: an if-assigned local or `a0 * 5 + (...)` gets other registers.
 */
int FIELD_GIMMICK_ROTATING_ROOM_ButtonEventProc(struct GameEvent *event, int *state)
{
    struct GameSystem *gameSystem = GAME_EVENT_GetGameSystem(event);
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    FieldGimmickRotatingRoomWork *work;

    FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_ROTATING_ROOM_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        work->event.anim.modelIndex = (work->side == 0 ? FIELD_GIMMICK_ROTATING_ROOM_MODEL_BUTTON_BASE : FIELD_GIMMICK_ROTATING_ROOM_MODEL_BUTTON_BASE + 1) + work->unitIndex * FIELD_GIMMICK_ROTATING_ROOM_MODELS_PER_UNIT;
        work->event.anim.startCount = 1;
        work->event.anim.animId[0] = 0;
        work->event.anim.stopCount = 1;
        work->event.anim.startSe = FIELD_GIMMICK_ROTATING_ROOM_SE_BUTTON;
        work->event.anim.endSe = FIELD_GIMMICK_ROTATING_ROOM_SE_NONE;
        GAME_EVENT_CallEvent(event, func_020122C0(gameSystem, 0, FIELD_GIMMICK_ROTATING_ROOM_PlayAnimEventProc, 0));
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}






int FIELD_GIMMICK_ROTATING_ROOM_LeverEventProc(struct GameEvent *event, int *state)
{
    struct GameSystem *gameSystem = GAME_EVENT_GetGameSystem(event);
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    FieldGimmickRotatingRoomWork *work;
    int newLeverState;

    FIELDMAP_GetExpObj(fieldMap);
    newLeverState = 1;
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_ROTATING_ROOM_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        if (work->unit->leverOn[work->side] != 0)
            newLeverState = 0;
        work->event.anim.modelIndex = (work->side == 0 ? FIELD_GIMMICK_ROTATING_ROOM_MODEL_LEVER_BASE : FIELD_GIMMICK_ROTATING_ROOM_MODEL_LEVER_BASE + 1) + work->unitIndex * FIELD_GIMMICK_ROTATING_ROOM_MODELS_PER_UNIT;
        work->event.anim.startCount = 1;
        work->event.anim.animId[0] = newLeverState;
        work->event.anim.stopCount = 2;
        work->event.anim.startSe = FIELD_GIMMICK_ROTATING_ROOM_SE_LEVER_START;
        work->event.anim.endSe = FIELD_GIMMICK_ROTATING_ROOM_SE_LEVER_END;
        GAME_EVENT_CallEvent(event, func_020122C0(gameSystem, 0, FIELD_GIMMICK_ROTATING_ROOM_PlayAnimEventProc, 0));
        work->unit->leverOn[work->side] = newLeverState;
        (*state)++;
        break;
    case 1:
        return newLeverState;
    }
    return 0;
}





int FIELD_GIMMICK_ROTATING_ROOM_RotateEventProc(struct GameEvent *event, int *state)
{
    struct GameSystem *gameSystem = GAME_EVENT_GetGameSystem(event);
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    FieldGimmickRotatingRoomWork *work;
    int newPose;
    int bodyAnim;

    FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_ROTATING_ROOM_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        newPose = FIELD_GIMMICK_ROTATING_ROOM_CalcUnitPose(work->unit);
        bodyAnim = FIELD_GIMMICK_ROTATING_ROOM_GetRotateAnim(work->unit, newPose);
        work->event.anim.modelIndex = work->unitIndex * FIELD_GIMMICK_ROTATING_ROOM_MODELS_PER_UNIT;
        work->event.anim.startCount = 1;
        work->event.anim.animId[0] = bodyAnim;
        work->event.anim.stopCount = 8;
        work->event.anim.startSe = FIELD_GIMMICK_ROTATING_ROOM_SE_ROTATE_START;
        work->event.anim.endSe = FIELD_GIMMICK_ROTATING_ROOM_SE_ROTATE_END;
        GAME_EVENT_CallEvent(event, func_020122C0(gameSystem, 0, FIELD_GIMMICK_ROTATING_ROOM_PlayAnimEventProc, 0));
        work->unit->pose = newPose;
        (*state)++;
        break;
    case 1:
        FIELD_GIMMICK_ROTATING_ROOM_ApplyPoseLines(fieldMap, work->unitIndex, work->unit->pose);
        return 1;
    }
    return 0;
}




int FIELD_GIMMICK_ROTATING_ROOM_PlayAnimEventProc(struct GameEvent *event, int *state)
{
    struct FieldMap *fieldMap;
    struct FldExpObj *expObj;
    FieldGimmickRotatingRoomAnimEvent *anim;
    u8 modelIdx;
    int i;
    u8 animIdx;

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    anim = &FIELDMAP_GetCommonWork(fieldMap, 1)->event.anim;
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_ROTATING_ROOM_SAVE_BLOCK_ID);
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
            GFL_USE_PlaySeDefaultVolume(anim->startSe);
        }
        (*state)++;
        break;
    case 1:
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, anim->modelIndex, anim->animId[0]))) {
            GFL_USE_StopAllSe();
            if (anim->endSe != FIELD_GIMMICK_ROTATING_ROOM_SE_NONE)
                GFL_USE_PlaySeDefaultVolume(anim->endSe);
            return 1;
        }
        break;
    }
    return 0;
}




int FIELD_GIMMICK_ROTATING_ROOM_HopEventProc(struct GameEvent *event, int *state)
{
    struct FieldMap *fieldMap;
    FieldGimmickRotatingRoomHopEvent *hop;
    int done = 1;
    struct FieldPlayer *player;
    Vec3Fx pos;

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    FIELDMAP_GetExpObj(fieldMap);
    hop = &FIELDMAP_GetCommonWork(fieldMap, 1)->event.hop;
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_ROTATING_ROOM_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(FIELD_GIMMICK_ROTATING_ROOM_SE_HOP_START);
        (*state)++;
        break;
    case 1:
        player = FIELDMAP_GetFieldPlayer(fieldMap);
        FIELD_PLAYER_GetPos(player, &pos);
        pos.x = pos.x + hop->speedX;
        pos.y = hop->baseY + (sRotatingRoomHopHeights[hop->step] << 12);
        FIELD_PLAYER_SetPos(player, &pos);
        hop->step = hop->step + 1;
        if (hop->step >= FIELD_GIMMICK_ROTATING_ROOM_HOP_STEPS) {
            GFL_USE_PlaySeDefaultVolume(FIELD_GIMMICK_ROTATING_ROOM_SE_HOP_END);
            return done;
        }
        break;
    }
    return 0;
}




void FIELD_GIMMICK_ROTATING_ROOM_SetExteriorHidden(struct FldExpObj *expObj, struct FieldMap *fieldMap, u32 hidden)
{
    DEMO3D_ENGINE_Delete(expObj, 0, 15, hidden);
    DEMO3D_ENGINE_Delete(expObj, 0, 10, hidden);
    DEMO3D_ENGINE_Delete(expObj, 0, 11, hidden);
    DEMO3D_ENGINE_Delete(expObj, 0, 12, hidden);
    DEMO3D_ENGINE_Delete(expObj, 0, 13, hidden);
    DEMO3D_ENGINE_Delete(expObj, 0, 14, hidden);
    FIELD_GIMMICK_ROTATING_ROOM_SetMmdlVanish(fieldMap, 4, hidden);
    FIELD_GIMMICK_ROTATING_ROOM_SetMmdlVanish(fieldMap, 5, hidden);
    FIELD_GIMMICK_ROTATING_ROOM_SetMmdlVanish(fieldMap, 9, hidden);
    FIELD_GIMMICK_ROTATING_ROOM_SetMmdlVanish(fieldMap, 6, hidden);
}




struct Mmdl *FIELD_GIMMICK_ROTATING_ROOM_FindMmdlByObjId(struct FieldMap *fieldMap, int objId)
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



void FIELD_GIMMICK_ROTATING_ROOM_SetMmdlVanish(struct FieldMap *fieldMap, int objId, u32 vanish)
{
    struct Mmdl *mmdl;

    mmdl = FIELD_GIMMICK_ROTATING_ROOM_FindMmdlByObjId(fieldMap, objId);
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
void FIELD_GIMMICK_ROTATING_ROOM_ApplyPoseLines(struct FieldMap *fieldMap, int unitIndex, int pose)
{
    int lines[6];
    int enabled[6];
    struct NogridMapper *mapper = FIELDMAP_GetNogridMapper(fieldMap);
    int i;

    for (i = 0; i < 6; i++) {
        lines[i] = sRotatingRoomPoseLines[unitIndex][pose][i];
        enabled[i] = 0;
    }
    if (pose != 1) {
        enabled[0] = 1;
        enabled[1] = 1;
    }
    for (i = 0; i < 6; i++)
        FIELD_NOGRID_MAPPER_SetLineEnable(mapper, lines[i], enabled[i]);
}

int FIELD_GIMMICK_ROTATING_ROOM_IsPosInside(Vec3Fx *pos)
{
    if (pos->y > 0x40000)
        return 0;
    if (pos->x >= 0x100000 && pos->z >= 0x1e0000)
        return 1;
    return 0;
}
