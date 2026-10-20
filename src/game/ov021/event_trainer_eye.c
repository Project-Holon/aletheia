/*
 * file:     event_trainer_eye.c
 * unit:     yes
 * function: EVENT_TRAINER_EYE_Check, EVENT_TRAINER_EYE_GetPlayerDistance, EVENT_TRAINER_EYE_FindTrainer, EVENT_TRAINER_EYE_GetSightDistance, EVENT_TRAINER_EYE_CheckSight, EVENT_TRAINER_EYE_CheckSightUp, EVENT_TRAINER_EYE_CheckSightDown, EVENT_TRAINER_EYE_CheckSightLeft, EVENT_TRAINER_EYE_CheckSightRight, EVENT_TRAINER_EYE_CreatePairEvent, EVENT_TRAINER_EYE_Create, EVENT_TRAINER_EYE_StepResumeMove, EVENT_TRAINER_EYE_StepFaceTarget, EVENT_TRAINER_EYE_StepWaitPlayer, EVENT_TRAINER_EYE_StepStartTurn, EVENT_TRAINER_EYE_StepWaitTurn, EVENT_TRAINER_EYE_StepStartMark, EVENT_TRAINER_EYE_StepWaitMark, EVENT_TRAINER_EYE_StepStartAlert, EVENT_TRAINER_EYE_StepWaitAlert, EVENT_TRAINER_EYE_StepDelay, EVENT_TRAINER_EYE_StepSelectApproach, EVENT_TRAINER_EYE_StepApproach, EVENT_TRAINER_EYE_StepWaitStep, EVENT_TRAINER_EYE_StepAdjacent, EVENT_TRAINER_EYE_StepPlayerFaceTrainer, EVENT_TRAINER_EYE_StepWaitPlayerFace, EVENT_TRAINER_EYE_StepRelease, EVENT_TRAINER_EYE_StepDone, EVENT_TRAINER_EYE_Run, EVENT_TRAINER_EYE_UpdatePairEvent, EVENT_TRAINER_EYE_GetSightType, EVENT_TRAINER_EYE_IsPathBlocked, EVENT_TRAINER_EYE_GetTrainerId, EVENT_TRAINER_EYE_IsTrainerDefeated, EVENT_TRAINER_EYE_FillHit, EVENT_TRAINER_EYE_FindPartner, EVENT_TRAINER_EYE_CreateScriptWork
 * address:  0x021AE0CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Trainer eye event: finds the trainers that see the player, runs the
 * 18-step event of each and the helpers of the step functions. Merged from
 * event_trainer_eye.c (021AE0CC..021AE5EC), unit_021AE604.c (021AE604..021AE650)
 * and event_trainer_eye_p01.c (021AE66C..021AE930); the code between and after
 * holds no other function.
 *
 * symbols:
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   EVENT_TRAINER_GetBattleType  0x0215A4C8  thumb  ov010
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELD_EVENT_CHECK_CountAlivePartyMembers  0x0218B6AC  thumb  ov021
 *   EVENT_TRAINER_EYE_CreateScriptWork  0x021AE930  thumb  ov021
 *   EVENT_TRAINER_SetScriptTrainerEntry  0x0215A438  thumb  ov010
 *   EVENT_TRAINER_EYE_FindPartner  0x021AE8D4  thumb  ov021
 *   EVENT_TRAINER_EYE_FillHit  0x021AE8B4  thumb  ov021
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_GetGridNowPos  0x0216D828  thumb  ov010
 *   EVENT_TRAINER_EYE_IsPathBlocked  0x021AE7A8  thumb  ov021
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   EVENT_TRAINER_EYE_IsTrainerDefeated  0x021AE890  thumb  ov021
 *   EVENT_TRAINER_EYE_GetSightType  0x021AE79C  thumb  ov021
 *   FLDMMDL_GetParam  0x0216D63C  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   sTrainerEyeSightFuncs  0x021D9338  data  a4
 *   EVENT_TRAINER_EYE_UpdatePairEvent  0x021AE754  thumb  ov021
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   sEventTrainerEyeFileName  0x021DE138  data  a4
 *   FLDMMDL_CheckMoveBitMove  0x0216DA5C  thumb  ov010
 *   FLDMMDL_OffMoveBitMovePause  0x0216DB04  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_OnMoveBitMovePause  0x0216DAF8  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_GYOE_SetMMdl  0x021BB528  thumb  ov021
 *   FLDEFF_GYOE_IsFinished  0x021BB5C8  thumb  ov021
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirFromPoints  0x021642B4  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   FLDMMDL_ChangeMoveCode  0x0216E0E8  thumb  ov010
 *   sTrainerEyeStepFuncs  0x021D9348  data
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FLDMMDL_GetEventType  0x0216D5A8  thumb
 *   FLDMMDL_NormalizeEventType  0x0216E434  thumb
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 *   FLDMMDL_MOVE_HitCheckMoveCurrent  0x02163994  thumb  ov010
 *   EFFECT_ENCOUNT_IsSpotAt  0x021AA900  thumb  ov021
 *   FLDMMDL_GetEventId  0x0216D5B8  thumb  ov010
 *   EVENT_TRAINER_GetTrainerIdFromScriptId  0x0215A460  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   EVENT_TRAINER_CheckDefeatedFlag  0x0215A4D8  thumb  ov010
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   GAME_EVENT_Create  0x020122C0  thumb  arm9
 *   GAME_EVENT_GetWork  0x020124E8  thumb  arm9
 */
