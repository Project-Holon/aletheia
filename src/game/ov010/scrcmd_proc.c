/*
 * file:     scrcmd_proc.c
 * unit:     yes
 * function: SCRCMD_PROC_LookupTableValue, SCRCMD_PROC_GetPartyMember, SCRCMD_PROC_GetPartyMemberParam, SCRCMD_PROC_CheckMonKnowsMove, SCRCMD_PROC_GetMonPairedParams, SCRCMD_PROC_HealParty, SCRCMD_PROC_GetMonEvTotal, SCRCMD_PROC_CheckMonParamMismatch, SCRCMD_PROC_CheckMonIsEgg, SCRCMD_PROC_GetMonFriendship, SCRCMD_PROC_ChangeMonFriendship, SCRCMD_PROC_GetMonSpeciesOrEgg, SCRCMD_PROC_GetMonForm, SCRCMD_PROC_FindFirstPartyIndex, SCRCMD_PROC_GetPartyCount, SCRCMD_PROC_CountPartyMonsOfSpecies, SCRCMD_PROC_GetBoxMonCount, SCRCMD_PROC_FindPartyMonBySpecies, SCRCMD_PROC_CheckPartyMonKnowsMove, SCRCMD_PROC_FindPartyMonWithMove, SCRCMD_PROC_AddMonToPartySimple, SCRCMD_PROC_AddMonToPartyDetailed, SCRCMD_PROC_CountMonMoves, SCRCMD_PROC_GetMonMove, SCRCMD_PROC_SetMonMove, SCRCMD_PROC_CheckMonIsPlayerOwned, SCRCMD_PROC_ChangeMonForm, SCRCMD_PROC_SetRotomFormMove, SCRCMD_PROC_GetRelearnableMoveCount, SCRCMD_PROC_CheckMonParamMatchesTable, SCRCMD_PROC_GetMonTripleParams, SCRCMD_PROC_SetMonParamChecked, SCRCMD_PROC_GetMonParamIfListed, SCRCMD_PROC_AddMonToBoxSimple, SCRCMD_PROC_AddMonToBoxDetailed, SCRCMD_PROC_AddEggToParty, SCRCMD_PROC_CreateMonFromSpec, SCRCMD_PROC_AddMonToBox, SCRCMD_PROC_AddMonToParty, SCRCMD_PROC_SetMiscValue, SCRCMD_PROC_AddMiscValue, SCRCMD_PROC_CheckMiscValueReached, SCRCMD_PROC_CallFieldOpenEvent, SCRCMD_PROC_CallFieldCloseEvent, SCRCMD_PROC_StartOverlayProc, SCRCMD_PROC_WaitOverlayProc, SCRCMD_PROC_ResetEventSlot, SCRCMD_PROC_OnBagClosed, SCRCMD_PROC_CallBagScreen, SCRCMD_PROC_OnGtsNegotiationDone, SCRCMD_PROC_CallGtsNegotiation, SCRCMD_PROC_OnMoveRelearnDone, SCRCMD_PROC_CallMoveRelearn, SCRCMD_PROC_CallPlayerProfile, SCRCMD_PROC_CallSubEvent, SCRCMD_PROC_CallValueScreen, SCRCMD_PROC_CallModeScreen, SCRCMD_PROC_CallWordScreen, SCRCMD_PROC_WaitNothing, SCRCMD_PROC_CallWifiBattleMatch, SCRCMD_PROC_CallMenuProc, SCRCMD_PROC_Ov037InitFromVars, SCRCMD_PROC_Ov037SetValueA, SCRCMD_PROC_Ov037SetValueB, SCRCMD_PROC_Ov037ReadEightVars, SCRCMD_PROC_Ov037Finish, SCRCMD_PROC_GetDaycareState, SCRCMD_PROC_DaycareInitFromParty, SCRCMD_PROC_StopDaycareTimer, SCRCMD_PROC_CallDaycarePartyMenu, SCRCMD_PROC_DepositDaycareMon, SCRCMD_PROC_WithdrawDaycareMon, SCRCMD_PROC_GetDaycareMonCount, SCRCMD_PROC_CheckDaycareEgg, SCRCMD_PROC_GetDaycareMonSpecies, SCRCMD_PROC_GetDaycareMonForm, SCRCMD_PROC_GetDaycareMonGender, SCRCMD_PROC_GetDaycareSlotExp, SCRCMD_PROC_GetDaycareSlotLevelsGrown, SCRCMD_PROC_GetDaycareSlotPrice, SCRCMD_PROC_GetDaycareMonGenderKindIfFirst, SCRCMD_PROC_GetDaycareGenderKind, SCRCMD_SODATEYA_RunPartyMenuEvent, SCRCMD_SODATEYA_Create
 * address:  0x0215B488
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   VM_GetU16  0x02011330  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKEPARTY_FindFirstBattleReady  0x0201AB08  thumb
 *   POKEPARTY_FindFirstNonEgg  0x0201AB18  thumb
 *   POKEPARTY_GetCapacity  0x0201AA14  thumb
 *   POKEPARTY_GetNonEggCount  0x0201AA1C  thumb
 *   POKEPARTY_GetBattleReadyCount  0x0201AA50  thumb
 *   POKEPARTY_GetEggCount  0x0201AA88  thumb
 *   POKEPARTY_GetBadEggCount  0x0201AAD4  thumb
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb
 *   func_02007984  0x02007984  thumb
 *   func_020079A0  0x020079A0  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   POKE_TOOL_PushMove  0x020180F4  thumb
 *   POKE_TOOL_SetMoveSlot  0x020181F4  thumb
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 *   func_02008530  0x02008530  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   func_02008500  0x02008500  thumb
 *   STRBUF_IsEqual  0x0204589C  arm
 *   STRBUF_Delete  0x02045808  arm
 *   func_02008550  0x02008550  thumb
 *   g0209DF08      0x0209DF08  data  a1
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   ZUKAN_SAVE_RegisterSeen  0x0200CFA0  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   sScrcmdCompareTable     0x02171180  data   ov010  a2
 *   sScrcmdParamLimits     0x0217118E  data   ov010  a2
 *   d_02171190     0x02171190  data   ov010  a2
 *   POKE_TOOL_SetRotomFormMove  0x02017A20  thumb
 *   WAZA_OSHIE_CreateMoveList  0x0216F948  thumb  ov010
 *   WAZA_OSHIE_IsListEntryValid  0x0216FAA0  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   sScrcmdAllowedParamIds 0x02171182 data a1
 *   POKE_TOOL_Create  0x020173F0  thumb
 *   func_02008510  0x02008510  thumb
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0202F190  0x0202F190  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   gSpeciesNameBank     0x020A7370  data
 *   POKE_TOOL_CreatePersonalRnd 0x020186C8 thumb
 *   POKE_TOOL_CreateEx 0x02017430 thumb
 *   func_02020FE4 0x02020FE4 thumb
 *   PALANM_GetPairedCodeForFirst 0x0202142C thumb
 *   GAME_DATA_GetMyPlayerWork 0x020127A4 thumb
 *   GAME_DATA_GetPlayerZoneId 0x02012AC8 thumb
 *   ZONEDATA_GetPlaceNameId 0x02013E4C thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   func_020074D8  0x020074D8  thumb
 *   ZUKAN_SAVE_RegisterCaught  0x0200CDE0  thumb
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   func_0200C278 0x0200C278 thumb
 *   func_0200C29C 0x0200C29C thumb
 *   func_0200C274 0x0200C274 thumb
 *   FIELD_STATUS_CreateFieldOpenEvent   0x020145CC  thumb
 *   SCRIPT_SYS_CallEvent   0x0215897C  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   SCRIPT_WORK_GetUserWorkPtr  0x02158FB4  thumb  ov010
 *   func_02030734  0x02030734  arm
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
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   GAME_DATA_GetIntrudeIdByte  0x0215841C  thumb  ov010
 *   INTRUDE_COMM_GetMemberNameNetId  0x02175FB4  thumb  ov011
 *   INTRUDE_COMM_GetMemberEntry  0x0215840C  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
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
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
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
 *   func_0200BDB0  0x0200BDB0  thumb
 *   SODATEYA_DepositPokemon 0x021C3204 thumb ov021
 *   SODATEYA_WithdrawPokemon 0x021C3270 thumb ov021
 *   SODATEYA_GetPokemonCount  0x021C340C  thumb
 *   SODATEYA_GetCompatibility  0x021C34C4  thumb
 *   SODATEYA_GetPokemon 0x021C34F8 thumb ov021
 *   SODATEYA_GetCurrentLevel 0x021C341C thumb ov021
 *   SODATEYA_GetLevelsGained 0x021C3490 thumb ov021
 *   SODATEYA_GetWithdrawCost 0x021C34B4 thumb ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   func_02014910  0x02014910  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   sAllocSiteScrcmdSodateya     0x02172900  data
 */

struct GameData;
struct ScriptVm;
struct PokemonParam;
struct Strbuf;
struct MyStatus;
struct ZukanSave;
struct GameSystem;
struct Party;
struct MsgBank;
struct PersonalData;
struct PlayerWork;
struct BoxPokemonParam;
struct MiscSave;
struct GameEvent;
struct PlayerProfile;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef short s16;

typedef signed int     s32;

