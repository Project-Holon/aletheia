/*
 * file:     unit_021C06CC.c
 * unit:     yes
 * function: func_021C06CC, func_021C06E0, func_021C0780, func_021C0808, func_021C080C, func_021C0810, func_021C0820, func_021C0844, func_021C0904, func_021C0988, func_021C09A8, func_021C09B0, func_021C0A10, func_021C0A48, func_021C0A70, func_021C0AA0, func_021C0AC0, func_021C0B3C, func_021C0BD8, func_021C0BE8, func_021C0C48, func_021C0C80, func_021C0C94
 * address:  0x021C06CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_player_grid_event.c at 0x021C06CC (lane CL118, no __FILE__ anchor, original unknown: a sub-proc event (06CC..0810, called by field_event_check.c and ov018 intrude_subdisp.c) and the Pokemon Center recovery ball events (0820..0C94, called by scrcmd_screeneffects.c); possibly two originals, cut at 021C0820).
 *
 * symbols:
 *   func_02012374  0x02012374  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_0218C584  0x0218C584  thumb  ov021
 *   func_0218C724  0x0218C724  thumb  ov021
 *   func_0218C88C  0x0218C88C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0218C8FC  0x0218C8FC  thumb  ov021
 *   func_0218C860  0x0218C860  thumb  ov021
 *   d_021DA08C  0x021DA08C  data
 *   ov021_id  0x00000015  data
 *   func_0200FB38  0x0200FB38  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_020146F8  0x020146F8  thumb
 *   func_0202647C  0x0202647C  thumb
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_02012124  0x02012124  thumb
 *   func_020121CC  0x020121CC  thumb
 *   func_02026474  0x02026474  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02164FC4  0x02164FC4  thumb  ov010
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02029830  0x02029830  thumb
 *   func_02029620  0x02029620  thumb
 *   func_0218C6D0  0x0218C6D0  thumb  ov021
 *   func_020520FC  0x020520FC  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0218C7F0  0x0218C7F0  thumb  ov021
 *   d_021DA098  0x021DA098  data  ov021  a4
 *   func_0218C69C  0x0218C69C  thumb  ov021
 *   d_021DA0E0     0x021DA0E0  data  a4
 *   func_0218C8D8  0x0218C8D8  thumb  ov021
 *   func_02012934  0x02012934  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 */
#include "fieldmap_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
struct GameComm;
struct GameData;
struct FieldPlayer;
struct FieldG3dMapper;
struct BuildModelMan;
struct BuildModelEntry;
struct BuildModelNode;

/* Values an event function returns to the event runner. */
enum {
    UNIT_021C06CC_CONTINUE,
    UNIT_021C06CC_FINISHED
};

typedef int (*GameEventFunc)(GameEvent *event, int *seq, void *work);

/* The functions of a sub proc (init, main, end), as the proc runner calls them. */
typedef int (*SubProcFunc)(void *proc, int *seq, void *procWork, void *myWork);

typedef struct SubProcData {
    SubProcFunc init;       /* 0x00 */
    SubProcFunc main;       /* 0x04 */
    SubProcFunc end;        /* 0x08 */
} SubProcData;

/* A model placement for the build model manager: position, scale, rotation. */
typedef struct Mtx33 {
    int m[9];
} Mtx33;

typedef struct RecoveryBallPlacement {
    VecFx32 pos;            /* 0x00 */
    VecFx32 scale;          /* 0x0C */
    Mtx33 rotation;         /* 0x18 */
} RecoveryBallPlacement;

/* Search rectangle for build model entries, in 20.12 fixed point. */
typedef struct RecoveryRect {
    int zMin;
    int zMax;
    int xMin;
    int xMax;
} RecoveryRect;

/* The most recovery balls an event shows. */
#define RECOVERY_BALL_MAX 6

/* Build model entry kinds the recovery events look for around the player. */
#define RECOVERY_ENTRY_KIND_BALLS 3
#define RECOVERY_ENTRY_KIND_MACHINE 8

/* Half size of the search area around the player (5 tiles, fx32). */
#define RECOVERY_SEARCH_RADIUS 0x50000

