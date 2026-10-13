/*
 * file:     entrance_camera.c
 * unit:     yes
 * function: func_021BDC94, func_021BDCB8, func_021BDCC8, func_021BDD20, func_021BDD34, func_021BDD40, func_021BDD48, func_021BDD58, func_021BDD74, func_021BDD7C, func_021BDD9C, func_021BDDAC, func_021BDDC0, func_021BDEB4, func_021BDFB0, func_021BE068, func_021BE148, func_021BE158, func_021BE17C, func_021BE180, func_021BE184, func_021BE194, func_021BE1A0, func_021BE1B0, func_021BE1C4
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
 *   func_020307B0  0x020307B0  arm
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_0218FEA0  0x0218FEA0  thumb  ov021
 *   func_0218FF00  0x0218FF00  thumb  ov021
 *   func_0218FF20  0x0218FF20  thumb
 *   d_021DE37C     0x021DE37C  data  a4
 *   func_0218FE80  0x0218FE80  thumb  ov021
 *   func_0218FE98  0x0218FE98  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021A7B08  0x021A7B08  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0218FEA4  0x0218FEA4  thumb  ov021
 *   func_0218FE78  0x0218FE78  thumb  ov021
 *   func_0218FEC0  0x0218FEC0  thumb  ov021
 *   func_02048F4C  0x02048F4C  arm
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0218E104  0x0218E104  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_02162370  0x02162370  thumb
 */
#include "entrance_camera_types.h"

struct FieldPlayer;
struct FieldSave;
struct GameSystem;
struct GameData;

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern unsigned int func_020307B0(void *p);
extern struct FieldCamera *func_02188C58(FieldMap *fieldMap);
extern void func_02082BCC(void *, int, int);
extern void func_0218EC54(struct FieldCamera *camera);
extern struct FieldPlayer *func_02188CB4(FieldMap *fieldMap);
extern unsigned short func_02188C84(FieldMap *fieldMap);
extern void func_0218FEA0(struct FieldCameraAnime *anime, FieldCameraAnimeData *data);
extern int func_0218FF00(struct FieldCameraAnime *anime);
extern void func_0218FF20(struct FieldCameraAnime *anime);
extern struct FieldCameraAnime *func_0218FE80(FieldMap *fieldMap);
extern void func_0218FE98(void);
extern unsigned short func_021A3050(struct FieldPlayer *player);
extern void func_021A7B08(FieldMap *fieldMap, VecFx32 *out);
extern void func_021A3038(struct FieldPlayer *player, VecFx32 *out);
extern void func_0218FEA4(struct FieldCameraAnime *anime);
extern void func_0218FE78(struct FieldCamera *camera, FieldCameraParam *param);
extern void func_0218FEC0(struct FieldCameraAnime *anime);
extern void func_02048F4C(void *dst, unsigned int archiveId, unsigned int memberId);
extern void func_0218E104(struct FieldCamera *camera, unsigned int value);
extern int func_0218EC60(struct FieldCamera *camera);
extern unsigned int func_0218EC90(struct FieldCamera *camera, const VecFx32 *target);
extern unsigned int func_02162370(unsigned int entranceType);

void *func_021BDC94(FieldMap *fieldMap);
void func_021BDCB8(EntranceCamera *work);
void func_021BDCC8(EntranceCamera *work, const EntranceCameraRequest *request);
void func_021BDD20(EntranceCamera *work);
void func_021BDD34(EntranceCamera *work);
int func_021BDD40(EntranceCamera *work);
int func_021BDD48(EntranceCamera *work);
void *func_021BDD58(int heapId);
void func_021BDD74(void *work);
void func_021BDD7C(EntranceCamera *work, FieldMap *fieldMap);
void func_021BDD9C(EntranceCamera *work, int heapId);
void func_021BDDAC(EntranceCamera *work);
void func_021BDDC0(EntranceCamera *work);
void func_021BDEB4(EntranceCamera *work);
void func_021BDFB0(EntranceCamera *work);
void func_021BE068(EntranceCamera *work);
void func_021BE148(EntranceCameraRecord *dst, int entranceType);
int func_021BE158(struct FieldCamera *camera, VecFx32 *target);
struct FieldCamera *func_021BE17C(EntranceCamera *work);
EntranceCameraRequest *func_021BE180(EntranceCamera *work);
void func_021BE184(EntranceCamera *work, const EntranceCameraRequest *request);
int func_021BE194(EntranceCamera *work);
int func_021BE1A0(EntranceCamera *work);
int func_021BE1B0(EntranceCamera *work);
int func_021BE1C4(EntranceCamera *work);
extern const char d_021DE37C[];

