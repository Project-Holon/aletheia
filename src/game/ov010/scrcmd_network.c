/*
 * file:     scrcmd_network.c
 * unit:     yes
 * function: SCRCMD_NETWORK_WaitCommState, SCRCMD_NETWORK_CmdWaitCommState, SCRCMD_NETWORK_CmdGetCommValue, SCRCMD_NETWORK_CmdStartAutoComm, SCRCMD_NETWORK_CmdRequestCommExit, SCRCMD_NETWORK_CmdRestartAutoComm, SCRCMD_NETWORK_CmdUnblockComm, SCRCMD_NETWORK_CmdGetAlwaysNet, SCRCMD_NETWORK_CmdClearAlwaysNet, SCRCMD_NETWORK_CmdLoadNpcTable, SCRCMD_NETWORK_CmdFreeNpcTable, SCRCMD_NETWORK_CmdSetNpcEventFromTable, SCRCMD_NETWORK_CmdSetNpcEventPairFromTable, SCRCMD_NETWORK_CmdSetNpcTripleFromTable, SCRCMD_NETWORK_CmdApplyTableEventKeys, SCRCMD_NETWORK_PickSixDistinctRandom, SCRCMD_NETWORK_FindNpcTableRow, SCRCMD_NETWORK_HasSituationWarpChanged, SCRCMD_NETWORK_CommProcEventMain, SCRCMD_NETWORK_CreateCommProcEvent
 * address:  0x0215F168
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from scrcmd_network.c by tools/splitfile.py.
 *
 * symbols:
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   SCRIPT_WORK_GetUserWorkPtr  0x02158FB4  thumb  ov010
 *   FIELDMAP_CheckCommExit  0x02189734  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   SCRCMD_NETWORK_sFileName     0x0217294C  data  ov010  a4
 *   VM_SetWait  0x020113D0  thumb
 *   APP_ENV_IsWirelessAvailable  0x0202EB44  thumb
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAMESYSTEM_SetCommBlocked  0x0201213C  thumb
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 *   SCRIPT_WORK_ResetCheckFlag   0x02159168  thumb  ov010
 *   GAMESYSTEM_IsAlwaysNetFlagSet  0x0201214C  thumb
 *   GAMESYSTEM_SetAlwaysNetFlag 0x02012158 thumb
 *   ARC_UTIL_LoadMember 0x0204A1BC arm
 *   SCRIPT_WORK_SetReturnFlag 0x02159114 thumb ov010
 *   SCRIPT_WORK_GetReturnFlag  0x0215911C  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENT_TRAINER_GetPrimaryScriptId  0x0215A480  thumb  ov010
 *   EVENTDATA_SYSTEM_SetNpcEventId  0x02162788  thumb  ov010
 *   EVENT_TRAINER_GetSecondaryScriptId  0x0215A490  thumb  ov010
 *   EVENTDATA_SYSTEM_SetNpcObjCode  0x02162774  thumb  ov010
 *   SCRIPT_WORK_GetGameSystem 0x02158F54 thumb ov010
 *   EVENT_TRAINER_ClearDefeatedFlag 0x0215A500 thumb ov010
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   MAP_REPLACE_GetDefaultWarpId 0x02159F80 thumb ov010
 *   GAME_DATA_GetSituationWarpId 0x02012914 thumb
 *   BRIGHTNESS_Set  0x02023F60  thumb
 *   GAME_EVENT_CallProc  0x02012444  thumb
 *   d_021B9EC0     0x021B9EC0  data  a4
 *   ov_id_00CD     0x000000CD  data  a1
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_DATA_GetEventState  0x02012ED0  thumb
 *   SYMBOL_MAP_DeleteLinkRecord  0x021666A4  thumb  ov010
 *   EVENT_WIFI_PROC_LoadOv020Task 0x0215FA1C thumb ov010
 */
#include "../arm9/script_vm_types.h"
#include "scrcmd_network_shared_types.h"