/* The model of one recovery ball and its sound effects. */
#define RECOVERY_BALL_MODEL_TABLE_ID 0x62
#define RECOVERY_SE_BALL_PLACED 0x568
#define RECOVERY_BGM_JINGLE 0x514

/* Frames between two balls, and frames to wait after the last one. */
#define RECOVERY_BALLS_SPAWN_INTERVAL 15
#define RECOVERY_PARTY_SPAWN_INTERVAL 20
#define RECOVERY_END_DELAY 10

/* Entry animation slot and the node modes the events set. */
#define RECOVERY_ANIME_SLOT 0
#define RECOVERY_MODE_START 0
#define RECOVERY_MODE_ACTIVE 2
#define RECOVERY_MODE_FINISH 3

/* Work of the recovery balls event (0x38 bytes). */
typedef struct RecoveryBallsWork {
    u16 heapId;                             /* 0x00 */
    u8 padding02[2];
    FieldMap *fieldMap;                     /* 0x04 */
    VecFx32 machinePos;                     /* 0x08: world position of the machine entry */
    u8 ballCount;                           /* 0x14: balls to show, at most RECOVERY_BALL_MAX */
    u8 ballsPlaced;                         /* 0x15 */
    u16 frame;                              /* 0x16: frames in the current step */
    struct BuildModelMan *buildModelMan;    /* 0x18 */
    struct BuildModelNode *balls[RECOVERY_BALL_MAX]; /* 0x1C */
    struct BuildModelEntry *machineEntry;   /* 0x34 */
} RecoveryBallsWork;

/* Work of the party recovery event (0x3C bytes). */
typedef struct PartyRecoveryWork {
    u16 heapId;                             /* 0x00 */
    u8 padding02[2];
    FieldMap *fieldMap;                     /* 0x04 */
    VecFx32 machinePos;                     /* 0x08 */
    u8 ballCount;                           /* 0x14: one ball per party member that is not an egg */
    u8 ballsPlaced;                         /* 0x15 */
    u16 frame;                              /* 0x16 */
    struct BuildModelMan *buildModelMan;    /* 0x18 */
    struct BuildModelNode *balls[RECOVERY_BALL_MAX]; /* 0x1C */
    struct BuildModelEntry *machineEntry;   /* 0x34 */
    struct BuildModelNode *machineNode;     /* 0x38: node made from the machine entry */
} PartyRecoveryWork;

/* Steps of the comm error event. */
enum {
    COMM_ERROR_STEP_START,
    COMM_ERROR_STEP_WAIT
};

/* Steps of the comm shutdown event. */
enum {
    COMM_EXIT_STEP_EXIT,
    COMM_EXIT_STEP_WAIT_SESSION_END,
    COMM_EXIT_STEP_AUTO_COMM,
    COMM_EXIT_STEP_SET_SEARCH_DELAY
};

/* Steps of the recovery balls event. */
enum {
    RECOVERY_BALLS_STEP_PLACE,
    RECOVERY_BALLS_STEP_START_ANIME,
    RECOVERY_BALLS_STEP_WAIT_ANIME,
    RECOVERY_BALLS_STEP_POP_SOUND,
    RECOVERY_BALLS_STEP_END
};

/* Steps of the party recovery event. */
enum {
    PARTY_RECOVERY_STEP_PLACE,
    PARTY_RECOVERY_STEP_START_ANIME,
    PARTY_RECOVERY_STEP_WAIT_ANIME,
    PARTY_RECOVERY_STEP_END
};

