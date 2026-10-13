/*
 * file:     field_gimmick_cannons.c
 * unit:     yes
 * function: FIELD_GIMMICK_CANNONS_Init, FIELD_GIMMICK_CANNONS_Exit, FIELD_GIMMICK_CANNONS_Update, FIELD_GIMMICK_CANNONS_CreateLaunchEvent, FIELD_GIMMICK_CANNONS_EventLaunch, FIELD_GIMMICK_CANNONS_FindCannonAt, FIELD_GIMMICK_CANNONS_GetFirstAnimeSlot, FIELD_GIMMICK_CANNONS_FacingToRingIndex, FIELD_GIMMICK_CANNONS_TurnRingDirection, FIELD_GIMMICK_CANNONS_GetCannonDirection, FIELD_GIMMICK_CANNONS_StartBounce, FIELD_GIMMICK_CANNONS_ResetBounce, FIELD_GIMMICK_CANNONS_UpdateBounce
 * address:  0x021F36C0
 * region:   ov041
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gCannonsUnitSetup     0x021F40A4  data  a4
 *   gCannonsCannonPos     0x021F4208  data  a4
 *   gCannonsCannonQuarterTurns     0x021F4660  data  a1
 *   FX_SinCosTable_     0x020A1B38  data  a2
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   func_0207AF1C  0x0207AF1C  thumb
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   FLD_EXP_OBJ_RemoveUnit 0x021BE418 thumb ov021
 *   FLD_EXP_OBJ_UpdateAnimes 0x021BE580 thumb ov021
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   FIELD_GIMMICK_CANNONS_UpdateBounce  0x021F4000  thumb  ov041
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeFrame  0x021BE6E8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   FIELD_CAMERA_PushState  0x0218F818  thumb  ov021
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   FIELD_CAMERA_StartMove  0x0218F900  thumb  ov021
 *   FIELD_CAMERA_IsMoving  0x0218FE50  thumb  ov021
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 *   FIELD_CAMERA_PopState  0x0218F878  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_GetEyeRaw  0x0218ECE4  thumb  ov021
 *   FIELD_CAMERA_StartFreeMove  0x0218F930  thumb  ov021
 *   FIELD_CAMERA_GetMoveGoal  0x0218FE70  thumb  ov021
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 *   FIELD_CAMERA_StartMoveToSaved  0x0218F9C4  thumb  ov021
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   ICA_ANIME_CreateWithFullBuffer  0x02011428  thumb
 *   ICA_ANIME_GetFrameNum  0x02011608  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   ICA_ANIME_Delete  0x02011558  thumb
 *   ICA_ANIME_GetTranslateAt  0x02011688  thumb
 *   gCannonsFlights     0x021F4320  data  a4
 *   gCannonsCameraInfos     0x021F4198  data  a2
 *   gCannonsCannonCells     0x021F40F0  data  a2
 *   gCannonsFireSeFrames     0x021F4084  data  a2
 *   gCannonsFireDoneFrames     0x021F408C  data  a2
 *   gCannonsLandingFrames     0x021F4094  data  a2
 *   gCannonsFlightStartFrames     0x021F409C  data  a2
 *   gCannonsLandSeFramesBeforeEnd     0x021F40B4  data  a2
 *   gCannonsDirectionRing     0x021F4080  data  a1
 *   FIELD_CAMERA_SetEyeRaw  0x0218ECF4  thumb  ov021
 */
#include "../ov021/fld_exp_obj_types.h"
#include "field_gimmick_cannons_types.h"

typedef signed short s16;

/*
 * Same layout as FieldCameraView, FieldCameraMoveChannels and
 * FieldCameraMoveRequest (ov021/field_camera_types.h), which cannot be
 * included here: it and the expansion object types both define VecFx32.
 */
typedef struct FieldGimmickCannonsCameraView {
    VecFx32 eye;
    VecFx32 target;
    VecFx32 shift;
    u16 pitch;
    u16 yaw;
    int distance;
    u16 fov;
    u16 reserved;
} FieldGimmickCannonsCameraView;

