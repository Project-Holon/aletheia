/*
 * file:     event_ircbattle.c
 * unit:     yes
 * function: IRC_BATTLE_ENTRY_Main, IRC_BATTLE_ENTRY_Create, IRC_BATTLE_ENTRY_FreeParties, IRC_BATTLE_ENTRY_RestoreBgm, IRC_BATTLE_ENTRY_SetMode, IRC_BATTLE_ENTRY_GetGameSys, IRC_BATTLE_ENTRY_GetSaveControl
 * address:  0x02155478
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
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0200FBB0  0x0200FBB0  thumb
 *   GFL_NET_ERR_ShowSimpleScreen  0x0200F83C  thumb
 *   func_0200FA84  0x0200FA84  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   BTL_SETUP_Create  0x02013090  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   BTL_SETUP_SetupCommSingle  0x02013790  thumb
 *   BTL_SETUP_SetupCommDouble  0x020137C0  thumb
 *   BTL_SETUP_SetupCommTriple  0x02013864  thumb
 *   BTL_SETUP_SetupCommRotation  0x02013894  thumb
 *   BTL_SETUP_SetupCommMulti  0x020137F0  thumb
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   BTL_SETUP_SetParty  0x02013128  thumb
 *   BTL_SETUP_AllocRecordBuffer  0x02013980  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   BTL_SETUP_Delete  0x020130B4  thumb
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   GFL_NET_IRC_WIRELESS_Exit  0x0203D0D0  arm
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   EVENT_BATTLE_REC_SAVE_Start  0x021550A0  thumb  ov008
 *   MUSICAL_EVENT_BuildParty  0x0215518C  thumb  ov010
 *   MUSICAL_EVENT_TrimAllPartiesToThree  0x02155224  thumb  ov010
 *   MUSICAL_EVENT_UpdateFriendRecords  0x02155244  thumb  ov010
 *   MUSICAL_EVENT_BindParticipantSlots  0x02155328  thumb  ov010
 *   ov008_id       0x00000008  data
 *   ov021_id       0x00000015  data
 *   ov093_id       0x0000005D  data
 *   ov100_id       0x00000064  data
 *   ov101_id       0x00000065  data
 *   ov119_id       0x00000077  data
 *   ov195_id       0x000000C3  data
 *   d_021D3FE8     0x021D3FE8  data  ov021
 *   d_021BB6A4     0x021BB6A4  data  ov100
 *   d_021F03C4     0x021F03C4  data  ov093
 *   d_021E75D8     0x021E75D8  data  ov119
 *   d_02172700     0x02172700  data  a1
 *   d_02208C40     0x02208C40  data  ov195
 *   d_021B74AC     0x021B74AC  data  ov101
 *   d_0216FEE0     0x0216FEE0  data
 *   func_020122C0  0x020122C0  thumb
 *   GAME_EVENT_Change  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   POKEPARTY_Create  0x0201A920  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 */
#include "../arm9/btl_setup_types.h"
#include "event_ircbattle_shared_types.h"

typedef volatile u16 vu16;

/* Hardware: POWCNT1 (display power control). */
#define HW_POWER_CONTROL_REG (*(vu16 *)0x04000304)

/* ---- IR battle entry sequence ---- */

/* Argument block of the overlay that picks the party and result (work+0x08). */
typedef struct IrcBattlePickArgs {
    u32 reserved[2];        /* 0x00 */
    u32 repeatFlag;         /* 0x08: in/out, 1 = come back from the detail screen */
    u32 selection;          /* 0x0C: out */
    u32 subSelection;       /* 0x10: out */
    void *gameData;         /* 0x14 */
    u32 unused;             /* 0x18 */
    void *partyList;        /* 0x1C */
} IrcBattlePickArgs;

/* Argument block of the detail overlay (0x14 bytes, heap). */
typedef struct IrcBattleDetailArgs {
    void *gameData;         /* 0x00 */
    void *partyList;        /* 0x04 */
    u16 selection;          /* 0x08 */
    u8 reserved0A;          /* 0x0A */
    u8 subSelection;        /* 0x0B */
    u32 enabled;            /* 0x0C */
    u32 reserved10;         /* 0x10 */
} IrcBattleDetailArgs;

