/*
 * file:     wifibattlematch_sys.c
 * unit:     yes
 * function: WIFIBATTLEMATCH_SYS_CreateWork, WIFIBATTLEMATCH_SYS_DestroyWork, WIFIBATTLEMATCH_SYS_WaitTask, WIFIBATTLEMATCH_SYS_BuildRuleCommand, WIFIBATTLEMATCH_SYS_HandleRuleCommand, WIFIBATTLEMATCH_SYS_BuildMatchCommand, WIFIBATTLEMATCH_SYS_HandleMatchCommand, WIFIBATTLEMATCH_SYS_BuildRegulationRecord, WIFIBATTLEMATCH_SYS_HandlePartyCommand, WIFIBATTLEMATCH_SYS_BuildSetupRecord, WIFIBATTLEMATCH_SYS_ApplySetup, WIFIBATTLEMATCH_SYS_BuildStartCommand, WIFIBATTLEMATCH_SYS_HandleStartCommand, WIFIBATTLEMATCH_SYS_BuildSyncCommand, WIFIBATTLEMATCH_SYS_HandleSyncCommand, WIFIBATTLEMATCH_SYS_BuildVersionCommand, WIFIBATTLEMATCH_SYS_HandleVersionCommand, WIFIBATTLEMATCH_SYS_BuildRule2Command, WIFIBATTLEMATCH_SYS_HandleRule2Command, WIFIBATTLEMATCH_SYS_BuildSlotCommand, WIFIBATTLEMATCH_SYS_DestroySlotCommand, WIFIBATTLEMATCH_SYS_AllocPartyBuffers, WIFIBATTLEMATCH_SYS_FreePartyBuffers, WIFIBATTLEMATCH_SYS_FillSetupRecord, WIFIBATTLEMATCH_SYS_CountBoxSpecies, WIFIBATTLEMATCH_SYS_GetPartyCounts, WIFIBATTLEMATCH_SYS_CreateProcWork, WIFIBATTLEMATCH_SYS_DeleteProcWork, WIFIBATTLEMATCH_SYS_RunScreen, WIFIBATTLEMATCH_SYS_GetResult, WIFIBATTLEMATCH_SYS_GetKind, WIFIBATTLEMATCH_SYS_SetStep, WIFIBATTLEMATCH_SYS_SetStepDone, WIFIBATTLEMATCH_SYS_CreateSubWork, WIFIBATTLEMATCH_SYS_DestroySubWork, WIFIBATTLEMATCH_SYS_HandleNetState
 * address:  0x02212560
 * region:   ov199
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GF_PANIC_Fail 0x02034714 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   GAME_DATA_Create 0x020124F4 thumb
 *   POKEPARTY_Create 0x0201A920 thumb
 *   BATTLE_REC_AllocWork 0x0200B400 thumb
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   BATTLE_BOX_CreateParty 0x0200BAF4 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   d_02213D00 0x02213D00 data a1 ov199
 *   d_02213C58 0x02213C58 data a4 ov199
 *   BATTLE_REC_FreeWork 0x0200B424 thumb
 *   GAME_DATA_Delete 0x02012704 thumb
 *   OS_ResetSystem 0x02087BCC arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   GFL_NET_ERR_ShowScreen 0x0200F7B8 thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_USE_GetBgmNo 0x02005C44 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   d_02213D04 0x02213D04 data a1 ov199
 *   LIVEBATTLEMATCH_SAVE_GetFromSave 0x0200E9F4 thumb
 *   LIVEBATTLEMATCH_SAVE_GetStats2 0x0200EA04 thumb
 *   POKEPARTY_Init 0x0201A948 thumb
 *   POKE_REGULATION_Load 0x0201A354 thumb
 *   REGULATION_NoOp 0x0200AE14 thumb
 *   REGULATION_GetCard 0x0200B1D4 thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   POKEPARTY_Copy 0x0201AC2C thumb
 *   POKE_REGULATION_AdjustPartyLevels 0x0201A2A8 thumb
 *   MYSTATUS_GetName 0x020084F4 thumb
 *   MYSTATUS_GetSex 0x02008550 thumb
 *   ov093_id 0x0000005D data
 *   BATTLE_REC_ClearWork 0x0200B480 thumb
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   BTL_SETUP_SetupCommSingle 0x02013790 thumb
 *   BTL_SETUP_SetupCommDouble 0x020137C0 thumb
 *   BTL_SETUP_SetupCommTriple 0x02013864 thumb
 *   BTL_SETUP_SetupCommRotation 0x02013894 thumb
 *   REGULATION_GetRuleValue 0x0200AE54 thumb
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   BTL_SETUP_SetParty 0x02013128 thumb
 *   BTL_SETUP_ApplyRegulation 0x02013160 thumb
 *   BTL_SETUP_AllocRecordBuffer 0x02013980 thumb
 *   BATTLE_REC_LoadToolOverlay 0x0200BA58 thumb
 *   BATTLE_REC_TOOL_PackSetup 0x021EEE78 thumb ov188
 *   BATTLE_REC_UnloadToolOverlay 0x0200BA68 thumb
 *   BTL_SETUP_FreeSlots 0x020130DC thumb
 *   BATTLE_REC_IsVersionSupported 0x0200BA38 thumb
 *   BATTLE_REC_TOOL_UnpackSetup 0x021EEEA8 thumb ov188
 *   BTL_SETUP_ClearWithSlots 0x02013930 thumb
 *   MYSTATUS_GetProfileId 0x0200853C thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   DWC_GetDateTime 0x02167ED8 arm ov009
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Delete 0x0203133C arm
 *   PROCSYS_Main 0x02031330 arm
 *   PROCSYS_Push 0x02031348 arm
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   BTL_SETUP_InitWithSlots  0x020138C4  thumb  arm9
 *   BTL_SETUP_Clear  0x020130C4  thumb  arm9
 *   ov213_id 0x000000D5 data
 *   data_021BB0B0 0x021BB0B0 data ov213
 *   data_021F03C4 0x021F03C4 data ov093
 *   data_021EFDAC 0x021EFDAC data ov093
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   GFL_NET_ERR_RequestScreen  0x0200FB38  thumb  arm9
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm  arm9
 *   GFL_NET_GetRunState  0x0203CD98  arm  arm9
 *   GFL_NET_GetInitParam  0x0203D798  arm  arm9
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm  arm9
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm  arm9
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb  arm9
 */

#include "../arm9/btl_setup_types.h"
#include "../ov213/comm_btl_demo_shared_types.h"

struct Big;
struct BigObj;
struct Party;
struct Proc;
struct WifiBattleMatchSysProc;
struct Rec160;
struct Rec534;
struct MyStatus;
struct Entry;
struct Reg;
struct Reg2;
struct ZoneData;
struct Obj;
struct Link;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef enum { setupValueOffset = 0x24f } SetupValueOffset;

typedef enum { matchValueOffset = 0x2c0 } MatchValueOffset;

typedef signed int     s32;

struct Sub { u32 a0; u32 a4; u8 pad[1]; };

/*
 * Per-side party buffer allocated by WIFIBATTLEMATCH_SYS_AllocPartyBuffers
 * (POKE_REGULATION_GetDataSize() + 0xd4 bytes).  Its head is a trainer
 * status record read by the 02008xxx accessors (MyStatus), it carries a
 * battle-record version at 0x44 and a saved value at 0x48, and the party
 * data copied by MI_CpuCopy8 starts at 0xd4.
 */
struct WifiBattleMatchSysPartyBuffer {
    u8 pad_00[0x44];
    u32 recordVersion;        /* 0x44, checked by BATTLE_REC_IsVersionSupported */
    u32 savedValue;           /* 0x48, copied into WifiBattleMatchSysSetupOut */
    u8 pad_4c[0xd4 - 0x4c];
    u8 partyData[];           /* 0xd4, POKEPARTY / POKE_REGULATION payload */
};

/*
 * Manager work allocated by WIFIBATTLEMATCH_SYS_CreateWork (0x8B0 bytes).
 * One struct folds the former address-named views of the same pointer
 * (sixteen views plus the local struct In).
 *
 * gameData, partyBuffer0/1 and partyA..partyD are pointers.  A few command
 * buffers (BuildRule/Match/Start/Sync) store them as plain words, so those
 * eight sites keep an explicit pointer-to-int cast rather than a union: a
 * union member suffix would touch every one of the ~100 pointer uses for no
 * change in the emitted bytes.
 */
struct WifiBattleMatchSysWork {
    u32 gameDataOwned;                    /* 0x000 */
    void *gameData;                       /* 0x004 */
    s32 battleType;                       /* 0x008 */
    s32 commMode;                         /* 0x00C */
    s32 matchKind;                        /* 0x010 */
    s32 flag14;                           /* 0x014 */
    void *procWork;                       /* 0x018 */
    s32 ruleKind;                         /* 0x01C */
    s32 result;                           /* 0x020 */
    s32 flag24;                           /* 0x024 */
    void *partyBuffer0;                   /* 0x028 */
    void *partyBuffer1;                   /* 0x02C */
    void *partyA;                         /* 0x030 */
    void *partyB;                         /* 0x034 */
    void *partyC;                         /* 0x038 */
    void *partyD;                         /* 0x03C */
    u8 pad_040[0x1B4 - 0x040];
    u32 setupRuleValue;                      /* 0x1B4 */
    u32 setupRecordVersion;                      /* 0x1B8 */
    u8 speciesCount;                      /* 0x1BC */
    u8 pad_1BD[3];
    s32 partyReady;                       /* 0x1C0 */
    u32 flagC1;                           /* 0x1C4 */
    u32 versionFlag;                      /* 0x1C8 */
    s32 countdown;                        /* 0x1CC */
    u8 pad_1D0[0x220 - 0x1D0];
    s32 startFlag;                        /* 0x220 */
    u8 pad_224[0x8AC - 0x224];
    s32 flag8AC;                          /* 0x8AC */
};

