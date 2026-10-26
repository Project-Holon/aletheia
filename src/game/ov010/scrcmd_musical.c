/*
 * file:     scrcmd_musical.c
 * unit:     yes
 * function: SCRCMD_MUSICAL_StartMusical, SCRCMD_MUSICAL_ShowPartyMonMusical, SCRCMD_MUSICAL_GetValue, SCRCMD_MUSICAL_GetProgramInfo, SCRCMD_MUSICAL_AddOwnedProp, SCRCMD_MUSICAL_BufferString, SCRCMD_MUSICAL_ResetProgramRank, SCRCMD_MUSICAL_SelectPartyMon, SCRCMD_MUSICAL_LinkControl, SCRCMD_MUSICAL_CreateLinkWork, SCRCMD_MUSICAL_DeleteLinkWork, SCRCMD_MUSICAL_BeginCommSession, SCRCMD_MUSICAL_CloseCommSession, SCRCMD_MUSICAL_TaskStartMusical, SCRCMD_MUSICAL_TaskShowMusicalProc, SCRCMD_MUSICAL_FreeProcArgs, SCRCMD_MUSICAL_LinkProcCallback, SCRCMD_MUSICAL_WaitEntryMenuParent, SCRCMD_MUSICAL_WaitEntryMenuChild, SCRCMD_MUSICAL_WaitSetMemberCount, SCRCMD_MUSICAL_WaitSessionReady, SCRCMD_MUSICAL_WaitCommAttach, SCRCMD_MUSICAL_WaitCommIdle, SCRCMD_MUSICAL_WaitSessionFinish, SCRCMD_MUSICAL_WifiListCommand
 * address:  0x0215D34C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from scrcmd_musical.c, move_pokemon.c by tools/splitfile.py.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAME_DATA_GetExternalWork  0x02012F80  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   MUSICAL_EVENT_Create  0x02155A98  thumb  ov010
 *   SCRIPT_SYS_SetNextEventFromWork  0x0215898C  thumb  ov010
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   VM_End  0x02011290  thumb
 *   GAME_DATA_GetSaveBlock2A  0x02012F44  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MUSICAL_SAVE_NoOp  0x0200A640  thumb
 *   FIELD_STATUS_CreateSubProcCallbackEvent  0x02014808  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   ov112_id       0x00000070  data
 *   d_02172914     0x02172914  data
 *   d_021F8360     0x021F8360  data
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   MUSICAL_MCSS_CreateMon  0x021F675C  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   MUSICAL_EVENT_GetLocalSlot  0x021568E0  thumb  ov010
 *   MUSICAL_EVENT_GetMaxScore  0x02156954  thumb  ov010
 *   MUSICAL_EVENT_GetMinScore  0x02156978  thumb  ov010
 *   MUSICAL_EVENT_GetScoreCapped  0x02156934  thumb  ov010
 *   MUSICAL_EVENT_GetPlayerOfSlot  0x021568E8  thumb  ov010
 *   MUSICAL_EVENT_GetProgramBestCategory  0x02156908  thumb  ov010
 *   MUSICAL_EVENT_GetSlotOfRank  0x0215699C  thumb  ov010
 *   MUSICAL_EVENT_GetBestAppealCategory  0x021569A4  thumb  ov010
 *   MUSICAL_EVENT_GetPortraitClass  0x021569EC  thumb  ov010
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   MUSICAL_SAVE_GetOutfits  0x0200A628  thumb
 *   MUSICAL_SAVE_IsPropOwned  0x0200A644  thumb
 *   MUSICAL_SAVE_GetShowCount  0x0200A75C  thumb
 *   MUSICAL_SAVE_GetTopRankCount  0x0200A780  thumb
 *   MUSICAL_SAVE_GetEquippedProp  0x0200A7A0  thumb
 *   MUSICAL_SAVE_GetSelectedProgram  0x0200A7B8  thumb
 *   MUSICAL_SAVE_GetScriptSetting  0x0200A7C8  thumb
 *   MUSICAL_SAVE_SetScriptSetting  0x0200A7D4  thumb
 *   MUSICAL_SAVE_GetHasDistData  0x0200A7E0  thumb
 *   MUSICAL_MCSS_GetMonValue  0x021F6744  thumb  ov112
 *   MUSICAL_SAVE_GetProgram  0x0200A750  thumb
 *   MUSICAL_SAVE_AddProp   0x0200A6BC  thumb
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   MUSICAL_EVENT_AllocTitleString  0x02156914  thumb  ov010
 *   MUSICAL_EVENT_SetPlayerNameWord  0x02156A3C  thumb  ov010
 *   MUSICAL_EVENT_SetPokemonNameWord  0x02156AD4  thumb  ov010
 *   MUSICAL_SAVE_GetStageData  0x0200A7F8  thumb
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetStringN  0x02045994  arm
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   EVENT_POKE_STATUS_CreatePokeSelectStatusEvent 0x0215A168 thumb ov010
 *   MUSICAL_EVENT_CheckNetError  0x02156BAC  thumb  ov010
 *   MUSICAL_EVENT_IsAborted  0x02156BCC  thumb  ov010
 *   GAMESYSTEM_SetFieldMapState  0x02012124  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   VM_SetWait  0x020113D0  thumb
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   COMM_ENTRY_MENU_Create  0x021CD48C  thumb  ov021
 *   MUS_COMM_FUNC_SetTimingSync  0x021FCDEC  thumb  ov132
 *   STA_SLOT_GetRecordTable  0x021FDA6C  thumb  ov132
 *   d_021BB6A4     0x021BB6A4  data  ov100
 *   ov100_id       0x00000064  data
 *   GAME_DATA_SetExternalWork  0x02012F74  thumb
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   ov132_id       0x00000084  data
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   MUS_COMM_FUNC_Create  0x021FC644  thumb  ov132
 *   MUS_COMM_FUNC_Delete  0x021FC684  thumb
 *   GAME_EVENT_GetGameSystem 0x020124E4 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_EVENT_CallEvent 0x02012374 thumb
 *   GAME_COMM_GetKind 0x02026454 thumb
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   GAMESYSTEM_TryStartAutoComm 0x020121CC thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   MUSICAL_DRESSUP_SYS_ProcTable     0x02172724  data
 *   MUS_COMM_FUNC_InitCommandTable  0x021FC81C  thumb
 *   COMM_ENTRY_MENU_Main  0x021CD688  thumb
 *   MUS_COMM_FUNC_SetHostFlag  0x021FC804  thumb
 *   COMM_ENTRY_MENU_Delete  0x021CD5A4  thumb
 *   MUS_COMM_FUNC_CheckTimingSync  0x021FCE00  thumb
 *   STA_NET_GetSlot3Done  0x021FD844  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   STA_NET_GetRecordsReceived  0x021FD910  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_SYNC_GetBlock  0x02009448  thumb
 *   BLOCK20_SAVEDATA_CountEntries  0x02009370  thumb
 *   PDW_POSTMAN_CountUnreceivable  0x021B76F8  thumb  ov021
 *   PDW_POSTMAN_CreateListEvent  0x021B7794  thumb  ov021
 *   PDW_POSTMAN_ReceiveItems  0x021B76B4  thumb  ov021
 *   PDW_POSTMAN_GetUnreceivableItem  0x021B7740  thumb  ov021
 *   WORDSET_SetSlotFromMsg118  0x0201EF5C  thumb
 */
