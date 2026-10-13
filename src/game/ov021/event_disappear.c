/*
 * file:     event_disappear.c
 * unit:     yes
 * function: EVENT_DISAPPEAR_CreateWalkFall, EVENT_DISAPPEAR_CreateSpinZoom, EVENT_DISAPPEAR_CreateSpinZoomEffect, EVENT_DISAPPEAR_CreateSpinFade, EVENT_DISAPPEAR_CreateRisingSpin, EVENT_DISAPPEAR_RunWalkFall, EVENT_DISAPPEAR_RunSpinZoom, EVENT_DISAPPEAR_StartSpin, EVENT_DISAPPEAR_StartZoomIn, EVENT_DISAPPEAR_EndZoomIn, EVENT_DISAPPEAR_CreateFadeOut, EVENT_DISAPPEAR_RunSpinZoomEffect, EVENT_DISAPPEAR_StartSpinAndEffect, EVENT_DISAPPEAR_StartZoomInAlt, EVENT_DISAPPEAR_EndZoomInAlt, EVENT_DISAPPEAR_CreateFadeOutAlt, EVENT_DISAPPEAR_RunSpinFade, EVENT_DISAPPEAR_RunRisingSpin
 * address:  0x021BFD34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_player_grid_event.c at 0x021BFD34 (lane CL118, name guess, no __FILE__ anchor: five 0x7C-byte player disappear events (spin ease-in, rise, fade) and their handlers).
 *
 * symbols:
 *   FADE_IsActive  0x0204E804  arm
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_CAMERA_GetMode  0x0218E138  thumb  ov021
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 *   FIELD_CAMERA_ANIME_Create 0x0218FE80 thumb ov021
 *   FIELD_CAMERA_ANIME_SetData 0x0218FEA0 thumb ov021
 *   FIELD_CAMERA_ANIME_Setup 0x0218FEA4 thumb ov021
 *   FIELD_CAMERA_ANIME_GetCurrentParam 0x0218FE78 thumb ov021
 *   FIELD_CAMERA_ANIME_ApplyStartParam 0x0218FEC0 thumb ov021
 *   FIELD_CAMERA_ANIME_Start 0x0218FF00 thumb ov021
 *   FIELD_CAMERA_ANIME_Restore  0x0218FF20  thumb  ov021
 *   FIELD_CAMERA_ANIME_Delete  0x0218FE98  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_KEMURI_Start  0x021AC528  thumb  ov021
 *   FIELD_TASK_CreatePlayerSpinLinear  0x021C71D4  thumb  ov021
 *   FIELD_TASK_CreatePlayerDrawOffsetTween  0x021C7858  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   func_0200616C  0x0200616C  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_GetBuildModel  0x0218DC6C  thumb  ov021
 *   FIELD_BUILDMODEL_CollectEntriesInRect  0x0218C584  thumb  ov021
 *   FIELD_BUILDMODEL_CreateNodeFromEntry  0x0218C724  thumb  ov021
 *   FIELD_BUILDMODEL_PlayNodeSlot  0x0218C88C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_TASK_CreatePlayerPosTween  0x021C754C  thumb  ov021
 *   FIELD_BUILDMODEL_IsNodeSlotIdle  0x0218C8FC  thumb  ov021
 *   func_0203630C  0x0203630C  arm
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FIELD_TASK_CreateCameraDistanceTween  0x021C6F00  thumb  ov021
 *   FIELD_TASK_CreateFade  0x021C7814  thumb  ov021
 *   func_020061F8  0x020061F8  thumb
 *   FIELD_BUILDMODEL_DeleteNode  0x0218C860  thumb  ov021
 *   FIELD_TASK_CreatePlayerSpinEaseIn  0x021C7260  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   FIELD_TASK_CreateRepeatPlayerEffect  0x021C7D28  thumb  ov021
 *   FIELD_TASK_CreateWait  0x021C77D8  thumb  ov021
 */
/*
 * Player disappear events of a map change (EVENT_DISAPPEAR_*). They run on
 * the old map: the player leaves by one of five effects (walk to a position
 * and fall, a camera zoom with a spin, the same with a player effect, a spin
 * with a fade-out, a rising spin) and the screen fades out. event_mapchange.c
 * picks the event by the kind of the map change; event_appear.c holds the
 * matching arrival events.
 *
 * Every event is a GAME_EVENT with a 0x7C-byte work. The creators take the
 * parent event, the game system and the field map.
 */
#include "field_camera_types.h"
#include "../ov010/fldmmdl_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
typedef struct FieldTask FieldTask;
typedef struct FieldTaskManager FieldTaskManager;

struct FieldCamera;
struct FieldCameraAnime;
struct FieldPlayer;
struct FieldEffectCtrl;
struct FieldG3dMapper;
struct BuildModelMan;
struct BuildModelEntry;
struct BuildModelNode;

/* Values an event function returns to the event runner. */
enum {
    EVENT_DISAPPEAR_CONTINUE,
    EVENT_DISAPPEAR_FINISHED
};

