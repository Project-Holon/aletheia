/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F3938, func_021F395C, func_021F398C, func_021F3A28, func_021F3AC0, func_021F3D78, func_021F3ECC, func_021F3EEC, func_021F3F38, func_021F3FBC, func_021F3FE8, func_021F4174, func_021F41B8, func_021F4210
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
 *   d_021F4510     0x021F4510  data  a4
 *   d_021F4480     0x021F4480  data  a4
 *   d_021F4318     0x021F4318  data  a4
 *   d_021F4358     0x021F4358  data  a4
 *   d_021F434C     0x021F434C  data  a4
 *   d_021F4340     0x021F4340  data  a4
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C64  0x02188C64  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_0218CEE0  0x0218CEE0  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021C0628  0x021C0628  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A01BC  0x021A01BC  thumb  ov021
 *   func_021A01B4  0x021A01B4  thumb  ov021
 *   sub_02030344   0x02030344  arm
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021BE580 0x021BE580 thumb ov021
 *   func_0201210C  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   d_021F4490    0x021F4490  data  a4
 *   func_020124E4  0x020124E4  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_021C06C0  0x021C06C0  thumb  ov021
 *   func_021A0244  0x021A0244  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218EC30  0x0218EC30  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   d_021F4328     0x021F4328  data  ov043
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_02188C68  0x02188C68  thumb  ov021
 *   func_021A03A4  0x021A03A4  thumb  ov021
 *   func_021A03B8  0x021A03B8  thumb  ov021
 *   func_021A01FC  0x021A01FC  thumb  ov021
 *   func_0218ECC4  0x0218ECC4  thumb  ov021
 *   func_0218ECD4  0x0218ECD4  thumb  ov021
 */
#include "unit_021F36C0_types.h"

struct GameData;
struct FieldSave;
struct GameEvent;