/* Argument block of the battle menu overlay (work+0x60). */
typedef struct IrcBattleMenuArgs {
    void *gameData;         /* 0x00 */
    void *ownParty;         /* 0x04 */
    void *linkParties[4];   /* 0x08 */
    u8 teamByNetId[4];      /* 0x18 */
    u32 mode;               /* 0x1C: in/out */
} IrcBattleMenuArgs;

/* Work of the IR battle entry event task (0xE8 bytes). */
typedef struct IrcBattleEntryWork {
    void *gameSys;                      /* 0x00 */
    void *gameData;                     /* 0x04 */
    IrcBattlePickArgs pickArgs;         /* 0x08 */
    IrcBattleDetailArgs *detailArgs;    /* 0x28 */
    u8 pad2C[0xC];
    void *ownParty;                     /* 0x38 */
    void *linkParties[4];               /* 0x3C */
    void *saveControl;                  /* 0x4C */
    u32 mode;                           /* 0x50: 1..5 battle kind, 6/7/8/12/13 menu results */
    u32 savedBgm;                       /* 0x54 */
    int partyMode;                      /* 0x58 */
    void *recorderArg;                  /* 0x5C */
    IrcBattleMenuArgs menuArgs;         /* 0x60 */
    u8 pad80[8];
    struct BattleSetupParam *setup;     /* 0x88 */
    u8 recorderSlots[0x40];             /* 0x8C */
    u32 reservedCC;                     /* 0xCC */
    u32 ruleCategory;                   /* 0xD0 */
    u32 ruleBase;                       /* 0xD4 */
    u32 ruleOffset;                     /* 0xD8 */
    u32 reservedDC;                     /* 0xDC */
    void *trainerRecord;                /* 0xE0 */
    u32 waitFrames;                     /* 0xE4 */
} IrcBattleEntryWork;

/* Event task of the IR battle entry as the event system sees it. */
typedef struct IrcBattleEventTask {
    void *gameSys;                      /* 0x00 */
    void *gameData;                     /* 0x04 */
    u8 pad08[0x30];
    void *ownParty;                     /* 0x38 */
    void *linkParties[4];               /* 0x3C */
    void *saveControl;                  /* 0x4C */
} IrcBattleEventTask;

typedef struct Tbl4 { u32 v[4]; } Tbl4;

/* Callees outside this file (named tree-wide by the integrator's rename map). */
extern void *GAMESYSTEM_GetFieldMap(void *gameSys);

extern void GAME_EVENT_CallEvent(void *parentEvent, void *childEvent);

extern void *FIELD_STATUS_CreateFieldCloseEvent(void *gameSys, void *fieldMap);

extern void GAMESYSTEM_CallProc(void *gameSys, u32 overlayId, void *procTable, void *procArg);

extern u32 GAMESYSTEM_GetProcStatus(void *gameSys);

extern void *GAMESYSTEM_GetGameData(void *gameSys);

extern int func_02034AC4(s32 overlayId);

extern void func_02034A5C(s32 overlayId);

extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);

extern struct NetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);

extern void GFL_NET_HANDLE_SetTimingSyncRange(struct NetHandle *handle, u32 timing, u32 range);

extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct NetHandle *handle, u32 timing, u32 range);

extern u32 func_0200FB24(void);

extern u32 func_0200FBB0(void);

extern void GFL_NET_ERR_ShowSimpleScreen(void);

extern void func_0200FA84(void);

extern void func_0200FBA0(void);

extern struct BattleSetupParam *BTL_SETUP_Create(u32 heapId);

extern void *GAME_DATA_GetTrainerRecord(void *gameData);

extern void BTL_SETUP_SetupCommSingle(struct BattleSetupParam *setup, void *gameData, struct NetHandle *handle, u32 a, u16 heapId);

extern void BTL_SETUP_SetupCommDouble(struct BattleSetupParam *setup, void *gameData, struct NetHandle *handle, u32 a, u16 heapId);

extern void BTL_SETUP_SetupCommTriple(struct BattleSetupParam *setup, void *gameData, struct NetHandle *handle, u32 a, u16 heapId);

