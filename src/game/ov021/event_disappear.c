/*
 * file:     event_disappear.c
 * unit:     yes
 * function: func_021BFD34, func_021BFD70, func_021BFDA0, func_021BFDD0, func_021BFE00, func_021BFE2C, func_021C00C8, func_021C0140, func_021C017C, func_021C01E4, func_021C01F8, func_021C021C, func_021C029C, func_021C02F8, func_021C0360, func_021C0374, func_021C0398, func_021C04C0
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
 *   func_0204E804  0x0204E804  arm
 *   func_02012374  0x02012374  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0218E138  0x0218E138  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_0218FE80 0x0218FE80 thumb ov021
 *   func_0218FEA0 0x0218FEA0 thumb ov021
 *   func_0218FEA4 0x0218FEA4 thumb ov021
 *   func_0218FE78 0x0218FE78 thumb ov021
 *   func_0218FEC0 0x0218FEC0 thumb ov021
 *   func_0218FF00 0x0218FF00 thumb ov021
 *   func_0218FF20  0x0218FF20  thumb  ov021
 *   func_0218FE98  0x0218FE98  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021AC528  0x021AC528  thumb  ov021
 *   func_021C71D4  0x021C71D4  thumb  ov021
 *   func_021C7858  0x021C7858  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_02006148  0x02006148  thumb
 *   func_0200616C  0x0200616C  thumb
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_0218C584  0x0218C584  thumb  ov021
 *   func_0218C724  0x0218C724  thumb  ov021
 *   func_0218C88C  0x0218C88C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021C754C  0x021C754C  thumb  ov021
 *   func_0218C8FC  0x0218C8FC  thumb  ov021
 *   func_0203630C  0x0203630C  arm
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_021C6F00  0x021C6F00  thumb  ov021
 *   func_021C7814  0x021C7814  thumb  ov021
 *   func_020061F8  0x020061F8  thumb
 *   func_0218C860  0x0218C860  thumb  ov021
 *   func_021C7260  0x021C7260  thumb  ov021
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021C7D28  0x021C7D28  thumb  ov021
 *   func_021C77D8  0x021C77D8  thumb  ov021
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
extern void func_02012374(GameEvent *parent, GameEvent *child);
extern struct FieldCamera *func_02188C58(FieldMap *fieldMap);
extern struct FieldPlayer *func_02188CB4(FieldMap *fieldMap);
extern FieldTaskManager *func_02188D38(FieldMap *fieldMap);
extern struct FieldEffectCtrl *func_02188CD0(FieldMap *fieldMap);
extern struct FieldG3dMapper *func_02188C98(FieldMap *fieldMap);
extern Mmdl *func_021A3074(struct FieldPlayer *player);
extern void func_021A3038(struct FieldPlayer *player, VecFx32 *out);
extern unsigned int func_0218E138(struct FieldCamera *camera);
extern void func_0218E13C(struct FieldCamera *camera, unsigned int mode);
extern void func_0216D410(Mmdl *mmdl, u16 acmdCode);
extern void func_0216D568(Mmdl *mmdl, u32 bit);
extern GameEvent *func_021BE8D4(GameSystem *gameSystem, FieldMap *fieldMap, int effectId, int wait);
extern FieldTask *func_021C7260(FieldMap *fieldMap, u16 frames, int spins);
extern FieldTask *func_021C71D4(FieldMap *fieldMap, u32 frames, u32 spins);
extern FieldTask *func_021C7858(FieldMap *fieldMap, int frames, const VecFx32 *offset);
extern FieldTask *func_021C754C(FieldMap *fieldMap, u32 frames, VecFx32 *to);
extern FieldTask *func_021C6F00(FieldMap *fieldMap, u16 frames, int targetDistance);
extern FieldTask *func_021C7814(FieldMap *fieldMap, u32 fadeMode, u32 startBrightness, u32 endBrightness, u32 wait);
extern FieldTask *func_021C77D8(FieldMap *fieldMap, u16 frames);
extern FieldTask *func_021C7D28(FieldMap *fieldMap, Mmdl *mmdl, u16 frames, u16 interval);
extern void func_021C6DE0(FieldTaskManager *manager, FieldTask *task, FieldTask *prerequisite);
extern int func_021C6E48(FieldTaskManager *manager);
extern struct FieldCameraAnime *func_0218FE80(FieldMap *fieldMap);
extern void func_0218FEA0(struct FieldCameraAnime *anime, FieldCameraAnimeData *data);
extern int func_0218FEA4(struct FieldCameraAnime *anime);
extern void func_0218FE78(struct FieldCamera *camera, FieldCameraParam *param);
extern void func_0218FEC0(struct FieldCameraAnime *anime);
extern int func_0218FF00(struct FieldCameraAnime *anime);
extern void func_0218FF20(struct FieldCameraAnime *anime);
extern void func_0218FE98(struct FieldCameraAnime *anime);
extern struct BuildModelMan *func_0218DC6C(struct FieldG3dMapper *mapper);
extern struct BuildModelEntry **func_0218C584(struct BuildModelMan *man, EventDisappearRect *rect, int kind, int *count);
extern struct BuildModelNode *func_0218C724(struct BuildModelMan *man, struct BuildModelEntry *entry);
extern void func_0218C88C(struct BuildModelNode *node, int slot, int mode);
extern int func_0218C8FC(struct BuildModelNode *node, int slot);
extern void func_0218C860(struct BuildModelNode *node);
extern void func_021AC528(Mmdl *mmdl, struct FieldEffectCtrl *effectCtrl);
extern unsigned int func_020307B0(void *block);
extern unsigned int func_0203630C(void);
extern int func_0204E804(void);
extern void func_020061E4(u32 seId);
extern void func_020061F8(int slot);
extern void func_0200616C(u32 seqNo, int slot);
extern int func_02006148(u32 seqNo);

GameEvent *func_021BFD34(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, const VecFx32 *targetPos);
GameEvent *func_021BFD70(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int seasonChanged);
GameEvent *func_021BFDA0(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int seasonChanged);
GameEvent *func_021BFDD0(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int soundVariant);
GameEvent *func_021BFE00(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
int func_021BFE2C(GameEvent *event, int *seq, EventDisappearWork *work);
int func_021C00C8(GameEvent *event, int *seq, EventDisappearWork *work);
void func_021C0140(EventDisappearWork *work);
void func_021C017C(EventDisappearWork *work);
void func_021C01E4(EventDisappearWork *work);
GameEvent *func_021C01F8(EventDisappearWork *work);
int func_021C021C(GameEvent *event, int *seq, EventDisappearWork *work);
void func_021C029C(EventDisappearWork *work);
void func_021C02F8(EventDisappearWork *work);
void func_021C0360(EventDisappearWork *work);
GameEvent *func_021C0374(EventDisappearWork *work);
int func_021C0398(GameEvent *event, int *seq, EventDisappearWork *work);
int func_021C04C0(GameEvent *event, int *seq, EventDisappearWork *work);

/* Same as VEC_Set of the SDK. */
static inline void VEC_Set(VecFx32 *dst, int x, int y, int z)
{
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

/* Creates the walk event: the player walks to targetPos and falls. */
GameEvent *func_021BFD34(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, const VecFx32 *targetPos)
{
    GameEvent *event = func_020122C0(gameSystem, parent, func_021BFE2C, 0x7C);
    EventDisappearWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->frame = 0;
    work->buildNode = 0;
    VEC_Set(&work->targetPos, targetPos->x, targetPos->y, targetPos->z);
    return event;
}

/* Creates the spin zoom event. */
GameEvent *func_021BFD70(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int seasonChanged)
{
    GameEvent *event = func_020122C0(gameSystem, parent, func_021C00C8, 0x7C);
    EventDisappearWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->frame = 0;
    work->waitFrames = 0;
    work->seasonChanged = seasonChanged;
    return event;
}

/* Creates the spin zoom event with the player effect. */
GameEvent *func_021BFDA0(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int seasonChanged)
{
    GameEvent *event = func_020122C0(gameSystem, parent, func_021C021C, 0x7C);
    EventDisappearWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->frame = 0;
    work->waitFrames = 0;
    work->seasonChanged = seasonChanged;
    return event;
}

/* Creates the spin fade event. */
GameEvent *func_021BFDD0(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int soundVariant)
{
    GameEvent *event = func_020122C0(gameSystem, parent, func_021C0398, 0x7C);
    EventDisappearWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->frame = 0;
    work->soundVariant = soundVariant;
    return event;
}

/* Creates the rising spin event. */
GameEvent *func_021BFE00(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, parent, func_021C04C0, 0x7C);
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
int func_021BFE2C(GameEvent *event, int *seq, EventDisappearWork *work)
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

    player = func_02188CB4(work->fieldMap);
    mmdl = func_021A3074(player);
    effectCtrl = func_02188CD0(work->fieldMap);
    camera = func_02188C58(work->fieldMap);
    switch (*seq) {
    case EVENT_DISAPPEAR_WALK_START:
        work->savedCameraMode = func_0218E138(camera);
        func_0218E13C(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
        *seq = EVENT_DISAPPEAR_WALK_FIND_NODE;
        break;
    case EVENT_DISAPPEAR_WALK_FIND_NODE:
        func_0200616C(EVENT_DISAPPEAR_SE_WALK_LOOP, func_02006148(EVENT_DISAPPEAR_SE_WALK_LOOP));
        buildModelMan = func_0218DC6C(func_02188C98(work->fieldMap));
        rect.xMin = work->targetPos.x - 0x20000;
        rect.xMax = work->targetPos.x + 0x20000;
        rect.zMin = work->targetPos.z - 0x20000;
        rect.zMax = work->targetPos.z + 0x20000;
        entries = func_0218C584(buildModelMan, &rect, 2, &count);
        if (*entries != 0) {
            work->buildNode = func_0218C724(buildModelMan, *entries);
            func_0218C88C(work->buildNode, 0, 0);
        } else {
            work->buildNode = 0;
        }
        func_020307B0(entries);
        *seq = EVENT_DISAPPEAR_WALK_MOVE;
        break;
    case EVENT_DISAPPEAR_WALK_MOVE:
        func_021A3038(player, &playerPos);
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
            task = func_021C754C(work->fieldMap, walkFrames, &work->targetPos);
            func_021C6DE0(func_02188D38(work->fieldMap), task, 0);
            *seq = EVENT_DISAPPEAR_WALK_WAIT;
        } else {
            *seq = EVENT_DISAPPEAR_WALK_FALL;
        }
        work->frame = 0;
        break;
    case EVENT_DISAPPEAR_WALK_WAIT:
        if (work->buildNode != 0 && func_0218C8FC(work->buildNode, 0) != 0)
            func_0218C88C(work->buildNode, 0, 0);
        keys = func_0203630C();
        if (keys & EVENT_DISAPPEAR_PAD_UP)
            func_0216D410(mmdl, EVENT_DISAPPEAR_ACMD_WALK_UP);
        if (keys & EVENT_DISAPPEAR_PAD_DOWN)
            func_0216D410(mmdl, EVENT_DISAPPEAR_ACMD_WALK_DOWN);
        if (keys & EVENT_DISAPPEAR_PAD_LEFT)
            func_0216D410(mmdl, EVENT_DISAPPEAR_ACMD_WALK_LEFT);
        if (keys & EVENT_DISAPPEAR_PAD_RIGHT)
            func_0216D410(mmdl, EVENT_DISAPPEAR_ACMD_WALK_RIGHT);
        frame = work->frame;
        work->frame = frame + 1;
        if (frame % 10 == 0)
            func_021AC528(mmdl, effectCtrl);
        if (func_021C6E48(func_02188D38(work->fieldMap)) != 0)
            *seq = EVENT_DISAPPEAR_WALK_FALL;
        break;
    case EVENT_DISAPPEAR_WALK_FALL:
        func_020061E4(EVENT_DISAPPEAR_SE_FALL);
        func_0216D568(mmdl, MMDL_MOVEBIT_SHOAL_SET);
        fallOffset.x = 0;
        fallOffset.y = -0x1E000;
        fallOffset.z = 0;
        offsetTask = func_021C7858(work->fieldMap, 0x22, &fallOffset);
        spinTask = func_021C71D4(work->fieldMap, 0x22, 5);
        distanceTask = func_021C6F00(work->fieldMap, 0x1e, 0xB4000);
        fadeTask = func_021C7814(work->fieldMap, 3, 0, 0x10, 0);
        taskManager = func_02188D38(work->fieldMap);
        func_021C6DE0(taskManager, offsetTask, 0);
        func_021C6DE0(taskManager, spinTask, 0);
        func_021C6DE0(taskManager, distanceTask, 0);
        func_021C6DE0(taskManager, fadeTask, distanceTask);
        work->frame = 0;
        *seq = EVENT_DISAPPEAR_WALK_FALL_WAIT;
        break;
    case EVENT_DISAPPEAR_WALK_FALL_WAIT:
        if (func_021C6E48(func_02188D38(work->fieldMap)) != 0)
            *seq = EVENT_DISAPPEAR_WALK_END;
        break;
    case EVENT_DISAPPEAR_WALK_END:
        func_020061F8(func_02006148(EVENT_DISAPPEAR_SE_WALK_LOOP));
        func_0218E13C(camera, work->savedCameraMode);
        if (work->buildNode != 0)
            func_0218C860(work->buildNode);
        return EVENT_DISAPPEAR_FINISHED;
    }
    return EVENT_DISAPPEAR_CONTINUE;
}

