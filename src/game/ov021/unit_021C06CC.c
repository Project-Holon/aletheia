/*
 * file:     unit_021C06CC.c
 * unit:     yes
 * function: EVENT_COMM_ERROR_Create, EVENT_COMM_ERROR_Run, EVENT_COMM_ERROR_RunCommExit, EVENT_COMM_ERROR_SubProcInit, EVENT_COMM_ERROR_SubProcMain, EVENT_COMM_ERROR_SubProcEnd, EVENT_RECOVERY_CreateBallsEvent, EVENT_RECOVERY_RunBalls, EVENT_RECOVERY_InitBalls, EVENT_RECOVERY_DeleteBalls, EVENT_RECOVERY_SetBallsStep, EVENT_RECOVERY_PlaceBall, EVENT_RECOVERY_StartBallsAnime, EVENT_RECOVERY_FinishBalls, EVENT_RECOVERY_AreBallsIdle, EVENT_RECOVERY_CreatePartyEvent, EVENT_RECOVERY_RunParty, EVENT_RECOVERY_InitParty, EVENT_RECOVERY_DeleteMachineNode, EVENT_RECOVERY_PlacePartyBall, EVENT_RECOVERY_ActivateParty, EVENT_RECOVERY_IsMachineAnimeDone, EVENT_RECOVERY_GetPartyBallCount
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
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_GetBuildModel  0x0218DC6C  thumb  ov021
 *   FIELD_BUILDMODEL_CollectEntriesInRect  0x0218C584  thumb  ov021
 *   FIELD_BUILDMODEL_CreateNodeFromEntry  0x0218C724  thumb  ov021
 *   FIELD_BUILDMODEL_PlayNodeSlot  0x0218C88C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_BUILDMODEL_IsNodeSlotIdle  0x0218C8FC  thumb  ov021
 *   FIELD_BUILDMODEL_DeleteNode  0x0218C860  thumb  ov021
 *   sCommErrorSubProcData  0x021DA08C  data
 *   ov021_id  0x00000015  data
 *   GFL_NET_ERR_RequestScreen  0x0200FB38  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   func_020124E4  0x020124E4  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   FIELD_STATUS_CreateSubProcEvent  0x020146F8  thumb
 *   func_0202647C  0x0202647C  thumb
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   FIELDMAP_IsReady  0x02188BE8  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   GAMESYSTEM_SetFieldMapState  0x02012124  thumb
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   func_02026474  0x02026474  thumb
 *   func_02026454  0x02026454  thumb
 *   GAME_BEACON_SEARCH_SetStartDelay  0x02164FC4  thumb  ov010
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELD_SOUND_SYSTEM_StartPushAndPlayTask  0x02029830  thumb
 *   FIELD_SOUND_SYSTEM_StartPopAndWaitTask  0x02029620  thumb
 *   FIELD_BUILDMODEL_GetEntryWorldPos  0x0218C6D0  thumb  ov021
 *   BUTTON_MAN_MakeRotMtxXYZ  0x020520FC  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   FIELD_BUILDMODEL_CreateNodeFromBlock  0x0218C7F0  thumb  ov021
 *   sRecoveryBallOffsets  0x021DA098  data  ov021  a4
 *   FIELD_BUILDMODEL_PlayEntryAnim  0x0218C69C  thumb  ov021
 *   sPartyRecoveryBallOffsets     0x021DA0E0  data  a4
 *   FIELD_BUILDMODEL_TryOpenNodeCurrentSlot  0x0218C8D8  thumb  ov021
 *   GAME_DATA_GetMyParty  0x02012934  thumb
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
extern FieldMap *GAMESYSTEM_GetFieldMap(GameSystem *gameSystem);
extern struct GameComm *GAMESYSTEM_GetGameComm(GameSystem *gameSystem);
extern struct GameData *GAMESYSTEM_GetGameData(GameSystem *gameSystem);
extern void GAMESYSTEM_SetFieldMapState(GameSystem *gameSystem, u32 state);
extern u32 GAMESYSTEM_TryStartAutoComm(GameSystem *gameSystem);
extern void GAME_EVENT_CallEvent(GameEvent *parent, GameEvent *child);
extern int GAME_DATA_GetIntrudeCount(struct GameData *gameData);
extern void *GAME_DATA_GetMyParty(struct GameData *gameData);
extern u32 func_0201AA1C(void *party);
extern u32 func_0202647C(struct GameComm *gameComm);
extern void *func_02026474(struct GameComm *gameComm);
extern u32 func_02026454(struct GameComm *gameComm);
extern int GFL_NET_GetRunState(void);
extern int GFL_NET_Exit(int a0);
extern int GFL_NET_IsSessionNull(void);
extern void GFL_NET_ERR_RequestScreen(void);
extern void func_0200FBA0(void);
extern GameEvent *FIELD_STATUS_CreateSubProcEvent(GameSystem *gameSystem, FieldMap *fieldMap, u8 *overlayId, const SubProcData *procData, GameSystem *procWork);
extern void GAME_BEACON_SEARCH_SetStartDelay(void *searchWork);
extern struct MmdlSys *FIELDMAP_GetMmdlSys(FieldMap *fieldMap);
extern int FIELDMAP_IsReady(FieldMap *fieldMap);
extern void FLDMMDL_SysPauseMove(struct MmdlSys *mmdlSys);
extern u32 *FLDMMDL_SysResumeMove(struct MmdlSys *mmdlSys);
extern u16 FIELDMAP_GetHeapId(FieldMap *fieldMap);
extern struct FieldG3dMapper *FIELDMAP_GetG3dMapper(FieldMap *fieldMap);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(FieldMap *fieldMap);
extern GameSystem *FIELDMAP_GetGameSystem(FieldMap *fieldMap);
extern void FIELD_PLAYER_GetPos(struct FieldPlayer *player, VecFx32 *out);
extern struct BuildModelMan *FIELD_G3D_MAPPER_GetBuildModel(struct FieldG3dMapper *mapper);
extern struct BuildModelEntry **FIELD_BUILDMODEL_CollectEntriesInRect(struct BuildModelMan *man, RecoveryRect *rect, int kind, int *count);
extern void FIELD_BUILDMODEL_GetEntryWorldPos(struct BuildModelEntry *entry, VecFx32 *out);
extern struct BuildModelNode *FIELD_BUILDMODEL_CreateNodeFromEntry(struct BuildModelMan *man, struct BuildModelEntry *entry);
extern struct BuildModelNode *FIELD_BUILDMODEL_CreateNodeFromBlock(struct BuildModelMan *man, u32 tableId, RecoveryBallPlacement *placement);
extern void FIELD_BUILDMODEL_PlayEntryAnim(struct BuildModelMan *man, struct BuildModelEntry *entry, int slot, int mode);
extern void FIELD_BUILDMODEL_DeleteNode(struct BuildModelNode *node);
extern void FIELD_BUILDMODEL_PlayNodeSlot(struct BuildModelNode *node, int slot, int mode);
extern int FIELD_BUILDMODEL_TryOpenNodeCurrentSlot(struct BuildModelNode *node);
extern int FIELD_BUILDMODEL_IsNodeSlotIdle(struct BuildModelNode *node, int slot);
extern GameEvent *FIELD_SOUND_SYSTEM_StartPushAndPlayTask(GameSystem *gameSystem, u32 bgmId);
extern GameEvent *FIELD_SOUND_SYSTEM_StartPopAndWaitTask(GameSystem *gameSystem, u32 a, u32 fadeFrames);
extern void func_020061E4(u32 seId);
extern u32 func_020307B0(void *block);
extern void BUTTON_MAN_MakeRotMtxXYZ(int angleX, int angleY, int angleZ, Mtx33 *out);
extern void func_0207C9D0(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);

extern u8 ov021_id[];
extern const SubProcData sCommErrorSubProcData;
extern const VecFx32 sRecoveryBallOffsets[RECOVERY_BALL_MAX];
extern const VecFx32 sPartyRecoveryBallOffsets[RECOVERY_BALL_MAX];

GameEvent *EVENT_COMM_ERROR_Create(GameSystem *gameSystem, FieldMap *fieldMap);
int EVENT_COMM_ERROR_Run(GameEvent *event, int *seq, void *work);
int EVENT_COMM_ERROR_RunCommExit(GameEvent *event, int *seq, void *work);
int EVENT_COMM_ERROR_SubProcInit(void *proc, int *seq, void *procWork, void *myWork);
int EVENT_COMM_ERROR_SubProcMain(void *proc, int *seq, void *procWork, void *myWork);
int EVENT_COMM_ERROR_SubProcEnd(void *proc, int *seq, void *procWork, void *myWork);
GameEvent *EVENT_RECOVERY_CreateBallsEvent(GameSystem *gameSystem, GameEvent *parent, u32 count);
int EVENT_RECOVERY_RunBalls(GameEvent *event, int *seq, void *eventWork);
void EVENT_RECOVERY_InitBalls(RecoveryBallsWork *work, GameSystem *gameSystem, u32 count);
void EVENT_RECOVERY_DeleteBalls(RecoveryBallsWork *work);
void EVENT_RECOVERY_SetBallsStep(RecoveryBallsWork *work, int *seq, int nextStep);
void EVENT_RECOVERY_PlaceBall(RecoveryBallsWork *work);
void EVENT_RECOVERY_StartBallsAnime(RecoveryBallsWork *work);
void EVENT_RECOVERY_FinishBalls(RecoveryBallsWork *work);
int EVENT_RECOVERY_AreBallsIdle(RecoveryBallsWork *work);
GameEvent *EVENT_RECOVERY_CreatePartyEvent(GameSystem *gameSystem, GameEvent *parent);
int EVENT_RECOVERY_RunParty(GameEvent *event, int *seq, void *eventWork);
void EVENT_RECOVERY_InitParty(PartyRecoveryWork *work, GameSystem *gameSystem);
void EVENT_RECOVERY_DeleteMachineNode(PartyRecoveryWork *work);
void EVENT_RECOVERY_PlacePartyBall(PartyRecoveryWork *work);
void EVENT_RECOVERY_ActivateParty(PartyRecoveryWork *work);
int EVENT_RECOVERY_IsMachineAnimeDone(PartyRecoveryWork *work);
u32 EVENT_RECOVERY_GetPartyBallCount(GameSystem *gameSystem);

/*
 * Starts the comm error event.
 */