extern void *func_02188D2C(void *fieldMap);
extern void *func_02188C64(void *fieldMap);
extern void *func_02188C80(void *fieldMap);
extern u16 func_02188C84(u8 *fieldMap);
extern void *func_02188C98(void *fieldMap);
extern void *func_02188CB4(void *fieldMap);
extern void *func_0218CEE0(void *g3dMapper);
extern void *func_02189764(unsigned char *fieldMap, int id, int a, int size);
extern void *func_020120F4(void *gameSystem);
extern struct FieldSave *func_02012EC4(struct GameData *gameData);
extern Gimmick43Save *func_0200B3A4(struct FieldSave *fieldSave, u32 blockId);
extern void  func_021C0628(u8 areaId, int tileX, int tileZ, int width, int depth, int height, int c, void *heightEx);
extern void  func_021BE760(void *expObj, void *unitDesc, int b);
extern VecFx32 *func_021BE480(void *expObj, unsigned unit, u16 model);
extern void func_021BE4A4(void *expObj, int unit, int model, int visible);
extern void *func_021BE674(void *expObj, int unit, u16 model, u16 animeIdx);
extern void func_021BE6B8(unsigned char *anime, int loop);
extern void func_021BE6B0(unsigned char *anime, int paused);
extern void func_021BE700(void *expObj, int unit, u16 model, u16 animeIdx, int enabled);
extern int func_021BE748(void *anime);
extern void func_021BE6CC(void *expObj, int unit, int model, int animeIdx, int frame);
extern void func_021A3038(unsigned char *player, VecFx32 *out);
extern int   func_021A01BC(void *fog, u32 offset);
extern int   func_021A01B4(void *fog, u32 slope);
extern void *sub_02030344(u32 heapId);
extern void *func_021897BC(void *fieldMap, int id);
extern void func_021897A0(void *fieldMap, int id);
extern void func_021BE418(u8 *expObj, u16 unit);
extern void func_021BE580(void *expObj);
extern void *func_0201210C(void *gameSystem);
extern struct GameEvent *func_020122C0(void *owner, void *a, void *eventFunc, u32 size);
extern void *func_020124E4(void *event);
extern void *func_02188C58(void *fieldMap);
extern void *func_02188C7C(unsigned char *fieldMap);
extern int func_0216DD1C(void *mmdlSys, void **out, int *iter);
extern int func_0216D83C(void *mmdl);
extern int func_0216D86C(void *mmdl);
extern void func_0216D88C(void *mmdl, VecFx32 *out);
extern VecFx32 *func_0216D888(void *mmdl);
extern void func_0216D85C(void *mmdl, int gridY);
extern void func_0216D89C(void *mmdl, VecFx32 *pos);
extern void func_0218F0A8(u8 *camera);
extern u32 func_0218F0E8(u8 *camera);
extern void func_0218F05C(unsigned char *camera);
extern void func_020061E4(u32 seId);
extern int func_021BE6BC(void *anime);
extern void func_021C06C0(u8 areaId, int height, void *heightEx);
extern int func_021A0244(void *fog);
extern u32 func_0218EC5C(u8 *camera);
extern void func_0218EC54(u8 *camera);
extern void func_0218EC30(u8 *camera, int target);
extern void func_021A3044(u8 *player, VecFx32 *pos);
extern int func_02006148(u32 seId);
extern void func_020061F8(int slot);
extern void *func_02188C68(void *fieldMap);
extern int func_021A03A4(void *zoneFog);
extern int func_021A03B8(void *zoneFog);
extern void func_021A01FC(void *fog, u32 offset, u32 slope, u32 frames);
extern void func_0218ECC4(u8 *camera, VecFx32 *out);
extern void func_0218ECD4(u8 *camera, VecFx32 *shift);
void func_021F36C0(void *fieldMap);
void func_021F3938(u8 *fieldMap);
void func_021F395C(u8 *fieldMap);
void *func_021F398C(void *gameSystem, int liftIndex);
void func_021F3A28(void *gameSystem, int isRising);
int func_021F3AC0(void *event, int *seq);
int func_021F3D78(void *event, int *seq);
int func_021F3ECC(Gimmick43Work *work);
int func_021F3EEC(u8 liftIndex, int tileX, int tileZ);
void func_021F3F38(Gimmick43Save *save, void *expObj, int liftIndex);
int func_021F3FBC(Gimmick43Save *save, int liftIndex);
void func_021F3FE8(void *gameSystem);
void func_021F4174(void *expObj);
void func_021F41B8(u8 liftIndex, int stepY, int isStart, u8 *camera, CameraShake *shake);
int func_021F4210(CameraShake *shake);
extern const HeightRegion d_021F4510[];
extern const LiftZone d_021F4480[];
extern int d_021F4318;
extern const VecFx32 d_021F4358[];
extern const VecFx32 d_021F434C;
extern const VecFx32 d_021F4340;
extern LiftHeights d_021F4490[];
extern int d_021F4328[];




