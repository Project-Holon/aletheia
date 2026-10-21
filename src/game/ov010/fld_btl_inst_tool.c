/*
 * file:     fld_btl_inst_tool.c
 * unit:     yes
 * function: FLD_BTL_INST_TOOL_CreatePokeListEvent, FLD_BTL_INST_TOOL_PokeListEventMain, FLD_BTL_INST_TOOL_CreateTrainerMsgEvent, FLD_BTL_INST_TOOL_TrainerMsgEventMain, FLD_BTL_INST_TOOL_CreateBtlSetup, FLD_BTL_INST_TOOL_BuildBattleMon, FLD_BTL_INST_TOOL_BattleMonToPokemon, FLD_BTL_INST_TOOL_ReadMonData, FLD_BTL_INST_TOOL_LoadTrainerGroup, FLD_BTL_INST_TOOL_GetRandomU16, FLD_BTL_INST_TOOL_GetIvForRank, FLD_BTL_INST_TOOL_CreateTrainer, FLD_BTL_INST_TOOL_InitTrainerHeader, FLD_BTL_INST_TOOL_DrawTrainerParty, FLD_BTL_INST_TOOL_HasBattleMsgs, FLD_BTL_INST_TOOL_LookupKeyValue, FLD_BTL_INST_TOOL_SetDoneFlag, FLD_BTL_INST_TOOL_CommResetEventMain, FLD_BTL_INST_TOOL_CreateCommResetEvent, FLD_BTL_INST_TOOL_CreatePartySelectStepEvent, FLD_BTL_INST_TOOL_PartySelectStepEventMain, FLD_BTL_INST_TOOL_CreateBattleEvent, FLD_BTL_INST_TOOL_AddBattleTally, FLD_BTL_INST_TOOL_CreateTrialHouseAwardEvent, FLD_BTL_INST_TOOL_TrialHouseAwardEventMain
 * address:  0x02167EF4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from fld_btl_inst_tool.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   POKE_REGULATION_LoadInto 0x0201A364 thumb
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled 0x0200CA38 thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateSubProcListEvent  0x02014910  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   POKEPARTY_GetCapacity  0x0201AA14  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb ov021
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   PMSI_PARAM_ToString  0x0202435C  thumb
 *   GAME_DATA_GetOccupyInfo  0x02012964  thumb
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb
 *   FLDMMDL_GetPos  0x0216D88C  thumb
 *   FIELD_MSGBG_AddTalkWin  0x0219129C  thumb ov021
 *   FIELD_MSGBG_TalkWinMain  0x02191388  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   FIELD_MSGBG_DeleteTalkWin  0x021912D8  thumb
 *   FIELD_MSGBG_WaitTalkWinClose  0x021912F8  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   FIELD_ENCOUNT_SetFieldSituation  0x021AA304  thumb  ov021
 *   BTL_SETUP_Create  0x02013090  thumb
 *   BTL_SETUP_SetupTrainerSingle  0x02013610  thumb
 *   BTL_SETUP_SetupTrainerDouble  0x02013644  thumb
 *   BTL_SETUP_SetupTrainerMulti  0x02013734  thumb
 *   BTL_SETUP_SetupCommAiMulti  0x02013810  thumb
 *   BTL_SETUP_AllocRecordBuffer  0x02013980  thumb
 *   POKEPARTY_InitEx  0x0201A954  thumb
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb
 *   POKE_TOOL_ClearPartyParam  0x02017528  thumb
 *   POKE_TOOL_CopyPartyPokemon  0x02019CE0  thumb
 *   POKE_TOOL_SetLevelAndRecalc  0x02019CA0  thumb
 *   STRBUF_SetString  0x02045924  arm
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 *   BTL_SETUP_ChangeToSubway  0x0201394C  thumb
 *   d_02172A2C     0x02172A2C  data
 *   POKE_TOOL_CreatePersonalRnd  0x020186C8  thumb
 *   POKE_TOOL_GetPersonalParam  0x02019C90  thumb
 *   MSGDATA_ReadUnits  0x02045F5C  arm
 *   d_02172084     0x02172084  data
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_SetNature  0x020185B0  thumb
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   POKE_TOOL_CalcLevel  0x02018430  thumb
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   STRBUF_ToChars  0x02045A38  arm
 *   g_0217208C  0x0217208C  data  ov010  a2
 *   g_0217208E  0x0217208E  data  ov010  a2
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb ov021
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAMESYSTEM_SetAlwaysNetFlag  0x02012158  thumb
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   FIELD_SUBSCREEN_RequestModeWithCallback  0x021A0F7C  thumb ov021
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   BATTLE_BOX_GetFromSave  0x0200BAC8  thumb
 *   BATTLE_BOX_CreateParty  0x0200BAF4  thumb
 *   EVENT_BATTLE_CreateForcedWinTask 0x0216E910 thumb ov010
 *   TRIAL_HOUSE_SAVE_GetFromSave  0x0200E8F8  thumb
 *   GAME_EVENT_CallProc 0x02012444 thumb
 *   d_021BA39C 0x021BA39C data ov220 a4
 *   ov220_id 0x000000DC data
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "field_event_types.h"
#include "fld_btl_inst_tool_shared_types.h"

#include "../types.h"
#include "../arm9/ica_anime_shared_types.h"

#include "../sdk_fx.h"

/* Opaque types owned by other files. */
#include "../ov021/event_fieldmap_control.h"




typedef struct MyStatus MyStatus;

typedef struct ZukanSave ZukanSave;

typedef struct Strbuf Strbuf;

typedef struct MsgBank MsgData;

typedef struct PokemonParam PokemonParam;

typedef struct FldMmdl FldMmdl;

typedef struct FldMmdlSys FldMmdlSys;

typedef struct FieldTalkWin FldMsgBalloon;

typedef struct FieldMsgBg FldMsgBalloonSys;

typedef struct NetHandle NetHandle;

typedef struct TrialHouseSave TrialHouseSave;

typedef struct Regulation Regulation;


/* ---- Party select event (poke list, then status screen, with field close/open around it) ---- */

/* Status screen parameter (0x28 bytes); same record as in event_poke_status.c. */
typedef struct PStatusParam {
    Party *ppd;             /* 0x00 */
    u8 reserved04[4];
    GameData *config;       /* 0x08 */
    u8 ppt;                 /* 0x0C */
    u8 mode;                /* 0x0D */
    u8 max;                 /* 0x0E */
    u8 pos;                 /* 0x0F */
    u8 page;                /* 0x10 */
    u8 reserved11[7];
    u32 isNationalDex;      /* 0x18 */
    u8 reserved1C[0xC];
} PStatusParam;

typedef struct PartySelectEventWork {
    GameSystem *gameSystem;     /* 0x000 */
    FieldMap *fieldMap;         /* 0x004 */
    PStatusParam statusParam;   /* 0x008 */
    PokeListParam listParam;    /* 0x030 */
    u8 regulationData[0xBC];    /* 0x0C8 */
    u32 *resultCommand;         /* 0x184: gets listParam.command */
    u32 *resultSlot;            /* 0x188: gets listParam.selectedSlot */
    u8 *resultOrder;            /* 0x18C: gets listParam.selectOrder */
    Party *sourceParty;         /* 0x190 */
    Party *resultParty;         /* 0x194: receives the chosen members */
} PartySelectEventWork;