#include "../arm9/script_vm_types.h"
#include "scrcmd_musical_shared_types.h"

struct GameComm;

struct ScrcmdWork;

struct ScrcmdWork;

struct MusicalEvent;

struct MusicalSave;

struct WordSet;

struct MsgBank;

struct Strbuf;

struct BgmInfo;

struct CgearSaveBlock;

typedef void (*SubProcCallback)(void *callbackArg);

/* Musical save block 0x2A (0x2A4 bytes), layout from mystery_data.c. */
#include "../arm9/musical_save_types.h"

/* The first word of the musical save block (what MUSICAL_SAVE_NoOp points at). */
typedef struct MusicalHeadBits {
    u32 showcaseMonsNo : 16;
    u32 shotState : 5;
    u32 showcaseFlags : 11;
} MusicalHeadBits;

#include "musical_link_types.h"

/* Wait context for the ov100 proc callback. */
typedef struct MusicalLinkWait {
    struct ScrcmdWork *scriptWork;
    MusicalLink *link;
} MusicalLinkWait;

/* Task work of StartMusical. */
typedef struct MusicalStartTask {
    struct GameEvent *musicalSeq;         /* 0x00: musical link sequence event */
    MusicalLink *link;                /* 0x04 */
    u32 mode;                             /* 0x08 */
} MusicalStartTask;

/* Arguments of the ov112 proc started by StartMusical (mode 2 and up). */
typedef struct MusicalProcArgs {
    u32 startMode;                        /* 0x00 */
    u32 isOffline;                        /* 0x04 */
    MusicalHeadBits *saveBits;            /* 0x08 */
} MusicalProcArgs;

typedef struct MusicalProcBox {
    MusicalProcArgs *args;
} MusicalProcBox;

/* Arguments handed to the musical system proc of ShowPartyMonMusical. */
typedef struct MusicalSystemArgs {
    u32 startMode;                        /* 0x00 */
    void *musicalSystem;                  /* 0x04: result of MUSICAL_SYSTEM_Create */
    struct MusicalSave *musicalSave;                      /* 0x08 */
} MusicalSystemArgs;

typedef struct MusicalSystemTask {
    MusicalSystemArgs *args;
} MusicalSystemTask;
struct ScrcmdWork;
struct ScrcmdWork;
struct ScrcmdWork;

                         
struct GameSystem;

struct GameData;

struct ScrcmdWork;

struct ScriptFieldParam;


struct ScriptVm;

                       


struct ScriptVm;


#include "event_poke_status.h"

/* game system, game event, game data */
#include "../arm9/gamesystem.h"







#include "../arm9/game_event.h"





/* the wait callback receives the user work of the script command */
typedef int (*ScriptWorkWaitFn)(ScriptVm *vm, struct ScrcmdWork *scriptWork);


#include "../arm9/game_data.h"







#include "../arm9/field_status.h"

/* overlay loading, heap, string helpers */
#include "../arm9/gfl_heap_wrap.h"


#include "../arm9/gf_overlay.h"


#include "../arm9/mi_memory.h"

#include "../arm9/strbuf.h"


struct MsgBank;

#include "../arm9/msgdata.h"



#include "../arm9/wordset.h"


/* musical save block */
#include "../arm9/musical_save.h"












struct MusicalLink;

/* musical event (ov010 musical_dressup_sys.c) */
#include "musical_event.h"
struct MusicalEventWork;














struct Party;

/* party and musical system */
#include "../arm9/pokeparty.h"
struct PokemonParam;


#include "../ov112/musical_mcss.h"

#include "../ov112/musical_system.h"
struct FieldMap;
struct CommEntryMenu;

                                               
                            

#include "../ov021/comm_entry_menu.h"

                                   

                              



                              


                        




struct GameSyncData;


                             


                                        
#include "../arm9/game_sync.h"
struct CgearSaveBlock;
struct CgearSaveBlock;

#include "../arm9/block20_savedata.h"
struct CgearSaveBlock;

#include "../ov021/pdw_postman.h"
#include "../ov132/mus_comm_func.h"
#include "../ov132/sta_slot.h"
#include "../arm9/net_err.h"
#include "../arm9/game_comm.h"
#include "../arm9/net.h"
#include "../ov132/sta_net.h"
#include "scrcmd_work.h"
#include "script_work.h"
#include "../arm9/vm.h"
#ifndef __MWERKS__
#include "script_sys.h"
#endif




int SCRCMD_MUSICAL_StartMusical(ScriptVm *vm, struct ScrcmdWork *scriptWork);

int SCRCMD_MUSICAL_ShowPartyMonMusical(ScriptVm *vm, struct ScrcmdWork *scriptWork);

int SCRCMD_MUSICAL_GetValue(ScriptVm *vm, struct ScrcmdWork *scriptWork);

int SCRCMD_MUSICAL_GetProgramInfo(ScriptVm *vm, struct ScrcmdWork *scriptWork);

int SCRCMD_MUSICAL_AddOwnedProp(ScriptVm *vm, struct ScrcmdWork *scriptWork);

int SCRCMD_MUSICAL_BufferString(ScriptVm *vm, struct ScrcmdWork *scriptWork);

int SCRCMD_MUSICAL_ResetProgramRank(ScriptVm *vm, struct ScrcmdWork *scriptWork);

int SCRCMD_MUSICAL_SelectPartyMon(ScriptVm *vm, struct ScrcmdWork *scriptWork);

int SCRCMD_MUSICAL_LinkControl(ScriptVm *vm, struct ScrcmdWork *scriptWork);

void SCRCMD_MUSICAL_CreateLinkWork(struct ScriptWork *unused, struct GameData *gameData);

void SCRCMD_MUSICAL_DeleteLinkWork(MusicalLink *link, struct GameData *gameData);

void SCRCMD_MUSICAL_BeginCommSession(void *link, struct GameSystem *gameSys, struct GameComm *gameComm, int arg);

void SCRCMD_MUSICAL_CloseCommSession(MusicalLink *link);

int SCRCMD_MUSICAL_TaskStartMusical(struct GameEvent *task, int *state, void *work);

int SCRCMD_MUSICAL_TaskShowMusicalProc(struct GameEvent *task, int *state, void *work);

void SCRCMD_MUSICAL_FreeProcArgs(void *callbackArg);

void SCRCMD_MUSICAL_LinkProcCallback(void *callbackArg);

int SCRCMD_MUSICAL_WaitEntryMenuParent(ScriptVm *vm, void *scriptWork);

