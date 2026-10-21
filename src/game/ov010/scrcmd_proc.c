/*
 * file:     scrcmd_proc.c
 * unit:     yes
 * function: SCRCMD_PROC_LookupTableValue, SCRCMD_PROC_GetPartyMember, SCRCMD_PROC_GetPartyMemberParam, SCRCMD_PROC_CheckMonKnowsMove, SCRCMD_PROC_GetMonPairedParams, SCRCMD_PROC_HealParty, SCRCMD_PROC_GetMonEvTotal, SCRCMD_PROC_CheckMonHpNotFullOrEgg, SCRCMD_PROC_CheckMonIsEgg, SCRCMD_PROC_GetMonFriendship, SCRCMD_PROC_ChangeMonFriendship, SCRCMD_PROC_GetMonSpeciesOrEgg, SCRCMD_PROC_GetMonForm, SCRCMD_PROC_FindFirstPartyIndex, SCRCMD_PROC_GetPartyCount, SCRCMD_PROC_CountPartyMonsOfSpecies, SCRCMD_PROC_GetBoxMonCount, SCRCMD_PROC_FindPartyMonBySpecies, SCRCMD_PROC_CheckPartyMonKnowsMove, SCRCMD_PROC_FindPartyMonWithMove, SCRCMD_PROC_AddMonToPartySimple, SCRCMD_PROC_AddMonToPartyDetailed, SCRCMD_PROC_CountMonMoves, SCRCMD_PROC_GetMonMove, SCRCMD_PROC_SetMonMove, SCRCMD_PROC_CheckMonIsPlayerOwned, SCRCMD_PROC_ChangeMonForm, SCRCMD_PROC_SetRotomFormMove, SCRCMD_PROC_GetRelearnableMoveCount, SCRCMD_PROC_CheckMonParamMatchesTable, SCRCMD_PROC_GetMonTripleParams, SCRCMD_PROC_SetMonParamChecked, SCRCMD_PROC_GetMonParamIfListed, SCRCMD_PROC_AddMonToBoxSimple, SCRCMD_PROC_AddMonToBoxDetailed, SCRCMD_PROC_AddEggToParty, SCRCMD_PROC_CreateMonFromSpec, SCRCMD_PROC_AddMonToBox, SCRCMD_PROC_AddMonToParty, SCRCMD_PROC_AddMoney, SCRCMD_PROC_SubMoney, SCRCMD_PROC_CheckMoneyAtLeast, SCRCMD_PROC_CallFieldOpenEvent, SCRCMD_PROC_CallFieldCloseEvent, SCRCMD_PROC_StartOverlayProc, SCRCMD_PROC_WaitOverlayProc, SCRCMD_PROC_FreeScriptUserWork, SCRCMD_PROC_OnBagClosed, SCRCMD_PROC_CallBagScreen, SCRCMD_PROC_OnGtsNegotiationDone, SCRCMD_PROC_CallGtsNegotiation, SCRCMD_PROC_OnMoveRelearnDone, SCRCMD_PROC_CallMoveRelearn, SCRCMD_PROC_CallPlayerProfile, SCRCMD_PROC_CallSubEvent, SCRCMD_PROC_CallValueScreen, SCRCMD_PROC_CallModeScreen, SCRCMD_PROC_CallWordScreen, SCRCMD_PROC_WaitNothing, SCRCMD_PROC_CallWifiBattleMatch, SCRCMD_PROC_CallMenuProc, SCRCMD_PROC_Ov037InitFromVars, SCRCMD_PROC_Ov037SetValueA, SCRCMD_PROC_Ov037SetValueB, SCRCMD_PROC_Ov037ReadEightVars, SCRCMD_PROC_Ov037Finish, SCRCMD_PROC_CheckDaycareHasEgg, SCRCMD_PROC_ReceiveDaycareEgg, SCRCMD_PROC_DeclineDaycareEgg, SCRCMD_PROC_CallDaycarePartyMenu, SCRCMD_PROC_DepositDaycareMon, SCRCMD_PROC_WithdrawDaycareMon, SCRCMD_PROC_GetDaycareMonCount, SCRCMD_PROC_GetDaycareCompatibility, SCRCMD_PROC_GetDaycareMonSpecies, SCRCMD_PROC_GetDaycareMonForm, SCRCMD_PROC_GetDaycareMonGender, SCRCMD_PROC_GetDaycareSlotLevel, SCRCMD_PROC_GetDaycareSlotLevelsGrown, SCRCMD_PROC_GetDaycareSlotPrice, SCRCMD_PROC_GetDaycareMonGenderKindIfFirst, SCRCMD_PROC_GetDaycareGenderKind
 * address:  0x0215B488
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from scrcmd_proc.c by tools/splitfile.py.
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   sScrcmdLookupTable 0x02171170 data a2
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue   0x02017E1C  thumb
 *   POKE_TOOL_HealParty  0x0201BA34  thumb
 *   VM_ReadU16  0x02011330  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKEPARTY_FindFirstBattleReady  0x0201AB08  thumb
 *   POKEPARTY_FindFirstNonEgg  0x0201AB18  thumb
 *   POKEPARTY_GetCapacity  0x0201AA14  thumb
 *   POKEPARTY_GetNonEggCount  0x0201AA1C  thumb
 *   POKEPARTY_GetBattleReadyCount  0x0201AA50  thumb
 *   POKEPARTY_GetEggCount  0x0201AA88  thumb
 *   POKEPARTY_GetBadEggCount  0x0201AAD4  thumb
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb
 *   BOX_SAVEDATA_CountPokemon  0x02007984  thumb
 *   BOX_SAVEDATA_CountNonEggPokemon  0x020079A0  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   POKE_TOOL_PushMove  0x020180F4  thumb
 *   POKE_TOOL_SetMoveSlot  0x020181F4  thumb
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   MYSTATUS_NameToStrbuf  0x02008500  thumb
 *   STRBUF_IsEqual  0x0204589C  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   g0209DF08      0x0209DF08  data  a1
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   ZUKAN_SAVE_RegisterSeen  0x0200CFA0  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   sScrcmdCompareTable     0x02171180  data   ov010  a2
 *   sScrcmdParamLimits     0x0217118E  data   ov010  a2
 *   POKE_TOOL_SetRotomFormMove  0x02017A20  thumb
 *   WAZA_OSHIE_CreateMoveList  0x0216F948  thumb  ov010
 *   WAZA_OSHIE_IsListEntryValid  0x0216FAA0  thumb  ov010
 *   GFL_HEAP_Free  0x020307B0  arm
 *   sScrcmdAllowedParamIds 0x02171182 data a1
 *   POKE_TOOL_Create  0x020173F0  thumb
 *   MYSTATUS_CreateNameStrbuf  0x02008510  thumb
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   SAVE_EVENT_Write  0x0202F190  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   gSpeciesNameBank     0x020A7370  data
 *   POKE_TOOL_CreatePersonalRnd 0x020186C8 thumb
 *   POKE_TOOL_CreateEx 0x02017430 thumb
 *   FILE_UTIL_GetItemParam 0x02020FE4 thumb
 *   PALANM_GetPairedCodeForFirst 0x0202142C thumb
 *   GAME_DATA_GetMyPlayerWork 0x020127A4 thumb
 *   GAME_DATA_GetPlayerZoneId 0x02012AC8 thumb
 *   ZONEDATA_GetPlaceNameId 0x02013E4C thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   BOX_SAVEDATA_AddPokemon  0x020074D8  thumb
 *   ZUKAN_SAVE_RegisterCaught  0x0200CDE0  thumb
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   MISC_AddMoney 0x0200C278 thumb
 *   MISC_SubMoney 0x0200C29C thumb
 *   MISC_GetMoney 0x0200C274 thumb
 *   FIELD_STATUS_CreateFieldOpenEvent   0x020145CC  thumb
 *   SCRIPT_SYS_CallEvent   0x0215897C  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   SCRIPT_WORK_GetUserWorkPtr  0x02158FB4  thumb  ov010
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   VM_SetWait  0x020113D0  thumb
 *   sAllocSiteScrcmdProc     0x021728F0  data  a1
 *   SCRIPT_WORK_GetUserWork  0x02158FB8  thumb  ov010
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   SCRIPT_WORK_FreeUserWork  0x02158FBC  thumb  ov010
 *   BAG_PARAM_Create  0x0202E474  thumb
 *   ov070_id       0x00000046  data
 *   gItemMenuProcData     0x021BB96C  data  ov070 a4
 *   FIELD_STATUS_CreateSubProcNoFadeCallbackEvent  0x02014840  thumb
 *   ov136_id       0x00000088  data
 *   gMbSeqProcData     0x021C78A4  data  ov136  a1
 *   WAZA_OSHIE_Delete  0x0216F940  thumb  ov010
 *   WAZA_OSHIE_Create 0x0216F918 thumb ov010
 *   FIELD_STATUS_CreateSubProcCallbackEvent 0x02014808 thumb
 *   ov173_id 0x000000AD data
 *   gMoveRelearnProcData 0x021B81D0 data ov173 a4
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   GAME_DATA_GetIntrudeIdByte  0x0215841C  thumb  ov010
 *   INTRUDE_COMM_GetMemberNameNetId  0x02175FB4  thumb  ov011
 *   INTRUDE_COMM_GetMemberEntry  0x0215840C  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   INTRUDE_GetFromSave  0x0200BE48  thumb
 *   INTRUDE_COMM_BuildLocalProfile  0x02175648  thumb  ov011
 *   gPlayerProfileProcData     0x021BA758  data  ov099  a1
 *   ov071_id       0x00000047  data
 *   SCRIPT_WORK_GetEvent  0x02158F50  thumb  ov010
 *   EVENT_FIELD_PROCLINK_CreateCommExitEvent  0x02161B90  thumb  ov010
 *   ov174_id       0x000000AE  data
 *   gLocalTvtSysProcData     0x021B74A0  data  a1 ov174
 *   GAME_BEACON_SEARCH_SetScriptEvent  0x02165344  thumb  ov010
 *   ov221_id       0x000000DD  data
 *   ov222_id       0x000000DE  data
 *   ov224_id       0x000000E0  data
 *   gChihouZukanAwardProcData     0x021BA1A4  data  ov221  a4
 *   gZenkokuZukanAwardProcData     0x021BA250  data  ov222  a4
 *   gSubwayMapProcData     0x021B9BF8  data  ov224  a4
 *   ov223_id       0x000000DF  data
 *   gPselProcData     0x021BC8C4  data  ov223
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   EVENT_WIFIBATTLEMATCH_Entry  0x02154438  thumb  ov002
 *   ov002_id       0x00000002  data
 *   EVENT_MENUPROC_Entry  0x021543BC  thumb  ov003
 *   ov003_id       0x00000003  data
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   GIMMICK_INIT_SetCartLanesFlags  0x021F36C0  thumb  ov037
 *   ov037_id       0x00000025  data
 *   GIMMICK_INIT_SetFlagAnimeFlag 0x021F36E8 thumb ov037
 *   GIMMICK_INIT_SetButtonStatesFlags 0x021F3724 thumb ov037
 *   GIMMICK_INIT_RestorePlateDoorsState  0x021F3768  thumb  ov037
 *   GIMMICK_INIT_ResetRotatingRoomPanels 0x021F3800 thumb ov037
 *   FIELDMAP_GetSodateya  0x02188D50  thumb
 *   SODATEYA_HasEgg  0x021C3400  thumb  ov021
 *   SODATEYA_ReceiveEgg 0x021C32F4 thumb ov021
 *   SODATEYA_DeclineEgg  0x021C335C  thumb
 *   DAYCARE_GetFromSave  0x0200BDB0  thumb
 *   SODATEYA_DepositPokemon 0x021C3204 thumb ov021
 *   SODATEYA_WithdrawPokemon 0x021C3270 thumb ov021
 *   SODATEYA_GetPokemonCount  0x021C340C  thumb
 *   SODATEYA_GetCompatibility  0x021C34C4  thumb
 *   SODATEYA_GetPokemon 0x021C34F8 thumb ov021
 *   SODATEYA_GetCurrentLevel 0x021C341C thumb ov021
 *   SODATEYA_GetLevelsGained 0x021C3490 thumb ov021
 *   SODATEYA_GetWithdrawCost 0x021C34B4 thumb ov021
 *   SCRCMD_SODATEYA_Create 0x0215D2A4 thumb ov010
 */
