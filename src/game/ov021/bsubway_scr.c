/*
 * file:     bsubway_scr.c
 * unit:     yes
 * function: BSUBWAY_SCR_ClearWorkPtr, BSUBWAY_SCR_CreateWork, BSUBWAY_SCR_DeleteWork, BSUBWAY_SCR_ChangeCommMultiMode, BSUBWAY_SCR_SaveRestPlayData, BSUBWAY_SCR_LoadMembers, BSUBWAY_SCR_SavePlayDataMembers, BSUBWAY_SCR_ResetPlayMode, BSUBWAY_SCR_SetLoseScore, BSUBWAY_SCR_AddBattlePoint, BSUBWAY_SCR_DrawTrainerNos, BSUBWAY_SCR_SetSelectedMembers, BSUBWAY_SCR_IsWinMax, BSUBWAY_SCR_SetClearScore, BSUBWAY_SCR_ClearStateBits, BSUBWAY_SCR_CreateRoundTrainers, BSUBWAY_SCR_GetTrainerObjCode, BSUBWAY_SCR_UpdateStageRank, BSUBWAY_SCR_LoadPartyCopy, BSUBWAY_SCR_GetParty, BSUBWAY_SCR_GetWinCount, BSUBWAY_SCR_SetWinCount, BSUBWAY_SCR_IncWinCount, BSUBWAY_SCR_ClearWinCount, BSUBWAY_SCR_SetWinCountFromRound, BSUBWAY_SCR_GetMemberNum, BSUBWAY_SCR_IsTrainerNoUsed, BSUBWAY_SCR_GetStageNo, BSUBWAY_SCR_SaveRecordParty, BSUBWAY_SCR_CreatePartners, BSUBWAY_SCR_PackBattleMon, BSUBWAY_SCR_SaveMemberParty, BSUBWAY_SCR_CmdCreateWork, BSUBWAY_SCR_CmdClearWorkPtr, BSUBWAY_SCR_CmdDeleteWork, BSUBWAY_SCR_CmdTool, func_021CB6DC, func_021CB700, func_021CB754, func_021CB7E8, func_021CB86C, func_021CB8AC, func_021CB914, func_021CB934, func_021CB9BC, func_021CB9E4, func_021CBBA0, func_021CBBAC, func_021CBBD0, func_021CBC14, BSUBWAY_SCR_GetRegulationNo, BSUBWAY_SCR_GetTrainNo, func_021CBD08, func_021CBD84, BSUBWAY_SCR_DrawTrainerNo, BSUBWAY_SCR_CreateTrainer, BSUBWAY_SCR_GetMonIv, BSUBWAY_SCR_CreatePartnerMons, func_021CBF98
 * address:  0x021C9924
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * bsubway_scr.c __FILE__ anchors at 0x021C9934 and 0x021CA4C0; 0x021C9924 is called only from 0x021CA57C.
 *
 * symbols:
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   ICA_ANIME_GetField20  0x0201210C  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   GAME_DATA_SetCurrentEvent  0x02012EE4  thumb
 *   func_02012944  0x02012944  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   d_021DE58C     0x021DE58C  data  ov021
 *   func_02008550  0x02008550  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_0200D868  0x0200D868  thumb
 *   func_0200D85C  0x0200D85C  thumb
 *   func_0200DA14  0x0200DA14  thumb
 *   func_0200DB44  0x0200DB44  thumb
 *   func_0200DAC4  0x0200DAC4  thumb
 *   func_0200D914  0x0200D914  thumb
 *   func_0200D884  0x0200D884  thumb
 *   GAME_DATA_GetField114  0x020127A4  thumb
 *   func_0200DA54  0x0200DA54  thumb
 *   func_0200DB80  0x0200DB80  thumb
 *   BTL_SETUP_Delete  0x020130B4  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0200DB1C  0x0200DB1C  thumb
 *   func_0200DB08  0x0200DB08  thumb
 *   func_0200DAEC  0x0200DAEC  thumb
 *   func_0200DC08  0x0200DC08  thumb
 *   func_0200DA80  0x0200DA80  thumb
 *   d_021DACDC     0x021DACDC  data  a1
 *   func_0200DB60  0x0200DB60  thumb
 *   func_0200DEA8  0x0200DEA8  thumb
 *   FLD_BTL_INST_TOOL_LookupKeyValue  0x02168AEC  thumb  ov010
 *   func_0200DBA0  0x0200DBA0  thumb
 *   func_0200DBF0  0x0200DBF0  thumb
 *   func_0200DC0C  0x0200DC0C  thumb
 *   func_0200DBFC  0x0200DBFC  thumb
 *   data_021DACD0  0x021DACD0  data
 *   BATTLE_BOX_GetFromSave  0x0200BAC8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_0200DC94  0x0200DC94  thumb
 *   func_0200DC50  0x0200DC50  thumb
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   GAME_DATA_GetCurrentEvent  0x02012ED8  thumb
 *   data_021DAD24  0x021DAD24  data
 *   data_021DAD36  0x021DAD36  data
 *   data_021DAD70  0x021DAD70  data
 *   data_021DAD88  0x021DAD88  data
 *   data_021DADAC  0x021DADAC  data
 *   data_021DAE50  0x021DAE50  data
 *   BATTLE_REC_FreeWork  0x0200B424  thumb
 *   BATTLE_REC_CheckSaved  0x0200B5CC  thumb
 *   BATTLE_REC_IsVersionSupported  0x0200BA38  thumb
 *   BATTLE_REC_LoadToolOverlay  0x0200BA58  thumb
 *   BATTLE_REC_UnloadToolOverlay  0x0200BA68  thumb
 *   BATTLE_BOX_HasMon  0x0200BBA8  thumb
 *   func_0200D87C  0x0200D87C  thumb
 *   func_0200D9E8  0x0200D9E8  thumb
 *   func_0200DA28  0x0200DA28  thumb
 *   func_0200DB30  0x0200DB30  thumb
 *   BSUBWAY_SAVEDATA_GetTrainersPresent  0x0200DE5C  thumb
 *   BSUBWAY_SAVEDATA_GetHistoryPresent  0x0200DE64  thumb
 *   BSUBWAY_SAVEDATA_GetTrainersTagA  0x0200DE94  thumb
 *   BSUBWAY_SAVEDATA_GetHistoryTagA  0x0200DF40  thumb
 *   BSUBWAY_SAVEDATA_GetHistoryTagB  0x0200DF4C  thumb
 *   BSUBWAY_SAVEDATA_AllocHistoryCopy  0x0200DF58  thumb
 *   BSUBWAY_SAVEDATA_CountHistoryEntries  0x0200DF94  thumb
 *   MISC_SAVEDATA_GetBlock44  0x0200ED48  thumb
 *   MISC_SAVEDATA_InsertRecentValue  0x0200ED54  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   GFL_NET_ERR_RequestScreen  0x0200FB38  thumb
 *   VM_SetWait  0x020113D0  thumb
 *   ICA_ANIME_SetField30  0x02012124  thumb
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   GAME_DATA_SetField168  0x0201289C  thumb
 *   ov007_id       0x00000007  data  a1
 *   ov100_id       0x00000064  data  a1
 *   ov214_id       0x000000D6  data  a1
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_SetDirectLocation  0x02014184  thumb
 *   ZONEDATA_SetEventFlag  0x02014314  thumb
 *   ZONEDATA_ResetEventFlag  0x0201433C  thumb
 *   FIELD_STATUS_CreateSubProcCallbackEvent  0x02014808  thumb
 *   func_02019ED4  0x02019ED4  thumb
 *   POKE_REGULATION_Load  0x0201A354  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   ISS_SYS_GetSwitchSys  0x0202B578  thumb
 *   ISS_SWITCH_SYS_SwitchOn  0x0202C0D0  thumb
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   OS_ResetSystem  0x02087BCC  arm
 *   EVENT_BSUBWAY_COMM_Start  0x021542C0  thumb  ov007
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_GetWorkPtr  0x02158FE0  thumb  ov010
 *   BSUBWAY_COMM_NetInit  0x02167AB0  thumb  ov010
 *   BSUBWAY_COMM_AddCommandTable  0x02167B00  thumb  ov010
 *   BSUBWAY_COMM_StartTimingSync  0x02167B24  thumb  ov010
 *   BSUBWAY_COMM_SetSendData  0x02167BFC  thumb  ov010
 *   BSUBWAY_COMM_SetRecvMode  0x02167CF4  thumb  ov010
 *   NAMEIN_SETUP_StartPartyPickEvent  0x0216C538  thumb  ov010
 *   NAMEIN_SETUP_StartEncounterScene  0x0216C640  thumb  ov010
 *   NAMEIN_SETUP_StartNameBalloonFromRecord  0x0216C6E8  thumb  ov010
 *   NAMEIN_SETUP_StartHistoryScreenEvent  0x0216C860  thumb  ov010
 *   NAMEIN_SETUP_StartNameBalloonFromHistory  0x0216CB48  thumb  ov010
 *   FLDMMDL_GetParam  0x0216D63C  thumb  ov010
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   FLDMMDL_OnMoveBitMovePause  0x0216DAF8  thumb  ov010
 *   FLDMMDL_SetStatusBitHeightGetOff  0x0216DB4C  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_InitPosition  0x0216E014  thumb  ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   FIELD_PLAYER_GetSex  0x021A30B0  thumb  ov021
 *   FIELD_PLAYER_GetFormObjCode  0x021A3190  thumb  ov021
 *   FIELD_PLAYER_GetObjCodeOfFormCode  0x021A31A4  thumb  ov021
 *   data_021BB474  0x021BB474  data  ov214
 *   data_021BB6A4  0x021BB6A4  data  ov100
 *   COMM_ENTRY_MENU_Create  0x021CD48C  thumb  ov021
 *   FLDEFF_BTRAIN_SetAnime  0x021D024C  thumb  ov021
 *   FLDEFF_BTRAIN_SetHidden  0x021D028C  thumb  ov021
 *   BATTLE_REC_TOOL_PackSetup  0x021EEE78  thumb  ov188
 *   FIELD_GIMMICK_BSUBWAY_StartTrain  0x021F37C0  thumb  ov052
 *   FIELD_GIMMICK_BSUBWAY_GetTrainEffect  0x021F380C  thumb  ov052
 *   FIELD_GIMMICK_BSUBWAY_HaltTrainSway  0x021F388C  thumb  ov052
 *   BSUBWAY_COMM_SendData  0x02167CB4  thumb  ov010
 *   BSUBWAY_COMM_CheckTimingSync  0x02167B34  thumb  ov010
 *   COMM_ENTRY_MENU_Main  0x021CD688  thumb  ov021
 *   COMM_ENTRY_MENU_Delete  0x021CD5A4  thumb  ov021
 *   BSUBWAY_COMM_IsRecvEnd  0x02167D00  thumb  ov010
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   BSUBWAY_COMM_DeleteCommandTable  0x02167B18  thumb  ov010
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   SCRCMD_WORK_SetWaitCount  0x0215A684  thumb  ov010
 *   SCRCMD_WORK_CountDownWait  0x0215A690  thumb  ov010
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb
 *   FIELD_MSGBG_CreateYesNoMenu  0x02190BE4  thumb
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb
 *   BSUBWAY_SAVEDATA_GetHistoryEntryScore  0x0200DFB4  thumb
 *   FLDMMDL_AddMmdlParam  0x0216CE6C  thumb  ov010
 *   FLDMMDL_SetParam  0x0216D620  thumb  ov010
 *   FLDMMDL_SetEventId  0x0216D5B4  thumb  ov010
 *   d_021DADD0     0x021DADD0  data  a2
 *   d_021DAD48     0x021DAD48  data  a2
 *   d_021DAD5C     0x021DAD5C  data  a2
 *   d_021DAEBC     0x021DAEBC  data  a2
 *   d_021DADF8     0x021DADF8  data  a4
 *   data_021DAEBC  0x021DAEBC  data
 *   BATTLE_REC_BeginSave  0x0200B6E0  thumb
 *   POKEPARTY_Create  0x0201A920  thumb
 *   POKEPARTY_InitEx  0x0201A954  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   FLD_BTL_INST_TOOL_CreateBtlSetup  0x021681C8  thumb  ov010
 *   d_021DB3D0  0x021DB3D0  data
 *   d_021DB3D8  0x021DB3D8  data
 *   d_021DB3E4  0x021DB3E4  data
 *   d_021DB3F4  0x021DB3F4  data
 *   FLD_BTL_INST_TOOL_CreateTrainer  0x02168878  thumb  ov010
 *   FLD_BTL_INST_TOOL_InitTrainerHeader  0x021688BC  thumb  ov010
 *   FLD_BTL_INST_TOOL_BuildBattleMon  0x021684E8  thumb  ov010
 *   func_020056EC  0x020056EC  thumb
 */

#define NULL ((void *)0)
struct GameSystem;
struct GameData;
struct ScriptStream;
struct Task;
struct FieldMap;
struct VecFx32;
struct MapObj;
struct BsubwayScoreData;
struct BsubwayPlayData;
struct SaveControl;
struct MyStatus;
struct BsubwayRecordSrc;
struct BsubwayWifiRecordList;
struct GdsProfileSave;
struct Ov007ProcParam;
struct BsubwayWifiData;
struct ReturnLocation;
struct PartySelectParam;
struct ScreenHandle;
struct WifiRecordEntry;
struct Party;
struct PartyMon;
struct BattleSystem;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short s16;

typedef signed char    s8;

typedef int (*TaskFn)(void *task, int *state, void *work);

typedef signed int     s32;

#include "bsubway_scr_types.h"












/* Work area of the sub-screen task (fade out, run the screen, report whether it was cancelled). */
typedef struct ScreenTaskWork {
    void *script;
    u16 *result;
    u32 screen;
    u32 arg;
} ScreenTaskWork;

