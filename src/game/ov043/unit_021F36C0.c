/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: GIMMICK43_Init, GIMMICK43_Exit, GIMMICK43_Update, GIMMICK43_CallLiftEvent, GIMMICK43_CallElevatorEvent, GIMMICK43_LiftEventMain, GIMMICK43_ElevatorEventMain, GIMMICK43_IsLiftArrived, GIMMICK43_IsInLiftZone, GIMMICK43_ShowLiftAnime, GIMMICK43_GetLiftAnimeIndex, GIMMICK43_UpdateBigLift, GIMMICK43_ShowElevatorIdleAnime, GIMMICK43_StartCameraShake, GIMMICK43_UpdateCameraShake
 * address:  0x021F36C0
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sGimmick43FixedHeightAreas     0x021F4510  data  a4
 *   sGimmick43LiftZones     0x021F4480  data  a4
 *   sGimmick43ExpObjUnitDesc     0x021F4318  data  a4
 *   sGimmick43LiftStartPos     0x021F4358  data  a4
 *   sGimmick43ElevatorStartPos     0x021F434C  data  a4
 *   sGimmick43ObstacleStartPos     0x021F4340  data  a4
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetFog  0x02188C64  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_G3D_MAPPER_GetHeightEx  0x0218CEE0  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   HEIGHT_EX_SetArea  0x021C0628  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeLastFrame  0x021BE748  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_FOG_SetOffset  0x021A01BC  thumb  ov021
 *   FIELD_FOG_SetSlope  0x021A01B4  thumb  ov021
 *   sub_02030344   0x02030344  arm
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   FLD_EXP_OBJ_RemoveUnit 0x021BE418 thumb ov021
 *   FLD_EXP_OBJ_UpdateAnimes 0x021BE580 thumb ov021
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   sGimmick43LiftHeights    0x021F4490  data  a4
 *   func_020124E4  0x020124E4  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_GetPosPtr  0x0216D888  thumb  ov010
 *   FLDMMDL_SetGridNowY  0x0216D85C  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   HEIGHT_EX_SetAreaHeight  0x021C06C0  thumb  ov021
 *   FIELD_FOG_FADE_IsFade  0x021A0244  thumb  ov021
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_SetTraceTarget  0x0218EC30  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   sGimmick43LiftAnimeFlip     0x021F4328  data  ov043
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   FIELDMAP_GetZoneFog  0x02188C68  thumb  ov021
 *   FIELD_ZONEFOG_GetFogOffset  0x021A03A4  thumb  ov021
 *   FIELD_ZONEFOG_GetFogSlope  0x021A03B8  thumb  ov021
 *   FIELD_FOG_FADE_Init  0x021A01FC  thumb  ov021
 *   FIELD_CAMERA_GetTargetShift  0x0218ECC4  thumb  ov021
 *   FIELD_CAMERA_SetTargetShift  0x0218ECD4  thumb  ov021
 */
#include "unit_021F36C0_types.h"

struct GameData;
struct FieldSave;
struct GameEvent;