int SCRCMD_MUSICAL_WaitEntryMenuChild(ScriptVm *vm, void *scriptWork);

int SCRCMD_MUSICAL_WaitSetMemberCount(ScriptVm *vm, void *scriptWork);

int SCRCMD_MUSICAL_WaitSessionReady(ScriptVm *vm, void *scriptWork);

int SCRCMD_MUSICAL_WaitCommAttach(ScriptVm *vm, void *scriptWork);

int SCRCMD_MUSICAL_WaitCommIdle(ScriptVm *vm, void *scriptWork);

int SCRCMD_MUSICAL_WaitSessionFinish(ScriptVm *vm, void *scriptWork);

int SCRCMD_MUSICAL_WifiListCommand(ScriptVm *vm, struct ScrcmdWork *scriptWork);

extern u8 ov112_id[];

extern const char d_02172914[];

extern u8 d_021F8360[];

extern u8 d_021BB6A4[];

extern u8 ov100_id[];

extern u8 ov132_id[];

#include "../arm9/procsys.h"
extern const ProcData MUSICAL_DRESSUP_SYS_ProcTable;

/*
 * Script command: start the ov010 musical link sequence (MUSICAL_EVENT_Create) for
 * mode 0/1, or push the ov112 proc through FIELD_STATUS_CreateSubProcCallbackEvent otherwise.
 *
 * Levers (all needed for the exact bytes): `d = (mode == 0) ? 0 : 1` instead
 * of an if (removes a register swap); SCRIPT_WORK_ReadWorkValue declared u16 with the
 * argument held in a u16 local (moves the outgoing stack store, see
 * docs/idioms/a-u16-accessor-result-held-in-a-u16-local-moves-the-stack-argument-stores.md).
 * The callback 0x0215DF6C is a 12-byte tail stub in the image.
 * SCRIPT_WORK_ResetFieldParam returns a+0x18 (result ignored); GAME_DATA_GetSaveBlock2A is void in its
 * own file, but this caller uses its result as the musical save pointer.
 */
#include "script_work_cmd.h"
int SCRCMD_MUSICAL_StartMusical(ScriptVm *vm, struct ScrcmdWork *scriptWork)
{
    struct ScriptWork *scriptCtl;
    struct GameSystem *gameSys;
    struct GameData *gameData;
    struct FieldMap *fieldMap;
    u16 arg;
    u8 mode;

    scriptCtl = SCRCMD_WORK_GetScriptWork(scriptWork);
    gameSys = SCRCMD_WORK_GetGameSystem(scriptWork);
    gameData = SCRCMD_WORK_GetGameData(scriptWork);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSys);
    SCRIPT_WORK_ResetFieldParam(scriptCtl);
    arg = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    mode = *vm->pc;
    vm->pc++;
    if (mode <= 1) {
        MusicalLink *link = GAME_DATA_GetExternalWork(gameData);
        u32 startMode;
        struct GameEvent *task;
        MusicalStartTask *startTask;

        startMode = (mode == 0) ? 0 : 1;
        task = GAME_EVENT_Create(gameSys, 0, SCRCMD_MUSICAL_TaskStartMusical, sizeof(MusicalStartTask));
        startTask = GAME_EVENT_GetWork(task);
        MI_CpuFill8(startTask, 0, sizeof(MusicalStartTask));
        startTask->musicalSeq = MUSICAL_EVENT_Create((void *)gameSys, (void *)gameData, arg, startMode, link);
        startTask->link = link;
        startTask->mode = startMode;
        SCRIPT_SYS_SetNextEventFromWork((void *)scriptCtl, task);
        GAME_DATA_GetBgmInfo(gameData);
        VM_End(vm);
        return 1;
    } else {
        struct MusicalSave *musical = (struct MusicalSave *)GAME_DATA_GetSaveBlock2A(gameData);
        MusicalProcBox *box;

        box = GFL_HEAP_Alloc(4, sizeof(MusicalProcBox), 1, d_02172914, 0xA9);
        box->args = GFL_HEAP_Alloc(4, 0x14, 1, d_02172914, 0xAA);
        box->args->startMode = 0;
        box->args->saveBits = (MusicalHeadBits *)MUSICAL_SAVE_NoOp(musical);
        box->args->isOffline = 1;
        SCRIPT_SYS_CallEvent((void *)scriptCtl, FIELD_STATUS_CreateSubProcCallbackEvent(gameSys, fieldMap, (uptr)ov112_id, d_021F8360, box->args, SCRCMD_MUSICAL_FreeProcArgs, box));
        return 1;
    }
}

/*
 * Script command: show the musical of a party Pokemon. Reads a party index,
 * creates the musical system for that member and runs the proc MUSICAL_DRESSUP_SYS_ProcTable
 * on it from a task (SCRCMD_MUSICAL_TaskShowMusicalProc), which frees the work when done.
 */
int SCRCMD_MUSICAL_ShowPartyMonMusical(ScriptVm *vm, struct ScrcmdWork *scriptWork)
{
    struct ScriptWork *scriptCtl = SCRCMD_WORK_GetScriptWork(scriptWork);
    struct GameSystem *gameSys = SCRCMD_WORK_GetGameSystem(scriptWork);
    struct GameData *gameData = SCRCMD_WORK_GetGameData(scriptWork);
    int partyIndex;
    struct MusicalSave *musicalSave; void *musicalSystem;
    struct GameEvent *task;
    MusicalSystemTask *systemTask;

    GAMESYSTEM_GetFieldMap(gameSys);
    partyIndex = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    musicalSave = (struct MusicalSave *)GAME_DATA_GetSaveBlock2A(gameData);
    musicalSystem = MUSICAL_MCSS_CreateMon((void *)(struct Pokemon *)POKEPARTY_GetMember((void *)(struct PokeParty *)GAME_DATA_GetMyParty(gameData), partyIndex), 4);
    task = GAME_EVENT_Create(gameSys, 0, SCRCMD_MUSICAL_TaskShowMusicalProc, 4);
    systemTask = GAME_EVENT_GetWork(task);
    MI_CpuFill8(systemTask, 0, sizeof(*systemTask));
    systemTask->args = GFL_HEAP_Alloc(4, sizeof(*systemTask->args), 1, d_02172914, 0xd7);
    systemTask->args->musicalSystem = musicalSystem;
    systemTask->args->musicalSave = musicalSave;
    systemTask->args->startMode = 0;
    SCRIPT_SYS_CallEvent((void *)scriptCtl, task);
    return 1;
}

/*
 * Script command: read a one-byte query id from the script cursor, one
 * argument word and a result variable, and store the answer of the query
 * (musical save counters 0..15, link-result queries 30..39) into the variable.
 *
 * Levers: the per-case best/second locals at function scope in declaration
 * order with op declared last (sets the stack slots), max initialised before
 * best, case 10 loops over its own block-local slot, case 7 tests == 0 first.
 */
