/*
 * file:     event_wificlub.c
 * unit:     yes
 * function: EVENT_WIFICLUB_SetupBattle, EVENT_WIFICLUB_BuildBattleEntry, EVENT_WIFICLUB_SetBattleParty, EVENT_WIFICLUB_ResetSound, EVENT_WIFICLUB_Main, EVENT_WIFICLUB_FreeWork, EVENT_WIFICLUB_InitWork, EVENT_WIFICLUB_Create, EVENT_WIFICLUB_Entry
 * address:  0x021542C0
 * region:   ov006
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 *   ov115_id 0x73 data a1
 *   ov099_id 0x63 data a1
 *   ov067_id 0x43 data a1
 *   ov127_id 0x7f data a1
 *   ov134_id 0x86 data a1
 *   ov093_id 0x5d data a1
 *   ov008_id 0x8 data a1
 *   ov119_id 0x77 data a1
 *   ov195_id 0xc3 data a1
 *   ov172_id 0xac data a1
 *   GFL_USE_SetSleepVolumeHooks  0x020057AC  thumb  arm9
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb  arm9
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb  arm9
 *   PM_VOICE_ResetMasterVolume  0x02006740  thumb  arm9
 *   GFL_NET_ERR_ShowScreen  0x0200F7B8  thumb  arm9
 *   GFL_NET_ERR_ShowSimpleScreen  0x0200F83C  thumb  arm9
 * Callback adapter: unpacks a two-word argument block and tail-calls
 * EVENT_WIFICLUB_Create (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Region
 * ov006: the only overlay mapped at this address; Thumb code directly after
 * the pool word of EVENT_WIFICLUB_Create, which is also its tail-call target.
 * ov021 SCRCMD_PROC_FLD_CallOv006Event passes it as a function pointer together with the block
 * {GAMESYSTEM_GetFieldMap(..), 0} (wave A1 witness).
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   REGULATION_SetRuleValue  0x0200AEE8  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   BTL_SETUP_SetupCommSingle  0x02013790  thumb
 *   BTL_SETUP_SetupCommDouble  0x020137C0  thumb
 *   BTL_SETUP_SetupCommTriple  0x02013864  thumb
 *   BTL_SETUP_SetupCommRotation  0x02013894  thumb
 *   BTL_SETUP_AllocRecordBuffer  0x02013980  thumb
 *   BTL_SETUP_ApplyRegulation  0x02013160  thumb
 *   POKE_REGULATION_AdjustPartyLevels  0x0201A2A8  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GAME_DATA_GetMyStatusPlayer 0x02012950 thumb
 *   MYSTATUS_GetName 0x020084F4 thumb
 *   MYSTATUS_GetSex 0x02008550 thumb
 *   POKEPARTY_Init 0x0201A948 thumb
 *   BTL_SETUP_SetParty 0x02013128 thumb
 *   GFL_USE_SetPlayerVolumes 0x02005CBC thumb
 *   PM_VOICE_SetMasterVolume 0x02006734 thumb
 *   GAMESYSTEM_GetGameComm 0x02012138 thumb
 *   GAME_COMM_GetKind 0x02026454 thumb
 *   FIELD_STATUS_CreateFieldCloseEvent 0x020144DC thumb
 *   GAME_EVENT_CallEvent 0x02012374 thumb
 *   RINGTONE_SYS_RegisterSleepCallbacks 0x02029F6C thumb
 *   FIELD_STATUS_CreateFieldOpenEvent 0x020145CC thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   BTL_SETUP_Delete 0x020130B4 thumb
 *   BTL_SETUP_Create 0x02013090 thumb
 *   GAME_EVENT_CallProc 0x02012444 thumb
 *   GAME_DATA_GetMyStatusPlayer 0x02012950 thumb
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Push 0x02031348 arm
 *   PROCSYS_Main 0x02031330 arm
 *   PROCSYS_Delete 0x0203133C arm
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_IsIdle 0x0203D210 arm
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn 0x021BE92C thumb ov021
 *   WIFICLUB_RunPeerAddrRoutine 0x021C2850 thumb ov099
 *   gNetSaveMainProc 0x021D6338 data ov115 a4
 *   gNetSaveRetryProc 0x021D654C data ov115 a4
 *   d_021C37E8 0x021C37E8 data ov099 a4
 *   d_02154C40 0x02154C40 data ov006 a2
 *   d_021DCCA4 0x021DCCA4 data ov134 a4
 *   d_021F03C4 0x021F03C4 data ov093 a4
 *   d_02154C2C 0x02154C2C data ov006 a1
 *   d_0215513C 0x0215513C data ov008 a4
 *   d_021E75C0 0x021E75C0 data ov119 a4
 *   d_02154C80 0x02154C80 data ov006 a4
 *   d_02208C40 0x02208C40 data ov195 a4
 *   d_021C7240 0x021C7240 data ov172 a4
 *   GAME_EVENT_GetWork   0x020124E8  thumb
 *   GAME_COMM_RequestExitNoCallback   0x02026400  thumb
 *   POKEPARTY_Create   0x0201A920  thumb
 *   GAME_DATA_GetSaveControl   0x02012EBC  thumb
 *   GFL_USE_GetBgmNo   0x02005C44  thumb
 *   REGULATION_Create   0x0200ADF0  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GFL_USE_SetSleepVolumeHooks  0x020057AC  thumb  arm9
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb  arm9
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb  arm9
 *   PM_VOICE_ResetMasterVolume  0x02006740  thumb  arm9
 *   GFL_NET_ERR_ShowScreen  0x0200F7B8  thumb  arm9
 *   GFL_NET_ERR_ShowSimpleScreen  0x0200F83C  thumb  arm9
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb  arm9
 *   GFL_NET_ERR_WaitLinkClosed  0x0200FBB0  thumb  arm9
 *   WIFILIST_CountFriends  0x02009A34  thumb  arm9
 *   WIFILIST_AddFriendBattleRecord  0x02009BB8  thumb  arm9
 */
