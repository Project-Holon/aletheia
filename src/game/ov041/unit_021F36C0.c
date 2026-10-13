/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F37B8, func_021F37D4, func_021F37E0, func_021F3884, func_021F3EE4, func_021F3F18, func_021F3F44, func_021F3F70, func_021F3FC0, func_021F3FD8, func_021F3FEC
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
 *   d_021F40A4     0x021F40A4  data  a4
 *   d_021F4208     0x021F4208  data  a4
 *   d_021F4660     0x021F4660  data  a1
 *   d_020A1B38     0x020A1B38  data  a2
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_0207AF1C  0x0207AF1C  thumb
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021BE580 0x021BE580 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F4000  0x021F4000  thumb  ov041
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE6E8  0x021BE6E8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218F818  0x0218F818  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_0218F900  0x0218F900  thumb  ov021
 *   func_0218FE50  0x0218FE50  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_0218F878  0x0218F878  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218ECE4  0x0218ECE4  thumb  ov021
 *   func_0218F930  0x0218F930  thumb  ov021
 *   func_0218FE70  0x0218FE70  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_0218F9C4  0x0218F9C4  thumb  ov021
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_020124E4  0x020124E4  thumb
 *   ICA_ANIME_CreateWithFullBuffer  0x02011428  thumb
 *   ICA_ANIME_GetFrameNum  0x02011608  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02011558  0x02011558  thumb
 *   ICA_ANIME_GetTranslateAt  0x02011688  thumb
 *   d_021F4320     0x021F4320  data  a4
 *   d_021F4198     0x021F4198  data  a2
 *   d_021F40F0     0x021F40F0  data  a2
 *   d_021F4084     0x021F4084  data  a2
 *   d_021F408C     0x021F408C  data  a2
 *   d_021F4094     0x021F4094  data  a2
 *   d_021F409C     0x021F409C  data  a2
 *   d_021F40B4     0x021F40B4  data  a2
 *   d_021F4080     0x021F4080  data  a1
 */
#include "../ov021/fld_exp_obj_types.h"
#include "unit_021F36C0_types.h"

typedef signed short s16;

/*
 * Same layout as FieldCameraView, FieldCameraMoveChannels and
 * FieldCameraMoveRequest (ov021/field_camera_types.h), which cannot be
 * included here: it and the expansion object types both define VecFx32.
 */
typedef struct Gimmick41CameraView {
    VecFx32 eye;
    VecFx32 target;
    VecFx32 shift;
    u16 pitch;
    u16 yaw;
    int distance;
    u16 fov;
    u16 reserved;
} Gimmick41CameraView;

typedef struct Gimmick41CameraChannels {
    u32 shift;
    u32 pitch;
    u32 yaw;
    u32 distance;
    u32 fov;
    u32 target;
} Gimmick41CameraChannels;

typedef struct Gimmick41CameraRequest {
    Gimmick41CameraView goal;
    Gimmick41CameraChannels channels;
} Gimmick41CameraRequest;

/* Cannon positions: the table is read in full. */
typedef struct Gimmick41PosTable {
    VecFx32 pos[GIMMICK41_CANNON_COUNT];
} Gimmick41PosTable;

typedef struct Gimmick41DirTable {
    u8 direction[GIMMICK41_DIRECTION_COUNT];
} Gimmick41DirTable;

extern FldExpObjCnt *func_02188D2C(struct FieldMap *fieldMap);
extern u16 func_02188C84(struct FieldMap *fieldMap);
extern void *func_02189764(struct FieldMap *fieldMap, int id, int heapId, int size);
extern void func_021897A0(struct FieldMap *fieldMap, int id);
extern void *func_021897BC(struct FieldMap *fieldMap, int id);
extern struct GameSystem *func_02188C80(struct FieldMap *fieldMap);
extern struct FieldPlayer *func_02188CB4(struct FieldMap *fieldMap);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct GimmickWork *func_02012EC4(struct GameData *gameData);
extern void *func_0200B3A4(struct GimmickWork *gimmickWork, u32 gimmickId);
extern struct FieldMap *func_0201210C(const struct GameSystem *gameSystem);
extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent,
                                       GameEventFunc func, u32 workSize);