typedef unsigned long long u64;

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
typedef struct ScriptProcHandoff {
    void *work;         /* 0x00 */
    u32 userData;       /* 0x04 */
    u32 onFinish;       /* 0x08, function called with the record when set */
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

typedef struct PlayerName {
    u16 chars[20];
} PlayerName;

typedef struct PlayerProfile {
    u32 words[4];
} PlayerProfile;

typedef struct PlayerRecord {
    u8 data[0x28];
} PlayerRecord;

typedef struct CommState {
    u8 pad00[0x86];
    u16 localPlayerId : 3;  /* 0x086 */
    u16 reserved : 13;
    u8 pad88[0x1AC - 0x88];
    PlayerRecord records[1];    /* 0x1AC */
} CommState;

typedef struct ProfileProcWork {
    void *gameSystem;   /* 0x00 */
    PlayerName name;    /* 0x04 */
    PlayerProfile profile;  /* 0x2C */
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

typedef struct PartyMenuParam {
    void *party;        /* 0x00 */
    u32 pad04[2];
    u32 listWork;       /* 0x0C */
    u32 pad10[9];
    u32 menuType;       /* 0x34 */
    u32 cursorPos;      /* 0x38 */
    u32 selectedPos;    /* 0x3C */
} PartyMenuParam;

typedef struct PartyMenuState {
    void *party;        /* 0x00 */
    u32 listWork;       /* 0x04 */
    u32 gameData;       /* 0x08 */
    u8 enabled;         /* 0x0C */
    u8 cursor;          /* 0x0D */
    u8 partyCount;      /* 0x0E */
    u8 selectedPos;     /* 0x0F */
    u8 reserved10;      /* 0x10 */
    u8 pad11[7];
    u32 zukanSave;      /* 0x18 */
} PartyMenuState;

typedef struct DaycareEventWork {
    void *gameSystem;           /* 0x00 */
    void *fieldMap;             /* 0x04 */
    PartyMenuParam *menuParam;  /* 0x08 */
    PartyMenuState *menuState;  /* 0x0C */
    u16 *resultVar;             /* 0x10 */
} DaycareEventWork;

extern u16 SCRIPT_WORK_ReadWorkValue(void *, void *);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *, void *);
extern void *SCRCMD_WORK_GetGameData(void *);
extern void *GAME_DATA_GetMyParty(const struct GameData *);
extern u32 POKEPARTY_GetCount(void *);
extern void *POKEPARTY_GetMember(void *, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *, u32 id, u32);
extern void POKE_TOOL_HealParty(void *);
extern u16 VM_GetU16(struct ScriptVm *);
extern void POKE_TOOL_SetPartyValue(void *, u32 id, u32);
extern u32 POKEPARTY_FindFirstBattleReady(void *);
extern u32 POKEPARTY_FindFirstNonEgg(void *);
extern u32 POKEPARTY_GetCapacity(void *);
extern u32 POKEPARTY_GetNonEggCount(void *);
extern u32 POKEPARTY_GetBattleReadyCount(void *);
extern u32 POKEPARTY_GetEggCount(void *);
extern u32 POKEPARTY_GetBadEggCount(void *);
extern u32 GAME_DATA_GetBoxManager(const struct GameData *);
extern int func_02007984(void *);
extern int func_020079A0(void *);
extern void *SCRCMD_WORK_GetGameSystem(void *);
extern u16 SCRCMD_WORK_GetHeapId(void *);
extern u8 *GAME_DATA_GetMyStatus(void *);
extern u32 POKE_TOOL_DecodePartyParam(struct PokemonParam *);
extern void POKE_TOOL_PushMove(void *, int move);
extern void POKE_TOOL_SetMoveSlot(void *, u16 move, u32 slot);
extern u32 POKE_TOOL_EncodePartyParam(struct PokemonParam *, u32);
extern u32 func_02008530(const struct MyStatus *obj);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_02008500(void *player, void *str);
extern int STRBUF_IsEqual(struct Strbuf *, struct Strbuf *);
extern void STRBUF_Delete(struct Strbuf *vec);
extern u8 func_02008550(const struct MyStatus *obj);
extern void *SCRCMD_WORK_GetScriptWork(void *);
extern void *GAMESYSTEM_GetGameData(const struct GameSystem *);
extern u32 POKE_TOOL_ChangeForm(void *, u32);
extern void *ZUKAN_SAVE_GetFromGameData(void *);
extern void ZUKAN_SAVE_RegisterSeen(struct ZukanSave *, void *);
extern u32 POKE_TOOL_SetRotomFormMove(void *, u32 idx, u32 val);
extern u16 *WAZA_OSHIE_CreateMoveList(void *mon, u32 heap);
extern int WAZA_OSHIE_IsListEntryValid(u16 *);
extern u32 func_020307B0(void *);
extern void POKE_TOOL_RecalcParam(void *);
extern void *POKE_TOOL_Create(u32 species, u32 level, u64 id, u32 heap);
extern void *func_02008510(void *, int tag);
extern void *POKE_PERSONAL_Create(unsigned int species, int form, unsigned int heap);
extern u32 POKE_PERSONAL_GetParam(const struct PersonalData *, u32 field);
extern void POKE_PERSONAL_Delete(void *);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0202F190(void *mon, u32, void *, u32, u32 heap);
extern u32 POKEPARTY_Add(struct Party *, const struct PokemonParam *src);
extern u32 POKE_TOOL_CreatePersonalRnd(u32, int, int, int, int, int);
extern void *POKE_TOOL_CreateEx(u16, u16, u64, u32, u64, u16);
extern int func_02020FE4(u16, u32, u16);
extern unsigned short PALANM_GetPairedCodeForFirst(int);
extern void *GAME_DATA_GetMyPlayerWork(struct GameData *);
extern u16 GAME_DATA_GetPlayerZoneId(const struct PlayerWork *);
extern u32 ZONEDATA_GetPlaceNameId(u32 id);
extern void *POKE_TOOL_GetBoxParam(void *);
extern int func_020074D8(void **save, const struct BoxPokemonParam *src);
extern void ZUKAN_SAVE_RegisterCaught(struct ZukanSave *, void *);
extern void *GAME_DATA_GetMiscSave(int *);
extern u32 func_0200C278(struct MiscSave *, u32);
extern u32 func_0200C29C(struct MiscSave *, u32);
extern u32 func_0200C274(struct MiscSave *);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *);
extern void SCRIPT_SYS_CallEvent(void *, void *);
extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *);
extern int FIELD_STATUS_CreateFieldCloseEvent(int, int);
extern void *SCRIPT_WORK_GetUserWorkPtr(void *);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void GAMESYSTEM_CallProc(struct GameSystem *, u32 id, void *, void *);
extern void VM_SetWait(char *, int val);
extern u32 SCRIPT_WORK_GetUserWork(void *);
extern u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *);
extern int SCRIPT_WORK_FreeUserWork();
extern void *BAG_PARAM_Create(const struct GameData *, int, int, int);
extern void *FIELD_STATUS_CreateSubProcNoFadeCallbackEvent(char *, int, int, int, int, int, int);
extern int WAZA_OSHIE_Delete();
extern void *WAZA_OSHIE_Create(u32 heap);
extern void *FIELD_STATUS_CreateSubProcCallbackEvent(char *, int, int, int, int, int, int);
extern u32 GAMESYSTEM_GetGameComm(const struct GameSystem *);
extern int INTRUDE_COMM_GetWorkIfRunning(int);
extern u8 GAME_DATA_GetExitMode(const struct GameData *);
extern u8 GAME_DATA_GetIntrudeIdByte(void *);
extern int INTRUDE_COMM_GetMemberNameNetId(u8 *);
extern PlayerName *INTRUDE_COMM_GetMemberEntry(CommState *, int idx);
extern void *GAME_DATA_GetSaveControl(struct GameData *);
extern u16 *func_0200BE48(void *);
extern void INTRUDE_COMM_BuildLocalProfile(void *sv, struct PlayerProfile *o);
extern void *SCRIPT_WORK_GetEvent(void *);
extern void *EVENT_FIELD_PROCLINK_CreateCommExitEvent(void *, void *, int kind, int sub, int flag);
extern void GAME_BEACON_SEARCH_SetScriptEvent(void);
extern struct GameEvent *GAME_EVENT_CreateOverlayEvent(void *, u32, u32 (*fn)(void *, u32), u32);
extern void EVENT_WIFIBATTLEMATCH_Entry(s32, s32 *);
extern void EVENT_MENUPROC_Entry(void);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern void GIMMICK_INIT_SetCartLanesFlags(unsigned int, int, int);
extern void GIMMICK_INIT_SetFlagAnimeFlag(void *, int);
extern void GIMMICK_INIT_SetButtonStatesFlags(unsigned int, int);
extern void GIMMICK_INIT_RestorePlateDoorsState(unsigned int, unsigned short **);
extern void GIMMICK_INIT_ResetRotatingRoomPanels(unsigned int);
extern void *FIELDMAP_GetSodateya(void *);
extern int SODATEYA_HasEgg(void *);
extern void SODATEYA_ReceiveEgg(unsigned int *, unsigned int);
extern void SODATEYA_DeclineEgg(void **);
extern void *func_0200BDB0(void *);
extern void SODATEYA_DepositPokemon(unsigned int *, unsigned int, unsigned int);
extern void SODATEYA_WithdrawPokemon(unsigned int *, unsigned int, unsigned int);
extern int SODATEYA_GetPokemonCount();
extern u8 SODATEYA_GetCompatibility(void **);
extern void *SODATEYA_GetPokemon(void *, unsigned int);
extern int SODATEYA_GetCurrentLevel(unsigned int *, unsigned int);
extern int SODATEYA_GetLevelsGained(void **, int);
extern int SODATEYA_GetWithdrawCost(void **, int);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeOut(void *, void *, int, int);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeIn(void *, void *, int, int, int, int, int);
extern void GAME_EVENT_CallEvent(struct GameEvent *evt, struct GameEvent **out);
extern void *func_02014910(char *, int, int, int);
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct ZukanSave *);
extern struct GameEvent *func_020122C0(void *owner, void *, void *, u32 size);
extern void *func_020124E8(struct GameEvent *);
int SCRCMD_PROC_LookupTableValue(int, int);
int SCRCMD_PROC_GetPartyMember(void *, u32, void **);
int SCRCMD_PROC_GetPartyMemberParam(void *, void *, void *);
int SCRCMD_PROC_CheckMonKnowsMove(int, int);
int SCRCMD_PROC_GetMonPairedParams(int, int);
int SCRCMD_PROC_HealParty(int, int);
int SCRCMD_PROC_GetMonEvTotal(void *, void *);
int SCRCMD_PROC_CheckMonParamMismatch(int, int, int);
int SCRCMD_PROC_CheckMonIsEgg(int, int, int);
int SCRCMD_PROC_GetMonFriendship(int, int, int);
int SCRCMD_PROC_ChangeMonFriendship(int, int);
int SCRCMD_PROC_GetMonSpeciesOrEgg(int, int);
int SCRCMD_PROC_GetMonForm(int, int, int);
int SCRCMD_PROC_FindFirstPartyIndex(int, int);
int SCRCMD_PROC_GetPartyCount(void *, void *);
int SCRCMD_PROC_CountPartyMonsOfSpecies(void *, void *);
int SCRCMD_PROC_GetBoxMonCount(void *, void *);
int SCRCMD_PROC_FindPartyMonBySpecies(void *, void *);
int SCRCMD_PROC_CheckPartyMonKnowsMove(int, int, int);
int SCRCMD_PROC_FindPartyMonWithMove(void *, void *);
int SCRCMD_PROC_AddMonToPartySimple(void *, void *);
int SCRCMD_PROC_AddMonToPartyDetailed(void *, void *);
int SCRCMD_PROC_CountMonMoves(int, int, int);
int SCRCMD_PROC_GetMonMove(void *, void *);
int SCRCMD_PROC_SetMonMove(void *, void *);
int SCRCMD_PROC_CheckMonIsPlayerOwned(void *, void *);
int SCRCMD_PROC_ChangeMonForm(void *, void *);
int SCRCMD_PROC_SetRotomFormMove(void *, void *);
int SCRCMD_PROC_GetRelearnableMoveCount(int, int, int);
int SCRCMD_PROC_CheckMonParamMatchesTable(void *, void *);
int SCRCMD_PROC_GetMonTripleParams(void *, void *);
int SCRCMD_PROC_SetMonParamChecked(void *, void *);
int SCRCMD_PROC_GetMonParamIfListed(void *, void *);
int SCRCMD_PROC_AddMonToBoxSimple(void *, void *);
int SCRCMD_PROC_AddMonToBoxDetailed(void *, void *);
int SCRCMD_PROC_AddEggToParty(void *, void *);
void *SCRCMD_PROC_CreateMonFromSpec(void *, PokemonSpec *);
int SCRCMD_PROC_AddMonToBox(void *, void *);
int SCRCMD_PROC_AddMonToParty(void *, void *);
int SCRCMD_PROC_SetMiscValue(int, int);
int SCRCMD_PROC_AddMiscValue(int, int);
int SCRCMD_PROC_CheckMiscValueReached(void *, void *);
int SCRCMD_PROC_CallFieldOpenEvent(void *, void *);
int SCRCMD_PROC_CallFieldCloseEvent(int, int);
void SCRCMD_PROC_StartOverlayProc(void *, void *, u32 overlayId, const void *procData, void *procWork, u32 onFinish, u32 userData);
int SCRCMD_PROC_WaitOverlayProc(int, int);
int SCRCMD_PROC_ResetEventSlot(int, int);
void SCRCMD_PROC_OnBagClosed(BagCloseData *closeData);
int SCRCMD_PROC_CallBagScreen(void *, void *);
void SCRCMD_PROC_OnGtsNegotiationDone(GtsCallbackData *callbackData);
int SCRCMD_PROC_CallGtsNegotiation(void *, void *);
int SCRCMD_PROC_OnMoveRelearnDone(int, int);
int SCRCMD_PROC_CallMoveRelearn(void *, void *);
int SCRCMD_PROC_CallPlayerProfile(void *, void *);
int SCRCMD_PROC_CallSubEvent(void *, void *);
int SCRCMD_PROC_CallValueScreen(void *, void *);
int SCRCMD_PROC_CallModeScreen(void *, void *);
int SCRCMD_PROC_CallWordScreen(void *, void *);
int SCRCMD_PROC_WaitNothing(int, int);
int SCRCMD_PROC_CallWifiBattleMatch(void *, void *);
int SCRCMD_PROC_CallMenuProc(void *, void *);
int SCRCMD_PROC_Ov037InitFromVars(void *, void *);
int SCRCMD_PROC_Ov037SetValueA(void *, void *);
int SCRCMD_PROC_Ov037SetValueB(void *, void *);
int SCRCMD_PROC_Ov037ReadEightVars(void *, void *);
int SCRCMD_PROC_Ov037Finish(void *, void *);
int SCRCMD_PROC_GetDaycareState(int, int);
int SCRCMD_PROC_DaycareInitFromParty(void *, void *);
int SCRCMD_PROC_StopDaycareTimer(int, int);
int SCRCMD_PROC_CallDaycarePartyMenu(void *, void *);
int SCRCMD_PROC_DepositDaycareMon(void *, void *);
int SCRCMD_PROC_WithdrawDaycareMon(void *, void *);
int SCRCMD_PROC_GetDaycareMonCount(int, int);
int SCRCMD_PROC_CheckDaycareEgg(int, int);
int SCRCMD_PROC_GetDaycareMonSpecies(void *, void *);
int SCRCMD_PROC_GetDaycareMonForm(void *, void *);
int SCRCMD_PROC_GetDaycareMonGender(void *, void *);
int SCRCMD_PROC_GetDaycareSlotExp(void *, void *);
int SCRCMD_PROC_GetDaycareSlotLevelsGrown(void *, void *);
int SCRCMD_PROC_GetDaycareSlotPrice(void *, void *);
int SCRCMD_PROC_GetDaycareMonGenderKindIfFirst(void *, void *);
int SCRCMD_PROC_GetDaycareGenderKind(void *);
int SCRCMD_SODATEYA_RunPartyMenuEvent(void *event, u32 *seq, DaycareEventWork *work);
void *SCRCMD_SODATEYA_Create(void *gameSystem, void *fieldMap, u16 *resultVar);
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
extern const char sAllocSiteScrcmdSodateya[];