typedef struct FieldGimmickCannonsCameraChannels {
    u32 shift;
    u32 pitch;
    u32 yaw;
    u32 distance;
    u32 fov;
    u32 target;
} FieldGimmickCannonsCameraChannels;

typedef struct FieldGimmickCannonsCameraRequest {
    FieldGimmickCannonsCameraView goal;
    FieldGimmickCannonsCameraChannels channels;
} FieldGimmickCannonsCameraRequest;

/* Cannon positions: the table is read in full. */
typedef struct FieldGimmickCannonsPosTable {
    VecFx32 pos[FIELD_GIMMICK_CANNONS_CANNON_COUNT];
} FieldGimmickCannonsPosTable;

typedef struct FieldGimmickCannonsDirTable {
    u8 direction[FIELD_GIMMICK_CANNONS_DIRECTION_COUNT];
} FieldGimmickCannonsDirTable;

extern FldExpObjCnt *FIELDMAP_GetExpObj(struct FieldMap *fieldMap);
extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern void *FIELDMAP_AllocCommonWork(struct FieldMap *fieldMap, int id, int heapId, int size);
extern void FIELDMAP_FreeCommonWork(struct FieldMap *fieldMap, int id);
extern void *FIELDMAP_GetCommonWork(struct FieldMap *fieldMap, int id);
extern struct GameSystem *FIELDMAP_GetGameSystem(struct FieldMap *fieldMap);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct GimmickWork *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern void *GIMMICK_WORK_GetSaveArea(struct GimmickWork *gimmickWork, u32 gimmickId);
extern struct FieldMap *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent,
                                       GameEventFunc func, u32 workSize);
extern void FLD_EXP_OBJ_RemoveUnit(FldExpObjCnt *expObj, u16 unitIndex);
extern G3dObjectStatus *FLD_EXP_OBJ_GetModelStatus(FldExpObjCnt *expObj, unsigned unitIndex, int modelIndex);
extern void FLD_EXP_OBJ_SetModelCullDraw(FldExpObjCnt *expObj, int unitIndex, u16 modelIndex, int cullDraw);
extern void FLD_EXP_OBJ_UpdateAnimes(FldExpObjCnt *expObj);
extern FldExpObjAnime *FLD_EXP_OBJ_GetAnime(FldExpObjCnt *expObj, int unitIndex, unsigned modelIndex, int animeIndex);
extern void FLD_EXP_OBJ_SetAnimePaused(FldExpObjAnime *anime, int paused);
extern void FLD_EXP_OBJ_SetAnimeLoop(FldExpObjAnime *anime, int loop);
extern void FLD_EXP_OBJ_SetAnimeFrame(FldExpObjCnt *expObj, int unitIndex, u16 modelIndex, u16 animeIndex, int frame);
extern int FLD_EXP_OBJ_GetAnimeFrame(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int animeIndex);
extern void FLD_EXP_OBJ_SetAnimeEnabled(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int animeIndex, int enable);
extern void FLD_EXP_OBJ_AddUnitFromArchive(FldExpObjCnt *expObj, const G3dUtilSetup *setup, u16 unitIndex);
extern void func_0207AF1C(void *matrix, int sin, int cos);
extern void FIELD_PLAYER_GetPos(struct FieldPlayer *player, VecFx32 *out);
extern void FIELD_PLAYER_SetPos(struct FieldPlayer *player, const VecFx32 *pos);
extern u16 FIELD_PLAYER_GetDirDisp(struct FieldPlayer *player);
extern struct Mmdl *FIELD_PLAYER_GetMmdl(struct FieldPlayer *player);
extern void FLDMMDL_SetStatusBitVanish(struct Mmdl *mmdl, int flag);
extern u32 *FLDMMDL_SetStatusBit(struct Mmdl *mmdl, u32 bit);
extern struct Mmdl *FLDMMDL_SetMoveBit(struct Mmdl *mmdl, u32 bit);
extern u32 *FLDMMDL_ClearStatusBit(struct Mmdl *mmdl, u32 bit);
extern char *FLDMMDL_ClearMoveBit(struct Mmdl *mmdl, u32 bit);
extern u32 FLDMMDL_CheckMoveBit(struct Mmdl *mmdl, u32 bit);
extern int SCRIPT_SYS_CallScriptEvent(struct GameEvent *event, u16 scriptId, int arg1, int arg2, u16 heapId);
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);
extern struct IcaAnime *ICA_ANIME_CreateWithFullBuffer(u32 heapId, u32 arcId, u32 dataId, void *buffer, u32 bufferSize);
extern u32 ICA_ANIME_GetFrameNum(struct IcaAnime *anime);
extern void ICA_ANIME_Delete(struct IcaAnime *anime);
extern u32 ICA_ANIME_GetTranslateAt(struct IcaAnime *anime, VecFx32 *out, u32 frame);
extern void FIELD_CAMERA_EndDelay(struct FieldCamera *camera);
extern u32 FIELD_CAMERA_IsDelayEnabled(struct FieldCamera *camera);
extern void FIELD_CAMERA_PushState(struct FieldCamera *camera);
extern void FIELD_CAMERA_PopState(struct FieldCamera *camera);
extern void FIELD_CAMERA_RestartDelay(struct FieldCamera *camera);
extern void FIELD_CAMERA_StartMove(struct FieldCamera *camera, FieldGimmickCannonsCameraRequest *request, int frames);
extern int FIELD_CAMERA_IsMoving(struct FieldCamera *camera);
extern void FIELD_CAMERA_SetMode(struct FieldCamera *camera, u32 mode);
extern void FIELD_CAMERA_StopTargetTrace(struct FieldCamera *camera);
extern int FIELD_CAMERA_ResumeTargetTrace(u32 camera);
extern void FIELD_CAMERA_StartFreeMove(struct FieldCamera *camera, VecFx32 *eyeGoal, VecFx32 *targetGoal,
                          FieldGimmickCannonsCameraChannels *channels, u16 frames);