typedef struct VecFx32 {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

/* Seven-word entrance location record (zone, direction, position). */
typedef struct ReturnLocation {
    u32 word[7];
} ReturnLocation;

/* Parameter of the ov007 proc started by commands 103 to 105. */
typedef struct Ov007ProcParam {
    u32 mode;
    u16 *result;
} Ov007ProcParam;

/* Index of the record entry written by the progress record command. */
typedef enum BsubwayRecordNo {
    BSUBWAY_RECORD_NO_FIRST
} BsubwayRecordNo;

/* Spawn position of a record-list marker object (halfword pairs). */
typedef struct SpawnPos {
    s16 x;
    s16 reserved02;
    s16 y;
    s16 reserved06;
} SpawnPos;

/* One 0x10-byte marker object table entry. */
typedef struct SpawnEntry {
    u16 objCode;
    u16 thresholdNo;
    s16 x;
    u16 reserved06;
    s16 y;
    u16 param;
    u32 reserved0C;
} SpawnEntry;

/* Byte at +0x20 of a wifi record list entry. */
typedef struct WifiRecordFlags {
    u8 flag0 : 1;
    u8 lookSet : 1;
} WifiRecordFlags;

/* 0x10-byte NPC table entry; infoThird == 0 marks an unavailable entry. */
typedef struct NpcInfoEntry {
    u8 reserved00[0xa];
    u16 infoFirst;
    u16 infoSecond;
    u16 infoThird;
} NpcInfoEntry;

typedef struct TrainerNoRange {
    u16 minNo;
    u16 maxNo;
} TrainerNoRange;


extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *ICA_ANIME_GetField20(const struct GameSystem *p);
extern void *ICA_ANIME_GetField1C(const struct GameSystem *p);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern u16 func_02011330(struct ScriptStream *s);
extern u16 SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern struct Task *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Task *p);
extern void *FIELDMAP_GetFieldPlayer(struct FieldMap *p);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern void FLDMMDL_SetDirDispCheckPause(int a, int b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void FLDMMDL_GetPos(const struct MapObj *a, struct VecFx32 *v);
extern void *GAME_DATA_SetCurrentEvent(GameData *gameData, BsubwayScrWork *work);
extern u8 *func_02012944(void *p);
extern void *GAME_DATA_GetSaveControl(struct GameData *p);
extern u8 func_02008550(const struct MyStatus *obj);
extern void *func_020071CC(struct SaveControl *ctrl, u32 id);
extern void func_0200D868(struct BsubwayPlayData *p, u32 v);
extern void func_0200D85C(struct BsubwayPlayData *p);
extern void func_0200DA14(struct BsubwayPlayData *p);
extern u32 func_0200DB44(struct BsubwayScoreData *p, u32 i);
extern u16 func_0200DAC4(struct BsubwayScoreData *p, u32 i);
extern void func_0200D914(struct BsubwayPlayData *p, u32 id, const void *src);
extern u32 func_0200D884(struct BsubwayPlayData *p, u32 id, void *out);
extern void *GAME_DATA_GetField114(void *p);
extern u16 func_0200DA54(struct BsubwayPlayData *p);
extern u16 func_0200DB80(struct BsubwayScoreData *p, u32 i);
extern int BTL_SETUP_Delete(int a0);
extern void MI_CpuFill8(void *p, int v, int n);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 func_02017E1C(void *m, u32 id, u32 v);
extern void func_0200DB1C(struct BsubwayScoreData *p, u32 i);
extern void func_0200DB08(struct BsubwayScoreData *p, u32 i, u16 v);
extern void func_0200DAEC(struct BsubwayScoreData *p, u32 i, u16 v);
extern u8 func_0200DC08(struct BsubwayScoreData *p);
extern void func_0200DA80(struct BsubwayScoreData *p, s32 v);
extern void func_0200DB60(struct BsubwayScoreData *p, u32 i);
extern void func_0200DEA8(u32 h, u8 *list, u8 n, u16 id);
extern u16 FLD_BTL_INST_TOOL_LookupKeyValue(u16 a0);
extern u32 func_0200DBA0(struct BsubwayScoreData *p, s32 i, u32 op);
extern void func_0200DBF0(struct BsubwayScoreData *p);
extern u8 func_0200DC0C(struct BsubwayScoreData *p, u32 kind);
extern void func_0200DBFC(struct BsubwayScoreData *p);
extern void *BATTLE_BOX_GetFromSave(void *p);
extern void *func_0200BAF4(int a0, int a1);
extern void *GAME_DATA_GetMyParty(const struct GameData *p);
extern int func_0209C0A4(int a, int b);
extern void func_0200DC94(struct BsubwayScoreData *p, const struct BsubwayRecordSrc *q);
extern void func_0200DC50(struct BsubwayScoreData *p, u32 which, const void *src);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern void *SCRIPT_WORK_GetGameSystem(void *p);
extern void *GAME_DATA_GetCurrentEvent(struct GameData *p);
extern u32 GAME_DATA_GetEventWork(const struct GameData *p);
extern u16 *SCRIPT_WORK_GetWorkPtr(void *a, void *b, unsigned int id);
extern void SCRIPT_SYS_CallEvent(void *h, void *task);
extern void OS_ResetSystem(u32 a);
extern u32 func_0200D87C(struct BsubwayPlayData *p);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void ZONEDATA_SetDirectLocation(ReturnLocation *out, u32 id, s16 n, u32 a, u32 b, u32 c);
extern void GAME_DATA_SetField168(struct GameData *p, const struct ReturnLocation *src);
extern void ZONEDATA_SetEventFlag(char *a0, int a1);
extern void ZONEDATA_ResetEventFlag(char *a0, int a1);
extern u32 FIELD_PLAYER_GetSex(u8 *p);
extern u16 FIELD_PLAYER_GetFormObjCode(int i, int j);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern void *FLDMMDL_SysSearchObjId(void *a, u32 id);
extern void FLDMMDL_SetStatusBitVanish(unsigned int *p, unsigned int v);
extern void FIELD_GIMMICK_BSUBWAY_StartTrain(void *a, int b, int c);
extern int FIELD_GIMMICK_BSUBWAY_GetTrainEffect(int a);
extern void FLDEFF_BTRAIN_SetAnime(void *o, u32 v);
extern void FLDEFF_BTRAIN_SetHidden(void *o, u32 v);
extern void FLDMMDL_InitPosition(void *a, int *p, int b);
extern int FLDMMDL_SetStatusBitHeightGetOff(void *a0, int a1);
extern int FIELD_PLAYER_GetObjCodeOfFormCode(int i, int v);
extern u32 BATTLE_BOX_HasMon(void *a);
extern void FLDMMDL_OnMoveBitMovePause(void *o);
extern int FLDMMDL_GetParam(char *a0, int a1);
extern void *NAMEIN_SETUP_StartNameBalloonFromHistory(u32 x, u32 v, u32 id);
extern struct BsubwayWifiRecordList *BSUBWAY_SAVEDATA_AllocHistoryCopy(struct BsubwayWifiData *p, u32 heap);
extern u32 BSUBWAY_SAVEDATA_CountHistoryEntries(struct BsubwayWifiRecordList *b);
extern struct Task *GAME_EVENT_CreateOverlayEvent(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern int EVENT_BSUBWAY_COMM_Start(int x, struct Ov007ProcParam *p);
extern u8 BSUBWAY_SAVEDATA_GetTrainersTagA(struct BsubwayWifiData *p);
extern u8 BSUBWAY_SAVEDATA_GetTrainersPresent(struct BsubwayWifiData *p);
extern u8 BSUBWAY_SAVEDATA_GetHistoryPresent(struct BsubwayWifiData *p);
extern void *NAMEIN_SETUP_StartHistoryScreenEvent(void *a);
extern int BSUBWAY_SAVEDATA_GetHistoryTagA(struct BsubwayWifiData *p);
extern u8 BSUBWAY_SAVEDATA_GetHistoryTagB(struct BsubwayWifiData *p);
extern void *NAMEIN_SETUP_StartPartyPickEvent(struct PartySelectParam *c, void *sys, u8 useOwn);
extern void *NAMEIN_SETUP_StartEncounterScene(BsubwayScrWork *work, u32 gameSystem, void *fieldMap);
extern void *NAMEIN_SETUP_StartNameBalloonFromRecord(BsubwayScrWork *work, void *gameSystem, u32 idx, u16 id, u8 dir);
extern u32 GAMESYSTEM_GetIssSystem(u32 *p);
extern u32 ISS_SYS_GetSwitchSys(u32 *p);
extern void ISS_SWITCH_SYS_SwitchOn(u8 *p, u32 a);
extern void *POKE_REGULATION_Load(int a, int b);
extern int func_02019ED4(void *ctx, void *q);
extern u32 BATTLE_REC_CheckSaved(void *a, u32 heap, u32 *dp, u32 id);
extern void BATTLE_REC_LoadToolOverlay(void);
extern void BATTLE_REC_TOOL_PackSetup(void *p);
extern void BATTLE_REC_UnloadToolOverlay(void);
extern void VM_SetWait(char *p, int val);
extern void BATTLE_REC_FreeWork(void);
extern void *FIELD_STATUS_CreateSubProcCallbackEvent(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void FIELD_GIMMICK_BSUBWAY_HaltTrainSway(int a);
extern u32 POKEPARTY_GetCount(void *party);
extern void func_0200D9E8(struct BsubwayPlayData *p, s32 a, s32 b, s32 c);
extern void func_0200DA28(struct BsubwayPlayData *p);
extern void func_0200DB30(struct BsubwayScoreData *p, u32 i);
extern void BSUBWAY_COMM_AddCommandTable(u32 a);
extern void BSUBWAY_COMM_NetInit(void *p);
extern int BSUBWAY_COMM_StartTimingSync(int a0);
extern u32 COMM_ENTRY_MENU_Create(u32 a, void *b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void BSUBWAY_COMM_SetSendData(BsubwayScrWork *work, u32 cmd, u32 arg);
extern void BSUBWAY_COMM_SetRecvMode(BsubwayScrWork *work, u8 v);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void MISC_SAVEDATA_InsertRecentValue(struct GdsProfileSave *l, u32 val);
extern void *MISC_SAVEDATA_GetBlock44(void *p);
extern void GFL_NET_ERR_RequestScreen(void);
extern void ICA_ANIME_SetField30(struct GameSystem *p, u32 v);
extern u32 func_0200FB24(void);
extern u32 BATTLE_REC_IsVersionSupported(u32 v);
extern int BSUBWAY_COMM_SendData(BsubwayScrWork *work);
extern int BSUBWAY_COMM_CheckTimingSync(int a0);
extern u32 COMM_ENTRY_MENU_Main(u8 *p);
extern u32 COMM_ENTRY_MENU_Delete(u32 *p);
extern int BSUBWAY_COMM_IsRecvEnd(BsubwayScrWork *work, u16 *out);
extern u32 GFL_NET_IsParentAid(void);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void BSUBWAY_COMM_DeleteCommandTable(void *p);
extern int GFL_NET_GetNegotiationNum(void);
extern int GFL_NET_Exit(int a0);
extern int GFL_NET_IsSessionNull(void);
extern void SCRCMD_WORK_SetWaitCount(int *p, unsigned short v);
extern int SCRCMD_WORK_CountDownWait(char *a0);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern u32 *FIELD_MSGBG_CreateYesNoMenu(u16 *a, u32 b);
extern int FIELD_MSGBG_YesNoMenuMain(struct ScreenHandle *h);
extern int FIELD_MSGBG_DeleteMenuFunc(void *a);
extern u32 BSUBWAY_SAVEDATA_GetHistoryEntryScore(struct WifiRecordEntry *e);
extern void *FLDMMDL_AddMmdlParam(void *o, int x, int y, u16 d, u32 a, u32 b, u32 c, u32 e);
extern int FLDMMDL_SetParam(int a0, int a1, int a2);
extern void FLDMMDL_SetEventId(void *h, u16 v);
extern u32 BATTLE_REC_BeginSave(void *a, u16 b, u32 c, u32 d, u32 e, u16 *state, u16 *sub);
extern struct Party *POKEPARTY_Create(u32 heap);
extern void POKEPARTY_InitEx(struct Party *p, s32 capacity);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern struct BattleSystem *FLD_BTL_INST_TOOL_CreateBtlSetup(void *gameSystem, void *party, u32 playMode, BtlInstTrainer *trainers, BtlInstTrainer *partner, int memberNum);
extern u8 FLD_BTL_INST_TOOL_CreateTrainer(BtlInstTrainer *trainer, u16 trainerNo, u8 memberNum, u16 *monsNo, u16 *itemNo, BtlInstDraw *draw, u16 heapId);
extern void *FLD_BTL_INST_TOOL_InitTrainerHeader(BtlInstTrainer *trainer, int trainerNo, u16 heapId);
extern u32 FLD_BTL_INST_TOOL_BuildBattleMon(struct BattleMon *out, u32 member, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useItem, u16 heap);
extern u32 func_020056EC(u32 max);
int BSUBWAY_SCR_ClearWorkPtr(GameSystem *gameSystem);
BsubwayScrWork *BSUBWAY_SCR_CreateWork(GameSystem *gameSystem, int resume, u32 playMode);
void BSUBWAY_SCR_DeleteWork(GameSystem *gameSystem, BsubwayScrWork *work);
void BSUBWAY_SCR_ChangeCommMultiMode(BsubwayScrWork *work);
void BSUBWAY_SCR_SaveRestPlayData(BsubwayScrWork *work);
void BSUBWAY_SCR_LoadMembers(BsubwayScrWork *work, u32 unused);
void BSUBWAY_SCR_SavePlayDataMembers(BsubwayScrWork *work);
u32 BSUBWAY_SCR_ResetPlayMode(const struct GameSystem *gameSystem);
void BSUBWAY_SCR_SetLoseScore(u32 unused, BsubwayScrWork *work);
u32 BSUBWAY_SCR_AddBattlePoint(BsubwayScrWork *work);
void BSUBWAY_SCR_DrawTrainerNos(BsubwayScrWork *work);
u32 BSUBWAY_SCR_SetSelectedMembers(BsubwayScrWork *work, u32 unused);
int BSUBWAY_SCR_IsWinMax(BsubwayScrWork *work);
void BSUBWAY_SCR_SetClearScore(BsubwayScrWork *work, u32 unused);
int BSUBWAY_SCR_ClearStateBits(BsubwayScrWork *work, u32 unused);
void BSUBWAY_SCR_CreateRoundTrainers(BsubwayScrWork *work);
u32 BSUBWAY_SCR_GetTrainerObjCode(BsubwayScrWork *work, int i);
int BSUBWAY_SCR_UpdateStageRank(void *scoreData, int unused, int mode);
void BSUBWAY_SCR_LoadPartyCopy(BsubwayScrWork *work);
void *BSUBWAY_SCR_GetParty(BsubwayScrWork *work);
u16 BSUBWAY_SCR_GetWinCount(BsubwayScrWork *work);
void BSUBWAY_SCR_SetWinCount(BsubwayScrWork *work, u16 winCount);
void BSUBWAY_SCR_IncWinCount(BsubwayScrWork *work);
int BSUBWAY_SCR_ClearWinCount(BsubwayScrWork *work);
void BSUBWAY_SCR_SetWinCountFromRound(BsubwayScrWork *work, u32 stage, u32 round);
int BSUBWAY_SCR_GetMemberNum(u16 playMode);
int BSUBWAY_SCR_IsTrainerNoUsed(const u16 *list, u16 value, u16 count);
u16 BSUBWAY_SCR_GetStageNo(u16 winCount);
void BSUBWAY_SCR_SaveRecordParty(BsubwayScrWork *work, u32 saveControl, int unused, u16 winCount);
void BSUBWAY_SCR_CreatePartners(BsubwayScrWork *work, u8 isAltRom);
void BSUBWAY_SCR_PackBattleMon(BattleMon *mon, u32 pokeParam);
void BSUBWAY_SCR_SaveMemberParty(BsubwayScrWork *work, u32 unused, int slot);
int BSUBWAY_SCR_CmdCreateWork(u32 script, u32 scriptCtx);
int BSUBWAY_SCR_CmdClearWorkPtr(u32 script, u32 scriptCtx);
int BSUBWAY_SCR_CmdDeleteWork(u32 script, u32 scriptCtx);
int BSUBWAY_SCR_CmdTool(void *scriptCtx, u32 script);
int func_021CB6DC(void *task, void *script);
int func_021CB700(u32 unused, u32 script);
int func_021CB754(u32 unused, u32 script);
int func_021CB7E8(u32 unused, u32 script);
int func_021CB86C(u32 unused, u32 script);
int func_021CB8AC(void *task, int *rank, BsubwayScrWork **work);
void *func_021CB914(void *gameSystem, u32 script);
int func_021CB934(void *task, int *rank, ScreenTaskWork *taskWork);
void *func_021CB9BC(void *gameSystem, u32 script, u32 resultDst, u32 arg);
void func_021CB9E4(BsubwayScrWork *work, void *gameData, void *fieldMmdlSys, void *fieldMap);
u32 func_021CBBA0(u32 mapObj);
u32 func_021CBBAC(BsubwayScrWork *work, u32 idx);
void func_021CBBD0(BsubwayScrWork *work, u32 idx, u16 *infoFirst, u16 *infoSecond, u16 *infoThird);
int func_021CBC14(u32 unused, u32 script);
int BSUBWAY_SCR_GetRegulationNo(u32 playMode);
int BSUBWAY_SCR_GetTrainNo(void *fieldMap);
u32 func_021CBD08(BsubwayScrWork *work, int gameSystem);
void *func_021CBD84(void *work);
u16 BSUBWAY_SCR_DrawTrainerNo(BsubwayScrWork *work, u32 round, u32 stage, u32 line, u8 alt);
u8 BSUBWAY_SCR_CreateTrainer(BsubwayScrWork *work, BtlInstTrainer *trainer, u16 trainerNo, u8 memberNum, u16 *monsNo, u16 *itemNo, BtlInstDraw *draw, u16 heapId);
u8 BSUBWAY_SCR_GetMonIv(u32 trainerNo);
void BSUBWAY_SCR_CreatePartnerMons(BsubwayScrWork *work, BtlInstTrainer *trainer, u16 trainerNo, int useItem, BtlInstDraw *draw, u16 heapId);
u16 func_021CBF98(void *unused);
extern const char d_021DE58C[];
extern const u8 d_021DACDC[7][10];
extern const u8 data_021DACD0[];
extern u8 data_021BB474[];
extern u8 data_021BB6A4[];
extern char ov007_id[];
extern char ov100_id[];
extern char ov214_id[];
extern const u16 data_021DAD36[];
extern const u32 data_021DAD88[];
extern const VecFx32 data_021DAD70[];
extern const VecFx32 data_021DAE50[];
extern const u32 data_021DADAC[];
extern const u16 data_021DAD24[];
extern const SpawnPos d_021DADD0[];
extern const u16 d_021DAD48[];
extern const u16 d_021DAD5C[];
extern const SpawnEntry d_021DAEBC[];
extern const u32 d_021DADF8[];
extern const NpcInfoEntry data_021DAEBC[];
extern const TrainerNoRange d_021DB3D0[];
extern const TrainerNoRange d_021DB3D8[];
extern const TrainerNoRange d_021DB3E4[];
extern const TrainerNoRange d_021DB3F4[];






/*
 * Blocking site: the bl to GAME_DATA_SetCurrentEvent at +0008 of this function.
 *
 * no listing carries scoreData func_ label at this address -- disasm.py classified the bytes as data in every overlay whose window holds it -- and the only branches to it are these ov021 call sites, so the `label` class has no traced entry point to read and scoreData region hint cannot invent one.  Filing scoreData source for the TARGET (rule 10) would attest every caller that needs it, with no change here.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int BSUBWAY_SCR_ClearWorkPtr(GameSystem *gameSystem)
{
    return (int)GAME_DATA_SetCurrentEvent(ICA_ANIME_GetField1C(gameSystem), 0);
}






BsubwayScrWork *BSUBWAY_SCR_CreateWork(GameSystem *gameSystem, int resume, u32 playMode)
{
    GameData *gameData;
    void *myStatus;
    SaveControl *saveControl;
    BsubwayScrWork *work;
    int i;
    u32 trainerBase;
    u32 mode;
    u16 round;
    u8 saveByte;

    gameData = ICA_ANIME_GetField1C(gameSystem);
    myStatus = func_02012944(gameData);
    saveControl = GAME_DATA_GetSaveControl(gameData);
    work = func_02030734(4, 0x7EC, 1, d_021DE58C, 0x5f);
    work->heapId = 4;
    work->magic = 0x12345678;
    work->gameData = gameData;
    work->romCode = func_02008550(myStatus);
    work->playData = func_020071CC(saveControl, 0x39);
    work->scoreData = func_020071CC(saveControl, 0x3a);
    work->wifiData = func_020071CC(saveControl, 0x3b);
    func_0200D868(work->playData, 0);
    GAME_DATA_SetCurrentEvent(gameData, work);
    if (resume == 0) {
        work->playMode = playMode;
        work->memberNum = BSUBWAY_SCR_GetMemberNum(work->playMode);
        for (i = 0; i < 4; i++)
            work->memberIndex[i] = 0xff;
        for (i = 0; i < 14; i++)
            work->trainerNo[i] = 0xffff;
        func_0200D85C(work->playData);
        func_0200DA14(work->playData);
        if (func_0200DB44(work->scoreData, work->playMode) == 1)
            BSUBWAY_SCR_SetWinCount(work, func_0200DAC4(work->scoreData, work->playMode));
        saveByte = work->playMode;
        func_0200D914(work->playData, 0, &saveByte);
    } else {
        work->playMode = func_0200D884(work->playData, 0, 0);
        work->memberNum = BSUBWAY_SCR_GetMemberNum(work->playMode);
        if (func_0200D884(work->playData, 10, 0) != 0)
            BSUBWAY_SCR_LoadPartyCopy(work);
        func_0200D884(work->playData, 5, work->memberIndex);
        func_0200D884(work->playData, 8, work->trainerNo);
        if (work->playMode == 2 || work->playMode == 7) {
            work->stateBits.partnerNo = (u8)func_0200D884(work->playData, 9, 0);
            func_0200D884(work->playData, 6, &work->partnerDraws[work->stateBits.partnerNo]);
            trainerBase = 0x12f;
            if (func_02008550((const struct MyStatus *)((u8 *)GAME_DATA_GetField114(gameData) + 0x20)) != 0)
                trainerBase -= 3;
            i = work->stateBits.partnerNo;
            BSUBWAY_SCR_CreatePartnerMons(work, &work->partners[i], trainerBase + i, func_0200D884(work->playData, 7, 0), &work->partnerDraws[i], work->heapId);
        }
        mode = work->playMode;
        if (func_0200DB44(work->scoreData, mode) == 1) {
            round = func_0200DA54(work->playData);
            BSUBWAY_SCR_SetWinCountFromRound(work, func_0200DB80(work->scoreData, mode), round);
        }
    }
    return work;
}






void BSUBWAY_SCR_DeleteWork(GameSystem *gameSystem, BsubwayScrWork *work)
{
    if (work != 0) {
        if (work->partyCopy != 0) {
            func_020307B0(work->partyCopy);
            work->partyCopy = 0;
        }
        if (work->btlSetup != 0) {
            BTL_SETUP_Delete((int)(work->btlSetup));
            work->btlSetup = 0;
        }
        MI_CpuFill8(work, 0, 0x7EC);
        func_020307B0(work);
    }
    GAME_DATA_SetCurrentEvent(ICA_ANIME_GetField1C(gameSystem), 0);
}






/*
 * Remaps playMode 2/7 to 3/8, pushes it to the play data and refreshes winCount from the score data.
 *
 * Addresses are Black-image addresses.
 */
void BSUBWAY_SCR_ChangeCommMultiMode(BsubwayScrWork *work)
{
    u8 commMode;

    if (work->playMode == 2)
        commMode = 3;
    else if (work->playMode == 7)
        commMode = 8;
    work->playMode = commMode;
    func_0200D914(work->playData, 0, &commMode);
    if (func_0200DB44(work->scoreData, work->playMode) == 1)
        BSUBWAY_SCR_SetWinCount(work, func_0200DAC4(work->scoreData, work->playMode));
    else
        BSUBWAY_SCR_ClearWinCount(work);
}






/*
 * Pushes playMode, the memberIndex and trainerNo blocks and, for playMode 2/7, the selected partnerResult entry to the play data.
 *
 * Addresses are Black-image addresses.
 */
void BSUBWAY_SCR_SaveRestPlayData(BsubwayScrWork *work)
{
    u8 saveByte = work->playMode;

    func_0200D914(work->playData, 0, &saveByte);
    func_0200D914(work->playData, 5, work->memberIndex);
    func_0200D914(work->playData, 8, work->trainerNo);
    func_0200D868(work->playData, 1);
    if (work->playMode == 2 || work->playMode == 7) {
        saveByte = work->stateBits.partnerNo;
        func_0200D914(work->playData, 9, &saveByte);
        func_0200D914(work->playData, 6, &work->partnerDraws[work->stateBits.partnerNo]);
        func_0200D914(work->playData, 7, &work->partnerResult[work->stateBits.partnerNo]);
    }
}






/*
 * Classifies playMode into memberNum and reads two stats per slot into memberMonsNo and memberItemNo.
 *
 * Addresses are Black-image addresses.
 */
void BSUBWAY_SCR_LoadMembers(BsubwayScrWork *work, u32 unused)
{
    void *party;
    int i;
    u32 mon;

    work->memberNum = BSUBWAY_SCR_GetMemberNum(work->playMode);
    func_0200D884(work->playData, 5, work->memberIndex);
    party = BSUBWAY_SCR_GetParty(work);
    for (i = 0; i < work->memberNum; i++) {
        mon = (u32)POKEPARTY_GetMember(party, work->memberIndex[i]);
        work->memberMonsNo[i] = func_02017E1C((void *)mon, 5, 0);
        work->memberItemNo[i] = func_02017E1C((void *)mon, 6, 0);
    }
}






/*
 * Like 0x021C9BCC with a reset of the play data and without the trainerNo block.
 *
 * Addresses are Black-image addresses.
 */
void BSUBWAY_SCR_SavePlayDataMembers(BsubwayScrWork *work)
{
    u8 saveByte = work->playMode;

    func_0200D914(work->playData, 0, &saveByte);
    func_0200DA14(work->playData);
    func_0200D914(work->playData, 5, work->memberIndex);
    func_0200D868(work->playData, 1);
    if (work->playMode == 2 || work->playMode == 7) {
        saveByte = work->stateBits.partnerNo;
        func_0200D914(work->playData, 9, &saveByte);
        func_0200D914(work->playData, 6, &work->partnerDraws[work->stateBits.partnerNo]);
        func_0200D914(work->playData, 7, &work->partnerResult[work->stateBits.partnerNo]);
    }
}






/*
 * Reads the play mode from the play data, clears the play data and resets the score data entry of that mode.
 *
 * Addresses are Black-image addresses.
 */
u32 BSUBWAY_SCR_ResetPlayMode(const struct GameSystem *gameSystem)
{
    u32 saveControl = (u32)GAME_DATA_GetSaveControl((struct GameData *)ICA_ANIME_GetField1C(gameSystem));
    u32 playData = (u32)func_020071CC((struct SaveControl *)saveControl, 0x39);
    u32 scoreData = (u32)func_020071CC((struct SaveControl *)saveControl, 0x3a);
    u8 playMode = func_0200D884((struct BsubwayPlayData *)playData, 0, 0);

    func_0200DA14((struct BsubwayPlayData *)playData);
    func_0200DB1C((struct BsubwayScoreData *)scoreData, playMode);
    return playMode;
}






/*
 * Commits winCount for the current playMode and redraws.
 *
 * Addresses are Black-image addresses.
 */
void BSUBWAY_SCR_SetLoseScore(u32 unused, BsubwayScrWork *work)
{
    u16 winCount = work->winCount;
    u8 playMode = work->playMode;
    u32 scoreData = (u32)work->scoreData;

    func_0200DB08((struct BsubwayScoreData *)scoreData, playMode, winCount);
    func_0200DAEC((struct BsubwayScoreData *)scoreData, playMode, winCount);
    BSUBWAY_SCR_SaveRecordParty(work, (u32)GAME_DATA_GetSaveControl(work->gameData), 1, winCount);
    func_0200DB1C(work->scoreData, playMode);
    func_0200DA14(work->playData);
}






/*
 * Picks a step amount from a 7x10 byte table by playMode and a clamped
 * counter, adds it to the record in scoreData and returns it.
 *
 * Addresses are Black-image addresses.
 */
u32 BSUBWAY_SCR_AddBattlePoint(BsubwayScrWork *work)
{
    int points;
    int row;
    int idx;
    u16 count;

    if (work->playMode == 4) {
        points = 0;
        if ((u16)func_0200D884(work->playData, 0xB, 0) == 1) {
            idx = (s8)func_0200DC08(work->scoreData);
            if (idx < 0)
                idx = 0;
            else if (idx >= 10)
                idx = 9;
            points = d_021DACDC[6][idx];
        } else {
            points = 5;
        }
    } else {
        points = 0;
        count = func_0200DB80(work->scoreData, work->playMode);
        switch (work->playMode) {
        case 0:
            row = 0;
            break;
        case 5:
            row = 1;
            points = 1;
            break;
        case 1:
            row = 2;
            break;
        case 6:
            row = 3;
            points = 1;
            break;
        case 2:
            row = 4;
            break;
        case 3:
            row = 4;
            break;
        case 7:
            row = 5;
            points = 1;
            break;
        case 8:
            row = 5;
            points = 1;
            break;
        case 4:
            row = 6;
            break;
        default:
            row = 0;
            break;
        }
        count = count - 1;
        if ((s16)count < 0)
            idx = 0;
        else if (count >= 10)
            idx = 9;
        else
            idx = count;
        if (work->stateBits.fixedBpMode) {
            if (points == 1)
                points = 30;
            else
                points = 10;
        } else {
            points = d_021DACDC[row][idx];
        }
    }
    if (points == 0)
        points = 1;
    func_0200DA80(work->scoreData, points);
    return points;
}






/*
 * Fills the trainerNo list with distinct draws: 14 for playMode 2, 3, 7, 8, else 7.
 *
 * Addresses are Black-image addresses.
 */
void BSUBWAY_SCR_DrawTrainerNos(BsubwayScrWork *work)
{
    u8 playMode = work->playMode;
    u16 stage = BSUBWAY_SCR_GetStageNo(BSUBWAY_SCR_GetWinCount(work));
    int i;
    u16 trainerNo;

    if (playMode == 2 || playMode == 3 || playMode == 7 || playMode == 8) {
        if (stage < work->partnerStage)
            stage = work->partnerStage;
        for (i = 0; i < 14; i++) {
            do {
                trainerNo = BSUBWAY_SCR_DrawTrainerNo(work, stage, (u8)(i / 2), playMode, (u8)(i & 1));
            } while (BSUBWAY_SCR_IsTrainerNoUsed(work->trainerNo, trainerNo, i));
            work->trainerNo[i] = trainerNo;
        }
    } else {
        for (i = 0; i < 7; i++) {
            do {
                trainerNo = BSUBWAY_SCR_DrawTrainerNo(work, stage, (u8)i, work->playMode, 0);
            } while (BSUBWAY_SCR_IsTrainerNoUsed(work->trainerNo, trainerNo, i));
            work->trainerNo[i] = trainerNo;
        }
    }
}






/*
 * Unless blocked, clamps each slot's selectPos id to 1..6, copies it into memberIndex and reloads the slot's two stats.
 *
 * Addresses are Black-image addresses.
 */
u32 BSUBWAY_SCR_SetSelectedMembers(BsubwayScrWork *work, u32 unused)
{
    void *party;
    u16 i;
    u32 mon;

    if (work->selectCancel != 0 || work->selectMode == 7 || work->selectMode == 8)
        return 0;
    party = BSUBWAY_SCR_GetParty(work);
    for (i = 0; i < work->memberNum; i++) {
        if (work->selectPos[i] - 1 >= 6)
            work->selectPos[i] = 1;
        work->memberIndex[i] = work->selectPos[i] - 1;
        mon = (u32)POKEPARTY_GetMember(party, work->memberIndex[i]);
        work->memberMonsNo[i] = func_02017E1C((void *)mon, 5, 0);
        work->memberItemNo[i] = func_02017E1C((void *)mon, 6, 0);
    }
    return 1;
}






/*
 * Latches stateBits.winMaxReached once the play data count reaches 7.
 *
 * Addresses are Black-image addresses.
 */
int BSUBWAY_SCR_IsWinMax(BsubwayScrWork *work)
{
    if (work->stateBits.winMaxReached == 0) {
        if (func_0200DA54(work->playData) < 7)
            return 0;
        work->stateBits.winMaxReached = 1;
    }
    return 1;
}






/*
 * Commits winCount and the current playMode's level and redraws.
 *
 * Addresses are Black-image addresses.
 */
void BSUBWAY_SCR_SetClearScore(BsubwayScrWork *work, u32 unused)
{
    u8 playMode = work->playMode;
    u16 winCount = BSUBWAY_SCR_GetWinCount(work);

    func_0200DB08(work->scoreData, playMode, winCount);
    func_0200DAEC(work->scoreData, playMode, func_0200DAC4(work->scoreData, playMode));
    func_0200DB60(work->scoreData, playMode);
    BSUBWAY_SCR_SaveRecordParty(work, (u32)GAME_DATA_GetSaveControl(work->gameData), 1, winCount);
    func_0200DA14(work->playData);
}






int BSUBWAY_SCR_ClearStateBits(BsubwayScrWork *work, u32 unused)
{
    work->stateBits.winMaxReached = 0;
    work->stateBits.fixedBpMode = 0;
    return (int)work;
}






/*
 * Draws the current page of the trainerNo list through 0x021CBED8; playMode 2, 3, 7, 8 draw two pages with the slot tags.
 *
 * Addresses are Black-image addresses.
 */
void BSUBWAY_SCR_CreateRoundTrainers(BsubwayScrWork *work)
{
    u32 round = func_0200DA54(work->playData);
    int i;
    u32 j;
    u16 monsNo[2];
    u16 itemNo[2];

    switch (work->playMode) {
    case 4:
        func_0200DEA8((u32)work->wifiData, (u8 *)work->trainers, round, work->heapId);
        return;
    case 2:
    case 3:
    case 7:
    case 8:
        i = 0;
        j = round * 2;
        BSUBWAY_SCR_CreateTrainer(work, &work->trainers[0], work->trainerNo[j], work->memberNum, 0, 0, 0, work->heapId);
        for (; i < work->memberNum; i++) {
            monsNo[i] = work->trainers[0].mons[i].species;
            itemNo[i] = work->trainers[0].mons[i].item;
        }
        BSUBWAY_SCR_CreateTrainer(work, &work->trainers[1], work->trainerNo[j + 1], work->memberNum, (u16 *)monsNo, (u16 *)itemNo, 0, work->heapId);
        return;
    }
    BSUBWAY_SCR_CreateTrainer(work, &work->trainers[0], work->trainerNo[round], work->memberNum, 0, 0, 0, work->heapId);
}






/*
 * Tail-calls into ov010 with trainerType of trainers[i].
 *
 * Addresses are Black-image addresses.
 */
u32 BSUBWAY_SCR_GetTrainerObjCode(BsubwayScrWork *work, int i)
{
    return FLD_BTL_INST_TOOL_LookupKeyValue(work->trainers[i].trainerType);
}






/*
 * Steps an arm9 object by mode (0, 3, 4) and reports whether it advanced.
 *
 * Addresses are Black-image addresses.
 */
int BSUBWAY_SCR_UpdateStageRank(void *scoreData, int unused, int mode)
{
    u8 rank = (int)func_0200DC08(scoreData);
    u32 streak;

    switch (mode) {
    case 0:
        return rank;
    case 3:
        func_0200DBA0(scoreData, 0, 2);
        if (rank == 10)
            return 0;
        func_0200DBF0(scoreData);
        return 1;
    case 4:
        streak = func_0200DC0C(scoreData, 3);
        if (rank == 1)
            return 0;
        if (streak >= data_021DACD0[rank - 1]) {
            func_0200DBFC(scoreData);
            func_0200DC0C(scoreData, 2);
            func_0200DBA0(scoreData, 0, 2);
            return 1;
        }
        return 0;
    }
    return 0;
}






/*
 * Releases partyCopy and allocates a fresh one from gameData.
 *
 * Addresses are Black-image addresses.
 */
void BSUBWAY_SCR_LoadPartyCopy(BsubwayScrWork *work)
{
    if (work->partyCopy != 0)
        func_020307B0(work->partyCopy);
    work->partyCopy = func_0200BAF4((int)BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(work->gameData)), 4);
}






/*
 * Returns the party of gameData unless the query on playData is set, then the cached partyCopy.
 *
 * Addresses are Black-image addresses.
 */
void *BSUBWAY_SCR_GetParty(BsubwayScrWork *work)
{
    if (func_0200D884(work->playData, 10, 0) == 0)
        return GAME_DATA_GetMyParty(work->gameData);
    return work->partyCopy;
}






/*
 * Returns winCount.
 */
u16 BSUBWAY_SCR_GetWinCount(BsubwayScrWork *work)
{
    return work->winCount;
}






/*
 * Sets winCount.
 *
 * Addresses are Black-image addresses.
 */
void BSUBWAY_SCR_SetWinCount(BsubwayScrWork *work, u16 winCount)
{
    work->winCount = winCount;
}






/*
 * Saturating increment of winCount.
 * Addresses are Black-image addresses.
 */
void BSUBWAY_SCR_IncWinCount(BsubwayScrWork *work)
{
    u16 winCount = work->winCount;

    if (winCount < 0xffff)
        work->winCount = winCount + 1;
}






int BSUBWAY_SCR_ClearWinCount(BsubwayScrWork *work)
{
    work->winCount = 0;
    return (int)work;
}





void BSUBWAY_SCR_SetWinCountFromRound(BsubwayScrWork *work, u32 stage, u32 round)
{
    u32 winCount = stage * 7;

    winCount += round;
    if (winCount > 0xffff)
        winCount = 0xffff;
    work->winCount = winCount;
}






int BSUBWAY_SCR_GetMemberNum(u16 playMode)
{
    switch (playMode) {
    case 0:
    case 4:
    case 5:
        return 3;
    case 1:
    case 6:
        return 4;
    case 2:
    case 3:
    case 7:
    case 8:
        return 2;
    }
    return 0;
}






/*
 * Linear search of a halfword array.
 * Addresses are Black-image addresses.
 */
int BSUBWAY_SCR_IsTrainerNoUsed(const u16 *list, u16 value, u16 count)
{
    u16 i;

    for (i = 0; i < count; i++) {
        if (value == list[i])
            return 1;
    }
    return 0;
}






u16 BSUBWAY_SCR_GetStageNo(u16 winCount)
{
    return (u16)func_0209C0A4(winCount, 7);
}






void BSUBWAY_SCR_SaveRecordParty(BsubwayScrWork *work, u32 saveControl, int unused, u16 winCount)
{
    u8 saveByte;

    switch (work->playMode) {
    case 0:
        BSUBWAY_SCR_SaveMemberParty(work, saveControl, 0);
        break;
    case 1:
        break;
    case 4:
        BSUBWAY_SCR_SaveMemberParty(work, saveControl, 1);
        saveByte = work->playMode;
        func_0200D914(work->playData, 0, &saveByte);
        saveByte = func_0200DA54(work->playData) + 1;
        func_0200D914(work->playData, 1, &saveByte);
        func_0200DC94(work->scoreData, (const struct BsubwayRecordSrc *)(work->playData));
        break;
    }
}






/*
 * Draws the three partnerDraws entries through 0x021CBED8 and stores each result byte in partnerResult.
 *
 * Addresses are Black-image addresses.
 */
void BSUBWAY_SCR_CreatePartners(BsubwayScrWork *work, u8 isAltRom)
{
    int trainerBase = 300;
    int i;

    if (isAltRom)
        trainerBase += 3;
    for (i = 0; i < 3; i++)
        work->partnerResult[i] = BSUBWAY_SCR_CreateTrainer(work, &work->partners[i], trainerBase + i, work->memberNum,
                                               work->memberMonsNo, work->memberItemNo,
                                               &work->partnerDraws[i], work->heapId);
}






/*
 * Packs one party member into a 0x3c-byte slot: species/form, item, four moves with their PP-up bits, ids, stats and nickname.
 *
 * Addresses are Black-image addresses.
 */
void BSUBWAY_SCR_PackBattleMon(BattleMon *mon, u32 pokeParam)
{
    int i;

    mon->species = func_02017E1C((void *)pokeParam, 5, 0);
    mon->form = func_02017E1C((void *)pokeParam, 0x6f, 0);
    mon->item = func_02017E1C((void *)pokeParam, 6, 0);
    for (i = 0; i < 4; i++) {
        mon->moves[i] = func_02017E1C((void *)pokeParam, 0x36 + i, 0);
        mon->ppUps |= func_02017E1C((void *)pokeParam, 0x3e + i, 0) << (i * 2);
    }
    mon->lang = func_02017E1C((void *)pokeParam, 0xc, 0);
    mon->otId = func_02017E1C((void *)pokeParam, 7, 0);
    mon->pid = func_02017E1C((void *)pokeParam, 0, 0);
    mon->ivs = func_02017E1C((void *)pokeParam, 0xac, 0);
    for (i = 0; i < 6; i++)
        mon->ev[i] = func_02017E1C((void *)pokeParam, 0xd + i, 0);
    mon->ability = func_02017E1C((void *)pokeParam, 0xa, 0);
    mon->friendship = func_02017E1C((void *)pokeParam, 9, 0);
    func_02017E1C((void *)pokeParam, 0x74, (u32)mon->nick);
}





/*
 * Packs the three selected party members into a scratch buffer from bsubway_scr.c and hands it to the score data.
 *
 * Addresses are Black-image addresses.
 */
void BSUBWAY_SCR_SaveMemberParty(BsubwayScrWork *work, u32 unused, int slot)
{
    BattleMon *buf;
    int i;
    void *party;

    i = 0;
    buf = func_02030734((u16)(((u16)work->heapId & 0x7fff) | 0x8000), 0xb4, 0, d_021DE58C, 0x89a);
    MI_CpuFill8(buf, 0, 0xb4);
    party = BSUBWAY_SCR_GetParty(work);
    for (; i < 3; i++)
        BSUBWAY_SCR_PackBattleMon(&buf[i], (u32)POKEPARTY_GetMember(party, work->memberIndex[i]));
    func_0200DC50(work->scoreData, slot, buf);
    MI_CpuFill8(buf, 0, 0xb4);
    func_020307B0(buf);
}




int BSUBWAY_SCR_CmdCreateWork(u32 script, u32 scriptCtx)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork((void *)scriptCtx);
    u32 gameSystem, resume;

    SCRIPT_WORK_ResetFieldParam((int)scriptWork);
    gameSystem = (u32)SCRIPT_WORK_GetGameSystem(scriptWork);
    resume = func_02011330((struct ScriptStream *)script);
    BSUBWAY_SCR_CreateWork((GameSystem *)gameSystem, resume, SCRIPT_WORK_ReadWorkValue((void *)script, (void *)scriptCtx));
    return 0;
}




int BSUBWAY_SCR_CmdClearWorkPtr(u32 script, u32 scriptCtx)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork((void *)scriptCtx);

    SCRIPT_WORK_ResetFieldParam((int)scriptWork);
    BSUBWAY_SCR_ClearWorkPtr(SCRIPT_WORK_GetGameSystem(scriptWork));
    return 0;
}




int BSUBWAY_SCR_CmdDeleteWork(u32 script, u32 scriptCtx)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork((void *)scriptCtx);
    u32 gameSystem;

    SCRIPT_WORK_ResetFieldParam((int)scriptWork);
    gameSystem = (u32)SCRIPT_WORK_GetGameSystem(scriptWork);
    BSUBWAY_SCR_DeleteWork((GameSystem *)gameSystem, GAME_DATA_GetCurrentEvent(ICA_ANIME_GetField1C((const struct GameSystem *)gameSystem)));
    return 0;
}