struct ScriptWork;

struct ScriptCtl;

struct EventDataSystem;

struct EventWork;

typedef signed short s16;

typedef enum { FALSE, TRUE } BOOL;

/* Wait callback of a script command: receives the script work as user data. */
typedef int (*ScriptWorkWaitFn)(ScriptVm *vm, struct ScriptWork *scriptWork);

/* Heap block behind the script command "wait for the comm state". */
typedef struct CommWaitWork {
    u16 *resultVar;     /* 0x00: script variable that receives 2 when the state is 2 */
} CommWaitWork;

/*
 * One row of the 0x6B-row table in archive member 0xD1 (8 bytes). A row is
 * found by its two keys; the other two fields feed the NPC records of the
 * event data.
 */
#define NPC_TABLE_ROW_COUNT 0x6B

typedef struct NpcTableRow {
    u16 keyA;           /* 0x00 */
    u16 keyB;           /* 0x02 */
    u16 objCode;        /* 0x04: stored as is in the NPC record */
    u16 eventKey;       /* 0x06: converted to the NPC event ids */
} NpcTableRow;

/* Work of the event that starts a comm session from the field (0xC bytes). */
typedef struct CommProcEventWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    int warpChanged;                /* 0x04: selects the script id */
    struct MyStatus *myStatus;      /* 0x08 */
} CommProcEventWork;
struct ScrcmdWork;

/* script work (ov010) */
extern struct GameSystem *SCRCMD_WORK_GetGameSystem(struct ScrcmdWork *work);

extern struct ScriptWork *SCRCMD_WORK_GetScriptWork(struct ScrcmdWork *work);
struct GameData;

extern struct GameData *SCRCMD_WORK_GetGameData(struct ScrcmdWork *work);

extern u16 *SCRIPT_WORK_ReadWorkPointer(ScriptVm *vm, struct ScriptWork *scriptWork);
struct ScriptVm;

extern u32 SCRIPT_WORK_ReadWorkValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

extern CommWaitWork **SCRIPT_WORK_GetUserWorkPtr(struct ScriptCtl *scriptCtl);

extern void *SCRIPT_WORK_GetGameSystem(struct ScriptWork *work);

extern struct ScriptWork *SCRIPT_WORK_SetReturnFlag(struct ScriptWork *work, unsigned int flag);

extern unsigned int SCRIPT_WORK_GetReturnFlag(struct ScriptWork *work);

extern void SCRIPT_WORK_SetCheckFlag(int flagNo);

extern void SCRIPT_WORK_ResetCheckFlag(int flagNo);

extern void EVENT_TRAINER_ClearDefeatedFlag(char *flagSet, unsigned int flagOffset);

extern u16 EVENT_TRAINER_GetPrimaryScriptId(unsigned eventKey);

extern u16 EVENT_TRAINER_GetSecondaryScriptId(unsigned eventKey);

extern int MAP_REPLACE_GetDefaultWarpId(void);

extern void *SCRIPT_SYS_CallScriptEvent(void *parentEvent, unsigned short scriptId, void *target, void *parentWork, unsigned short reserved);

extern void EVENTDATA_SYSTEM_SetNpcEventId(struct EventDataSystem *eventData, unsigned slot, u16 eventId);

extern void EVENTDATA_SYSTEM_SetNpcObjCode(struct EventDataSystem *eventData, unsigned slot, u16 objCode);

/* script virtual machine */
extern void VM_SetWait(ScriptVm *vm, ScriptWorkWaitFn waitFn);

/* game system, game event, game data */
extern struct GameEvent *GAME_EVENT_Create(struct GameSystem *gameSystem, struct GameEvent *parent, EventTaskFn taskFn, unsigned int workSize);

extern void *GAME_EVENT_GetWork(struct GameEvent *event);

extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);

extern void GAME_EVENT_CallProc(struct GameEvent *event, u32 overlayId, const void *procData, void *procArg);

