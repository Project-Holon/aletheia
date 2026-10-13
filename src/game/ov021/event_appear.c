/*
 * file:     event_appear.c
 * unit:     yes
 * function: func_021BF58C, func_021BF5B4, func_021BF5E8, func_021BF61C, func_021BF644, func_021BF66C, func_021BF694, func_021BF76C, func_021BF7F8, func_021BF860, func_021BF874, func_021BF898, func_021BF8DC, func_021BF8EC, func_021BF978, func_021BF9E0, func_021BF9F4, func_021BFA18, func_021BFA5C, func_021BFA6C, func_021BFB90, func_021BFC98
 * address:  0x021BF58C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_player_grid_event.c at 0x021BF58C (lane CL118, name guess, no __FILE__ anchor: six 0x68-byte player appear events (drop, spin ease-out, rise) and their handlers).
 *
 * symbols:
 *   func_02012374  0x02012374  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0218E138  0x0218E138  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_021C7684  0x021C7684  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   d_021DA080     0x021DA080  data   a4
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218FE80 0x0218FE80 thumb ov021
 *   func_0218FEA0 0x0218FEA0 thumb ov021
 *   func_0218FEA4 0x0218FEA4 thumb ov021
 *   func_0218FE78 0x0218FE78 thumb ov021
 *   func_0218FEC0 0x0218FEC0 thumb ov021
 *   func_0218FF00 0x0218FF00 thumb ov021
 *   func_0218FF20  0x0218FF20  thumb  ov021
 *   func_0218FE98  0x0218FE98  thumb  ov021
 *   func_021C72AC  0x021C72AC  thumb  ov021
 *   func_021BE9A0 0x021BE9A0 thumb ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021AC528  0x021AC528  thumb  ov021
 *   func_021C71D4  0x021C71D4  thumb  ov021
 *   func_021C7858  0x021C7858  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D454 0x0216D454 thumb ov010
 *   func_0216D480 0x0216D480 thumb ov010
 */
/*
 * Player appear events of a map change (EVENT_APPEAR_*). They run on the new
 * map after the field has been rebuilt: the screen fades in and the player
 * arrives by one of six effects (drop from above, a camera zoom-out with a
 * spin, a spin with a smoke puff, a spin that comes down from above, a
 * single move animation). event_mapchange.c picks the event by the kind of
 * the map change; event_disappear.c holds the matching leave events.
 *
 * Every event is a GAME_EVENT with a 0x68-byte work. The creators take the
 * parent event, the game system and the field map. The events switch the
 * field camera to mode FIELD_CAMERA_MODE_TRACK_TARGET while they run and put
 * the saved mode back at the end.
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

/* Values an event function returns to the event runner. */
enum {
    EVENT_APPEAR_CONTINUE,
    EVENT_APPEAR_FINISHED
};

/* Sound effect and move animation codes the events start. */
#define EVENT_APPEAR_SE_DESCENT_END 0x67B       /* the descending spin ends */
#define EVENT_APPEAR_ACMD_DROP_START 1          /* move animation of the drop event */
#define EVENT_APPEAR_ACMD_APPEAR 0x44           /* move animation of the move animation event */

/* Camera zoom-out and player spin (spin zoom events). */
#define EVENT_APPEAR_ZOOM_FRAMES 60
#define EVENT_APPEAR_SPIN_COUNT 8
#define EVENT_APPEAR_SPIN_END_DIRECTION 1
#define EVENT_APPEAR_ZOOM_DISTANCE 0x64000      /* fx32: the camera starts this much closer */

/* The player drop (FIELD_TASK_CreatePlayerDrop): frames and height. */
#define EVENT_APPEAR_DROP_FRAMES 0x28
#define EVENT_APPEAR_DROP_HEIGHT 0xFA

