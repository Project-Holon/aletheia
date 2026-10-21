/*
 * file:     trial_house.c
 * unit:     yes
 * function: TRIAL_HOUSE_CreateWork, TRIAL_HOUSE_LoadDeliveryState, TRIAL_HOUSE_DeleteWork, TRIAL_HOUSE_SetBattleMode, TRIAL_HOUSE_SetUseDeliveredTrainers, TRIAL_HOUSE_LoadTrainer, TRIAL_HOUSE_BuildTrainerFromMode, TRIAL_HOUSE_LoadDeliveredTrainer, TRIAL_HOUSE_GetTrainerObjCode, TRIAL_HOUSE_CreateTrainerMsgEvent, TRIAL_HOUSE_CreateDeliveryTask, TRIAL_HOUSE_DeliveryTaskMain, TRIAL_HOUSE_ComputeScoreAndRank, TRIAL_HOUSE_GetDeliveryState, TRIAL_HOUSE_CreateSaveTask, TRIAL_HOUSE_GetRecordSlotsState, TRIAL_HOUSE_IsDeliveryIdReceived, TRIAL_HOUSE_MarkDeliveryIdReceived, TRIAL_HOUSE_SaveTaskMain 
 * address:  0x021D096C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from trial_house.c at 0x021D096C (lane L136, __FILE__ anchor trial_house.c at 021D096C/09D0/0B58/0DB0/10A8 (d_021DE674)).
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   abs_id_4b      0x0000004B  data
 *   abs_id_4d      0x0000004D  data
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   abs_id_39      0x00000039  data
 *   BATTLE_EXAMINATION_GetBlockSize  0x0200E588  thumb
 *   POKEPARTY_Create  0x0201A920  thumb
 *   d_021DE674     0x021DE674  data  a4
 *   SAVE_CONTROL_LoadExtraSaveWithBuffer  0x020072CC  thumb
 *   SAVE_CONTROL_GetExtraSaveRecord  0x020073D8  thumb
 *   BATTLE_EXAMINATION_IsDeliveryValid  0x0200E5A0  thumb
 *   BATTLE_EXAMINATION_IsDeliveryUnused  0x0200E5CC  thumb
 *   SAVE_CONTROL_DeleteExtraSaveBuffered  0x0200734C  thumb
 *   POKEPARTY_InitEx  0x0201A954  thumb
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   FLD_BTL_INST_TOOL_CreateTrainer  0x02168878  thumb  ov010
 *   BATTLE_EXAMINATION_GetTrainerSlot  0x0200E5F8  thumb
 *   FLD_BTL_INST_TOOL_LookupKeyValue  0x02168AEC  thumb  ov010
 *   FLD_BTL_INST_TOOL_CreateTrainerMsgEvent  0x021680C8  thumb  ov010
 *   GAME_LANGUAGE_Code     0x0209DF0C  data  a1
 *   DELIVERY_BEACON_Create  0x021576D0  thumb  ov010
 *   DELIVERY_BEACON_Start  0x021578A0  thumb  ov010
 *   DELIVERY_BEACON_RunStep  0x02157928  thumb  ov010
 *   DELIVERY_BEACON_HasAnyPiece  0x021578F0  thumb  ov010
 *   DELIVERY_BEACON_TryComplete  0x02157910  thumb  ov010
 *   TRIAL_HOUSE_SAVE_GetFromSave  0x0200E8F8  thumb
 *   BATTLE_EXAMINATION_GetDeliveryId  0x0200E5E4  thumb
 *   BATTLE_EXAMINATION_LoadDelivery  0x0200E608  thumb
 *   DELIVERY_BEACON_Delete  0x02157938  thumb  ov010
 *   GFL_NET_IsIdle  0x0203D210  arm
 *   RECORD_GetFromSave  0x02008C58  thumb
 *   RECORD_SetTrialScore  0x02008E88  thumb
 *   RECORD_SetTrialRank  0x02008E68  thumb
 *   FIELD_SAVEANIME_Create  0x021D1164  thumb  ov021
 *   FIELD_SAVEANIME_Start  0x021D11B0  thumb  ov021
 *   BATTLE_EXAMINATION_RefreshMarker  0x0200E684  thumb
 *   GAME_DATA_PartSaveStart  0x02012E4C  thumb
 *   GAME_DATA_PartSaveMain  0x02012E7C  thumb
 *   FIELD_SAVEANIME_Stop  0x021D11D8  thumb  ov021
 *   FIELD_SAVEANIME_Delete  0x021D1194  thumb  ov021
 */
#include "../types.h"

#include "../version.h"
#include "bsubway_scr_types.h"

