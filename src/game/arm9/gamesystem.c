/*
 * file:     gamesystem.c
 * unit:     yes
 * function: GAMESYSTEM_CallIfSet, GAMESYSTEM_RandTwice, GAMESYSTEM_ApplyTamperPenalty, GAMESYSTEM_ProbeHeapCreate, GAMESYSTEM_ApplyTamperPenaltyRepeat, GAMESYSTEM_ProcInit, GAMESYSTEM_ProcMain, GAMESYSTEM_ProcEnd, GAMESYSTEM_SetupInitWork, GAMESYSTEM_GetWorkSize, GAMESYSTEM_Init, GAMESYSTEM_Exit, GAMESYSTEM_Setup, GAMESYSTEM_Main, GAMESYSTEM_UpdateAutoComm, GAMESYSTEM_Delete, GAMESYSTEM_SetEventCreator, GAMESYSTEM_UpdateEventActiveFlag, GAMESYSTEM_CallProc, GAMESYSTEM_CallFieldProc, GAMESYSTEM_IsEventActive, GAMESYSTEM_GetProcStatus, GAMESYSTEM_GetGameData, GAMESYSTEM_GetMyPlayerWork, GAMESYSTEM_GetEvent, GAMESYSTEM_SetEvent, GAMESYSTEM_GetFieldMap, GAMESYSTEM_SetFieldMap, GAMESYSTEM_IsFieldMapActive, GAMESYSTEM_SetFieldMapState, GAMESYSTEM_GetFieldMapState, GAMESYSTEM_GetIssSystem, GAMESYSTEM_GetGameComm, GAMESYSTEM_SetCommBlocked, GAMESYSTEM_IsCommBlocked, GAMESYSTEM_IsAlwaysNetFlagSet, GAMESYSTEM_SetAlwaysNetFlag, GAMESYSTEM_CanStartAutoComm, GAMESYSTEM_TryStartAutoComm, GAMESYSTEM_IsNetOffBySleep, GAMESYSTEM_ClearNetOffBySleep, GAMESYSTEM_OnSleep, GAMESYSTEM_RegisterSleepCallback, GAMESYSTEM_ReleaseSleepCallback, GAMESYSTEM_IsSleepBlocked, GAMESYSTEM_RegisterSleepCheck, GAMESYSTEM_ReleaseSleepCheck
 * address:  0x02011D28
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from ica_anime.c by tools/splitfile.py.
 *
 * symbols:
 *   _GPowerState  0x021461E8  data
 *   MI_CpuFill8        0x02082BCC  arm
 *   GF_STANDARD_Rand  0x0203F0A8  arm
 *   GFL_USE_AddMainTask   0x020056A0  thumb
 *   _GameSystemGlobal  0x02146248  data
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   ov230_id       0x000000E6  data
 *   OV230_CallSealedBody0  0x021882A0  arm  ov230d
 *   OV230_CallSealedBody3  0x02188354  arm  ov230d
 *   OV230_CallSealedBody4  0x02188390  arm  ov230d
 *   EVENT_WIFI_PROC_CreateOv020Event  0x0215FA00  thumb  ov010
 *   GAMESYSTEM_Delete     0x02012088  thumb
 *   PROCSYS_FreeProcWork     0x020315D4  arm
 *   OS_ResetSystem     0x02087BCC  arm
 *   PROCSYS_Create  0x02031324  arm
 *   GAME_COMM_Create  0x020261E4  thumb
 *   ISS_SYS_Create  0x0202B4BC  thumb
 *   ZONEDATA_Init  0x020139B0  thumb
 *   ISS_SYS_Delete  0x0202B4F0  thumb
 *   GAME_COMM_Delete  0x02026250  thumb
 *   ZONEDATA_Exit  0x02013A48  thumb
 *   GAME_BEACON_Setup     0x020267BC  thumb
 *   PALANM_StopTimer     0x02021438  thumb
 *   GAME_DATA_IsWalkCountEnabled  0x02012A24  thumb
 *   UI_SetFrameRate  0x02035614  arm
 *   GAME_DATA_IncWalkCount  0x020129FC  thumb
 *   GAMESYSTEM_UpdateAutoComm  0x0201205C  thumb
 *   GAME_COMM_Update  0x0202627C  thumb
 *   PROCSYS_Main  0x02031330  arm
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_Update  0x02028A14  thumb
 *   ISS_SYS_Update  0x0202B500  thumb
 *   PALANM_UpdateTimer  0x02021464  thumb
 *   GFL_NET_ERR_ShowScreen  0x0200F7B8  thumb
 *   FIELDMAP_IsReady     0x02188BE8  thumb  ov021
 *   PROCSYS_Delete  0x0203133C  arm
 *   PROCSYS_Push  0x02031348  arm
 *   SDK_OVERLAY_ov021_ID          0x00000015  data
 *   FieldMapProcData  0x021D359C  data  ov021
 *   GAME_DATA_IsConfigFlagSet  0x02012BB0  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   ZONEDATA_IsNoGameEventZone  0x02013D34  thumb
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   INTRUDE_COMM_CheckEntryAllowed  0x02158318  thumb  ov010
 *   DWCi_IsFold  0x02035390  arm
 *   UI_IsPowerConnected  0x020353B0  arm
 *   BLOCK20_SAVEDATA_GetBlockFromSys  0x0200921C  thumb
 *   CGEAR_SAVE_GetObtained  0x020090E0  thumb
 *   GFL_NET_GetRunState     0x0203CD98  arm
 *   GAME_COMM_GetKind     0x02026454  thumb
 *   GAME_COMM_Start     0x020263D8  thumb
 *   UI_SetWakePoweredHookGlobal  0x02035138  arm
 *   UI_SetKeepAwakePred  0x02035064  arm
 *   GAME_DATA_SetConfigFlag  0x02012BC8  thumb
 *   GFL_NET_IRC_WIRELESS_IsActive  0x0203DA4C  arm
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MISC_CountBadges  0x0200C258  thumb
 *   GAME_DATA_GetMyPlayerWork         0x020127A4  thumb
 *   GAME_EVENT_Control 0x02012380 thumb arm9
 *   GAME_EVENT_IsRunning 0x020123C4 thumb arm9
 *   GAME_EVENT_StartByCreator 0x020123D8 thumb arm9
 *   GAME_DATA_Create 0x020124F4 thumb arm9
 *   GAME_DATA_Delete 0x02012704 thumb arm9
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "btl_setup_types.h"
#include "script_vm_types.h"
#include "vm_shared_types.h"
#include "ica_anime_shared_types.h"
#include "ica_anime_shared_types.h"
int GFL_NET_IRC_WIRELESS_IsActive(void);

struct WirelessSave;

struct GameInitWork {
    u32 mode;
    struct Vec3 position;
    u16 zoneId;
    u16 direction;
};

/* Statics of gamesystem.c (0x02146248). */
struct GameSystemGlobal {
    struct GameSystem *gameSystem;
    u32 tamperCount;
    struct GameInitWork initWork;
};