extern struct GameData *GAMESYSTEM_GetGameData(struct GameSystem *gameSystem);

extern struct FieldMap *GAMESYSTEM_GetFieldMap(struct GameSystem *gameSystem);

extern struct GameComm *GAMESYSTEM_GetGameComm(struct GameSystem *gameSystem);

extern void GAMESYSTEM_SetCommBlocked(struct GameSystem *gameSystem, u32 commBlocked);

extern u32 GAMESYSTEM_IsAlwaysNetFlagSet(struct GameSystem *gameSystem);

extern void GAMESYSTEM_SetAlwaysNetFlag(struct GameSystem *gameSystem, u32 alwaysNet);

extern u32 GAMESYSTEM_TryStartAutoComm(struct GameSystem *gameSystem);

extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gameData);

extern void *GAME_DATA_GetEventData(struct GameData *gameData);

extern void *GAME_DATA_GetEventWork(struct GameData *gameData);

extern u16 GAME_DATA_GetSituationWarpId(struct GameData *gameData);

extern unsigned char *GAME_DATA_GetEventState(struct GameData *gameData);

/* game comm, config, misc */
extern u32 GAME_COMM_GetKind(struct GameComm *gameComm);

extern void GAME_COMM_RequestExitNoCallback(struct GameComm *gameComm);

extern int FIELDMAP_CheckCommExit(struct GameComm *gameComm);

extern int APP_ENV_IsWirelessAvailable(void);

/* heap, archive, random, overlays, memory */
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *ptr);

extern int ARC_UTIL_LoadMember(int archiveID, int memberIdx, int decompress, unsigned short heapID);

extern u32 GFL_USE_GetRandom(u32 range);

/* screen, sound */
extern void BRIGHTNESS_Set(unsigned int brightness, unsigned int plane, unsigned int mask);
struct SymbolMapOwner;

extern void SYMBOL_MAP_DeleteLinkRecord(struct SymbolMapOwner *owner);

extern const char SCRCMD_NETWORK_sFileName[];

extern u8 d_021B9EC0[];

extern u8 ov_id_00CD[];

int SCRCMD_NETWORK_WaitCommState(ScriptVm *vm, struct ScriptWork *scriptWork);

int SCRCMD_NETWORK_CmdWaitCommState(ScriptVm *vm, struct ScriptWork *scriptWork);

int SCRCMD_NETWORK_CmdGetCommValue(ScriptVm *vm, struct ScriptWork *scriptWork);

int SCRCMD_NETWORK_CmdStartAutoComm(ScriptVm *vm, struct ScriptWork *scriptWork);

int SCRCMD_NETWORK_CmdRequestCommExit(ScriptVm *vm, struct ScriptWork *scriptWork);

int SCRCMD_NETWORK_CmdRestartAutoComm(ScriptVm *vm, struct ScriptWork *scriptWork);

int SCRCMD_NETWORK_CmdUnblockComm(struct GameSystem **gameSystemRef, void *unused);

int SCRCMD_NETWORK_CmdGetAlwaysNet(ScriptVm *vm, struct ScriptWork *scriptWork);

int SCRCMD_NETWORK_CmdClearAlwaysNet(ScriptVm *vm, struct ScriptWork *scriptWork);

int SCRCMD_NETWORK_CmdLoadNpcTable(ScriptVm *vm, struct ScriptWork *scriptWork);

int SCRCMD_NETWORK_CmdFreeNpcTable(ScriptVm *vm, struct ScriptWork *scriptWork);

int SCRCMD_NETWORK_CmdSetNpcEventFromTable(ScriptVm *vm, struct ScriptWork *scriptWork);

int SCRCMD_NETWORK_CmdSetNpcEventPairFromTable(ScriptVm *vm, struct ScriptWork *scriptWork);

int SCRCMD_NETWORK_CmdSetNpcTripleFromTable(ScriptVm *vm, struct ScriptWork *scriptWork);