/* Opaque types of other files. */
typedef struct GameEvent GameEvent;
typedef struct Party Party;
typedef struct FieldMap FieldMap;
typedef struct FieldSaveAnime FieldSaveAnime;         /* save icon animation (field_saveanime.c) */
typedef struct DeliveryBeacon DeliveryBeacon;         /* wireless delivery session (ov010 delivery_beacon.c) */
typedef struct RecordBlock RecordBlock;               /* player record block of the save */

/* Id of the heap the trial house work and its party live in. */
#define TRIAL_HOUSE_HEAP_ID 5

/* Save block that holds the delivered trainers, and the heap and buffer size it is read with. */
#define TRIAL_HOUSE_SAVE_BLOCK 5
#define TRIAL_HOUSE_SAVE_HEAP_ID 0x8004
#define TRIAL_HOUSE_SAVE_BUF_SIZE 0x1000

/* Values of TrialHouseWork.deliveryState. */
#define TRIAL_HOUSE_DELIVERY_NONE  0 /* no valid delivered trainers in the save */
#define TRIAL_HOUSE_DELIVERY_FRESH 1 /* valid, not used yet */
#define TRIAL_HOUSE_DELIVERY_USED  2 /* valid, marked as used */

/* Result codes of the delivery task (written to the script variable). */
#define TRIAL_HOUSE_DELIVERY_RESULT_FAILED   0
#define TRIAL_HOUSE_DELIVERY_RESULT_RECEIVED 1
#define TRIAL_HOUSE_DELIVERY_RESULT_KNOWN    2 /* this delivery id was received before */
#define TRIAL_HOUSE_DELIVERY_RESULT_NET_ERROR 3

/* Wireless delivery: game kind sent in the beacon, and frames to wait for senders. */
#define TRIAL_HOUSE_DELIVERY_GAME_KIND 0x2E
#define TRIAL_HOUSE_DELIVERY_ACCEPT_MASK PM_VERSION_MASK
#define TRIAL_HOUSE_DELIVERY_HEAP_ID 0x8015
#define TRIAL_HOUSE_DELIVERY_WAIT_FRAMES 120

#define TRIAL_HOUSE_SAVED_TRAINER_COUNT 5

/* The 128 delivery ids are a bit set in TrialHouseSave. */
#define TRIAL_HOUSE_DELIVERY_ID_COUNT 0x80

/* Trainers delivered by wireless (save block 5, 0x5C8 bytes). */
typedef struct TrialHouseDelivery {
    BtlInstTrainer trainers[TRIAL_HOUSE_SAVED_TRAINER_COUNT]; /* 0x000 */
    u8 profile[0x22];                      /* 0x5A0 copied to TrialHouseSave.profile */
    u16 magic;                             /* 0x5C2 0xD68 in valid data */
    u16 idAndUsed;                         /* 0x5C4 delivery id in bits 0..6, bit 15 = used */
    u16 checksum;                          /* 0x5C6 */
} TrialHouseDelivery;

/* One of the four Pokemon of a saved result. */
typedef struct TrialHouseSaveMon {
    u16 species;
    u8 form;                               /* guess: Pokemon parameter 0x6F */
    u8 gender;                             /* guess: Pokemon parameter 0x6E */
} TrialHouseSaveMon;

/* Best result of one kind of battle (0x14 bytes). */
typedef struct TrialHouseSaveSlot {
    u8 valid;
    u8 battleMode;                         /* 0 = 3 Pokemon, 1 = 4 Pokemon */
    u16 score;
    TrialHouseSaveMon mons[4];
} TrialHouseSaveSlot;

/* Trial house part of the main save. */
typedef struct TrialHouseSave {
    TrialHouseSaveSlot slot[2];            /* 0x00 */
    u8 receivedIds[16];                    /* 0x28 bit set of delivery ids received before */
    u8 profile[0x22];                      /* 0x38 */
} TrialHouseSave;

/* Battle results of the work, summed over the battles of a run (ov010 BtlInstRecord). */
typedef struct TrialHouseTally {
    u16 tally[10];                         /* 0x00 */
    u16 scoreShare;                        /* 0x14 */
    u16 lastTally;                         /* 0x16 */
} TrialHouseTally;

/* Work of the trial house script commands (0x154 bytes); ov010 treats it as the battle request. */
typedef struct TrialHouseWork {
    BtlInstTrainer trainer;                /* 0x000 trainer of the next battle */
    u16 heapId;                            /* 0x120 */
    u16 pad122;
    int monCount;                          /* 0x124 Pokemon per side: 3 or 4 */
    Party *playerParty;                    /* 0x128 */
    int battleMode;                        /* 0x12C 0 = 3 Pokemon, 1 = 4 Pokemon */
    int useDeliveredTrainers;              /* 0x130 draw trainers from the delivered data */
    TrialHouseTally tally;                 /* 0x134 */
    TrialHouseDelivery *delivery;          /* 0x14C buffer for the delivered data */
    u32 deliveryState;                     /* 0x150 TRIAL_HOUSE_DELIVERY_* */
} TrialHouseWork;