/*
 * Spin zoom: the player spins away and the camera zooms in. After 35 frames
 * the fade-out event starts. func_021C6E48 takes the task manager that stays
 * live across the switch, which puts the step number in r1.
 */
int func_021C00C8(GameEvent *event, int *seq, EventDisappearWork *work)
{
    FieldTaskManager *taskManager;
    int frame;

    taskManager = func_02188D38(work->fieldMap);
    switch (*seq) {
    case EVENT_DISAPPEAR_ZOOM_START:
        func_021C0140(work);
        func_021C017C(work);
        (*seq)++;
        break;
    case EVENT_DISAPPEAR_ZOOM_COUNT:
        frame = work->waitFrames;
        work->waitFrames = frame + 1;
        if (frame > EVENT_DISAPPEAR_FADE_DELAY_FRAMES) {
            func_02012374(event, func_021C01F8(work));
            (*seq)++;
            break;
        }
    case EVENT_DISAPPEAR_ZOOM_WAIT:
        if (func_021C6E48(taskManager) != 0) {
            func_020061E4(EVENT_DISAPPEAR_SE_SPIN_END);
            (*seq)++;
        }
        break;
    case EVENT_DISAPPEAR_ZOOM_END:
        func_021C01E4(work);
        return EVENT_DISAPPEAR_FINISHED;
    }
    return EVENT_DISAPPEAR_CONTINUE;
}