/* Work of the appear events (0x68 bytes). */
typedef struct EventAppearWork {
    GameSystem *gameSystem;                     /* 0x00 */
    FieldMap *fieldMap;                         /* 0x04 */
    unsigned int savedCameraMode;               /* 0x08: camera mode before the event */
    FieldCameraAnimeData cameraAnime;           /* 0x0C: camera zoom-out request */
    struct FieldCameraAnime *cameraAnimeHandle; /* 0x58 */
    int showSeasonScoreboard;                   /* 0x5C: nonzero fades in with the season scoreboard */
    int seasonShown;                            /* 0x60: season on the scoreboard before */
    int seasonTarget;                           /* 0x64: season on the scoreboard after */
} EventAppearWork;

typedef int (*EventAppearFunc)(GameEvent *event, int *seq, EventAppearWork *work);
typedef void (*EventAppearCallback)(EventAppearWork *work);

/* Steps of the drop event. */
enum {
    EVENT_APPEAR_DROP_START,
    EVENT_APPEAR_DROP_WAIT,
    EVENT_APPEAR_DROP_RESTORE,
    EVENT_APPEAR_DROP_END
};

/* Steps of the spin zoom events (both copies and the smoke variant). */
enum {
    EVENT_APPEAR_ZOOM_END_DELAY,
    EVENT_APPEAR_ZOOM_WAIT_DELAY,
    EVENT_APPEAR_ZOOM_START,
    EVENT_APPEAR_ZOOM_FADE_IN,
    EVENT_APPEAR_ZOOM_WAIT,
    EVENT_APPEAR_ZOOM_END
};

/* Steps of the descending spin event. */
enum {
    EVENT_APPEAR_DESCENT_START,
    EVENT_APPEAR_DESCENT_WAIT,
    EVENT_APPEAR_DESCENT_SMOKE,
    EVENT_APPEAR_DESCENT_RESTORE,
    EVENT_APPEAR_DESCENT_END
};

/* Steps of the move animation event. */
enum {
    EVENT_APPEAR_ACMD_START,
    EVENT_APPEAR_ACMD_WAIT,
    EVENT_APPEAR_ACMD_RESTORE,
    EVENT_APPEAR_ACMD_END
};

extern GameEvent *func_020122C0(GameSystem *gameSystem, GameEvent *parent, EventAppearFunc func, u32 workSize);
extern void *func_020124E8(GameEvent *event);
extern void func_02012374(GameEvent *parent, GameEvent *child);
extern struct FieldCamera *func_02188C58(FieldMap *fieldMap);
extern struct FieldPlayer *func_02188CB4(FieldMap *fieldMap);
extern FieldTaskManager *func_02188D38(FieldMap *fieldMap);
extern struct FieldEffectCtrl *func_02188CD0(FieldMap *fieldMap);
extern Mmdl *func_021A3074(struct FieldPlayer *player);
extern unsigned int func_0218E138(struct FieldCamera *camera);
extern void func_0218E13C(struct FieldCamera *camera, unsigned int mode);
extern void func_0218F0A8(struct FieldCamera *camera);
extern unsigned int func_0218F0E8(struct FieldCamera *camera);
extern void func_0216D8C0(Mmdl *mmdl, VecFx32 *offset);
extern void func_0216D410(Mmdl *mmdl, u16 acmdCode);
extern int func_0216D454(Mmdl *mmdl);
extern int func_0216D480(Mmdl *mmdl);
extern GameEvent *func_021BE92C(GameSystem *gameSystem, FieldMap *fieldMap, int mode, int wait, int bgInit, u8 season, u8 seasonTarget);
extern GameEvent *func_021BE9A0(GameSystem *gameSystem, FieldMap *fieldMap, int seasonShown, int seasonTarget, EventAppearCallback finishCallback, EventAppearWork *finishCallbackArg);
extern FieldTask *func_021C7684(FieldMap *fieldMap, Mmdl *mmdl, int frames, int height);
extern FieldTask *func_021C72AC(FieldMap *fieldMap, u16 frames, int spins, int endDirection);
extern FieldTask *func_021C71D4(FieldMap *fieldMap, u32 frames, u32 spins);
extern FieldTask *func_021C7858(FieldMap *fieldMap, int frames, const VecFx32 *offset);
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
extern void func_021AC528(Mmdl *mmdl, struct FieldEffectCtrl *effectCtrl);
extern void func_020061E4(u32 seId);