extern void *FIELDMAP_GetExpObj(void *fieldMap);
extern void *FIELDMAP_GetFog(void *fieldMap);
extern void *FIELDMAP_GetGameSystem(void *fieldMap);
extern u16 FIELDMAP_GetHeapId(u8 *fieldMap);
extern void *FIELDMAP_GetG3dMapper(void *fieldMap);
extern void *FIELDMAP_GetFieldPlayer(void *fieldMap);
extern void *FIELD_G3D_MAPPER_GetHeightEx(void *g3dMapper);
extern void *FIELDMAP_AllocCommonWork(unsigned char *fieldMap, int id, int a, int size);
extern void *GAMESYSTEM_GetGameData(void *gameSystem);
extern struct FieldSave *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern Gimmick43Save *GIMMICK_WORK_GetSaveArea(struct FieldSave *fieldSave, u32 blockId);
extern void  HEIGHT_EX_SetArea(u8 areaId, int tileX, int tileZ, int width, int depth, int height, int c, void *heightEx);
extern void  FLD_EXP_OBJ_AddUnitFromArchive(void *expObj, void *unitDesc, int b);
extern VecFx32 *FLD_EXP_OBJ_GetModelStatus(void *expObj, unsigned unit, u16 model);
extern void FLD_EXP_OBJ_SetModelCullDraw(void *expObj, int unit, int model, int visible);
extern void *FLD_EXP_OBJ_GetAnime(void *expObj, int unit, u16 model, u16 animeIdx);
extern void FLD_EXP_OBJ_SetAnimeLoop(unsigned char *anime, int loop);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *anime, int paused);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *expObj, int unit, u16 model, u16 animeIdx, int enabled);
extern int FLD_EXP_OBJ_GetAnimeLastFrame(void *anime);
extern void FLD_EXP_OBJ_SetAnimeFrame(void *expObj, int unit, int model, int animeIdx, int frame);
extern void FIELD_PLAYER_GetPos(unsigned char *player, VecFx32 *out);
extern int   FIELD_FOG_SetOffset(void *fog, u32 offset);
extern int   FIELD_FOG_SetSlope(void *fog, u32 slope);
extern void *sub_02030344(u32 heapId);
extern void *FIELDMAP_GetCommonWork(void *fieldMap, int id);
extern void FIELDMAP_FreeCommonWork(void *fieldMap, int id);
extern void FLD_EXP_OBJ_RemoveUnit(u8 *expObj, u16 unit);
extern void FLD_EXP_OBJ_UpdateAnimes(void *expObj);
extern void *GAMESYSTEM_GetFieldMap(void *gameSystem);
extern struct GameEvent *func_020122C0(void *owner, void *a, void *eventFunc, u32 size);
extern void *func_020124E4(void *event);
extern void *FIELDMAP_GetCamera(void *fieldMap);
extern void *FIELDMAP_GetMmdlSys(unsigned char *fieldMap);
extern int FLDMMDL_SysSearchUseMmdl(void *mmdlSys, void **out, int *iter);
extern int FLDMMDL_GetGridNowX(void *mmdl);
extern int FLDMMDL_GetGridNowZ(void *mmdl);
extern void FLDMMDL_GetPos(void *mmdl, VecFx32 *out);
extern VecFx32 *FLDMMDL_GetPosPtr(void *mmdl);
extern void FLDMMDL_SetGridNowY(void *mmdl, int gridY);
extern void FLDMMDL_SetPos(void *mmdl, VecFx32 *pos);
extern void FIELD_CAMERA_EndDelay(u8 *camera);
extern u32 FIELD_CAMERA_IsDelayEnabled(u8 *camera);
extern void FIELD_CAMERA_RestartDelay(unsigned char *camera);
extern void func_020061E4(u32 seId);
extern int FLD_EXP_OBJ_IsAnimeStopped(void *anime);
extern void HEIGHT_EX_SetAreaHeight(u8 areaId, int height, void *heightEx);
extern int FIELD_FOG_FADE_IsFade(void *fog);
extern u32 FIELD_CAMERA_GetTraceTarget(u8 *camera);
extern void FIELD_CAMERA_StopTargetTrace(u8 *camera);
extern void FIELD_CAMERA_SetTraceTarget(u8 *camera, int target);
extern void FIELD_PLAYER_SetPos(u8 *player, VecFx32 *pos);
extern int GFL_USE_GetSeSlot(u32 seId);
extern void func_020061F8(int slot);
extern void *FIELDMAP_GetZoneFog(void *fieldMap);
extern int FIELD_ZONEFOG_GetFogOffset(void *zoneFog);
extern int FIELD_ZONEFOG_GetFogSlope(void *zoneFog);
extern void FIELD_FOG_FADE_Init(void *fog, u32 offset, u32 slope, u32 frames);
extern void FIELD_CAMERA_GetTargetShift(u8 *camera, VecFx32 *out);
extern void FIELD_CAMERA_SetTargetShift(u8 *camera, VecFx32 *shift);
void GIMMICK43_Init(void *fieldMap);
void GIMMICK43_Exit(u8 *fieldMap);
void GIMMICK43_Update(u8 *fieldMap);
void *GIMMICK43_CallLiftEvent(void *gameSystem, int liftIndex);
void GIMMICK43_CallElevatorEvent(void *gameSystem, int isRising);
int GIMMICK43_LiftEventMain(void *event, int *seq);
int GIMMICK43_ElevatorEventMain(void *event, int *seq);
int GIMMICK43_IsLiftArrived(Gimmick43Work *work);
int GIMMICK43_IsInLiftZone(u8 liftIndex, int tileX, int tileZ);
void GIMMICK43_ShowLiftAnime(Gimmick43Save *save, void *expObj, int liftIndex);
int GIMMICK43_GetLiftAnimeIndex(Gimmick43Save *save, int liftIndex);
void GIMMICK43_UpdateBigLift(void *gameSystem);
void GIMMICK43_ShowElevatorIdleAnime(void *expObj);
void GIMMICK43_StartCameraShake(u8 liftIndex, int stepY, int isStart, u8 *camera, CameraShake *shake);
int GIMMICK43_UpdateCameraShake(CameraShake *shake);
extern const HeightRegion sGimmick43FixedHeightAreas[];
extern const LiftZone sGimmick43LiftZones[];
extern int sGimmick43ExpObjUnitDesc;
extern const VecFx32 sGimmick43LiftStartPos[];
extern const VecFx32 sGimmick43ElevatorStartPos;
extern const VecFx32 sGimmick43ObstacleStartPos;
extern LiftHeights sGimmick43LiftHeights[];
extern int sGimmick43LiftAnimeFlip[];