extern void func_021BE418(FldExpObjCnt *expObj, u16 unitIndex);
extern G3dObjectStatus *func_021BE480(FldExpObjCnt *expObj, unsigned unitIndex, int modelIndex);
extern void func_021BE4A4(FldExpObjCnt *expObj, int unitIndex, u16 modelIndex, int cullDraw);
extern void func_021BE580(FldExpObjCnt *expObj);
extern FldExpObjAnime *func_021BE674(FldExpObjCnt *expObj, int unitIndex, unsigned modelIndex, int animeIndex);
extern void func_021BE6B0(FldExpObjAnime *anime, int paused);
extern void func_021BE6B8(FldExpObjAnime *anime, int loop);
extern void func_021BE6CC(FldExpObjCnt *expObj, int unitIndex, u16 modelIndex, u16 animeIndex, int frame);
extern int func_021BE6E8(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int animeIndex);
extern void func_021BE700(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int animeIndex, int enable);
extern void func_021BE760(FldExpObjCnt *expObj, const G3dUtilSetup *setup, u16 unitIndex);
extern void func_0207AF1C(void *matrix, int sin, int cos);
extern void func_021A3038(struct FieldPlayer *player, VecFx32 *out);
extern void func_021A3044(struct FieldPlayer *player, const VecFx32 *pos);
extern u16 func_021A3050(struct FieldPlayer *player);
extern struct Mmdl *func_021A3074(struct FieldPlayer *player);
extern void func_0216DAC8(struct Mmdl *mmdl, int flag);
extern u32 *func_0216D548(struct Mmdl *mmdl, u32 bit);
extern struct Mmdl *func_0216D568(struct Mmdl *mmdl, u32 bit);
extern u32 *func_0216D550(struct Mmdl *mmdl, u32 bit);
extern char *func_0216D570(struct Mmdl *mmdl, u32 bit);
extern u32 func_0216D57C(struct Mmdl *mmdl, u32 bit);
extern int func_02158780(struct GameEvent *event, u16 scriptId, int arg1, int arg2, u16 heapId);
extern void func_020061E4(u32 seId);
extern struct IcaAnime *ICA_ANIME_CreateWithFullBuffer(u32 heapId, u32 arcId, u32 dataId, void *buffer, u32 bufferSize);
extern u32 ICA_ANIME_GetFrameNum(struct IcaAnime *anime);
extern void func_02011558(struct IcaAnime *anime);
extern u32 ICA_ANIME_GetTranslateAt(struct IcaAnime *anime, VecFx32 *out, u32 frame);
extern void func_0218F0A8(struct FieldCamera *camera);
extern u32 func_0218F0E8(struct FieldCamera *camera);
extern void func_0218F818(struct FieldCamera *camera);
extern void func_0218F878(struct FieldCamera *camera);
extern void func_0218F05C(struct FieldCamera *camera);
extern void func_0218F900(struct FieldCamera *camera, Gimmick41CameraRequest *request, int frames);
extern int func_0218FE50(struct FieldCamera *camera);
extern void func_0218E13C(struct FieldCamera *camera, u32 mode);
extern void func_0218EC54(struct FieldCamera *camera);
extern int func_0218EC60(u32 camera);
extern void func_0218F930(struct FieldCamera *camera, VecFx32 *eyeGoal, VecFx32 *targetGoal,
                          Gimmick41CameraChannels *channels, u16 frames);
extern Gimmick41CameraView *func_0218FE70(struct FieldCamera *camera);
extern void func_0218F9C4(struct FieldCamera *camera, Gimmick41CameraChannels *channels, u16 frames);