/*
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 */
int SCRCMD_PROC_LookupTableValue(int vm,int cmdWork)
{
    int tableIndex = SCRIPT_WORK_ReadWorkValue((void *)vm,(void *)cmdWork);
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer((void *)vm,(void *)cmdWork);
    *resultVar = sScrcmdLookupTable[tableIndex];
    return 0;
}



int SCRCMD_PROC_GetPartyMember(void *cmdWork, u32 partyIndex, void **outMemberArg)
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
int SCRCMD_PROC_GetPartyMemberParam(void *cmdWork, void *partyIndex, void *paramId)
{
    int member;

    if (SCRCMD_PROC_GetPartyMember(cmdWork, (u32)partyIndex, (void **)(&member)) == 1)
        return POKE_TOOL_GetPartyValue((void *)member, (u32)paramId, 0);

    return 0;
}



int SCRCMD_PROC_CheckMonKnowsMove(int callArg0, int callArg1)
{
    int callArg2;
    int moveIdCopy;
    int monCopy;
    int zero;

moveIdCopy = callArg1 + 0;
callArg1 = 0x4c;
callArg2 = 0;
monCopy = callArg0 + 0;
zero = 0;
    callArg0 = POKE_TOOL_GetPartyValue((void *)callArg0, callArg1, callArg2);
    if (callArg0 == 0) goto checkSlots;
callArg0 = zero + 0;
    return callArg0;
checkSlots:
callArg0 = monCopy + 0;
callArg1 = 0x36;
callArg2 = zero + 0;
    callArg0 = POKE_TOOL_GetPartyValue((void *)callArg0, callArg1, callArg2);
    if (moveIdCopy == callArg0) goto found;
callArg0 = monCopy + 0;
callArg1 = 0x37;
callArg2 = zero + 0;
    callArg0 = POKE_TOOL_GetPartyValue((void *)callArg0, callArg1, callArg2);
    if (moveIdCopy == callArg0) goto found;
callArg0 = monCopy + 0;
callArg1 = 0x38;
callArg2 = zero + 0;
    callArg0 = POKE_TOOL_GetPartyValue((void *)callArg0, callArg1, callArg2);
    if (moveIdCopy == callArg0) goto found;
callArg0 = monCopy + 0;
callArg1 = 0x39;
callArg2 = zero + 0;
    callArg0 = POKE_TOOL_GetPartyValue((void *)callArg0, callArg1, callArg2);
    if (moveIdCopy != callArg0) goto notFound;
found:
callArg0 = 1;
    return callArg0;
notFound:
callArg0 = zero + 0;
    return callArg0;}


int SCRCMD_PROC_GetMonPairedParams(int vm, int cmdWork)
{
    u16 *firstResultVar = SCRIPT_WORK_ReadWorkPointer((void *)vm, (void *)cmdWork);
    u16 *secondResultVar = SCRIPT_WORK_ReadWorkPointer((void *)vm, (void *)cmdWork);
    int mon;
    if (SCRCMD_PROC_GetPartyMember((void *)cmdWork, SCRIPT_WORK_ReadWorkValue((void *)vm, (void *)cmdWork), (void **)(&mon)) == 1) {
        *firstResultVar = POKE_TOOL_GetPartyValue((void *)mon, 0xAE, 0);
        *secondResultVar = POKE_TOOL_GetPartyValue((void *)mon, 0xAF, 0);
    } else {
        *firstResultVar = 0;
        *secondResultVar = 0;
    }
    return 0;
}



int SCRCMD_PROC_HealParty(int callArg0, int callArg1)
{
    void *gameData;
    void *party;

callArg0 = callArg1 + 0;
    gameData = SCRCMD_WORK_GetGameData((void *)callArg0);
    party = GAME_DATA_GetMyParty(gameData);
    POKE_TOOL_HealParty(party);
callArg0 = 0;
    return callArg0;}


#pragma opt_lifetimes off


#pragma opt_propagation off


/*
 * 2026-10-05 (wave P14 C6): closed with per-function opt_lifetimes off plus
 * opt_propagation off. Without them the two zeros (the named argument zero z
 * and the initial sum) merge into one register and the first add folds to
 * adds r0,r0,#0 (35 B off, 166 B). opt_lifetimes off alone: 2 B off.
 */