/* ---- Trainer pre-battle message balloon event ---- */
typedef struct TrainerMsgEventWork {
    GameSystem *gameSystem;     /* 0x00 */
    VecFx32 trainerPos;         /* 0x04 */
    FldMsgBalloon *balloon;     /* 0x10 */
    Strbuf *message;            /* 0x14 */
    u8 reserved18[4];
} TrainerMsgEventWork;

/* ---- Battle facility trainer data ---- */
/* One 16-byte record of archive a/2/1/4. */
typedef struct BtlInstMonData {
    u16 species;        /* 0x00 */
    u16 moves[4];       /* 0x02 */
    u8 evMask;          /* 0x0A */
    u8 nature;          /* 0x0B */
    u16 item;           /* 0x0C */
    u16 form;           /* 0x0E */
} BtlInstMonData;

/* One group list of archive a/2/1/5. */
typedef struct BtlInstGroup {
    u16 trainerType;    /* 0x00 */
    u16 count;          /* 0x02 */
    u16 memberIds[1];   /* 0x04 */
} BtlInstGroup;

/* Battle request of the facility (0x130 bytes). */
typedef enum { BTL_INST_REQUEST_MODE_OFFSET = 0x12c } BtlInstRequestOffset;

typedef struct BtlInstBattleRequest {
    u8 trainerData[0x124];      /* BtlInstTrainer, see review.tsv */
    int monCount;               /* 0x124 */
    Party *playerParty;         /* 0x128 */
    BtlInstRequestOffset mode;  /* 0x12C */
} BtlInstBattleRequest;

/* ---- Battle setup built for the facility ---- */
typedef enum {
    BTL_CLIENT_PLAYER,
    BTL_CLIENT_ENEMY1,
    BTL_CLIENT_PARTNER,
    BTL_CLIENT_ENEMY2
} BtlInstClient;

/* ---- Party select wrapper event ---- */
typedef struct PartySelectStepWork {
    GameSystem *gameSystem;     /* 0x00 */
    FieldMap *fieldMap;         /* 0x04 */
    u8 reserved08[4];
    u16 *resultOk;              /* 0x0C: set to 1 when the player confirmed a party */
    u32 listArg;                /* 0x10 */
    u32 regulationId;           /* 0x14 */
    Party *party;               /* 0x18 */
    Party *tempParty;           /* 0x1C: freed when done, may be 0 */
    u32 resultSlot;             /* 0x20 */
    u32 resultCommand;          /* 0x24 */
    u8 selectOrder[8];          /* 0x28 */
    BtlInstBattleRequest *request; /* 0x30 */
} PartySelectStepWork;

/* ---- Tally record ---- */
typedef struct BtlInstRecord {
    u8 reserved000[0x134];
    u16 tally[10];              /* 0x134 */
    u16 scoreShare;             /* 0x148 */
    u16 lastTally;              /* 0x14A */
} BtlInstRecord;

/* ---- Comm reset event ---- */
typedef struct CommResetWork {
    int done;                   /* 0x00: set by the callback */
    int restoreAutoComm;        /* 0x04 */
    GameSystem *gameSystem;     /* 0x08 */
} CommResetWork;

typedef enum {
    COMM_RESET_REQUEST_EXIT,
    COMM_RESET_WAIT_EXIT,
    COMM_RESET_RESTORE_AUTO_COMM,
    COMM_RESET_REQUEST_FIELD_RESET,
    COMM_RESET_WAIT_DONE,
    COMM_RESET_END
} CommResetStep;

/* ---- Trial house award event ---- */
typedef struct TrialHouseAwardParam {
    u8 playerSex;               /* 0x00 */
    u8 reserved01[3];
    TrialHouseSave *trialHouse; /* 0x04 */
    int hasSecondEntry;         /* 0x08 */
    int fadeOutBgm;             /* 0x0C */
} TrialHouseAwardParam;

typedef struct TrialHouseAwardEventWork {
    GameSystem *gameSystem;     /* 0x00 */
    FieldMap *fieldMap;         /* 0x04 */
    TrialHouseAwardParam param; /* 0x08 */
} TrialHouseAwardEventWork;

#include "../arm9/mi_memory.h"


#include "../arm9/gfl_heap_wrap.h"


#include "../arm9/gamesystem.h"


#include "../arm9/game_data.h"
struct GFLNetHandle;

#include "../arm9/net_handle.h"

#include "../arm9/mystatus.h"

#include "../arm9/pokeparty.h"

#include "../arm9/poke_tool.h"

#include "../arm9/net_system.h"

#include "../arm9/game_event.h"


#include "../arm9/poke_regulation.h"

#include "../arm9/zukan_save.h"





#include "../arm9/field_status.h"





struct FieldMsgBg;

#include "../ov021/fieldmap.h"

#include "../arm9/strbuf.h"
struct MsgBank;

#include "../arm9/msgdata.h"



#include "../arm9/pmsi_param.h"
struct GameData;

struct MmdlSys;
struct Mmdl;

#include "fldmmdl.h"
struct VecFx32;

struct FieldTalkWin;

#include "../ov021/field_msgbg.h"
struct FieldTalkWin;


#include "../arm9/key.h"



struct FieldSituation;

#include "../ov021/field_encount.h"
struct BattleSetupParam;

#include "../arm9/btl_setup.h"








struct PartyPokemon;















#include "../arm9/arc_tool.h"

#ifdef __MWERKS__
extern void *ARC_UTIL_LoadMember(int archiveId, int member, int flag, int heapId); /* original prototype; the definition differs in argument width */
#else
#include "../arm9/arc_util.h"
#endif

#include "../arm9/gfl_use.h"



struct FieldSubscreen;



#include "../arm9/game_comm.h"





struct SaveControl;
struct BattleBoxSave;

#include "../arm9/battle_box.h"
struct BoxMonGroup;
struct Party;


#include "event_battle.h"

#include "../arm9/trial_house_savedata.h"
#include "../ov021/field_subscreen.h"


extern const char d_02172A2C[];

extern const u16 d_02172084[];

extern u16 g_0217208C[];

extern u16 g_0217208E[];

extern const unsigned int d_021BA39C[];

extern unsigned char ov220_id[];

GameEvent *FLD_BTL_INST_TOOL_CreatePokeListEvent(GameSystem *gameSystem, int listArg, int listMode, int regulationId, Party *party, u8 *resultOrder, u32 *resultSlot, u32 *resultCommand, Party *resultParty);

int FLD_BTL_INST_TOOL_PokeListEventMain(GameEvent *event, u32 *seq, PartySelectEventWork *work);

GameEvent *FLD_BTL_INST_TOOL_CreateTrainerMsgEvent(GameSystem *gameSystem, BtlInstTrainer *trainers, int index, int mmdlId);

int FLD_BTL_INST_TOOL_TrainerMsgEventMain(GameEvent *event, int *seq, TrainerMsgEventWork *work);

struct BattleSetupParam *FLD_BTL_INST_TOOL_CreateBtlSetup(GameSystem *gameSystem, Party *playerParty, u32 battleMode, BtlInstTrainer *trainerA, BtlInstTrainer *trainerB, int monCount);

u32 FLD_BTL_INST_TOOL_BuildBattleMon(BattleMon *out, u32 memberId, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useTableItem, u16 heapId);

