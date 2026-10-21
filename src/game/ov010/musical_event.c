/*
 * file:     musical_event.c
 * unit:     yes
 * function: MUSICAL_EVENT_Create, MUSICAL_EVENT_Main, MUSICAL_EVENT_CreateLocalPerformer, MUSICAL_EVENT_Free, MUSICAL_EVENT_CreateDressupParam, MUSICAL_EVENT_SendLocalPerformer, MUSICAL_EVENT_CreateStage, MUSICAL_EVENT_ScorePerformers, MUSICAL_EVENT_CreateShowRecord, MUSICAL_EVENT_ApplyResults, MUSICAL_EVENT_RollProgramRewards, MUSICAL_EVENT_RunLeaveSequence, MUSICAL_EVENT_RunEnterSequence, MUSICAL_EVENT_SpawnSeatEffect, MUSICAL_EVENT_SpawnExitEffect, MUSICAL_EVENT_ShowMessage, MUSICAL_EVENT_CountNpcSlotsBelow, MUSICAL_EVENT_GetLocalSlot, MUSICAL_EVENT_GetPlayerOfSlot, MUSICAL_EVENT_GetProgramBestCategory, MUSICAL_EVENT_AllocTitleString, MUSICAL_EVENT_GetScoreCapped, MUSICAL_EVENT_GetMaxScore, MUSICAL_EVENT_GetMinScore, MUSICAL_EVENT_GetSlotOfRank, MUSICAL_EVENT_GetBestAppealCategory, MUSICAL_EVENT_GetPortraitClass, MUSICAL_EVENT_SetPlayerNameWord, MUSICAL_EVENT_SetPokemonNameWord, MUSICAL_EVENT_ReceiveShowProgram, MUSICAL_EVENT_CheckNetError, MUSICAL_EVENT_IsAborted
 * address:  0x02155A98
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from musical_dressup_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_BEACON_SEARCH_SetNamedEvent  0x0216576C  thumb  ov010
 *   MUSICAL_MCSS_AllocDistSave  0x021F685C  thumb  ov112
 *   MUSICAL_MCSS_LoadDistSave  0x021F68BC  thumb  ov112
 *   STA_NET_GetRole  0x021FD904  thumb  ov132
 *   MUS_COMM_FUNC_InitWork  0x021FC848  thumb  ov132
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   GAME_DATA_GetSaveBlock2A  0x02012F44  thumb
 *   MUSICAL_SAVE_GetScriptSetting  0x0200A7C8  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   POKE_TOOL_CastToBoxParam  0x020185F0  thumb
 *   MUSICAL_SAVE_GetFanPoints  0x0200A81C  thumb
 *   GFL_USE_GetRandomBelow  0x02005728  thumb
 *   STA_NET_GetBoxesReceived  0x021FD908  thumb  ov132
 *   STA_NET_SetState6Pair  0x021FD918  thumb  ov132
 *   STA_NET_GetCurrentSlotValue  0x021FD8D4  thumb  ov132
 *   STA_NET_GetSlotValueByIndex  0x021FD8EC  thumb  ov132
 *   MUS_COMM_FUNC_GetSlotValueA  0x021FCE28  thumb  ov132
 *   STA_NET_GetSlot1Done  0x021FD83C  thumb  ov132
 *   MET_TRAINERS_GetFromSave  0x0200ED48  thumb
 *   MET_TRAINERS_Insert  0x0200ED54  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   GFL_NET_ERR_RequestScreen  0x0200FB38  thumb
 *   GFL_HEAP_DumpReport  0x02030B50  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   MUSICAL_DRESSUP_SYS_ProcTable     0x02172724  data
 *   MUSICAL_STAGE_SYS_ProcTable     0x02172748  data
 *   d_021F8360     0x021F8360  data
 *   MUSICAL_MCSS_CreateMon  0x021F675C  thumb
 *   STA_NET_BeginKind5Phase  0x021FD938  thumb  ov132
 *   MUSICAL_MCSS_FreeDistSave  0x021F6888  thumb
 *   STA_NET_SetState18Value  0x021FD948  thumb  ov132
 *   STA_NET_FindRecValueByKey  0x021FD4F8  thumb  ov132
 *   STA_SLOT_GetSub  0x021FD964  thumb  ov132
 *   MUSICAL_MCSS_LoadActorData  0x021F4F14  thumb  ov112
 *   MUSICAL_MCSS_GetElemA  0x021F5140  thumb  ov112
 *   MUSICAL_MCSS_FreeActorData  0x021F4F40  thumb  ov112
 *   GF_STANDARD_GetCachedDate  0x0203F4E4  arm
 *   STRBUF_ToChars  0x02045A38  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   MUSICAL_SAVE_GetFromSave  0x0200A5F8  thumb
 *   sMusicalEventFileName  0x02172714  data
 *   MUSICAL_SAVE_IncrementShowCount  0x0200A768  thumb
 *   MUSICAL_SAVE_IncrementTopRankCount  0x0200A788  thumb
 *   MUSICAL_SAVE_SetSelectedProgram  0x0200A7C0  thumb
 *   MUSICAL_SAVE_AddFanPoints  0x0200A800  thumb
 *   MUSICAL_SAVE_SetEquippedProp  0x0200A7AC  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   NATSUKI_Calc  0x0201B7A0  thumb
 *   RECORD_AddOne  0x02008DF0  thumb
 *   RECORD_AddCounter  0x02008DAC  thumb
 *   MUSICAL_SAVE_GetProgram  0x0200A750  thumb
 *   STA_NET_GetSlotWordByIndex  0x021FD8F8  thumb  ov132
 *   MUSICAL_SAVE_IsPropOwned  0x0200A644  thumb
 *   d_0216FF14  0x0216FF14  data
 *   d_0216FF28  0x0216FF28  data
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_StartPopTask  0x02029690  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   FIELD_SOUND_SYSTEM_StartPushTask  0x020295A4  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitSettledTask  0x02029C64  thumb
 *   EVENT_MAPCHANGE_CreateWarpEventDefaultTransition  0x021854B0  thumb  ov020
 *   d_0216FEFC  0x0216FEFC  data
 *   d_0216FEF0  0x0216FEF0  data
 *   d_0216FF08  0x0216FF08  data
 *   SCRIPT_SYS_CreateScriptEventSimple   0x02158768  thumb  ov010
 *   SCRIPT_SYS_GetEventScriptWork   0x021589D0  thumb  ov010
 *   MSGDATA_CreateFromMemory  0x02045C44  arm
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   MUS_COMM_FUNC_GetSlotValueB  0x021FCE44  thumb  ov132
 *   WORDSET_SetSlotMonNickname  0x0201EEF4  thumb
 *   WORDSET_SetSlotMonNicknameAlt  0x0201EF14  thumb
 *   STA_NET_GetPairA  0x021FD954  thumb  ov132
 *   STA_NET_GetPairB  0x021FD95C  thumb  ov132
 *   MUSICAL_DRESSUP_SYS_Create 0x02156CAC thumb ov010
 *   MUSICAL_DRESSUP_SYS_Delete 0x02156CD8 thumb ov010
 *   MUSICAL_STAGE_SYS_Create 0x02156F68 thumb ov010
 *   MUSICAL_STAGE_SYS_Delete 0x02156F98 thumb ov010
 *   MUSICAL_STAGE_SYS_SetLocalPerformer 0x02156FC4 thumb ov010
 *   MUSICAL_STAGE_SYS_SetRemotePerformer 0x02157000 thumb ov010
 *   MUSICAL_PROGRAM_Create 0x02157028 thumb ov010
 *   MUSICAL_PROGRAM_Delete 0x0215716C thumb ov010
 *   MUSICAL_PROGRAM_SplitBonus 0x02157174 thumb ov010
 *   MUSICAL_PROGRAM_PackBonus 0x02157260 thumb ov010
 *   MUSICAL_PROGRAM_UnpackBonus 0x02157278 thumb ov010
 *   MUSICAL_PROGRAM_PackPicks 0x02157298 thumb ov010
 *   MUSICAL_PROGRAM_UnpackPicks 0x021572A8 thumb ov010
 *   MUSICAL_PROGRAM_GetBestCategory 0x021572C0 thumb ov010
 *   MUSICAL_PROGRAM_CreateNpcPerformer 0x021572E4 thumb ov010
 *   MUSICAL_PROGRAM_GetBaseProgramId 0x02157364 thumb ov010
 *   MUSICAL_PROGRAM_GetPropRow 0x0215736C thumb ov010
 *   MUSICAL_PROGRAM_GetNpcPortraitClass 0x02157374 thumb ov010
 *   MUSICAL_PROGRAM_GetNpcNameId 0x02157384 thumb ov010
 *   MUSICAL_PROGRAM_GetCategoryShare 0x02157394 thumb ov010
 */
