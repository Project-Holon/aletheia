/*
 * file:     game_data.c
 * unit:     yes
 * function: GAME_DATA_Create, GAME_DATA_Delete, GAME_DATA_GetPlayerWork, GAME_DATA_GetField114, GAME_DATA_GetField1D4, GAME_DATA_GetLastBattleRecSlot, GAME_DATA_GetSecondUnionInfo, GAME_DATA_GetUnionInfo, GAME_DATA_GetMysteryRecvFlagA, GAME_DATA_GetMysteryRecvFlagB, GAME_DATA_TakeUnionInfo, GAME_DATA_ClearUnionInfo, GAME_DATA_GetField1A0, GAME_DATA_GetField158, GAME_DATA_GetField160, GAME_DATA_SetField160, GAME_DATA_GetField164, GAME_DATA_SetField164, GAME_DATA_GetField168, GAME_DATA_SetField168, GAME_DATA_GetField16C, GAME_DATA_SetField16C, GAME_DATA_GetField170Ptr, GAME_DATA_SetField170, GAME_DATA_SetWarpId, GAME_DATA_GetSituationWarpId, GAME_DATA_GetMapMatrix, GAME_DATA_GetMyItem, GAME_DATA_GetMyParty, GAME_DATA_GetBoxManager, GAME_DATA_GetMyStatus, GAME_DATA_GetPlayerStatusById, GAME_DATA_GetBagCursor, GAME_DATA_GetOccupyInfo, GAME_DATA_GetEventWork, GAME_DATA_GetFieldWork, GAME_DATA_GetMusicalWork, GAME_DATA_GetSeason, GAME_DATA_SetSeason, GAME_DATA_GetSubscreenMode, GAME_DATA_SetSubscreenMode, GAME_DATA_GetSubscreenType, GAME_DATA_SetSubscreenType, GAME_DATA_GetFrameRate, GAME_DATA_SetFrameRate, GAME_DATA_SetWalkCountEnabled, GAME_DATA_ResetWalkCount, GAME_DATA_IncWalkCount, GAME_DATA_IsWalkCountEnabled, GAME_DATA_GetBgmInfo, GAME_DATA_GetFieldGimmick, GAME_DATA_GetFieldMode, GAME_DATA_SetFieldMode, GAME_DATA_GetItemUseWork, GAME_DATA_InitPlayerWork, GAME_DATA_SetPlayerPosition, GAME_DATA_GetPlayerPosition, GAME_DATA_SetPlayerRail, GAME_DATA_GetPlayerRail, GAME_DATA_SetPlayerMoveForm, GAME_DATA_GetPlayerMoveForm, GAME_DATA_SetPlayerZoneId, GAME_DATA_GetPlayerZoneId, GAME_DATA_SetPlayerDirection, GAME_DATA_GetPlayerDirection, GAME_DATA_SetPlayerDirectionType, GAME_DATA_GetPlayerDirectionType, GAME_DATA_GetPlayerObjectCode, GAME_DATA_SetPlayerObjectCode, GAME_DATA_SetPlayerPalaceZoneId, GAME_DATA_GetPlayerPalaceZoneId, GAME_DATA_GetMoveModelSys, GAME_DATA_GetEnterMode, GAME_DATA_SetEnterMode, GAME_DATA_GetOwnNetId, GAME_DATA_SetOwnNetId, GAME_DATA_GetIntrudeCount, GAME_DATA_SetIntrudeCount, GAME_DATA_GetIntrudeId, GAME_DATA_SetIntrudeId, GAME_DATA_GetSlotFlag, GAME_DATA_SetSlotFlag, GAME_DATA_IsConfigFlagSet, GAME_DATA_SetConfigFlag, GAME_DATA_SetSaveFlag, GAME_DATA_CheckSaveFlag, GAME_DATA_GetRtcWork, GAME_DATA_LoadFromSave, GAME_DATA_WriteToSave, GAME_DATA_SaveStart, GAME_DATA_SaveMain, GAME_DATA_SaveCancel, GAME_DATA_IsSaving, GAME_DATA_PartSaveStart, GAME_DATA_PartSaveMain, GAME_DATA_GetSaveControl, GAME_DATA_GetSaveControlWork, GAME_DATA_GetFieldSave, GAME_DATA_GetEventState, GAME_DATA_GetCurrentEvent, GAME_DATA_SetCurrentEvent, GAME_DATA_GetSaveBlock3A, GAME_DATA_GetSaveBlock3B, GAME_DATA_GetMiscSave, GAME_DATA_GetSaveBlock1F, GAME_DATA_GetPmsWork, GAME_DATA_GetTrainerRecord, GAME_DATA_GetSaveSyncBlock, GAME_DATA_GetSaveBlock2A, GAME_DATA_GetListCursor, GAME_DATA_GetSaveBlock21, GAME_DATA_GetSaveBlock42, GAME_DATA_SetExternalWork, GAME_DATA_GetExternalWork, GAME_DATA_GetSaveBlockWork, GAME_DATA_GetBoxSave, GAME_DATA_SetSymbolMapFlag, GAME_DATA_GetSymbolMapFlag, GAME_DATA_CheckPlayTime, GAME_DATA_GetPlayTime, GAME_DATA_GetSaveBlock43, GAME_DATA_GetEventWorkFromSave
 * address:  0x020124F4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from ica_anime.c, btl_setup.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MI_CpuFill8        0x02082BCC  arm
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   GAME_DATA_IsWalkCountEnabled  0x02012A24  thumb
 *   GAME_DATA_IncWalkCount  0x020129FC  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   GAME_DATA_IsConfigFlagSet  0x02012BB0  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   _GameDataFileName  0x020A728C  data
 *   func_020070A4  0x020070A4  thumb
 *   COMM_PLAYER_SUPPORT_GetSeasonFromClock  0x0202E888  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02008844  0x02008844  thumb
 *   func_02008848  0x02008848  thumb
 *   func_0200884C  0x0200884C  thumb
 *   func_02006E40  0x02006E40  thumb
 *   GAME_DATA_InitPlayerWork  0x02012A60  thumb
 *   MYSTATUS_GetSize  0x02008468  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008730  0x02008730  thumb
 *   memcpy         0x02082D44  arm
 *   EVENTDATA_SYSTEM_Create  0x0216237C  thumb  ov010
 *   EVENTDATA_SYSTEM_Clear  0x021623DC  thumb  ov010
 *   GAME_DATA_GetEventWorkFromSave  0x02012FE4  thumb
 *   MAP_MATRIX_Create  0x02159B48  thumb  ov010
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   FLDMMDL_CreateSys  0x0216CC58  thumb  ov010
 *   FIELD_SOUND_SYSTEM_Create  0x02028844  thumb
 *   FIELD_STATUS_Create  0x02014428  thumb
 *   func_02008254  0x02008254  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02007AA4  0x02007AA4  thumb
 *   WIFILIST_Create  0x020097C4  thumb
 *   INTRUDE_InitOccupy  0x0200BDE4  thumb
 *   EVENT_FIELD_PROCLINK_InitEventdataSystem  0x02161D98  thumb  ov010
 *   func_0200857C  0x0200857C  thumb
 *   func_020071E4  0x020071E4  thumb
 *   FIELD_ENCOUNT_ST_Create  0x0215E31C  thumb  ov010
 *   PMS_DRAW_ClearWork  0x0202E43C  thumb
 *   GAME_DATA_LoadFromSave  0x02012C18  thumb
 *   COMM_PLAYER_SUPPORT_Create  0x0202E770  thumb
 *   BEACON_STATUS_Create  0x0202751C  thumb
 *   CALENDER_Create  0x021647A0  thumb  ov010
 *   CALENDER_Delete   0x021647D8  thumb  ov010
 *   BEACON_STATUS_Delete   0x02027584  thumb
 *   func_0202E794   0x0202E794  thumb
 *   FIELD_ENCOUNT_ST_Delete   0x0215E334  thumb  ov010
 *   func_02006E64   0x02006E64  thumb
 *   func_02007AC8   0x02007AC8  thumb
 *   FLDMMDL_DeleteSys   0x0216CCB0  thumb  ov010
 *   MAP_MATRIX_Delete   0x02159BBC  thumb  ov010
 *   EVENTDATA_SYSTEM_Delete   0x021623BC  thumb  ov010
 *   FIELD_STATUS_Delete   0x02014444  thumb
 *   FIELD_SOUND_SYSTEM_Delete   0x0202889C  thumb
 *   EVENT_FIELD_PROCLINK_CheckZoneFlag  0x02161D64  thumb  ov010
 *   func_02008850  0x02008850  thumb
 *   GAME_DATA_SetConfigFlag  0x02012BC8  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   MUSICAL_SHOT_GetFromSave  0x0200A864  thumb
 *   MUSICAL_SHOT_GetTitle  0x0200A890  thumb
 *   MUSICAL_SHOT_GetExtraData  0x0200A898  thumb
 *   GAME_DATA_GetField114         0x020127A4  thumb
 *   sPlayerDirectionAngles  0x0209DFA8  data  a2
 *   CONFIG_GetBattleFlag  0x02008448  thumb
 *   CONFIG_SetBattleFlag  0x02008450  thumb
 *   RECENT_ID_LIST_SAVEDATA_GetBlock  0x0200C40C  thumb
 *   RECENT_ID_LIST_SAVEDATA_SetId  0x0200C418  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02008808  0x02008808  thumb
 *   func_020088B8  0x020088B8  thumb
 *   func_0200EEAC  0x0200EEAC  thumb
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   INTRUDE_LoadOccupy  0x0200BE6C  thumb
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   MUSICAL_SHOT_CopyPhotoRev  0x0200A884  thumb
 *   GIMMICK_WORK_Load  0x0200B3C8  thumb
 *   func_0200893C  0x0200893C  thumb
 *   func_02008954  0x02008954  thumb
 *   func_02009D08  0x02009D08  thumb
 *   func_020097F0  0x020097F0  thumb
 *   func_02008964  0x02008964  thumb
 *   func_0200E89C  0x0200E89C  thumb
 *   func_02008748  0x02008748  thumb
 *   func_0200863C  0x0200863C  thumb
 *   func_020087E8  0x020087E8  thumb
 *   func_02008860  0x02008860  thumb
 *   NET_DEVICE_TABLE_BuildFromProducer  0x0200EE64  thumb
 *   INTRUDE_StoreOccupy  0x0200BE54  thumb
 *   MUSICAL_SHOT_CopyPhoto  0x0200A870  thumb
 *   GIMMICK_WORK_Save  0x0200B3B0  thumb
 *   func_0200892C  0x0200892C  thumb
 *   func_0200894C  0x0200894C  thumb
 *   func_0200895C  0x0200895C  thumb
 *   func_0200E884  0x0200E884  thumb
 *   func_02008658  0x02008658  thumb
 *   TRADE_HISTORY_GetFromSave  0x02009EC8  thumb
 *   func_020089C0  0x020089C0  thumb
 *   GAME_SYNC_GetBlock  0x02009448  thumb
 *   func_02007B44  0x02007B44  thumb
 *   SAVE_CONTROL_StartSave  0x02007150  thumb
 *   SAVE_CONTROL_MainSave  0x02007168  thumb
 *   SAVE_CONTROL_CancelSave  0x020071A8  thumb
 *   SAVE_CONTROL_BeginExtraSaveWrite  0x02007374  thumb
 *   SAVE_CONTROL_StepExtraSaveWrite  0x020073B0  thumb
 *   CONFIG_Create  0x020082EC  thumb
 *   WIH_DWC_PauseTimers  0x0201042C  thumb
 *   WIH_DWC_ResumeTimers  0x02010444  thumb
 *   GFL_USE_IsLoaderBusy  0x02005C64  thumb
 *   RECENT_ID_LIST_SAVEDATA_GetBlockFromSys  0x0200C404  thumb
 *   RECENT_ID_LIST_SAVEDATA_ContainsId  0x0200C44C  thumb
 *   BEACON_GetBlock  0x0200C0F0  thumb
 *   GAME_DATA_GetField1A0  0x0201283C  thumb
 *   UI_SetKeepAwakeFlagsGlobal  0x02034F84  arm
 *   UI_ClearKeepAwakeFlagsGlobal  0x02034FB8  arm
 *   UI_TestKeepAwakeFlagsGlobal  0x02034FE8  arm
 *   UI_SetFlags39Global  0x0203516C  arm
 *   UI_ClearFlags39Global  0x020351A0  arm
 */