/* Setup block of the wireless delivery session (ov010 DeliveryBeaconParam). */
typedef struct TrialHouseBeaconParam {
    u32 gameKind;                          /* 0x00 */
    u8 reserved04;
    u8 pad05;
    u16 heapId;                            /* 0x06 */
    int destSize;                          /* 0x08 */
    TrialHouseDelivery *dest;              /* 0x0C receives the delivered data */
    u32 gameVersion;                       /* 0x10 */
    u32 acceptMask;                        /* 0x14 */
    u8 reserved18[0x60];
    u32 pageCount;                         /* 0x78 */
} TrialHouseBeaconParam;

/* Work of the delivery task (0x90 bytes). */
typedef struct TrialHouseDeliveryTaskWork {
    TrialHouseBeaconParam param;           /* 0x00 */
    DeliveryBeacon *beacon;                /* 0x7C */
    GameSystem *gameSystem;                /* 0x80 */
    TrialHouseWork *trialHouse;            /* 0x84 */
    u16 *result;                           /* 0x88 TRIAL_HOUSE_DELIVERY_RESULT_* */
    int waitFrames;                        /* 0x8C */
} TrialHouseDeliveryTaskWork;

/* Work of the save task (0x10 bytes). */
typedef struct TrialHouseSaveTaskWork {
    GameSystem *gameSystem;                /* 0x00 */
    TrialHouseDelivery *buffer;            /* 0x04 save block 5 while it is written */
    int mode;                              /* 0x08 1 = mark the delivered data used, else erase it */
    FieldSaveAnime *saveAnime;             /* 0x0C */
} TrialHouseSaveTaskWork;

#include "../arm9/mi_memory.h"
#include "../arm9/key.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/game_event.h"
struct GameSystem;
#include "../arm9/gamesystem.h"
#include "../arm9/game_data.h"
struct PokemonParam;
#include "../arm9/pokeparty.h"
#include "../arm9/poke_tool.h"
extern u32 BATTLE_EXAMINATION_GetBlockSize(void);
extern u32 SAVE_CONTROL_LoadExtraSaveWithBuffer(SaveControl *saveControl, u32 blockId, u16 heapId, void *buf, u32 size);
extern TrialHouseDelivery *SAVE_CONTROL_GetExtraSaveRecord(SaveControl *saveControl, u32 blockId, u32 arg);
extern void SAVE_CONTROL_DeleteExtraSaveBuffered(SaveControl *saveControl, unsigned int blockId);
extern int BATTLE_EXAMINATION_IsDeliveryValid(void *delivery);
extern int BATTLE_EXAMINATION_IsDeliveryUnused(void *delivery);
extern BtlInstTrainer *BATTLE_EXAMINATION_GetTrainerSlot(TrialHouseDelivery *delivery, u32 index);
extern u16 BATTLE_EXAMINATION_GetDeliveryId(void *delivery);
extern void BATTLE_EXAMINATION_LoadDelivery(void *gameData, void *dst, u32 heap);
extern void BATTLE_EXAMINATION_RefreshMarker(void *delivery);
#include "../arm9/trial_house_savedata.h"
#include "../arm9/record.h"
#include "../arm9/gfl_use.h"
#include "../ov010/fld_btl_inst_tool.h"
struct DeliveryBeaconParam;
#include "../ov010/delivery_beacon.h"
#include "../arm9/net.h"
#include "field_saveanime.h"