void FLD_BTL_INST_TOOL_BattleMonToPokemon(const BattleMon *src, PokemonParam *mon);

void FLD_BTL_INST_TOOL_ReadMonData(void *dest, u32 memberId);

void *FLD_BTL_INST_TOOL_LoadTrainerGroup(u32 group, u32 heapId);

int FLD_BTL_INST_TOOL_GetRandomU16(void);

u8 FLD_BTL_INST_TOOL_GetIvForRank(u32 rank);

int FLD_BTL_INST_TOOL_CreateTrainer(BtlInstTrainer *trainer, u16 trainerIndex, int count, u16 *exclSpecies, u16 *exclItems, BtlInstDraw *draw, u16 heapId);

BtlInstGroup *FLD_BTL_INST_TOOL_InitTrainerHeader(BtlInstTrainer *trainer, int trainerIndex, int heapId);

int FLD_BTL_INST_TOOL_DrawTrainerParty(BtlInstGroup *group, u16 rank, BattleMon *mons, int count, u16 *exclSpecies, u16 *exclItems, BtlInstDraw *draw, u16 heapId);

int FLD_BTL_INST_TOOL_HasBattleMsgs(BtlInstTrainer *trainer);

u16 FLD_BTL_INST_TOOL_LookupKeyValue(u16 key);

void FLD_BTL_INST_TOOL_SetDoneFlag(int *doneFlag);

int FLD_BTL_INST_TOOL_CommResetEventMain(GameEvent *event, int *step, CommResetWork *work);

GameEvent *FLD_BTL_INST_TOOL_CreateCommResetEvent(GameSystem *gameSystem, int restoreAutoComm);

GameEvent *FLD_BTL_INST_TOOL_CreatePartySelectStepEvent(GameSystem *gameSystem, BtlInstBattleRequest *request, int regulationId, int useTempParty, u16 *resultOk);

int FLD_BTL_INST_TOOL_PartySelectStepEventMain(GameEvent *event, int *step, PartySelectStepWork *work);

GameEvent *FLD_BTL_INST_TOOL_CreateBattleEvent(GameSystem *gameSystem, BtlInstBattleRequest *request);

void FLD_BTL_INST_TOOL_AddBattleTally(BtlInstRecord *record, struct BattleSetupParam *result);

GameEvent *FLD_BTL_INST_TOOL_CreateTrialHouseAwardEvent(GameSystem *gameSystem, int hasSecondEntry, int fadeOutBgm);

int FLD_BTL_INST_TOOL_TrialHouseAwardEventMain(GameEvent *event, int *step);

/*
 * Creates the party select event: a Pokemon list screen followed by the
 * status screen, with the field closed before and opened after. The chosen
 * slot, command and order are copied to the caller's outputs when the
 * event ends.
 *
 * lever: named temporaries keep the list parameter address live across the
 * regulation load; bounded permuter47 compiles found byte-correct192.
 * Interface evidence: UNION_ONESELF_LoadRegulation.c records r0->r2, r1->r0, r1=0x69, jump via02048F4C. Original caller supplies d in r0 and p->buf in r1.
 * TU: MATCH192,9/10 relocations; suggest-split leaves sole function OUT.
 * checks: 1 020124E8 takes live hd from122C0, own matched accessor reads+0xc; 2 family/neighbours reread, no full twin; 3 unsigned b/c each retain31 before search; 4 pointer-copy idiom read; 5 neighbours/idioms reread, frame is scalar spills, no stack aggregate.
 * permuter: once budget300 types, emitted baseline agreed31/192; stopped at47 with MATCH; fixed one confirmsMATCH192.
 */
GameEvent *FLD_BTL_INST_TOOL_CreatePokeListEvent(GameSystem *gameSystem, int listArg, int listMode, int regulationId, Party *party, u8 *resultOrder, u32 *resultSlot, u32 *resultCommand, Party *resultParty)
{
    PartySelectEventWork *work;
    PokeListParam *listParam;
    PStatusParam *statusParam;
    GameData *gameData;
    ZukanSave *zukan;
    FieldMap *fieldMap;
    GameEvent *event;
    PokeListParam *listTmp;
    u8 maxCount;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    event = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)FLD_BTL_INST_TOOL_PokeListEventMain, 0x198);
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->resultOrder = resultOrder;
    work->resultSlot = resultSlot;
    work->resultCommand = resultCommand;
    work->sourceParty = party;
    listTmp = &work->listParam;
    work->resultParty = resultParty;
    POKE_REGULATION_LoadInto(regulationId, (Regulation *)work->regulationData);
    listParam = listTmp;
    listParam->party = party;
    listParam->regulation = (Regulation *)work->regulationData;
    listParam->listArg = listArg;
    listParam->listMode = listMode;
    statusParam = &work->statusParam;
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    zukan = ZUKAN_SAVE_GetFromGameData(gameData);
    MI_CpuFill8(statusParam, 0, 0x28);
    statusParam->ppd = party;
    statusParam->ppt = 1;
    maxCount = POKEPARTY_GetCount(party);
    statusParam->max = maxCount;
    statusParam->mode = 0;
    statusParam->page = 0;
    statusParam->config = gameData;
    statusParam->isNationalDex = ZUKAN_SAVE_IsNationalDexEnabled(zukan);
    return event;
}

/*
 * Sub-process sequence: runs five child processes one after another
 * (two from ov021, three from arm9), copying the result of the fifth
 * back and re-adding the chosen party members.
 *
 * First draft plus one lever (2026-09-28 tree_ov010_4): w->heap read into
 * a local before the switch. The member index is taken before the range
 * fix-up, so a reset slot still passes its old index (the image does not
 * reload it).
 */
int FLD_BTL_INST_TOOL_PokeListEventMain(GameEvent *event, u32 *seq, PartySelectEventWork *work)
{
    int count;
    int i;
    int slot;
    GameSystem *gameSystem;

    gameSystem = work->gameSystem;
    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, work->fieldMap, 0, 0));
        (*seq)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldCloseEvent(gameSystem, work->fieldMap));
        (*seq)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateSubProcListEvent(gameSystem, (sptr)work->fieldMap, (sptr)(&work->listParam), (sptr)(&work->statusParam)));
        (*seq)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*seq)++;
        break;
    case 4:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, work->fieldMap, 0, 0, 1, 0, 0));
        MI_CpuCopy8(work->listParam.selectOrder, work->resultOrder, 6);
        *work->resultSlot = work->listParam.selectedSlot;
        *work->resultCommand = work->listParam.command;
        if (*work->resultSlot != 7 && *work->resultSlot != 8 && work->resultParty != 0) {
            count = POKEPARTY_GetCapacity(work->resultParty);
            for (i = 0; i < count; i++) {
                slot = work->resultOrder[i] - 1;
                if (slot >= 6)
                    work->resultOrder[i] = 1;
                POKEPARTY_Add(work->resultParty, POKEPARTY_GetMember(work->sourceParty, slot));
            }
        }
        (*seq)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}

/*
 * Creates the balloon event for a trainer's pre-battle message.
 *
 * evidence: 0x0202435C is an unlabelled ARM9 thunk ("ldr r3, =PMSI_PARAM_ToStringWords; movs r2, #2; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov069 0x021BA21A, ov093 0x021D1894, ov010 0x0216C778), so the call
 * attests as `label`.
 */