extern void PROCSYS_Delete(struct ProcSys *procSys);

extern void PROCSYS_FreeProcWork(struct Proc *proc);

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

extern u32 GF_STANDARD_Rand(void);

extern void *GFL_USE_AddMainTask(u32 task, u32 work, u32 priority);

extern void GFL_HEAP_CreateChildHeap(unsigned int parentHeapId, unsigned int heapId, unsigned int size);

extern void GFL_HEAP_DeleteChecked(unsigned int heapId);

extern int GF_OVERLAY_Load(int overlayId);

extern u32   OV230_CallSealedBody0(void (*hook)(void), void (*hookArg)(void), u32 unused);

extern u32   OV230_CallSealedBody3(void (*hook)(void), void (*hookArg)(void), u32 unused);

extern u32   OV230_CallSealedBody4(void (*hook)(void), void (*hookArg)(void), u32 unused);

//P
extern void  GF_OVERLAY_Unload(s32 overlayId);

extern void *PROCSYS_AllocProcWork(struct Proc *proc, u32 size, u32 heapId);

extern struct GameEvent *EVENT_WIFI_PROC_CreateOv020Event(struct GameSystem *gameSystem, u32 initParam);
struct GameData;

extern void *GAME_DATA_GetMiscSave(struct GameData *gameData);

extern u32 MISC_CountBadges(struct MiscSave *miscSave);

extern void GAMESYSTEM_Delete(struct GameSystem *gameSystem);

extern void OS_ResetSystem(u32 mode);

extern void *PROCSYS_Create(int heapId);
struct VecSet;

extern struct VecSet *GAME_COMM_Create(u32 heapId, void *gameData);

extern void *ISS_SYS_Create(struct GameData *gameData, unsigned int heapId);

extern void ZONEDATA_Init(u32 heapId);

extern void ISS_SYS_Delete(void *issSystem);

extern void GAME_COMM_Delete(struct VecSet *obj);

extern void ZONEDATA_Exit(void);

extern void GAME_BEACON_Setup(struct GameData *gameData);

extern void PALANM_StopTimer(void);

extern u8 GAME_DATA_IsWalkCountEnabled(const struct GameData *gameData);

extern void UI_SetFrameRate(u8 value);

extern u8 GAME_DATA_IncWalkCount(struct GameData *gameData);

extern void GAMESYSTEM_UpdateAutoComm(struct GameSystem *gameSystem);

extern void GAME_COMM_Update(struct GameComm *gameComm);

extern unsigned int PROCSYS_Main(struct ProcSys *procSys);

extern u32 GAME_DATA_GetBgmInfo(const struct GameData *gameData);
struct FieldSoundSystem;

extern void FIELD_SOUND_SYSTEM_Update(struct FieldSoundSystem *s);

extern void ISS_SYS_Update(void *issSystem);

extern void PALANM_UpdateTimer(u8 *target);

extern u32 GFL_NET_ERR_ShowScreen(u32 mode);

extern void PROCSYS_Push(struct ProcSys *procSys, u32 overlayId, void *procData, void *param);

extern u32 GAME_DATA_IsConfigFlagSet(const struct GameData *gameData);

extern void GAME_DATA_SetConfigFlag(struct GameData *gameData, int on);

extern u16   GAME_DATA_GetPlayerZoneId(const struct PlayerWork *player);

extern u32 ZONEDATA_IsNoGameEventZone(u32 zoneId);

extern u32   GFL_NET_ERR_GetErrorLevel(void);

extern int INTRUDE_COMM_CheckEntryAllowed(struct GameSystem *gameSystem);

extern int   DWCi_IsFold(void);

extern int UI_IsPowerConnected(void);
struct CgearSaveBlock;

extern struct CgearSaveBlock *BLOCK20_SAVEDATA_GetBlockFromSys(void *p);
struct CGearSave;

extern u8 CGEAR_SAVE_GetObtained(struct CGearSave *save);

extern int GFL_NET_GetRunState(void);

extern u32 GAME_COMM_GetKind(struct GameComm *gameComm);

extern void GAME_COMM_Start(struct GameComm *comm, u32 kind, u32 param);

extern void UI_SetWakePoweredHookGlobal(void (*callback)(struct GameSystem *), void *arg);

extern void UI_SetKeepAwakePred(int (*callback)(struct GameSystem *), void *arg);

u32 GAMESYSTEM_CallIfSet(u32 (*func)(void));

void GAMESYSTEM_RandTwice(void);

void GAMESYSTEM_ApplyTamperPenalty(void);

void GAMESYSTEM_ProbeHeapCreate(void);

void GAMESYSTEM_ApplyTamperPenaltyRepeat(void);

u32 GAMESYSTEM_ProcInit(struct Proc *proc, u32 *seq, u32 initParam);

u32 GAMESYSTEM_ProcMain(struct Proc *proc, u32 *seq, u32 initParam, struct GameSystem *gameSystem);

u32 GAMESYSTEM_ProcEnd(struct Proc *proc, u32 *seq, u32 initParam, struct GameSystem *gameSystem);

struct GameInitWork *GAMESYSTEM_SetupInitWork(u32 mode, u16 zoneId, struct Vec3 *position, int direction);

u32 GAMESYSTEM_GetWorkSize(void);

void GAMESYSTEM_Init(struct GameSystem *gameSystem, u16 heapId, u32 initParam);

void GAMESYSTEM_Exit(struct GameSystem *gameSystem);

void GAMESYSTEM_Setup(struct GameSystem *gameSystem, u16 heapId, u32 initParam);

int GAMESYSTEM_Main(struct GameSystem *gameSystem);

void GAMESYSTEM_SetEventCreator(struct GameSystem *gameSystem, GameEventCreatorFn creator, void *arg);

void GAMESYSTEM_UpdateEventActiveFlag(struct GameSystem *gameSystem);

void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, void *procData, void *param);

void GAMESYSTEM_CallFieldProc(struct GameSystem *gameSystem);

int GAMESYSTEM_IsEventActive(struct GameSystem *gameSystem);

u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem);

struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);

struct PlayerWork *GAMESYSTEM_GetMyPlayerWork(const struct GameSystem *gameSystem);

struct GameEvent *GAMESYSTEM_GetEvent(const struct GameSystem *gameSystem);

void GAMESYSTEM_SetEvent(struct GameSystem *gameSystem, struct GameEvent *event);

void *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);

void GAMESYSTEM_SetFieldMap(struct GameSystem *gameSystem, void *fieldMap);

u32 GAMESYSTEM_IsFieldMapActive(const struct GameSystem *gameSystem);

void GAMESYSTEM_SetFieldMapState(struct GameSystem *gameSystem, u32 state);

