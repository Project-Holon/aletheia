/*
 * file:     field_gimmick_arc_effect.c
 * unit:     yes
 * function: FIELD_GIMMICK_ARC_EFFECT_Init, FIELD_GIMMICK_ARC_EFFECT_Exit, FIELD_GIMMICK_ARC_EFFECT_Update, FIELD_GIMMICK_ARC_EFFECT_StartPlayerEffect, FIELD_GIMMICK_ARC_EFFECT_PlayerEffectEvent, FIELD_GIMMICK_ARC_EFFECT_StartArcEffect, FIELD_GIMMICK_ARC_EFFECT_ShowArcModelAt, FIELD_GIMMICK_ARC_EFFECT_CreateWaitPeakEvent, FIELD_GIMMICK_ARC_EFFECT_CreateWaitEndEvent, FIELD_GIMMICK_ARC_EFFECT_ArcEffectEvent, FIELD_GIMMICK_ARC_EFFECT_IsArcPeakReached, FIELD_GIMMICK_ARC_EFFECT_IsArcAnimeStopped
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
 *   gArcEffectPlayerUnitSetup     0x021F3C20  data  a4
 *   gArcEffectDefaultUnitSetup     0x021F3C30  data  a4
 *   FIELDMAP_FreeCommonWork  0x021897A0  thumb  ov021
 *   FLD_EXP_OBJ_RemoveUnit  0x021BE418  thumb  ov021
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeFrame  0x021BE6E8  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeLastFrame  0x021BE748  thumb  ov021
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   FIELD_GIMMICK_ARC_EFFECT_IsArcAnimeStopped  0x021F3BD8  thumb  ov064
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 */
#include "field_gimmick_arc_effect_types.h"

struct GameEvent;

#include "../ov021/fieldmap.h"
struct FieldMap;
#include "../arm9/gpower.h"
struct G3dUtilSetup;
struct FldExpObjCnt;
#include "../ov021/fld_exp_obj.h"
struct FldExpObjAnime;
#include "../arm9/gamesystem.h"
#include "../ov021/field_player.h"
struct GameSystem;
#include "../arm9/game_event.h"
#include "../arm9/gfl_use.h"
#include "../arm9/fade.h"
extern int FIELD_GIMMICK_ARC_EFFECT_IsArcAnimeStopped(struct GameEvent *event, int *unusedSeq, void *eventWork);
void FIELD_GIMMICK_ARC_EFFECT_Init(void *fieldMap);
void FIELD_GIMMICK_ARC_EFFECT_Exit(void *fieldMap);
void FIELD_GIMMICK_ARC_EFFECT_Update(void *fieldMap);
struct GameEvent *FIELD_GIMMICK_ARC_EFFECT_StartPlayerEffect(void *gameSystem);
int FIELD_GIMMICK_ARC_EFFECT_PlayerEffectEvent(struct GameEvent *event, int *seq, void *eventWork);
struct GameEvent *FIELD_GIMMICK_ARC_EFFECT_StartArcEffect(void *gameSystem, const VecFx32 *startPos, const VecFx32 *endPos, int arcHeight, int frameCount);
void FIELD_GIMMICK_ARC_EFFECT_ShowArcModelAt(void *gameSystem, VecFx32 *pos);
struct GameEvent *FIELD_GIMMICK_ARC_EFFECT_CreateWaitPeakEvent(void *gameSystem);
struct GameEvent *FIELD_GIMMICK_ARC_EFFECT_CreateWaitEndEvent(void *gameSystem);
int FIELD_GIMMICK_ARC_EFFECT_ArcEffectEvent(struct GameEvent *event, int *unusedSeq, void *eventWork);
int FIELD_GIMMICK_ARC_EFFECT_IsArcPeakReached(struct GameEvent *event, int *unusedSeq, void *eventWork);
extern char gArcEffectPlayerUnitSetup[];
extern char gArcEffectDefaultUnitSetup[];