extern FieldGimmickCannonsCameraView *FIELD_CAMERA_GetMoveGoal(struct FieldCamera *camera);
extern void FIELD_CAMERA_StartMoveToSaved(struct FieldCamera *camera, FieldGimmickCannonsCameraChannels *channels, u16 frames);

void FIELD_GIMMICK_CANNONS_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_CANNONS_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_CANNONS_Update(struct FieldMap *fieldMap);
struct GameEvent *FIELD_GIMMICK_CANNONS_CreateLaunchEvent(struct GameSystem *gameSystem);
int FIELD_GIMMICK_CANNONS_EventLaunch(struct GameEvent *event, int *seq, void *eventWork);
u8 FIELD_GIMMICK_CANNONS_FindCannonAt(int cellX, int cellZ);
u16 FIELD_GIMMICK_CANNONS_GetFirstAnimeSlot(int direction);
int FIELD_GIMMICK_CANNONS_FacingToRingIndex(int facing);
int FIELD_GIMMICK_CANNONS_TurnRingDirection(int direction, int turns);
int FIELD_GIMMICK_CANNONS_GetCannonDirection(unsigned int facing, int cannonIndex);

extern int gCannonsUnitSetup;
extern FieldGimmickCannonsPosTable gCannonsCannonPos;
extern const u8 gCannonsCannonQuarterTurns[];
extern s16 FX_SinCosTable_[];
extern FieldGimmickCannonsFlight gCannonsFlights[][FIELD_GIMMICK_CANNONS_DIRECTION_COUNT];
extern FieldGimmickCannonsCameraInfo gCannonsCameraInfos[];
extern FieldGimmickCannonsCannonCell gCannonsCannonCells[];
extern u16 gCannonsFireSeFrames[];
extern u16 gCannonsFireDoneFrames[];
extern u16 gCannonsLandingFrames[];
extern u16 gCannonsFlightStartFrames[];
extern u16 gCannonsLandSeFramesBeforeEnd[];
extern FieldGimmickCannonsDirTable gCannonsDirectionRing;