/*
 * Script command dispatcher: reads a command id and two arguments from the
 * script, then runs one of 137 cases on the work area, the save blocks
 * 0x39/0x3A/0x3B and the result slot. Returns 1 when the case started a task
 * the script must wait for.  One 4376-byte function (0x021CA5C4..0x021CB6DC,
 * see layout/far_branch_functions.txt); every concrete byte matches.
 *
 * Shape notes (2026-10-01), all measured:
 * - The switch tree only reproduces with one more empty case label inside the
 *   0..113 jump table (any of 9, 10, 46..99, 102; its entry is the break, so
 *   the value is invisible).  BSUBWAY_SCR_CMD_NOP_A is that label (102).  Without it the top group becomes one 359..416
 *   table instead of compares for 358/359 and a 400..416 table.
 * - cmd, arg1, arg2 and resultWorkId are u16 (u16 returns): u32 makes the tree
 *   unsigned, and u32 arg1 truncates before each bitfield insert.
 * - The counter of BSUBWAY_SCR_CMD_SET_PROGRESS_RECORDS is an enum local: an int counter folds `recordNo + playRound + 1` and
 *   the loop's entry guard.
 * - BSUBWAY_SCR_CMD_GET_TRAINER_NO writes the result in each arm (cross-jumped tail leaves the
 *   `b` to the next instruction); BSUBWAY_SCR_CMD_START_COMM_CHECK_B sets startedTask after the call (it is
 *   still scheduled into the argument stores); the two SET_RETURN_LOCATION table cases read the table
 *   row through a pointer and pass its three words as separate arguments.
 *
 * Witnesses (closed 2026-10-02, gA2): EVENT_BSUBWAY_COMM_Start (ov007), BSUBWAY_COMM_NetInit
 *   and BSUBWAY_COMM_SetRecvMode (ov010) were seeded in layout/function_starts.txt and
 *   filed EXACT; data_021BB474 (ov214) and data_021BB6A4 (ov100) are
 *   hand-declared proc tables in layout/data_objects.txt, and
 *   attest_xwin_loaded() no longer counts ov021's own start at 0x021BB474
 *   as a third-overlay contest.
 */