/* Creates the camera work for the field map and its camera anime. */
void *func_021BDC94(FieldMap *fieldMap)
{
    unsigned short heapId = func_02188C84(fieldMap);
    EntranceCamera *work = func_021BDD58(heapId);

    func_021BDD7C(work, fieldMap);
    func_021BDD9C(work, heapId);
    return work;
}

void func_021BDCB8(EntranceCamera *work)
{
    func_021BDDAC(work);
    func_021BDD74(work);
}

/* Stores the request and prepares the camera move of the phase it names. */
void func_021BDCC8(EntranceCamera *work, const EntranceCameraRequest *request)
{
    func_021BE184(work, request);
    func_0218FEA0(work->anime, &work->animData);
    if (func_021BE1A0(work) != 0) {
        switch (request->phase) {
        case ENTRANCE_CAMERA_PHASE_LEAVE:
            func_021BDFB0(work);
            break;
        case ENTRANCE_CAMERA_PHASE_ARRIVE:
            func_021BE068(work);
            break;
        }
    } else {
        switch (request->phase) {
        case ENTRANCE_CAMERA_PHASE_LEAVE:
            func_021BDDC0(work);
            break;
        case ENTRANCE_CAMERA_PHASE_ARRIVE:
            func_021BDEB4(work);
            break;
        }
    }
    work->isSetUp = 1;
}

/* Starts the prepared move when the current phase has one. */
void func_021BDD20(EntranceCamera *work)
{
    if (func_021BE1C4(work)) {
        func_0218FF00(work->anime);
    }
}

/* Tail call: restores the camera through the camera anime. */
void func_021BDD34(EntranceCamera *work)
{
    func_0218FF20(work->anime);
}

int func_021BDD40(EntranceCamera *work)
{
    return func_021BE1C4(work);
}

/* Returns 1 when the prepared move has no frames (the end setting applies at once). */
int func_021BDD48(EntranceCamera *work)
{
    if (work->animData.frames == 0) {
        return 1;
    }
    return 0;
}

void *func_021BDD58(int heapId)
{
    return func_02030734(heapId, sizeof(EntranceCamera), 0, d_021DE37C, 0x12A);
}

/* Tail call: frees the work. */
void func_021BDD74(void *work)
{
    func_020307B0(work);
}

void func_021BDD7C(EntranceCamera *work, FieldMap *fieldMap)
{
    func_02082BCC(work, 0, sizeof(EntranceCamera));
    work->fieldMap = fieldMap;
    work->camera = func_02188C58(fieldMap);
    work->isSetUp = 0;
}

void func_021BDD9C(EntranceCamera *work, int heapId)
{
    work->anime = func_0218FE80(work->fieldMap);
}

void func_021BDDAC(EntranceCamera *work)
{
    if (work->anime != 0) {
        func_0218FE98();
        work->anime = 0;
    }
}

/*
 * Leave move chosen by the player facing (no archive record). Only facing
 * left or right moves the camera: it swings the yaw of the end setting.
 *
 * The unused `unusedZero` vector is a dead initialised local: an initialiser
 * keeps its three stores (plain assignments are eliminated), and declaring it
 * in an inner block schedules them between the two func_0218FE78 calls. The
 * yaw is u16 (pool word 0x0000F5F7, not 0xFFFFF5F7).
 */