/* Load the cannon models, place and turn them, and stop their animations. */
void FIELD_GIMMICK_CANNONS_Init(struct FieldMap *fieldMap)
{
    G3dObjectStatus *status;
    unsigned int i;
    u8 j;
    int sinCosIndex;
    FieldGimmickCannonsPosTable cannonPos;
    FldExpObjCnt *expObj;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_AllocCommonWork(fieldMap, 1, FIELDMAP_GetHeapId(fieldMap), sizeof(FieldGimmickCannonsWork));
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, (const G3dUtilSetup *)&gCannonsUnitSetup, 0);
    i = 0;
    cannonPos = gCannonsCannonPos;
    for (; i < FIELD_GIMMICK_CANNONS_CANNON_COUNT; i = (u8)(i + 1)) {
        status = FLD_EXP_OBJ_GetModelStatus(expObj, 0, (u16)i);
        FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, i, 1);
        status->trans = cannonPos.pos[i];
        sinCosIndex = ((gCannonsCannonQuarterTurns[i] << 14) >> 4) * 2;
        func_0207AF1C(&status->rotate, FX_SinCosTable_[sinCosIndex], FX_SinCosTable_[sinCosIndex + 1]);
        for (j = 0; j < FIELD_GIMMICK_CANNONS_DIRECTION_COUNT; j++) {
            FLD_EXP_OBJ_SetAnimeLoop(FLD_EXP_OBJ_GetAnime(expObj, 0, (u16)i, (u16)(j * 2)), 0);
            FLD_EXP_OBJ_SetAnimeLoop(FLD_EXP_OBJ_GetAnime(expObj, 0, (u16)i, (u16)(j * 2 + 1)), 0);
        }
    }
}

void FIELD_GIMMICK_CANNONS_Exit(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj = FIELDMAP_GetExpObj(fieldMap);

    FIELDMAP_FreeCommonWork(fieldMap, 1);
    FLD_EXP_OBJ_RemoveUnit(expObj, 0);
}

void FIELD_GIMMICK_CANNONS_Update(struct FieldMap *fieldMap)
{
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
}

/*
 * Field event check: the player faces the cell two steps before a cannon.
 * Create the launch event for that cannon; null when no cannon stands there.
 */
struct GameEvent *FIELD_GIMMICK_CANNONS_CreateLaunchEvent(struct GameSystem *gameSystem)
{
    struct FieldMap *fieldMap;
    struct FieldPlayer *player;
    FieldGimmickCannonsWork *work;
    VecFx32 playerPos;
    int cellX;
    int cellZ;
    int facing;
    u8 cannonIndex;
    struct GameEvent *event;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 5);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    FIELD_PLAYER_GetPos(player, &playerPos);
    cellX = playerPos.x / 0x10000;
    cellZ = playerPos.z / 0x10000;
    facing = FIELD_PLAYER_GetDirDisp(player);
    switch (facing) {
    case 0:
        cellZ -= 2;
        break;
    case 1:
        cellZ += 2;
        break;
    case 2:
        cellX -= 2;
        break;
    case 3:
        cellX += 2;
        break;
    }
    cannonIndex = FIELD_GIMMICK_CANNONS_FindCannonAt(cellX, cellZ);
    if (cannonIndex >= FIELD_GIMMICK_CANNONS_CANNON_COUNT) {
        return 0;
    }
    event = func_020122C0(gameSystem, 0, FIELD_GIMMICK_CANNONS_EventLaunch, 0);
    work->cannonIndex = cannonIndex;
    work->facing = facing;
    return event;
}

/*
 * Launch event, run frame by frame. Seq 0 starts the camera bounce setup and
 * the cannon animations, 1 loads the flight animation, 2 waits for the
 * cannon to fire, 3 hides the player, 4 waits for the flight start frame,
 * 5 moves the player with the flight animation and the camera, 6 ends.
 *
 * Closed 2026-10-05 (wD9r lane 36), after many waves at an "s keeps r7" allocator residue. The residue
 * was source shape, not the allocator:
 *   - seq 1: followFrames and returnFrames read into locals (followFrames first), and the clamp written
 *     as an if/else with BOTH stores (cameraFollowEndFrame and cameraReturnFrames) in each arm; tail
 *     merging rebuilds the image's single join store and its empty-arm `b`. This alone moves expObj to
 *     its spill slot [sp,#0x24] and gives frame 0xE8.
 *   - seq 2, 4, 5: `animeValue = FLD_EXP_OBJ_GetAnimeFrame(...)` then `animeValue / 4096` at each compare (the r*2
 *     index is then computed before the divide, as in the image).
 *   - all aggregate locals (request, pos, base, end, start, channels) are block-scoped where they are
 *     used; their slots then follow the order of appearance, and `VecFx32 x = {0, 0, 0}` gives the
 *     `add rN,sp,#K; str [rN]` zeroing form.
 *   - the tail after the switch is `if (work->flying != 0) { ... } return 0;` (one shared epilogue).
 *   - the tail uses its own local tailPlayerMmdl (declared between direction and ringIndex) for its
 *     spill slot.
 */
