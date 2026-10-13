/*
 * file:     field_gimmick_lane_trains.c
 * unit:     yes
 * function: FIELD_GIMMICK_LANE_TRAINS_Init, FIELD_GIMMICK_LANE_TRAINS_Exit, FIELD_GIMMICK_LANE_TRAINS_Update, FIELD_GIMMICK_LANE_TRAINS_PlaceTrains, FIELD_GIMMICK_LANE_TRAINS_PlaceLaneTrains
 * address:  0x021F36C0
 * region:   ov058
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
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   sLaneTrainsUnitSetup  0x021F3B60  data  ov058  a4
 *   FLD_EXP_OBJ_RemoveUnit  0x021BE418  thumb  ov021
 *   FIELDMAP_FreeCommonWork  0x021897A0  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus 0x021BE480 thumb ov021
 *   FIELDMAP_GetFieldPlayer 0x02188CB4 thumb ov021
 *   FIELD_PLAYER_GetPos 0x021A3038 thumb ov021
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   func_020056EC 0x020056EC thumb
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   GFL_USE_IsSeSlotBusy 0x02006224 thumb
 *   FIELD_SOUND_SYSTEM_ClaimSlot 0x02028A7C thumb
 *   FIELD_GIMMICK_LANE_TRAINS_PlaceLaneTrains  0x021F391C  thumb  ov058
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   func_0207AF1C  0x0207AF1C  thumb
 *   FX_SinCosTable_     0x020A1B38  data  a2
 */
#include "../ov021/fld_exp_obj_types.h"
#include "field_gimmick_lane_trains_types.h"

extern struct GameSystem *FIELDMAP_GetGameSystem(struct FieldMap *fieldMap);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct GimmickWork *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern void *FIELDMAP_AllocCommonWork(struct FieldMap *fieldMap, int id, int heapId, int size);
extern FieldGimmickLaneTrainsWork *FIELDMAP_GetCommonWork(struct FieldMap *fieldMap, int id);
extern void FIELDMAP_FreeCommonWork(struct FieldMap *fieldMap, int id);
extern void FLD_EXP_OBJ_AddUnitFromArchive(FldExpObjCnt *expObj, const G3dUtilSetup *setup, u16 unitIndex);
extern void FLD_EXP_OBJ_RemoveUnit(FldExpObjCnt *expObj, u16 unitIndex);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);
extern void FIELD_PLAYER_GetPos(struct FieldPlayer *player, VecFx32 *pos);
extern void *GAME_DATA_GetBgmInfo(struct GameData *gameData);
extern u32 func_020056EC(u32 range);
extern int GFL_USE_GetSeSlot(u32 seId);
extern int GFL_USE_IsSeSlotBusy(int seSlot);
extern void FIELD_SOUND_SYSTEM_ClaimSlot(void *fieldSound, u32 seId);
extern void FIELD_GIMMICK_LANE_TRAINS_PlaceLaneTrains(FieldGimmickLaneTrainsWork *work, struct FieldMap *fieldMap, int leadModel, int trailModel);

void FIELD_GIMMICK_LANE_TRAINS_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_LANE_TRAINS_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_LANE_TRAINS_Update(struct FieldMap *fieldMap);
void FIELD_GIMMICK_LANE_TRAINS_PlaceTrains(FieldGimmickLaneTrainsWork *work, struct FieldMap *fieldMap);

extern G3dUtilSetup sLaneTrainsUnitSetup;

/* Allocate the work, add the train models and put them at their start. */
void FIELD_GIMMICK_LANE_TRAINS_Init(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;
    FieldGimmickLaneTrainsWork *work;

    FIELDMAP_GetHeapId(fieldMap);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    FIELDMAP_AllocCommonWork(fieldMap, 1, FIELDMAP_GetHeapId(fieldMap), 0x20);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, &sLaneTrainsUnitSetup, 0);
    FIELD_GIMMICK_LANE_TRAINS_PlaceTrains(work, fieldMap);
}

void FIELD_GIMMICK_LANE_TRAINS_Exit(struct FieldMap *fieldMap)
{
    GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    FLD_EXP_OBJ_RemoveUnit(FIELDMAP_GetExpObj(fieldMap), 0);
    FIELDMAP_FreeCommonWork(fieldMap, 1);
}