void FIELD_GIMMICK_ARC_EFFECT_Init(void *fieldMap)
{
    void *expObj;
    FieldGimmickArcEffectWork *work;
    int animeIdx;
    u8 *anime;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_AllocCommonWork(fieldMap, FIELD_GIMMICK_ARC_EFFECT_WORK_ID, FIELDMAP_GetHeapId(fieldMap), sizeof(FieldGimmickArcEffectWork));
    work->fadeWait = 0;
    if (GPOWER_GetSpecialPowerId() == FIELD_GIMMICK_ARC_EFFECT_SPECIAL_POWER_ID) {
        FLD_EXP_OBJ_AddUnitFromArchive(expObj, (struct G3dUtilSetup *)gArcEffectPlayerUnitSetup, 0);
    } else {
        FLD_EXP_OBJ_AddUnitFromArchive(expObj, (struct G3dUtilSetup *)gArcEffectDefaultUnitSetup, 0);
    }
    work->fadeTarget = 4;
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_PLAYER_MODEL, 1);
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_ARC_MODEL, 1);
    for (animeIdx = 0; animeIdx < FIELD_GIMMICK_ARC_EFFECT_PLAYER_ANIME_COUNT; animeIdx++) {
        anime = (u8 *)FLD_EXP_OBJ_GetAnime(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_PLAYER_MODEL, (u16)animeIdx);
        FLD_EXP_OBJ_SetAnimeLoop((struct FldExpObjAnime *)anime, 0);
        FLD_EXP_OBJ_SetAnimePaused((struct FldExpObjAnime *)anime, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_PLAYER_MODEL, animeIdx, 0);
    }
    for (animeIdx = 0; animeIdx < FIELD_GIMMICK_ARC_EFFECT_ARC_ANIME_COUNT; animeIdx++) {
        anime = (u8 *)FLD_EXP_OBJ_GetAnime(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_ARC_MODEL, (u16)animeIdx);
        FLD_EXP_OBJ_SetAnimeLoop((struct FldExpObjAnime *)anime, 0);
        FLD_EXP_OBJ_SetAnimePaused((struct FldExpObjAnime *)anime, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_ARC_MODEL, animeIdx, 0);
    }
}

void FIELD_GIMMICK_ARC_EFFECT_Exit(void *fieldMap)
{
    void *expObj;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_FreeCommonWork(fieldMap, FIELD_GIMMICK_ARC_EFFECT_WORK_ID);
    FLD_EXP_OBJ_RemoveUnit(expObj, 0);
}

void FIELD_GIMMICK_ARC_EFFECT_Update(void *fieldMap)
{
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
}

/* Shows the player effect model at the player and starts its animes; the returned event ends with the animation. */
struct GameEvent *FIELD_GIMMICK_ARC_EFFECT_StartPlayerEffect(void *gameSystem)
{
    int animeIdx;
    void *fieldMap;
    void *expObj;
    VecFx32 playerPos;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos);
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_PLAYER_MODEL)->trans = playerPos;
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_PLAYER_MODEL, 0);
    for (animeIdx = 0; animeIdx < FIELD_GIMMICK_ARC_EFFECT_PLAYER_ANIME_COUNT; animeIdx++) {
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_PLAYER_MODEL, (u16)animeIdx), 0);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_PLAYER_MODEL, animeIdx, 1);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_PLAYER_MODEL, animeIdx, 0);
    }
    return GAME_EVENT_Create((struct GameSystem *)gameSystem, 0, FIELD_GIMMICK_ARC_EFFECT_PlayerEffectEvent, 0);
}

/* Event of the player effect: plays sounds at frames of the first anime and fades the screen out and in
 * around frame 0x65000. Ends when the anime reaches its last frame. */
int FIELD_GIMMICK_ARC_EFFECT_PlayerEffectEvent(struct GameEvent *event, int *seq, void *eventWork)
{
    void *fieldMap;
    void *expObj;
    FieldGimmickArcEffectWork *work;
    int frame;
    int lastFrame;

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, FIELD_GIMMICK_ARC_EFFECT_WORK_ID);
    frame = FLD_EXP_OBJ_GetAnimeFrame(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_PLAYER_MODEL, 0);
    lastFrame = FLD_EXP_OBJ_GetAnimeLastFrame(FLD_EXP_OBJ_GetAnime(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_PLAYER_MODEL, 0));
    if (frame >= 0 && work->seDone[0] == 0) {
        GFL_USE_StopAllSe();
        GFL_USE_PlaySeDefaultVolume(0x7D0);
        work->seDone[0] = 1;
    } else if (frame >= 0x83000 && work->seDone[1] == 0) {
        GFL_USE_StopAllSe();
        GFL_USE_PlaySeDefaultVolume(0x7CB);
        work->seDone[1] = 1;
    } else if (frame >= 0x6C000 && work->seDone[2] == 0) {
        GFL_USE_StopAllSe();
        GFL_USE_PlaySeDefaultVolume(0x7CC);
        work->seDone[2] = 1;
    } else if (frame >= 0xFA000 && work->seDone[3] == 0) {
        GFL_USE_StopAllSe();
        GFL_USE_PlaySeDefaultVolume(0x7F2);
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
struct GameEvent *FIELD_GIMMICK_ARC_EFFECT_StartArcEffect(void *gameSystem, const VecFx32 *startPos, const VecFx32 *endPos, int arcHeight, int frameCount)
{
    int animeIdx;
    void *fieldMap;
    void *expObj;
    FieldGimmickArcEffectWork *work;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    work = FIELDMAP_GetCommonWork(fieldMap, FIELD_GIMMICK_ARC_EFFECT_WORK_ID);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    GFL_USE_PlaySeDefaultVolume(0x566);
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_ARC_MODEL)->trans = *startPos;
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_ARC_MODEL, 0);
    for (animeIdx = 0; animeIdx < FIELD_GIMMICK_ARC_EFFECT_ARC_ANIME_COUNT; animeIdx++) {
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_ARC_MODEL, (u16)animeIdx), 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_ARC_MODEL, animeIdx, 0);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_ARC_MODEL, animeIdx, 0);
    }
    work->arcStart = *startPos;
    work->arcEnd = *endPos;
    work->arcFrameCount = frameCount;
    work->arcFrame = 0;
    work->arcHeight = arcHeight;
    return GAME_EVENT_Create((struct GameSystem *)gameSystem, 0, FIELD_GIMMICK_ARC_EFFECT_ArcEffectEvent, 0);
}