TrialHouseWork *TRIAL_HOUSE_CreateWork(GameSystem *gameSystem);
void TRIAL_HOUSE_LoadDeliveryState(GameSystem *gameSystem, TrialHouseWork *work);
void TRIAL_HOUSE_DeleteWork(GameSystem *gameSystem, TrialHouseWork **slot);
void TRIAL_HOUSE_SetBattleMode(TrialHouseWork *work, u32 mode);
void TRIAL_HOUSE_SetUseDeliveredTrainers(TrialHouseWork *work, int useDeliveredTrainers);
u16 TRIAL_HOUSE_LoadTrainer(GameSystem *gameSystem, TrialHouseWork *work, u32 index);
void TRIAL_HOUSE_BuildTrainerFromMode(TrialHouseWork *work, u32 mode);
void TRIAL_HOUSE_LoadDeliveredTrainer(GameSystem *gameSystem, BtlInstTrainer *dst, int index);
u16 TRIAL_HOUSE_GetTrainerObjCode(TrialHouseWork *work);
GameEvent *TRIAL_HOUSE_CreateTrainerMsgEvent(GameSystem *gameSystem, TrialHouseWork *work, u32 index, u32 mmdlId);
GameEvent *TRIAL_HOUSE_CreateDeliveryTask(GameSystem *gameSystem, TrialHouseWork *work, u16 *result);
int TRIAL_HOUSE_DeliveryTaskMain(GameEvent *event, u32 *seq, void *work);
void TRIAL_HOUSE_ComputeScoreAndRank(GameSystem *gameSystem, TrialHouseWork *work, u16 *outRank, u16 *outScore);
int TRIAL_HOUSE_GetDeliveryState(struct GameSystem *unused, TrialHouseWork *work);
GameEvent *TRIAL_HOUSE_CreateSaveTask(GameSystem *gameSystem, struct TrialHouseWork *unused, int mode);
int TRIAL_HOUSE_GetRecordSlotsState(GameSystem *gameSystem);
u8 TRIAL_HOUSE_IsDeliveryIdReceived(TrialHouseSave *save, u32 id);
void TRIAL_HOUSE_MarkDeliveryIdReceived(TrialHouseSave *save, u32 id);
int TRIAL_HOUSE_SaveTaskMain(GameEvent *event, u32 *seq, void *work);

extern char d_021DE674[];                              /* source file name for the heap allocator */
extern u8 GAME_LANGUAGE_Code;                                  /* game version of this ROM */

/* ------------------------------------------------------------------ */
/* trial_house.c                                                       */
/* ------------------------------------------------------------------ */

/*
 * Callee witnesses filed in wave A1 (witness lane).
 */
TrialHouseWork *TRIAL_HOUSE_CreateWork(GameSystem *gameSystem)
{
    TrialHouseWork *work;
    u32 deliverySize;

    deliverySize = BATTLE_EXAMINATION_GetBlockSize();
    GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem)); /* result unused in the original */
    work = GFL_HEAP_Alloc(TRIAL_HOUSE_HEAP_ID, sizeof(TrialHouseWork), 1, d_021DE674, 0x5D);
    work->heapId = TRIAL_HOUSE_HEAP_ID;
    work->delivery = GFL_HEAP_Alloc(TRIAL_HOUSE_HEAP_ID, deliverySize, 1, d_021DE674, 0x5F);
    TRIAL_HOUSE_LoadDeliveryState(gameSystem, work);
    work->playerParty = POKEPARTY_Create(work->heapId);
    return work;
}

/* Reads the delivered trainers of the save and stores their state in the work. */
void TRIAL_HOUSE_LoadDeliveryState(GameSystem *gameSystem, TrialHouseWork *work)
{
    int state;
    TrialHouseDelivery *delivery;
    SaveControl *saveControl;
    void *buf;

    saveControl = GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem));
    buf = GFL_HEAP_Alloc(TRIAL_HOUSE_SAVE_HEAP_ID, TRIAL_HOUSE_SAVE_BUF_SIZE, 1, d_021DE674, 0x79);
    SAVE_CONTROL_LoadExtraSaveWithBuffer(saveControl, TRIAL_HOUSE_SAVE_BLOCK, TRIAL_HOUSE_SAVE_HEAP_ID, buf, TRIAL_HOUSE_SAVE_BUF_SIZE);
    state = TRIAL_HOUSE_DELIVERY_NONE;
    delivery = SAVE_CONTROL_GetExtraSaveRecord(saveControl, TRIAL_HOUSE_SAVE_BLOCK, 0);
    if (BATTLE_EXAMINATION_IsDeliveryValid(delivery)) {
        int notUsed = BATTLE_EXAMINATION_IsDeliveryUnused(delivery);
        state = TRIAL_HOUSE_DELIVERY_FRESH;
        if (notUsed == 0) {
            state = TRIAL_HOUSE_DELIVERY_USED;
        }
    }
    SAVE_CONTROL_DeleteExtraSaveBuffered(saveControl, TRIAL_HOUSE_SAVE_BLOCK);
    GFL_HEAP_Free(buf);
    work->deliveryState = state;
}

void TRIAL_HOUSE_DeleteWork(GameSystem *gameSystem, TrialHouseWork **slot)
{
    if (*slot != 0) {
        GFL_HEAP_Free((*slot)->delivery);
        GFL_HEAP_Free((*slot)->playerParty);
        GFL_HEAP_Free(*slot);
        *slot = 0;
    }
}

/*
 * The 0x124 store is written in each arm of the mode test (cross-jumped
 * into one tail) and the 0x12C store after it: that puts the two stores in
 * different blocks when constants are derived, so the second offset is
 * rematerialised (`movs #0x4b; lsls`) instead of `adds r0,#8`.
 * Extent runs into TRIAL_HOUSE_SetUseDeliveredTrainers (filed separately).
 */
