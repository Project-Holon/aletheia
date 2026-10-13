/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F3790, func_021F37AC, func_021F37B8, func_021F384C, func_021F3970, func_021F3A44, func_021F3AC0, func_021F3ADC, func_021F3AF8, func_021F3BAC
 * address:  0x021F36C0
 * region:   ov064
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   d_021F3C20     0x021F3C20  data  a4
 *   d_021F3C30     0x021F3C30  data  a4
 *   func_021897A0  0x021897A0  thumb  ov021
 *   func_021BE418  0x021BE418  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE6E8  0x021BE6E8  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_021F3BD8  0x021F3BD8  thumb  ov064
 */
#include "unit_021F36C0_types.h"

struct GameEvent;

extern void *func_02188D2C(void *fieldMap);
extern u16 func_02188C84(void *fieldMap);
extern Gimmick64Work *func_02189764(void *fieldMap, int id, int heapId, int size);
extern u32 GPOWER_GetSpecialPowerId(void);
extern void func_021BE760(void *expObj, void *unitDesc, int b);
extern void func_021BE4B4(void *expObj, int unit, int model, int hidden);
extern void *func_021BE674(void *expObj, int unit, unsigned int model, int animeIdx);
extern void func_021BE6B8(u8 *anime, int loop);
extern void func_021BE6B0(u8 *anime, int paused);
extern void func_021BE700(void *expObj, int unit, int model, u16 animeIdx, int enabled);
extern void func_021897A0(void *fieldMap, int id);
extern void func_021BE418(void *expObj, unsigned short unit);
extern void func_021BE580(void *expObj);
extern void *func_0201210C(void *gameSystem);
extern void *func_02188CB4(void *fieldMap);
extern void func_021A3038(void *player, VecFx32 *out);
extern VecFx32 *func_021BE480(void *expObj, unsigned unit, int model);
extern void func_021BE6CC(void *expObj, int unit, int model, u16 animeIdx, int frame);
extern struct GameEvent *func_020122C0(void *owner, void *a, int (*eventFunc)(void *event, int *seq), u32 size);
extern void *func_020124E4(void *event);
extern Gimmick64Work *func_021897BC(void *fieldMap, int idx);
extern int func_021BE6E8(void *expObj, int unit, int model, int animeIdx);
extern int func_021BE748(u8 *anime);
extern void GFL_USE_StopAllSe(void);
extern void func_020061E4(u32 seId);
extern void func_0204E720(u32 screen, s32 from, s32 to, s32 wait);
extern int func_0204E804(void);
extern int func_021F3BD8(void *event, int *unusedSeq);
void func_021F36C0(void *fieldMap);
void func_021F3790(void *fieldMap);
void func_021F37AC(void *fieldMap);
struct GameEvent *func_021F37B8(void *gameSystem);
int func_021F384C(void *event, int *seq);
void func_021F3970(void *gameSystem, const VecFx32 *startPos, const VecFx32 *endPos, int arcHeight, int frameCount);
void func_021F3A44(void *gameSystem, VecFx32 *pos);
struct GameEvent *func_021F3AC0(void *gameSystem);
struct GameEvent *func_021F3ADC(void *gameSystem);
int func_021F3AF8(void *event, int *unusedSeq);
int func_021F3BAC(void *event, int *unusedSeq);
extern char d_021F3C20[];
extern char d_021F3C30[];

void func_021F36C0(void *fieldMap)
{
    void *expObj;
    Gimmick64Work *work;
    int animeIdx;
    u8 *anime;

    expObj = func_02188D2C(fieldMap);
    work = func_02189764(fieldMap, GIMMICK64_WORK_ID, func_02188C84(fieldMap), sizeof(Gimmick64Work));
    work->fadeWait = 0;
    if (GPOWER_GetSpecialPowerId() == GIMMICK64_SPECIAL_POWER_ID) {
        func_021BE760(expObj, d_021F3C20, 0);
    } else {
        func_021BE760(expObj, d_021F3C30, 0);
    }
    work->fadeTarget = 4;
    func_021BE4B4(expObj, 0, GIMMICK64_PLAYER_MODEL, 1);
    func_021BE4B4(expObj, 0, GIMMICK64_ARC_MODEL, 1);
    for (animeIdx = 0; animeIdx < GIMMICK64_PLAYER_ANIME_COUNT; animeIdx++) {
        anime = func_021BE674(expObj, 0, GIMMICK64_PLAYER_MODEL, (u16)animeIdx);
        func_021BE6B8(anime, 0);
        func_021BE6B0(anime, 1);
        func_021BE700(expObj, 0, GIMMICK64_PLAYER_MODEL, animeIdx, 0);
    }
    for (animeIdx = 0; animeIdx < GIMMICK64_ARC_ANIME_COUNT; animeIdx++) {
        anime = func_021BE674(expObj, 0, GIMMICK64_ARC_MODEL, (u16)animeIdx);
        func_021BE6B8(anime, 0);
        func_021BE6B0(anime, 1);
        func_021BE700(expObj, 0, GIMMICK64_ARC_MODEL, animeIdx, 0);
    }
}

