/*
 * file:     event_trainer_eye.c
 * unit:     yes
 * function: func_021AE0CC, func_021AE198, func_021AE1FC, func_021AE288, func_021AE348, func_021AE360, func_021AE394, func_021AE3C8, func_021AE3FC, func_021AE430, func_021AE454, func_021AE498, func_021AE4B4, func_021AE4E0, func_021AE524, func_021AE550, func_021AE56C, func_021AE58C, func_021AE5A8, func_021AE5BC, func_021AE5D4, func_021AE5EC, func_021AE604, func_021AE630, func_021AE650, func_021AE66C, func_021AE6E0, func_021AE708, func_021AE724, func_021AE72C, func_021AE754, func_021AE79C, func_021AE7A8, func_021AE884, func_021AE890, func_021AE8B4, func_021AE8D4, func_021AE930
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
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0215A4C8  0x0215A4C8  thumb  ov010
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0218B6AC  0x0218B6AC  thumb  ov021
 *   func_021AE930  0x021AE930  thumb  ov021
 *   func_0215A438  0x0215A438  thumb  ov010
 *   func_021AE8D4  0x021AE8D4  thumb  ov021
 *   func_021AE8B4  0x021AE8B4  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_021AE7A8  0x021AE7A8  thumb  ov021
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_021AE890  0x021AE890  thumb  ov021
 *   func_021AE79C  0x021AE79C  thumb  ov021
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   d_021D9338  0x021D9338  data  a4
 *   func_021AE754  0x021AE754  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   d_021DE138  0x021DE138  data  a4
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0216DB04  0x0216DB04  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021BB528  0x021BB528  thumb  ov021
 *   func_021BB5C8  0x021BB5C8  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021642B4  0x021642B4  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_0216E0E8  0x0216E0E8  thumb  ov010
 *   d_021D9348  0x021D9348  data
 *   func_020307B0  0x020307B0  arm
 *   func_0216D5A8  0x0216D5A8  thumb
 *   func_0216E434  0x0216E434  thumb
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_02163994  0x02163994  thumb  ov010
 *   func_021AA900  0x021AA900  thumb  ov021
 *   func_0216D5B8  0x0216D5B8  thumb  ov010
 *   func_0215A460  0x0215A460  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_0215A4D8  0x0215A4D8  thumb  ov010
 *   func_02158768  0x02158768  thumb  ov010
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

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern void func_020307B0(void *memory);
extern void func_021AC154(FieldEffectObj *effect);
extern int func_0215A4C8(int trainerId);
extern int func_0215A460(u32 eventId);
extern u32 func_0215A4D8(void *saveData, u32 trainerId);
extern void func_0215A438(int scriptWork, int index, TrainerEyeHit *hit);
extern GameSystem *func_02188C80(FieldMap *fieldMap);
extern int func_0218B6AC(GameSystem *gameSystem);
extern void *func_020120F4(GameSystem *gameSystem);
extern void *func_0201296C(void *gameData);
extern int func_02158768(GameSystem *gameSystem, u32 size, Mmdl *trainer, int flag);
extern MmdlSys *func_0216D67C(Mmdl *mmdl);
extern Mmdl *func_0216DE94(MmdlSys *mmdlSys, u32 objId);
extern void func_0216D828(Mmdl *mmdl, GridPos *out);
extern FieldEncount *func_02188CE8(FieldMap *fieldMap);
extern FieldPlayer *func_02188CB4(FieldMap *fieldMap);
extern Mmdl *func_021A3074(FieldPlayer *player);
extern MmdlSys *func_02188C7C(FieldMap *fieldMap);
extern int func_0216DD1C(MmdlSys *mmdlSys, Mmdl **outMmdl, u32 *iter);
extern int func_0216D63C(Mmdl *mmdl, int paramIndex);
extern u16 func_0216D5F8(const Mmdl *mmdl);
extern GameEvent *func_020122C0(void *owner, void *a, GameEventFunc func, u32 workSize);
extern void *func_020124E8(GameEvent *event);
extern int func_0216DA5C(Mmdl *mmdl);
extern void func_0216DB04(Mmdl *mmdl);
extern void func_0216D5E0(Mmdl *mmdl, int dir);
extern void func_0216DAF8(Mmdl *mmdl);
extern int func_0216D454(Mmdl *mmdl);
extern u16 func_0216D5A0(Mmdl *mmdl);
extern int func_0216D3CC(Mmdl *mmdl);
extern void func_0216D410(Mmdl *mmdl, u32 acmd);
extern int func_02197E7C(int dir, int acmdBase);
extern FieldEffectObj *func_021BB528(void *fieldEffect, Mmdl *mmdl, u32 a, u32 b);
extern int func_021BB5C8(FieldEffectObj *effect);
extern void *func_02188CD0(FieldMap *fieldMap);
extern int func_0216D83C(Mmdl *mmdl);
extern int func_0216D86C(Mmdl *mmdl);
extern u16 func_021642B4(int x0, int z0, int x1, int z1);
extern void func_0216D480(Mmdl *mmdl);
extern void func_0216E0E8(Mmdl *mmdl, int value);
extern u32 func_0216D5A8(Mmdl *mmdl);
extern int func_0216E434(u32 movementCode);
extern u32 func_0216D5B8(Mmdl *mmdl);
extern s16 func_021641E8(u32 dir);
extern s16 func_021641F8(u32 dir);
extern int func_02163994(Mmdl *mmdl, int x, int y, int z, u32 dir);
extern int func_021AA900(FieldEncount *encount, GridPos *pos);

int func_021AE0CC(FieldMap *fieldMap);
int func_021AE198(Mmdl *mmdl, u32 dir, int range, FieldEncount *encount);
int func_021AE1FC(FieldMap *fieldMap, Mmdl *exclude, TrainerEyeHit *out);
int func_021AE288(FieldEncount *encount, Mmdl *trainer, Mmdl *player, u16 *outDir);
int func_021AE348(int dir, int range, const GridPos *trainerPos, const GridPos *targetPos);
int func_021AE360(int range, const GridPos *trainerPos, const GridPos *targetPos);
int func_021AE394(int range, const GridPos *trainerPos, const GridPos *targetPos);
int func_021AE3C8(int range, const GridPos *trainerPos, const GridPos *targetPos);
int func_021AE3FC(int range, const GridPos *trainerPos, const GridPos *targetPos);
GameEvent *func_021AE430(void *owner, TrainerEyeWork *first, TrainerEyeWork *second);
TrainerEyeWork *func_021AE454(u32 heapId, FieldMap *fieldMap, TrainerEyeHit *hit, int recordIndex);
int func_021AE498(TrainerEyeWork *work);
int func_021AE4B4(TrainerEyeWork *work);
int func_021AE4E0(TrainerEyeWork *work);
int func_021AE524(TrainerEyeWork *work);
int func_021AE550(TrainerEyeWork *work);
int func_021AE56C(TrainerEyeWork *work);
int func_021AE58C(TrainerEyeWork *work);
int func_021AE5A8(TrainerEyeWork *work);
int func_021AE5BC(TrainerEyeWork *work);
int func_021AE5D4(TrainerEyeWork *work);
int func_021AE5EC(TrainerEyeWork *work);
int func_021AE604(TrainerEyeWork *work);
int func_021AE630(TrainerEyeWork *work);
int func_021AE650(TrainerEyeWork *work);
int func_021AE66C(TrainerEyeWork *work);
int func_021AE6E0(TrainerEyeWork *work);
int func_021AE708(TrainerEyeWork *work);
int func_021AE724(TrainerEyeWork *work);
int func_021AE72C(TrainerEyeWork *work);
int func_021AE754(void *eventSys, void *gameSystem, void *work);
int func_021AE79C(Mmdl *mmdl);
int func_021AE7A8(Mmdl *mmdl, u32 dir, int distance, FieldEncount *encount);
int func_021AE884(Mmdl *mmdl);
int func_021AE890(FieldMap *fieldMap, Mmdl *mmdl);
void func_021AE8B4(TrainerEyeHit *hit, Mmdl *trainer, u32 distance, u32 direction);
Mmdl *func_021AE8D4(Mmdl *mmdl, u16 trainerId);
int func_021AE930(FieldMap *fieldMap, Mmdl *trainer);

extern TrainerEyeSightFunc d_021D9338[4];              /* sight check per direction */
extern TrainerEyeStepFunc d_021D9348[];                /* step table of the event */
extern char d_021DE138[];                              /* source file name for the heap allocator */