void func_021F36C0(struct FieldMap *fieldMap);
void func_021F37B8(struct FieldMap *fieldMap);
void func_021F37D4(struct FieldMap *fieldMap);
struct GameEvent *func_021F37E0(struct GameSystem *gameSystem);
int func_021F3884(struct GameEvent *event, int *seq, void *eventWork);
u8 func_021F3EE4(int cellX, int cellZ);
u16 func_021F3F18(int direction);
int func_021F3F44(int facing);
int func_021F3F70(int direction, int turns);
int func_021F3FC0(unsigned int facing, int cannonIndex);

extern int d_021F40A4;
extern Gimmick41PosTable d_021F4208;
extern const u8 d_021F4660[];
extern s16 d_020A1B38[];
extern Gimmick41Flight d_021F4320[][GIMMICK41_DIRECTION_COUNT];
extern Gimmick41CameraInfo d_021F4198[];
extern Gimmick41CannonCell d_021F40F0[];
extern u16 d_021F4084[];
extern u16 d_021F408C[];
extern u16 d_021F4094[];
extern u16 d_021F409C[];
extern u16 d_021F40B4[];
extern Gimmick41DirTable d_021F4080;

/* Load the cannon models, place and turn them, and stop their animations. */
void func_021F36C0(struct FieldMap *fieldMap)
{
    G3dObjectStatus *status;
    unsigned int i;
    u8 j;
    int sinCosIndex;
    Gimmick41PosTable cannonPos;
    FldExpObjCnt *expObj;

    expObj = func_02188D2C(fieldMap);
    func_02189764(fieldMap, 1, func_02188C84(fieldMap), sizeof(Gimmick41Work));
    func_021BE760(expObj, (const G3dUtilSetup *)&d_021F40A4, 0);
    i = 0;
    cannonPos = d_021F4208;
    for (; i < GIMMICK41_CANNON_COUNT; i = (u8)(i + 1)) {
        status = func_021BE480(expObj, 0, (u16)i);
        func_021BE4A4(expObj, 0, i, 1);
        status->trans = cannonPos.pos[i];
        sinCosIndex = ((d_021F4660[i] << 14) >> 4) * 2;
        func_0207AF1C(&status->rotate, d_020A1B38[sinCosIndex], d_020A1B38[sinCosIndex + 1]);
        for (j = 0; j < GIMMICK41_DIRECTION_COUNT; j++) {
            func_021BE6B8(func_021BE674(expObj, 0, (u16)i, (u16)(j * 2)), 0);
            func_021BE6B8(func_021BE674(expObj, 0, (u16)i, (u16)(j * 2 + 1)), 0);
        }
    }
}

void func_021F37B8(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj = func_02188D2C(fieldMap);

    func_021897A0(fieldMap, 1);
    func_021BE418(expObj, 0);
}

void func_021F37D4(struct FieldMap *fieldMap)
{
    func_021BE580(func_02188D2C(fieldMap));
}

/*
 * Field event check: the player faces the cell two steps before a cannon.
 * Create the launch event for that cannon; null when no cannon stands there.
 */
struct GameEvent *func_021F37E0(struct GameSystem *gameSystem)
{
    struct FieldMap *fieldMap;
    struct FieldPlayer *player;
    Gimmick41Work *work;
    VecFx32 playerPos;
    int cellX;
    int cellZ;
    int facing;
    u8 cannonIndex;
    struct GameEvent *event;