#include "event_ircbattle_shared_types.h"
#include "musical_event_shared_types.h"

#include "../arm9/musical_save_types.h"

typedef struct MusicalShowEquip {
    u16 propId;                         /* 0xFF = none */
    s16 offset;
    u8 bodySlot;                        /* 10 = none */
    u8 pad[3];
} MusicalShowEquip;

typedef struct MusicalShowPerformer {
    u16 monsNo;
    u16 gender : 2;
    u16 shiny : 1;
    u16 form : 5;
    u32 personality;
    u8 name[0x10];
    MusicalShowEquip props[8];
} MusicalShowPerformer;

/* The record of one show, stored in the musical save (0x1B0 bytes). */
typedef struct MusicalShowRecord {
    u32 programId : 5;
    u32 winnerMask : 4;
    u32 year : 7;
    u32 month : 5;
    u32 day : 6;
    u32 localSlot : 2;
    u32 reserved : 3;
    MusicalShowPerformer performers[MUSICAL_PERFORMERS];
    u16 title[0x25];
    u8 showType;
    u8 valid;
} MusicalShowRecord;

/* What the show screen reads (0x14 bytes, heap). */
typedef struct MusicalShowResult {
    u32 ready;                          /* 0x00 */
    u32 state;                          /* 0x04 */
    MusicalShowRecord *record;          /* 0x08 */
    struct MusicalSave *save;           /* 0x0C */
    void *session;                      /* 0x10 */
} MusicalShowResult;

/* Session back pointer used by the link sequence. */
#include "musical_link_types.h"

/* Work of the musical show event task (0x54 bytes). */
typedef struct MusicalEventWork {
    void *gameSys;                      /* 0x00 */
    void *gameData;                     /* 0x04 */
    MusicalLink *link;                  /* 0x08 */
    u32 state;                          /* 0x0C */
    u8 step;                            /* 0x10: sub-step of the fade sequences */
    u8 pad11[3];
    u32 linkMode;                       /* 0x14: 1 = wireless session */
    void *ownMon;                       /* 0x18 */
    void *saveControl;                  /* 0x1C */
    void *gameComm;                     /* 0x20 */
    MusicalSystemHead *musicalSystem;   /* 0x24 */
    void *session;                      /* 0x28 */
    MusicalDressupParam *dressup;       /* 0x2C */
    MusicalStage *stage;                /* 0x30 */
    MusicalShowResult *result;          /* 0x34 */
    MusicalShowProgram *program;        /* 0x38 */
    MusicalPerformer *localPerformer;   /* 0x3C */
    struct MusicalSave *save;           /* 0x40 */
    u8 playerSlot[4];                   /* 0x44: stage slot of each player */
    u8 rankOrder[4];                    /* 0x48: stage slot of each rank */
    u8 localSlot;                       /* 0x4C */
    u8 pad4D[3];
    u32 aborted;                        /* 0x50 */
} MusicalEventWork;

enum {
    MUSICAL_EVENT_STATE_ENTER_CLOSE = 0,
    MUSICAL_EVENT_STATE_ENTER_DONE = 1,
    MUSICAL_EVENT_STATE_FINISH = 2,
    MUSICAL_EVENT_STATE_START_DRESSUP = 3,
    MUSICAL_EVENT_STATE_WAIT_DRESSUP = 4,
    MUSICAL_EVENT_STATE_START_STAGE = 5,
    MUSICAL_EVENT_STATE_WAIT_STAGE = 6,
    MUSICAL_EVENT_STATE_START_SHOW = 7,
    MUSICAL_EVENT_STATE_WAIT_SHOW = 8,
    MUSICAL_EVENT_STATE_THANKS = 9,
    MUSICAL_EVENT_STATE_END = 10,
    MUSICAL_EVENT_STATE_LINK_WAIT_PEERS = 11,
    MUSICAL_EVENT_STATE_LINK_WAIT_START = 12,
    MUSICAL_EVENT_STATE_SPAWN_MARKER = 13,
    MUSICAL_EVENT_STATE_CREATE_PERFORMER = 14,
    MUSICAL_EVENT_STATE_LEAVE_DRESSUP = 16,
    MUSICAL_EVENT_STATE_MESSAGE_STAGE = 17,
    MUSICAL_EVENT_STATE_ENTER_STAGE = 18,
    MUSICAL_EVENT_STATE_LEAVE_SHOW = 19,
    MUSICAL_EVENT_STATE_MESSAGE_SHOW = 20,
    MUSICAL_EVENT_STATE_ABORT_LEAVE = 22,
    MUSICAL_EVENT_STATE_ABORT_NET = 23,
    MUSICAL_EVENT_STATE_ABORT_CLEANUP = 24,
    MUSICAL_EVENT_STATE_ABORT_WAIT = 25,
    MUSICAL_EVENT_STATE_ABORT_MESSAGE = 26
};

#include "../sdk_fx.h"
typedef VecFx32 Float3;

#include "../arm9/gf_standard_types.h"
struct GameSystem;

/* Callees outside this file (named tree-wide by the integrator's rename map). */
#include "../arm9/gamesystem.h"
struct GameEvent;

struct FieldMap;
struct GameSystem;
struct GameEvent;

#include "../arm9/field_status.h"


struct GameData;


#include "../arm9/net_err.h"

#include "../arm9/game_data.h"

#include "../arm9/gfl_heap_wrap.h"




struct SaveControl;


#include "../arm9/gfl_heap.h"
struct GameComm;

struct Strbuf;

#include "../arm9/strbuf.h"

struct Party;
struct PokemonParam;

#include "../arm9/pokeparty.h"

#include "../arm9/poke_tool.h"

#include "game_beacon_set.h"



#include "../ov112/musical_system.h"

#include "../ov132/sta_net.h"

#include "../arm9/musical_save.h"

struct MyStatus;



#include "../ov132/mus_comm_func.h"


#include "../arm9/gfl_use.h"







#include "../arm9/met_trainers_savedata.h"
struct MetTrainersSave;


#include "../arm9/mystatus.h"







struct StaNetCtx;


#include "../ov132/sta_slot.h"