GameEvent *func_021BF58C(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *func_021BF5B4(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int showSeasonScoreboard, int seasonShown, int seasonTarget);
GameEvent *func_021BF5E8(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int showSeasonScoreboard, int seasonShown, int seasonTarget);
GameEvent *func_021BF61C(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *func_021BF644(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *func_021BF66C(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
int func_021BF694(GameEvent *event, int *seq, EventAppearWork *work);
int func_021BF76C(GameEvent *event, int *seq, EventAppearWork *work);
void func_021BF7F8(EventAppearWork *work);
void func_021BF860(EventAppearWork *work);
void func_021BF874(EventAppearWork *work);
GameEvent *func_021BF898(EventAppearWork *work);
void func_021BF8DC(EventAppearWork *work);
int func_021BF8EC(GameEvent *event, int *seq, EventAppearWork *work);
void func_021BF978(EventAppearWork *work);
void func_021BF9E0(EventAppearWork *work);
void func_021BF9F4(EventAppearWork *work);
GameEvent *func_021BFA18(EventAppearWork *work);
void func_021BFA5C(EventAppearWork *work);
int func_021BFA6C(GameEvent *event, int *seq, EventAppearWork *work);
int func_021BFB90(GameEvent *event, int *seq, EventAppearWork *work);
int func_021BFC98(GameEvent *event, int *seq, EventAppearWork *work);

extern const VecFx32 d_021DA080;

/* Creates the player drop event. */
GameEvent *func_021BF58C(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, parent, func_021BF694, 0x68);
    EventAppearWork *work = func_020124E8(event);

    work->fieldMap = fieldMap;
    work->gameSystem = gameSystem;
    return event;
}

/* Creates the spin zoom event with an optional season scoreboard. */
GameEvent *func_021BF5B4(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int showSeasonScoreboard, int seasonShown, int seasonTarget)
{
    GameEvent *event = func_020122C0(gameSystem, parent, func_021BF76C, 0x68);
    EventAppearWork *work = func_020124E8(event);

    work->fieldMap = fieldMap;
    work->gameSystem = gameSystem;
    work->showSeasonScoreboard = showSeasonScoreboard;
    work->seasonShown = seasonShown;
    work->seasonTarget = seasonTarget;
    return event;
}

/* Second copy of the spin zoom event; the map change events use the two as pairs. */
GameEvent *func_021BF5E8(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int showSeasonScoreboard, int seasonShown, int seasonTarget)
{
    GameEvent *event = func_020122C0(gameSystem, parent, func_021BF8EC, 0x68);
    EventAppearWork *work = func_020124E8(event);

    work->fieldMap = fieldMap;
    work->gameSystem = gameSystem;
    work->showSeasonScoreboard = showSeasonScoreboard;
    work->seasonShown = seasonShown;
    work->seasonTarget = seasonTarget;
    return event;
}

/* Creates the spin zoom event that ends with a smoke puff at the player. */
GameEvent *func_021BF61C(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, parent, func_021BFA6C, 0x68);
    EventAppearWork *work = func_020124E8(event);

    work->fieldMap = fieldMap;
    work->gameSystem = gameSystem;
    return event;
}

/* Creates the descending spin event. */
GameEvent *func_021BF644(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, parent, func_021BFB90, 0x68);
    EventAppearWork *work = func_020124E8(event);

    work->fieldMap = fieldMap;
    work->gameSystem = gameSystem;
    return event;
}

/* Creates the move animation event. */
GameEvent *func_021BF66C(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, parent, func_021BFC98, 0x68);
    EventAppearWork *work = func_020124E8(event);

    work->fieldMap = fieldMap;
    work->gameSystem = gameSystem;
    return event;
}