void GIMMICK43_Init(void *fieldMap)
{
    void *expObj;
    Gimmick43Save *save;
    void *fog;
    void *heightEx;
    VecFx32 *modelPos;
    void *anime;
    int i;
    int animeIdx;
    u8 state;
    u8 areaId;
    VecFx32 playerPos;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    fog = FIELDMAP_GetFog(fieldMap);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK43_SAVE_BLOCK);
    FIELDMAP_AllocCommonWork(fieldMap, 1, FIELDMAP_GetHeapId(fieldMap), sizeof(Gimmick43Work));
    heightEx = FIELD_G3D_MAPPER_GetHeightEx(FIELDMAP_GetG3dMapper(fieldMap));
    for (i = 0; i < GIMMICK43_FIXED_AREA_COUNT; i++) {
        HEIGHT_EX_SetArea(i, sGimmick43FixedHeightAreas[i].tileX, sGimmick43FixedHeightAreas[i].tileZ, sGimmick43FixedHeightAreas[i].width,
                      sGimmick43FixedHeightAreas[i].depth, sGimmick43FixedHeightAreas[i].height, 0x800000, heightEx);
    }
    for (i = 0; i < GIMMICK43_LIFT_COUNT; i++) {
        areaId = i + 8;
        if (save->liftState[i] != 0) {
            state = 1;
        } else {
            state = 0;
        }
        HEIGHT_EX_SetArea(areaId, sGimmick43LiftZones[i].tileX, sGimmick43LiftZones[i].tileZ, sGimmick43LiftZones[i].width,
                      sGimmick43LiftZones[i].depth, sGimmick43LiftZones[i].height[state], 0x800000, heightEx);
    }
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, &sGimmick43ExpObjUnitDesc, 0);
    for (i = 0; i < GIMMICK43_LIFT_COUNT; i++) {
        modelPos = FLD_EXP_OBJ_GetModelStatus(expObj, 0, i);
        *modelPos = sGimmick43LiftStartPos[i];
        state = save->liftState[i] ? 1 : 0;
        modelPos->y = sGimmick43LiftZones[i].height[state];
        FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, (u16)i, 1);
        for (animeIdx = 0; animeIdx < 2; animeIdx++) {
            anime = FLD_EXP_OBJ_GetAnime(expObj, 0, i, animeIdx);
            FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
            FLD_EXP_OBJ_SetAnimePaused(anime, 1);
        }
        GIMMICK43_ShowLiftAnime(save, expObj, i);
    }
    modelPos = FLD_EXP_OBJ_GetModelStatus(expObj, 0, GIMMICK43_ELEVATOR);
    *modelPos = sGimmick43ElevatorStartPos;
    FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, (u16)GIMMICK43_ELEVATOR, 1);
    for (animeIdx = 0; animeIdx < 2; animeIdx++) {
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, GIMMICK43_ELEVATOR, animeIdx);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 1);
    }
    GIMMICK43_ShowElevatorIdleAnime(expObj);
    modelPos = FLD_EXP_OBJ_GetModelStatus(expObj, 0, GIMMICK43_OBSTACLE);
    *modelPos = sGimmick43ObstacleStartPos;
    FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, (u16)GIMMICK43_OBSTACLE, 1);
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, GIMMICK43_OBSTACLE, 0, 1);
    anime = FLD_EXP_OBJ_GetAnime(expObj, 0, GIMMICK43_OBSTACLE, 0);
    FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
    FLD_EXP_OBJ_SetAnimePaused(anime, 1);
    if (save->obstacleBroken) {
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, GIMMICK43_OBSTACLE, 0, FLD_EXP_OBJ_GetAnimeLastFrame(anime));
    }
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos);
    if (playerPos.y <= -0x280000) {
        FIELD_FOG_SetOffset(fog, 0x7FDF);
        FIELD_FOG_SetSlope(fog, 9);
    }
    sub_02030344(0x15);
}