GameEvent *EVENT_COMM_ERROR_Create(GameSystem *gameSystem, FieldMap *fieldMap)
{
    return func_020122C0(gameSystem, 0, EVENT_COMM_ERROR_Run, 0);
}

/*
 * Comm error event: pauses the move models, shows the error through the
 * sub proc (or shuts the comm down when the comm is not in the intrude
 * state), and resumes the move models when the field map is ready again.
 */
int EVENT_COMM_ERROR_Run(GameEvent *event, int *seq, void *work)
{
    GameSystem *gameSystem = func_020124E4(event);
    FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    GameEvent *child;

    switch (*seq) {
    case COMM_ERROR_STEP_START:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(fieldMap));
        if (func_0202647C(GAMESYSTEM_GetGameComm(gameSystem)) == 2) {
            if (GAME_DATA_GetIntrudeCount(GAMESYSTEM_GetGameData(gameSystem)) == 1) {
                GFL_NET_ERR_RequestScreen();
                child = FIELD_STATUS_CreateSubProcEvent(gameSystem, fieldMap, ov021_id, &sCommErrorSubProcData, gameSystem);
            } else {
                child = func_020122C0(gameSystem, 0, EVENT_COMM_ERROR_RunCommExit, 0);
            }
        } else {
            GFL_NET_ERR_RequestScreen();
            child = FIELD_STATUS_CreateSubProcEvent(gameSystem, fieldMap, ov021_id, &sCommErrorSubProcData, gameSystem);
        }
        GAME_EVENT_CallEvent(event, child);
        (*seq)++;
        break;
    case COMM_ERROR_STEP_WAIT:
        if (fieldMap != 0 && FIELDMAP_IsReady(fieldMap) == 1) {
            FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(fieldMap));
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
int EVENT_COMM_ERROR_RunCommExit(GameEvent *event, int *seq, void *work)
{
    GameSystem *gameSystem;
    struct GameComm *gameComm;
    void *searchWork;

    gameSystem = func_020124E4(event);
    gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    switch (*seq) {
    case COMM_EXIT_STEP_EXIT:
        if (GFL_NET_GetRunState()) {
            GFL_NET_Exit(0);
        }
        *seq = *seq + 1;
        break;
    case COMM_EXIT_STEP_WAIT_SESSION_END:
        if (GFL_NET_IsSessionNull() == 1) {
            func_0200FBA0();
            GAMESYSTEM_SetFieldMapState(gameSystem, 0);
            *seq = *seq + 1;
        }
        break;
    case COMM_EXIT_STEP_AUTO_COMM:
        if (GAMESYSTEM_TryStartAutoComm(gameSystem) == 1) {
            *seq = *seq + 1;
            break;
        }
        return UNIT_021C06CC_FINISHED;
    case COMM_EXIT_STEP_SET_SEARCH_DELAY:
        searchWork = func_02026474(gameComm);
        if (searchWork && func_02026454(gameComm)) {
            GAME_BEACON_SEARCH_SetStartDelay(searchWork);
            return UNIT_021C06CC_FINISHED;
        }
        break;
    }
    return UNIT_021C06CC_CONTINUE;
}

/*
 * Init function of the comm error sub proc: nothing to set up.
 */
int EVENT_COMM_ERROR_SubProcInit(void *proc, int *seq, void *procWork, void *myWork)
{
    return 1;
}

/*
 * Main function of the comm error sub proc: ends at once.
 */
int EVENT_COMM_ERROR_SubProcMain(void *proc, int *seq, void *procWork, void *myWork)
{
    return 1;
}

/*
 * End function of the comm error sub proc: resets the field map state of the
 * game system it was started with.
 */
int EVENT_COMM_ERROR_SubProcEnd(void *proc, int *seq, void *procWork, void *myWork)
{
    GAMESYSTEM_SetFieldMapState(procWork, 0);
    return 1;
}

/*
 * Creates the recovery balls event (count balls, at most RECOVERY_BALL_MAX).
 */
GameEvent *EVENT_RECOVERY_CreateBallsEvent(GameSystem *gameSystem, GameEvent *parent, u32 count)
{
    GameEvent *event = func_020122C0(gameSystem, parent, EVENT_RECOVERY_RunBalls, sizeof(RecoveryBallsWork));
    RecoveryBallsWork *work = func_020124E8(event);

    EVENT_RECOVERY_InitBalls(work, gameSystem, count);
    return event;
}

/*
 * Recovery balls event: places a ball every RECOVERY_BALLS_SPAWN_INTERVAL
 * frames, starts the machine animation and the jingle, waits until every ball
 * is idle, then plays the balls out and the sound task that ends the jingle.
 */
int EVENT_RECOVERY_RunBalls(GameEvent *event, int *seq, void *eventWork)
{
    RecoveryBallsWork *work = eventWork;

    switch (*seq) {
    case RECOVERY_BALLS_STEP_PLACE:
        if ((int)work->frame % RECOVERY_BALLS_SPAWN_INTERVAL == 0) {
            EVENT_RECOVERY_PlaceBall(work);
            if (work->ballCount <= work->ballsPlaced) {
                EVENT_RECOVERY_SetBallsStep(work, seq, RECOVERY_BALLS_STEP_START_ANIME);
            }
        }
        break;
    case RECOVERY_BALLS_STEP_START_ANIME:
        if (work->frame > RECOVERY_END_DELAY) {
            EVENT_RECOVERY_StartBallsAnime(work);
            GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPushAndPlayTask(FIELDMAP_GetGameSystem(work->fieldMap), RECOVERY_BGM_JINGLE));
            EVENT_RECOVERY_SetBallsStep(work, seq, RECOVERY_BALLS_STEP_WAIT_ANIME);
        }
        break;
    case RECOVERY_BALLS_STEP_WAIT_ANIME:
        if (EVENT_RECOVERY_AreBallsIdle(work) != 0) {
            EVENT_RECOVERY_FinishBalls(work);
            EVENT_RECOVERY_SetBallsStep(work, seq, RECOVERY_BALLS_STEP_POP_SOUND);
        }
        break;
    case RECOVERY_BALLS_STEP_POP_SOUND:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPopAndWaitTask(FIELDMAP_GetGameSystem(work->fieldMap), 0, 6));
        EVENT_RECOVERY_SetBallsStep(work, seq, RECOVERY_BALLS_STEP_END);
        break;
    case RECOVERY_BALLS_STEP_END:
        EVENT_RECOVERY_DeleteBalls(work);
        return UNIT_021C06CC_FINISHED;
    }
    work->frame = work->frame + 1;
    return UNIT_021C06CC_CONTINUE;
}