extern GameEvent *func_020122C0(GameSystem *gameSystem, GameEvent *parent, GameEventFunc handler, u32 workSize);
extern void *func_020124E8(GameEvent *event);
extern GameSystem *func_020124E4(GameEvent *event);
extern FieldMap *func_0201210C(GameSystem *gameSystem);
extern struct GameComm *func_02012138(GameSystem *gameSystem);
extern struct GameData *func_020120F4(GameSystem *gameSystem);
extern void func_02012124(GameSystem *gameSystem, u32 state);
extern u32 func_020121CC(GameSystem *gameSystem);
extern void func_02012374(GameEvent *parent, GameEvent *child);
extern int func_02012B70(struct GameData *gameData);
extern void *func_02012934(struct GameData *gameData);
extern u32 func_0201AA1C(void *party);
extern u32 func_0202647C(struct GameComm *gameComm);
extern void *func_02026474(struct GameComm *gameComm);
extern u32 func_02026454(struct GameComm *gameComm);
extern int func_0203CD98(void);
extern int func_0203CEAC(int a0);
extern int func_0203CDBC(void);
extern void func_0200FB38(void);
extern void func_0200FBA0(void);
extern GameEvent *func_020146F8(GameSystem *gameSystem, FieldMap *fieldMap, u8 *overlayId, const SubProcData *procData, GameSystem *procWork);
extern void func_02164FC4(void *searchWork);
extern struct MmdlSys *func_02188C7C(FieldMap *fieldMap);
extern int func_02188BE8(FieldMap *fieldMap);
extern void func_0216D9A0(struct MmdlSys *mmdlSys);
extern u32 *func_0216D9E4(struct MmdlSys *mmdlSys);
extern u16 func_02188C84(FieldMap *fieldMap);
extern struct FieldG3dMapper *func_02188C98(FieldMap *fieldMap);
extern struct FieldPlayer *func_02188CB4(FieldMap *fieldMap);
extern GameSystem *func_02188C80(FieldMap *fieldMap);
extern void func_021A3038(struct FieldPlayer *player, VecFx32 *out);
extern struct BuildModelMan *func_0218DC6C(struct FieldG3dMapper *mapper);
extern struct BuildModelEntry **func_0218C584(struct BuildModelMan *man, RecoveryRect *rect, int kind, int *count);
extern void func_0218C6D0(struct BuildModelEntry *entry, VecFx32 *out);
extern struct BuildModelNode *func_0218C724(struct BuildModelMan *man, struct BuildModelEntry *entry);
extern struct BuildModelNode *func_0218C7F0(struct BuildModelMan *man, u32 tableId, RecoveryBallPlacement *placement);
extern void func_0218C69C(struct BuildModelMan *man, struct BuildModelEntry *entry, int slot, int mode);
extern void func_0218C860(struct BuildModelNode *node);
extern void func_0218C88C(struct BuildModelNode *node, int slot, int mode);
extern int func_0218C8D8(struct BuildModelNode *node);
extern int func_0218C8FC(struct BuildModelNode *node, int slot);
extern GameEvent *func_02029830(GameSystem *gameSystem, u32 bgmId);
extern GameEvent *func_02029620(GameSystem *gameSystem, u32 a, u32 fadeFrames);
extern void func_020061E4(u32 seId);
extern u32 func_020307B0(void *block);
extern void func_020520FC(int angleX, int angleY, int angleZ, Mtx33 *out);
extern void func_0207C9D0(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);

extern u8 ov021_id[];
extern const SubProcData d_021DA08C;
extern const VecFx32 d_021DA098[RECOVERY_BALL_MAX];
extern const VecFx32 d_021DA0E0[RECOVERY_BALL_MAX];

GameEvent *func_021C06CC(GameSystem *gameSystem, FieldMap *fieldMap);
int func_021C06E0(GameEvent *event, int *seq, void *work);
int func_021C0780(GameEvent *event, int *seq, void *work);
int func_021C0808(void *proc, int *seq, void *procWork, void *myWork);
int func_021C080C(void *proc, int *seq, void *procWork, void *myWork);
int func_021C0810(void *proc, int *seq, void *procWork, void *myWork);
GameEvent *func_021C0820(GameSystem *gameSystem, GameEvent *parent, u32 count);
int func_021C0844(GameEvent *event, int *seq, void *eventWork);
void func_021C0904(RecoveryBallsWork *work, GameSystem *gameSystem, u32 count);
void func_021C0988(RecoveryBallsWork *work);
void func_021C09A8(RecoveryBallsWork *work, int *seq, int nextStep);
void func_021C09B0(RecoveryBallsWork *work);
void func_021C0A10(RecoveryBallsWork *work);
void func_021C0A48(RecoveryBallsWork *work);
int func_021C0A70(RecoveryBallsWork *work);
GameEvent *func_021C0AA0(GameSystem *gameSystem, GameEvent *parent);
int func_021C0AC0(GameEvent *event, int *seq, void *eventWork);
void func_021C0B3C(PartyRecoveryWork *work, GameSystem *gameSystem);
void func_021C0BD8(PartyRecoveryWork *work);
void func_021C0BE8(PartyRecoveryWork *work);
void func_021C0C48(PartyRecoveryWork *work);
int func_021C0C80(PartyRecoveryWork *work);
u32 func_021C0C94(GameSystem *gameSystem);