int FIELD_GIMMICK_CANNONS_EventLaunch(struct GameEvent *event, int *seq, void *eventWork)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    FieldGimmickCannonsWork *work;
    struct FieldCamera *camera;
    struct FieldPlayer *player;
    int animeValue;
    u16 cannonIndex;
    u16 frameCount;
    int cannonRow;
    int direction;
    struct Mmdl *tailPlayerMmdl;
    int ringIndex;
    u16 returnFrames;
    int followFrames;
    u16 initAnimeSlot;
    u16 pauseAnimeSlot;
    u16 playAnimeSlot;
    u16 endAnimeSlot;
    u16 cameraInfoIndex;
    struct Mmdl *playerMmdl;

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    camera = FIELDMAP_GetCamera(fieldMap);
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 5);
    switch (*seq) {
    case 0:
        FIELD_CAMERA_EndDelay(camera);
        FIELD_GIMMICK_CANNONS_ResetBounce(&work->bounce);
        (*seq)++;
        break;
    case 1:
        if ((int)FIELD_CAMERA_IsDelayEnabled(camera) != 0)
            break;
        cannonRow = work->cannonIndex;
        ringIndex = FIELD_GIMMICK_CANNONS_FacingToRingIndex(work->facing);
        animeValue = gCannonsFlights[work->cannonIndex][ringIndex].icaDataId;
        if (animeValue == -1)
            return 1;
        work->flightAnime = ICA_ANIME_CreateWithFullBuffer(0x8015, 0x79, animeValue, work->icaBuffer, 0x708);
        work->frameCount = ICA_ANIME_GetFrameNum(work->flightAnime);
        cameraInfoIndex = gCannonsFlights[cannonRow][ringIndex].cameraInfoIndex;
        followFrames = gCannonsCameraInfos[cameraInfoIndex].followFrames;
        returnFrames = gCannonsCameraInfos[cameraInfoIndex].returnFrames;
        frameCount = work->frameCount;
        if (followFrames + returnFrames >= frameCount) {
            work->cameraFollowEndFrame = frameCount - (returnFrames + 1);
            work->cameraReturnFrames = returnFrames;
        } else {
            work->cameraFollowEndFrame = followFrames;
            work->cameraReturnFrames = returnFrames;
        }
        work->cameraArrived = 0;
        cannonIndex = work->cannonIndex;
        initAnimeSlot = FIELD_GIMMICK_CANNONS_GetFirstAnimeSlot(FIELD_GIMMICK_CANNONS_GetCannonDirection(work->facing, cannonIndex));
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, (u16)cannonIndex, (u16)initAnimeSlot, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, (u16)cannonIndex, (u16)(initAnimeSlot + 1), 1);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, cannonIndex, initAnimeSlot, 0);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, cannonIndex, initAnimeSlot + 1, 0);
        FIELD_CAMERA_PushState(camera);
        (*seq)++;
        break;
    case 2:
        cannonIndex = work->cannonIndex;
        direction = FIELD_GIMMICK_CANNONS_GetCannonDirection(work->facing, cannonIndex);
        animeValue = FLD_EXP_OBJ_GetAnimeFrame(expObj, 0, (u16)cannonIndex, (u16)FIELD_GIMMICK_CANNONS_GetFirstAnimeSlot(direction));
        if (animeValue / 4096 == gCannonsFireSeFrames[direction])
            GFL_USE_PlaySeDefaultVolume(0x698);
        if (animeValue / 4096 < gCannonsFireDoneFrames[direction])
            break;
        pauseAnimeSlot = FIELD_GIMMICK_CANNONS_GetFirstAnimeSlot(direction);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, (u16)cannonIndex, (u16)pauseAnimeSlot), 1);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, (u16)cannonIndex, (u16)(pauseAnimeSlot + 1)), 1);
        SCRIPT_SYS_CallScriptEvent(event, 2, 0, 0, 0x8015);
        cameraInfoIndex = gCannonsFlights[work->cannonIndex][FIELD_GIMMICK_CANNONS_FacingToRingIndex(work->facing)].cameraInfoIndex;
        {
        FieldGimmickCannonsCameraRequest request;
        request.goal.pitch = gCannonsCameraInfos[cameraInfoIndex].pitch;
        request.goal.yaw = gCannonsCameraInfos[cameraInfoIndex].yaw;
        request.channels.shift = 0;
        request.channels.pitch = 1;
        request.channels.yaw = 1;
        request.channels.distance = 0;
        request.channels.fov = 0;
        FIELD_CAMERA_StartMove(camera, &request, gCannonsCameraInfos[cameraInfoIndex].moveFrames);
        }
        (*seq)++;
        break;
    case 3:
        if (FIELD_CAMERA_IsMoving(camera) != 0)
            break;
        FIELD_CAMERA_SetMode(camera, 2);
        playerMmdl = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
        FLDMMDL_SetStatusBitVanish(playerMmdl, 1);
        FLDMMDL_SetStatusBit(playerMmdl, 0x200);
        FLDMMDL_SetMoveBit(playerMmdl, 0x8000);
        cannonIndex = work->cannonIndex;
        playAnimeSlot = FIELD_GIMMICK_CANNONS_GetFirstAnimeSlot(FIELD_GIMMICK_CANNONS_GetCannonDirection(work->facing, cannonIndex));
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, (u16)cannonIndex, (u16)playAnimeSlot), 0);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, (u16)cannonIndex, (u16)(playAnimeSlot + 1)), 0);
        GFL_USE_PlaySeDefaultVolume(0x699);
        (*seq)++;
        break;
    case 4:
        cannonIndex = work->cannonIndex;
        direction = FIELD_GIMMICK_CANNONS_GetCannonDirection(work->facing, cannonIndex);
        animeValue = FLD_EXP_OBJ_GetAnimeFrame(expObj, 0, (u16)cannonIndex, (u16)FIELD_GIMMICK_CANNONS_GetFirstAnimeSlot(direction));
        if (animeValue / 4096 < gCannonsFlightStartFrames[direction])
            break;
        GFL_USE_PlaySeDefaultVolume(0x6A0);
        work->flying = 1;
        work->frame = 0;
        (*seq)++;
        break;
    case 5:
        cannonIndex = work->cannonIndex;
        direction = FIELD_GIMMICK_CANNONS_GetCannonDirection(work->facing, cannonIndex);
        animeValue = FLD_EXP_OBJ_GetAnimeFrame(expObj, 0, (u16)cannonIndex, (u16)FIELD_GIMMICK_CANNONS_GetFirstAnimeSlot(direction));
        if (animeValue / 4096 == gCannonsLandingFrames[direction]) {
            GFL_USE_PlaySeDefaultVolume(0x696);
            if (work->cameraArrived == 0) {
                FIELD_GIMMICK_CANNONS_StartBounce(work);
                FIELD_CAMERA_SetMode(camera, 1);
            }
            FLDMMDL_SetStatusBitVanish(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)), 0);
        }
        if (work->flying != 0)
            break;
        player = FIELDMAP_GetFieldPlayer(fieldMap);
        {
            VecFx32 pos = {0, 0, 0};
            FieldGimmickCannonsFlight *flight = &gCannonsFlights[work->cannonIndex][FIELD_GIMMICK_CANNONS_FacingToRingIndex(work->facing)];
            pos.x = (flight->landX << 16) + 0x8000;
            pos.y = flight->landY << 16;
            pos.z = (flight->landZ << 16) + 0x8000;
            FIELD_PLAYER_SetPos(player, &pos);
        }
        (*seq)++;
        break;
    case 6:
        FLDMMDL_ClearStatusBit(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)), 0x200);
        ICA_ANIME_Delete(work->flightAnime);
        cannonIndex = work->cannonIndex;
        endAnimeSlot = FIELD_GIMMICK_CANNONS_GetFirstAnimeSlot(FIELD_GIMMICK_CANNONS_GetCannonDirection(work->facing, cannonIndex));
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, (u16)cannonIndex, (u16)endAnimeSlot, 0);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, (u16)cannonIndex, (u16)(endAnimeSlot + 1), 0);
        FIELD_CAMERA_RestartDelay(camera);
        FIELD_CAMERA_PopState(camera);
        return 1;
    }
    if (work->flying != 0) {
        {
            VecFx32 flightPos = {0, 0, 0};
            cannonIndex = work->cannonIndex;
            if (ICA_ANIME_GetTranslateAt(work->flightAnime, &flightPos, work->frame) != 0) {
                flightPos.x += (gCannonsCannonCells[cannonIndex].x << 16) + 0x8000;
                flightPos.y += gCannonsCannonCells[cannonIndex].y << 16;
                flightPos.z += (gCannonsCannonCells[cannonIndex].z << 16) + 0x8000;
                FIELD_PLAYER_SetPos(FIELDMAP_GetFieldPlayer(fieldMap), &flightPos);
            }
        }
        if (work->bounce.finished != 0 && work->frame < work->cameraFollowEndFrame) {
            VecFx32 playerPos;
            VecFx32 eyePos;
            FieldGimmickCannonsCameraChannels channels;
            FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos);
            if (work->bounce.cameraMoveStarted == 0) {
                FIELD_CAMERA_StopTargetTrace(camera);
                FIELD_CAMERA_GetEyeRaw(camera, &eyePos);
                channels.target = 1;
                channels.fov = 0;
                channels.shift = 0;
                channels.pitch = 0;
                channels.yaw = 0;
                channels.distance = 0;
                FIELD_CAMERA_StartFreeMove(camera, &eyePos, &playerPos, &channels, work->cameraFollowEndFrame - work->frame);
                work->bounce.cameraMoveStarted = 1;
            } else {
                FIELD_CAMERA_GetMoveGoal(camera)->target = playerPos;
            }
        }
        if (work->frame == work->cameraFollowEndFrame) {
            if (work->bounce.active != 0)
                work->bounce.active = 0;
            FIELD_CAMERA_ResumeTargetTrace((u32)camera);
            FIELD_CAMERA_SetMode(camera, 0);
            {
            FieldGimmickCannonsCameraChannels returnChannels;
            returnChannels.shift = 1;
            returnChannels.pitch = 1;
            returnChannels.yaw = 1;
            returnChannels.distance = 1;
            returnChannels.fov = 1;
            returnChannels.target = 0;
            FIELD_CAMERA_StartMoveToSaved(camera, &returnChannels, work->cameraReturnFrames);
            }
            work->cameraArrived = 1;
        }
        cannonRow = work->cannonIndex;
        cameraInfoIndex = gCannonsFlights[cannonRow][FIELD_GIMMICK_CANNONS_FacingToRingIndex(work->facing)].cameraInfoIndex;
        tailPlayerMmdl = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
        if (work->frame == work->frameCount - 1 - gCannonsLandSeFramesBeforeEnd[cameraInfoIndex] && cameraInfoIndex != 11) {
            FLDMMDL_ClearMoveBit(tailPlayerMmdl, 0x8000);
            GFL_USE_PlaySeDefaultVolume(0x697);
        }
        if (cameraInfoIndex == 11) {
            if (work->frame == 0x46)
                GFL_USE_PlaySeDefaultVolume(0x6A1);
            if (work->frame + 8 >= work->frameCount) {
                if ((int)FLDMMDL_CheckMoveBit(tailPlayerMmdl, 0x8000) != 0)
                    FLDMMDL_ClearMoveBit(tailPlayerMmdl, 0x8000);
            }
        }
        work->frame += 1;
        if (work->frame >= work->frameCount)
            work->flying = 0;
        FIELD_GIMMICK_CANNONS_UpdateBounce(&work->bounce, camera);
    }
    return 0;
}