int SCRCMD_PROC_GetMonEvTotal(void *vm, void *cmdWork)
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



int SCRCMD_PROC_CheckMonParamMismatch(int callArg0, int callArg1, int callArg2)
{
    unsigned char monSlot[4];
    int workOrValue;
    int vmOrZero;
    u16 *resultVar;
vmOrZero = callArg0 + 0;
workOrValue = callArg1 + 0;
    resultVar = SCRIPT_WORK_ReadWorkPointer((void *)callArg0, (void *)callArg1);
callArg0 = vmOrZero + 0;
callArg1 = workOrValue + 0;
    callArg0 = SCRIPT_WORK_ReadWorkValue((void *)callArg0, (void *)callArg1);
callArg1 = callArg0 + 0;
vmOrZero = 0;
callArg0 = workOrValue + 0;
callArg2 = (int)(monSlot + 0);
*resultVar = vmOrZero;
    callArg0 = SCRCMD_PROC_GetPartyMember((void *)callArg0, callArg1, (void **)callArg2);
    if (callArg0 != 1) goto done;
    callArg0 = *(int *)monSlot;
callArg1 = 0xa0;
callArg2 = vmOrZero + 0;
    callArg0 = (int)POKE_TOOL_GetPartyValue((void *)callArg0, callArg1, callArg2);
callArg0 = callArg0 << 0x10;
workOrValue = (unsigned)callArg0 >> 0x10;
    callArg0 = *(int *)monSlot;
callArg1 = 0xa1;
callArg2 = vmOrZero + 0;
    callArg0 = (int)POKE_TOOL_GetPartyValue((void *)callArg0, callArg1, callArg2);
callArg0 = callArg0 << 0x10;
callArg0 = (unsigned)callArg0 >> 0x10;
    if (workOrValue == callArg0) goto differ;
    callArg0 = *(int *)monSlot;
callArg1 = 0x4c;
callArg2 = vmOrZero + 0;
    callArg0 = (int)POKE_TOOL_GetPartyValue((void *)callArg0, callArg1, callArg2);
    if (callArg0 != 1) goto done;
differ:
callArg0 = 1;
*resultVar = callArg0;
done:
callArg0 = 0;
    return callArg0;
}



int SCRCMD_PROC_CheckMonIsEgg(int callArg0, int callArg1, int callArg2)
{
    unsigned char monSlot[4];
    int cmdWorkCopy;
    int vmOrZero;
    u16 *resultVar;
vmOrZero = callArg0 + 0;
cmdWorkCopy = callArg1 + 0;
    resultVar = SCRIPT_WORK_ReadWorkPointer((void *)callArg0, (void *)callArg1);
callArg0 = vmOrZero + 0;
callArg1 = cmdWorkCopy + 0;
    callArg0 = (int)SCRIPT_WORK_ReadWorkValue((void *)callArg0, (void *)callArg1);
callArg1 = callArg0 + 0;
vmOrZero = 0;
callArg0 = cmdWorkCopy + 0;
callArg2 = (int)(monSlot + 0);
*resultVar = vmOrZero;
    callArg0 = SCRCMD_PROC_GetPartyMember((void *)callArg0, callArg1, (void **)callArg2);
    if (callArg0 != 1) goto done;
    callArg0 = *(int *)monSlot;
callArg1 = 0x4c;
callArg2 = vmOrZero + 0;
    callArg0 = POKE_TOOL_GetPartyValue((void *)callArg0, callArg1, callArg2);
    if (callArg0 != 0) goto isEgg;
*resultVar = vmOrZero;
    goto done;
isEgg:
callArg0 = 1;
*resultVar = callArg0;
done:
callArg0 = 0;
    return callArg0;
}



int SCRCMD_PROC_GetMonFriendship(int callArg0, int callArg1, int callArg2)
{
    unsigned char monSlot[4];
    int cmdWorkCopy;
    int vmOrZero;
    u16 *resultVar;
vmOrZero = callArg0 + 0;
cmdWorkCopy = callArg1 + 0;
    resultVar = SCRIPT_WORK_ReadWorkPointer((void *)callArg0, (void *)callArg1);
callArg0 = vmOrZero + 0;
callArg1 = cmdWorkCopy + 0;
    callArg0 = (int)SCRIPT_WORK_ReadWorkValue((void *)callArg0, (void *)callArg1);
callArg1 = callArg0 + 0;
vmOrZero = 0;
callArg0 = cmdWorkCopy + 0;
callArg2 = (int)(monSlot + 0);
*resultVar = vmOrZero;
    callArg0 = SCRCMD_PROC_GetPartyMember((void *)callArg0, callArg1, (void **)callArg2);
    if (callArg0 != 1) goto done;
    callArg0 = *(int *)monSlot;
callArg1 = 0x4c;
callArg2 = vmOrZero + 0;
    callArg0 = (int)POKE_TOOL_GetPartyValue((void *)callArg0, (u32)callArg1, (u32)callArg2);
    if (callArg0 != 0) goto done;
    callArg0 = *(int *)monSlot;
callArg1 = 9;
callArg2 = vmOrZero + 0;
    callArg0 = (int)POKE_TOOL_GetPartyValue((void *)callArg0, (u32)callArg1, (u32)callArg2);
*resultVar = callArg0;
done:
callArg0 = 0;
    return callArg0;
}


int SCRCMD_PROC_ChangeMonFriendship(int vm, int cmdWork)
{
    int partyIndex = SCRIPT_WORK_ReadWorkValue((void *)vm, (void *)cmdWork);
    int amount = SCRIPT_WORK_ReadWorkValue((void *)vm, (void *)cmdWork);
    int operation = VM_GetU16((struct ScriptVm *)vm);
    int mon = 0;
    u8 friendship;
    if (SCRCMD_PROC_GetPartyMember((void *)cmdWork, partyIndex, (void **)(&mon)) == 0) {
        return 0;
    }
    if (POKE_TOOL_GetPartyValue((void *)mon, 0x4C, 0) == 1) {
        return 0;
    }
    friendship = POKE_TOOL_GetPartyValue((void *)mon, 9, 0);
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
    POKE_TOOL_SetPartyValue((void *)mon, 9, friendship);
    return 0;
}


int SCRCMD_PROC_GetMonSpeciesOrEgg(int vm,int cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer((void *)vm,(void *)cmdWork);
    int partyIndex = SCRIPT_WORK_ReadWorkValue((void *)vm,(void *)cmdWork);
    if (SCRCMD_PROC_GetPartyMemberParam((void *)cmdWork,(void *)partyIndex,(void *)0x4C) != 0) *resultVar = 0x28A; else *resultVar = SCRCMD_PROC_GetPartyMemberParam((void *)cmdWork,(void *)partyIndex,(void *)5);
    return 0;
}



int SCRCMD_PROC_GetMonForm(int callArg0, int callArg1, int callArg2)
{
    int cmdWorkCopy;
    int vmCopy;
    u16 *resultVar;

vmCopy = callArg0 + 0;
cmdWorkCopy = callArg1 + 0;
    resultVar = SCRIPT_WORK_ReadWorkPointer((void *)callArg0, (void *)callArg1);
callArg0 = vmCopy + 0;
callArg1 = cmdWorkCopy + 0;
    callArg0 = (int)SCRIPT_WORK_ReadWorkValue((void *)callArg0, (void *)callArg1);
callArg1 = callArg0 + 0;
callArg0 = cmdWorkCopy + 0;
callArg2 = 0x6f;
    callArg0 = SCRCMD_PROC_GetPartyMemberParam((void *)callArg0, (void *)callArg1, (void *)callArg2);
*resultVar = callArg0;
callArg0 = 0;
    return callArg0;}



int SCRCMD_PROC_FindFirstPartyIndex(int callArg0, int callArg1)
{
    int vmOrMode;
    int cmdWorkCopy;
    unsigned short *resultVar;
    void *party;

vmOrMode = callArg0 + 0;
cmdWorkCopy = callArg1 + 0;
    resultVar = SCRIPT_WORK_ReadWorkPointer((void *)callArg0, (void *)callArg1);
callArg0 = vmOrMode + 0;
callArg1 = cmdWorkCopy + 0;
    callArg0 = (int)SCRIPT_WORK_ReadWorkValue((void *)callArg0, (void *)callArg1);
vmOrMode = callArg0 + 0;
callArg0 = cmdWorkCopy + 0;
    party = SCRCMD_WORK_GetGameData((void *)callArg0);
    party = GAME_DATA_GetMyParty(party);
    if (vmOrMode == 1) goto nonEgg;
    if (vmOrMode != 2) goto none;
    callArg0 = POKEPARTY_FindFirstBattleReady(party);
truncate:
callArg0 = callArg0 << 0x10;
callArg0 = (unsigned)callArg0 >> 0x10;
    goto store;
nonEgg:
    callArg0 = POKEPARTY_FindFirstNonEgg(party);
    goto truncate;
none:
callArg0 = 0;
store:
*resultVar = callArg0;
callArg0 = 0;
    return callArg0;}



int SCRCMD_PROC_GetPartyCount(void *vm, void *cmdWork)
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



int SCRCMD_PROC_CountPartyMonsOfSpecies(void *vm, void *cmdWork)
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