/*
 * Starts the comm error event.
 */
GameEvent *func_021C06CC(GameSystem *gameSystem, FieldMap *fieldMap)
{
    return func_020122C0(gameSystem, 0, func_021C06E0, 0);
}

/*
 * Comm error event: pauses the move models, shows the error through the
 * sub proc (or shuts the comm down when the comm is not in the intrude
 * state), and resumes the move models when the field map is ready again.
 */
int func_021C06E0(GameEvent *event, int *seq, void *work)
{
    GameSystem *gameSystem = func_020124E4(event);
    FieldMap *fieldMap = func_0201210C(gameSystem);
    GameEvent *child;

    switch (*seq) {
    case COMM_ERROR_STEP_START:
        func_0216D9A0(func_02188C7C(fieldMap));
        if (func_0202647C(func_02012138(gameSystem)) == 2) {
            if (func_02012B70(func_020120F4(gameSystem)) == 1) {
                func_0200FB38();
                child = func_020146F8(gameSystem, fieldMap, ov021_id, &d_021DA08C, gameSystem);
            } else {
                child = func_020122C0(gameSystem, 0, func_021C0780, 0);
            }
        } else {
            func_0200FB38();
            child = func_020146F8(gameSystem, fieldMap, ov021_id, &d_021DA08C, gameSystem);
        }
        func_02012374(event, child);
        (*seq)++;
        break;
    case COMM_ERROR_STEP_WAIT:
        if (fieldMap != 0 && func_02188BE8(fieldMap) == 1) {
            func_0216D9E4(func_02188C7C(fieldMap));
            return UNIT_021C06CC_FINISHED;
        }
        break;
    }
    return UNIT_021C06CC_CONTINUE;
}

/*
 * Comm shutdown event: leaves the comm session, resets the field map state,
 * restarts the automatic comm and sets the beacon search delay.
 */
int func_021C0780(GameEvent *event, int *seq, void *work)
{
    GameSystem *gameSystem;
    struct GameComm *gameComm;
    void *searchWork;

    gameSystem = func_020124E4(event);
    gameComm = func_02012138(gameSystem);
    switch (*seq) {
    case COMM_EXIT_STEP_EXIT:
        if (func_0203CD98()) {
            func_0203CEAC(0);
        }
        *seq = *seq + 1;
        break;
    case COMM_EXIT_STEP_WAIT_SESSION_END:
        if (func_0203CDBC() == 1) {
            func_0200FBA0();
            func_02012124(gameSystem, 0);
            *seq = *seq + 1;
        }
        break;
    case COMM_EXIT_STEP_AUTO_COMM:
        if (func_020121CC(gameSystem) == 1) {
            *seq = *seq + 1;
            break;
        }
        return UNIT_021C06CC_FINISHED;
    case COMM_EXIT_STEP_SET_SEARCH_DELAY:
        searchWork = func_02026474(gameComm);
        if (searchWork && func_02026454(gameComm)) {
            func_02164FC4(searchWork);
            return UNIT_021C06CC_FINISHED;
        }
        break;
    }
    return UNIT_021C06CC_CONTINUE;
}

/*
 * Init function of the comm error sub proc: nothing to set up.
 */
int func_021C0808(void *proc, int *seq, void *procWork, void *myWork)
{
    return 1;
}

/*
 * Main function of the comm error sub proc: ends at once.
 */
int func_021C080C(void *proc, int *seq, void *procWork, void *myWork)
{
    return 1;
}

