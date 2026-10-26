/*
 * file:     event_appear.c
 * unit:     yes
 * function: EVENT_APPEAR_CreatePlayerDrop, EVENT_APPEAR_CreateSpinZoom, EVENT_APPEAR_CreateSpinZoomAlt, EVENT_APPEAR_CreateSpinZoomSmoke, EVENT_APPEAR_CreateDescendingSpin, EVENT_APPEAR_CreateMoveAnime, EVENT_APPEAR_RunPlayerDrop, EVENT_APPEAR_RunSpinZoom, EVENT_APPEAR_StartZoomOut, EVENT_APPEAR_EndZoomOut, EVENT_APPEAR_StartPlayerSpin, EVENT_APPEAR_CreateFadeIn, EVENT_APPEAR_OnScoreboardEnd, EVENT_APPEAR_RunSpinZoomAlt, EVENT_APPEAR_StartZoomOutAlt, EVENT_APPEAR_EndZoomOutAlt, EVENT_APPEAR_StartPlayerSpinAlt, EVENT_APPEAR_CreateFadeInAlt, EVENT_APPEAR_OnScoreboardEndAlt, EVENT_APPEAR_RunSpinZoomSmoke, EVENT_APPEAR_RunDescendingSpin, EVENT_APPEAR_RunMoveAnime
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
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_CAMERA_GetMode  0x0218E138  thumb  ov021
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   FIELD_TASK_CreatePlayerDrop  0x021C7684  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 *   d_021DA080     0x021DA080  data   a4
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   FIELD_CAMERA_ANIME_Create 0x0218FE80 thumb ov021
 *   FIELD_CAMERA_ANIME_SetData 0x0218FEA0 thumb ov021
 *   FIELD_CAMERA_ANIME_Setup 0x0218FEA4 thumb ov021
 *   FIELD_CAMERA_ANIME_GetCurrentParam 0x0218FE78 thumb ov021
 *   FIELD_CAMERA_ANIME_ApplyStartParam 0x0218FEC0 thumb ov021
 *   FIELD_CAMERA_ANIME_Start 0x0218FF00 thumb ov021
 *   FIELD_CAMERA_ANIME_Restore  0x0218FF20  thumb  ov021
 *   FIELD_CAMERA_ANIME_Delete  0x0218FE98  thumb  ov021
 *   FIELD_TASK_CreatePlayerSpinEaseOut  0x021C72AC  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEventWithCallback 0x021BE9A0 thumb ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_KEMURI_Start  0x021AC528  thumb  ov021
 *   FIELD_TASK_CreatePlayerSpinLinear  0x021C71D4  thumb  ov021
 *   FIELD_TASK_CreatePlayerDrawOffsetTween  0x021C7858  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLDMMDL_CheckEndAcmd 0x0216D454 thumb ov010
 *   FLDMMDL_EndAcmd 0x0216D480 thumb ov010
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

#include "../types.h"

#include "fieldmap.h"
#include "field_task_manager.h"

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

#include "../arm9/game_event.h"
struct FieldMap;
struct FieldEffectSys;
#include "field_player.h"
#include "field_camera.h"
struct VecFx32;
struct Mmdl;
#include "../ov010/fldmmdl.h"
#include "event_fieldmap_control.h"
#include "field_camera_anime.h"
struct FieldEffectSys;
#include "fldeff_kemuri.h"
#include "../arm9/gfl_use.h"

GameEvent *EVENT_APPEAR_CreatePlayerDrop(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_APPEAR_CreateSpinZoom(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int showSeasonScoreboard, int seasonShown, int seasonTarget);
GameEvent *EVENT_APPEAR_CreateSpinZoomAlt(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int showSeasonScoreboard, int seasonShown, int seasonTarget);
GameEvent *EVENT_APPEAR_CreateSpinZoomSmoke(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_APPEAR_CreateDescendingSpin(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_APPEAR_CreateMoveAnime(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
int EVENT_APPEAR_RunPlayerDrop(struct GameEvent *event, int *seq, void *work);
int EVENT_APPEAR_RunSpinZoom(struct GameEvent *event, int *seq, void *work);
void EVENT_APPEAR_StartZoomOut(EventAppearWork *work);
void EVENT_APPEAR_EndZoomOut(EventAppearWork *work);
void EVENT_APPEAR_StartPlayerSpin(EventAppearWork *work);
GameEvent *EVENT_APPEAR_CreateFadeIn(EventAppearWork *work);
void EVENT_APPEAR_OnScoreboardEnd(void *workArg);
int EVENT_APPEAR_RunSpinZoomAlt(struct GameEvent *event, int *seq, void *work);
void EVENT_APPEAR_StartZoomOutAlt(EventAppearWork *work);
void EVENT_APPEAR_EndZoomOutAlt(EventAppearWork *work);
void EVENT_APPEAR_StartPlayerSpinAlt(EventAppearWork *work);
GameEvent *EVENT_APPEAR_CreateFadeInAlt(EventAppearWork *work);
void EVENT_APPEAR_OnScoreboardEndAlt(void *workArg);
int EVENT_APPEAR_RunSpinZoomSmoke(struct GameEvent *event, int *seq, void *work);
int EVENT_APPEAR_RunDescendingSpin(struct GameEvent *event, int *seq, void *work);
int EVENT_APPEAR_RunMoveAnime(struct GameEvent *event, int *seq, void *work);

extern const VecFx32 d_021DA080;

/* Creates the player drop event. */
GameEvent *EVENT_APPEAR_CreatePlayerDrop(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, parent, EVENT_APPEAR_RunPlayerDrop, sizeof(EventAppearWork));
    EventAppearWork *work = GAME_EVENT_GetWork(event);

    work->fieldMap = fieldMap;
    work->gameSystem = gameSystem;
    return event;
}