/* Sound effects. */
#define EVENT_DISAPPEAR_SE_WALK_LOOP 0x680      /* plays while the player walks to the position */
#define EVENT_DISAPPEAR_SE_FALL 0x7A0           /* the player falls */
#define EVENT_DISAPPEAR_SE_SPIN_END 0x559       /* the spin has run its course */
#define EVENT_DISAPPEAR_SE_SPIN_START 0x6DF     /* the spin with the player effect starts */
#define EVENT_DISAPPEAR_SE_FADE 0x676           /* the fade-out starts */
#define EVENT_DISAPPEAR_SE_FADE_ALT 0x6E7       /* the fade-out starts (sound variant 1) */

/* Move animation codes of the walk, one per pad direction. */
#define EVENT_DISAPPEAR_ACMD_WALK_UP 0x24
#define EVENT_DISAPPEAR_ACMD_WALK_DOWN 0x25
#define EVENT_DISAPPEAR_ACMD_WALK_LEFT 0x26
#define EVENT_DISAPPEAR_ACMD_WALK_RIGHT 0x27

/* Pad bits the walk reads. */
#define EVENT_DISAPPEAR_PAD_UP 0x40
#define EVENT_DISAPPEAR_PAD_DOWN 0x80
#define EVENT_DISAPPEAR_PAD_LEFT 0x20
#define EVENT_DISAPPEAR_PAD_RIGHT 0x10

/* Spin zoom: the camera moves this much closer (fx32) in 60 frames. */
#define EVENT_DISAPPEAR_ZOOM_FRAMES 60
#define EVENT_DISAPPEAR_ZOOM_DISTANCE 0x64000
#define EVENT_DISAPPEAR_SPIN_FRAMES 0x14
#define EVENT_DISAPPEAR_SPIN_EASE_IN_COUNT 3
#define EVENT_DISAPPEAR_SPIN_LINEAR_COUNT 5

/* The spin zoom events leave the camera zooming this many frames before the fade-out. */
#define EVENT_DISAPPEAR_FADE_DELAY_FRAMES 35

/* Search rectangle of build models, 20.12 fixed point (same layout as BuildModelRect). */
typedef struct EventDisappearRect {
    int zMin;
    int zMax;
    int xMin;
    int xMax;
} EventDisappearRect;

/* Work of the disappear events (0x7C bytes). */
typedef struct EventDisappearWork {
    GameSystem *gameSystem;                     /* 0x00 */
    FieldMap *fieldMap;                         /* 0x04 */
    unsigned int savedCameraMode;               /* 0x08: camera mode before the event */
    int frame;                                  /* 0x0C: frame counter of the walk */
    int soundVariant;                           /* 0x10: nonzero plays the alternate fade sound (spin fade event) */
    VecFx32 targetPos;                          /* 0x14: position the player walks to (walk event) */
    struct BuildModelNode *buildNode;           /* 0x20: build model at the position, 0 if none (walk event) */
    FieldCameraAnimeData cameraAnime;           /* 0x24: camera zoom request */
    struct FieldCameraAnime *cameraAnimeHandle; /* 0x70 */
    int waitFrames;                             /* 0x74: frames since the zoom started */
    int seasonChanged;                          /* 0x78: nonzero fades out with effect 0, else effect 1 */
} EventDisappearWork;

typedef int (*EventDisappearFunc)(GameEvent *event, int *seq, EventDisappearWork *work);

/* Steps of the walk event. */
enum {
    EVENT_DISAPPEAR_WALK_START,
    EVENT_DISAPPEAR_WALK_FIND_NODE,
    EVENT_DISAPPEAR_WALK_MOVE,
    EVENT_DISAPPEAR_WALK_WAIT,
    EVENT_DISAPPEAR_WALK_FALL,
    EVENT_DISAPPEAR_WALK_FALL_WAIT,
    EVENT_DISAPPEAR_WALK_END
};

/* Steps of the spin zoom events. */
enum {
    EVENT_DISAPPEAR_ZOOM_START,
    EVENT_DISAPPEAR_ZOOM_COUNT,     /* counts frames, then starts the fade-out; falls through to the wait */
    EVENT_DISAPPEAR_ZOOM_WAIT,
    EVENT_DISAPPEAR_ZOOM_END
};

/* Steps of the spin fade event. */
enum {
    EVENT_DISAPPEAR_FADE_START,
    EVENT_DISAPPEAR_FADE_WAIT,
    EVENT_DISAPPEAR_FADE_END
};

/* Steps of the rising spin event. */
enum {
    EVENT_DISAPPEAR_RISE_START,
    EVENT_DISAPPEAR_RISE_WAIT,
    EVENT_DISAPPEAR_RISE_RESTORE,
    EVENT_DISAPPEAR_RISE_END
};

