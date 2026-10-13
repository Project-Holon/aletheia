/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, GIMMICK64_Exit, GIMMICK64_Update, func_021F37B8, GIMMICK64_PlayerEffectEvent, GIMMICK64_StartArcEffect, GIMMICK64_ShowArcModelAt, GIMMICK64_CreateWaitPeakEvent, GIMMICK64_CreateWaitEndEvent, GIMMICK64_ArcEffectEvent, GIMMICK64_IsArcPeakReached
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
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   d_021F3C20     0x021F3C20  data  a4
 *   d_021F3C30     0x021F3C30  data  a4
 *   FIELDMAP_FreeCommonWork  0x021897A0  thumb  ov021
 *   FLD_EXP_OBJ_RemoveUnit  0x021BE418  thumb  ov021
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E4  0x020124E4  thumb
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeFrame  0x021BE6E8  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeLastFrame  0x021BE748  thumb  ov021
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   func_020061E4  0x020061E4  thumb
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   GIMMICK64_IsArcAnimeStopped  0x021F3BD8  thumb  ov064
 */
#include "unit_021F36C0_types.h"

struct GameEvent;

extern void *FIELDMAP_GetExpObj(void *fieldMap);
extern u16 FIELDMAP_GetHeapId(void *fieldMap);
extern Gimmick64Work *FIELDMAP_AllocCommonWork(void *fieldMap, int id, int heapId, int size);
extern u32 GPOWER_GetSpecialPowerId(void);
extern void FLD_EXP_OBJ_AddUnitFromArchive(void *expObj, void *unitDesc, int b);
extern void FLD_EXP_OBJ_SetModelHidden(void *expObj, int unit, int model, int hidden);
extern void *FLD_EXP_OBJ_GetAnime(void *expObj, int unit, unsigned int model, int animeIdx);
extern void FLD_EXP_OBJ_SetAnimeLoop(u8 *anime, int loop);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *anime, int paused);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *expObj, int unit, int model, u16 animeIdx, int enabled);
extern void FIELDMAP_FreeCommonWork(void *fieldMap, int id);
extern void FLD_EXP_OBJ_RemoveUnit(void *expObj, unsigned short unit);
extern void FLD_EXP_OBJ_UpdateAnimes(void *expObj);
extern void *GAMESYSTEM_GetFieldMap(void *gameSystem);
extern void *FIELDMAP_GetFieldPlayer(void *fieldMap);
extern void FIELD_PLAYER_GetPos(void *player, VecFx32 *out);
extern VecFx32 *FLD_EXP_OBJ_GetModelStatus(void *expObj, unsigned unit, int model);
extern void FLD_EXP_OBJ_SetAnimeFrame(void *expObj, int unit, int model, u16 animeIdx, int frame);
extern struct GameEvent *func_020122C0(void *owner, void *a, int (*eventFunc)(void *event, int *seq), u32 size);
extern void *func_020124E4(void *event);
extern Gimmick64Work *FIELDMAP_GetCommonWork(void *fieldMap, int idx);
extern int FLD_EXP_OBJ_GetAnimeFrame(void *expObj, int unit, int model, int animeIdx);
extern int FLD_EXP_OBJ_GetAnimeLastFrame(u8 *anime);
extern void GFL_USE_StopAllSe(void);
extern void func_020061E4(u32 seId);
extern void FADE_Start(u32 screen, s32 from, s32 to, s32 wait);
extern int FADE_IsActive(void);
extern int GIMMICK64_IsArcAnimeStopped(void *event, int *unusedSeq);
void func_021F36C0(void *fieldMap);
void GIMMICK64_Exit(void *fieldMap);
void GIMMICK64_Update(void *fieldMap);
struct GameEvent *func_021F37B8(void *gameSystem);
int GIMMICK64_PlayerEffectEvent(void *event, int *seq);
void GIMMICK64_StartArcEffect(void *gameSystem, const VecFx32 *startPos, const VecFx32 *endPos, int arcHeight, int frameCount);
void GIMMICK64_ShowArcModelAt(void *gameSystem, VecFx32 *pos);
struct GameEvent *GIMMICK64_CreateWaitPeakEvent(void *gameSystem);
struct GameEvent *GIMMICK64_CreateWaitEndEvent(void *gameSystem);
int GIMMICK64_ArcEffectEvent(void *event, int *unusedSeq);
int GIMMICK64_IsArcPeakReached(void *event, int *unusedSeq);
extern char d_021F3C20[];
extern char d_021F3C30[];