#include "scrcmd_proc_shared_types.h"

struct ScriptVm;

struct PokemonParam;

struct Strbuf;

struct MyStatus;

struct Party;

struct MsgBank;

struct PersonalData;

struct PlayerWork;

struct BoxPokemonParam;

struct MiscSave;


#include "../types.h"
#ifdef __MWERKS__
#define POKE_TOOL_Create POKE_TOOL_Create_header
#endif
#include "../arm9/poke_tool.h"
#ifdef __MWERKS__
#undef POKE_TOOL_Create
#endif

typedef enum { B_FALSE, B_TRUE } Bool;

/* Creation request shared by the party and box helpers (offsets as read). */
typedef struct PokemonSpec {
    u16 heapId;         /* 0x00 */
    u16 pad02;
    int species;        /* 0x04 */
    int form;           /* 0x08 */
    int level;          /* 0x0C */
    int heldItem;       /* 0x10 */
    int genderMode;     /* 0x14 */
    int natureMode;     /* 0x18 */
    int shinyMode;      /* 0x1C */
    int ballItem;       /* 0x20 */
} PokemonSpec;

/* Record the overlay-launch helper parks in the script's event slot. */
typedef void (*ScriptProcFinishFn)(void *handoff);

typedef struct ScriptProcHandoff {
    void *work;                   /* 0x00 */
    void *userData;               /* 0x04 */
    ScriptProcFinishFn onFinish;  /* 0x08, function called with the record when set */
} ScriptProcHandoff;

typedef struct BagResultVars { u16 *selectedVar; u16 *itemVar; } BagResultVars;

typedef struct BagParamResult { char pad[0x34]; u32 selected; u32 itemId; } BagParamResult;

typedef struct BagCloseData { BagParamResult *bagParam; BagResultVars *resultVars; } BagCloseData;

typedef struct GtsParam {
    void *gameData;     /* 0x00 */
    u32 result;         /* 0x04, written by the overlay */
} GtsParam;

typedef struct GtsCallbackData {
    GtsParam *param;
    u16 *resultVar;
} GtsCallbackData;

typedef struct MoveRelearnParam {
    void *mon;          /* 0x00 */
    void *myStatus;     /* 0x04 */
    u32 flags;          /* 0x08 */
    void *gameSystem;   /* 0x0C */
    void *relearnMoves; /* 0x10 */
    u8 pad14[5];
    u8 enabled;         /* 0x19 */
    u8 learned;         /* 0x1A, set by the overlay */
} MoveRelearnParam;

typedef struct RelearnCallbackData {
    MoveRelearnParam *param;
    u16 *resultVar;
} RelearnCallbackData;

#include "../ov011/intrude_comm_types.h"

typedef struct ProfileProcWork {
    void *gameSystem;   /* 0x00 */
    IntrudeMemberEntry name;    /* 0x04 */
    IntrudeRemoteRecord profile;  /* 0x2C */
    u8 playerIndex;     /* 0x3C */
    u8 isRemote;        /* 0x3D */
    u8 pad3E[2];
} ProfileProcWork;

typedef struct ValueProcParam {
    u16 value;          /* 0x00 */
    u16 pad02;
    void *gameData;     /* 0x04 */
} ValueProcParam;

typedef struct ModeProcParam {
    void *gameData;     /* 0x00 */
    u32 value;          /* 0x04 */
} ModeProcParam;

typedef struct WifiBattleMatchParam {
    void *fieldMap;     /* 0x00 */
    u32 enabled;        /* 0x04 */
    u32 flag;           /* 0x08 */
    u32 matchKind;      /* 0x0C */
} WifiBattleMatchParam;

typedef struct MenuProcParam { u32 fieldMap; u32 mode; } MenuProcParam;

struct ScriptVm;
struct ScrcmdWork;
#ifdef __MWERKS__
extern unsigned short SCRIPT_WORK_ReadWorkValue(void *, void *); /* original prototype; the definition differs in pointer type, return type */
#else
extern unsigned short SCRIPT_WORK_ReadWorkValue(struct ScriptVm*, struct ScrcmdWork*);
#endif
struct ScrcmdWork;