extern GameEvent *func_020122C0(GameSystem *gameSystem, GameEvent *parent, EventDisappearFunc func, u32 workSize);
extern void *func_020124E8(GameEvent *event);
extern void GAME_EVENT_CallEvent(GameEvent *parent, GameEvent *child);
extern struct FieldCamera *FIELDMAP_GetCamera(FieldMap *fieldMap);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(FieldMap *fieldMap);
extern FieldTaskManager *FIELDMAP_GetTaskManager(FieldMap *fieldMap);
extern struct FieldEffectCtrl *FIELDMAP_GetEffect(FieldMap *fieldMap);
extern struct FieldG3dMapper *FIELDMAP_GetG3dMapper(FieldMap *fieldMap);
extern Mmdl *FIELD_PLAYER_GetMmdl(struct FieldPlayer *player);
extern void FIELD_PLAYER_GetPos(struct FieldPlayer *player, VecFx32 *out);
extern unsigned int FIELD_CAMERA_GetMode(struct FieldCamera *camera);
extern void FIELD_CAMERA_SetMode(struct FieldCamera *camera, unsigned int mode);
extern void FLDMMDL_SetAcmd(Mmdl *mmdl, u16 acmdCode);
extern void FLDMMDL_SetMoveBit(Mmdl *mmdl, u32 bit);
extern GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeOut(GameSystem *gameSystem, FieldMap *fieldMap, int effectId, int wait);
extern FieldTask *FIELD_TASK_CreatePlayerSpinEaseIn(FieldMap *fieldMap, u16 frames, int spins);
extern FieldTask *FIELD_TASK_CreatePlayerSpinLinear(FieldMap *fieldMap, u32 frames, u32 spins);
extern FieldTask *FIELD_TASK_CreatePlayerDrawOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset);
extern FieldTask *FIELD_TASK_CreatePlayerPosTween(FieldMap *fieldMap, u32 frames, VecFx32 *to);
extern FieldTask *FIELD_TASK_CreateCameraDistanceTween(FieldMap *fieldMap, u16 frames, int targetDistance);
extern FieldTask *FIELD_TASK_CreateFade(FieldMap *fieldMap, u32 fadeMode, u32 startBrightness, u32 endBrightness, u32 wait);
extern FieldTask *FIELD_TASK_CreateWait(FieldMap *fieldMap, u16 frames);
extern FieldTask *FIELD_TASK_CreateRepeatPlayerEffect(FieldMap *fieldMap, Mmdl *mmdl, u16 frames, u16 interval);
extern void FIELD_TASK_MANAGER_AddTask(FieldTaskManager *manager, FieldTask *task, FieldTask *prerequisite);
extern int FIELD_TASK_MANAGER_IsEmpty(FieldTaskManager *manager);
extern struct FieldCameraAnime *FIELD_CAMERA_ANIME_Create(FieldMap *fieldMap);
extern void FIELD_CAMERA_ANIME_SetData(struct FieldCameraAnime *anime, FieldCameraAnimeData *data);
extern int FIELD_CAMERA_ANIME_Setup(struct FieldCameraAnime *anime);
extern void FIELD_CAMERA_ANIME_GetCurrentParam(struct FieldCamera *camera, FieldCameraParam *param);
extern void FIELD_CAMERA_ANIME_ApplyStartParam(struct FieldCameraAnime *anime);
extern int FIELD_CAMERA_ANIME_Start(struct FieldCameraAnime *anime);
extern void FIELD_CAMERA_ANIME_Restore(struct FieldCameraAnime *anime);
extern void FIELD_CAMERA_ANIME_Delete(struct FieldCameraAnime *anime);
extern struct BuildModelMan *FIELD_G3D_MAPPER_GetBuildModel(struct FieldG3dMapper *mapper);
extern struct BuildModelEntry **FIELD_BUILDMODEL_CollectEntriesInRect(struct BuildModelMan *man, EventDisappearRect *rect, int kind, int *count);
extern struct BuildModelNode *FIELD_BUILDMODEL_CreateNodeFromEntry(struct BuildModelMan *man, struct BuildModelEntry *entry);
extern void FIELD_BUILDMODEL_PlayNodeSlot(struct BuildModelNode *node, int slot, int mode);
extern int FIELD_BUILDMODEL_IsNodeSlotIdle(struct BuildModelNode *node, int slot);
extern void FIELD_BUILDMODEL_DeleteNode(struct BuildModelNode *node);
extern void FLDEFF_KEMURI_Start(Mmdl *mmdl, struct FieldEffectCtrl *effectCtrl);
extern unsigned int func_020307B0(void *block);
extern unsigned int func_0203630C(void);
extern int FADE_IsActive(void);
extern void func_020061E4(u32 seId);
extern void func_020061F8(int slot);
extern void func_0200616C(u32 seqNo, int slot);
extern int GFL_USE_GetSeSlot(u32 seqNo);