#include "../ov112/mus_item_data.h"



#include "../arm9/gf_standard.h"


#include "../arm9/mi_memory.h"
struct MsgBank;

#include "../arm9/msgdata.h"










#include "../arm9/natsuki.h"

#include "../arm9/record.h"






#include "../arm9/field_sound_system.h"





#ifdef __MWERKS__
extern struct GameEvent *SCRIPT_SYS_CreateScriptEventSimple(void *gameSys, int messageId, int c, int d); /* original prototype; the definition differs in pointer as integer, argument width */
#else
#include "script_sys.h"
#endif



struct WordSet;

#include "../arm9/wordset.h"







extern u8 d_021F8360[];

extern const char sMusicalEventFileName[];

extern u8 MUSICAL_DRESSUP_SYS_ProcTable[];

extern u8 MUSICAL_STAGE_SYS_ProcTable[];

extern const u16 d_0216FF14[10];

extern const u8 d_0216FF28[7][0x28];

#include "../ov020/event_mapchange.h"
struct PlayerWork;
extern const Float3 d_0216FEFC;

extern const Float3 d_0216FEF0;

extern const Float3 d_0216FF08;

struct GameEvent *MUSICAL_EVENT_Create(void *gameSys, void *gameData, u8 partyIndex, u32 linkMode, MusicalLink *link);

int MUSICAL_EVENT_Main(void *event, void *unused, MusicalEventWork *work);

void MUSICAL_EVENT_CreateLocalPerformer(MusicalEventWork *work);

int MUSICAL_EVENT_Free(MusicalEventWork *work);

MusicalDressupParam *MUSICAL_EVENT_CreateDressupParam(MusicalEventWork *work);

void MUSICAL_EVENT_SendLocalPerformer(MusicalEventWork *work);

void MUSICAL_EVENT_CreateStage(MusicalEventWork *work);

void MUSICAL_EVENT_ScorePerformers(MusicalEventWork *work);

void MUSICAL_EVENT_CreateShowRecord(MusicalEventWork *work);

void MUSICAL_EVENT_ApplyResults(MusicalEventWork *work);

void MUSICAL_EVENT_RollProgramRewards(MusicalEventWork *work);

int MUSICAL_EVENT_RunLeaveSequence(void *event, MusicalEventWork *work);

int MUSICAL_EVENT_RunEnterSequence(void *event, MusicalEventWork *work);

void MUSICAL_EVENT_SpawnSeatEffect(void *event, MusicalEventWork *work);

void MUSICAL_EVENT_SpawnExitEffect(void *event, MusicalEventWork *work);

void MUSICAL_EVENT_ShowMessage(void *event, MusicalEventWork *work, int messageId);

u8 MUSICAL_EVENT_CountNpcSlotsBelow(MusicalEventWork *work, u8 n);

u8 MUSICAL_EVENT_GetLocalSlot(MusicalEventWork *work);

u8 MUSICAL_EVENT_GetPlayerOfSlot(MusicalEventWork *work, u8 slot);

u8 MUSICAL_EVENT_GetProgramBestCategory(MusicalEventWork *work);

void *MUSICAL_EVENT_AllocTitleString(MusicalEventWork *work, int heapId);

u8 MUSICAL_EVENT_GetScoreCapped(MusicalEventWork *work, u8 slot);

u16 MUSICAL_EVENT_GetMaxScore(MusicalEventWork *work);

u16 MUSICAL_EVENT_GetMinScore(MusicalEventWork *work);

u8 MUSICAL_EVENT_GetSlotOfRank(MusicalEventWork *work, u8 rank);

u8 MUSICAL_EVENT_GetBestAppealCategory(MusicalEventWork *work, u8 slot);

u8 MUSICAL_EVENT_GetPortraitClass(MusicalEventWork *work, u8 slot);

void MUSICAL_EVENT_SetPlayerNameWord(MusicalEventWork *work, u8 slot, void *wordSet, u32 wordIndex);

void MUSICAL_EVENT_SetPokemonNameWord(MusicalEventWork *work, u8 slot, void *wordSet, u32 wordIndex);

void MUSICAL_EVENT_ReceiveShowProgram(MusicalEventWork *work);

void MUSICAL_EVENT_CheckNetError(MusicalEventWork *work);

u32 MUSICAL_EVENT_IsAborted(MusicalEventWork *work);

#include "musical_dressup_sys.h"


#include "musical_stage_sys.h"




#include "musical_program.h"
#include "../arm9/game_event.h"














/*
 * Creates the musical show event task (MUSICAL_EVENT_Main over a
 * MusicalEventWork) and either starts the wireless exchange (state 11) or
 * shuffles the four player slots and deals locally (state 13). The owner
 * back-pointer is stored through work->link while the session is read
 * through the parameter: storing through the parameter enregisters it
 * instead.
 */
struct GameEvent *MUSICAL_EVENT_Create(void *gameSys, void *gameData, u8 partyIndex, u32 linkMode, MusicalLink *link)
{
    struct GameEvent *event;
    MusicalEventWork *work;
    void *nickname;

    GFL_HEAP_CreateChildHeap(1, 0x802C, 0x42000);
    event = GAME_EVENT_Create(gameSys, 0, (GameEventFunc)MUSICAL_EVENT_Main, sizeof(MusicalEventWork));
    work = GAME_EVENT_GetWork(event);
    work->gameSys = gameSys;
    work->gameData = gameData;
    work->linkMode = linkMode;
    work->saveControl = GAME_DATA_GetSaveControl(gameData);
    work->gameComm = GAMESYSTEM_GetGameComm(gameSys);
    work->link = link;
    work->link->owner = work;
    work->session = link->session;
    work->aborted = 0;
    work->program = 0;
    nickname = STRBUF_Create(11, 4);
    work->ownMon = POKEPARTY_GetMember(GAME_DATA_GetMyParty(work->gameData), partyIndex);
    POKE_TOOL_GetPartyValue(work->ownMon, (unsigned int)0x73, (uptr)nickname);
    GAME_BEACON_SEARCH_SetNamedEvent(nickname);
    STRBUF_Delete(nickname);
    work->dressup = 0;
    work->stage = 0;
    work->result = 0;
    work->save = GAME_DATA_GetSaveBlock2A(gameData);
    work->musicalSystem = MUSICAL_MCSS_AllocDistSave(4);
    if (work->linkMode == 0 || STA_NET_GetRole(work->link->session) == 1)
        MUSICAL_MCSS_LoadDistSave((unsigned char *)work->musicalSystem, (uptr)work->saveControl, work->gameData, MUSICAL_SAVE_GetScriptSetting(work->save), 0x2C);
    if (work->linkMode == 1) {
        work->state = MUSICAL_EVENT_STATE_LINK_WAIT_PEERS;
        work->step = 0;
        MUS_COMM_FUNC_InitWork(work->session, (void *)(GAME_DATA_GetMyStatus(work->gameData)), (void *)(POKE_TOOL_CastToBoxParam(work->ownMon)), work->gameComm, work->musicalSystem, 4);
    } else {
        u16 maxLevel = MUSICAL_SAVE_GetFanPoints(work->save);
        u8 i;
        u8 j;
        u8 k;
        u8 temp;

        for (i = 0; i < 4; i++)
            work->playerSlot[i] = i;
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 4; j++) {
                k = GFL_USE_GetRandomBelow(4);
                temp = work->playerSlot[j];
                work->playerSlot[j] = work->playerSlot[k];
                work->playerSlot[k] = temp;
            }
        }
        work->localSlot = work->playerSlot[0];
        work->program = MUSICAL_PROGRAM_Create(4, work->musicalSystem, maxLevel);
        work->state = MUSICAL_EVENT_STATE_SPAWN_MARKER;
        work->step = 0;
    }
    return event;
}

