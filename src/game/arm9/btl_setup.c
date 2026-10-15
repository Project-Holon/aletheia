/*
 * file:     btl_setup.c
 * unit:     yes
 * function: GAME_DATA_GetSituationWarpId, GAME_DATA_GetMapMatrix, func_0201292C, func_02012934, func_0201293C, func_02012944, func_02012950, GAME_DATA_GetBagCursor, func_02012964, func_0201296C, func_02012974, GAME_DATA_GetMusicalWork, func_02012984, GAME_DATA_SetSeason, func_02012994, GAME_DATA_SetSubscreenMode, func_020129AC, func_020129B8, func_020129C4, func_020129D0, func_020129DC, func_020129F0, GAME_DATA_IncWalkCount, GAME_DATA_IsWalkCountEnabled, func_02012A30, func_02012A38, func_02012A44, GAME_DATA_SetFieldMode, func_02012A54, GAME_DATA_InitPlayerWork, func_02012A90, func_02012AA0, func_02012AA4, func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4, func_02012AC8, func_02012ACC, func_02012AD0, GAME_DATA_SetPlayerDirectionType, func_02012AE4, func_02012B28, func_02012B2C, func_02012B30, func_02012B34, func_02012B38, GAME_DATA_GetEnterMode, func_02012B4C, func_02012B58, func_02012B64, func_02012B70, func_02012B78, func_02012B80, func_02012B8C, GAME_DATA_GetSlotFlag, GAME_DATA_SetSlotFlag, GAME_DATA_IsConfigFlagSet, GAME_DATA_SetConfigFlag, GAME_DATA_SetSaveFlag, GAME_DATA_CheckSaveFlag, GAME_DATA_GetRtcWork, GAME_DATA_LoadFromSave, GAME_DATA_WriteToSave, GAME_DATA_SaveStart, GAME_DATA_SaveMain, GAME_DATA_SaveCancel, GAME_DATA_IsSaving, GAME_DATA_PartSaveStart, GAME_DATA_PartSaveMain, GAME_DATA_GetSaveControl, GAME_DATA_GetSaveControlWork, GAME_DATA_GetFieldSave, GAME_DATA_GetEventState, GAME_DATA_GetCurrentEvent, GAME_DATA_SetCurrentEvent, GAME_DATA_GetSaveBlock3A, GAME_DATA_GetSaveBlock3B, GAME_DATA_GetMiscSave, GAME_DATA_GetSaveBlock1F, GAME_DATA_GetPmsWork, GAME_DATA_GetTrainerRecord, GAME_DATA_GetSaveSyncBlock, GAME_DATA_GetSaveBlock2A, GAME_DATA_GetListCursor, GAME_DATA_GetSaveBlock21, GAME_DATA_GetSaveBlock42, GAME_DATA_SetExternalWork, GAME_DATA_GetExternalWork, GAME_DATA_GetSaveBlockWork, GAME_DATA_GetBoxSave, GAME_DATA_SetSymbolMapFlag, GAME_DATA_GetSymbolMapFlag, GAME_DATA_CheckPlayTime, GAME_DATA_GetPlayTime, GAME_DATA_GetSaveBlock43, GAME_DATA_GetEventWorkFromSave, func_02012FF0, func_02012FFC, func_02013020, func_02013050, func_02013080, BTL_SETUP_Create, BTL_SETUP_Delete, BTL_SETUP_Clear, BTL_SETUP_FreeSlots, BTL_SETUP_SetParty, BTL_SETUP_GetParty, BTL_SETUP_SetStatusFlag, BTL_SETUP_CheckStatusFlag, BTL_SETUP_ApplyRegulation, BTL_SETUP_InitCommFieldSituation, BTL_SETUP_InitFieldSituation, BTL_SETUP_CreateTrainerData, BTL_SETUP_DeleteTrainerData, BTL_SETUP_SetTrainer, BTL_SETUP_SetPlayerParty, BTL_SETUP_InitCommon, BTL_SETUP_SetupWild, BTL_SETUP_SetupTrainerBase, BTL_SETUP_SetupComm, BTL_SETUP_SetupDemo, BTL_SETUP_SetupTrainerSingle, BTL_SETUP_SetupTrainerDouble, BTL_SETUP_SetupTrainerTriple, BTL_SETUP_SetupTrainerRotation, BTL_SETUP_SetupTrainerTag, BTL_SETUP_SetupTrainerMulti, BTL_SETUP_SetupCommSingle, BTL_SETUP_SetupCommDouble, BTL_SETUP_SetupCommMulti, BTL_SETUP_SetupCommAiMulti, BTL_SETUP_SetupCommTriple, BTL_SETUP_SetupCommRotation, BTL_SETUP_InitWithSlots, BTL_SETUP_ClearWithSlots, BTL_SETUP_ChangeToSubway, BTL_SETUP_AllocRecordBuffer
 * address:  0x02012914
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02008850  0x02008850  thumb
 *   func_020127A4         0x020127A4  thumb
 *   sPlayerDirectionAngles  0x0209DFA8  data  a2
 *   CONFIG_GetBattleFlag  0x02008448  thumb
 *   CONFIG_SetBattleFlag  0x02008450  thumb
 *   RECENT_ID_LIST_SAVEDATA_GetBlock  0x0200C40C  thumb
 *   RECENT_ID_LIST_SAVEDATA_SetId  0x0200C418  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_020071E4  0x020071E4  thumb
 *   func_02008808  0x02008808  thumb
 *   func_020088B8  0x020088B8  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_0200EEAC  0x0200EEAC  thumb
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   func_0200BE6C  0x0200BE6C  thumb
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   func_0200A864  0x0200A864  thumb
 *   func_0200A884  0x0200A884  thumb
 *   func_0200B3C8  0x0200B3C8  thumb
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
 *   func_0200EE64  0x0200EE64  thumb
 *   func_0200BE54  0x0200BE54  thumb
 *   func_0200A870  0x0200A870  thumb
 *   func_0200B3B0  0x0200B3B0  thumb
 *   func_0200892C  0x0200892C  thumb
 *   func_0200894C  0x0200894C  thumb
 *   func_0200895C  0x0200895C  thumb
 *   func_0200E884  0x0200E884  thumb
 *   func_02008658  0x02008658  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_02009EC8  0x02009EC8  thumb
 *   func_020089C0  0x020089C0  thumb
 *   func_02009448  0x02009448  thumb
 *   func_02007B44  0x02007B44  thumb
 *   sMsgSpeedSaveControl  0x020A7298  data
 *   sMsgSpeedWaitTable 0x0209DFB0  data
 *   func_0200873C  0x0200873C  thumb
 *   CONFIG_GetTextSpeed  0x02008374  thumb
 *   sBtlSetupFileName  0x020A729C  data
 *   POKEPARTY_Copy  0x0201AC2C  thumb
 *   func_0200AE54   0x0200AE54  thumb
 *   func_0200B040   0x0200B040  thumb
 *   POKE_REGULATION_AdjustPartyLevels   0x0201A2A8  thumb
 *   POKE_REGULATION_ResetPartyNicknames   0x0201A30C  thumb
 *   POKEPARTY_Create   0x0201A920  thumb
 *   func_0202A3FC   0x0202A3FC  thumb
 *   func_0202A440   0x0202A440  thumb
 *   func_0202A4B4   0x0202A4B4  thumb
 *   FORMCHANGE_UpdateSeasonForms   0x0216AAE4  thumb
 *   func_0200873C   0x0200873C  thumb
 *   func_0200C0E8   0x0200C0E8  thumb
 *   func_0200C258   0x0200C258  thumb
 *   ZUKAN_SAVE_GetFromGameData   0x0200CA1C  thumb
 *   ZONEDATA_CheckEventFlag   0x020142E8  thumb
 *   MI_CpuCopy8   0x02082D44  arm
 *   func_020076D0   0x020076D0  thumb
 *   POKEPARTY_GetCapacity   0x0201AA14  thumb
 *   POKEPARTY_GetCount   0x0201AA18  thumb
 *   MYSTATUS_Create   0x0200846C  thumb
 *   func_020307B0     0x020307B0  arm
 *   BTL_SETUP_FreeSlots     0x020130DC  thumb
 *   func_02030734  0x02030734  arm
 *   SAVE_CONTROL_StartSave  0x02007150  thumb
 *   SAVE_CONTROL_MainSave  0x02007168  thumb
 *   SAVE_CONTROL_CancelSave  0x020071A8  thumb
 *   SAVE_CONTROL_BeginExtraSaveWrite  0x02007374  thumb
 *   SAVE_CONTROL_StepExtraSaveWrite  0x020073B0  thumb
 *   CONFIG_Create  0x020082EC  thumb
 *   CONFIG_Copy  0x02008314  thumb
 *   WIH_DWC_PauseTimers  0x0201042C  thumb
 *   WIH_DWC_ResumeTimers  0x02010444  thumb
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   GFL_USE_IsLoaderBusy  0x02005C64  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   RECENT_ID_LIST_SAVEDATA_GetBlockFromSys  0x0200C404  thumb
 *   RECENT_ID_LIST_SAVEDATA_ContainsId  0x0200C44C  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed short s16;

typedef signed char s8;

#include "btl_setup_types.h"

struct Situation;
struct FieldState;
struct UnionInfo;
struct FieldSaveData;
struct Regulation;
struct StrBuf;
struct NetHandle;
struct MiscSave;

extern u16 *func_02008850(struct Situation *situation);
extern struct PlayerWork *func_020127A4(struct GameData *gd);
extern unsigned int CONFIG_GetBattleFlag(struct Config *config);
extern void CONFIG_SetBattleFlag(struct Config *config, int on);
extern void *RECENT_ID_LIST_SAVEDATA_GetBlock(struct SaveControl *save);
extern void RECENT_ID_LIST_SAVEDATA_SetId(void *flags, u32 id, u32 on);
extern void *RECENT_ID_LIST_SAVEDATA_GetBlockFromSys(struct SaveControl *save);
extern void RECENT_ID_LIST_SAVEDATA_ContainsId(void *flags, u32 id);
extern u8 func_020071E4(struct SaveControl *save);
extern void func_02008808(struct SaveControl *save, struct PlayerWork *dest);
extern void func_020088B8(struct SaveControl *save, struct PlayerWork *dest);
extern void *func_020071CC(struct SaveControl *save, u32 blockId);
extern void func_0200EEAC(void *occupy, void *block);
extern void *GAME_DATA_GetLastBattleRecSlot(struct GameData *gd);
extern void func_0200BE6C(struct SaveControl *save, u16 *dest);
extern struct UnionInfo *GAME_DATA_GetSecondUnionInfo(struct GameData *gd);
extern struct UnionInfo *func_0200A864(struct SaveControl *save);
extern void func_0200A884(const struct UnionInfo *src, struct UnionInfo *dest);
extern void func_0200B3C8(struct SaveControl *save, const struct FieldSaveData *src);
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
extern void func_0200EE64(void *occupy, void *block);
extern void func_0200BE54(struct SaveControl *save, const u16 *src);
extern void func_0200A870(struct UnionInfo *dest, const struct UnionInfo *src);
extern void func_0200B3B0(struct FieldSaveData *dest, struct SaveControl *save);
extern void func_0200892C(struct Situation *situation, const void *src);
extern void func_0200894C(struct Situation *situation, u8 value);
extern void func_0200895C(struct Situation *situation, u8 value);
extern void func_0200E884(void *src, struct SaveControl *save);
extern void func_02008658(struct PlayTime *playTime);
extern void WIH_DWC_PauseTimers(void);
extern void func_0203516C();
extern int SAVE_CONTROL_StartSave(struct SaveControl *save);
extern int  GFL_USE_IsLoaderBusy(void);
extern u32 SAVE_CONTROL_MainSave(struct SaveControl *save);
extern int func_020351A0(u32 v);
extern void WIH_DWC_ResumeTimers(void);
extern int SAVE_CONTROL_CancelSave(struct SaveControl *save);
extern int  func_02034FE8(u32 soundId);
extern void func_02034FB8(u32 soundId);
extern void func_02034F84(int soundId);
extern void SAVE_CONTROL_BeginExtraSaveWrite(struct SaveControl *save, u32 blockId);
extern int SAVE_CONTROL_StepExtraSaveWrite(struct SaveControl *save, u32 blockId);
extern void *func_0200C0F0(struct SaveControl *save);
extern void *func_02009EC8(struct SaveControl *save);
extern void *func_020089C0(struct SaveControl *save);
extern void *func_02009448(struct SaveControl *save);
extern void *func_02007B44(struct SaveControl *save);
extern u32 func_020085D4(struct PlayTime *playTime, u32 limit);
extern struct Config *func_0200873C(struct SaveControl *save);
extern unsigned int CONFIG_GetTextSpeed(struct Config *config);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *dst, int c, u32 n);
extern u32 func_020307B0(void *p);
extern void POKEPARTY_Copy(const struct Party *src, struct Party *dst);
extern u32 func_0200AE54(struct Regulation *reg, u32 id);
extern void func_0200B040(struct Regulation *reg, u8 *rules);
extern void POKE_REGULATION_AdjustPartyLevels(struct Regulation *reg, struct Party *party);
extern void POKE_REGULATION_ResetPartyNicknames(struct Regulation *reg, struct Party *party, u32 level);
extern struct StrBuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Delete(struct StrBuf *str);
extern void  PMSI_PARAM_ClearSentence(void *word);
extern struct Party *POKEPARTY_Create(u16 heap);
extern void func_0202A440(u32 trainerId, struct BattleTrainerData *tr, u16 heap);
extern void func_0202A4B4(u32 trainerId, struct Party *party, u16 heap);
extern void FORMCHANGE_UpdateSeasonForms(struct GameData *gd, struct Party *party, u32 season);
extern u8 func_0202A3FC(u32 trainerType);
extern struct MiscSave *func_0200C0E8(struct SaveControl *save);
extern u32 func_0200C258(struct MiscSave *misc);
extern void *ZUKAN_SAVE_GetFromGameData(struct GameData *gd);
extern u32 ZONEDATA_CheckEventFlag(void *eventWork, s32 flagId);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
extern u32  POKEPARTY_GetCount(struct Party *party);
extern u32 POKEPARTY_GetCapacity(struct Party *party);
extern int func_020076D0(u32 boxManager, u32 *tray, u32 *pos);
extern struct FieldState *func_0201283C(const struct GameData *gd);
extern void *MYSTATUS_Create(u16 heap);
extern u8 GFL_NET_GetHandleNetID(struct NetHandle *net);
extern struct Config *CONFIG_Create(u16 heap);
extern void CONFIG_Copy(struct Config *src, struct Config *dest);

extern const u16 sPlayerDirectionAngles[];
extern struct SaveControl *sMsgSpeedSaveControl;
extern const signed char sMsgSpeedWaitTable[];
extern const char sBtlSetupFileName[];

u16 GAME_DATA_GetSituationWarpId(const struct GameData *gd);
u32 GAME_DATA_GetMapMatrix(const struct GameData *gd);
void *func_0201292C(const struct GameData *gd);
void *func_02012934(const struct GameData *gd);
u32 func_0201293C(const struct GameData *gd);
struct PlayerStatus *func_02012944(struct GameData *gd);
struct PlayerStatus *func_02012950(struct GameData *gd, u32 playerId);
u32 GAME_DATA_GetBagCursor(const struct GameData *gd);
void *func_02012964(const struct GameData *gd);
void *func_0201296C(const struct GameData *gd);
u32 func_02012974(const struct GameData *gd);
u32 GAME_DATA_GetMusicalWork(const struct GameData *gd);
u8 func_02012984(const struct GameData *gd);
void GAME_DATA_SetSeason(struct GameData *gd, u8 value);
u8 func_02012994(const struct GameData *gd);
void GAME_DATA_SetSubscreenMode(struct GameData *gd, u8 value);
u8 func_020129AC(const struct GameData *gd);
void func_020129B8(struct GameData *gd, u32 value);
u8 func_020129C4(const struct GameData *gd);
void func_020129D0(struct GameData *gd, u8 value);
void func_020129DC(struct GameData *gd, u8 enable);
void func_020129F0(struct GameData *gd);
u8 GAME_DATA_IncWalkCount(struct GameData *gd);
u8 GAME_DATA_IsWalkCountEnabled(const struct GameData *gd);
u32 func_02012A30(const struct GameData *gd);
u32 func_02012A38(const struct GameData *gd);
u32 func_02012A44(const struct GameData *gd);
void GAME_DATA_SetFieldMode(struct GameData *gd, u32 value);
u32 func_02012A54(const struct GameData *gd);
void GAME_DATA_InitPlayerWork(struct PlayerWork *player);
void func_02012A90(struct PlayerWork *player, const struct PlayerPosition *pos);
struct PlayerPosition *func_02012AA0(struct PlayerWork *player);
void func_02012AA4(struct PlayerWork *player, const struct RailLocationWords *rail);
struct RailLocationWords *func_02012AB8(struct PlayerWork *player);
void func_02012ABC(struct PlayerWork *player, u8 form);
u8 func_02012AC0(const struct PlayerWork *player);
struct PlayerWork *func_02012AC4(struct PlayerWork *player, u16 zoneId);
u16 func_02012AC8(const struct PlayerWork *player);
void func_02012ACC(struct PlayerWork *player, int direction);
u16 func_02012AD0(const struct PlayerWork *player);
void GAME_DATA_SetPlayerDirectionType(struct PlayerWork *player, int dirId);
u32 func_02012AE4(const struct PlayerWork *player);
u32 func_02012B28(const struct PlayerWork *player);
void func_02012B2C(struct PlayerWork *player, u32 code);
void func_02012B30(struct PlayerWork *player, u16 zoneId);
u16 func_02012B34(const struct PlayerWork *player);
void *func_02012B38(const struct GameData *gd);
u8 GAME_DATA_GetEnterMode(const struct GameData *gd);
void func_02012B4C(struct GameData *gd, u8 value);
u8 func_02012B58(const struct GameData *gd);
void func_02012B64(struct GameData *gd, u8 value);
int func_02012B70(const struct GameData *gd);
struct GameData *func_02012B78(struct GameData *gd, u8 count);
u8 func_02012B80(const struct GameData *gd);
void func_02012B8C(struct GameData *gd, u32 value);
u8 GAME_DATA_GetSlotFlag(const struct GameData *gd, u32 slot);
void GAME_DATA_SetSlotFlag(struct GameData *gd, int slot, u8 value);
u32 GAME_DATA_IsConfigFlagSet(const struct GameData *gd);
void GAME_DATA_SetConfigFlag(struct GameData *gd, int on);
void GAME_DATA_SetSaveFlag(struct GameData *gd, u32 id, u32 on);
void GAME_DATA_CheckSaveFlag(struct GameData *gd, u32 id);
u8 *GAME_DATA_GetRtcWork(struct GameData *gd);
void GAME_DATA_LoadFromSave(struct GameData *gd);
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
void *GAME_DATA_GetEventWorkFromSave(struct SaveControl *save);
void func_02012FF0(struct SaveControl *save);
signed char func_02012FFC(void);
signed char func_02013020(void);
signed char func_02013050(void);
signed char func_02013080(u32 speed);
struct BattleSetupParam *BTL_SETUP_Create(u32 heap);
void BTL_SETUP_Delete(struct BattleSetupParam *param);
void BTL_SETUP_Clear(struct BattleSetupParam *param);
void BTL_SETUP_FreeSlots(struct BattleSetupParam *param);
void BTL_SETUP_SetParty(struct BattleSetupParam *param, struct Party *src, int client);
void *BTL_SETUP_GetParty(struct BattleSetupParam *param, int client);
void BTL_SETUP_SetStatusFlag(struct BattleSetupParam *param, int flag);
int BTL_SETUP_CheckStatusFlag(struct BattleSetupParam *param, int mask);
void BTL_SETUP_ApplyRegulation(struct BattleSetupParam *param, struct Regulation *reg, u32 level);
void BTL_SETUP_InitCommFieldSituation(struct FieldSituation *sit);
void BTL_SETUP_InitFieldSituation(struct FieldSituation *sit);
struct BattleTrainerData *BTL_SETUP_CreateTrainerData(u16 heap);
void BTL_SETUP_DeleteTrainerData(struct BattleTrainerData *tr);
void BTL_SETUP_SetTrainer(struct BattleSetupParam *param, struct GameData *gd, u32 client, struct Party **party, u32 trainerId, u16 heap);
void BTL_SETUP_SetPlayerParty(struct BattleSetupParam *param, struct GameData *gd, u16 heap);
void BTL_SETUP_InitCommon(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit);
void BTL_SETUP_SetupWild(struct BattleSetupParam *param, struct GameData *gd, struct Party *wildParty, const struct FieldSituation *sit, u32 rule, u16 heap);
void BTL_SETUP_SetupTrainerBase(struct BattleSetupParam *param, struct GameData *gd, u32 rule, const struct FieldSituation *sit, u16 heap);
void BTL_SETUP_SetupComm(struct BattleSetupParam *param, struct GameData *gd, u32 rule, u8 multiMode, u32 netHandle, u8 commPos, u8 netId, u16 heap);
void BTL_SETUP_SetupDemo(struct BattleSetupParam *param, struct GameData *gd, struct Party *enemyParty, struct Party *partnerParty, const struct FieldSituation *sit, u16 heap);
void BTL_SETUP_SetupTrainerSingle(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap);
void BTL_SETUP_SetupTrainerDouble(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap);
void BTL_SETUP_SetupTrainerTriple(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap);
void BTL_SETUP_SetupTrainerRotation(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap);
void BTL_SETUP_SetupTrainerTag(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId1, u32 trainerId2, u16 heap);
void BTL_SETUP_SetupTrainerMulti(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 partnerId, u32 trainerId1, u32 trainerId2, u16 heap);
void BTL_SETUP_SetupCommSingle(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u16 heap);
void BTL_SETUP_SetupCommDouble(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u16 heap);
void BTL_SETUP_SetupCommMulti(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u8 netId, u16 heap);
void BTL_SETUP_SetupCommAiMulti(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u8 netId, u32 trainerId1, u32 trainerId2, u16 heap);
void BTL_SETUP_SetupCommTriple(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u16 heap);
void BTL_SETUP_SetupCommRotation(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u16 heap);
void BTL_SETUP_InitWithSlots(struct BattleSetupParam *param, struct GameData *gd, u16 heap);
void BTL_SETUP_ClearWithSlots(struct BattleSetupParam *param);
void BTL_SETUP_ChangeToSubway(struct BattleSetupParam *param);
void BTL_SETUP_AllocRecordBuffer(struct BattleSetupParam *param, u32 heap);



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
 *           func_02012944, func_02012950, GAME_DATA_GetBagCursor, func_02012964,
 *           func_0201296C, func_02012974, GAME_DATA_GetMusicalWork, func_02012984,
 *           GAME_DATA_SetSeason, func_02012994, GAME_DATA_SetSubscreenMode, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, GAME_DATA_IncWalkCount, GAME_DATA_IsWalkCountEnabled, func_02012A30,
 *           func_02012A38, func_02012A44, GAME_DATA_SetFieldMode, func_02012A54,
 *           GAME_DATA_InitPlayerWork, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
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
 *    func_02012AA4 copies whole) and a five-field view.
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



void *func_0201292C(const struct GameData *gd)
{
    return gd->myItem;
}



void *func_02012934(const struct GameData *gd)
{
    return gd->myParty;
}



u32 func_0201293C(const struct GameData *gd)
{
    return gd->boxManager;
}



struct PlayerStatus *func_02012944(struct GameData *gd)
{
    return &func_020127A4(gd)->status;
}



struct PlayerStatus *func_02012950(struct GameData *gd, u32 playerId)
{
    return &gd->playerWork[playerId].status;
}



u32 GAME_DATA_GetBagCursor(const struct GameData *gd)
{
    return gd->bagCursor;
}



void *func_02012964(const struct GameData *gd)
{
    return gd->occupyInfo;
}



void *func_0201296C(const struct GameData *gd)
{
    return gd->eventWork;
}



u32 func_02012974(const struct GameData *gd)
{
    return gd->fieldWork;
}



u32 GAME_DATA_GetMusicalWork(const struct GameData *gd)
{
    return gd->musicalWork;
}



u8 func_02012984(const struct GameData *gd)
{
    return gd->season;
}



void GAME_DATA_SetSeason(struct GameData *gd, u8 value)
{
    gd->season = value;
}



u8 func_02012994(const struct GameData *gd)
{
    return gd->subscreenMode;
}



void GAME_DATA_SetSubscreenMode(struct GameData *gd, u8 value)
{
    gd->subscreenMode = value;
}



u8 func_020129AC(const struct GameData *gd)
{
    return gd->subscreenType;
}



void func_020129B8(struct GameData *gd, u32 value)
{
    gd->subscreenType = value;
}



u8 func_020129C4(const struct GameData *gd)
{
    return gd->frameRate;
}



void func_020129D0(struct GameData *gd, u8 value)
{
    gd->frameRate = value;
}



void func_020129DC(struct GameData *gd, u8 enable)
{
    gd->walkCountEnabled = enable;
    if (enable != 0) {
        gd->walkCount = 0;
    }
}



void func_020129F0(struct GameData *gd)
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



u32 func_02012A30(const struct GameData *gd)
{
    return gd->bgmInfo;
}



u32 func_02012A38(const struct GameData *gd)
{
    return gd->fieldGimmick;
}



u32 func_02012A44(const struct GameData *gd)
{
    return gd->fieldMode;
}



void GAME_DATA_SetFieldMode(struct GameData *gd, u32 value)
{
    gd->fieldMode = value;
}



u32 func_02012A54(const struct GameData *gd)
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



void func_02012A90(struct PlayerWork *player, const struct PlayerPosition *pos)
{
    player->position = *pos;
}



struct PlayerPosition *func_02012AA0(struct PlayerWork *player)
{
    return &player->position;
}



void func_02012AA4(struct PlayerWork *player, const struct RailLocationWords *rail)
{
    player->rail.all = *rail;
}



struct RailLocationWords *func_02012AB8(struct PlayerWork *player)
{
    return &player->rail.all;
}



void func_02012ABC(struct PlayerWork *player, u8 form)
{
    player->moveForm = form;
}



u8 func_02012AC0(const struct PlayerWork *player)
{
    return player->moveForm;
}



struct PlayerWork *func_02012AC4(struct PlayerWork *player, u16 zoneId)
{
    player->zoneId = zoneId;
    return player;
}



u16 func_02012AC8(const struct PlayerWork *player)
{
    return player->zoneId;
}



void func_02012ACC(struct PlayerWork *player, int direction)
{
    player->direction = direction;
}



u16 func_02012AD0(const struct PlayerWork *player)
{
    return player->direction;
}



void GAME_DATA_SetPlayerDirectionType(struct PlayerWork *player, int dirId)
{
    player->direction = sPlayerDirectionAngles[dirId];
}



/*
 *           func_02012B34, func_02012B38, GAME_DATA_GetEnterMode, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, GAME_DATA_GetSlotFlag, GAME_DATA_SetSlotFlag,
 *           GAME_DATA_IsConfigFlagSet
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * PlayerWork for func_02012AE4 .. func_02012B34 and GameData from func_02012B38 on.
 *
 * func_02012AE4 buckets the PlayerWork direction at +0x18 into 0, 1, 2 or 3.  The
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
u32 func_02012AE4(const struct PlayerWork *player)
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



u32 func_02012B28(const struct PlayerWork *player)
{
    return player->objectCode;
}



void func_02012B2C(struct PlayerWork *player, u32 code)
{
    player->objectCode = code;
}



void func_02012B30(struct PlayerWork *player, u16 zoneId)
{
    player->palaceZoneId = zoneId;
}



u16 func_02012B34(const struct PlayerWork *player)
{
    return player->palaceZoneId;
}



void *func_02012B38(const struct GameData *gd)
{
    return gd->moveModelSys;
}



u8 GAME_DATA_GetEnterMode(const struct GameData *gd)
{
    return gd->enterMode;
}



void func_02012B4C(struct GameData *gd, u8 value)
{
    gd->enterMode = value;
}



u8 func_02012B58(const struct GameData *gd)
{
    return gd->ownNetId;
}



void func_02012B64(struct GameData *gd, u8 value)
{
    gd->ownNetId = value;
}



int func_02012B70(const struct GameData *gd)
{
    return gd->intrudeCount;
}



struct GameData *func_02012B78(struct GameData *gd, u8 count)
{
    gd->intrudeCount = count;
    return gd;
}



u8 func_02012B80(const struct GameData *gd)
{
    return gd->intrudeId;
}



void func_02012B8C(struct GameData *gd, u32 value)
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
    player = func_020127A4(gd);
    func_02008808(gd->saveControl, player);
    func_020088B8(gd->saveControl, player);
    occupy = func_02012964(gd);
    func_0200EEAC(occupy, func_020071CC(gd->saveControl, 0x29));
    func_0200BE6C(gd->saveControl, (u16 *)GAME_DATA_GetLastBattleRecSlot(gd));
    unionInfo = GAME_DATA_GetSecondUnionInfo(gd);
    func_0200A884(func_0200A864(gd->saveControl), unionInfo);
    func_0200B3C8(gd->saveControl, (const struct FieldSaveData *)gd->fieldSave);
    situation = gd->situation;
    func_0200893C((const struct Situation *)situation, gd->moveModelSys);
    func_02008954((const struct Situation *)situation, &gd->season);
    fieldState = func_0201283C(gd);
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
    player = func_020127A4(gd);
    func_020087E8(gd->saveControl, player);
    func_02008860(gd->saveControl, player);
    occupy = func_02012964(gd);
    func_0200EE64(occupy, func_020071CC(gd->saveControl, 0x29));
    func_0200BE54(gd->saveControl, (const u16 *)GAME_DATA_GetLastBattleRecSlot(gd));
    unionInfo = GAME_DATA_GetSecondUnionInfo(gd);
    func_0200A870(func_0200A864(gd->saveControl), unionInfo);
    func_0200B3B0((struct FieldSaveData *)gd->fieldSave, gd->saveControl);
    situation = gd->situation;
    func_0200892C((struct Situation *)situation, gd->moveModelSys);
    func_0200894C((struct Situation *)situation, gd->season);
    fieldState = func_0201283C(gd);
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
    func_0203516C(2, 1);
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
        func_020351A0(2);
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
    func_020351A0(2);
    WIH_DWC_ResumeTimers();
    gd->isSaving = 0;
    SAVE_CONTROL_CancelSave(gd->saveControl);
    soundId = 0x80;
    if (func_02034FE8(soundId) == 1)
        func_02034FB8(soundId);
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
    func_02034F84(0x80);
    GAME_DATA_WriteToSave(gd);
    WIH_DWC_PauseTimers();
    gd->isSaving = 1;
    func_0203516C(2);
    SAVE_CONTROL_BeginExtraSaveWrite(gd->saveControl, blockId);
}



int GAME_DATA_PartSaveMain(struct GameData *gd, int blockId)
{
    int result;
    if (GFL_USE_IsLoaderBusy() == 1)
        return 0;
    result = SAVE_CONTROL_StepExtraSaveWrite(gd->saveControl, blockId);
    if (result == 2 || result == 3) {
        func_020351A0(2);
        WIH_DWC_ResumeTimers();
        gd->isSaving = 0;
        func_02034FB8(0x80);
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
 * Unlabelled Thumb tail-call thunk: func_020071CC(*p, 0x3a).
 */