/*
 * Fills the recovery balls work: finds the machine entry around the player.
 */
void EVENT_RECOVERY_InitBalls(RecoveryBallsWork *work, GameSystem *gameSystem, u32 count)
{
    FieldMap *fieldMap;
    u32 heapId;
    struct FieldG3dMapper *mapper;
    struct BuildModelEntry **entries;
    VecFx32 playerPos;
    RecoveryRect rect;
    int entryCount;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    heapId = FIELDMAP_GetHeapId(fieldMap);
    mapper = FIELDMAP_GetG3dMapper(fieldMap);
    work->heapId = heapId;
    work->ballCount = count;
    work->fieldMap = fieldMap;
    work->ballsPlaced = 0;
    work->buildModelMan = FIELD_G3D_MAPPER_GetBuildModel(mapper);
    work->machineEntry = 0;
    if (work->ballCount > RECOVERY_BALL_MAX) {
        work->ballCount = RECOVERY_BALL_MAX;
    }
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(work->fieldMap), &playerPos);
    rect.zMin = playerPos.z - RECOVERY_SEARCH_RADIUS;
    rect.zMax = playerPos.z + RECOVERY_SEARCH_RADIUS;
    rect.xMin = playerPos.x - RECOVERY_SEARCH_RADIUS;
    rect.xMax = playerPos.x + RECOVERY_SEARCH_RADIUS;
    entries = FIELD_BUILDMODEL_CollectEntriesInRect(work->buildModelMan, &rect, RECOVERY_ENTRY_KIND_BALLS, &entryCount);
    if (entries) {
        work->machineEntry = *entries;
        FIELD_BUILDMODEL_GetEntryWorldPos(*entries, &work->machinePos);
    }
    func_020307B0(entries);
}