/* Proc work (0x20 bytes) built by WIFIBATTLEMATCH_SYS_CreateProcWork.
 * Folded views: four former address-named views and the former local typedef S. */
struct WifiBattleMatchSysProc {
    void *proc;                           /* 0x00 */
    s32 result;                           /* 0x04 */
    u16 heap;                             /* 0x08 */
    u8 pad_0A[2];
    s32 cbArg;                            /* 0x0C */
    char *table;                          /* 0x10 */
    void *owner;                          /* 0x14 */
    u8 kind;                              /* 0x18 */
    u8 step;                              /* 0x19 */
    u8 stepIndex;                         /* 0x1A */
    u8 state;                             /* 0x1B */
    s32 procState;                        /* 0x1C */
};

/* Sub work (0x10 bytes) built by WIFIBATTLEMATCH_SYS_CreateSubWork.
 * Folded views: three former address-named views. */
struct WifiBattleMatchSysSubWork {
    void *proc;                           /* 0x00 */
    void *timeoutFrames;                             /* 0x04 */
    s32 overlayLoaded;                    /* 0x08 */
    s32 commandAdded;                     /* 0x0C */
};

/* Regulation record (0x24 bytes) returned by
 * WIFIBATTLEMATCH_SYS_BuildRegulationRecord. One former view. */
struct WifiBattleMatchSysRegRecord {
    void *card;                           /* 0x00 */
    void *partyC;                         /* 0x04 */
    void *row;                            /* 0x08 */
    u8 rowFlag;                           /* 0x0C */
    u8 pad_0D[3];
    void *partyD;                         /* 0x10 */
    void *gameData;                       /* 0x14 */
    u8 pad_18[4];
    void *partyA;                         /* 0x1C */
};

/* Setup argument consumed by WIFIBATTLEMATCH_SYS_ApplySetup.
 * One former view. */
struct WifiBattleMatchSysSetupArg {
    u8 pad_00[4];
    void *record;                         /* 0x04 */
    void *extra;                          /* 0x08 */
    s32 state;                            /* 0x0C */
};

/* Command buffer shared by the build/handle command pairs.  The values are
 * filled by the net command framework (data_021F03C4); 0x08 is the command
 * opcode switched in CreateWork and HandleSyncCommand, 0x1C the start mode
 * switched in HandleStartCommand.
 * Folded views: three former address-named views. */
struct WifiBattleMatchSysCommand {
    u8 pad_00[8];
    s32 kind;                             /* 0x08, command opcode */
    u8 pad_0C[0x1C - 0x0C];
    s32 mode;                             /* 0x1C, start mode */
};

/* Setup record passed to ApplySetup and FillSetupRecord, and the "box
 * record" read by CountBoxSpecies / GetPartyCounts (four sides: party
 * pointers at 0x24, 6-byte name rows at 0xc8, member counts at 0xe0).
 * Folded views: two former address-named views. */
struct WifiBattleMatchSysSetupRecord {
    u8 pad_00[4];
    u32 recordVersion;                    /* 0x04, copied to Work.setupRecordVersion */
    u8 pad_08[0x21 - 0x08];
    u8 flags;                             /* 0x21, bit 0 is the side */
    u8 pad_22[2];
    void *parties[4];                     /* 0x24, POKEPARTY pointers per side */
    u8 pad_34[0x8C - 0x34];
    u32 netSetupResult;                   /* 0x8C, net setup result code, copied to Work.setupRuleValue */
    u8 pad_90[0xC8 - 0x90];
    u8 names[4][6];                       /* 0xC8, 6-byte name per side */
    u32 counts[4];                        /* 0xE0, member count per side */
};

/* 0x50-byte record filled by WIFIBATTLEMATCH_SYS_FillSetupRecord.
 * One former view. */
struct WifiBattleMatchSysSetupOut {
    u32 card;                             /* 0x00 */
    u32 savedValue;                       /* 0x04 */
    u8 pad_08[0x48 - 0x08];
    s32 setting;                          /* 0x48 */
};

/* Slot command consumed by WIFIBATTLEMATCH_SYS_DestroySlotCommand.
 * One former view. */
struct WifiBattleMatchSysSlotCommand {
    u8 pad_00[0x34];
    void *buffer;                         /* 0x34 */
};

/*
 * The 0x58-byte setup record (struct CommBtlDemoArgs) and its per-side record
 * (struct CommBtlDemoSide) are the ov213 types, shared through
 * ../ov213/comm_btl_demo_shared_types.h. WIFIBATTLEMATCH_SYS_BuildSetupRecord
 * fills side[0]/side[1] and soundKind/animTarget; ov213 reads them.
 */

/*
 * out->setupParam is the 0xF0-byte BattleSetupParam that BTL_SETUP_Create
 * allocates (arm9/btl_setup_types.h).  It is passed straight to BTL_SETUP_SetupComm*,
 * BTL_SETUP_ApplyRegulation and BTL_SETUP_AllocRecordBuffer; this file reads the
 * FieldSituation bgType/bgAttr, the bgmBattle/bgmWin ids and the bitFlags byte.
 */

/* The 0x10-byte record BuildSetupRecord returns: gameData (0x00), the 0xF0
 * BattleSetupParam (0x04) and the CommBtlDemoArgs demo record (0x08). */
struct Out { void *gameData; struct BattleSetupParam *setupParam; struct CommBtlDemoArgs *demoArgs; };

typedef struct Flag { u8 bit:1; u8 rest:7; } Flag;

typedef struct PartyCounts { u8 a,b,c; } PartyCounts;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Flags { u32 year:7, month:4, day:5, hour:5, minute:6, rest:4, enabled:1; } Flags;

typedef struct Nibbles { u8 a:4,b:4; } Nibbles;

typedef struct Triple { int a,b,c; } Triple;

typedef struct Date { int a,b,c,weekday; } Date;

typedef struct PartyCountPair { u8 a,b; } PartyCountPair;

typedef struct WifiBattleMatchSysProc WifiBattleMatchSysProc;

struct MyWk {
    void *procSys;
    u32 timeoutFrames;
    u32 overlayLoaded;
    u32 commandAdded;
};

struct WifiBattleMatchSysNameRow { u8 pad[10]; u8 name[6]; };

struct PWk {
    u32 reserved00;
    u8 *matchParam;
    u8 *battleParam;
    u32 result;
};