void TRIAL_HOUSE_SetBattleMode(TrialHouseWork *work, u32 mode)
{
    if (work == 0) {
        return;
    }
    if (mode <= 1) {
        int battleMode;
        if (mode == 0) {
            battleMode = 0;
            work->monCount = 3;
        } else {
            battleMode = 1;
            work->monCount = 4;
        }
        work->battleMode = battleMode;
    } else {
        work->battleMode = 0;
        work->monCount = 3;
    }
    POKEPARTY_InitEx(work->playerParty, work->monCount);
}

/*
 * Unlabelled ov021 leaf hidden in a word run: stores the second argument at
 * +0x130 of the first.  Matched to supply the `matched` witness for the
 * pending ov010 caller SCRCMD_TRIALHOUSE_SetRecordSource.
 */
void TRIAL_HOUSE_SetUseDeliveredTrainers(TrialHouseWork *work, int useDeliveredTrainers)
{
    work->useDeliveredTrainers = useDeliveredTrainers;
}

u16 TRIAL_HOUSE_LoadTrainer(GameSystem *gameSystem, TrialHouseWork *work, u32 index)
{
    if (work->useDeliveredTrainers != 0) {
        TRIAL_HOUSE_LoadDeliveredTrainer(gameSystem, &work->trainer, index);
    } else {
        TRIAL_HOUSE_BuildTrainerFromMode(work, index);
    }
    return TRIAL_HOUSE_GetTrainerObjCode(work);
}

/* Draws a trainer of the built-in list: the tier is the mode, the trainer is random within it. */
void TRIAL_HOUSE_BuildTrainerFromMode(TrialHouseWork *work, u32 mode)
{
    int firstIndex;
    int count;
    int trainerIndex;
    u16 heapId;

    switch (mode) {
    case 0:
        firstIndex = 0x32;
        count = 0x14;
        break;
    case 1:
        firstIndex = 0x6E;
        count = 0x32;
        break;
    case 2:
        firstIndex = 0xA0;
        count = 0x14;
        break;
    case 3:
        firstIndex = 0xF0;
        count = 0x1E;
        break;
    case 4:
        firstIndex = 0x10E;
        count = 0x1E;
        break;
    default:
        firstIndex = 0x32;
        count = 0x14;
        break;
    }
    trainerIndex = firstIndex + GFL_USE_GetRandom(count);
    heapId = work->heapId;
    FLD_BTL_INST_TOOL_CreateTrainer(&work->trainer, (u16)trainerIndex, work->monCount, 0, 0, 0, (heapId & 0x7FFF) | 0x8000);
}

/* Copies one delivered trainer into the work. */
void TRIAL_HOUSE_LoadDeliveredTrainer(GameSystem *gameSystem, BtlInstTrainer *dst, int index)
{
    SaveControl *saveControl;
    void *buf;

    saveControl = GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem));
    buf = GFL_HEAP_Alloc(TRIAL_HOUSE_SAVE_HEAP_ID, TRIAL_HOUSE_SAVE_BUF_SIZE, 1, d_021DE674, 0x14C);
    if (SAVE_CONTROL_LoadExtraSaveWithBuffer(saveControl, TRIAL_HOUSE_SAVE_BLOCK, TRIAL_HOUSE_SAVE_HEAP_ID, buf, TRIAL_HOUSE_SAVE_BUF_SIZE) == 1) {
        *dst = *BATTLE_EXAMINATION_GetTrainerSlot(SAVE_CONTROL_GetExtraSaveRecord(saveControl, TRIAL_HOUSE_SAVE_BLOCK, 0), index);
    }
    SAVE_CONTROL_DeleteExtraSaveBuffered(saveControl, TRIAL_HOUSE_SAVE_BLOCK);
    GFL_HEAP_Free(buf);
}

/*
 * Unblocked by matching FLD_BTL_INST_TOOL_LookupKeyValue (ov010, EXACT): the +0008 ABS32 site now
 * attests as `matched`.
 */
u16 TRIAL_HOUSE_GetTrainerObjCode(TrialHouseWork *work)
{
    return FLD_BTL_INST_TOOL_LookupKeyValue(work->trainer.trainerType);
}

/* Starts the message event of the trainer. */
GameEvent *TRIAL_HOUSE_CreateTrainerMsgEvent(GameSystem *gameSystem, TrialHouseWork *work, u32 index, u32 mmdlId)
{
    return FLD_BTL_INST_TOOL_CreateTrainerMsgEvent(gameSystem, &work->trainer, index, (u16)mmdlId);
}