u8 GAMESYSTEM_GetFieldMapState(const struct GameSystem *gameSystem);

void *GAMESYSTEM_GetIssSystem(const struct GameSystem *gameSystem);

struct GameComm *GAMESYSTEM_GetGameComm(const struct GameSystem *gameSystem);

void GAMESYSTEM_SetCommBlocked(struct GameSystem *gameSystem, u32 blocked);

u8 GAMESYSTEM_IsCommBlocked(const struct GameSystem *gameSystem);

u32 GAMESYSTEM_IsAlwaysNetFlagSet(const struct GameSystem *gameSystem);

void GAMESYSTEM_SetAlwaysNetFlag(struct GameSystem *gameSystem, unsigned int on);

u32 GAMESYSTEM_CanStartAutoComm(struct GameSystem *gameSystem);

u32 GAMESYSTEM_TryStartAutoComm(struct GameSystem *gameSystem);

u32 GAMESYSTEM_IsNetOffBySleep(const struct GameSystem *gameSystem);

void GAMESYSTEM_ClearNetOffBySleep(struct GameSystem *gameSystem);

void GAMESYSTEM_OnSleep(struct GameSystem *gameSystem);

void GAMESYSTEM_RegisterSleepCallback(struct GameSystem *gameSystem);

void GAMESYSTEM_ReleaseSleepCallback(struct GameSystem *gameSystem);

int GAMESYSTEM_IsSleepBlocked(struct GameSystem *gameSystem);

void GAMESYSTEM_RegisterSleepCheck(struct GameSystem *gameSystem);

void GAMESYSTEM_ReleaseSleepCheck(struct GameSystem *gameSystem);

int GAME_EVENT_Control(struct GameSystem *gameSystem);

int GAME_EVENT_IsRunning(struct GameSystem *gameSystem);

int GAME_EVENT_StartByCreator(struct GameSystem *gameSystem, GameEventCreatorFn creator, void *arg);

struct GameData *GAME_DATA_Create(u16 heapId);

void GAME_DATA_Delete(struct GameData *gameData);

struct PlayerWork *GAME_DATA_GetMyPlayerWork(struct GameData *gameData);

extern struct GameSystemGlobal _GameSystemGlobal;

extern u8 ov230_id[];

extern u8 SDK_OVERLAY_ov021_ID[];

extern u8 FieldMapProcData;
struct FieldMap;

/*
 * GAMESYSTEM_CallIfSet calls its argument, if not null, purely for effect: the
 * call falls straight through into `mvns r0, r4` with no branch around it,
 * so the return value is always the bitwise complement of the function
 * pointer itself, never whatever the call returned.
 *
 * GAMESYSTEM_RandTwice calls GF_STANDARD_Rand twice and returns nothing, a debug
 * marker pair (begin/end) around nothing in between.
 *
 * GAMESYSTEM_ApplyTamperPenalty and GAMESYSTEM_ApplyTamperPenaltyRepeat, on either side of the function between
 * this pair, were a documented register-swap near miss on their single
 * `_GameSystemGlobal.tamperCount += 1`; now EXACT (src/matched/GAMESYSTEM_ApplyTamperPenalty.c and
 * src/matched/GAMESYSTEM_ApplyTamperPenaltyRepeat.c). The fix was declaring the global as a
 * real struct and using field syntax (`_GameSystemGlobal.tamperCount += 1`) instead
 * of raw pointer-plus-offset arithmetic; not merged into this unit
 * because GAMESYSTEM_ProbeHeapCreate between them stays out of the manifest (see
 * below).
 *
 * The function between them, GAMESYSTEM_ProbeHeapCreate, reproduces every byte the
 * comparison covers, but is left out of the manifest: the listing's extent
 * runs two bytes long across the `00 00` alignment pad in front of
 * GAMESYSTEM_ApplyTamperPenaltyRepeat, an `EXACT*` this territory's policy does not accept
 * because the follower carries a real label rather than being the
 * unlabelled-follower case `EXACT*` is meant for.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011D28.c \
 *       --addr 0x02011D28 --thumb
 */
u32 GAMESYSTEM_CallIfSet(u32 (*func)(void))
{
    if (func != 0) {
        func();
    }
    return ~(u32)func;
}

void GAMESYSTEM_RandTwice(void)
{
    GF_STANDARD_Rand();
    GF_STANDARD_Rand();
}

/*
 * Allocates 0x7F bytes off heap 0 through GFL_USE_AddMainTask.c's allocator
 * wrapper, tagged with GAMESYSTEM_RandTwice's own address (the SDK debug-tag
 * convention: the tag is the calling site, here literally the sibling
 * debug-marker function's address), discards the result, and bumps
 * _GameSystemGlobal.tamperCount. See unit_02011D28.c's header for the sibling
 * GAMESYSTEM_ApplyTamperPenaltyRepeat and the documented near miss on this increment.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GAMESYSTEM_ApplyTamperPenalty.c \
 *       --func GAMESYSTEM_ApplyTamperPenalty --addr 0x02011D40 --cc 1.1p1 --thumb
 */
void GAMESYSTEM_ApplyTamperPenalty(void)
{
    GFL_USE_AddMainTask((u32)GAMESYSTEM_RandTwice, 0, 0x7f);
    _GameSystemGlobal.tamperCount += 1;
}

void GAMESYSTEM_ProbeHeapCreate(void)
{
    GFL_HEAP_CreateChildHeap(9, 5, 5 << 10);
    GAMESYSTEM_GetWorkSize();
    GFL_HEAP_DeleteChecked(5);
}

/*
 * Allocates 0x7F bytes off heap 0 through GFL_USE_AddMainTask.c's allocator
 * wrapper, tagged with GAMESYSTEM_RandTwice's own address (the SDK debug-tag
 * convention: the tag is the calling site, here literally the sibling
 * debug-marker function's address), discards the result, and bumps
 * _GameSystemGlobal.tamperCount. See unit_02011D28.c's header for the sibling
 * GAMESYSTEM_ApplyTamperPenalty (src/matched/GAMESYSTEM_ApplyTamperPenalty.c, converted to EXACT
 * alongside this one) and the formerly-documented near miss on this
 * increment: the `_GameSystemGlobal.tamperCount += 1` register swap resolves when the
 * global is declared as a real struct (`_GameSystemGlobal.tamperCount += 1`) rather
 * than accessed through raw pointer-plus-offset arithmetic.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GAMESYSTEM_ApplyTamperPenaltyRepeat.c \
 *       --func GAMESYSTEM_ApplyTamperPenaltyRepeat --addr 0x02011D7C --cc 1.1p1 --thumb
 */
void GAMESYSTEM_ApplyTamperPenaltyRepeat(void)
{
    GFL_USE_AddMainTask((u32)GAMESYSTEM_RandTwice, 0, 0x7f);
    _GameSystemGlobal.tamperCount += 1;
}