/* Shows the arc model at pos and plays its animes. */
void FIELD_GIMMICK_ARC_EFFECT_ShowArcModelAt(void *gameSystem, VecFx32 *pos)
{
    int animeIdx;
    void *expObj;

    expObj = FIELDMAP_GetExpObj(GAMESYSTEM_GetFieldMap(gameSystem));
    GFL_USE_PlaySeDefaultVolume(0x567);
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_ARC_MODEL)->trans = *pos;
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_ARC_MODEL, 0);
    for (animeIdx = 0; animeIdx < FIELD_GIMMICK_ARC_EFFECT_ARC_ANIME_COUNT; animeIdx++) {
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_ARC_MODEL, (u16)animeIdx), 0);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_ARC_MODEL, animeIdx, 1);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_ARC_MODEL, animeIdx, 0);
    }
}

/* Creates an event that ends once the arc model anime has passed frame 0x5000. */
struct GameEvent *FIELD_GIMMICK_ARC_EFFECT_CreateWaitPeakEvent(void *gameSystem)
{
    GAMESYSTEM_GetFieldMap(gameSystem);
    return GAME_EVENT_Create((struct GameSystem *)gameSystem, 0, FIELD_GIMMICK_ARC_EFFECT_IsArcPeakReached, 0);
}

/* Creates an event that ends once the arc model anime has stopped. */
struct GameEvent *FIELD_GIMMICK_ARC_EFFECT_CreateWaitEndEvent(void *gameSystem)
{
    GAMESYSTEM_GetFieldMap(gameSystem);
    return GAME_EVENT_Create((struct GameSystem *)gameSystem, 0, FIELD_GIMMICK_ARC_EFFECT_IsArcAnimeStopped, 0);
}

/* Event of the arc effect: moves the arc model one frame along the line from start to end with the extra arc height. */
int FIELD_GIMMICK_ARC_EFFECT_ArcEffectEvent(struct GameEvent *event, int *unusedSeq, void *eventWork)
{
    VecFx32 pos;
    FieldGimmickArcEffectWork *work;
    void *fieldMap;
    void *expObj;
    int frame;
    int frameCount;
    int base;
    int delta;

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, FIELD_GIMMICK_ARC_EFFECT_WORK_ID);
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
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_ARC_MODEL)->trans = pos;
    if (work->arcFrame >= work->arcFrameCount)
        return 1;
    return 0;
}

/*
 * Lever: initialise the flag after the callee result has been captured; the
 * saved zero is then materialised before the saved one. The trailing
 * halfword at 021F3BD6 is zero alignment padding.
 */
int FIELD_GIMMICK_ARC_EFFECT_IsArcPeakReached(struct GameEvent *event, int *unusedSeq, void *eventWork)
{
    unsigned char zero;
    unsigned char reached;
    int frame;
    void *expObj;
    int tmp;

    expObj = FIELDMAP_GetExpObj(GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event)));
    zero = 0;
    tmp = FLD_EXP_OBJ_GetAnimeFrame(expObj, zero, 1, zero);
    frame = tmp;
    reached = 1;
    if (frame < 0x5000)
        reached = zero;
    return reached;
}

/* Event: ends once the first anime of the arc model has stopped. */
int FIELD_GIMMICK_ARC_EFFECT_IsArcAnimeStopped(struct GameEvent *event, int *unusedSeq, void *eventWork)
{
    void *expObj;

    expObj = FIELDMAP_GetExpObj(GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event)));
    if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, FIELD_GIMMICK_ARC_EFFECT_ARC_MODEL, 0)) != 0) {
        return 1;
    }
    return 0;
}
