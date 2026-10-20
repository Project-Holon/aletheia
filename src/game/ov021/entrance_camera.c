/*
 * file:     entrance_camera.c
 * unit:     yes
 * function: ENTRANCE_CAMERA_Create, ENTRANCE_CAMERA_Delete, ENTRANCE_CAMERA_Setup, ENTRANCE_CAMERA_Start, ENTRANCE_CAMERA_Restore, ENTRANCE_CAMERA_IsActive, ENTRANCE_CAMERA_IsInstant, ENTRANCE_CAMERA_AllocWork, ENTRANCE_CAMERA_FreeWork, ENTRANCE_CAMERA_InitWork, ENTRANCE_CAMERA_CreateAnime, ENTRANCE_CAMERA_DeleteAnime, ENTRANCE_CAMERA_SetupLeaveByDir, ENTRANCE_CAMERA_SetupArriveByDir, ENTRANCE_CAMERA_SetupLeaveByRecord, ENTRANCE_CAMERA_SetupArriveByRecord, ENTRANCE_CAMERA_LoadRecord, ENTRANCE_CAMERA_AimAtTarget, ENTRANCE_CAMERA_GetCamera, ENTRANCE_CAMERA_GetRequest, ENTRANCE_CAMERA_SetRequest, ENTRANCE_CAMERA_GetEntranceType, ENTRANCE_CAMERA_HasRecord, ENTRANCE_CAMERA_AimsAtEntrance, ENTRANCE_CAMERA_IsPhaseActive
 * address:  0x021BDC94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_place_name.c at 0x021BDC94 (lane SP3, __FILE__ anchors, certain cut).
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELD_CAMERA_ANIME_SetData  0x0218FEA0  thumb  ov021
 *   FIELD_CAMERA_ANIME_Start  0x0218FF00  thumb  ov021
 *   FIELD_CAMERA_ANIME_Restore  0x0218FF20  thumb
 *   gEntranceCameraFileName     0x021DE37C  data  a4
 *   FIELD_CAMERA_ANIME_Create  0x0218FE80  thumb  ov021
 *   FIELD_CAMERA_ANIME_Delete  0x0218FE98  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   FIELD_GROUND_ANIME_GetEntryPos  0x021A7B08  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_CAMERA_ANIME_Setup  0x0218FEA4  thumb  ov021
 *   FIELD_CAMERA_ANIME_GetCurrentParam  0x0218FE78  thumb  ov021
 *   FIELD_CAMERA_ANIME_ApplyStartParam  0x0218FEC0  thumb  ov021
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 *   FIELD_CAMERA_Main  0x0218E104  thumb  ov021
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 *   EVENT_FIELD_PROCLINK_IsSlotIndexOutOfRange  0x02162370  thumb
 */
#include "entrance_camera_types.h"

struct FieldPlayer;
struct FieldSave;
struct GameSystem;
struct GameData;

#include "../arm9/gfl_heap_wrap.h"
#include "fieldmap.h"
#include "../arm9/mi_memory.h"
#include "field_camera.h"
#include "field_camera_anime.h"
#include "field_player.h"
#include "field_ground_anime.h"
#include "../arm9/arc_tool.h"
#include "../ov010/event_field_proclink_return.h"

void *ENTRANCE_CAMERA_Create(FieldMap *fieldMap);
void ENTRANCE_CAMERA_Delete(EntranceCamera *work);
void ENTRANCE_CAMERA_Setup(EntranceCamera *work, const EntranceCameraRequest *request);
void ENTRANCE_CAMERA_Start(EntranceCamera *work);
void ENTRANCE_CAMERA_Restore(EntranceCamera *work);
int ENTRANCE_CAMERA_IsActive(EntranceCamera *work);
int ENTRANCE_CAMERA_IsInstant(EntranceCamera *work);
void *ENTRANCE_CAMERA_AllocWork(int heapId);
void ENTRANCE_CAMERA_FreeWork(void *work);
void ENTRANCE_CAMERA_InitWork(EntranceCamera *work, FieldMap *fieldMap);
void ENTRANCE_CAMERA_CreateAnime(EntranceCamera *work, int heapId);
void ENTRANCE_CAMERA_DeleteAnime(EntranceCamera *work);
void ENTRANCE_CAMERA_SetupLeaveByDir(EntranceCamera *work);
void ENTRANCE_CAMERA_SetupArriveByDir(EntranceCamera *work);
void ENTRANCE_CAMERA_SetupLeaveByRecord(EntranceCamera *work);
void ENTRANCE_CAMERA_SetupArriveByRecord(EntranceCamera *work);
void ENTRANCE_CAMERA_LoadRecord(EntranceCameraRecord *dst, int entranceType);
void ENTRANCE_CAMERA_AimAtTarget(struct FieldCamera *camera, VecFx32 *target);
struct FieldCamera *ENTRANCE_CAMERA_GetCamera(EntranceCamera *work);
EntranceCameraRequest *ENTRANCE_CAMERA_GetRequest(EntranceCamera *work);
void ENTRANCE_CAMERA_SetRequest(EntranceCamera *work, const EntranceCameraRequest *request);
int ENTRANCE_CAMERA_GetEntranceType(EntranceCamera *work);
int ENTRANCE_CAMERA_HasRecord(EntranceCamera *work);
int ENTRANCE_CAMERA_AimsAtEntrance(EntranceCamera *work);
int ENTRANCE_CAMERA_IsPhaseActive(EntranceCamera *work);
extern const char gEntranceCameraFileName[];