/*
 * promoted: wave 21 lane T, EXACT (match.py one, 25 of 25 relocations)
 *           once the ov230d token let the probe targets resolve
 *
 * ica_anime.c: scene bring-up.  Loads overlay 230, runs three checksum
 * probes over this family's own code (GAMESYSTEM_CallIfSet to GAMESYSTEM_ApplyTamperPenalty,
 * GAMESYSTEM_ProbeHeapCreate, GAMESYSTEM_ApplyTamperPenaltyRepeat; each result compared with the complement of
 * the end address), creates three heaps through GFL_HEAP_CreateChildHeap, allocates
 * the work block and publishes it to _GameSystemGlobal, then, when the probe
 * results do not add up to a multiple of 0x12AF, runs a MISC_CountBadges-counted
 * loop of GAMESYSTEM_ApplyTamperPenalty.
 *
 * Byte-correct: 272 of 272 bytes, 0 concrete bytes out (match.py one,
 * dsi/1.1p1, 2026-09-24 wave 21 lane H).  The lever that closed it after
 * eight waves at 8 out: the probes' shared start address is held in a u32
 * local (`start = (u32)GAMESYSTEM_CallIfSet;`) and cast back at each call
 * (docs/idioms/an-address-held-in-a-u32-local-is-reloaded-at-every-site.md).
 * The local's web spans the second heap call, so the argument 4 there is
 * rematerialised (`movs r2,#4 ... movs r1,#4; lsls r2,r2,#14`) instead of
 * being common-subexpression-eliminated into r1, which is what the image
 * does; the single-call shape `off = 0; if (flag == 0) off = 0x191;` is the
 * right control flow once that holds.
 *
 * Probe targets (wave 21 lanes H2 and T): 0x021882A0, 0x02188354 and
 * 0x02188390 are slots 0, 3 and 4 of the six ARM thunk slots ov230's first
 * static initialiser (at 0x02188408) decrypts in place when this function
 * loads the overlay.  The ROM bytes there are ciphertext, so ov230's ROM
 * listing never labels them; tools/ovcrypt.py replays ov230's own
 * decryptor (every range checked to be a clean ARM function ending in a
 * return) and asm/ov230d/ov230d.s lists the result.  With the `ov230d`
 * token on the three symbols: lines they resolve as sole-ref/code against
 * that listing: 25 of 25 sites (ov230_id as overlay_id, EVENT_WIFI_PROC_CreateOv020Event
 * sole-ref/code with the ov010 hint).
 */
u32 GAMESYSTEM_ProcInit(struct Proc *proc, u32 *seq, u32 initParam)
{
    u32 workSize;
    u32 checkSum;
    u32 intact;
    u32 checkPenalty;
    struct GameSystem *gameSystem;
    s32 penaltyCount;
    s32 i;
    u32 checkCaller;

    workSize = GAMESYSTEM_GetWorkSize();
    checkCaller = (u32)GAMESYSTEM_CallIfSet;
    checkSum = 0xc35ffb;
    GF_OVERLAY_Load((int)ov230_id);
    intact = 0;
    if (OV230_CallSealedBody0((void (*)(void))checkCaller, GAMESYSTEM_ApplyTamperPenalty, 0) == ~(u32)GAMESYSTEM_ApplyTamperPenalty)
        intact = 1;
    checkSum += intact * 0x47;
    GFL_HEAP_CreateChildHeap(1, 3, 0xa << 12);
    intact = 1;
    if (OV230_CallSealedBody3((void (*)(void))checkCaller, GAMESYSTEM_ProbeHeapCreate, 0) != ~(u32)GAMESYSTEM_ProbeHeapCreate)
        intact = 0;
    checkPenalty = 0;
    if (intact == 0)
        checkPenalty = 0x191;
    GFL_HEAP_CreateChildHeap(1, 4, 4 << 14);
    OV230_CallSealedBody4((void (*)(void))checkCaller, GAMESYSTEM_ApplyTamperPenaltyRepeat, 0);
    GFL_HEAP_CreateChildHeap(9, 5, 5 << 10);
    GF_OVERLAY_Unload((s32)ov230_id);
    gameSystem = PROCSYS_AllocProcWork(proc, workSize, 3);
    MI_CpuFill8(gameSystem, 0, workSize);
    _GameSystemGlobal.gameSystem = gameSystem;
    GAMESYSTEM_Setup(gameSystem, 3, initParam);
    GAMESYSTEM_SetEvent(gameSystem, EVENT_WIFI_PROC_CreateOv020Event(gameSystem, initParam));
    if ((checkSum + checkPenalty) % 0x12af != 0) {
        penaltyCount = MISC_CountBadges(GAME_DATA_GetMiscSave(GAMESYSTEM_GetGameData(gameSystem)));
        for (i = 0; i < penaltyCount; i++)
            GAMESYSTEM_ApplyTamperPenalty();
    }
    return 1;
}

/*
 * Only the fourth parameter is used, and it is moved straight out of r3 into
 * r0 at entry - a one-argument wrapper whose first three arguments are the
 * caller's leftovers (r0..r2 are untouched, which is what the prologue's
 * `adds r0, r3, #0` says).
 *
 *           call inside this function (checked: `label` finds no outside
 *           branch, and no EXACT manifest entry covers 0x02011FCC, so
 *           `matched` does not reach it either).  No cut helps - shrinking
 *           the range to this function keeps the call inside it.  Writing
 *           0x02011FCC (144 bytes, packet pkt_02011F28) as an EXACT entry
 *           would close this one; nothing else will.
 * Verified with:
 *   python tools/match.py one --src src/pending/GAMESYSTEM_ProcMain.c \
 *       --func GAMESYSTEM_ProcMain --addr 0x02011EAC --cc 1.1p1 --thumb
 */
u32 GAMESYSTEM_ProcMain(struct Proc *proc, u32 *seq, u32 initParam, struct GameSystem *gameSystem)
{
    if (GAMESYSTEM_Main(gameSystem) != 0)
        return 1;
    return 0;
}

/*
 * Promoted from src/pending/ in the second 0-64 byte band pass (lane 1).  It
 * was parked there on the call to 0x02012088 only; GAMESYSTEM_Delete now has an
 * EXACT entry of its own, so the site resolves through the `matched` class and
 * the file needs no change.  The fourth parameter is moved out of r3 at entry
 * and passed first; then the first parameter; the three GFL_HEAP_DeleteChecked calls
 * with consecutive ids 3, 4, 5 and a final OS_ResetSystem(0).  Returns 1.
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_ProcEnd.c \
 *       --func GAMESYSTEM_ProcEnd --addr 0x02011EC0 --cc 1.1p1 --thumb
 */