int BSUBWAY_SCR_CmdTool(void *scriptCtx, u32 script)
{
    VecFx32 playerPos;
    ReturnLocation playerLocation;
    VecFx32 npcPos;
    ReturnLocation tableLocation;
    ReturnLocation modeLocation;
    Ov007ProcParam procParam;
    u32 recordSlot;
    u16 firstA, firstB, firstC;
    u16 secondA, secondB, secondC;
    u16 thirdA, thirdB, thirdC;
    u8 byte11;
    u8 byte10;
    int startedTask;
    void *scriptWork;
    u32 gameSystem;
    u32 gameData;
    u32 saveControl;
    u32 eventFlags;
    BsubwayScrWork *work;
    u32 playData;
    u32 playMode;
    u32 scoreData;
    u32 wifiData;
    void *fieldMap;
    u16 arg1;
    u16 arg2;
    u16 resultWorkId;
    u16 *resultDst;
    u16 cmd;

    startedTask = 0;
    scriptWork = SCRCMD_WORK_GetScriptWork((void *)script);
    SCRIPT_WORK_ResetFieldParam((int)scriptWork);
    gameSystem = (u32)SCRIPT_WORK_GetGameSystem(scriptWork);
    gameData = (u32)ICA_ANIME_GetField1C((const struct GameSystem *)gameSystem);
    saveControl = (u32)GAME_DATA_GetSaveControl((struct GameData *)gameData);
    eventFlags = GAME_DATA_GetEventWork((const struct GameData *)gameData);
    work = GAME_DATA_GetCurrentEvent((struct GameData *)gameData);
    playData = (u32)func_020071CC((struct SaveControl *)saveControl, 0x39);
    playMode = func_0200D884((struct BsubwayPlayData *)playData, 0, 0);
    scoreData = (u32)func_020071CC((struct SaveControl *)saveControl, 0x3a);
    wifiData = (u32)func_020071CC((struct SaveControl *)saveControl, 0x3b);
    fieldMap = ICA_ANIME_GetField20((void *)gameSystem);
    cmd = func_02011330(scriptCtx);
    arg1 = SCRIPT_WORK_ReadWorkValue(scriptCtx, (void *)script);
    arg2 = SCRIPT_WORK_ReadWorkValue(scriptCtx, (void *)script);
    resultWorkId = func_02011330(scriptCtx);
    resultDst = SCRIPT_WORK_GetWorkPtr(scriptWork, (void *)gameData, resultWorkId);

    if (work == NULL && cmd >= 300)
        return startedTask;

    switch (cmd) {
    case BSUBWAY_SCR_CMD_GET_TRAIN_INDEX:
        *resultDst = BSUBWAY_SCR_GetTrainNo(fieldMap);
        break;
    case BSUBWAY_SCR_CMD_RESET_SYSTEM:
        OS_ResetSystem(0);
        break;
    case BSUBWAY_SCR_CMD_CLEAR_PLAY_DATA:
        func_0200D85C((struct BsubwayPlayData *)playData);
        break;
    case BSUBWAY_SCR_CMD_GET_PLAY_DATA_STATE:
        *resultDst = func_0200D87C((struct BsubwayPlayData *)playData);
        break;
    case BSUBWAY_SCR_CMD_SET_RETURN_LOCATION_AT_PLAYER: {
        void *playerObj = FIELDMAP_GetFieldPlayer((void *)fieldMap);
        u32 dirIndex = FIELD_PLAYER_GetDirDisp(playerObj);
        int dirCode;
        FIELD_PLAYER_GetPos(playerObj, (struct VecFx32 *)&playerPos);
        switch (dirIndex) {
        case 0:
            dirCode = 1;
            break;
        case 1:
            dirCode = 2;
            break;
        case 2:
            dirCode = 3;
            break;
        case 3:
            dirCode = 4;
            break;
        default:
            dirCode = 0;
            break;
        }
        ZONEDATA_SetDirectLocation(&playerLocation, FIELDMAP_GetZoneId(fieldMap), dirCode, playerPos.x, playerPos.y, playerPos.z);
        GAME_DATA_SetField168((struct GameData *)gameData, (const struct ReturnLocation *)(&playerLocation));
        ZONEDATA_SetEventFlag((char *)eventFlags, 0x966);
        break;
    }
    case BSUBWAY_SCR_CMD_CLEAR_RETURN_LOCATION_FLAG:
        ZONEDATA_ResetEventFlag((char *)eventFlags, 0x966);
        break;
    case BSUBWAY_SCR_CMD_GET_RECORD_WIN_COUNT:
        *resultDst = func_0200DAC4((struct BsubwayScoreData *)scoreData, arg1);
        if (*resultDst > 9999)
            *resultDst = 9999;
        break;
    case BSUBWAY_SCR_CMD_BEGIN_PLAY_GET_MODE:
        *resultDst = BSUBWAY_SCR_ResetPlayMode((const struct GameSystem *)gameSystem);
        break;
    case BSUBWAY_SCR_CMD_GET_PLAYER_LOOK:
        *resultDst = FIELD_PLAYER_GetFormObjCode(FIELD_PLAYER_GetSex(FIELDMAP_GetFieldPlayer((void *)fieldMap)), 0);
        break;
    case BSUBWAY_SCR_CMD_SET_NPC_DIRECTION: {
        void *npcObj = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), arg1);
        if (npcObj != 0)
            FLDMMDL_SetStatusBitVanish(npcObj, arg2);
        break;
    }
    case BSUBWAY_SCR_CMD_GET_NEXT_ROUND_FROM_SAVE:
        *resultDst = func_0200DA54((struct BsubwayPlayData *)playData) + 1;
        break;
    case BSUBWAY_SCR_CMD_GET_NEXT_ROUND:
        *resultDst = func_0200DA54((struct BsubwayPlayData *)(work->playData));
        *resultDst += 1;
        break;
    case BSUBWAY_SCR_CMD_GET_SCORE_FLAG:
        if (data_021DAD36[arg1] == 11)
            *resultDst = 1;
        else
            *resultDst = func_0200DBA0((struct BsubwayScoreData *)scoreData, data_021DAD36[arg1], 0);
        break;
    case BSUBWAY_SCR_CMD_SET_SCORE_FLAG:
        if (data_021DAD36[arg1] != 11)
            func_0200DBA0((struct BsubwayScoreData *)scoreData, data_021DAD36[arg1], 1);
        break;
    case BSUBWAY_SCR_CMD_GET_SCORE_FLAG_CLEAR:
        *resultDst = func_0200DBA0((struct BsubwayScoreData *)scoreData, 10, 0);
        break;
    case BSUBWAY_SCR_CMD_SET_SCORE_FLAG_CLEAR:
        func_0200DBA0((struct BsubwayScoreData *)scoreData, 10, 1);
        break;
    case BSUBWAY_SCR_CMD_SET_TRAIN_SIGN_TABLE:
        FIELD_GIMMICK_BSUBWAY_StartTrain(fieldMap, data_021DAD88[arg1], (int)(&data_021DAD70[arg2]));
        break;
    case BSUBWAY_SCR_CMD_SET_TRAIN_DOOR_STATE:
        FLDEFF_BTRAIN_SetAnime((void *)FIELD_GIMMICK_BSUBWAY_GetTrainEffect((int)fieldMap), arg1);
        break;
    case BSUBWAY_SCR_CMD_SET_TRAIN_DOOR_STATE_OTHER:
        FLDEFF_BTRAIN_SetHidden((void *)FIELD_GIMMICK_BSUBWAY_GetTrainEffect((int)fieldMap), arg1);
        break;
    case BSUBWAY_SCR_CMD_GET_SAVED_PLAY_MODE:
        *resultDst = func_0200D884((struct BsubwayPlayData *)playData, 0, 0);
        break;
    case BSUBWAY_SCR_CMD_IS_MULTI_PLAY_MODE:
        *resultDst = 0;
        switch (arg1) {
        case 0:
        case 1:
        case 4:
        case 5:
        case 6:
            break;
        case 2:
        case 3:
        case 7:
        case 8:
            *resultDst = 1;
            break;
        }
        break;
    case BSUBWAY_SCR_CMD_SET_NPC_HEIGHT_AND_LOCK: {
        u32 height = arg2 << 16;
        void *npcObj = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), arg1);
        if (npcObj != 0) {
            FLDMMDL_GetPos(npcObj, &npcPos);
            npcPos.y = height;
            FLDMMDL_InitPosition(npcObj, (int *)(&npcPos), FLDMMDL_GetDirDisp(npcObj));
            FLDMMDL_SetStatusBitHeightGetOff(npcObj, 1);
        }
        break;
    }
    case BSUBWAY_SCR_CMD_UNLOCK_NPC: {
        void *npcObj = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), arg1);
        if (npcObj != 0)
            FLDMMDL_SetStatusBitHeightGetOff(npcObj, 0);
        break;
    }
    case BSUBWAY_SCR_CMD_IS_NPC_PRESENT: {
        void *npcObj = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), arg1);
        *resultDst = 0;
        if (npcObj != 0)
            *resultDst = 1;
        break;
    }
    case BSUBWAY_SCR_CMD_GET_NPC_TRAIN_STATE: {
        void *npcObj = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), arg1);
        *resultDst = 0;
        if (npcObj != 0)
            *resultDst = func_021CBBA0((u32)npcObj);
        break;
    }
    case BSUBWAY_SCR_CMD_GET_RANK:
        *resultDst = BSUBWAY_SCR_UpdateStageRank((void *)scoreData, gameSystem, 0);
        if ((s16)*resultDst <= 0)
            *resultDst = 1;
        break;
    case BSUBWAY_SCR_CMD_LOWER_RANK:
        *resultDst = BSUBWAY_SCR_UpdateStageRank((void *)scoreData, gameSystem, 3);
        break;
    case BSUBWAY_SCR_CMD_RAISE_RANK:
        *resultDst = BSUBWAY_SCR_UpdateStageRank((void *)scoreData, gameSystem, 4);
        break;
    case BSUBWAY_SCR_CMD_GET_SCORE_ROUND_VALUE:
        *resultDst = func_0200DB80((struct BsubwayScoreData *)scoreData, arg1);
        break;
    case BSUBWAY_SCR_CMD_GET_PARTNER_LOOK:
        *resultDst = FIELD_PLAYER_GetObjCodeOfFormCode(func_02008550((const struct MyStatus *)((u8 *)GAME_DATA_GetField114((struct GameData *)gameData) + 0x20)) == 0 ? 1 : 0, 0);
        break;
    case BSUBWAY_SCR_CMD_IS_BATTLE_REC_SAVED: {
        u32 recordSys = (u32)BATTLE_BOX_GetFromSave((void *)saveControl);
        *resultDst = 0;
        if (BATTLE_BOX_HasMon((void *)recordSys) == 1)
            *resultDst = 1;
        break;
    }
    case BSUBWAY_SCR_CMD_RESULT_FALSE_A:
        *resultDst = 0;
        break;
    case BSUBWAY_SCR_CMD_SET_TRAIN_SIGN_DEFAULT:
        FIELD_GIMMICK_BSUBWAY_StartTrain(fieldMap, 7, (int)data_021DAD70);
        break;
    case BSUBWAY_SCR_CMD_SET_NPC_ANIMATION: {
        void *npcObj = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), arg1);
        if (npcObj != 0)
            FLDMMDL_SetDirDispCheckPause((int)npcObj, arg2);
        break;
    }
    case BSUBWAY_SCR_CMD_RESET_NPC_ANIMATION: {
        void *npcObj = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), arg1);
        if (npcObj != 0)
            FLDMMDL_OnMoveBitMovePause(npcObj);
        break;
    }
    case BSUBWAY_SCR_CMD_START_NPC_TASK:
        SCRIPT_SYS_CallEvent(scriptWork, NAMEIN_SETUP_StartNameBalloonFromHistory(gameSystem, FLDMMDL_GetParam(FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), arg1), 0), arg1));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_GET_MODE_CLEARED:
        *resultDst = func_0200DB44((struct BsubwayScoreData *)scoreData, arg1);
        break;
    case BSUBWAY_SCR_CMD_IS_NPC_AVAILABLE: {
        u32 npcIndex = FLDMMDL_GetParam(FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), arg1), 0);
        *resultDst = 0;
        if (func_021CBBAC(work, npcIndex) == 1)
            *resultDst = 1;
        break;
    }
    case BSUBWAY_SCR_CMD_GET_NPC_INFO_FIRST:
        func_021CBBD0(work, FLDMMDL_GetParam(FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), arg1), 0), &firstA, &firstB, &firstC);
        *resultDst = firstA;
        break;
    case BSUBWAY_SCR_CMD_GET_NPC_INFO_SECOND:
        func_021CBBD0(work, FLDMMDL_GetParam(FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), arg1), 0), &secondA, &secondB, &secondC);
        *resultDst = secondB;
        break;
    case BSUBWAY_SCR_CMD_GET_NPC_INFO_THIRD:
        func_021CBBD0(work, FLDMMDL_GetParam(FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), arg1), 0), &thirdA, &thirdB, &thirdC);
        *resultDst = thirdC;
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_RECORD_COUNT: {
        void *recordList = BSUBWAY_SAVEDATA_AllocHistoryCopy((struct BsubwayWifiData *)wifiData, 4);
        *resultDst = BSUBWAY_SAVEDATA_CountHistoryEntries(recordList);
        func_020307B0(recordList);
        break;
    }
    case BSUBWAY_SCR_CMD_START_SCREEN_TASK: {
        u32 cancelFlag = 0;
        if (arg1 == 1)
            cancelFlag = 1;
        SCRIPT_SYS_CallEvent(scriptWork, func_021CB9BC((void *)gameSystem, script, (u32)resultDst, cancelFlag));
        startedTask = 1;
        break;
    }
    case BSUBWAY_SCR_CMD_SET_RETURN_LOCATION_FROM_TABLE: {
        u16 tableIndex = BSUBWAY_SCR_GetTrainNo(fieldMap);
        const VecFx32 *pos = &data_021DAE50[tableIndex];
        ZONEDATA_SetDirectLocation(&tableLocation, data_021DADAC[tableIndex], 4, pos->x, pos->y, pos->z);
        GAME_DATA_SetField168((struct GameData *)gameData, (const struct ReturnLocation *)(&tableLocation));
        ZONEDATA_SetEventFlag((char *)eventFlags, 0x966);
        break;
    }
    case BSUBWAY_SCR_CMD_SET_SCORE_FLAG_FIRST:
        if (arg1 == 0)
            func_0200DBA0((struct BsubwayScoreData *)scoreData, 1, 2);
        else
            func_0200DBA0((struct BsubwayScoreData *)scoreData, 1, 1);
        break;
    case BSUBWAY_SCR_CMD_GET_SCORE_FLAG_FIRST:
        *resultDst = func_0200DBA0((struct BsubwayScoreData *)scoreData, 1, 0);
        break;
    case BSUBWAY_SCR_CMD_START_OV007_PROC_A:
        procParam.mode = 0;
        procParam.result = resultDst;
        SCRIPT_SYS_CallEvent(scriptWork, GAME_EVENT_CreateOverlayEvent((void *)gameSystem, (u32)ov007_id, (u32 (*)(void *, u32))EVENT_BSUBWAY_COMM_Start, (u32)(&procParam)));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_START_OV007_PROC_B:
        startedTask = 1;
        procParam.mode = 1;
        procParam.result = resultDst;
        SCRIPT_SYS_CallEvent(scriptWork, GAME_EVENT_CreateOverlayEvent((void *)gameSystem, (u32)ov007_id, (u32 (*)(void *, u32))EVENT_BSUBWAY_COMM_Start, (u32)(&procParam)));
        break;
    case BSUBWAY_SCR_CMD_START_OV007_PROC_C:
        procParam.mode = 2;
        procParam.result = resultDst;
        SCRIPT_SYS_CallEvent(scriptWork, GAME_EVENT_CreateOverlayEvent((void *)gameSystem, (u32)ov007_id, (u32 (*)(void *, u32))EVENT_BSUBWAY_COMM_Start, (u32)(&procParam)));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_FIELD_101:
        *resultDst = BSUBWAY_SAVEDATA_GetTrainersTagA((struct BsubwayWifiData *)wifiData);
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_FIELD_FE:
        *resultDst = BSUBWAY_SAVEDATA_GetTrainersPresent((struct BsubwayWifiData *)wifiData);
        break;
    case BSUBWAY_SCR_CMD_SET_PLAY_DATA_BYTE_11:
        byte11 = arg1;
        func_0200D914((struct BsubwayPlayData *)playData, 11, &byte11);
        break;
    case BSUBWAY_SCR_CMD_GET_PLAY_DATA_BYTE_11:
        *resultDst = func_0200D884((struct BsubwayPlayData *)playData, 11, 0);
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_FIELD_FF:
        *resultDst = BSUBWAY_SAVEDATA_GetHistoryPresent((struct BsubwayWifiData *)wifiData);
        break;
    case BSUBWAY_SCR_CMD_START_PARTY_TASK:
        SCRIPT_SYS_CallEvent(scriptWork, NAMEIN_SETUP_StartHistoryScreenEvent((void *)gameSystem));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_FIELD_103:
        *resultDst = BSUBWAY_SAVEDATA_GetHistoryTagA((struct BsubwayWifiData *)wifiData);
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_FIELD_102:
        *resultDst = BSUBWAY_SAVEDATA_GetHistoryTagB((struct BsubwayWifiData *)wifiData);
        break;
    case BSUBWAY_SCR_CMD_RESULT_FALSE_B:
        *resultDst = 0;
        break;
    case BSUBWAY_SCR_CMD_NOP_A:
    case BSUBWAY_SCR_CMD_NOP_B:
    case BSUBWAY_SCR_CMD_NOP_C:
        break;
    case BSUBWAY_SCR_CMD_RESULT_FALSE_C:
        *resultDst = 0;
        break;
    case BSUBWAY_SCR_CMD_SET_RETURN_LOCATION_FROM_MODE:
        if (playMode < 9) {
            const VecFx32 *pos = &data_021DAE50[playMode];
            ZONEDATA_SetDirectLocation(&modeLocation, data_021DADAC[playMode], 4, pos->x, pos->y, pos->z);
            GAME_DATA_SetField168((struct GameData *)gameData, (const struct ReturnLocation *)(&modeLocation));
            ZONEDATA_SetEventFlag((char *)eventFlags, 0x966);
        }
        break;
    case BSUBWAY_SCR_CMD_START_PARTY_SELECT:
        {
            u8 useOwnParty = func_0200D884((struct BsubwayPlayData *)playData, 10, 0);
            SCRIPT_SYS_CallEvent(scriptWork, NAMEIN_SETUP_StartPartyPickEvent((struct PartySelectParam *)work, (void *)gameSystem, useOwnParty));
        }
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_SET_SELECTED_MEMBERS:
        *resultDst = BSUBWAY_SCR_SetSelectedMembers(work, gameSystem);
        break;
    case BSUBWAY_SCR_CMD_RESULT_FALSE_D:
        *resultDst = 0;
        break;
    case BSUBWAY_SCR_CMD_IS_WIN_MAX:
        if (BSUBWAY_SCR_IsWinMax(work) == 1)
            *resultDst = 1;
        else
            *resultDst = 0;
        break;
    case BSUBWAY_SCR_CMD_SET_LOSE_SCORE:
        BSUBWAY_SCR_SetLoseScore(gameSystem, work);
        break;
    case BSUBWAY_SCR_CMD_SET_CLEAR_SCORE:
        BSUBWAY_SCR_SetClearScore(work, gameSystem);
        break;
    case BSUBWAY_SCR_CMD_SAVE_REST_PLAY_DATA:
        BSUBWAY_SCR_SaveRestPlayData(work);
        break;
    case BSUBWAY_SCR_CMD_CREATE_ROUND_TRAINERS:
        BSUBWAY_SCR_CreateRoundTrainers(work);
        break;
    case BSUBWAY_SCR_CMD_GET_TRAINER_OBJ_CODE:
        *resultDst = BSUBWAY_SCR_GetTrainerObjCode(work, arg1);
        break;
    case BSUBWAY_SCR_CMD_START_ENCOUNTER_TASK:
        SCRIPT_SYS_CallEvent(scriptWork, NAMEIN_SETUP_StartEncounterScene(work, gameSystem, fieldMap));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_GET_PLAY_MODE:
        *resultDst = work->playMode;
        break;
    case BSUBWAY_SCR_CMD_SET_FIXED_BP_MODE:
        work->stateBits.fixedBpMode = arg1;
        break;
    case BSUBWAY_SCR_CMD_GET_FIXED_BP_MODE:
        *resultDst = work->stateBits.fixedBpMode;
        break;
    case BSUBWAY_SCR_CMD_GET_BATTLE_POINTS:
        *resultDst = BSUBWAY_SCR_AddBattlePoint(work);
        break;
    case BSUBWAY_SCR_CMD_SET_PARTNER_NO:
        work->stateBits.partnerNo = arg1;
        break;
    case BSUBWAY_SCR_CMD_GET_PARTNER_NO:
        *resultDst = work->stateBits.partnerNo;
        break;
    case BSUBWAY_SCR_CMD_DRAW_TRAINER_NOS:
        BSUBWAY_SCR_DrawTrainerNos(work);
        break;
    case BSUBWAY_SCR_CMD_GET_MEMBER_INDEX:
        *resultDst = work->memberIndex[arg1];
        break;
    case BSUBWAY_SCR_CMD_CLEAR_RECV_BUF:
        work->recvCount = 0;
        MI_CpuFill8(work->recvBuf, 0, 0x46);
        break;
    case BSUBWAY_SCR_CMD_START_PARTNER_TASK_A:
        SCRIPT_SYS_CallEvent(scriptWork, NAMEIN_SETUP_StartNameBalloonFromRecord(work, (void *)gameSystem, arg1, arg2, 5));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_SAVE_PLAY_DATA_MEMBERS:
        BSUBWAY_SCR_SavePlayDataMembers(work);
        break;
    case BSUBWAY_SCR_CMD_LOAD_MEMBERS:
        BSUBWAY_SCR_LoadMembers(work, gameSystem);
        break;
    case BSUBWAY_SCR_CMD_SET_PLAY_DATA_BYTE_10:
        byte10 = arg1;
        func_0200D914((struct BsubwayPlayData *)playData, 10, &byte10);
        break;
    case BSUBWAY_SCR_CMD_CHANGE_COMM_MULTI_MODE:
        BSUBWAY_SCR_ChangeCommMultiMode(work);
        break;
    case BSUBWAY_SCR_CMD_IS_UPPER_PLAY_MODE:
        if (playMode - 5 <= 3)
            *resultDst = 1;
        else
            *resultDst = 0;
        break;
    case BSUBWAY_SCR_CMD_SPAWN_FIELD_OBJECTS:
        func_021CB9E4(work, (void *)gameData, FIELDMAP_GetMmdlSys((void *)fieldMap), fieldMap);
        break;
    case BSUBWAY_SCR_CMD_SET_STATE_FLAG8:
        work->stateBits.flag8 = arg1;
        break;
    case BSUBWAY_SCR_CMD_GET_STATE_FLAG8:
        *resultDst = work->stateBits.flag8;
        break;
    case BSUBWAY_SCR_CMD_IS_BATTLE_WON: {
        BtlSetup *setup = work->btlSetup;
        if (setup == NULL)
            *resultDst = 0;
        else if (setup->outcome == 1)
            *resultDst = 1;
        else
            *resultDst = 0;
        break;
    }
    case BSUBWAY_SCR_CMD_CLEAR_STATE_BITS:
        BSUBWAY_SCR_ClearStateBits(work, gameSystem);
        break;
    case BSUBWAY_SCR_CMD_SET_PROGRESS_RECORDS: {
        BsubwayRecordNo recordNo = 0;
        u16 playRound = func_0200DA54((struct BsubwayPlayData *)playData);
        if (playRound != 0) {
            void *trainerCard = (void *)ISS_SYS_GetSwitchSys((u32 *)GAMESYSTEM_GetIssSystem((u32 *)gameSystem));
            playRound = recordNo + playRound + 1;
            for (; recordNo < playRound; recordNo++) {
                if (recordNo < 9 && recordNo != 0)
                    ISS_SWITCH_SYS_SwitchOn(trainerCard, recordNo);
            }
        }
        break;
    }
    case BSUBWAY_SCR_CMD_CREATE_PARTNERS:
        BSUBWAY_SCR_CreatePartners(work, func_02008550((const struct MyStatus *)((u8 *)GAME_DATA_GetField114((struct GameData *)gameData) + 0x20)) == 0 ? 1 : 0);
        break;
    case BSUBWAY_SCR_CMD_GET_MEMBER_MONS_NO:
        *resultDst = work->memberMonsNo[arg1];
        break;
    case BSUBWAY_SCR_CMD_SET_COMM_MODE:
        work->stateBits.commMode = arg1;
        break;
    case BSUBWAY_SCR_CMD_GET_COMM_MODE:
        *resultDst = work->stateBits.commMode;
        break;
    case BSUBWAY_SCR_CMD_CHECK_PARTY_REGULATION: {
        void *recordParty = NULL;
        u32 partySource;
        void *regulation;
        void *checkedParty;
        u32 checkResult;
        *resultDst = 0;
        partySource = func_0200D884((struct BsubwayPlayData *)playData, 10, 0);
        regulation = POKE_REGULATION_Load(BSUBWAY_SCR_GetRegulationNo(playMode), 4);
        if (partySource == 1) {
            recordParty = func_0200BAF4((u32)BATTLE_BOX_GetFromSave((void *)saveControl), 4);
            checkedParty = recordParty;
        } else {
            checkedParty = GAME_DATA_GetMyParty((void *)gameData);
        }
        checkResult = func_02019ED4(regulation, checkedParty);
        func_020307B0(regulation);
        if (recordParty != NULL)
            func_020307B0(recordParty);
        if (checkResult <= 1)
            *resultDst = 1;
        break;
    }
    case BSUBWAY_SCR_CMD_LOAD_PARTY_COPY:
        BSUBWAY_SCR_LoadPartyCopy(work);
        break;
    case BSUBWAY_SCR_CMD_GET_REGULATION_NO:
        *resultDst = BSUBWAY_SCR_GetRegulationNo(playMode);
        break;
    case BSUBWAY_SCR_CMD_GET_MEMBER_NUM:
        *resultDst = BSUBWAY_SCR_GetMemberNum(playMode);
        break;
    case BSUBWAY_SCR_CMD_CHECK_BATTLE_REC_SLOT:
        if (work->stateBits.btlRecState == 0) {
            work->stateBits.btlRecState = 1;
            if (BATTLE_REC_CheckSaved((void *)saveControl, 4, &recordSlot, 0) == 1)
                work->stateBits.btlRecState = 2;
        }
        break;
    case BSUBWAY_SCR_CMD_GET_BATTLE_REC_EXISTS:
        if (work->stateBits.btlRecState == 1)
            *resultDst = 0;
        else
            *resultDst = 1;
        break;
    case BSUBWAY_SCR_CMD_SAVE_BATTLE_REC_FROM_SETUP:
        BATTLE_REC_LoadToolOverlay();
        BATTLE_REC_TOOL_PackSetup((void *)work->btlSetup);
        BATTLE_REC_UnloadToolOverlay();
        break;
    case BSUBWAY_SCR_CMD_START_RESULT_MESSAGE:
        work->msgState = 0;
        work->msgSubState = 0;
        work->msgNumber = arg1;
        VM_SetWait(scriptCtx, (int)func_021CBC14);
        work->stateBits.btlRecState = 2;
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_FREE_BATTLE_SETUP:
        if (work->btlSetup != 0) {
            BATTLE_REC_FreeWork();
            BTL_SETUP_Delete((int)work->btlSetup);
            work->btlSetup = 0;
        }
        break;
    case BSUBWAY_SCR_CMD_START_BATTLE_REC_PROC:
        MI_CpuFill8(&work->btlRecProcParam, 0, 0x18);
        work->btlRecProcParam.gameData = (GameData *)gameData;
        work->btlRecProcParam.mode = 1;
        work->btlRecProcParam.recordNo = 0;
        work->btlRecProcParam.subwayFlag = 1;
        work->btlRecProcParam.category = data_021DAD24[playMode];
        work->btlRecProcParam.winCount = BSUBWAY_SCR_GetWinCount(work);
        if (work->btlRecProcParam.winCount > 9999)
            work->btlRecProcParam.winCount = 9999;
        SCRIPT_SYS_CallEvent(scriptWork, FIELD_STATUS_CreateSubProcCallbackEvent((char *)gameSystem, (int)fieldMap, (u32)ov214_id, (int)data_021BB474, (int)&work->btlRecProcParam, 0, 0));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_COMMIT_MODE_CLEAR:
        func_0200DA14((struct BsubwayPlayData *)playData);
        func_0200DB1C((struct BsubwayScoreData *)scoreData, playMode);
        break;
    case BSUBWAY_SCR_CMD_RELEASE_TRAIN_SIGN:
        FIELD_GIMMICK_BSUBWAY_HaltTrainSway((int)fieldMap);
        break;
    case BSUBWAY_SCR_CMD_GET_TRAINER_NO: {
        u32 playRound = func_0200DA54((struct BsubwayPlayData *)playData);
        switch (playMode) {
        case 2:
        case 3:
        case 7:
        case 8:
            *resultDst = work->trainerNo[playRound * 2 + arg1];
            break;
        case 0:
        case 1:
        case 4:
        case 5:
        case 6:
        default:
            *resultDst = work->trainerNo[playRound];
            break;
        }
        break;
    }
    case BSUBWAY_SCR_CMD_START_PARTNER_TASK_B:
        SCRIPT_SYS_CallEvent(scriptWork, NAMEIN_SETUP_StartNameBalloonFromRecord(work, (void *)gameSystem, arg1, arg2, 6));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_ADD_BATTLE_TALLY: {
        BtlSetup *setup = work->btlSetup;
        if (setup != NULL) {
            u32 tallyFirst = setup->tally[0];
            u32 tallyLast = setup->tally[9];
            int monCount;
            void *btlParty = setup->parties[0];
            int monIndex;
            int sumBefore;
            int sumAfter;
            monCount = POKEPARTY_GetCount(btlParty);
            sumBefore = 0;
            sumAfter = 0;
            for (monIndex = 0; monIndex < monCount; monIndex++) {
                void *partyMon = POKEPARTY_GetMember(btlParty, monIndex);
                int valueBefore = func_02017E1C(partyMon, 0xa0, 0);
                int valueAfter = func_02017E1C(partyMon, 0xa1, 0);
                sumBefore += valueBefore;
                sumAfter += valueAfter;
            }
            func_0200D9E8((struct BsubwayPlayData *)playData, tallyLast, tallyFirst, (u16)(sumAfter - sumBefore));
        }
        break;
    }
    case BSUBWAY_SCR_CMD_SET_STATE_FLAG12:
        work->stateBits.flag12 = arg1;
        break;
    case BSUBWAY_SCR_CMD_GET_STATE_FLAG12:
        *resultDst = work->stateBits.flag12;
        break;
    case BSUBWAY_SCR_CMD_GET_PLAY_DATA_BYTE_10:
        *resultDst = func_0200D884((struct BsubwayPlayData *)playData, 10, 0);
        break;
    case BSUBWAY_SCR_CMD_NEXT_ROUND_GET_WIN_COUNT:
        func_0200DA28((struct BsubwayPlayData *)playData);
        BSUBWAY_SCR_IncWinCount(work);
        *resultDst = BSUBWAY_SCR_GetWinCount(work);
        if (*resultDst > 9999)
            *resultDst = 9999;
        break;
    case BSUBWAY_SCR_CMD_GET_WIN_COUNT:
        *resultDst = BSUBWAY_SCR_GetWinCount(work);
        if (*resultDst > 9999)
            *resultDst = 9999;
        break;
    case BSUBWAY_SCR_CMD_COMMIT_FIRST_CLEAR:
        if (func_0200DB44((struct BsubwayScoreData *)scoreData, playMode) == 0) {
            func_0200DB30((struct BsubwayScoreData *)scoreData, playMode);
            func_0200DA14((struct BsubwayPlayData *)playData);
            BSUBWAY_SCR_ClearWinCount(work);
        }
        break;
    case BSUBWAY_SCR_CMD_START_COMM_SESSION:
        if (work->stateBits.commMode == 1)
            BSUBWAY_COMM_AddCommandTable((u32)work);
        else
            BSUBWAY_COMM_NetInit(work);
        break;
    case BSUBWAY_SCR_CMD_START_COMM_CLOSE_TASK:
        SCRIPT_SYS_CallEvent(scriptWork, func_021CB914((void *)gameSystem, (u32)work));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_START_TIMING_SYNC:
        work->timingNo = arg1;
        work->resultWorkId = resultWorkId;
        BSUBWAY_COMM_StartTimingSync(work->timingNo);
        VM_SetWait(scriptCtx, (int)func_021CB700);
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_START_COMM_CHECK_A:
        work->commResultDst = resultDst;
        work->commTask = (void *)COMM_ENTRY_MENU_Create((u32)func_02012944((void *)gameData), fieldMap, 2, 2, 4, 0, 2, 0);
        VM_SetWait(scriptCtx, (int)func_021CB754);
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_START_COMM_CHECK_B:
        work->commResultDst = resultDst;
        work->commTask = (void *)COMM_ENTRY_MENU_Create((u32)func_02012944((void *)gameData), fieldMap, 2, 2, 4, 1, 2, 0);
        startedTask = 1;
        VM_SetWait(scriptCtx, (int)func_021CB7E8);
        break;
    case BSUBWAY_SCR_CMD_SEND_COMM_COMMAND:
        BSUBWAY_COMM_SetSendData(work, arg1, arg2);
        VM_SetWait(scriptCtx, (int)func_021CB6DC);
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_START_COMM_RECEIVE:
        BSUBWAY_COMM_SetRecvMode(work, arg1);
        work->resultWorkId = resultWorkId;
        VM_SetWait(scriptCtx, (int)func_021CB86C);
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_GET_COMM_PLAYER_ID:
        *resultDst = GFL_NET_SYSTEM_GetCurrentAid();
        break;
    case BSUBWAY_SCR_CMD_START_WIFI_PROC:
        MI_CpuFill8(&work->wifiProcParam, 0, 0x24);
        work->wifiProcParam.gameData = (GameData *)gameData;
        work->wifiProcParam.result = 11;
        SCRIPT_SYS_CallEvent(scriptWork, FIELD_STATUS_CreateSubProcCallbackEvent((char *)gameSystem, (int)fieldMap, (u32)ov100_id, (int)data_021BB6A4, (int)&work->wifiProcParam, 0, 0));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_PROC_RESULT:
        switch (work->wifiProcParam.result) {
        case 11:
            *resultDst = 0;
            break;
        case 12:
            *resultDst = 1;
            break;
        case 13:
            *resultDst = 2;
            break;
        default:
            *resultDst = 1;
            break;
        }
        break;
    case BSUBWAY_SCR_CMD_SET_PARTNER_PROFILE_ID:
        MISC_SAVEDATA_InsertRecentValue(MISC_SAVEDATA_GetBlock44((void *)saveControl), work->partnerMyStatus.id);
        break;
    case BSUBWAY_SCR_CMD_GET_LOOK_FIRST:
        *resultDst = FIELD_PLAYER_GetFormObjCode(GFL_NET_SYSTEM_GetCurrentAid() == 0 ? FIELD_PLAYER_GetSex(FIELDMAP_GetFieldPlayer((void *)fieldMap)) : work->partnerMyStatus.outfitVariant, 0);
        break;
    case BSUBWAY_SCR_CMD_GET_LOOK_SECOND:
        *resultDst = FIELD_PLAYER_GetFormObjCode(GFL_NET_SYSTEM_GetCurrentAid() == 0 ? work->partnerMyStatus.outfitVariant : FIELD_PLAYER_GetSex(FIELDMAP_GetFieldPlayer((void *)fieldMap)), 0);
        break;
    case BSUBWAY_SCR_CMD_CLEAR_SYSTEM_FLAG:
        GFL_NET_ERR_RequestScreen();
        break;
    case BSUBWAY_SCR_CMD_SET_SYSTEM_MODE:
        ICA_ANIME_SetField30((struct GameSystem *)gameSystem, 1);
        break;
    case BSUBWAY_SCR_CMD_IS_SYSTEM_FLAG_SET:
        *resultDst = 0;
        if (func_0200FB24() != 0)
            *resultDst = 1;
        break;
    case BSUBWAY_SCR_CMD_IS_BATTLE_REC_PLAYABLE: {
        BtlSetup *setup;
        *resultDst = 0;
        setup = work->btlSetup;
        if (setup != NULL && BATTLE_REC_IsVersionSupported(setup->recordMode) == 1)
            *resultDst = 1;
        break;
    }
    case BSUBWAY_SCR_CMD_NOP_END:
        break;
    }
    return startedTask;
}