int SCRCMD_PROC_GetBoxMonCount(void *vm, void *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int countKind = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    void *boxManager = (void *)GAME_DATA_GetBoxManager(gameData);
    int result;

    GAME_DATA_GetMyParty(gameData);
    switch (countKind) {
    case 0:
        result = func_02007984(boxManager);
        break;
    case 1:
    case 2:
        result = func_020079A0(boxManager);
        break;
    case 3:
        result = func_02007984(boxManager) - func_020079A0(boxManager);
        break;
    case 5: {
        int storedCount = func_02007984(boxManager);
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



int SCRCMD_PROC_FindPartyMonBySpecies(void *vm, void *cmdWork)
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



int SCRCMD_PROC_CheckPartyMonKnowsMove(int callArg0, int callArg1, int callArg2)
{
    int mon;
    int cmdWorkCopy;
    int vmCopy;
    int moveId;
    u16 *resultVar;
vmCopy = callArg0 + 0;
cmdWorkCopy = callArg1 + 0;
    resultVar = SCRIPT_WORK_ReadWorkPointer((void *)callArg0, (void *)callArg1);
callArg0 = vmCopy + 0;
callArg1 = cmdWorkCopy + 0;
    callArg0 = (int)SCRIPT_WORK_ReadWorkValue((void *)callArg0, (void *)callArg1);
moveId = callArg0 + 0;
callArg0 = vmCopy + 0;
callArg1 = cmdWorkCopy + 0;
    callArg0 = (int)SCRIPT_WORK_ReadWorkValue((void *)callArg0, (void *)callArg1);
callArg1 = callArg0 + 0;
callArg0 = 0;
*resultVar = callArg0;
callArg0 = cmdWorkCopy + 0;
callArg2 = (int)&mon;
    callArg0 = SCRCMD_PROC_GetPartyMember((void *)callArg0, callArg1, (void **)callArg2);
    if (callArg0 != 1) goto done;
    callArg0 = mon;
callArg1 = moveId + 0;
    callArg0 = SCRCMD_PROC_CheckMonKnowsMove(callArg0, callArg1);
    if (callArg0 != 1) goto done;
callArg0 = 1;
*resultVar = callArg0;
done:
callArg0 = 0;
    return callArg0;
}



int SCRCMD_PROC_FindPartyMonWithMove(void *vm, void *cmdWork)
{
    void *party = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(cmdWork));
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    void *moveId = (void *)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int i;
    int partyCount = POKEPARTY_GetCount(party);

    *resultVar = 6;
    for (i = 0; i < partyCount; i++) {
        if (SCRCMD_PROC_CheckMonKnowsMove((int)POKEPARTY_GetMember(party, i), (int)moveId) == 1) {
            *resultVar = i;
            break;
        }
    }
    return 0;
}



int SCRCMD_PROC_AddMonToPartySimple(void *vm, void *cmdWork)
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
int SCRCMD_PROC_AddMonToPartyDetailed(void *vm, void *cmdWork)
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







int SCRCMD_PROC_CountMonMoves(int callArg0, int callArg1, int callArg2)
{
    int mon;
    int moveSlot;
    int moveCount;
    int zero;
    u16 *resultVar;
moveCount = callArg0 + 0;
moveSlot = callArg1 + 0;
    resultVar = SCRIPT_WORK_ReadWorkPointer((void *)callArg0, (void *)callArg1);
callArg0 = moveCount + 0;
callArg1 = moveSlot + 0;
    callArg0 = (int)SCRIPT_WORK_ReadWorkValue((void *)callArg0, (void *)callArg1);
callArg1 = callArg0 + 0;
callArg0 = moveSlot + 0;
callArg2 = (int)&mon;
moveCount = 0;
    callArg0 = SCRCMD_PROC_GetPartyMember((void *)callArg0, callArg1, (void **)callArg2);
    if (callArg0 != 1) goto store;
moveSlot = moveCount + 0;
zero = moveCount + 0;
countSlot:
callArg1 = moveSlot + 0;
    callArg0 = mon;
callArg1 = callArg1 + 0x36;
callArg2 = zero + 0;
    callArg0 = POKE_TOOL_GetPartyValue((void *)callArg0, callArg1, callArg2);
    if (callArg0 == 0) goto nextSlot;
moveCount = moveCount + 1;
nextSlot:
moveSlot = moveSlot + 1;
    if (moveSlot < 4) goto countSlot;
store:
*resultVar = moveCount;
callArg0 = 0;
    return callArg0;
}







int SCRCMD_PROC_GetMonMove(void *vm, void *cmdWork)
{
    u16 *resultVar;
    void *partyIndex;
    char *moveSlot;
    void *mon;

    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    partyIndex = (char *)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    moveSlot = (char *)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    if (SCRCMD_PROC_GetPartyMember(cmdWork, (u32)partyIndex, &mon) == 1) {
        *resultVar = POKE_TOOL_GetPartyValue(mon, (u32)(moveSlot + 0x36), 0);
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
int SCRCMD_PROC_SetMonMove(void *vm, void *cmdWork)
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
int SCRCMD_PROC_CheckMonIsPlayerOwned(void *vm, void *cmdWork)
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
    if (POKE_TOOL_GetPartyValue(mon, 7, 0) != func_02008530(myStatus)) {
        *resultVar = 0;
        return 0;
    }
    heapId = SCRCMD_WORK_GetHeapId(cmdWork);
    monOtName = STRBUF_Create(16, heapId);
    playerName = STRBUF_Create(16, heapId);
    if (monOtName != 0 && playerName != 0) {
        POKE_TOOL_GetPartyValue(mon, 0x8D, (u32)monOtName);
        func_02008500(myStatus, playerName);
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
    if (POKE_TOOL_GetPartyValue(mon, 0x9A, 0) != func_02008550(myStatus)) {
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







int SCRCMD_PROC_ChangeMonForm(void *vm, void *cmdWork)
{
    void *partyIndex = (void *)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *form = (void *)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *gameData;
    void *mon;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameData = GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(cmdWork));
    mon = POKEPARTY_GetMember(GAME_DATA_GetMyParty(gameData), (u32)partyIndex);
    POKE_TOOL_ChangeForm(mon, (u32)form);
    ZUKAN_SAVE_RegisterSeen(ZUKAN_SAVE_GetFromGameData(gameData), mon);
    return 0;
}







int SCRCMD_PROC_SetRotomFormMove(void *vm, void *cmdWork)
{
    void *partyIndex = (void *)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *form = (void *)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *moveSlot = (void *)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *gameData;
    void *mon;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameData = GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(cmdWork));
    mon = POKEPARTY_GetMember(GAME_DATA_GetMyParty(gameData), (u32)partyIndex);
    POKE_TOOL_SetRotomFormMove(mon, (u32)moveSlot, (u32)form);
    ZUKAN_SAVE_RegisterSeen(ZUKAN_SAVE_GetFromGameData(gameData), mon);
    return 0;
}







int SCRCMD_PROC_GetRelearnableMoveCount(int callArg0, int callArg1, int callArg2)
{
    int mon;
    int cmdWorkCopy;
    int partyIndex;
    int heapId;
    void *relearnMoves;
    u16 *resultVar;
partyIndex = callArg0 + 0;
cmdWorkCopy = callArg1 + 0;
    resultVar = SCRIPT_WORK_ReadWorkPointer((void *)callArg0, (void *)callArg1);
callArg0 = partyIndex + 0;
callArg1 = cmdWorkCopy + 0;
    callArg0 = (int)SCRIPT_WORK_ReadWorkValue((void *)callArg0, (void *)callArg1);
partyIndex = callArg0 + 0;
callArg0 = cmdWorkCopy + 0;
    callArg0 = SCRCMD_WORK_GetHeapId((void *)callArg0);
heapId = callArg0 + 0;
callArg0 = cmdWorkCopy + 0;
callArg1 = partyIndex + 0;
callArg2 = (int)&mon;
    callArg0 = SCRCMD_PROC_GetPartyMember((void *)callArg0, callArg1, (void **)callArg2);
    if (callArg0 != 1) goto done;
    callArg0 = mon;
callArg1 = heapId + 0;
    relearnMoves = WAZA_OSHIE_CreateMoveList((void *)callArg0, callArg1);
    callArg0 = WAZA_OSHIE_IsListEntryValid(relearnMoves);
*resultVar = callArg0;
    callArg0 = func_020307B0(relearnMoves);
done:
callArg0 = 0;
    return callArg0;
}







int SCRCMD_PROC_CheckMonParamMatchesTable(void *vm, void *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int tableIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    u16 monValue = SCRCMD_PROC_GetPartyMemberParam(cmdWork, (void *)partyIndex, (void *)0x95);

    if (monValue == sScrcmdCompareTable[tableIndex]) {
        *resultVar = 1;
    } else {
        *resultVar = 0;
    }
    return 0;
}







int SCRCMD_PROC_GetMonTripleParams(void *vm, void *cmdWork)
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







int SCRCMD_PROC_SetMonParamChecked(void *vm, void *cmdWork)
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
int SCRCMD_PROC_GetMonParamIfListed(void *vm, void *cmdWork)
{
    u16 *resultVar;
    u32 partyIndex;
    u32 paramId;
    u32 i;
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    paramId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    for (i = 0; i < 12; i++) {
        if (paramId == sScrcmdAllowedParamIds[i]) {
            *resultVar = SCRCMD_PROC_GetPartyMemberParam(cmdWork, (void *)partyIndex, (void *)paramId);
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
int SCRCMD_PROC_AddMonToBoxSimple(void *vm, void *cmdWork)
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
int SCRCMD_PROC_AddMonToBoxDetailed(void *vm, void *cmdWork)
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
int SCRCMD_PROC_AddEggToParty(void *vm, void *cmdWork)
{
    void *gameData;
    u32 heapId;
    void *party;
    void *myStatus;
    u16 *resultVar;
    u32 species;
    u32 form;
    void *mon;
    u32 tempStrbuf;
    u32 personal;
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
    tempStrbuf = (u32)func_02008510(GAME_DATA_GetMyStatus(gameData), heapId);
    POKE_TOOL_SetPartyValue(mon, 0x8D, tempStrbuf);
    STRBUF_Delete((struct Strbuf *)tempStrbuf);
    personal = (u32)POKE_PERSONAL_Create((u16)POKE_TOOL_GetPartyValue(mon, 5, 0), (u16)POKE_TOOL_GetPartyValue(mon, 0x6F, 0), heapId);
    hatchCycles = POKE_PERSONAL_GetParam((const struct PersonalData *)personal, 0x15);
    POKE_PERSONAL_Delete((void *)personal);
    POKE_TOOL_SetPartyValue(mon, 9, hatchCycles);
    POKE_TOOL_SetPartyValue(mon, 0x4C, 1);
    tempStrbuf = (u32)func_02045EC0(gSpeciesNameBank, 0x28A);
    POKE_TOOL_SetPartyValue(mon, 0x73, tempStrbuf);
    STRBUF_Delete((struct Strbuf *)tempStrbuf);
    POKE_TOOL_RecalcParam(mon);
    func_0202F190(mon, 5, myStatus, 0xEA63, heapId);
    POKEPARTY_Add(party, mon);
    func_020307B0(mon);
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
    void *trainerIdOrMon;
    u32 personalRnd;
    myStatus = GAME_DATA_GetMyStatus(gameData);
    trainerIdOrMon = (void *)func_02008530((const struct MyStatus *)GAME_DATA_GetMyStatus(gameData));
    personalRnd = POKE_TOOL_CreatePersonalRnd((u32)trainerIdOrMon, (u16)spec->species, (u16)spec->form, (u32)spec->natureMode, (u32)spec->genderMode, (u32)spec->shinyMode);
    trainerIdOrMon = POKE_TOOL_CreateEx(spec->species, spec->level, (u32)trainerIdOrMon, -1, personalRnd, spec->heapId);
    POKE_TOOL_SetPartyValue(trainerIdOrMon, 0x6F, spec->form);
    POKE_TOOL_SetPartyValue(trainerIdOrMon, 6, spec->heldItem);
    if (func_02020FE4(spec->ballItem, 0xF, spec->heapId) == 4)
        POKE_TOOL_SetPartyValue(trainerIdOrMon, 0x98, (u32)PALANM_GetPairedCodeForFirst((u16)spec->ballItem));
    func_0202F190(trainerIdOrMon, 0, (void *)myStatus, ZONEDATA_GetPlaceNameId(GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(gameData))), spec->heapId);
    POKE_TOOL_RecalcParam(trainerIdOrMon);
    return trainerIdOrMon;
}






int SCRCMD_PROC_AddMonToBox(void *gameData, void *spec)
{
    void *boxManager;
    void *mon;

    boxManager = (void *)GAME_DATA_GetBoxManager(gameData);
    if (func_02007984(boxManager) >= 0x2D0)
        return 0;
    mon = SCRCMD_PROC_CreateMonFromSpec(gameData, spec);
    func_020074D8(boxManager, (const struct BoxPokemonParam *)((u32)POKE_TOOL_GetBoxParam(mon)));
    ZUKAN_SAVE_RegisterCaught(ZUKAN_SAVE_GetFromGameData(gameData), mon);
    func_020307B0(mon);
    return 1;
}






int SCRCMD_PROC_AddMonToParty(void *gameData, void *spec)
{
    void *party;
    void *mon;

    party = GAME_DATA_GetMyParty(gameData);
    if ((int)POKEPARTY_GetCapacity(party) <= (int)POKEPARTY_GetCount(party))
        return 0;
    mon = SCRCMD_PROC_CreateMonFromSpec(gameData, spec);
    POKEPARTY_Add(party, mon);
    ZUKAN_SAVE_RegisterCaught(ZUKAN_SAVE_GetFromGameData(gameData), mon);
    func_020307B0(mon);
    return 1;
}





/*
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 */
int SCRCMD_PROC_SetMiscValue(int vm,int cmdWork)
{
    void *gameData = SCRCMD_WORK_GetGameData((void *)cmdWork);
    int value;
    GAME_DATA_GetMyPlayerWork(gameData);
    value = SCRIPT_WORK_ReadWorkValue((void *)vm,(void *)cmdWork);
    func_0200C278(GAME_DATA_GetMiscSave(gameData),value);
    return 0;
}





int SCRCMD_PROC_AddMiscValue(int vm,int cmdWork)
{
    void *gameData = SCRCMD_WORK_GetGameData((void *)cmdWork);
    int value;
    GAME_DATA_GetMyPlayerWork(gameData);
    value = SCRIPT_WORK_ReadWorkValue((void *)vm,(void *)cmdWork);
    func_0200C29C(GAME_DATA_GetMiscSave(gameData),value);
    return 0;
}






int SCRCMD_PROC_CheckMiscValueReached(void *vm, void *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    unsigned int value = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    GAME_DATA_GetMyPlayerWork(gameData);
    *resultVar = value <= func_0200C274(GAME_DATA_GetMiscSave(gameData)) ? 1 : 0;
    return 0;
}





/*
 * Two overlay lookups on the second argument, the second of them classified
 * by an arm9 call, then submitted together.
 */
int SCRCMD_PROC_CallFieldOpenEvent(void *vm, void *cmdWork)
{
    void *eventSlot = SCRCMD_WORK_GetScriptWork(cmdWork);

    SCRIPT_SYS_CallEvent(eventSlot, FIELD_STATUS_CreateFieldOpenEvent(SCRCMD_WORK_GetGameSystem(cmdWork)));

    return 1;
}








int SCRCMD_PROC_CallFieldCloseEvent(int callArg0, int callArg1)
{
    int cmdWorkCopy;
    void *eventSlot;
    void *gameSystem;
    void *fieldMap;

cmdWorkCopy = callArg1 + 0;
callArg0 = cmdWorkCopy + 0;
    eventSlot = SCRCMD_WORK_GetScriptWork((void *)callArg0);
callArg0 = cmdWorkCopy + 0;
    gameSystem = SCRCMD_WORK_GetGameSystem((void *)callArg0);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    callArg0 = FIELD_STATUS_CreateFieldCloseEvent((int)gameSystem, (int)fieldMap);
callArg1 = callArg0 + 0;
    SCRIPT_SYS_CallEvent(eventSlot, (void *)callArg1);
callArg0 = 1;
    return callArg0;}









/*
 * Starts a child process from an overlay on behalf of a script command:
 * allocates the 12-byte hand-off record (work pointer and two words),
 * launches the process over the work with GAMESYSTEM_CallProc, parks the record in the
 * script's slot and waits on SCRCMD_PROC_WaitOverlayProc.
 */
void SCRCMD_PROC_StartOverlayProc(void *vm, void *cmdWork, u32 overlayId, const void *procData, void *procWork, u32 onFinish, u32 userData)
{
    void *gameSystem;
    void **handoffSlot;
    ScriptProcHandoff *handoff;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    handoffSlot = SCRIPT_WORK_GetUserWorkPtr(SCRCMD_WORK_GetScriptWork(cmdWork));
    handoff = func_02030734(4, sizeof(ScriptProcHandoff), 1, sAllocSiteScrcmdProc, 0x8B);
    handoff->work = procWork;
    handoff->userData = userData;
    handoff->onFinish = onFinish;
    GAMESYSTEM_CallProc(gameSystem, overlayId, (void *)procData, procWork);
    *handoffSlot = handoff;
    VM_SetWait(vm, (int)SCRCMD_PROC_WaitOverlayProc);
}









int SCRCMD_PROC_WaitOverlayProc(int callArg0, int callArg1)
{
    int cmdWorkOrSlot;
    int handoff;
    void *gameSystem;

cmdWorkOrSlot = callArg1 + 0;
callArg0 = cmdWorkOrSlot + 0;
    gameSystem = SCRCMD_WORK_GetGameSystem((void *)callArg0);
callArg0 = cmdWorkOrSlot + 0;
    callArg0 = (int)SCRCMD_WORK_GetScriptWork((void *)callArg0); /* int-typed on purpose: pointer local changes codegen */
cmdWorkOrSlot = callArg0 + 0;
    callArg0 = SCRIPT_WORK_GetUserWork((void *)callArg0);
handoff = callArg0 + 0;
    callArg0 = GAMESYSTEM_GetProcStatus(gameSystem);
    if (callArg0 == 0) goto checkCallback;
callArg0 = 0;
    return callArg0;
checkCallback:
callArg1 = (int)((ScriptProcHandoff *)handoff)->onFinish;
    if (callArg1 == 0) goto noCallback;
callArg0 = handoff + 0;
    callArg0 = ((int (*)())callArg1)(callArg0);
    goto clearSlot;
noCallback:
callArg0 = (int)((ScriptProcHandoff *)handoff)->work;
    if (callArg0 == 0) goto freeUserData;
    func_020307B0((void *)callArg0);
freeUserData:
callArg0 = (int)((ScriptProcHandoff *)handoff)->userData;
    if (callArg0 == 0) goto clearSlot;
    func_020307B0((void *)callArg0);
clearSlot:
callArg0 = cmdWorkOrSlot + 0;
    callArg0 = SCRIPT_WORK_FreeUserWork(callArg0);
callArg0 = 1;
    return callArg0;}









int SCRCMD_PROC_ResetEventSlot(int callArg0, int callArg1)
{
    void *eventSlot;

callArg0 = callArg1 + 0;
    eventSlot = SCRCMD_WORK_GetScriptWork((void *)callArg0);
    callArg0 = SCRIPT_WORK_FreeUserWork(eventSlot);
callArg0 = 1;
    return callArg0;}







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
    func_020307B0(closeData->resultVars);
    func_020307B0(closeData->bagParam);
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
int SCRCMD_PROC_CallBagScreen(void *vm, void *cmdWork)
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
    selectedVar = (u32)SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    itemVar = (u32)SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    if (bagMode == 0)
        bagType = 4;
    else if (bagMode == 1)
        bagType = 5;
    else
        bagType = 0;
    bagParam = BAG_PARAM_Create((const struct GameData *)SCRCMD_WORK_GetGameData(cmdWork), 0, bagType, 4);
    closeData = func_02030734(4, 8, 1, sAllocSiteScrcmdProc, 0x118);
    closeData[0] = selectedVar;
    closeData[1] = itemVar;
    SCRCMD_PROC_StartOverlayProc(vm, cmdWork, (u32)ov070_id, gItemMenuProcData, bagParam, (u32)SCRCMD_PROC_OnBagClosed, (u32)closeData);
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
    func_020307B0(callbackData->param);
}








/*
 * Script command: allocates two 8-byte records (a work holding the
 * system's word, then a hand-off holding the work and one script word),
 * launches overlay 0x88 over them with the SCRCMD_PROC_OnGtsNegotiationDone callback and
 * parks the result in the script's slot.
 *
 * 2026-10-05 (wave D9): EXACT. gMbSeqProcData resolves once its symbols line carries the ov136 token (the overlay the function loads); SCRCMD_PROC_OnGtsNegotiationDone has its own witness.
 */
int SCRCMD_PROC_CallGtsNegotiation(void *vm, void *cmdWork)
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
    gtsParam = func_02030734(4, 8, 0, sAllocSiteScrcmdProc, 0x14F);
    callbackData = func_02030734(4, 8, 0, sAllocSiteScrcmdProc, 0x150);
    gtsParam[0] = (u32)gameData;
    callbackData[0] = (u32)gtsParam;
    callbackData[1] = (u32)SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    SCRIPT_SYS_CallEvent(eventSlot, FIELD_STATUS_CreateSubProcNoFadeCallbackEvent(gameSystem, (int)fieldMap, (u32)ov136_id, (int)gMbSeqProcData, (int)gtsParam, (int)((void *)SCRCMD_PROC_OnGtsNegotiationDone), (int)callbackData));
    return 1;
}








int SCRCMD_PROC_OnMoveRelearnDone(int callArg0, int callArg1)
{
    int callbackData;

callbackData = callArg0 + 0;
callArg0 = (int)((RelearnCallbackData *)callbackData)->param;
callArg0 = ((MoveRelearnParam *)callArg0)->learned;
    if (callArg0 == 0) goto notLearned;
    if (callArg0 == 1) goto learned;
notLearned:
callArg1 = 0;
    goto store;
learned:
callArg1 = 1;
store:
callArg0 = (int)((RelearnCallbackData *)callbackData)->resultVar;
*(u16 *)callArg0 = callArg1;
callArg0 = (int)((RelearnCallbackData *)callbackData)->param;
callArg0 = (int)((MoveRelearnParam *)callArg0)->relearnMoves;
    callArg0 = (int)func_020307B0((void *)callArg0);
callArg0 = (int)((RelearnCallbackData *)callbackData)->param;
    callArg0 = WAZA_OSHIE_Delete(callArg0);
    return callArg0;}








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
int SCRCMD_PROC_CallMoveRelearn(void *vm, void *cmdWork)
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
    resultVar = (u32)SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    mon = POKEPARTY_GetMember(GAME_DATA_GetMyParty(gameData), partyIndex);
    myStatus = GAME_DATA_GetMyStatus(gameData);
    relearnMoves = WAZA_OSHIE_CreateMoveList(mon, 4);
    relearnParam = WAZA_OSHIE_Create(4);
    MoveRelearnParam_Init(relearnParam, mon, myStatus, gameSystem, relearnMoves);
    callbackData = func_02030734(4, 8, 0, sAllocSiteScrcmdProc, 0x19B);
    callbackData[0] = (u32)relearnParam;
    callbackData[1] = resultVar;
    SCRIPT_SYS_CallEvent(eventSlot, FIELD_STATUS_CreateSubProcCallbackEvent(gameSystem, (int)fieldMap, (u32)ov173_id, (int)gMoveRelearnProcData, (int)relearnParam, (int)((void *)SCRCMD_PROC_OnMoveRelearnDone), (int)callbackData));
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
int SCRCMD_PROC_CallPlayerProfile(void *vm, void *cmdWork)
{
    void *gameSystem;
    void *gameComm;
    void *gameData;
    ProfileProcWork *work;
    CommState *commState;
    u8 playerIndex;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameComm = (void *)GAMESYSTEM_GetGameComm(gameSystem);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    SCRCMD_WORK_GetScriptWork(cmdWork);
    commState = (CommState *)INTRUDE_COMM_GetWorkIfRunning((int)gameComm);
    work = func_02030734(4, sizeof(ProfileProcWork), 1, sAllocSiteScrcmdProc, 0x1BC);
    if (commState != 0 && commState->localPlayerId != GAME_DATA_GetExitMode(gameData)
        && INTRUDE_COMM_GetMemberNameNetId((u8 *)(&commState->records[GAME_DATA_GetIntrudeIdByte(gameData)])) == 1
        && ((u8 *)commState)[0x922] == 1) {
        playerIndex = GAME_DATA_GetIntrudeIdByte(gameData);
        work->name = *INTRUDE_COMM_GetMemberEntry(commState, playerIndex);
        work->profile = *(PlayerProfile *)((u8 *)commState + 0x914);
        work->isRemote = 1;
    } else {
        func_0200BE48(GAME_DATA_GetSaveControl(gameData));
        INTRUDE_COMM_BuildLocalProfile(gameData, (struct PlayerProfile *)(&work->profile));
        playerIndex = 0;
        work->isRemote = 0;
    }
    work->gameSystem = gameSystem;
    work->playerIndex = playerIndex;
    SCRCMD_PROC_StartOverlayProc(vm, cmdWork, (u32)ov071_id, gPlayerProfileProcData, work, 0, 0);
    return 1;
}








/*
 * Script command: reads two words and stores EVENT_FIELD_PROCLINK_CreateCommExitEvent's result
 * (over the system and the script's cell) in the script's slot.
 */
int SCRCMD_PROC_CallSubEvent(void *vm, void *cmdWork)
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
int SCRCMD_PROC_CallValueScreen(void *vm, void *cmdWork)
{
    u16 value;
    ValueProcParam *param;

    value = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    param = func_02030734(4, 8, 1, sAllocSiteScrcmdProc, 0x205);
    param->value = value;
    param->gameData = SCRCMD_WORK_GetGameData(cmdWork);
    SCRCMD_PROC_StartOverlayProc(vm, cmdWork, (u32)ov174_id, gLocalTvtSysProcData, param, 0, 0);
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
int SCRCMD_PROC_CallModeScreen(void *vm, void *cmdWork)
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
        param = func_02030734(4, 8, 1, sAllocSiteScrcmdProc, 0x22B);
        param->gameData = gameData;
        param->value = value;
        SCRCMD_PROC_StartOverlayProc(vm, cmdWork, (u32)ov221_id, gChihouZukanAwardProcData, param, 0, 0);
        break;
    case 1:
        param = func_02030734(4, 8, 1, sAllocSiteScrcmdProc, 0x233);
        param->gameData = gameData;
        param->value = value;
        SCRCMD_PROC_StartOverlayProc(vm, cmdWork, (u32)ov222_id, gZenkokuZukanAwardProcData, param, 0, 0);
        break;
    case 2:
        myStatusParam = func_02030734(4, 4, 1, sAllocSiteScrcmdProc, 0x23C);
        *myStatusParam = myStatus;
        SCRCMD_PROC_StartOverlayProc(vm, cmdWork, (u32)ov224_id, gSubwayMapProcData, myStatusParam, 0, 0);
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
int SCRCMD_PROC_CallWordScreen(void *vm, void *cmdWork)
{
    u32 value;
    u32 *param;

    value = (u32)SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    param = func_02030734(4, 8, 1, sAllocSiteScrcmdProc, 0x254);
    param[0] = value;
    SCRCMD_PROC_StartOverlayProc(vm, cmdWork, (u32)ov223_id, gPselProcData, param, 0, 0);
    return 1;
}








int SCRCMD_PROC_WaitNothing(int callArg0, int callArg1)
{
    int cmdWorkCopy;
    void *eventSlot;
    void *gameSystem;

cmdWorkCopy = callArg1 + 0;
callArg0 = cmdWorkCopy + 0;
    eventSlot = SCRCMD_WORK_GetScriptWork((void *)callArg0);
callArg0 = cmdWorkCopy + 0;
    gameSystem = SCRCMD_WORK_GetGameSystem((void *)callArg0);
callArg0 = 1;
    return callArg0;}








/*
 * Script command: reads a kind (0xF-0x13 mapped to 0-4) and a flag (0/1),
 * builds a four-word request on the stack and launches EVENT_WIFIBATTLEMATCH_Entry
 * (ov002) through GAME_EVENT_CreateOverlayEvent, parking the result in the script's slot.
 */
int SCRCMD_PROC_CallWifiBattleMatch(void *vm, void *cmdWork)
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
    SCRIPT_SYS_CallEvent(eventSlot, GAME_EVENT_CreateOverlayEvent(gameSystem, (u32)ov002_id, (void *)EVENT_WIFIBATTLEMATCH_Entry, (u32)(&param)));
    return 1;
}








/*
 * The ov003 callback 0x021543BC (unlabelled leaf, formerly the blocker) is
 * matched in pkt_ov003_021543BC and attests as matched.
 */
int SCRCMD_PROC_CallMenuProc(void *vm, void *cmdWork)
{
    MenuProcParam param;
    void *eventSlot = SCRCMD_WORK_GetScriptWork(cmdWork);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u32 mode = !SCRIPT_WORK_ReadWorkValue(vm, cmdWork) ? 1 : 2;
    param.fieldMap = (u32)GAMESYSTEM_GetFieldMap(gameSystem);
    param.mode = mode;
    SCRIPT_SYS_CallEvent(eventSlot, GAME_EVENT_CreateOverlayEvent(gameSystem, (u32)ov003_id, (void *)EVENT_MENUPROC_Entry, (u32)(&param)));
    return 1;
}








int SCRCMD_PROC_Ov037InitFromVars(void *vm, void *cmdWork)
{
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u16 *firstVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    u16 *secondVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    func_02034AC4((u32)ov037_id);
    GIMMICK_INIT_SetCartLanesFlags((unsigned int)gameSystem, *firstVar, *secondVar);
    func_02034A5C((u32)ov037_id);
    return 0;
}








int SCRCMD_PROC_Ov037SetValueA(void *vm, void *cmdWork)
{
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    int value = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    func_02034AC4((int)ov037_id);
    GIMMICK_INIT_SetFlagAnimeFlag(gameSystem, value);
    func_02034A5C((int)ov037_id);
    return 0;
}







int SCRCMD_PROC_Ov037SetValueB(void *vm, void *cmdWork)
{
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    int value = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    func_02034AC4((int)ov037_id);
    GIMMICK_INIT_SetButtonStatesFlags((unsigned int)gameSystem, value);
    func_02034A5C((int)ov037_id);
    return 0;
}







int SCRCMD_PROC_Ov037ReadEightVars(void *vm, void *cmdWork)
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
    func_02034AC4((u32)ov037_id);
    GIMMICK_INIT_RestorePlateDoorsState((unsigned int)gameSystem, resultVars);
    func_02034A5C((u32)ov037_id);
    return 0;
}







int SCRCMD_PROC_Ov037Finish(void *vm, void *cmdWork)
{
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    func_02034AC4((int)ov037_id);
    GIMMICK_INIT_ResetRotatingRoomPanels((unsigned int)gameSystem);
    func_02034A5C((int)ov037_id);
    return 0;
}







/*
 * unblocked: SODATEYA_HasEgg (ov021, unlabelled leaf) was matched bottom-up
 *   and filed as pkt_021C3400; the `ov021` token then resolves the site as
 *   `matched, overlay`.  Extent runs 36 bytes against 34 compiled: the
 *   unlabelled follower.
 */
int SCRCMD_PROC_GetDaycareState(int callArg0, int callArg1)
{    int cmdWorkCopy;
    unsigned short *resultVar;
    void *gameSystem;
    void *fieldMap;

cmdWorkCopy = callArg1 + 0;
    resultVar = SCRIPT_WORK_ReadWorkPointer((void *)callArg0, (void *)callArg1);
callArg0 = cmdWorkCopy + 0;
    gameSystem = SCRCMD_WORK_GetGameSystem((void *)callArg0);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    callArg0 = SODATEYA_HasEgg(FIELDMAP_GetSodateya(fieldMap));
*resultVar = callArg0;
callArg0 = 0;
    return callArg0;}







int SCRCMD_PROC_DaycareInitFromParty(void *vm, void *cmdWork)
{
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *party = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(cmdWork));
    SODATEYA_ReceiveEgg(FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(gameSystem)), (unsigned int)party);
    return 0;
}







int SCRCMD_PROC_StopDaycareTimer(int callArg0, int callArg1)
{
    void *gameSystem;
    void *fieldMap;

callArg0 = callArg1 + 0;
    gameSystem = SCRCMD_WORK_GetGameSystem((void *)callArg0);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    SODATEYA_DeclineEgg((void **)FIELDMAP_GetSodateya(fieldMap));
callArg0 = 0;
    return callArg0;}







int SCRCMD_PROC_CallDaycarePartyMenu(void *vm, void *cmdWork)
{
    void *eventSlot = SCRCMD_WORK_GetScriptWork(cmdWork);
    unsigned short *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    void *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    GAME_DATA_GetMyParty(gameData);
    func_0200BDB0(GAME_DATA_GetSaveControl(gameData));
    SCRIPT_SYS_CallEvent(eventSlot, SCRCMD_SODATEYA_Create(gameSystem, fieldMap, resultVar));
    return 1;
}







int SCRCMD_PROC_DepositDaycareMon(void *vm, void *cmdWork)
{
    int partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *party = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(cmdWork));
    SODATEYA_DepositPokemon(FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))), (unsigned int)party, partyIndex);
    return 0;
}