u32 GAMESYSTEM_ProcEnd(struct Proc *proc, u32 *seq, u32 initParam, struct GameSystem *gameSystem)
{
    GAMESYSTEM_Delete(gameSystem);
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_DeleteChecked(3);
    GFL_HEAP_DeleteChecked(4);
    GFL_HEAP_DeleteChecked(5);
    OS_ResetSystem(0);
    return 1;
}

/*
 * The object at 0x02146248, seen through its +0x08 field: the pool words are
 * 0x02146250 (the address of +0x08, used both for the 0x14-byte clear and
 * for the return value), 0x02146248 and 0x02146254 (= +0x0C, the destination
 * of the twelve-byte record copy).  So the struct is
 * `{ u32 mode; Vec3 position; u16 zoneId; u16 direction; }` and the function
 * clears +0x08..+0x1C, stores two scalars, copies the record in and stores
 * one more scalar.
 *
 * The scalar store to +0x08 goes through the +0x08 pointer, the two
 * halfwords go through the +0x00 base, and the copy is one twelve-byte
 * aggregate assignment (the ldm/stm pair plus the third word).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_SetupInitWork.c \
 *       --func GAMESYSTEM_SetupInitWork --addr 0x02011EEC --cc 1.1p1 --thumb
 */
struct GameInitWork *GAMESYSTEM_SetupInitWork(u32 mode, u16 zoneId, struct Vec3 *position, int direction)
{
    MI_CpuFill8(&_GameSystemGlobal.initWork, 0, sizeof(struct GameInitWork));
    _GameSystemGlobal.initWork.mode = mode;
    _GameSystemGlobal.initWork.zoneId = zoneId;
    _GameSystemGlobal.initWork.position = *position;
    _GameSystemGlobal.initWork.direction = direction;
    return &_GameSystemGlobal.initWork;
}

/*
 * Four bytes, `movs r0, #0x34; bx lr`: the sizeof getter of the context record
 * whose accessors are src/matched/unit_020120F0.c and
 * src/matched/unit_02012204.c.  It is what pins that struct's size, and the
 * declaration here is the same one those two files carry, so the three check
 * each other.  It is a file of its own because the functions on either side of
 * it are not matched yet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011F24.c  *       --addr 0x02011F24 --thumb
 */
u32 GAMESYSTEM_GetWorkSize(void)
{
    return sizeof(struct GameSystem);
}

/*
 * Initialise an ica_anime record (struct IcaAnime, docs/families/ica_anime.h)
 * for resource id `id`: open the handle (+0x08), clear the clock words,
 * load the table (+0x1c) and build its companion (+0x24) and the +0x2c
 * object from it, clear +0x32 and bit 0 of +0x33, then reset and start.
 *
 * The note's 8-byte r0/r1 "tie" (docs/notes/pkt_02011F28.c.txt) was a
 * misread arity: GAME_COMM_Create takes TWO arguments (its own matched file
 * reads r1), and the second is the table just stored at +0x1c, passed as
 * `p->gameData` -- which the compiler forwards from the register, hence the
 * `adds r1, r0, #0` the image has before the id reload.  Written as a
 * struct, not raw pointer casts.  EXACT* only because the 2-byte pad at
 * 0x02011F8E runs the extent to 0x02011F90.
 */
void GAMESYSTEM_Init(struct GameSystem *gameSystem, u16 heapId, u32 initParam)
{
    gameSystem->heapId = heapId;
    gameSystem->initParam = initParam;
    gameSystem->procSys = PROCSYS_Create(gameSystem->heapId);
    gameSystem->procStatus = 0;
    gameSystem->eventCreator = 0;
    gameSystem->eventCreatorArg = 0;
    gameSystem->event = 0;
    gameSystem->gameData = GAME_DATA_Create(gameSystem->heapId);
    gameSystem->fieldMap = 0;
    gameSystem->gameComm = (struct GameComm *)GAME_COMM_Create(gameSystem->heapId, gameSystem->gameData);
    gameSystem->reserved = 0;
    gameSystem->issSystem = ISS_SYS_Create(gameSystem->gameData, heapId);
    gameSystem->commBlocked = 0;
    gameSystem->netOffBySleep = 0;
    GAMESYSTEM_RegisterSleepCallback(gameSystem);
    GAMESYSTEM_RegisterSleepCheck(gameSystem);
    ZONEDATA_Init(heapId);
}

/*
 * Teardown: two calls on the object itself, then three on its words at +0x2c,
 * +0x1c and +0x24, then a final no-argument call.  Every callee resolves on its
 * own manifest entry or on a label outside the range, so the file is EXACT up to
 * the two bytes of section padding after the pop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_Exit.c \
 *       --func GAMESYSTEM_Exit --addr 0x02011F90 --cc 1.1p1 --thumb
 */
void GAMESYSTEM_Exit(struct GameSystem *gameSystem)
{
    GAMESYSTEM_ReleaseSleepCheck(gameSystem);
    GAMESYSTEM_ReleaseSleepCallback(gameSystem);
    ISS_SYS_Delete(gameSystem->issSystem);
    GAME_DATA_Delete(gameSystem->gameData);
    GAME_COMM_Delete((struct VecSet *)gameSystem->gameComm);
    ZONEDATA_Exit();
}

/*
 * The object goes through GAMESYSTEM_Init with r0-r2 untouched, then one field
 * destructor and a global call.
 *
 *           (its only caller in the image is this function) and 0x020267BC at
 *           +0x0A.  Both are byte-correct here; the range cannot be cut to
 *           free them because the call is inside the only function that makes
 *           it.  Folding 0x02011F28 into the same unit would take the packet
 *           to 0x02011F28.. and is possible - see the note in
 *           docs/notes/pkt_02011F28.c.txt.
 * Verified with:
 *   python tools/match.py one --src src/pending/GAMESYSTEM_Setup.c \
 *       --func GAMESYSTEM_Setup --addr 0x02011FB8 --cc 1.1p1 --thumb
 */
void GAMESYSTEM_Setup(struct GameSystem *gameSystem, u16 heapId, u32 initParam)
{
    GAMESYSTEM_Init(gameSystem, heapId, initParam);
    GAME_BEACON_Setup(gameSystem->gameData);
    PALANM_StopTimer();
}