extern void GF_PANIC_Fail(const char *expr, u32 line, const char *file);
extern void GFL_HEAP_CreateChildHeap(unsigned, unsigned, unsigned);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, int, unsigned);
extern void MI_CpuCopy8(const void *, void *, unsigned);
extern void *GAME_DATA_Create(u16);
extern struct Party *POKEPARTY_Create(u32 heap);
extern void BATTLE_REC_AllocWork(unsigned);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern int POKE_REGULATION_GetDataSize(void);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BATTLE_BOX_GetFromSave(void *);
extern void *BATTLE_BOX_CreateParty(int box, int heap);
extern u32 GFL_HEAP_Free(void *p);
extern void BATTLE_REC_FreeWork(void);
extern void GAME_DATA_Delete(u8 *p);
extern void OS_ResetSystem(u32 parameter);
extern void PROCSYS_FreeProcWork(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(u32);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern u32 GFL_NET_ERR_ShowScreen(u32 isFatal);
extern void *GFL_HEAP_Alloc(unsigned, unsigned, int, const char *, unsigned short);
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_CancelChangeAndPlayBgm(unsigned, unsigned);
extern void *LIVEBATTLEMATCH_SAVE_GetFromSave(void *p);
extern int LIVEBATTLEMATCH_SAVE_GetStats2(int);
extern void POKEPARTY_Init(struct Party *p);
extern void *POKE_REGULATION_Load(int, int);
extern void *REGULATION_NoOp(void *);
extern struct Rec160 *REGULATION_GetCard(struct Rec160 *arr, u32 index);
extern void *BATTLE_COMPETITION_GetFromSave(void *);
extern void POKEPARTY_Copy(const struct Rec534 *src, struct Rec534 *dst);
extern void POKE_REGULATION_AdjustPartyLevels(void *, void *);
extern void *MYSTATUS_GetName(void *);
extern u8 MYSTATUS_GetSex(const struct MyStatus *obj);
extern void BATTLE_REC_ClearWork(void);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern int GF_OVERLAY_Load(s32 handle);
extern void GF_OVERLAY_Unload(int);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void BTL_SETUP_SetupCommSingle(void *, void *, int, int, u32);
extern void BTL_SETUP_SetupCommDouble(void *, void *, int, int, u32);
extern void BTL_SETUP_SetupCommTriple(void *, void *, int, int, u32);
extern void BTL_SETUP_SetupCommRotation(void *, void *, int, int, u32);
extern u32 REGULATION_GetRuleValue(struct Reg *p, u32 id);
extern s32 REGULATION_Card_GetValue(struct Reg2 *p, u32 id);
extern void BTL_SETUP_SetParty(void *, void *, int);
extern void BTL_SETUP_ApplyRegulation(u8 *o, void *reg, u32 level);
extern void BTL_SETUP_AllocRecordBuffer(struct ZoneData *o, u32 heap);
extern void BATTLE_REC_LoadToolOverlay(void);
extern void BATTLE_REC_TOOL_PackSetup(void *);
extern void BATTLE_REC_UnloadToolOverlay(void);
extern void BTL_SETUP_FreeSlots(void *);
extern unsigned BATTLE_REC_IsVersionSupported(unsigned);
extern void BTL_SETUP_Clear(u8 *p);
extern void BTL_SETUP_InitWithSlots(char *, void *, int);
extern void BATTLE_REC_TOOL_UnpackSetup(void *p, u32 c);
extern void BTL_SETUP_ClearWithSlots(struct Obj *p);
extern u32 MYSTATUS_GetProfileId(const struct MyStatus *obj);
extern unsigned POKEPARTY_GetCount(void *);
extern void *POKEPARTY_GetMember(void *,unsigned);
extern unsigned POKE_TOOL_GetPartyValue(void *,unsigned,unsigned);
extern int DWC_GetDateTime(void *date, void *time);
extern void *PROCSYS_Create(int);
extern void PROCSYS_Delete(struct Proc *p);
extern u32 PROCSYS_Main(void *);
extern void PROCSYS_Push(void *, int, void *, void *);
extern void GFL_USE_FadeOutBgm(unsigned);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *, u32, u32);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *, u32, u32);
extern int GFL_NET_GetRunState(void);
extern void *GFL_NET_GetInitParam(void);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern void GFL_NET_ERR_RequestScreen(void);
extern int DWC_RAPCOMMON_HandleNetError(int, int);
int WIFIBATTLEMATCH_SYS_CreateWork(void *a, int unused, u8 *arg);
int WIFIBATTLEMATCH_SYS_DestroyWork(void *sys, int unused, void *data, char *p);
int WIFIBATTLEMATCH_SYS_WaitTask(int unused,int *state,int unused2,char *p);
int *WIFIBATTLEMATCH_SYS_BuildRuleCommand(void *obj, unsigned heap, char *ctx);
int WIFIBATTLEMATCH_SYS_HandleRuleCommand(void *obj, int *command, int *ctx);
int *WIFIBATTLEMATCH_SYS_BuildMatchCommand(int unused, unsigned heap, char *ctx);
int WIFIBATTLEMATCH_SYS_HandleMatchCommand(void *obj, int *command, int *ctx);
u8 *WIFIBATTLEMATCH_SYS_BuildRegulationRecord(int unused, unsigned heap, u8 *p);
int WIFIBATTLEMATCH_SYS_HandlePartyCommand(void *obj, int *command, int *ctx);
struct Out *WIFIBATTLEMATCH_SYS_BuildSetupRecord(int unused, u32 heap, struct WifiBattleMatchSysWork *p);
int WIFIBATTLEMATCH_SYS_ApplySetup(void *manager, u8 *arg, u8 *p);
int *WIFIBATTLEMATCH_SYS_BuildStartCommand(int unused, unsigned heap, char *ctx);
int WIFIBATTLEMATCH_SYS_HandleStartCommand(char *p, char *q, char *work);
void *WIFIBATTLEMATCH_SYS_BuildSyncCommand(void *unused, int heap, char *p);
int WIFIBATTLEMATCH_SYS_HandleSyncCommand(char *a, char *work, char *p);
unsigned *WIFIBATTLEMATCH_SYS_BuildVersionCommand(int unused, unsigned heap, u8 *p);
int WIFIBATTLEMATCH_SYS_HandleVersionCommand(char *p, char *q, char *work);
void *WIFIBATTLEMATCH_SYS_BuildRule2Command(void *unused, int heap, char *p);
int WIFIBATTLEMATCH_SYS_HandleRule2Command(char *a, void *work, char *p);
void *WIFIBATTLEMATCH_SYS_BuildSlotCommand(void *unused, int heap, char *p);
int WIFIBATTLEMATCH_SYS_DestroySlotCommand(char *p, char *q);
void WIFIBATTLEMATCH_SYS_AllocPartyBuffers(char *p, int heap);
void WIFIBATTLEMATCH_SYS_FreePartyBuffers(u8 *p);
void WIFIBATTLEMATCH_SYS_FillSetupRecord(u8 *p,void *party1,void *party2,u8 *save,void *reg,int setting,u8 *record,void *other,int mode);
void WIFIBATTLEMATCH_SYS_CountBoxSpecies(struct WifiBattleMatchSysSetupRecord *box, unsigned char *a, unsigned char *b);
void WIFIBATTLEMATCH_SYS_GetPartyCounts(const struct WifiBattleMatchSysSetupRecord *box, unsigned char *a, unsigned char *b);
void *WIFIBATTLEMATCH_SYS_CreateProcWork(void *a, void *b, void *c, int heap);
void WIFIBATTLEMATCH_SYS_DeleteProcWork(char *p);
int WIFIBATTLEMATCH_SYS_RunScreen(struct WifiBattleMatchSysProc *s);
int WIFIBATTLEMATCH_SYS_GetResult(char *p);
unsigned char WIFIBATTLEMATCH_SYS_GetKind(char *p);
void WIFIBATTLEMATCH_SYS_SetStep(char *p, int value);
void WIFIBATTLEMATCH_SYS_SetStepDone(unsigned char *p);
int WIFIBATTLEMATCH_SYS_CreateSubWork(struct Proc *p,int unused,char *q);
int WIFIBATTLEMATCH_SYS_DestroySubWork(void *a, void *b, void *c, char *work);
int WIFIBATTLEMATCH_SYS_HandleNetState(void *proc, int *seq, struct PWk *pw, struct MyWk *wk);
extern const char d_02213D00[];
extern const unsigned d_02213C58[];
extern const char d_02213D00[], d_02213D04[];
extern const char ov093_id[];
extern u8 ov213_id[];
extern u8 data_021BB0B0[];
extern u8 data_021F03C4[];
extern u8 data_021EFDAC[];


/*
 * lever: case 1 precedes case 0 to preserve the backward shared assignment.
 * ABI exception: 3159C legacy void callee leaves allocator pointer in r0;
 * caller immediately uses this result as its workspace.
 */
int WIFIBATTLEMATCH_SYS_CreateWork(void *a, int unused, u8 *arg)
{
    u8 *p;
    void *v;
    u8 *dst;
    unsigned kind;
    switch (((struct WifiBattleMatchSysCommand *)arg)->kind) {
    case 1: kind = 1; break;
    case 0: kind = 1; break;
    default: GF_PANIC_Fail(d_02213D00, 0, d_02213D00); break;
    }
    GFL_HEAP_CreateChildHeap(kind, 0x56, 0x8000);
    p = PROCSYS_AllocProcWork(a, 0x8b0, 0x56);
    MI_CpuFill8(p, 0, 0x8b0);
    MI_CpuCopy8(arg, p + 4, 0x14);
    ((struct WifiBattleMatchSysWork *)p)->result = 0;
    if (((struct WifiBattleMatchSysWork *)p)->gameData == 0) {
        ((struct WifiBattleMatchSysWork *)p)->gameData = GAME_DATA_Create(1);
        ((struct WifiBattleMatchSysWork *)p)->gameDataOwned = 1;
    }
    ((struct WifiBattleMatchSysWork *)p)->partyA = POKEPARTY_Create(0x56);
    ((struct WifiBattleMatchSysWork *)p)->partyB = POKEPARTY_Create(0x56);
    ((struct WifiBattleMatchSysWork *)p)->partyC = POKEPARTY_Create(0x56);
    ((struct WifiBattleMatchSysWork *)p)->partyD = POKEPARTY_Create(0x56);
    BATTLE_REC_AllocWork(0x56);
    WIFIBATTLEMATCH_SYS_AllocPartyBuffers((char *)p, 0x56);
    ((struct WifiBattleMatchSysWork *)p)->procWork = WIFIBATTLEMATCH_SYS_CreateProcWork((void *)d_02213C58, (void *)9, p, 0x56);
    switch (((struct WifiBattleMatchSysWork *)p)->commMode) {
    case 0:
        ((struct WifiBattleMatchSysWork *)p)->ruleKind = 0;
        WIFIBATTLEMATCH_SYS_SetStep(((struct WifiBattleMatchSysWork *)p)->procWork, 0);
        break;
    case 1:
        ((struct WifiBattleMatchSysWork *)p)->ruleKind = 2;
        WIFIBATTLEMATCH_SYS_SetStep(((struct WifiBattleMatchSysWork *)p)->procWork, 4);
        break;
    default: GF_PANIC_Fail(d_02213D00, 0, d_02213D00); break;
    }
    dst = *(u8 * *)&((struct WifiBattleMatchSysWork *)p)->partyBuffer0;
    switch (((struct WifiBattleMatchSysWork *)p)->matchKind) {
    case 0:
        v = GAME_DATA_GetMyParty(((struct WifiBattleMatchSysWork *)p)->gameData);
        MI_CpuCopy8(v, dst + 0xd4, POKE_REGULATION_GetDataSize());
        break;
    case 1:
        v = BATTLE_BOX_CreateParty((int)BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(((struct WifiBattleMatchSysWork *)p)->gameData)), 0x8056);
        MI_CpuCopy8(v, dst + 0xd4, POKE_REGULATION_GetDataSize());
        GFL_HEAP_Free(v);
        break;
    }
    return 1;
}


int WIFIBATTLEMATCH_SYS_DestroyWork(void *sys, int unused, void *data, char *p)
{
    WIFIBATTLEMATCH_SYS_DeleteProcWork(((struct WifiBattleMatchSysWork *)p)->procWork);
    WIFIBATTLEMATCH_SYS_FreePartyBuffers((u8 *)p);
    BATTLE_REC_FreeWork();
    GFL_HEAP_Free(((struct WifiBattleMatchSysWork *)p)->partyD);
    GFL_HEAP_Free(((struct WifiBattleMatchSysWork *)p)->partyC);
    GFL_HEAP_Free(((struct WifiBattleMatchSysWork *)p)->partyB);
    GFL_HEAP_Free(((struct WifiBattleMatchSysWork *)p)->partyA);
    if (((struct WifiBattleMatchSysWork *)p)->gameDataOwned) GAME_DATA_Delete(((struct WifiBattleMatchSysWork *)p)->gameData);
    if (((struct WifiBattleMatchSysWork *)p)->commMode != 1) OS_ResetSystem(0);
    if (((struct WifiBattleMatchSysWork *)p)->flag14) GFL_HEAP_Free(data);
    PROCSYS_FreeProcWork(sys);
    GFL_HEAP_DeleteChecked(0x56);
    GFL_USE_CancelChangeAndStopBgm();
    return 1;
}