GameEvent *EVENT_DISAPPEAR_CreateWalkFall(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, const VecFx32 *targetPos);
GameEvent *EVENT_DISAPPEAR_CreateSpinZoom(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int seasonChanged);
GameEvent *EVENT_DISAPPEAR_CreateSpinZoomEffect(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int seasonChanged);
GameEvent *EVENT_DISAPPEAR_CreateSpinFade(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int soundVariant);
GameEvent *EVENT_DISAPPEAR_CreateRisingSpin(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
int EVENT_DISAPPEAR_RunWalkFall(GameEvent *event, int *seq, EventDisappearWork *work);
int EVENT_DISAPPEAR_RunSpinZoom(GameEvent *event, int *seq, EventDisappearWork *work);
void EVENT_DISAPPEAR_StartSpin(EventDisappearWork *work);
void EVENT_DISAPPEAR_StartZoomIn(EventDisappearWork *work);
void EVENT_DISAPPEAR_EndZoomIn(EventDisappearWork *work);
GameEvent *EVENT_DISAPPEAR_CreateFadeOut(EventDisappearWork *work);
int EVENT_DISAPPEAR_RunSpinZoomEffect(GameEvent *event, int *seq, EventDisappearWork *work);
void EVENT_DISAPPEAR_StartSpinAndEffect(EventDisappearWork *work);
void EVENT_DISAPPEAR_StartZoomInAlt(EventDisappearWork *work);
void EVENT_DISAPPEAR_EndZoomInAlt(EventDisappearWork *work);
GameEvent *EVENT_DISAPPEAR_CreateFadeOutAlt(EventDisappearWork *work);
int EVENT_DISAPPEAR_RunSpinFade(GameEvent *event, int *seq, EventDisappearWork *work);
int EVENT_DISAPPEAR_RunRisingSpin(GameEvent *event, int *seq, EventDisappearWork *work);

/* Same as VEC_Set of the SDK. */
static inline void VEC_Set(VecFx32 *dst, int x, int y, int z)
{
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

/* Creates the walk event: the player walks to targetPos and falls. */
GameEvent *EVENT_DISAPPEAR_CreateWalkFall(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, const VecFx32 *targetPos)
{
    GameEvent *event = func_020122C0(gameSystem, parent, EVENT_DISAPPEAR_RunWalkFall, 0x7C);
    EventDisappearWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->frame = 0;
    work->buildNode = 0;
    VEC_Set(&work->targetPos, targetPos->x, targetPos->y, targetPos->z);
    return event;
}

/* Creates the spin zoom event. */
GameEvent *EVENT_DISAPPEAR_CreateSpinZoom(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int seasonChanged)
{
    GameEvent *event = func_020122C0(gameSystem, parent, EVENT_DISAPPEAR_RunSpinZoom, 0x7C);
    EventDisappearWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->frame = 0;
    work->waitFrames = 0;
    work->seasonChanged = seasonChanged;
    return event;
}

/* Creates the spin zoom event with the player effect. */
GameEvent *EVENT_DISAPPEAR_CreateSpinZoomEffect(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int seasonChanged)
{
    GameEvent *event = func_020122C0(gameSystem, parent, EVENT_DISAPPEAR_RunSpinZoomEffect, 0x7C);
    EventDisappearWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->frame = 0;
    work->waitFrames = 0;
    work->seasonChanged = seasonChanged;
    return event;
}

/* Creates the spin fade event. */
GameEvent *EVENT_DISAPPEAR_CreateSpinFade(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int soundVariant)
{
    GameEvent *event = func_020122C0(gameSystem, parent, EVENT_DISAPPEAR_RunSpinFade, 0x7C);
    EventDisappearWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->frame = 0;
    work->soundVariant = soundVariant;
    return event;
}

/* Creates the rising spin event. */
GameEvent *EVENT_DISAPPEAR_CreateRisingSpin(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, parent, EVENT_DISAPPEAR_RunRisingSpin, 0x7C);
    EventDisappearWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->frame = 0;
    return event;
}

/*
 * Walk and fall: a build model at the position (a door or a hatch) starts its
 * animation, the player walks to the position with the walk animation of the
 * pad direction, smoke puffs every 10 frames, then the player sinks, spins,
 * the camera moves away and the screen fades out. Waits are skipped when the
 * player already stands on the position.
 */
int EVENT_DISAPPEAR_RunWalkFall(GameEvent *event, int *seq, EventDisappearWork *work)
{
    struct FieldPlayer *player;
    Mmdl *mmdl;
    struct FieldEffectCtrl *effectCtrl;
    struct FieldCamera *camera;
    struct BuildModelMan *buildModelMan;
    struct BuildModelEntry **entries;
    int dx;
    int dz;
    int walkFrames;
    FieldTask *task;
    int keys;
    int frame;
    FieldTask *offsetTask;
    FieldTask *spinTask;
    FieldTask *distanceTask;
    FieldTask *fadeTask;
    FieldTaskManager *taskManager;
    EventDisappearRect rect;
    int count;
    VecFx32 playerPos;
    VecFx32 fallOffset;

    player = FIELDMAP_GetFieldPlayer(work->fieldMap);
    mmdl = FIELD_PLAYER_GetMmdl(player);
    effectCtrl = FIELDMAP_GetEffect(work->fieldMap);
    camera = FIELDMAP_GetCamera(work->fieldMap);
    switch (*seq) {
    case EVENT_DISAPPEAR_WALK_START:
        work->savedCameraMode = FIELD_CAMERA_GetMode(camera);
        FIELD_CAMERA_SetMode(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
        *seq = EVENT_DISAPPEAR_WALK_FIND_NODE;
        break;
    case EVENT_DISAPPEAR_WALK_FIND_NODE:
        func_0200616C(EVENT_DISAPPEAR_SE_WALK_LOOP, GFL_USE_GetSeSlot(EVENT_DISAPPEAR_SE_WALK_LOOP));
        buildModelMan = FIELD_G3D_MAPPER_GetBuildModel(FIELDMAP_GetG3dMapper(work->fieldMap));
        rect.xMin = work->targetPos.x - 0x20000;
        rect.xMax = work->targetPos.x + 0x20000;
        rect.zMin = work->targetPos.z - 0x20000;
        rect.zMax = work->targetPos.z + 0x20000;
        entries = FIELD_BUILDMODEL_CollectEntriesInRect(buildModelMan, &rect, 2, &count);
        if (*entries != 0) {
            work->buildNode = FIELD_BUILDMODEL_CreateNodeFromEntry(buildModelMan, *entries);
            FIELD_BUILDMODEL_PlayNodeSlot(work->buildNode, 0, 0);
        } else {
            work->buildNode = 0;
        }
        func_020307B0(entries);
        *seq = EVENT_DISAPPEAR_WALK_MOVE;
        break;
    case EVENT_DISAPPEAR_WALK_MOVE:
        FIELD_PLAYER_GetPos(player, &playerPos);
        dx = (playerPos.x >> 12) / 16 - (work->targetPos.x >> 12) / 16;
        dz = (playerPos.z >> 12) / 16 - (work->targetPos.z >> 12) / 16;
        if (dx < 0)
            dx = -dx;
        if (dz < 0)
            dz = -dz;
        if (dx == 0 && dz == 0)
            walkFrames = 0;
        else if (dx < 2 && dz < 2)
            walkFrames = 0x3c;
        else
            walkFrames = 0x78;
        if (walkFrames > 0) {
            task = FIELD_TASK_CreatePlayerPosTween(work->fieldMap, walkFrames, &work->targetPos);
            FIELD_TASK_MANAGER_AddTask(FIELDMAP_GetTaskManager(work->fieldMap), task, 0);
            *seq = EVENT_DISAPPEAR_WALK_WAIT;
        } else {
            *seq = EVENT_DISAPPEAR_WALK_FALL;
        }
        work->frame = 0;
        break;
    case EVENT_DISAPPEAR_WALK_WAIT:
        if (work->buildNode != 0 && FIELD_BUILDMODEL_IsNodeSlotIdle(work->buildNode, 0) != 0)
            FIELD_BUILDMODEL_PlayNodeSlot(work->buildNode, 0, 0);
        keys = func_0203630C();
        if (keys & EVENT_DISAPPEAR_PAD_UP)
            FLDMMDL_SetAcmd(mmdl, EVENT_DISAPPEAR_ACMD_WALK_UP);
        if (keys & EVENT_DISAPPEAR_PAD_DOWN)
            FLDMMDL_SetAcmd(mmdl, EVENT_DISAPPEAR_ACMD_WALK_DOWN);
        if (keys & EVENT_DISAPPEAR_PAD_LEFT)
            FLDMMDL_SetAcmd(mmdl, EVENT_DISAPPEAR_ACMD_WALK_LEFT);
        if (keys & EVENT_DISAPPEAR_PAD_RIGHT)
            FLDMMDL_SetAcmd(mmdl, EVENT_DISAPPEAR_ACMD_WALK_RIGHT);
        frame = work->frame;
        work->frame = frame + 1;
        if (frame % 10 == 0)
            FLDEFF_KEMURI_Start(mmdl, effectCtrl);
        if (FIELD_TASK_MANAGER_IsEmpty(FIELDMAP_GetTaskManager(work->fieldMap)) != 0)
            *seq = EVENT_DISAPPEAR_WALK_FALL;
        break;
    case EVENT_DISAPPEAR_WALK_FALL:
        func_020061E4(EVENT_DISAPPEAR_SE_FALL);
        FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_SHOAL_SET);
        fallOffset.x = 0;
        fallOffset.y = -0x1E000;
        fallOffset.z = 0;
        offsetTask = FIELD_TASK_CreatePlayerDrawOffsetTween(work->fieldMap, 0x22, &fallOffset);
        spinTask = FIELD_TASK_CreatePlayerSpinLinear(work->fieldMap, 0x22, 5);
        distanceTask = FIELD_TASK_CreateCameraDistanceTween(work->fieldMap, 0x1e, 0xB4000);
        fadeTask = FIELD_TASK_CreateFade(work->fieldMap, 3, 0, 0x10, 0);
        taskManager = FIELDMAP_GetTaskManager(work->fieldMap);
        FIELD_TASK_MANAGER_AddTask(taskManager, offsetTask, 0);
        FIELD_TASK_MANAGER_AddTask(taskManager, spinTask, 0);
        FIELD_TASK_MANAGER_AddTask(taskManager, distanceTask, 0);
        FIELD_TASK_MANAGER_AddTask(taskManager, fadeTask, distanceTask);
        work->frame = 0;
        *seq = EVENT_DISAPPEAR_WALK_FALL_WAIT;
        break;
    case EVENT_DISAPPEAR_WALK_FALL_WAIT:
        if (FIELD_TASK_MANAGER_IsEmpty(FIELDMAP_GetTaskManager(work->fieldMap)) != 0)
            *seq = EVENT_DISAPPEAR_WALK_END;
        break;
    case EVENT_DISAPPEAR_WALK_END:
        func_020061F8(GFL_USE_GetSeSlot(EVENT_DISAPPEAR_SE_WALK_LOOP));
        FIELD_CAMERA_SetMode(camera, work->savedCameraMode);
        if (work->buildNode != 0)
            FIELD_BUILDMODEL_DeleteNode(work->buildNode);
        return EVENT_DISAPPEAR_FINISHED;
    }
    return EVENT_DISAPPEAR_CONTINUE;
}

/*
 * Spin zoom: the player spins away and the camera zooms in. After 35 frames
 * the fade-out event starts. FIELD_TASK_MANAGER_IsEmpty takes the task manager that stays
 * live across the switch, which puts the step number in r1.
 */
int EVENT_DISAPPEAR_RunSpinZoom(GameEvent *event, int *seq, EventDisappearWork *work)
{
    FieldTaskManager *taskManager;
    int frame;

    taskManager = FIELDMAP_GetTaskManager(work->fieldMap);
    switch (*seq) {
    case EVENT_DISAPPEAR_ZOOM_START:
        EVENT_DISAPPEAR_StartSpin(work);
        EVENT_DISAPPEAR_StartZoomIn(work);
        (*seq)++;
        break;
    case EVENT_DISAPPEAR_ZOOM_COUNT:
        frame = work->waitFrames;
        work->waitFrames = frame + 1;
        if (frame > EVENT_DISAPPEAR_FADE_DELAY_FRAMES) {
            GAME_EVENT_CallEvent(event, EVENT_DISAPPEAR_CreateFadeOut(work));
            (*seq)++;
            break;
        }
    case EVENT_DISAPPEAR_ZOOM_WAIT:
        if (FIELD_TASK_MANAGER_IsEmpty(taskManager) != 0) {
            func_020061E4(EVENT_DISAPPEAR_SE_SPIN_END);
            (*seq)++;
        }
        break;
    case EVENT_DISAPPEAR_ZOOM_END:
        EVENT_DISAPPEAR_EndZoomIn(work);
        return EVENT_DISAPPEAR_FINISHED;
    }
    return EVENT_DISAPPEAR_CONTINUE;
}

/* Starts the eased spin and the linear spin that follows it. */
void EVENT_DISAPPEAR_StartSpin(EventDisappearWork *work)
{
    FieldMap *fieldMap = work->fieldMap;
    FieldTaskManager *taskManager = FIELDMAP_GetTaskManager(fieldMap);
    FieldTask *easeTask = FIELD_TASK_CreatePlayerSpinEaseIn(fieldMap, EVENT_DISAPPEAR_SPIN_FRAMES, EVENT_DISAPPEAR_SPIN_EASE_IN_COUNT);
    FieldTask *linearTask = FIELD_TASK_CreatePlayerSpinLinear(fieldMap, EVENT_DISAPPEAR_SPIN_FRAMES, EVENT_DISAPPEAR_SPIN_LINEAR_COUNT);

    FIELD_TASK_MANAGER_AddTask(taskManager, easeTask, 0);
    FIELD_TASK_MANAGER_AddTask(taskManager, linearTask, easeTask);
}

/* Starts the camera zoom: from the current pose to a pose closer to the target. */
void EVENT_DISAPPEAR_StartZoomIn(EventDisappearWork *work)
{
    struct FieldCamera *camera;
    struct FieldCameraAnime *anime;

    camera = FIELDMAP_GetCamera(work->fieldMap);
    anime = FIELD_CAMERA_ANIME_Create(work->fieldMap);
    work->cameraAnime.frames = EVENT_DISAPPEAR_ZOOM_FRAMES;
    work->cameraAnime.detachTarget = 1;
    work->cameraAnime.stopTrace = 1;
    work->cameraAnimeHandle = anime;
    FIELD_CAMERA_ANIME_SetData(anime, &work->cameraAnime);
    FIELD_CAMERA_ANIME_Setup(work->cameraAnimeHandle);
    FIELD_CAMERA_ANIME_GetCurrentParam(camera, &work->cameraAnime.start);
    work->cameraAnime.end = work->cameraAnime.start;
    work->cameraAnime.end.distance -= EVENT_DISAPPEAR_ZOOM_DISTANCE;
    FIELD_CAMERA_ANIME_ApplyStartParam(work->cameraAnimeHandle);
    FIELD_CAMERA_ANIME_Start(work->cameraAnimeHandle);
}

/* Ends the camera zoom and frees its handle. */
void EVENT_DISAPPEAR_EndZoomIn(EventDisappearWork *work)
{
    FIELD_CAMERA_ANIME_Restore(work->cameraAnimeHandle);
    FIELD_CAMERA_ANIME_Delete(work->cameraAnimeHandle);
}

/* Starts the fade-out: effect 0 when the season changes, else effect 1. */
GameEvent *EVENT_DISAPPEAR_CreateFadeOut(EventDisappearWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;

    if (work->seasonChanged != 0)
        return EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 0, 0);
    else
        return EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 1, 0);
}