/*
 * Byte-correct, MATCH-capped: all 144 concrete bytes reproduce, the four
 * remaining wildcards are call sites whose targets live in OTHER PACKETS and
 * have no witness outside this range:
 *
 *   +0034  bl GAME_EVENT_Control   -> pkt_02012380
 *   +003A  bl GAME_COMM_Update   -> pkt_0202627C
 *   +0052  bl ISS_SYS_Update   -> pkt_0202B500
 *   +0058  bl PALANM_UpdateTimer   -> pkt_02021464
 *
 * Each reports `no witness outside 02011FCC..02012060`, i.e. the only branch
 * anywhere in the image reaching them is the call in this function, so the
 * `label` class cannot attest them and no cut frees them.  Blocking class:
 * label.  Nothing in this C changes when those packets are filed -- the file
 * graduates for free.
 *
 * Two spellings this function pinned down:
 *
 *  - The last guard is ONE conjunction, `a == 0 && b == 0 -> return 1`.  The
 *    equivalent disjunction (`a != 0 || b != 0 -> return 0`) makes mwcc pick
 *    the other arm as the fall-through and comes out four bytes of wrong
 *    layout: `bne #0x2012054` + `beq` + the two `movs r0` swapped, where the
 *    original branches BOTH tests to a shared out-of-line `movs r0,#0; pop`
 *    and falls through to `movs r0,#1`.
 *  - The state word at +0x0c is re-read from memory at each use rather than
 *    cached in a register, so it is spelled as the field every time.
 */
int GAMESYSTEM_Main(struct GameSystem *gameSystem)
{
    GAMESYSTEM_UpdateEventActiveFlag(gameSystem);
    if (GAME_DATA_IsWalkCountEnabled(gameSystem->gameData) != 0)
        UI_SetFrameRate(0x1e);
    if (GAME_DATA_IncWalkCount(gameSystem->gameData) == 0) {
        GAME_EVENT_StartByCreator(gameSystem, gameSystem->eventCreator, gameSystem->eventCreatorArg);
        GAMESYSTEM_UpdateAutoComm(gameSystem);
        GAME_EVENT_Control(gameSystem);
        GAME_COMM_Update(gameSystem->gameComm);
    }
    gameSystem->procStatus = PROCSYS_Main(gameSystem->procSys);
    FIELD_SOUND_SYSTEM_Update((struct FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameSystem->gameData));
    ISS_SYS_Update(gameSystem->issSystem);
    PALANM_UpdateTimer((u8 *)gameSystem->gameData);
    if (GAME_DATA_IsWalkCountEnabled(gameSystem->gameData) != 0)
        UI_SetFrameRate(0x3c);
    if (gameSystem->procStatus == 2 || gameSystem->procStatus == 0)
        GFL_NET_ERR_ShowScreen(0);
    if (gameSystem->procStatus == 0 && gameSystem->event == 0)
        return 1;
    return 0;
}

extern int FIELDMAP_IsReady(struct FieldMap *fieldMap);   /* overlay-resident */

/*
 * Three nested tests sharing one epilogue: the object is driven through
 * GAMESYSTEM_TryStartAutoComm only when GAMESYSTEM_IsEventActive returns 0, GAMESYSTEM_IsFieldMapActive returns 1
 * and the overlay call returns 1 as well.  That last call's argument is
 * GAMESYSTEM_GetFieldMap(p)'s result - r0 is not reloaded in between, which is what
 * the source's nesting says.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_UpdateAutoComm.c \
 *       --func GAMESYSTEM_UpdateAutoComm --addr 0x0201205C --cc 1.1p1 --thumb
 */
void GAMESYSTEM_UpdateAutoComm(struct GameSystem *gameSystem)
{
    if (GAMESYSTEM_IsEventActive(gameSystem) == 0) {
        if (GAMESYSTEM_IsFieldMapActive(gameSystem) == 1) {
            if (FIELDMAP_IsReady(GAMESYSTEM_GetFieldMap(gameSystem)) == 1)
                GAMESYSTEM_TryStartAutoComm(gameSystem);
        }
    }
}

/*
 * The tail of the packet's small table walkers: two loads off the
 * _GPowerState tables and one store, 18 bytes, every relocation a label outside
 * the range.  It re-verified EXACT after GPOWER_ClearType and GPOWER_GetSelectedMinutesLeft were
 * filed in pkt_02010EEC (the same two tables), so the entry is a chain payoff.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_Delete.c \
 *       --func GAMESYSTEM_Delete --addr 0x02012088 --cc 1.1p1 --thumb
 */
void GAMESYSTEM_Delete(struct GameSystem *gameSystem)
{
    PROCSYS_Delete(gameSystem->procSys);
    GAMESYSTEM_Exit(gameSystem);
}

/*
 * The word pair setter that follows GAMESYSTEM_Delete's epilogue at 0x0201209A:
 * two words at +0x10 and +0x14, no prologue, no label.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_SetEventCreator.c \
 *       --func GAMESYSTEM_SetEventCreator --addr 0x0201209C --cc 1.1p1 --thumb
 */
void GAMESYSTEM_SetEventCreator(struct GameSystem *gameSystem, GameEventCreatorFn creator, void *arg)
{
    gameSystem->eventCreator = creator;
    gameSystem->eventCreatorArg = arg;
}

void GAMESYSTEM_UpdateEventActiveFlag(struct GameSystem *gameSystem)
{
    gameSystem->eventActive = (u8)GAME_EVENT_IsRunning(gameSystem);
}

/*
 * ica_anime.c.  Forwards the +0x08 handle and the caller's other three
 * arguments to the ARM routine at 0x02031348.  The frame
 * (push {r3,lr} / blx / pop {r3,pc}) where every one-argument spelling gets
 * a pool-word-and-bx sibling call (26 spellings in
 * docs/notes/pkt_020120B4.c.txt) is the tail-call-cannot-pass-a-fourth-
 * argument idiom: r1-r3 are passed through untouched, so they cost no
 * instruction, and r3 being live blocks the sibling call.  The arity is
 * independently evidenced by the only caller, GAMESYSTEM_CallFieldProc, which sets up
 * r1, r2 and r3 (r3 = r0) before the bl.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_CallProc.c \
 *       --func GAMESYSTEM_CallProc --addr 0x020120B4 --cc 1.1p1 --thumb
 */
void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, void *procData, void *param)
{
    PROCSYS_Push(gameSystem->procSys, overlayId, procData, param);
}

/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id site
 *           SDK_OVERLAY_ov021_ID (21) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 * evidence: FieldMapProcData lies in the windows of ov021 (data) and ov114 (bss),
 *           so the ov021 hint needs outside support.  The same call passes
 *           SDK_OVERLAY_ov021_ID (0x15, attested `overlay_id`) and this pointer to the
 *           proc system: GAMESYSTEM_CallProc -> PROCSYS_Push -> PROCSYS_PushInternal ->
 *           PROCSYS_NewProc stores the id at Proc+4 and the pointer at Proc+0
 *           (ProcData), and PROCSYS_StepProc loads overlay Proc+4
 *           (GF_OVERLAY_Load) before it calls any ProcData callback.  So ov021
 *           is resident whenever the pointer is dereferenced.  Independently,
 *           ov021's bytes at 0x021D359C are three Thumb pointers
 *           0x02187F01/0x02187FD1/0x02187FE9, each a func_ label in
 *           ov021's own listing (init/main/end), while ov114 holds bss there.
 *           With the hint the site attests as `data_table` from ov021's bytes.
 *
 * Four arguments, and the first is the same object twice: the pool words are
 * a small constant 0x15 (an absolute linker symbol, not a literal - see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md, 21 is
 * an overlay id) and the overlay-space address 0x021D359C.  GAMESYSTEM_CallProc
 * itself only reads r0, which is why its ten-byte body says nothing about
 * this call's arity.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_CallFieldProc.c \
 *       --func GAMESYSTEM_CallFieldProc --addr 0x020120C0 --cc 1.1p1 --thumb
 */
