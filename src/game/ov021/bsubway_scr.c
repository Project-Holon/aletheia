/*
 * file:     bsubway_scr.c
 * unit:     yes
 * function: BSUBWAY_SCR_ClearWorkPtr, BSUBWAY_SCR_CreateWork, BSUBWAY_SCR_DeleteWork, BSUBWAY_SCR_ChangeCommMultiMode, BSUBWAY_SCR_SaveRestPlayData, BSUBWAY_SCR_LoadMembers, BSUBWAY_SCR_SavePlayDataMembers, BSUBWAY_SCR_ResetPlayMode, BSUBWAY_SCR_SetLoseScore, BSUBWAY_SCR_AddBattlePoint, BSUBWAY_SCR_DrawTrainerNos, BSUBWAY_SCR_SetSelectedMembers, BSUBWAY_SCR_IsWinMax, BSUBWAY_SCR_SetClearScore, BSUBWAY_SCR_ClearStateBits, BSUBWAY_SCR_CreateRoundTrainers, BSUBWAY_SCR_GetTrainerObjCode, BSUBWAY_SCR_UpdateStageRank, BSUBWAY_SCR_LoadPartyCopy, BSUBWAY_SCR_GetParty, BSUBWAY_SCR_GetWinCount, BSUBWAY_SCR_SetWinCount, BSUBWAY_SCR_IncWinCount, BSUBWAY_SCR_ClearWinCount, BSUBWAY_SCR_SetWinCountFromRound, BSUBWAY_SCR_GetMemberNum, BSUBWAY_SCR_IsTrainerNoUsed, BSUBWAY_SCR_GetStageNo, BSUBWAY_SCR_SaveRecordParty, BSUBWAY_SCR_CreatePartners, BSUBWAY_SCR_PackBattleMon, BSUBWAY_SCR_SaveMemberParty, BSUBWAY_SCR_CmdCreateWork, BSUBWAY_SCR_CmdClearWorkPtr, BSUBWAY_SCR_CmdDeleteWork, BSUBWAY_SCR_CmdTool, BSUBWAY_SCR_WaitCommSend, BSUBWAY_SCR_WaitTimingSync, BSUBWAY_SCR_WaitCommEntryMenu, BSUBWAY_SCR_WaitCommEntryMenuSimple, BSUBWAY_SCR_WaitCommRecvEnd, BSUBWAY_SCR_CommShutdownMain, BSUBWAY_SCR_CreateCommShutdownTask, BSUBWAY_SCR_YesNoMenuMain, BSUBWAY_SCR_CreateYesNoMenuTask, BSUBWAY_SCR_CreateMarkerObjects, BSUBWAY_SCR_GetMmdlParam, BSUBWAY_SCR_IsNpcEntryAvailable, BSUBWAY_SCR_GetNpcEntryInfo, BSUBWAY_SCR_WaitBeginSave, BSUBWAY_SCR_GetRegulationNo, BSUBWAY_SCR_GetTrainNo, BSUBWAY_SCR_CreateBtlSetup, BSUBWAY_SCR_GetNameinEncounterWork, BSUBWAY_SCR_DrawTrainerNo, BSUBWAY_SCR_CreateTrainer, BSUBWAY_SCR_GetMonIv, BSUBWAY_SCR_CreatePartnerMons, BSUBWAY_SCR_Random
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
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   VM_ReadU16  0x02011330  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   GAME_DATA_SetCurrentEvent  0x02012EE4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   d_021DE58C     0x021DE58C  data  ov021
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   BSUBWAY_PLAYDATA_SetFlag01  0x0200D868  thumb
 *   BSUBWAY_PLAYDATA_Init  0x0200D85C  thumb
 *   BSUBWAY_PLAYDATA_ClearRound  0x0200DA14  thumb
 *   BSUBWAY_SCOREDATA_HasCleared  0x0200DB44  thumb
 *   BSUBWAY_SCOREDATA_GetWinCount  0x0200DAC4  thumb
 *   BSUBWAY_PLAYDATA_SetField  0x0200D914  thumb
 *   BSUBWAY_PLAYDATA_GetField  0x0200D884  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   BSUBWAY_PLAYDATA_GetRound  0x0200DA54  thumb
 *   BSUBWAY_SCOREDATA_GetRepeatClearCount  0x0200DB80  thumb
 *   BTL_SETUP_Delete  0x020130B4  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   BSUBWAY_SCOREDATA_ResetClearCount  0x0200DB1C  thumb
 *   BSUBWAY_SCOREDATA_SetWinCount  0x0200DB08  thumb
 *   BSUBWAY_SCOREDATA_UpdateMaxWinCount  0x0200DAEC  thumb
 *   BSUBWAY_SCOREDATA_GetLevel  0x0200DC08  thumb
 *   BSUBWAY_SCOREDATA_AddBattlePoints  0x0200DA80  thumb
 *   d_021DACDC     0x021DACDC  data  a1
 *   BSUBWAY_SCOREDATA_IncClearCount  0x0200DB60  thumb
 *   BSUBWAY_SAVEDATA_ExportTrainer  0x0200DEA8  thumb
 *   FLD_BTL_INST_TOOL_LookupKeyValue  0x02168AEC  thumb  ov010
 *   BSUBWAY_SCOREDATA_AccessFlag  0x0200DBA0  thumb
 *   BSUBWAY_SCOREDATA_IncLevel  0x0200DBF0  thumb
 *   BSUBWAY_SCOREDATA_UpdateStreak  0x0200DC0C  thumb
 *   BSUBWAY_SCOREDATA_DecLevel  0x0200DBFC  thumb
 *   data_021DACD0  0x021DACD0  data
 *   BATTLE_BOX_GetFromSave  0x0200BAC8  thumb
 *   BATTLE_BOX_CreateParty  0x0200BAF4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   BSUBWAY_SCOREDATA_CalcRecordScore  0x0200DC94  thumb
 *   BSUBWAY_SCOREDATA_SetRecordBlob  0x0200DC50  thumb
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
 *   BATTLE_REC_VerifyAndCloseSave  0x0200B5CC  thumb
 *   BATTLE_REC_IsVersionSupported  0x0200BA38  thumb
 *   BATTLE_REC_LoadToolOverlay  0x0200BA58  thumb
 *   BATTLE_REC_UnloadToolOverlay  0x0200BA68  thumb
 *   BATTLE_BOX_HasMon  0x0200BBA8  thumb
 *   BSUBWAY_PLAYDATA_GetFlag01  0x0200D87C  thumb
 *   BSUBWAY_PLAYDATA_AddCounters  0x0200D9E8  thumb
 *   BSUBWAY_PLAYDATA_IncRound  0x0200DA28  thumb
 *   BSUBWAY_SCOREDATA_SetFirstClear  0x0200DB30  thumb
 *   BSUBWAY_SAVEDATA_GetTrainersPresent  0x0200DE5C  thumb
 *   BSUBWAY_SAVEDATA_GetHistoryPresent  0x0200DE64  thumb
 *   BSUBWAY_SAVEDATA_GetTrainersTagA  0x0200DE94  thumb
 *   BSUBWAY_SAVEDATA_GetHistoryTagA  0x0200DF40  thumb
 *   BSUBWAY_SAVEDATA_GetHistoryTagB  0x0200DF4C  thumb
 *   BSUBWAY_SAVEDATA_AllocHistoryCopy  0x0200DF58  thumb
 *   BSUBWAY_SAVEDATA_CountHistoryEntries  0x0200DF94  thumb
 *   MET_TRAINERS_GetFromSave  0x0200ED48  thumb
 *   MET_TRAINERS_Insert  0x0200ED54  thumb
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   GFL_NET_ERR_RequestScreen  0x0200FB38  thumb
 *   VM_SetWait  0x020113D0  thumb
 *   GAMESYSTEM_SetFieldMapState  0x02012124  thumb
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   GAME_DATA_SetSpecialLocation  0x0201289C  thumb
 *   ov007_id       0x00000007  data  a1
 *   ov100_id       0x00000064  data  a1
 *   ov214_id       0x000000D6  data  a1
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_SetDirectLocation  0x02014184  thumb
 *   ZONEDATA_SetEventFlag  0x02014314  thumb
 *   ZONEDATA_ResetEventFlag  0x0201433C  thumb
 *   FIELD_STATUS_CreateSubProcCallbackEvent  0x02014808  thumb
 *   POKE_REGULATION_CheckPartyUsable  0x02019ED4  thumb
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
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   _u32_div_f                   0x0209C2B0  arm
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
struct ScrcmdWork;


extern struct GameSystem *SCRCMD_WORK_GetGameSystem(struct ScrcmdWork *work);
extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *p);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *p);
struct ScriptWork;
extern struct ScriptWork *SCRCMD_WORK_GetScriptWork(struct ScrcmdWork *work);
struct ScriptVm;
extern u16 VM_ReadU16(struct ScriptVm *vm);
extern u16 SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern struct Task *GAME_EVENT_Create(void *owner, void *a, void *b, u32 size);
struct GameEvent;
extern void *GAME_EVENT_GetWork(struct GameEvent *event);
struct FieldPlayer;
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *p);
struct Mmdl;
extern u16 FLDMMDL_GetDirDisp(struct Mmdl *mmdl);
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern void FLDMMDL_SetDirDispCheckPause(struct Mmdl *mmdl, s32 dir);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 GFL_HEAP_Free(void *p);
struct MmdlVec;
extern void FLDMMDL_GetPos(struct Mmdl *mmdl, struct MmdlVec *out);
extern struct GameData *GAME_DATA_SetCurrentEvent(struct GameData *gd, void *event);
extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gd);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *p);
extern u8 MYSTATUS_GetSex(const struct MyStatus *obj);
extern void *SAVE_CONTROL_GetBlock(struct SaveControl *ctrl, u32 id);
extern void BSUBWAY_PLAYDATA_SetFlag01(struct BsubwayPlayData *p, u32 v);
extern void BSUBWAY_PLAYDATA_Init(struct BsubwayPlayData *p);
extern void BSUBWAY_PLAYDATA_ClearRound(struct BsubwayPlayData *p);
extern u32 BSUBWAY_SCOREDATA_HasCleared(struct BsubwayScoreData *p, u32 i);
extern u16 BSUBWAY_SCOREDATA_GetWinCount(struct BsubwayScoreData *p, u32 i);
extern void BSUBWAY_PLAYDATA_SetField(struct BsubwayPlayData *p, u32 id, const void *src);
extern u32 BSUBWAY_PLAYDATA_GetField(struct BsubwayPlayData *p, u32 id, void *out);
struct PlayerWork;
extern struct PlayerWork *GAME_DATA_GetMyPlayerWork(struct GameData *gameData);
extern u16 BSUBWAY_PLAYDATA_GetRound(struct BsubwayPlayData *p);
extern u16 BSUBWAY_SCOREDATA_GetRepeatClearCount(struct BsubwayScoreData *p, u32 i);
struct BattleSetupParam;
extern void BTL_SETUP_Delete(struct BattleSetupParam *param);
extern void MI_CpuFill8(void *p, int v, int n);
struct PokemonParam;
extern struct PokemonParam *POKEPARTY_GetMember(struct Party *party, u32 pos);
extern u32 POKE_TOOL_GetPartyValue(struct PokemonParam *pp, u32 paramId, u32 arg);
extern void BSUBWAY_SCOREDATA_ResetClearCount(struct BsubwayScoreData *p, u32 i);
extern void BSUBWAY_SCOREDATA_SetWinCount(struct BsubwayScoreData *p, u32 i, u16 v);
extern void BSUBWAY_SCOREDATA_UpdateMaxWinCount(struct BsubwayScoreData *p, u32 i, u16 v);
extern u8 BSUBWAY_SCOREDATA_GetLevel(struct BsubwayScoreData *p);
extern void BSUBWAY_SCOREDATA_AddBattlePoints(struct BsubwayScoreData *p, s32 v);
extern void BSUBWAY_SCOREDATA_IncClearCount(struct BsubwayScoreData *p, u32 i);
extern void BSUBWAY_SAVEDATA_ExportTrainer(u32 h, u8 *list, u8 n, u16 id);
extern u16 FLD_BTL_INST_TOOL_LookupKeyValue(u16 key);
extern u32 BSUBWAY_SCOREDATA_AccessFlag(struct BsubwayScoreData *p, s32 i, u32 op);
extern void BSUBWAY_SCOREDATA_IncLevel(struct BsubwayScoreData *p);
extern u8 BSUBWAY_SCOREDATA_UpdateStreak(struct BsubwayScoreData *p, u32 kind);
extern void BSUBWAY_SCOREDATA_DecLevel(struct BsubwayScoreData *p);
struct BattleBoxSave;
extern struct BattleBoxSave *BATTLE_BOX_GetFromSave(struct SaveControl *save);
struct BoxMonGroup;
extern struct Party *BATTLE_BOX_CreateParty(struct BoxMonGroup *box, s32 heap);
extern void *GAME_DATA_GetMyParty(const struct GameData *p);
struct GdsScoreSrc;
extern void BSUBWAY_SCOREDATA_CalcRecordScore(struct BsubwayScoreData *p, struct GdsScoreSrc *q);
extern void BSUBWAY_SCOREDATA_SetRecordBlob(struct BsubwayScoreData *p, u32 which, const void *src);
struct ScriptFieldParam;
extern struct ScriptFieldParam *SCRIPT_WORK_ResetFieldParam(struct ScriptWork *work);
extern void *SCRIPT_WORK_GetGameSystem(struct ScriptWork *work);
extern void *GAME_DATA_GetCurrentEvent(struct GameData *p);
extern void *GAME_DATA_GetEventWork(const struct GameData *p);
extern u16 *SCRIPT_WORK_GetWorkPtr(struct ScriptWork *work, void *gameData, u32 id);
extern void SCRIPT_SYS_CallEvent(void *h, void *task);
extern void OS_ResetSystem(u32 a);
extern u32 BSUBWAY_PLAYDATA_GetFlag01(struct BsubwayPlayData *p);
extern u16 FIELD_PLAYER_GetDirDisp(struct FieldPlayer *player);
extern u16 FIELDMAP_GetZoneId(struct FieldMap *fieldMap);
extern void ZONEDATA_SetDirectLocation(ReturnLocation *out, u32 id, s16 n, u32 a, u32 b, u32 c);
struct Location;
extern void GAME_DATA_SetSpecialLocation(struct GameData *gameData, struct Location *location);
struct EventWork;
extern void ZONEDATA_SetEventFlag(struct EventWork *ev, s32 flagId);
extern void ZONEDATA_ResetEventFlag(struct EventWork *ev, s32 flagId);
extern u32 FIELD_PLAYER_GetSex(struct FieldPlayer *player);
extern u16 FIELD_PLAYER_GetFormObjCode(int i, int j);
struct MmdlSys;
extern struct MmdlSys *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);
extern struct Mmdl *FLDMMDL_SysSearchObjId(struct MmdlSys *sys, u32 objId);
extern void FLDMMDL_SetStatusBitVanish(struct Mmdl *mmdl, s32 flag);
extern void FIELD_GIMMICK_BSUBWAY_StartTrain(void *a, int b, int c);
struct FieldEffectObj;
extern struct FieldEffectObj *FIELD_GIMMICK_BSUBWAY_GetTrainEffect(struct FieldMap *fieldMap);
extern void FLDEFF_BTRAIN_SetAnime(struct FieldEffectObj *effect, u32 animeIndex);
extern void FLDEFF_BTRAIN_SetHidden(struct FieldEffectObj *effect, u32 hidden);
extern void FLDMMDL_InitPosition(struct Mmdl *mmdl, struct MmdlVec *pos, s32 dir);
extern void FLDMMDL_SetStatusBitHeightGetOff(struct Mmdl *mmdl, s32 flag);
extern int FIELD_PLAYER_GetObjCodeOfFormCode(int i, int v);
extern u32 BATTLE_BOX_HasMon(struct BoxMonGroup *box);
extern void FLDMMDL_OnMoveBitMovePause(struct Mmdl *mmdl);
extern int FLDMMDL_GetParam(struct Mmdl *mmdl, s32 no);
extern void *NAMEIN_SETUP_StartNameBalloonFromHistory(u32 x, u32 v, u32 id);
struct BsubwaySave;
struct HistoryBuf;
extern struct HistoryBuf *BSUBWAY_SAVEDATA_AllocHistoryCopy(struct BsubwaySave *save, u32 heapId);
extern u32 BSUBWAY_SAVEDATA_CountHistoryEntries(struct HistoryBuf *history);
extern struct GameEvent *GAME_EVENT_CreateOverlayEvent(struct GameSystem *gameSystem, u32 overlayId, u32 (*fn)(void *, u32), void *arg);
struct BsubwayProcArgs;
extern int EVENT_BSUBWAY_COMM_Start(s32 gameSystem, struct BsubwayProcArgs *args);
extern u8 BSUBWAY_SAVEDATA_GetTrainersTagA(struct BsubwaySave *save);
extern u8 BSUBWAY_SAVEDATA_GetTrainersPresent(struct BsubwaySave *save);
extern u8 BSUBWAY_SAVEDATA_GetHistoryPresent(struct BsubwaySave *save);
extern struct GameEvent *NAMEIN_SETUP_StartHistoryScreenEvent(struct GameSystem *gameSystem);
extern int BSUBWAY_SAVEDATA_GetHistoryTagA(struct BsubwaySave *save);
extern u8 BSUBWAY_SAVEDATA_GetHistoryTagB(struct BsubwaySave *save);
struct EncounterContext;
extern struct GameEvent *NAMEIN_SETUP_StartPartyPickEvent(struct EncounterContext *ctx, struct GameSystem *gameSystem, u8 useOwnParty);
extern void *NAMEIN_SETUP_StartEncounterScene(BsubwayScrWork *work, u32 gameSystem, void *fieldMap);
struct NameBalloonRecord;
extern struct GameEvent *NAMEIN_SETUP_StartNameBalloonFromRecord(struct NameBalloonRecord *records, struct GameSystem *gameSystem, u32 recordIndex, u16 npcId, u8 dir);
extern void *GAMESYSTEM_GetIssSystem(struct GameSystem *gameSystem);
extern u32 ISS_SYS_GetSwitchSys(u32 *p);
extern void ISS_SWITCH_SYS_SwitchOn(u8 *p, u32 a);
extern void *POKE_REGULATION_Load(int a, int b);
struct Regulation;
extern int POKE_REGULATION_CheckPartyUsable(struct Regulation *reg, struct Party *party);
extern u32 BATTLE_REC_VerifyAndCloseSave(struct SaveControl *save, u32 heap, u32 *result, u32 id);
extern void BATTLE_REC_LoadToolOverlay(void);
extern void BATTLE_REC_TOOL_PackSetup(struct BattleSetupParam *setup);
extern void BATTLE_REC_UnloadToolOverlay(void);
extern void VM_SetWait(char *p, int val);
extern void BATTLE_REC_FreeWork(void);
extern void *FIELD_STATUS_CreateSubProcCallbackEvent(char *gameSystem, int fieldMap, int overlayId, int procData, int procWork, int callback, int callbackWork);
extern void FIELD_GIMMICK_BSUBWAY_HaltTrainSway(struct FieldMap *fieldMap);
extern u32 POKEPARTY_GetCount(struct Party *party);
extern void BSUBWAY_PLAYDATA_AddCounters(struct BsubwayPlayData *p, s32 a, s32 b, s32 c);
extern void BSUBWAY_PLAYDATA_IncRound(struct BsubwayPlayData *p);
extern void BSUBWAY_SCOREDATA_SetFirstClear(struct BsubwayScoreData *p, u32 i);
extern void BSUBWAY_COMM_AddCommandTable(u32 a);
extern void BSUBWAY_COMM_NetInit(void *p);
extern int BSUBWAY_COMM_StartTimingSync(int timingNo);
struct CommEntryMenu;
extern struct CommEntryMenu *COMM_ENTRY_MENU_Create(struct MyStatus *myStatus, struct FieldMap *fieldMap, u32 minMembers, u32 maxMembers, u32 heapId, u32 menuMode, u32 isChild, u8 *mac);
struct BsubwayScrWork;
extern void BSUBWAY_COMM_SetSendData(struct BsubwayScrWork *work, u32 cmd, u16 arg);
extern void BSUBWAY_COMM_SetRecvMode(BsubwayScrWork *work, u8 v);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
struct MetTrainersSave;
extern void MET_TRAINERS_Insert(struct MetTrainersSave *list, u32 value);
extern void *MET_TRAINERS_GetFromSave(void *p);
extern void GFL_NET_ERR_RequestScreen(void);
extern void GAMESYSTEM_SetFieldMapState(struct GameSystem *p, u32 v);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern u32 BATTLE_REC_IsVersionSupported(u32 v);
extern int BSUBWAY_COMM_SendData(BsubwayScrWork *work);
extern int BSUBWAY_COMM_CheckTimingSync(int timingNo);
extern u32 COMM_ENTRY_MENU_Main(struct CommEntryMenu *menu);
extern u32 COMM_ENTRY_MENU_Delete(struct CommEntryMenu *menu);
extern int BSUBWAY_COMM_IsRecvEnd(BsubwayScrWork *work, u16 *out);
extern u32 GFL_NET_IsParentAid(void);
extern void GFL_NET_SetLoginOption(u8 loginOption);
extern void BSUBWAY_COMM_DeleteCommandTable(void *p);
extern int GFL_NET_GetNegotiationNum(void);
extern int GFL_NET_Exit(int exitCallback);
extern int GFL_NET_IsSessionNull(void);
extern void SCRCMD_WORK_SetWaitCount(struct ScrcmdWork *work, u16 count);
extern int SCRCMD_WORK_CountDownWait(struct ScrcmdWork *work);
struct FieldMsgBg;
extern struct FieldMsgBg *FIELDMAP_GetMsgBg(struct FieldMap *fieldMap);
struct FieldMenuFunc;
extern struct FieldMenuFunc *FIELD_MSGBG_CreateYesNoMenu(struct FieldMsgBg *msgBg, u32 cursorPos);
extern int FIELD_MSGBG_YesNoMenuMain(struct FieldMenuFunc *menu);
extern int FIELD_MSGBG_DeleteMenuFunc(struct FieldMenuFunc *menu);
struct HistoryEntry;
extern u32 BSUBWAY_SAVEDATA_GetHistoryEntryScore(struct HistoryEntry *entry);
extern void *FLDMMDL_AddMmdlParam(void *o, int x, int y, u16 d, u32 a, u32 b, u32 c, u32 e);
extern void FLDMMDL_SetParam(struct Mmdl *mmdl, s32 param, s32 no);
extern void FLDMMDL_SetEventId(struct Mmdl *mmdl, u16 eventId);
extern u32 BATTLE_REC_BeginSave(struct GameData *gameData, u16 heap, u32 modeIndex, u32 battleCount, u32 id, u16 *seq, u16 *subSeq);
extern struct Party *POKEPARTY_Create(u32 heap);
extern void POKEPARTY_InitEx(struct Party *p, s32 capacity);
extern u32 POKEPARTY_Add(struct Party *party, struct PokemonParam *member);
struct BtlInstTrainer;
struct BtlSetup;
extern struct BtlSetup *FLD_BTL_INST_TOOL_CreateBtlSetup(struct GameSystem *gameSystem, struct Party *playerParty, u32 battleMode, struct BtlInstTrainer *trainerA, struct BtlInstTrainer *trainerB, s32 monCount);
extern u8 FLD_BTL_INST_TOOL_CreateTrainer(BtlInstTrainer *trainer, u16 trainerNo, u8 memberNum, u16 *monsNo, u16 *itemNo, BtlInstDraw *draw, u16 heapId);
struct BtlInstGroup;
extern struct BtlInstGroup *FLD_BTL_INST_TOOL_InitTrainerHeader(struct BtlInstTrainer *trainer, s32 trainerIndex, s32 heapId);
extern u32 FLD_BTL_INST_TOOL_BuildBattleMon(struct BattleMon *out, u32 member, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useItem, u16 heap);
extern u32 GFL_USE_GetRandom(u32 max);
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
int BSUBWAY_SCR_WaitCommSend(void *task, void *script);
int BSUBWAY_SCR_WaitTimingSync(u32 unused, u32 script);
int BSUBWAY_SCR_WaitCommEntryMenu(u32 unused, u32 script);
int BSUBWAY_SCR_WaitCommEntryMenuSimple(u32 unused, u32 script);
int BSUBWAY_SCR_WaitCommRecvEnd(u32 unused, u32 script);
int BSUBWAY_SCR_CommShutdownMain(void *task, int *rank, BsubwayScrWork **work);
void *BSUBWAY_SCR_CreateCommShutdownTask(void *gameSystem, u32 script);
int BSUBWAY_SCR_YesNoMenuMain(void *task, int *rank, ScreenTaskWork *taskWork);
void *BSUBWAY_SCR_CreateYesNoMenuTask(void *gameSystem, u32 script, u32 resultDst, u32 arg);
void BSUBWAY_SCR_CreateMarkerObjects(BsubwayScrWork *work, void *gameData, void *fieldMmdlSys, void *fieldMap);
u32 BSUBWAY_SCR_GetMmdlParam(u32 mapObj);
u32 BSUBWAY_SCR_IsNpcEntryAvailable(BsubwayScrWork *work, u32 idx);
void BSUBWAY_SCR_GetNpcEntryInfo(BsubwayScrWork *work, u32 idx, u16 *infoFirst, u16 *infoSecond, u16 *infoThird);
int BSUBWAY_SCR_WaitBeginSave(u32 unused, u32 script);
int BSUBWAY_SCR_GetRegulationNo(u32 playMode);
int BSUBWAY_SCR_GetTrainNo(void *fieldMap);
u32 BSUBWAY_SCR_CreateBtlSetup(BsubwayScrWork *work, struct GameSystem *gameSystem);
void *BSUBWAY_SCR_GetNameinEncounterWork(void *work);
u16 BSUBWAY_SCR_DrawTrainerNo(BsubwayScrWork *work, u32 round, u32 stage, u32 line, u8 alt);
u8 BSUBWAY_SCR_CreateTrainer(BsubwayScrWork *work, BtlInstTrainer *trainer, u16 trainerNo, u8 memberNum, u16 *monsNo, u16 *itemNo, BtlInstDraw *draw, u16 heapId);
u8 BSUBWAY_SCR_GetMonIv(u32 trainerNo);
void BSUBWAY_SCR_CreatePartnerMons(BsubwayScrWork *work, BtlInstTrainer *trainer, u16 trainerNo, int useItem, BtlInstDraw *draw, u16 heapId);
u16 BSUBWAY_SCR_Random(void *unused);
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
    return (int)GAME_DATA_SetCurrentEvent(GAMESYSTEM_GetGameData(gameSystem), 0);
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

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    myStatus = GAME_DATA_GetMyStatus(gameData);
    saveControl = GAME_DATA_GetSaveControl(gameData);
    work = GFL_HEAP_Alloc(4, 0x7EC, 1, d_021DE58C, 0x5f);
    work->heapId = 4;
    work->magic = 0x12345678;
    work->gameData = gameData;
    work->romCode = MYSTATUS_GetSex(myStatus);
    work->playData = SAVE_CONTROL_GetBlock(saveControl, 0x39);
    work->scoreData = SAVE_CONTROL_GetBlock(saveControl, 0x3a);
    work->wifiData = SAVE_CONTROL_GetBlock(saveControl, 0x3b);
    BSUBWAY_PLAYDATA_SetFlag01(work->playData, 0);
    GAME_DATA_SetCurrentEvent(gameData, work);
    if (resume == 0) {
        work->playMode = playMode;
        work->memberNum = BSUBWAY_SCR_GetMemberNum(work->playMode);
        for (i = 0; i < 4; i++)
            work->memberIndex[i] = 0xff;
        for (i = 0; i < 14; i++)
            work->trainerNo[i] = 0xffff;
        BSUBWAY_PLAYDATA_Init(work->playData);
        BSUBWAY_PLAYDATA_ClearRound(work->playData);
        if (BSUBWAY_SCOREDATA_HasCleared(work->scoreData, work->playMode) == 1)
            BSUBWAY_SCR_SetWinCount(work, BSUBWAY_SCOREDATA_GetWinCount(work->scoreData, work->playMode));
        saveByte = work->playMode;
        BSUBWAY_PLAYDATA_SetField(work->playData, 0, &saveByte);
    } else {
        work->playMode = BSUBWAY_PLAYDATA_GetField(work->playData, 0, 0);
        work->memberNum = BSUBWAY_SCR_GetMemberNum(work->playMode);
        if (BSUBWAY_PLAYDATA_GetField(work->playData, 10, 0) != 0)
            BSUBWAY_SCR_LoadPartyCopy(work);
        BSUBWAY_PLAYDATA_GetField(work->playData, 5, work->memberIndex);
        BSUBWAY_PLAYDATA_GetField(work->playData, 8, work->trainerNo);
        if (work->playMode == 2 || work->playMode == 7) {
            work->stateBits.partnerNo = (u8)BSUBWAY_PLAYDATA_GetField(work->playData, 9, 0);
            BSUBWAY_PLAYDATA_GetField(work->playData, 6, &work->partnerDraws[work->stateBits.partnerNo]);
            trainerBase = 0x12f;
            if (MYSTATUS_GetSex((const struct MyStatus *)((u8 *)GAME_DATA_GetMyPlayerWork(gameData) + 0x20)) != 0)
                trainerBase -= 3;
            i = work->stateBits.partnerNo;
            BSUBWAY_SCR_CreatePartnerMons(work, &work->partners[i], trainerBase + i, BSUBWAY_PLAYDATA_GetField(work->playData, 7, 0), &work->partnerDraws[i], work->heapId);
        }
        mode = work->playMode;
        if (BSUBWAY_SCOREDATA_HasCleared(work->scoreData, mode) == 1) {
            round = BSUBWAY_PLAYDATA_GetRound(work->playData);
            BSUBWAY_SCR_SetWinCountFromRound(work, BSUBWAY_SCOREDATA_GetRepeatClearCount(work->scoreData, mode), round);
        }
    }
    return work;
}






void BSUBWAY_SCR_DeleteWork(GameSystem *gameSystem, BsubwayScrWork *work)
{
    if (work != 0) {
        if (work->partyCopy != 0) {
            GFL_HEAP_Free(work->partyCopy);
            work->partyCopy = 0;
        }
        if (work->btlSetup != 0) {
            BTL_SETUP_Delete((struct BattleSetupParam *)(work->btlSetup));
            work->btlSetup = 0;
        }
        MI_CpuFill8(work, 0, 0x7EC);
        GFL_HEAP_Free(work);
    }
    GAME_DATA_SetCurrentEvent(GAMESYSTEM_GetGameData(gameSystem), 0);
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
    BSUBWAY_PLAYDATA_SetField(work->playData, 0, &commMode);
    if (BSUBWAY_SCOREDATA_HasCleared(work->scoreData, work->playMode) == 1)
        BSUBWAY_SCR_SetWinCount(work, BSUBWAY_SCOREDATA_GetWinCount(work->scoreData, work->playMode));
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

    BSUBWAY_PLAYDATA_SetField(work->playData, 0, &saveByte);
    BSUBWAY_PLAYDATA_SetField(work->playData, 5, work->memberIndex);
    BSUBWAY_PLAYDATA_SetField(work->playData, 8, work->trainerNo);
    BSUBWAY_PLAYDATA_SetFlag01(work->playData, 1);
    if (work->playMode == 2 || work->playMode == 7) {
        saveByte = work->stateBits.partnerNo;
        BSUBWAY_PLAYDATA_SetField(work->playData, 9, &saveByte);
        BSUBWAY_PLAYDATA_SetField(work->playData, 6, &work->partnerDraws[work->stateBits.partnerNo]);
        BSUBWAY_PLAYDATA_SetField(work->playData, 7, &work->partnerResult[work->stateBits.partnerNo]);
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
    BSUBWAY_PLAYDATA_GetField(work->playData, 5, work->memberIndex);
    party = BSUBWAY_SCR_GetParty(work);
    for (i = 0; i < work->memberNum; i++) {
        mon = (u32)POKEPARTY_GetMember(party, work->memberIndex[i]);
        work->memberMonsNo[i] = POKE_TOOL_GetPartyValue((void *)mon, 5, 0);
        work->memberItemNo[i] = POKE_TOOL_GetPartyValue((void *)mon, 6, 0);
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

    BSUBWAY_PLAYDATA_SetField(work->playData, 0, &saveByte);
    BSUBWAY_PLAYDATA_ClearRound(work->playData);
    BSUBWAY_PLAYDATA_SetField(work->playData, 5, work->memberIndex);
    BSUBWAY_PLAYDATA_SetFlag01(work->playData, 1);
    if (work->playMode == 2 || work->playMode == 7) {
        saveByte = work->stateBits.partnerNo;
        BSUBWAY_PLAYDATA_SetField(work->playData, 9, &saveByte);
        BSUBWAY_PLAYDATA_SetField(work->playData, 6, &work->partnerDraws[work->stateBits.partnerNo]);
        BSUBWAY_PLAYDATA_SetField(work->playData, 7, &work->partnerResult[work->stateBits.partnerNo]);
    }
}






/*
 * Reads the play mode from the play data, clears the play data and resets the score data entry of that mode.
 *
 * Addresses are Black-image addresses.
 */