/* Find the cannon whose cell is (cellX, cellZ); FIELD_GIMMICK_CANNONS_CANNON_COUNT when none. */
u8 FIELD_GIMMICK_CANNONS_FindCannonAt(int cellX, int cellZ)
{
    u8 i;

    for (i = 0; i < FIELD_GIMMICK_CANNONS_CANNON_COUNT; i++) {
        if (cellX == gCannonsCannonCells[i].x && cellZ == gCannonsCannonCells[i].z) {
            return i;
        }
    }
    return i;
}

/*
 * An unlabelled leaf (no lr save) next to FIELD_GIMMICK_CANNONS_FacingToRingIndex: the first animation
 * slot of a direction (two slots per direction). Callee of FIELD_GIMMICK_CANNONS_EventLaunch.
 */
u16 FIELD_GIMMICK_CANNONS_GetFirstAnimeSlot(int direction)
{
    switch (direction) {
    case 0: return 0;
    case 1: return 2;
    case 2: return 4;
    case 3: return 6;
    }
    return 0;
}

/* Player facing (0 up, 1 down, 2 left, 3 right) to the index in the direction ring. */
int FIELD_GIMMICK_CANNONS_FacingToRingIndex(int facing)
{
    switch (facing) {
    case 0: return 0;
    case 1: return 1;
    case 3: return 2;
    case 2: return 3;
    }
    return 0;
}