/*
 * End function of the comm error sub proc: resets the field map state of the
 * game system it was started with.
 */
int func_021C0810(void *proc, int *seq, void *procWork, void *myWork)
{
    func_02012124(procWork, 0);
    return 1;
}

/*
 * Creates the recovery balls event (count balls, at most RECOVERY_BALL_MAX).
 */
GameEvent *func_021C0820(GameSystem *gameSystem, GameEvent *parent, u32 count)
{
    GameEvent *event = func_020122C0(gameSystem, parent, func_021C0844, sizeof(RecoveryBallsWork));
    RecoveryBallsWork *work = func_020124E8(event);

    func_021C0904(work, gameSystem, count);
    return event;
}

/*
 * Recovery balls event: places a ball every RECOVERY_BALLS_SPAWN_INTERVAL
 * frames, starts the machine animation and the jingle, waits until every ball
 * is idle, then plays the balls out and the sound task that ends the jingle.
 */
int func_021C0844(GameEvent *event, int *seq, void *eventWork)
{
    RecoveryBallsWork *work = eventWork;

    switch (*seq) {
    case RECOVERY_BALLS_STEP_PLACE:
        if ((int)work->frame % RECOVERY_BALLS_SPAWN_INTERVAL == 0) {
            func_021C09B0(work);
            if (work->ballCount <= work->ballsPlaced) {
                func_021C09A8(work, seq, RECOVERY_BALLS_STEP_START_ANIME);
            }
        }
        break;
    case RECOVERY_BALLS_STEP_START_ANIME:
        if (work->frame > RECOVERY_END_DELAY) {
            func_021C0A10(work);
            func_02012374(event, func_02029830(func_02188C80(work->fieldMap), RECOVERY_BGM_JINGLE));
            func_021C09A8(work, seq, RECOVERY_BALLS_STEP_WAIT_ANIME);
        }
        break;
    case RECOVERY_BALLS_STEP_WAIT_ANIME:
        if (func_021C0A70(work) != 0) {
            func_021C0A48(work);
            func_021C09A8(work, seq, RECOVERY_BALLS_STEP_POP_SOUND);
        }
        break;
    case RECOVERY_BALLS_STEP_POP_SOUND:
        func_02012374(event, func_02029620(func_02188C80(work->fieldMap), 0, 6));
        func_021C09A8(work, seq, RECOVERY_BALLS_STEP_END);
        break;
    case RECOVERY_BALLS_STEP_END:
        func_021C0988(work);
        return UNIT_021C06CC_FINISHED;
    }
    work->frame = work->frame + 1;
    return UNIT_021C06CC_CONTINUE;
}

/*
 * Fills the recovery balls work: finds the machine entry around the player.
 */
void func_021C0904(RecoveryBallsWork *work, GameSystem *gameSystem, u32 count)
{
    FieldMap *fieldMap;
    u32 heapId;
    struct FieldG3dMapper *mapper;
    struct BuildModelEntry **entries;
    VecFx32 playerPos;
    RecoveryRect rect;
    int entryCount;

    fieldMap = func_0201210C(gameSystem);
    heapId = func_02188C84(fieldMap);
    mapper = func_02188C98(fieldMap);
    work->heapId = heapId;
    work->ballCount = count;
    work->fieldMap = fieldMap;
    work->ballsPlaced = 0;
    work->buildModelMan = func_0218DC6C(mapper);
    work->machineEntry = 0;
    if (work->ballCount > RECOVERY_BALL_MAX) {
        work->ballCount = RECOVERY_BALL_MAX;
    }
    func_021A3038(func_02188CB4(work->fieldMap), &playerPos);
    rect.zMin = playerPos.z - RECOVERY_SEARCH_RADIUS;
    rect.zMax = playerPos.z + RECOVERY_SEARCH_RADIUS;
    rect.xMin = playerPos.x - RECOVERY_SEARCH_RADIUS;
    rect.xMax = playerPos.x + RECOVERY_SEARCH_RADIUS;
    entries = func_0218C584(work->buildModelMan, &rect, RECOVERY_ENTRY_KIND_BALLS, &entryCount);
    if (entries) {
        work->machineEntry = *entries;
        func_0218C6D0(*entries, &work->machinePos);
    }
    func_020307B0(entries);
}