int SCRCMD_NETWORK_CmdApplyTableEventKeys(ScriptVm *vm, struct ScriptWork *scriptWork);

int SCRCMD_NETWORK_PickSixDistinctRandom(ScriptVm *vm, struct ScriptWork *scriptWork);

int SCRCMD_NETWORK_FindNpcTableRow(const NpcTableRow *table, int keyA, int keyB);

BOOL SCRCMD_NETWORK_HasSituationWarpChanged(struct GameData *gameData);

int SCRCMD_NETWORK_CommProcEventMain(struct GameEvent *event, u32 *seq, void *workArg);

struct GameEvent *SCRCMD_NETWORK_CreateCommProcEvent(struct GameSystem *gameSystem);

struct GameEvent *EVENT_WIFI_PROC_LoadOv020Task(struct GameSystem *gameSystem);

/*
 * Wait callback of the "wait for the comm state" command: state 0 keeps
 * waiting, state 1 ends the wait, state 2 ends it and stores 2 in the
 * result variable.
 */
int SCRCMD_NETWORK_WaitCommState(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)scriptWork);
    struct ScriptCtl *scriptCtl = (struct ScriptCtl *)SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)scriptWork);
    struct GameComm *gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    CommWaitWork *waitWork;

    GAMESYSTEM_GetFieldMap(gameSystem);
    waitWork = *SCRIPT_WORK_GetUserWorkPtr(scriptCtl);
    switch (FIELDMAP_CheckCommExit(gameComm)) {
    case 0:
        return 0;
    case 1:
        GFL_HEAP_Free(waitWork);
        return 1;
    case 2:
        *waitWork->resultVar = 2;
        GFL_HEAP_Free(waitWork);
        return 1;
    default:
        return 0;
    }
}

int SCRCMD_NETWORK_CmdWaitCommState(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    CommWaitWork **slot;
    u16 *resultVar;
    CommWaitWork *waitWork;

    slot = SCRIPT_WORK_GetUserWorkPtr((struct ScriptCtl *)SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)scriptWork));
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    waitWork = GFL_HEAP_Alloc(4, 4, 1, SCRCMD_NETWORK_sFileName, 0x63);
    *slot = waitWork;
    waitWork->resultVar = resultVar;
    *resultVar = 0;
    VM_SetWait(vm, SCRCMD_NETWORK_WaitCommState);
    return 1;
}

int SCRCMD_NETWORK_CmdGetCommValue(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);

    *resultVar = APP_ENV_IsWirelessAvailable();
    return 0;
}

int SCRCMD_NETWORK_CmdStartAutoComm(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)scriptWork);

    GAMESYSTEM_TryStartAutoComm(gameSystem);
    return 1;
}

int SCRCMD_NETWORK_CmdRequestCommExit(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct GameSystem *gameSystem;
    struct GameComm *gameComm;

    gameSystem = SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)scriptWork);
    gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    switch (GAME_COMM_GetKind(gameComm)) {
    case 1:
    case 2:
    case 5:
        GAME_COMM_RequestExitNoCallback(gameComm);
        break;
    case 0:
    case 3:
    case 4:
        break;
    }
    GAMESYSTEM_SetCommBlocked(gameSystem, 1);
    SCRIPT_WORK_SetCheckFlag(0xb);
    return 1;
}

int SCRCMD_NETWORK_CmdRestartAutoComm(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)scriptWork);

    GAMESYSTEM_SetCommBlocked(gameSystem, 0);
    GAMESYSTEM_TryStartAutoComm(gameSystem);
    SCRIPT_WORK_ResetCheckFlag(0xB);

    return 1;
}

/* Callback that takes a cell holding the game system. */
int SCRCMD_NETWORK_CmdUnblockComm(struct GameSystem **gameSystemRef, void *unused)
{
    struct GameSystem *gameSystem = *gameSystemRef;

    GAMESYSTEM_SetCommBlocked(gameSystem, 0);
    GAMESYSTEM_TryStartAutoComm(gameSystem);
    return 1;
}