/* Starts the task that receives trainers by wireless delivery; the result is written to *result. */
GameEvent *TRIAL_HOUSE_CreateDeliveryTask(GameSystem *gameSystem, TrialHouseWork *work, u16 *result)
{
    GameEvent *event;
    TrialHouseDeliveryTaskWork *task;

    event = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)TRIAL_HOUSE_DeliveryTaskMain, sizeof(TrialHouseDeliveryTaskWork));
    task = GAME_EVENT_GetWork(event);
    task->gameSystem = gameSystem;
    task->result = result;
    task->trialHouse = work;
    task->waitFrames = 0;
    task->param.gameKind = TRIAL_HOUSE_DELIVERY_GAME_KIND;
    task->param.destSize = BATTLE_EXAMINATION_GetBlockSize();
    task->param.dest = work->delivery;
    task->param.gameVersion = GAME_LANGUAGE_Code;
    task->param.acceptMask = TRIAL_HOUSE_DELIVERY_ACCEPT_MASK;
    task->param.pageCount = 1;
    task->param.reserved04 = 0;
    task->param.heapId = TRIAL_HOUSE_DELIVERY_HEAP_ID;
    return event;
}

/*
 * Delivery task: searches for a sender, waits for the pieces, checks the data
 * and writes it to the save.
 *
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * Addresses are Black-image addresses.
 */
int TRIAL_HOUSE_DeliveryTaskMain(GameEvent *event, u32 *seq, void *work)
{
    TrialHouseDeliveryTaskWork *task = work;
    GameSystem *gameSystem;
    GameData *gameData;
    SaveControl *saveControl;
    TrialHouseSave *save;
    TrialHouseDelivery *delivery;
    int deliveryId, isValid, isKnown;

    gameSystem = task->gameSystem;
    switch (*seq) {
    case 0:
        task->beacon = DELIVERY_BEACON_Create((struct DeliveryBeaconParam *)(&task->param));
        if (DELIVERY_BEACON_Start(task->beacon) == 0) {
            *task->result = TRIAL_HOUSE_DELIVERY_RESULT_FAILED;
            *seq = 4;
        } else {
            *seq = 1;
        }
        break;
    case 1:
        if (KEY_GetTrg() == 2) {
            *task->result = TRIAL_HOUSE_DELIVERY_RESULT_NET_ERROR;
            *seq = 4;
            break;
        }
        DELIVERY_BEACON_RunStep(task->beacon);
        if (++task->waitFrames > TRIAL_HOUSE_DELIVERY_WAIT_FRAMES) {
            *seq = 2;
        }
        break;
    case 2:
        if (KEY_GetTrg() == 2) {
            *task->result = TRIAL_HOUSE_DELIVERY_RESULT_NET_ERROR;
            *seq = 4;
            break;
        }
        DELIVERY_BEACON_RunStep(task->beacon);
        if (DELIVERY_BEACON_HasAnyPiece(task->beacon)) {
            *seq = 3;
        } else {
            *task->result = TRIAL_HOUSE_DELIVERY_RESULT_FAILED;
            *seq = 4;
        }
        break;
    case 3:
        if (KEY_GetTrg() == 2) {
            *task->result = TRIAL_HOUSE_DELIVERY_RESULT_NET_ERROR;
            *seq = 4;
            break;
        }
        DELIVERY_BEACON_RunStep(task->beacon);
        if (DELIVERY_BEACON_TryComplete(task->beacon) == 0) {
            break;
        }
        gameData = GAMESYSTEM_GetGameData(gameSystem);
        saveControl = GAME_DATA_GetSaveControl(gameData);
        save = TRIAL_HOUSE_SAVE_GetFromSave(saveControl);
        delivery = task->trialHouse->delivery;
        deliveryId = BATTLE_EXAMINATION_GetDeliveryId(delivery);
        isValid = BATTLE_EXAMINATION_IsDeliveryValid(delivery);
        isKnown = TRIAL_HOUSE_IsDeliveryIdReceived(save, deliveryId);
        if (isValid != 0 && (isKnown == 0 || deliveryId == 0)) {
            TRIAL_HOUSE_MarkDeliveryIdReceived(save, deliveryId);
            BATTLE_EXAMINATION_LoadDelivery(gameData, task->trialHouse->delivery, TRIAL_HOUSE_SAVE_HEAP_ID);
            *task->result = TRIAL_HOUSE_DELIVERY_RESULT_RECEIVED;
        } else if (isKnown != 0) {
            *task->result = TRIAL_HOUSE_DELIVERY_RESULT_KNOWN;
        } else {
            *task->result = TRIAL_HOUSE_DELIVERY_RESULT_FAILED;
        }
        *seq = 4;
        break;
    case 4:
        DELIVERY_BEACON_Delete(task->beacon);
        *seq = 5;
        break;
    case 5:
        if (GFL_NET_IsIdle()) {
            *seq = 6;
        }
        break;
    case 6:
        TRIAL_HOUSE_LoadDeliveryState(gameSystem, task->trialHouse);
        return 1;
    }
    return 0;
}