GameEvent *FLD_BTL_INST_TOOL_CreateTrainerMsgEvent(GameSystem *gameSystem, BtlInstTrainer *trainers, int index, int mmdlId)
{
    GameEvent *event;
    GameData *gameData;
    FldMsgBalloonSys *balloonSys;
    TrainerMsgEventWork *work;

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    balloonSys = (struct FieldMsgBg *)FIELDMAP_GetMsgBg(GAMESYSTEM_GetFieldMap(gameSystem));
    event = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)FLD_BTL_INST_TOOL_TrainerMsgEventMain, 0x1c);
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    if (trainers->introMsg.sentenceType == 0xFFFF) {
        MsgData *msgData;
        work->message = STRBUF_Create(0x5c, 4);
        msgData = (struct MsgBank *)MSGDATA_CreateFromArchive(0, 2, 0xb8, 4);
        MSGDATA_ReadString((struct MsgBank *)msgData, trainers->introMsg.sentenceId, work->message);
        MSGDATA_Delete((struct MsgBank *)msgData);
    } else {
        work->message = PMSI_PARAM_ToString(&trainers[index].introMsg, 4);
    }
    FLDMMDL_GetPos(FLDMMDL_SysSearchObjId(GAME_DATA_GetOccupyInfo(gameData), mmdlId), (struct VecFx32 *)(&work->trainerPos));
    work->balloon = FIELD_MSGBG_AddTalkWin(balloonSys, 1, &work->trainerPos, work->message, 0, 0);
    return event;
}

/*
 * Message balloon state machine: wait until the balloon is up, wait for a
 * confirm or cancel press, close the balloon and free the text.
 */