#include "btl_setup_types.h"
#include "script_vm_types.h"
#include "ica_anime_shared_types.h"
#include "game_data_shared_types.h"

struct BagCursor;

struct Situation;

extern u32 GFL_HEAP_Free(void *memory);

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct SaveControl *func_020070A4(void);

extern u8    COMM_PLAYER_SUPPORT_GetSeasonFromClock(void);

extern struct Situation *func_02008854(struct SaveControl *saveControl);

extern struct Location *func_02008844(u32 situation);

extern struct Location *func_02008848(struct Situation *situation);

extern struct Location *func_0200884C(struct Situation *situation);

extern struct BagCursor *func_02006E40(u32 heapId);

void GAME_DATA_InitPlayerWork(struct PlayerWork *player);

extern int MYSTATUS_GetSize(void);

struct PlayerStatus *GAME_DATA_GetMyStatus(struct GameData *gd);

extern struct PlayerStatus *func_02008730(struct SaveControl *saveControl);

extern void *memcpy(void *dst, const void *src, u32 size);

extern int EVENTDATA_SYSTEM_Create(int heapId);

extern void EVENTDATA_SYSTEM_Clear(void *eventData);

void *GAME_DATA_GetEventWorkFromSave(struct SaveControl *save);

extern u16 *MAP_MATRIX_Create(int heapId);

extern void *SAVE_CONTROL_GetBlock(struct SaveControl *save, u32 blockId);

extern void *FLDMMDL_CreateSys(int heapId, int count, int saveBlock);

extern struct BgmInfo *FIELD_SOUND_SYSTEM_Create(struct GameData *gameData, u32 heapId);

extern u32   FIELD_STATUS_Create(int heapId);

extern void *func_02008254(u32 heapId);

extern struct Config *func_0200873C(struct SaveControl *saveControl);

extern u32 *func_02007AA4(u32 heapId, u32 saveControl);

extern void *WIFILIST_Create(int heapId);

extern void INTRUDE_InitOccupy(void *slot);

extern void  EVENT_FIELD_PROCLINK_InitEventdataSystem(void *unionInfo);

extern void *func_0200857C(u32 heapId);

extern u8 func_020071E4(struct SaveControl *save);

extern void *FIELD_ENCOUNT_ST_Create(u32 heapId);

extern void  PMS_DRAW_ClearWork(void *rtcWork);

void GAME_DATA_LoadFromSave(struct GameData *gd);

extern void *COMM_PLAYER_SUPPORT_Create(void *heapId);

extern u32   BEACON_STATUS_Create(int heapId, u32 flags);

extern u8 *CALENDER_Create(struct GameData *gameData, u32 heapId);

extern int CALENDER_Delete(int musicalWork);

extern void BEACON_STATUS_Delete(u32 itemUseWork);

extern void func_0202E794(void *pmsWork);

extern void FIELD_ENCOUNT_ST_Delete(void *fieldGimmick);

extern void func_02006E64(struct BagCursor *bagCursor);

extern void func_02007AC8(void *boxManager);

extern int FLDMMDL_DeleteSys(int occupyInfo);

extern void MAP_MATRIX_Delete(void *fieldWork);

extern int EVENTDATA_SYSTEM_Delete(int eventData);

extern void FIELD_STATUS_Delete(u32 moveModelSys);

extern void FIELD_SOUND_SYSTEM_Delete(struct BgmInfo *bgmInfo);

struct MusicalShot;

extern struct UnionInfo *MUSICAL_SHOT_GetFromSave(struct SaveControl *save);

extern u16 *MUSICAL_SHOT_GetTitle(struct UnionInfo *shot);

extern u8 *MUSICAL_SHOT_GetExtraData(struct UnionInfo *shot);

extern void MI_CpuCopy8(void *dst, const void *src, u32 size);

extern int EVENT_FIELD_PROCLINK_CheckZoneFlag(int unionInfo);

extern u16 *func_02008850(struct Situation *situation);

struct GameData *GAME_DATA_Create(u16 heapId);

void GAME_DATA_Delete(struct GameData *gameData);

struct PlayerWork *GAME_DATA_GetPlayerWork(struct GameData *gameData, int index);

extern struct PlayerWork *GAME_DATA_GetField114(struct GameData *gd);

void *GAME_DATA_GetField1D4(struct GameData *gameData, u32 index);

extern void *GAME_DATA_GetLastBattleRecSlot(struct GameData *gd);

extern struct UnionInfo *GAME_DATA_GetSecondUnionInfo(struct GameData *gd);

u8 *GAME_DATA_GetUnionInfo(struct GameData *gameData, u32 index);

u16 *GAME_DATA_GetMysteryRecvFlagA(struct GameData *gameData);

u8 *GAME_DATA_GetMysteryRecvFlagB(struct GameData *gameData);

void GAME_DATA_TakeUnionInfo(struct GameData *gameData, void *dst);

void GAME_DATA_ClearUnionInfo(struct GameData *gameData);

extern struct FieldState *GAME_DATA_GetField1A0(const struct GameData *gd);

void *GAME_DATA_GetField158(const struct GameData *gameData);

struct Location *GAME_DATA_GetField160(const struct GameData *gameData);

void GAME_DATA_SetField160(struct GameData *gameData, const struct Location *location);

struct Location *GAME_DATA_GetField164(const struct GameData *gameData);

void GAME_DATA_SetField164(struct GameData *gameData, const struct Location *location);

struct Location *GAME_DATA_GetField168(const struct GameData *gameData);

void GAME_DATA_SetField168(struct GameData *gameData, const struct Location *location);

struct Location *GAME_DATA_GetField16C(const struct GameData *gameData);

void GAME_DATA_SetField16C(struct GameData *gameData, const struct Location *location);

struct Location *GAME_DATA_GetField170Ptr(struct GameData *gameData);

void GAME_DATA_SetField170(struct GameData *gameData, const struct Location *location);

void GAME_DATA_SetWarpId(const struct GameData *gameData, u16 warpId);

extern const char _GameDataFileName[];