/* Starts the eased spin and the linear spin that follows it. */
void func_021C0140(EventDisappearWork *work)
{
    FieldMap *fieldMap = work->fieldMap;
    FieldTaskManager *taskManager = func_02188D38(fieldMap);
    FieldTask *easeTask = func_021C7260(fieldMap, EVENT_DISAPPEAR_SPIN_FRAMES, EVENT_DISAPPEAR_SPIN_EASE_IN_COUNT);
    FieldTask *linearTask = func_021C71D4(fieldMap, EVENT_DISAPPEAR_SPIN_FRAMES, EVENT_DISAPPEAR_SPIN_LINEAR_COUNT);

    func_021C6DE0(taskManager, easeTask, 0);
    func_021C6DE0(taskManager, linearTask, easeTask);
}

/* Starts the camera zoom: from the current pose to a pose closer to the target. */
void func_021C017C(EventDisappearWork *work)
{
    struct FieldCamera *camera;
    struct FieldCameraAnime *anime;

    camera = func_02188C58(work->fieldMap);
    anime = func_0218FE80(work->fieldMap);
    work->cameraAnime.frames = EVENT_DISAPPEAR_ZOOM_FRAMES;
    work->cameraAnime.detachTarget = 1;
    work->cameraAnime.stopTrace = 1;
    work->cameraAnimeHandle = anime;
    func_0218FEA0(anime, &work->cameraAnime);
    func_0218FEA4(work->cameraAnimeHandle);
    func_0218FE78(camera, &work->cameraAnime.start);
    work->cameraAnime.end = work->cameraAnime.start;
    work->cameraAnime.end.distance -= EVENT_DISAPPEAR_ZOOM_DISTANCE;
    func_0218FEC0(work->cameraAnimeHandle);
    func_0218FF00(work->cameraAnimeHandle);
}