/*
 * Spin zoom with the player effect: a sound, the spin tasks and a repeated
 * player effect start together, the camera zooms in and after 35 frames the
 * fade-out event starts.
 */
int EVENT_DISAPPEAR_RunSpinZoomEffect(GameEvent *event, int *seq, EventDisappearWork *work)
{
    int frame;
    FieldTaskManager *taskManager;

    taskManager = FIELDMAP_GetTaskManager(work->fieldMap);
    switch (*seq) {
    case EVENT_DISAPPEAR_ZOOM_START:
        EVENT_DISAPPEAR_StartSpinAndEffect(work);
        EVENT_DISAPPEAR_StartZoomInAlt(work);
        func_020061E4(EVENT_DISAPPEAR_SE_SPIN_START);
        *seq = *seq + 1;
        break;
    case EVENT_DISAPPEAR_ZOOM_COUNT:
        frame = work->waitFrames;
        work->waitFrames = frame + 1;
        if (frame > 0x23) {
            GAME_EVENT_CallEvent(event, EVENT_DISAPPEAR_CreateFadeOutAlt(work));
            *seq = *seq + 1;
            break;
        }
    case EVENT_DISAPPEAR_ZOOM_WAIT:
        if (FIELD_TASK_MANAGER_IsEmpty(taskManager)) {
            func_020061E4(EVENT_DISAPPEAR_SE_SPIN_END);
            *seq = *seq + 1;
        }
        break;
    case EVENT_DISAPPEAR_ZOOM_END:
        EVENT_DISAPPEAR_EndZoomInAlt(work);
        return EVENT_DISAPPEAR_FINISHED;
    }
    return EVENT_DISAPPEAR_CONTINUE;
}