extern void BTL_SETUP_SetupCommRotation(struct BattleSetupParam *setup, void *gameData, struct NetHandle *handle, u32 a, u16 heapId);

extern void BTL_SETUP_SetupCommMulti(struct BattleSetupParam *setup, void *gameData, struct NetHandle *handle, u32 a, u8 team, u16 heapId);

extern u32 GFL_NET_GetHandleNetID(struct NetHandle *handle);

extern void BTL_SETUP_SetParty(struct BattleSetupParam *setup, void *party, int index);

extern void BTL_SETUP_AllocRecordBuffer(struct BattleSetupParam *setup, u32 flag);

extern u16 GFL_USE_GetBgmNo(void);

extern void GFL_USE_CancelChangeAndStopBgm(void);

extern void GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u16 fadeFrames);

extern int BTL_SETUP_Delete(struct BattleSetupParam *setup);

extern u32 GFL_NET_IsParentAid(void);

extern struct GameEvent *GAME_EVENT_CreateOverlayEvent(void *gameSys, u32 overlayId, void *proc, void *procArg);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);

extern u32 func_020307B0(void *ptr);

extern int GFL_NET_GetRunState(void);

extern int GFL_NET_Exit(int a0);

extern void *FIELD_STATUS_CreateFieldOpenEvent(void *gameSys);

extern void GFL_NET_IRC_WIRELESS_Exit(void);

extern void *EVENT_FIELDMAP_CONTROL_StartFadeOut(void *gameSys, void *fieldMap, int sel, int d);

extern void *EVENT_FIELDMAP_CONTROL_StartFadeIn(void *gameSys, void *fieldMap, int sel, int d, int e, u8 f, u8 g);

extern void *EVENT_BATTLE_REC_SAVE_Start(void *a, const int *p);

extern void MUSICAL_EVENT_BuildParty(int mode, IrcBattleEntryWork *work);

extern void MUSICAL_EVENT_TrimAllPartiesToThree(IrcBattleEntryWork *work);

extern void MUSICAL_EVENT_UpdateFriendRecords(IrcBattleEntryWork *work, void *gameData);

extern void MUSICAL_EVENT_BindParticipantSlots(IrcBattleEntryWork *work, void *gameSys);

extern struct GameEvent *func_020122C0(void *gameSys, void *a, void *proc, u32 size);

extern void GAME_EVENT_Change(void *event, void *proc, u32 size);

extern void *func_020124E8(struct GameEvent *event);

extern void *GAME_DATA_GetSaveControl(void *gameData);

extern void *POKEPARTY_Create(u32 heapId);

extern void GFL_USE_FadeInBgmFull(u32 frames);

/* Overlay ids (absolute linker symbols) and data of other overlays. */
extern u8 ov008_id[];

extern u8 ov021_id[];

extern u8 ov093_id[];

extern u8 ov100_id[];

extern u8 ov101_id[];

extern u8 ov119_id[];

extern u8 ov195_id[];

extern u8 d_021D3FE8[];

extern u8 d_021BB6A4[];

extern u8 d_021F03C4[];

extern u8 d_021E75D8[];

extern u8 d_02208C40[];

extern u8 d_021B74AC[];

/* Data of this overlay. */
extern const char d_02172700[];

extern const Tbl4 d_0216FEE0;

/* Functions of this file. */
int IRC_BATTLE_ENTRY_Main(void *parentEvent, int *step, IrcBattleEntryWork *work);

struct GameEvent *IRC_BATTLE_ENTRY_Create(void *gameSys, int unused, struct GameEvent *event, int create);

void IRC_BATTLE_ENTRY_FreeParties(IrcBattleEntryWork *work);

void IRC_BATTLE_ENTRY_RestoreBgm(IrcBattleEntryWork *work);

void IRC_BATTLE_ENTRY_SetMode(IrcBattleEntryWork *work, u32 mode);

void *IRC_BATTLE_ENTRY_GetGameSys(IrcBattleEntryWork *work);

void *IRC_BATTLE_ENTRY_GetSaveControl(IrcBattleEntryWork *work);