void *GAME_DATA_GetSaveBlock3A(struct GameData *gd)
{
    return func_020071CC(gd->saveControl, 0x3a);
}



/*
 * Unlabelled Thumb tail-call thunk: func_020071CC(*p, 0x3b).
 */
void *GAME_DATA_GetSaveBlock3B(struct GameData *gd)
{
    return func_020071CC(gd->saveControl, 0x3b);
}



void *GAME_DATA_GetMiscSave(struct GameData *gd)
{
    return func_0200C0F0(gd->saveControl);
}



/*
 * Save-block getter through the handle's first word: tail call to
 * func_02009EC8 (block 0x1f).  Seeded from ov119 0x021E0226, 0x021E06D0,
 * 0x021E080C (tree_ov170_3).
 *
 * Addresses are Black-image addresses.
 */
void *GAME_DATA_GetSaveBlock1F(struct GameData *gd)
{
    return func_02009EC8(gd->saveControl);
}



int GAME_DATA_GetPmsWork(struct GameData *gd)
{
    return gd->pmsWork;
}



void *GAME_DATA_GetTrainerRecord(struct GameData *gd)
{
    return func_020071CC(gd->saveControl, 0x26);
}



/*
 * Unlabelled leaf accessor: base + 0x694.
 */
u8 *GAME_DATA_GetSaveSyncBlock(struct GameData *gd)
{
    return gd->saveSyncBlock;
}