int WIFIBATTLEMATCH_SYS_WaitTask(int unused,int *state,int unused2,char *p)
{
    switch(*state) {
    case 0:
        if(WIFIBATTLEMATCH_SYS_RunScreen((struct WifiBattleMatchSysProc *)(((struct WifiBattleMatchSysWork *)p)->procWork))) *state=1;
        if(((struct WifiBattleMatchSysWork *)p)->countdown) --((struct WifiBattleMatchSysWork *)p)->countdown;
        {
            int x=WIFIBATTLEMATCH_SYS_GetResult((char *)(((struct WifiBattleMatchSysWork *)p)->procWork));
            if(x==2 || x==0) GFL_NET_ERR_ShowScreen(0);
        }
        break;
    case 1: return 1;
    }
    return 0;
}


/*
 * ABI: allocator tag is u16; passing symbolic setupValueOffset directly avoids truncating
 * the live offset variable and preserves the original instruction shape.
 * lever: enum tag 0x24F remains live and becomes offset 0x1B4.
 */
int *WIFIBATTLEMATCH_SYS_BuildRuleCommand(void *obj, unsigned heap, char *ctx)
{
    SetupValueOffset offset = setupValueOffset;
    int *p = GFL_HEAP_Alloc(heap, 0x18, 0, d_02213D04, setupValueOffset);
    MI_CpuFill8(p, 0, 0x18);
    p[0] = (int)((struct WifiBattleMatchSysWork *)ctx)->gameData;
    offset -= 0x9b;
    p[3] = (int)((struct WifiBattleMatchSysWork *)ctx)->partyBuffer0;
    p[4] = (int)((struct WifiBattleMatchSysWork *)ctx)->partyBuffer1;
    p[5] = (int)(ctx + offset);
    switch (WIFIBATTLEMATCH_SYS_GetKind(obj)) {
    case 4: case 7: p[1] = 1; break;
    case 8: p[1] = 6; break;
    case 3: p[1] = 4; break;
    case 6: p[1] = 5; break;
    case 0: p[1] = 0; break;
    case 1: case 2: case 5:
    default:
        if (((struct WifiBattleMatchSysWork *)ctx)->partyReady) p[1] = 6;
        else GF_PANIC_Fail(d_02213D00, 0, d_02213D00);
        break;
    }
    if (GFL_USE_GetBgmNo() != 0x487) GFL_USE_CancelChangeAndPlayBgm(0x487, 0xffff);
    return p;
}


int WIFIBATTLEMATCH_SYS_HandleRuleCommand(void *obj, int *command, int *ctx)
{
    switch (command[2]) {
    case 0: WIFIBATTLEMATCH_SYS_SetStepDone(obj); break;
    case 1: ctx[7] = 0; WIFIBATTLEMATCH_SYS_SetStep(obj, 4); break;
    case 2: ctx[7] = 1; WIFIBATTLEMATCH_SYS_SetStep(obj, 2); break;
    case 3: ctx[7] = 1; WIFIBATTLEMATCH_SYS_SetStep(obj, 6); break;
    case 4: ctx[7] = 1; WIFIBATTLEMATCH_SYS_SetStep(obj, 8); break;
    default: GF_PANIC_Fail(d_02213D00, 0, d_02213D00); break;
    }
    GFL_HEAP_Free(command);
    return 1;
}


/*
 * ABI: EA04 consumes the live return register from E9F4, with no new setup.
 * lever: derive an integer offset before adding the base, then reduce the enum.
 */
int *WIFIBATTLEMATCH_SYS_BuildMatchCommand(int unused, unsigned heap, char *ctx)
{
    MatchValueOffset offset = matchValueOffset;
    int *p = GFL_HEAP_Alloc(heap, 0x44, 0, d_02213D04, matchValueOffset);
    MI_CpuFill8(p, 0, 0x44);
    p[2] = (int)(ctx + 4);
    p[3] = ((struct WifiBattleMatchSysWork *)ctx)->result;
    p[0] = ((struct WifiBattleMatchSysWork *)ctx)->ruleKind - 2;
    p[5] = (int)((struct WifiBattleMatchSysWork *)ctx)->partyBuffer0;
    p[6] = (int)((struct WifiBattleMatchSysWork *)ctx)->partyBuffer1;
    p[7] = (int)(ctx + 0x40);
    p[8] = (int)(ctx + (offset - 0xf4));
    offset -= 0xf0;
    p[9] = (int)(ctx + offset);
    p[15] = (int)(ctx + 0x7d4);
    p[10] = (int)(ctx + 0x8a8);
    p[11] = (int)(ctx + 0x1b4);
    p[12] = (int)(ctx + 0x224);
    p[13] = (int)(ctx + 0x22c);
    p[14] = (int)(ctx + 0x778);
    p[16] = (int)(ctx + 0x8ac);
    {
        void *q = GAME_DATA_GetSaveControl(((struct WifiBattleMatchSysWork *)ctx)->gameData);
        p[4] = LIVEBATTLEMATCH_SAVE_GetStats2((int)LIVEBATTLEMATCH_SAVE_GetFromSave(q));
    }
    if (GFL_USE_GetBgmNo() != 0x487) GFL_USE_CancelChangeAndPlayBgm(0x487, 0xffff);
    return p;
}


/*
 * lever: case 4 stores the flag and falls through to case 0's shared call.
 */
int WIFIBATTLEMATCH_SYS_HandleMatchCommand(void *obj, int *command, int *ctx)
{
    switch (command[0]) {
    case 0: ctx[7] = 2; break;
    case 1: ctx[7] = 3; break;
    case 2: break;
    case 3: ctx[7] = 3; break;
    }
    switch (command[1]) {
    case 1: WIFIBATTLEMATCH_SYS_SetStep(obj, 2); break;
    case 2: WIFIBATTLEMATCH_SYS_SetStep(obj, 6); break;
    case 3: ctx[0x220 / 4] = 1; WIFIBATTLEMATCH_SYS_SetStep(obj, 4); break;
    case 4: ctx[9] = 1;
    case 0: WIFIBATTLEMATCH_SYS_SetStep(obj, 7); break;
    default: GF_PANIC_Fail(d_02213D00, 0, d_02213D00); break;
    }
    GFL_HEAP_Free(command);
    return 1;
}


/*
 * ABI exception: AE14 and 084F4 empty callees preserve live pointer r0;
 * caller consumes it after their BL, despite legacy void(void).
 */
u8 *WIFIBATTLEMATCH_SYS_BuildRegulationRecord(int unused, unsigned heap, u8 *p)
{
    u8 *out;
    u8 *row;
    unsigned id;
    POKEPARTY_Init(((struct WifiBattleMatchSysWork *)p)->partyA);
    POKEPARTY_Init(((struct WifiBattleMatchSysWork *)p)->partyB);
    out = GFL_HEAP_Alloc(heap, 0x24, 0, d_02213D04, 0x32f);
    MI_CpuFill8(out, 0, 0x24);
    if (((struct WifiBattleMatchSysWork *)p)->ruleKind == 2 || ((struct WifiBattleMatchSysWork *)p)->ruleKind == 3) {
        switch (((struct WifiBattleMatchSysWork *)p)->battleType) {
        case 0: id = 15; break;
        case 1: id = 16; break;
        case 2: id = 17; break;
        case 3: id = 18; break;
        case 4: id = 19; break;
        default: GF_PANIC_Fail(d_02213D00, 0, d_02213D00); break;
        }
        ((struct WifiBattleMatchSysRegRecord *)out)->card = POKE_REGULATION_Load(id, heap);
    } else if (((struct WifiBattleMatchSysWork *)p)->ruleKind == 0) {
        ((struct WifiBattleMatchSysRegRecord *)out)->card = REGULATION_NoOp(REGULATION_GetCard(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl(((struct WifiBattleMatchSysWork *)p)->gameData)), 0));
    } else if (((struct WifiBattleMatchSysWork *)p)->ruleKind == 1) {
        ((struct WifiBattleMatchSysRegRecord *)out)->card = REGULATION_NoOp(REGULATION_GetCard(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl(((struct WifiBattleMatchSysWork *)p)->gameData)), 1));
    } else {
        GF_PANIC_Fail(d_02213D00, 0, d_02213D00);
    }
    ((struct WifiBattleMatchSysRegRecord *)out)->partyA = ((struct WifiBattleMatchSysWork *)p)->partyA;
    ((struct WifiBattleMatchSysRegRecord *)out)->gameData = ((struct WifiBattleMatchSysWork *)p)->gameData;
    POKEPARTY_Copy((const struct Rec534 *)(*(u8 * *)&((struct WifiBattleMatchSysWork *)p)->partyBuffer0 + 0xd4), ((struct WifiBattleMatchSysWork *)p)->partyC);
    POKE_REGULATION_AdjustPartyLevels(((struct WifiBattleMatchSysRegRecord *)out)->card, ((struct WifiBattleMatchSysWork *)p)->partyC);
    ((struct WifiBattleMatchSysRegRecord *)out)->partyC = ((struct WifiBattleMatchSysWork *)p)->partyC;
    row = *(u8 * *)&((struct WifiBattleMatchSysWork *)p)->partyBuffer1;
    POKEPARTY_Copy((const struct Rec534 *)(row + 0xd4), ((struct WifiBattleMatchSysWork *)p)->partyD);
    POKE_REGULATION_AdjustPartyLevels(((struct WifiBattleMatchSysRegRecord *)out)->card, ((struct WifiBattleMatchSysWork *)p)->partyD);
    ((struct WifiBattleMatchSysRegRecord *)out)->row = MYSTATUS_GetName(row);
    ((struct WifiBattleMatchSysRegRecord *)out)->partyD = ((struct WifiBattleMatchSysWork *)p)->partyD;
    out[0xc] = MYSTATUS_GetSex((const struct MyStatus *)row);
    return out;
}


/*
 * tail: 02212AF6..02212AF8 is zero alignment padding.
 */