#include "event_wificlub_types.h"

struct Reg;
struct BattleSetup;
struct PlayerStatusList;
struct Link;
struct TrainerRecordInfo;
struct PlayerStatusRecord;
struct NetTask;
struct BoxRecord;
struct GameComm;
struct Party;
/* View of the battle setup block: only the trainer record pointer at +0x6C is written here. */
typedef struct BattleSetupView {
    u8 reserved[0x6C];
    void *trainerRecord;
} BattleSetupView;

/* Entry of the menu transition table: the menu result picks the next sequence step. */
typedef struct MenuTransition {
    u8 selection;
    u8 reserved;
    u16 nextSeq;
} MenuTransition;

/* Order in which the two sides are written when this machine is the child. */
typedef struct SideOrder {
    u8 first, second;
} SideOrder;

typedef struct Pair {
    int a;
    int b;
} Pair;

#include "../arm9/gamesystem.h"
struct Regulation;
#include "../arm9/regulation.h"
struct GFLNetHandle;
#include "../arm9/net_handle.h"
struct BattleSetupParam;
#include "../arm9/btl_setup.h"
struct Regulation;
#include "../arm9/poke_regulation.h"
#include "../arm9/game_data.h"
#include "../arm9/net.h"
struct MyStatus;
#include "../arm9/mystatus.h"
#include "../arm9/pokeparty.h"
#include "../arm9/gfl_use.h"
#include "../arm9/pm_voice.h"
#include "../arm9/game_comm.h"
struct FieldMap;
struct GameEvent;
#include "../arm9/field_status.h"
#include "../arm9/game_event.h"
#include "../arm9/ringtone_sys.h"
#include "../ov021/event_fieldmap_control.h"
#include "../arm9/mi_memory.h"
#include "../arm9/procsys.h"
struct ProcData;
#include "../arm9/net_err.h"
struct FieldState;
struct WifiList;
#include "../arm9/wifilist.h"
#include "../arm9/gf_overlay.h"
struct WifiClubPlayerStatus;
#include "../ov099/wifi_club.h"
#include "../arm9/net_command.h"
#include "../arm9/gfl_heap_wrap.h"
struct SaveControl;
void EVENT_WIFICLUB_SetupBattle(WifiClubEventWork *work, int menuIndex);
void EVENT_WIFICLUB_BuildBattleEntry(WifiClubEventWork *work, void *gameData, int seq);
void EVENT_WIFICLUB_SetBattleParty(WifiClubEventWork *work, void *gameData, int seq);
void EVENT_WIFICLUB_ResetSound(WifiClubEventWork *work);
int EVENT_WIFICLUB_Main(struct GameEvent *event, u32 *seq, WifiClubEventWork *work);
void EVENT_WIFICLUB_FreeWork(WifiClubEventWork *work);
void EVENT_WIFICLUB_InitWork(void *event, void *gameSystem, int fieldMap, int hideFieldObjects);
int EVENT_WIFICLUB_Create(int gameSystem, int fieldMap, int hideFieldObjects);
int EVENT_WIFICLUB_Entry(int gameSystem, Pair *request);
extern const char gNetSaveMainProc[],gNetSaveRetryProc[],d_021DCCA4[],d_021F03C4[],d_021C37E8[];
extern const char d_0215513C[],d_021E75C0[],d_02154C80[],d_02208C40[],d_021C7240[];
extern char ov008_id[],ov067_id[],ov127_id[],ov115_id[],ov099_id[];
extern char ov134_id[],ov093_id[],ov119_id[],ov195_id[],ov172_id[];
extern const SideOrder d_02154C2C;
extern const MenuTransition d_02154C40[];
extern const char d_02154C80[];