int SCRCMD_MUSICAL_GetValue(ScriptVm *vm, struct ScrcmdWork *scriptWork)
{
    u32 arg;
    u16 *resultVar;
    struct GameData *gameData;
    struct MusicalSave *musical;
    struct MusicalEvent *musicalEvent;
    u8 i;
    u8 maxCount;
    u8 uniqueTopSlot;
    u8 lowestSlot;
    u8 topSlot;
    u8 leaderSlot;
    u8 leaderPrevMax;
    u8 runnerUpSlot;
    struct PokeParty *party;
    u8 op;

    SCRCMD_WORK_GetScriptWork(scriptWork);
    op = *vm->pc;
    vm->pc++;
    arg = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    gameData = SCRCMD_WORK_GetGameData(scriptWork);
    musical = (struct MusicalSave *)GAME_DATA_GetSaveBlock2A(gameData);
    musicalEvent = 0;
    if (op >= 30) {
        struct MusicalEvent **linkEvent = GAME_DATA_GetExternalWork(gameData);

        if (linkEvent == 0) {
            *resultVar = 0;
            return 0;
        }
        musicalEvent = *linkEvent;
    }
    switch (op) {
    case 0:
        *resultVar = MUSICAL_SAVE_GetShowCount(musical);
        break;
    case 1:
        *resultVar = MUSICAL_SAVE_GetTopRankCount(musical);
        break;
    case 2:
        *resultVar = MUSICAL_SAVE_GetSelectedProgram(musical);
        break;
    case 3: {
        /* equipped prop slot with the single highest value, 4 on a tie */
        maxCount = 0;
        uniqueTopSlot = 4;

        for (i = 0; i < 4; i++) {
            u8 value = MUSICAL_SAVE_GetEquippedProp(musical, i);

            if (value > maxCount) {
                maxCount = value;
                uniqueTopSlot = i;
            } else if (value == maxCount) {
                uniqueTopSlot = 4;
            }
        }
        *resultVar = uniqueTopSlot;
        break;
    }
    case 4:
        *resultVar = MUSICAL_SAVE_GetScriptSetting(musical);
        break;
    case 5:
        MUSICAL_SAVE_SetScriptSetting(musical, arg);
        break;
    case 6:
        *resultVar = 0;
        for (i = 0; i < 4; i++) {
            if (MUSICAL_SAVE_GetEquippedProp(musical, i) != 0)
                *resultVar = 1;
        }
        break;
    case 7:
        if (((MusicalHeadBits *)MUSICAL_SAVE_NoOp(musical))->shotState == 0)
            *resultVar = 0;
        else
            *resultVar = 1;
        break;
    case 8: {
        /* slot with the lowest value (last one on a tie) */
        maxCount = 0xFF;
        lowestSlot = 4;

        for (i = 0; i < 4; i++) {
            u8 value = MUSICAL_SAVE_GetEquippedProp(musical, i);

            if (value <= maxCount) {
                maxCount = value;
                lowestSlot = i;
            }
        }
        *resultVar = lowestSlot;
        break;
    }
    case 9: {
        /* slot with the highest value (first one on a tie) */
        maxCount = 0;
        topSlot = 4;

        for (i = 0; i < 4; i++) {
            u8 value = MUSICAL_SAVE_GetEquippedProp(musical, i);

            if (value > maxCount) {
                maxCount = value;
                topSlot = i;
            }
        }
        *resultVar = topSlot;
        break;
    }
    case 10: {
        /* runner-up slot, 4 when the runner-up ties */
        u8 slot;

        leaderSlot = 4;
        leaderPrevMax = 0;
        maxCount = 0;
        runnerUpSlot = 4;

        for (slot = 0; slot < 4; slot++) {
            u8 value = MUSICAL_SAVE_GetEquippedProp(musical, slot);

            if (value > maxCount) {
                if (leaderPrevMax == maxCount) {
                    runnerUpSlot = 4;
                } else {
                    leaderPrevMax = maxCount;
                    runnerUpSlot = leaderSlot;
                }
                maxCount = value;
                leaderSlot = slot;
            }
        }
        *resultVar = runnerUpSlot;
        break;
    }
    case 11: {
        /* number of party members that can take part in a musical */
        u8 count = 0;
        u8 partyCount;

        party = (struct PokeParty *)GAME_DATA_GetMyParty(gameData);
        partyCount = POKEPARTY_GetCount((struct Party *)party);

        for (i = 0; i < partyCount; i++) {
            if ((u32)MUSICAL_MCSS_GetMonValue((struct Pokemon *)POKEPARTY_GetMember((void *)party, (int)i)) == 1)
                count++;
        }
        *resultVar = count;
        break;
    }
    case 12:
        if ((u32)MUSICAL_MCSS_GetMonValue((struct Pokemon *)POKEPARTY_GetMember((void *)(struct PokeParty *)GAME_DATA_GetMyParty(gameData), (int)arg)) == 1)
            *resultVar = 1;
        else
            *resultVar = 0;
        break;
    case 13: {
        /* any outfit slot in use */
        MusicalOutfit *outfits = MUSICAL_SAVE_GetOutfits(musical);

        *resultVar = 0;
        for (i = 0; i < 8; i++) {
            if (outfits[i].pokeSlot != 10)
                *resultVar = 1;
        }
        break;
    }
    case 14:
        if (MUSICAL_SAVE_GetHasDistData(musical) == 1)
            *resultVar = 1;
        else
            *resultVar = 0;
        break;
    case 15:
        if (MUSICAL_SAVE_IsPropOwned(musical, (u8)arg) == 1)
            *resultVar = 1;
        else
            *resultVar = 0;
        break;
    case 30:
        *resultVar = MUSICAL_EVENT_GetLocalSlot((struct MusicalEventWork *)musicalEvent);
        break;
    case 31:
        *resultVar = MUSICAL_EVENT_GetMaxScore((struct MusicalEventWork *)musicalEvent);
        break;
    case 32:
        *resultVar = MUSICAL_EVENT_GetMinScore((struct MusicalEventWork *)musicalEvent);
        break;
    case 33:
        *resultVar = MUSICAL_EVENT_GetScoreCapped((struct MusicalEventWork *)musicalEvent, arg);
        break;
    case 35:
        *resultVar = MUSICAL_EVENT_GetPlayerOfSlot((struct MusicalEventWork *)musicalEvent, arg);
        break;
    case 36:
        *resultVar = MUSICAL_EVENT_GetProgramBestCategory((struct MusicalEventWork *)musicalEvent);
        break;
    case 37:
        *resultVar = MUSICAL_EVENT_GetSlotOfRank((struct MusicalEventWork *)musicalEvent, arg);
        break;
    case 38:
        *resultVar = MUSICAL_EVENT_GetBestAppealCategory((struct MusicalEventWork *)musicalEvent, arg);
        break;
    case 39:
        *resultVar = MUSICAL_EVENT_GetPortraitClass((struct MusicalEventWork *)musicalEvent, arg);
        break;
    }
    return 0;
}