void func_021F36C0(void *fieldMap)
{
    void *expObj;
    Gimmick64Work *work;
    int animeIdx;
    u8 *anime;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_AllocCommonWork(fieldMap, GIMMICK64_WORK_ID, FIELDMAP_GetHeapId(fieldMap), sizeof(Gimmick64Work));
    work->fadeWait = 0;
    if (GPOWER_GetSpecialPowerId() == GIMMICK64_SPECIAL_POWER_ID) {
        FLD_EXP_OBJ_AddUnitFromArchive(expObj, d_021F3C20, 0);
    } else {
        FLD_EXP_OBJ_AddUnitFromArchive(expObj, d_021F3C30, 0);
    }
    work->fadeTarget = 4;
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, GIMMICK64_PLAYER_MODEL, 1);
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, GIMMICK64_ARC_MODEL, 1);
    for (animeIdx = 0; animeIdx < GIMMICK64_PLAYER_ANIME_COUNT; animeIdx++) {
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, GIMMICK64_PLAYER_MODEL, (u16)animeIdx);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, GIMMICK64_PLAYER_MODEL, animeIdx, 0);
    }
    for (animeIdx = 0; animeIdx < GIMMICK64_ARC_ANIME_COUNT; animeIdx++) {
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, GIMMICK64_ARC_MODEL, (u16)animeIdx);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, GIMMICK64_ARC_MODEL, animeIdx, 0);
    }
}

void GIMMICK64_Exit(void *fieldMap)
{
    void *expObj;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_FreeCommonWork(fieldMap, GIMMICK64_WORK_ID);
    FLD_EXP_OBJ_RemoveUnit(expObj, 0);
}

void GIMMICK64_Update(void *fieldMap)
{
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
}

/* Shows the player effect model at the player and starts its animes; the returned event ends with the animation. */
struct GameEvent *func_021F37B8(void *gameSystem)
{
    int animeIdx;
    void *fieldMap;
    void *expObj;
    VecFx32 playerPos;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos);
    *FLD_EXP_OBJ_GetModelStatus(expObj, 0, GIMMICK64_PLAYER_MODEL) = playerPos;
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, GIMMICK64_PLAYER_MODEL, 0);
    for (animeIdx = 0; animeIdx < GIMMICK64_PLAYER_ANIME_COUNT; animeIdx++) {
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, GIMMICK64_PLAYER_MODEL, (u16)animeIdx), 0);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, GIMMICK64_PLAYER_MODEL, animeIdx, 1);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, GIMMICK64_PLAYER_MODEL, animeIdx, 0);
    }
    return func_020122C0(gameSystem, 0, GIMMICK64_PlayerEffectEvent, 0);
}

/* Event of the player effect: plays sounds at frames of the first anime and fades the screen out and in
 * around frame 0x65000. Ends when the anime reaches its last frame. */
int GIMMICK64_PlayerEffectEvent(void *event, int *seq)
{
    void *fieldMap;
    void *expObj;
    Gimmick64Work *work;
    int frame;
    int lastFrame;

    fieldMap = GAMESYSTEM_GetFieldMap(func_020124E4(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, GIMMICK64_WORK_ID);
    frame = FLD_EXP_OBJ_GetAnimeFrame(expObj, 0, GIMMICK64_PLAYER_MODEL, 0);
    lastFrame = FLD_EXP_OBJ_GetAnimeLastFrame(FLD_EXP_OBJ_GetAnime(expObj, 0, GIMMICK64_PLAYER_MODEL, 0));
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
            FADE_Start(work->fadeTarget, 0, 0x10, 0);
            work->fadeWait = 15;
            (*seq)++;
        }
        break;
    case 1:
        if (FADE_IsActive() == 0) {
            if (work->fadeWait <= 0) {
                FADE_Start(work->fadeTarget, 0x10, 0, 0);
                (*seq)++;
            } else {
                work->fadeWait--;
            }
        }
        break;
    case 2:
        if (FADE_IsActive() == 0) {
            (*seq)++;
        }
        break;
    }
    return frame >= lastFrame;
}