/*
 *           have exactly ONE branch anywhere in the image and it is the `bl`
 *           inside this function (0x020125AA, 0x020125E0, 0x02012698,
 *           0x020126DC), so the `label` class has no outside witness.  Two
 *           overlays (ov009, ov010) hold each address, so even with the
 *           `ov010` region hint on the symbols: line the witness condition
 *           still fails.  `sole-ref/code` cannot carry them either: it reads
 *           `evidence().labels`, which is the ARM9 listing only, so an
 *           overlay-resident function start is outside its index.
 *           `tu --suggest-split` confirms no cut helps ("best partition:
 *           0 piece(s), 1 function(s) left out") -- the only witnesses are
 *           the calls that need them.  Same wall as src/pending/GAME_DATA_Delete.c
 *           (the matching destructor), which is blocked on five siblings of
 *           these same overlay addresses.
 *           Every one of the 528 concrete bytes is correct; only the four
 *           relocation FIELDS stay wildcarded.
 * The constructor of the big game_data object destroyed by GAME_DATA_Delete.
 * 0x6B0 bytes from GFL_HEAP_Alloc(heap, 0x6B0, 1, "game_data.c", 0xAD); the
 * field offsets are the destructor's, read through a u8 * so the compiler
 * derives them all from the two pooled/scaled bases 0x1C4 (= 0x71 << 2),
 * 0x158 (= 0x56 << 2) and 0x6AC.
 *
 * THE TWO LEVERS (both found this wave; 528 bytes size-exact on the first
 * write, then 176 concrete-byte mismatches down to 0 in two changes):
 *
 * 1. THE HEAP PARAMETER IS `u16`, NOT `int`.  With `int` the seven prologue
 *    instructions are the right seven in the wrong order: mwcc emits the
 *    `str r0, [sp, #4]` spill LAST, after `movs r1,#0xad / str r1,[sp] /
 *    movs r1,#0x6b / ldr r3,pool / lsls r1,r1,#4 / movs r2,#1`, while the
 *    original emits it FIRST.  A `u16` parameter has a narrowed stack home
 *    the marshaller must establish before it builds the other arguments,
 *    which is exactly the original's order.  No spelling of the body moves
 *    it: `int heap = a0;` as the first local, as the last local, hoisting
 *    0x6B0 into a named `size`, and 300 single mutations of the permuter in
 *    --mode hill ("no single mutation improves") all leave the same seven.
 *    The permuter's --mode anneal found it as `type:p(a0:int->u16)` in 286
 *    compiles; the sibling caller src/matched/CONFIG_Create.c independently
 *    corroborates it, passing `(unsigned short)a0` to the same allocator.
 *
 * 2. THE memcpy ARGUMENTS ARE EVALUATED THROUGH TWO NAMED LOCALS, in the
 *    original's order: `n = MYSTATUS_GetSize(); src = GAME_DATA_GetMyStatus(p);` and
 *    only then `memcpy(func_02008730(*(u32 *)p), src, n)`.  Written as one
 *    nested expression mwcc schedules func_02008730 first and the whole
 *    tail of the function reallocates: that alone was 169 of the 176
 *    mismatches.  (docs/idioms/an-inline-call-argument-is-scheduled-per-site-
 *    a-local-is-not.md)
 *
 * Verified with:
 *   python3 tools/match.py one --src src/pending/GAME_DATA_Create.c \
 *       --func GAME_DATA_Create --addr 0x020124F4 --cc 1.1p1 --thumb
 */
struct GameData *GAME_DATA_Create(u16 heapId)
{
    struct GameData *gameData;
    int i;
    u32 statusSize;
    struct PlayerStatus *status;
    void *eventData;

    gameData = GFL_HEAP_Alloc(heapId, sizeof(struct GameData), 1, _GameDataFileName, 0xAD);
    gameData->saveControl = func_020070A4();
    gameData->season = COMM_PLAYER_SUPPORT_GetSeasonFromClock();
    gameData->subscreenType = 0;

    gameData->situation = (u32)func_02008854(gameData->saveControl);
    gameData->startLocation = func_02008844(gameData->situation);
    gameData->entranceLocation = func_02008844(gameData->situation);
    gameData->specialLocation = func_02008848((struct Situation *)gameData->situation);
    gameData->escapeLocation = func_0200884C((struct Situation *)gameData->situation);

    gameData->bagCursor = (u32)func_02006E40(heapId);

    for (i = 0; i < 5; i++) {
        GAME_DATA_InitPlayerWork(&gameData->playerWork[i]);
    }

    statusSize = MYSTATUS_GetSize();
    status = GAME_DATA_GetMyStatus(gameData);
    memcpy(func_02008730(gameData->saveControl), status, statusSize);

    gameData->eventData = eventData = (void *)EVENTDATA_SYSTEM_Create(heapId);
    EVENTDATA_SYSTEM_Clear(eventData);
    gameData->eventWork = GAME_DATA_GetEventWorkFromSave(gameData->saveControl);
    gameData->fieldWork = (u32)MAP_MATRIX_Create(heapId);
    gameData->occupyInfo = FLDMMDL_CreateSys(heapId, 0x40, (u32)SAVE_CONTROL_GetBlock(gameData->saveControl, 0x33));
    gameData->bgmInfo = (u32)FIELD_SOUND_SYSTEM_Create(gameData, heapId);
    gameData->moveModelSys = (void *)FIELD_STATUS_Create(heapId);
    gameData->mapMatrix = (u32)func_02008254(heapId);
    gameData->myItem = SAVE_CONTROL_GetBlock(gameData->saveControl, 0x19);
    gameData->myParty = SAVE_CONTROL_GetBlock(gameData->saveControl, 0x1A);
    gameData->config = func_0200873C(gameData->saveControl);
    gameData->boxManager = (u32)func_02007AA4(heapId, (u32)gameData->saveControl);
    gameData->wifiList = (u32)WIFILIST_Create(heapId);

    for (i = 0; i < 4; i++) {
        INTRUDE_InitOccupy(gameData->battleRecSlot[i]);
    }

    for (i = 0; i < 2; i++) {
        EVENT_FIELD_PROCLINK_InitEventdataSystem(gameData->unionInfo[i]);
    }

    gameData->playTime = func_0200857C(heapId);
    gameData->saveStatus = 0;
    func_020071E4(gameData->saveControl);

    gameData->fieldGimmick = (u32)FIELD_ENCOUNT_ST_Create(heapId);
    PMS_DRAW_ClearWork(gameData->rtcWork);
    GAME_DATA_LoadFromSave(gameData);
    gameData->eventState = 0;
    gameData->currentEvent = 0;
    gameData->pmsWork = (int)COMM_PLAYER_SUPPORT_Create((void *)heapId);
    gameData->itemUseWork = BEACON_STATUS_Create(heapId, 0x8001);
    gameData->musicalWork = (u32)CALENDER_Create(gameData, heapId);
    gameData->listCursor = 0;
    gameData->externalWork = 0;

    return gameData;
}

/*
 * note:     wave 16: promoted.  0x0215E334 and 0x02159BBC are unlabelled ov010
 *           ENV_SetResourceSet thunks matched in src/matched/FIELD_ENCOUNT_ST_Delete.c and
 *           MAP_MATRIX_Delete.c (`matched, overlay`); 0x021647D8, 0x0216CCB0 and
 *           0x021623BC resolve as sole-ref/code (overlay).
 * A destructor: fifteen pointer fields of one big object handed to fifteen
 * different release functions, then the object itself to the base deleter
 * 0x020307B0 (the ARM `blx` target, called three times).
 *
 * The literal 0x6AC is pooled once and every other offset is derived from it
 * with `adds`/`subs` (0x690, 0x68C, 0x684, 0x5E4), which is why the second
 * group starts from 0x69 << 2: the offsets are the source's array indices
 * scaled by four, and the field reads are `p[0x1AB]`, `p[0x1A4]`, ... in a
 * `u32 *`.  Writing the fields as byte offsets through a `u8 *` reproduces
 * the same derived-constant chain.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_DATA_Delete.c \
 *       --func GAME_DATA_Delete --addr 0x02012704 --cc 1.1p1 --thumb
 */
void GAME_DATA_Delete(struct GameData *gameData)
{
    GFL_HEAP_Free(gameData->playTime);
    CALENDER_Delete(gameData->musicalWork);
    BEACON_STATUS_Delete(gameData->itemUseWork);
    func_0202E794((void *)gameData->pmsWork);
    FIELD_ENCOUNT_ST_Delete((void *)gameData->fieldGimmick);
    func_02006E64((struct BagCursor *)gameData->bagCursor);
    GFL_HEAP_Free((void *)gameData->wifiList);
    func_02007AC8((void *)gameData->boxManager);
    GFL_HEAP_Free((void *)gameData->mapMatrix);
    FLDMMDL_DeleteSys((int)gameData->occupyInfo);
    MAP_MATRIX_Delete((void *)gameData->fieldWork);
    EVENTDATA_SYSTEM_Delete((int)gameData->eventData);
    FIELD_STATUS_Delete((u32)gameData->moveModelSys);
    FIELD_SOUND_SYSTEM_Delete((struct BgmInfo *)gameData->bgmInfo);
    GFL_HEAP_Free(gameData);
}

struct PlayerWork *GAME_DATA_GetPlayerWork(struct GameData *gameData, int index)
{
    return &gameData->playerWork[index];
}

/*
 * Two address-of-member accessors on the same save-data block, neither of
 * which saves lr, so neither carries a label
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md) and the pair
 * has to be worked as one unit.
 *
 * Both offsets are out of Thumb immediate range and are built as
 * `movs #n / lsls #2`, which is why 0x114 appears as 0x45 and 0x1d4 as 0x75.
 * The second takes an index into a 16-byte array that starts at +0x1d4.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020127A4.c \
 *       --addr 0x020127A4 --thumb
 */
struct PlayerWork *GAME_DATA_GetField114(struct GameData *gameData)
{
    return &gameData->playerWork[4];
}

void *GAME_DATA_GetField1D4(struct GameData *gameData, u32 index)
{
    return gameData->battleRecSlot[index];
}

/*
 * Promoted from src/pending/GAME_DATA_GetLastBattleRecSlot.c (was MATCH, blocker 0x020127AC,
 * declared by the naming convention, which defaults to ARM).  The pool word
 * is 0x020127AD, so the target is Thumb; declared `thumb` the `matched`
 * class fires on the EXACT unit entry for 0x020127AC
 * (src/matched/unit_020127A4.c, which names it as a member function) and
 * the site resolves with no change to the C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_DATA_GetLastBattleRecSlot.c \
 *       --func GAME_DATA_GetLastBattleRecSlot --addr 0x020127B8 --cc 1.1p1 --thumb
 */