void GIMMICK43_Exit(u8 *fieldMap)
{
    void *expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_GetCommonWork(fieldMap, 1);
    FIELDMAP_FreeCommonWork(fieldMap, 1);
    FLD_EXP_OBJ_RemoveUnit(expObj, 0);
}



void GIMMICK43_Update(u8 *fieldMap)
{
    void *expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_GetCommonWork(fieldMap, 1);
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK43_SAVE_BLOCK);
    FLD_EXP_OBJ_UpdateAnimes(expObj);
}




void *GIMMICK43_CallLiftEvent(void *gameSystem, int liftIndex)
{
    void *fieldMap;
    Gimmick43Save *save;
    Gimmick43Work *work;
    int step;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK43_SAVE_BLOCK);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    if (liftIndex >= GIMMICK43_LIFT_COUNT) {
        return 0;
    }
    work->liftIndex = liftIndex;
    if (save->liftState[liftIndex] != 0) {
        work->curY = sGimmick43LiftHeights[liftIndex].y[1];
        work->goalY = sGimmick43LiftHeights[liftIndex].y[0];
    } else {
        work->curY = sGimmick43LiftHeights[liftIndex].y[0];
        work->goalY = sGimmick43LiftHeights[liftIndex].y[1];
    }
    if (liftIndex == GIMMICK43_BIG_LIFT) {
        step = 0x8000;
        work->isFogCheckPending = 1;
    } else {
        step = 0x4000;
        work->isFogCheckPending = 0;
    }
    if (work->goalY - work->curY < 0) {
        work->stepY = -step;
    } else {
        work->stepY = step;
    }
    work->obstacleAnimeState = 0;
    return func_020122C0(gameSystem, 0, GIMMICK43_LiftEventMain, 0);
}