/*
 * Task step: resolves the field's current map object and reports whether its fade has finished.
 *
 * Addresses are Black-image addresses.
 */
int func_021CB6DC(void *task, void *script)
{
    if (BSUBWAY_COMM_SendData(GAME_DATA_GetCurrentEvent(ICA_ANIME_GetField1C(SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(script))))) == 1)
        return 1;
    return 0;
}





int func_021CB700(u32 unused, u32 script)
{
    void *gameData;
    BsubwayScrWork *work;
    void *scriptWork;
    u16 *resultDst;

    scriptWork = SCRCMD_WORK_GetScriptWork((void *)script);
    gameData = ICA_ANIME_GetField1C(SCRIPT_WORK_GetGameSystem(scriptWork));
    work = GAME_DATA_GetCurrentEvent(gameData);
    resultDst = SCRIPT_WORK_GetWorkPtr(scriptWork, gameData, work->resultWorkId);
    if (func_0200FB24() != 0) {
        *resultDst = 0;
        return 1;
    }
    if (BSUBWAY_COMM_CheckTimingSync(work->timingNo) == 1) {
        *resultDst = 1;
        return 1;
    }
    return 0;
}





int func_021CB754(u32 unused, u32 script)
{
    void *gameData, *saveControl;
    void *scriptWork;
    BsubwayScrWork *work;
    int commResult;
    u32 zero;

    scriptWork = SCRCMD_WORK_GetScriptWork((void *)script);
    SCRIPT_WORK_ResetFieldParam((int)scriptWork);
    gameData = ICA_ANIME_GetField1C(SCRIPT_WORK_GetGameSystem(scriptWork));
    saveControl = GAME_DATA_GetSaveControl(gameData);
    GAME_DATA_GetEventWork(gameData);
    work = GAME_DATA_GetCurrentEvent(gameData);
    zero = 0;
    func_0200D884(func_020071CC(saveControl, 0x39), 0, 0);
    func_020071CC(saveControl, 0x3A);
    commResult = COMM_ENTRY_MENU_Main((u8 *)work->commTask);
    if (commResult != 0) {
        COMM_ENTRY_MENU_Delete((u32 *)work->commTask);
        work->commTask = (void *)zero;
        switch (commResult) {
        case 1:
            *work->commResultDst = zero;
            return 1;
        case 2:
            *work->commResultDst = 1;
            return 1;
        case 4:
        default:
            *work->commResultDst = 2;
            return 1;
        }
    }
    return zero;
}