void EVENT_WIFICLUB_SetupBattle(WifiClubEventWork *work, int menuIndex)
{
    struct GameData *gameData;
    u8 useAltRule;
    int battleKind;

    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    useAltRule = work->session->useAltRule;
    if (useAltRule)
        REGULATION_SetRuleValue(work->session->regulation, 0xd, 1);
    else
        REGULATION_SetRuleValue(work->session->regulation, 0xd, 0);

    switch (menuIndex) {
    case 8:
        battleKind = 1;
        if (useAltRule)
            battleKind = 3;
        break;
    case 7:
        battleKind = 0;
        if (useAltRule)
            battleKind = 2;
        break;
    case 10:
        battleKind = 5;
        if (useAltRule)
            battleKind = 7;
        break;
    case 9:
        battleKind = 4;
        if (useAltRule)
            battleKind = 6;
        break;
    case 12:
        battleKind = 9;
        if (useAltRule)
            battleKind = 0xb;
        break;
    case 11:
        battleKind = 8;
        if (useAltRule)
            battleKind = 0xa;
        break;
    case 14:
        battleKind = 0xd;
        if (useAltRule)
            battleKind = 0xf;
        break;
    case 13:
        battleKind = 0xc;
        if (useAltRule)
            battleKind = 0xe;
        break;
    }
    work->startParam.battleKind = battleKind;
    work->startParam.reserved = 0;

    switch (menuIndex) {
    case 7:
    case 8:
        BTL_SETUP_SetupCommSingle(work->battleSetup, gameData, (uptr)GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 9:
    case 10:
        BTL_SETUP_SetupCommDouble(work->battleSetup, gameData, (uptr)GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 11:
    case 12:
        BTL_SETUP_SetupCommTriple(work->battleSetup, gameData, (uptr)GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 13:
    case 14:
        BTL_SETUP_SetupCommRotation(work->battleSetup, gameData, (uptr)GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    }
    BTL_SETUP_AllocRecordBuffer(work->battleSetup, 1);
    BTL_SETUP_ApplyRegulation(work->battleSetup, work->session->regulation, 4);
    POKE_REGULATION_AdjustPartyLevels(work->session->regulation, work->session->party[0]);
    POKE_REGULATION_AdjustPartyLevels(work->session->regulation, work->session->party[1]);
    ((BattleSetupView *)work->battleSetup)->trainerRecord = GAME_DATA_GetTrainerRecord(GAMESYSTEM_GetGameData(work->gameSystem));
}



/*
 * size: 136
 *
 * The lead is 110 bytes, followed by two padding bytes and the 24-byte
 * EVENT_WIFICLUB_SetBattleParty thunk. function_starts: 0x021544BC.
 * MYSTATUS_GetName is the bx-lr identity: the original retains the pointer
 * returned by GAME_DATA_GetMyStatusPlayer in r0 across two loads, passes it to the
 * identity, and stores the unchanged result. Its prior (void) extern
 * dropped the live input and caused an 18-byte scheduling residue.
 * GFL_NET_GetHandleNetID explicitly returns only eight bits; the caller consumes
 * those bits without truncation. Indexed record reads retain modular
 * unsigned address arithmetic without assuming an index domain.
 */
void EVENT_WIFICLUB_BuildBattleEntry(WifiClubEventWork *work, void *gameData, int seq)
{
    int selfSide, partnerSide;
    void *partnerRecord;
    ClubBattleEntry *entry;
    WifiClubEventSession *session;

    selfSide = GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle());
    partnerSide = 1 - selfSide;
    partnerRecord = GAME_DATA_GetMyStatusPlayer(gameData, partnerSide);
    work->battleEntry.regulation = work->session->regulation;
    entry = &work->battleEntry;
    entry->ownParty = *(void **)((uptr)work->session + 0x14 + 4 * (unsigned int)selfSide);
    entry->partnerInfo = (void *)MYSTATUS_GetName(partnerRecord);
    entry->partnerGender = MYSTATUS_GetSex(partnerRecord);
    entry->partnerParty = *(void **)((uptr)work->session + 0x14 + 4 * (unsigned int)partnerSide);
    entry->gameData = gameData;
    entry->reserved18 = 0;
    POKEPARTY_Init(work->battleParty);
    entry->battleParty = work->battleParty;
    entry->partyA = work->session->party[0];
    entry->partyB = work->session->party[1];
}



void EVENT_WIFICLUB_SetBattleParty(WifiClubEventWork *work, void *gameData, int seq)
{
    BTL_SETUP_SetParty(work->battleSetup, work->battleParty, 0);
}



/*
 * Extent ends with two bytes of alignment padding at 0x021544EE.
 * Error exit: puts the sound volume back and flags the session as failed.
 */
void EVENT_WIFICLUB_ResetSound(WifiClubEventWork *work)
{
    GFL_USE_SetPlayerVolumes(127, 63);
    PM_VOICE_SetMasterVolume(127);
    work->login.useSaveData = 1;
}




/*
 * blockers: code-start witnesses for ov006 EVENT_WIFICLUB_SetBattleParty and ov099
 * WIFICLUB_RunPeerAddrRoutine; overlay-ID consumer evidence for GAME_EVENT_CallProc:r1
 * (IDs 127,134,8,119,195,172). All concrete bytes match.
 * Matching levers: typed Sel table folds the u16 field offset into its
 * pool word; Pair struct copies to SP; char-pointer field addressing
 * avoids loop spills; repeated cleanup tails preserve cross-jumped hops.
 * checks: 1 callees and PC-relative IDs rederived; 2 no matching twin;
 * 3 const 02031330 and unsigned counter worsened; 4 repeated cleanup
 * tails closed branch residue; 5 idioms relisted and neighbours reread.
 * TU --suggest-split: one section, no viable cut; tool consumer correction
 * needed before filing the two overlay leaves. No ARM9 blocker remains.
 * Prototype evidence: 02031324 and 02031348 forward all registers to
 * 02031354(int) and 020314F4(obj,u32,u32,u32); 0200F7B8 receives the
 * explicitly loaded zero despite its legacy void declaration.
 * 2026-10-04 note (wave D2 lane 15): still MATCH, bytes identical. Unresolved after re-run:
 * THM_CALL WIFICLUB_RunPeerAddrRoutine (ov099 hint present, but 021C2850 is a Thumb veneer in ov099, 64 bytes
 * incl. data, no matched witness exists) and six single-use overlay-id words (ov008 0x8,
 * ov119 0x77, ov127 0x7f, ov134 0x86, ov172 0xac, ov195 0xc3) with no witness outside this
 * function. Nothing left to change in the C.
 * 2026-10-05 note (D4-14): re-run, still MATCH (1484 bytes, 111 of 112 relocations resolve; the open one is WIFICLUB_RunPeerAddrRoutine, a Thumb veneer in ov099). No change possible in C.
 */
int EVENT_WIFICLUB_Main(struct GameEvent *event, u32 *seq, WifiClubEventWork *work)
{
    struct GameSystem *gameSystem;
    u32 step;
    int i, offset;
    SideOrder order;
    EvolutionRequest *request;
    WifiClubEventSession *session;

    gameSystem = work->gameSystem;
    step = *seq;
    switch (step) {
    case 0:
        work->savedBgmNo = GFL_USE_GetBgmNo();
        GFL_USE_FadeOutBgm(6);
        ++*seq;
        break;
    case 1:
        if (!GAME_COMM_GetKind(GAMESYSTEM_GetGameComm(gameSystem))) {
            work->reserved10 = 0;
            GAME_EVENT_CallEvent(event, (void *)FIELD_STATUS_CreateFieldCloseEvent((struct GameSystem *)gameSystem, (struct FieldMap *)work->fieldMap));
            ++*seq;
        }
        break;
    case 2:
        GFL_USE_SetSleepVolumeHooks();
        *seq = 8;
        break;
    case 3: break;
    case 4:
        if (GFL_NET_IsSessionNull()) {
            ++*seq;
            EVENT_WIFICLUB_FreeWork(work);
            PM_VOICE_ResetMasterVolume();
            GFL_USE_CancelChangeAndPlayBgm(work->savedBgmNo, 0xffff);
            GFL_USE_FadeInBgmFull(60);
        }
        break;
    case 5:
        RINGTONE_SYS_RegisterSleepCallbacks();
        GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        ++*seq;
        break;
    case 6:
        if (work->hideFieldObjects)
            GAME_EVENT_CallEvent(event, (void *)EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, (struct FieldMap *)work->fieldMap, 0, 0, 1, 0, 0));
        ++*seq;
        break;
    case 7: return 1;
    case 8:
        MI_CpuFill8(&work->login, 0, 0x28);
        *seq = 9;
        work->login.useSaveData = 0;
        break;
    case 9:
        work->login.gameData = GAMESYSTEM_GetGameData(gameSystem);
        work->login.loginOption = 1;
        work->login.loginType = 0;
        work->login.messageId = 10;
        work->login.allowCancel = 1;
        GFL_USE_CancelChangeAndPlayBgm(0x481, 0xffff);
        work->loginTask = PROCSYS_Create(4);
        PROCSYS_Push(work->loginTask, (uptr)ov115_id, (const struct ProcData *)gNetSaveMainProc, &work->login);
        work->session->menuChoice = 0;
        *seq = 10;
        break;
    case 10:
        if (PROCSYS_Main(work->loginTask)) { GFL_NET_ERR_ShowScreen(0); return 0; }
        PROCSYS_Delete(work->loginTask);
        if (!work->login.result) {
            if (!WIFILIST_CountFriends((void *)GAME_DATA_GetWifiList(work->paramGameData))) *seq = 30;
            else { *seq = 11; GFL_USE_FadeOutBgm(6); }
        } else { GFL_USE_FadeOutBgm(6); *seq = 25; }
        break;
    case 30:
        work->confirm.gameData = GAMESYSTEM_GetGameData(gameSystem);
        work->confirm.loginOption = 1;
        work->confirm.loginType = 0;
        work->confirm.messageId = 1;
        work->confirm.saveData = 0;
        work->confirm.useSaveData = 0;
        work->confirm.allowCancel = 0;
        work->loginTask = PROCSYS_Create(4);
        PROCSYS_Push(work->loginTask, (uptr)ov115_id, (const struct ProcData *)gNetSaveRetryProc, &work->confirm);
        ++*seq;
        break;
    case 31:
        if (PROCSYS_Main(work->loginTask)) { GFL_NET_ERR_ShowScreen(0); return 0; }
        PROCSYS_Delete(work->loginTask);
        GFL_USE_FadeOutBgm(6);
        *seq = 4;
        break;
    case 11:
        GF_OVERLAY_Load((sptr)ov099_id);
        GF_OVERLAY_Load((sptr)ov067_id);
        WIFICLUB_RunPeerAddrRoutine((struct WifiClubPlayerStatus *)work->session->scratchBuffer);
        if (work->battleSetup) { BTL_SETUP_Delete((struct BattleSetupParam *)work->battleSetup); work->battleSetup = 0; }
        GAME_EVENT_CallProc(work->event, (uptr)ov127_id, (void *)d_021C37E8, (void *)work->session);
        ++*seq;
        break;
    case 12:
        *seq = d_02154C40[work->session->menuChoice].nextSeq;
        if (work->session->menuChoice == 1) work->login.useSaveData = 1;
        work->menuSelection = d_02154C40[work->session->menuChoice].selection;
        GF_OVERLAY_Unload((sptr)ov067_id);
        GF_OVERLAY_Unload((sptr)ov099_id);
        break;
    case 13:
        EVENT_WIFICLUB_BuildBattleEntry(work, (void *)GAMESYSTEM_GetGameData(gameSystem), step);
        work->battleSetup = BTL_SETUP_Create(4);
        EVENT_WIFICLUB_SetupBattle(work, work->session->menuChoice);
        GAME_EVENT_CallProc(work->event, (uptr)ov134_id, (void *)d_021DCCA4, (void *)&work->battleEntry);
        ++*seq;
        break;
    case 14:
        if (work->battleResult == 1) {
            if (GFL_NET_GetRunState()) {
                work->session->rematch = 0;
                *seq = 11;
            } else {
                EVENT_WIFICLUB_ResetSound(work);
                *seq = 9;
            }
        } else {
            EVENT_WIFICLUB_SetBattleParty(work, (void *)GAMESYSTEM_GetGameData(gameSystem), step);
            GF_OVERLAY_Load((sptr)ov093_id);
            GFL_NET_COMMAND_AddCommandTable(0x100, (uptr)d_021F03C4, 9, 0);
            GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 100, 10);
            ++*seq;
        }
        break;
    case 15:
        if (!GFL_NET_GetRunState() || GFL_NET_ERR_GetErrorLevel()) {
            GFL_NET_ERR_WaitLinkClosed(); GFL_NET_ERR_ShowSimpleScreen(); goto cleanup;
        }
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 100, 10)) ++*seq;
        break;
    case 16:
        GFL_USE_CancelChangeAndPlayBgm(0x490, 0xffff);
        work->matchActive = 1;
        /* (work + offset) then the member offset, as in the original; indexing sides[] changes the bytes */
        if (!GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) {
            for (i = 0; i < 2; i++) {
                offset = i << 4;
                ((WifiClubEventWork *)((uptr)work + offset))->sides[0].playerStatus = GAME_DATA_GetMyStatusPlayer(GAMESYSTEM_GetGameData(gameSystem), i);
                ((WifiClubEventWork *)((uptr)work + offset))->sides[0].party = work->session->party[i];
            }
        } else {
            order = d_02154C2C;
            for (i = 0; i < 2; i++) {
                offset = ((u8 *)&order)[i] << 4;
                ((WifiClubEventWork *)((uptr)work + offset))->sides[0].playerStatus = GAME_DATA_GetMyStatusPlayer(GAMESYSTEM_GetGameData(gameSystem), i);
                ((WifiClubEventWork *)((uptr)work + offset))->sides[0].party = work->session->party[i];
            }
        }
        work->startParam.gameData = GAMESYSTEM_GetGameData(work->gameSystem);
        work->startParam.battleSetup = work->battleSetup;
        work->startParam.sides = work->sides;
        work->startParam.enabled = 1;
        work->trainerRecord = GAME_DATA_GetTrainerRecord(GAMESYSTEM_GetGameData(work->gameSystem));
        GF_OVERLAY_Unload((sptr)ov093_id);
        GAME_EVENT_CallProc(work->event, (uptr)ov008_id, (void *)d_0215513C, (void *)&work->startParam);
        ++*seq;
        break;
    case 17:
        if (!GFL_NET_GetRunState()) goto cleanup;
        if (work->matchOutcome == 0)
            WIFILIST_AddFriendBattleRecord((void *)GAME_DATA_GetWifiList(GAMESYSTEM_GetGameData(work->gameSystem)), work->session->ruleId - 1, 1, 0, 0);
        else if (work->matchOutcome == 1)
            WIFILIST_AddFriendBattleRecord((void *)GAME_DATA_GetWifiList(GAMESYSTEM_GetGameData(work->gameSystem)), work->session->ruleId - 1, 0, 1, 0);
        GFL_NET_COMMAND_DeleteCommandTable(0x100);
        *seq = 11;
        break;
    case 18:
        work->tradeParam.result = 0;
        work->tradeParam.ruleId = work->session->ruleId;
        ++*seq;
        break;
    case 19:
        work->tradeParam.gameData = GAMESYSTEM_GetGameData(gameSystem);
        GAME_EVENT_CallProc(work->event, (uptr)ov119_id, (void *)d_021E75C0, (void *)&work->tradeParam);
        ++*seq;
        break;
    case 20:
        switch (work->tradeParam.result) {
        case 1: *seq = 21; break;
        case 2: work->session->menuChoice = 1; *seq = 11; break;
        default: *seq = 11; break;
        }
        if (!GFL_NET_GetRunState()) {
            EVENT_WIFICLUB_ResetSound(work);
            *seq = 9;
        }
        break;
    case 21:
        request = GFL_HEAP_Alloc(4, 0x14, 0, d_02154C80, 0x24b);
        request->gameData = GAMESYSTEM_GetGameData(work->gameSystem);
        request->party = work->tradeParam.party;
        request->targetSpecies = work->tradeParam.partyIndex;
        request->partySlot = 0;
        request->evolveCondition = work->tradeParam.evolveCondition;
        request->fromTrade = 1;
        request->fromField = 0;
        work->tradeParam.evolutionRequest = request;
        GAME_EVENT_CallProc(work->event, (uptr)ov195_id, (void *)d_02208C40, (void *)request);
        *seq = 22;
        break;
    case 22:
        GFL_HEAP_Free(work->tradeParam.evolutionRequest);
        work->tradeParam.result = 1;
        *seq = 19;
        if (!GFL_NET_GetRunState()) {
            EVENT_WIFICLUB_ResetSound(work);
            *seq = 9;
        }
        break;
    case 23:
        work->viewParam.gameData = GAMESYSTEM_GetGameData(gameSystem);
        work->viewParam.mode = 3;
        GAME_EVENT_CallProc(work->event, (uptr)ov172_id, (void *)d_021C7240, (void *)&work->viewParam);
        ++*seq;
        break;
    case 24:
        if (GFL_NET_GetRunState()) goto menu;
cleanup:
        EVENT_WIFICLUB_ResetSound(work);
        *seq = 9;
        break;
menu:
        *seq = 11;
        break;
    case 28: GFL_NET_Exit(0); *seq = 29; break;
    case 29: if (GFL_NET_IsIdle()) *seq = 4; break;
    case 25: case 26: case 27: *seq = 4; break;
    }
    return 0;
}