void func_021F3790(void *fieldMap)
{
    void *expObj;

    expObj = func_02188D2C(fieldMap);
    func_021897A0(fieldMap, GIMMICK64_WORK_ID);
    func_021BE418(expObj, 0);
}

void func_021F37AC(void *fieldMap)
{
    func_021BE580(func_02188D2C(fieldMap));
}

/* Shows the player effect model at the player and starts its animes; the returned event ends with the animation. */
struct GameEvent *func_021F37B8(void *gameSystem)
{
    int animeIdx;
    void *fieldMap;
    void *expObj;
    VecFx32 playerPos;

    fieldMap = func_0201210C(gameSystem);
    expObj = func_02188D2C(fieldMap);
    func_021A3038(func_02188CB4(fieldMap), &playerPos);
    *func_021BE480(expObj, 0, GIMMICK64_PLAYER_MODEL) = playerPos;
    func_021BE4B4(expObj, 0, GIMMICK64_PLAYER_MODEL, 0);
    for (animeIdx = 0; animeIdx < GIMMICK64_PLAYER_ANIME_COUNT; animeIdx++) {
        func_021BE6B0(func_021BE674(expObj, 0, GIMMICK64_PLAYER_MODEL, (u16)animeIdx), 0);
        func_021BE700(expObj, 0, GIMMICK64_PLAYER_MODEL, animeIdx, 1);
        func_021BE6CC(expObj, 0, GIMMICK64_PLAYER_MODEL, animeIdx, 0);
    }
    return func_020122C0(gameSystem, 0, func_021F384C, 0);
}

/* Event of the player effect: plays sounds at frames of the first anime and fades the screen out and in
 * around frame 0x65000. Ends when the anime reaches its last frame. */
int func_021F384C(void *event, int *seq)
{
    void *fieldMap;
    void *expObj;
    Gimmick64Work *work;
    int frame;
    int lastFrame;

    fieldMap = func_0201210C(func_020124E4(event));
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, GIMMICK64_WORK_ID);
    frame = func_021BE6E8(expObj, 0, GIMMICK64_PLAYER_MODEL, 0);
    lastFrame = func_021BE748(func_021BE674(expObj, 0, GIMMICK64_PLAYER_MODEL, 0));
    if (frame >= 0 && work->seDone[0] == 0) {
        GFL_USE_StopAllSe();
        func_020061E4(0x7D0);
        work->seDone[0] = 1;
    } else if (frame >= 0x83000 && work->seDone[1] == 0) {
        GFL_USE_StopAllSe();
        func_020061E4(0x7CB);
        work->seDone[1] = 1;
    } else if (frame >= 0x6C000 && work->seDone[2] == 0) {
        GFL_USE_StopAllSe();
        func_020061E4(0x7CC);
        work->seDone[2] = 1;
    } else if (frame >= 0xFA000 && work->seDone[3] == 0) {
        GFL_USE_StopAllSe();
        func_020061E4(0x7F2);
        work->seDone[3] = 1;
    }
    switch (*seq) {
    case 0:
        if (frame == 0x65000) {
            func_0204E720(work->fadeTarget, 0, 0x10, 0);
            work->fadeWait = 15;
            (*seq)++;
        }
        break;
    case 1:
        if (func_0204E804() == 0) {
            if (work->fadeWait <= 0) {
                func_0204E720(work->fadeTarget, 0x10, 0, 0);
                (*seq)++;
            } else {
                work->fadeWait--;
            }
        }
        break;
    case 2:
        if (func_0204E804() == 0) {
            (*seq)++;
        }
        break;
    }
    return frame >= lastFrame;
}