/*
 * Player drop: the player starts above the ground (draw offset from
 * d_021DA080), the screen fades in and the player falls to the ground.
 */
int func_021BF694(GameEvent *event, int *seq, EventAppearWork *work)
{
    struct FieldCamera *camera = func_02188C58(work->fieldMap);
    VecFx32 drawOffset;
    Mmdl *player;
    FieldTask *dropTask;

    switch (*seq) {
    case EVENT_APPEAR_DROP_START:
        work->savedCameraMode = func_0218E138(camera);
        func_0218E13C(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
        drawOffset = d_021DA080;
        player = func_021A3074(func_02188CB4(work->fieldMap));
        func_0216D8C0(player, &drawOffset);
        func_0216D410(player, EVENT_APPEAR_ACMD_DROP_START);
        func_02012374(event, func_021BE92C(work->gameSystem, work->fieldMap, 0, 1, 1, 0, 0));
        dropTask = func_021C7684(work->fieldMap, func_021A3074(func_02188CB4(work->fieldMap)), EVENT_APPEAR_DROP_FRAMES, EVENT_APPEAR_DROP_HEIGHT);
        func_021C6DE0(func_02188D38(work->fieldMap), dropTask, 0);
        (*seq)++;
        break;
    case EVENT_APPEAR_DROP_WAIT:
        if (func_021C6E48(func_02188D38(work->fieldMap)) != 0)
            (*seq)++;
        break;
    case EVENT_APPEAR_DROP_RESTORE:
        func_0218E13C(camera, work->savedCameraMode);
        (*seq)++;
        break;
    case EVENT_APPEAR_DROP_END:
        return EVENT_APPEAR_FINISHED;
    }
    return EVENT_APPEAR_CONTINUE;
}

/*
 * Spin zoom: the camera moves away from the target to its normal pose while
 * the player spins into place. With the season scoreboard the spin and the zoom start when the
 * scoreboard ends (func_021BF8DC), else at once. func_021C6E48 takes the task
 * manager that stays live across the switch, which puts the step number in r1.
 */
int func_021BF76C(GameEvent *event, int *seq, EventAppearWork *work)
{
    FieldMap *fieldMap;
    struct FieldCamera *camera;
    FieldTaskManager *taskManager;

    fieldMap = work->fieldMap;
    camera = func_02188C58(fieldMap);
    taskManager = func_02188D38(fieldMap);
    switch (*seq) {
    case EVENT_APPEAR_ZOOM_END_DELAY:
        func_0218F0A8(camera);
        (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_WAIT_DELAY:
        if (func_0218F0E8(camera) == 0)
            (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_START:
        if (work->showSeasonScoreboard == 0) {
            func_021BF874(work);
            func_021BF7F8(work);
        }
        (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_FADE_IN:
        func_02012374(event, func_021BF898(work));
        (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_WAIT:
        if (func_021C6E48(taskManager) != 0)
            (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_END:
        func_021BF860(work);
        return EVENT_APPEAR_FINISHED;
    }
    return EVENT_APPEAR_CONTINUE;
}

/* Starts the camera zoom-out: from a pose closer to the target to the current pose. */
void func_021BF7F8(EventAppearWork *work)
{
    struct FieldCamera *camera;
    struct FieldCameraAnime *anime;

    camera = func_02188C58(work->fieldMap);
    anime = func_0218FE80(work->fieldMap);
    work->cameraAnime.frames = EVENT_APPEAR_ZOOM_FRAMES;
    work->cameraAnime.detachTarget = 1;
    work->cameraAnime.stopTrace = 1;
    work->cameraAnimeHandle = anime;
    func_0218FEA0(anime, &work->cameraAnime);
    func_0218FEA4(work->cameraAnimeHandle);
    func_0218FE78(camera, &work->cameraAnime.end);
    work->cameraAnime.start = work->cameraAnime.end;
    work->cameraAnime.start.distance = work->cameraAnime.start.distance - EVENT_APPEAR_ZOOM_DISTANCE;
    func_0218FEC0(work->cameraAnimeHandle);
    func_0218FF00(work->cameraAnimeHandle);
}

/* Ends the camera zoom-out and frees its handle. */
void func_021BF860(EventAppearWork *work)
{
    func_0218FF20(work->cameraAnimeHandle);
    func_0218FE98(work->cameraAnimeHandle);
}

/* Starts the player spin that ends facing the map direction. */
void func_021BF874(EventAppearWork *work)
{
    func_021C6DE0(func_02188D38(work->fieldMap), func_021C72AC(work->fieldMap, EVENT_APPEAR_ZOOM_FRAMES, EVENT_APPEAR_SPIN_COUNT, EVENT_APPEAR_SPIN_END_DIRECTION), 0);
}

/* Fades in; with the scoreboard the spin and the zoom start when it ends. */
GameEvent *func_021BF898(EventAppearWork *work)
{
    int showSeasonScoreboard = work->showSeasonScoreboard;
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;

    if (showSeasonScoreboard != 0) {
        return func_021BE9A0(gameSystem, fieldMap, (u8)work->seasonShown, (u8)work->seasonTarget, func_021BF8DC, work);
    }
    return func_021BE92C(gameSystem, fieldMap, 1, 1, 1, 0, 0);
}

/* Scoreboard finished: start the spin and the zoom. */
void func_021BF8DC(EventAppearWork *work)
{
    func_021BF874(work);
    func_021BF7F8(work);
}

/*
 * Second copy of the spin zoom (func_021BF76C). Its fade-in, scoreboard
 * callback and helpers are copies as well.
 */
int func_021BF8EC(GameEvent *event, int *seq, EventAppearWork *work)
{
    FieldMap *fieldMap;
    struct FieldCamera *camera;
    FieldTaskManager *taskManager;

    fieldMap = work->fieldMap;
    camera = func_02188C58(fieldMap);
    taskManager = func_02188D38(fieldMap);
    switch (*seq) {
    case EVENT_APPEAR_ZOOM_END_DELAY:
        func_0218F0A8(camera);
        (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_WAIT_DELAY:
        if (func_0218F0E8(camera) == 0)
            (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_START:
        if (work->showSeasonScoreboard == 0) {
            func_021BF9F4(work);
            func_021BF978(work);
        }
        (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_FADE_IN:
        func_02012374(event, func_021BFA18(work));
        (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_WAIT:
        if (func_021C6E48(taskManager) != 0)
            (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_END:
        func_021BF9E0(work);
        return EVENT_APPEAR_FINISHED;
    }
    return EVENT_APPEAR_CONTINUE;
}

/* Copy of func_021BF7F8. */
void func_021BF978(EventAppearWork *work)
{
    struct FieldCamera *camera;
    struct FieldCameraAnime *anime;

    camera = func_02188C58(work->fieldMap);
    anime = func_0218FE80(work->fieldMap);
    work->cameraAnime.frames = EVENT_APPEAR_ZOOM_FRAMES;
    work->cameraAnime.detachTarget = 1;
    work->cameraAnime.stopTrace = 1;
    work->cameraAnimeHandle = anime;
    func_0218FEA0(anime, &work->cameraAnime);
    func_0218FEA4(work->cameraAnimeHandle);
    func_0218FE78(camera, &work->cameraAnime.end);
    work->cameraAnime.start = work->cameraAnime.end;
    work->cameraAnime.start.distance = work->cameraAnime.start.distance - EVENT_APPEAR_ZOOM_DISTANCE;
    func_0218FEC0(work->cameraAnimeHandle);
    func_0218FF00(work->cameraAnimeHandle);
}

/* Copy of func_021BF860. */
void func_021BF9E0(EventAppearWork *work)
{
    func_0218FF20(work->cameraAnimeHandle);
    func_0218FE98(work->cameraAnimeHandle);
}

/* Copy of func_021BF874. */
void func_021BF9F4(EventAppearWork *work)
{
    func_021C6DE0(func_02188D38(work->fieldMap), func_021C72AC(work->fieldMap, EVENT_APPEAR_ZOOM_FRAMES, EVENT_APPEAR_SPIN_COUNT, EVENT_APPEAR_SPIN_END_DIRECTION), 0);
}

/* Copy of func_021BF898. */
GameEvent *func_021BFA18(EventAppearWork *work)
{
    int showSeasonScoreboard = work->showSeasonScoreboard;
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;

    if (showSeasonScoreboard != 0) {
        return func_021BE9A0(gameSystem, fieldMap, (u8)work->seasonShown, (u8)work->seasonTarget, func_021BFA5C, work);
    }
    return func_021BE92C(gameSystem, fieldMap, 1, 1, 1, 0, 0);
}

/* Copy of func_021BF8DC. */
void func_021BFA5C(EventAppearWork *work)
{
    func_021BF9F4(work);
    func_021BF978(work);
}

/*
 * Spin zoom that ends with a smoke puff: the spin task, the camera zoom-out
 * and the fade-in start in sequence, and the smoke starts at the player when
 * the spin is over.
 */
int func_021BFA6C(GameEvent *event, int *seq, EventAppearWork *work)
{
    GameSystem *gameSystem;
    FieldMap *fieldMap;
    struct FieldCamera *camera;
    FieldTaskManager *taskManager;
    struct FieldCameraAnime *anime;
    Mmdl *player;

    gameSystem = work->gameSystem;
    fieldMap = work->fieldMap;
    camera = func_02188C58(fieldMap);
    taskManager = func_02188D38(fieldMap);
    switch (*seq) {
    case EVENT_APPEAR_ZOOM_END_DELAY:
        func_0218F0A8(camera);
        (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_WAIT_DELAY:
        if (func_0218F0E8(camera) == 0)
            (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_START:
        func_021C6DE0(taskManager, func_021C72AC(fieldMap, EVENT_APPEAR_ZOOM_FRAMES, EVENT_APPEAR_SPIN_COUNT, EVENT_APPEAR_SPIN_END_DIRECTION), 0);
        anime = func_0218FE80(fieldMap);
        work->cameraAnime.frames = EVENT_APPEAR_ZOOM_FRAMES;
        work->cameraAnime.detachTarget = 1;
        work->cameraAnime.stopTrace = 1;
        work->cameraAnimeHandle = anime;
        func_0218FEA0(anime, &work->cameraAnime);
        func_0218FEA4(work->cameraAnimeHandle);
        func_0218FE78(camera, &work->cameraAnime.end);
        work->cameraAnime.start = work->cameraAnime.end;
        work->cameraAnime.start.distance = work->cameraAnime.start.distance - EVENT_APPEAR_ZOOM_DISTANCE;
        func_0218FEC0(work->cameraAnimeHandle);
        func_0218FF00(work->cameraAnimeHandle);
        (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_FADE_IN:
        func_02012374(event, func_021BE92C(gameSystem, fieldMap, 0, 1, 1, 0, 0));
        (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_WAIT:
        if (func_021C6E48(taskManager) != 0) {
            player = func_021A3074(func_02188CB4(fieldMap));
            func_021AC528(player, func_02188CD0(fieldMap));
            (*seq)++;
        }
        break;
    case EVENT_APPEAR_ZOOM_END:
        func_0218FF20(work->cameraAnimeHandle);
        func_0218FE98(work->cameraAnimeHandle);
        return EVENT_APPEAR_FINISHED;
    }
    return EVENT_APPEAR_CONTINUE;
}

/*
 * Descending spin: the player starts high above the ground, the screen fades
 * in and a spin task and a draw offset task bring the player down. It is the
 * mirror of the rising spin of event_disappear.c.
 */
int func_021BFB90(GameEvent *event, int *seq, EventAppearWork *work)
{
    FieldMap *fieldMap;
    struct FieldCamera *camera;
    Mmdl *player;
    FieldTask *spinTask;
    FieldTask *offsetTask;
    FieldTaskManager *taskManager;

    fieldMap = work->fieldMap;
    camera = func_02188C58(fieldMap);
    switch (*seq) {
    case EVENT_APPEAR_DESCENT_START:
        work->savedCameraMode = func_0218E138(camera);
        func_0218E13C(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
        player = func_021A3074(func_02188CB4(fieldMap));
        {
            VecFx32 startOffset;
            startOffset.y = 0xA000;
            startOffset.x = 0;
            startOffset.z = 0;
            func_0216D8C0(player, &startOffset);
        }
        func_02012374(event, func_021BE92C(work->gameSystem, fieldMap, 0, 1, 1, 0, 0));
        {
            VecFx32 riseOffset;
            riseOffset.y = 0x96000;
            riseOffset.x = 0;
            riseOffset.z = 0;
            spinTask = func_021C71D4(fieldMap, 0x18, 3);
            offsetTask = func_021C7858(fieldMap, -0x18, &riseOffset);
        }
        taskManager = func_02188D38(fieldMap);
        func_021C6DE0(taskManager, spinTask, 0);
        func_021C6DE0(taskManager, offsetTask, 0);
        (*seq)++;
        break;
    case EVENT_APPEAR_DESCENT_WAIT:
        if (func_021C6E48(func_02188D38(fieldMap)) != 0)
            (*seq)++;
        break;
    case EVENT_APPEAR_DESCENT_SMOKE:
        player = func_021A3074(func_02188CB4(fieldMap));
        func_021AC528(player, func_02188CD0(work->fieldMap));
        func_020061E4(EVENT_APPEAR_SE_DESCENT_END);
        (*seq)++;
        break;
    case EVENT_APPEAR_DESCENT_RESTORE:
        func_0218E13C(camera, work->savedCameraMode);
        (*seq)++;
        break;
    case EVENT_APPEAR_DESCENT_END:
        return EVENT_APPEAR_FINISHED;
    }
    return EVENT_APPEAR_CONTINUE;
}

/*
 * Move animation: the screen fades in while the player plays the move
 * animation EVENT_APPEAR_ACMD_APPEAR.
 */
int func_021BFC98(GameEvent *event, int *seq, EventAppearWork *work)
{
    struct FieldCamera *camera = func_02188C58(work->fieldMap);
    Mmdl *player;

    player = func_021A3074(func_02188CB4(work->fieldMap));
    switch (*seq) {
    case EVENT_APPEAR_ACMD_START:
        work->savedCameraMode = func_0218E138(camera);
        func_0218E13C(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
        func_0216D410(player, EVENT_APPEAR_ACMD_APPEAR);
        func_02012374(event, func_021BE92C(work->gameSystem, work->fieldMap, 0, 1, 1, 0, 0));
        (*seq)++;
        break;
    case EVENT_APPEAR_ACMD_WAIT:
        if (func_0216D454(player) == 1) {
            func_0216D480(player);
            (*seq)++;
        }
        break;
    case EVENT_APPEAR_ACMD_RESTORE:
        func_0218E13C(camera, work->savedCameraMode);
        (*seq)++;
        break;
    case EVENT_APPEAR_ACMD_END:
        return EVENT_APPEAR_FINISHED;
    }
    return EVENT_APPEAR_CONTINUE;
}