    fieldMap = func_0201210C(gameSystem);
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), 5);
    work = func_021897BC(fieldMap, 1);
    player = func_02188CB4(fieldMap);
    func_021A3038(player, &playerPos);
    cellX = playerPos.x / 0x10000;
    cellZ = playerPos.z / 0x10000;
    facing = func_021A3050(player);
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
    cannonIndex = func_021F3EE4(cellX, cellZ);
    if (cannonIndex >= GIMMICK41_CANNON_COUNT) {
        return 0;
    }
    event = func_020122C0(gameSystem, 0, func_021F3884, 0);
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
 *   - seq 2, 4, 5: `animeValue = func_021BE6E8(...)` then `animeValue / 4096` at each compare (the r*2
 *     index is then computed before the divide, as in the image).
 *   - all aggregate locals (request, pos, base, end, start, channels) are block-scoped where they are
 *     used; their slots then follow the order of appearance, and `VecFx32 x = {0, 0, 0}` gives the
 *     `add rN,sp,#K; str [rN]` zeroing form.
 *   - the tail after the switch is `if (work->flying != 0) { ... } return 0;` (one shared epilogue).
 *   - the tail uses its own local tailPlayerMmdl (declared between direction and ringIndex) for its
 *     spill slot.
 */
int func_021F3884(struct GameEvent *event, int *seq, void *eventWork)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    Gimmick41Work *work;
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

    fieldMap = func_0201210C(func_020124E4(event));
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);
    camera = func_02188C58(fieldMap);
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), 5);
    switch (*seq) {
    case 0:
        func_0218F0A8(camera);
        func_021F3FEC(&work->bounce);
        (*seq)++;
        break;
    case 1:
        if ((int)func_0218F0E8(camera) != 0)
            break;
        cannonRow = work->cannonIndex;
        ringIndex = func_021F3F44(work->facing);
        animeValue = d_021F4320[work->cannonIndex][ringIndex].icaDataId;
        if (animeValue == -1)
            return 1;
        work->flightAnime = ICA_ANIME_CreateWithFullBuffer(0x8015, 0x79, animeValue, work->icaBuffer, 0x708);
        work->frameCount = ICA_ANIME_GetFrameNum(work->flightAnime);
        cameraInfoIndex = d_021F4320[cannonRow][ringIndex].cameraInfoIndex;
        followFrames = d_021F4198[cameraInfoIndex].followFrames;
        returnFrames = d_021F4198[cameraInfoIndex].returnFrames;
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
        initAnimeSlot = func_021F3F18(func_021F3FC0(work->facing, cannonIndex));
        func_021BE700(expObj, 0, (u16)cannonIndex, (u16)initAnimeSlot, 1);
        func_021BE700(expObj, 0, (u16)cannonIndex, (u16)(initAnimeSlot + 1), 1);
        func_021BE6CC(expObj, 0, cannonIndex, initAnimeSlot, 0);
        func_021BE6CC(expObj, 0, cannonIndex, initAnimeSlot + 1, 0);
        func_0218F818(camera);
        (*seq)++;
        break;
    case 2:
        cannonIndex = work->cannonIndex;
        direction = func_021F3FC0(work->facing, cannonIndex);
        animeValue = func_021BE6E8(expObj, 0, (u16)cannonIndex, (u16)func_021F3F18(direction));
        if (animeValue / 4096 == d_021F4084[direction])
            func_020061E4(0x698);
        if (animeValue / 4096 < d_021F408C[direction])
            break;
        pauseAnimeSlot = func_021F3F18(direction);
        func_021BE6B0(func_021BE674(expObj, 0, (u16)cannonIndex, (u16)pauseAnimeSlot), 1);
        func_021BE6B0(func_021BE674(expObj, 0, (u16)cannonIndex, (u16)(pauseAnimeSlot + 1)), 1);
        func_02158780(event, 2, 0, 0, 0x8015);
        cameraInfoIndex = d_021F4320[work->cannonIndex][func_021F3F44(work->facing)].cameraInfoIndex;
        {
        Gimmick41CameraRequest request;
        request.goal.pitch = d_021F4198[cameraInfoIndex].pitch;
        request.goal.yaw = d_021F4198[cameraInfoIndex].yaw;
        request.channels.shift = 0;
        request.channels.pitch = 1;
        request.channels.yaw = 1;
        request.channels.distance = 0;
        request.channels.fov = 0;
        func_0218F900(camera, &request, d_021F4198[cameraInfoIndex].moveFrames);
        }
        (*seq)++;
        break;
    case 3:
        if (func_0218FE50(camera) != 0)
            break;
        func_0218E13C(camera, 2);
        playerMmdl = func_021A3074(func_02188CB4(fieldMap));
        func_0216DAC8(playerMmdl, 1);
        func_0216D548(playerMmdl, 0x200);
        func_0216D568(playerMmdl, 0x8000);
        cannonIndex = work->cannonIndex;
        playAnimeSlot = func_021F3F18(func_021F3FC0(work->facing, cannonIndex));
        func_021BE6B0(func_021BE674(expObj, 0, (u16)cannonIndex, (u16)playAnimeSlot), 0);
        func_021BE6B0(func_021BE674(expObj, 0, (u16)cannonIndex, (u16)(playAnimeSlot + 1)), 0);
        func_020061E4(0x699);
        (*seq)++;
        break;
    case 4:
        cannonIndex = work->cannonIndex;
        direction = func_021F3FC0(work->facing, cannonIndex);
        animeValue = func_021BE6E8(expObj, 0, (u16)cannonIndex, (u16)func_021F3F18(direction));
        if (animeValue / 4096 < d_021F409C[direction])
            break;
        func_020061E4(0x6A0);
        work->flying = 1;
        work->frame = 0;
        (*seq)++;
        break;
    case 5:
        cannonIndex = work->cannonIndex;
        direction = func_021F3FC0(work->facing, cannonIndex);
        animeValue = func_021BE6E8(expObj, 0, (u16)cannonIndex, (u16)func_021F3F18(direction));
        if (animeValue / 4096 == d_021F4094[direction]) {
            func_020061E4(0x696);
            if (work->cameraArrived == 0) {
                func_021F3FD8(work);
                func_0218E13C(camera, 1);
            }
            func_0216DAC8(func_021A3074(func_02188CB4(fieldMap)), 0);
        }
        if (work->flying != 0)
            break;
        player = func_02188CB4(fieldMap);
        {
            VecFx32 pos = {0, 0, 0};
            Gimmick41Flight *flight = &d_021F4320[work->cannonIndex][func_021F3F44(work->facing)];
            pos.x = (flight->landX << 16) + 0x8000;
            pos.y = flight->landY << 16;
            pos.z = (flight->landZ << 16) + 0x8000;
            func_021A3044(player, &pos);
        }
        (*seq)++;
        break;
    case 6:
        func_0216D550(func_021A3074(func_02188CB4(fieldMap)), 0x200);
        func_02011558(work->flightAnime);
        cannonIndex = work->cannonIndex;
        endAnimeSlot = func_021F3F18(func_021F3FC0(work->facing, cannonIndex));
        func_021BE700(expObj, 0, (u16)cannonIndex, (u16)endAnimeSlot, 0);
        func_021BE700(expObj, 0, (u16)cannonIndex, (u16)(endAnimeSlot + 1), 0);
        func_0218F05C(camera);
        func_0218F878(camera);
        return 1;
    }
    if (work->flying != 0) {
        {
            VecFx32 flightPos = {0, 0, 0};
            cannonIndex = work->cannonIndex;
            if (ICA_ANIME_GetTranslateAt(work->flightAnime, &flightPos, work->frame) != 0) {
                flightPos.x += (d_021F40F0[cannonIndex].x << 16) + 0x8000;
                flightPos.y += d_021F40F0[cannonIndex].y << 16;
                flightPos.z += (d_021F40F0[cannonIndex].z << 16) + 0x8000;
                func_021A3044(func_02188CB4(fieldMap), &flightPos);
            }
        }
        if (work->bounce.finished != 0 && work->frame < work->cameraFollowEndFrame) {
            VecFx32 playerPos;
            VecFx32 eyePos;
            Gimmick41CameraChannels channels;
            func_021A3038(func_02188CB4(fieldMap), &playerPos);
            if (work->bounce.cameraMoveStarted == 0) {
                func_0218EC54(camera);
                func_0218ECE4(camera, &eyePos);
                channels.target = 1;
                channels.fov = 0;
                channels.shift = 0;
                channels.pitch = 0;
                channels.yaw = 0;
                channels.distance = 0;
                func_0218F930(camera, &eyePos, &playerPos, &channels, work->cameraFollowEndFrame - work->frame);
                work->bounce.cameraMoveStarted = 1;
            } else {
                func_0218FE70(camera)->target = playerPos;
            }
        }
        if (work->frame == work->cameraFollowEndFrame) {
            if (work->bounce.active != 0)
                work->bounce.active = 0;
            func_0218EC60((u32)camera);
            func_0218E13C(camera, 0);
            {
            Gimmick41CameraChannels returnChannels;
            returnChannels.shift = 1;
            returnChannels.pitch = 1;
            returnChannels.yaw = 1;
            returnChannels.distance = 1;
            returnChannels.fov = 1;
            returnChannels.target = 0;
            func_0218F9C4(camera, &returnChannels, work->cameraReturnFrames);
            }
            work->cameraArrived = 1;
        }
        cannonRow = work->cannonIndex;
        cameraInfoIndex = d_021F4320[cannonRow][func_021F3F44(work->facing)].cameraInfoIndex;
        tailPlayerMmdl = func_021A3074(func_02188CB4(fieldMap));
        if (work->frame == work->frameCount - 1 - d_021F40B4[cameraInfoIndex] && cameraInfoIndex != 11) {
            func_0216D570(tailPlayerMmdl, 0x8000);
            func_020061E4(0x697);
        }
        if (cameraInfoIndex == 11) {
            if (work->frame == 0x46)
                func_020061E4(0x6A1);
            if (work->frame + 8 >= work->frameCount) {
                if ((int)func_0216D57C(tailPlayerMmdl, 0x8000) != 0)
                    func_0216D570(tailPlayerMmdl, 0x8000);
            }
        }
        work->frame += 1;
        if (work->frame >= work->frameCount)
            work->flying = 0;
        func_021F4000(&work->bounce, camera);
    }
    return 0;
}