int SCRCMD_PROC_WithdrawDaycareMon(void *vm, void *cmdWork)
{
    int daycareSlot = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *party = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(cmdWork));
    SODATEYA_WithdrawPokemon(FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))), daycareSlot, (unsigned int)party);
    return 0;
}







int SCRCMD_PROC_GetDaycareMonCount(int callArg0, int callArg1)
{    int cmdWorkCopy;
    unsigned short *resultVar;
    void *gameSystem;
    void *fieldMap;

cmdWorkCopy = callArg1 + 0;
    resultVar = SCRIPT_WORK_ReadWorkPointer((void *)callArg0, (void *)callArg1);
callArg0 = cmdWorkCopy + 0;
    gameSystem = SCRCMD_WORK_GetGameSystem((void *)callArg0);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    callArg0 = SODATEYA_GetPokemonCount(FIELDMAP_GetSodateya(fieldMap));
*resultVar = callArg0;
callArg0 = 0;
    return callArg0;}







int SCRCMD_PROC_CheckDaycareEgg(int callArg0, int callArg1)
{    int cmdWorkCopy;
    unsigned short *resultVar;
    void *gameSystem;
    void *fieldMap;

cmdWorkCopy = callArg1 + 0;
    resultVar = SCRIPT_WORK_ReadWorkPointer((void *)callArg0, (void *)callArg1);
callArg0 = cmdWorkCopy + 0;
    gameSystem = SCRCMD_WORK_GetGameSystem((void *)callArg0);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    callArg0 = SODATEYA_GetCompatibility((void **)FIELDMAP_GetSodateya(fieldMap));
*resultVar = callArg0;
callArg0 = 0;
    return callArg0;}