/* Starts the arc effect: the arc model flies from startPos to endPos in frameCount frames, rising by arcHeight at the middle. */
void func_021F3970(void *gameSystem, const VecFx32 *startPos, const VecFx32 *endPos, int arcHeight, int frameCount)
{
    int animeIdx;
    void *fieldMap;
    void *expObj;
    Gimmick64Work *work;

    fieldMap = func_0201210C(gameSystem);
    work = func_021897BC(fieldMap, GIMMICK64_WORK_ID);
    expObj = func_02188D2C(fieldMap);
    func_020061E4(0x566);
    *func_021BE480(expObj, 0, GIMMICK64_ARC_MODEL) = *startPos;
    func_021BE4B4(expObj, 0, GIMMICK64_ARC_MODEL, 0);
    for (animeIdx = 0; animeIdx < GIMMICK64_ARC_ANIME_COUNT; animeIdx++) {
        func_021BE6B0(func_021BE674(expObj, 0, GIMMICK64_ARC_MODEL, (u16)animeIdx), 1);
        func_021BE700(expObj, 0, GIMMICK64_ARC_MODEL, animeIdx, 0);
        func_021BE6CC(expObj, 0, GIMMICK64_ARC_MODEL, animeIdx, 0);
    }
    work->arcStart = *startPos;
    work->arcEnd = *endPos;
    work->arcFrameCount = frameCount;
    work->arcFrame = 0;
    work->arcHeight = arcHeight;
    func_020122C0(gameSystem, 0, func_021F3AF8, 0);
}

/* Shows the arc model at pos and plays its animes. */
void func_021F3A44(void *gameSystem, VecFx32 *pos)
{
    int animeIdx;
    void *expObj;

    expObj = func_02188D2C(func_0201210C(gameSystem));
    func_020061E4(0x567);
    *func_021BE480(expObj, 0, GIMMICK64_ARC_MODEL) = *pos;
    func_021BE4B4(expObj, 0, GIMMICK64_ARC_MODEL, 0);
    for (animeIdx = 0; animeIdx < GIMMICK64_ARC_ANIME_COUNT; animeIdx++) {
        func_021BE6B0(func_021BE674(expObj, 0, GIMMICK64_ARC_MODEL, (u16)animeIdx), 0);
        func_021BE700(expObj, 0, GIMMICK64_ARC_MODEL, animeIdx, 1);
        func_021BE6CC(expObj, 0, GIMMICK64_ARC_MODEL, animeIdx, 0);
    }
}

/* Creates an event that ends once the arc model anime has passed frame 0x5000. */
struct GameEvent *func_021F3AC0(void *gameSystem)
{
    func_0201210C(gameSystem);
    return func_020122C0(gameSystem, 0, func_021F3BAC, 0);
}

/* Creates an event that ends once the arc model anime has stopped. */
struct GameEvent *func_021F3ADC(void *gameSystem)
{
    func_0201210C(gameSystem);
    return func_020122C0(gameSystem, 0, func_021F3BD8, 0);
}

/* Event of the arc effect: moves the arc model one frame along the line from start to end with the extra arc height. */
int func_021F3AF8(void *event, int *unusedSeq)
{
    VecFx32 pos;
    Gimmick64Work *work;
    void *fieldMap;
    void *expObj;
    int frame;
    int frameCount;
    int base;
    int delta;

    fieldMap = func_0201210C(func_020124E4(event));
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, GIMMICK64_WORK_ID);
    work->arcFrame++;
    base = work->arcStart.x;
    frame = work->arcFrame;
    delta = work->arcEnd.x - base;
    frameCount = work->arcFrameCount;
    pos.x = base + delta * frame / frameCount;
    base = work->arcStart.y;
    delta = work->arcEnd.y - base;
    pos.y = base + delta * frame / frameCount;
    base = work->arcStart.z;
    delta = work->arcEnd.z - base;
    pos.z = base + delta * frame / frameCount;
    if (frame >= (frameCount + 1) / 2)
        frame = frameCount - frame;
    pos.y += work->arcHeight * frame / frameCount;
    *func_021BE480(expObj, 0, GIMMICK64_ARC_MODEL) = pos;
    if (work->arcFrame >= work->arcFrameCount)
        return 1;
    return 0;
}

/*
 * Lever: initialise the flag after the callee result has been captured; the
 * saved zero is then materialised before the saved one. The trailing
 * halfword at 021F3BD6 is zero alignment padding.
 */
int func_021F3BAC(void *event, int *unusedSeq)
{
    unsigned char zero;
    unsigned char reached;
    int frame;
    void *expObj;
    int tmp;

    expObj = func_02188D2C(func_0201210C(func_020124E4(event)));
    zero = 0;
    tmp = func_021BE6E8(expObj, zero, 1, zero);
    frame = tmp;
    reached = 1;
    if (frame < 0x5000)
        reached = zero;
    return reached;
}