/* Ends the camera zoom and frees its handle. */
void func_021C01E4(EventDisappearWork *work)
{
    func_0218FF20(work->cameraAnimeHandle);
    func_0218FE98(work->cameraAnimeHandle);
}

/* Starts the fade-out: effect 0 when the season changes, else effect 1. */
GameEvent *func_021C01F8(EventDisappearWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;

    if (work->seasonChanged != 0)
        return func_021BE8D4(gameSystem, fieldMap, 0, 0);
    else
        return func_021BE8D4(gameSystem, fieldMap, 1, 0);
}

/*
 * Spin zoom with the player effect: a sound, the spin tasks and a repeated
 * player effect start together, the camera zooms in and after 35 frames the
 * fade-out event starts.
 */
int func_021C021C(GameEvent *event, int *seq, EventDisappearWork *work)
{
    int frame;
    FieldTaskManager *taskManager;

    taskManager = func_02188D38(work->fieldMap);
    switch (*seq) {
    case EVENT_DISAPPEAR_ZOOM_START:
        func_021C029C(work);
        func_021C02F8(work);
        func_020061E4(EVENT_DISAPPEAR_SE_SPIN_START);
        *seq = *seq + 1;
        break;
    case EVENT_DISAPPEAR_ZOOM_COUNT:
        frame = work->waitFrames;
        work->waitFrames = frame + 1;
        if (frame > 0x23) {
            func_02012374(event, func_021C0374(work));
            *seq = *seq + 1;
            break;
        }
    case EVENT_DISAPPEAR_ZOOM_WAIT:
        if (func_021C6E48(taskManager)) {
            func_020061E4(EVENT_DISAPPEAR_SE_SPIN_END);
            *seq = *seq + 1;
        }
        break;
    case EVENT_DISAPPEAR_ZOOM_END:
        func_021C0360(work);
        return EVENT_DISAPPEAR_FINISHED;
    }
    return EVENT_DISAPPEAR_CONTINUE;
}