/* Creates the spin zoom event with an optional season scoreboard. */
GameEvent *EVENT_APPEAR_CreateSpinZoom(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int showSeasonScoreboard, int seasonShown, int seasonTarget)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, parent, EVENT_APPEAR_RunSpinZoom, sizeof(EventAppearWork));
    EventAppearWork *work = GAME_EVENT_GetWork(event);

    work->fieldMap = fieldMap;
    work->gameSystem = gameSystem;
    work->showSeasonScoreboard = showSeasonScoreboard;
    work->seasonShown = seasonShown;
    work->seasonTarget = seasonTarget;
    return event;
}

/* Second copy of the spin zoom event; the map change events use the two as pairs. */
GameEvent *EVENT_APPEAR_CreateSpinZoomAlt(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int showSeasonScoreboard, int seasonShown, int seasonTarget)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, parent, EVENT_APPEAR_RunSpinZoomAlt, sizeof(EventAppearWork));
    EventAppearWork *work = GAME_EVENT_GetWork(event);

    work->fieldMap = fieldMap;
    work->gameSystem = gameSystem;
    work->showSeasonScoreboard = showSeasonScoreboard;
    work->seasonShown = seasonShown;
    work->seasonTarget = seasonTarget;
    return event;
}

/* Creates the spin zoom event that ends with a smoke puff at the player. */
GameEvent *EVENT_APPEAR_CreateSpinZoomSmoke(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, parent, EVENT_APPEAR_RunSpinZoomSmoke, sizeof(EventAppearWork));
    EventAppearWork *work = GAME_EVENT_GetWork(event);

    work->fieldMap = fieldMap;
    work->gameSystem = gameSystem;
    return event;
}

/* Creates the descending spin event. */
GameEvent *EVENT_APPEAR_CreateDescendingSpin(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, parent, EVENT_APPEAR_RunDescendingSpin, sizeof(EventAppearWork));
    EventAppearWork *work = GAME_EVENT_GetWork(event);

    work->fieldMap = fieldMap;
    work->gameSystem = gameSystem;
    return event;
}

/* Creates the move animation event. */
GameEvent *EVENT_APPEAR_CreateMoveAnime(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, parent, EVENT_APPEAR_RunMoveAnime, sizeof(EventAppearWork));
    EventAppearWork *work = GAME_EVENT_GetWork(event);

    work->fieldMap = fieldMap;
    work->gameSystem = gameSystem;
    return event;
}

/*
 * Player drop: the player starts above the ground (draw offset from
 * d_021DA080), the screen fades in and the player falls to the ground.
 */