/* Creates the camera work for the field map and its camera anime. */
void *ENTRANCE_CAMERA_Create(FieldMap *fieldMap)
{
    unsigned short heapId = FIELDMAP_GetHeapId(fieldMap);
    EntranceCamera *work = ENTRANCE_CAMERA_AllocWork(heapId);

    ENTRANCE_CAMERA_InitWork(work, fieldMap);
    ENTRANCE_CAMERA_CreateAnime(work, heapId);
    return work;
}

void ENTRANCE_CAMERA_Delete(EntranceCamera *work)
{
    ENTRANCE_CAMERA_DeleteAnime(work);
    ENTRANCE_CAMERA_FreeWork(work);
}

/* Stores the request and prepares the camera move of the phase it names. */
void ENTRANCE_CAMERA_Setup(EntranceCamera *work, const EntranceCameraRequest *request)
{
    ENTRANCE_CAMERA_SetRequest(work, request);
    FIELD_CAMERA_ANIME_SetData(work->anime, &work->animData);
    if (ENTRANCE_CAMERA_HasRecord(work) != 0) {
        switch (request->phase) {
        case ENTRANCE_CAMERA_PHASE_LEAVE:
            ENTRANCE_CAMERA_SetupLeaveByRecord(work);
            break;
        case ENTRANCE_CAMERA_PHASE_ARRIVE:
            ENTRANCE_CAMERA_SetupArriveByRecord(work);
            break;
        }
    } else {
        switch (request->phase) {
        case ENTRANCE_CAMERA_PHASE_LEAVE:
            ENTRANCE_CAMERA_SetupLeaveByDir(work);
            break;
        case ENTRANCE_CAMERA_PHASE_ARRIVE:
            ENTRANCE_CAMERA_SetupArriveByDir(work);
            break;
        }
    }
    work->isSetUp = 1;
}

/* Starts the prepared move when the current phase has one. */
void ENTRANCE_CAMERA_Start(EntranceCamera *work)
{
    if (ENTRANCE_CAMERA_IsPhaseActive(work)) {
        FIELD_CAMERA_ANIME_Start(work->anime);
    }
}

/* Tail call: restores the camera through the camera anime. */
void ENTRANCE_CAMERA_Restore(EntranceCamera *work)
{
    FIELD_CAMERA_ANIME_Restore(work->anime);
}

int ENTRANCE_CAMERA_IsActive(EntranceCamera *work)
{
    return ENTRANCE_CAMERA_IsPhaseActive(work);
}

/* Returns 1 when the prepared move has no frames (the end setting applies at once). */
int ENTRANCE_CAMERA_IsInstant(EntranceCamera *work)
{
    if (work->animData.frames == 0) {
        return 1;
    }
    return 0;
}

void *ENTRANCE_CAMERA_AllocWork(int heapId)
{
    return GFL_HEAP_Alloc(heapId, sizeof(EntranceCamera), 0, gEntranceCameraFileName, 0x12A);
}

/* Tail call: frees the work. */
void ENTRANCE_CAMERA_FreeWork(void *work)
{
    GFL_HEAP_Free(work);
}

void ENTRANCE_CAMERA_InitWork(EntranceCamera *work, FieldMap *fieldMap)
{
    MI_CpuFill8(work, 0, sizeof(EntranceCamera));
    work->fieldMap = fieldMap;
    work->camera = FIELDMAP_GetCamera(fieldMap);
    work->isSetUp = 0;
}

void ENTRANCE_CAMERA_CreateAnime(EntranceCamera *work, int heapId)
{
    work->anime = FIELD_CAMERA_ANIME_Create(work->fieldMap);
}