/* Starts the player effect, the eased spin and the linear spin that follows it. */
void func_021C029C(EventDisappearWork *work)
{
    FieldMap *fieldMap;
    FieldTaskManager *taskManager;
    FieldTask *effectTask;
    FieldTask *easeTask;
    FieldTask *linearTask;

    fieldMap = work->fieldMap;
    taskManager = func_02188D38(fieldMap);
    effectTask = func_021C7D28(fieldMap, func_021A3074(func_02188CB4(fieldMap)), 0x28, 6);
    easeTask = func_021C7260(fieldMap, EVENT_DISAPPEAR_SPIN_FRAMES, 4);
    linearTask = func_021C71D4(fieldMap, EVENT_DISAPPEAR_SPIN_FRAMES, EVENT_DISAPPEAR_SPIN_LINEAR_COUNT);
    func_021C6DE0(taskManager, effectTask, 0);
    func_021C6DE0(taskManager, easeTask, 0);
    func_021C6DE0(taskManager, linearTask, easeTask);
}

/* Copy of func_021C017C. */
void func_021C02F8(EventDisappearWork *work)
{
    struct FieldCamera *camera;
    struct FieldCameraAnime *anime;

    camera = func_02188C58(work->fieldMap);
    anime = func_0218FE80(work->fieldMap);
    work->cameraAnime.frames = EVENT_DISAPPEAR_ZOOM_FRAMES;
    work->cameraAnime.detachTarget = 1;
    work->cameraAnime.stopTrace = 1;
    work->cameraAnimeHandle = anime;
    func_0218FEA0(anime, &work->cameraAnime);
    func_0218FEA4(work->cameraAnimeHandle);
    func_0218FE78(camera, &work->cameraAnime.start);
    work->cameraAnime.end = work->cameraAnime.start;
    work->cameraAnime.end.distance -= EVENT_DISAPPEAR_ZOOM_DISTANCE;
    func_0218FEC0(work->cameraAnimeHandle);
    func_0218FF00(work->cameraAnimeHandle);
}

/* Copy of func_021C01E4. */
void func_021C0360(EventDisappearWork *work)
{
    func_0218FF20(work->cameraAnimeHandle);
    func_0218FE98(work->cameraAnimeHandle);
}

/* Copy of func_021C01F8. */
GameEvent *func_021C0374(EventDisappearWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;

    if (work->seasonChanged != 0)
        return func_021BE8D4(gameSystem, fieldMap, 0, 0);
    else
        return func_021BE8D4(gameSystem, fieldMap, 1, 0);
}

/*
 * Spin fade: the spin tasks and a fade start together (the fade waits 30
 * frames), the sound depends on soundVariant, and the camera zooms in.
 */