/*
 * Deletes each of the placed ball nodes.
 */
void EVENT_RECOVERY_DeleteBalls(RecoveryBallsWork *work)
{
    int i;

    for (i = 0; i < work->ballCount; i++)
        FIELD_BUILDMODEL_DeleteNode(work->balls[i]);
}

/*
 * Moves the event to the next step and restarts the frame counter.
 */
void EVENT_RECOVERY_SetBallsStep(RecoveryBallsWork *work, int *seq, int nextStep)
{
    *seq = nextStep;
    work->frame = 0;
}

/*
 * Places the next ball at its offset from the machine and plays the sound.
 */
void EVENT_RECOVERY_PlaceBall(RecoveryBallsWork *work)
{
    RecoveryBallPlacement placement;
    u32 i;

    i = work->ballsPlaced;
    if (work->ballCount > i) {
        placement.scale.x = 0x1000;
        placement.scale.y = 0x1000;
        placement.scale.z = 0x1000;
        BUTTON_MAN_MakeRotMtxXYZ(0, 0, 0, &placement.rotation);
        func_0207C9D0(&work->machinePos, &sRecoveryBallOffsets[i], &placement.pos);
        work->balls[i] = FIELD_BUILDMODEL_CreateNodeFromBlock(work->buildModelMan, RECOVERY_BALL_MODEL_TABLE_ID, &placement);
        work->ballsPlaced = work->ballsPlaced + 1;
        func_020061E4(RECOVERY_SE_BALL_PLACED);
    }
}