void ENTRANCE_CAMERA_DeleteAnime(EntranceCamera *work)
{
    if (work->anime != 0) {
        FIELD_CAMERA_ANIME_Delete(work->anime);
        work->anime = 0;
    }
}

/*
 * Leave move chosen by the player facing (no archive record). Only facing
 * left or right moves the camera: it swings the yaw of the end setting.
 *
 * The unused `unusedZero` vector is a dead initialised local: an initialiser
 * keeps its three stores (plain assignments are eliminated), and declaring it
 * in an inner block schedules them between the two FIELD_CAMERA_ANIME_GetCurrentParam calls. The
 * yaw is u16 (pool word 0x0000F5F7, not 0xFFFFF5F7).
 */
void ENTRANCE_CAMERA_SetupLeaveByDir(EntranceCamera *work)
{
    FieldCameraAnimeData *data = &work->animData;
    FieldCameraParam *end = &data->end;
    VecFx32 playerPos;
    struct FieldPlayer *player;
    int playerDir;

    ENTRANCE_CAMERA_GetCamera(work);
    player = FIELDMAP_GetFieldPlayer(work->fieldMap);
    playerDir = FIELD_PLAYER_GetDirDisp(player);
    switch (playerDir) {
    case ENTRANCE_CAMERA_DIR_LEFT:
    case ENTRANCE_CAMERA_DIR_RIGHT:
        work->leaveActive = 1;
        work->arriveActive = 0;
        break;
    case ENTRANCE_CAMERA_DIR_UP:
    case ENTRANCE_CAMERA_DIR_DOWN:
        work->leaveActive = 0;
        work->arriveActive = 0;
        break;
    }
    if (work->leaveActive == 0) {
        return;
    }
    data->stopTrace = 0;
    data->detachTarget = 0;
    if (ENTRANCE_CAMERA_AimsAtEntrance(work)) {
        FIELD_GROUND_ANIME_GetEntryPos(work->fieldMap, &playerPos);
    } else {
        FIELD_PLAYER_GetPos(player, &playerPos);
    }
    FIELD_CAMERA_ANIME_Setup(work->anime);
    FIELD_CAMERA_ANIME_GetCurrentParam(work->camera, &data->start);
    {
        VecFx32 unusedZero = {0, 0, 0};
        FIELD_CAMERA_ANIME_GetCurrentParam(work->camera, end);
    }
    switch (playerDir) {
    case ENTRANCE_CAMERA_DIR_UP:
        end->distance = 0xB4000;
        break;
    case ENTRANCE_CAMERA_DIR_DOWN:
        break;
    case ENTRANCE_CAMERA_DIR_LEFT:
        end->yaw = 0xA09;
        break;
    case ENTRANCE_CAMERA_DIR_RIGHT:
        end->yaw = -0xA09;
        break;
    }
    switch (playerDir) {
    case ENTRANCE_CAMERA_DIR_UP:
        data->frames = 0;
        break;
    case ENTRANCE_CAMERA_DIR_DOWN:
        data->frames = 0;
        break;
    case ENTRANCE_CAMERA_DIR_LEFT:
        data->frames = 10;
        break;
    case ENTRANCE_CAMERA_DIR_RIGHT:
        data->frames = 10;
        break;
    }
}

/*
 * Arrive move chosen by the player facing; same object layout as
 * ENTRANCE_CAMERA_SetupArriveByRecord. The first switch's arms are laid out in source order, cases
 * 1-3 ahead of case 0 (its table entry for 0 is the later block); the
 * identical arms of the second switch are separate blocks cross-jumped into
 * the case-3 store.
 */