void GAMESYSTEM_CallFieldProc(struct GameSystem *gameSystem)
{
    GAMESYSTEM_CallProc(gameSystem, (u32)SDK_OVERLAY_ov021_ID, &FieldMapProcData, gameSystem);
}

int GAMESYSTEM_IsEventActive(struct GameSystem *gameSystem)
{
    if (GAME_EVENT_IsRunning(gameSystem))
        return 1;
    return gameSystem->eventActive;
}

/*
 *           GAMESYSTEM_SetEvent, GAMESYSTEM_GetFieldMap, GAMESYSTEM_SetFieldMap, GAMESYSTEM_IsFieldMapActive,
 *           GAMESYSTEM_SetFieldMapState, GAMESYSTEM_GetFieldMapState, GAMESYSTEM_GetIssSystem, GAMESYSTEM_GetGameComm,
 *           GAMESYSTEM_SetCommBlocked, GAMESYSTEM_IsCommBlocked, GAMESYSTEM_IsAlwaysNetFlagSet
 *
 * 104 bytes, 0x020120F0..0x02012158, 15 functions, none of which carries a
 * label: every one of them is a two- or three-instruction accessor on a
 * 0x34-byte context record, and the whole run arrives in the listing as .word
 * data between two literal pools.
 *
 * The size of the record is not a guess: GAMESYSTEM_GetWorkSize is
 * `movs r0, #0x34; bx lr`, its sizeof getter, and it is matched in
 * src/matched/unit_02011F24.c against the same declaration.  The two byte
 * fields at +0x30 and +0x32 cost an `adds r0, #0x30` each because the Thumb
 * `strb` immediate only reaches +31, which is
 * docs/idioms/thumb-immediate-reach-costs-an-adds.md and not a pointer in the
 * source.
 *
 * GAMESYSTEM_GetMyPlayerWork and GAMESYSTEM_IsAlwaysNetFlagSet are tail calls through pool words: the
 * first hands +0x1C to GAME_DATA_GetMyPlayerWork and the second to GAME_DATA_IsConfigFlagSet, and
 * both are ABS32 against a Thumb target, so the pool word is odd.
 *
 * 0x02012158, 12 bytes, is a third tail call of the same shape and is a near
 * miss.  Its pool word holds 0x02012BC9, and GAME_DATA_SetConfigFlag has no label in the
 * listing (it has no register-saving prologue) and no other reference anywhere
 * in the image, so neither the `label` nor the `literal` class has a witness
 * outside the twelve bytes under test.  Every concrete byte reproduces from
 *
 *     void GAMESYSTEM_SetAlwaysNetFlag(struct GameSystem *gameSystem, unsigned int on)
 *     {
 *         GAME_DATA_SetConfigFlag(gameSystem->gameData, on);
 *     }
 *
 * that closes 0x02012BC8 itself; see src/matched/unit_02012AE4.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020120F0.c \
 *       --addr 0x020120F0 --thumb
 */
u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem)
{
    return gameSystem->procStatus;
}

struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem)
{
    return gameSystem->gameData;
}

struct PlayerWork *GAMESYSTEM_GetMyPlayerWork(const struct GameSystem *gameSystem)
{
    return GAME_DATA_GetMyPlayerWork(gameSystem->gameData);
}

struct GameEvent *GAMESYSTEM_GetEvent(const struct GameSystem *gameSystem)
{
    return gameSystem->event;
}

void GAMESYSTEM_SetEvent(struct GameSystem *gameSystem, struct GameEvent *event)
{
    gameSystem->event = event;
}

void *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem)
{
    return gameSystem->fieldMap;
}

void GAMESYSTEM_SetFieldMap(struct GameSystem *gameSystem, void *fieldMap)
{
    gameSystem->fieldMap = fieldMap;
}

u32 GAMESYSTEM_IsFieldMapActive(const struct GameSystem *gameSystem)
{
    if (gameSystem->fieldMap != 0) {
        return 1;
    }
    return 0;
}

void GAMESYSTEM_SetFieldMapState(struct GameSystem *gameSystem, u32 state)
{
    gameSystem->fieldMapState = state;
}

u8 GAMESYSTEM_GetFieldMapState(const struct GameSystem *gameSystem)
{
    return gameSystem->fieldMapState;
}

void *GAMESYSTEM_GetIssSystem(const struct GameSystem *gameSystem)
{
    return gameSystem->issSystem;
}

struct GameComm *GAMESYSTEM_GetGameComm(const struct GameSystem *gameSystem)
{
    return gameSystem->gameComm;
}

void GAMESYSTEM_SetCommBlocked(struct GameSystem *gameSystem, u32 blocked)
{
    gameSystem->commBlocked = blocked;
}

u8 GAMESYSTEM_IsCommBlocked(const struct GameSystem *gameSystem)
{
    return gameSystem->commBlocked;
}

u32 GAMESYSTEM_IsAlwaysNetFlagSet(const struct GameSystem *gameSystem)
{
    return GAME_DATA_IsConfigFlagSet(gameSystem->gameData);
}

void GAMESYSTEM_SetAlwaysNetFlag(struct GameSystem *gameSystem, unsigned int on)
{
    GAME_DATA_SetConfigFlag(gameSystem->gameData, on);
}

/*
 *           listing but its only caller in the whole image is the bl at
 *           +0x38 inside this range, so `label` has no outside witness and
 *           sole-ref/code does not consider overlay starts.  Every concrete
 *           byte is right (MATCH*: the extent runs over the 2-byte pad).
 *
 * The note's 4-byte r0/r1 "tie" (docs/notes/pkt_02012164.c.txt) was a
 * misread arity: GAME_DATA_GetPlayerZoneId is `ldrh r0, [r0]; bx lr`, a getter taking
 * the pointer GAMESYSTEM_GetMyPlayerWork returns, and ZONEDATA_IsNoGameEventZone takes that u16 in
 * r0 -- so the image keeps it in r0 across the p->commBlocked test and reads the
 * byte through r1.  `id = GAME_DATA_GetPlayerZoneId(GAMESYSTEM_GetMyPlayerWork(p))` then
 * `ZONEDATA_IsNoGameEventZone(id)` closes it.
 */