/*
 * Resets the animation of each placed ball, then plays the machine entry
 * animation when there is one.
 */
void EVENT_RECOVERY_StartBallsAnime(RecoveryBallsWork *work)
{
    int i;

    for (i = 0; i < work->ballsPlaced; i++)
        FIELD_BUILDMODEL_PlayNodeSlot(work->balls[i], RECOVERY_ANIME_SLOT, RECOVERY_MODE_START);
    if (work->machineEntry != 0)
        FIELD_BUILDMODEL_PlayEntryAnim(work->buildModelMan, work->machineEntry, RECOVERY_ANIME_SLOT, RECOVERY_MODE_START);
}

/*
 * Sets the finish mode on each placed ball.
 */
void EVENT_RECOVERY_FinishBalls(RecoveryBallsWork *work)
{
    int i;

    for (i = 0; i < work->ballsPlaced; i++)
        FIELD_BUILDMODEL_PlayNodeSlot(work->balls[i], RECOVERY_ANIME_SLOT, RECOVERY_MODE_FINISH);
}

/*
 * Returns 1 when every placed ball has an idle animation slot.
 */
int EVENT_RECOVERY_AreBallsIdle(RecoveryBallsWork *work)
{
    int i;

    for (i = 0; i < work->ballsPlaced; i++) {
        if (FIELD_BUILDMODEL_IsNodeSlotIdle(work->balls[i], RECOVERY_ANIME_SLOT) != 1)
            return 0;
    }
    return 1;
}