/* Turn a ring direction by a number of quarter turns. */
int FIELD_GIMMICK_CANNONS_TurnRingDirection(int direction, int turns)
{
    FieldGimmickCannonsDirTable ring = gCannonsDirectionRing;
    u8 i;
    u8 turned;

    for (i = 0; i < FIELD_GIMMICK_CANNONS_DIRECTION_COUNT; i++) {
        if (ring.direction[i] == direction) {
            turned = (i + turns) % 4;
            return ring.direction[turned];
        }
    }
    return direction;
}

/* The direction of a cannon as the player sees it: facing turned by the cannon rotation. */
int FIELD_GIMMICK_CANNONS_GetCannonDirection(unsigned int facing, int cannonIndex)
{
    return FIELD_GIMMICK_CANNONS_TurnRingDirection(FIELD_GIMMICK_CANNONS_FacingToRingIndex(facing), gCannonsCannonQuarterTurns[cannonIndex]);
}

/* Start the camera bounce. */
void FIELD_GIMMICK_CANNONS_StartBounce(FieldGimmickCannonsWork *work)
{
    FIELD_GIMMICK_CANNONS_ResetBounce(&work->bounce);
    work->bounce.active = 1;
}

/*
 * extent: 18 bytes of code followed by two zero alignment bytes.
 */