#include "event_trainer_eye_types.h"
#include "field_effect_types.h"
#include "field_encount_types.h"

/* Opaque types of other files. */
typedef struct FieldMap FieldMap;
typedef struct FieldPlayer FieldPlayer;
typedef struct GameEvent GameEvent;
typedef struct GameSystem GameSystem;

/* Position of a model on the map grid. */
typedef struct GridPos {
    s16 x;
    s16 y;
    s16 z;
    s16 pad06;
} GridPos;

/* Work of the event that waits for two trainer eye events (8 bytes). */
typedef struct TrainerEyePairWork {
    TrainerEyeWork *first;                         /* 0x00 cleared when finished */
    TrainerEyeWork *second;                        /* 0x04 */
} TrainerEyePairWork;

/* Trainer battle types (trainer data) and how a hit is registered. */
#define TRAINER_EYE_BATTLE_SINGLE   0
#define TRAINER_EYE_BATTLE_DOUBLE   1
#define TRAINER_EYE_BATTLE_TRIPLE   2
#define TRAINER_EYE_BATTLE_ROTATION 3

#define TRAINER_EYE_HIT_SINGLE      0   /* one trainer fights alone */
#define TRAINER_EYE_HIT_DOUBLE_SOLO 1   /* double battle trainer with a partner trainer */
#define TRAINER_EYE_HIT_DOUBLE_PAIR 2   /* two single trainers fight together */

/* Sight types of a trainer model (0 and everything else above 2: no sight). */
#define TRAINER_EYE_SIGHT_FACING         1   /* sees only along its facing */
#define TRAINER_EYE_SIGHT_ALL_DIRECTIONS 2   /* looks along all four directions */

/* Object id of the player model. */
#define TRAINER_EYE_PLAYER_OBJ_ID 0xff

/* Animation command codes of a field model. */
#define TRAINER_EYE_ACMD_ALERT 101

/* Frames the trainer waits after the mark before it acts. */
#define TRAINER_EYE_DELAY_FRAMES 30

/* Frames the trainer waits when it stands next to the player. */
#define TRAINER_EYE_ADJACENT_FRAMES 8

/* Script work block of a trainer battle: capacity argument of the creator. */
#define TRAINER_EYE_SCRIPT_WORK_SIZE (226 << 4)

typedef int (*TrainerEyeSightFunc)(int range, const GridPos *trainerPos, const GridPos *targetPos);
typedef int (*TrainerEyeStepFunc)(TrainerEyeWork *work);
typedef int (*GameEventFunc)(void *eventSys, void *gameSystem, void *work);

#include "../arm9/gfl_heap_wrap.h"
#include "field_effect.h"
#include "../ov010/event_trainer.h"
struct RecordHead24;
#include "fieldmap.h"
#include "field_event_check.h"
struct GameData;
extern struct GameData *GAMESYSTEM_GetGameData(GameSystem *gameSystem);
#include "../arm9/game_data.h"
extern struct GameEvent *SCRIPT_SYS_CreateScriptEventSimple(void *fieldSys, u16 scriptId, void *target, s32 reserved);
#ifdef __MWERKS__
#define FLDMMDL_SetAcmd FLDMMDL_SetAcmd_header
#include "../ov010/fldmmdl.h"
#include "../ov010/fldmmdl_move.h"
#undef FLDMMDL_SetAcmd
void FLDMMDL_SetAcmd(Mmdl *mmdl, u32 acmd); /* original prototype: the definition takes u16 */
#else
#include "../ov010/fldmmdl.h"
#include "../ov010/fldmmdl_move.h"
#endif
struct MmdlGridVec;
struct Mmdl;
#include "field_player.h"
extern GameEvent *GAME_EVENT_Create(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc func, u32 workSize);
extern void *GAME_EVENT_GetWork(GameEvent *event);
#include "fldmmdl_acmd.h"
#include "fldeff_gyoe.h"
struct FieldEffectCont;
struct FieldEncount;
#include "effect_encount.h"