/* Find the cannon whose cell is (cellX, cellZ); GIMMICK41_CANNON_COUNT when none. */
u8 func_021F3EE4(int cellX, int cellZ)
{
    u8 i;

    for (i = 0; i < GIMMICK41_CANNON_COUNT; i++) {
        if (cellX == d_021F40F0[i].x && cellZ == d_021F40F0[i].z) {
            return i;
        }
    }
    return i;
}

/*
 * An unlabelled leaf (no lr save) next to func_021F3F44: the first animation
 * slot of a direction (two slots per direction). Callee of func_021F3884.
 */
u16 func_021F3F18(int direction)
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
int func_021F3F44(int facing)
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
int func_021F3F70(int direction, int turns)
{
    Gimmick41DirTable ring = d_021F4080;
    u8 i;
    u8 turned;

    for (i = 0; i < GIMMICK41_DIRECTION_COUNT; i++) {
        if (ring.direction[i] == direction) {
            turned = (i + turns) % 4;
            return ring.direction[turned];
        }
    }
    return direction;
}

/* The direction of a cannon as the player sees it: facing turned by the cannon rotation. */
int func_021F3FC0(unsigned int facing, int cannonIndex)
{
    return func_021F3F70(func_021F3F44(facing), d_021F4660[cannonIndex]);
}

/* Start the camera bounce. */
void func_021F3FD8(Gimmick41Work *work)
{
    func_021F3FEC(&work->bounce);
    work->bounce.active = 1;
}

/*
 * extent: 18 bytes of code followed by two zero alignment bytes.
 */
void func_021F3FEC(Gimmick41Bounce *bounce)
{
    bounce->active = 0;
    bounce->finished = 0;
    bounce->cameraMoveStarted = 0;
    bounce->phase = 0;
    bounce->wait = 0;
    bounce->downSteps = 0;
    bounce->tick = 0;
}