/*
 * The IR battle entry sequence: a 28-state machine over *step that loads the
 * sub-overlays (21, 100, 119, 195, 101, 8, 93) as child procs, sets up the
 * party/slot records through MUSICAL_EVENT_BuildParty/MUSICAL_EVENT_BindParticipantSlots/MUSICAL_EVENT_UpdateFriendRecords,
 * runs the fade and wireless-sync waits, and tears everything down in
 * states 21 to 23.
 *
 * Shape levers that closed it (they also settled the work/step register
 * swap): case 18 writes the waitFrames = 0 / (*step)++ tail in both arms;
 * case 19 writes (*step)++ in both arms; state 10 writes the
 * GFL_USE_CancelChangeAndPlayBgm call in each arm.
 */
int IRC_BATTLE_ENTRY_Main(void *parentEvent, int *step, IrcBattleEntryWork *work)
{
    Tbl4 ruleTable;
    BattleRecSaveArgs recArgs;
    void *gameSys;
    void *fieldMap;
    IrcBattleDetailArgs *detail;

    gameSys = work->gameSys;
    fieldMap = GAMESYSTEM_GetFieldMap(gameSys);
    switch (*step) {
    case 0:
        GAME_EVENT_CallEvent(parentEvent, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSys, fieldMap, 0, 0));
        (*step)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(parentEvent, FIELD_STATUS_CreateFieldCloseEvent(gameSys, fieldMap));
        *step = 2;
        break;
    case 2:
        GAMESYSTEM_CallProc(gameSys, (u32)ov021_id, d_021D3FE8, work);
        (*step)++;
        break;
    case 3:
        if (GAMESYSTEM_GetProcStatus(gameSys) == 0) {
            if (work->mode == 8) {
                *step = 24;
            } else if (work->mode == 12) {
                *step = 21;
            } else {
                (*step)++;
            }
        }
        break;
    case 4:
        (*step)++;
        break;
    case 5:
        MUSICAL_EVENT_BuildParty(work->partyMode, work);
        work->menuArgs.gameData = work->gameData;
        work->menuArgs.ownParty = work->ownParty;
        work->menuArgs.linkParties[0] = work->linkParties[0];
        work->menuArgs.linkParties[1] = work->linkParties[1];
        work->menuArgs.linkParties[2] = work->linkParties[2];
        work->menuArgs.linkParties[3] = work->linkParties[3];
        work->menuArgs.mode = work->mode;
        GAMESYSTEM_CallProc(gameSys, (u32)ov100_id, d_021BB6A4, &work->menuArgs);
        (*step)++;
        break;
    case 6:
        if (GAMESYSTEM_GetProcStatus(gameSys) == 0) {
            work->mode = work->menuArgs.mode;
            switch (work->mode) {
            case 7:
                *step = 20;
                break;
            case 12:
                *step = 20;
                break;
            case 13:
                *step = 2;
                break;
            case 6:
                work->pickArgs.repeatFlag = 0;
                *step = 13;
                break;
            default:
                *step = 7;
                break;
            }
        }
        break;
    case 7:
        func_02034AC4((u32)ov093_id);
        GFL_NET_COMMAND_AddCommandTable(0x100, (u32)d_021F03C4, 9, 0);
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x6e, 12);
        (*step)++;
        break;
    case 8:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x6e, 12))
            (*step)++;
        if (func_0200FB24()) {
            if (func_0200FBB0() == 1)
                GFL_NET_ERR_ShowSimpleScreen();
            else
                func_0200FA84();
            func_02034A5C((u32)ov093_id);
            *step = 20;
        }
        break;
    case 9:
        work->setup = BTL_SETUP_Create(4);
        work->trainerRecord = GAME_DATA_GetTrainerRecord(work->gameData);
        work->ruleOffset = 0;
        switch (work->mode) {
        case 0:
            break;
        case 1:
            work->ruleCategory = 1;
            work->ruleBase = 2;
            BTL_SETUP_SetupCommSingle(work->setup, work->gameData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
            break;
        case 2:
            work->ruleCategory = 1;
            work->ruleBase = 6;
            BTL_SETUP_SetupCommDouble(work->setup, work->gameData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
            break;
        case 3:
            work->ruleCategory = 1;
            work->ruleBase = 10;
            BTL_SETUP_SetupCommTriple(work->setup, work->gameData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
            break;
        case 4:
            work->ruleCategory = 1;
            work->ruleBase = 14;
            BTL_SETUP_SetupCommRotation(work->setup, work->gameData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
            break;
        case 5:
            ruleTable = d_0216FEE0;
            work->ruleCategory = 3;
            work->ruleBase = 18;
            BTL_SETUP_SetupCommMulti(work->setup, work->gameData, GFL_NET_HANDLE_GetCurrentHandle(), 1,
                          ruleTable.v[work->menuArgs.teamByNetId[GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())]], 4);
            work->setup->multiMode = 1;
            work->setup->rule = 1;
            MUSICAL_EVENT_TrimAllPartiesToThree(work);
            break;
        }
        BTL_SETUP_SetParty(work->setup, work->ownParty, 0);
        BTL_SETUP_AllocRecordBuffer(work->setup, 1);
        work->savedBgm = GFL_USE_GetBgmNo();
        GFL_USE_CancelChangeAndStopBgm();
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 10, 12);
        (*step)++;
        break;
    case 10:
        if (func_0200FB24()) {
            BTL_SETUP_Delete(work->setup);
            work->setup = 0;
            if (func_0200FBB0() == 1)
                GFL_NET_ERR_ShowSimpleScreen();
            else
                func_0200FA84();
            func_02034A5C((u32)ov093_id);
            *step = 20;
        } else if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 10, 12)) {
            if (GFL_NET_IsParentAid())
                GFL_USE_CancelChangeAndPlayBgm(0x48B, 0xFFFF);
            else
                GFL_USE_CancelChangeAndPlayBgm(0x48C, 0xFFFF);
            (*step)++;
        }
        break;
    case 11:
        MUSICAL_EVENT_BindParticipantSlots(work, gameSys);
        func_02034A5C((u32)ov093_id);
        recArgs.setup = work->setup;
        recArgs.slotData = work->recorderSlots;
        recArgs.flag = 1;
        GAME_EVENT_CallEvent(parentEvent, GAME_EVENT_CreateOverlayEvent(gameSys, (u32)ov008_id, EVENT_BATTLE_REC_SAVE_Start, &recArgs));
        (*step)++;
        break;
    case 12:
        if (GAMESYSTEM_GetProcStatus(gameSys) == 0) {
            MUSICAL_EVENT_UpdateFriendRecords(work, GAMESYSTEM_GetGameData(gameSys));
            BTL_SETUP_Delete(work->setup);
            work->setup = 0;
            GFL_USE_CancelChangeAndStopBgm();
            IRC_BATTLE_ENTRY_RestoreBgm(work);
            *step = 17;
        }
        break;
    case 13:
        work->pickArgs.gameData = work->gameData;
        work->pickArgs.partyList = work->ownParty;
        GAMESYSTEM_CallProc(gameSys, (u32)ov119_id, d_021E75D8, &work->pickArgs);
        (*step)++;
        break;
    case 14:
        if (GAMESYSTEM_GetProcStatus(gameSys) == 0) {
            if (work->pickArgs.repeatFlag == 1)
                *step = 15;
            else
                *step = 17;
        }
        break;
    case 15:
        detail = func_02030734(4, 0x14, 0, d_02172700, 0x219);
        detail->gameData = work->gameData;
        detail->partyList = work->pickArgs.partyList;
        detail->selection = work->pickArgs.selection;
        detail->reserved0A = 0;
        detail->subSelection = work->pickArgs.subSelection;
        detail->enabled = 1;
        detail->reserved10 = 0;
        work->detailArgs = detail;
        GAMESYSTEM_CallProc(gameSys, (u32)ov195_id, d_02208C40, detail);
        (*step)++;
        break;
    case 16:
        if (GAMESYSTEM_GetProcStatus(gameSys) == 0) {
            func_020307B0(work->detailArgs);
            work->pickArgs.repeatFlag = 1;
            *step = 13;
        }
        break;
    case 17:
        if (GFL_NET_GetRunState() && func_0200FB24() == 0)
            GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0xdc, 12);
        (*step)++;
        break;
    case 18:
        if (GFL_NET_GetRunState() && func_0200FB24() == 0) {
            if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0xdc, 12) == 0)
                break;
            work->waitFrames = 0;
            (*step)++;
        } else {
            work->waitFrames = 0;
            (*step)++;
        }
        break;
    case 19:
        if (GFL_NET_GetRunState()) {
            work->waitFrames++;
            if (work->waitFrames < 60)
                break;
            GFL_NET_Exit(0);
            (*step)++;
        } else {
            (*step)++;
        }
        break;
    case 20:
        if (GFL_NET_GetRunState() == 0) {
            func_0200FBA0();
            *step = 21;
        }
        break;
    case 21:
        IRC_BATTLE_ENTRY_RestoreBgm(work);
        GAME_EVENT_CallEvent(parentEvent, FIELD_STATUS_CreateFieldOpenEvent(gameSys));
        (*step)++;
        break;
    case 22:
        GAME_EVENT_CallEvent(parentEvent, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSys, fieldMap, 0, 0, 1, 0, 0));
        (*step)++;
        break;
    case 23:
        GFL_NET_IRC_WIRELESS_Exit();
        IRC_BATTLE_ENTRY_FreeParties(work);
        return 1;
    case 24:
        (*step)++;
        break;
    case 25:
        (*step)++;
        break;
    case 26:
        work->recorderArg = work->gameSys;
        GAMESYSTEM_CallProc(gameSys, (u32)ov101_id, d_021B74AC, &work->recorderArg);
        (*step)++;
        break;
    case 27:
        if (GAMESYSTEM_GetProcStatus(gameSys) == 0) {
            HW_POWER_CONTROL_REG |= 0x8000;
            *step = 20;
        }
        break;
    }
    return 0;
}