int func_021C0398(GameEvent *event, int *seq, EventDisappearWork *work)
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
    player = func_02188CB4(fieldMap);
    camera = func_02188C58(work->fieldMap);
    taskManager = func_02188D38(fieldMap);
    switch (*seq) {
    case EVENT_DISAPPEAR_FADE_START:
        easeTask = func_021C7260(fieldMap, EVENT_DISAPPEAR_SPIN_FRAMES, EVENT_DISAPPEAR_SPIN_EASE_IN_COUNT);
        linearTask = func_021C71D4(fieldMap, EVENT_DISAPPEAR_SPIN_FRAMES, EVENT_DISAPPEAR_SPIN_LINEAR_COUNT);
        waitTask = func_021C77D8(fieldMap, 0x1e);
        fadeTask = func_021C7814(fieldMap, 3, 0, 0x10, 1);
        func_021C6DE0(taskManager, easeTask, 0);
        func_021C6DE0(taskManager, linearTask, easeTask);
        func_021C6DE0(taskManager, waitTask, 0);
        func_021C6DE0(taskManager, fadeTask, waitTask);
        if (work->soundVariant != 0)
            func_020061E4(EVENT_DISAPPEAR_SE_FADE_ALT);
        else
            func_020061E4(EVENT_DISAPPEAR_SE_FADE);
        anime = func_0218FE80(fieldMap);
        work->cameraAnime.frames = EVENT_DISAPPEAR_ZOOM_FRAMES;
        work->cameraAnime.detachTarget = 1;
        work->cameraAnime.stopTrace = 1;
        work->cameraAnimeHandle = anime;
        func_0218FEA0(anime, &work->cameraAnime);
        func_0218FEA4(work->cameraAnimeHandle);
        func_0218FE78(camera, &work->cameraAnime.start);
        work->cameraAnime.end = work->cameraAnime.start;
        work->cameraAnime.end.distance -= EVENT_DISAPPEAR_ZOOM_DISTANCE;
        func_0218FEC0(work->cameraAnimeHandle);
        func_0218FF00(work->cameraAnimeHandle);
        *seq = *seq + 1;
        break;
    case EVENT_DISAPPEAR_FADE_WAIT:
        if (func_021C6E48(taskManager))
            *seq = *seq + 1;
        break;
    case EVENT_DISAPPEAR_FADE_END:
        func_0218FF20(work->cameraAnimeHandle);
        func_0218FE98(work->cameraAnimeHandle);
        return EVENT_DISAPPEAR_FINISHED;
    }
    return EVENT_DISAPPEAR_CONTINUE;
}

/*
 * Rising spin: the player spins and rises (draw offset 0x96000) while the
 * screen fades out. It is the mirror of the descending spin of
 * event_appear.c.
 */
int func_021C04C0(GameEvent *event, int *seq, EventDisappearWork *work)
{
    FieldMap *fieldMap;
    struct FieldPlayer *player;
    struct FieldCamera *camera;
    FieldTask *spinTask;
    FieldTask *fadeTask;
    FieldTask *offsetTask;
    FieldTaskManager *taskManager;

    fieldMap = work->fieldMap;
    player = func_02188CB4(fieldMap);
    camera = func_02188C58(fieldMap);
    switch (*seq) {
    case EVENT_DISAPPEAR_RISE_START:
        work->savedCameraMode = func_0218E138(camera);
        func_0218E13C(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
        {
            VecFx32 riseOffset;
            riseOffset.y = 0x96000;
            riseOffset.x = 0;
            riseOffset.z = 0;
            spinTask = func_021C71D4(fieldMap, 0x18, 3);
            fadeTask = func_021C7814(fieldMap, 3, 0, 0x10, 1);
            offsetTask = func_021C7858(fieldMap, 0x18, &riseOffset);
        }
        taskManager = func_02188D38(fieldMap);
        func_021C6DE0(taskManager, spinTask, 0);
        func_021C6DE0(taskManager, offsetTask, 0);
        func_021C6DE0(taskManager, fadeTask, offsetTask);
        func_020061E4(EVENT_DISAPPEAR_SE_FADE);
        (*seq)++;
        break;
    case EVENT_DISAPPEAR_RISE_WAIT:
        if (func_021C6E48(func_02188D38(fieldMap)) != 0 && func_0204E804() == 0)
            (*seq)++;
        break;
    case EVENT_DISAPPEAR_RISE_RESTORE:
        func_0218E13C(camera, work->savedCameraMode);
        (*seq)++;
        break;
    case EVENT_DISAPPEAR_RISE_END:
        return EVENT_DISAPPEAR_FINISHED;
    }
    return EVENT_DISAPPEAR_CONTINUE;
}