int WIFIBATTLEMATCH_SYS_HandlePartyCommand(void *obj, int *command, int *ctx)
{
    if (ctx[7] == 1) {
        switch (command[8]) {
        case 0: WIFIBATTLEMATCH_SYS_SetStep(obj, 5); break;
        case 2: ctx[0x1c0 / 4] = 1; WIFIBATTLEMATCH_SYS_SetStep(obj, 0); break;
        }
    } else {
        switch (command[8]) {
        case 0: WIFIBATTLEMATCH_SYS_SetStep(obj, 5); break;
        case 1: ctx[0x220 / 4] = 1; WIFIBATTLEMATCH_SYS_SetStep(obj, 4); break;
        case 3: ctx[8] = 2; WIFIBATTLEMATCH_SYS_SetStep(obj, 1); break;
        }
    }
    if ((unsigned)(ctx[7] - 2) <= 1) GFL_HEAP_Free((void *)command[0]);
    GFL_HEAP_Free(command);
    return 1;
}


/*
 * matching: a switch default written as its own copy of case 0 leaves the b stub the
 *   original has; explicit copies per index (0 and 1) instead of a helper; y*2+0x21+x add order.
 */
struct Out *WIFIBATTLEMATCH_SYS_BuildSetupRecord(int unused, u32 heap, struct WifiBattleMatchSysWork *p)
{
    struct Out *out;
    void *v;
    void *sys;
    int id;
    int a;
    int flag = 0;
    sys = BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl(p->gameData));
    out = GFL_HEAP_Alloc(heap, 0x10, 0, d_02213D04, 0x3e0);
    MI_CpuFill8(out, 0, 0x10);
    out->gameData = p->gameData;
    BATTLE_REC_ClearWork();
    MI_CpuFill8((u8 *)p + 0x1b4, 0, 0x18);
    out->demoArgs = GFL_HEAP_Alloc(heap, 0x58, 0, d_02213D04, 0x3eb);
    MI_CpuFill8(out->demoArgs, 0, 0x58);
    out->demoArgs->animTarget = GAME_DATA_GetTrainerRecord(p->gameData);
    out->demoArgs->soundKind = 0;
    {
        struct CommBtlDemoArgs *r = out->demoArgs;
        r->side[0].textSys = p->partyBuffer0;
        r->side[0].party = p->partyA;
        r->side[0].pad08[1] = ((struct WifiBattleMatchSysPartyBuffer *)p->partyBuffer0)->recordVersion;
    }
    {
        struct CommBtlDemoArgs *r = out->demoArgs;
        struct CommBtlDemoSide *b = &r->side[1];
        b->textSys = p->partyBuffer1;
        b->party = p->partyB;
        b->pad08[1] = ((struct WifiBattleMatchSysPartyBuffer *)p->partyBuffer1)->recordVersion;
    }
    out->setupParam = GFL_HEAP_Alloc(heap, 0xf0, 0, d_02213D04, 0x403);
    MI_CpuFill8(out->setupParam, 0, 0xf0);
    GF_OVERLAY_Load((int)ov093_id);
    if (p->ruleKind == 2 || p->ruleKind == 3) {
        id = 16;
        switch (p->battleType) {
        case 0: default: id = 15; BTL_SETUP_SetupCommSingle(out->setupParam, p->gameData, (int)GFL_NET_HANDLE_GetCurrentHandle(), 2, heap); break;
        case 1: BTL_SETUP_SetupCommDouble(out->setupParam, p->gameData, (int)GFL_NET_HANDLE_GetCurrentHandle(), 2, heap); break;
        case 2: id = 17; BTL_SETUP_SetupCommTriple(out->setupParam, p->gameData, (int)GFL_NET_HANDLE_GetCurrentHandle(), 2, heap); break;
        case 3: id = 18; BTL_SETUP_SetupCommRotation(out->setupParam, p->gameData, (int)GFL_NET_HANDLE_GetCurrentHandle(), 2, heap); break;
        case 4: id = 19; BTL_SETUP_SetupCommTriple(out->setupParam, p->gameData, (int)GFL_NET_HANDLE_GetCurrentHandle(), 2, heap); break;
        }
        v = POKE_REGULATION_Load(id, heap);
        flag = 1;
    } else if (p->ruleKind == 0) {
        v = REGULATION_NoOp(REGULATION_GetCard(sys, 0));
        switch (REGULATION_GetRuleValue(v, 0x15)) {
        case 0: BTL_SETUP_SetupCommSingle(out->setupParam, p->gameData, (int)GFL_NET_HANDLE_GetCurrentHandle(), 2, heap); break;
        case 1: BTL_SETUP_SetupCommDouble(out->setupParam, p->gameData, (int)GFL_NET_HANDLE_GetCurrentHandle(), 2, heap); break;
        case 2: BTL_SETUP_SetupCommTriple(out->setupParam, p->gameData, (int)GFL_NET_HANDLE_GetCurrentHandle(), 2, heap); break;
        case 3: BTL_SETUP_SetupCommRotation(out->setupParam, p->gameData, (int)GFL_NET_HANDLE_GetCurrentHandle(), 2, heap); break;
        default: BTL_SETUP_SetupCommSingle(out->setupParam, p->gameData, (int)GFL_NET_HANDLE_GetCurrentHandle(), 2, heap); break;
        }
    } else if (p->ruleKind == 1) {
        v = REGULATION_NoOp(REGULATION_GetCard(sys, 1));
        switch (REGULATION_GetRuleValue(v, 0x15)) {
        case 0: BTL_SETUP_SetupCommSingle(out->setupParam, p->gameData, (int)GFL_NET_HANDLE_GetCurrentHandle(), 2, heap); break;
        case 1: BTL_SETUP_SetupCommDouble(out->setupParam, p->gameData, (int)GFL_NET_HANDLE_GetCurrentHandle(), 2, heap); break;
        case 2: BTL_SETUP_SetupCommTriple(out->setupParam, p->gameData, (int)GFL_NET_HANDLE_GetCurrentHandle(), 2, heap); break;
        case 3: BTL_SETUP_SetupCommRotation(out->setupParam, p->gameData, (int)GFL_NET_HANDLE_GetCurrentHandle(), 2, heap); break;
        default: BTL_SETUP_SetupCommSingle(out->setupParam, p->gameData, (int)GFL_NET_HANDLE_GetCurrentHandle(), 2, heap); break;
        }
    } else {
        GF_PANIC_Fail(d_02213D00, flag, d_02213D00);
    }
    if (p->ruleKind == 3) a = p->battleType + 0x17;
    else if (p->ruleKind == 2) a = p->battleType + 0x1c;
    else {
        int x = REGULATION_GetRuleValue(v, 0xd);
        int y = REGULATION_GetRuleValue(v, 0x15);
        if (x >= 2) x = 1;
        a = y * 2 + 0x21 + x;
    }
    *(s32 *)out->demoArgs->pad48 = a;
    if (p->ruleKind == 2 || p->ruleKind == 3) {
        out->setupParam->bgmBattle = 0x490;
        out->setupParam->bgmWin = 0x47d;
    } else if (p->ruleKind == 0) {
        void *e = REGULATION_GetCard(sys, 0);
        int m = REGULATION_Card_GetValue(e, 0xb);
        int r = REGULATION_GetRuleValue(REGULATION_NoOp(e), 0x12);
        if (m == 1) { out->setupParam->bgmBattle = 0x48d; out->setupParam->bgmWin = 0x480; }
        else { out->setupParam->bgmBattle = 0x46b; out->setupParam->bgmWin = 0x47d; }
        if ((u32)(r - 2) <= 1) {
            out->setupParam->fieldSituation.bgAttr = 0xe;
            out->setupParam->fieldSituation.bgType = 0x12;
            out->demoArgs->soundKind = 1;
        }
    } else if (p->ruleKind == 1) {
        void *e = REGULATION_GetCard(sys, 1);
        int m = REGULATION_Card_GetValue(e, 0xb);
        int r = REGULATION_GetRuleValue(REGULATION_NoOp(e), 0x12);
        if (m == 1) { out->setupParam->bgmBattle = 0x48d; out->setupParam->bgmWin = 0x480; }
        else { out->setupParam->bgmBattle = 0x46b; out->setupParam->bgmWin = 0x47d; }
        if ((u32)(r - 2) <= 1) {
            out->setupParam->fieldSituation.bgAttr = 0xe;
            out->setupParam->fieldSituation.bgType = 0x12;
            out->demoArgs->soundKind = 1;
        }
    }
    BTL_SETUP_SetParty(out->setupParam, p->partyA, 0);
    BTL_SETUP_ApplyRegulation((u8 *)out->setupParam, v, (u16)((heap & 0x7fff) | 0x8000));
    if (p->flag8AC) out->setupParam->bitFlags |= 4;
    BTL_SETUP_AllocRecordBuffer((struct ZoneData *)out->setupParam, heap);
    GF_OVERLAY_Unload((int)ov093_id);
    if (flag) GFL_HEAP_Free(v);
    return out;
}