/* Starts the player effect, the eased spin and the linear spin that follows it. */
void EVENT_DISAPPEAR_StartSpinAndEffect(EventDisappearWork *work)
{
    FieldMap *fieldMap;
    FieldTaskManager *taskManager;
    FieldTask *effectTask;
    FieldTask *easeTask;
    FieldTask *linearTask;

    fieldMap = work->fieldMap;
    taskManager = FIELDMAP_GetTaskManager(fieldMap);
    effectTask = FIELD_TASK_CreateRepeatPlayerEffect(fieldMap, FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)), 0x28, 6);
    easeTask = FIELD_TASK_CreatePlayerSpinEaseIn(fieldMap, EVENT_DISAPPEAR_SPIN_FRAMES, 4);
    linearTask = FIELD_TASK_CreatePlayerSpinLinear(fieldMap, EVENT_DISAPPEAR_SPIN_FRAMES, EVENT_DISAPPEAR_SPIN_LINEAR_COUNT);
    FIELD_TASK_MANAGER_AddTask(taskManager, effectTask, 0);
    FIELD_TASK_MANAGER_AddTask(taskManager, easeTask, 0);
    FIELD_TASK_MANAGER_AddTask(taskManager, linearTask, easeTask);
}

/* Copy of EVENT_DISAPPEAR_StartZoomIn. */
void EVENT_DISAPPEAR_StartZoomInAlt(EventDisappearWork *work)
{
    struct FieldCamera *camera;
    struct FieldCameraAnime *anime;

    camera = FIELDMAP_GetCamera(work->fieldMap);
    anime = FIELD_CAMERA_ANIME_Create(work->fieldMap);
    work->cameraAnime.frames = EVENT_DISAPPEAR_ZOOM_FRAMES;
    work->cameraAnime.detachTarget = 1;
    work->cameraAnime.stopTrace = 1;
    work->cameraAnimeHandle = anime;
    FIELD_CAMERA_ANIME_SetData(anime, &work->cameraAnime);
    FIELD_CAMERA_ANIME_Setup(work->cameraAnimeHandle);
    FIELD_CAMERA_ANIME_GetCurrentParam(camera, &work->cameraAnime.start);
    work->cameraAnime.end = work->cameraAnime.start;
    work->cameraAnime.end.distance -= EVENT_DISAPPEAR_ZOOM_DISTANCE;
    FIELD_CAMERA_ANIME_ApplyStartParam(work->cameraAnimeHandle);
    FIELD_CAMERA_ANIME_Start(work->cameraAnimeHandle);
}