u32 BSUBWAY_SCR_ResetPlayMode(const struct GameSystem *gameSystem)
{
    u32 saveControl = (u32)GAME_DATA_GetSaveControl((struct GameData *)GAMESYSTEM_GetGameData(gameSystem));
    u32 playData = (u32)SAVE_CONTROL_GetBlock((struct SaveControl *)saveControl, 0x39);
    u32 scoreData = (u32)SAVE_CONTROL_GetBlock((struct SaveControl *)saveControl, 0x3a);
    u8 playMode = BSUBWAY_PLAYDATA_GetField((struct BsubwayPlayData *)playData, 0, 0);

    BSUBWAY_PLAYDATA_ClearRound((struct BsubwayPlayData *)playData);
    BSUBWAY_SCOREDATA_ResetClearCount((struct BsubwayScoreData *)scoreData, playMode);
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

    BSUBWAY_SCOREDATA_SetWinCount((struct BsubwayScoreData *)scoreData, playMode, winCount);
    BSUBWAY_SCOREDATA_UpdateMaxWinCount((struct BsubwayScoreData *)scoreData, playMode, winCount);
    BSUBWAY_SCR_SaveRecordParty(work, (u32)GAME_DATA_GetSaveControl(work->gameData), 1, winCount);
    BSUBWAY_SCOREDATA_ResetClearCount(work->scoreData, playMode);
    BSUBWAY_PLAYDATA_ClearRound(work->playData);
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
        if ((u16)BSUBWAY_PLAYDATA_GetField(work->playData, 0xB, 0) == 1) {
            idx = (s8)BSUBWAY_SCOREDATA_GetLevel(work->scoreData);
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
        count = BSUBWAY_SCOREDATA_GetRepeatClearCount(work->scoreData, work->playMode);
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
    BSUBWAY_SCOREDATA_AddBattlePoints(work->scoreData, points);
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
        work->memberMonsNo[i] = POKE_TOOL_GetPartyValue((void *)mon, 5, 0);
        work->memberItemNo[i] = POKE_TOOL_GetPartyValue((void *)mon, 6, 0);
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
        if (BSUBWAY_PLAYDATA_GetRound(work->playData) < 7)
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

    BSUBWAY_SCOREDATA_SetWinCount(work->scoreData, playMode, winCount);
    BSUBWAY_SCOREDATA_UpdateMaxWinCount(work->scoreData, playMode, BSUBWAY_SCOREDATA_GetWinCount(work->scoreData, playMode));
    BSUBWAY_SCOREDATA_IncClearCount(work->scoreData, playMode);
    BSUBWAY_SCR_SaveRecordParty(work, (u32)GAME_DATA_GetSaveControl(work->gameData), 1, winCount);
    BSUBWAY_PLAYDATA_ClearRound(work->playData);
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
    u32 round = BSUBWAY_PLAYDATA_GetRound(work->playData);
    int i;
    u32 j;
    u16 monsNo[2];
    u16 itemNo[2];

    switch (work->playMode) {
    case 4:
        BSUBWAY_SAVEDATA_ExportTrainer((u32)work->wifiData, (u8 *)work->trainers, round, work->heapId);
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
    u8 rank = (int)BSUBWAY_SCOREDATA_GetLevel(scoreData);
    u32 streak;

    switch (mode) {
    case 0:
        return rank;
    case 3:
        BSUBWAY_SCOREDATA_AccessFlag(scoreData, 0, 2);
        if (rank == 10)
            return 0;
        BSUBWAY_SCOREDATA_IncLevel(scoreData);
        return 1;
    case 4:
        streak = BSUBWAY_SCOREDATA_UpdateStreak(scoreData, 3);
        if (rank == 1)
            return 0;
        if (streak >= data_021DACD0[rank - 1]) {
            BSUBWAY_SCOREDATA_DecLevel(scoreData);
            BSUBWAY_SCOREDATA_UpdateStreak(scoreData, 2);
            BSUBWAY_SCOREDATA_AccessFlag(scoreData, 0, 2);
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
        GFL_HEAP_Free(work->partyCopy);
    work->partyCopy = BATTLE_BOX_CreateParty((struct BoxMonGroup *)BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(work->gameData)), 4);
}






/*
 * Returns the party of gameData unless the query on playData is set, then the cached partyCopy.
 *
 * Addresses are Black-image addresses.
 */
void *BSUBWAY_SCR_GetParty(BsubwayScrWork *work)
{
    if (BSUBWAY_PLAYDATA_GetField(work->playData, 10, 0) == 0)
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
    return (u16)(winCount / 7);
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
        BSUBWAY_PLAYDATA_SetField(work->playData, 0, &saveByte);
        saveByte = BSUBWAY_PLAYDATA_GetRound(work->playData) + 1;
        BSUBWAY_PLAYDATA_SetField(work->playData, 1, &saveByte);
        BSUBWAY_SCOREDATA_CalcRecordScore(work->scoreData, (struct GdsScoreSrc *)(work->playData));
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

    mon->species = POKE_TOOL_GetPartyValue((void *)pokeParam, 5, 0);
    mon->form = POKE_TOOL_GetPartyValue((void *)pokeParam, 0x6f, 0);
    mon->item = POKE_TOOL_GetPartyValue((void *)pokeParam, 6, 0);
    for (i = 0; i < 4; i++) {
        mon->moves[i] = POKE_TOOL_GetPartyValue((void *)pokeParam, 0x36 + i, 0);
        mon->ppUps |= POKE_TOOL_GetPartyValue((void *)pokeParam, 0x3e + i, 0) << (i * 2);
    }
    mon->lang = POKE_TOOL_GetPartyValue((void *)pokeParam, 0xc, 0);
    mon->otId = POKE_TOOL_GetPartyValue((void *)pokeParam, 7, 0);
    mon->pid = POKE_TOOL_GetPartyValue((void *)pokeParam, 0, 0);
    mon->ivs = POKE_TOOL_GetPartyValue((void *)pokeParam, 0xac, 0);
    for (i = 0; i < 6; i++)
        mon->ev[i] = POKE_TOOL_GetPartyValue((void *)pokeParam, 0xd + i, 0);
    mon->ability = POKE_TOOL_GetPartyValue((void *)pokeParam, 0xa, 0);
    mon->friendship = POKE_TOOL_GetPartyValue((void *)pokeParam, 9, 0);
    POKE_TOOL_GetPartyValue((void *)pokeParam, 0x74, (u32)mon->nick);
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
    buf = GFL_HEAP_Alloc((u16)(((u16)work->heapId & 0x7fff) | 0x8000), 0xb4, 0, d_021DE58C, 0x89a);
    MI_CpuFill8(buf, 0, 0xb4);
    party = BSUBWAY_SCR_GetParty(work);
    for (; i < 3; i++)
        BSUBWAY_SCR_PackBattleMon(&buf[i], (u32)POKEPARTY_GetMember(party, work->memberIndex[i]));
    BSUBWAY_SCOREDATA_SetRecordBlob(work->scoreData, slot, buf);
    MI_CpuFill8(buf, 0, 0xb4);
    GFL_HEAP_Free(buf);
}




int BSUBWAY_SCR_CmdCreateWork(u32 script, u32 scriptCtx)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork((void *)scriptCtx);
    u32 gameSystem, resume;

    SCRIPT_WORK_ResetFieldParam((struct ScriptWork *)scriptWork);
    gameSystem = (u32)SCRIPT_WORK_GetGameSystem(scriptWork);
    resume = VM_ReadU16((struct ScriptVm *)script);
    BSUBWAY_SCR_CreateWork((GameSystem *)gameSystem, resume, SCRIPT_WORK_ReadWorkValue((void *)script, (void *)scriptCtx));
    return 0;
}




int BSUBWAY_SCR_CmdClearWorkPtr(u32 script, u32 scriptCtx)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork((void *)scriptCtx);

    SCRIPT_WORK_ResetFieldParam((struct ScriptWork *)scriptWork);
    BSUBWAY_SCR_ClearWorkPtr(SCRIPT_WORK_GetGameSystem(scriptWork));
    return 0;
}




int BSUBWAY_SCR_CmdDeleteWork(u32 script, u32 scriptCtx)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork((void *)scriptCtx);
    u32 gameSystem;

    SCRIPT_WORK_ResetFieldParam((struct ScriptWork *)scriptWork);
    gameSystem = (u32)SCRIPT_WORK_GetGameSystem(scriptWork);
    BSUBWAY_SCR_DeleteWork((GameSystem *)gameSystem, GAME_DATA_GetCurrentEvent(GAMESYSTEM_GetGameData((const struct GameSystem *)gameSystem)));
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
 * - cmd, operand1, operand2 and resultWorkId are u16 (u16 returns): u32 makes the tree
 *   unsigned, and u32 operand1 truncates before each bitfield insert.
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
    u16 operand1;
    u16 operand2;
    u16 resultWorkId;
    u16 *resultDst;
    u16 cmd;

    startedTask = 0;
    scriptWork = SCRCMD_WORK_GetScriptWork((void *)script);
    SCRIPT_WORK_ResetFieldParam((struct ScriptWork *)scriptWork);
    gameSystem = (u32)SCRIPT_WORK_GetGameSystem(scriptWork);
    gameData = (u32)GAMESYSTEM_GetGameData((const struct GameSystem *)gameSystem);
    saveControl = (u32)GAME_DATA_GetSaveControl((struct GameData *)gameData);
    eventFlags = (u32)GAME_DATA_GetEventWork((const struct GameData *)gameData);
    work = GAME_DATA_GetCurrentEvent((struct GameData *)gameData);
    playData = (u32)SAVE_CONTROL_GetBlock((struct SaveControl *)saveControl, 0x39);
    playMode = BSUBWAY_PLAYDATA_GetField((struct BsubwayPlayData *)playData, 0, 0);
    scoreData = (u32)SAVE_CONTROL_GetBlock((struct SaveControl *)saveControl, 0x3a);
    wifiData = (u32)SAVE_CONTROL_GetBlock((struct SaveControl *)saveControl, 0x3b);
    fieldMap = GAMESYSTEM_GetFieldMap((void *)gameSystem);
    cmd = VM_ReadU16(scriptCtx);
    operand1 = SCRIPT_WORK_ReadWorkValue(scriptCtx, (void *)script);
    operand2 = SCRIPT_WORK_ReadWorkValue(scriptCtx, (void *)script);
    resultWorkId = VM_ReadU16(scriptCtx);
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
        BSUBWAY_PLAYDATA_Init((struct BsubwayPlayData *)playData);
        break;
    case BSUBWAY_SCR_CMD_GET_PLAY_DATA_STATE:
        *resultDst = BSUBWAY_PLAYDATA_GetFlag01((struct BsubwayPlayData *)playData);
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
        GAME_DATA_SetSpecialLocation((struct GameData *)gameData, (struct Location *)(&playerLocation));
        ZONEDATA_SetEventFlag((struct EventWork *)eventFlags, 0x966);
        break;
    }
    case BSUBWAY_SCR_CMD_CLEAR_RETURN_LOCATION_FLAG:
        ZONEDATA_ResetEventFlag((struct EventWork *)eventFlags, 0x966);
        break;
    case BSUBWAY_SCR_CMD_GET_RECORD_WIN_COUNT:
        *resultDst = BSUBWAY_SCOREDATA_GetWinCount((struct BsubwayScoreData *)scoreData, operand1);
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
        void *npcObj = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), operand1);
        if (npcObj != 0)
            FLDMMDL_SetStatusBitVanish(npcObj, operand2);
        break;
    }
    case BSUBWAY_SCR_CMD_GET_NEXT_ROUND_FROM_SAVE:
        *resultDst = BSUBWAY_PLAYDATA_GetRound((struct BsubwayPlayData *)playData) + 1;
        break;
    case BSUBWAY_SCR_CMD_GET_NEXT_ROUND:
        *resultDst = BSUBWAY_PLAYDATA_GetRound((struct BsubwayPlayData *)(work->playData));
        *resultDst += 1;
        break;
    case BSUBWAY_SCR_CMD_GET_SCORE_FLAG:
        if (data_021DAD36[operand1] == 11)
            *resultDst = 1;
        else
            *resultDst = BSUBWAY_SCOREDATA_AccessFlag((struct BsubwayScoreData *)scoreData, data_021DAD36[operand1], 0);
        break;
    case BSUBWAY_SCR_CMD_SET_SCORE_FLAG:
        if (data_021DAD36[operand1] != 11)
            BSUBWAY_SCOREDATA_AccessFlag((struct BsubwayScoreData *)scoreData, data_021DAD36[operand1], 1);
        break;
    case BSUBWAY_SCR_CMD_GET_SCORE_FLAG_CLEAR:
        *resultDst = BSUBWAY_SCOREDATA_AccessFlag((struct BsubwayScoreData *)scoreData, 10, 0);
        break;
    case BSUBWAY_SCR_CMD_SET_SCORE_FLAG_CLEAR:
        BSUBWAY_SCOREDATA_AccessFlag((struct BsubwayScoreData *)scoreData, 10, 1);
        break;
    case BSUBWAY_SCR_CMD_SET_TRAIN_SIGN_TABLE:
        FIELD_GIMMICK_BSUBWAY_StartTrain(fieldMap, data_021DAD88[operand1], (int)(&data_021DAD70[operand2]));
        break;
    case BSUBWAY_SCR_CMD_SET_TRAIN_DOOR_STATE:
        FLDEFF_BTRAIN_SetAnime((void *)FIELD_GIMMICK_BSUBWAY_GetTrainEffect((struct FieldMap *)fieldMap), operand1);
        break;
    case BSUBWAY_SCR_CMD_SET_TRAIN_DOOR_STATE_OTHER:
        FLDEFF_BTRAIN_SetHidden((void *)FIELD_GIMMICK_BSUBWAY_GetTrainEffect((struct FieldMap *)fieldMap), operand1);
        break;
    case BSUBWAY_SCR_CMD_GET_SAVED_PLAY_MODE:
        *resultDst = BSUBWAY_PLAYDATA_GetField((struct BsubwayPlayData *)playData, 0, 0);
        break;
    case BSUBWAY_SCR_CMD_IS_MULTI_PLAY_MODE:
        *resultDst = 0;
        switch (operand1) {
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
        u32 height = operand2 << 16;
        void *npcObj = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), operand1);
        if (npcObj != 0) {
            FLDMMDL_GetPos(npcObj, (struct MmdlVec *)(&npcPos));
            npcPos.y = height;
            FLDMMDL_InitPosition(npcObj, (struct MmdlVec *)(&npcPos), FLDMMDL_GetDirDisp(npcObj));
            FLDMMDL_SetStatusBitHeightGetOff(npcObj, 1);
        }
        break;
    }
    case BSUBWAY_SCR_CMD_UNLOCK_NPC: {
        void *npcObj = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), operand1);
        if (npcObj != 0)
            FLDMMDL_SetStatusBitHeightGetOff(npcObj, 0);
        break;
    }
    case BSUBWAY_SCR_CMD_IS_NPC_PRESENT: {
        void *npcObj = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), operand1);
        *resultDst = 0;
        if (npcObj != 0)
            *resultDst = 1;
        break;
    }
    case BSUBWAY_SCR_CMD_GET_NPC_TRAIN_STATE: {
        void *npcObj = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), operand1);
        *resultDst = 0;
        if (npcObj != 0)
            *resultDst = BSUBWAY_SCR_GetMmdlParam((u32)npcObj);
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
        *resultDst = BSUBWAY_SCOREDATA_GetRepeatClearCount((struct BsubwayScoreData *)scoreData, operand1);
        break;
    case BSUBWAY_SCR_CMD_GET_PARTNER_LOOK:
        *resultDst = FIELD_PLAYER_GetObjCodeOfFormCode(MYSTATUS_GetSex((const struct MyStatus *)((u8 *)GAME_DATA_GetMyPlayerWork((struct GameData *)gameData) + 0x20)) == 0 ? 1 : 0, 0);
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
        void *npcObj = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), operand1);
        if (npcObj != 0)
            FLDMMDL_SetDirDispCheckPause((struct Mmdl *)npcObj, operand2);
        break;
    }
    case BSUBWAY_SCR_CMD_RESET_NPC_ANIMATION: {
        void *npcObj = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), operand1);
        if (npcObj != 0)
            FLDMMDL_OnMoveBitMovePause(npcObj);
        break;
    }
    case BSUBWAY_SCR_CMD_START_NPC_TASK:
        SCRIPT_SYS_CallEvent(scriptWork, NAMEIN_SETUP_StartNameBalloonFromHistory(gameSystem, FLDMMDL_GetParam(FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), operand1), 0), operand1));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_GET_MODE_CLEARED:
        *resultDst = BSUBWAY_SCOREDATA_HasCleared((struct BsubwayScoreData *)scoreData, operand1);
        break;
    case BSUBWAY_SCR_CMD_IS_NPC_AVAILABLE: {
        u32 npcIndex = FLDMMDL_GetParam(FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), operand1), 0);
        *resultDst = 0;
        if (BSUBWAY_SCR_IsNpcEntryAvailable(work, npcIndex) == 1)
            *resultDst = 1;
        break;
    }
    case BSUBWAY_SCR_CMD_GET_NPC_INFO_FIRST:
        BSUBWAY_SCR_GetNpcEntryInfo(work, FLDMMDL_GetParam(FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), operand1), 0), &firstA, &firstB, &firstC);
        *resultDst = firstA;
        break;
    case BSUBWAY_SCR_CMD_GET_NPC_INFO_SECOND:
        BSUBWAY_SCR_GetNpcEntryInfo(work, FLDMMDL_GetParam(FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), operand1), 0), &secondA, &secondB, &secondC);
        *resultDst = secondB;
        break;
    case BSUBWAY_SCR_CMD_GET_NPC_INFO_THIRD:
        BSUBWAY_SCR_GetNpcEntryInfo(work, FLDMMDL_GetParam(FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)fieldMap), operand1), 0), &thirdA, &thirdB, &thirdC);
        *resultDst = thirdC;
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_RECORD_COUNT: {
        void *recordList = BSUBWAY_SAVEDATA_AllocHistoryCopy((struct BsubwaySave *)wifiData, 4);
        *resultDst = BSUBWAY_SAVEDATA_CountHistoryEntries(recordList);
        GFL_HEAP_Free(recordList);
        break;
    }
    case BSUBWAY_SCR_CMD_START_SCREEN_TASK: {
        u32 cancelFlag = 0;
        if (operand1 == 1)
            cancelFlag = 1;
        SCRIPT_SYS_CallEvent(scriptWork, BSUBWAY_SCR_CreateYesNoMenuTask((void *)gameSystem, script, (u32)resultDst, cancelFlag));
        startedTask = 1;
        break;
    }
    case BSUBWAY_SCR_CMD_SET_RETURN_LOCATION_FROM_TABLE: {
        u16 tableIndex = BSUBWAY_SCR_GetTrainNo(fieldMap);
        const VecFx32 *pos = &data_021DAE50[tableIndex];
        ZONEDATA_SetDirectLocation(&tableLocation, data_021DADAC[tableIndex], 4, pos->x, pos->y, pos->z);
        GAME_DATA_SetSpecialLocation((struct GameData *)gameData, (struct Location *)(&tableLocation));
        ZONEDATA_SetEventFlag((struct EventWork *)eventFlags, 0x966);
        break;
    }
    case BSUBWAY_SCR_CMD_SET_SCORE_FLAG_FIRST:
        if (operand1 == 0)
            BSUBWAY_SCOREDATA_AccessFlag((struct BsubwayScoreData *)scoreData, 1, 2);
        else
            BSUBWAY_SCOREDATA_AccessFlag((struct BsubwayScoreData *)scoreData, 1, 1);
        break;
    case BSUBWAY_SCR_CMD_GET_SCORE_FLAG_FIRST:
        *resultDst = BSUBWAY_SCOREDATA_AccessFlag((struct BsubwayScoreData *)scoreData, 1, 0);
        break;
    case BSUBWAY_SCR_CMD_START_OV007_PROC_A:
        procParam.mode = 0;
        procParam.result = resultDst;
        SCRIPT_SYS_CallEvent(scriptWork, GAME_EVENT_CreateOverlayEvent((void *)gameSystem, (u32)ov007_id, (u32 (*)(void *, u32))EVENT_BSUBWAY_COMM_Start, (void *)(&procParam)));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_START_OV007_PROC_B:
        startedTask = 1;
        procParam.mode = 1;
        procParam.result = resultDst;
        SCRIPT_SYS_CallEvent(scriptWork, GAME_EVENT_CreateOverlayEvent((void *)gameSystem, (u32)ov007_id, (u32 (*)(void *, u32))EVENT_BSUBWAY_COMM_Start, (void *)(&procParam)));
        break;
    case BSUBWAY_SCR_CMD_START_OV007_PROC_C:
        procParam.mode = 2;
        procParam.result = resultDst;
        SCRIPT_SYS_CallEvent(scriptWork, GAME_EVENT_CreateOverlayEvent((void *)gameSystem, (u32)ov007_id, (u32 (*)(void *, u32))EVENT_BSUBWAY_COMM_Start, (void *)(&procParam)));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_FIELD_101:
        *resultDst = BSUBWAY_SAVEDATA_GetTrainersTagA((struct BsubwaySave *)wifiData);
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_FIELD_FE:
        *resultDst = BSUBWAY_SAVEDATA_GetTrainersPresent((struct BsubwaySave *)wifiData);
        break;
    case BSUBWAY_SCR_CMD_SET_PLAY_DATA_BYTE_11:
        byte11 = operand1;
        BSUBWAY_PLAYDATA_SetField((struct BsubwayPlayData *)playData, 11, &byte11);
        break;
    case BSUBWAY_SCR_CMD_GET_PLAY_DATA_BYTE_11:
        *resultDst = BSUBWAY_PLAYDATA_GetField((struct BsubwayPlayData *)playData, 11, 0);
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_FIELD_FF:
        *resultDst = BSUBWAY_SAVEDATA_GetHistoryPresent((struct BsubwaySave *)wifiData);
        break;
    case BSUBWAY_SCR_CMD_START_PARTY_TASK:
        SCRIPT_SYS_CallEvent(scriptWork, NAMEIN_SETUP_StartHistoryScreenEvent((void *)gameSystem));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_FIELD_103:
        *resultDst = BSUBWAY_SAVEDATA_GetHistoryTagA((struct BsubwaySave *)wifiData);
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_FIELD_102:
        *resultDst = BSUBWAY_SAVEDATA_GetHistoryTagB((struct BsubwaySave *)wifiData);
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
            GAME_DATA_SetSpecialLocation((struct GameData *)gameData, (struct Location *)(&modeLocation));
            ZONEDATA_SetEventFlag((struct EventWork *)eventFlags, 0x966);
        }
        break;
    case BSUBWAY_SCR_CMD_START_PARTY_SELECT:
        {
            u8 useOwnParty = BSUBWAY_PLAYDATA_GetField((struct BsubwayPlayData *)playData, 10, 0);
            SCRIPT_SYS_CallEvent(scriptWork, NAMEIN_SETUP_StartPartyPickEvent((struct EncounterContext *)work, (void *)gameSystem, useOwnParty));
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
        *resultDst = BSUBWAY_SCR_GetTrainerObjCode(work, operand1);
        break;
    case BSUBWAY_SCR_CMD_START_ENCOUNTER_TASK:
        SCRIPT_SYS_CallEvent(scriptWork, NAMEIN_SETUP_StartEncounterScene(work, gameSystem, fieldMap));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_GET_PLAY_MODE:
        *resultDst = work->playMode;
        break;
    case BSUBWAY_SCR_CMD_SET_FIXED_BP_MODE:
        work->stateBits.fixedBpMode = operand1;
        break;
    case BSUBWAY_SCR_CMD_GET_FIXED_BP_MODE:
        *resultDst = work->stateBits.fixedBpMode;
        break;
    case BSUBWAY_SCR_CMD_GET_BATTLE_POINTS:
        *resultDst = BSUBWAY_SCR_AddBattlePoint(work);
        break;
    case BSUBWAY_SCR_CMD_SET_PARTNER_NO:
        work->stateBits.partnerNo = operand1;
        break;
    case BSUBWAY_SCR_CMD_GET_PARTNER_NO:
        *resultDst = work->stateBits.partnerNo;
        break;
    case BSUBWAY_SCR_CMD_DRAW_TRAINER_NOS:
        BSUBWAY_SCR_DrawTrainerNos(work);
        break;
    case BSUBWAY_SCR_CMD_GET_MEMBER_INDEX:
        *resultDst = work->memberIndex[operand1];
        break;
    case BSUBWAY_SCR_CMD_CLEAR_RECV_BUF:
        work->recvCount = 0;
        MI_CpuFill8(work->recvBuf, 0, 0x46);
        break;
    case BSUBWAY_SCR_CMD_START_PARTNER_TASK_A:
        SCRIPT_SYS_CallEvent(scriptWork, NAMEIN_SETUP_StartNameBalloonFromRecord((struct NameBalloonRecord *)work, (void *)gameSystem, operand1, operand2, 5));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_SAVE_PLAY_DATA_MEMBERS:
        BSUBWAY_SCR_SavePlayDataMembers(work);
        break;
    case BSUBWAY_SCR_CMD_LOAD_MEMBERS:
        BSUBWAY_SCR_LoadMembers(work, gameSystem);
        break;
    case BSUBWAY_SCR_CMD_SET_PLAY_DATA_BYTE_10:
        byte10 = operand1;
        BSUBWAY_PLAYDATA_SetField((struct BsubwayPlayData *)playData, 10, &byte10);
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
        BSUBWAY_SCR_CreateMarkerObjects(work, (void *)gameData, FIELDMAP_GetMmdlSys((void *)fieldMap), fieldMap);
        break;
    case BSUBWAY_SCR_CMD_SET_STATE_FLAG8:
        work->stateBits.flag8 = operand1;
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
        u16 playRound = BSUBWAY_PLAYDATA_GetRound((struct BsubwayPlayData *)playData);
        if (playRound != 0) {
            void *trainerCard = (void *)ISS_SYS_GetSwitchSys((u32 *)GAMESYSTEM_GetIssSystem((struct GameSystem *)gameSystem));
            playRound = recordNo + playRound + 1;
            for (; recordNo < playRound; recordNo++) {
                if (recordNo < 9 && recordNo != 0)
                    ISS_SWITCH_SYS_SwitchOn(trainerCard, recordNo);
            }
        }
        break;
    }
    case BSUBWAY_SCR_CMD_CREATE_PARTNERS:
        BSUBWAY_SCR_CreatePartners(work, MYSTATUS_GetSex((const struct MyStatus *)((u8 *)GAME_DATA_GetMyPlayerWork((struct GameData *)gameData) + 0x20)) == 0 ? 1 : 0);
        break;
    case BSUBWAY_SCR_CMD_GET_MEMBER_MONS_NO:
        *resultDst = work->memberMonsNo[operand1];
        break;
    case BSUBWAY_SCR_CMD_SET_COMM_MODE:
        work->stateBits.commMode = operand1;
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
        partySource = BSUBWAY_PLAYDATA_GetField((struct BsubwayPlayData *)playData, 10, 0);
        regulation = POKE_REGULATION_Load(BSUBWAY_SCR_GetRegulationNo(playMode), 4);
        if (partySource == 1) {
            recordParty = BATTLE_BOX_CreateParty((struct BoxMonGroup *)BATTLE_BOX_GetFromSave((void *)saveControl), 4);
            checkedParty = recordParty;
        } else {
            checkedParty = GAME_DATA_GetMyParty((void *)gameData);
        }
        checkResult = POKE_REGULATION_CheckPartyUsable(regulation, checkedParty);
        GFL_HEAP_Free(regulation);
        if (recordParty != NULL)
            GFL_HEAP_Free(recordParty);
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
            if (BATTLE_REC_VerifyAndCloseSave((void *)saveControl, 4, &recordSlot, 0) == 1)
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
        work->msgNumber = operand1;
        VM_SetWait(scriptCtx, (int)BSUBWAY_SCR_WaitBeginSave);
        work->stateBits.btlRecState = 2;
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_FREE_BATTLE_SETUP:
        if (work->btlSetup != 0) {
            BATTLE_REC_FreeWork();
            BTL_SETUP_Delete((struct BattleSetupParam *)work->btlSetup);
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
        BSUBWAY_PLAYDATA_ClearRound((struct BsubwayPlayData *)playData);
        BSUBWAY_SCOREDATA_ResetClearCount((struct BsubwayScoreData *)scoreData, playMode);
        break;
    case BSUBWAY_SCR_CMD_RELEASE_TRAIN_SIGN:
        FIELD_GIMMICK_BSUBWAY_HaltTrainSway((struct FieldMap *)fieldMap);
        break;
    case BSUBWAY_SCR_CMD_GET_TRAINER_NO: {
        u32 playRound = BSUBWAY_PLAYDATA_GetRound((struct BsubwayPlayData *)playData);
        switch (playMode) {
        case 2:
        case 3:
        case 7:
        case 8:
            *resultDst = work->trainerNo[playRound * 2 + operand1];
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
        SCRIPT_SYS_CallEvent(scriptWork, NAMEIN_SETUP_StartNameBalloonFromRecord((struct NameBalloonRecord *)work, (void *)gameSystem, operand1, operand2, 6));
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
                int valueBefore = POKE_TOOL_GetPartyValue(partyMon, 0xa0, 0);
                int valueAfter = POKE_TOOL_GetPartyValue(partyMon, 0xa1, 0);
                sumBefore += valueBefore;
                sumAfter += valueAfter;
            }
            BSUBWAY_PLAYDATA_AddCounters((struct BsubwayPlayData *)playData, tallyLast, tallyFirst, (u16)(sumAfter - sumBefore));
        }
        break;
    }
    case BSUBWAY_SCR_CMD_SET_STATE_FLAG12:
        work->stateBits.flag12 = operand1;
        break;
    case BSUBWAY_SCR_CMD_GET_STATE_FLAG12:
        *resultDst = work->stateBits.flag12;
        break;
    case BSUBWAY_SCR_CMD_GET_PLAY_DATA_BYTE_10:
        *resultDst = BSUBWAY_PLAYDATA_GetField((struct BsubwayPlayData *)playData, 10, 0);
        break;
    case BSUBWAY_SCR_CMD_NEXT_ROUND_GET_WIN_COUNT:
        BSUBWAY_PLAYDATA_IncRound((struct BsubwayPlayData *)playData);
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
        if (BSUBWAY_SCOREDATA_HasCleared((struct BsubwayScoreData *)scoreData, playMode) == 0) {
            BSUBWAY_SCOREDATA_SetFirstClear((struct BsubwayScoreData *)scoreData, playMode);
            BSUBWAY_PLAYDATA_ClearRound((struct BsubwayPlayData *)playData);
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
        SCRIPT_SYS_CallEvent(scriptWork, BSUBWAY_SCR_CreateCommShutdownTask((void *)gameSystem, (u32)work));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_START_TIMING_SYNC:
        work->timingNo = operand1;
        work->resultWorkId = resultWorkId;
        BSUBWAY_COMM_StartTimingSync(work->timingNo);
        VM_SetWait(scriptCtx, (int)BSUBWAY_SCR_WaitTimingSync);
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_START_COMM_CHECK_A:
        work->commResultDst = resultDst;
        work->commTask = (void *)COMM_ENTRY_MENU_Create((struct MyStatus *)GAME_DATA_GetMyStatus((void *)gameData), fieldMap, 2, 2, 4, 0, 2, 0);
        VM_SetWait(scriptCtx, (int)BSUBWAY_SCR_WaitCommEntryMenu);
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_START_COMM_CHECK_B:
        work->commResultDst = resultDst;
        work->commTask = (void *)COMM_ENTRY_MENU_Create((struct MyStatus *)GAME_DATA_GetMyStatus((void *)gameData), fieldMap, 2, 2, 4, 1, 2, 0);
        startedTask = 1;
        VM_SetWait(scriptCtx, (int)BSUBWAY_SCR_WaitCommEntryMenuSimple);
        break;
    case BSUBWAY_SCR_CMD_SEND_COMM_COMMAND:
        BSUBWAY_COMM_SetSendData(work, operand1, operand2);
        VM_SetWait(scriptCtx, (int)BSUBWAY_SCR_WaitCommSend);
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_START_COMM_RECEIVE:
        BSUBWAY_COMM_SetRecvMode(work, operand1);
        work->resultWorkId = resultWorkId;
        VM_SetWait(scriptCtx, (int)BSUBWAY_SCR_WaitCommRecvEnd);
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
        MET_TRAINERS_Insert(MET_TRAINERS_GetFromSave((void *)saveControl), work->partnerMyStatus.id);
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
        GAMESYSTEM_SetFieldMapState((struct GameSystem *)gameSystem, 1);
        break;
    case BSUBWAY_SCR_CMD_IS_SYSTEM_FLAG_SET:
        *resultDst = 0;
        if (GFL_NET_ERR_GetErrorLevel() != 0)
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
int BSUBWAY_SCR_WaitCommSend(void *task, void *script)
{
    if (BSUBWAY_COMM_SendData(GAME_DATA_GetCurrentEvent(GAMESYSTEM_GetGameData(SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(script))))) == 1)
        return 1;
    return 0;
}