/*
 * Creates the party recovery event (one ball per party member).
 */
GameEvent *EVENT_RECOVERY_CreatePartyEvent(GameSystem *gameSystem, GameEvent *parent)
{
    GameEvent *event = func_020122C0(gameSystem, parent, EVENT_RECOVERY_RunParty, sizeof(PartyRecoveryWork));
    PartyRecoveryWork *work = func_020124E8(event);

    EVENT_RECOVERY_InitParty(work, gameSystem);
    return event;
}

/*
 * Party recovery event: places a ball every RECOVERY_PARTY_SPAWN_INTERVAL
 * frames, then starts the finish mode on the balls and the machine node,
 * waits for the machine animation and ends.
 */
int EVENT_RECOVERY_RunParty(GameEvent *event, int *seq, void *eventWork)
{
    PartyRecoveryWork *work = eventWork;

    switch (*seq) {
    case PARTY_RECOVERY_STEP_PLACE:
        if ((int)work->frame % RECOVERY_PARTY_SPAWN_INTERVAL == 0) {
            EVENT_RECOVERY_PlacePartyBall(work);
            if (work->ballCount <= work->ballsPlaced) {
                *seq = *seq + 1;
                work->frame = 0;
            }
        }
        break;
    case PARTY_RECOVERY_STEP_START_ANIME:
        if (work->frame > RECOVERY_END_DELAY) {
            EVENT_RECOVERY_ActivateParty(work);
            *seq = *seq + 1;
            work->frame = 0;
        }
        break;
    case PARTY_RECOVERY_STEP_WAIT_ANIME:
        if (EVENT_RECOVERY_IsMachineAnimeDone(work) != 0) {
            *seq = *seq + 1;
        }
        break;
    case PARTY_RECOVERY_STEP_END:
        EVENT_RECOVERY_DeleteMachineNode(work);
        return UNIT_021C06CC_FINISHED;
    }
    work->frame = work->frame + 1;
    return UNIT_021C06CC_CONTINUE;
}

/*
 * Fills the party recovery work: finds the machine entry around the player
 * and makes a node from it.
 */