/*
 * Looks for the trainers that see the player and registers them as records
 * of a script command work. Returns that work, or 0 when no trainer sees
 * the player.
 */
int func_021AE0CC(FieldMap *fieldMap)
{
    TrainerEyeHit hit;
    TrainerEyeHit partner;
    u32 battleType;
    u32 partyCount;
    int zero = 0;
    int scriptWork = 0;

    if (func_021AE1FC(fieldMap, 0, &hit) == 1) {
        battleType = (u32)func_0215A4C8((u16)hit.trainerId);
        partyCount = func_0218B6AC(func_02188C80(fieldMap));
        if (battleType == TRAINER_EYE_BATTLE_SINGLE) {
            if (partyCount < 2 || func_021AE1FC(fieldMap, hit.trainer, &partner) == 0) {
                scriptWork = func_021AE930(fieldMap, hit.trainer);
                hit.hitKind = TRAINER_EYE_HIT_SINGLE;
                func_0215A438(scriptWork, 0, &hit);
            } else {
                scriptWork = func_021AE930(fieldMap, hit.trainer);
                hit.hitKind = TRAINER_EYE_HIT_DOUBLE_PAIR;
                func_0215A438(scriptWork, zero, &hit);
                partner.hitKind = TRAINER_EYE_HIT_DOUBLE_PAIR;
                func_0215A438(scriptWork, 1, &partner);
            }
        } else if (battleType == TRAINER_EYE_BATTLE_DOUBLE) {
            if (partyCount >= 2) {
                func_021AE8B4(&partner, func_021AE8D4(hit.trainer, hit.trainerId), hit.distance, (u16)hit.direction);
                scriptWork = func_021AE930(fieldMap, hit.trainer);
                hit.hitKind = TRAINER_EYE_HIT_DOUBLE_SOLO;
                func_0215A438(scriptWork, zero, &hit);
                partner.hitKind = TRAINER_EYE_HIT_DOUBLE_SOLO;
                func_0215A438(scriptWork, 1, &partner);
            }
        } else if (battleType == TRAINER_EYE_BATTLE_TRIPLE || battleType == TRAINER_EYE_BATTLE_ROTATION) {
            if (partyCount >= 3) {
                scriptWork = func_021AE930(fieldMap, hit.trainer);
                hit.hitKind = zero;
                func_0215A438(scriptWork, zero, &hit);
            }
        }
    }
    return scriptWork;
}