/*
 * Deletes each of the placed ball nodes.
 */
void func_021C0988(RecoveryBallsWork *work)
{
    int i;

    for (i = 0; i < work->ballCount; i++)
        func_0218C860(work->balls[i]);
}

/*
 * Moves the event to the next step and restarts the frame counter.
 */
void func_021C09A8(RecoveryBallsWork *work, int *seq, int nextStep)
{
    *seq = nextStep;
    work->frame = 0;
}

/*
 * Places the next ball at its offset from the machine and plays the sound.
 */
void func_021C09B0(RecoveryBallsWork *work)
{
    RecoveryBallPlacement placement;
    u32 i;

    i = work->ballsPlaced;
    if (work->ballCount > i) {
        placement.scale.x = 0x1000;
        placement.scale.y = 0x1000;
        placement.scale.z = 0x1000;
        func_020520FC(0, 0, 0, &placement.rotation);
        func_0207C9D0(&work->machinePos, &d_021DA098[i], &placement.pos);
        work->balls[i] = func_0218C7F0(work->buildModelMan, RECOVERY_BALL_MODEL_TABLE_ID, &placement);
        work->ballsPlaced = work->ballsPlaced + 1;
        func_020061E4(RECOVERY_SE_BALL_PLACED);
    }
}

/*
 * Resets the animation of each placed ball, then plays the machine entry
 * animation when there is one.
 */
void func_021C0A10(RecoveryBallsWork *work)
{
    int i;

    for (i = 0; i < work->ballsPlaced; i++)
        func_0218C88C(work->balls[i], RECOVERY_ANIME_SLOT, RECOVERY_MODE_START);
    if (work->machineEntry != 0)
        func_0218C69C(work->buildModelMan, work->machineEntry, RECOVERY_ANIME_SLOT, RECOVERY_MODE_START);
}

/*
 * Sets the finish mode on each placed ball.
 */
void func_021C0A48(RecoveryBallsWork *work)
{
    int i;

    for (i = 0; i < work->ballsPlaced; i++)
        func_0218C88C(work->balls[i], RECOVERY_ANIME_SLOT, RECOVERY_MODE_FINISH);
}

/*
 * Returns 1 when every placed ball has an idle animation slot.
 */
int func_021C0A70(RecoveryBallsWork *work)
{
    int i;

    for (i = 0; i < work->ballsPlaced; i++) {
        if (func_0218C8FC(work->balls[i], RECOVERY_ANIME_SLOT) != 1)
            return 0;
    }
    return 1;
}

/*
 * Creates the party recovery event (one ball per party member).
 */
GameEvent *func_021C0AA0(GameSystem *gameSystem, GameEvent *parent)
{
    GameEvent *event = func_020122C0(gameSystem, parent, func_021C0AC0, sizeof(PartyRecoveryWork));
    PartyRecoveryWork *work = func_020124E8(event);

    func_021C0B3C(work, gameSystem);
    return event;
}

/*
 * Party recovery event: places a ball every RECOVERY_PARTY_SPAWN_INTERVAL
 * frames, then starts the finish mode on the balls and the machine node,
 * waits for the machine animation and ends.
 */
int func_021C0AC0(GameEvent *event, int *seq, void *eventWork)
{
    PartyRecoveryWork *work = eventWork;

    switch (*seq) {
    case PARTY_RECOVERY_STEP_PLACE:
        if ((int)work->frame % RECOVERY_PARTY_SPAWN_INTERVAL == 0) {
            func_021C0BE8(work);
            if (work->ballCount <= work->ballsPlaced) {
                *seq = *seq + 1;
                work->frame = 0;
            }
        }
        break;
    case PARTY_RECOVERY_STEP_START_ANIME:
        if (work->frame > RECOVERY_END_DELAY) {
            func_021C0C48(work);
            *seq = *seq + 1;
            work->frame = 0;
        }
        break;
    case PARTY_RECOVERY_STEP_WAIT_ANIME:
        if (func_021C0C80(work) != 0) {
            *seq = *seq + 1;
        }
        break;
    case PARTY_RECOVERY_STEP_END:
        func_021C0BD8(work);
        return UNIT_021C06CC_FINISHED;
    }
    work->frame = work->frame + 1;
    return UNIT_021C06CC_CONTINUE;
}