int func_021CB7E8(u32 unused, u32 script)
{
    void *gameData, *saveControl;
    void *scriptWork;
    BsubwayScrWork *work;
    int commResult;
    u32 zero;

    scriptWork = SCRCMD_WORK_GetScriptWork((void *)script);
    SCRIPT_WORK_ResetFieldParam((int)scriptWork);
    gameData = ICA_ANIME_GetField1C(SCRIPT_WORK_GetGameSystem(scriptWork));
    saveControl = GAME_DATA_GetSaveControl(gameData);
    GAME_DATA_GetEventWork(gameData);
    work = GAME_DATA_GetCurrentEvent(gameData);
    zero = 0;
    func_0200D884(func_020071CC(saveControl, 0x39), 0, 0);
    func_020071CC(saveControl, 0x3A);
    commResult = COMM_ENTRY_MENU_Main((u8 *)work->commTask);
    if (commResult != 0) {
        COMM_ENTRY_MENU_Delete((u32 *)work->commTask);
        work->commTask = (void *)zero;
        switch (commResult) {
        case 1:
            *work->commResultDst = zero;
            return 1;
        case 2:
        default:
            *work->commResultDst = 1;
            return 1;
        }
    }
    return zero;
}





int func_021CB86C(u32 unused, u32 script)
{
    void *gameData;
    void *scriptWork;
    BsubwayScrWork *work;
    u16 *resultDst;

    scriptWork = SCRCMD_WORK_GetScriptWork((void *)script);
    gameData = ICA_ANIME_GetField1C(SCRIPT_WORK_GetGameSystem(scriptWork));
    work = GAME_DATA_GetCurrentEvent(gameData);
    resultDst = SCRIPT_WORK_GetWorkPtr(scriptWork, gameData, work->resultWorkId);
    if (BSUBWAY_COMM_IsRecvEnd(work, resultDst) == 1)
        return 1;
    return 0;
}