/*
 * The listing extent (568 B) runs over the unlabelled 8-byte follower leaf
 * at 0x021D0FE0 (return *(u32 *)(r1 + 0x150)); the function is 560 B.
 * score is u32 with (int) casts on the clamp (signed clamp, unsigned rank
 * ladder); that and the saveControl, score, save, rank declaration order give
 * the stack slots.
 *
 * Addresses are Black-image addresses.
 */
void TRIAL_HOUSE_ComputeScoreAndRank(GameSystem *gameSystem, TrialHouseWork *work, u16 *outRank, u16 *outScore)
{
    TrialHouseTally *tally;
    SaveControl *saveControl;
    u32 score;
    TrialHouseSave *save;
    u32 rank;
    TrialHouseSaveSlot *slot;
    int i;
    TrialHouseSaveMon *saveMon;
    void *mon;
    SaveControl *saveControl2;
    void *buf;
    RecordBlock *record;

    tally = &work->tally;
    score = 0;
    score += tally->tally[7] * 1000;
    score += tally->tally[8] * 80;
    score += tally->tally[1] * 5;
    score += tally->tally[3];
    score += tally->tally[5] * 5;
    score += tally->tally[6] * 2;
    score += tally->lastTally * 15;
    score -= tally->tally[0] * 10;
    score -= tally->tally[2] * 10;
    score -= tally->tally[4] * 2;
    score -= tally->tally[9] * 80;
    score -= 500 - tally->scoreShare;
    if ((int)score < 0) {
        score = 0;
    } else if ((int)score > 9999) {
        score = 9999;
    }

    if (score >= 6000) {
        rank = 6;
    } else if (score >= 5000) {
        rank = 5;
    } else if (score >= 4000) {
        rank = 4;
    } else if (score >= 3000) {
        rank = 3;
    } else if (score >= 2000) {
        rank = 2;
    } else if (score >= 1000) {
        rank = 1;
    } else {
        rank = 0;
    }
    *outRank = rank;
    *outScore = score;

    saveControl = GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem));
    save = TRIAL_HOUSE_SAVE_GetFromSave(saveControl);
    slot = &save->slot[(u8)(work->deliveryState != 0)];
    slot->valid = 1;
    if (work->monCount == 3) {
        slot->battleMode = 0;
    } else if (work->monCount == 4) {
        slot->battleMode = 1;
    } else {
        slot->battleMode = 0;
    }
    slot->score = score;
    MI_CpuFill8(slot->mons, 0, sizeof(slot->mons));
    for (i = 0; i < work->monCount; i++) {
        saveMon = &slot->mons[i];
        mon = POKEPARTY_GetMember(work->playerParty, i);
        saveMon->species = POKE_TOOL_GetPartyValue(mon, 5, 0);
        saveMon->form = POKE_TOOL_GetPartyValue(mon, 0x6f, 0);
        saveMon->gender = POKE_TOOL_GetPartyValue(mon, 0x6e, 0);
    }

    if (work->deliveryState != 0) {
        saveControl2 = GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem));
        buf = GFL_HEAP_Alloc(TRIAL_HOUSE_SAVE_HEAP_ID, TRIAL_HOUSE_SAVE_BUF_SIZE, 1, d_021DE674, 0x277);
        if (SAVE_CONTROL_LoadExtraSaveWithBuffer(saveControl2, TRIAL_HOUSE_SAVE_BLOCK, TRIAL_HOUSE_SAVE_HEAP_ID, buf, TRIAL_HOUSE_SAVE_BUF_SIZE) == 1) {
            MI_CpuCopy8(SAVE_CONTROL_GetExtraSaveRecord(saveControl2, TRIAL_HOUSE_SAVE_BLOCK, 0)->profile, save->profile, sizeof(save->profile));
        }
        GFL_HEAP_Free(buf);
        SAVE_CONTROL_DeleteExtraSaveBuffered(saveControl2, TRIAL_HOUSE_SAVE_BLOCK);
    }

    record = RECORD_GetFromSave(saveControl);
    RECORD_SetTrialScore(record, score);
    RECORD_SetTrialRank(record, (u8)rank);
}

/*
 * Unlabelled ov021 leaf hidden in a word run: returns the word at +0x150 of
 * its pointer argument (the second argument register).  Matched to supply the
 * `matched` witness for the pending ov010 caller SCRCMD_TRIALHOUSE_GetSaveState.
 */