int WIFIBATTLEMATCH_SYS_ApplySetup(void *manager, u8 *arg, u8 *p)
{
    u8 *record = *(u8 * *)&((struct WifiBattleMatchSysSetupArg *)arg)->record;
    int state = ((struct WifiBattleMatchSysSetupArg *)arg)->state;
    PartyCounts bytes;
    void *rules,*reg,*created;
    int setting;
    ((struct WifiBattleMatchSysWork *)p)->setupRecordVersion = ((struct WifiBattleMatchSysSetupRecord *)record)->recordVersion;
    ((struct WifiBattleMatchSysWork *)p)->setupRuleValue = ((struct WifiBattleMatchSysSetupRecord *)record)->netSetupResult;
    ((struct WifiBattleMatchSysWork *)p)->flagC1 = ((Flag *)(record + 0xc1))->bit;
    ((struct WifiBattleMatchSysWork *)p)->setupRuleValue = ((struct WifiBattleMatchSysSetupRecord *)record)->netSetupResult;
    WIFIBATTLEMATCH_SYS_CountBoxSpecies((struct WifiBattleMatchSysSetupRecord *)*(u8 * *)&((struct WifiBattleMatchSysSetupArg *)arg)->record, &bytes.b, &bytes.c);
    p[0x1bc] = bytes.c;
    WIFIBATTLEMATCH_SYS_GetPartyCounts((const struct WifiBattleMatchSysSetupRecord *)*(u8 * *)&((struct WifiBattleMatchSysSetupArg *)arg)->record, &bytes.a, p + 0x1bd);
    BATTLE_REC_LoadToolOverlay();
    BATTLE_REC_TOOL_PackSetup(((struct WifiBattleMatchSysSetupArg *)arg)->record);
    BATTLE_REC_UnloadToolOverlay();
    if (((struct WifiBattleMatchSysWork *)p)->ruleKind == 0) {
        rules = REGULATION_GetCard(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl(((struct WifiBattleMatchSysWork *)p)->gameData)),0);
        reg = REGULATION_NoOp(rules);
        setting = REGULATION_Card_GetValue(rules,2);
        if (state == 0) WIFIBATTLEMATCH_SYS_FillSetupRecord(p + 0x1d0,((struct WifiBattleMatchSysWork *)p)->partyA,((struct WifiBattleMatchSysWork *)p)->partyB,((struct WifiBattleMatchSysWork *)p)->partyBuffer1,reg,setting,record,p + 0x1b4,0);
    } else if (((struct WifiBattleMatchSysWork *)p)->ruleKind == 2) {
        created = POKE_REGULATION_Load(((struct WifiBattleMatchSysWork *)p)->battleType + 0xf,0x56);
        if (state == 0) WIFIBATTLEMATCH_SYS_FillSetupRecord(p + 0x1d0,((struct WifiBattleMatchSysWork *)p)->partyA,((struct WifiBattleMatchSysWork *)p)->partyB,((struct WifiBattleMatchSysWork *)p)->partyBuffer1,created,0,record,p + 0x1b4,2);
        GFL_HEAP_Free(created);
    }
    BTL_SETUP_FreeSlots(((struct WifiBattleMatchSysSetupArg *)arg)->record);
    GFL_HEAP_Free(((struct WifiBattleMatchSysSetupArg *)arg)->record);
    GFL_HEAP_Free(((struct WifiBattleMatchSysSetupArg *)arg)->extra);
    GFL_HEAP_Free(arg);
    if (((struct WifiBattleMatchSysWork *)p)->ruleKind == 1) {
        switch(state) {
        case 0: WIFIBATTLEMATCH_SYS_SetStep(manager,0);break;
        case 1: ((struct WifiBattleMatchSysWork *)p)->partyReady=1;WIFIBATTLEMATCH_SYS_SetStep(manager,0);break;
        }
    } else {
        switch(state) {
        case 0: ((struct WifiBattleMatchSysWork *)p)->result=1;WIFIBATTLEMATCH_SYS_SetStep(manager,1);break;
        case 2: ((struct WifiBattleMatchSysWork *)p)->startFlag=1;WIFIBATTLEMATCH_SYS_SetStep(manager,4);break;
        case 3: ((struct WifiBattleMatchSysWork *)p)->result=2;WIFIBATTLEMATCH_SYS_SetStep(manager,1);break;
        }
    }
    return 1;
}


int *WIFIBATTLEMATCH_SYS_BuildStartCommand(int unused, unsigned heap, char *ctx)
{
    int zero = 0;
    int *p = GFL_HEAP_Alloc(heap, 0x28, zero, d_02213D04, 0x588);
    MI_CpuFill8(p, zero, 0x28);
    p[0] = (int)((struct WifiBattleMatchSysWork *)ctx)->gameData;
    p[1] = zero;
    p[2] = 1;
    p[4] = (int)(ctx + 0x40);
    if (((struct WifiBattleMatchSysWork *)ctx)->commMode == 0) p[3] = 0x24;
    else p[3] = 0x34;
    if (((struct WifiBattleMatchSysWork *)ctx)->startFlag) {
        ((struct WifiBattleMatchSysWork *)ctx)->startFlag = zero;
        p[5] = 1;
    } else p[5] = zero;
    return p;
}


int WIFIBATTLEMATCH_SYS_HandleStartCommand(char *p, char *q, char *work)
{
    int mode = ((struct WifiBattleMatchSysCommand *)q)->mode;
    GFL_HEAP_Free(q);
    switch (mode) {
    case 0:
        ((struct WifiBattleMatchSysWork *)work)->result = 0;
        WIFIBATTLEMATCH_SYS_SetStep(p, 1);
        break;
    case 1:
        if (((struct WifiBattleMatchSysWork *)work)->commMode == 0) WIFIBATTLEMATCH_SYS_SetStep(p, 0);
        else WIFIBATTLEMATCH_SYS_SetStepDone((unsigned char *)p);
        break;
    }
    return 1;
}


void *WIFIBATTLEMATCH_SYS_BuildSyncCommand(void *unused, int heap, char *p)
{
    unsigned int *work = GFL_HEAP_Alloc(heap, 0x1c, 0, d_02213D04, 0x5dc);
    MI_CpuFill8(work, 0, 0x1c);
    work[0] = (unsigned int)(p + 4);
    work[3] = (u32)((struct WifiBattleMatchSysWork *)p)->partyA;
    work[4] = (u32)((struct WifiBattleMatchSysWork *)p)->partyB;
    work[5] = (unsigned int)(p + 0x7d4);
    work[6] = (unsigned int)(p + 0x8a8);
    if (((struct WifiBattleMatchSysWork *)p)->ruleKind == 1)
        work[1] = 1;
    else
        work[1] = 0;
    return work;
}


int WIFIBATTLEMATCH_SYS_HandleSyncCommand(char *a, char *work, char *p)
{
    int state = ((struct WifiBattleMatchSysCommand *)work)->kind;
    GFL_HEAP_Free(work);
    if (((struct WifiBattleMatchSysWork *)p)->ruleKind == 1) {
        switch (state) {
        case 0: WIFIBATTLEMATCH_SYS_SetStep(a, 3); break;
        case 2: ((struct WifiBattleMatchSysWork *)p)->partyReady = 1; WIFIBATTLEMATCH_SYS_SetStep(a, 0); break;
        }
    } else {
        switch (state) {
        case 0: WIFIBATTLEMATCH_SYS_SetStep(a, 3); break;
        case 1: ((struct WifiBattleMatchSysWork *)p)->startFlag = 1; WIFIBATTLEMATCH_SYS_SetStep(a, 4); break;
        case 3: ((struct WifiBattleMatchSysWork *)p)->result = 2; WIFIBATTLEMATCH_SYS_SetStep(a, 1); break;
        }
    }
    return 1;
}


/*
 * ABI exception: empty AE14 preserves its input pointer in r0, consumed here.
 */
unsigned *WIFIBATTLEMATCH_SYS_BuildVersionCommand(int unused, unsigned heap, u8 *p)
{
    unsigned *out;
    unsigned index, id, flag;
    unsigned zero = 0;
    void *reg;
    int a;
    unsigned b;
    out = GFL_HEAP_Alloc(heap, 0x18, 0, d_02213D04, 0x637);
    MI_CpuFill8(out, 0, 0x18);
    if (((struct WifiBattleMatchSysWork *)p)->ruleKind == 3) {
        id = ((struct WifiBattleMatchSysWork *)p)->battleType + 0x17;
    } else if (((struct WifiBattleMatchSysWork *)p)->ruleKind == 2) {
        id = ((struct WifiBattleMatchSysWork *)p)->battleType + 0x1c;
    } else {
        if (((struct WifiBattleMatchSysWork *)p)->ruleKind == 0) index = zero;
        else if (((struct WifiBattleMatchSysWork *)p)->ruleKind == 1) index = 1;
        else GF_PANIC_Fail(d_02213D00, zero, d_02213D00);
        reg = REGULATION_NoOp(REGULATION_GetCard(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl(((struct WifiBattleMatchSysWork *)p)->gameData)), index));
        a = REGULATION_GetRuleValue(reg, 0xd);
        b = REGULATION_GetRuleValue(reg, 0x15);
        if (a >= 2) a = 1;
        id = a + (b * 2 + 0x21);
    }
    flag = 1;
    out[0] = *(unsigned *)&((struct WifiBattleMatchSysWork *)p)->gameData;
    out[1] = flag;
    out[2] = 0;
    out[4] = id;
    out[5] = 0;
    if (((struct WifiBattleMatchSysWork *)p)->ruleKind == 1) {
        out[3] = flag;
    } else {
        if (((struct WifiBattleMatchSysWork *)p)->flagC1 == 0 && ((struct WifiBattleMatchSysWork *)p)->versionFlag == 0) {
            flag = 1;
        } else {
            flag = 0;
        }
        out[3] = flag;
    }
    if (BATTLE_REC_IsVersionSupported((u8)((struct WifiBattleMatchSysPartyBuffer *)(*(u8 * *)&((struct WifiBattleMatchSysWork *)p)->partyBuffer1))->recordVersion) != 0) out[1] = 1;
    else out[1] = 0;
    return out;
}


int WIFIBATTLEMATCH_SYS_HandleVersionCommand(char *p, char *q, char *work)
{
    GFL_HEAP_Free(q);
    if (((struct WifiBattleMatchSysWork *)work)->ruleKind == 1) WIFIBATTLEMATCH_SYS_SetStep(p, 0);
    else {
        ((struct WifiBattleMatchSysWork *)work)->result = 3;
        WIFIBATTLEMATCH_SYS_SetStep(p, 1);
    }
    return 1;
}


void *WIFIBATTLEMATCH_SYS_BuildRule2Command(void *unused, int heap, char *p)
{
    unsigned int *work = GFL_HEAP_Alloc(heap, 0x1c, 0, d_02213D04, 0x6b2);
    MI_CpuFill8(work, 0, 0x1c);
    work[0] = (u32)((struct WifiBattleMatchSysWork *)p)->gameData;
    work[1] = 0;
    work[2] = 1;
    if (((struct WifiBattleMatchSysWork *)p)->flag24 != 0)
        work[4] = 0x12;
    return work;
}