/* Per frame: move both trains, restart them after a run, play the pass sound. */
void FIELD_GIMMICK_LANE_TRAINS_Update(struct FieldMap *fieldMap)
{
    VecFx32 playerPos;
    int eastLeadX;
    int westLeadX;
    struct GameData *gameData;
    FldExpObjCnt *expObj;
    FieldGimmickLaneTrainsWork *work;
    FieldGimmickLaneTrainsTrain *train;
    int modelIndex;
    G3dObjectStatus *model;
    void *fieldSound;
    int delta;

    gameData = GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap));
    GAME_DATA_GetFieldSave(gameData);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);

    train = &work->eastbound;
    if (train->waitFrames != 0) {
        train->waitFrames--;
    } else {
        modelIndex = train->lane * FIELD_GIMMICK_LANE_TRAINS_MODELS_PER_LANE;
        train->step++;
        model = FLD_EXP_OBJ_GetModelStatus(expObj, 0, (u16)modelIndex);
        model->trans.x = (train->step << 16) + FIELD_GIMMICK_LANE_TRAINS_TRACK_MIN_X;
        if (model->trans.x >= FIELD_GIMMICK_LANE_TRAINS_TRACK_MAX_X) {
            train->step = 0;
            work->eastSoundPlayed = 0;
            train->waitFrames = func_020056EC(30) + 30;
            train->lane = func_020056EC(3);
        }
        eastLeadX = model->trans.x;
        model = FLD_EXP_OBJ_GetModelStatus(expObj, 0, (u16)(modelIndex + 1));
        model->trans.x = (train->step << 16) + (FIELD_GIMMICK_LANE_TRAINS_TRACK_MIN_X - FIELD_GIMMICK_LANE_TRAINS_TRAIL_GAP);
        if (model->trans.x >= FIELD_GIMMICK_LANE_TRAINS_TRACK_MAX_X)
            train->step = 0;
    }

    train = &work->westbound;
    if (train->waitFrames != 0) {
        train->waitFrames--;
    } else {
        modelIndex = train->lane * FIELD_GIMMICK_LANE_TRAINS_MODELS_PER_LANE + 2;
        train->step++;
        model = FLD_EXP_OBJ_GetModelStatus(expObj, 0, (u16)modelIndex);
        model->trans.x = FIELD_GIMMICK_LANE_TRAINS_TRACK_MAX_X - (train->step << 16);
        if (model->trans.x <= FIELD_GIMMICK_LANE_TRAINS_TRACK_MIN_X) {
            train->step = 0;
            work->westSoundPlayed = 0;
            train->waitFrames = func_020056EC(30);
            train->lane = func_020056EC(3);
        }
        westLeadX = model->trans.x;
        model = FLD_EXP_OBJ_GetModelStatus(expObj, 0, (u16)(modelIndex + 1));
        model->trans.x = (FIELD_GIMMICK_LANE_TRAINS_TRACK_MAX_X + FIELD_GIMMICK_LANE_TRAINS_TRAIL_GAP) - (train->step << 16);
        if (model->trans.x <= FIELD_GIMMICK_LANE_TRAINS_TRACK_MIN_X)
            train->step = 0;
    }

    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos);
    if (playerPos.z >= FIELD_GIMMICK_LANE_TRAINS_HEAR_MIN_Z && playerPos.z <= FIELD_GIMMICK_LANE_TRAINS_HEAR_MAX_Z) {
        fieldSound = GAME_DATA_GetBgmInfo(gameData);
        delta = playerPos.x - eastLeadX;
        if (delta >= 0 && delta <= FIELD_GIMMICK_LANE_TRAINS_HEAR_DISTANCE && work->eastSoundPlayed == 0) {
            if (GFL_USE_IsSeSlotBusy(GFL_USE_GetSeSlot(0x77e)) == 0) {
                work->eastSoundPlayed = 1;
                FIELD_SOUND_SYSTEM_ClaimSlot(fieldSound, 0x77e);
            }
        }
        delta = westLeadX - playerPos.x;
        if (delta >= 0 && delta <= FIELD_GIMMICK_LANE_TRAINS_HEAR_DISTANCE && work->westSoundPlayed == 0) {
            if (GFL_USE_IsSeSlotBusy(GFL_USE_GetSeSlot(0x77f)) == 0) {
                work->westSoundPlayed = 1;
                FIELD_SOUND_SYSTEM_ClaimSlot(fieldSound, 0x77f);
            }
        }
    }
}