int TRIAL_HOUSE_GetDeliveryState(struct GameSystem *unused, TrialHouseWork *work)
{
    return work->deliveryState;
}

/* Starts the task that writes the delivered data to the save (mode 1: mark it used, else erase it). */
GameEvent *TRIAL_HOUSE_CreateSaveTask(GameSystem *gameSystem, struct TrialHouseWork *unused, int mode)
{
    GameEvent *event;
    TrialHouseSaveTaskWork *task;
    FieldSaveAnime *saveAnime;

    event = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)TRIAL_HOUSE_SaveTaskMain, sizeof(TrialHouseSaveTaskWork));
    task = GAME_EVENT_GetWork(event);
    task->gameSystem = gameSystem;
    task->buffer = 0;
    task->mode = mode;
    saveAnime = FIELD_SAVEANIME_Create(0x8015, GAMESYSTEM_GetFieldMap(gameSystem));
    task->saveAnime = saveAnime;
    FIELD_SAVEANIME_Start(saveAnime);
    return event;
}

/* Returns a bit mask of the saved results: bit 0 = first slot, bit 1 = second slot. */
int TRIAL_HOUSE_GetRecordSlotsState(GameSystem *gameSystem)
{
    TrialHouseSave *save = TRIAL_HOUSE_SAVE_GetFromSave(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem)));

    if (save->slot[0].valid != 0) {
        if (save->slot[1].valid != 0) {
            return 3;
        }
        return 1;
    }
    if (save->slot[1].valid != 0) {
        return 2;
    }
    return 0;
}

/* Whether a delivery id was received before; ids out of range count as received. */
u8 TRIAL_HOUSE_IsDeliveryIdReceived(TrialHouseSave *save, u32 id)
{
    if (id < TRIAL_HOUSE_DELIVERY_ID_COUNT) {
        return (save->receivedIds[(u8)(id >> 3)] >> (u8)(id & 7)) & 1;
    }
    return 1;
}

/*
 * Bit set in the 128-bit field at +0x28, ignoring out-of-range indices.
 * Region ov021 for the same reason as TRIAL_HOUSE_IsDeliveryIdReceived (wave A1 witness).
 * Addresses are Black-image addresses.
 */
void TRIAL_HOUSE_MarkDeliveryIdReceived(TrialHouseSave *save, u32 id)
{
    if (id < TRIAL_HOUSE_DELIVERY_ID_COUNT) {
        save->receivedIds[(u8)(id >> 3)] |= (u8)(1 << (u8)(id & 7));
    }
}

/* Save task: writes save block 5 and shows the save animation until it is done. */
int TRIAL_HOUSE_SaveTaskMain(GameEvent *event, u32 *seq, void *work)
{
    TrialHouseSaveTaskWork *task = work;
    GameData *gameData = GAMESYSTEM_GetGameData(task->gameSystem);
    SaveControl *saveControl = GAME_DATA_GetSaveControl(gameData);
    TrialHouseDelivery *delivery;

    switch (*seq) {
    case 0:
        task->buffer = GFL_HEAP_Alloc(TRIAL_HOUSE_SAVE_HEAP_ID, TRIAL_HOUSE_SAVE_BUF_SIZE, 0, d_021DE674, 0x34C);
        SAVE_CONTROL_LoadExtraSaveWithBuffer(saveControl, TRIAL_HOUSE_SAVE_BLOCK, TRIAL_HOUSE_SAVE_HEAP_ID, task->buffer, TRIAL_HOUSE_SAVE_BUF_SIZE);
        delivery = SAVE_CONTROL_GetExtraSaveRecord(saveControl, TRIAL_HOUSE_SAVE_BLOCK, 0);
        if (task->mode == 1) {
            BATTLE_EXAMINATION_RefreshMarker(delivery);
        } else {
            MI_CpuFill8(delivery, 0, BATTLE_EXAMINATION_GetBlockSize());
        }
        GAME_DATA_PartSaveStart(gameData, TRIAL_HOUSE_SAVE_BLOCK);
        *seq = *seq + 1;
        break;
    case 1:
        if (GAME_DATA_PartSaveMain(gameData, TRIAL_HOUSE_SAVE_BLOCK) == 2) {
            SAVE_CONTROL_DeleteExtraSaveBuffered(saveControl, TRIAL_HOUSE_SAVE_BLOCK);
            GFL_HEAP_Free(task->buffer);
            FIELD_SAVEANIME_Stop(task->saveAnime);
            FIELD_SAVEANIME_Delete(task->saveAnime);
            return 1;
        }
        break;
    }
    return 0;
}