int WIFIBATTLEMATCH_SYS_HandleRule2Command(char *a, void *work, char *p)
{
    switch (((struct WifiBattleMatchSysWork *)p)->ruleKind) {
    case 0:
        if (((struct WifiBattleMatchSysWork *)p)->flag24 != 0)
            WIFIBATTLEMATCH_SYS_SetStepDone((unsigned char *)a);
        else
            WIFIBATTLEMATCH_SYS_SetStep(a, 0);
        break;
    case 1:
        GF_PANIC_Fail(d_02213D00, 0, d_02213D00);
        break;
    case 2:
    case 3:
        WIFIBATTLEMATCH_SYS_SetStepDone((unsigned char *)a);
        break;
    }
    GFL_HEAP_Free(work);
    return 1;
}


/*
 * Scratch-only tails each EXACT 16B; blocker-0200BA58.log and blocker-0200BA68.log.
 * TU/suggest-split MATCH: no viable partition; the integrator owns ARM9 filing.
 * Verified blocker C (symbols: ov188_id 0x000000BC data a1;
 * GF_OVERLAY_Load 0x02034AC4 arm; GF_OVERLAY_Unload 0x02034A5C arm):
 * extern const char ov188_id[];
 * extern void GF_OVERLAY_Load(const void *);
 * extern void GF_OVERLAY_Unload(const void *);
 * void BATTLE_REC_LoadToolOverlay(void) { GF_OVERLAY_Load(ov188_id); }
 * void BATTLE_REC_UnloadToolOverlay(void) { GF_OVERLAY_Unload(ov188_id); }
 */
void *WIFIBATTLEMATCH_SYS_BuildSlotCommand(void *unused, int heap, char *p)
{
    char *work = GFL_HEAP_Alloc(heap, 0xf0, 0, d_02213D04, 0x6f4);
    MI_CpuFill8(work, 0, 0xf0);
    GF_OVERLAY_Load((s32)ov093_id);
    BTL_SETUP_Clear((u8 *)work);
    BTL_SETUP_InitWithSlots(work, *(void **)(p + 4), heap);
    GF_OVERLAY_Unload((s32)ov093_id);
    BATTLE_REC_LoadToolOverlay();
    BATTLE_REC_TOOL_UnpackSetup(work, heap);
    BATTLE_REC_UnloadToolOverlay();
    GF_OVERLAY_Load((s32)ov093_id);
    GFL_USE_CancelChangeAndStopBgm();
    GFL_USE_CancelChangeAndPlayBgm(*(unsigned short *)(work + 0x18), 0xffff);
    return work;
}


int WIFIBATTLEMATCH_SYS_DestroySlotCommand(char *p, char *q)
{
    GFL_USE_CancelChangeAndStopBgm();
    GFL_HEAP_Free(((struct WifiBattleMatchSysSlotCommand *)q)->buffer);
    BTL_SETUP_ClearWithSlots((struct Obj *)q);
    GFL_HEAP_Free(q);
    GF_OVERLAY_Unload((int)ov093_id);
    WIFIBATTLEMATCH_SYS_SetStep(p, 0);
    return 1;
}


void WIFIBATTLEMATCH_SYS_AllocPartyBuffers(char *p, int heap)
{
    int size;
    ((struct WifiBattleMatchSysWork *)p)->partyBuffer0 = GFL_HEAP_Alloc(heap, POKE_REGULATION_GetDataSize() + 0xd4, 0, d_02213D04, 0x72d);
    size = POKE_REGULATION_GetDataSize() + 0xd4;
    MI_CpuFill8(((struct WifiBattleMatchSysWork *)p)->partyBuffer0, 0, size);
    ((struct WifiBattleMatchSysWork *)p)->partyBuffer1 = GFL_HEAP_Alloc(heap, POKE_REGULATION_GetDataSize() + 0xd4, 0, d_02213D04, 0x72f);
    size = POKE_REGULATION_GetDataSize() + 0xd4;
    MI_CpuFill8(((struct WifiBattleMatchSysWork *)p)->partyBuffer1, 0, size);
}



/*
 * Addresses are Black-image addresses.
 */
void WIFIBATTLEMATCH_SYS_FreePartyBuffers(u8 *p)
{
    GFL_HEAP_Free((void *)(((struct WifiBattleMatchSysWork *)p)->partyBuffer0));
    GFL_HEAP_Free((void *)(((struct WifiBattleMatchSysWork *)p)->partyBuffer1));
}


void WIFIBATTLEMATCH_SYS_FillSetupRecord(u8 *p,void *party1,void *party2,u8 *save,void *reg,int setting,u8 *record,void *other,int mode)
{
    int i;
    unsigned zero = 0;
    void *mon;
    Date date;
    Triple time;
    PartyCountPair bytes;
    MI_CpuFill8(p,0,0x50);
    ((struct WifiBattleMatchSysSetupOut *)p)->card=MYSTATUS_GetProfileId((const struct MyStatus *)save);
    ((struct WifiBattleMatchSysSetupOut *)p)->savedValue=((struct WifiBattleMatchSysPartyBuffer *)save)->savedValue;
    for(i=0;i<(int)POKEPARTY_GetCount(party2);i++) {
        mon=POKEPARTY_GetMember(party2,i);
        if(POKE_TOOL_GetPartyValue(mon,0xa9,0)) {
            *(u16 *)((unsigned)p+i*2+8)=POKE_TOOL_GetPartyValue(mon,5,0);
            *(u8 *)((unsigned)p+i+0x14)=POKE_TOOL_GetPartyValue(mon,0x6f,0);
            *(u8 *)((unsigned)p+i+0x1a)=POKE_TOOL_GetPartyValue(mon,0x9e,0);
            *(u8 *)((unsigned)p+i+0x20)=POKE_TOOL_GetPartyValue(mon,0x6e,0);
        }
    }
    for(i=0;i<(int)POKEPARTY_GetCount(party1);i++) {
        mon=POKEPARTY_GetMember(party1,i);
        if(POKE_TOOL_GetPartyValue(mon,0xa9,zero)) {
            *(u16 *)((unsigned)p+i*2+0x26)=POKE_TOOL_GetPartyValue(mon,5,zero);
            *(u8 *)((unsigned)p+i+0x32)=POKE_TOOL_GetPartyValue(mon,0x6f,zero);
            *(u8 *)((unsigned)p+i+0x38)=POKE_TOOL_GetPartyValue(mon,0x9e,zero);
            *(u8 *)((unsigned)p+i+0x3e)=POKE_TOOL_GetPartyValue(mon,0x6e,zero);
        }
    }
    if(DWC_GetDateTime(&date,&time)==0) GF_PANIC_Fail(d_02213D00,0,d_02213D00);
    ((Flags *)(p + 0x44))->year=date.a;
    ((Flags *)(p + 0x44))->month=date.b;
    ((Flags *)(p + 0x44))->day=date.c;
    ((Flags *)(p + 0x44))->hour=time.a;
    ((Flags *)(p + 0x44))->minute=time.b;
    ((struct WifiBattleMatchSysSetupOut *)p)->setting=setting;
    p[0x4c]=((struct WifiBattleMatchSysSetupRecord *)record)->netSetupResult;
    WIFIBATTLEMATCH_SYS_CountBoxSpecies((struct WifiBattleMatchSysSetupRecord *)record,&bytes.a,&bytes.b);
    ((Nibbles *)(p + 0x4e))->a=bytes.a;
    ((Nibbles *)(p + 0x4e))->b=bytes.b;
    p[0x4d]=REGULATION_GetRuleValue(reg,0x15);
    ((Flags *)(p + 0x44))->enabled=REGULATION_GetRuleValue(reg,0xd);
}


void WIFIBATTLEMATCH_SYS_CountBoxSpecies(struct WifiBattleMatchSysSetupRecord *box, unsigned char *a, unsigned char *b)
{
    int i, index, j, count;
    int side, flags;
    i = 0;
    flags = box->flags;
    *a = 0;
    *b = 0;
    side = flags & 1;
    for (; i <= 1; i++) {
        if ((i & 1) == side) {
            if (side != 0)
                index = (i & 2) + 1;
            else
                index = i & 2;
            count = POKEPARTY_GetCount(box->parties[index]);
            for (j = 0; j < count; j++) {
                if (box->names[index][j] != 2)
                    (*a)++;
            }
        } else {
            if (side != 0)
                index = i & 2;
            else
                index = (i & 2) + 1;
            count = POKEPARTY_GetCount(box->parties[index]);
            for (j = 0; j < count; j++) {
                if (box->names[index][j] != 2)
                    (*b)++;
            }
        }
    }
}


void WIFIBATTLEMATCH_SYS_GetPartyCounts(const struct WifiBattleMatchSysSetupRecord *box, unsigned char *a, unsigned char *b)
{
    int i, index;
    int side, flags;
    flags = box->flags;
    *a = 0;
    *b = 0;
    side = flags & 1;
    for (i = 0; i <= 1; i++) {
        if ((i & 1) == side) {
            if (side != 0)
                index = (i & 2) + 1;
            else
                index = i & 2;
            *a = box->counts[index];
        } else {
            if (side != 0)
                index = i & 2;
            else
                index = (i & 2) + 1;
            *b = box->counts[index];
        }
    }
}


void *WIFIBATTLEMATCH_SYS_CreateProcWork(void *a, void *b, void *c, int heap)
{
    char *work = GFL_HEAP_Alloc(heap, 0x20, 0, d_02213D04, 0x846);
    MI_CpuFill8(work, 0, 0x20);
    ((struct WifiBattleMatchSysProc *)work)->proc = PROCSYS_Create(heap);
    ((struct WifiBattleMatchSysProc *)work)->cbArg = (int)c;
    ((struct WifiBattleMatchSysProc *)work)->table = a;
    ((struct WifiBattleMatchSysProc *)work)->owner = b;
    ((struct WifiBattleMatchSysProc *)work)->heap = heap;
    return work;
}