/*
 * Task callback of the musical show event: the whole show flow, from the
 * wireless handshake through dress-up, stage, result screen and cleanup.
 */
int MUSICAL_EVENT_Main(void *event, void *unused, MusicalEventWork *work)
{
    MUSICAL_EVENT_CheckNetError(work);
    switch (work->state) {
    case MUSICAL_EVENT_STATE_LINK_WAIT_PEERS:
        if (STA_NET_GetBoxesReceived(work->link->session) == 1) {
            u32 packedBonus = 0;
            u32 packedPicks = 0;
            void *list;
            u8 i;

            if (STA_NET_GetRole(work->link->session) == 1) {
                work->program = MUSICAL_PROGRAM_Create(4, work->musicalSystem, MUSICAL_SAVE_GetFanPoints(work->save));
                packedBonus = MUSICAL_PROGRAM_PackBonus(work->program);
                packedPicks = MUSICAL_PROGRAM_PackPicks(work->program);
            }
            STA_NET_SetState6Pair(work->link->session, packedBonus, packedPicks);
            work->state = MUSICAL_EVENT_STATE_LINK_WAIT_START;
            list = MET_TRAINERS_GetFromSave(work->saveControl);
            for (i = 0; i < 4; i++) {
                if (STA_NET_GetCurrentSlotValue(work->link->session) != STA_NET_GetSlotValueByIndex(work->link->session, i)) {
                    void *peerStatus = (void *)MUS_COMM_FUNC_GetSlotValueA(work->link->session, i);
                    if (peerStatus != 0)
                        MET_TRAINERS_Insert(list, MYSTATUS_GetId(peerStatus));
                }
            }
        } else if (work->aborted == 1) {
            work->state = MUSICAL_EVENT_STATE_ABORT_NET;
        }
        break;
    case MUSICAL_EVENT_STATE_LINK_WAIT_START:
        if (STA_NET_GetSlot1Done(work->link->session) == 1) {
            u8 i;

            work->state = MUSICAL_EVENT_STATE_SPAWN_MARKER;
            for (i = 0; i < 4; i++)
                work->playerSlot[i] = STA_NET_GetSlotValueByIndex(work->link->session, i);
            work->localSlot = STA_NET_GetCurrentSlotValue(work->link->session);
            MUSICAL_EVENT_ReceiveShowProgram(work);
        } else if (work->aborted == 1) {
            work->state = MUSICAL_EVENT_STATE_ABORT_NET;
        }
        break;
    case MUSICAL_EVENT_STATE_SPAWN_MARKER:
        MUSICAL_EVENT_SpawnSeatEffect(event, work);
        work->state = MUSICAL_EVENT_STATE_CREATE_PERFORMER;
        break;
    case MUSICAL_EVENT_STATE_CREATE_PERFORMER:
        MUSICAL_EVENT_CreateLocalPerformer(work);
        MUSICAL_EVENT_ShowMessage(event, work, 3);
        work->state = MUSICAL_EVENT_STATE_ENTER_CLOSE;
        break;
    case MUSICAL_EVENT_STATE_ENTER_CLOSE:
        if (work->aborted == 1 && work->step == 0) {
            work->state = MUSICAL_EVENT_STATE_ABORT_NET;
        } else if (MUSICAL_EVENT_RunEnterSequence(event, work) == 1) {
            work->step = 0;
            work->state = MUSICAL_EVENT_STATE_ENTER_DONE;
        }
        break;
    case MUSICAL_EVENT_STATE_ENTER_DONE:
        work->state = MUSICAL_EVENT_STATE_START_DRESSUP;
        break;
    case MUSICAL_EVENT_STATE_START_DRESSUP:
        MUSICAL_EVENT_CreateDressupParam(work);
        GAMESYSTEM_CallProc(work->gameSys, ~0u, MUSICAL_DRESSUP_SYS_ProcTable, work->dressup);
        work->state = MUSICAL_EVENT_STATE_WAIT_DRESSUP;
        break;
    case MUSICAL_EVENT_STATE_WAIT_DRESSUP:
        if (GAMESYSTEM_GetProcStatus(work->gameSys) == 0) {
            MUSICAL_EVENT_SendLocalPerformer(work);
            work->state = MUSICAL_EVENT_STATE_LEAVE_DRESSUP;
        }
        break;
    case MUSICAL_EVENT_STATE_LEAVE_DRESSUP:
        if (MUSICAL_EVENT_RunLeaveSequence(event, work) == 1) {
            work->step = 0;
            work->state = MUSICAL_EVENT_STATE_MESSAGE_STAGE;
            if (work->aborted == 1)
                work->state = MUSICAL_EVENT_STATE_ABORT_NET;
        }
        break;
    case MUSICAL_EVENT_STATE_MESSAGE_STAGE:
        MUSICAL_EVENT_ShowMessage(event, work, 4);
        work->state = MUSICAL_EVENT_STATE_ENTER_STAGE;
        break;
    case MUSICAL_EVENT_STATE_ENTER_STAGE:
        if (work->aborted == 1 && work->step == 0) {
            work->state = MUSICAL_EVENT_STATE_ABORT_NET;
        } else if (MUSICAL_EVENT_RunEnterSequence(event, work) == 1) {
            work->step = 0;
            work->state = MUSICAL_EVENT_STATE_START_STAGE;
        }
        break;
    case MUSICAL_EVENT_STATE_START_STAGE:
        MUSICAL_EVENT_CreateStage(work);
        GAMESYSTEM_CallProc(work->gameSys, ~0u, MUSICAL_STAGE_SYS_ProcTable, work->stage);
        work->state = MUSICAL_EVENT_STATE_WAIT_STAGE;
        break;
    case MUSICAL_EVENT_STATE_WAIT_STAGE:
        if (GAMESYSTEM_GetProcStatus(work->gameSys) == 0) {
            MUSICAL_EVENT_ScorePerformers(work);
            work->state = MUSICAL_EVENT_STATE_START_SHOW;
            if (work->aborted == 1)
                work->state = MUSICAL_EVENT_STATE_ABORT_LEAVE;
        }
        break;
    case MUSICAL_EVENT_STATE_START_SHOW:
        MUSICAL_EVENT_CreateShowRecord(work);
        GAMESYSTEM_CallProc(work->gameSys, ~0u, d_021F8360, work->result);
        work->state = MUSICAL_EVENT_STATE_WAIT_SHOW;
        break;
    case MUSICAL_EVENT_STATE_WAIT_SHOW:
        if (GAMESYSTEM_GetProcStatus(work->gameSys) == 0) {
            work->state = MUSICAL_EVENT_STATE_LEAVE_SHOW;
            if (work->aborted == 1)
                work->state = MUSICAL_EVENT_STATE_ABORT_LEAVE;
        }
        break;
    case MUSICAL_EVENT_STATE_LEAVE_SHOW:
        if (MUSICAL_EVENT_RunLeaveSequence(event, work) == 1) {
            work->step = 0;
            work->state = MUSICAL_EVENT_STATE_MESSAGE_SHOW;
            MUSICAL_EVENT_RollProgramRewards(work);
            MUSICAL_EVENT_ApplyResults(work);
        }
        break;
    case MUSICAL_EVENT_STATE_MESSAGE_SHOW:
        MUSICAL_EVENT_ShowMessage(event, work, 5);
        work->state = MUSICAL_EVENT_STATE_FINISH;
        break;
    case MUSICAL_EVENT_STATE_FINISH:
        if (work->aborted == 1) {
            work->state = MUSICAL_EVENT_STATE_ABORT_NET;
        } else {
            MUSICAL_EVENT_Free(work);
            MUSICAL_EVENT_SpawnExitEffect(event, work);
            work->state = MUSICAL_EVENT_STATE_THANKS;
        }
        break;
    case MUSICAL_EVENT_STATE_THANKS:
        MUSICAL_EVENT_ShowMessage(event, work, 0x28CC);
        work->state = MUSICAL_EVENT_STATE_END;
        break;
    case MUSICAL_EVENT_STATE_END:
        GFL_HEAP_DumpReport((unsigned int)4);
        GFL_HEAP_DeleteChecked(0x2C);
        return 1;
    case MUSICAL_EVENT_STATE_ABORT_LEAVE:
        if (MUSICAL_EVENT_RunLeaveSequence(event, work) == 1)
            work->state = MUSICAL_EVENT_STATE_ABORT_NET;
        break;
    case MUSICAL_EVENT_STATE_ABORT_NET:
        GFL_NET_ERR_RequestScreen();
        work->state = MUSICAL_EVENT_STATE_ABORT_CLEANUP;
        break;
    case MUSICAL_EVENT_STATE_ABORT_CLEANUP:
        MUSICAL_EVENT_Free(work);
        MUSICAL_EVENT_SpawnExitEffect(event, work);
        work->state = MUSICAL_EVENT_STATE_ABORT_WAIT;
        break;
    case MUSICAL_EVENT_STATE_ABORT_WAIT:
        work->state = MUSICAL_EVENT_STATE_ABORT_MESSAGE;
        break;
    case MUSICAL_EVENT_STATE_ABORT_MESSAGE:
        MUSICAL_EVENT_ShowMessage(event, work, 0x28CD);
        work->state = MUSICAL_EVENT_STATE_END;
        break;
    }
    return 0;
}