void func_021F36C0(void *fieldMap)
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

    expObj = func_02188D2C(fieldMap);
    fog = func_02188C64(fieldMap);
    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK43_SAVE_BLOCK);
    func_02189764(fieldMap, 1, func_02188C84(fieldMap), sizeof(Gimmick43Work));
    heightEx = func_0218CEE0(func_02188C98(fieldMap));
    for (i = 0; i < GIMMICK43_FIXED_AREA_COUNT; i++) {
        func_021C0628(i, d_021F4510[i].tileX, d_021F4510[i].tileZ, d_021F4510[i].width,
                      d_021F4510[i].depth, d_021F4510[i].height, 0x800000, heightEx);
    }
    for (i = 0; i < GIMMICK43_LIFT_COUNT; i++) {
        areaId = i + 8;
        if (save->liftState[i] != 0) {
            state = 1;
        } else {
            state = 0;
        }
        func_021C0628(areaId, d_021F4480[i].tileX, d_021F4480[i].tileZ, d_021F4480[i].width,
                      d_021F4480[i].depth, d_021F4480[i].height[state], 0x800000, heightEx);
    }
    func_021BE760(expObj, &d_021F4318, 0);
    for (i = 0; i < GIMMICK43_LIFT_COUNT; i++) {
        modelPos = func_021BE480(expObj, 0, i);
        *modelPos = d_021F4358[i];
        state = save->liftState[i] ? 1 : 0;
        modelPos->y = d_021F4480[i].height[state];
        func_021BE4A4(expObj, 0, (u16)i, 1);
        for (animeIdx = 0; animeIdx < 2; animeIdx++) {
            anime = func_021BE674(expObj, 0, i, animeIdx);
            func_021BE6B8(anime, 0);
            func_021BE6B0(anime, 1);
        }
        func_021F3F38(save, expObj, i);
    }
    modelPos = func_021BE480(expObj, 0, GIMMICK43_ELEVATOR);
    *modelPos = d_021F434C;
    func_021BE4A4(expObj, 0, (u16)GIMMICK43_ELEVATOR, 1);
    for (animeIdx = 0; animeIdx < 2; animeIdx++) {
        anime = func_021BE674(expObj, 0, GIMMICK43_ELEVATOR, animeIdx);
        func_021BE6B8(anime, 0);
        func_021BE6B0(anime, 1);
    }
    func_021F4174(expObj);
    modelPos = func_021BE480(expObj, 0, GIMMICK43_OBSTACLE);
    *modelPos = d_021F4340;
    func_021BE4A4(expObj, 0, (u16)GIMMICK43_OBSTACLE, 1);
    func_021BE700(expObj, 0, GIMMICK43_OBSTACLE, 0, 1);
    anime = func_021BE674(expObj, 0, GIMMICK43_OBSTACLE, 0);
    func_021BE6B8(anime, 0);
    func_021BE6B0(anime, 1);
    if (save->obstacleBroken) {
        func_021BE6CC(expObj, 0, GIMMICK43_OBSTACLE, 0, func_021BE748(anime));
    }
    func_021A3038(func_02188CB4(fieldMap), &playerPos);
    if (playerPos.y <= -0x280000) {
        func_021A01BC(fog, 0x7FDF);
        func_021A01B4(fog, 9);
    }
    sub_02030344(0x15);
}



void func_021F3938(u8 *fieldMap)
{
    void *expObj = func_02188D2C(fieldMap);
    func_021897BC(fieldMap, 1);
    func_021897A0(fieldMap, 1);
    func_021BE418(expObj, 0);
}



void func_021F395C(u8 *fieldMap)
{
    void *expObj = func_02188D2C(fieldMap);
    func_021897BC(fieldMap, 1);
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK43_SAVE_BLOCK);
    func_021BE580(expObj);
}




void *func_021F398C(void *gameSystem, int liftIndex)
{
    void *fieldMap;
    Gimmick43Save *save;
    Gimmick43Work *work;
    int step;

    fieldMap = func_0201210C(gameSystem);
    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK43_SAVE_BLOCK);
    work = func_021897BC(fieldMap, 1);
    if (liftIndex >= GIMMICK43_LIFT_COUNT) {
        return 0;
    }
    work->liftIndex = liftIndex;
    if (save->liftState[liftIndex] != 0) {
        work->curY = d_021F4490[liftIndex].y[1];
        work->goalY = d_021F4490[liftIndex].y[0];
    } else {
        work->curY = d_021F4490[liftIndex].y[0];
        work->goalY = d_021F4490[liftIndex].y[1];
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
    return func_020122C0(gameSystem, 0, func_021F3AC0, 0);
}




void func_021F3A28(void *gameSystem, int isRising)
{
    void *fieldMap;
    Gimmick43Work *work;
    void *expObj;
    int step;

    fieldMap = func_0201210C(gameSystem);
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK43_SAVE_BLOCK);
    work = func_021897BC(fieldMap, 1);
    work->isRising = isRising;
    if (isRising) {
        work->curY = 0x320000;
        work->goalY = 0x370000;
    } else {
        work->curY = 0x370000;
        work->goalY = 0x320000;
        expObj = func_02188D2C(fieldMap);
        func_021BE700(expObj, 0, GIMMICK43_ELEVATOR, 1, 1);
        func_021BE700(expObj, 0, GIMMICK43_ELEVATOR, 0, 0);
    }
    step = work->goalY - work->curY;
    if (step < 0) {
        step = -0x2000;
    } else {
        step = 0x2000;
    }
    work->stepY = step;
    func_020122C0(gameSystem, 0, func_021F3D78, 0);
}