extern u16 *SCRIPT_WORK_ReadWorkPointer(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
struct GameData;

#include "scrcmd_work.h"

#include "../arm9/game_data.h"

#include "../arm9/pokeparty.h"



#include "../arm9/poke_tool_ext.h"











#include "../arm9/box_savedata.h"

struct GameSystem;








#include "../arm9/mystatus.h"

#include "../arm9/strbuf.h"






#include "../arm9/gamesystem.h"


#include "../arm9/zukan_save.h"





#include "../arm9/gfl_heap_wrap.h"


#ifdef __MWERKS__
extern struct PokemonParam *POKE_TOOL_Create(u32 species, u32 level, u64 otId, u32 heapId); /* original prototype; the definition differs in argument width */
#else
#endif


#include "../arm9/poke_personal.h"



#include "../arm9/msgdata.h"

#ifdef __MWERKS__
extern void SAVE_EVENT_Write(void *gameData, u32 mode, struct MyStatus *record, u32 eventId, u32 index); /* original prototype; the definition differs in argument width */
#else
#include "../arm9/save_event.h"
#endif




#include "../arm9/file_util.h"

#include "../arm9/palanm.h"



#include "../arm9/zonedata.h"
struct BoxPokemon;





#include "../arm9/beacon.h"


struct GameEvent;


#include "script_sys.h"

struct FieldMap;

struct ScriptWork;

#include "script_work.h"



#include "../arm9/vm.h"



struct BigObj;

#include "../arm9/bag_param.h"


#include "waza_oshie.h"
#include "../arm9/field_status.h"


struct GameComm;

struct IntrudeCommSys;

#include "intrude_comm_query.h"


struct IntrudeMemberName;

#include "../ov011/intrude_comm.h"
struct IntrudeMemberEntry;

struct SaveControl;

struct IntrudeSave;

#include "../arm9/intrude.h"
struct IntrudeProfileData;



#include "event_field_proclink.h"

#include "game_beacon_set.h"

#include "../arm9/game_event.h"

#include "../ov002/event_wifibattlematch.h"

struct LaunchRequest;
extern void*EVENT_MENUPROC_Entry(void*, struct LaunchRequest*);

#include "../arm9/gf_overlay.h"


#include "../ov037/gimmick_init_helpers.h"




struct Sodateya;

#include "../ov021/fieldmap.h"

#include "../ov021/sodateya.h"
struct SodateyaWork;


struct DaycareSave;

#include "../arm9/daycare.h"









int SCRCMD_PROC_LookupTableValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetPartyMember(struct ScrcmdWork *cmdWork, u32 partyIndex, void **outMemberArg);

int SCRCMD_PROC_GetPartyMemberParam(struct ScrcmdWork *cmdWork, u32 partyIndex, u32 paramId);

int SCRCMD_PROC_CheckMonKnowsMove(struct PokemonParam *, int);

int SCRCMD_PROC_GetMonPairedParams(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_HealParty(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetMonEvTotal(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CheckMonHpNotFullOrEgg(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CheckMonIsEgg(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetMonFriendship(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_ChangeMonFriendship(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetMonSpeciesOrEgg(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetMonForm(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FindFirstPartyIndex(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetPartyCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CountPartyMonsOfSpecies(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetBoxMonCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FindPartyMonBySpecies(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CheckPartyMonKnowsMove(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FindPartyMonWithMove(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_AddMonToPartySimple(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_AddMonToPartyDetailed(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CountMonMoves(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetMonMove(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_SetMonMove(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CheckMonIsPlayerOwned(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_ChangeMonForm(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_SetRotomFormMove(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetRelearnableMoveCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CheckMonParamMatchesTable(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetMonTripleParams(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_SetMonParamChecked(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetMonParamIfListed(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_AddMonToBoxSimple(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_AddMonToBoxDetailed(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_AddEggToParty(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

void *SCRCMD_PROC_CreateMonFromSpec(void *, PokemonSpec *);

int SCRCMD_PROC_AddMonToBox(void *gameData, PokemonSpec *spec);

int SCRCMD_PROC_AddMonToParty(void *gameData, PokemonSpec *spec);

int SCRCMD_PROC_AddMoney(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_SubMoney(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CheckMoneyAtLeast(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CallFieldOpenEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CallFieldCloseEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

void SCRCMD_PROC_StartOverlayProc(struct ScriptVm *, struct ScrcmdWork *, u32 overlayId, const void *procData, void *procWork, ScriptProcFinishFn onFinish, void *userData);

int SCRCMD_PROC_WaitOverlayProc(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FreeScriptUserWork(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

void SCRCMD_PROC_OnBagClosed(BagCloseData *closeData);

int SCRCMD_PROC_CallBagScreen(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

void SCRCMD_PROC_OnGtsNegotiationDone(GtsCallbackData *callbackData);

int SCRCMD_PROC_CallGtsNegotiation(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_OnMoveRelearnDone(RelearnCallbackData *callbackData, int callArg1);

int SCRCMD_PROC_CallMoveRelearn(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CallPlayerProfile(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CallSubEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CallValueScreen(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CallModeScreen(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CallWordScreen(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_WaitNothing(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CallWifiBattleMatch(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CallMenuProc(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_Ov037InitFromVars(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_Ov037SetValueA(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_Ov037SetValueB(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_Ov037ReadEightVars(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_Ov037Finish(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CheckDaycareHasEgg(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_ReceiveDaycareEgg(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_DeclineDaycareEgg(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_CallDaycarePartyMenu(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_DepositDaycareMon(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_WithdrawDaycareMon(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetDaycareMonCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetDaycareCompatibility(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetDaycareMonSpecies(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetDaycareMonForm(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetDaycareMonGender(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetDaycareSlotLevel(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetDaycareSlotLevelsGrown(void *, void *);

int SCRCMD_PROC_GetDaycareSlotPrice(void *, void *);

int SCRCMD_PROC_GetDaycareMonGenderKindIfFirst(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_GetDaycareGenderKind(void *);

#include "scrcmd_sodateya.h"

extern const u16 sScrcmdLookupTable[];

extern u8 g0209DF08;

extern u16 sScrcmdCompareTable[];

extern struct { u16 paramId; u16 maxValue; } sScrcmdParamLimits[6];

extern const u8 sScrcmdAllowedParamIds[];

extern void *gSpeciesNameBank;

extern const char sAllocSiteScrcmdProc[];

extern const u8 gItemMenuProcData[];

extern u8 ov070_id[];

extern const u8 gMbSeqProcData[];

extern u8 ov136_id[];

extern const u8 gMoveRelearnProcData[];

extern u8 ov173_id[];

extern const u8 gPlayerProfileProcData[];

extern u8 ov071_id[];

extern const u8 gLocalTvtSysProcData[];

extern u8 ov174_id[];

extern const u8 gChihouZukanAwardProcData[];

extern const u8 gZenkokuZukanAwardProcData[];

extern const u8 gSubwayMapProcData[];

extern u8 ov221_id[];

extern u8 ov222_id[];

extern u8 ov224_id[];

extern const u8 gPselProcData[];

extern u8 ov223_id[];

extern u8 ov002_id[];

extern char ov003_id[];

extern char ov037_id[];

/*
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 */
int SCRCMD_PROC_LookupTableValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int tableIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *resultVar = sScrcmdLookupTable[tableIndex];
    return 0;
}

int SCRCMD_PROC_GetPartyMember(struct ScrcmdWork *cmdWork, u32 partyIndex, void **outMemberArg)
{
    int isValid;
    u32 slotIndex;
    void **outMember;
    int partyCount;
    void *member;
    void *gameData;
    void *party;

slotIndex = partyIndex + 0;
outMember = outMemberArg;
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    party = GAME_DATA_GetMyParty(gameData);
    partyCount = POKEPARTY_GetCount(party);
    if (slotIndex >= (unsigned)partyCount) goto outOfRange;
isValid = 1;
    goto store;
outOfRange:
isValid = 0;
slotIndex = 0;
store:
    member = POKEPARTY_GetMember(party, slotIndex);
*outMember = member;
    return isValid;}

/*
 * Unpacks a record into a local and, when the overlay call says it took,
 * forwards the record and the third argument to the arm9 side.
 */
int SCRCMD_PROC_GetPartyMemberParam(struct ScrcmdWork *cmdWork, u32 partyIndex, u32 paramId)
{
    sptr member;

    if (SCRCMD_PROC_GetPartyMember(cmdWork, partyIndex, (void **)(&member)) == 1)
        return POKE_TOOL_GetPartyValue((void *)member, paramId, 0);

    return 0;
}

int SCRCMD_PROC_CheckMonKnowsMove(struct PokemonParam *mon, int moveId)
{
    if (POKE_TOOL_GetPartyValue(mon, 0x4c, 0) != 0) {
        return 0;
    }
    if (moveId == POKE_TOOL_GetPartyValue(mon, 0x36, 0) || moveId == POKE_TOOL_GetPartyValue(mon, 0x37, 0)
        || moveId == POKE_TOOL_GetPartyValue(mon, 0x38, 0) || moveId == POKE_TOOL_GetPartyValue(mon, 0x39, 0)) {
        return 1;
    }
    return 0;
}

int SCRCMD_PROC_GetMonPairedParams(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 *firstResultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    u16 *secondResultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    struct PokemonParam *mon;
    if (SCRCMD_PROC_GetPartyMember(cmdWork, SCRIPT_WORK_ReadWorkValue(vm, cmdWork), (void **)&mon) == 1) {
        *firstResultVar = POKE_TOOL_GetPartyValue(mon, 0xAE, 0);
        *secondResultVar = POKE_TOOL_GetPartyValue(mon, 0xAF, 0);
    } else {
        *firstResultVar = 0;
        *secondResultVar = 0;
    }
    return 0;
}

int SCRCMD_PROC_HealParty(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    void *party = GAME_DATA_GetMyParty(gameData);

    POKE_TOOL_HealParty(party);
    return 0;
}

#pragma opt_lifetimes off

#pragma opt_propagation off

/*
 * 2026-10-05 (wave P14 C6): closed with per-function opt_lifetimes off plus
 * opt_propagation off. Without them the two zeros (the named argument zero z
 * and the initial sum) merge into one register and the first add folds to
 * adds r0,r0,#0 (35 B off, 166 B). opt_lifetimes off alone: 2 B off.
 */
int SCRCMD_PROC_GetMonEvTotal(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 *resultVar = (u16 *)SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int zero = 0;
    u16 evTotal = 0;
    void *mon;
    if (SCRCMD_PROC_GetPartyMember(cmdWork, partyIndex, &mon) == 1) {
        evTotal = zero + (u16)POKE_TOOL_GetPartyValue(mon, 0xD, zero);
        evTotal = evTotal + (u16)POKE_TOOL_GetPartyValue(mon, 0xE, zero);
        evTotal = evTotal + (u16)POKE_TOOL_GetPartyValue(mon, 0xF, zero);
        evTotal = evTotal + (u16)POKE_TOOL_GetPartyValue(mon, 0x10, zero);
        evTotal = evTotal + (u16)POKE_TOOL_GetPartyValue(mon, 0x11, zero);
        evTotal = evTotal + (u16)POKE_TOOL_GetPartyValue(mon, 0x12, zero);
    }
    *resultVar = evTotal;
    return 0;
}

#pragma opt_lifetimes reset

#pragma opt_propagation reset

int SCRCMD_PROC_CheckMonHpNotFullOrEgg(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct PokemonParam *mon;
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    *resultVar = 0;
    if (SCRCMD_PROC_GetPartyMember(cmdWork, partyIndex, (void **)&mon) == 1) {
        u16 hp = POKE_TOOL_GetPartyValue(mon, 0xa0, 0);
        u16 maxHp = POKE_TOOL_GetPartyValue(mon, 0xa1, 0);

        if (hp == maxHp || POKE_TOOL_GetPartyValue(mon, 0x4c, 0) == 1) {
            *resultVar = 1;
        }
    }
    return 0;
}

int SCRCMD_PROC_CheckMonIsEgg(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct PokemonParam *mon;
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    *resultVar = 0;
    if (SCRCMD_PROC_GetPartyMember(cmdWork, partyIndex, (void **)&mon) == 1) {
        if (POKE_TOOL_GetPartyValue(mon, 0x4c, 0) == 0) {
            *resultVar = 0;
        } else {
            *resultVar = 1;
        }
    }
    return 0;
}

int SCRCMD_PROC_GetMonFriendship(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct PokemonParam *mon;
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    *resultVar = 0;
    if (SCRCMD_PROC_GetPartyMember(cmdWork, partyIndex, (void **)&mon) == 1) {
        if (POKE_TOOL_GetPartyValue(mon, 0x4c, 0) == 0) {
            *resultVar = POKE_TOOL_GetPartyValue(mon, 9, 0);
        }
    }
    return 0;
}

int SCRCMD_PROC_ChangeMonFriendship(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int amount = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int operation = VM_ReadU16(vm);
    struct PokemonParam *mon = 0;
    u8 friendship;
    if (SCRCMD_PROC_GetPartyMember(cmdWork, partyIndex, (void **)&mon) == 0) {
        return 0;
    }
    if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0) == 1) {
        return 0;
    }
    friendship = POKE_TOOL_GetPartyValue(mon, 9, 0);
    switch (operation) {
    case 0:
        if ((u32)amount > 0xFF) {
            friendship = 0xFF;
        } else {
            friendship = amount;
        }
        break;
    case 1:
        if (friendship + amount > 0xFF) {
            friendship = 0xFF;
        } else {
            friendship = friendship + (u8)amount;
        }
        break;
    case 2:
        if (friendship < amount) {
            friendship = 0;
        } else {
            friendship = friendship - (u8)amount;
        }
        break;
    }
    POKE_TOOL_SetPartyValue(mon, 9, friendship);
    return 0;
}

int SCRCMD_PROC_GetMonSpeciesOrEgg(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    if (SCRCMD_PROC_GetPartyMemberParam(cmdWork, partyIndex, 0x4C) != 0) *resultVar = 0x28A; else *resultVar = SCRCMD_PROC_GetPartyMemberParam(cmdWork, partyIndex, 5);
    return 0;
}

int SCRCMD_PROC_GetMonForm(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    *resultVar = SCRCMD_PROC_GetPartyMemberParam(cmdWork, partyIndex, 0x6f);
    return 0;
}

int SCRCMD_PROC_FindFirstPartyIndex(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int mode;
    struct ScrcmdWork *cmdWorkCopy;
    u16 *resultVar;
    void *party;
    int result;

    cmdWorkCopy = cmdWork;
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    mode = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    party = SCRCMD_WORK_GetGameData(cmdWorkCopy);
    party = GAME_DATA_GetMyParty(party);
    if (mode == 1) goto nonEgg;
    if (mode != 2) goto none;
    result = POKEPARTY_FindFirstBattleReady(party);
truncate:
    result = result << 0x10;
    result = (unsigned)result >> 0x10;
    goto store;
nonEgg:
    result = POKEPARTY_FindFirstNonEgg(party);
    goto truncate;
none:
    result = 0;
store:
    *resultVar = result;
    result = 0;
    return result;
}

int SCRCMD_PROC_GetPartyCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int countKind = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *party = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(cmdWork));
    int result;

    switch (countKind) {
    case 0:
        result = POKEPARTY_GetCount(party);
        break;
    case 1:
        result = POKEPARTY_GetNonEggCount(party);
        break;
    case 2:
        result = POKEPARTY_GetBattleReadyCount(party);
        break;
    case 3:
        result = POKEPARTY_GetEggCount(party);
        break;
    case 4:
        result = POKEPARTY_GetBadEggCount(party);
        break;
    case 5: {
        int capacity = POKEPARTY_GetCapacity(party);
        int count = POKEPARTY_GetCount(party);
        if (capacity < count) {
            result = 0;
        } else {
            result = capacity - count;
        }
        break;
    }
    default:
        result = 0;
        break;
    }
    *resultVar = result;
    return 0;
}

int SCRCMD_PROC_CountPartyMonsOfSpecies(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 species = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    void *party = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(cmdWork));
    u16 partyCount = POKEPARTY_GetCount(party);
    u16 matchCount = 0;
    int i;

    if (species != 0 && species <= 0x289) {
        for (i = 0; i < partyCount; i++) {
            void *member = POKEPARTY_GetMember(party, i);
            u16 memberSpecies;

            if (member != 0 && POKE_TOOL_GetPartyValue(member, 0x4C, 0) == 0) {
                memberSpecies = POKE_TOOL_GetPartyValue(member, 5, 0);
                if (memberSpecies == species) {
                    matchCount++;
                }
            }
        }
        *resultVar = matchCount;
    } else {
        *resultVar = 0;
    }
    return 0;
}

int SCRCMD_PROC_GetBoxMonCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int countKind = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    void *boxManager = (void *)GAME_DATA_GetBoxManager(gameData);
    int result;

    GAME_DATA_GetMyParty(gameData);
    switch (countKind) {
    case 0:
        result = BOX_SAVEDATA_CountPokemon(boxManager);
        break;
    case 1:
    case 2:
        result = BOX_SAVEDATA_CountNonEggPokemon(boxManager);
        break;
    case 3:
        result = BOX_SAVEDATA_CountPokemon(boxManager) - BOX_SAVEDATA_CountNonEggPokemon(boxManager);
        break;
    case 5: {
        int storedCount = BOX_SAVEDATA_CountPokemon(boxManager);
        if (storedCount > 720) {
            result = 0;
        } else {
            result = 720 - storedCount;
        }
        break;
    }
    default:
        result = 0;
        break;
    }
    *resultVar = result;
    return 0;
}

int SCRCMD_PROC_FindPartyMonBySpecies(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 species = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    u16 *foundVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    u16 *indexVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    void *party = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(cmdWork));
    u16 partyCount = POKEPARTY_GetCount(party);
    int i;

    if (species != 0 && species <= 0x289) {
        for (i = 0; i < partyCount; i++) {
            void *member = POKEPARTY_GetMember(party, i);
            u16 memberSpecies;

            if (member != 0 && POKE_TOOL_GetPartyValue(member, 0x4C, 0) == 0) {
                memberSpecies = POKE_TOOL_GetPartyValue(member, 5, 0);
                if (memberSpecies == species) {
                    break;
                }
            }
        }
        if (i < partyCount) {
            *foundVar = 1;
            *indexVar = i;
        } else {
            *foundVar = 0;
        }
    } else {
        *foundVar = 0;
    }
    return 0;
}

int SCRCMD_PROC_CheckPartyMonKnowsMove(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct PokemonParam *mon;
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int moveId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    *resultVar = 0;
    if (SCRCMD_PROC_GetPartyMember(cmdWork, partyIndex, (void **)&mon) == 1) {
        if (SCRCMD_PROC_CheckMonKnowsMove(mon, moveId) == 1) {
            *resultVar = 1;
        }
    }
    return 0;
}

int SCRCMD_PROC_FindPartyMonWithMove(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *party = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(cmdWork));
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int moveId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int i;
    int partyCount = POKEPARTY_GetCount(party);

    *resultVar = 6;
    for (i = 0; i < partyCount; i++) {
        if (SCRCMD_PROC_CheckMonKnowsMove(POKEPARTY_GetMember(party, i), moveId) == 1) {
            *resultVar = i;
            break;
        }
    }
    return 0;
}

int SCRCMD_PROC_AddMonToPartySimple(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameData;
    u16 heapId;
    u16 *resultVar;
    int species;
    int form;
    int level;
    PokemonSpec spec;

    SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    heapId = SCRCMD_WORK_GetHeapId(cmdWork);
    GAME_DATA_GetMyParty(gameData);
    GAME_DATA_GetMyStatus(gameData);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    species = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    form = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    level = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    spec.heapId = heapId;
    spec.species = species;
    spec.form = form;
    spec.level = level;
    spec.heldItem = 0;
    spec.genderMode = 2;
    spec.natureMode = 2;
    spec.shinyMode = 2;
    spec.ballItem = 4;
    *resultVar = SCRCMD_PROC_AddMonToParty(gameData, &spec);
    return 0;
}

/*
 * Sibling of SCRCMD_PROC_AddMonToPartySimple (same request record, eight reads instead of
 * three, three of them clamped to 2), and of SCRCMD_PROC_AddMonToBoxDetailed: the u16 locals
 * are what make the second clamp reload its value from the spill slot.
 */
int SCRCMD_PROC_AddMonToPartyDetailed(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameData;
    u16 heapId;
    u16 *resultVar;
    u16 species;
    u16 form;
    u16 level;
    u16 genderMode;
    u16 natureMode;
    u16 shinyMode;
    u16 heldItem;
    u16 ballItem;
    PokemonSpec spec;

    SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    heapId = SCRCMD_WORK_GetHeapId(cmdWork);
    GAME_DATA_GetMyParty(gameData);
    GAME_DATA_GetMyStatus(gameData);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    species = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    form = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    level = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    genderMode = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    natureMode = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    shinyMode = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    heldItem = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    ballItem = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    spec.heapId = heapId;
    spec.species = species;
    spec.form = form;
    spec.level = level;
    spec.heldItem = heldItem;
    spec.genderMode = genderMode;
    if (spec.genderMode >= 3)
        spec.genderMode = 2;
    spec.natureMode = natureMode;
    if (spec.natureMode >= 3)
        spec.natureMode = 2;
    spec.shinyMode = shinyMode;
    if (spec.shinyMode >= 3)
        spec.shinyMode = 2;
    spec.ballItem = ballItem;
    *resultVar = SCRCMD_PROC_AddMonToParty(gameData, &spec);
    return 0;
}

int SCRCMD_PROC_CountMonMoves(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct PokemonParam *mon;
    int moveSlot;
    int moveCount;
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    moveCount = 0;
    if (SCRCMD_PROC_GetPartyMember(cmdWork, partyIndex, (void **)&mon) == 1) {
        for (moveSlot = 0; moveSlot < 4; moveSlot++) {
            if (POKE_TOOL_GetPartyValue(mon, moveSlot + 0x36, 0) != 0) {
                moveCount++;
            }
        }
    }
    *resultVar = moveCount;
    return 0;
}

int SCRCMD_PROC_GetMonMove(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 *resultVar;
    int partyIndex;
    int moveSlot;
    struct PokemonParam *mon;

    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    moveSlot = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    if (SCRCMD_PROC_GetPartyMember(cmdWork, partyIndex, (void **)&mon) == 1) {
        *resultVar = POKE_TOOL_GetPartyValue(mon, moveSlot + 0x36, 0);
    } else {
        *resultVar = 0;
    }
    return 0;
}

/*
 * Script command: reads a party slot, a move slot and a move. A move slot
 * past 4 goes to POKE_TOOL_PushMove (teach into a free slot); a zero move deletes
 * the slot, shifting the later moves (ids 0x36 move, 0x3A pp, 0x3E pp-ups)
 * down one; otherwise POKE_TOOL_SetMoveSlot sets the move into the slot.
 */
int SCRCMD_PROC_SetMonMove(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 partyIndex;
    u16 moveSlot;
    u16 move;
    void *mon;
    u32 saved;
    u8 i;
    u32 m;
    u32 ppUp;
    u32 pp;

    partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    moveSlot = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    move = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    if (SCRCMD_PROC_GetPartyMember(cmdWork, partyIndex, &mon) == 0) {
        return 0;
    }
    saved = POKE_TOOL_DecodePartyParam(mon);
    if (moveSlot > 4) {
        POKE_TOOL_PushMove(mon, move);
    } else if (move == 0) {
        i = moveSlot;
        if (moveSlot < 3) {
            for (; i < 3; i++) {
                m = POKE_TOOL_GetPartyValue(mon, i + 0x37, 0);
                if (m == 0) {
                    break;
                }
                ppUp = POKE_TOOL_GetPartyValue(mon, i + 0x3F, 0);
                pp = POKE_TOOL_GetPartyValue(mon, i + 0x3B, 0);
                POKE_TOOL_SetPartyValue(mon, i + 0x36, m);
                POKE_TOOL_SetPartyValue(mon, i + 0x3E, ppUp);
                POKE_TOOL_SetPartyValue(mon, i + 0x3A, pp);
            }
        }
        POKE_TOOL_SetPartyValue(mon, i + 0x36, 0);
        POKE_TOOL_SetPartyValue(mon, i + 0x3E, 0);
        POKE_TOOL_SetPartyValue(mon, i + 0x3A, 0);
    } else {
        POKE_TOOL_SetMoveSlot(mon, move, (u8)moveSlot);
    }
    POKE_TOOL_EncodePartyParam(mon, saved);
    return 0;
}

/*
 * Script command: is the party member in the given slot the player's own
 * catch (trainer id, OT name, OT gender and game version all match)?
 * Writes the answer to a script variable.
 *
 * Levers (2026-09-28 tree_ov010_4): the allocation check as
 * `if (a && b) {...} else fail` (moves the failure block after the name
 * test), the name test as `== 0` (STRBUF_IsEqual answers "equal"), and the
 * version read into a local before the compare (`cmp r0, r1`).
 */
int SCRCMD_PROC_CheckMonIsPlayerOwned(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *myStatus;
    void *mon;
    u16 *resultVar;
    u32 partyIndex;
    u32 heapId;
    void *monOtName;
    void *playerName;
    u32 gameVersion;

    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    myStatus = GAME_DATA_GetMyStatus(SCRCMD_WORK_GetGameData(cmdWork));
    mon = 0;
    if (!SCRCMD_PROC_GetPartyMember(cmdWork, partyIndex, &mon)) {
        *resultVar = 0;
        return 0;
    }
    if (POKE_TOOL_GetPartyValue(mon, 7, 0) != MYSTATUS_GetId(myStatus)) {
        *resultVar = 0;
        return 0;
    }
    heapId = SCRCMD_WORK_GetHeapId(cmdWork);
    monOtName = STRBUF_Create(16, heapId);
    playerName = STRBUF_Create(16, heapId);
    if (monOtName != 0 && playerName != 0) {
        POKE_TOOL_GetPartyValue(mon, 0x8D, (uptr)monOtName);
        MYSTATUS_NameToStrbuf(myStatus, playerName);
        if (STRBUF_IsEqual(monOtName, playerName) == 0) {
            STRBUF_Delete(monOtName);
            STRBUF_Delete(playerName);
            *resultVar = 0;
            return 0;
        }
    } else {
        *resultVar = 0;
        return 0;
    }
    STRBUF_Delete(monOtName);
    STRBUF_Delete(playerName);
    if (POKE_TOOL_GetPartyValue(mon, 0x9A, 0) != MYSTATUS_GetSex(myStatus)) {
        *resultVar = 0;
        return 0;
    }
    gameVersion = POKE_TOOL_GetPartyValue(mon, 0x77, 0);
    if (gameVersion != g0209DF08) {
        *resultVar = 0;
        return 0;
    }
    *resultVar = 1;
    return 0;
}

int SCRCMD_PROC_ChangeMonForm(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int form = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *gameData;
    void *mon;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameData = GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(cmdWork));
    mon = POKEPARTY_GetMember(GAME_DATA_GetMyParty(gameData), partyIndex);
    POKE_TOOL_ChangeForm(mon, form);
    ZUKAN_SAVE_RegisterSeen(ZUKAN_SAVE_GetFromGameData(gameData), mon);
    return 0;
}

int SCRCMD_PROC_SetRotomFormMove(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int form = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int moveSlot = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *gameData;
    void *mon;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameData = GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(cmdWork));
    mon = POKEPARTY_GetMember(GAME_DATA_GetMyParty(gameData), partyIndex);
    POKE_TOOL_SetRotomFormMove(mon, moveSlot, form);
    ZUKAN_SAVE_RegisterSeen(ZUKAN_SAVE_GetFromGameData(gameData), mon);
    return 0;
}

int SCRCMD_PROC_GetRelearnableMoveCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct PokemonParam *mon;
    struct ScrcmdWork *cmdWorkCopy;
    int partyIndex;
    int heapId;
    void *relearnMoves;
    u16 *resultVar;
    int result;

    cmdWorkCopy = cmdWork;
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    heapId = SCRCMD_WORK_GetHeapId(cmdWorkCopy);
    result = SCRCMD_PROC_GetPartyMember(cmdWorkCopy, partyIndex, (void **)&mon);
    if (result != 1) goto done;
    relearnMoves = WAZA_OSHIE_CreateMoveList(mon, heapId);
    result = WAZA_OSHIE_IsListEntryValid(relearnMoves);
    *resultVar = result;
    result = GFL_HEAP_Free(relearnMoves);
done:
    result = 0;
    return result;
}

int SCRCMD_PROC_CheckMonParamMatchesTable(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int tableIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    u16 monValue = SCRCMD_PROC_GetPartyMemberParam(cmdWork, partyIndex, 0x95);

    if (monValue == sScrcmdCompareTable[tableIndex]) {
        *resultVar = 1;
    } else {
        *resultVar = 0;
    }
    return 0;
}

int SCRCMD_PROC_GetMonTripleParams(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 *firstResultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    u16 *secondResultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    u16 *thirdResultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    void *mon;

    if (SCRCMD_PROC_GetPartyMember(cmdWork, SCRIPT_WORK_ReadWorkValue(vm, cmdWork), &mon) == 1) {
        *firstResultVar = POKE_TOOL_GetPartyValue(mon, 0x92, 0);
        *secondResultVar = POKE_TOOL_GetPartyValue(mon, 0x93, 0);
        *thirdResultVar = POKE_TOOL_GetPartyValue(mon, 0x94, 0);
    } else {
        *firstResultVar = 0;
        *secondResultVar = 0;
        *thirdResultVar = 0;
    }
    return 0;
}

int SCRCMD_PROC_SetMonParamChecked(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    u32 paramId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    u32 value = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *mon;
    u32 i;

    for (i = 0; i < 6; i++) {
        if (paramId == sScrcmdParamLimits[i].paramId) {
            if (value <= sScrcmdParamLimits[i].maxValue && SCRCMD_PROC_GetPartyMember(cmdWork, partyIndex, &mon) == 1) {
                POKE_TOOL_SetPartyValue(mon, paramId, value);
                POKE_TOOL_RecalcParam(mon);
            }
            return 0;
        }
    }
    return 0;
}

/*
 * lever: selector remains live in r2 and is SCRCMD_PROC_GetPartyMemberParam's third argument.
 */
int SCRCMD_PROC_GetMonParamIfListed(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 *resultVar;
    uptr partyIndex;
    uptr paramId;
    u32 i;
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    paramId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    for (i = 0; i < 12; i++) {
        if (paramId == sScrcmdAllowedParamIds[i]) {
            *resultVar = SCRCMD_PROC_GetPartyMemberParam(cmdWork, partyIndex, paramId);
            return 0;
        }
    }
    *resultVar = 0;
    return 0;
}

/*
 * Script command: reads a destination variable and three arguments,
 * fills a 0x24-byte spec on the stack (function 0x0215C4C8 consumes it)
 * and stores the returned value through the destination.
 */
int SCRCMD_PROC_AddMonToBoxSimple(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameData;
    u16 heapId;
    u16 *resultVar;
    u32 species;
    u32 form;
    u32 level;
    PokemonSpec spec;

    SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    heapId = SCRCMD_WORK_GetHeapId(cmdWork);
    GAME_DATA_GetMyParty(gameData);
    GAME_DATA_GetMyStatus(gameData);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    species = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    form = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    level = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    spec.heapId = heapId;
    spec.species = species;
    spec.form = form;
    spec.level = level;
    spec.heldItem = 0;
    spec.genderMode = 2;
    spec.natureMode = 2;
    spec.shinyMode = 2;
    spec.ballItem = 4;
    *resultVar = SCRCMD_PROC_AddMonToBox(gameData, &spec);
    return 0;
}

/*
 * Script command, sibling of SCRCMD_PROC_AddMonToBoxSimple: reads a destination variable
 * and eight arguments, three of them clamped to 2 when 3 or more, fills
 * the 0x24-byte spec SCRCMD_PROC_AddMonToBox consumes and stores its result.
 *
 * The arguments are u16 (SCRIPT_WORK_ReadWorkValue returns u16): the widening copy
 * into each int field is why the clamp of the spilled one reloads its
 * slot, and comparing the int field (not the u16 local) gives blt.
 */
int SCRCMD_PROC_AddMonToBoxDetailed(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameData;
    u16 heapId;
    u16 *resultVar;
    u16 species;
    u16 form;
    u16 level;
    u16 genderMode;
    u16 natureMode;
    u16 shinyMode;
    u16 heldItem;
    u16 ballItem;
    PokemonSpec spec;

    SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    heapId = SCRCMD_WORK_GetHeapId(cmdWork);
    GAME_DATA_GetMyParty(gameData);
    GAME_DATA_GetMyStatus(gameData);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    species = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    form = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    level = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    genderMode = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    natureMode = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    shinyMode = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    heldItem = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    ballItem = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    spec.heapId = heapId;
    spec.species = species;
    spec.form = form;
    spec.level = level;
    spec.heldItem = heldItem;
    spec.genderMode = genderMode;
    if (spec.genderMode >= 3) {
        spec.genderMode = 2;
    }
    spec.natureMode = natureMode;
    if (spec.natureMode >= 3) {
        spec.natureMode = 2;
    }
    spec.shinyMode = shinyMode;
    if (spec.shinyMode >= 3) {
        spec.shinyMode = 2;
    }
    spec.ballItem = ballItem;
    *resultVar = SCRCMD_PROC_AddMonToBox(gameData, &spec);
    return 0;
}

/*
 * Script command: add a level-1 Pokemon egg of the given species and
 * form to the party (hatch counter from the personal data, the egg name
 * from message 0x28A), writing 1 to the result word, or 0 when the
 * party is full. First draft.
 */
int SCRCMD_PROC_AddEggToParty(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameData;
    u32 heapId;
    void *party;
    void *myStatus;
    u16 *resultVar;
    u32 species;
    u32 form;
    void *mon;
    uptr tempStrbuf;
    uptr personal;
    u32 hatchCycles;

    SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    heapId = SCRCMD_WORK_GetHeapId(cmdWork);
    party = GAME_DATA_GetMyParty(gameData);
    myStatus = GAME_DATA_GetMyStatus(gameData);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    species = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    form = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    if ((int)POKEPARTY_GetCapacity(party) <= (int)POKEPARTY_GetCount(party)) {
        *resultVar = 0;
        return 0;
    }
    mon = POKE_TOOL_Create(species, 1, (u64)-1, heapId);
    POKE_TOOL_SetPartyValue(mon, 0x6F, form);
    tempStrbuf = (uptr)MYSTATUS_CreateNameStrbuf((u16 *)GAME_DATA_GetMyStatus(gameData), heapId);
    POKE_TOOL_SetPartyValue(mon, 0x8D, tempStrbuf);
    STRBUF_Delete((struct Strbuf *)tempStrbuf);
    personal = (uptr)POKE_PERSONAL_Create((u16)POKE_TOOL_GetPartyValue(mon, 5, 0), (u16)POKE_TOOL_GetPartyValue(mon, 0x6F, 0), heapId);
    hatchCycles = POKE_PERSONAL_GetParam((const struct PersonalData *)personal, 0x15);
    POKE_PERSONAL_Delete((void *)personal);
    POKE_TOOL_SetPartyValue(mon, 9, hatchCycles);
    POKE_TOOL_SetPartyValue(mon, 0x4C, 1);
    tempStrbuf = (uptr)MSGDATA_AllocString(gSpeciesNameBank, 0x28A);
    POKE_TOOL_SetPartyValue(mon, 0x73, tempStrbuf);
    STRBUF_Delete((struct Strbuf *)tempStrbuf);
    POKE_TOOL_RecalcParam(mon);
    SAVE_EVENT_Write(mon, 5, myStatus, 0xEA63, heapId);
    POKEPARTY_Add(party, mon);
    GFL_HEAP_Free(mon);
    *resultVar = 1;
    return 0;
}

/*
 * lever: POKE_TOOL_CreateEx's matched signature has two u64 inputs; widening the
 * personality result to u64 schedules its high zero before the low-word store.
 */
void *SCRCMD_PROC_CreateMonFromSpec(void *gameData, PokemonSpec *spec)
{
    void *myStatus;
    u32 trainerId;
    struct PokemonParam *mon;
    u32 personalRnd;
    myStatus = GAME_DATA_GetMyStatus(gameData);
    trainerId = MYSTATUS_GetId((const struct MyStatus *)GAME_DATA_GetMyStatus(gameData));
    personalRnd = POKE_TOOL_CreatePersonalRnd(trainerId, (u16)spec->species, (u16)spec->form, (u32)spec->natureMode, (u32)spec->genderMode, (u32)spec->shinyMode);
    mon = POKE_TOOL_CreateEx(spec->species, spec->level, trainerId, -1, personalRnd, spec->heapId);
    POKE_TOOL_SetPartyValue(mon, 0x6F, spec->form);
    POKE_TOOL_SetPartyValue(mon, 6, spec->heldItem);
    if ((s32)FILE_UTIL_GetItemParam((u16)spec->ballItem, 0xF, spec->heapId) == 4)
        POKE_TOOL_SetPartyValue(mon, 0x98, (u32)PALANM_GetPairedCodeForFirst((u16)spec->ballItem));
    SAVE_EVENT_Write(mon, 0, (void *)myStatus, ZONEDATA_GetPlaceNameId(GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(gameData))), spec->heapId);
    POKE_TOOL_RecalcParam(mon);
    return mon;
}

int SCRCMD_PROC_AddMonToBox(void *gameData, PokemonSpec *spec)
{
    void *boxManager;
    void *mon;

    boxManager = (void *)GAME_DATA_GetBoxManager(gameData);
    if (BOX_SAVEDATA_CountPokemon(boxManager) >= 0x2D0)
        return 0;
    mon = SCRCMD_PROC_CreateMonFromSpec(gameData, spec);
    BOX_SAVEDATA_AddPokemon(boxManager, POKE_TOOL_GetBoxParam(mon));
    ZUKAN_SAVE_RegisterCaught(ZUKAN_SAVE_GetFromGameData(gameData), mon);
    GFL_HEAP_Free(mon);
    return 1;
}

int SCRCMD_PROC_AddMonToParty(void *gameData, PokemonSpec *spec)
{
    void *party;
    void *mon;

    party = GAME_DATA_GetMyParty(gameData);
    if ((int)POKEPARTY_GetCapacity(party) <= (int)POKEPARTY_GetCount(party))
        return 0;
    mon = SCRCMD_PROC_CreateMonFromSpec(gameData, spec);
    POKEPARTY_Add(party, mon);
    ZUKAN_SAVE_RegisterCaught(ZUKAN_SAVE_GetFromGameData(gameData), mon);
    GFL_HEAP_Free(mon);
    return 1;
}

/*
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 */
int SCRCMD_PROC_AddMoney(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    int value;
    GAME_DATA_GetMyPlayerWork(gameData);
    value = SCRIPT_WORK_ReadWorkValue(vm,cmdWork);
    MISC_AddMoney(GAME_DATA_GetMiscSave(gameData),value);
    return 0;
}

int SCRCMD_PROC_SubMoney(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    int value;
    GAME_DATA_GetMyPlayerWork(gameData);
    value = SCRIPT_WORK_ReadWorkValue(vm,cmdWork);
    MISC_SubMoney(GAME_DATA_GetMiscSave(gameData),value);
    return 0;
}

int SCRCMD_PROC_CheckMoneyAtLeast(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    unsigned int value = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    GAME_DATA_GetMyPlayerWork(gameData);
    *resultVar = value <= MISC_GetMoney(GAME_DATA_GetMiscSave(gameData)) ? 1 : 0;
    return 0;
}

/*
 * Two overlay lookups on the second argument, the second of them classified
 * by an arm9 call, then submitted together.
 */
int SCRCMD_PROC_CallFieldOpenEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *eventSlot = SCRCMD_WORK_GetScriptWork(cmdWork);

    SCRIPT_SYS_CallEvent(eventSlot, FIELD_STATUS_CreateFieldOpenEvent(SCRCMD_WORK_GetGameSystem(cmdWork)));

    return 1;
}

int SCRCMD_PROC_CallFieldCloseEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct ScrcmdWork *cmdWorkCopy;
    void *eventSlot;
    void *gameSystem;
    void *fieldMap;
    void *event;
    int result;

    cmdWorkCopy = cmdWork;
    eventSlot = SCRCMD_WORK_GetScriptWork(cmdWorkCopy);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWorkCopy);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    event = FIELD_STATUS_CreateFieldCloseEvent((struct GameSystem *)gameSystem, (struct FieldMap *)fieldMap);
    SCRIPT_SYS_CallEvent(eventSlot, event);
    result = 1;
    return result;
}

/*
 * Starts a child process from an overlay on behalf of a script command:
 * allocates the 12-byte hand-off record (work pointer and two words),
 * launches the process over the work with GAMESYSTEM_CallProc, parks the record in the
 * script's slot and waits on SCRCMD_PROC_WaitOverlayProc.
 */
void SCRCMD_PROC_StartOverlayProc(struct ScriptVm *vm, struct ScrcmdWork *cmdWork, u32 overlayId, const void *procData, void *procWork, ScriptProcFinishFn onFinish, void *userData)
{
    void *gameSystem;
    void **handoffSlot;
    ScriptProcHandoff *handoff;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    handoffSlot = SCRIPT_WORK_GetUserWorkPtr(SCRCMD_WORK_GetScriptWork(cmdWork));
    handoff = GFL_HEAP_Alloc(4, sizeof(ScriptProcHandoff), 1, sAllocSiteScrcmdProc, 0x8B);
    handoff->work = procWork;
    handoff->userData = userData;
    handoff->onFinish = onFinish;
    GAMESYSTEM_CallProc(gameSystem, overlayId, (void *)procData, procWork);
    *handoffSlot = handoff;
    VM_SetWait(vm, (ScriptWaitFn)SCRCMD_PROC_WaitOverlayProc);
}

int SCRCMD_PROC_WaitOverlayProc(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct ScrcmdWork *cmdWorkCopy;
    struct ScriptWork *eventSlot;
    ScriptProcHandoff *handoff;
    void *gameSystem;
    int result;

    cmdWorkCopy = cmdWork;
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWorkCopy);
    eventSlot = SCRCMD_WORK_GetScriptWork(cmdWorkCopy);
    handoff = SCRIPT_WORK_GetUserWork(eventSlot);
    result = GAMESYSTEM_GetProcStatus(gameSystem);
    if (result == 0) goto checkCallback;
    result = 0;
    return result;
checkCallback:
    if (handoff->onFinish == 0) goto noCallback;
    handoff->onFinish(handoff);
    goto clearSlot;
noCallback:
    if (handoff->work == 0) goto freeUserData;
    GFL_HEAP_Free(handoff->work);
freeUserData:
    if (handoff->userData == 0) goto clearSlot;
    GFL_HEAP_Free(handoff->userData);
clearSlot:
    SCRIPT_WORK_FreeUserWork(eventSlot);
    result = 1;
    return result;
}

int SCRCMD_PROC_FreeScriptUserWork(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *eventSlot;
    int result;

    eventSlot = SCRCMD_WORK_GetScriptWork(cmdWork);
    SCRIPT_WORK_FreeUserWork(eventSlot);
    result = 1;
    return result;
}

/*
 * lever: Stores in both if/else arms retain the zero-first full branch;
 * a local flag (u32, u16, or enum) folds to 42 bytes and DIFF 33.
 */
void SCRCMD_PROC_OnBagClosed(BagCloseData *closeData)
{
    BagParamResult *bagParam = closeData->bagParam;
    BagResultVars *resultVars = closeData->resultVars;
    if (bagParam->selected == 0)
        *resultVars->selectedVar = B_FALSE;
    else
        *resultVars->selectedVar = B_TRUE;
    *resultVars->itemVar = bagParam->itemId;
    GFL_HEAP_Free(closeData->resultVars);
    GFL_HEAP_Free(closeData->bagParam);
}

/*
 * Script command: reads a selector and two words, maps the selector
 * (0 -> 4, 1 -> 5, else 0), then opens overlay 0x46 over a work built
 * from BAG_PARAM_Create with an 8-byte hand-off record.
 *
 * 2026-10-05 (wave D9): EXACT. The ov070 token on the gItemMenuProcData data line
 * (the proc table lives in ov070, the overlay this function opens) gave the
 * witness; ov070_id then resolved through the overlay_id walk (SCRCMD_PROC_StartOverlayProc
 * is a registered consumer). Source unchanged.
 */
int SCRCMD_PROC_CallBagScreen(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 bagMode;
    u32 selectedVar;
    u32 itemVar;
    u32 bagType;
    void *bagParam;
    u32 *closeData;

    SCRCMD_WORK_GetGameSystem(cmdWork);
    SCRCMD_WORK_GetScriptWork(cmdWork);
    bagMode = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    selectedVar = (uptr)SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    itemVar = (uptr)SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    if (bagMode == 0)
        bagType = 4;
    else if (bagMode == 1)
        bagType = 5;
    else
        bagType = 0;
    bagParam = BAG_PARAM_Create((struct BigObj *)(struct BigObj *)SCRCMD_WORK_GetGameData(cmdWork), 0, bagType, 4);
    closeData = GFL_HEAP_Alloc(4, 8, 1, sAllocSiteScrcmdProc, 0x118);
    closeData[0] = selectedVar;
    closeData[1] = itemVar;
    SCRCMD_PROC_StartOverlayProc(vm, cmdWork, (uptr)ov070_id, gItemMenuProcData, bagParam, (ScriptProcFinishFn)SCRCMD_PROC_OnBagClosed, closeData);
    return 1;
}

/*
 * Unlabelled Thumb leaf (callback of SCRCMD_PROC_CallGtsNegotiation): stores whether the
 * first record's word at +4 equals 1 into the halfword the second record
 * points to, then frees the first record's first word.
 */
void SCRCMD_PROC_OnGtsNegotiationDone(GtsCallbackData *callbackData)
{
    if (callbackData->param->result == 1)
        *callbackData->resultVar = 1;
    else
        *callbackData->resultVar = 0;
    GFL_HEAP_Free(callbackData->param);
}

/*
 * Script command: allocates two 8-byte records (a work holding the
 * system's word, then a hand-off holding the work and one script word),
 * launches overlay 0x88 over them with the SCRCMD_PROC_OnGtsNegotiationDone callback and
 * parks the result in the script's slot.
 *
 * 2026-10-05 (wave D9): EXACT. gMbSeqProcData resolves once its symbols line carries the ov136 token (the overlay the function loads); SCRCMD_PROC_OnGtsNegotiationDone has its own witness.
 */
int SCRCMD_PROC_CallGtsNegotiation(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *eventSlot;
    void *gameSystem;
    void *gameData;
    void *fieldMap;
    u32 *gtsParam;
    u32 *callbackData;

    eventSlot = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    gtsParam = GFL_HEAP_Alloc(4, 8, 0, sAllocSiteScrcmdProc, 0x14F);
    callbackData = GFL_HEAP_Alloc(4, 8, 0, sAllocSiteScrcmdProc, 0x150);
    gtsParam[0] = (uptr)gameData;
    callbackData[0] = (uptr)gtsParam;
    callbackData[1] = (uptr)SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    SCRIPT_SYS_CallEvent(eventSlot, FIELD_STATUS_CreateSubProcNoFadeCallbackEvent(gameSystem, fieldMap, (uptr)ov136_id, (void *)gMbSeqProcData, gtsParam, (void (*)(void *))SCRCMD_PROC_OnGtsNegotiationDone, callbackData));
    return 1;
}

int SCRCMD_PROC_OnMoveRelearnDone(RelearnCallbackData *callbackData, int callArg1)
{
    int learned;
    int result;

    result = callbackData->param->learned;
    if (result == 0) goto notLearned;
    if (result == 1) goto learned;
notLearned:
    learned = 0;
    goto store;
learned:
    learned = 1;
store:
    *callbackData->resultVar = learned;
    GFL_HEAP_Free(callbackData->param->relearnMoves);
    result = WAZA_OSHIE_Delete(callbackData->param);
    return result;
}

static inline void MoveRelearnParam_Init(MoveRelearnParam *param, void *mon, void *myStatus, void *gameSystem, void *moves)
{
    enum One { ONE = 1 } one;
    param->mon = mon;
    param->myStatus = myStatus;
    param->flags = 0;
    param->gameSystem = gameSystem;
    param->relearnMoves = moves;
    one = ONE;
    param->enabled = one;
}

/*
 * lever: enum one assigned immediately before the enabled store in the inline
 * record initializer separates it from the constant return and selects r0.
 */
int SCRCMD_PROC_CallMoveRelearn(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *eventSlot;
    void *gameSystem;
    void *gameData;
    void *fieldMap;
    u32 resultVar;
    u32 partyIndex;
    void *mon;
    void *myStatus;
    void *relearnMoves;
    MoveRelearnParam *relearnParam;
    u32 *callbackData;

    eventSlot = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    resultVar = (uptr)SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    mon = POKEPARTY_GetMember(GAME_DATA_GetMyParty(gameData), partyIndex);
    myStatus = GAME_DATA_GetMyStatus(gameData);
    relearnMoves = WAZA_OSHIE_CreateMoveList(mon, 4);
    relearnParam = WAZA_OSHIE_Create(4);
    MoveRelearnParam_Init(relearnParam, mon, myStatus, gameSystem, relearnMoves);
    callbackData = GFL_HEAP_Alloc(4, 8, 0, sAllocSiteScrcmdProc, 0x19B);
    callbackData[0] = (uptr)relearnParam;
    callbackData[1] = resultVar;
    SCRIPT_SYS_CallEvent(eventSlot, FIELD_STATUS_CreateSubProcCallbackEvent(gameSystem, fieldMap, (uptr)ov173_id, (void *)gMoveRelearnProcData, relearnParam, (void (*)(void *))SCRCMD_PROC_OnMoveRelearnDone, callbackData));
    return 1;
}

/*
 * Script command: opens the ov071 process on a 0x40-byte work. When the
 * current link record is usable (another player's slot, flagged, and
 * marked at +0x922) the work takes that player's name and profile;
 * otherwise it is filled from the local player. The chosen slot index
 * (0 for the local player) is stored at +0x3C.
 *
 * MATCH, bytes exact (2026-09-28 tree_ov010_4; lever: one `idx` local
 * set in both arms, which is what keeps the r6 zero). Three wildcards:
 * ov011 0x02175FB4 is an unlabelled leaf (`ldrb r0, [r0, #0x10]; bx lr`),
 * and the pooled 0x47 (ov071_id) and 0x021BA758 (the ov071 process
 * template) only reach an overlay loader through SCRCMD_PROC_StartOverlayProc, so no
 * class attests them.
 *
 * 2026-10-05 (wave D9): gPlayerProfileProcData now resolves with the ov099 token on its symbols line (`data  ov099  a1`; other covering overlays stay contested or unresolved). Only ov071_id remains: it reaches SCRCMD_PROC_StartOverlayProc, which is not in match.py OVERLAY_ID_CONSUMERS (forwards r2 to GAMESYSTEM_CallProc r1); a data token on the id line does not help. Needs the consumer entry (tools), not C.
 */
int SCRCMD_PROC_CallPlayerProfile(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem;
    void *gameComm;
    void *gameData;
    ProfileProcWork *work;
    IntrudeCommSys *commState;
    u8 playerIndex;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameComm = (void *)GAMESYSTEM_GetGameComm(gameSystem);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    SCRCMD_WORK_GetScriptWork(cmdWork);
    commState = (IntrudeCommSys *)INTRUDE_COMM_GetWorkIfRunning((struct GameComm *)gameComm);
    work = GFL_HEAP_Alloc(4, sizeof(ProfileProcWork), 1, sAllocSiteScrcmdProc, 0x1BC);
    if (commState != 0 && commState->localPeer.intrudeId != GAME_DATA_GetOwnNetId(gameData)
        && INTRUDE_COMM_GetMemberNameNetId((struct IntrudeMemberName *)(&commState->session.members[GAME_DATA_GetIntrudeIdByte(gameData)])) == 1
        && ((u8 *)commState)[0x922] == 1) {
        playerIndex = GAME_DATA_GetIntrudeIdByte(gameData);
        work->name = *INTRUDE_COMM_GetMemberEntry(commState, playerIndex);
        work->profile = *(IntrudeRemoteRecord *)((u8 *)commState + 0x914);
        work->isRemote = 1;
    } else {
        INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(gameData));
        INTRUDE_COMM_BuildLocalProfile(gameData, (struct IntrudeProfileData *)(&work->profile));
        playerIndex = 0;
        work->isRemote = 0;
    }
    work->gameSystem = gameSystem;
    work->playerIndex = playerIndex;
    SCRCMD_PROC_StartOverlayProc(vm, cmdWork, (uptr)ov071_id, gPlayerProfileProcData, work, 0, 0);
    return 1;
}

/*
 * Script command: reads two words and stores EVENT_FIELD_PROCLINK_CreateCommExitEvent's result
 * (over the system and the script's cell) in the script's slot.
 */
int SCRCMD_PROC_CallSubEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *eventSlot;
    void *gameSystem;
    u32 firstArg;
    u32 secondArg;

    eventSlot = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    firstArg = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    secondArg = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRIPT_SYS_CallEvent(eventSlot, EVENT_FIELD_PROCLINK_CreateCommExitEvent(gameSystem, SCRIPT_WORK_GetEvent(eventSlot), firstArg, secondArg, 0));
    return 1;
}

/*
 * Script command: reads one halfword and the system, boxes them in an
 * 8-byte record and opens overlay 0xAE over it.
 *
 * Bytes exact.
 *
 * 2026-10-05 (wave D9): EXACT. The ov174 token on the gLocalTvtSysProcData data line (the
 * proc table lives in ov174, which this function loads) gave the witness; the
 * ov174_id word then resolved through the overlay_id walk. Source unchanged.
 */
int SCRCMD_PROC_CallValueScreen(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 value;
    ValueProcParam *param;

    value = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    param = GFL_HEAP_Alloc(4, 8, 1, sAllocSiteScrcmdProc, 0x205);
    param->value = value;
    param->gameData = SCRCMD_WORK_GetGameData(cmdWork);
    SCRCMD_PROC_StartOverlayProc(vm, cmdWork, (uptr)ov174_id, gLocalTvtSysProcData, param, 0, 0);
    return 1;
}

/*
 * Script command: reads a mode (0-2) and a word; unless the mode is 2
 * calls GAME_BEACON_SEARCH_SetScriptEvent, then boxes the system object (and the word) in a
 * hand-off record and opens overlay 0xDD, 0xDE or 0xE0 over it through
 * SCRCMD_PROC_StartOverlayProc.
 *
 * MATCH, bytes exact. Blockers: the three overlay ids (ABS32 0xDD, 0xDE,
 * 0xE0) have no witness: `overlay_id` would carry them, but SCRCMD_PROC_StartOverlayProc
 * (which forwards its r2 to GAMESYSTEM_CallProc's r1) is not in match.py's
 * OVERLAY_ID_CONSUMERS. gZenkokuZukanAwardProcData (ov222) and gSubwayMapProcData (ov224) are
 * contested hints that resolve once the function loads those overlays
 * through an overlay_id site. gChihouZukanAwardProcData (ov221) already resolves.
 *
 * 2026-10-05 (wave D9): re-tried overlay tokens on the contested hints; they stay contested because the id sites do not attest. Residue is the three id words (ov221_id, ov222_id, ov224_id) reaching SCRCMD_PROC_StartOverlayProc, which is not in OVERLAY_ID_CONSUMERS; add that consumer (r2 -> GAMESYSTEM_CallProc r1) and the hints resolve. Not fixable in C.
 */
int SCRCMD_PROC_CallModeScreen(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameData;
    void *myStatus;
    u32 screenMode;
    u32 value;
    ModeProcParam *param;
    void **myStatusParam;

    gameData = GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(cmdWork));
    myStatus = GAME_DATA_GetMyStatus(gameData);
    screenMode = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    value = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    if (screenMode != 2) {
        GAME_BEACON_SEARCH_SetScriptEvent();
    }
    switch (screenMode) {
    case 0:
        param = GFL_HEAP_Alloc(4, 8, 1, sAllocSiteScrcmdProc, 0x22B);
        param->gameData = gameData;
        param->value = value;
        SCRCMD_PROC_StartOverlayProc(vm, cmdWork, (uptr)ov221_id, gChihouZukanAwardProcData, param, 0, 0);
        break;
    case 1:
        param = GFL_HEAP_Alloc(4, 8, 1, sAllocSiteScrcmdProc, 0x233);
        param->gameData = gameData;
        param->value = value;
        SCRCMD_PROC_StartOverlayProc(vm, cmdWork, (uptr)ov222_id, gZenkokuZukanAwardProcData, param, 0, 0);
        break;
    case 2:
        myStatusParam = GFL_HEAP_Alloc(4, 4, 1, sAllocSiteScrcmdProc, 0x23C);
        *myStatusParam = myStatus;
        SCRCMD_PROC_StartOverlayProc(vm, cmdWork, (uptr)ov224_id, gSubwayMapProcData, myStatusParam, 0, 0);
        break;
    }
    return 1;
}

/*
 * Script command: reads one word from the script stream, boxes it in a
 * 4-byte hand-off record and opens overlay 0xDF over it.
 *
 * 2026-10-05 (D9 lane 02): gPselProcData resolves with the ov223 token (the overlay it points into) on its data line; ov223_id resolves as an overlay id word.
 *
 * 2026-10-05 (wave D8): ov223_id and gPselProcData are data with no witness; not fixable in C. Source re-read against the listing, unchanged.
 */
int SCRCMD_PROC_CallWordScreen(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 value;
    u32 *param;

    value = (uptr)SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    param = GFL_HEAP_Alloc(4, 8, 1, sAllocSiteScrcmdProc, 0x254);
    param[0] = value;
    SCRCMD_PROC_StartOverlayProc(vm, cmdWork, (uptr)ov223_id, gPselProcData, param, 0, 0);
    return 1;
}

int SCRCMD_PROC_WaitNothing(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct ScrcmdWork *cmdWorkCopy;
    void *eventSlot;
    void *gameSystem;
    int result;

    cmdWorkCopy = cmdWork;
    eventSlot = SCRCMD_WORK_GetScriptWork(cmdWorkCopy);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWorkCopy);
    result = 1;
    return result;
}

/*
 * Script command: reads a kind (0xF-0x13 mapped to 0-4) and a flag (0/1),
 * builds a four-word request on the stack and launches EVENT_WIFIBATTLEMATCH_Entry
 * (ov002) through GAME_EVENT_CreateOverlayEvent, parking the result in the script's slot.
 */
int SCRCMD_PROC_CallWifiBattleMatch(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *eventSlot;
    void *gameSystem;
    u32 kindVar;
    u32 flagVar;
    u32 kindIndex;
    u32 flagValue;
    WifiBattleMatchParam param;

    eventSlot = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    kindVar = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    flagVar = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    switch (kindVar) {
    case 0xF:
        kindIndex = 0;
        break;
    case 0x10:
        kindIndex = 1;
        break;
    case 0x11:
        kindIndex = 2;
        break;
    case 0x12:
        kindIndex = 3;
        break;
    case 0x13:
        kindIndex = 4;
        break;
    }
    switch (flagVar) {
    case 0:
        flagValue = 0;
        break;
    case 1:
        flagValue = 1;
        break;
    }
    param.fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    param.enabled = 1;
    param.flag = flagValue;
    param.matchKind = kindIndex;
    SCRIPT_SYS_CallEvent(eventSlot, GAME_EVENT_CreateOverlayEvent(gameSystem, (uptr)ov002_id, (void *)EVENT_WIFIBATTLEMATCH_Entry, (&param)));
    return 1;
}

/*
 * The ov003 callback 0x021543BC (unlabelled leaf, formerly the blocker) is
 * matched in pkt_ov003_021543BC and attests as matched.
 */
int SCRCMD_PROC_CallMenuProc(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    MenuProcParam param;
    void *eventSlot = SCRCMD_WORK_GetScriptWork(cmdWork);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u32 mode = !SCRIPT_WORK_ReadWorkValue(vm, cmdWork) ? 1 : 2;
    param.fieldMap = (uptr)GAMESYSTEM_GetFieldMap(gameSystem);
    param.mode = mode;
    SCRIPT_SYS_CallEvent(eventSlot, GAME_EVENT_CreateOverlayEvent(gameSystem, (uptr)ov003_id, (void *)EVENT_MENUPROC_Entry, (&param)));
    return 1;
}

int SCRCMD_PROC_Ov037InitFromVars(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u16 *firstVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    u16 *secondVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    GF_OVERLAY_Load((uptr)ov037_id);
    GIMMICK_INIT_SetCartLanesFlags(gameSystem, *firstVar, *secondVar);
    GF_OVERLAY_Unload((uptr)ov037_id);
    return 0;
}

int SCRCMD_PROC_Ov037SetValueA(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    int value = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    GF_OVERLAY_Load((sptr)ov037_id);
    GIMMICK_INIT_SetFlagAnimeFlag(gameSystem, value);
    GF_OVERLAY_Unload((sptr)ov037_id);
    return 0;
}

int SCRCMD_PROC_Ov037SetValueB(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    int value = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    GF_OVERLAY_Load((sptr)ov037_id);
    GIMMICK_INIT_SetButtonStatesFlags(gameSystem, value);
    GF_OVERLAY_Unload((sptr)ov037_id);
    return 0;
}

int SCRCMD_PROC_Ov037ReadEightVars(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    unsigned short *resultVars[8];
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    resultVars[0] = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    resultVars[1] = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    resultVars[2] = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    resultVars[3] = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    resultVars[4] = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    resultVars[5] = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    resultVars[6] = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    resultVars[7] = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    GF_OVERLAY_Load((uptr)ov037_id);
    GIMMICK_INIT_RestorePlateDoorsState(gameSystem, resultVars);
    GF_OVERLAY_Unload((uptr)ov037_id);
    return 0;
}

int SCRCMD_PROC_Ov037Finish(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    GF_OVERLAY_Load((sptr)ov037_id);
    GIMMICK_INIT_ResetRotatingRoomPanels(gameSystem);
    GF_OVERLAY_Unload((sptr)ov037_id);
    return 0;
}

/*
 * unblocked: SODATEYA_HasEgg (ov021, unlabelled leaf) was matched bottom-up
 *   and filed as pkt_021C3400; the `ov021` token then resolves the site as
 *   `matched, overlay`.  Extent runs 36 bytes against 34 compiled: the
 *   unlabelled follower.
 */
int SCRCMD_PROC_CheckDaycareHasEgg(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct ScrcmdWork *cmdWorkCopy;
    unsigned short *resultVar;
    void *gameSystem;
    void *fieldMap;
    int result;

    cmdWorkCopy = cmdWork;
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWorkCopy);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    result = SODATEYA_HasEgg(FIELDMAP_GetSodateya(fieldMap));
    *resultVar = result;
    result = 0;
    return result;
}

int SCRCMD_PROC_ReceiveDaycareEgg(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *party = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(cmdWork));
    SODATEYA_ReceiveEgg((struct SodateyaWork *)FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(gameSystem)), (void *)party);
    return 0;
}

int SCRCMD_PROC_DeclineDaycareEgg(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem;
    void *fieldMap;
    int result;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    SODATEYA_DeclineEgg((struct SodateyaWork *)FIELDMAP_GetSodateya(fieldMap));
    result = 0;
    return result;
}

int SCRCMD_PROC_CallDaycarePartyMenu(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *eventSlot = SCRCMD_WORK_GetScriptWork(cmdWork);
    unsigned short *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    void *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    GAME_DATA_GetMyParty(gameData);
    DAYCARE_GetFromSave(GAME_DATA_GetSaveControl(gameData));
    SCRIPT_SYS_CallEvent(eventSlot, SCRCMD_SODATEYA_Create(gameSystem, fieldMap, resultVar));
    return 1;
}

int SCRCMD_PROC_DepositDaycareMon(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *party = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(cmdWork));
    SODATEYA_DepositPokemon((struct SodateyaWork *)FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))), (void *)party, partyIndex);
    return 0;
}

int SCRCMD_PROC_WithdrawDaycareMon(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int daycareSlot = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *party = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(cmdWork));
    SODATEYA_WithdrawPokemon((struct SodateyaWork *)FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))), daycareSlot, (void *)party);
    return 0;
}

int SCRCMD_PROC_GetDaycareMonCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct ScrcmdWork *cmdWorkCopy;
    unsigned short *resultVar;
    void *gameSystem;
    void *fieldMap;
    int result;

    cmdWorkCopy = cmdWork;
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWorkCopy);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    result = SODATEYA_GetPokemonCount((struct SodateyaWork *)FIELDMAP_GetSodateya(fieldMap));
    *resultVar = result;
    result = 0;
    return result;
}

int SCRCMD_PROC_GetDaycareCompatibility(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct ScrcmdWork *cmdWorkCopy;
    unsigned short *resultVar;
    void *gameSystem;
    void *fieldMap;
    int result;

    cmdWorkCopy = cmdWork;
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWorkCopy);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    result = SODATEYA_GetCompatibility((struct SodateyaWork *)FIELDMAP_GetSodateya(fieldMap));
    *resultVar = result;
    result = 0;
    return result;
}

/*
 * interface: SODATEYA_GetPokemon has two observed inputs. Its full ov021 body
 * and 0200BCA8/0200BC2C read r0/r1 only; legacy trailing r2/r3 are omitted.
 */
int SCRCMD_PROC_GetDaycareMonSpecies(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int daycareSlot = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *daycareMon = SODATEYA_GetPokemon((struct SodateyaWork *)FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))), daycareSlot);
    *resultVar = POKE_TOOL_GetPartyValue(daycareMon, 5, 0);

    return 0;
}

int SCRCMD_PROC_GetDaycareMonForm(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int daycareSlot = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *daycareMon = SODATEYA_GetPokemon((struct SodateyaWork *)FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))), daycareSlot);
    *resultVar = POKE_TOOL_GetPartyValue(daycareMon, 111, 0);

    return 0;
}

int SCRCMD_PROC_GetDaycareMonGender(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int daycareSlot = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *daycareMon = SODATEYA_GetPokemon((struct SodateyaWork *)FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))), daycareSlot);
    *resultVar = POKE_TOOL_GetPartyValue(daycareMon, 110, 0);

    return 0;
}

int SCRCMD_PROC_GetDaycareSlotLevel(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int daycareSlot = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    *resultVar = SODATEYA_GetCurrentLevel((struct SodateyaWork *)FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))), daycareSlot);

    return 0;
}

int SCRCMD_PROC_GetDaycareSlotLevelsGrown(void *vm,void *cmdWork)
{
 u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm,cmdWork);
 int daycareSlot = SCRIPT_WORK_ReadWorkValue(vm,cmdWork);
 void **daycare = (void **)FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork)));
 SODATEYA_GetPokemon((struct SodateyaWork *)daycare,daycareSlot);
 *resultVar = SODATEYA_GetLevelsGained((struct SodateyaWork *)daycare,daycareSlot);
 return 0;
}

int SCRCMD_PROC_GetDaycareSlotPrice(void *vm,void *cmdWork)
{
 u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm,cmdWork);
 int daycareSlot = SCRIPT_WORK_ReadWorkValue(vm,cmdWork);
 void **daycare = (void **)FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork)));
 SODATEYA_GetPokemon((struct SodateyaWork *)daycare,daycareSlot);
 *resultVar = SODATEYA_GetWithdrawCost((struct SodateyaWork *)daycare,daycareSlot);
 return 0;
}

int SCRCMD_PROC_GetDaycareMonGenderKindIfFirst(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int queryKind;
    u16 *resultVar;
    void *daycareMon;
    void *daycare = FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork)));
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    queryKind = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    daycareMon = SODATEYA_GetPokemon(daycare, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    if (queryKind == 0)
        *resultVar = SCRCMD_PROC_GetDaycareGenderKind(daycareMon);
    else
        *resultVar = 0;
    return 0;
}

int SCRCMD_PROC_GetDaycareGenderKind(void *mon)
{
    int species = POKE_TOOL_GetPartyValue(mon, 5, 0);
    int gender = POKE_TOOL_GetPartyValue(mon, 0x6e, 0);
    if (species == 0x20 || species == 0x1d) {
        species = 0;
        if (POKE_TOOL_GetPartyValue(mon, 0x75, 0) == 0)
            return species;
    }
    switch (gender) {
    case 2:
    default: return 0;
    case 0: return 1;
    case 1: return 2;
    }
}