/*
 * Task step: closes the message window, optionally resumes the field, then waits for the save to finish.
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 * The caller leaves the owner pointer in r0 for BSUBWAY_COMM_DeleteCommandTable, so the extern
 * keeps one (ignored) parameter.
 *
 * Addresses are Black-image addresses.
 */
int func_021CB8AC(void *task, int *state, BsubwayScrWork **work)
{
    switch (*state) {
    case 0:
        if (GFL_NET_IsParentAid() == 1)
            GFL_NET_SetLoginOption(0);
        if ((*work)->stateBits.commMode == 1)
            BSUBWAY_COMM_DeleteCommandTable(*work);
        (*state)++;
        break;
    case 1:
        if (GFL_NET_IsParentAid() == 1) {
            if (GFL_NET_GetNegotiationNum() <= 1) {
                GFL_NET_Exit(0);
                (*state)++;
            }
        } else {
            GFL_NET_Exit(0);
            (*state)++;
        }
        break;
    case 2:
        if (GFL_NET_IsSessionNull() == 1)
            return 1;
        break;
    }
    return 0;
}





/*
 * Starts the task 0x021CB8AC with a one-word work area holding the owner.
 *
 * Addresses are Black-image addresses.
 */
void *func_021CB914(void *gameSystem, u32 script)
{
    void *task = func_020122C0(gameSystem, 0, (TaskFn)func_021CB8AC, 4);
    *(u32 *)func_020124E8(task) = script;
    return task;
}