int EVENT_APPEAR_RunPlayerDrop(struct GameEvent *event, int *seq, void *workPtr)
{
    EventAppearWork *work = workPtr;
    struct FieldCamera *camera = FIELDMAP_GetCamera(work->fieldMap);
    VecFx32 drawOffset;
    Mmdl *player;
    FieldTask *dropTask;

    switch (*seq) {
    case EVENT_APPEAR_DROP_START:
        work->savedCameraMode = FIELD_CAMERA_GetMode(camera);
        FIELD_CAMERA_SetMode(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
        drawOffset = d_021DA080;
        player = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(work->fieldMap));
        FLDMMDL_SetDrawOffset(player, (struct VecFx32 *)(&drawOffset));
        FLDMMDL_SetAcmd(player, EVENT_APPEAR_ACMD_DROP_START);
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(work->gameSystem, work->fieldMap, 0, 1, 1, 0, 0));
        dropTask = FIELD_TASK_CreatePlayerDrop(work->fieldMap, FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(work->fieldMap)), EVENT_APPEAR_DROP_FRAMES, EVENT_APPEAR_DROP_HEIGHT);
        FIELD_TASK_MANAGER_AddTask(FIELDMAP_GetTaskManager(work->fieldMap), dropTask, 0);
        (*seq)++;
        break;
    case EVENT_APPEAR_DROP_WAIT:
        if (FIELD_TASK_MANAGER_IsEmpty(FIELDMAP_GetTaskManager(work->fieldMap)) != 0)
            (*seq)++;
        break;
    case EVENT_APPEAR_DROP_RESTORE:
        FIELD_CAMERA_SetMode(camera, work->savedCameraMode);
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
 * scoreboard ends (EVENT_APPEAR_OnScoreboardEnd), else at once. FIELD_TASK_MANAGER_IsEmpty takes the task
 * manager that stays live across the switch, which puts the step number in r1.
 */