int BSUBWAY_SCR_WaitTimingSync(u32 unused, u32 script)
{
    void *gameData;
    BsubwayScrWork *work;
    void *scriptWork;
    u16 *resultDst;

    scriptWork = SCRCMD_WORK_GetScriptWork((void *)script);
    gameData = GAMESYSTEM_GetGameData(SCRIPT_WORK_GetGameSystem(scriptWork));
    work = GAME_DATA_GetCurrentEvent(gameData);
    resultDst = SCRIPT_WORK_GetWorkPtr(scriptWork, gameData, work->resultWorkId);
    if (GFL_NET_ERR_GetErrorLevel() != 0) {
        *resultDst = 0;
        return 1;
    }
    if (BSUBWAY_COMM_CheckTimingSync(work->timingNo) == 1) {
        *resultDst = 1;
        return 1;
    }
    return 0;
}





int BSUBWAY_SCR_WaitCommEntryMenu(u32 unused, u32 script)
{
    void *gameData, *saveControl;
    void *scriptWork;
    BsubwayScrWork *work;
    int commResult;
    u32 zero;

    scriptWork = SCRCMD_WORK_GetScriptWork((void *)script);
    SCRIPT_WORK_ResetFieldParam((struct ScriptWork *)scriptWork);
    gameData = GAMESYSTEM_GetGameData(SCRIPT_WORK_GetGameSystem(scriptWork));
    saveControl = GAME_DATA_GetSaveControl(gameData);
    GAME_DATA_GetEventWork(gameData);
    work = GAME_DATA_GetCurrentEvent(gameData);
    zero = 0;
    BSUBWAY_PLAYDATA_GetField(SAVE_CONTROL_GetBlock(saveControl, 0x39), 0, 0);
    SAVE_CONTROL_GetBlock(saveControl, 0x3A);
    commResult = COMM_ENTRY_MENU_Main((struct CommEntryMenu *)work->commTask);
    if (commResult != 0) {
        COMM_ENTRY_MENU_Delete((struct CommEntryMenu *)work->commTask);
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





int BSUBWAY_SCR_WaitCommEntryMenuSimple(u32 unused, u32 script)
{
    void *gameData, *saveControl;
    void *scriptWork;
    BsubwayScrWork *work;
    int commResult;
    u32 zero;

    scriptWork = SCRCMD_WORK_GetScriptWork((void *)script);
    SCRIPT_WORK_ResetFieldParam((struct ScriptWork *)scriptWork);
    gameData = GAMESYSTEM_GetGameData(SCRIPT_WORK_GetGameSystem(scriptWork));
    saveControl = GAME_DATA_GetSaveControl(gameData);
    GAME_DATA_GetEventWork(gameData);
    work = GAME_DATA_GetCurrentEvent(gameData);
    zero = 0;
    BSUBWAY_PLAYDATA_GetField(SAVE_CONTROL_GetBlock(saveControl, 0x39), 0, 0);
    SAVE_CONTROL_GetBlock(saveControl, 0x3A);
    commResult = COMM_ENTRY_MENU_Main((struct CommEntryMenu *)work->commTask);
    if (commResult != 0) {
        COMM_ENTRY_MENU_Delete((struct CommEntryMenu *)work->commTask);
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





int BSUBWAY_SCR_WaitCommRecvEnd(u32 unused, u32 script)
{
    void *gameData;
    void *scriptWork;
    BsubwayScrWork *work;
    u16 *resultDst;

    scriptWork = SCRCMD_WORK_GetScriptWork((void *)script);
    gameData = GAMESYSTEM_GetGameData(SCRIPT_WORK_GetGameSystem(scriptWork));
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
int BSUBWAY_SCR_CommShutdownMain(void *task, int *state, BsubwayScrWork **work)
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
void *BSUBWAY_SCR_CreateCommShutdownTask(void *gameSystem, u32 script)
{
    void *task = GAME_EVENT_Create(gameSystem, 0, (TaskFn)BSUBWAY_SCR_CommShutdownMain, 4);
    *(u32 *)GAME_EVENT_GetWork(task) = script;
    return task;
}





/*
 * Task step: fades out, runs the ov021 sub-screen on the arg member, stores whether it was cancelled in *result.
 *
 * Addresses are Black-image addresses.
 */
int BSUBWAY_SCR_YesNoMenuMain(void *task, int *state, ScreenTaskWork *taskWork)
{
    SCRCMD_WORK_GetScriptWork(taskWork->script);
    switch (*state) {
    case 0:
        SCRCMD_WORK_SetWaitCount(taskWork->script, 8);
        (*state)++;
    case 1:
        if (SCRCMD_WORK_CountDownWait(taskWork->script) == 1) {
            taskWork->screen = (u32)FIELD_MSGBG_CreateYesNoMenu((struct FieldMsgBg *)FIELDMAP_GetMsgBg(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(taskWork->script))), taskWork->arg);
            (*state)++;
        }
        break;
    case 2:
        switch (FIELD_MSGBG_YesNoMenuMain((struct FieldMenuFunc *)taskWork->screen)) {
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





void *BSUBWAY_SCR_CreateYesNoMenuTask(void *gameSystem, u32 script, u32 resultDst, u32 arg)
{
    void *task = GAME_EVENT_Create(gameSystem, 0, (TaskFn)BSUBWAY_SCR_YesNoMenuMain, 0x10);
    u32 *taskWork = GAME_EVENT_GetWork(task);

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
void BSUBWAY_SCR_CreateMarkerObjects(BsubwayScrWork *work, void *gameData, void *fieldMmdlSys, void *fieldMap)
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
        recordList = (u8 *)BSUBWAY_SAVEDATA_AllocHistoryCopy(SAVE_CONTROL_GetBlock(GAME_DATA_GetSaveControl(gameData), 0x3B), (int)4);
        recordCount = BSUBWAY_SAVEDATA_CountHistoryEntries((struct HistoryBuf *)recordList);
        if (recordCount != 0) {
            recordEntry = recordList + (recordCount - 1) * 0x22;
            while (recordCount != 0 && i < 5) {
                u32 lookIndex = BSUBWAY_SAVEDATA_GetHistoryEntryScore((struct HistoryEntry *)recordEntry) % 10;
                if (((WifiRecordFlags *)(recordEntry + 0x20))->lookSet == 0)
                    objCode = d_021DAD48[lookIndex];
                else
                    objCode = d_021DAD5C[lookIndex];
                mapObj = FLDMMDL_AddMmdlParam(fieldMmdlSys, spawnPos->x, spawnPos->y, i % 4, objId, objCode, 2, zoneId);
                FLDMMDL_SetParam((struct Mmdl *)mapObj, (u16)(recordCount - 1), 0);
                FLDMMDL_SetEventId(mapObj, 5);
                recordEntry -= 0x22;
                i++;
                objId++;
                spawnPos++;
                recordCount--;
            }
        }
        GFL_HEAP_Free(recordList);
        return;
    }
    spawnEntry = d_021DAEBC;
    threshold = BSUBWAY_SCOREDATA_GetRepeatClearCount(work->scoreData, playMode);
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
            FLDMMDL_SetParam((struct Mmdl *)mapObj, (u16)i, 0);
            FLDMMDL_SetParam((struct Mmdl *)mapObj, (u16)spawnEntry->param, 1);
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
u32 BSUBWAY_SCR_GetMmdlParam(u32 mapObj)
{
    return FLDMMDL_GetParam((struct Mmdl *)mapObj, 1);
}





/*
 * Whether entry idx of the 16-byte table at 0x021DAEBC is available (never for kind 4; unlabelled start).
 *
 * Addresses are Black-image addresses.
 */
u32 BSUBWAY_SCR_IsNpcEntryAvailable(BsubwayScrWork *work, u32 idx)
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
void BSUBWAY_SCR_GetNpcEntryInfo(BsubwayScrWork *work, u32 idx, u16 *infoFirst, u16 *infoSecond, u16 *infoThird)
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
int BSUBWAY_SCR_WaitBeginSave(u32 unused, u32 script)
{
    void *gameData;
    BsubwayScrWork *work;
    int messageId;
    int number;
    int messageResult;

    gameData = GAMESYSTEM_GetGameData(SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork((void *)script)));
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
u32 BSUBWAY_SCR_CreateBtlSetup(BsubwayScrWork *work, struct GameSystem *gameSystem)
{
    void *partyList = POKEPARTY_Create(0x8004);
    void *party = BSUBWAY_SCR_GetParty(work);
    int i;
    u32 result;

    POKEPARTY_InitEx(partyList, work->memberNum);
    for (i = 0; i < work->memberNum; i++)
        POKEPARTY_Add(partyList, POKEPARTY_GetMember(party, work->memberIndex[i]));
    result = (u32)FLD_BTL_INST_TOOL_CreateBtlSetup((void *)gameSystem, partyList, work->playMode, work->trainers, &work->partners[work->stateBits.partnerNo], work->memberNum);
    GFL_HEAP_Free(partyList);
    return result;
}




/*
 * Unlabelled leaf in ov021 (printed as a `.word` run at 0x021CBD84); the
 * matching byte at 0x021CBD8C is the pool word 0x0000074C.  Six-byte
 * accessor reached from ov010's NAMEIN_SETUP_StartEncounterTransition across the overlay pair.
 */
void *BSUBWAY_SCR_GetNameinEncounterWork(void *work)
{
    return (char *)work + 0x74c;
}





static inline u16 RandInRange(BsubwayScrWork *work, u32 tbl, u32 round)
{
    u16 span = ((const TrainerNoRange *)(tbl + round * 4))->maxNo - ((const TrainerNoRange *)(tbl + round * 4))->minNo + 1;
    return BSUBWAY_SCR_Random(work) % span + ((const TrainerNoRange *)(tbl + round * 4))->minNo;
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
 * (d_X + 2), and loads the base before the index shift. The signed
 * divide helper is used: the u16 % u16 modulo is signed (int promotion).
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
        id = BSUBWAY_SCR_Random(work) % 100 + 200;
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
    GFL_HEAP_Free(trainerData);
}





/*
 * A 16-bit random value: the arm9 random source scaled down by 0xFFFF.
 *
 * Addresses are Black-image addresses.
 */
u16 BSUBWAY_SCR_Random(void *unused)
{
    return GFL_USE_GetRandom(0xffffffff) / 0xffff;
}