int FLD_BTL_INST_TOOL_TrainerMsgEventMain(GameEvent *event, int *seq, TrainerMsgEventWork *work)
{
    switch (*seq) {
    case 0:
        if (FIELD_MSGBG_TalkWinMain((struct FieldTalkWin *)work->balloon) == 1)
            (*seq)++;
        break;
    case 1:
        if ((KEY_GetTrg() & 3) != 0) {
            FIELD_MSGBG_DeleteTalkWin((struct FieldTalkWin *)work->balloon);
            (*seq)++;
        }
        break;
    case 2:
        if (FIELD_MSGBG_WaitTalkWinClose((struct FieldTalkWin *)work->balloon) == 1) {
            STRBUF_Delete(work->message);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Builds the battle-intro sprite set: a BTL_SETUP_Create object, one party
 * list per side filled from 0x3C-byte records through FLD_BTL_INST_TOOL_BattleMonToPokemon.
 * Levers: side ids are an enum (an int index folds to a constant offset);
 * the mode truncation is a u16 local copied from a u32 parameter; the
 * mode==4 and FLD_BTL_INST_TOOL_HasBattleMsgs arms each carry their own copy of the eight
 * halfword stores (the cross-jump leaves the `b` into the second copy);
 * one party local per side block sets the spill slots; the sprite pointer
 * of the third block is read before the record pointer moves.
 */
struct BattleSetupParam *FLD_BTL_INST_TOOL_CreateBtlSetup(GameSystem *gameSystem, Party *playerParty, u32 battleMode, BtlInstTrainer *trainerA, BtlInstTrainer *trainerB, int monCount)
{
    u16 mode;
    struct FieldSituation situation;
    struct BattleSetupParam *bs;
    GameData *gameData;
    PokemonParam *tempMon;
    Party *party;
    Party *enemy1Party;
    Party *enemy2Party;
    Party *partnerParty;
    struct BattleTrainerData *trainerData;
    int i;
    BtlInstClient client;
    int playerPos;
    NetHandle *netHandle;
    PokemonParam *srcMon;
    MyStatus *myStatus;
    BtlInstTrainer *trainerC;

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    mode = battleMode;
    FIELD_ENCOUNT_SetFieldSituation(&situation, gameData, GAMESYSTEM_GetFieldMap(gameSystem));
    bs = BTL_SETUP_Create(4);
    switch (mode) {
    case 0:
    case 4:
    case 5:
        BTL_SETUP_SetupTrainerSingle(bs, gameData, &situation, 0, 4);
        break;
    case 1:
    case 6:
        BTL_SETUP_SetupTrainerDouble(bs, gameData, &situation, 0, 4);
        break;
    case 2:
    case 7:
        BTL_SETUP_SetupTrainerMulti(bs, gameData, &situation, 0, 0, 0, 4);
        break;
    case 3:
    case 8:
        netHandle = (struct NetHandle *)GFL_NET_HANDLE_GetCurrentHandle();
        playerPos = 0;
        if (GFL_NET_SYSTEM_GetCurrentAid() != 0)
            playerPos = 2;
        BTL_SETUP_SetupCommAiMulti(bs, gameData, (uptr)netHandle, 1, playerPos, 0, 0, 4);
        break;
    }
    BTL_SETUP_AllocRecordBuffer(bs, 4);

    client = BTL_CLIENT_PLAYER;
    i = 0;
    myStatus = GAME_DATA_GetMyStatus(gameData);
    bs->playerStatus[client] = myStatus;
    party = bs->party[client];
    POKEPARTY_InitEx(party, 6);
    tempMon = GFL_HEAP_Alloc(0x8004, POKE_TOOL_GetPartyParamSize(), 0, d_02172A2C, 0x253);
    POKE_TOOL_ClearPartyParam(tempMon);
    for (; i < monCount; i++) {
        srcMon = POKEPARTY_GetMember(playerParty, i);
        POKE_TOOL_CopyPartyPokemon((struct PartyPokemon *)srcMon, (struct PartyPokemon *)tempMon);
        if (POKE_TOOL_GetPartyValue(srcMon, 0x9E, 0) != 0x32)
            POKE_TOOL_SetLevelAndRecalc(tempMon, 0x32);
        POKEPARTY_Add(party, tempMon);
    }
    GFL_HEAP_Free(tempMon);

    client = BTL_CLIENT_ENEMY1;
    trainerData = bs->trainerData[client];
    trainerData->trainerId = trainerA->trainerId;
    trainerData->trainerType = trainerA->trainerType;
    trainerData->aiFlags = 0x87;
    STRBUF_SetString(trainerData->name, trainerA->name);
    PMSI_PARAM_ClearSentence((PmsData *)&trainerData->winWords[0]);
    PMSI_PARAM_ClearSentence((PmsData *)&trainerData->loseWords[0]);
    if (mode == 4) {
        trainerData->winWords[0] = trainerA->battleMsgs.half[0];
        trainerData->winWords[1] = trainerA->battleMsgs.half[1];
        trainerData->winWords[2] = trainerA->battleMsgs.half[2];
        trainerData->winWords[3] = trainerA->battleMsgs.half[3];
        trainerData->loseWords[0] = trainerA->battleMsgs.half[4];
        trainerData->loseWords[1] = trainerA->battleMsgs.half[5];
        trainerData->loseWords[2] = trainerA->battleMsgs.half[6];
        trainerData->loseWords[3] = trainerA->battleMsgs.half[7];
    } else if (FLD_BTL_INST_TOOL_HasBattleMsgs(trainerA) != 0) {
        trainerData->winWords[0] = trainerA->battleMsgs.half[0];
        trainerData->winWords[1] = trainerA->battleMsgs.half[1];
        trainerData->winWords[2] = trainerA->battleMsgs.half[2];
        trainerData->winWords[3] = trainerA->battleMsgs.half[3];
        trainerData->loseWords[0] = trainerA->battleMsgs.half[4];
        trainerData->loseWords[1] = trainerA->battleMsgs.half[5];
        trainerData->loseWords[2] = trainerA->battleMsgs.half[6];
        trainerData->loseWords[3] = trainerA->battleMsgs.half[7];
    }
    enemy1Party = bs->party[client];
    POKEPARTY_InitEx(enemy1Party, 6);
    tempMon = GFL_HEAP_Alloc(0x8004, POKE_TOOL_GetPartyParamSize(), 0, d_02172A2C, 0x29E);
    for (i = 0; i < monCount; i++) {
        FLD_BTL_INST_TOOL_BattleMonToPokemon(&trainerA->mons[i], tempMon);
        POKEPARTY_Add(enemy1Party, tempMon);
    }
    GFL_HEAP_Free(tempMon);

    if (bs->multiMode != 0) {
        client = BTL_CLIENT_ENEMY2;
        trainerData = bs->trainerData[client];
        trainerC = trainerA + 1;
        trainerData->trainerId = trainerC->trainerId;
        trainerData->trainerType = trainerC->trainerType;
        trainerData->aiFlags = 0x87;
        STRBUF_SetString(trainerData->name, trainerC->name);
        enemy2Party = bs->party[client];
        POKEPARTY_InitEx(enemy2Party, 6);
        tempMon = GFL_HEAP_Alloc(0x8004, POKE_TOOL_GetPartyParamSize(), 0, d_02172A2C, 0x2C4);
        for (i = 0; i < monCount; i++) {
            FLD_BTL_INST_TOOL_BattleMonToPokemon(&trainerC->mons[i], tempMon);
            POKEPARTY_Add(enemy2Party, tempMon);
        }
        GFL_HEAP_Free(tempMon);
    }
    if (bs->multiMode == 3) {
        client = BTL_CLIENT_PARTNER;
        trainerData = bs->trainerData[client];
        trainerData->trainerId = trainerB->trainerId;
        trainerData->trainerType = trainerB->trainerType;
        trainerData->aiFlags = 0x87;
        STRBUF_SetString(trainerData->name, trainerB->name);
        PMSI_PARAM_ClearSentence((PmsData *)&trainerData->winWords[0]);
        PMSI_PARAM_ClearSentence((PmsData *)&trainerData->loseWords[0]);
        partnerParty = bs->party[client];
        POKEPARTY_InitEx(partnerParty, 6);
        tempMon = GFL_HEAP_Alloc(0x8004, POKE_TOOL_GetPartyParamSize(), 0, d_02172A2C, 0x2F3);
        for (i = 0; i < monCount; i++) {
            FLD_BTL_INST_TOOL_BattleMonToPokemon(&trainerB->mons[i], tempMon);
            POKEPARTY_Add(partnerParty, tempMon);
        }
        GFL_HEAP_Free(tempMon);
    }
    BTL_SETUP_ChangeToSubway(bs);
    return bs;
}

/*
 * Build a battle-facility Pokemon from its a/2/1/4 record (the reader is
 * FLD_BTL_INST_TOOL_ReadMonData). Levers: the pid store in both arms of an if/else, the
 * ability as a nested if storing in all three arms, and (2026-09-28
 * tree_ov010_4) the EV share as an int local computed straight from the
 * division with the count reused as the second loop's counter.
 */
u32 FLD_BTL_INST_TOOL_BuildBattleMon(BattleMon *out, u32 memberId, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useTableItem, u16 heapId)
{
    BtlInstMonData data;
    int i;
    int evStatCount;
    u8 friendship;
    int evPerStat;
    u32 ability;
    MsgData *speciesNames;

    MI_CpuFill8(out, 0, sizeof(BattleMon));
    FLD_BTL_INST_TOOL_ReadMonData(&data, memberId);
    out->species = data.species;
    out->form = data.form;
    if (useTableItem)
        out->item = d_02172084[itemIdx];
    else
        out->item = data.item;
    friendship = 0xFF;
    for (i = 0; i < 4; i++) {
        out->moves[i] = data.moves[i];
        if (data.moves[i] == 0xDA)
            friendship = 0;
    }
    out->otId = otId;
    if (pid == 0) {
        pid = POKE_TOOL_CreatePersonalRnd(otId, data.species, data.form, 2, 2, 0);
        out->pid = pid;
    } else {
        out->pid = pid;
    }
    out->nature = data.nature;
    out->iv.b.hpIv = iv;
    out->iv.b.atkIv = iv;
    out->iv.b.defIv = iv;
    out->iv.b.speIv = iv;
    out->iv.b.spaIv = iv;
    out->iv.b.spdIv = iv;
    evStatCount = 0;
    for (i = 0; i < 6; i++) {
        if (data.evMask & (1 << i))
            evStatCount++;
    }
    evPerStat = 510 / evStatCount;
    if (evPerStat > 255)
        evPerStat = 255;
    for (evStatCount = 0; evStatCount < 6; evStatCount++) {
        if (data.evMask & (1 << evStatCount))
            out->ev[evStatCount] = evPerStat;
    }
    out->ppUps = 0;
    out->lang = 0;
    ability = POKE_TOOL_GetPersonalParam(out->species, 0, 0x1B);
    if (ability != 0) {
        if (out->pid & 1)
            out->ability = ability;
        else
            out->ability = POKE_TOOL_GetPersonalParam(out->species, 0, 0x1A);
    } else {
        out->ability = POKE_TOOL_GetPersonalParam(out->species, 0, 0x1A);
    }
    out->friendship = friendship;
    speciesNames = (struct MsgBank *)MSGDATA_CreateFromArchive(0, 2, 0x46, heapId);
    MSGDATA_ReadUnits((struct MsgBank *)speciesNames, out->species, out->nick, 11);
    MSGDATA_Delete((struct MsgBank *)speciesNames);
    return pid;
}

/*
 * Builds a level-50 party mon from a 0x3C-byte record. Two levers: the
 * PP-up count read back through POKE_TOOL_GetPartyValue goes through a u8 local, and
 * the nickname copy reads through a `const u16 *` local (indexing
 * src->nick directly keeps the strbuf in a register and swaps r5/r6).
 */
void FLD_BTL_INST_TOOL_BattleMonToPokemon(const BattleMon *src, PokemonParam *mon)
{
    u16 name[11];
    Strbuf *nickBuf;
    u16 eos;
    int i;
    u8 pp;
    const u16 *nick;

    POKE_TOOL_ClearPartyParam(mon);
    POKE_TOOL_SetupPartyParamEx(mon, src->species, 50, (u64)-1, src->iv.ivs & 0x3FFFFFFF, src->pid);
    POKE_TOOL_SetPartyValue(mon, 0x6F, (u8)src->form);
    POKE_TOOL_SetPartyValue(mon, 6, src->item);
    for (i = 0; i < 4; i++) {
        POKE_TOOL_SetPartyValue(mon, 0x36 + i, src->moves[i]);
        POKE_TOOL_SetPartyValue(mon, 0x3E + i, (u8)((src->ppUps >> (i * 2)) & 3));
        pp = POKE_TOOL_GetPartyValue(mon, 0x42 + i, 0);
        POKE_TOOL_SetPartyValue(mon, 0x3A + i, pp);
    }
    POKE_TOOL_SetPartyValue(mon, 7, src->otId);
    POKE_TOOL_SetPartyValue(mon, 0xD, src->ev[0]);
    POKE_TOOL_SetPartyValue(mon, 0xE, src->ev[1]);
    POKE_TOOL_SetPartyValue(mon, 0xF, src->ev[2]);
    POKE_TOOL_SetPartyValue(mon, 0x10, src->ev[3]);
    POKE_TOOL_SetPartyValue(mon, 0x11, src->ev[4]);
    POKE_TOOL_SetPartyValue(mon, 0x12, src->ev[5]);
    POKE_TOOL_SetPartyValue(mon, 0xA, src->ability);
    POKE_TOOL_SetPartyValue(mon, 9, src->friendship);
    POKE_TOOL_SetNature(mon, src->nature);
    nickBuf = STRBUF_Create(11, 4);
    eos = STRBUF_GetEosChar();
    nick = src->nick;
    for (i = 0; i < 11; i++)
        name[i] = nick[i];
    name[i - 1] = eos;
    STRBUF_SetString(nickBuf, name);
    POKE_TOOL_SetPartyValue(mon, 0x73, (uptr)nickBuf);
    STRBUF_Delete(nickBuf);
    POKE_TOOL_SetPartyValue(mon, 0xC, src->lang);
    POKE_TOOL_SetPartyValue(mon, 0x9E, POKE_TOOL_CalcLevel(mon));
}

/*
 * The reader for a/2/1/4: copy one 16-byte record into the caller's buffer.
 * 214 is the archive id and it never appears as an immediate at any call to
 * the arc_tool.c entry points, because this accessor reaches ARC_TOOL_ReadMember
 * by pool word and `bx` rather than by `bl`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md): a plain scan of `bl`
 * sites misses it entirely.
 *
 * The record is a battle-facility Pokemon: FLD_BTL_INST_TOOL_BuildBattleMon, three functions
 * up in the same file (fld_btl_inst_tool.c, by the __FILE__ anchors either
 * side of this address), reads the buffer field by field into a party
 * slot: +0 species (masked to 11 bits), +2/+4/+6/+8 the four move ids,
 * +10 a six-bit "which stats are EV-invested" mask (the caller divides 510
 * EVs between the set bits), +11 the nature (0..24 over the whole archive),
 * +12 the held item and +14 the form (five bits, always zero here).  The
 * member ids come from a/2/1/5, whose own reader is FLD_BTL_INST_TOOL_LoadTrainerGroup
 * immediately below this one.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLD_BTL_INST_TOOL_ReadMonData.c \
 *       --func FLD_BTL_INST_TOOL_ReadMonData --addr 0x02168800 --region ov010 \
 *       --cc 1.1p1 --thumb
 */
void FLD_BTL_INST_TOOL_ReadMonData(void *dest, u32 memberId)
{
    ARC_TOOL_ReadMember(dest, 214, memberId);
}

/*
 * The reader for a/2/1/5: allocate a buffer and load one group record.
 * ARC_UTIL_LoadMember(archive_id, member, flag, heap) is arc_util.c's
 * "allocate and read a member" helper, so the returned pointer is the
 * sub-file itself.
 *
 * Two things the bytes pin down.  The member is `group + 1`, truncated to
 * 16 bits before the call, so group 0 is sub-file 1 and sub-file 0 is the
 * usual unused sentinel.  And the record is the group list documented in
 * docs/ASSETS.md, [u16 group_id][u16 count][u16 member_id x count]: its
 * consumer FLD_BTL_INST_TOOL_DrawTrainerParty takes `count` from +2, picks a random index below
 * it, reads `member_id` from +4 + 2*index, and hands that id to
 * FLD_BTL_INST_TOOL_ReadMonData, the a/2/1/4 record reader immediately above this
 * function.  That is the direct evidence that a/2/1/5's member ids index
 * a/2/1/4, which the previous pass could only infer from the id range.
 *
 * Addresses are Black-image addresses.  --region ov010 is required.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLD_BTL_INST_TOOL_LoadTrainerGroup.c \
 *       --func FLD_BTL_INST_TOOL_LoadTrainerGroup --addr 0x0216880C --region ov010 \
 *       --cc 1.1p1 --thumb
 */
void *FLD_BTL_INST_TOOL_LoadTrainerGroup(u32 group, u32 heapId)
{
    return (void *)ARC_UTIL_LoadMember(215, (u16)(group + 1), 0, heapId);
}

/*
 * Random 16-bit value: a 32-bit random number (full range) reduced by 0xFFFF.
 */
int FLD_BTL_INST_TOOL_GetRandomU16(void)
{
    u32 range;

    range = ~0;
    return (u16)(GFL_USE_GetRandom(range) / (range >> 16));
}

/*
 * IV value for a battle-facility trainer index: a step table over the
 * index (3 below 50, up to 31 from 200). Returns u8: FLD_BTL_INST_TOOL_DrawTrainerParty
 * stores the result to its u8 local without an extension.
 */
u8 FLD_BTL_INST_TOOL_GetIvForRank(u32 rank)
{
    if (rank < 50)
        return 3;
    if (rank < 70)
        return 6;
    if (rank < 90)
        return 9;
    if (rank < 110)
        return 12;
    if (rank < 160)
        return 15;
    if (rank < 180)
        return 18;
    if (rank < 200)
        return 21;
    return 31;
}

/*
 * Creates a facility trainer: loads the trainer header, then draws the party.
 */
int FLD_BTL_INST_TOOL_CreateTrainer(BtlInstTrainer *trainer, u16 trainerIndex, int count, u16 *exclSpecies, u16 *exclItems, BtlInstDraw *draw, u16 heapId)
{
    BtlInstGroup *group = FLD_BTL_INST_TOOL_InitTrainerHeader(trainer, trainerIndex, heapId);
    int itemRuleDropped = FLD_BTL_INST_TOOL_DrawTrainerParty(group, trainerIndex, trainer->mons, (u8)count, exclSpecies, exclItems, draw, heapId);
    GFL_HEAP_Free(group);
    return itemRuleDropped;
}

/*
 * Fills the trainer header: id, type from the a/2/1/5 group, name from
 * message bank 11 and the intro message id (three messages per trainer).
 */
BtlInstGroup *FLD_BTL_INST_TOOL_InitTrainerHeader(BtlInstTrainer *trainer, int trainerIndex, int heapId)
{
    MsgData *nameBank = (struct MsgBank *)MSGDATA_CreateFromArchive(0, 2, 11, heapId);
    BtlInstGroup *group;
    Strbuf *name;
    MI_CpuFill8(trainer, 0, 0x120);
    group = FLD_BTL_INST_TOOL_LoadTrainerGroup(trainerIndex, heapId);
    trainer->trainerId = trainerIndex + 1;
    trainer->introMsg.sentenceType = 0xFFFF;
    trainer->introMsg.sentenceId = trainerIndex * 3;
    trainer->trainerType = group->trainerType;
    name = MSGDATA_AllocString((struct MsgBank *)nameBank, trainerIndex);
    STRBUF_ToChars(name, trainer->name, 16);
    STRBUF_Delete(name);
    MSGDATA_Delete((struct MsgBank *)nameBank);
    return group;
}

/*
 * Draws `count` distinct battle-facility Pokemon from an a/2/1/5 group
 * list (FLD_BTL_INST_TOOL_LoadTrainerGroup's record): no repeated species, none of the
 * excluded species, and for the first 50 tries no repeated or excluded
 * held item. Builds each one with FLD_BTL_INST_TOOL_BuildBattleMon under one random trainer
 * id and optionally reports the first two draws. Returns 1 when the
 * item rule had to be dropped.
 *
 * Levers: locals declared in reverse of their frame order (the arrays
 * after natures, the scalars from otId down), the IV step as u8 (its
 * reader returns only constants up to 31), and a 16-bit `rank` parameter,
 * which moves the r1 spill ahead of the r3 copy (u8 matches equally; int
 * and u32 are 4 bytes out).
 */
int FLD_BTL_INST_TOOL_DrawTrainerParty(BtlInstGroup *group, u16 rank, BattleMon *mons, int count, u16 *exclSpecies, u16 *exclItems, BtlInstDraw *draw, u16 heapId)
{
    u8 natures[4];
    int memberIds[4];
    u32 pids[4];
    BtlInstMonData otherData;
    BtlInstMonData data;
    u32 otId;
    u8 iv;
    int memberId;
    int itemTries;
    int itemRuleDropped;
    int i;
    int drawn;

    itemRuleDropped = 0;
    itemTries = 0;
    drawn = 0;
    while (drawn != count) {
        memberId = group->memberIds[(u8)(FLD_BTL_INST_TOOL_GetRandomU16() % group->count)];
        FLD_BTL_INST_TOOL_ReadMonData(&data, memberId);
        for (i = 0; i < drawn; i++) {
            FLD_BTL_INST_TOOL_ReadMonData(&otherData, memberIds[i]);
            if (otherData.species == data.species)
                break;
        }
        if (i != drawn)
            continue;
        if (exclSpecies != 0) {
            for (i = 0; i < count; i++) {
                if (data.species == exclSpecies[i])
                    break;
            }
            if (i != count)
                continue;
        }
        if (itemTries < 50) {
            for (i = 0; i < drawn; i++) {
                FLD_BTL_INST_TOOL_ReadMonData(&otherData, memberIds[i]);
                if (otherData.item != 0 && otherData.item == data.item)
                    break;
            }
            if (i != drawn) {
                itemTries++;
                continue;
            }
            if (exclItems != 0) {
                for (i = 0; i < count; i++) {
                    if (data.item == exclItems[i] && exclItems[i] != 0)
                        break;
                }
                if (i != count) {
                    itemTries++;
                    continue;
                }
            }
        }
        memberIds[drawn] = memberId;
        natures[drawn] = data.nature;
        drawn++;
    }

    iv = FLD_BTL_INST_TOOL_GetIvForRank(rank);
    otId = FLD_BTL_INST_TOOL_GetRandomU16() | (FLD_BTL_INST_TOOL_GetRandomU16() << 16);
    if (itemTries >= 50)
        itemRuleDropped = 1;
    for (i = 0; i < drawn; i++)
        pids[i] = FLD_BTL_INST_TOOL_BuildBattleMon(&mons[i], (u16)memberIds[i], otId, 0, iv, i, itemRuleDropped, heapId);
    if (draw == 0)
        return itemRuleDropped;
    draw->otId = otId;
    for (i = 0; i < 2; i++) {
        draw->ids[i] = memberIds[i];
        draw->pids[i] = pids[i];
        draw->natures[i] = natures[i];
    }
    return itemRuleDropped;
}

/*
 * Nonzero when either of the two battle message sentences of the trainer
 * has any word set.
 */
int FLD_BTL_INST_TOOL_HasBattleMsgs(BtlInstTrainer *trainer)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (trainer->battleMsgs.half[i] != 0)
            return 1;
        if (trainer->battleMsgs.half[i + 4] != 0)
            return 1;
    }
    return 0;
}

/*
 * Recursive MATCH unblocker: ABS32 target of TRIAL_HOUSE_GetTrainerObjCode (ov021) +0008.
 * Coherent Thumb code in ov010 (ARM data in ov009), so the ov010 shard makes
 * that site attest as `matched`.
 *
 * Looks a key up in a table of 0x35 (key, value) halfword pairs; 0xA when
 * the key is absent.
 */
u16 FLD_BTL_INST_TOOL_LookupKeyValue(u16 key)
{
    u32 i;

    for (i = 0; i < 0x35; i++) {
        if (g_0217208C[i * 2] == key)
            return g_0217208E[i * 2];
    }
    return 0xA;
}

/*
 * Unlabelled leaf callback (movs r1,#1; str r1,[r0]; bx lr); filed as the
 * sole blocker of FLD_BTL_INST_TOOL_CommResetEventMain (its pool word). Sets the done flag.
 */
void FLD_BTL_INST_TOOL_SetDoneFlag(int *doneFlag)
{
    *doneFlag = 1;
}

/*
 * Comm reset event step: leave the comm session, optionally restart the
 * automatic comm, then ask the field to reset and wait for its callback.
 *
 * lever: 02026454 reads the live 02012138 result in r0 in cases 0 and 1.
 */
int FLD_BTL_INST_TOOL_CommResetEventMain(GameEvent *event, int *step, CommResetWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    struct FieldSubscreen *subscreen = FIELDMAP_GetSubscreen(GAMESYSTEM_GetFieldMap(gameSystem));
    GameComm *gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    CommResetStep current = (CommResetStep)*step;
    switch (current) {
    case COMM_RESET_REQUEST_EXIT:
        if (GAME_COMM_GetKind(gameComm) != 0)
            GAME_COMM_RequestExitNoCallback(gameComm);
        (*step)++;
        break;
    case COMM_RESET_WAIT_EXIT:
        if (GAME_COMM_GetKind(gameComm) != 0)
            break;
        GAMESYSTEM_SetAlwaysNetFlag(gameSystem, 0);
        (*step)++;
        break;
    case COMM_RESET_RESTORE_AUTO_COMM:
        if (work->restoreAutoComm != 0) {
            GAMESYSTEM_SetAlwaysNetFlag(gameSystem, 1);
            GAMESYSTEM_TryStartAutoComm(gameSystem);
        }
        (*step)++;
        break;
    case COMM_RESET_REQUEST_FIELD_RESET:
        FIELD_SUBSCREEN_RequestModeWithCallback(subscreen, 8, (void (*)(int))FLD_BTL_INST_TOOL_SetDoneFlag, (uptr)work);
        (*step)++;
        break;
    case COMM_RESET_WAIT_DONE:
        if (work->done != 0)
            *step = current + 1;
        break;
    case COMM_RESET_END:
        return 1;
    }
    return 0;
}

/*
 * Creates the comm reset event.
 */
GameEvent *FLD_BTL_INST_TOOL_CreateCommResetEvent(GameSystem *gameSystem, int restoreAutoComm)
{
    GameEvent *event;
    CommResetWork *work;
    GAMESYSTEM_GetGameData(gameSystem);
    event = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)FLD_BTL_INST_TOOL_CommResetEventMain, 0xc);
    work = GAME_EVENT_GetWork(event);
    MI_CpuFill8(work, 0, 0xc);
    work->gameSystem = gameSystem;
    work->restoreAutoComm = restoreAutoComm;
    return event;
}