/*
 * Creates the local performer from the own Pokemon. In a wireless session
 * the two session calls follow; the first one's result is unused (the call
 * is kept: the session object is read through it).
 */
void MUSICAL_EVENT_CreateLocalPerformer(MusicalEventWork *work)
{
    work->localPerformer = (struct MusicalPerformer *)MUSICAL_MCSS_CreateMon(work->ownMon, 4);
    if (work->linkMode != 0) {
        STA_NET_GetRole(work->link->session);
        STA_NET_BeginKind5Phase(work->link->session);
    }
}

/*
 * Frees everything the event owns: dress-up parameter, stage, result
 * record, musical system, local performer and program, then clears the
 * owner back pointer in the link. Returns the link (r0 left as is).
 */
int MUSICAL_EVENT_Free(MusicalEventWork *work)
{
    MusicalLink *link;

    if (work->dressup != 0)
        MUSICAL_DRESSUP_SYS_Delete(work->dressup);
    if (work->stage != 0)
        MUSICAL_STAGE_SYS_Delete(work->stage);
    if (work->result != 0) {
        GFL_HEAP_Free(work->result->record);
        GFL_HEAP_Free(work->result);
    }
    if (work->musicalSystem != 0)
        MUSICAL_MCSS_FreeDistSave((char *)work->musicalSystem);
    if (work->localPerformer != 0)
        GFL_HEAP_Free(work->localPerformer);
    if (work->program != 0)
        MUSICAL_PROGRAM_Delete(work->program);
    link = work->link;
    link->owner = 0;
    return (sptr)link;
}

/*
 * Creates the dress-up parameter block for the local performer.
 */
MusicalDressupParam *MUSICAL_EVENT_CreateDressupParam(MusicalEventWork *work)
{
    MusicalDressupParam *param;

    param = MUSICAL_DRESSUP_SYS_Create(4, work->localPerformer, work->saveControl);
    work->dressup = param;
    param->session = work->session;
    return param;
}

/*
 * Sends the local performer to the peers of a wireless session.
 */
void MUSICAL_EVENT_SendLocalPerformer(MusicalEventWork *work)
{
    if (work->linkMode == 1)
        STA_NET_SetState18Value(work->session, (uptr)work->localPerformer);
}

/*
 * Builds the stage: the local performer, the NPC performers (local show)
 * or the peers' performers (wireless show, NPCs fill the empty slots), then
 * the program and its bonus split.
 */
void MUSICAL_EVENT_CreateStage(MusicalEventWork *work)
{
    u8 i;
    u8 npc;
    MusicalPerformer *peer;

    work->stage = MUSICAL_STAGE_SYS_Create(4, work->session);
    if (work->linkMode == 0) {
        for (i = 0; i < 4; i++) {
            if (i == 0)
                MUSICAL_STAGE_SYS_SetLocalPerformer(work->stage, work->playerSlot[i], work->localPerformer);
            else
                MUSICAL_PROGRAM_CreateNpcPerformer(work->program, work->stage, work->playerSlot[i], i - 1, 4);
        }
    } else {
        npc = 0;
        for (i = 0; i < 4; i++) {
            peer = (struct MusicalPerformer *)STA_NET_FindRecValueByKey(work->session, work->playerSlot[i]);
            if (peer != 0) {
                MUSICAL_STAGE_SYS_SetRemotePerformer(work->stage, work->playerSlot[i], peer);
            } else {
                MUSICAL_PROGRAM_CreateNpcPerformer(work->program, work->stage, work->playerSlot[i], npc, 4);
                npc++;
            }
        }
    }
    work->stage->musicalSystem = work->musicalSystem;
    work->stage->program = work->program;
    MUSICAL_PROGRAM_SplitBonus(4, work->program, work->stage);
}

/*
 * Adds the program's per-category share to the total of every performer for
 * each equipped prop. In a wireless show the props the peers report as used
 * are marked first. The u8 local category is what puts the truncation of
 * MUSICAL_MCSS_GetElemA's result ahead of the work->program load.
 */
void MUSICAL_EVENT_ScorePerformers(MusicalEventWork *work)
{
    MusicalPerformer *performer;
    void *propTable;
    u8 i;
    u8 j;
    u32 index;
    u8 category;

    if (work->linkMode == 1) {
        for (i = 0; i < 4; i++) {
            performer = work->stage->performers[i];
            for (j = 0; j < 2; j++) {
                index = STA_SLOT_GetSub(work->session, i, j);
                if (index != 0xFF)
                    performer->equipUsed[index] = 1;
            }
        }
    }
    propTable = MUSICAL_MCSS_LoadActorData(4);
    for (i = 0; i < 4; i++) {
        performer = work->stage->performers[i];
        for (j = 0; j < 9; j++) {
            if (performer->equipUsed[j] == 1) {
                category = (u32)MUSICAL_MCSS_GetElemA(propTable, (u16)performer->equips[j].propId);
                performer->totalScore += MUSICAL_PROGRAM_GetCategoryShare(work->program, category);
            }
        }
    }
    MUSICAL_MCSS_FreeActorData(propTable);
}

/*
 * Fills the show record (date, program, title, the four performers with
 * their props) for the result screen and orders the performers by score
 * into rankOrder.
 */