void FIELD_GIMMICK_CANNONS_ResetBounce(FieldGimmickCannonsBounce *bounce)
{
    bounce->active = 0;
    bounce->finished = 0;
    bounce->cameraMoveStarted = 0;
    bounce->phase = 0;
    bounce->wait = 0;
    bounce->downSteps = 0;
    bounce->tick = 0;
}

/* One step of the camera bounce: raise the camera eye a half unit, then lower it, twice. */
void FIELD_GIMMICK_CANNONS_UpdateBounce(FieldGimmickCannonsBounce *bounce, struct FieldCamera *camera)
{
    int step;
    VecFx32 eye;

    if (bounce->active != 0) {
        bounce->tick++;
        if (bounce->wait == 0) {
            if (bounce->phase % 2 == 0) {
                step = 0x8000;
            } else {
                step = -0x8000;
                bounce->downSteps++;
            }
            bounce->phase = (bounce->phase + 1) % 2;
            FIELD_CAMERA_GetEyeRaw(camera, &eye);
            eye.y += step;
            FIELD_CAMERA_SetEyeRaw(camera, &eye);
            bounce->wait = 1;
        } else {
            bounce->wait--;
        }
        if (bounce->downSteps >= 2) {
            bounce->active = 0;
            bounce->finished = 1;
        }
    }
}