int func_021F3AC0(void *event, int *seq)
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
    fieldMap = func_0201210C(gameSystem);
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);
    camera = func_02188C58(fieldMap);
    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK43_SAVE_BLOCK);
    switch (*seq) {
    case 0:
        riderCount = 0;
        iter = 0;
        mmdlSys = func_02188C7C(fieldMap);
        for (i = 0; i < GIMMICK43_RIDER_MAX; i++) {
            work->riders[i] = 0;
        }
        func_021A3038(func_02188CB4(fieldMap), &playerPos);
        while (func_0216DD1C(mmdlSys, &mmdl, &iter) == 1) {
            tileX = func_0216D83C(mmdl);
            tileZ = func_0216D86C(mmdl);
            if (func_021F3EEC(work->liftIndex, tileX, tileZ)) {
                func_0216D88C(mmdl, &mmdlPos);
                if (playerPos.y - 0x10000 < mmdlPos.y && mmdlPos.y < playerPos.y + 0x10000 && riderCount < GIMMICK43_RIDER_MAX) {
                    work->riders[riderCount++] = mmdl;
                }
            }
        }
        func_021F41B8(work->liftIndex, work->stepY, 1, camera, &work->shake);
        (*seq)++;
        break;
    case 1:
        if (func_021F4210(&work->shake)) {
            (*seq)++;
        }
        break;
    case 2:
        func_0218F0A8(camera);
        (*seq)++;
        break;
    case 3:
        if (func_0218F0E8(camera) != 0) {
            break;
        }
        func_020061E4(0x6ca);
        (*seq)++;
    case 4:
        if (work->isStalled == 0) {
            work->curY += work->stepY;
        }
        if (func_021F3ECC(work)) {
            work->curY = work->goalY;
            func_021F41B8(work->liftIndex, work->stepY, 0, camera, &work->shake);
            func_020061E4(0x6cb);
            (*seq)++;
        }
        func_021BE480(expObj, 0, work->liftIndex)->y = work->curY;
        for (i = 0; i < GIMMICK43_RIDER_MAX; i++) {
            rider = work->riders[i];
            if (rider != 0) {
                ridePos = *func_0216D888(rider);
                ridePos.y = work->curY;
                func_0216D85C(rider, (s16)((ridePos.y >> 4) / 4096));
                func_0216D89C(rider, &ridePos);
            }
        }
        break;
    case 5:
        if (func_021F4210(&work->shake)) {
            (*seq)++;
        }
        break;
    case 6:
        func_0218F05C(camera);
        animeIdx = work->liftIndex;
        func_021BE6B0(func_021BE674(expObj, 0, (u16)animeIdx, (u16)func_021F3FBC(save, animeIdx)), 0);
        (*seq)++;
        break;
    case 7:
        animeIdx = work->liftIndex;
        anime = func_021BE674(expObj, 0, (u16)animeIdx, (u16)func_021F3FBC(save, animeIdx));
        becameOn = 0;
        if (func_021BE6BC(anime) == 0) {
            break;
        }
        if (save->liftState[work->liftIndex]) {
            save->liftState[work->liftIndex] = 0;
        } else {
            save->liftState[work->liftIndex] = 1;
            becameOn = 1;
        }
        heightEx = func_0218CEE0(func_02188C98(fieldMap));
        func_021C06C0(work->liftIndex + 8, d_021F4490[work->liftIndex].y[becameOn], heightEx);
        func_021F3F38(save, expObj, work->liftIndex);
        if (work->liftIndex != GIMMICK43_BIG_LIFT) {
            return 1;
        }
        (*seq)++;
        break;
    case 8:
        if (func_021A0244(func_02188C64(fieldMap)) == 0) {
            return 1;
        }
        break;
    }
    func_021F3FE8(gameSystem);
    return 0;
}