/*
 * Fills the party recovery work: finds the machine entry around the player
 * and makes a node from it.
 */
void func_021C0B3C(PartyRecoveryWork *work, GameSystem *gameSystem)
{
    FieldMap *fieldMap;
    struct FieldG3dMapper *mapper;
    struct BuildModelEntry **entries;
    VecFx32 playerPos;
    RecoveryRect rect;
    int entryCount;

    fieldMap = func_0201210C(gameSystem);
    mapper = func_02188C98(fieldMap);
    work->heapId = func_02188C84(fieldMap);
    work->fieldMap = fieldMap;
    work->ballCount = func_021C0C94(gameSystem);
    work->ballsPlaced = 0;
    work->buildModelMan = func_0218DC6C(mapper);
    work->machineEntry = 0;
    if (work->ballCount > RECOVERY_BALL_MAX) {
        work->ballCount = RECOVERY_BALL_MAX;
    }
    func_021A3038(func_02188CB4(work->fieldMap), &playerPos);
    rect.zMin = playerPos.z - RECOVERY_SEARCH_RADIUS;
    rect.zMax = playerPos.z + RECOVERY_SEARCH_RADIUS;
    rect.xMin = playerPos.x - RECOVERY_SEARCH_RADIUS;
    rect.xMax = playerPos.x + RECOVERY_SEARCH_RADIUS;
    entries = func_0218C584(work->buildModelMan, &rect, RECOVERY_ENTRY_KIND_MACHINE, &entryCount);
    if (entries) {
        work->machineEntry = *entries;
        func_0218C6D0(*entries, &work->machinePos);
    }
    func_020307B0(entries);
    if (work->machineEntry != 0) {
        work->machineNode = func_0218C724(work->buildModelMan, work->machineEntry);
    }
}

/*
 * Deletes the machine node when there is one.
 */
void func_021C0BD8(PartyRecoveryWork *work)
{
    if (work->machineEntry != 0)
        func_0218C860(work->machineNode);
}

/*
 * Places the next ball at its offset from the machine and plays the sound.
 */
void func_021C0BE8(PartyRecoveryWork *work)
{
    RecoveryBallPlacement placement;
    u32 i;

    i = work->ballsPlaced;
    if (work->ballCount > i) {
        placement.scale.x = 0x1000;
        placement.scale.y = 0x1000;
        placement.scale.z = 0x1000;
        func_020520FC(0, 0, 0, &placement.rotation);
        func_0207C9D0(&work->machinePos, &d_021DA0E0[i], &placement.pos);
        work->balls[i] = func_0218C7F0(work->buildModelMan, RECOVERY_BALL_MODEL_TABLE_ID, &placement);
        work->ballsPlaced++;
        func_020061E4(RECOVERY_SE_BALL_PLACED);
    }
}

/*
 * Sets the active mode on each placed ball and resets the machine node.
 */
void func_021C0C48(PartyRecoveryWork *work)
{
    int i;

    for (i = 0; i < work->ballsPlaced; i++)
        func_0218C88C(work->balls[i], RECOVERY_ANIME_SLOT, RECOVERY_MODE_ACTIVE);
    if (work->machineEntry != 0)
        func_0218C88C(work->machineNode, RECOVERY_ANIME_SLOT, RECOVERY_MODE_START);
}

/*
 * Returns the state of the machine node animation, or 1 without a machine.
 */
int func_021C0C80(PartyRecoveryWork *work)
{
    if (work->machineEntry != 0) {
        return func_0218C8D8(work->machineNode);
    }
    return 1;
}

/*
 * Number of party members that are not eggs.
 */
u32 func_021C0C94(GameSystem *gameSystem)
{
    return func_0201AA1C(func_02012934(func_020120F4(gameSystem)));
}