int EVENT_APPEAR_RunSpinZoom(struct GameEvent *event, int *seq, void *workPtr)
{
    EventAppearWork *work = workPtr;
    FieldMap *fieldMap;
    struct FieldCamera *camera;
    FieldTaskManager *taskManager;

    fieldMap = work->fieldMap;
    camera = FIELDMAP_GetCamera(fieldMap);
    taskManager = FIELDMAP_GetTaskManager(fieldMap);
    switch (*seq) {
    case EVENT_APPEAR_ZOOM_END_DELAY:
        FIELD_CAMERA_EndDelay(camera);
        (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_WAIT_DELAY:
        if (FIELD_CAMERA_IsDelayEnabled(camera) == 0)
            (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_START:
        if (work->showSeasonScoreboard == 0) {
            EVENT_APPEAR_StartPlayerSpin(work);
            EVENT_APPEAR_StartZoomOut(work);
        }
        (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_FADE_IN:
        GAME_EVENT_CallEvent(event, EVENT_APPEAR_CreateFadeIn(work));
        (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_WAIT:
        if (FIELD_TASK_MANAGER_IsEmpty(taskManager) != 0)
            (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_END:
        EVENT_APPEAR_EndZoomOut(work);
        return EVENT_APPEAR_FINISHED;
    }
    return EVENT_APPEAR_CONTINUE;
}

/* Starts the camera zoom-out: from a pose closer to the target to the current pose. */
void EVENT_APPEAR_StartZoomOut(EventAppearWork *work)
{
    struct FieldCamera *camera;
    struct FieldCameraAnime *anime;

    camera = FIELDMAP_GetCamera(work->fieldMap);
    anime = FIELD_CAMERA_ANIME_Create(work->fieldMap);
    work->cameraAnime.frames = EVENT_APPEAR_ZOOM_FRAMES;
    work->cameraAnime.detachTarget = 1;
    work->cameraAnime.stopTrace = 1;
    work->cameraAnimeHandle = anime;
    FIELD_CAMERA_ANIME_SetData(anime, &work->cameraAnime);
    FIELD_CAMERA_ANIME_Setup(work->cameraAnimeHandle);
    FIELD_CAMERA_ANIME_GetCurrentParam(camera, &work->cameraAnime.end);
    work->cameraAnime.start = work->cameraAnime.end;
    work->cameraAnime.start.distance = work->cameraAnime.start.distance - EVENT_APPEAR_ZOOM_DISTANCE;
    FIELD_CAMERA_ANIME_ApplyStartParam(work->cameraAnimeHandle);
    FIELD_CAMERA_ANIME_Start(work->cameraAnimeHandle);
}

/* Ends the camera zoom-out and frees its handle. */
void EVENT_APPEAR_EndZoomOut(EventAppearWork *work)
{
    FIELD_CAMERA_ANIME_Restore(work->cameraAnimeHandle);
    FIELD_CAMERA_ANIME_Delete(work->cameraAnimeHandle);
}

/* Starts the player spin that ends facing the map direction. */
void EVENT_APPEAR_StartPlayerSpin(EventAppearWork *work)
{
    FIELD_TASK_MANAGER_AddTask(FIELDMAP_GetTaskManager(work->fieldMap), FIELD_TASK_CreatePlayerSpinEaseOut(work->fieldMap, EVENT_APPEAR_ZOOM_FRAMES, EVENT_APPEAR_SPIN_COUNT, EVENT_APPEAR_SPIN_END_DIRECTION), 0);
}

/* Fades in; with the scoreboard the spin and the zoom start when it ends. */
GameEvent *EVENT_APPEAR_CreateFadeIn(EventAppearWork *work)
{
    int showSeasonScoreboard = work->showSeasonScoreboard;
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;

    if (showSeasonScoreboard != 0) {
        return EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEventWithCallback(gameSystem, fieldMap, (u8)work->seasonShown, (u8)work->seasonTarget, EVENT_APPEAR_OnScoreboardEnd, work);
    }
    return EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 1, 1, 1, 0, 0);
}

/* Scoreboard finished: start the spin and the zoom. */
void EVENT_APPEAR_OnScoreboardEnd(void *workArg)
{
    EventAppearWork *work = workArg;
    EVENT_APPEAR_StartPlayerSpin(work);
    EVENT_APPEAR_StartZoomOut(work);
}

/*
 * Second copy of the spin zoom (EVENT_APPEAR_RunSpinZoom). Its fade-in, scoreboard
 * callback and helpers are copies as well.
 */
int EVENT_APPEAR_RunSpinZoomAlt(struct GameEvent *event, int *seq, void *workPtr)
{
    EventAppearWork *work = workPtr;
    FieldMap *fieldMap;
    struct FieldCamera *camera;
    FieldTaskManager *taskManager;

    fieldMap = work->fieldMap;
    camera = FIELDMAP_GetCamera(fieldMap);
    taskManager = FIELDMAP_GetTaskManager(fieldMap);
    switch (*seq) {
    case EVENT_APPEAR_ZOOM_END_DELAY:
        FIELD_CAMERA_EndDelay(camera);
        (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_WAIT_DELAY:
        if (FIELD_CAMERA_IsDelayEnabled(camera) == 0)
            (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_START:
        if (work->showSeasonScoreboard == 0) {
            EVENT_APPEAR_StartPlayerSpinAlt(work);
            EVENT_APPEAR_StartZoomOutAlt(work);
        }
        (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_FADE_IN:
        GAME_EVENT_CallEvent(event, EVENT_APPEAR_CreateFadeInAlt(work));
        (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_WAIT:
        if (FIELD_TASK_MANAGER_IsEmpty(taskManager) != 0)
            (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_END:
        EVENT_APPEAR_EndZoomOutAlt(work);
        return EVENT_APPEAR_FINISHED;
    }
    return EVENT_APPEAR_CONTINUE;
}

/* Copy of EVENT_APPEAR_StartZoomOut. */
void EVENT_APPEAR_StartZoomOutAlt(EventAppearWork *work)
{
    struct FieldCamera *camera;
    struct FieldCameraAnime *anime;

    camera = FIELDMAP_GetCamera(work->fieldMap);
    anime = FIELD_CAMERA_ANIME_Create(work->fieldMap);
    work->cameraAnime.frames = EVENT_APPEAR_ZOOM_FRAMES;
    work->cameraAnime.detachTarget = 1;
    work->cameraAnime.stopTrace = 1;
    work->cameraAnimeHandle = anime;
    FIELD_CAMERA_ANIME_SetData(anime, &work->cameraAnime);
    FIELD_CAMERA_ANIME_Setup(work->cameraAnimeHandle);
    FIELD_CAMERA_ANIME_GetCurrentParam(camera, &work->cameraAnime.end);
    work->cameraAnime.start = work->cameraAnime.end;
    work->cameraAnime.start.distance = work->cameraAnime.start.distance - EVENT_APPEAR_ZOOM_DISTANCE;
    FIELD_CAMERA_ANIME_ApplyStartParam(work->cameraAnimeHandle);
    FIELD_CAMERA_ANIME_Start(work->cameraAnimeHandle);
}

/* Copy of EVENT_APPEAR_EndZoomOut. */
void EVENT_APPEAR_EndZoomOutAlt(EventAppearWork *work)
{
    FIELD_CAMERA_ANIME_Restore(work->cameraAnimeHandle);
    FIELD_CAMERA_ANIME_Delete(work->cameraAnimeHandle);
}

/* Copy of EVENT_APPEAR_StartPlayerSpin. */
void EVENT_APPEAR_StartPlayerSpinAlt(EventAppearWork *work)
{
    FIELD_TASK_MANAGER_AddTask(FIELDMAP_GetTaskManager(work->fieldMap), FIELD_TASK_CreatePlayerSpinEaseOut(work->fieldMap, EVENT_APPEAR_ZOOM_FRAMES, EVENT_APPEAR_SPIN_COUNT, EVENT_APPEAR_SPIN_END_DIRECTION), 0);
}

/* Copy of EVENT_APPEAR_CreateFadeIn. */
GameEvent *EVENT_APPEAR_CreateFadeInAlt(EventAppearWork *work)
{
    int showSeasonScoreboard = work->showSeasonScoreboard;
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;

    if (showSeasonScoreboard != 0) {
        return EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEventWithCallback(gameSystem, fieldMap, (u8)work->seasonShown, (u8)work->seasonTarget, EVENT_APPEAR_OnScoreboardEndAlt, work);
    }
    return EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 1, 1, 1, 0, 0);
}

/* Copy of EVENT_APPEAR_OnScoreboardEnd. */
void EVENT_APPEAR_OnScoreboardEndAlt(void *workArg)
{
    EventAppearWork *work = workArg;
    EVENT_APPEAR_StartPlayerSpinAlt(work);
    EVENT_APPEAR_StartZoomOutAlt(work);
}

/*
 * Spin zoom that ends with a smoke puff: the spin task, the camera zoom-out
 * and the fade-in start in sequence, and the smoke starts at the player when
 * the spin is over.
 */
int EVENT_APPEAR_RunSpinZoomSmoke(struct GameEvent *event, int *seq, void *workPtr)
{
    EventAppearWork *work = workPtr;
    GameSystem *gameSystem;
    FieldMap *fieldMap;
    struct FieldCamera *camera;
    FieldTaskManager *taskManager;
    struct FieldCameraAnime *anime;
    Mmdl *player;

    gameSystem = work->gameSystem;
    fieldMap = work->fieldMap;
    camera = FIELDMAP_GetCamera(fieldMap);
    taskManager = FIELDMAP_GetTaskManager(fieldMap);
    switch (*seq) {
    case EVENT_APPEAR_ZOOM_END_DELAY:
        FIELD_CAMERA_EndDelay(camera);
        (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_WAIT_DELAY:
        if (FIELD_CAMERA_IsDelayEnabled(camera) == 0)
            (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_START:
        FIELD_TASK_MANAGER_AddTask(taskManager, FIELD_TASK_CreatePlayerSpinEaseOut(fieldMap, EVENT_APPEAR_ZOOM_FRAMES, EVENT_APPEAR_SPIN_COUNT, EVENT_APPEAR_SPIN_END_DIRECTION), 0);
        anime = FIELD_CAMERA_ANIME_Create(fieldMap);
        work->cameraAnime.frames = EVENT_APPEAR_ZOOM_FRAMES;
        work->cameraAnime.detachTarget = 1;
        work->cameraAnime.stopTrace = 1;
        work->cameraAnimeHandle = anime;
        FIELD_CAMERA_ANIME_SetData(anime, &work->cameraAnime);
        FIELD_CAMERA_ANIME_Setup(work->cameraAnimeHandle);
        FIELD_CAMERA_ANIME_GetCurrentParam(camera, &work->cameraAnime.end);
        work->cameraAnime.start = work->cameraAnime.end;
        work->cameraAnime.start.distance = work->cameraAnime.start.distance - EVENT_APPEAR_ZOOM_DISTANCE;
        FIELD_CAMERA_ANIME_ApplyStartParam(work->cameraAnimeHandle);
        FIELD_CAMERA_ANIME_Start(work->cameraAnimeHandle);
        (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_FADE_IN:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 0, 1, 1, 0, 0));
        (*seq)++;
        break;
    case EVENT_APPEAR_ZOOM_WAIT:
        if (FIELD_TASK_MANAGER_IsEmpty(taskManager) != 0) {
            player = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
            FLDEFF_KEMURI_Start(player, (struct FieldEffectSys *)FIELDMAP_GetEffect(fieldMap));
            (*seq)++;
        }
        break;
    case EVENT_APPEAR_ZOOM_END:
        FIELD_CAMERA_ANIME_Restore(work->cameraAnimeHandle);
        FIELD_CAMERA_ANIME_Delete(work->cameraAnimeHandle);
        return EVENT_APPEAR_FINISHED;
    }
    return EVENT_APPEAR_CONTINUE;
}

/*
 * Descending spin: the player starts high above the ground, the screen fades
 * in and a spin task and a draw offset task bring the player down. It is the
 * mirror of the rising spin of event_disappear.c.
 */
int EVENT_APPEAR_RunDescendingSpin(struct GameEvent *event, int *seq, void *workPtr)
{
    EventAppearWork *work = workPtr;
    FieldMap *fieldMap;
    struct FieldCamera *camera;
    Mmdl *player;
    FieldTask *spinTask;
    FieldTask *offsetTask;
    FieldTaskManager *taskManager;

    fieldMap = work->fieldMap;
    camera = FIELDMAP_GetCamera(fieldMap);
    switch (*seq) {
    case EVENT_APPEAR_DESCENT_START:
        work->savedCameraMode = FIELD_CAMERA_GetMode(camera);
        FIELD_CAMERA_SetMode(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
        player = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
        {
            VecFx32 startOffset;
            startOffset.y = 0xA000;
            startOffset.x = 0;
            startOffset.z = 0;
            FLDMMDL_SetDrawOffset(player, (struct VecFx32 *)(&startOffset));
        }
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(work->gameSystem, fieldMap, 0, 1, 1, 0, 0));
        {
            VecFx32 riseOffset;
            riseOffset.y = 0x96000;
            riseOffset.x = 0;
            riseOffset.z = 0;
            spinTask = FIELD_TASK_CreatePlayerSpinLinear(fieldMap, 0x18, 3);
            offsetTask = FIELD_TASK_CreatePlayerDrawOffsetTween(fieldMap, -0x18, &riseOffset);
        }
        taskManager = FIELDMAP_GetTaskManager(fieldMap);
        FIELD_TASK_MANAGER_AddTask(taskManager, spinTask, 0);
        FIELD_TASK_MANAGER_AddTask(taskManager, offsetTask, 0);
        (*seq)++;
        break;
    case EVENT_APPEAR_DESCENT_WAIT:
        if (FIELD_TASK_MANAGER_IsEmpty(FIELDMAP_GetTaskManager(fieldMap)) != 0)
            (*seq)++;
        break;
    case EVENT_APPEAR_DESCENT_SMOKE:
        player = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
        FLDEFF_KEMURI_Start(player, (struct FieldEffectSys *)FIELDMAP_GetEffect(work->fieldMap));
        GFL_USE_PlaySeDefaultVolume(EVENT_APPEAR_SE_DESCENT_END);
        (*seq)++;
        break;
    case EVENT_APPEAR_DESCENT_RESTORE:
        FIELD_CAMERA_SetMode(camera, work->savedCameraMode);
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
int EVENT_APPEAR_RunMoveAnime(struct GameEvent *event, int *seq, void *workPtr)
{
    EventAppearWork *work = workPtr;
    struct FieldCamera *camera = FIELDMAP_GetCamera(work->fieldMap);
    Mmdl *player;

    player = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(work->fieldMap));
    switch (*seq) {
    case EVENT_APPEAR_ACMD_START:
        work->savedCameraMode = FIELD_CAMERA_GetMode(camera);
        FIELD_CAMERA_SetMode(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
        FLDMMDL_SetAcmd(player, EVENT_APPEAR_ACMD_APPEAR);
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(work->gameSystem, work->fieldMap, 0, 1, 1, 0, 0));
        (*seq)++;
        break;
    case EVENT_APPEAR_ACMD_WAIT:
        if (FLDMMDL_CheckEndAcmd(player) == 1) {
            FLDMMDL_EndAcmd(player);
            (*seq)++;
        }
        break;
    case EVENT_APPEAR_ACMD_RESTORE:
        FIELD_CAMERA_SetMode(camera, work->savedCameraMode);
        (*seq)++;
        break;
    case EVENT_APPEAR_ACMD_END:
        return EVENT_APPEAR_FINISHED;
    }
    return EVENT_APPEAR_CONTINUE;
}