void GIMMICK43_CallElevatorEvent(void *gameSystem, int isRising)
{
    void *fieldMap;
    Gimmick43Work *work;
    void *expObj;
    int step;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK43_SAVE_BLOCK);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    work->isRising = isRising;
    if (isRising) {
        work->curY = 0x320000;
        work->goalY = 0x370000;
    } else {
        work->curY = 0x370000;
        work->goalY = 0x320000;
        expObj = FIELDMAP_GetExpObj(fieldMap);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, GIMMICK43_ELEVATOR, 1, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, GIMMICK43_ELEVATOR, 0, 0);
    }
    step = work->goalY - work->curY;
    if (step < 0) {
        step = -0x2000;
    } else {
        step = 0x2000;
    }
    work->stepY = step;
    func_020122C0(gameSystem, 0, GIMMICK43_ElevatorEventMain, 0);
}




int GIMMICK43_LiftEventMain(void *event, int *seq)
{
    VecFx32 playerPos;
    VecFx32 mmdlPos;
    VecFx32 ridePos;
    int iter;
    void *mmdl;
    void *gameSystem;
    void *fieldMap;
    void *expObj;
    Gimmick43Work *work;
    u8 *camera;
    Gimmick43Save *save;
    void *mmdlSys;
    int riderCount;
    int i;
    int tileX;
    int tileZ;
    void *rider;
    int animeIdx;
    int becameOn;
    void *anime;
    void *heightEx;

    gameSystem = func_020124E4(event);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    camera = FIELDMAP_GetCamera(fieldMap);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK43_SAVE_BLOCK);
    switch (*seq) {
    case 0:
        riderCount = 0;
        iter = 0;
        mmdlSys = FIELDMAP_GetMmdlSys(fieldMap);
        for (i = 0; i < GIMMICK43_RIDER_MAX; i++) {
            work->riders[i] = 0;
        }
        FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos);
        while (FLDMMDL_SysSearchUseMmdl(mmdlSys, &mmdl, &iter) == 1) {
            tileX = FLDMMDL_GetGridNowX(mmdl);
            tileZ = FLDMMDL_GetGridNowZ(mmdl);
            if (GIMMICK43_IsInLiftZone(work->liftIndex, tileX, tileZ)) {
                FLDMMDL_GetPos(mmdl, &mmdlPos);
                if (playerPos.y - 0x10000 < mmdlPos.y && mmdlPos.y < playerPos.y + 0x10000 && riderCount < GIMMICK43_RIDER_MAX) {
                    work->riders[riderCount++] = mmdl;
                }
            }
        }
        GIMMICK43_StartCameraShake(work->liftIndex, work->stepY, 1, camera, &work->shake);
        (*seq)++;
        break;
    case 1:
        if (GIMMICK43_UpdateCameraShake(&work->shake)) {
            (*seq)++;
        }
        break;
    case 2:
        FIELD_CAMERA_EndDelay(camera);
        (*seq)++;
        break;
    case 3:
        if (FIELD_CAMERA_IsDelayEnabled(camera) != 0) {
            break;
        }
        func_020061E4(0x6ca);
        (*seq)++;
    case 4:
        if (work->isStalled == 0) {
            work->curY += work->stepY;
        }
        if (GIMMICK43_IsLiftArrived(work)) {
            work->curY = work->goalY;
            GIMMICK43_StartCameraShake(work->liftIndex, work->stepY, 0, camera, &work->shake);
            func_020061E4(0x6cb);
            (*seq)++;
        }
        FLD_EXP_OBJ_GetModelStatus(expObj, 0, work->liftIndex)->y = work->curY;
        for (i = 0; i < GIMMICK43_RIDER_MAX; i++) {
            rider = work->riders[i];
            if (rider != 0) {
                ridePos = *FLDMMDL_GetPosPtr(rider);
                ridePos.y = work->curY;
                FLDMMDL_SetGridNowY(rider, (s16)((ridePos.y >> 4) / 4096));
                FLDMMDL_SetPos(rider, &ridePos);
            }
        }
        break;
    case 5:
        if (GIMMICK43_UpdateCameraShake(&work->shake)) {
            (*seq)++;
        }
        break;
    case 6:
        FIELD_CAMERA_RestartDelay(camera);
        animeIdx = work->liftIndex;
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, (u16)animeIdx, (u16)GIMMICK43_GetLiftAnimeIndex(save, animeIdx)), 0);
        (*seq)++;
        break;
    case 7:
        animeIdx = work->liftIndex;
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, (u16)animeIdx, (u16)GIMMICK43_GetLiftAnimeIndex(save, animeIdx));
        becameOn = 0;
        if (FLD_EXP_OBJ_IsAnimeStopped(anime) == 0) {
            break;
        }
        if (save->liftState[work->liftIndex]) {
            save->liftState[work->liftIndex] = 0;
        } else {
            save->liftState[work->liftIndex] = 1;
            becameOn = 1;
        }
        heightEx = FIELD_G3D_MAPPER_GetHeightEx(FIELDMAP_GetG3dMapper(fieldMap));
        HEIGHT_EX_SetAreaHeight(work->liftIndex + 8, sGimmick43LiftHeights[work->liftIndex].y[becameOn], heightEx);
        GIMMICK43_ShowLiftAnime(save, expObj, work->liftIndex);
        if (work->liftIndex != GIMMICK43_BIG_LIFT) {
            return 1;
        }
        (*seq)++;
        break;
    case 8:
        if (FIELD_FOG_FADE_IsFade(FIELDMAP_GetFog(fieldMap)) == 0) {
            return 1;
        }
        break;
    }
    GIMMICK43_UpdateBigLift(gameSystem);
    return 0;
}