int SCRCMD_NETWORK_CmdGetAlwaysNet(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct GameSystem *gameSystem;
    u16 *resultVar;

    gameSystem = SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)scriptWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    *resultVar = GAMESYSTEM_IsAlwaysNetFlagSet(gameSystem);
    return 0;
}

int SCRCMD_NETWORK_CmdClearAlwaysNet(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    GAMESYSTEM_SetAlwaysNetFlag(SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)scriptWork), 0);
    return 0;
}

/* Loads archive member 0xD1 (the NpcTableRow table) into the script control. */
int SCRCMD_NETWORK_CmdLoadNpcTable(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl = (struct ScriptCtl *)SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)scriptWork);

    SCRIPT_WORK_SetReturnFlag((struct ScriptWork *)scriptCtl, (unsigned int)ARC_UTIL_LoadMember(0xd1, 0, 0, 0x8004));
    return 0;
}

int SCRCMD_NETWORK_CmdFreeNpcTable(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl = (struct ScriptCtl *)SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)scriptWork);
    void *table = (void *)SCRIPT_WORK_GetReturnFlag((struct ScriptWork *)scriptCtl);

    if (table != 0) {
        GFL_HEAP_Free(table);
        SCRIPT_WORK_SetReturnFlag((struct ScriptWork *)scriptCtl, 0);
    }
    return 0;
}

/* Sets the event id of NPC record outSlot from the row found by (keyA, keyB). */
int SCRCMD_NETWORK_CmdSetNpcEventFromTable(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl = (struct ScriptCtl *)SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)scriptWork);
    u32 keyA = SCRIPT_WORK_ReadWorkValue(vm, (struct ScrcmdWork *)scriptWork);
    u32 outSlot = SCRIPT_WORK_ReadWorkValue(vm, (struct ScrcmdWork *)scriptWork);
    u32 keyB = SCRIPT_WORK_ReadWorkValue(vm, (struct ScrcmdWork *)scriptWork);
    const NpcTableRow *table;
    struct EventDataSystem *eventData;
    u16 eventKey;

    eventData = GAME_DATA_GetEventData(SCRCMD_WORK_GetGameData((struct ScrcmdWork *)scriptWork));
    table = (struct NpcTableRow *)SCRIPT_WORK_GetReturnFlag((struct ScriptWork *)scriptCtl);
    eventKey = table[(u16)SCRCMD_NETWORK_FindNpcTableRow(table, keyA, keyB)].eventKey;
    EVENTDATA_SYSTEM_SetNpcEventId(eventData, outSlot, EVENT_TRAINER_GetPrimaryScriptId(eventKey));
    return 0;
}

/* Same lookup, sets the event ids of two NPC records. */
int SCRCMD_NETWORK_CmdSetNpcEventPairFromTable(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl = (struct ScriptCtl *)SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)scriptWork);
    u32 keyA = SCRIPT_WORK_ReadWorkValue(vm, (struct ScrcmdWork *)scriptWork);
    u32 outSlotA = SCRIPT_WORK_ReadWorkValue(vm, (struct ScrcmdWork *)scriptWork);
    u32 outSlotB = SCRIPT_WORK_ReadWorkValue(vm, (struct ScrcmdWork *)scriptWork);
    u32 keyB = SCRIPT_WORK_ReadWorkValue(vm, (struct ScrcmdWork *)scriptWork);
    const NpcTableRow *table;
    struct EventDataSystem *eventData;
    u16 index;

    eventData = GAME_DATA_GetEventData(SCRCMD_WORK_GetGameData((struct ScrcmdWork *)scriptWork));
    table = (struct NpcTableRow *)SCRIPT_WORK_GetReturnFlag((struct ScriptWork *)scriptCtl);
    index = SCRCMD_NETWORK_FindNpcTableRow(table, keyA, keyB);
    EVENTDATA_SYSTEM_SetNpcEventId(eventData, outSlotA, EVENT_TRAINER_GetPrimaryScriptId(table[index].eventKey));
    EVENTDATA_SYSTEM_SetNpcEventId(eventData, outSlotB, EVENT_TRAINER_GetSecondaryScriptId(table[index].eventKey));
    return 0;
}