void EVENT_RECOVERY_InitParty(PartyRecoveryWork *work, GameSystem *gameSystem)
{
    FieldMap *fieldMap;
    struct FieldG3dMapper *mapper;
    struct BuildModelEntry **entries;
    VecFx32 playerPos;
    RecoveryRect rect;
    int entryCount;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    mapper = FIELDMAP_GetG3dMapper(fieldMap);
    work->heapId = FIELDMAP_GetHeapId(fieldMap);
    work->fieldMap = fieldMap;
    work->ballCount = EVENT_RECOVERY_GetPartyBallCount(gameSystem);
    work->ballsPlaced = 0;
    work->buildModelMan = FIELD_G3D_MAPPER_GetBuildModel(mapper);
    work->machineEntry = 0;
    if (work->ballCount > RECOVERY_BALL_MAX) {
        work->ballCount = RECOVERY_BALL_MAX;
    }
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(work->fieldMap), &playerPos);
    rect.zMin = playerPos.z - RECOVERY_SEARCH_RADIUS;
    rect.zMax = playerPos.z + RECOVERY_SEARCH_RADIUS;
    rect.xMin = playerPos.x - RECOVERY_SEARCH_RADIUS;
    rect.xMax = playerPos.x + RECOVERY_SEARCH_RADIUS;
    entries = FIELD_BUILDMODEL_CollectEntriesInRect(work->buildModelMan, &rect, RECOVERY_ENTRY_KIND_MACHINE, &entryCount);
    if (entries) {
        work->machineEntry = *entries;
        FIELD_BUILDMODEL_GetEntryWorldPos(*entries, &work->machinePos);
    }
    func_020307B0(entries);
    if (work->machineEntry != 0) {
        work->machineNode = FIELD_BUILDMODEL_CreateNodeFromEntry(work->buildModelMan, work->machineEntry);
    }
}

/*
 * Deletes the machine node when there is one.
 */
void EVENT_RECOVERY_DeleteMachineNode(PartyRecoveryWork *work)
{
    if (work->machineEntry != 0)
        FIELD_BUILDMODEL_DeleteNode(work->machineNode);
}

/*
 * Places the next ball at its offset from the machine and plays the sound.
 */
void EVENT_RECOVERY_PlacePartyBall(PartyRecoveryWork *work)
{
    RecoveryBallPlacement placement;
    u32 i;

    i = work->ballsPlaced;
    if (work->ballCount > i) {
        placement.scale.x = 0x1000;
        placement.scale.y = 0x1000;
        placement.scale.z = 0x1000;
        BUTTON_MAN_MakeRotMtxXYZ(0, 0, 0, &placement.rotation);
        func_0207C9D0(&work->machinePos, &sPartyRecoveryBallOffsets[i], &placement.pos);
        work->balls[i] = FIELD_BUILDMODEL_CreateNodeFromBlock(work->buildModelMan, RECOVERY_BALL_MODEL_TABLE_ID, &placement);
        work->ballsPlaced++;
        func_020061E4(RECOVERY_SE_BALL_PLACED);
    }
}

/*
 * Sets the active mode on each placed ball and resets the machine node.
 */
void EVENT_RECOVERY_ActivateParty(PartyRecoveryWork *work)
{
    int i;

    for (i = 0; i < work->ballsPlaced; i++)
        FIELD_BUILDMODEL_PlayNodeSlot(work->balls[i], RECOVERY_ANIME_SLOT, RECOVERY_MODE_ACTIVE);
    if (work->machineEntry != 0)
        FIELD_BUILDMODEL_PlayNodeSlot(work->machineNode, RECOVERY_ANIME_SLOT, RECOVERY_MODE_START);
}

/*
 * Returns the state of the machine node animation, or 1 without a machine.
 */
int EVENT_RECOVERY_IsMachineAnimeDone(PartyRecoveryWork *work)
{
    if (work->machineEntry != 0) {
        return FIELD_BUILDMODEL_TryOpenNodeCurrentSlot(work->machineNode);
    }
    return 1;
}

/*
 * Number of party members that are not eggs.
 */
u32 EVENT_RECOVERY_GetPartyBallCount(GameSystem *gameSystem)
{
    return func_0201AA1C(GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData(gameSystem)));
}