void *GAME_DATA_GetLastBattleRecSlot(struct GameData *gameData)
{
    return GAME_DATA_GetField1D4(gameData, 3);
}

/*
 * Promoted from src/pending/GAME_DATA_GetSecondUnionInfo.c (was MATCH, blocker 0x020127D0,
 * declared by the naming convention, i.e. ARM).  Two things had to happen:
 * the pool word is 0x020127D1 so the target is Thumb, and
 * src/matched/GAME_DATA_GetUnionInfo.c has to exist as an EXACT entry for the
 * `matched` class to reach it - both done, and the C never changed.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_DATA_GetSecondUnionInfo.c \
 *       --func GAME_DATA_GetSecondUnionInfo --addr 0x020127C4 --cc 1.1p1 --thumb
 */
struct UnionInfo *GAME_DATA_GetSecondUnionInfo(struct GameData *gameData)
{
    return (struct UnionInfo *)GAME_DATA_GetUnionInfo(gameData, 1);
}

/*
 * Address-of-element on a 0x1E8-byte record array at +0x214: the pair of
 * constants 0x214 and 0x1E8 differ by 0x2c, so the compiler materialises the
 * larger one from a pool-free `movs`/`lsls` pair and derives the stride with
 * a `subs` (see docs/idioms/a-constant-pair-...).  Entry attested by the
 * pool word 0x020127D1 that GAME_DATA_GetSecondUnionInfo loads.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_DATA_GetUnionInfo.c \
 *       --func GAME_DATA_GetUnionInfo --addr 0x020127D0 --cc 1.1p1 --thumb
 */
u8 *GAME_DATA_GetUnionInfo(struct GameData *gameData, u32 index)
{
    return gameData->unionInfo[index];
}

u16 *GAME_DATA_GetMysteryRecvFlagA(struct GameData *gameData)
{
    return MUSICAL_SHOT_GetTitle(MUSICAL_SHOT_GetFromSave(gameData->saveControl));
}