/* Distance in tiles to the player along dir, or -1 when the player is not in line or the way is blocked. */
int func_021AE198(Mmdl *mmdl, u32 dir, int range, FieldEncount *encount)
{
    GridPos trainerPos;
    GridPos playerPos;
    Mmdl *player;
    int distance;

    player = func_0216DE94(func_0216D67C(mmdl), TRAINER_EYE_PLAYER_OBJ_ID);
    if (player == 0)
        return -1;
    func_0216D828(player, &playerPos);
    func_0216D828(mmdl, &trainerPos);
    distance = func_021AE348(dir, (s16)range, &trainerPos, &playerPos);
    if (distance != -1) {
        if (func_021AE7A8(mmdl, dir, distance, encount) == 1)
            distance = -1;
    }
    return distance;
}

/* Finds the first model that is not exclude and sees the player; fills out. */
int func_021AE1FC(FieldMap *fieldMap, Mmdl *exclude, TrainerEyeHit *out)
{
    TrainerEyeHit *hit = out;
    FieldEncount *encount;
    int distance;
    u16 direction;
    Mmdl *current;
    u32 iter;
    Mmdl *player;
    MmdlSys *mmdlSys;

    encount = func_02188CE8(fieldMap);
    player = func_021A3074(func_02188CB4(fieldMap));
    mmdlSys = func_02188C7C(fieldMap);
    current = 0;
    iter = 0;
    while (func_0216DD1C(mmdlSys, &current, &iter) == 1) {
        if (current != player && (exclude == 0 || exclude != current)) {
            distance = func_021AE288(encount, current, player, &direction);
            if (distance != -1 && func_021AE890(fieldMap, current) == 0) {
                func_021AE8B4(hit, current, distance, direction);
                return 1;
            }
        }
    }
    return 0;
}