void MUSICAL_EVENT_CreateShowRecord(MusicalEventWork *work)
{
    MusicalShowRecord *record;
    RTCDate date;
    void *title;
    u8 sortScore[4];
    u8 i;
    u8 j;
    u8 pair;
    u8 bestScore;
    u8 score;
    int pairs;
    void *peerName;
    MusicalPerformer *performer;
    void *msgData;
    u8 left;
    u8 swapSlot;
    u8 right;
    u8 k;

    work->result = GFL_HEAP_Alloc(4, 0x14, 0, sMusicalEventFileName, 0x312);
    work->result->record = GFL_HEAP_Alloc(4, 0x1b0, 1, sMusicalEventFileName, 0x313);
    work->result->state = 0;
    work->result->session = work->session;
    record = work->result->record;
    GF_STANDARD_GetCachedDate(&date);
    record->programId = MUSICAL_PROGRAM_GetBaseProgramId(work->program);
    record->year = date.year;
    record->month = date.month;
    record->day = date.day;
    title = MUSICAL_EVENT_AllocTitleString(work, 4);
    STRBUF_ToChars(title, record->title, 0x25);
    STRBUF_Delete(title);
    record->reserved = 0;
    record->showType = 0x15;
    record->valid = 1;
    record->localSlot = work->localSlot;
    bestScore = 0;
    for (i = 0; i < 4; i++) {
        score = work->stage->performers[i]->totalScore;
        if (bestScore < score) {
            record->winnerMask = 0;
            bestScore = score;
        }
        if (bestScore == score)
            record->winnerMask = record->winnerMask + (1 << i);
    }
    for (i = 0; i < 4; i++) {
        peerName = 0;
        performer = work->stage->performers[i];
        record->performers[i].monsNo = performer->monsNo;
        record->performers[i].gender = performer->gender;
        record->performers[i].shiny = performer->shiny;
        record->performers[i].form = performer->form;
        record->performers[i].personality = performer->personality;
        if (i == work->localSlot)
            peerName = GAME_DATA_GetMyStatus(work->gameData);
        else if (work->linkMode == 1)
            peerName = (void *)MUS_COMM_FUNC_GetSlotValueA(work->session, MUSICAL_EVENT_GetPlayerOfSlot(work, i));
        if (peerName != 0) {
            MI_CpuCopy8(peerName, record->performers[i].name, 0x10);
        } else {
            u8 nameId = MUSICAL_PROGRAM_GetNpcNameId(work->program, MUSICAL_EVENT_CountNpcSlotsBelow(work, MUSICAL_EVENT_GetPlayerOfSlot(work, i)));

            msgData = MSGDATA_CreateFromArchive(0, 2, 0x4C, 4);
            title = MSGDATA_AllocString(msgData, nameId);
            STRBUF_ToChars(title, (u16 *)record->performers[i].name, 8);
            STRBUF_Delete(title);
            MSGDATA_Delete(msgData);
        }
        for (j = 0; j < 8; j++) {
            record->performers[i].props[j].propId = 0xFF;
            record->performers[i].props[j].offset = 0;
            record->performers[i].props[j].bodySlot = 10;
        }
        for (j = 0; j < 9; j++) {
            if (performer->equips[j].propId != 0xFF) {
                u8 order = performer->equips[j].order;

                record->performers[i].props[order].propId = performer->equips[j].propId;
                record->performers[i].props[order].offset = performer->equips[j].offset;
                record->performers[i].props[order].bodySlot = j;
            }
        }
    }
    work->result->ready = 1;
    work->result->save = MUSICAL_SAVE_GetFromSave(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(work->gameSys)));
    for (k = 0; k < 4; k++) {
        sortScore[k] = work->stage->performers[k]->totalScore;
        work->rankOrder[k] = k;
    }
    for (k = 0; k < 4; k++) {
        pairs = 4 - (k + 1);
        for (pair = 0; pair < pairs; pair++) {
            left = sortScore[pair];
            right = sortScore[pair + 1];
            if (right > left) {
                swapSlot = work->rankOrder[pair + 1];
                sortScore[pair + 1] = left;
                work->rankOrder[pair + 1] = work->rankOrder[pair];
                sortScore[pair] = right;
                work->rankOrder[pair] = swapSlot;
            }
        }
    }
}

/*
 * Writes the show results into the musical save, the trainer record and the
 * friendship of the own Pokemon. The u16 read through GAME_DATA_GetMyPlayerWork's result
 * goes through a local; passed inline it is copied to r2 before the ldrh.
 * The tally array is `u8 count[4] = {0, ...}` in a nested block (as in
 * MUSICAL_PROGRAM_Create).
 */
void MUSICAL_EVENT_ApplyResults(MusicalEventWork *work)
{
    u8 localScore;
    u8 topScore;
    u8 j;
    void *propTable;
    MusicalPerformer *performer;
    void *trainerRecord;
    u16 zoneId;

    localScore = MUSICAL_EVENT_GetScoreCapped(work, work->localSlot);
    topScore = MUSICAL_EVENT_GetScoreCapped(work, work->rankOrder[0]);
    MUSICAL_SAVE_IncrementShowCount(work->save);
    if (localScore == topScore && localScore != 0)
        MUSICAL_SAVE_IncrementTopRankCount(work->save);
    MUSICAL_SAVE_SetSelectedProgram(work->save, localScore);
    MUSICAL_SAVE_AddFanPoints(work->save, localScore);
    {
        u8 count[4] = {0, 0, 0, 0};

        propTable = MUSICAL_MCSS_LoadActorData(4);
        performer = work->stage->performers[work->localSlot];
        for (j = 0; j < 9; j++) {
            if (performer->equips[j].propId != 0xFF)
                count[(u8)(u32)MUSICAL_MCSS_GetElemA(propTable, (u16)performer->equips[j].propId)]++;
        }
        for (j = 0; j < 4; j++)
            MUSICAL_SAVE_SetEquippedProp(work->save, j, count[j]);
    }
    MUSICAL_MCSS_FreeActorData(propTable);
    zoneId = *(u16 *)GAME_DATA_GetMyPlayerWork(work->gameData);
    NATSUKI_Calc(work->ownMon, 6, zoneId, 4);
    trainerRecord = GAME_DATA_GetTrainerRecord(work->gameData);
    if (work->linkMode == 0) {
        RECORD_AddOne(trainerRecord, 0x72);
        if (localScore == topScore && localScore != 0)
            RECORD_AddOne(trainerRecord, 0x73);
    } else {
        RECORD_AddOne(trainerRecord, 0x74);
        if (localScore == topScore && localScore != 0)
            RECORD_AddOne(trainerRecord, 0x75);
    }
    RECORD_AddCounter(trainerRecord, 0x76, localScore);
}

/*
 * Rolls the rewards of the ten save programs after a show. The reward level
 * comes from the summed scores; the programs to reward are picked by a
 * shuffled order, each with a chance equal to the local score to also give
 * an unowned prop from the program's prop row. Two levers: the spilled
 * locals are declared in the order of their stack slots from the top down,
 * and the table row pointer is set in the for-initialiser after j (a
 * separate statement stores it before `j = 0`).
 */