int GIMMICK43_ElevatorEventMain(void *event, int *seq)
{
    void *fieldMap;
    void *expObj;
    Gimmick43Work *work;
    u8 *camera;
    void *player;
    VecFx32 pos;

    fieldMap = GAMESYSTEM_GetFieldMap(func_020124E4(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    camera = FIELDMAP_GetCamera(fieldMap);
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK43_SAVE_BLOCK);
    switch (*seq) {
    case 0:
        if (work->isRising != 0) {
            work->savedCameraTarget = FIELD_CAMERA_GetTraceTarget(camera);
            FIELD_CAMERA_StopTargetTrace(camera);
        }
        func_020061E4(work->isRising == 0 ? 0x6da : 0x6ca);
        (*seq)++;
        break;
    case 1:
        work->curY += work->stepY;
        if (GIMMICK43_IsLiftArrived(work)) {
            work->curY = work->goalY;
            if (work->isRising == 0) {
                GIMMICK43_StartCameraShake(0xff, work->stepY, 0, camera, &work->shake);
                func_020061E4(0x6cb);
            }
            (*seq)++;
        }
        FLD_EXP_OBJ_GetModelStatus(expObj, 0, GIMMICK43_ELEVATOR)->y = work->curY;
        player = FIELDMAP_GetFieldPlayer(fieldMap);
        FIELD_PLAYER_GetPos(player, &pos);
        pos.y = work->curY;
        FIELD_PLAYER_SetPos(player, &pos);
        break;
    case 2:
        if (work->isRising != 0) {
            return 1;
        }
        if (GIMMICK43_UpdateCameraShake(&work->shake)) {
            if (work->savedCameraTarget != 0) {
                FIELD_CAMERA_SetTraceTarget(camera, work->savedCameraTarget);
            }
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, GIMMICK43_ELEVATOR, 1), 0);
            (*seq)++;
        }
        break;
    case 3:
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, GIMMICK43_ELEVATOR, 1))) {
            GIMMICK43_ShowElevatorIdleAnime(expObj);
            return 1;
        }
        break;
    }
    return 0;
}