/*
 * Script command: read a query kind and a program slot, store a derived
 * value of that musical program into a script variable.
 */
int SCRCMD_MUSICAL_GetProgramInfo(ScriptVm *vm, struct ScrcmdWork *scriptWork)
{
    int slot;
    u32 kind;
    u16 *resultVar;
    MusicalProgram *program;

    slot = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    kind = *vm->pc;
    vm->pc++;
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    program = MUSICAL_SAVE_GetProgram((struct MusicalSave *)GAME_DATA_GetSaveBlock2A(SCRCMD_WORK_GetGameData(scriptWork)), (u8)slot);
    switch (kind) {
    case 0:
        switch (program->state) {
        case 0: *resultVar = 0x18; break;
        case 1: *resultVar = 0xf; break;
        case 2: *resultVar = 0x2d; break;
        case 3: *resultVar = 0xc; break;
        case 4: *resultVar = 0; break;
        }
        break;
    case 1:
        *resultVar = slot + 5;
        break;
    case 2:
        slot += 0xf;
        *resultVar = slot;
        break;
    case 3:
        *resultVar = program->rank;
        break;
    case 4:
        *resultVar = program->score;
        break;
    }
    return 0;
}

/* Script command: mark a musical prop as owned. The id is truncated to a byte before the arm9 call. */
int SCRCMD_MUSICAL_AddOwnedProp(ScriptVm *vm, struct ScrcmdWork *scriptWork)
{
    int prop = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);

    MUSICAL_SAVE_AddProp((struct MusicalSave *)GAME_DATA_GetSaveBlock2A(SCRCMD_WORK_GetGameData(scriptWork)), (u8)prop);

    return 0;
}

/*
 * Script command: read a one-byte string kind and a word-set slot from the
 * script cursor, one argument word, and buffer the matching string into the
 * slot (stage name, message-bank entries, link member names, or the three
 * placement labels of a four-way ranking).
 */
int SCRCMD_MUSICAL_BufferString(ScriptVm *vm, struct ScrcmdWork *scriptWork)
{
    struct ScriptWork *scriptCtl = SCRCMD_WORK_GetScriptWork(scriptWork);
    struct GameData *gameData = SCRCMD_WORK_GetGameData(scriptWork);
    u32 heapId = SCRCMD_WORK_GetHeapId(scriptWork);
    struct WordSet *wordSet = (struct WordSet *)SCRIPT_WORK_GetWordSet(scriptCtl);
    u8 kind;
    u8 slot;
    u32 arg;
    struct MsgBank *msgData;
    struct Strbuf *str;

    kind = *vm->pc;
    vm->pc++;
    slot = *vm->pc;
    vm->pc++;
    arg = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);

    switch (kind) {
    case 0: {
        struct MusicalSave *musical = (struct MusicalSave *)GAME_DATA_GetSaveBlock2A(SCRCMD_WORK_GetGameData(scriptWork));

        str = STRBUF_Create(0x26, heapId);
        STRBUF_SetStringN(str, (const u16 *)MUSICAL_SAVE_GetStageData(musical), 0x26);
        WORDSET_SetSlotTag(wordSet, slot, str, 0, 1, 2);
        STRBUF_Delete(str);
        break;
    }
    case 1:
    case 8:
        if (kind == 1)
            msgData = (struct MsgBank *)MSGDATA_CreateFromArchive(0, 2, 0x4F, heapId);
        else
            msgData = (struct MsgBank *)MSGDATA_CreateFromArchive(0, 2, 0x11A, heapId);
        str = MSGDATA_AllocString((struct MsgBank *)msgData, arg + 3);
        WORDSET_SetSlotTag(wordSet, slot, str, 0, 1, 2);
        STRBUF_Delete(str);
        MSGDATA_Delete((struct MsgBank *)msgData);
        break;
    case 2:
        str = MUSICAL_EVENT_AllocTitleString((struct MusicalEventWork *)(*((void **)GAME_DATA_GetExternalWork(gameData))), heapId);
        WORDSET_SetSlotTag(wordSet, slot, str, 0, 1, 2);
        STRBUF_Delete(str);
        break;
    case 3:
        msgData = (struct MsgBank *)MSGDATA_CreateFromArchive(0, 2, 0x4B, heapId);
        str = MSGDATA_AllocString((struct MsgBank *)msgData, arg);
        WORDSET_SetSlotTag(wordSet, slot, str, 0, 1, 2);
        STRBUF_Delete(str);
        MSGDATA_Delete((struct MsgBank *)msgData);
        break;
    case 4:
        msgData = (struct MsgBank *)MSGDATA_CreateFromArchive(0, 2, 0x4B, heapId);
        str = MSGDATA_AllocString((struct MsgBank *)msgData, arg + 4);
        WORDSET_SetSlotTag(wordSet, slot, str, 0, 1, 2);
        STRBUF_Delete(str);
        MSGDATA_Delete((struct MsgBank *)msgData);
        break;
    case 5:
        MUSICAL_EVENT_SetPlayerNameWord(*((void **)GAME_DATA_GetExternalWork(gameData)), arg, wordSet, slot);
        break;
    case 6:
        MUSICAL_EVENT_SetPokemonNameWord(*((void **)GAME_DATA_GetExternalWork(gameData)), arg, wordSet, slot);
        break;
    case 7: {
        struct MusicalSave *musical = (struct MusicalSave *)GAME_DATA_GetSaveBlock2A(SCRCMD_WORK_GetGameData(scriptWork));
        u16 labelIds[3];
        u8 slotOrder[4];
        u8 slotValue[4];
        u8 i;
        u8 j;

        /* sort the four slots by value, descending (bubble sort) */
        for (i = 0; i < 4; i++) {
            slotOrder[i] = i;
            slotValue[i] = MUSICAL_SAVE_GetEquippedProp(musical, i);
        }
        for (i = 1; i < 4; i++) {
            for (j = 0; j < 4 - i; j++) {
                u8 next = j + 1;

                if (slotValue[j] < slotValue[next]) {
                    u8 tmp = slotValue[j];

                    slotValue[j] = slotValue[next];
                    slotValue[next] = tmp;
                    tmp = slotOrder[j];
                    slotOrder[j] = slotOrder[next];
                    slotOrder[next] = tmp;
                }
            }
        }
        if (slotValue[0] == slotValue[1] && slotValue[0] == slotValue[2]) {
            labelIds[0] = 9;
            labelIds[1] = 8;
        } else {
            labelIds[0] = slotOrder[0] + 4;
            if (slotValue[1] == slotValue[2])
                labelIds[1] = 8;
            else
                labelIds[1] = slotOrder[1] + 4;
        }
        if (slotValue[1] == slotValue[3])
            labelIds[2] = slotOrder[1] + 4;
        else if (slotValue[2] == slotValue[3])
            labelIds[2] = slotOrder[2] + 4;
        else
            labelIds[2] = slotOrder[3] + 4;
        msgData = (struct MsgBank *)MSGDATA_CreateFromArchive(0, 2, 0x4B, heapId);
        for (i = 0; i < 3; i++) {
            str = MSGDATA_AllocString((struct MsgBank *)msgData, labelIds[i]);
            WORDSET_SetSlotTag(wordSet, i, str, 0, 1, 2);
            STRBUF_Delete(str);
        }
        MSGDATA_Delete((struct MsgBank *)msgData);
        break;
    }
    }
    return 0;
}