/* Put the three sets of train models at their start. */
void FIELD_GIMMICK_LANE_TRAINS_PlaceTrains(FieldGimmickLaneTrainsWork *work, struct FieldMap *fieldMap)
{
    FIELD_GIMMICK_LANE_TRAINS_PlaceLaneTrains(work, fieldMap, 0, 1);
    FIELD_GIMMICK_LANE_TRAINS_PlaceLaneTrains(work, fieldMap, 4, 5);
    FIELD_GIMMICK_LANE_TRAINS_PlaceLaneTrains(work, fieldMap, 8, 9);
}

/*
 * Put the four models of one lane at their start: the eastbound lead and
 * trail (turned by the sine/cosine pair at angle step 0x400) and the
 * westbound lead and trail (pair 0xC00). The cosine values are separate
 * locals (two stack slots) while the sine value reuses one register; the
 * cosine declared before the sine puts the sine in r7.
 */
void FIELD_GIMMICK_LANE_TRAINS_PlaceLaneTrains(FieldGimmickLaneTrainsWork *work, struct FieldMap *fieldMap, int leadModel, int trailModel)
{
    FldExpObjCnt *expObj;
    G3dObjectStatus *model;
    int cosEast;
    int sinValue;
    int cosWest;

    FIELDMAP_GetHeapId(fieldMap);
    expObj = FIELDMAP_GetExpObj(fieldMap);

    model = FLD_EXP_OBJ_GetModelStatus(expObj, 0, (u16)leadModel);
    model->trans.x = FIELD_GIMMICK_LANE_TRAINS_TRACK_MIN_X;
    model->trans.y = FIELD_GIMMICK_LANE_TRAINS_TRAIN_Y;
    model->trans.z = FIELD_GIMMICK_LANE_TRAINS_EAST_TRACK_Z;
    sinValue = FX_SinCosTable_[0x800];
    cosEast = FX_SinCosTable_[0x801];
    func_0207AF1C(&model->rotate, sinValue, cosEast);
    FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, leadModel, 1);

    model = FLD_EXP_OBJ_GetModelStatus(expObj, 0, (u16)trailModel);
    model->trans.x = FIELD_GIMMICK_LANE_TRAINS_TRACK_MIN_X - FIELD_GIMMICK_LANE_TRAINS_TRAIL_GAP;
    model->trans.y = FIELD_GIMMICK_LANE_TRAINS_TRAIN_Y;
    model->trans.z = FIELD_GIMMICK_LANE_TRAINS_EAST_TRACK_Z;
    func_0207AF1C(&model->rotate, sinValue, cosEast);
    FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, trailModel, 1);

    model = FLD_EXP_OBJ_GetModelStatus(expObj, 0, (u16)(leadModel + 2));
    model->trans.x = FIELD_GIMMICK_LANE_TRAINS_TRACK_MAX_X;
    model->trans.y = FIELD_GIMMICK_LANE_TRAINS_TRAIN_Y;
    model->trans.z = FIELD_GIMMICK_LANE_TRAINS_WEST_TRACK_Z;
    sinValue = FX_SinCosTable_[0x1800];
    cosWest = FX_SinCosTable_[0x1801];
    func_0207AF1C(&model->rotate, sinValue, cosWest);
    FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, leadModel + 2, 1);

    model = FLD_EXP_OBJ_GetModelStatus(expObj, 0, (u16)(trailModel + 2));
    model->trans.x = FIELD_GIMMICK_LANE_TRAINS_TRACK_MAX_X + FIELD_GIMMICK_LANE_TRAINS_TRAIL_GAP;
    model->trans.y = FIELD_GIMMICK_LANE_TRAINS_TRAIN_Y;
    model->trans.z = FIELD_GIMMICK_LANE_TRAINS_WEST_TRACK_Z;
    func_0207AF1C(&model->rotate, sinValue, cosWest);
    FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, trailModel + 2, 1);
}