int func_021F3D78(void *event, int *seq)
{
    void *fieldMap;
    void *expObj;
    Gimmick43Work *work;
    u8 *camera;
    void *player;
    VecFx32 pos;

    fieldMap = func_0201210C(func_020124E4(event));
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);
    camera = func_02188C58(fieldMap);
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK43_SAVE_BLOCK);
    switch (*seq) {
    case 0:
        if (work->isRising != 0) {
            work->savedCameraTarget = func_0218EC5C(camera);
            func_0218EC54(camera);
        }
        func_020061E4(work->isRising == 0 ? 0x6da : 0x6ca);
        (*seq)++;
        break;
    case 1:
        work->curY += work->stepY;
        if (func_021F3ECC(work)) {
            work->curY = work->goalY;
            if (work->isRising == 0) {
                func_021F41B8(0xff, work->stepY, 0, camera, &work->shake);
                func_020061E4(0x6cb);
            }
            (*seq)++;
        }
        func_021BE480(expObj, 0, GIMMICK43_ELEVATOR)->y = work->curY;
        player = func_02188CB4(fieldMap);
        func_021A3038(player, &pos);
        pos.y = work->curY;
        func_021A3044(player, &pos);
        break;
    case 2:
        if (work->isRising != 0) {
            return 1;
        }
        if (func_021F4210(&work->shake)) {
            if (work->savedCameraTarget != 0) {
                func_0218EC30(camera, work->savedCameraTarget);
            }
            func_021BE6B0(func_021BE674(expObj, 0, GIMMICK43_ELEVATOR, 1), 0);
            (*seq)++;
        }
        break;
    case 3:
        if (func_021BE6BC(func_021BE674(expObj, 0, GIMMICK43_ELEVATOR, 1))) {
            func_021F4174(expObj);
            return 1;
        }
        break;
    }
    return 0;
}



int func_021F3ECC(Gimmick43Work *work)
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
 * Unlabelled leaf called only from func_021F3AC0. Each field gets its own
 * pool word (d_021F4480 + 0/8/4/C). The loads must be written in field
 * order tileX, tileZ, width, depth: loading width before tileZ swaps the
 * index and value registers (17 bytes).
 */
int func_021F3EEC(u8 liftIndex, int tileX, int tileZ)
{
    int x0;
    int z0;
    int width;
    int depth;

    x0 = d_021F4480[liftIndex].tileX;
    z0 = d_021F4480[liftIndex].tileZ;
    width = d_021F4480[liftIndex].width;
    depth = d_021F4480[liftIndex].depth;
    if (x0 <= tileX && tileX <= x0 + width - 1 && z0 <= tileZ && tileZ <= z0 + depth - 1) {
        return 1;
    }
    return 0;
}




void func_021F3F38(Gimmick43Save *save, void *expObj, int liftIndex)
{
    int shownAnime, hiddenAnime;

    if (save->liftState[liftIndex]) {
        if (d_021F4328[liftIndex]) {
            shownAnime = 0;
            hiddenAnime = 1;
        } else {
            shownAnime = 1;
            hiddenAnime = 0;
        }
    } else {
        if (d_021F4328[liftIndex]) {
            shownAnime = 1;
            hiddenAnime = 0;
        } else {
            shownAnime = 0;
            hiddenAnime = 1;
        }
    }
    func_021BE700(expObj, 0, liftIndex, shownAnime, 1);
    func_021BE700(expObj, 0, liftIndex, hiddenAnime, 0);
    func_021BE6CC(expObj, 0, (u16)liftIndex, (u16)shownAnime, 0);
    func_021BE6B0(func_021BE674(expObj, 0, liftIndex, shownAnime), 1);
}