u8 *GAME_DATA_GetMysteryRecvFlagB(struct GameData *gameData)
{
    return MUSICAL_SHOT_GetExtraData(MUSICAL_SHOT_GetFromSave(gameData->saveControl));
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_DATA_TakeUnionInfo.c \
 *       --func GAME_DATA_TakeUnionInfo --addr 0x02012800 --cc 1.1p1 --thumb
 */
void GAME_DATA_TakeUnionInfo(struct GameData *gameData, void *dst)
{
    MI_CpuCopy8(dst, gameData->unionInfo[0], sizeof(gameData->unionInfo[0]));
    EVENT_FIELD_PROCLINK_CheckZoneFlag((int)gameData->unionInfo[0]);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_DATA_ClearUnionInfo.c \
 *       --func GAME_DATA_ClearUnionInfo --addr 0x0201281C --cc 1.1p1 --thumb
 */
void GAME_DATA_ClearUnionInfo(struct GameData *gameData)
{
    MI_CpuFill8(gameData->unionInfo[0], 0, sizeof(gameData->unionInfo[0]));
    EVENT_FIELD_PROCLINK_CheckZoneFlag((int)gameData->unionInfo[1]);
}

/*
 *           GAME_DATA_GetField164, GAME_DATA_SetField164, GAME_DATA_GetField168, GAME_DATA_SetField168,
 *           GAME_DATA_GetField16C, GAME_DATA_SetField16C, GAME_DATA_GetField170Ptr, GAME_DATA_SetField170,
 *           GAME_DATA_SetWarpId
 *
 * 214 bytes, 0x0201283C..0x02012914, 13 functions, five of them labelled.  It
 * abuts src/matched/unit_02012924.c at the far end, across the one function
 * the cut below moved out.
 *
 * Four pointer fields at +0x160, +0x164, +0x168 and +0x16C and one inline
 * record at +0x170 all hold the same 28-byte thing, and each has a getter and
 * a setter.  28 bytes is three `ldm`/`stm` pairs plus a trailing `ldr`/`str`,
 * which is docs/idioms/aggregate-assignment-is-ldm-stm.md; the record has to
 * be declared four-aligned (struct Location, u32 words[7], not u8 [28]) or the copy becomes a
 * byte loop.  The four pointer setters write through the pointer
 * (`*gameData->startLocation = *location`) and the fifth writes the inline record
 * (`gameData->warpLocation = *location`), which is the difference between the `ldr r2, [r0, r1]`
 * and the `adds r2, r0, r1` that opens each.
 *
 * The file is cut at 0x02012914 rather than at 0x02012924, which is where the
 * next file starts, because GAME_DATA_SetWarpId and GAME_DATA_GetSituationWarpId are the only two
 * callers of func_02008850 in the image: one range holding both leaves the
 * `label` class no witness and the whole unit reads MATCH with every concrete
 * byte right.  Split, each is the other's outside witness and both are EXACT.
 * That is docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md, and
 * the other half is src/matched/unit_02012914.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201283C.c \
 *       --addr 0x0201283C --thumb
 */
struct FieldState *GAME_DATA_GetField1A0(const struct GameData *gameData)
{
    return (struct FieldState *)gameData->wifiList;
}

void *GAME_DATA_GetField158(const struct GameData *gameData)
{
    return gameData->eventData;
}

struct Location *GAME_DATA_GetField160(const struct GameData *gameData)
{
    return gameData->startLocation;
}

void GAME_DATA_SetField160(struct GameData *gameData, const struct Location *location)
{
    *gameData->startLocation = *location;
}

struct Location *GAME_DATA_GetField164(const struct GameData *gameData)
{
    return gameData->entranceLocation;
}

void GAME_DATA_SetField164(struct GameData *gameData, const struct Location *location)
{
    *gameData->entranceLocation = *location;
}

struct Location *GAME_DATA_GetField168(const struct GameData *gameData)
{
    return gameData->specialLocation;
}

void GAME_DATA_SetField168(struct GameData *gameData, const struct Location *location)
{
    *gameData->specialLocation = *location;
}

struct Location *GAME_DATA_GetField16C(const struct GameData *gameData)
{
    return gameData->escapeLocation;
}

void GAME_DATA_SetField16C(struct GameData *gameData, const struct Location *location)
{
    *gameData->escapeLocation = *location;
}

struct Location *GAME_DATA_GetField170Ptr(struct GameData *gameData)
{
    return &gameData->warpLocation;
}

void GAME_DATA_SetField170(struct GameData *gameData, const struct Location *location)
{
    gameData->warpLocation = *location;
}

void GAME_DATA_SetWarpId(const struct GameData *gameData, u16 warpId)
{
    *func_02008850((struct Situation *)gameData->situation) = warpId;
}

struct FieldState;

struct UnionInfo;

struct FieldSaveData;

extern unsigned int CONFIG_GetBattleFlag(struct Config *config);

extern void CONFIG_SetBattleFlag(struct Config *config, int on);

extern void *RECENT_ID_LIST_SAVEDATA_GetBlock(struct SaveControl *save);

extern void RECENT_ID_LIST_SAVEDATA_SetId(void *flags, u32 id, u32 on);

extern void *RECENT_ID_LIST_SAVEDATA_GetBlockFromSys(struct SaveControl *save);

extern void RECENT_ID_LIST_SAVEDATA_ContainsId(void *flags, u32 id);

extern void func_02008808(struct SaveControl *save, struct PlayerWork *dest);

extern void func_020088B8(struct SaveControl *save, struct PlayerWork *dest);

extern void func_0200EEAC(void *occupy, void *block);

extern void INTRUDE_LoadOccupy(struct SaveControl *save, u16 *dest);

extern void MUSICAL_SHOT_CopyPhotoRev(const struct UnionInfo *src, struct UnionInfo *dest);

extern void GIMMICK_WORK_Load(struct SaveControl *save, const struct FieldSaveData *src);

extern void func_0200893C(const struct Situation *situation, void *dest);

extern void func_02008954(const struct Situation *situation, u8 *out);

extern struct FieldState *func_02009D08(struct SaveControl *save);

extern void func_020097F0(const struct FieldState *src, struct FieldState *dest);

extern void func_02008964(const struct Situation *situation, u8 *out);

extern void func_0200E89C(struct SaveControl *save, void *dest);

extern struct PlayTime *func_02008748(struct SaveControl *save);

extern void func_0200863C(struct PlayTime *dest, const struct PlayTime *src);

extern void func_020087E8(struct SaveControl *save, const struct PlayerWork *src);

extern void func_02008860(struct SaveControl *save, const struct PlayerWork *src);

extern void NET_DEVICE_TABLE_BuildFromProducer(void *occupy, void *block);

extern void INTRUDE_StoreOccupy(struct SaveControl *save, const u16 *src);

extern void MUSICAL_SHOT_CopyPhoto(struct UnionInfo *dest, const struct UnionInfo *src);

extern void GIMMICK_WORK_Save(struct FieldSaveData *dest, struct SaveControl *save);

extern void func_0200892C(struct Situation *situation, const void *src);

extern void func_0200894C(struct Situation *situation, u8 value);

extern void func_0200895C(struct Situation *situation, u8 value);

extern void func_0200E884(void *src, struct SaveControl *save);

extern void func_02008658(struct PlayTime *playTime);

extern void WIH_DWC_PauseTimers(void);

extern void UI_SetFlags39Global();

extern int SAVE_CONTROL_StartSave(struct SaveControl *save);

extern int  GFL_USE_IsLoaderBusy(void);

extern u32 SAVE_CONTROL_MainSave(struct SaveControl *save);

extern int UI_ClearFlags39Global(u32 v);

extern void WIH_DWC_ResumeTimers(void);

extern int SAVE_CONTROL_CancelSave(struct SaveControl *save);

extern int  UI_TestKeepAwakeFlagsGlobal(u32 soundId);

extern void UI_ClearKeepAwakeFlagsGlobal(u32 soundId);

extern void UI_SetKeepAwakeFlagsGlobal(int soundId);

extern void SAVE_CONTROL_BeginExtraSaveWrite(struct SaveControl *save, u32 blockId);

extern int SAVE_CONTROL_StepExtraSaveWrite(struct SaveControl *save, u32 blockId);

extern void *BEACON_GetBlock(struct SaveControl *save);

extern void *TRADE_HISTORY_GetFromSave(struct SaveControl *save);

extern void *func_020089C0(struct SaveControl *save);

extern void *GAME_SYNC_GetBlock(struct SaveControl *save);

extern void *func_02007B44(struct SaveControl *save);

extern u32 func_020085D4(struct PlayTime *playTime, u32 limit);

extern const u16 sPlayerDirectionAngles[];

u16 GAME_DATA_GetSituationWarpId(const struct GameData *gd);

u32 GAME_DATA_GetMapMatrix(const struct GameData *gd);

void *GAME_DATA_GetMyItem(const struct GameData *gd);

void *GAME_DATA_GetMyParty(const struct GameData *gd);

u32 GAME_DATA_GetBoxManager(const struct GameData *gd);

struct PlayerStatus *GAME_DATA_GetPlayerStatusById(struct GameData *gd, u32 playerId);

u32 GAME_DATA_GetBagCursor(const struct GameData *gd);

void *GAME_DATA_GetOccupyInfo(const struct GameData *gd);

void *GAME_DATA_GetEventWork(const struct GameData *gd);

u32 GAME_DATA_GetFieldWork(const struct GameData *gd);

u32 GAME_DATA_GetMusicalWork(const struct GameData *gd);

u8 GAME_DATA_GetSeason(const struct GameData *gd);

void GAME_DATA_SetSeason(struct GameData *gd, u8 value);

u8 GAME_DATA_GetSubscreenMode(const struct GameData *gd);

void GAME_DATA_SetSubscreenMode(struct GameData *gd, u8 value);

u8 GAME_DATA_GetSubscreenType(const struct GameData *gd);

void GAME_DATA_SetSubscreenType(struct GameData *gd, u32 value);

u8 GAME_DATA_GetFrameRate(const struct GameData *gd);

void GAME_DATA_SetFrameRate(struct GameData *gd, u8 value);

void GAME_DATA_SetWalkCountEnabled(struct GameData *gd, u8 enable);

void GAME_DATA_ResetWalkCount(struct GameData *gd);

u8 GAME_DATA_IncWalkCount(struct GameData *gd);

u8 GAME_DATA_IsWalkCountEnabled(const struct GameData *gd);

u32 GAME_DATA_GetBgmInfo(const struct GameData *gd);

u32 GAME_DATA_GetFieldGimmick(const struct GameData *gd);

u32 GAME_DATA_GetFieldMode(const struct GameData *gd);

void GAME_DATA_SetFieldMode(struct GameData *gd, u32 value);

u32 GAME_DATA_GetItemUseWork(const struct GameData *gd);

void GAME_DATA_SetPlayerPosition(struct PlayerWork *player, const struct PlayerPosition *pos);

struct PlayerPosition *GAME_DATA_GetPlayerPosition(struct PlayerWork *player);

void GAME_DATA_SetPlayerRail(struct PlayerWork *player, const struct RailLocationWords *rail);

struct RailLocationWords *GAME_DATA_GetPlayerRail(struct PlayerWork *player);

void GAME_DATA_SetPlayerMoveForm(struct PlayerWork *player, u8 form);

u8 GAME_DATA_GetPlayerMoveForm(const struct PlayerWork *player);

struct PlayerWork *GAME_DATA_SetPlayerZoneId(struct PlayerWork *player, u16 zoneId);

u16 GAME_DATA_GetPlayerZoneId(const struct PlayerWork *player);

void GAME_DATA_SetPlayerDirection(struct PlayerWork *player, int direction);

u16 GAME_DATA_GetPlayerDirection(const struct PlayerWork *player);

void GAME_DATA_SetPlayerDirectionType(struct PlayerWork *player, int dirId);

u32 GAME_DATA_GetPlayerDirectionType(const struct PlayerWork *player);

u32 GAME_DATA_GetPlayerObjectCode(const struct PlayerWork *player);

void GAME_DATA_SetPlayerObjectCode(struct PlayerWork *player, u32 code);

void GAME_DATA_SetPlayerPalaceZoneId(struct PlayerWork *player, u16 zoneId);

u16 GAME_DATA_GetPlayerPalaceZoneId(const struct PlayerWork *player);

void *GAME_DATA_GetMoveModelSys(const struct GameData *gd);

u8 GAME_DATA_GetEnterMode(const struct GameData *gd);

void GAME_DATA_SetEnterMode(struct GameData *gd, u8 value);

u8 GAME_DATA_GetOwnNetId(const struct GameData *gd);

void GAME_DATA_SetOwnNetId(struct GameData *gd, u8 value);

int GAME_DATA_GetIntrudeCount(const struct GameData *gd);

struct GameData *GAME_DATA_SetIntrudeCount(struct GameData *gd, u8 count);

u8 GAME_DATA_GetIntrudeId(const struct GameData *gd);

void GAME_DATA_SetIntrudeId(struct GameData *gd, u32 value);

u8 GAME_DATA_GetSlotFlag(const struct GameData *gd, u32 slot);

void GAME_DATA_SetSlotFlag(struct GameData *gd, int slot, u8 value);

u32 GAME_DATA_IsConfigFlagSet(const struct GameData *gd);

void GAME_DATA_SetConfigFlag(struct GameData *gd, int on);

void GAME_DATA_SetSaveFlag(struct GameData *gd, u32 id, u32 on);

void GAME_DATA_CheckSaveFlag(struct GameData *gd, u32 id);

u8 *GAME_DATA_GetRtcWork(struct GameData *gd);

void GAME_DATA_WriteToSave(struct GameData *gd);

int GAME_DATA_SaveStart(struct GameData *gd);

int GAME_DATA_SaveMain(struct GameData *gd);

void GAME_DATA_SaveCancel(struct GameData *gd);

u8 GAME_DATA_IsSaving(const struct GameData *gd);

void GAME_DATA_PartSaveStart(struct GameData *gd, u32 blockId);

int GAME_DATA_PartSaveMain(struct GameData *gd, int blockId);

struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gd);

struct SaveControl *GAME_DATA_GetSaveControlWork(struct GameData *gd);

u8 *GAME_DATA_GetFieldSave(struct GameData *gd);

u8 *GAME_DATA_GetEventState(struct GameData *gd);

void *GAME_DATA_GetCurrentEvent(struct GameData *gd);

struct GameData *GAME_DATA_SetCurrentEvent(struct GameData *gd, void *event);

void *GAME_DATA_GetSaveBlock3A(struct GameData *gd);

void *GAME_DATA_GetSaveBlock3B(struct GameData *gd);

void *GAME_DATA_GetMiscSave(struct GameData *gd);

void *GAME_DATA_GetSaveBlock1F(struct GameData *gd);

int GAME_DATA_GetPmsWork(struct GameData *gd);

void *GAME_DATA_GetTrainerRecord(struct GameData *gd);

u8 *GAME_DATA_GetSaveSyncBlock(struct GameData *gd);

void *GAME_DATA_GetSaveBlock2A(struct GameData *gd);

u32 *GAME_DATA_GetListCursor(struct GameData *gd);

void *GAME_DATA_GetSaveBlock21(struct GameData *gd);

void *GAME_DATA_GetSaveBlock42(struct GameData *gd);

void GAME_DATA_SetExternalWork(struct GameData *gd, void *work);

void *GAME_DATA_GetExternalWork(struct GameData *gd);

void *GAME_DATA_GetSaveBlockWork(struct GameData *gd);

void *GAME_DATA_GetBoxSave(struct GameData *gd);

void GAME_DATA_SetSymbolMapFlag(struct GameData *gd, u8 flag);

int GAME_DATA_GetSymbolMapFlag(struct GameData *gd);

u32 GAME_DATA_CheckPlayTime(struct GameData *gd, u32 limit);

struct PlayTime *GAME_DATA_GetPlayTime(struct GameData *gd);

void *GAME_DATA_GetSaveBlock43(struct GameData *gd);

/*
 * Sixteen bytes.  The other half of the cut described in the header of
 * src/matched/unit_0201283C.c: this call site and the one at 0x0201290A are
 * the only two references to func_02008850 in the image, so they have to sit
 * in different ranges for either of them to be attested.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012914.c \
 *       --addr 0x02012914 --thumb
 */
u16 GAME_DATA_GetSituationWarpId(const struct GameData *gd)
{
    return *func_02008850((struct Situation *)gd->situation);
}

/*
 *           GAME_DATA_GetMyStatus, GAME_DATA_GetPlayerStatusById, GAME_DATA_GetBagCursor, GAME_DATA_GetOccupyInfo,
 *           GAME_DATA_GetEventWork, GAME_DATA_GetFieldWork, GAME_DATA_GetMusicalWork, GAME_DATA_GetSeason,
 *           GAME_DATA_SetSeason, GAME_DATA_GetSubscreenMode, GAME_DATA_SetSubscreenMode, GAME_DATA_GetSubscreenType,
 *           GAME_DATA_SetSubscreenType, GAME_DATA_GetFrameRate, GAME_DATA_SetFrameRate, GAME_DATA_SetWalkCountEnabled,
 *           GAME_DATA_ResetWalkCount, GAME_DATA_IncWalkCount, GAME_DATA_IsWalkCountEnabled, GAME_DATA_GetBgmInfo,
 *           GAME_DATA_GetFieldGimmick, GAME_DATA_GetFieldMode, GAME_DATA_SetFieldMode, GAME_DATA_GetItemUseWork,
 *           GAME_DATA_InitPlayerWork, GAME_DATA_SetPlayerPosition, GAME_DATA_GetPlayerPosition, GAME_DATA_SetPlayerRail,
 *           GAME_DATA_GetPlayerRail, GAME_DATA_SetPlayerMoveForm, GAME_DATA_GetPlayerMoveForm, GAME_DATA_SetPlayerZoneId,
 *           GAME_DATA_GetPlayerZoneId, GAME_DATA_SetPlayerDirection, GAME_DATA_GetPlayerDirection
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - GameData is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - PlayerWork is the 0x44-byte record (five of them in GameData), and GAME_DATA_InitPlayerWork
 *    onwards are its constructor and accessors.  GAME_DATA_InitPlayerWork is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    GAME_DATA_SetPlayerRail copies whole) and a five-field view.
 *
 * GAME_DATA_IncWalkCount is a post-increment and not an assignment:
 * `return gd->walkCount++;` spends an extra `adds r1, r4, #0` copy that
 * `n = gd->walkCount; gd->walkCount = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because GAME_DATA_SetPlayerDirectionType cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u32 GAME_DATA_GetMapMatrix(const struct GameData *gd)
{
    return gd->mapMatrix;
}

void *GAME_DATA_GetMyItem(const struct GameData *gd)
{
    return gd->myItem;
}

void *GAME_DATA_GetMyParty(const struct GameData *gd)
{
    return gd->myParty;
}

u32 GAME_DATA_GetBoxManager(const struct GameData *gd)
{
    return gd->boxManager;
}

struct PlayerStatus *GAME_DATA_GetMyStatus(struct GameData *gd)
{
    return &GAME_DATA_GetField114(gd)->status;
}

struct PlayerStatus *GAME_DATA_GetPlayerStatusById(struct GameData *gd, u32 playerId)
{
    return &gd->playerWork[playerId].status;
}

u32 GAME_DATA_GetBagCursor(const struct GameData *gd)
{
    return gd->bagCursor;
}

void *GAME_DATA_GetOccupyInfo(const struct GameData *gd)
{
    return gd->occupyInfo;
}

void *GAME_DATA_GetEventWork(const struct GameData *gd)
{
    return gd->eventWork;
}

u32 GAME_DATA_GetFieldWork(const struct GameData *gd)
{
    return gd->fieldWork;
}

u32 GAME_DATA_GetMusicalWork(const struct GameData *gd)
{
    return gd->musicalWork;
}

u8 GAME_DATA_GetSeason(const struct GameData *gd)
{
    return gd->season;
}

void GAME_DATA_SetSeason(struct GameData *gd, u8 value)
{
    gd->season = value;
}

u8 GAME_DATA_GetSubscreenMode(const struct GameData *gd)
{
    return gd->subscreenMode;
}

void GAME_DATA_SetSubscreenMode(struct GameData *gd, u8 value)
{
    gd->subscreenMode = value;
}

u8 GAME_DATA_GetSubscreenType(const struct GameData *gd)
{
    return gd->subscreenType;
}

void GAME_DATA_SetSubscreenType(struct GameData *gd, u32 value)
{
    gd->subscreenType = value;
}

u8 GAME_DATA_GetFrameRate(const struct GameData *gd)
{
    return gd->frameRate;
}

void GAME_DATA_SetFrameRate(struct GameData *gd, u8 value)
{
    gd->frameRate = value;
}

void GAME_DATA_SetWalkCountEnabled(struct GameData *gd, u8 enable)
{
    gd->walkCountEnabled = enable;
    if (enable != 0) {
        gd->walkCount = 0;
    }
}

void GAME_DATA_ResetWalkCount(struct GameData *gd)
{
    gd->walkCount = 0;
}

u8 GAME_DATA_IncWalkCount(struct GameData *gd)
{
    if (gd->walkCountEnabled != 0) {
        return gd->walkCount++;
    }
    return 0;
}

u8 GAME_DATA_IsWalkCountEnabled(const struct GameData *gd)
{
    return gd->walkCountEnabled;
}

u32 GAME_DATA_GetBgmInfo(const struct GameData *gd)
{
    return gd->bgmInfo;
}

u32 GAME_DATA_GetFieldGimmick(const struct GameData *gd)
{
    return gd->fieldGimmick;
}

u32 GAME_DATA_GetFieldMode(const struct GameData *gd)
{
    return gd->fieldMode;
}

void GAME_DATA_SetFieldMode(struct GameData *gd, u32 value)
{
    gd->fieldMode = value;
}

u32 GAME_DATA_GetItemUseWork(const struct GameData *gd)
{
    return gd->itemUseWork;
}

void GAME_DATA_InitPlayerWork(struct PlayerWork *player)
{
    player->status.romCode = 0;
    player->status.gender = 0;
    player->zoneId = 0;
    player->position.x = 0;
    player->position.y = 0;
    player->position.z = 0;
    player->direction = 0;
    player->moveForm = 0;
    player->status.id = 0;
    player->rail.part.type = 0;
    player->rail.part.key = 0;
    player->rail.part.lineIndex = 0;
    player->rail.part.sideGrid = 0;
    player->rail.part.frontGrid = 0;
    player->palaceZoneId = 0xFFFF;
}

void GAME_DATA_SetPlayerPosition(struct PlayerWork *player, const struct PlayerPosition *pos)
{
    player->position = *pos;
}

struct PlayerPosition *GAME_DATA_GetPlayerPosition(struct PlayerWork *player)
{
    return &player->position;
}

void GAME_DATA_SetPlayerRail(struct PlayerWork *player, const struct RailLocationWords *rail)
{
    player->rail.all = *rail;
}

struct RailLocationWords *GAME_DATA_GetPlayerRail(struct PlayerWork *player)
{
    return &player->rail.all;
}

void GAME_DATA_SetPlayerMoveForm(struct PlayerWork *player, u8 form)
{
    player->moveForm = form;
}

u8 GAME_DATA_GetPlayerMoveForm(const struct PlayerWork *player)
{
    return player->moveForm;
}

struct PlayerWork *GAME_DATA_SetPlayerZoneId(struct PlayerWork *player, u16 zoneId)
{
    player->zoneId = zoneId;
    return player;
}

u16 GAME_DATA_GetPlayerZoneId(const struct PlayerWork *player)
{
    return player->zoneId;
}

void GAME_DATA_SetPlayerDirection(struct PlayerWork *player, int direction)
{
    player->direction = direction;
}

u16 GAME_DATA_GetPlayerDirection(const struct PlayerWork *player)
{
    return player->direction;
}

void GAME_DATA_SetPlayerDirectionType(struct PlayerWork *player, int dirId)
{
    player->direction = sPlayerDirectionAngles[dirId];
}

/*
 *           GAME_DATA_GetPlayerPalaceZoneId, GAME_DATA_GetMoveModelSys, GAME_DATA_GetEnterMode, GAME_DATA_SetEnterMode,
 *           GAME_DATA_GetOwnNetId, GAME_DATA_SetOwnNetId, GAME_DATA_GetIntrudeCount, GAME_DATA_SetIntrudeCount,
 *           GAME_DATA_GetIntrudeId, GAME_DATA_SetIntrudeId, GAME_DATA_GetSlotFlag, GAME_DATA_SetSlotFlag,
 *           GAME_DATA_IsConfigFlagSet
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * PlayerWork for GAME_DATA_GetPlayerDirectionType .. GAME_DATA_GetPlayerPalaceZoneId and GameData from GAME_DATA_GetMoveModelSys on.
 *
 * GAME_DATA_GetPlayerDirectionType buckets the PlayerWork direction at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `player->direction = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void GAME_DATA_SetPlayerDirectionType(struct PlayerWork *player, int dirId)
 *        {
 *            player->direction = sPlayerDirectionAngles[dirId];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled CONFIG_GetBattleFlag four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void GAME_DATA_SetConfigFlag(struct GameData *gd, int on)
 *        {
 *            CONFIG_SetBattleFlag(gd->config, on ? 1 : 0);
 *        }
 *
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */
u32 GAME_DATA_GetPlayerDirectionType(const struct PlayerWork *player)
{
    u32 dirId = 0;
    u16 angle = player->direction;
    if (angle > 0x2000 && angle < 0x6000) {
        dirId = 2;
    } else if (angle >= 0x6000 && angle <= 0xA000) {
        dirId = 1;
    } else if (angle > 0xA000 && angle < 0xE000) {
        dirId = 3;
    }
    return dirId;
}

u32 GAME_DATA_GetPlayerObjectCode(const struct PlayerWork *player)
{
    return player->objectCode;
}

void GAME_DATA_SetPlayerObjectCode(struct PlayerWork *player, u32 code)
{
    player->objectCode = code;
}

void GAME_DATA_SetPlayerPalaceZoneId(struct PlayerWork *player, u16 zoneId)
{
    player->palaceZoneId = zoneId;
}

u16 GAME_DATA_GetPlayerPalaceZoneId(const struct PlayerWork *player)
{
    return player->palaceZoneId;
}

void *GAME_DATA_GetMoveModelSys(const struct GameData *gd)
{
    return gd->moveModelSys;
}

u8 GAME_DATA_GetEnterMode(const struct GameData *gd)
{
    return gd->enterMode;
}

void GAME_DATA_SetEnterMode(struct GameData *gd, u8 value)
{
    gd->enterMode = value;
}

u8 GAME_DATA_GetOwnNetId(const struct GameData *gd)
{
    return gd->ownNetId;
}

void GAME_DATA_SetOwnNetId(struct GameData *gd, u8 value)
{
    gd->ownNetId = value;
}

int GAME_DATA_GetIntrudeCount(const struct GameData *gd)
{
    return gd->intrudeCount;
}

struct GameData *GAME_DATA_SetIntrudeCount(struct GameData *gd, u8 count)
{
    gd->intrudeCount = count;
    return gd;
}

u8 GAME_DATA_GetIntrudeId(const struct GameData *gd)
{
    return gd->intrudeId;
}

void GAME_DATA_SetIntrudeId(struct GameData *gd, u32 value)
{
    gd->intrudeId = value;
}

u8 GAME_DATA_GetSlotFlag(const struct GameData *gd, u32 slot)
{
    return gd->slotFlags[slot];
}

void GAME_DATA_SetSlotFlag(struct GameData *gd, int slot, u8 value)
{
    gd->slotFlags[slot] = value;
}

u32 GAME_DATA_IsConfigFlagSet(const struct GameData *gd)
{
    if (CONFIG_GetBattleFlag(gd->config) == 1) {
        return 1;
    }
    return 0;
}

/*
 * Forward a boolean-normalised flag to CONFIG_SetBattleFlag on the object held at
 * +0x198 of the game-data object (func_0200873C(handle) in GAME_DATA_Create).
 *
 * The tail call's pool word names 0x02008450, an unlabelled Thumb leaf
 * (the bit-10 setter beside the labelled getter CONFIG_GetBattleFlag); this
 * pool word is its only reference in the image.  It is attested by the
 * compiled witness src/matched/CONFIG_SetBattleFlag.c (class `matched`).
 */
void GAME_DATA_SetConfigFlag(struct GameData *gd, int on)
{
    CONFIG_SetBattleFlag(gd->config, on ? 1 : 0);
}

/*
 * One function, 24 bytes, because the function immediately after it is a near
 * miss and the one after that is src/matched/unit_02012C0C.c.
 *
 * 0x02012BF8, 20 bytes, is the twin of this one and reproduces every concrete
 * byte:
 *
 *     void GAME_DATA_CheckSaveFlag(void *p, u32 a)
 *     {
 *         RECENT_ID_LIST_SAVEDATA_ContainsId(RECENT_ID_LIST_SAVEDATA_GetBlockFromSys(GAME_DATA_GetSaveControlWork(p)), a);
 *     }
 *
 * with `RECENT_ID_LIST_SAVEDATA_GetBlockFromSys 0x0200C404 thumb`, `RECENT_ID_LIST_SAVEDATA_ContainsId 0x0200C44C thumb` and
 * `GAME_DATA_GetSaveControlWork 0x02012EC0 thumb`.  It caps at MATCH because the `bl` at
 * 0x02012C06 is the only branch to RECENT_ID_LIST_SAVEDATA_ContainsId anywhere in the image, so the
 * `label` class has no witness outside the range and, this being the only
 * caller, no cut can create one.  Evidence class: label, 0 witnesses outside.
 * The other five call targets here all have witnesses elsewhere.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012BE0.c \
 *       --addr 0x02012BE0 --thumb
 */
void GAME_DATA_SetSaveFlag(struct GameData *gd, u32 id, u32 on)
{
    RECENT_ID_LIST_SAVEDATA_SetId(RECENT_ID_LIST_SAVEDATA_GetBlock(GAME_DATA_GetSaveControl(gd)), id, on);
}

void GAME_DATA_CheckSaveFlag(struct GameData *gd, u32 id)
{
    RECENT_ID_LIST_SAVEDATA_ContainsId(RECENT_ID_LIST_SAVEDATA_GetBlockFromSys(GAME_DATA_GetSaveControlWork(gd)), id);
}

/*
 * Twelve bytes: the address of the GameData sub-object at +0x5E8 (rtcWork), reached
 * through a literal pool word holding the plain constant 0x5E8 rather than a
 * relocation.  It is a file of its own because the function in front of it,
 * 0x02012BF8, is a documented near miss; see the header of
 * src/matched/unit_02012BE0.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012C0C.c \
 *       --addr 0x02012C0C --thumb
 */
u8 *GAME_DATA_GetRtcWork(struct GameData *gd)
{
    return gd->rtcWork;
}

/*
 * 204 bytes, 0x02012C18..0x02012CDC (the listing extent 204 includes the
 * 0x5EC pool word at 0x02012CDC).  Sibling of GAME_DATA_WriteToSave, same shape plus
 * an opening guard `if (func_020071E4(*(u32 *)p) == 1) return;`.
 *
 * docs/notes/pkt_02012C18.c.txt recorded this as an unmovable register
 * rotation (r4/r6/r7) -- it was not.  The rotation was downstream of ONE
 * wrong argument order: the original is
 *     func_020097F0(func_02009D08(*(u32 *)p), v);
 * i.e. the inner call's result is argument 1 and the 0x0201283C result is
 * argument 2, the OPPOSITE of the sibling's func_020097F0(v, func_02009D08())
 * at 0x02012D6E.  With the arguments the sibling's way, mwcc needs an extra
 * `adds r0, r7, #0` at the call, which shifts everything after it by two
 * bytes, forces the trailing `c046` pool-alignment nop, and reallocates the
 * three callee-saved registers -- which is what the note saw and read as the
 * whole residue.  Swapping them alone takes the file from that DIFF to EXACT
 * with no other change.  (docs/idioms/cmp-operand-order-names-the-temporary.md
 * generalised: the call-result operand order names which value gets the
 * named-local treatment.)
 */
void GAME_DATA_LoadFromSave(struct GameData *gd)
{
    struct PlayerWork *player;
    void *occupy;
    struct UnionInfo *unionInfo;
    struct FieldState *fieldState;
    struct PlayTime *savedTime;
    u32 situation;
    if (func_020071E4(gd->saveControl) == 1) {
        return;
    }
    player = GAME_DATA_GetField114(gd);
    func_02008808(gd->saveControl, player);
    func_020088B8(gd->saveControl, player);
    occupy = GAME_DATA_GetOccupyInfo(gd);
    func_0200EEAC(occupy, SAVE_CONTROL_GetBlock(gd->saveControl, 0x29));
    INTRUDE_LoadOccupy(gd->saveControl, (u16 *)GAME_DATA_GetLastBattleRecSlot(gd));
    unionInfo = GAME_DATA_GetSecondUnionInfo(gd);
    MUSICAL_SHOT_CopyPhotoRev(MUSICAL_SHOT_GetFromSave(gd->saveControl), unionInfo);
    GIMMICK_WORK_Load(gd->saveControl, (const struct FieldSaveData *)gd->fieldSave);
    situation = gd->situation;
    func_0200893C((const struct Situation *)situation, gd->moveModelSys);
    func_02008954((const struct Situation *)situation, &gd->season);
    fieldState = GAME_DATA_GetField1A0(gd);
    func_020097F0(func_02009D08(gd->saveControl), fieldState);
    func_02008964((const struct Situation *)gd->situation, &gd->subscreenMode);
    func_0200E89C(gd->saveControl, gd->saveSyncBlock);
    savedTime = func_02008748(gd->saveControl);
    func_0200863C(gd->playTime, savedTime);
}

/*
 * 204 bytes, 0x02012CE0..0x02012DAC, EXACT on the first run after the one
 * change that mattered: the u32 at p+0x15C is read once into a NAMED local and
 * handed to both 0x0200892C and 0x0200894C.  Spelled inline at each call site
 * the compiler re-materialises the address per site (`adds r1, r6, #0;
 * adds r1, #0x5c; ldr r0, [r5, r6]`) and loses four bytes; with the local it
 * keeps the value live in r7 across the two calls, exactly as the original
 * does.  The third use (0x0200895C, after two more calls) re-reads it, which
 * is also what the original does.
 *
 * The GameData fields at 0x15C / 0x1B8 / 0x1C4 / 0x1C5 / 0x5EC / 0x694 /
 * 0x6AC compile to the same displacements as the byte-pointer spelling the
 * function had first; mwcc materialises 0x5EC as a pool word (it is not a
 * single-instruction Thumb immediate).
 */
void GAME_DATA_WriteToSave(struct GameData *gd)
{
    struct PlayerWork *player;
    void *occupy;
    struct UnionInfo *unionInfo;
    struct FieldState *fieldState;
    struct PlayTime *savedTime;
    u32 situation;
    player = GAME_DATA_GetField114(gd);
    func_020087E8(gd->saveControl, player);
    func_02008860(gd->saveControl, player);
    occupy = GAME_DATA_GetOccupyInfo(gd);
    NET_DEVICE_TABLE_BuildFromProducer(occupy, SAVE_CONTROL_GetBlock(gd->saveControl, 0x29));
    INTRUDE_StoreOccupy(gd->saveControl, (const u16 *)GAME_DATA_GetLastBattleRecSlot(gd));
    unionInfo = GAME_DATA_GetSecondUnionInfo(gd);
    MUSICAL_SHOT_CopyPhoto(MUSICAL_SHOT_GetFromSave(gd->saveControl), unionInfo);
    GIMMICK_WORK_Save((struct FieldSaveData *)gd->fieldSave, gd->saveControl);
    situation = gd->situation;
    func_0200892C((struct Situation *)situation, gd->moveModelSys);
    func_0200894C((struct Situation *)situation, gd->season);
    fieldState = GAME_DATA_GetField1A0(gd);
    func_020097F0(fieldState, func_02009D08(gd->saveControl));
    func_0200895C((struct Situation *)gd->situation, gd->subscreenMode);
    func_0200E884(gd->saveSyncBlock, gd->saveControl);
    savedTime = func_02008748(gd->saveControl);
    func_02008658(gd->playTime);
    func_0200863C(savedTime, gd->playTime);
}

int GAME_DATA_SaveStart(struct GameData *gd)
{
    GAME_DATA_WriteToSave(gd);
    WIH_DWC_PauseTimers();
    gd->isSaving = 1;
    UI_SetFlags39Global(2, 1);
    return SAVE_CONTROL_StartSave(gd->saveControl);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_DATA_SaveMain.c \
 *       --func GAME_DATA_SaveMain --addr 0x02012DD0 --cc 1.1p1 --thumb
 */
int GAME_DATA_SaveMain(struct GameData *gd)
{
    int result;
    if (GFL_USE_IsLoaderBusy() == 1) {
        return 0;
    }
    result = SAVE_CONTROL_MainSave(gd->saveControl);
    if ((u32)(result - 2) <= 1) {
        UI_ClearFlags39Global(2);
        WIH_DWC_ResumeTimers();
        gd->isSaving = 0;
    }
    return result;
}

void GAME_DATA_SaveCancel(struct GameData *gd)
{
    u32 soundId;
    if (gd->isSaving != 1)
        return;
    UI_ClearFlags39Global(2);
    WIH_DWC_ResumeTimers();
    gd->isSaving = 0;
    SAVE_CONTROL_CancelSave(gd->saveControl);
    soundId = 0x80;
    if (UI_TestKeepAwakeFlagsGlobal(soundId) == 1)
        UI_ClearKeepAwakeFlagsGlobal(soundId);
}

/*
 * A one-byte getter for the field at +0x1CE, entry attested by the pool word
 * 0x02012E41 that the sibling setter pair loads.  0x1CE does not fit a Thumb
 * immediate, so the offset comes from the function's own literal pool while
 * the pointer stays in r0.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_DATA_IsSaving.c \
 *       --func GAME_DATA_IsSaving --addr 0x02012E40 --cc 1.1p1 --thumb
 */
u8 GAME_DATA_IsSaving(const struct GameData *gd)
{
    return gd->isSaving;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_DATA_PartSaveStart.c \
 *       --func GAME_DATA_PartSaveStart --addr 0x02012E4C --cc 1.1p1 --thumb
 */
void GAME_DATA_PartSaveStart(struct GameData *gd, u32 blockId)
{
    UI_SetKeepAwakeFlagsGlobal(0x80);
    GAME_DATA_WriteToSave(gd);
    WIH_DWC_PauseTimers();
    gd->isSaving = 1;
    UI_SetFlags39Global(2);
    SAVE_CONTROL_BeginExtraSaveWrite(gd->saveControl, blockId);
}

int GAME_DATA_PartSaveMain(struct GameData *gd, int blockId)
{
    int result;
    if (GFL_USE_IsLoaderBusy() == 1)
        return 0;
    result = SAVE_CONTROL_StepExtraSaveWrite(gd->saveControl, blockId);
    if (result == 2 || result == 3) {
        UI_ClearFlags39Global(2);
        WIH_DWC_ResumeTimers();
        gd->isSaving = 0;
        UI_ClearKeepAwakeFlagsGlobal(0x80);
    }
    return result;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           GAME_DATA_GetCurrentEvent
 *
 * Five leaf accessors on one large record.  Offsets 0x5ec and 0x688 are out
 * of Thumb immediate reach so each costs a pool word, while 0x680 is
 * 0x1a << 6 and is rematerialised with `movs`/`lsls` instead.  Two of the
 * five read the same word at +0, which the compiler keeps as two separate
 * sections rather than folding.  None saves lr, so none is labelled.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012EBC.c \
 *       --addr 0x02012EBC --thumb
 */
struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gd)
{
    return gd->saveControl;
}

struct SaveControl *GAME_DATA_GetSaveControlWork(struct GameData *gd)
{
    return gd->saveControl;
}

u8 *GAME_DATA_GetFieldSave(struct GameData *gd)
{
    return gd->fieldSave;
}

u8 *GAME_DATA_GetEventState(struct GameData *gd)
{
    return (u8 *)&gd->eventState;
}

void *GAME_DATA_GetCurrentEvent(struct GameData *gd)
{
    return gd->currentEvent;
}

/*
 * Unlabelled leaf accessor: stores v at base + 0x688.
 */
struct GameData *GAME_DATA_SetCurrentEvent(struct GameData *gd, void *event)
{
    gd->currentEvent = event;
    return gd;
}

/*
 * Unlabelled Thumb tail-call thunk: SAVE_CONTROL_GetBlock(*p, 0x3a).
 */
void *GAME_DATA_GetSaveBlock3A(struct GameData *gd)
{
    return SAVE_CONTROL_GetBlock(gd->saveControl, 0x3a);
}

/*
 * Unlabelled Thumb tail-call thunk: SAVE_CONTROL_GetBlock(*p, 0x3b).
 */
void *GAME_DATA_GetSaveBlock3B(struct GameData *gd)
{
    return SAVE_CONTROL_GetBlock(gd->saveControl, 0x3b);
}

void *GAME_DATA_GetMiscSave(struct GameData *gd)
{
    return BEACON_GetBlock(gd->saveControl);
}

/*
 * Save-block getter through the handle's first word: tail call to
 * TRADE_HISTORY_GetFromSave (block 0x1f).  Seeded from ov119 0x021E0226, 0x021E06D0,
 * 0x021E080C (tree_ov170_3).
 *
 * Addresses are Black-image addresses.
 */
void *GAME_DATA_GetSaveBlock1F(struct GameData *gd)
{
    return TRADE_HISTORY_GetFromSave(gd->saveControl);
}

int GAME_DATA_GetPmsWork(struct GameData *gd)
{
    return gd->pmsWork;
}

void *GAME_DATA_GetTrainerRecord(struct GameData *gd)
{
    return SAVE_CONTROL_GetBlock(gd->saveControl, 0x26);
}

/*
 * Unlabelled leaf accessor: base + 0x694.
 */
u8 *GAME_DATA_GetSaveSyncBlock(struct GameData *gd)
{
    return gd->saveSyncBlock;
}

/*
 * Unlabelled leaf: tail-calls SAVE_CONTROL_GetBlock(*(void **)p, 0x2a).
 */
void *GAME_DATA_GetSaveBlock2A(struct GameData *gd)
{
    return SAVE_CONTROL_GetBlock(gd->saveControl, 0x2a);
}

/*
 * Unlabelled leaf accessor: base + 0x6A4.  No register-saving prologue, so
 * disasm.py never traced a func_ label here; matching it gives the overlay
 * call sites a `matched` witness.
 */
u32 *GAME_DATA_GetListCursor(struct GameData *gd)
{
    return &gd->listCursor;
}

/*
 * Save-block getter through the handle's first word: tail call to
 * func_020089C0 (block 0x21, src/matched/unit_020089A8.c).  Seeded from ov111
 * 0x021C40FC, 0x021C4126, 0x021C6208 and ov010 0x0215AC8E.
 *
 * Addresses are Black-image addresses.
 */
void *GAME_DATA_GetSaveBlock21(struct GameData *gd)
{
    return func_020089C0(gd->saveControl);
}

/*
 * Two leaves before GAME_DATA_GetExternalWork (the +0x6a8 getter): save-block getter
 * for block 0x42 through the handle's first word, and the +0x6a8 setter.
 * Seeded from ov048/ov171/ov205 (0x02012F68) and ov010 SCRCMD_MUSICAL_CreateLinkWork and
 * SCRCMD_MUSICAL_DeleteLinkWork (0x02012F74).
 */
void *GAME_DATA_GetSaveBlock42(struct GameData *gd)
{
    return SAVE_CONTROL_GetBlock(gd->saveControl, 0x42);
}

void GAME_DATA_SetExternalWork(struct GameData *gd, void *work)
{
    gd->externalWork = work;
}

/*
 * Unlabelled leaf accessor: reads the word at base + 0x6A8.  No
 * register-saving prologue, so disasm.py never traced a func_ label here;
 * matching it gives the overlay call sites a `matched` witness.
 */
void *GAME_DATA_GetExternalWork(struct GameData *gd)
{
    return gd->externalWork;
}

/*
 * Unlabelled leaf: tail-calls GAME_SYNC_GetBlock(*p).  Filed as the witness for
 * ov021 SCRCMD_CheckWifiListFlags, SCRCMD_WifiListOperation and SCRCMD_SetWifiFriendNameWord.
 */
void *GAME_DATA_GetSaveBlockWork(struct GameData *gd)
{
    return GAME_SYNC_GetBlock(gd->saveControl);
}

/*
 * Unlabelled leaf: tail-calls func_02007B44(*(void **)p).
 */
void *GAME_DATA_GetBoxSave(struct GameData *gd)
{
    return func_02007B44(gd->saveControl);
}

/*
 * Unlabelled Thumb leaf: stores a byte at +0x1CF.
 */
void GAME_DATA_SetSymbolMapFlag(struct GameData *gd, u8 flag)
{
    gd->symbolMapFlag = flag;
}

/*
 * Unlabelled leaf accessor: reads the byte at base + 0x1CF.
 */
int GAME_DATA_GetSymbolMapFlag(struct GameData *gd)
{
    return gd->symbolMapFlag;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_DATA_CheckPlayTime.c \
 *       --func GAME_DATA_CheckPlayTime --addr 0x02012FBC --cc 1.1p1 --thumb
 */
u32 GAME_DATA_CheckPlayTime(struct GameData *gd, u32 limit)
{
    return func_020085D4(gd->playTime, limit);
}

struct PlayTime *GAME_DATA_GetPlayTime(struct GameData *gd)
{
    return gd->playTime;
}

void *GAME_DATA_GetSaveBlock43(struct GameData *gd)
{
    return SAVE_CONTROL_GetBlock(gd->saveControl, 0x43);
}

void *GAME_DATA_GetEventWorkFromSave(struct SaveControl *save)
{
    return SAVE_CONTROL_GetBlock(save, 0x2d);
}