/* Distance in tiles from the trainer to the player along its sight, or -1. Sets the direction used. */
int func_021AE288(FieldEncount *encount, Mmdl *trainer, Mmdl *player, u16 *outDir)
{
    GridPos trainerPos;
    GridPos playerPos;
    int sightType;
    int range;
    int dir;
    u16 scanDir;

    sightType = func_021AE79C(trainer);
    if ((u16)(sightType + 0xffff) <= 1) {
        scanDir = 0;
        range = (s16)func_0216D63C(trainer, 0);
        func_0216D828(trainer, &trainerPos);
        func_0216D828(player, &playerPos);
        if (sightType == TRAINER_EYE_SIGHT_FACING) {
            dir = func_0216D5F8(trainer);
            sightType = func_021AE348(dir, range, &trainerPos, &playerPos);
            if (sightType != scanDir - 1 && func_021AE7A8(trainer, dir, sightType, encount) == 0) {
                *outDir = dir;
                return sightType;
            }
        } else {
            do {
                sightType = func_021AE348(scanDir, range, &trainerPos, &playerPos);
                if (sightType != -1 && func_021AE7A8(trainer, scanDir, sightType, encount) == 0) {
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
int func_021AE348(int dir, int range, const GridPos *trainerPos, const GridPos *targetPos)
{
    return d_021D9338[dir](range, trainerPos, targetPos);
}

/* Sight check upwards: tiles to the target on the same column above the trainer, or -1. */
int func_021AE360(int range, const GridPos *trainerPos, const GridPos *targetPos)
{
    if (trainerPos->x == targetPos->x && trainerPos->y == targetPos->y && targetPos->z < trainerPos->z && targetPos->z >= trainerPos->z - range)
        return trainerPos->z - targetPos->z;
    return -1;
}

/* Sight check downwards. */
int func_021AE394(int range, const GridPos *trainerPos, const GridPos *targetPos)
{
    if (trainerPos->x == targetPos->x && trainerPos->y == targetPos->y && targetPos->z > trainerPos->z && targetPos->z <= trainerPos->z + range)
        return targetPos->z - trainerPos->z;
    return -1;
}

/* Sight check to the left. */
int func_021AE3C8(int range, const GridPos *trainerPos, const GridPos *targetPos)
{
    if (trainerPos->z == targetPos->z && trainerPos->y == targetPos->y && targetPos->x < trainerPos->x && targetPos->x >= trainerPos->x - range)
        return trainerPos->x - targetPos->x;
    return -1;
}

/* Sight check to the right. */
int func_021AE3FC(int range, const GridPos *trainerPos, const GridPos *targetPos)
{
    if (trainerPos->z == targetPos->z && trainerPos->y == targetPos->y && targetPos->x > trainerPos->x && targetPos->x <= trainerPos->x + range)
        return targetPos->x - trainerPos->x;
    return -1;
}

/* Creates the event that waits for two trainer eye events to end. */
GameEvent *func_021AE430(void *owner, TrainerEyeWork *first, TrainerEyeWork *second)
{
    GameEvent *event;
    TrainerEyePairWork *pair;

    event = func_020122C0(owner, 0, func_021AE754, sizeof(TrainerEyePairWork));
    pair = func_020124E8(event);
    pair->first = first;
    pair->second = second;
    return event;
}

/* Creates the trainer eye event for one record. */
TrainerEyeWork *func_021AE454(u32 heapId, FieldMap *fieldMap, TrainerEyeHit *hit, int recordIndex)
{
    TrainerEyeWork *work = func_02030734(heapId, sizeof(TrainerEyeWork), 1, d_021DE138, 0x1fa);

    work->hit = *hit;
    work->reserved20 = 0;
    work->recordIndex = recordIndex;
    work->fieldMap = fieldMap;
    work->player = func_02188CB4(fieldMap);
    return work;
}

/* Step 0: lets the trainer move again if it was paused. */
int func_021AE498(TrainerEyeWork *work)
{
    if (func_0216DA5C(work->hit.trainer) == 1) {
        func_0216DB04(work->hit.trainer);
    }
    work->state = TRAINER_EYE_STATE_FACE_TARGET;
    return 1;
}

/* Step 1: waits for the trainer to stop, then turns it toward the player and pauses it. */
int func_021AE4B4(TrainerEyeWork *work)
{
    if (func_0216DA5C(work->hit.trainer) == 1) {
        return 0;
    }
    func_0216D5E0(work->hit.trainer, (u16)work->hit.direction);
    func_0216DAF8(work->hit.trainer);
    work->state = TRAINER_EYE_STATE_WAIT_PLAYER;
    return 1;
}

/* Step 2: waits for the player model to finish its animation. */
int func_021AE4E0(TrainerEyeWork *work)
{
    if (func_0216D454(func_021A3074(work->player)) == 0)
        return 0;
    work->state = TRAINER_EYE_STATE_START_TURN;
    switch (func_0216D5A0(work->hit.trainer)) {
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
int func_021AE524(TrainerEyeWork *work)
{
    if (func_0216D3CC(work->hit.trainer) == 1) {
        func_0216D410(work->hit.trainer, func_02197E7C((u16)work->hit.direction, TRAINER_EYE_ACMD_TURN));
        work->state = TRAINER_EYE_STATE_WAIT_TURN;
    }
    return 0;
}

/* Step 4: waits for the turn animation to end. */
int func_021AE550(TrainerEyeWork *work)
{
    if (func_0216D454(work->hit.trainer) == 0) {
        return 0;
    }
    work->state = TRAINER_EYE_STATE_START_MARK;
    return 1;
}

/* Step 5: shows the "!" mark over the trainer. */
int func_021AE56C(TrainerEyeWork *work)
{
    work->markEffect = func_021BB528(func_02188CD0(work->fieldMap), work->hit.trainer, 0, 0);
    work->state = TRAINER_EYE_STATE_WAIT_MARK;
    return 0;
}

/* Step 6: waits for the mark effect to finish, then removes it. */
int func_021AE58C(TrainerEyeWork *work)
{
    if (func_021BB5C8(work->markEffect) == 1) {
        func_021AC154(work->markEffect);
        work->state = TRAINER_EYE_STATE_DELAY;
    }
    return 0;
}

/* Step 7: starts the alert animation of trainers that show no mark. */
int func_021AE5A8(TrainerEyeWork *work)
{
    func_0216D410(work->hit.trainer, TRAINER_EYE_ACMD_ALERT);
    work->state = TRAINER_EYE_STATE_WAIT_ALERT;
    return 0;
}

/* Step 8: waits for the alert animation to end. */
int func_021AE5BC(TrainerEyeWork *work)
{
    if (func_0216D454(work->hit.trainer) == 1) {
        work->state = TRAINER_EYE_STATE_DELAY;
    }
    return 0;
}

/* Step 9: waits TRAINER_EYE_DELAY_FRAMES frames. */
int func_021AE5D4(TrainerEyeWork *work)
{
    work->delayCount++;
    if (work->delayCount >= TRAINER_EYE_DELAY_FRAMES) {
        work->delayCount = 0;
        work->state = TRAINER_EYE_STATE_SELECT_APPROACH;
    }
    return 0;
}

/* Step 10: the trainer walks to the player, or just turns when next to it. */
int func_021AE5EC(TrainerEyeWork *work)
{
    if (work->hit.distance <= 1) {
        work->state = TRAINER_EYE_STATE_ADJACENT;
        return 1;
    }
    work->state = TRAINER_EYE_STATE_APPROACH;
    return 1;
}

/* Step 11: starts the trainer's walk step toward the player. */
int func_021AE604(TrainerEyeWork *work)
{
    if (func_0216D3CC(work->hit.trainer) == 1) {
        func_0216D410(work->hit.trainer, func_02197E7C((u16)work->hit.direction, TRAINER_EYE_ACMD_WALK));
        work->state = TRAINER_EYE_STATE_WAIT_STEP;
    }
    return 0;
}

/* Step 12: waits for the step to end, then counts one tile off the distance. */
int func_021AE630(TrainerEyeWork *work)
{
    if (func_0216D454(work->hit.trainer) == 0)
        return 0;
    work->hit.distance--;
    work->state = TRAINER_EYE_STATE_SELECT_APPROACH;
    return 1;
}

/* Step 13: the trainer stands next to the player; waits TRAINER_EYE_ADJACENT_FRAMES frames. */
int func_021AE650(TrainerEyeWork *work)
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
int func_021AE66C(TrainerEyeWork *work)
{
    Mmdl *player = func_021A3074(work->player);
    int playerX = func_0216D83C(player);
    int playerZ = func_0216D86C(player);
    int trainerX = func_0216D83C(work->hit.trainer);
    int dirToTrainer;

    dirToTrainer = func_021642B4(playerX, playerZ, trainerX, func_0216D86C(work->hit.trainer));
    if (dirToTrainer != func_0216D5F8(player) && (work->recordIndex == 0 || work->hit.hitKind == TRAINER_EYE_HIT_DOUBLE_PAIR)) {
        if (func_0216D3CC(player) == 1) {
            func_0216D410(player, func_02197E7C(dirToTrainer, TRAINER_EYE_ACMD_TURN));
            work->state = TRAINER_EYE_STATE_WAIT_PLAYER_FACE;
        }
    } else {
        work->state = TRAINER_EYE_STATE_RELEASE;
    }
    return 0;
}

/* Step 15: waits for the player's turn to end. */
int func_021AE6E0(TrainerEyeWork *work)
{
    Mmdl *player = func_021A3074(work->player);

    if (func_0216D454(player) == 0)
        return 0;
    func_0216D480(player);
    work->state = TRAINER_EYE_STATE_RELEASE;
    return 1;
}

/* Step 16: releases the trainer from its paused state. */
int func_021AE708(TrainerEyeWork *work)
{
    func_0216D480(work->hit.trainer);
    func_0216E0E8(work->hit.trainer, 0);
    work->state = TRAINER_EYE_STATE_DONE;
    return 1;
}

/* Step 17: marks the event as finished. */
int func_021AE724(TrainerEyeWork *work)
{
    work->finished = 1;
    return 0;
}

/* Runs steps until one asks to wait; returns 1 when the event is finished. */
int func_021AE72C(TrainerEyeWork *work)
{
    while (d_021D9348[work->state](work) == 1)
        ;
    if (work->finished == 1)
        return 1;
    return 0;
}

/* Event callback: runs both trainer eye events of a pair and frees each when done. Returns 1 when both ended. */
int func_021AE754(void *eventSys, void *gameSystem, void *work)
{
    TrainerEyePairWork *pair = work;

    if (pair->first != 0) {
        if (func_021AE72C(pair->first) == 1) {
            func_020307B0(pair->first);
            pair->first = 0;
        }
    }
    if (pair->second != 0) {
        if (func_021AE72C(pair->second) == 1) {
            func_020307B0(pair->second);
            pair->second = 0;
        }
    }
    if (pair->first == 0 && pair->second == 0) {
        return 1;
    }
    return 0;
}

/* Sight type of a model (TRAINER_EYE_SIGHT_*), from its movement code. */
int func_021AE79C(Mmdl *mmdl)
{
    return func_0216E434(func_0216D5A8(mmdl));
}

/* Returns 1 when something blocks the straight path of distance tiles from the model along dir. */
int func_021AE7A8(Mmdl *mmdl, u32 dir, int distance, FieldEncount *encount)
{
    GridPos pos;
    s16 dx;
    s16 dz;
    int i;

    if (distance != 0) {
        i = 0;
        func_0216D828(mmdl, &pos);
        dx = func_021641E8(dir);
        dz = func_021641F8(dir);
        pos.x += dx;
        pos.z += dz;
        for (; i < distance - 1; i++) {
            if ((func_02163994(mmdl, pos.x, pos.y, pos.z, dir) & ~1) != 0)
                return 1;
            if (encount != 0 && func_021AA900(encount, &pos) != 0)
                return 1;
            pos.x += dx;
            pos.z += dz;
        }
        if ((func_02163994(mmdl, pos.x, pos.y, pos.z, dir) & ~1) != 4)
            return 1;
        if (encount != 0 && func_021AA900(encount, &pos) != 0)
            return 1;
    }
    return 0;
}

/* Trainer id of a trainer model, from its object event id. */
int func_021AE884(Mmdl *mmdl)
{
    return func_0215A460(func_0216D5B8(mmdl));
}

/* Nonzero when the trainer of the model was already beaten. */
int func_021AE890(FieldMap *fieldMap, Mmdl *mmdl)
{
    return func_0215A4D8(func_0201296C(func_020120F4(func_02188C80(fieldMap))), func_021AE884(mmdl));
}

/* Fills a hit record for a trainer model. */
void func_021AE8B4(TrainerEyeHit *hit, Mmdl *trainer, u32 distance, u32 direction)
{
    hit->distance = distance;
    hit->direction = direction;
    hit->eventId = func_0216D5B8(trainer);
    hit->trainerId = func_021AE884(trainer);
    hit->trainer = trainer;
}

/* Finds the other trainer model with the same trainer id that has a sight; 0 if none. */
Mmdl *func_021AE8D4(Mmdl *mmdl, u16 trainerId)
{
    Mmdl *other;
    u32 iter;
    MmdlSys *mmdlSys;

    iter = 0;
    mmdlSys = func_0216D67C(mmdl);
    while (func_0216DD1C(mmdlSys, &other, &iter) == 1) {
        if (other != mmdl && (u16)(func_021AE79C(other) + 0xFFFF) <= 1 && trainerId == func_021AE884(other)) {
            return other;
        }
    }
    return 0;
}

/* Creates the script work of the trainer battle for a trainer model. */
int func_021AE930(FieldMap *fieldMap, Mmdl *trainer)
{
    return func_02158768(func_02188C80(fieldMap), TRAINER_EYE_SCRIPT_WORK_SIZE, trainer, 1);
}