/*
 * Creates the party select wrapper event. With useTempParty the party is a
 * fresh five-slot party that the event frees at its end, otherwise it is
 * the player's own party.
 */
GameEvent *FLD_BTL_INST_TOOL_CreatePartySelectStepEvent(GameSystem *gameSystem, BtlInstBattleRequest *request, int regulationId, int useTempParty, u16 *resultOk)
{
    GameEvent *event;
    GameData *gameData;
    PartySelectStepWork *work;
    int listArg;
    Party *party;
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    event = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)FLD_BTL_INST_TOOL_PartySelectStepEventMain, 0x34);
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    work->fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    work->resultOk = resultOk;
    work->request = request;
    if (regulationId == 0x14 || regulationId == 0x15) {
        if (regulationId == 0x14) {
            work->listArg = 0;
            listArg = 0x14;
        } else {
            work->listArg = 1;
            listArg = 0x15;
        }
    } else {
        work->listArg = 0;
        listArg = 0x14;
    }
    work->regulationId = listArg;
    if (useTempParty == 0) {
        work->tempParty = 0;
        party = GAME_DATA_GetMyParty(gameData);
    } else {
        party = BATTLE_BOX_CreateParty((struct BoxMonGroup *)(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(gameData))), 5);
        work->tempParty = party;
    }
    work->party = party;
    return event;
}