void MUSICAL_EVENT_RollProgramRewards(MusicalEventWork *work)
{
    u8 shuffle[10];
    u8 *candidates;
    MusicalProgram *program;
    u32 scoreSum;
    u32 propRow;
    u16 *peerValue;
    u8 j;
    u8 value;
    u8 pick;
    u8 chance;
    u8 i;
    u8 level;
    u8 candidateCount;
    u32 category;
    const u8 *row;
    u8 round;

    candidates = GFL_HEAP_Alloc(4, 0x28, 1, sMusicalEventFileName, 0x3F9);
    scoreSum = 0;
    for (i = 0; i < 10; i++) {
        program = MUSICAL_SAVE_GetProgram(work->save, i);
        program->state = 4;
        program->rank = 0;
        program->score = 0;
    }
    if (work->linkMode == 0) {
        scoreSum = MUSICAL_SAVE_GetFanPoints(work->save) + MUSICAL_EVENT_GetScoreCapped(work, work->localSlot);
    } else {
        for (j = 0; j < 4; j++) {
            peerValue = (unsigned short *)STA_NET_GetSlotWordByIndex(work->session, MUSICAL_EVENT_GetPlayerOfSlot(work, j));
            if (STA_NET_FindRecValueByKey(work->session, j) != 0) {
                scoreSum += *peerValue;
                scoreSum += MUSICAL_EVENT_GetScoreCapped(work, j);
            }
        }
    }
    for (i = 0; i < 10; i++) {
        if (d_0216FF14[i] <= scoreSum) {
            level = 10 - i;
            break;
        }
    }
    propRow = MUSICAL_PROGRAM_GetPropRow(work->program);
    if (propRow < 7) {
        candidateCount = 0;
        for (j = 0, row = d_0216FF28[propRow]; j < 0x28; j++) {
            value = row[j];
            if (MUSICAL_SAVE_IsPropOwned(work->save, value) == 0) {
                candidates[candidateCount] = value;
                candidateCount++;
            }
        }
    }
    category = MUSICAL_PROGRAM_GetBestCategory(work->program);
    for (i = 0; i < 10; i++)
        shuffle[i] = i;
    for (round = 0; round < 10; round++) {
        for (j = 0; j < 10; j++) {
            pick = GFL_USE_GetRandomBelow(10);
            value = shuffle[j];
            shuffle[j] = shuffle[pick];
            shuffle[pick] = value;
        }
    }
    for (i = 0; i < level; i++) {
        program = MUSICAL_SAVE_GetProgram(work->save, shuffle[i]);
        chance = MUSICAL_EVENT_GetScoreCapped(work, work->localSlot);
        program->state = category;
        if ((u8)GFL_USE_GetRandomBelow(100) < chance && candidateCount != 0) {
            pick = GFL_USE_GetRandomBelow(candidateCount);
            program->rank = 1;    /* the program rewards a prop */
            program->score = candidates[pick];    /* the rewarded prop */
            for (; pick < candidateCount - 1; pick++)
                candidates[pick] = candidates[pick + 1];
            candidateCount--;
        }
    }
    GFL_HEAP_Free(candidates);
}

/*
 * Return sequence after a screen: pop the sound, reopen the field, wait
 * for the sound request to be accepted. Returns 1 when done.
 */
int MUSICAL_EVENT_RunLeaveSequence(void *event, MusicalEventWork *work)
{
    GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(work->gameSys));
    switch (work->step) {
    case 0:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPopTask(work->gameSys, 0, 0x3C));
        work->step++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(work->gameSys));
        work->step++;
        break;
    case 2:
        work->step++;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(work->gameSys));
        work->step++;
        break;
    case 4:
        return 1;
    }
    return 0;
}

/*
 * Enter sequence before a screen: push the sound, close the field, wait
 * until the sound settles. Returns 1 when done.
 */
int MUSICAL_EVENT_RunEnterSequence(void *event, MusicalEventWork *work)
{
    void *fieldMap;

    GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(work->gameSys));
    fieldMap = GAMESYSTEM_GetFieldMap(work->gameSys);
    switch (work->step) {
    case 0:
        work->step++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPushTask(work->gameSys, 30));
        work->step++;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldCloseEvent(work->gameSys, fieldMap));
        work->step++;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartWaitSettledTask(work->gameSys));
        work->step++;
        break;
    case 4:
        return 1;
    }
    return 0;
}

/*
 * Spawns the effect object (id 0x4E) at the position of the local slot.
 */
void MUSICAL_EVENT_SpawnSeatEffect(void *event, MusicalEventWork *work)
{
    void *fieldMap;
    Float3 pos;

    fieldMap = GAMESYSTEM_GetFieldMap(work->gameSys);
    pos = d_0216FEFC;
    pos.x += work->localSlot << 17;
    GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(work->gameSys, fieldMap, 0x4E, &pos, 0));
}

/*
 * Spawns the effect object (id 0x4D) at the exit position (one position for
 * a wireless show, one for a local show). The call result goes through a
 * local so both arms share one GAME_EVENT_CallEvent call (calling it in each arm
 * keeps event in r6).
 */
void MUSICAL_EVENT_SpawnExitEffect(void *event, MusicalEventWork *work)
{
    void *fieldMap;
    Float3 localPos;
    void *effect;
    Float3 linkPos;

    fieldMap = GAMESYSTEM_GetFieldMap(work->gameSys);
    localPos = d_0216FEF0;
    linkPos = d_0216FF08;
    if (work->linkMode == 1)
        effect = EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(work->gameSys, fieldMap, 0x4D, &linkPos, 1);
    else
        effect = EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(work->gameSys, fieldMap, 0x4D, &localPos, 1);
    GAME_EVENT_CallEvent(event, effect);
}

/*
 * Shows a field message window and attaches it to the event.
 */
void MUSICAL_EVENT_ShowMessage(void *event, MusicalEventWork *work, int messageId)
{
    struct GameEvent *message = SCRIPT_SYS_CreateScriptEventSimple(work->gameSys, messageId, 0, 0x15);

    SCRIPT_SYS_GetEventScriptWork(message);
    GAME_EVENT_CallEvent(event, message);
}

/*
 * Counts the NPC slots below n: without a session every slot but 0, with a
 * session the slots that have no peer record.
 */
u8 MUSICAL_EVENT_CountNpcSlotsBelow(MusicalEventWork *work, u8 n)
{
    u8 i;
    u8 count;

    count = 0;
    for (i = 0; i < n; i++) {
        if (work->session == 0) {
            if (i == 0)
                continue;
        } else if (MUS_COMM_FUNC_GetSlotValueA(work->session, i) != 0) {
            continue;
        }
        count++;
    }
    return count;
}

/*
 * Returns the stage slot of the local player.
 */
u8 MUSICAL_EVENT_GetLocalSlot(MusicalEventWork *work)
{
    return work->localSlot;
}

/*
 * Returns the player whose stage slot is slot.
 */
u8 MUSICAL_EVENT_GetPlayerOfSlot(MusicalEventWork *work, u8 slot)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        if (work->playerSlot[i] == slot)
            return i;
    }
    return 0;
}

/*
 * Returns the best appeal category of the show program.
 */
u8 MUSICAL_EVENT_GetProgramBestCategory(MusicalEventWork *work)
{
    return MUSICAL_PROGRAM_GetBestCategory(work->program);
}

/*
 * Allocates the show title string (entry 0 of the musical system's
 * message file).
 */
void *MUSICAL_EVENT_AllocTitleString(MusicalEventWork *work, int heapId)
{
    void *title;
    void *msgData;

    msgData = MSGDATA_CreateFromMemory(work->musicalSystem->msgFile, heapId);
    title = MSGDATA_AllocString(msgData, 0);
    MSGDATA_Delete(msgData);
    return title;
}