void WIFIBATTLEMATCH_SYS_DeleteProcWork(char *p)
{
    if (((struct WifiBattleMatchSysProc *)p)->result) GF_PANIC_Fail(d_02213D00, 0, d_02213D00);
    PROCSYS_Delete(((struct WifiBattleMatchSysProc *)p)->proc);
    GFL_HEAP_Free(p);
}



/*
 * lever: case 3 as if (h) { if (h(..) != 0) { f4 = 0; f1b = 4; } } else { f1b = 4; }
 * gives the lone branch to the next instruction; the case 1 second veneer
 * argument is written `f10 + 4 + (f1a << 4)` so its add follows the first load.
 */
int WIFIBATTLEMATCH_SYS_RunScreen(struct WifiBattleMatchSysProc *s)
{
    switch (s->state) {
    case 0:
        s->kind = s->stepIndex;
        s->stepIndex = s->step;
        s->state = 1;
        break;
    case 1: {
        int (*r)(struct WifiBattleMatchSysProc *, int, int);
        r = *(int (**)(struct WifiBattleMatchSysProc *, int, int))((char *)s->table + (s->stepIndex << 4) + 8);
        if (r)
            s->result = r(s, s->heap, s->cbArg);
        else
            s->result = 0;
        PROCSYS_Push((void *)s->proc,
                        *(int *)((char *)s->table + (s->stepIndex << 4)),
                        (void *)(*(int *)((char *)s->table + 4 + (s->stepIndex << 4))),
                        (void *)s->result);
        s->state = 2;
        break;
    }
    case 2:
        s->procState = PROCSYS_Main((void *)s->proc);
        if (s->procState == 0)
            s->state = 3;
        break;
    case 3: {
        int (*h)(struct WifiBattleMatchSysProc *, int, int);
        h = *(int (**)(struct WifiBattleMatchSysProc *, int, int))((char *)s->table + (s->stepIndex << 4) + 0xc);
        if (h) {
            if (h(s, s->result, s->cbArg) != 0) {
                s->result = 0;
                s->state = 4;
            }
        } else {
            s->state = 4;
        }
        break;
    }
    case 4:
        if (s->step == 0xff)
            s->state = 5;
        else
            s->state = 0;
        break;
    case 5:
        return 1;
    }
    return 0;
}


int WIFIBATTLEMATCH_SYS_GetResult(char *p)
{
    return ((struct WifiBattleMatchSysProc *)p)->procState;
}


unsigned char WIFIBATTLEMATCH_SYS_GetKind(char *p)
{
    return ((struct WifiBattleMatchSysProc *)p)->kind;
}


void WIFIBATTLEMATCH_SYS_SetStep(char *p, int value)
{
    ((struct WifiBattleMatchSysProc *)p)->step = value;
}


/*
 * extent: final two bytes are alignment padding.
 */
void WIFIBATTLEMATCH_SYS_SetStepDone(unsigned char *p){p[0x19]=255;}


int WIFIBATTLEMATCH_SYS_CreateSubWork(struct Proc *p,int unused,char *q){void *r;GFL_HEAP_CreateChildHeap(1,88,336);r=PROCSYS_AllocProcWork(p,16,88);MI_CpuFill8(r,0,16);((struct WifiBattleMatchSysSubWork *)q)->commandAdded=0;((struct WifiBattleMatchSysSubWork *)r)->proc=PROCSYS_Create(88);GFL_USE_FadeOutBgm(16);return 1;}


int WIFIBATTLEMATCH_SYS_DestroySubWork(void *a, void *b, void *c, char *work)
{
    if (((struct WifiBattleMatchSysSubWork *)work)->overlayLoaded) {
        GF_OVERLAY_Unload((int)ov093_id);
        ((struct WifiBattleMatchSysSubWork *)work)->overlayLoaded = 0;
    }
    if (((struct WifiBattleMatchSysSubWork *)work)->commandAdded) {
        GFL_NET_COMMAND_DeleteCommandTable(0x100);
        ((struct WifiBattleMatchSysSubWork *)work)->commandAdded = 0;
    }
    PROCSYS_Delete(((struct WifiBattleMatchSysSubWork *)work)->proc);
    PROCSYS_FreeProcWork(a);
    GFL_HEAP_DeleteChecked(0x58);
    return 1;
}


int WIFIBATTLEMATCH_SYS_HandleNetState(void *proc, int *seq, struct PWk *pw, struct MyWk *wk)
{
    u32 st = PROCSYS_Main(wk->procSys);

    switch (*seq) {
    case 0:
        GFL_USE_CancelChangeAndPlayBgm(*(u16 *)(pw->matchParam + 0x18), 0xffff);
        *(u32 *)(pw->battleParam + 0x44) = 1;
        PROCSYS_Push(wk->procSys, (int)ov213_id, data_021BB0B0, pw->battleParam);
        st = 2;
        *seq = 1;
        break;
    case 1:
        if (st != 1) *seq = 2;
        break;
    case 2:
        GF_OVERLAY_Load((int)ov093_id);
        wk->overlayLoaded = 1;
        GFL_NET_COMMAND_AddCommandTable(0x100, (u32)data_021F03C4, 9, 0);
        wk->commandAdded = 1;
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xc8, 0x24);
        *seq = 3;
        break;
    case 3:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xc8, 0x24)) *seq = 4;
        break;
    case 4:
        PROCSYS_Push(wk->procSys, -1, data_021EFDAC, pw->matchParam);
        st = 2;
        *seq = 5;
        break;
    case 5:
        if (st != 1) *seq = 6;
        break;
    case 6:
        *seq = 7;
        break;
    case 7:
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xd2, 0x24);
        wk->timeoutFrames = 0;
        *seq = 8;
        break;
    case 8:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xd2, 0x24)) {
            GFL_NET_COMMAND_DeleteCommandTable(0x100);
            wk->commandAdded = 0;
            GF_OVERLAY_Unload((int)ov093_id);
            wk->overlayLoaded = 0;
            *seq = 9;
        }
        if (GFL_NET_GetRunState() && *(u8 *)((u8 *)GFL_NET_GetInitParam() + 0x65) == 3) {
            if (wk->timeoutFrames++ > 600) {
                GFL_NET_COMMAND_DeleteCommandTable(0x100);
                wk->commandAdded = 0;
                GF_OVERLAY_Unload((int)ov093_id);
                wk->overlayLoaded = 0;
                *seq = 9;
                wk->timeoutFrames = 0;
            }
        }
        break;
    case 9:
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xd3, 0x24);
        *seq = 10;
        wk->timeoutFrames = 0;
        break;
    case 10:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xd3, 0x24)) *seq = 11;
        if (GFL_NET_GetRunState() && *(u8 *)((u8 *)GFL_NET_GetInitParam() + 0x65) == 3) {
            if (wk->timeoutFrames++ > 600) {
                *seq = 11;
                wk->timeoutFrames = 0;
            }
        }
        break;
    case 11: {
        int flag = 1;
        int n, a, b, i, j, k, v;
        u8 *q;
        u8 side;
        if (pw->matchParam[0x22] == 0) *(u32 *)(pw->battleParam + 0x44) = 2;
        else *(u32 *)(pw->battleParam + 0x44) = 4;
        switch (*(u32 *)(pw->matchParam + 0x8c)) {
        case 1:
        case 4:
            *(u32 *)(pw->battleParam + 0x40) = 0;
            break;
        case 0:
        case 3:
            *(u32 *)(pw->battleParam + 0x40) = 1;
            break;
        case 2:
            *(u32 *)(pw->battleParam + 0x40) = 2;
            break;
        case 6:
            wk->timeoutFrames = 0;
            flag = 0;
            *seq = 15;
            break;
        default:
            *(u32 *)(pw->battleParam + 0x40) = 2;
            break;
        }
        q = pw->matchParam;
        if (q[0x22] == 0) {
            n = 1;
            a = 0;
            b = 1;
        } else {
            n = 3;
            a = 0;
            b = 2;
        }
        side = q[0x21];
        for (i = 0; i <= n; i++) {
            if ((i & 1) == (side & 1)) {
                k = (side & 1) ? (i & 2) + 1 : (i & 2);
                for (j = 0; j < 6; j++)
                    ((struct WifiBattleMatchSysNameRow *)pw->battleParam)[a + (i >> 1)].name[j] = pw->matchParam[k * 6 + j + 0xc8];
            } else {
                k = (side & 1) ? (i & 2) : (i & 2) + 1;
                for (j = 0; j < 6; j++)
                    ((struct WifiBattleMatchSysNameRow *)pw->battleParam)[b + (i >> 1)].name[j] = pw->matchParam[k * 6 + j + 0xc8];
            }
        }
        if (flag) {
            PROCSYS_Push(wk->procSys, (int)ov213_id, data_021BB0B0, pw->battleParam);
            st = 2;
            *seq = 12;
        }
        break;
    }
    case 12:
        if (st != 1) *seq = 14;
        break;
    case 13:
        break;
    case 14:
        return 1;
    case 15:
        if (wk->timeoutFrames++ > 0x708) {
            GFL_NET_ERR_RequestScreen();
            pw->result = 2;
            return 1;
        }
        break;
    }

    if (GFL_NET_GetRunState() && st != 1) {
        if (*(u8 *)((u8 *)GFL_NET_GetInitParam() + 0x65) == 3) {
            if (GFL_NET_ERR_GetErrorLevel()) {
                GFL_NET_ERR_RequestScreen();
                pw->result = 1;
                return 1;
            }
        } else {
            switch (DWC_RAPCOMMON_HandleNetError(1, 1)) {
            case 0:
                break;
            case 1:
            case 2:
            case 3:
            default:
                pw->result = 2;
                return 1;
            case 4:
                pw->result = 3;
                return 1;
            }
        }
    }
    return 0;
}