/*
 * Party select wrapper step: state 0 starts the party select event and moves to state 1;
 * state 1 frees the temporary party and stores whether the player confirmed (a command of 0
 * and a slot other than 7 and 8). The flag store is written in each arm of the if/else
 * (2026-10-05 recoup), which keeps the store before the epilogue add sp.
 */
int FLD_BTL_INST_TOOL_PartySelectStepEventMain(GameEvent *event, int *step, PartySelectStepWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    switch (*step) {
    case 0: {
        GameEvent *child = FLD_BTL_INST_TOOL_CreatePokeListEvent(gameSystem, work->listArg, 0x17, work->regulationId, work->party, work->selectOrder, &work->resultSlot, &work->resultCommand, work->request->playerParty);
        GAME_EVENT_CallEvent(event, child);
        *step = 1;
        break;
    }
    case 1:
        if (work->tempParty != 0)
            GFL_HEAP_Free(work->tempParty);
        if (work->resultCommand != 0 || work->resultSlot - 7 <= 1)
            *work->resultOk = 0;
        else
            *work->resultOk = 1;
        return 1;
    }
    return 0;
}

/*
 * accepted 2026-10-05 by the user: the held form (see the notes below) is accepted as plausible original source.
 * recoup 2026-10-05 (P21L10): extent 60 B includes a 2-byte pad (movs r0,r0); code is 58 B.
 * The old draft (12 B off, only the ldr r2 position and the lsls/adds r6 order) closed by
 * dropping const from the record pointer and the byte-pointer casts: EXACT* in c99 and c.
 * Not filed as matched: the offset enum local (off = BTL_INST_REQUEST_MODE_OFFSET, then off - 4, off - 8) is only
 * there to stop mwcc folding 0x12c into the load offsets. With int k or a plain int typedef,
 * literals, struct fields or a named kind local the compiler folds to a 0x49 base (40 B off).
 * A human reason for the held 0x12c is not known; integrator decides. Callee FLD_BTL_INST_TOOL_CreateBtlSetup
 * has u8 kind/n params in the ov021 twin caller but this caller passes full words (no
 * truncation), so the prototype here is int. pragmas scheduling/peephole/opt_lifetimes off:
 * no change on the old const form (12 B). unsigned kind: 15 B.
 *
 * Creates the facility trainer battle event from a battle request.
 */