/* Script command: clear the rank byte of a musical program slot. */
int SCRCMD_MUSICAL_ResetProgramRank(ScriptVm *vm, struct ScrcmdWork *scriptWork)
{
    int slot = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    MusicalProgram *program = MUSICAL_SAVE_GetProgram((struct MusicalSave *)GAME_DATA_GetSaveBlock2A(SCRCMD_WORK_GetGameData(scriptWork)), (u8)slot);

    program->rank = 0;
    return 0;
}

/* Script command: open the party selection screen; the two script variables receive the choice. */
int SCRCMD_MUSICAL_SelectPartyMon(ScriptVm *vm, struct ScrcmdWork *scriptWork)
{
    u16 *partyIndexVar = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    struct ScriptWork *scriptCtl = SCRCMD_WORK_GetScriptWork(scriptWork);

    SCRIPT_SYS_CallEvent((void *)scriptCtl, EVENT_POKE_STATUS_CreatePokeSelectStatusEvent(SCRCMD_WORK_GetGameSystem(scriptWork), partyIndexVar, resultVar));
    return 1;
}

/*
 * Script command: link-session control. Reads a sub-command, an argument
 * and a result variable, then opens or closes the link work (0, 1), starts
 * the ov132 session steps (10..18, most of which install a wait callback and
 * suspend the script) or reports the session state into the variable (19..21).
 *
 * The empty `case 100: break;` is what leaves the lone `cmp r6, #0x64`.
 * ov100_id is the overlay id of the ov100 proc (the symbol value is 0x64).
 */
int SCRCMD_MUSICAL_LinkControl(ScriptVm *vm, struct ScrcmdWork *scriptWork)
{
    struct ScriptWork *scriptCtl;
    struct GameSystem *gameSys;
    struct GameData *gameData;
    struct FieldMap *fieldMap;
    u16 cmd;
    u16 arg;
    u16 *resultVar;
    int busy;
    MusicalLink *link;

    scriptCtl = SCRCMD_WORK_GetScriptWork(scriptWork);
    gameSys = SCRCMD_WORK_GetGameSystem(scriptWork);
    gameData = SCRCMD_WORK_GetGameData(scriptWork);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSys);
    cmd = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    arg = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    busy = 0;
    link = 0;
    if (cmd != 0 && cmd != 0x15) {
        link = GAME_DATA_GetExternalWork(gameData);
        if (link->owner != 0) {
            MUSICAL_EVENT_CheckNetError((struct MusicalEventWork *)link->owner);
            if (MUSICAL_EVENT_IsAborted((struct MusicalEventWork *)link->owner) == 1)
                busy = 1;
        }
    }
    switch (cmd) {
    case 0:
        SCRCMD_MUSICAL_CreateLinkWork(scriptCtl, gameData);
        break;
    case 1:
        SCRCMD_MUSICAL_DeleteLinkWork(link, gameData);
        break;
    case 10:
        SCRCMD_MUSICAL_BeginCommSession(link, gameSys, GAMESYSTEM_GetGameComm(gameSys), arg);
        break;
    case 11:
        SCRCMD_MUSICAL_CloseCommSession(link);
        VM_SetWait(vm, SCRCMD_MUSICAL_WaitCommIdle);
        return 1;
    case 12:
        link->resultOut = resultVar;
        link->entryMenu = COMM_ENTRY_MENU_Create(GAME_DATA_GetMyStatus(gameData), fieldMap, 2, 4, 4, 0, 1, 0);
        VM_SetWait(vm, SCRCMD_MUSICAL_WaitEntryMenuParent);
        return 1;
    case 13:
        link->resultOut = resultVar;
        link->entryMenu = COMM_ENTRY_MENU_Create(GAME_DATA_GetMyStatus(gameData), fieldMap, 2, 4, 4, 1, 1, 0);
        VM_SetWait(vm, SCRCMD_MUSICAL_WaitEntryMenuChild);
        return 1;
    case 14:
        if (link->session == 0 || busy != 0)
            break;
        link->memberCount = arg;
        MUS_COMM_FUNC_SetTimingSync((sptr)link->session, (u8)link->memberCount);
        VM_SetWait(vm, SCRCMD_MUSICAL_WaitSetMemberCount);
        return 1;
    case 15:
        if (link->session == 0 || busy != 0)
            break;
        VM_SetWait(vm, SCRCMD_MUSICAL_WaitSessionReady);
        return 1;
    case 16:
        VM_SetWait(vm, SCRCMD_MUSICAL_WaitCommAttach);
        return 1;
    case 17:
        if (link->session == 0 || busy != 0)
            break;
        VM_SetWait(vm, SCRCMD_MUSICAL_WaitSessionFinish);
        return 1;
    case 18: {
        MusicalLinkWait *wait = GFL_HEAP_Alloc(0x8004, sizeof(*wait), (u32)1, d_02172914, (u32)0x3C8);

        wait->scriptWork = scriptWork;
        wait->link = link;
        link->resultOut = resultVar;
        link->gameData = gameData;
        link->procWork = STA_SLOT_GetRecordTable(gameData);
        link->procMode = arg == 0 ? 9 : 10;
        SCRIPT_SYS_CallEvent((void *)scriptCtl, FIELD_STATUS_CreateSubProcCallbackEvent(gameSys, fieldMap, (uptr)ov100_id, d_021BB6A4, &link->gameData, SCRCMD_MUSICAL_LinkProcCallback, wait));
        return 1;
    }
    case 19:
        if (link->session != 0 && busy == 1)
            *resultVar = 1;
        else
            *resultVar = 0;
        break;
    case 20:
        if (link->session != 0)
            *resultVar = 1;
        else
            *resultVar = 0;
        break;
    case 21:
        if (GFL_NET_ERR_GetErrorLevel() != 0) {
            GAMESYSTEM_SetFieldMapState(gameSys, 1);
            *resultVar = 1;
        } else {
            *resultVar = 0;
        }
        break;
    case 100:
        break;
    }
    return 0;
}

/*
 * Allocate the 0x38-byte link work, clear its first two words, attach it to
 * the game data external-work slot and load overlays 132 and 112.
 */
void SCRCMD_MUSICAL_CreateLinkWork(struct ScriptWork *unused, struct GameData *gameData)
{
    MusicalLink *link = GFL_HEAP_Alloc(4, sizeof(*link), 1, d_02172914, 0x413);

    link->owner = 0;
    link->session = 0;
    GAME_DATA_SetExternalWork(gameData, link);
    GF_OVERLAY_Load((uptr)ov132_id);
    GF_OVERLAY_Load((uptr)ov112_id);
}