void ENTRANCE_CAMERA_SetupArriveByDir(EntranceCamera *work)
{
    VecFx32 pos;
    struct FieldCamera *camera;
    struct FieldPlayer *player;
    int playerDir;
    FieldCameraAnimeData *data = &work->animData;
    FieldCameraParam *end = &data->end;

    camera = ENTRANCE_CAMERA_GetCamera(work);
    player = FIELDMAP_GetFieldPlayer(work->fieldMap);
    playerDir = FIELD_PLAYER_GetDirDisp(player);
    switch (playerDir) {
    case ENTRANCE_CAMERA_DIR_DOWN:
    case ENTRANCE_CAMERA_DIR_LEFT:
    case ENTRANCE_CAMERA_DIR_RIGHT:
        work->leaveActive = 0;
        work->arriveActive = 1;
        break;
    case ENTRANCE_CAMERA_DIR_UP:
        work->leaveActive = 0;
        work->arriveActive = 0;
        break;
    }
    if (work->arriveActive == 0)
        return;
    data->stopTrace = 0;
    data->detachTarget = 0;
    if (ENTRANCE_CAMERA_AimsAtEntrance(work) != 0)
        FIELD_GROUND_ANIME_GetEntryPos(work->fieldMap, &pos);
    else
        FIELD_PLAYER_GetPos(player, &pos);
    switch (playerDir) {
    case ENTRANCE_CAMERA_DIR_UP:
        data->frames = 0;
        break;
    case ENTRANCE_CAMERA_DIR_DOWN:
        data->frames = 10;
        break;
    case ENTRANCE_CAMERA_DIR_LEFT:
        data->frames = 10;
        break;
    case ENTRANCE_CAMERA_DIR_RIGHT:
        data->frames = 10;
        break;
    }
    if (ENTRANCE_CAMERA_AimsAtEntrance(work) != 0)
        ENTRANCE_CAMERA_AimAtTarget(camera, &pos);
    FIELD_CAMERA_ANIME_Setup(work->anime);
    FIELD_CAMERA_ANIME_GetCurrentParam(work->camera, &data->start);
    switch (playerDir) {
    case ENTRANCE_CAMERA_DIR_UP:
        break;
    case ENTRANCE_CAMERA_DIR_DOWN:
        data->start.distance = 0xB4000;
        break;
    case ENTRANCE_CAMERA_DIR_LEFT:
        data->start.yaw = 0xF5F7;
        break;
    case ENTRANCE_CAMERA_DIR_RIGHT:
        data->start.yaw = 0xA09;
        break;
    }
    FIELD_CAMERA_ANIME_GetCurrentParam(work->camera, end);
    if (work->arriveActive != 0)
        FIELD_CAMERA_ANIME_ApplyStartParam(work->anime);
}

/* Leave move read from the archive record of the entrance type. */
void ENTRANCE_CAMERA_SetupLeaveByRecord(EntranceCamera *work)
{
    FieldCameraAnimeData *data = &work->animData;
    FieldCameraParam *end = &data->end;
    VecFx32 pos;
    EntranceCameraRecord rec;
    struct FieldPlayer *player;
    int active;
    int x;
    int y;
    int z;

    ENTRANCE_CAMERA_GetCamera(work);
    player = FIELDMAP_GetFieldPlayer(work->fieldMap);
    FIELD_PLAYER_GetDirDisp(player);
    ENTRANCE_CAMERA_LoadRecord(&rec, ENTRANCE_CAMERA_GetEntranceType(work));
    data->stopTrace = rec.stopTrace;
    data->detachTarget = rec.detachTarget;
    active = rec.leaveActive;
    work->leaveActive = active;
    work->arriveActive = rec.arriveActive;
    if (active == 0) {
        return;
    }
    if (ENTRANCE_CAMERA_AimsAtEntrance(work) != 0) {
        FIELD_GROUND_ANIME_GetEntryPos(work->fieldMap, &pos);
    } else {
        FIELD_PLAYER_GetPos(player, &pos);
    }
    FIELD_CAMERA_ANIME_Setup(work->anime);
    FIELD_CAMERA_ANIME_GetCurrentParam(work->camera, &data->start);
    data->frames = rec.frames;
    end->pitch = rec.pitch;
    end->yaw = rec.yaw;
    end->distance = rec.distance << 12;
    z = rec.shift.z << 12;
    y = rec.shift.y << 12;
    x = rec.shift.x << 12;
    end->shift.x = x;
    end->shift.y = y;
    end->shift.z = z;
    if (rec.useFixedTarget != 0) {
        z = rec.target.z << 12;
        y = rec.target.y << 12;
        x = rec.target.x << 12;
        end->target.x = x;
        end->target.y = y;
        end->target.z = z;
    } else {
        end->target = pos;
    }
}