int GIMMICK43_IsLiftArrived(Gimmick43Work *work)
{
    if (work->stepY < 0) {
        if (work->goalY >= work->curY) {
            return 1;
        }
    } else {
        if (work->goalY <= work->curY) {
            return 1;
        }
    }
    return 0;
}




/*
 * Unlabelled leaf called only from GIMMICK43_LiftEventMain. Each field gets its own
 * pool word (sGimmick43LiftZones + 0/8/4/C). The loads must be written in field
 * order tileX, tileZ, width, depth: loading width before tileZ swaps the
 * index and value registers (17 bytes).
 */
int GIMMICK43_IsInLiftZone(u8 liftIndex, int tileX, int tileZ)
{
    int x0;
    int z0;
    int width;
    int depth;

    x0 = sGimmick43LiftZones[liftIndex].tileX;
    z0 = sGimmick43LiftZones[liftIndex].tileZ;
    width = sGimmick43LiftZones[liftIndex].width;
    depth = sGimmick43LiftZones[liftIndex].depth;
    if (x0 <= tileX && tileX <= x0 + width - 1 && z0 <= tileZ && tileZ <= z0 + depth - 1) {
        return 1;
    }
    return 0;
}




void GIMMICK43_ShowLiftAnime(Gimmick43Save *save, void *expObj, int liftIndex)
{
    int shownAnime, hiddenAnime;

    if (save->liftState[liftIndex]) {
        if (sGimmick43LiftAnimeFlip[liftIndex]) {
            shownAnime = 0;
            hiddenAnime = 1;
        } else {
            shownAnime = 1;
            hiddenAnime = 0;
        }
    } else {
        if (sGimmick43LiftAnimeFlip[liftIndex]) {
            shownAnime = 1;
            hiddenAnime = 0;
        } else {
            shownAnime = 0;
            hiddenAnime = 1;
        }
    }
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, liftIndex, shownAnime, 1);
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, liftIndex, hiddenAnime, 0);
    FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, (u16)liftIndex, (u16)shownAnime, 0);
    FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, liftIndex, shownAnime), 1);
}




int GIMMICK43_GetLiftAnimeIndex(Gimmick43Save *save, int liftIndex)
{
    int animeIdx;

    if (save->liftState[liftIndex]) {
        if (sGimmick43LiftAnimeFlip[liftIndex]) {
            animeIdx = 0;
        } else {
            animeIdx = 1;
        }
    } else {
        if (sGimmick43LiftAnimeFlip[liftIndex]) {
            animeIdx = 1;
        } else {
            animeIdx = 0;
        }
    }
    return animeIdx;
}




/*
 * FIELDMAP_GetFog's result is bound to zoneFog before the A01FC call: passed inline,
 * the ternary fourth argument is evaluated before the call.
 */