/* Sets object code and event id of three NPC records from three table rows. */
int SCRCMD_NETWORK_CmdSetNpcTripleFromTable(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl = (struct ScriptCtl *)SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)scriptWork);
    u32 slot0 = SCRIPT_WORK_ReadWorkValue(vm, (struct ScrcmdWork *)scriptWork);
    u32 slot1 = SCRIPT_WORK_ReadWorkValue(vm, (struct ScrcmdWork *)scriptWork);
    u32 slot2 = SCRIPT_WORK_ReadWorkValue(vm, (struct ScrcmdWork *)scriptWork);
    u32 row0 = SCRIPT_WORK_ReadWorkValue(vm, (struct ScrcmdWork *)scriptWork);
    u32 row1 = SCRIPT_WORK_ReadWorkValue(vm, (struct ScrcmdWork *)scriptWork);
    u32 row2 = SCRIPT_WORK_ReadWorkValue(vm, (struct ScrcmdWork *)scriptWork);
    struct EventDataSystem *eventData = GAME_DATA_GetEventData(SCRCMD_WORK_GetGameData((struct ScrcmdWork *)scriptWork));
    NpcTableRow *table = (struct NpcTableRow *)SCRIPT_WORK_GetReturnFlag((struct ScriptWork *)scriptCtl);

    EVENTDATA_SYSTEM_SetNpcObjCode(eventData, slot0, table[row0].objCode);
    EVENTDATA_SYSTEM_SetNpcObjCode(eventData, slot1, table[row1].objCode);
    EVENTDATA_SYSTEM_SetNpcObjCode(eventData, slot2, table[row2].objCode);
    EVENTDATA_SYSTEM_SetNpcEventId(eventData, slot0, EVENT_TRAINER_GetPrimaryScriptId(table[row0].eventKey));
    EVENTDATA_SYSTEM_SetNpcEventId(eventData, slot1, EVENT_TRAINER_GetPrimaryScriptId(table[row1].eventKey));
    EVENTDATA_SYSTEM_SetNpcEventId(eventData, slot2, EVENT_TRAINER_GetPrimaryScriptId(table[row2].eventKey));
    return 0;
}

int SCRCMD_NETWORK_CmdApplyTableEventKeys(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl;
    struct EventWork *eventWork;
    int i;
    NpcTableRow *table;

    scriptCtl = (struct ScriptCtl *)SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)scriptWork);
    eventWork = GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(SCRIPT_WORK_GetGameSystem((struct ScriptWork *)scriptCtl)));
    table = (struct NpcTableRow *)SCRIPT_WORK_GetReturnFlag((struct ScriptWork *)scriptCtl);
    for (i = 0; i < NPC_TABLE_ROW_COUNT; i++)
        EVENT_TRAINER_ClearDefeatedFlag((char *)eventWork, table[i].eventKey);
    return 0;
}

/*
 * Draws six distinct values from 0..0x33 (random pick among the ones not
 * yet taken) and writes each plus 0x37 to six script-variable slots.
 *
 * Keys: the work locals live in a nested block opened after the six
 * SCRIPT_WORK_ReadWorkPointer calls, so `u16 picked[6] = {0}` is emitted there (at function
 * scope the initializer lands above the calls) and its stores go through
 * the same `add r4, sp, #0x18` the search loops index. `u16 poolSize = 0x34`
 * declared before picked schedules `movs r7, #0x34` ahead of the zero stores.
 * EXACT* only for the 2-byte pad after the function (218 of 220).
 */