static inline void ENTRANCE_CAMERA_SetVec(VecFx32 *dst, int x, int y, int z)
{
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

/*
 * Arrive twin of ENTRANCE_CAMERA_SetupLeaveByRecord with the changed setting at the start of the
 * move (animData.start) instead of the end. A function-scope pointer to the
 * start setting is what keeps the else-arm copy's destination as
 * (animData+4)+8 in a fresh register; &start->target folds to animData+0xC.
 * The two vector writes are VEC_Set-style inline setters (arguments
 * evaluated right to left). The EXACT* is the 2-byte pad after the pop.
 */
void ENTRANCE_CAMERA_SetupArriveByRecord(EntranceCamera *work)
{
    VecFx32 pos;
    EntranceCameraRecord rec;
    struct FieldPlayer *player;
    FieldCameraAnimeData *data = &work->animData;
    FieldCameraParam *end = &data->end;
    FieldCameraParam *start = &data->start;
    struct FieldCamera *camera = ENTRANCE_CAMERA_GetCamera(work);

    player = FIELDMAP_GetFieldPlayer(work->fieldMap);
    FIELD_PLAYER_GetDirDisp(player);
    ENTRANCE_CAMERA_LoadRecord(&rec, ENTRANCE_CAMERA_GetEntranceType(work));
    data->stopTrace = rec.stopTrace;
    data->detachTarget = rec.detachTarget;
    work->leaveActive = rec.leaveActive;
    work->arriveActive = rec.arriveActive;
    if (work->arriveActive == 0)
        return;
    if (ENTRANCE_CAMERA_AimsAtEntrance(work) != 0)
        FIELD_GROUND_ANIME_GetEntryPos(work->fieldMap, &pos);
    else
        FIELD_PLAYER_GetPos(player, &pos);
    if (data->detachTarget != 0 && ENTRANCE_CAMERA_AimsAtEntrance(work) != 0)
        ENTRANCE_CAMERA_AimAtTarget(camera, &pos);
    FIELD_CAMERA_ANIME_Setup(work->anime);
    FIELD_CAMERA_ANIME_GetCurrentParam(work->camera, end);
    data->frames = rec.frames;
    start->pitch = rec.pitch;
    start->yaw = rec.yaw;
    start->distance = rec.distance << 12;
    ENTRANCE_CAMERA_SetVec(&start->shift, rec.shift.x << 12, rec.shift.y << 12, rec.shift.z << 12);
    if (rec.useFixedTarget != 0) {
        ENTRANCE_CAMERA_SetVec(&start->target, rec.target.x << 12, rec.target.y << 12, rec.target.z << 12);
    } else {
        start->target = pos;
    }
    if (work->arriveActive != 0)
        FIELD_CAMERA_ANIME_ApplyStartParam(work->anime);
}

/* Reads the camera record of the entrance type from the archive. */
void ENTRANCE_CAMERA_LoadRecord(EntranceCameraRecord *dst, int entranceType)
{
    ARC_TOOL_ReadMember(dst, ENTRANCE_CAMERA_RECORD_ARCHIVE, entranceType - ENTRANCE_CAMERA_FIRST_RECORD_TYPE);
}

/* Aims the camera at the target and returns the camera trace state. */
void ENTRANCE_CAMERA_AimAtTarget(struct FieldCamera *camera, VecFx32 *target)
{
    FIELD_CAMERA_StopTargetTrace(camera);
    FIELD_CAMERA_SetTarget(camera, target);
    FIELD_CAMERA_Main(camera, 0);
    FIELD_CAMERA_ResumeTargetTrace(camera);
}

struct FieldCamera *ENTRANCE_CAMERA_GetCamera(EntranceCamera *work)
{
    return work->camera;
}

/* Returns the request inside the work. */
EntranceCameraRequest *ENTRANCE_CAMERA_GetRequest(EntranceCamera *work)
{
    return &work->request;
}

void ENTRANCE_CAMERA_SetRequest(EntranceCamera *work, const EntranceCameraRequest *request)
{
    work->request = *request;
}

int ENTRANCE_CAMERA_GetEntranceType(EntranceCamera *work)
{
    return ENTRANCE_CAMERA_GetRequest(work)->entranceType;
}

/* Nonzero when the entrance type has an archive record (EVENT_FIELD_PROCLINK_IsSlotIndexOutOfRange tests the type). */
int ENTRANCE_CAMERA_HasRecord(EntranceCamera *work)
{
    return EVENT_FIELD_PROCLINK_IsSlotIndexOutOfRange(ENTRANCE_CAMERA_GetRequest(work)->entranceType);
}

/* Returns 1 when the camera aims at the entrance position, 0 when it aims at the player. */
int ENTRANCE_CAMERA_AimsAtEntrance(EntranceCamera *work)
{
    if (ENTRANCE_CAMERA_GetRequest(work)->usePlayerPos == 0) {
        return 1;
    }
    return 0;
}

/* Returns whether the move of the current phase runs. */
int ENTRANCE_CAMERA_IsPhaseActive(EntranceCamera *work)
{
    if (ENTRANCE_CAMERA_GetRequest(work)->phase == 0) {
        return work->leaveActive;
    }
    return work->arriveActive;
}