void func_021BDDC0(EntranceCamera *work)
{
    FieldCameraAnimeData *data = &work->animData;
    FieldCameraParam *end = &data->end;
    VecFx32 playerPos;
    struct FieldPlayer *player;
    int playerDir;

    func_021BE17C(work);
    player = func_02188CB4(work->fieldMap);
    playerDir = func_021A3050(player);
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
    if (func_021BE1B0(work)) {
        func_021A7B08(work->fieldMap, &playerPos);
    } else {
        func_021A3038(player, &playerPos);
    }
    func_0218FEA4(work->anime);
    func_0218FE78(work->camera, &data->start);
    {
        VecFx32 unusedZero = {0, 0, 0};
        func_0218FE78(work->camera, end);
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
 * func_021BE068. The first switch's arms are laid out in source order, cases
 * 1-3 ahead of case 0 (its table entry for 0 is the later block); the
 * identical arms of the second switch are separate blocks cross-jumped into
 * the case-3 store.
 */
void func_021BDEB4(EntranceCamera *work)
{
    VecFx32 pos;
    struct FieldCamera *camera;
    struct FieldPlayer *player;
    int playerDir;
    FieldCameraAnimeData *data = &work->animData;
    FieldCameraParam *end = &data->end;

    camera = func_021BE17C(work);
    player = func_02188CB4(work->fieldMap);
    playerDir = func_021A3050(player);
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
    if (func_021BE1B0(work) != 0)
        func_021A7B08(work->fieldMap, &pos);
    else
        func_021A3038(player, &pos);
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
    if (func_021BE1B0(work) != 0)
        func_021BE158(camera, &pos);
    func_0218FEA4(work->anime);
    func_0218FE78(work->camera, &data->start);
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
    func_0218FE78(work->camera, end);
    if (work->arriveActive != 0)
        func_0218FEC0(work->anime);
}

/* Leave move read from the archive record of the entrance type. */
void func_021BDFB0(EntranceCamera *work)
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

    func_021BE17C(work);
    player = func_02188CB4(work->fieldMap);
    func_021A3050(player);
    func_021BE148(&rec, func_021BE194(work));
    data->stopTrace = rec.stopTrace;
    data->detachTarget = rec.detachTarget;
    active = rec.leaveActive;
    work->leaveActive = active;
    work->arriveActive = rec.arriveActive;
    if (active == 0) {
        return;
    }
    if (func_021BE1B0(work) != 0) {
        func_021A7B08(work->fieldMap, &pos);
    } else {
        func_021A3038(player, &pos);
    }
    func_0218FEA4(work->anime);
    func_0218FE78(work->camera, &data->start);
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
 * Arrive twin of func_021BDFB0 with the changed setting at the start of the
 * move (animData.start) instead of the end. A function-scope pointer to the
 * start setting is what keeps the else-arm copy's destination as
 * (animData+4)+8 in a fresh register; &start->target folds to animData+0xC.
 * The two vector writes are VEC_Set-style inline setters (arguments
 * evaluated right to left). The EXACT* is the 2-byte pad after the pop.
 */
void func_021BE068(EntranceCamera *work)
{
    VecFx32 pos;
    EntranceCameraRecord rec;
    struct FieldPlayer *player;
    FieldCameraAnimeData *data = &work->animData;
    FieldCameraParam *end = &data->end;
    FieldCameraParam *start = &data->start;
    struct FieldCamera *camera = func_021BE17C(work);

    player = func_02188CB4(work->fieldMap);
    func_021A3050(player);
    func_021BE148(&rec, func_021BE194(work));
    data->stopTrace = rec.stopTrace;
    data->detachTarget = rec.detachTarget;
    work->leaveActive = rec.leaveActive;
    work->arriveActive = rec.arriveActive;
    if (work->arriveActive == 0)
        return;
    if (func_021BE1B0(work) != 0)
        func_021A7B08(work->fieldMap, &pos);
    else
        func_021A3038(player, &pos);
    if (data->detachTarget != 0 && func_021BE1B0(work) != 0)
        func_021BE158(camera, &pos);
    func_0218FEA4(work->anime);
    func_0218FE78(work->camera, end);
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
        func_0218FEC0(work->anime);
}

/* Reads the camera record of the entrance type from the archive. */
void func_021BE148(EntranceCameraRecord *dst, int entranceType)
{
    func_02048F4C(dst, ENTRANCE_CAMERA_RECORD_ARCHIVE, entranceType - ENTRANCE_CAMERA_FIRST_RECORD_TYPE);
}

/* Aims the camera at the target and returns the camera trace state. */
int func_021BE158(struct FieldCamera *camera, VecFx32 *target)
{
    func_0218EC54(camera);
    func_0218EC90(camera, target);
    func_0218E104(camera, 0);
    return func_0218EC60(camera);
}

struct FieldCamera *func_021BE17C(EntranceCamera *work)
{
    return work->camera;
}

/* Returns the request inside the work. */
EntranceCameraRequest *func_021BE180(EntranceCamera *work)
{
    return &work->request;
}

void func_021BE184(EntranceCamera *work, const EntranceCameraRequest *request)
{
    work->request = *request;
}

int func_021BE194(EntranceCamera *work)
{
    return func_021BE180(work)->entranceType;
}

/* Nonzero when the entrance type has an archive record (func_02162370 tests the type). */
int func_021BE1A0(EntranceCamera *work)
{
    return func_02162370(func_021BE180(work)->entranceType);
}

/* Returns 1 when the camera aims at the entrance position, 0 when it aims at the player. */
int func_021BE1B0(EntranceCamera *work)
{
    if (func_021BE180(work)->usePlayerPos == 0) {
        return 1;
    }
    return 0;
}

/* Returns whether the move of the current phase runs. */
int func_021BE1C4(EntranceCamera *work)
{
    if (func_021BE180(work)->phase == 0) {
        return work->leaveActive;
    }
    return work->arriveActive;
}