int SCRCMD_NETWORK_PickSixDistinctRandom(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    u16 *outVar0, *outVar1, *outVar2, *outVar3, *outVar4, *outVar5;

    SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)scriptWork);
    outVar0 = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    outVar1 = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    outVar2 = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    outVar3 = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    outVar4 = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    outVar5 = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    {
        u16 poolSize = 0x34;
        u16 picked[6] = {0};
        int drawIndex, candidate, prior;
        s16 skipCount;

        for (drawIndex = 0; drawIndex < 6; drawIndex++) {
            skipCount = GFL_USE_GetRandom(poolSize);
            for (candidate = 0; candidate < 0x34; candidate++) {
                for (prior = 0; prior < drawIndex; prior++) {
                    if (picked[prior] == candidate)
                        break;
                }
                if (prior == drawIndex) {
                    if (--skipCount < 0) {
                        picked[drawIndex] = candidate;
                        break;
                    }
                }
            }
            poolSize--;
        }
        *outVar0 = picked[0] + 0x37;
        *outVar1 = picked[1] + 0x37;
        *outVar2 = picked[2] + 0x37;
        *outVar3 = picked[3] + 0x37;
        *outVar4 = picked[4] + 0x37;
        *outVar5 = picked[5] + 0x37;
    }
    return 0;
}

/* Index of the first row matching both keys, 0 when none does. */
int SCRCMD_NETWORK_FindNpcTableRow(const NpcTableRow *table, int keyA, int keyB)
{
    int i;

    for (i = 0; i < NPC_TABLE_ROW_COUNT; i++) {
        const NpcTableRow *row = &table[i];

        if (keyA == row->keyA && keyB == row->keyB)
            return i;
    }
    return 0;
}

/* TRUE when the situation warp id differs from the current one. */
BOOL SCRCMD_NETWORK_HasSituationWarpChanged(struct GameData *gameData)
{
    int currentWarpId = MAP_REPLACE_GetDefaultWarpId();

    if (currentWarpId == GAME_DATA_GetSituationWarpId(gameData))
        return FALSE;
    else
        return TRUE;
}

/*
 * former blocker: ABS32 0x000000CD (ov_id_00CD) has no witness outside the function (literal pool word only)
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int SCRCMD_NETWORK_CommProcEventMain(struct GameEvent *event, u32 *seq, void *workArg)
{
    CommProcEventWork *work = workArg;

    switch (*seq) {
    case 0:
        BRIGHTNESS_Set(-16, 0x37, 1);
        BRIGHTNESS_Set(-16, 0x3f, 2);
        GAME_EVENT_CallProc(event, (u32)ov_id_00CD, d_021B9EC0, work);
        (*seq)++;
        break;
    case 1:
        BRIGHTNESS_Set(0, 0x3f, 3);
        GAME_EVENT_CallEvent(event, EVENT_WIFI_PROC_LoadOv020Task(work->gameSystem));
        (*seq)++;
        break;
    case 2:
        if (work->warpChanged == 0) {
            SCRIPT_SYS_CallScriptEvent(event, 3, 0, 0, 0x15);
        } else {
            SCRIPT_SYS_CallScriptEvent(event, 0x7d1, 0, 0, 0x15);
        }
        (*seq)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

struct GameEvent *SCRCMD_NETWORK_CreateCommProcEvent(struct GameSystem *gameSystem)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, SCRCMD_NETWORK_CommProcEventMain, sizeof(CommProcEventWork));
    CommProcEventWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->warpChanged = SCRCMD_NETWORK_HasSituationWarpChanged(gameData);
    work->myStatus = GAME_DATA_GetMyStatus(gameData);
    SYMBOL_MAP_DeleteLinkRecord((struct SymbolMapOwner *)GAME_DATA_GetEventState(gameData));
    GAMESYSTEM_SetCommBlocked(gameSystem, 0);
    return event;
}