/*
 * interface: SODATEYA_GetPokemon has two observed inputs. Its full ov021 body
 * and 0200BCA8/0200BC2C read r0/r1 only; legacy trailing r2/r3 are omitted.
 */
int SCRCMD_PROC_GetDaycareMonSpecies(void *vm, void *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int daycareSlot = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *daycareMon = SODATEYA_GetPokemon(FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))), daycareSlot);
    *resultVar = POKE_TOOL_GetPartyValue(daycareMon, 5, 0);

    return 0;
}







int SCRCMD_PROC_GetDaycareMonForm(void *vm, void *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int daycareSlot = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *daycareMon = SODATEYA_GetPokemon(FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))), daycareSlot);
    *resultVar = POKE_TOOL_GetPartyValue(daycareMon, 111, 0);

    return 0;
}







int SCRCMD_PROC_GetDaycareMonGender(void *vm, void *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int daycareSlot = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *daycareMon = SODATEYA_GetPokemon(FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))), daycareSlot);
    *resultVar = POKE_TOOL_GetPartyValue(daycareMon, 110, 0);

    return 0;
}







int SCRCMD_PROC_GetDaycareSlotExp(void *vm, void *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int daycareSlot = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    *resultVar = SODATEYA_GetCurrentLevel(FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))), daycareSlot);

    return 0;
}