/* Unload overlays 112 and 132, free the link work and detach it. */
void SCRCMD_MUSICAL_DeleteLinkWork(MusicalLink *link, struct GameData *gameData)
{
    GF_OVERLAY_Unload((uptr)ov112_id);
    GF_OVERLAY_Unload((uptr)ov132_id);
    GFL_HEAP_Free(link);
    GAME_DATA_SetExternalWork(gameData, 0);
}

/*
 * Forwards three of its four incoming argument registers to a callee whose
 * first parameter is the constant 4. The callee takes four arguments, so a
 * tail call is impossible (bx would spend an argument register on the
 * target), which is why the image keeps a frame and emits a direct bl.
 */
void SCRCMD_MUSICAL_BeginCommSession(void *link, struct GameSystem *gameSys, struct GameComm *gameComm, int arg)
{
    MUS_COMM_FUNC_Create(4, (void *)gameSys, (void *)gameComm, arg);
}

/* Close the comm session of the link work, if any. */
void SCRCMD_MUSICAL_CloseCommSession(MusicalLink *link)
{
    if (link->session != 0) {
        MUS_COMM_FUNC_Delete(link->session);
        link->session = 0;
    }
}

/*
 * Event task of StartMusical (states 0..3): call the link event, close the
 * session, wait for the comm (when mode 1), then free the link work.
 * Lever: the game data pointer stays live in r0 across the switch for
 * GAME_DATA_GetBgmInfo. Two zero alignment bytes follow the 150-byte function.
 */
int SCRCMD_MUSICAL_TaskStartMusical(struct GameEvent *task, int *state, void *work)
{
    MusicalStartTask *startTask = work;
    struct GameData *gameData;

    gameData = GAMESYSTEM_GetGameData(GAME_EVENT_GetGameSystem(task));
    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent(task, startTask->musicalSeq);
        (*state)++;
        break;
    case 1:
        GAME_DATA_GetBgmInfo(gameData);
        SCRCMD_MUSICAL_CloseCommSession(startTask->link);
        (*state)++;
        break;
    case 2:
        {
            struct GameComm *gameComm = GAMESYSTEM_GetGameComm(GAME_EVENT_GetGameSystem(task));
            if (startTask->mode != 0) {
                if (GAME_COMM_GetKind(gameComm) != 0)
                    break;
            }
        }
        (*state)++;
        break;
    case 3:
        if (GFL_NET_IsSessionNull() != 1) {
            if (startTask->mode != 0)
                break;
        }
        if (startTask->mode == 1) {
            GAMESYSTEM_TryStartAutoComm(GAME_EVENT_GetGameSystem(task));
        }
        SCRCMD_MUSICAL_DeleteLinkWork(startTask->link, gameData);
        (*state)++;
        return 1;
    }
    return 0;
}

/*
 * Event task of ShowPartyMonMusical: runs the proc MUSICAL_DRESSUP_SYS_ProcTable on the musical
 * system arguments, then frees the system and the argument block.
 */
int SCRCMD_MUSICAL_TaskShowMusicalProc(struct GameEvent *task, int *state, void *work)
{
    MusicalSystemTask *systemTask = work;
    struct GameSystem *gameSys = GAME_EVENT_GetGameSystem(task);

    GAMESYSTEM_GetGameData(gameSys);
    GAMESYSTEM_GetFieldMap(gameSys);
    switch (*state) {
    case 0:
        (*state)++;
        break;
    case 1:
        (*state)++;
        break;
    case 2:
        (*state)++;
        break;
    case 3:
        GAMESYSTEM_CallProc(gameSys, -1, &MUSICAL_DRESSUP_SYS_ProcTable, systemTask->args);
        (*state)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(gameSys) != 0)
            break;
        (*state)++;
        break;
    case 5:
        (*state)++;
        break;
    case 6:
        GFL_HEAP_Free(systemTask->args->musicalSystem);
        GFL_HEAP_Free(systemTask->args);
        return 1;
    }
    return 0;
}

/* Proc callback: free the argument block of the ov112 proc. */
void SCRCMD_MUSICAL_FreeProcArgs(void *callbackArg)
{
    MusicalProcBox *box = callbackArg;

    GFL_HEAP_Free(box->args);
}

/*
 * Callback of the ov100 proc: set the result variable to 1 (0 when the proc
 * mode is 12 or 13) and close the comm session otherwise.
 */
void SCRCMD_MUSICAL_LinkProcCallback(void *callbackArg)
{
    MusicalLinkWait *wait = callbackArg;
    struct GameSystem *gameSys;
    struct GameData *gameData;
    MusicalLink *link;

    gameSys = SCRCMD_WORK_GetGameSystem(wait->scriptWork);
    gameData = SCRCMD_WORK_GetGameData(wait->scriptWork);
    GAMESYSTEM_GetGameComm(gameSys);
    link = wait->link;
    if (link->procMode != 0xc && link->procMode != 0xd) {
        *link->resultOut = 1;
        MUS_COMM_FUNC_InitCommandTable(wait->link->session);
    } else {
        *link->resultOut = 0;
    }
}

/* Wait: entry menu opened as parent. Result 0 = accepted, 1 = declined, 2 = cancelled. */
int SCRCMD_MUSICAL_WaitEntryMenuParent(ScriptVm *vm, void *scriptWork)
{
    MusicalLink *link;
    int done;
    int status;

    SCRCMD_WORK_GetScriptWork(scriptWork);
    link = GAME_DATA_GetExternalWork(SCRCMD_WORK_GetGameData(scriptWork));
    status = (s32)COMM_ENTRY_MENU_Main(link->entryMenu);
    done = 0;
    switch (status) {
    case 1:
        *link->resultOut = 0;
        MUS_COMM_FUNC_SetHostFlag(link->session);
        done = 1;
        break;
    case 2:
        *link->resultOut = 1;
        done = 1;
        break;
    case 4:
        *link->resultOut = 2;
        done = 1;
        break;
    }
    if (done == 1) {
        (s32)COMM_ENTRY_MENU_Delete(link->entryMenu);
        link->entryMenu = 0;
    }
    return done;
}

/* Wait: entry menu opened as child. Result 3 = accepted, 4 = declined, 2 = cancelled. */
int SCRCMD_MUSICAL_WaitEntryMenuChild(ScriptVm *vm, void *scriptWork)
{
    MusicalLink *link;
    int done;
    int result;

    SCRCMD_WORK_GetScriptWork(scriptWork);
    link = GAME_DATA_GetExternalWork(SCRCMD_WORK_GetGameData(scriptWork));
    done = 0;
    switch ((s32)COMM_ENTRY_MENU_Main(link->entryMenu)) {
    case 1:
        *link->resultOut = 3;
        MUS_COMM_FUNC_SetHostFlag(link->session);
        done = 1;
        break;
    case 2:
        result = 4;
        *link->resultOut = result;
        done = 1;
        break;
    case 4:
        result = 2;
        *link->resultOut = result;
        done = 1;
        break;
    }
    if (done == 1) {
        (s32)COMM_ENTRY_MENU_Delete(link->entryMenu);
        link->entryMenu = 0;
    }
    return done;
}