/* Copy of EVENT_DISAPPEAR_EndZoomIn. */
void EVENT_DISAPPEAR_EndZoomInAlt(EventDisappearWork *work)
{
    FIELD_CAMERA_ANIME_Restore(work->cameraAnimeHandle);
    FIELD_CAMERA_ANIME_Delete(work->cameraAnimeHandle);
}

/* Copy of EVENT_DISAPPEAR_CreateFadeOut. */
GameEvent *EVENT_DISAPPEAR_CreateFadeOutAlt(EventDisappearWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;

    if (work->seasonChanged != 0)
        return EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 0, 0);
    else
        return EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 1, 0);
}

/*
 * Spin fade: the spin tasks and a fade start together (the fade waits 30
 * frames), the sound depends on soundVariant, and the camera zooms in.
 */
int EVENT_DISAPPEAR_RunSpinFade(GameEvent *event, int *seq, EventDisappearWork *work)
{
    FieldMap *fieldMap;
    struct FieldPlayer *player;
    struct FieldCamera *camera;
    FieldTaskManager *taskManager;
    FieldTask *easeTask;
    FieldTask *linearTask;
    FieldTask *waitTask;
    FieldTask *fadeTask;
    struct FieldCameraAnime *anime;

    fieldMap = work->fieldMap;
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    camera = FIELDMAP_GetCamera(work->fieldMap);
    taskManager = FIELDMAP_GetTaskManager(fieldMap);
    switch (*seq) {
    case EVENT_DISAPPEAR_FADE_START:
        easeTask = FIELD_TASK_CreatePlayerSpinEaseIn(fieldMap, EVENT_DISAPPEAR_SPIN_FRAMES, EVENT_DISAPPEAR_SPIN_EASE_IN_COUNT);
        linearTask = FIELD_TASK_CreatePlayerSpinLinear(fieldMap, EVENT_DISAPPEAR_SPIN_FRAMES, EVENT_DISAPPEAR_SPIN_LINEAR_COUNT);
        waitTask = FIELD_TASK_CreateWait(fieldMap, 0x1e);
        fadeTask = FIELD_TASK_CreateFade(fieldMap, 3, 0, 0x10, 1);
        FIELD_TASK_MANAGER_AddTask(taskManager, easeTask, 0);
        FIELD_TASK_MANAGER_AddTask(taskManager, linearTask, easeTask);
        FIELD_TASK_MANAGER_AddTask(taskManager, waitTask, 0);
        FIELD_TASK_MANAGER_AddTask(taskManager, fadeTask, waitTask);
        if (work->soundVariant != 0)
            func_020061E4(EVENT_DISAPPEAR_SE_FADE_ALT);
        else
            func_020061E4(EVENT_DISAPPEAR_SE_FADE);
        anime = FIELD_CAMERA_ANIME_Create(fieldMap);
        work->cameraAnime.frames = EVENT_DISAPPEAR_ZOOM_FRAMES;
        work->cameraAnime.detachTarget = 1;
        work->cameraAnime.stopTrace = 1;
        work->cameraAnimeHandle = anime;
        FIELD_CAMERA_ANIME_SetData(anime, &work->cameraAnime);
        FIELD_CAMERA_ANIME_Setup(work->cameraAnimeHandle);
        FIELD_CAMERA_ANIME_GetCurrentParam(camera, &work->cameraAnime.start);
        work->cameraAnime.end = work->cameraAnime.start;
        work->cameraAnime.end.distance -= EVENT_DISAPPEAR_ZOOM_DISTANCE;
        FIELD_CAMERA_ANIME_ApplyStartParam(work->cameraAnimeHandle);
        FIELD_CAMERA_ANIME_Start(work->cameraAnimeHandle);
        *seq = *seq + 1;
        break;
    case EVENT_DISAPPEAR_FADE_WAIT:
        if (FIELD_TASK_MANAGER_IsEmpty(taskManager))
            *seq = *seq + 1;
        break;
    case EVENT_DISAPPEAR_FADE_END:
        FIELD_CAMERA_ANIME_Restore(work->cameraAnimeHandle);
        FIELD_CAMERA_ANIME_Delete(work->cameraAnimeHandle);
        return EVENT_DISAPPEAR_FINISHED;
    }
    return EVENT_DISAPPEAR_CONTINUE;
}