/*
 * Unlabelled leaf: tail-calls func_020071CC(*(void **)p, 0x2a).
 */
void *GAME_DATA_GetSaveBlock2A(struct GameData *gd)
{
    return func_020071CC(gd->saveControl, 0x2a);
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
    return func_020071CC(gd->saveControl, 0x42);
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
 * Unlabelled leaf: tail-calls func_02009448(*p).  Filed as the witness for
 * ov021 SCRCMD_CheckWifiListFlags, SCRCMD_WifiListOperation and SCRCMD_SetWifiFriendNameWord.
 */
void *GAME_DATA_GetSaveBlockWork(struct GameData *gd)
{
    return func_02009448(gd->saveControl);
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
    return func_020071CC(gd->saveControl, 0x43);
}



void *GAME_DATA_GetEventWorkFromSave(struct SaveControl *save)
{
    return func_020071CC(save, 0x2d);
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * Message speed: the save control pointer setter and the clamped lookup of
 * the wait for the configured speed in sMsgSpeedWaitTable. These look like
 * a file of their own (see misplaced.tsv of the cleanup lane).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012FF0.c \
 *       --addr 0x02012FF0 --thumb
 */
void func_02012FF0(struct SaveControl *save)
{
    sMsgSpeedSaveControl = save;
}



signed char func_02012FFC(void)
{
    u32 speed = CONFIG_GetTextSpeed(func_0200873C(sMsgSpeedSaveControl));
    if (speed >= 5) {
        speed = 4;
    }
    return sMsgSpeedWaitTable[speed];
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * The slower and faster neighbours of the configured message speed, both
 * through the clamped lookup func_02013080.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013020.c \
 *       --addr 0x02013020 --thumb
 */
signed char func_02013020(void)
{
    u32 speed = CONFIG_GetTextSpeed(func_0200873C(sMsgSpeedSaveControl));
    switch (speed) {
    case 0:
        speed = 1;
        break;
    case 1:
        speed = 2;
        break;
    case 2:
        speed = 3;
        break;
    }
    return func_02013080(speed);
}



signed char func_02013050(void)
{
    u32 speed = CONFIG_GetTextSpeed(func_0200873C(sMsgSpeedSaveControl));
    switch (speed) {
    case 0:
        speed = 4;
        break;
    case 1:
        speed = 0;
        break;
    case 2:
        speed = 1;
        break;
    }
    return func_02013080(speed);
}



signed char func_02013080(u32 speed)
{
    if (speed >= 5) {
        speed = 4;
    }
    return sMsgSpeedWaitTable[speed];
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_Create.c \
 *       --func BTL_SETUP_Create --addr 0x02013090 --cc 1.1p1 --thumb
 */
struct BattleSetupParam *BTL_SETUP_Create(u32 heap)
{
    struct BattleSetupParam *param;
    param = func_02030734(heap, 0xf0, 0, sBtlSetupFileName, 0x31);
    BTL_SETUP_Clear(param);
    return param;
}



void BTL_SETUP_Delete(struct BattleSetupParam *param)
{
    BTL_SETUP_FreeSlots(param);
    func_020307B0(param);
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_Clear.c \
 *       --func BTL_SETUP_Clear --addr 0x020130C4 --cc 1.1p1 --thumb
 */
void BTL_SETUP_Clear(struct BattleSetupParam *param)
{
    MI_CpuFill8(param, 0, 0xf0);
    BTL_SETUP_InitFieldSituation(&param->fieldSituation);
}



/*
 * verdict is EXACT* : all 74 code bytes reproduce (5 of 5 relocation sites
 * resolved), the inferred extent only ran long by the follower at 0x02013128
 * (28 bytes, a tail-call wrapper into 0x0201AC2C|1) which has no label
 * because it saves nothing -- report it for layout/function_starts.txt
 * rather than editing that file here.
 */
void BTL_SETUP_FreeSlots(struct BattleSetupParam *param)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (param->party[i] != 0)
            func_020307B0(param->party[i]);
        if (param->trainerData[i] != 0)
            BTL_SETUP_DeleteTrainerData(param->trainerData[i]);
        if (i != 0 && param->playerStatus[i] != 0)
            func_020307B0(param->playerStatus[i]);
    }
    if (param->recordBuffer != 0)
        func_020307B0(param->recordBuffer);
    MI_CpuFill8(param, 0, 0xf0);
}



/*
 * Unlabelled Thumb thunk (btl_setup.c). Tail-calls
 * POKEPARTY_Copy (the 0x534-byte container copy in unit_0201AC2C.c,
 * prototype (src, dst)) with the second argument as source and the i-th
 * pointer of the table at +0x24 as destination.
 *
 * Addresses are Black-image addresses.
 */
void BTL_SETUP_SetParty(struct BattleSetupParam *param, struct Party *src, int client)
{
    POKEPARTY_Copy(src, param->party[client]);
}



/*
 * Unlabelled Thumb leaf: the i-th pointer of the table at +0x24.
 */
void *BTL_SETUP_GetParty(struct BattleSetupParam *param, int client)
{
    return param->party[client];
}



void BTL_SETUP_SetStatusFlag(struct BattleSetupParam *param, int flag)
{
    param->statusFlags |= (unsigned short)flag;
}



/*
 * Unlabelled leaf accessor: returns m & *(u16 *)(base + 0x82).
 */
int BTL_SETUP_CheckStatusFlag(struct BattleSetupParam *param, int mask)
{
    return param->statusFlags & mask;
}



/*
 * btl_setup.c.  The per-battle settings copier: two timer fields in seconds,
 * a name block, a three-way flag decision, and a pass over the four +0x24
 * slots binding each to the caller's third argument.
 *
 * This closes the near miss in docs/notes/pkt_02013160.c.txt, which compiled
 * 162 bytes against 172 with 77 concrete bytes out.  Three findings, in
 * descending order of how much each was worth.
 *
 * (1) THE SWITCH NEEDS AN EXPLICIT EMPTY `case 0:`.  This is the whole
 * function.  The image dispatches through a PC-relative halfword table of
 * four entries with a `cmp r0, #3 / bhi` range check, and that table only
 * exists if the case labels are dense from zero; with cases 1, 2 and 3 only,
 * the compiler emits a compare chain instead and the function comes out 12
 * bytes short.  Adding `case 0: break;` took the residue from 80 concrete
 * bytes out to ONE and the permuter's instruction score from 820 to 110, with
 * the size going from 160 to the correct 170.  See
 * docs/idioms/empty-switch-arms-are-what-make-the-table.md and
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *
 * (2) THE LOOP COUNTER IS SIGNED.  The last byte was `blt` against `blo`:
 * `int i` rather than `u32 i` for the four-slot loop.  Nothing else in the
 * function distinguishes them.
 *
 * (3) 0x10 and 0x3C are named locals, not literals.  `movs r5, #0x10` is
 * hoisted to the prologue, before the first func_0200AE54 call, and r5 is
 * then shifted left by 6 and by 7 to build the two flag masks; `movs r7,
 * #0x3c` is materialised once and reused as the multiplier for both timer
 * fields.  Spelling the masks as the constants 0x400 and 0x800, or the
 * multiplier as a literal 0x3c at each site, rematerialises them per use.
 * The multiplication is written `sec * f(...)` and not `f(...) * sec`: the
 * accumulator of a commutative chain is its second operand, so the operand
 * order here is what puts the call result in r1 and the constant in r7.
 *
 * The three switch arms tail-merge: case 3 falls into case 1's body rather
 * than duplicating the store, which is why the `b` at the end of case 2
 * targets the middle of case 1's block.  Writing the two ORs of case 3 as
 * two separate statements in source order is what produces that, not a
 * combined `|= (bit << 6) | (bit << 7)`.
 *
 * EXACT*: all 170 code bytes reproduce (4 of 4 relocation sites resolved);
 * the inferred extent ran two bytes long only on the `movs r0, r0` alignment
 * pad at 0x0201320A before BTL_SETUP_InitCommFieldSituation.  Never a byte difference.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_ApplyRegulation.c \
 *       --func BTL_SETUP_ApplyRegulation --addr 0x02013160 --cc 1.1p1 --thumb
 */
void BTL_SETUP_ApplyRegulation(struct BattleSetupParam *param, struct Regulation *reg, u32 level)
{
    u32 bit = 0x10;
    u32 sec = 0x3c;
    int i;
    param->limitTimeCommand = (u16)(sec * func_0200AE54(reg, 0x10));
    param->limitTimeGame = (u16)(sec * func_0200AE54(reg, 0xf));
    func_0200B040(reg, param->regulationRules);
    switch (func_0200AE54(reg, 0x12)) {
    case 0:
        break;
    case 1:
        param->statusFlags |= (u16)(bit << 7);
        break;
    case 2:
        param->statusFlags |= (u16)(bit << 6);
        break;
    case 3:
        param->statusFlags |= (u16)(bit << 6);
        param->statusFlags |= (u16)(bit << 7);
        break;
    }
    for (i = 0; i < 4; i++) {
        if (param->party[i] != 0) {
            POKE_REGULATION_ResetPartyNicknames(reg, param->party[i], level);
            POKE_REGULATION_AdjustPartyLevels(reg, param->party[i]);
        }
    }
}



void BTL_SETUP_InitCommFieldSituation(struct FieldSituation *sit)
{
    sit->bgType = 9;
    sit->bgAttr = 0;
    sit->weather = 0;
    sit->zoneId = 0;
    sit->hour = 0;
    sit->minute = 0;
    sit->season = 0;
}



void BTL_SETUP_InitFieldSituation(struct FieldSituation *sit)
{
    sit->bgType = 0;
    sit->bgAttr = 0;
    sit->season = 0;
    sit->weather = 0;
    sit->zoneId = 0;
    sit->hour = 0xa;
    sit->minute = 0;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_CreateTrainerData.c \
 *       --func BTL_SETUP_CreateTrainerData --addr 0x02013234 --cc 1.1p1 --thumb
 */
struct BattleTrainerData *BTL_SETUP_CreateTrainerData(u16 heap)
{
    struct BattleTrainerData *tr;
    tr = func_02030734(heap, 0x28, 1, sBtlSetupFileName, 0xef);
    tr->name = STRBUF_Create(0x10, heap);
    tr->trainerId = 0;
    PMSI_PARAM_ClearSentence(tr->winWord);
    PMSI_PARAM_ClearSentence(tr->loseWord);
    return tr;
}



void BTL_SETUP_DeleteTrainerData(struct BattleTrainerData *tr)
{
    STRBUF_Delete(tr->name);
    func_020307B0(tr);
}



/*
 * btl_setup.c.  The sub-block filler, and the most-called function of the
 * family: every builder in the range (BTL_SETUP_SetupTrainerSingle, BTL_SETUP_SetupTrainerDouble,
 * BTL_SETUP_SetupTrainerTriple, BTL_SETUP_SetupTrainerRotation, BTL_SETUP_SetupTrainerTag, BTL_SETUP_SetupTrainerMulti, BTL_SETUP_SetupCommAiMulti,
 * all EXACT) calls it once or three times.  It lazily fills two slots - the
 * caller's own out-pointer and the object's +0x48 array entry - then, only if
 * the value argument is non-zero, binds them together and picks the object's
 * +0x1a code from a twelve-way switch.
 *
 * This closes the near miss in docs/notes/pkt_02013284.c.txt, which sat at 48
 * concrete bytes out with the size already exact.  Two things closed it.
 *
 * (1) THE ARITY IS SIX, NOT SEVEN.  The note gave it seven parameters
 * (a0..a6).  The six-parameter form is fixed from outside this function by
 * the matched callers, every one of which passes exactly six
 * (o, a1, n, dst, v, h).  Re-spelling the signature that way took the
 * residue from 48 concrete bytes out to 15 and halved the permuter's
 * instruction score, 525 -> 280, with the size unchanged at 184.
 *
 * (2) THE +0x48 SLOT IS REGISTER-OFFSET ADDRESSED, so its base and its
 * scaled index have to be two separate live values.  The image loads it with
 * `ldr r0, [r7, r6]` where r7 is o+0x48 and r6 is n*4; writing the access as
 * a single pointer, `slot = (u32 *)(o + 0x48 + n * 4)`, folds the two into
 * one value and the allocator then has one fewer value to colour, which is
 * what produced the r5/r6/r7 rotation the permuter reported.  Splitting it
 * into a `u8 *slots` (the trainerData array) and a separate `u32 off`, and indexing as
 * `*(struct BattleTrainerData **)(slots + off)`, keeps both values live and gives the original
 * registers and the original `lsls` / `adds` order.  A `u32 *` base with a
 * divided index (`base[off / 4]`) does NOT work: the compiler folds the
 * scaling back out and the rotation returns.
 *
 * The permuter was the diagnostic here rather than the fix.  `--explain` on
 * the seven-parameter source printed a clean three-way register rotation
 * (r7->r6, r6->r7, r5->...), which is what said the residue was an allocation
 * tie and not a mistranslation, and on the six-parameter source it printed
 * the same rotation at 15 bytes out with every instruction aligned - which
 * localised the fix to the one value that was missing.  Its own best results
 * were rejected on both passes: hill found temp(tmp=*slot) at 11 bytes out
 * but with the instruction score RISING 280 -> 460, the signature of a
 * coincidental byte alignment rather than a real fix.
 *
 * The switch is dense from 2 to 11 with 0, 1, 5 and 10 falling to the
 * default, which is what makes the PC-relative halfword table exist; the
 * `cmp r0, #0xb / bhi` pair is the table's range check.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetTrainer.c \
 *       --func BTL_SETUP_SetTrainer --addr 0x02013284 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetTrainer(struct BattleSetupParam *param, struct GameData *gd, u32 client, struct Party **party, u32 trainerId, u16 heap)
{
    u8 *slots;
    u32 off;
    if (*party == 0) {
        *party = POKEPARTY_Create(heap);
    }
    off = client * 4;
    slots = (u8 *)param->trainerData;
    if (*(struct BattleTrainerData **)(slots + off) == 0) {
        *(struct BattleTrainerData **)(slots + off) = BTL_SETUP_CreateTrainerData(heap);
    }
    if (trainerId == 0) {
        return;
    }
    func_0202A440(trainerId, *(struct BattleTrainerData **)(slots + off), heap);
    func_0202A4B4(trainerId, *party, heap);
    FORMCHANGE_UpdateSeasonForms(gd, *party, func_02012984(gd));
    switch (func_0202A3FC((*(struct BattleTrainerData **)(slots + off))->trainerType)) {
    case 2:
    case 3:
        param->bgmWin = 0x47e;
        break;
    case 7:
    case 8:
        param->bgmWin = 0x47f;
        break;
    case 4:
    case 11:
        param->bgmWin = 0x480;
        break;
    case 6:
    case 9:
        param->bgmWin = 0x491;
        break;
    default:
        param->bgmWin = 0x47d;
        break;
    }
}



void BTL_SETUP_SetPlayerParty(struct BattleSetupParam *param, struct GameData *gd, u16 heap)
{
    func_020127A4(gd);
    param->party[0] = POKEPARTY_Create(heap);
    POKEPARTY_Copy(func_02012934(gd), param->party[0]);
}



/*
 * btl_setup.c.  The shared setup-object initialiser every builder of the
 * family calls with (o, a1, sub): reset the flag and slot fields, read the
 * per-battle values out of the game-data object a1, and copy the 0x10-byte
 * sub-block a2 to +8.
 *
 * Two facts closed it (docs/notes/pkt_02013360.c.txt had it at 266 bytes
 * out, every line phase-shifted from the head):
 *  - 0x02082D44 is MI_CpuCopy8 (layout/symbols_sdk.txt), whose order is
 *    (src, dst, size): the image computes o + 8 into r1 and a2 into r0.
 *    With that order the whole body is byte-exact and only the head differs.
 *  - The first loop counter is initialised at its declaration, ahead of the
 *    store run.  That puts the constant 0 (shared by the zero stores and the
 *    counter) before the 0xffff store in the IR, so the zero takes r0 and
 *    the 0x84 base is built in r1 from the o copy, which is the image's
 *    head.  With `for (i = 0; ...)` the base coalesces into r0 instead and
 *    every later line is displaced.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_InitCommon.c  *       --func BTL_SETUP_InitCommon --addr 0x02013360 --cc 1.1p1 --thumb
 */
void BTL_SETUP_InitCommon(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit)
{
    u32 i = 0;
    u32 j;
    struct SaveControl *save;
    void *misc;
    param->levelCap = 0xffff;
    param->commPos = 0;
    param->netId = 0;
    param->multiMode = 0;
    param->recordBuffer = 0;
    param->ownsSlots = 0;
    param->bitFlags = param->bitFlags & ~1;
    param->netHandle = 0;
    param->bitFlags = param->bitFlags & ~2;
    param->gameData = gd;
    for (; i < 4; i++) {
        param->party[i] = 0;
        param->playerStatus[i] = 0;
    }
    for (j = 0; j < 6; j++) {
        param->resultFlags[j] = 0;
    }
    param->recordEnabled = 1;
    for (i = 0; i < 7; i++) {
        param->regulationRules[i] = 0;
    }
    param->playerStatus[0] = func_02012944(gd);
    param->myItem = func_0201292C(gd);
    param->mapMatrix = GAME_DATA_GetMapMatrix(gd);
    param->zukanWork = ZUKAN_SAVE_GetFromGameData(gd);
    param->pmsWork = GAME_DATA_GetPmsWork(gd);
    param->trainerRecord = GAME_DATA_GetTrainerRecord(gd);
    save = GAME_DATA_GetSaveControl(gd);
    misc = func_0200C0E8(save);
    param->config = func_0200873C(save);
    param->badgeCount = (u8)func_0200C258(misc);
    MI_CpuCopy8(sit, &param->fieldSituation, 0x10);
    param->bgmBattle = 0x468;
    param->bgmWin = 0x468 + 0x14;
    param->moneyRate = 1;
    if (ZONEDATA_CheckEventFlag(func_0201296C(gd), 0x96d) != 0) {
        BTL_SETUP_SetStatusFlag(param, 2);
    }
}



/*
 * btl_setup.c.  The link-battle variant of the setup builder: the same
 * three shared writers as BTL_SETUP_SetupDemo, then the object is put in mode 0
 * and a consistency check on the +0x24 slot decides whether flag 0x40 is
 * set.
 *
 * The documented near miss in docs/notes/pkt_02013360.c.txt compiled 122
 * bytes against 120 and missed on 108 of them.  Two leftover-register
 * readings are what close it, and both are the same idiom, see
 * docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md.
 *
 * (1) POKEPARTY_Copy takes the POKEPARTY_Create result as a second argument.
 * The original writes `adds r1, r0, #0; str r1, [r4, #0x28]`, which reads
 * as a gratuitous register copy before the store.  It is not: r1 is the
 * second argument of the guarded POKEPARTY_Copy call below, so the value has
 * to reach r1 anyway and the store then sources it from there.  The
 * first drafts declared POKEPARTY_Copy variadic; with every call written with
 * both arguments, the plain (src, dst) prototype gives the same bytes.
 *
 * (2) func_020076D0 takes THREE arguments, and its first is the return
 * value of the func_0201293C call immediately above it.  The original sets
 * only r1 and r2 (`add r1, sp, #4; add r2, sp, #0`) and leaves r0 holding
 * what func_0201293C returned.  Declaring it with two parameters puts the
 * two pointers in r0/r1 and is a two-byte, two-instruction miss; declaring
 * func_0201293C as returning u32 and passing that result explicitly gives
 * the original bytes with no extra `adds`, because the value is already in
 * r0 and the compiler elides the copy.
 *
 * The two out-parameters are declared x then y but passed &x as the SECOND
 * argument and &y as the third: x lives at sp+4 and y at sp+0, which is the
 * later-declaration-at-the-lower-address rule, see
 * docs/idioms/local-declaration-order-is-stack-order.md.
 *
 * EXACT*: all 118 code bytes reproduce (10 of 10 relocation sites
 * resolved); the inferred extent ran two bytes long only on the
 * `movs r0, r0` alignment pad at 0x020134F2 before BTL_SETUP_SetupTrainerBase.  Never a
 * byte difference.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupWild.c \
 *       --func BTL_SETUP_SetupWild --addr 0x0201347C --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupWild(struct BattleSetupParam *param, struct GameData *gd, struct Party *wildParty, const struct FieldSituation *sit, u32 rule, u16 heap)
{
    u32 tray;
    u32 pos;
    struct Party *enemy;
    u32 count;
    u32 box;
    BTL_SETUP_Clear(param);
    BTL_SETUP_InitCommon(param, gd, sit);
    BTL_SETUP_SetPlayerParty(param, gd, heap);
    enemy = POKEPARTY_Create(heap);
    param->party[1] = enemy;
    if (wildParty != 0) {
        POKEPARTY_Copy(wildParty, enemy);
    }
    param->rule = rule;
    param->competitor = 0;
    count = POKEPARTY_GetCount(param->party[0]);
    if (count != POKEPARTY_GetCapacity(param->party[0])) {
        return;
    }
    box = func_0201293C(gd);
    tray = 0;
    pos = 0;
    if (func_020076D0(box, &tray, &pos) == 0) {
        BTL_SETUP_SetStatusFlag(param, 0x40);
    }
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupTrainerBase.c \
 *       --func BTL_SETUP_SetupTrainerBase --addr 0x020134F4 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupTrainerBase(struct BattleSetupParam *param, struct GameData *gd, u32 rule, const struct FieldSituation *sit, u16 heap)
{
    BTL_SETUP_Clear(param);
    BTL_SETUP_InitCommon(param, gd, sit);
    BTL_SETUP_SetPlayerParty(param, gd, heap);
    param->competitor = 1;
    param->rule = rule;
    param->bgmWin = 0x47d;
}






/*
 * btl_setup.c. The eight-argument setup builder (sibling of BTL_SETUP_SetupDemo).
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 152/152, 6 bytes out for four
 * waves, docs/notes/pkt_02013528.c.txt): the eighth (stack) parameter is a
 * heap id and is u16, with u16 on the matching parameter of BTL_SETUP_SetPlayerParty,
 * MYSTATUS_Create and POKEPARTY_Create (BTL_SETUP_SetupDemo already declares the first
 * and last that way). With u32 there, 1.1p1 schedules the r3 home store
 * `str r3, [sp]` after the three parameter copies; with u16 it comes first,
 * as in the image. docs/idioms/a-u16-stack-parameter-passed-to-a-u16-callee-
 * stays-behind-a-spill-store.md is the same lever.
 */
void BTL_SETUP_SetupComm(struct BattleSetupParam *param, struct GameData *gd, u32 rule, u8 multiMode, u32 netHandle, u8 commPos, u8 netId, u16 heap)
{
    struct FieldSituation sit;
    u32 i;
    BTL_SETUP_Clear(param);
    BTL_SETUP_InitCommFieldSituation(&sit);
    sit.bgType = 9;
    sit.bgAttr = 1;
    BTL_SETUP_InitCommon(param, gd, &sit);
    BTL_SETUP_SetPlayerParty(param, gd, heap);
    param->competitor = 3;
    param->rule = rule;
    param->netHandle = netHandle;
    param->commPos = commPos;
    param->multiMode = multiMode;
    param->netId = netId;
    param->levelCap = 0xff;
    param->bgmWin = 0x47d;
    i = 0;
    do {
        if (i != 0) {
            if (param->playerStatus[i] == 0)
                param->playerStatus[i] = MYSTATUS_Create(heap);
            if (param->party[i] == 0)
                param->party[i] = POKEPARTY_Create(heap);
        }
        i++;
    } while (i < 4);
}






/*
 * btl_setup.c.  The four-argument variant of the setup builder: the shared
 * writers run first, then up to two optional attachments are bound through
 * POKEPARTY_Copy, and the object is left in mode 4.
 *
 * This closes the near miss documented in docs/notes/pkt_02013528.c.txt.
 * That note was right that POKEPARTY_Copy cannot carry a fixed two-parameter
 * prototype - the first call site passes r0 and r1, the second passes only
 * r0 - and right that a variadic declaration, `void POKEPARTY_Copy(u32 a,
 * ...)`, is the only one under which both sites emit the original bytes.
 * What it could not recover was the `adds r1, r0, #0` the original keeps
 * before the +0x28 store, and it concluded that binding the result to a
 * named local did not help.
 *
 * The resolution is that r1 is not a register copy at all: it is the SECOND
 * ARGUMENT of the second POKEPARTY_Copy call.  Writing the call as
 * `POKEPARTY_Copy(a3, r)` - handing it the POKEPARTY_Create result the +0x28
 * store also consumes - produces `adds r1, r0, #0; str r1, [r5, #0x28]`
 * exactly, because the value has to reach r1 for the call and the store
 * then reads it from there.  The "leftover" register really is a passed
 * argument, the same tell as
 * docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md.
 * Both calls pass (src, dst), so the plain two-parameter prototype holds.
 *
 * Permuter note: tools/permuter.py hill (179 mutations tried) reached
 * 6 bytes out at the right size with copy(r->r_@6), but its mutation was
 * `r_ = r;` BEFORE r is assigned - an uninitialised read that scores well
 * and is not admissible C.  It did correctly localise the residue to a
 * single r1 -> r0 substitution at the store, which is what pointed at the
 * argument reading rather than at a copy.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupDemo.c \
 *       --func BTL_SETUP_SetupDemo --addr 0x020135C0 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupDemo(struct BattleSetupParam *param, struct GameData *gd, struct Party *enemyParty, struct Party *partnerParty, const struct FieldSituation *sit, u16 heap)
{
    struct Party *party;
    BTL_SETUP_Clear(param);
    BTL_SETUP_InitCommon(param, gd, sit);
    BTL_SETUP_SetPlayerParty(param, gd, heap);
    if (enemyParty != 0) {
        POKEPARTY_Copy(enemyParty, param->party[0]);
    }
    party = POKEPARTY_Create(heap);
    param->party[1] = party;
    if (partnerParty != 0) {
        POKEPARTY_Copy(partnerParty, party);
    }
    param->competitor = 4;
    param->rule = 0;
}






/*
 * One of a family of four (0x02013610, 0x02013644, 0x02013678, 0x020136AC)
 * that differ only in the constant handed to BTL_SETUP_SetupTrainerBase as its third
 * argument - 0, 1, 2 and 3 - so this is the id-0 member of a table of
 * builders.  The fifth argument arrives on the stack (the `add r2, sp, #0x20`
 * / `ldrh` pair), which is why the prologue pushes six registers and then
 * takes eight more bytes.
 *
 * The same object goes to both calls; the second call's fourth argument is
 * the object plus 0x28 (the tail of the two stack arguments it forwards).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupTrainerSingle.c \
 *       --func BTL_SETUP_SetupTrainerSingle --addr 0x02013610 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupTrainerSingle(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap)
{
    BTL_SETUP_SetupTrainerBase(param, gd, 0, sit, heap);
    BTL_SETUP_SetTrainer(param, gd, 1, &param->party[1], trainerId, heap);
}






/*
 * Member 1 of the four-member family at 0x02013610..0x020136E0 - the same
 * two calls with the same object, differing only in the id handed to
 * BTL_SETUP_SetupTrainerBase (1 here, and 0, 1, 2, 3 across the family).  The fifth
 * argument arrives on the stack.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupTrainerDouble.c \
 *       --func BTL_SETUP_SetupTrainerDouble --addr 0x02013644 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupTrainerDouble(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap)
{
    BTL_SETUP_SetupTrainerBase(param, gd, 1, sit, heap);
    BTL_SETUP_SetTrainer(param, gd, 1, &param->party[1], trainerId, heap);
}






/*
 * Member 2 of the four-member family at 0x02013610..0x020136E0 - the same
 * two calls with the same object, differing only in the id handed to
 * BTL_SETUP_SetupTrainerBase (2 here, and 0, 1, 2, 3 across the family).  The fifth
 * argument arrives on the stack.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupTrainerTriple.c \
 *       --func BTL_SETUP_SetupTrainerTriple --addr 0x02013678 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupTrainerTriple(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap)
{
    BTL_SETUP_SetupTrainerBase(param, gd, 2, sit, heap);
    BTL_SETUP_SetTrainer(param, gd, 1, &param->party[1], trainerId, heap);
}




/*
 * Member 3 of the four-member family at 0x02013610..0x020136E0 - the same
 * two calls with the same object, differing only in the id handed to
 * BTL_SETUP_SetupTrainerBase (3 here, and 0, 1, 2, 3 across the family).  The fifth
 * argument arrives on the stack.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupTrainerRotation.c \
 *       --func BTL_SETUP_SetupTrainerRotation --addr 0x020136AC --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupTrainerRotation(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap)
{
    BTL_SETUP_SetupTrainerBase(param, gd, 3, sit, heap);
    BTL_SETUP_SetTrainer(param, gd, 1, &param->party[1], trainerId, heap);
}



/*
 * The main variant of the three-slot setup (see BTL_SETUP_SetupTrainerMulti, the brief
 * one): the first call is the four-register form of the same writer with
 * count 1, then two calls into BTL_SETUP_SetTrainer that each carry the source's
 * own stack arguments - a word and the halfword at +4 of the argument
 * block - plus the two object sub-blocks at +0x28 and +0x30.  The last
 * store marks the object's +0x22 byte as the count of sub-blocks.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupTrainerTag.c \
 *       --func BTL_SETUP_SetupTrainerTag --addr 0x020136E0 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupTrainerTag(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId1, u32 trainerId2,
                   u16 heap)
{
    BTL_SETUP_SetupTrainerBase(param, gd, 1, sit, heap);
    BTL_SETUP_SetTrainer(param, gd, 1, &param->party[1], trainerId1, heap);
    BTL_SETUP_SetTrainer(param, gd, 3, &param->party[3], trainerId2, heap);
    param->multiMode = 4;
}



/*
 * The three-slot setup that takes a single word argument block: the shared
 * halfword is the first word of that block (its low half, copied into the
 * outgoing stack slot of the first call) and the fourth word of the object
 * is the outer value both other calls carry.  Only three sub-blocks here,
 * so the trailing byte is 3.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupTrainerMulti.c \
 *       --func BTL_SETUP_SetupTrainerMulti --addr 0x02013734 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupTrainerMulti(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 partnerId, u32 trainerId1,
                   u32 trainerId2, u16 heap)
{
    BTL_SETUP_SetupTrainerBase(param, gd, 1, sit, heap);
    BTL_SETUP_SetTrainer(param, gd, 2, &param->party[2], partnerId, heap);
    BTL_SETUP_SetTrainer(param, gd, 1, &param->party[1], trainerId1, heap);
    BTL_SETUP_SetTrainer(param, gd, 3, &param->party[3], trainerId2, heap);
    param->multiMode = 3;
}



/*
 * The id-0 member of the second builder family in this packet: the fourth
 * argument of the shared 8-argument helper BTL_SETUP_SetupComm is 0, and the
 * object's argument is first run through GFL_NET_GetHandleNetID (ARM) whose result
 * becomes the seventh argument.  BTL_SETUP_SetupComm's last four parameters live
 * on the stack, which is the sixteen-byte frame.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupCommSingle.c \
 *       --func BTL_SETUP_SetupCommSingle --addr 0x02013790 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupCommSingle(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u16 heap)
{
    u8 netId = GFL_NET_GetHandleNetID((struct NetHandle *)netHandle);
    BTL_SETUP_SetupComm(param, gd, 0, 0, netHandle, commPos, netId, heap);
}



/*
 * The id-1 member of the same family - byte for byte BTL_SETUP_SetupCommSingle with a 1
 * where it has a 0 (the third argument of BTL_SETUP_SetupComm).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupCommDouble.c \
 *       --func BTL_SETUP_SetupCommDouble --addr 0x020137C0 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupCommDouble(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u16 heap)
{
    u8 netId = GFL_NET_GetHandleNetID((struct NetHandle *)netHandle);
    BTL_SETUP_SetupComm(param, gd, 1, 0, netHandle, commPos, netId, heap);
}




/*
 * The shortest member of the family: no GFL_NET_GetHandleNetID call, and the two stack
 * arguments the caller passes (a byte at +0x00 and a halfword at +0x04 of the
 * caller's stack block) are forwarded as the seventh and eighth arguments.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupCommMulti.c \
 *       --func BTL_SETUP_SetupCommMulti --addr 0x020137F0 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupCommMulti(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u8 netId, u16 heap)
{
    BTL_SETUP_SetupComm(param, gd, 1, 1, netHandle, commPos, netId, heap);
}




/*
 * btl_setup.c.  The three-slot builder on the eight-argument writer: the
 * same shape as BTL_SETUP_SetupTrainerTag and BTL_SETUP_SetupTrainerMulti (both EXACT), but the lead
 * call is BTL_SETUP_SetupComm rather than BTL_SETUP_SetupTrainerBase, so the object's mode is
 * stored by this function (1) instead of by the writer.
 *
 * The documented near miss in docs/notes/pkt_02013810.c.txt compiled 56
 * bytes against 84 because it gave BTL_SETUP_SetupComm six parameters and
 * BTL_SETUP_SetTrainer seven, and passed the object's +0x28 sub-block as a bare
 * constant.  The arity is fixed by the matched members of both families:
 * BTL_SETUP_SetupComm takes eight (BTL_SETUP_SetupCommSingle, BTL_SETUP_SetupCommMulti et al) and
 * BTL_SETUP_SetTrainer takes six (BTL_SETUP_SetupTrainerSingle, BTL_SETUP_SetupTrainerTag et al).  With those
 * two prototypes and the shared halfword forwarded to all three calls, the
 * body is the ordinary family shape and matches first try.
 *
 * The incoming stack block is what `add r6, sp, #0x28` addresses (0x10 of
 * frame plus six pushed registers): a4 is the byte at +0x00, a5 the word at
 * +0x04, a6 the word at +0x08 and a7 the halfword at +0x0C, which is why a7
 * is re-loaded with `ldrh [r6, #0xc]` before each of the three calls rather
 * than kept in a register.
 *
 * EXACT*: all 82 code bytes reproduce (3 of 3 relocation sites resolved);
 * the inferred extent ran two bytes long only on the `movs r0, r0` alignment
 * pad at 0x02013862 before BTL_SETUP_SetupCommTriple, which has a label.  Never a byte
 * difference.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupCommAiMulti.c \
 *       --func BTL_SETUP_SetupCommAiMulti --addr 0x02013810 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupCommAiMulti(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u8 netId, u32 trainerId1, u32 trainerId2, u16 heap)
{
    BTL_SETUP_SetupComm(param, gd, 1, 2, netHandle, commPos, netId, heap);
    param->competitor = 1;
    BTL_SETUP_SetTrainer(param, gd, 1, &param->party[1], trainerId1, heap);
    BTL_SETUP_SetTrainer(param, gd, 3, &param->party[3], trainerId2, heap);
}



/*
 * The id-2 member of the same family - byte for byte BTL_SETUP_SetupCommSingle with a 2
 * where it has a 0 (the third argument of BTL_SETUP_SetupComm).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupCommTriple.c \
 *       --func BTL_SETUP_SetupCommTriple --addr 0x02013864 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupCommTriple(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u16 heap)
{
    u8 netId = GFL_NET_GetHandleNetID((struct NetHandle *)netHandle);
    BTL_SETUP_SetupComm(param, gd, 2, 0, netHandle, commPos, netId, heap);
}



/*
 * The id-3 member of the same family - byte for byte BTL_SETUP_SetupCommSingle with a 3
 * where it has a 0 (the third argument of BTL_SETUP_SetupComm).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupCommRotation.c \
 *       --func BTL_SETUP_SetupCommRotation --addr 0x02013894 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupCommRotation(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u16 heap)
{
    u8 netId = GFL_NET_GetHandleNetID((struct NetHandle *)netHandle);
    BTL_SETUP_SetupComm(param, gd, 3, 0, netHandle, commPos, netId, heap);
}




void BTL_SETUP_InitWithSlots(struct BattleSetupParam *param, struct GameData *gd, u16 heap)
{
    u32 i;
    struct Config *config;
    struct Config *copy;
    MI_CpuFill8(param, 0, 0xf0);
    for (i = 0; i < 4; i++) {
        param->party[i] = POKEPARTY_Create(heap);
        param->playerStatus[i] = MYSTATUS_Create(heap);
        param->trainerData[i] = BTL_SETUP_CreateTrainerData(heap);
    }
    param->gameData = gd;
    config = func_0200873C(GAME_DATA_GetSaveControl(gd));
    copy = CONFIG_Create(heap);
    param->config = copy;
    CONFIG_Copy(config, copy);
    param->zukanWork = ZUKAN_SAVE_GetFromGameData(gd);
    param->ownsSlots = 1;
    BTL_SETUP_AllocRecordBuffer(param, heap);
}




/*
 * The subsystem destructor: the +0x5C buffer is released and its pointer
 * cleared (the store inside the guard, not after it), then the teardown is
 * handed to BTL_SETUP_FreeSlots with the object left in r0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_ClearWithSlots.c  *       --func BTL_SETUP_ClearWithSlots --addr 0x02013930 --cc 1.1p1 --thumb
 */
void BTL_SETUP_ClearWithSlots(struct BattleSetupParam *param)
{
    if (param->config != 0) {
        func_020307B0(param->config);
        param->config = 0;
    }
    BTL_SETUP_FreeSlots(param);
}




/*
 * btl_setup.c.  A one-shot state step: only while the state word is 1 does it
 * advance to 2 and choose a pair of halfword bounds, keyed off a value read
 * through the object's +0x4c pointer.  The 0x470/0x480 pair is built by
 * `movs`+`lsls` (Thumb has no wide immediate), the 0x46b/0x47d pair comes
 * from the literal pool because 0x46b does not fit a Thumb immediate - both
 * spellings are a plain `u16` store of a constant.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_ChangeToSubway.c \
 *       --func BTL_SETUP_ChangeToSubway --addr 0x0201394C --cc 1.1p1 --thumb
 */
void BTL_SETUP_ChangeToSubway(struct BattleSetupParam *param)
{
    if (param->competitor == 1) {
        param->competitor = 2;
        if (func_0202A3FC(param->trainerData[1]->trainerType) != 0xb) {
            param->bgmBattle = 0x46b;
            param->bgmWin = 0x47d;
        } else {
            param->bgmBattle = 0x470;
            param->bgmWin = 0x480;
        }
    }
}




/*
 * btl_setup.c.  A lazy 0xc00-byte zeroed allocation hung off the object at
 * +0x94: the allocator gets the caller's heap (its own r0 is overwritten by
 * the pointer arithmetic, so the heap is carried in r1 at entry), the class
 * id 3 << 10 and the file name/line pair.  The `str r0, [sp]` is the fifth
 * argument, i.e. the source line 0x39a.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_AllocRecordBuffer.c \
 *       --func BTL_SETUP_AllocRecordBuffer --addr 0x02013980 --cc 1.1p1 --thumb
 */
void BTL_SETUP_AllocRecordBuffer(struct BattleSetupParam *param, u32 heap)
{
    if (param->recordBuffer == 0) {
        param->recordBuffer = func_02030734(heap, 3 << 10, 0, sBtlSetupFileName, 0x39a);
    }
}