/* Wait: member count set on the session (command 14). */
int SCRCMD_MUSICAL_WaitSetMemberCount(ScriptVm *vm, void *scriptWork)
{
    MusicalLink *link;

    SCRCMD_WORK_GetScriptWork(scriptWork);
    link = GAME_DATA_GetExternalWork(SCRCMD_WORK_GetGameData(scriptWork));
    if (link->owner != 0) {
        MUSICAL_EVENT_CheckNetError((struct MusicalEventWork *)link->owner);
        if (MUSICAL_EVENT_IsAborted((struct MusicalEventWork *)link->owner) == 1)
            return 1;
    }
    if (MUS_COMM_FUNC_CheckTimingSync(link->session, (u8)link->memberCount) == 1)
        return 1;
    return 0;
}

/* Wait: session ready (command 15). */
int SCRCMD_MUSICAL_WaitSessionReady(ScriptVm *vm, void *scriptWork)
{
    MusicalLink *link;

    SCRCMD_WORK_GetScriptWork(scriptWork);
    link = GAME_DATA_GetExternalWork(SCRCMD_WORK_GetGameData(scriptWork));
    MUSICAL_EVENT_CheckNetError((struct MusicalEventWork *)link->owner);
    if (MUSICAL_EVENT_IsAborted((struct MusicalEventWork *)link->owner) == 1)
        return 1;
    if (STA_NET_GetSlot3Done(link->session) == 1)
        return 1;
    return 0;
}

/* Wait: attach the link work to the comm session once the comm kind is 4 (command 16). */
int SCRCMD_MUSICAL_WaitCommAttach(ScriptVm *vm, void *scriptWork)
{
    struct GameSystem *gameSys;
    struct GameData *gameData;
    struct GameComm *gameComm;
    MusicalLink *link;

    SCRCMD_WORK_GetScriptWork(scriptWork);
    gameSys = SCRCMD_WORK_GetGameSystem(scriptWork);
    gameData = SCRCMD_WORK_GetGameData(scriptWork);
    gameComm = GAMESYSTEM_GetGameComm(gameSys);
    link = GAME_DATA_GetExternalWork(gameData);
    if (GAME_COMM_GetKind(gameComm) == 4) {
        link->session = (void *)GAME_COMM_GetWork(gameComm);
        return 1;
    }
    return 0;
}

/* Wait: the comm is gone and the musical event is idle (command 11). */
int SCRCMD_MUSICAL_WaitCommIdle(ScriptVm *vm, void *scriptWork)
{
    struct GameComm *gameComm;
    struct GameSystem *gameSys;
    struct GameData *gameData;
    MusicalLink *link;

    SCRCMD_WORK_GetScriptWork(scriptWork);
    gameSys = SCRCMD_WORK_GetGameSystem(scriptWork);
    gameData = SCRCMD_WORK_GetGameData(scriptWork);
    gameComm = GAMESYSTEM_GetGameComm(gameSys);
    link = GAME_DATA_GetExternalWork(gameData);
    if (link->owner != 0) {
        MUSICAL_EVENT_CheckNetError((struct MusicalEventWork *)link->owner);
        if (MUSICAL_EVENT_IsAborted((struct MusicalEventWork *)link->owner) == 1) {
            return 1;
        }
    }
    if (GAME_COMM_GetKind(gameComm) == 0) {
        return 1;
    }
    return 0;
}

/* Wait: session finished (command 17). */
int SCRCMD_MUSICAL_WaitSessionFinish(ScriptVm *vm, void *scriptWork)
{
    MusicalLink *link;

    SCRCMD_WORK_GetScriptWork(scriptWork);
    link = GAME_DATA_GetExternalWork(SCRCMD_WORK_GetGameData(scriptWork));
    MUSICAL_EVENT_CheckNetError((struct MusicalEventWork *)link->owner);
    if (MUSICAL_EVENT_IsAborted((struct MusicalEventWork *)link->owner) == 1)
        return 1;
    if (STA_NET_GetRecordsReceived(link->session) == 1)
        return 1;
    return 0;
}

/*
 * Script command with a six-way sub-command switch over an ov021 service
 * (0x021B76B4..0x021B7794) on the wifi list GAME_SYNC_GetBlock returns;
 * sub-commands 0, 1 and 4 write a halfword result through the result
 * variable, 5 formats a value into the word set.
 */
int SCRCMD_MUSICAL_WifiListCommand(ScriptVm *vm, struct ScrcmdWork *scriptWork)
{
    u32 cmd;
    u16 *resultVar;
    u16 key;
    struct GameSystem *gameSys;
    struct GameData *gameData;
    struct CgearSaveBlock *wifiList;
    u32 limit;
    void *postEvent;
    struct WordSet *wordSet;

    cmd = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    key = SCRCMD_WORK_GetHeapId(scriptWork);
    gameSys = SCRCMD_WORK_GetGameSystem(scriptWork);
    gameData = SCRCMD_WORK_GetGameData(scriptWork);
    wifiList = (struct CgearSaveBlock *)GAME_SYNC_GetBlock(GAME_DATA_GetSaveControl(gameData));
    limit = (int)BLOCK20_SAVEDATA_CountEntries(wifiList);
    if (GAMESYSTEM_GetFieldMap(gameSys) == 0 && cmd != 0) {
        return 0;
    }
    switch (cmd) {
    case 0:
        *resultVar = (int)BLOCK20_SAVEDATA_CountEntries(wifiList) > 0 ? 1 : 0;
        break;
    case 1:
        if (PDW_POSTMAN_CountUnreceivable(gameData, key, (struct PdwPostmanSave *)wifiList) < limit) {
            *resultVar = 1;
        } else {
            *resultVar = 0;
        }
        break;
    case 2:
        postEvent = (void *)PDW_POSTMAN_CreateListEvent(gameSys);
        SCRIPT_SYS_CallEvent((void *)SCRCMD_WORK_GetScriptWork(scriptWork), postEvent);
        return 1;
    case 3:
        PDW_POSTMAN_ReceiveItems(gameData, key, (struct PdwPostmanSave *)wifiList);
        break;
    case 5:
        wordSet = (struct WordSet *)SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(scriptWork));
        WORDSET_SetSlotFromMsg118(wordSet, 0, PDW_POSTMAN_GetUnreceivableItem(gameData, key, (void *)wifiList, *resultVar));
        break;
    case 4:
        *resultVar = PDW_POSTMAN_CountUnreceivable(gameData, key, (struct PdwPostmanSave *)wifiList);
        break;
    }
    return 0;
}