/*
 * Rising spin: the player spins and rises (draw offset 0x96000) while the
 * screen fades out. It is the mirror of the descending spin of
 * event_appear.c.
 */
int EVENT_DISAPPEAR_RunRisingSpin(GameEvent *event, int *seq, EventDisappearWork *work)
{
    FieldMap *fieldMap;
    struct FieldPlayer *player;
    struct FieldCamera *camera;
    FieldTask *spinTask;
    FieldTask *fadeTask;
    FieldTask *offsetTask;
    FieldTaskManager *taskManager;

    fieldMap = work->fieldMap;
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    camera = FIELDMAP_GetCamera(fieldMap);
    switch (*seq) {
    case EVENT_DISAPPEAR_RISE_START:
        work->savedCameraMode = FIELD_CAMERA_GetMode(camera);
        FIELD_CAMERA_SetMode(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
        {
            VecFx32 riseOffset;
            riseOffset.y = 0x96000;
            riseOffset.x = 0;
            riseOffset.z = 0;
            spinTask = FIELD_TASK_CreatePlayerSpinLinear(fieldMap, 0x18, 3);
            fadeTask = FIELD_TASK_CreateFade(fieldMap, 3, 0, 0x10, 1);
            offsetTask = FIELD_TASK_CreatePlayerDrawOffsetTween(fieldMap, 0x18, &riseOffset);
        }
        taskManager = FIELDMAP_GetTaskManager(fieldMap);
        FIELD_TASK_MANAGER_AddTask(taskManager, spinTask, 0);
        FIELD_TASK_MANAGER_AddTask(taskManager, offsetTask, 0);
        FIELD_TASK_MANAGER_AddTask(taskManager, fadeTask, offsetTask);
        func_020061E4(EVENT_DISAPPEAR_SE_FADE);
        (*seq)++;
        break;
    case EVENT_DISAPPEAR_RISE_WAIT:
        if (FIELD_TASK_MANAGER_IsEmpty(FIELDMAP_GetTaskManager(fieldMap)) != 0 && FADE_IsActive() == 0)
            (*seq)++;
        break;
    case EVENT_DISAPPEAR_RISE_RESTORE:
        FIELD_CAMERA_SetMode(camera, work->savedCameraMode);
        (*seq)++;
        break;
    case EVENT_DISAPPEAR_RISE_END:
        return EVENT_DISAPPEAR_FINISHED;
    }
    return EVENT_DISAPPEAR_CONTINUE;
}