int EVENT_TRAINER_EYE_Check(FieldMap *fieldMap);
int EVENT_TRAINER_EYE_GetPlayerDistance(Mmdl *mmdl, u16 dir, int range, FieldEncount *encount);
int EVENT_TRAINER_EYE_FindTrainer(FieldMap *fieldMap, Mmdl *exclude, TrainerEyeHit *out);
int EVENT_TRAINER_EYE_GetSightDistance(FieldEncount *encount, Mmdl *trainer, Mmdl *player, u16 *outDir);
int EVENT_TRAINER_EYE_CheckSight(int dir, int range, const GridPos *trainerPos, const GridPos *targetPos);
int EVENT_TRAINER_EYE_CheckSightUp(int range, const GridPos *trainerPos, const GridPos *targetPos);
int EVENT_TRAINER_EYE_CheckSightDown(int range, const GridPos *trainerPos, const GridPos *targetPos);
int EVENT_TRAINER_EYE_CheckSightLeft(int range, const GridPos *trainerPos, const GridPos *targetPos);
int EVENT_TRAINER_EYE_CheckSightRight(int range, const GridPos *trainerPos, const GridPos *targetPos);
GameEvent *EVENT_TRAINER_EYE_CreatePairEvent(void *owner, TrainerEyeWork *first, TrainerEyeWork *second);
TrainerEyeWork *EVENT_TRAINER_EYE_Create(u32 heapId, FieldMap *fieldMap, TrainerEyeHit *hit, int recordIndex);
int EVENT_TRAINER_EYE_StepResumeMove(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepFaceTarget(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepWaitPlayer(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepStartTurn(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepWaitTurn(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepStartMark(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepWaitMark(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepStartAlert(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepWaitAlert(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepDelay(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepSelectApproach(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepApproach(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepWaitStep(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepAdjacent(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepPlayerFaceTrainer(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepWaitPlayerFace(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepRelease(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepDone(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_Run(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_UpdatePairEvent(void *eventSys, void *gameSystem, void *work);
int EVENT_TRAINER_EYE_GetSightType(Mmdl *mmdl);
int EVENT_TRAINER_EYE_IsPathBlocked(Mmdl *mmdl, u16 dir, int distance, FieldEncount *encount);
int EVENT_TRAINER_EYE_GetTrainerId(Mmdl *mmdl);
int EVENT_TRAINER_EYE_IsTrainerDefeated(FieldMap *fieldMap, Mmdl *mmdl);
void EVENT_TRAINER_EYE_FillHit(TrainerEyeHit *hit, Mmdl *trainer, u32 distance, u32 direction);
Mmdl *EVENT_TRAINER_EYE_FindPartner(Mmdl *mmdl, u16 trainerId);
int EVENT_TRAINER_EYE_CreateScriptWork(FieldMap *fieldMap, Mmdl *trainer);

extern TrainerEyeSightFunc sTrainerEyeSightFuncs[4];              /* sight check per direction */
extern TrainerEyeStepFunc sTrainerEyeStepFuncs[];                /* step table of the event */
extern char sEventTrainerEyeFileName[];                              /* source file name for the heap allocator */

/*
 * Looks for the trainers that see the player and registers them as records
 * of a script command work. Returns that work, or 0 when no trainer sees
 * the player.
 */
int EVENT_TRAINER_EYE_Check(FieldMap *fieldMap)
{
    TrainerEyeHit hit;
    TrainerEyeHit partner;
    u32 battleType;
    u32 partyCount;
    int zero = 0;
    int scriptWork = 0;

    if (EVENT_TRAINER_EYE_FindTrainer(fieldMap, 0, &hit) == 1) {
        battleType = (u32)EVENT_TRAINER_GetBattleType((u16)hit.trainerId);
        partyCount = FIELD_EVENT_CHECK_CountAlivePartyMembers(FIELDMAP_GetGameSystem(fieldMap));
        if (battleType == TRAINER_EYE_BATTLE_SINGLE) {
            if (partyCount < 2 || EVENT_TRAINER_EYE_FindTrainer(fieldMap, hit.trainer, &partner) == 0) {
                scriptWork = EVENT_TRAINER_EYE_CreateScriptWork(fieldMap, hit.trainer);
                hit.hitKind = TRAINER_EYE_HIT_SINGLE;
                EVENT_TRAINER_SetScriptTrainerEntry(scriptWork, 0, (struct RecordHead24 *)(&hit));
            } else {
                scriptWork = EVENT_TRAINER_EYE_CreateScriptWork(fieldMap, hit.trainer);
                hit.hitKind = TRAINER_EYE_HIT_DOUBLE_PAIR;
                EVENT_TRAINER_SetScriptTrainerEntry(scriptWork, zero, (struct RecordHead24 *)(&hit));
                partner.hitKind = TRAINER_EYE_HIT_DOUBLE_PAIR;
                EVENT_TRAINER_SetScriptTrainerEntry(scriptWork, 1, (struct RecordHead24 *)(&partner));
            }
        } else if (battleType == TRAINER_EYE_BATTLE_DOUBLE) {
            if (partyCount >= 2) {
                EVENT_TRAINER_EYE_FillHit(&partner, EVENT_TRAINER_EYE_FindPartner(hit.trainer, hit.trainerId), hit.distance, (u16)hit.direction);
                scriptWork = EVENT_TRAINER_EYE_CreateScriptWork(fieldMap, hit.trainer);
                hit.hitKind = TRAINER_EYE_HIT_DOUBLE_SOLO;
                EVENT_TRAINER_SetScriptTrainerEntry(scriptWork, zero, (struct RecordHead24 *)(&hit));
                partner.hitKind = TRAINER_EYE_HIT_DOUBLE_SOLO;
                EVENT_TRAINER_SetScriptTrainerEntry(scriptWork, 1, (struct RecordHead24 *)(&partner));
            }
        } else if (battleType == TRAINER_EYE_BATTLE_TRIPLE || battleType == TRAINER_EYE_BATTLE_ROTATION) {
            if (partyCount >= 3) {
                scriptWork = EVENT_TRAINER_EYE_CreateScriptWork(fieldMap, hit.trainer);
                hit.hitKind = zero;
                EVENT_TRAINER_SetScriptTrainerEntry(scriptWork, zero, (struct RecordHead24 *)(&hit));
            }
        }
    }
    return scriptWork;
}

/* Distance in tiles to the player along dir, or -1 when the player is not in line or the way is blocked. */
int EVENT_TRAINER_EYE_GetPlayerDistance(Mmdl *mmdl, u16 dir, int range, FieldEncount *encount)
{
    GridPos trainerPos;
    GridPos playerPos;
    Mmdl *player;
    int distance;

    player = FLDMMDL_SysSearchObjId(FLDMMDL_GetMmdlSys(mmdl), TRAINER_EYE_PLAYER_OBJ_ID);
    if (player == 0)
        return -1;
    FLDMMDL_GetGridNowPos(player, (struct MmdlGridVec *)(&playerPos));
    FLDMMDL_GetGridNowPos(mmdl, (struct MmdlGridVec *)(&trainerPos));
    distance = EVENT_TRAINER_EYE_CheckSight(dir, (s16)range, &trainerPos, &playerPos);
    if (distance != -1) {
        if (EVENT_TRAINER_EYE_IsPathBlocked(mmdl, dir, distance, encount) == 1)
            distance = -1;
    }
    return distance;
}

/* Finds the first model that is not exclude and sees the player; fills out. */
int EVENT_TRAINER_EYE_FindTrainer(FieldMap *fieldMap, Mmdl *exclude, TrainerEyeHit *out)
{
    TrainerEyeHit *hit = out;
    FieldEncount *encount;
    int distance;
    u16 direction;
    Mmdl *current;
    u32 iter;
    Mmdl *player;
    MmdlSys *mmdlSys;

    encount = FIELDMAP_GetEncount(fieldMap);
    player = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
    mmdlSys = FIELDMAP_GetMmdlSys(fieldMap);
    current = 0;
    iter = 0;
    while (FLDMMDL_SysSearchUseMmdl(mmdlSys, &current, &iter) == 1) {
        if (current != player && (exclude == 0 || exclude != current)) {
            distance = EVENT_TRAINER_EYE_GetSightDistance(encount, current, player, &direction);
            if (distance != -1 && EVENT_TRAINER_EYE_IsTrainerDefeated(fieldMap, current) == 0) {
                EVENT_TRAINER_EYE_FillHit(hit, current, distance, direction);
                return 1;
            }
        }
    }
    return 0;
}

/* Distance in tiles from the trainer to the player along its sight, or -1. Sets the direction used. */
int EVENT_TRAINER_EYE_GetSightDistance(FieldEncount *encount, Mmdl *trainer, Mmdl *player, u16 *outDir)
{
    GridPos trainerPos;
    GridPos playerPos;
    int sightType;
    int range;
    u16 dir;
    u16 scanDir;

    sightType = EVENT_TRAINER_EYE_GetSightType(trainer);
    if ((u16)(sightType + 0xffff) <= 1) {
        scanDir = 0;
        range = (s16)FLDMMDL_GetParam(trainer, 0);
        FLDMMDL_GetGridNowPos(trainer, (struct MmdlGridVec *)(&trainerPos));
        FLDMMDL_GetGridNowPos(player, (struct MmdlGridVec *)(&playerPos));
        if (sightType == TRAINER_EYE_SIGHT_FACING) {
            dir = FLDMMDL_GetDirDisp(trainer);
            sightType = EVENT_TRAINER_EYE_CheckSight(dir, range, &trainerPos, &playerPos);
            if (sightType != scanDir - 1 && EVENT_TRAINER_EYE_IsPathBlocked(trainer, dir, sightType, encount) == 0) {
                *outDir = dir;
                return sightType;
            }
        } else {
            do {
                sightType = EVENT_TRAINER_EYE_CheckSight(scanDir, range, &trainerPos, &playerPos);
                if (sightType != -1 && EVENT_TRAINER_EYE_IsPathBlocked(trainer, scanDir, sightType, encount) == 0) {
                    *outDir = scanDir;
                    return sightType;
                }
                scanDir++;
            } while (scanDir < 4);
        }
    }
    return -1;
}

/* Runs the sight check of one direction (0 up, 1 down, 2 left, 3 right). */
int EVENT_TRAINER_EYE_CheckSight(int dir, int range, const GridPos *trainerPos, const GridPos *targetPos)
{
    return sTrainerEyeSightFuncs[dir](range, trainerPos, targetPos);
}

/* Sight check upwards: tiles to the target on the same column above the trainer, or -1. */
int EVENT_TRAINER_EYE_CheckSightUp(int range, const GridPos *trainerPos, const GridPos *targetPos)
{
    if (trainerPos->x == targetPos->x && trainerPos->y == targetPos->y && targetPos->z < trainerPos->z && targetPos->z >= trainerPos->z - range)
        return trainerPos->z - targetPos->z;
    return -1;
}

/* Sight check downwards. */
int EVENT_TRAINER_EYE_CheckSightDown(int range, const GridPos *trainerPos, const GridPos *targetPos)
{
    if (trainerPos->x == targetPos->x && trainerPos->y == targetPos->y && targetPos->z > trainerPos->z && targetPos->z <= trainerPos->z + range)
        return targetPos->z - trainerPos->z;
    return -1;
}

/* Sight check to the left. */
int EVENT_TRAINER_EYE_CheckSightLeft(int range, const GridPos *trainerPos, const GridPos *targetPos)
{
    if (trainerPos->z == targetPos->z && trainerPos->y == targetPos->y && targetPos->x < trainerPos->x && targetPos->x >= trainerPos->x - range)
        return trainerPos->x - targetPos->x;
    return -1;
}

/* Sight check to the right. */
int EVENT_TRAINER_EYE_CheckSightRight(int range, const GridPos *trainerPos, const GridPos *targetPos)
{
    if (trainerPos->z == targetPos->z && trainerPos->y == targetPos->y && targetPos->x > trainerPos->x && targetPos->x <= trainerPos->x + range)
        return targetPos->x - trainerPos->x;
    return -1;
}

/* Creates the event that waits for two trainer eye events to end. */
GameEvent *EVENT_TRAINER_EYE_CreatePairEvent(void *owner, TrainerEyeWork *first, TrainerEyeWork *second)
{
    GameEvent *event;
    TrainerEyePairWork *pair;

    event = GAME_EVENT_Create(owner, 0, (GameEventFunc)EVENT_TRAINER_EYE_UpdatePairEvent, sizeof(TrainerEyePairWork));
    pair = GAME_EVENT_GetWork(event);
    pair->first = first;
    pair->second = second;
    return event;
}

/* Creates the trainer eye event for one record. */
TrainerEyeWork *EVENT_TRAINER_EYE_Create(u32 heapId, FieldMap *fieldMap, TrainerEyeHit *hit, int recordIndex)
{
    TrainerEyeWork *work = GFL_HEAP_Alloc(heapId, sizeof(TrainerEyeWork), 1, sEventTrainerEyeFileName, 0x1fa);

    work->hit = *hit;
    work->reserved20 = 0;
    work->recordIndex = recordIndex;
    work->fieldMap = fieldMap;
    work->player = FIELDMAP_GetFieldPlayer(fieldMap);
    return work;
}

/* Step 0: lets the trainer move again if it was paused. */
int EVENT_TRAINER_EYE_StepResumeMove(TrainerEyeWork *work)
{
    if (FLDMMDL_CheckMoveBitMove(work->hit.trainer) == 1) {
        FLDMMDL_OffMoveBitMovePause(work->hit.trainer);
    }
    work->state = TRAINER_EYE_STATE_FACE_TARGET;
    return 1;
}

/* Step 1: waits for the trainer to stop, then turns it toward the player and pauses it. */
int EVENT_TRAINER_EYE_StepFaceTarget(TrainerEyeWork *work)
{
    if (FLDMMDL_CheckMoveBitMove(work->hit.trainer) == 1) {
        return 0;
    }
    FLDMMDL_SetDirDispCheckPause(work->hit.trainer, (u16)work->hit.direction);
    FLDMMDL_OnMoveBitMovePause(work->hit.trainer);
    work->state = TRAINER_EYE_STATE_WAIT_PLAYER;
    return 1;
}

/* Step 2: waits for the player model to finish its animation. */
int EVENT_TRAINER_EYE_StepWaitPlayer(TrainerEyeWork *work)
{
    if (FLDMMDL_CheckEndAcmd(FIELD_PLAYER_GetMmdl(work->player)) == 0)
        return 0;
    work->state = TRAINER_EYE_STATE_START_TURN;
    switch (FLDMMDL_GetMoveCode(work->hit.trainer)) {
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
        work->state = TRAINER_EYE_STATE_START_ALERT;
        break;
    }
    return 1;
}

/* Step 3: starts the turn animation toward the player. */
int EVENT_TRAINER_EYE_StepStartTurn(TrainerEyeWork *work)
{
    if (FLDMMDL_CheckPossibleAcmd(work->hit.trainer) == 1) {
        FLDMMDL_SetAcmd(work->hit.trainer, FLDMMDL_ACMD_ConvertCodeByDir((u16)work->hit.direction, TRAINER_EYE_ACMD_TURN));
        work->state = TRAINER_EYE_STATE_WAIT_TURN;
    }
    return 0;
}

/* Step 4: waits for the turn animation to end. */
int EVENT_TRAINER_EYE_StepWaitTurn(TrainerEyeWork *work)
{
    if (FLDMMDL_CheckEndAcmd(work->hit.trainer) == 0) {
        return 0;
    }
    work->state = TRAINER_EYE_STATE_START_MARK;
    return 1;
}

/* Step 5: shows the "!" mark over the trainer. */
int EVENT_TRAINER_EYE_StepStartMark(TrainerEyeWork *work)
{
    work->markEffect = FLDEFF_GYOE_SetMMdl(FIELDMAP_GetEffect(work->fieldMap), work->hit.trainer, 0, 0);
    work->state = TRAINER_EYE_STATE_WAIT_MARK;
    return 0;
}

/* Step 6: waits for the mark effect to finish, then removes it. */
int EVENT_TRAINER_EYE_StepWaitMark(TrainerEyeWork *work)
{
    if (FLDEFF_GYOE_IsFinished(work->markEffect) == 1) {
        FIELD_EFFECT_DeleteObject(work->markEffect);
        work->state = TRAINER_EYE_STATE_DELAY;
    }
    return 0;
}

/* Step 7: starts the alert animation of trainers that show no mark. */
int EVENT_TRAINER_EYE_StepStartAlert(TrainerEyeWork *work)
{
    FLDMMDL_SetAcmd(work->hit.trainer, TRAINER_EYE_ACMD_ALERT);
    work->state = TRAINER_EYE_STATE_WAIT_ALERT;
    return 0;
}

/* Step 8: waits for the alert animation to end. */
int EVENT_TRAINER_EYE_StepWaitAlert(TrainerEyeWork *work)
{
    if (FLDMMDL_CheckEndAcmd(work->hit.trainer) == 1) {
        work->state = TRAINER_EYE_STATE_DELAY;
    }
    return 0;
}

/* Step 9: waits TRAINER_EYE_DELAY_FRAMES frames. */
int EVENT_TRAINER_EYE_StepDelay(TrainerEyeWork *work)
{
    work->delayCount++;
    if (work->delayCount >= TRAINER_EYE_DELAY_FRAMES) {
        work->delayCount = 0;
        work->state = TRAINER_EYE_STATE_SELECT_APPROACH;
    }
    return 0;
}

/* Step 10: the trainer walks to the player, or just turns when next to it. */
int EVENT_TRAINER_EYE_StepSelectApproach(TrainerEyeWork *work)
{
    if (work->hit.distance <= 1) {
        work->state = TRAINER_EYE_STATE_ADJACENT;
        return 1;
    }
    work->state = TRAINER_EYE_STATE_APPROACH;
    return 1;
}

/* Step 11: starts the trainer's walk step toward the player. */
int EVENT_TRAINER_EYE_StepApproach(TrainerEyeWork *work)
{
    if (FLDMMDL_CheckPossibleAcmd(work->hit.trainer) == 1) {
        FLDMMDL_SetAcmd(work->hit.trainer, FLDMMDL_ACMD_ConvertCodeByDir((u16)work->hit.direction, TRAINER_EYE_ACMD_WALK));
        work->state = TRAINER_EYE_STATE_WAIT_STEP;
    }
    return 0;
}

/* Step 12: waits for the step to end, then counts one tile off the distance. */
int EVENT_TRAINER_EYE_StepWaitStep(TrainerEyeWork *work)
{
    if (FLDMMDL_CheckEndAcmd(work->hit.trainer) == 0)
        return 0;
    work->hit.distance--;
    work->state = TRAINER_EYE_STATE_SELECT_APPROACH;
    return 1;
}

/* Step 13: the trainer stands next to the player; waits TRAINER_EYE_ADJACENT_FRAMES frames. */
int EVENT_TRAINER_EYE_StepAdjacent(TrainerEyeWork *work)
{
    work->delayCount++;
    if (work->delayCount < TRAINER_EYE_ADJACENT_FRAMES) {
        return 0;
    }
    work->delayCount = 0;
    work->state = TRAINER_EYE_STATE_PLAYER_FACE;
    return 1;
}

/*
 * Step 14: turns the player toward the trainer (first record only, or both
 * records of a pair battle) unless it already faces it.
 */
int EVENT_TRAINER_EYE_StepPlayerFaceTrainer(TrainerEyeWork *work)
{
    Mmdl *player = FIELD_PLAYER_GetMmdl(work->player);
    int playerX = FLDMMDL_GetGridNowX(player);
    int playerZ = FLDMMDL_GetGridNowZ(player);
    int trainerX = FLDMMDL_GetGridNowX(work->hit.trainer);
    int dirToTrainer;

    dirToTrainer = FLDMMDL_MOVE_GetDirFromPoints(playerX, playerZ, trainerX, FLDMMDL_GetGridNowZ(work->hit.trainer));
    if (dirToTrainer != FLDMMDL_GetDirDisp(player) && (work->recordIndex == 0 || work->hit.hitKind == TRAINER_EYE_HIT_DOUBLE_PAIR)) {
        if (FLDMMDL_CheckPossibleAcmd(player) == 1) {
            FLDMMDL_SetAcmd(player, FLDMMDL_ACMD_ConvertCodeByDir(dirToTrainer, TRAINER_EYE_ACMD_TURN));
            work->state = TRAINER_EYE_STATE_WAIT_PLAYER_FACE;
        }
    } else {
        work->state = TRAINER_EYE_STATE_RELEASE;
    }
    return 0;
}

/* Step 15: waits for the player's turn to end. */
int EVENT_TRAINER_EYE_StepWaitPlayerFace(TrainerEyeWork *work)
{
    Mmdl *player = FIELD_PLAYER_GetMmdl(work->player);

    if (FLDMMDL_CheckEndAcmd(player) == 0)
        return 0;
    FLDMMDL_EndAcmd(player);
    work->state = TRAINER_EYE_STATE_RELEASE;
    return 1;
}

/* Step 16: releases the trainer from its paused state. */
int EVENT_TRAINER_EYE_StepRelease(TrainerEyeWork *work)
{
    FLDMMDL_EndAcmd(work->hit.trainer);
    FLDMMDL_ChangeMoveCode(work->hit.trainer, 0);
    work->state = TRAINER_EYE_STATE_DONE;
    return 1;
}

/* Step 17: marks the event as finished. */
int EVENT_TRAINER_EYE_StepDone(TrainerEyeWork *work)
{
    work->finished = 1;
    return 0;
}

/* Runs steps until one asks to wait; returns 1 when the event is finished. */
int EVENT_TRAINER_EYE_Run(TrainerEyeWork *work)
{
    while (sTrainerEyeStepFuncs[work->state](work) == 1)
        ;
    if (work->finished == 1)
        return 1;
    return 0;
}

/* Event callback: runs both trainer eye events of a pair and frees each when done. Returns 1 when both ended. */
int EVENT_TRAINER_EYE_UpdatePairEvent(void *eventSys, void *gameSystem, void *work)
{
    TrainerEyePairWork *pair = work;

    if (pair->first != 0) {
        if (EVENT_TRAINER_EYE_Run(pair->first) == 1) {
            GFL_HEAP_Free(pair->first);
            pair->first = 0;
        }
    }
    if (pair->second != 0) {
        if (EVENT_TRAINER_EYE_Run(pair->second) == 1) {
            GFL_HEAP_Free(pair->second);
            pair->second = 0;
        }
    }
    if (pair->first == 0 && pair->second == 0) {
        return 1;
    }
    return 0;
}

/* Sight type of a model (TRAINER_EYE_SIGHT_*), from its movement code. */
int EVENT_TRAINER_EYE_GetSightType(Mmdl *mmdl)
{
    return FLDMMDL_NormalizeEventType(FLDMMDL_GetEventType(mmdl));
}

/* Returns 1 when something blocks the straight path of distance tiles from the model along dir. */
int EVENT_TRAINER_EYE_IsPathBlocked(Mmdl *mmdl, u16 dir, int distance, FieldEncount *encount)
{
    GridPos pos;
    s16 dx;
    s16 dz;
    int i;

    if (distance != 0) {
        i = 0;
        FLDMMDL_GetGridNowPos(mmdl, (struct MmdlGridVec *)(&pos));
        dx = FLDMMDL_MOVE_GetDirAddGridX(dir);
        dz = FLDMMDL_MOVE_GetDirAddGridZ(dir);
        pos.x += dx;
        pos.z += dz;
        for (; i < distance - 1; i++) {
            if ((FLDMMDL_MOVE_HitCheckMoveCurrent(mmdl, pos.x, pos.y, pos.z, dir) & ~1) != 0)
                return 1;
            if (encount != 0 && EFFECT_ENCOUNT_IsSpotAt(encount, (s16 *)(&pos)) != 0)
                return 1;
            pos.x += dx;
            pos.z += dz;
        }
        if ((FLDMMDL_MOVE_HitCheckMoveCurrent(mmdl, pos.x, pos.y, pos.z, dir) & ~1) != 4)
            return 1;
        if (encount != 0 && EFFECT_ENCOUNT_IsSpotAt(encount, (s16 *)(&pos)) != 0)
            return 1;
    }
    return 0;
}

/* Trainer id of a trainer model, from its object event id. */
int EVENT_TRAINER_EYE_GetTrainerId(Mmdl *mmdl)
{
    return EVENT_TRAINER_GetTrainerIdFromScriptId(FLDMMDL_GetEventId(mmdl));
}

/* Nonzero when the trainer of the model was already beaten. */
int EVENT_TRAINER_EYE_IsTrainerDefeated(FieldMap *fieldMap, Mmdl *mmdl)
{
    return EVENT_TRAINER_CheckDefeatedFlag(GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), EVENT_TRAINER_EYE_GetTrainerId(mmdl));
}

/* Fills a hit record for a trainer model. */
void EVENT_TRAINER_EYE_FillHit(TrainerEyeHit *hit, Mmdl *trainer, u32 distance, u32 direction)
{
    hit->distance = distance;
    hit->direction = direction;
    hit->eventId = FLDMMDL_GetEventId(trainer);
    hit->trainerId = EVENT_TRAINER_EYE_GetTrainerId(trainer);
    hit->trainer = trainer;
}

/* Finds the other trainer model with the same trainer id that has a sight; 0 if none. */
Mmdl *EVENT_TRAINER_EYE_FindPartner(Mmdl *mmdl, u16 trainerId)
{
    Mmdl *other;
    u32 iter;
    MmdlSys *mmdlSys;

    iter = 0;
    mmdlSys = FLDMMDL_GetMmdlSys(mmdl);
    while (FLDMMDL_SysSearchUseMmdl(mmdlSys, &other, &iter) == 1) {
        if (other != mmdl && (u16)(EVENT_TRAINER_EYE_GetSightType(other) + 0xFFFF) <= 1 && trainerId == EVENT_TRAINER_EYE_GetTrainerId(other)) {
            return other;
        }
    }
    return 0;
}

/* Creates the script work of the trainer battle for a trainer model. */
int EVENT_TRAINER_EYE_CreateScriptWork(FieldMap *fieldMap, Mmdl *trainer)
{
    return (s32)SCRIPT_SYS_CreateScriptEventSimple(FIELDMAP_GetGameSystem(fieldMap), TRAINER_EYE_SCRIPT_WORK_SIZE, trainer, 1);
}