u32 GAMESYSTEM_CanStartAutoComm(struct GameSystem *gameSystem)
{
    u16 zoneId;

    GAMESYSTEM_GetGameComm(gameSystem);
    zoneId = GAME_DATA_GetPlayerZoneId(GAMESYSTEM_GetMyPlayerWork(gameSystem));
    if (gameSystem->commBlocked == 0
     && ZONEDATA_IsNoGameEventZone(zoneId) == 0
     && GFL_NET_ERR_GetErrorLevel() == 0
     && GAMESYSTEM_IsAlwaysNetFlagSet(gameSystem) == 1
     && INTRUDE_COMM_CheckEntryAllowed(gameSystem) == 1
     && !(DWCi_IsFold() == 1 && UI_IsPowerConnected() == 1)) {
        if (CGEAR_SAVE_GetObtained((struct CGearSave *)BLOCK20_SAVEDATA_GetBlockFromSys(gameSystem->gameData)) != 0) {
            return 1;
        }
    }
    return 0;
}

/*
 * Three tests, one epilogue: the handle returned by GAMESYSTEM_GetGameComm(p) is
 * checked with two externals (both called with it - r0 is not reloaded), then
 * the object is driven through GAMESYSTEM_CanStartAutoComm and only a result of exactly 1
 * reaches GAME_COMM_Start(handle, 1, p).  The nested ifs are what give all
 * three the same `return 0` at the end.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_TryStartAutoComm.c \
 *       --func GAMESYSTEM_TryStartAutoComm --addr 0x020121CC --cc 1.1p1 --thumb
 */
u32 GAMESYSTEM_TryStartAutoComm(struct GameSystem *gameSystem)
{
    struct GameComm *gameComm = GAMESYSTEM_GetGameComm(gameSystem);

    if (GFL_NET_GetRunState() == 0) {
        if (GAME_COMM_GetKind(gameComm) == 0) {
            if (GAMESYSTEM_CanStartAutoComm(gameSystem) == 1) {
                GAME_COMM_Start(gameComm, (u32)1, (u32)gameSystem);
                return 1;
            }
        }
    }
    return 0;
}

/*
 * The getter and the clearer of bit 0 of the byte at +0x33 of the same
 * 0x34-byte context record src/matched/unit_020120F0.c describes.  The
 * `lsls #0x1f` / `lsrs #0x1f` pair is a one bit field, not a cast: 32 - 31 is
 * not an integer width, which is
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md, and the
 * clearer's `movs r1, #1` / `bics` is what `p->netOffBySleep = 0;` compiles to
 * because Thumb has no immediate bic.  Neither function has a relocation.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012204.c  *       --addr 0x02012204 --thumb
 */
u32 GAMESYSTEM_IsNetOffBySleep(const struct GameSystem *gameSystem)
{
    return gameSystem->netOffBySleep;
}

void GAMESYSTEM_ClearNetOffBySleep(struct GameSystem *gameSystem)
{
    gameSystem->netOffBySleep = 0;
}

/*
 * ica_anime.c: when GAMESYSTEM_IsAlwaysNetFlagSet(p) says yes, stop the playback
 * (GAMESYSTEM_SetAlwaysNetFlag(p, 0), which is the tail call in the pending file
 * src/pending/GAMESYSTEM_SetAlwaysNetFlag.c) and set bit 0 of the byte at +0x33.
 *
 * The bit update is one expression, `(f & ~1) | 1`: the original loads the
 * byte once, clears with `bics` and sets with `orrs` - two statements would
 * be two loads and two stores (see
 * docs/idioms/an-and-not-is-what-emits-bic.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_OnSleep.c \
 *       --func GAMESYSTEM_OnSleep --addr 0x02012220 --cc 1.1p1 --thumb
 */
void GAMESYSTEM_OnSleep(struct GameSystem *gameSystem)
{
    if (GAMESYSTEM_IsAlwaysNetFlagSet(gameSystem) != 0) {
        GAMESYSTEM_SetAlwaysNetFlag(gameSystem, 0);
        gameSystem->netOffBySleep = 1;
    }
}

/*
 * Promoted from src/pending/GAMESYSTEM_RegisterSleepCallback.c.  The C never changed; the ISA
 * on the second symbols line did.  The tail call goes through the pool word
 * 0x02035138, i.e. an ARM target with no Thumb bit - the parked copy
 * declared it `thumb`, so the word match.py looked for was 0x02035139 and
 * the second pool holding 0x02035138 (at 0x02012260, in the next function,
 * outside this range) could not be seen.  Declared `arm`, the `literal`
 * class resolves the site and the entry is EXACT.  A `bx r3` tail call
 * always has a pool word, and the pool word's low bit is the only place the
 * callee's ISA shows up - a wrong declaration hides the witness silently.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_RegisterSleepCallback.c \
 *       --func GAMESYSTEM_RegisterSleepCallback --addr 0x02012248 --cc 1.1p1 --thumb
 */
void GAMESYSTEM_RegisterSleepCallback(struct GameSystem *gameSystem)
{
    UI_SetWakePoweredHookGlobal(GAMESYSTEM_OnSleep, gameSystem);
}

void GAMESYSTEM_ReleaseSleepCallback(struct GameSystem *gameSystem)
{
    UI_SetWakePoweredHookGlobal(0, 0);
}

int GAMESYSTEM_IsSleepBlocked(struct GameSystem *gameSystem)
{
    if (GAME_COMM_GetKind(GAMESYSTEM_GetGameComm(gameSystem)) != 0) {
        return 1;
    }
    if (GFL_NET_IRC_WIRELESS_IsActive() != 0) {
        return 1;
    }
    if (UI_IsPowerConnected() != 0) {
        return 0;
    }
    if (GAMESYSTEM_IsAlwaysNetFlagSet(gameSystem) != 0) {
        return 1;
    }
    return 0;
}

/*
 * Two instructions and a two word pool: the first argument is the address of
 * GAMESYSTEM_IsSleepBlocked tagged as a Thumb function pointer (the pool word is 0x02012265,
 * odd), the second is the caller's own argument, and the tail call is
 * `UI_SetKeepAwakePred(fn, arg)` with UI_SetKeepAwakePred an ARM function.  Declaring the
 * pointer as `GAMESYSTEM_IsSleepBlocked` rather than writing the literal 0x02012265 is what
 * gets the odd word out of the compiler; GAMESYSTEM_IsSleepBlocked's own manifest entry is
 * what attests it (`matched x1`).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_RegisterSleepCheck.c \
 *       --func GAMESYSTEM_RegisterSleepCheck --addr 0x020122A4 --cc 1.1p1 --thumb
 */
void GAMESYSTEM_RegisterSleepCheck(struct GameSystem *gameSystem)
{
    UI_SetKeepAwakePred(GAMESYSTEM_IsSleepBlocked, gameSystem);
}

void GAMESYSTEM_ReleaseSleepCheck(struct GameSystem *gameSystem)
{
    UI_SetKeepAwakePred(0, 0);
}