void GIMMICK43_UpdateBigLift(void *gameSystem)
{
    void *fieldMap;
    void *expObj;
    Gimmick43Work *work;
    u8 *camera;
    Gimmick43Save *save;
    int hasFogTarget;
    void *zoneFog;
    int fogOffset;
    int fogSlope;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    camera = FIELDMAP_GetCamera(fieldMap);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK43_SAVE_BLOCK);
    if (work->liftIndex != GIMMICK43_BIG_LIFT) {
        return;
    }
    if (save->obstacleBroken == 0 && work->curY <= -0x230000) {
        save->obstacleBroken = 1;
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, GIMMICK43_OBSTACLE, 0), 0);
        func_020061E4(0x6cd);
        work->curY = -0x230000;
        work->isStalled = 1;
        work->stallFrames = 0;
        work->stallStage = 0;
        work->obstacleAnimeState = 1;
    }
    if (work->isStalled != 0) {
        switch (work->stallStage) {
        case 0:
            GIMMICK43_StartCameraShake(work->liftIndex, work->stepY, 0, camera, &work->shake);
            func_020061E4(0x6cb);
            work->stallStage++;
            break;
        case 1:
            if (GIMMICK43_UpdateCameraShake(&work->shake)) {
                work->stallFrames++;
                if (work->stallFrames >= 100) {
                    work->stepY = -0x2000;
                    work->isStalled = 0;
                    func_020061E4(0x6ca);
                }
            }
            break;
        }
    }
    if (work->isFogCheckPending != 0) {
        hasFogTarget = 0;
        if (work->stepY >= 0) {
            if (work->curY >= -0x2a0000) {
                zoneFog = FIELDMAP_GetZoneFog(fieldMap);
                hasFogTarget = 1;
                fogOffset = FIELD_ZONEFOG_GetFogOffset(zoneFog);
                fogSlope = FIELD_ZONEFOG_GetFogSlope(zoneFog);
            }
        } else {
            if (work->curY <= -0x310000) {
                hasFogTarget = 1;
                fogOffset = 0x7fdf;
                fogSlope = 9;
            }
        }
        if (hasFogTarget) {
            zoneFog = FIELDMAP_GetFog(fieldMap);
            FIELD_FOG_FADE_Init(zoneFog, fogOffset, fogSlope, work->stepY == -0x2000 ? 0x20 : 0x10);
            work->isFogCheckPending = 0;
        }
    }
    if (work->obstacleAnimeState != 0) {
        if (work->obstacleAnimeState == 1) {
            work->obstacleAnimeState = 2;
            return;
        }
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, GIMMICK43_OBSTACLE, 0))) {
            func_020061F8(GFL_USE_GetSeSlot(0x6cd));
            work->obstacleAnimeState = 0;
        }
    }
}




void GIMMICK43_ShowElevatorIdleAnime(void *expObj)
{
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, GIMMICK43_ELEVATOR, 0, 1);
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, GIMMICK43_ELEVATOR, 1, 0);
    FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, GIMMICK43_ELEVATOR, 0, 0);
    expObj = FLD_EXP_OBJ_GetAnime(expObj, 0, GIMMICK43_ELEVATOR, 0);
    FLD_EXP_OBJ_SetAnimePaused(expObj, 1);
}




void GIMMICK43_StartCameraShake(u8 liftIndex, int stepY, int isStart, u8 *camera, CameraShake *shake)
{
    shake->phase = 0;
    shake->count = 0;
    shake->camera = camera;
    shake->savedCameraTarget = FIELD_CAMERA_GetTraceTarget(camera);
    FIELD_CAMERA_GetTargetShift(camera, &shake->savedShift);
    if (isStart) {
        shake->amplitude = 0x1000;
        shake->halfCycles = 2;
    } else {
        if (liftIndex == GIMMICK43_BIG_LIFT) {
            shake->amplitude = 0x4000;
        } else {
            shake->amplitude = 0x2000;
        }
        shake->halfCycles = 4;
    }
    if (stepY < 0) {
        shake->amplitude *= -1;
    }
}




int GIMMICK43_UpdateCameraShake(CameraShake *shake)
{
    VecFx32 shift;

    switch (shake->phase) {
    case 0:
        FIELD_CAMERA_StopTargetTrace(shake->camera);
        shake->phase++;
    case 1:
        if (shake->frameParity % 2 == 0) {
            FIELD_CAMERA_GetTargetShift(shake->camera, &shift);
            shift.y = shift.y + shake->amplitude;
            FIELD_CAMERA_SetTargetShift(shake->camera, &shift);
            shake->amplitude *= -1;
            shake->count++;
            if (shake->count >= shake->halfCycles * 2) {
                if (shake->savedCameraTarget) {
                    FIELD_CAMERA_SetTraceTarget(shake->camera, shake->savedCameraTarget);
                }
                FIELD_CAMERA_SetTargetShift(shake->camera, &shake->savedShift);
                return 1;
            }
        }
        shake->frameParity = (shake->frameParity + 1) % 2;
    }
    return 0;
}