/* Starts the arc effect: the arc model flies from startPos to endPos in frameCount frames, rising by arcHeight at the middle. */
void GIMMICK64_StartArcEffect(void *gameSystem, const VecFx32 *startPos, const VecFx32 *endPos, int arcHeight, int frameCount)
{
    int animeIdx;
    void *fieldMap;
    void *expObj;
    Gimmick64Work *work;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    work = FIELDMAP_GetCommonWork(fieldMap, GIMMICK64_WORK_ID);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    func_020061E4(0x566);
    *FLD_EXP_OBJ_GetModelStatus(expObj, 0, GIMMICK64_ARC_MODEL) = *startPos;
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, GIMMICK64_ARC_MODEL, 0);
    for (animeIdx = 0; animeIdx < GIMMICK64_ARC_ANIME_COUNT; animeIdx++) {
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, GIMMICK64_ARC_MODEL, (u16)animeIdx), 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, GIMMICK64_ARC_MODEL, animeIdx, 0);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, GIMMICK64_ARC_MODEL, animeIdx, 0);
    }
    work->arcStart = *startPos;
    work->arcEnd = *endPos;
    work->arcFrameCount = frameCount;
    work->arcFrame = 0;
    work->arcHeight = arcHeight;
    func_020122C0(gameSystem, 0, GIMMICK64_ArcEffectEvent, 0);
}

/* Shows the arc model at pos and plays its animes. */
void GIMMICK64_ShowArcModelAt(void *gameSystem, VecFx32 *pos)
{
    int animeIdx;
    void *expObj;

    expObj = FIELDMAP_GetExpObj(GAMESYSTEM_GetFieldMap(gameSystem));
    func_020061E4(0x567);
    *FLD_EXP_OBJ_GetModelStatus(expObj, 0, GIMMICK64_ARC_MODEL) = *pos;
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, GIMMICK64_ARC_MODEL, 0);
    for (animeIdx = 0; animeIdx < GIMMICK64_ARC_ANIME_COUNT; animeIdx++) {
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, GIMMICK64_ARC_MODEL, (u16)animeIdx), 0);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, GIMMICK64_ARC_MODEL, animeIdx, 1);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, GIMMICK64_ARC_MODEL, animeIdx, 0);
    }
}

/* Creates an event that ends once the arc model anime has passed frame 0x5000. */
struct GameEvent *GIMMICK64_CreateWaitPeakEvent(void *gameSystem)
{
    GAMESYSTEM_GetFieldMap(gameSystem);
    return func_020122C0(gameSystem, 0, GIMMICK64_IsArcPeakReached, 0);
}

/* Creates an event that ends once the arc model anime has stopped. */
struct GameEvent *GIMMICK64_CreateWaitEndEvent(void *gameSystem)
{
    GAMESYSTEM_GetFieldMap(gameSystem);
    return func_020122C0(gameSystem, 0, GIMMICK64_IsArcAnimeStopped, 0);
}

/* Event of the arc effect: moves the arc model one frame along the line from start to end with the extra arc height. */
int GIMMICK64_ArcEffectEvent(void *event, int *unusedSeq)
{
    VecFx32 pos;
    Gimmick64Work *work;
    void *fieldMap;
    void *expObj;
    int frame;
    int frameCount;
    int base;
    int delta;

    fieldMap = GAMESYSTEM_GetFieldMap(func_020124E4(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, GIMMICK64_WORK_ID);
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
    *FLD_EXP_OBJ_GetModelStatus(expObj, 0, GIMMICK64_ARC_MODEL) = pos;
    if (work->arcFrame >= work->arcFrameCount)
        return 1;
    return 0;
}

/*
 * Lever: initialise the flag after the callee result has been captured; the
 * saved zero is then materialised before the saved one. The trailing
 * halfword at 021F3BD6 is zero alignment padding.
 */
int GIMMICK64_IsArcPeakReached(void *event, int *unusedSeq)
{
    unsigned char zero;
    unsigned char reached;
    int frame;
    void *expObj;
    int tmp;

    expObj = FIELDMAP_GetExpObj(GAMESYSTEM_GetFieldMap(func_020124E4(event)));
    zero = 0;
    tmp = FLD_EXP_OBJ_GetAnimeFrame(expObj, zero, 1, zero);
    frame = tmp;
    reached = 1;
    if (frame < 0x5000)
        reached = zero;
    return reached;
}