int func_021F3FBC(Gimmick43Save *save, int liftIndex)
{
    int animeIdx;

    if (save->liftState[liftIndex]) {
        if (d_021F4328[liftIndex]) {
            animeIdx = 0;
        } else {
            animeIdx = 1;
        }
    } else {
        if (d_021F4328[liftIndex]) {
            animeIdx = 1;
        } else {
            animeIdx = 0;
        }
    }
    return animeIdx;
}




/*
 * func_02188C64's result is bound to zoneFog before the A01FC call: passed inline,
 * the ternary fourth argument is evaluated before the call.
 */
void func_021F3FE8(void *gameSystem)
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

    fieldMap = func_0201210C(gameSystem);
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);
    camera = func_02188C58(fieldMap);
    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK43_SAVE_BLOCK);
    if (work->liftIndex != GIMMICK43_BIG_LIFT) {
        return;
    }
    if (save->obstacleBroken == 0 && work->curY <= -0x230000) {
        save->obstacleBroken = 1;
        func_021BE6B0(func_021BE674(expObj, 0, GIMMICK43_OBSTACLE, 0), 0);
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
            func_021F41B8(work->liftIndex, work->stepY, 0, camera, &work->shake);
            func_020061E4(0x6cb);
            work->stallStage++;
            break;
        case 1:
            if (func_021F4210(&work->shake)) {
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
                zoneFog = func_02188C68(fieldMap);
                hasFogTarget = 1;
                fogOffset = func_021A03A4(zoneFog);
                fogSlope = func_021A03B8(zoneFog);
            }
        } else {
            if (work->curY <= -0x310000) {
                hasFogTarget = 1;
                fogOffset = 0x7fdf;
                fogSlope = 9;
            }
        }
        if (hasFogTarget) {
            zoneFog = func_02188C64(fieldMap);
            func_021A01FC(zoneFog, fogOffset, fogSlope, work->stepY == -0x2000 ? 0x20 : 0x10);
            work->isFogCheckPending = 0;
        }
    }
    if (work->obstacleAnimeState != 0) {
        if (work->obstacleAnimeState == 1) {
            work->obstacleAnimeState = 2;
            return;
        }
        if (func_021BE6BC(func_021BE674(expObj, 0, GIMMICK43_OBSTACLE, 0))) {
            func_020061F8(func_02006148(0x6cd));
            work->obstacleAnimeState = 0;
        }
    }
}




void func_021F4174(void *expObj)
{
    func_021BE700(expObj, 0, GIMMICK43_ELEVATOR, 0, 1);
    func_021BE700(expObj, 0, GIMMICK43_ELEVATOR, 1, 0);
    func_021BE6CC(expObj, 0, GIMMICK43_ELEVATOR, 0, 0);
    expObj = func_021BE674(expObj, 0, GIMMICK43_ELEVATOR, 0);
    func_021BE6B0(expObj, 1);
}




void func_021F41B8(u8 liftIndex, int stepY, int isStart, u8 *camera, CameraShake *shake)
{
    shake->phase = 0;
    shake->count = 0;
    shake->camera = camera;
    shake->savedCameraTarget = func_0218EC5C(camera);
    func_0218ECC4(camera, &shake->savedShift);
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




int func_021F4210(CameraShake *shake)
{
    VecFx32 shift;

    switch (shake->phase) {
    case 0:
        func_0218EC54(shake->camera);
        shake->phase++;
    case 1:
        if (shake->frameParity % 2 == 0) {
            func_0218ECC4(shake->camera, &shift);
            shift.y = shift.y + shake->amplitude;
            func_0218ECD4(shake->camera, &shift);
            shake->amplitude *= -1;
            shake->count++;
            if (shake->count >= shake->halfCycles * 2) {
                if (shake->savedCameraTarget) {
                    func_0218EC30(shake->camera, shake->savedCameraTarget);
                }
                func_0218ECD4(shake->camera, &shake->savedShift);
                return 1;
            }
        }
        shake->frameParity = (shake->frameParity + 1) % 2;
    }
    return 0;
}