/*
 * Task step: fades out, runs the ov021 sub-screen on the arg member, stores whether it was cancelled in *result.
 *
 * Addresses are Black-image addresses.
 */
int func_021CB934(void *task, int *state, ScreenTaskWork *taskWork)
{
    SCRCMD_WORK_GetScriptWork(taskWork->script);
    switch (*state) {
    case 0:
        SCRCMD_WORK_SetWaitCount(taskWork->script, 8);
        (*state)++;
    case 1:
        if (SCRCMD_WORK_CountDownWait(taskWork->script) == 1) {
            taskWork->screen = (u32)FIELD_MSGBG_CreateYesNoMenu((u16 *)FIELDMAP_GetMsgBg(ICA_ANIME_GetField20(SCRCMD_WORK_GetGameSystem(taskWork->script))), taskWork->arg);
            (*state)++;
        }
        break;
    case 2:
        switch (FIELD_MSGBG_YesNoMenuMain((struct ScreenHandle *)taskWork->screen)) {
        case 0:
            *taskWork->result = 0;
            (*state)++;
            break;
        case 2:
            break;
        default:
            *taskWork->result = 1;
            (*state)++;
            break;
        }
        break;
    case 3:
        FIELD_MSGBG_DeleteMenuFunc((void *)taskWork->screen);
        return 1;
    }
    return 0;
}





void *func_021CB9BC(void *gameSystem, u32 script, u32 resultDst, u32 arg)
{
    void *task = func_020122C0(gameSystem, 0, (TaskFn)func_021CB934, 0x10);
    u32 *taskWork = func_020124E8(task);

    taskWork[0] = script;
    taskWork[1] = resultDst;
    taskWork[3] = arg;
    return task;
}





/*
 * Spawns the marker objects for playMode: in mode 4 up to five from the
 * 0x3B record list (newest first), otherwise every 0x021DAEBC entry whose
 * threshold equals the step count. The u16 accessor result held in a u32
 * local is what puts it in the top spill slot (a u16 or int local takes the
 * lowest). Unlabelled follower: 0x021CBBA0 (already filed).
 *
 * Addresses are Black-image addresses.
 */
void func_021CB9E4(BsubwayScrWork *work, void *gameData, void *fieldMmdlSys, void *fieldMap)
{
    int i;
    u16 objId;
    u32 zoneId;
    u8 playMode;
    const SpawnPos *spawnPos;
    u8 *recordList;
    u32 recordCount;
    u8 *recordEntry;
    u16 objCode;
    void *mapObj;
    u16 threshold;
    const SpawnEntry *spawnEntry;

    i = 0;
    zoneId = FIELDMAP_GetZoneId(fieldMap);
    objId = 0x80;
    playMode = work->playMode;
    if (playMode == 4) {
        spawnPos = d_021DADD0;
        recordList = (u8 *)BSUBWAY_SAVEDATA_AllocHistoryCopy(func_020071CC(GAME_DATA_GetSaveControl(gameData), 0x3B), (int)4);
        recordCount = BSUBWAY_SAVEDATA_CountHistoryEntries((struct BsubwayWifiRecordList *)recordList);
        if (recordCount != 0) {
            recordEntry = recordList + (recordCount - 1) * 0x22;
            while (recordCount != 0 && i < 5) {
                u32 lookIndex = BSUBWAY_SAVEDATA_GetHistoryEntryScore((struct WifiRecordEntry *)recordEntry) % 10;
                if (((WifiRecordFlags *)(recordEntry + 0x20))->lookSet == 0)
                    objCode = d_021DAD48[lookIndex];
                else
                    objCode = d_021DAD5C[lookIndex];
                mapObj = FLDMMDL_AddMmdlParam(fieldMmdlSys, spawnPos->x, spawnPos->y, i % 4, objId, objCode, 2, zoneId);
                FLDMMDL_SetParam((int)mapObj, (u16)(recordCount - 1), 0);
                FLDMMDL_SetEventId(mapObj, 5);
                recordEntry -= 0x22;
                i++;
                objId++;
                spawnPos++;
                recordCount--;
            }
        }
        func_020307B0(recordList);
        return;
    }
    spawnEntry = d_021DAEBC;
    threshold = func_0200DB80(work->scoreData, playMode);
    switch (playMode) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        break;
    case 5:
    case 6:
    case 7:
    case 8:
        threshold += 3;
        break;
    }
    while (spawnEntry->objCode != 0xFFFF) {
        if (threshold == d_021DADF8[spawnEntry->thresholdNo - 1]) {
            mapObj = FLDMMDL_AddMmdlParam(fieldMmdlSys, spawnEntry->x, spawnEntry->y, i % 4, objId, spawnEntry->objCode, 2, zoneId);
            FLDMMDL_SetParam((int)mapObj, (u16)i, 0);
            FLDMMDL_SetParam((int)mapObj, (u16)spawnEntry->param, 1);
            FLDMMDL_SetEventId(mapObj, 5);
            if (objId < 0xFF)
                objId++;
        }
        spawnEntry++;
        i++;
    }
}





/*
 * Tail call into ov010 with a fixed second argument of 1 (unlabelled start).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CBBA0(u32 mapObj)
{
    return FLDMMDL_GetParam((char *)mapObj, 1);
}





/*
 * Whether entry idx of the 16-byte table at 0x021DAEBC is available (never for kind 4; unlabelled start).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CBBAC(BsubwayScrWork *work, u32 idx)
{
    const NpcInfoEntry *entry = &data_021DAEBC[idx];

    if (work->playMode == 4)
        return 0;
    if (entry->infoThird != 0)
        return 1;
    return 0;
}





/*
 * Reads the three halfwords of table entry idx, or the empty triple (0, 0, 4) (unlabelled start).
 *
 * Addresses are Black-image addresses.
 */
void func_021CBBD0(BsubwayScrWork *work, u32 idx, u16 *infoFirst, u16 *infoSecond, u16 *infoThird)
{
    const NpcInfoEntry *entry = &data_021DAEBC[idx];

    if (work->playMode == 4) {
        *infoFirst = 0;
        *infoSecond = 0;
        *infoThird = 4;
        return;
    }
    if (entry->infoThird == 0) {
        *infoFirst = 0;
        *infoSecond = 0;
        *infoThird = 4;
        return;
    }
    *infoFirst = entry->infoFirst;
    *infoSecond = entry->infoSecond;
    *infoThird = entry->infoThird;
}





/*
 * Shows the playMode's message (20/21/22) with msgNumber capped at 9999 and reports whether it ended with 2 or 3.
 *
 * Addresses are Black-image addresses.
 */
int func_021CBC14(u32 unused, u32 script)
{
    void *gameData;
    BsubwayScrWork *work;
    int messageId;
    int number;
    int messageResult;

    gameData = ICA_ANIME_GetField1C(SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork((void *)script)));
    work = GAME_DATA_GetCurrentEvent(gameData);
    messageId = 20;
    number = work->msgNumber;
    switch (work->playMode) {
    case 0:
    case 4:
    case 5:
        break;
    case 1:
    case 6:
        messageId = 21;
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        messageId = 22;
        break;
    }
    if (number > 9999)
        number = 9999;
    messageResult = BATTLE_REC_BeginSave(gameData, 4, messageId, number, 0, &work->msgState, &work->msgSubState);
    if (messageResult == 2 || messageResult == 3)
        return 1;
    return 0;
}





/*
 * Maps a kind 0..8 to the message id 20, 21 or 22.
 * Addresses are Black-image addresses.
 */
int BSUBWAY_SCR_GetRegulationNo(u32 playMode)
{
    int id = 20;

    switch (playMode) {
    case 0:
    case 4:
    case 5:
        break;
    case 1:
    case 6:
        id = 21;
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        id = 22;
        break;
    }
    return id;
}





/*
 * Maps the owner's mode 0x43..0x49 to a small index.
 *
 * Addresses are Black-image addresses.
 */
int BSUBWAY_SCR_GetTrainNo(void *fieldMap)
{
    u16 zoneId = FIELDMAP_GetZoneId(fieldMap);
    int trainIndex = 0;

    switch (zoneId) {
    case 0x43:
        trainIndex = 0;
        break;
    case 0x44:
        trainIndex = 5;
        break;
    case 0x45:
        trainIndex = 1;
        break;
    case 0x46:
        trainIndex = 6;
        break;
    case 0x47:
        trainIndex = 2;
        break;
    case 0x48:
        trainIndex = 7;
        break;
    case 0x49:
        trainIndex = 4;
        break;
    }
    return trainIndex;
}





/*
 * Builds a party list from the selected slots and runs the ov010 summary on it.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CBD08(BsubwayScrWork *work, int gameSystem)
{
    void *partyList = POKEPARTY_Create(0x8004);
    void *party = BSUBWAY_SCR_GetParty(work);
    int i;
    u32 result;

    POKEPARTY_InitEx(partyList, work->memberNum);
    for (i = 0; i < work->memberNum; i++)
        POKEPARTY_Add(partyList, POKEPARTY_GetMember(party, work->memberIndex[i]));
    result = (u32)FLD_BTL_INST_TOOL_CreateBtlSetup((void *)gameSystem, partyList, work->playMode, work->trainers, &work->partners[work->stateBits.partnerNo], work->memberNum);
    func_020307B0(partyList);
    return result;
}




/*
 * Unlabelled leaf in ov021 (printed as a `.word` run at 0x021CBD84); the
 * matching byte at 0x021CBD8C is the pool word 0x0000074C.  Six-byte
 * accessor reached from ov010's NAMEIN_SETUP_StartEncounterTransition across the overlay pair.
 */
void *func_021CBD84(void *work)
{
    return (char *)work + 0x74c;
}





static inline u16 RandInRange(BsubwayScrWork *work, u32 tbl, u32 round)
{
    u16 span = ((const TrainerNoRange *)(tbl + round * 4))->maxNo - ((const TrainerNoRange *)(tbl + round * 4))->minNo + 1;
    return func_021CBF98(work) % span + ((const TrainerNoRange *)(tbl + round * 4))->minNo;
}





/*
 * Picks a battle-subway trainer id: the fixed boss ids on the boss round, otherwise a random id from the per-round range table of the line (normal or super, early or late stages).
 *
 * Each table arm calls the random-range helper with the table address cast to
 * an integer. A shared `const TrainerNoRange *tbl` local is a named variable and takes
 * the first callee-saved register (r4) ahead of the scaled index and the span;
 * per-arm calls leave the base as a short-lived load that colours after them
 * (r6, with round*4 in r4 and span in r5), and the arms' identical tails are
 * cross-jumped into one block. The integer base keeps `tbl + off` then `+2`
 * for hi instead of folding the field offset into a second pool word
 * (d_X + 2), and loads the base before the index shift. 0x0209C0A4 is
 * _s32_div_f, so the u16 % u16 modulo is signed (int promotion).
 *
 * Addresses are Black-image addresses.
 */
u16 BSUBWAY_SCR_DrawTrainerNo(BsubwayScrWork *work, u32 round, u32 stage, u32 line, u8 alt)
{
    int super;
    int boss;
    u16 id;

    id = 0;
    super = 0;
    boss = -1;

    switch (line) {
    case 5:
    case 6:
    case 7:
    case 8:
        super = 1;
        break;
    }

    if (stage == 6) {
        if (!super) {
            if (round == 2)
                boss = 0;
        } else {
            if (round == 6)
                boss = 1;
        }
    }

    if (boss != -1) {
        switch (line) {
        case 0:
        case 5:
            if (boss == 0)
                id = 0x132;
            else if (boss == 1)
                id = 0x133;
            break;
        case 1:
        case 6:
            if (boss == 0)
                id = 0x134;
            else if (boss == 1)
                id = 0x135;
            break;
        case 2:
        case 3:
        case 7:
        case 8:
            if (boss == 0) {
                if (alt == 0)
                    id = 0x137;
                else
                    id = 0x136;
            } else if (boss == 1) {
                if (alt == 0)
                    id = 0x139;
                else
                    id = 0x138;
            }
            break;
        }
    } else if (!super) {
        if (round >= 3)
            goto done;
        if (stage < 6) {
            id = RandInRange(work, (u32)d_021DB3D8, round);
            goto done;
        }
        if (round >= 2)
            goto done;
        id = RandInRange(work, (u32)d_021DB3D0, round);
    } else {
        if (round >= 4)
            goto randomId;
        if (stage < 6) {
            id = RandInRange(work, (u32)d_021DB3E4, round);
            goto done;
        }
        id = RandInRange(work, (u32)d_021DB3F4, round);
        goto done;
randomId:
        id = func_021CBF98(work) % 100 + 200;
    }
done:
    return id;
}





/*
 * Forwarder into ov010 that drops the first argument and returns its byte result.
 *
 * Addresses are Black-image addresses.
 */
u8 BSUBWAY_SCR_CreateTrainer(BsubwayScrWork *work, BtlInstTrainer *trainer, u16 trainerNo, u8 memberNum, u16 *monsNo, u16 *itemNo, BtlInstDraw *draw, u16 heapId)
{
    return FLD_BTL_INST_TOOL_CreateTrainer(trainer, trainerNo, memberNum, monsNo, itemNo, draw, heapId);
}





/*
 * Maps a value to a bracket 3..31 in steps of 20.
 * Addresses are Black-image addresses.
 */
u8 BSUBWAY_SCR_GetMonIv(u32 trainerNo)
{
    if (trainerNo < 100)
        return 3;
    if (trainerNo < 120)
        return 6;
    if (trainerNo < 140)
        return 9;
    if (trainerNo < 160)
        return 12;
    if (trainerNo < 180)
        return 15;
    if (trainerNo < 200)
        return 18;
    if (trainerNo < 220)
        return 21;
    return 31;
}





/*
 * Builds the two battle-subway opponent mons in mons[] of the trainer record.
 *
 * Addresses are Black-image addresses.
 */
void BSUBWAY_SCR_CreatePartnerMons(BsubwayScrWork *work, BtlInstTrainer *trainer, u16 trainerNo, int useItem, BtlInstDraw *draw, u16 heapId)
{
    u8 iv;
    void *trainerData;
    int i;

    trainerData = FLD_BTL_INST_TOOL_InitTrainerHeader(trainer, trainerNo, heapId);
    iv = BSUBWAY_SCR_GetMonIv(trainerNo);
    for (i = 0; i < 2; i++)
        FLD_BTL_INST_TOOL_BuildBattleMon(&trainer->mons[i], draw->ids[i], draw->otId, draw->pids[i], iv, i, useItem, heapId);
    func_020307B0(trainerData);
}





/*
 * A 16-bit random value: the arm9 random source scaled down by 0xFFFF.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021CBF98(void *unused)
{
    return func_020056EC(0xffffffff) / 0xffff;
}