/*
 * Cleanup helper. The battle setup is freed and cleared only when non-NULL;
 * the six blx sites are ARM GFL_HEAP_Free. The 0x5A<<2 (0x168) field is a
 * Thumb encoding artefact, not evidence of a second pointer.
 */
void EVENT_WIFICLUB_FreeWork(WifiClubEventWork *work)
{
    int battleSetup = (sptr)work->battleSetup;
    if (battleSetup != 0) {
        BTL_SETUP_Delete((struct BattleSetupParam *)battleSetup);
        work->battleSetup = 0;
    }
    GFL_HEAP_Free(work->session->party[0]);
    GFL_HEAP_Free(work->session->party[1]);
    GFL_HEAP_Free(work->session->regulation);
    GFL_HEAP_Free(work->battleParty);
    GFL_HEAP_Free(work->session->scratchBuffer);
    GFL_HEAP_Free(work->session);
}




void EVENT_WIFICLUB_InitWork(void *event, void *gameSystem, int fieldMap, int hideFieldObjects)
{
    WifiClubEventWork *work;
    WifiClubEventSession *session;

    if (GAME_COMM_GetKind(GAMESYSTEM_GetGameComm(gameSystem)))
        GAME_COMM_RequestExitNoCallback(GAMESYSTEM_GetGameComm(gameSystem));
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->event = event;
    work->hideFieldObjects = hideFieldObjects;
    work->session = GFL_HEAP_Alloc(0x8004, 0x4c, 1, d_02154C80, 0x2b0);
    work->session->scratchBuffer = GFL_HEAP_Alloc(0x8004, 0x20, 1, d_02154C80, 0x2b1);
    work->session->gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    work->session->saveControl = GAME_DATA_GetSaveControl(work->session->gameData);
    work->session->rulesLoaded = 1;
    work->session->rematch = 0;
    work->paramGameData = work->session->gameData;
    work->battleRecord = (uptr)GAME_DATA_GetWifiList(work->paramGameData);
    work->session->menuChoice = 0;
    work->tradeParam.party = work->battleParty = POKEPARTY_Create(0x8004);
    work->self = work;
    work->savedBgmNo = GFL_USE_GetBgmNo();
    work->session->party[0] = POKEPARTY_Create(0x8001);
    work->session->party[1] = POKEPARTY_Create(0x8001);
    work->session->regulation = REGULATION_Create(0x8001);
    work->session->isActive = 1;
}




int EVENT_WIFICLUB_Create(int gameSystem, int fieldMap, int hideFieldObjects)
{
    sptr event;

    event = (sptr)GAME_EVENT_Create((void *)gameSystem, 0, (GameEventFunc)EVENT_WIFICLUB_Main, 0x174);
    EVENT_WIFICLUB_InitWork((void *)event, (void *)gameSystem, fieldMap, hideFieldObjects);
    return event;
}


/* Overlay entry point: unpacks the request pair and creates the event. */
int EVENT_WIFICLUB_Entry(int gameSystem, Pair *request)
{
    return EVENT_WIFICLUB_Create(gameSystem, request->a, request->b);
}