int SCRCMD_PROC_GetDaycareSlotLevelsGrown(void *vm,void *cmdWork)
{
 u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm,cmdWork);
 int daycareSlot = SCRIPT_WORK_ReadWorkValue(vm,cmdWork);
 void **daycare = FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork)));
 SODATEYA_GetPokemon(daycare,daycareSlot);
 *resultVar = SODATEYA_GetLevelsGained(daycare,daycareSlot);
 return 0;
}






int SCRCMD_PROC_GetDaycareSlotPrice(void *vm,void *cmdWork)
{
 u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm,cmdWork);
 int daycareSlot = SCRIPT_WORK_ReadWorkValue(vm,cmdWork);
 void **daycare = FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork)));
 SODATEYA_GetPokemon(daycare,daycareSlot);
 *resultVar = SODATEYA_GetWithdrawCost(daycare,daycareSlot);
 return 0;
}







int SCRCMD_PROC_GetDaycareMonGenderKindIfFirst(void *vm, void *cmdWork)
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







int SCRCMD_SODATEYA_RunPartyMenuEvent(void *event, u32 *seq, DaycareEventWork *work)
{
    u32 seqValue = *seq;
    void *gameSystem = work->gameSystem;
    switch (seqValue) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, work->fieldMap, 0, 0));
        *seq = 1;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, (struct GameEvent **)FIELD_STATUS_CreateFieldCloseEvent((int)gameSystem, (int)work->fieldMap));
        work->menuParam->selectedPos = work->menuState->selectedPos;
        *seq = 2;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, func_02014910(gameSystem, (int)work->fieldMap, (int)work->menuParam, (int)work->menuState));
        *seq = 3;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        *seq = 4;
        break;
    case 4:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, work->fieldMap, 0, 0, 1, 0, 0));
        *seq = 5;
        break;
    case 5:
        *work->resultVar = work->menuParam->selectedPos;
        func_020307B0(work->menuParam);
        func_020307B0(work->menuState);
        return 1;
    }
    return 0;
}







void *SCRCMD_SODATEYA_Create(void *gameSystem, void *fieldMap, u16 *resultVar)
{
    void *gameData = GAMESYSTEM_GetGameData(gameSystem);
    void *party = GAME_DATA_GetMyParty(gameData);
    u32 zukanSave = (u32)ZUKAN_SAVE_GetFromGameData(gameData);
    PartyMenuParam *menuParam = func_02030734(4, 0x98, 0, sAllocSiteScrcmdSodateya, 0x22B);
    PartyMenuState *menuState;
    DaycareEventWork *work;
    void *event;
    menuParam->party = party;
    menuParam->menuType = 0x12;
    menuParam->cursorPos = 0;
    menuParam->selectedPos = 0;
    menuState = func_02030734(4, 0x28, 0, sAllocSiteScrcmdSodateya, 0x232);
    menuState->party = menuParam->party;
    menuState->listWork = menuParam->listWork;
    menuState->gameData = (u32)gameData;
    menuState->enabled = 1;
    menuState->partyCount = POKEPARTY_GetCount(party);
    menuState->cursor = 0;
    menuState->reserved10 = 0;
    menuState->selectedPos = 0;
    menuState->zukanSave = ZUKAN_SAVE_IsNationalDexEnabled((struct ZukanSave *)zukanSave);
    event = func_020122C0(gameSystem, 0, (void *)SCRCMD_SODATEYA_RunPartyMenuEvent, 0x14);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->menuParam = menuParam;
    work->menuState = menuState;
    work->resultVar = resultVar;
    return event;
}