GameEvent *FLD_BTL_INST_TOOL_CreateBattleEvent(GameSystem *gameSystem, BtlInstBattleRequest *request)
{
    FieldMap *fieldMap;
    BtlInstRequestOffset mode;
    BtlInstRequestOffset off;
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    off = BTL_INST_REQUEST_MODE_OFFSET;
    mode = (BtlInstRequestOffset)*(int *)((u8 *)request + off);
    return (GameEvent *)EVENT_BATTLE_CreateForcedWinTask(gameSystem, fieldMap, FLD_BTL_INST_TOOL_CreateBtlSetup(gameSystem, *(Party *const *)((u8 *)request + (off - 4)), mode, (BtlInstTrainer *)request, 0, *(int *)((u8 *)request + (off - 8))));
}

/*
 * Add one battle's tallies into the running record and credit the
 * score share against the party's summed stat 0xA1. First draft.
 */
void FLD_BTL_INST_TOOL_AddBattleTally(BtlInstRecord *record, struct BattleSetupParam *result)
{
    Party *party;
    int count;
    int i;
    int statSum;

    record->tally[0] += (u16)(result->turnCount + 1);
    record->tally[1] += result->stats[0];
    record->tally[2] += result->stats[1];
    record->tally[3] += result->stats[2];
    record->tally[4] += result->stats[3];
    record->tally[5] += result->stats[4];
    record->tally[6] += result->stats[5];
    record->tally[7] += result->won;
    record->tally[8] += result->enemyFainted;
    record->tally[9] += result->ownFainted;
    record->lastTally += result->moveUseTotal;
    party = result->party[0];
    count = POKEPARTY_GetCount(party);
    statSum = 0;
    for (i = 0; i < count; i++)
        statSum += POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(party, i), 0xA1, 0);
    record->scoreShare += (u16)(result->hpSum * 100 / statSum);
}

/*
 * Creates the trial house award event: reads the player's sex and the
 * trial house save and hands them to the ov220 award screen.
 */
GameEvent *FLD_BTL_INST_TOOL_CreateTrialHouseAwardEvent(GameSystem *gameSystem, int hasSecondEntry, int fadeOutBgm)
{
    GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)FLD_BTL_INST_TOOL_TrialHouseAwardEventMain, 0x18);
    TrialHouseAwardEventWork *work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    work->fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    work->param.playerSex = MYSTATUS_GetSex(GAME_DATA_GetMyStatus(gameData));
    work->param.trialHouse = TRIAL_HOUSE_SAVE_GetFromSave(GAME_DATA_GetSaveControl(gameData));
    work->param.hasSecondEntry = hasSecondEntry;
    work->param.fadeOutBgm = fadeOutBgm;
    return event;
}

/*
 * former blocker: pooled ov220_id is passed to GAME_EVENT_CallProc r1, missing from
 * OVERLAY_ID_CONSUMERS. Its matched body stores a1 to payload[0]; matched
 * GAME_EVENT_CallProcSeq forwards item[0] as GAMESYSTEM_CallProc r1 (known consumer).
 * The ov220 table hint is supported by that load chain; matcher refuses
 * it as contested until the ID site resolves. No code leaf blocks this.
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int FLD_BTL_INST_TOOL_TrialHouseAwardEventMain(GameEvent *event, int *step)
{
    TrialHouseAwardEventWork *work;
    work = GAME_EVENT_GetWork(event);
    switch (*step) {
    case 0:
        GAME_EVENT_CallProc(event, (uptr)ov220_id, (void *)d_021BA39C, &work->param);
        (*step)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