/*
 * Creates (create != 0) or retargets the IR battle entry event and fills
 * its work: the five party lists are allocated here and freed by
 * IRC_BATTLE_ENTRY_FreeParties.
 */
struct GameEvent *IRC_BATTLE_ENTRY_Create(void *gameSys, int unused, struct GameEvent *event, int create)
{
    IrcBattleEventTask *task;
    int i;

    if (create != 0)
        event = func_020122C0(gameSys, 0, IRC_BATTLE_ENTRY_Main, 0xE8);
    else
        GAME_EVENT_Change(event, IRC_BATTLE_ENTRY_Main, 0xE8);
    task = func_020124E8(event);
    task->saveControl = GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSys));
    task->gameData = GAMESYSTEM_GetGameData(gameSys);
    task->gameSys = gameSys;
    for (i = 0; i < 4; i++)
        task->linkParties[i] = POKEPARTY_Create(4);
    task->ownParty = POKEPARTY_Create(4);
    return event;
}

/*
 * Frees the four link party lists and then the own party list.
 */
void IRC_BATTLE_ENTRY_FreeParties(IrcBattleEntryWork *work)
{
    int i;

    for (i = 0; i < 4; i++)
        func_020307B0(work->linkParties[i]);
    func_020307B0(work->ownParty);
}

/*
 * Stops the saved BGM (if any) and clears it.
 */
void IRC_BATTLE_ENTRY_RestoreBgm(IrcBattleEntryWork *work)
{
    if (work->savedBgm != 0) {
        GFL_USE_CancelChangeAndPlayBgm(work->savedBgm, 0xFFFF);
        GFL_USE_FadeInBgmFull(0x3c);
        work->savedBgm = 0;
    }
}

/*
 * Stores the mode word.
 */
void IRC_BATTLE_ENTRY_SetMode(IrcBattleEntryWork *work, u32 mode)
{
    work->mode = mode;
}

/*
 * Reads the game system pointer.
 */
void *IRC_BATTLE_ENTRY_GetGameSys(IrcBattleEntryWork *work)
{
    return work->gameSys;
}

/*
 * Reads the save control pointer.
 */
void *IRC_BATTLE_ENTRY_GetSaveControl(IrcBattleEntryWork *work)
{
    return work->saveControl;
}