/*
 * Returns the total score of the performer in slot, capped to 255.
 */
u8 MUSICAL_EVENT_GetScoreCapped(MusicalEventWork *work, u8 slot)
{
    u16 score;

    score = work->stage->performers[slot]->totalScore;
    if (score < 0x100)
        return score;
    return 0xFF;
}

/*
 * Returns the highest total score of the four performers.
 */
u16 MUSICAL_EVENT_GetMaxScore(MusicalEventWork *work)
{
    u16 best = 0;
    u8 i;

    for (i = 0; i < 4; i++) {
        if (best < work->stage->performers[i]->totalScore)
            best = work->stage->performers[i]->totalScore;
    }
    return best;
}

/*
 * Returns the lowest total score of the four performers (255 at most).
 */
u16 MUSICAL_EVENT_GetMinScore(MusicalEventWork *work)
{
    u16 lowest = 0xFF;
    u8 i;

    for (i = 0; i < 4; i++) {
        if (lowest > work->stage->performers[i]->totalScore)
            lowest = work->stage->performers[i]->totalScore;
    }
    return lowest;
}

/*
 * Returns the stage slot of the performer at the given rank.
 */
u8 MUSICAL_EVENT_GetSlotOfRank(MusicalEventWork *work, u8 rank)
{
    return work->rankOrder[rank];
}

/*
 * Index of the performer's best appeal category, or 4 on a tie for the best.
 * The loop counter is set before the performer load (i = 0; then
 * for (; ...)). That gives the work->stage temporary the register the image
 * uses (r6, shared with performer). Setting i in the for-init is 2 bytes
 * out.
 */
u8 MUSICAL_EVENT_GetBestAppealCategory(MusicalEventWork *work, u8 slot)
{
    u8 best;
    u8 i;
    u8 bestScore;
    u8 tie;
    MusicalPerformer *performer;

    bestScore = 0;
    best = 0;
    tie = 0;
    i = 0;
    performer = work->stage->performers[slot];
    for (; i < 4; i++) {
        if (bestScore < performer->appealScore[i]) {
            tie = 0;
            best = i;
            bestScore = performer->appealScore[i];
        } else if (bestScore == performer->appealScore[i]) {
            tie = 1;
        }
    }
    if (tie == 1)
        best = 4;
    return best;
}

/*
 * Portrait class of the performer in slot: 0 for the local player, 1 or 4
 * from the peer's outfit variant in a wireless show, else the class byte of
 * its NPC template.
 */
u8 MUSICAL_EVENT_GetPortraitClass(MusicalEventWork *work, u8 slot)
{
    u8 player = MUSICAL_EVENT_GetPlayerOfSlot(work, slot);
    void *peerStatus;

    if (slot == work->localSlot)
        return 0;
    if (work->linkMode == 1) {
        peerStatus = (void *)MUS_COMM_FUNC_GetSlotValueA(work->session, player);
        if (peerStatus != 0) {
            if (MYSTATUS_GetSex(peerStatus) == 0)
                return 1;
            return 4;
        }
    }
    return MUSICAL_PROGRAM_GetNpcPortraitClass(work->program, MUSICAL_EVENT_CountNpcSlotsBelow(work, player));
}

/*
 * Registers the name of the player in slot as word wordIndex: the own
 * trainer, a peer's trainer, or the NPC name from message bank 0x4C.
 */
void MUSICAL_EVENT_SetPlayerNameWord(MusicalEventWork *work, u8 slot, void *wordSet, u32 wordIndex)
{
    int done = 0;
    u8 player = MUSICAL_EVENT_GetPlayerOfSlot(work, slot);
    void *peerStatus;

    if (slot == work->localSlot) {
        WORDSET_SetSlotMyStatus(wordSet, wordIndex, GAME_DATA_GetMyStatus(work->gameData));
        done = 1;
    } else if (work->linkMode == 1) {
        peerStatus = (void *)MUS_COMM_FUNC_GetSlotValueA(work->session, player);
        if (peerStatus != 0) {
            WORDSET_SetSlotMyStatus(wordSet, wordIndex, peerStatus);
            done = 1;
        }
    }
    if (!done) {
        u8 nameId = MUSICAL_PROGRAM_GetNpcNameId(work->program, MUSICAL_EVENT_CountNpcSlotsBelow(work, player));
        void *msgData = MSGDATA_CreateFromArchive(0, 2, 0x4C, 4);
        void *str = MSGDATA_AllocString(msgData, nameId);

        WORDSET_SetSlotTag(wordSet, wordIndex, str, 0, 1, 2);
        STRBUF_Delete(str);
        MSGDATA_Delete(msgData);
    }
}

/*
 * Twin of MUSICAL_EVENT_SetPlayerNameWord for the Pokemon name: the own Pokemon, the peer's
 * Pokemon (MUS_COMM_FUNC_GetSlotValueB), or failing both the NPC Pokemon name from message
 * bank 0x4D.
 */
void MUSICAL_EVENT_SetPokemonNameWord(MusicalEventWork *work, u8 slot, void *wordSet, u32 wordIndex)
{
    int done = 0;
    u8 player = MUSICAL_EVENT_GetPlayerOfSlot(work, slot);
    void *peerMon;

    if (slot == work->localSlot) {
        GAME_DATA_GetMyStatus(work->gameData);
        WORDSET_SetSlotMonNickname(wordSet, wordIndex, work->ownMon);
        done = 1;
    } else if (work->linkMode == 1) {
        peerMon = (void *)MUS_COMM_FUNC_GetSlotValueB(work->session, player);
        if (peerMon != 0) {
            WORDSET_SetSlotMonNicknameAlt(wordSet, wordIndex, peerMon);
            done = 1;
        }
    }
    if (!done) {
        u8 nameId = MUSICAL_PROGRAM_GetNpcNameId(work->program, MUSICAL_EVENT_CountNpcSlotsBelow(work, player));
        void *msgData = MSGDATA_CreateFromArchive(0, 2, 0x4D, 4);
        void *str = MSGDATA_AllocString(msgData, nameId);

        WORDSET_SetSlotTag(wordSet, wordIndex, str, 0, 1, 2);
        STRBUF_Delete(str);
        MSGDATA_Delete(msgData);
    }
}

/*
 * Receives the show program from the session host: the two packed words
 * are read from the session and unpacked into the program (created first
 * if this machine has none yet).
 */
void MUSICAL_EVENT_ReceiveShowProgram(MusicalEventWork *work)
{
    u32 packedBonus;
    u32 packedPicks;

    packedBonus = STA_NET_GetPairA(work->session);
    packedPicks = STA_NET_GetPairB(work->session);
    if (work->program == 0)
        work->program = MUSICAL_PROGRAM_Create(4, work->musicalSystem, 0);
    MUSICAL_PROGRAM_UnpackBonus(work->program, packedBonus);
    MUSICAL_PROGRAM_UnpackPicks(work->program, packedPicks);
}

/*
 * One-shot network error test: only when the session is wireless and the
 * network reports an error does the aborted flag get set.
 */
void MUSICAL_EVENT_CheckNetError(MusicalEventWork *work)
{
    int linkMode = work->linkMode;

    if (linkMode == 1) {
        if (GFL_NET_ERR_GetErrorLevel()) {
            if (work->aborted == 0) {
                work->aborted = 1;
            }
        }
    }
}

/*
 * Reads the aborted flag.
 */
u32 MUSICAL_EVENT_IsAborted(MusicalEventWork *work) { return work->aborted; }
