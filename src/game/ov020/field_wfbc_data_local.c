/*
 * file:     field_wfbc_data_local.c
 * unit:     yes
 * function: FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl, FIELD_WFBC_DATA_LOCAL_ClearPeopleList, FIELD_WFBC_DATA_LOCAL_ClearBackPeopleList, FIELD_WFBC_DATA_LOCAL_Init, FIELD_WFBC_DATA_LOCAL_IsFullyPopulated, FIELD_WFBC_DATA_LOCAL_Sanitize, FIELD_WFBC_DATA_LOCAL_IsDataComplete, FIELD_WFBC_DATA_LOCAL_CountPeople, FIELD_WFBC_DATA_LOCAL_AdvanceDays, FIELD_WFBC_DATA_LOCAL_MoveBoredPeopleToBackList, FIELD_WFBC_DATA_LOCAL_ApplyTalkedMoodBonus, FIELD_WFBC_DATA_LOCAL_InsertPersonForCity, FIELD_WFBC_DATA_LOCAL_CreateMmdlHeaders, FIELD_WFBC_DATA_LOCAL_FillPeopleListEntries, FIELD_WFBC_DATA_LOCAL_ValidatePerson, FIELD_WFBC_DATA_LOCAL_ApplyGiftMoodBonus, FIELD_WFBC_DATA_LOCAL_ClearArrivalFlag, FIELD_WFBC_DATA_LOCAL_HasArrivalFlag, FIELD_WFBC_DATA_LOCAL_SetPersonParent, FIELD_WFBC_DATA_LOCAL_HasParent, FIELD_WFBC_DATA_LOCAL_GetNpcId, FIELD_WFBC_DATA_LOCAL_IsMoodLow, FIELD_WFBC_DATA_LOCAL_OpenNpcData, FIELD_WFBC_DATA_LOCAL_CloseNpcData, FIELD_WFBC_DATA_LOCAL_LoadNpcData, FIELD_WFBC_DATA_LOCAL_GetNpcRecord, FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable, FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable, FIELD_WFBC_DATA_LOCAL_GetPositionPair, FIELD_WFBC_DATA_LOCAL_GetItemPositionPair, FIELD_WFBC_DATA_LOCAL_CountItemSlots, FIELD_WFBC_DATA_LOCAL_SetItemSlotIfEmpty, FIELD_WFBC_DATA_LOCAL_GetItemSlot, FIELD_WFBC_DATA_LOCAL_IsItemSlotUsed, FIELD_WFBC_DATA_LOCAL_CreateItemMmdlHeaders, FIELD_WFBC_DATA_LOCAL_GetCounter, FIELD_WFBC_DATA_LOCAL_IncCounter, FIELD_WFBC_DATA_LOCAL_GetValue, FIELD_WFBC_DATA_LOCAL_AddValuePoints, FIELD_WFBC_DATA_LOCAL_ReadValue, FIELD_WFBC_DATA_LOCAL_WriteValue, FIELD_WFBC_DATA_LOCAL_ReadCounter, FIELD_WFBC_DATA_LOCAL_WriteCounter, FIELD_WFBC_DATA_LOCAL_PickNpcByWeight, FIELD_WFBC_DATA_LOCAL_GetNthAbsentNpcId, FIELD_WFBC_DATA_LOCAL_IsNpcPresent, FIELD_WFBC_DATA_LOCAL_InsertPerson, FIELD_WFBC_DATA_LOCAL_IsPeopleListFull, FIELD_WFBC_DATA_LOCAL_PushPersonFront, FIELD_WFBC_DATA_LOCAL_FindEmptyPersonSlot, FIELD_WFBC_DATA_LOCAL_InitNewPerson, FIELD_WFBC_DATA_LOCAL_IsMoodZero, FIELD_WFBC_DATA_LOCAL_AddMood, FIELD_WFBC_DATA_LOCAL_SetMood, FIELD_WFBC_DATA_LOCAL_ScrCmdMarkFacingPerson, FIELD_WFBC_DATA_LOCAL_ScrCmdCheckAndMarkFacingPerson, FIELD_WFBC_DATA_LOCAL_ScrCmdSetFacingPersonParam, FIELD_WFBC_DATA_LOCAL_ScrCmdGetWfbcValue, FIELD_WFBC_DATA_LOCAL_ScrCmdAddPoints, FIELD_WFBC_DATA_LOCAL_ScrCmdFindTargetPokemonInParty, FIELD_WFBC_DATA_LOCAL_ScrCmdGetFacingPersonMessageIndex, FIELD_WFBC_DATA_LOCAL_ScrCmdCallPersonTalkEvent, FIELD_WFBC_DATA_LOCAL_CreatePersonTalkEvent, FIELD_WFBC_DATA_LOCAL_PersonTalkEventMain, FIELD_WFBC_DATA_LOCAL_StartTalkMessage, FIELD_WFBC_DATA_LOCAL_StartTalkMessageWithChoice, FIELD_WFBC_DATA_LOCAL_UpdateTalkMessage, FIELD_WFBC_DATA_LOCAL_FreeTalkMessage
 * address:  0x02186090
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GAME_DATA_GetEntranceLocation  0x02012870  thumb
 *   GAME_DATA_GetStartLocation  0x0201284C  thumb
 *   ZONEDATA_IsParentZoneD6  0x02014068  thumb
 *   GAME_DATA_SetEscapeLocation  0x020128C0  thumb
 *   ZONEDATA_SetZoneStartLocation  0x02014204  thumb
 *   ZONEDATA_IsWeatherEnabled  0x02013C50  thumb
 *   ZONEDATA_IsZoneInTableDFDC 0x02013FEC thumb
 *   GAME_DATA_GetSpecialLocation 0x02012894 thumb
 *   GAME_DATA_GetMyPlayerWork 0x020127A4 thumb
 *   GAME_DATA_GetPlayerObjectCode 0x02012B28 thumb
 *   GAME_DATA_SetPlayerObjectCode 0x02012B2C thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_ToChars  0x02045A38  arm
 *   MAIL_Create  0x02008F08  thumb
 *   func_02008F88  0x02008F88  thumb
 *   func_02008FA0  0x02008FA0  thumb
 *   func_02008FA8  0x02008FA8  thumb
 *   func_02008FB4  0x02008FB4  thumb
 *   func_02008FBC  0x02008FBC  thumb
 *   func_02008FD8  0x02008FD8  thumb
 *   func_02008FC4  0x02008FC4  thumb
 *   func_02008FEC  0x02008FEC  thumb
 *   func_0200903C  0x0200903C  thumb
 *   func_020307B0  0x020307B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   d_02187DA4  0x02187DA4  data  ov020  a4
 *   d_02187DAC  0x02187DAC  data  ov020  a4
 *   d_02187DB4  0x02187DB4  data  ov020  a4
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   POKEPARTY_GetSaveData 0x0201AD0C thumb
 *   GAME_DATA_GetSeason 0x02012984 thumb
 *   func_02008B14 0x02008B14 thumb
 *   FORMCHANGE_RevertShayminAtNight 0x0216A358 thumb ov010
 *   func_02030734 0x02030734 arm
 *   d_02187EA0 0x02187EA0 data ov020 a1
 *   FLDMMDL_GetObjId  0x0216D588  thumb
 *   EVENT_FIELD_PROCLINK_ClearReturnEntry 0x02161E78 thumb ov010
 *   func_02008530  0x02008530  thumb
 *   func_020056EC  0x020056EC  thumb
 *   EVENT_FIELD_PROCLINK_IsReturnEntryAllowed 0x02161E84 thumb ov010
 *   func_0200855C  0x0200855C  thumb
 *   INTRUDE_COMM_NormalizeVersion  0x021584F4  thumb  ov010
 *   EVENT_FIELD_PROCLINK_IsReturnEntryValid 0x02161ECC thumb ov010
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   GAME_DATA_GetMysteryRecvFlagA  0x020127E0  thumb
 *   GAME_DATA_GetMysteryRecvFlagB  0x020127F0  thumb
 *   ZONEDATA_IsZoneInTableDFEC  0x02013DE0  thumb
 *   EVENT_FIELD_PROCLINK_CompactReturnList  0x02161E60  thumb
 *   EVENT_FIELD_PROCLINK_InitIdList  0x02161EEC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   FLDMMDL_InitPosRecord  0x0216E618  thumb  ov010
 *   d_02187EB4     0x02187EB4  data  ov020  a1
 *   d_02187DBC     0x02187DBC  data  ov020  a4
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   func_020084F4 0x020084F4 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_ReadHandleMember  0x0204932C  arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   d_02187DE0     0x02187DE0  data  ov020  a4
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_GetWfbc  0x0218DC70  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELD_PLAYER_GetFrontGridPos  0x021A3460  thumb  ov021
 *   FLDMMDL_SysSearchGridPos  0x0216DDC0  thumb  ov010
 *   FIELD_WFBC_ApplyGiftMood  0x02193B40  thumb  ov021
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   FIELD_WFBC_GetPeopleArrivalFlag  0x02193BE4  thumb  ov021
 *   FIELD_WFBC_ClearPeopleArrivalFlag  0x02193BC4  thumb  ov021
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   FIELD_WFBC_SetWordSetParentName  0x02193B68  thumb  ov021
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FIELD_WFBC_ReloadSaveData  0x02193904  thumb  ov021
 *   FIELD_WFBC_GetPeople  0x0219390C  thumb  ov021
 *   FIELD_WFBC_PEOPLE_GetNpcRecord  0x02193C00  thumb  ov021
 *   FIELD_WFBC_PEOPLE_GetPersonData  0x02193C04  thumb  ov021
 *   FIELD_WFBC_GetPeopleNum  0x021938F4  thumb  ov021
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   GF_STANDARD_SetField00_F4E4  0x0203F4E4  arm
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   FIELD_WFBC_GetCityType  0x0219391C  thumb  ov021
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   SCRIPT_SYS_CallEvent 0x0215897C thumb ov010
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_GetReturnSlots  0x02158434  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   GF_FONT_Create_EC64  0x0201EC64  thumb
 *   func_020127D0  0x020127D0  thumb
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   EVENT_FIELD_PROCLINK_ClearReturnDefaultAndPending  0x021620A0  thumb  ov010
 *   EVENT_FIELD_PROCLINK_RequestReturn  0x02162048  thumb  ov010
 *   EVENT_FIELD_PROCLINK_HasReturnDefaultSlot  0x0216208C  thumb  ov010
 *   EVENT_FIELD_PROCLINK_GetReturnDefaultSlotType  0x0216209C  thumb  ov010
 *   EVENT_FIELD_PROCLINK_HasEventdataEntry  0x02161E4C  thumb  ov010
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   EVENT_FIELD_PROCLINK_ApplyReturnEntry  0x02161F90  thumb  ov010
 *   FIELD_WFBC_RemovePeople  0x02193B20  thumb  ov021
 *   FLDMMDL_DeleteMmdl  0x0216CF2C  thumb  ov010
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   FIELD_MSGBG_AddTalkWin  0x0219129C  thumb  ov021
 *   d_02187E04     0x02187E04  data  ov020  a2
 *   FIELD_MSGBG_TalkWinMain  0x02191388  thumb  ov021
 *   KEY_GetTrg  0x020362DC  arm
 *   FIELD_MSGBG_CreateYesNoMenu  0x02190BE4  thumb  ov021
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb  ov021
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 *   FIELD_MSGBG_DeleteTalkWin  0x021912D8  thumb  ov021
 *   FIELD_MSGBG_WaitTalkWinClose  0x021912F8  thumb  ov021
 *   FIELD_MSGBG_ClearTalkWin 0x0219131C thumb ov021
 *   WAZA_OSHIE_GetTexFormatCount  0x0216FC4C  thumb  ov010
 *   WAZA_OSHIE_LoadTexPlttByName  0x0216FAB4  thumb  ov010
 *   EL_SCOREBOARD_SourceFileName     0x02187EDC  data  ov020  a4
 *   func_02061CA4 0x02061CA4 arm
 *   EL_SCOREBOARD_LampPaletteColors 0x02187ECC data ov020 a4
 *   func_020124EC  0x020124EC  thumb
 *   func_0202E8B8  0x0202E8B8  thumb
 *   BG_SYS_GetMainVisiblePlanes 0x02043658 arm
 *   FIELDMAP_SetBgMode 0x02188DA0 thumb ov021
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   EL_SCOREBOARD_VramBankConfig     0x02187E58  data  ov020
 *   EL_SCOREBOARD_DispConfig     0x02187E28  data  ov020
 *   EL_SCOREBOARD_BgTemplate     0x02187E38  data  ov020
 *   NNS_G2dGetUnpackedPaletteData  0x02062A98  arm
 *   BG_SYS_LoadPltt  0x02040E78  arm
 *   NNS_G2dGetUnpackedCharacterDataEx  0x02062A4C  arm
 *   BG_SYS_LoadTileData  0x02040B1C  arm
 *   NNS_G2dGetUnpackedScreenData  0x02062B30  arm
 *   BG_SYS_PushTileSource  0x020409E0  arm
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_0207D658  0x0207D658  arm
 *   func_0207D63C  0x0207D63C  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   func_0209BE04  0x0209BE04  arm
 *   func_0209CE10  0x0209CE10  arm
 *   func_0209C77C  0x0209C77C  arm
 *   func_0209C95C  0x0209C95C  arm
 *   func_0209CB8C  0x0209CB8C  arm
 *   func_0209C494  0x0209C494  arm
 *   func_0202E8A4  0x0202E8A4  thumb
 *   func_02040588  0x02040588  arm
 *   FIELDMAP_ResetBgAffineShowMsg  0x02188DB0  thumb  ov021
 *   FIELDMAP_SetSubscreenBusy 0x02189A50 thumb ov021
 */

struct GameData;
struct Location;
struct PlayerWork;
struct MsgData;
struct Strbuf;
struct MyStatus;
struct ArcHandle;
struct FieldMap;
struct FieldWfbc;
struct GameSystem;
struct RtcDate;
struct GameEvent;
struct WordSet;
struct Mmdl;
struct VecFx32;
struct FieldMsgHandle;
struct ScrcmdWork;
struct FieldYesNoHandle;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Location { u32 v[7]; };

typedef short GridCoord;

typedef signed int     s32;

typedef unsigned long long u64;
#include "../ov010/script_work_types.h"
#include "../ov021/field_wfbc_types.h"
extern void *GAME_DATA_GetMyPlayerWork(struct GameData *p);
struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
u32 func_020307B0(void *p);
void STRBUF_Delete(struct Strbuf *vec);
u32 MSGDATA_Delete(struct MsgData *rec);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u16 FLDMMDL_GetObjId(const struct Mmdl *mmdl);
extern void EVENT_FIELD_PROCLINK_ClearReturnEntry(WfbcPerson *person);
extern u32 func_02008530(const struct MyStatus *obj);
extern u32 func_020056EC(u32 n);
extern int EVENT_FIELD_PROCLINK_IsReturnEntryAllowed(const WfbcPerson *person);
u8 func_0200855C(const struct MyStatus *obj);
int INTRUDE_COMM_NormalizeVersion(int a, int b);
extern int EVENT_FIELD_PROCLINK_IsReturnEntryValid(const WfbcPerson *person);
extern u16 GAME_DATA_GetPlayerZoneId(const struct PlayerWork *p);
extern WfbcData *GAME_DATA_GetSecondUnionInfo(struct GameData *gameData);
extern u16 *GAME_DATA_GetMysteryRecvFlagA(struct GameData *gameData);
extern WfbcDailyState *GAME_DATA_GetMysteryRecvFlagB(struct GameData *gameData);
extern int ZONEDATA_IsZoneInTableDFEC(u16 id);
extern void EVENT_FIELD_PROCLINK_CompactReturnList(WfbcData *data, int mode);
extern void EVENT_FIELD_PROCLINK_InitIdList(u16 *itemSlots);
extern void FLDMMDL_InitPosRecord(MmdlHeader *header, u16 gridX, u16 gridZ, int direction);
extern u16 STRBUF_GetEosChar(void);
extern const void *func_020084F4(const void *p);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void ARC_TOOL_ReadHandleMember(struct ArcHandle *arc, u32 member, void *dst);
extern void ARC_TOOL_DeleteHandle(void *p);
extern void *ARC_TOOL_LoadHandleMember(struct ArcHandle *arc, unsigned int member,
                           unsigned int heap);
extern ScriptWork *SCRCMD_WORK_GetScriptWork(struct ScrcmdWork *work);
extern ScriptFieldParam *SCRIPT_WORK_ResetFieldParam(ScriptWork *scriptWork);
extern void *FIELDMAP_GetG3dMapper(void *fieldSystem);
extern FieldWfbc *FIELD_G3D_MAPPER_GetWfbc(void *fieldWfbcOwner);
extern struct GameData *SCRCMD_WORK_GetGameData(struct ScrcmdWork *work);
extern void *FIELDMAP_GetFieldPlayer(void *fieldSystem);
extern void *FIELDMAP_GetMmdlSys(void *fieldSystem);
extern int FIELD_PLAYER_GetFrontGridPos(void *player, GridCoord *outX, GridCoord *outY, GridCoord *outZ);
extern struct Mmdl *FLDMMDL_SysSearchGridPos(void *mmdlSystem, int gridX, int gridZ, int unused);
extern void FIELD_WFBC_ApplyGiftMood(FieldWfbc *wfbc, u32 personIndex);
extern int FIELD_WFBC_GetPeopleArrivalFlag(FieldWfbc *wfbc, u32 personIndex);
extern void FIELD_WFBC_ClearPeopleArrivalFlag(FieldWfbc *wfbc, u32 personIndex);
extern void *SCRIPT_WORK_GetWordSet(ScriptWork *scriptWork);
extern unsigned int SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, struct ScrcmdWork *work);
extern u16 SCRCMD_WORK_GetHeapId(struct ScrcmdWork *work);
extern void FIELD_WFBC_SetWordSetParentName(FieldWfbc *wfbc, void *wordSet, int npcId, int bufIndex, int heapId);
extern u16 *SCRIPT_WORK_ReadWorkPointer(ScriptVm *vm, struct ScrcmdWork *work);
extern void FIELD_WFBC_ReloadSaveData(FieldWfbc *wfbc);
extern FieldWfbcPeople *FIELD_WFBC_GetPeople(FieldWfbc *wfbc, u32 personIndex);
extern WfbcNpcRecord *FIELD_WFBC_PEOPLE_GetNpcRecord(FieldWfbcPeople *people);
extern WfbcPerson *FIELD_WFBC_PEOPLE_GetPersonData(FieldWfbcPeople *people);
extern int FIELD_WFBC_GetPeopleNum(FieldWfbc *wfbc);
extern struct GameSystem *FIELDMAP_GetGameSystem(void *fieldSystem);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
void *GAME_DATA_GetMyParty(const struct GameData *p);
u32 POKEPARTY_GetCount(void *a);
void GF_STANDARD_SetField00_F4E4(struct RtcDate *date);
void *POKEPARTY_GetMember(void *a, u32 i);
u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern unsigned char FIELD_WFBC_GetCityType(FieldWfbc *wfbc);
extern struct GameSystem *SCRCMD_WORK_GetGameSystem(struct ScrcmdWork *work);
extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
extern void SCRIPT_SYS_CallEvent(ScriptWork *scriptWork, void *event);
u16 FIELDMAP_GetHeapId(void *fieldSystem);
u32 FIELDMAP_GetMsgBg(void *fieldSystem);
void *GAMESYSTEM_GetGameComm(const struct GameSystem *gameSystem);
void *INTRUDE_COMM_GetWorkIfRunning(void *eventWork);
void *INTRUDE_COMM_GetReturnSlots(void *eventWork);
struct GameEvent *func_020122C0(struct GameSystem *gameSystem, void *parent, void *proc, u32 workSize);
void *func_020124E8(struct GameEvent *p);
struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
struct WordSet *GF_FONT_Create_EC64(u32 heap);
WfbcData *func_020127D0(struct GameData *gameData, u32 index);
void FLDMMDL_GetPos(const struct Mmdl *mmdl, struct VecFx32 *out);
int EVENT_FIELD_PROCLINK_ClearReturnDefaultAndPending(void *returnList);
void EVENT_FIELD_PROCLINK_RequestReturn(void *returnList, int personIndex, int mode);
int EVENT_FIELD_PROCLINK_HasReturnDefaultSlot(void *returnList, int personIndex);
u16 EVENT_FIELD_PROCLINK_GetReturnDefaultSlotType(void *returnList);
int EVENT_FIELD_PROCLINK_HasEventdataEntry(WfbcData *data, int personIndex, unsigned mode);
void FADE_Start(u32 a, s32 b, s32 c, s32 d);
int FADE_IsActive(void);
void *GAME_DATA_GetMyStatus(struct GameData *gameData);
void EVENT_FIELD_PROCLINK_ApplyReturnEntry(void *returnList, WfbcData *ownData, WfbcData *cityData, void *playerBlock, u16 personIndex, u16 heapId);
int FIELD_WFBC_RemovePeople(FieldWfbc *wfbc, u32 personIndex);
void FLDMMDL_DeleteMmdl(struct Mmdl *mmdl);
u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void MSGDATA_ReadString(struct MsgData *bank, u32 index, struct Strbuf *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *wordSet, struct Strbuf *dst, struct Strbuf *src);
extern struct FieldMsgHandle *FIELD_MSGBG_AddTalkWin(int msgBgSys, int speed, int *playerPos, struct Strbuf *message, u32 c, u32 d);
extern u32 FIELD_MSGBG_TalkWinMain(struct FieldMsgHandle *handle);
extern u32 KEY_GetTrg(void);
extern struct FieldYesNoHandle *FIELD_MSGBG_CreateYesNoMenu(int msgBgSys, u32 b);
extern int FIELD_MSGBG_YesNoMenuMain(struct FieldYesNoHandle *h);
extern int FIELD_MSGBG_DeleteMenuFunc(struct FieldYesNoHandle *handle);
extern int FIELD_MSGBG_DeleteTalkWin(struct FieldMsgHandle *handle);
extern int FIELD_MSGBG_WaitTalkWinClose(struct FieldMsgHandle *handle);
extern int FIELD_MSGBG_ClearTalkWin(struct FieldMsgHandle *handle);
int FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(const struct Mmdl *mmdl);
void FIELD_WFBC_DATA_LOCAL_ClearPeopleList(WfbcData *data);
void FIELD_WFBC_DATA_LOCAL_ClearBackPeopleList(WfbcData *data);
void FIELD_WFBC_DATA_LOCAL_Init(WfbcData *data, const struct MyStatus *myStatus, int heapSeed);
int FIELD_WFBC_DATA_LOCAL_IsFullyPopulated(WfbcData *data);
void FIELD_WFBC_DATA_LOCAL_Sanitize(WfbcData *data, const struct MyStatus *myStatus);
int FIELD_WFBC_DATA_LOCAL_IsDataComplete(WfbcData *data);
int FIELD_WFBC_DATA_LOCAL_CountPeople(const WfbcData *data, int which);
void FIELD_WFBC_DATA_LOCAL_AdvanceDays(struct GameData *gameData, int days, u32 heapSeed);
void FIELD_WFBC_DATA_LOCAL_MoveBoredPeopleToBackList(struct GameData *gameData);
void FIELD_WFBC_DATA_LOCAL_ApplyTalkedMoodBonus(u8 *data);
void FIELD_WFBC_DATA_LOCAL_InsertPersonForCity(WfbcData *data, const struct MyStatus *myStatus, WfbcPerson *person);
MmdlHeader *FIELD_WFBC_DATA_LOCAL_CreateMmdlHeaders(WfbcData *data, int which, int heapSeed);
void FIELD_WFBC_DATA_LOCAL_FillPeopleListEntries(const WfbcData *data, WfbcListEntry *entries, u16 *entryCount, int page, u16 heapId);
void FIELD_WFBC_DATA_LOCAL_ValidatePerson(WfbcPerson *person);
void FIELD_WFBC_DATA_LOCAL_ApplyGiftMoodBonus(WfbcPerson *person);
void FIELD_WFBC_DATA_LOCAL_ClearArrivalFlag(WfbcPerson *person);
int FIELD_WFBC_DATA_LOCAL_HasArrivalFlag(const WfbcPerson *person);
void FIELD_WFBC_DATA_LOCAL_SetPersonParent(WfbcPerson *person, const struct MyStatus *myStatus);
int FIELD_WFBC_DATA_LOCAL_HasParent(const WfbcPerson *person);
int FIELD_WFBC_DATA_LOCAL_GetNpcId(const WfbcPerson *person);
int FIELD_WFBC_DATA_LOCAL_IsMoodLow(const WfbcPerson *person);
WfbcNpcData *FIELD_WFBC_DATA_LOCAL_OpenNpcData(int fileId, int heapId);
void FIELD_WFBC_DATA_LOCAL_CloseNpcData(WfbcNpcData *npcData);
void FIELD_WFBC_DATA_LOCAL_LoadNpcData(WfbcNpcData *npcData, u32 fileId);
WfbcNpcRecord *FIELD_WFBC_DATA_LOCAL_GetNpcRecord(WfbcNpcData *npcData);
WfbcPosition *FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable(WfbcNpcData *npcData, int cityType, unsigned int heapId);
void FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable(WfbcPosition *positions);
WfbcPosition *FIELD_WFBC_DATA_LOCAL_GetPositionPair(WfbcPosition *positions, int index);
WfbcPosition *FIELD_WFBC_DATA_LOCAL_GetItemPositionPair(WfbcPosition *positions, int index);
int FIELD_WFBC_DATA_LOCAL_CountItemSlots(const u16 *itemSlots);
int FIELD_WFBC_DATA_LOCAL_SetItemSlotIfEmpty(u16 *itemSlots, u16 itemId, int slot);
u16 FIELD_WFBC_DATA_LOCAL_GetItemSlot(const u16 *itemSlots, int slot);
int FIELD_WFBC_DATA_LOCAL_IsItemSlotUsed(const u16 *itemSlots, int slot);
MmdlHeader *FIELD_WFBC_DATA_LOCAL_CreateItemMmdlHeaders(u16 *itemSlots, int which, int cityType, int heapSeed);
u16 FIELD_WFBC_DATA_LOCAL_GetCounter(const WfbcDailyState *dailyState);
void FIELD_WFBC_DATA_LOCAL_IncCounter(WfbcDailyState *dailyState);
u16 FIELD_WFBC_DATA_LOCAL_GetValue(const WfbcDailyState *dailyState);
void FIELD_WFBC_DATA_LOCAL_AddValuePoints(WfbcDailyState *dailyState);
u16 FIELD_WFBC_DATA_LOCAL_ReadValue(const WfbcDailyState *dailyState);
void FIELD_WFBC_DATA_LOCAL_WriteValue(WfbcDailyState *dailyState, u16 value);
u16 FIELD_WFBC_DATA_LOCAL_ReadCounter(const WfbcDailyState *dailyState);
void FIELD_WFBC_DATA_LOCAL_WriteCounter(WfbcDailyState *dailyState, u16 counter);
WfbcNpcRecord *FIELD_WFBC_DATA_LOCAL_PickNpcByWeight(const WfbcData *data, int limit, WfbcNpcData *npcData, int *outNpcId);
int FIELD_WFBC_DATA_LOCAL_GetNthAbsentNpcId(const WfbcData *data, int nth);
int FIELD_WFBC_DATA_LOCAL_IsNpcPresent(const WfbcData *data, int npcId);
void FIELD_WFBC_DATA_LOCAL_InsertPerson(WfbcData *data, const struct MyStatus *myStatus, WfbcPerson *person, int setParent);
int FIELD_WFBC_DATA_LOCAL_IsPeopleListFull(const WfbcPerson *list);
WfbcPerson *FIELD_WFBC_DATA_LOCAL_PushPersonFront(WfbcPerson *list, const WfbcPerson *person);
WfbcPerson *FIELD_WFBC_DATA_LOCAL_FindEmptyPersonSlot(WfbcPerson *list);
void FIELD_WFBC_DATA_LOCAL_InitNewPerson(WfbcPerson *person, int npcId, const struct MyStatus *myStatus, int mood, int setParent);
int FIELD_WFBC_DATA_LOCAL_IsMoodZero(const WfbcPerson *person);
int FIELD_WFBC_DATA_LOCAL_AddMood(WfbcPerson *person, int delta);
void FIELD_WFBC_DATA_LOCAL_SetMood(WfbcPerson *person, int mood);
int FIELD_WFBC_DATA_LOCAL_ScrCmdMarkFacingPerson(ScriptVm *vm, struct ScrcmdWork *work);
int FIELD_WFBC_DATA_LOCAL_ScrCmdCheckAndMarkFacingPerson(ScriptVm *vm, struct ScrcmdWork *work);
int FIELD_WFBC_DATA_LOCAL_ScrCmdSetFacingPersonParam(ScriptVm *vm, struct ScrcmdWork *work);
int FIELD_WFBC_DATA_LOCAL_ScrCmdGetWfbcValue(ScriptVm *vm, struct ScrcmdWork *work);
int FIELD_WFBC_DATA_LOCAL_ScrCmdAddPoints(ScriptVm *vm, struct ScrcmdWork *work);
int FIELD_WFBC_DATA_LOCAL_ScrCmdFindTargetPokemonInParty(ScriptVm *vm, struct ScrcmdWork *work);
int FIELD_WFBC_DATA_LOCAL_ScrCmdGetFacingPersonMessageIndex(ScriptVm *vm, struct ScrcmdWork *work);
int FIELD_WFBC_DATA_LOCAL_ScrCmdCallPersonTalkEvent(ScriptVm *vm, struct ScrcmdWork *work);
struct GameEvent *FIELD_WFBC_DATA_LOCAL_CreatePersonTalkEvent(struct GameSystem *gameSystem, void *fieldSystem);
int FIELD_WFBC_DATA_LOCAL_PersonTalkEventMain(struct GameEvent *event, int *state, WfbcTalkEvent *talk);
void FIELD_WFBC_DATA_LOCAL_StartTalkMessage(WfbcTalkEvent *talk, int messageSlot, int *state, int nextState);
void FIELD_WFBC_DATA_LOCAL_StartTalkMessageWithChoice(WfbcTalkEvent *talk, int messageSlot, int *state, int yesStateId, u16 noStateId);
int FIELD_WFBC_DATA_LOCAL_UpdateTalkMessage(WfbcTalkEvent *talk);
int FIELD_WFBC_DATA_LOCAL_FreeTalkMessage(WfbcTalkEvent *talk);
extern const char d_02187EB4[];
extern const MmdlHeader d_02187DBC;
extern const MmdlHeader d_02187DE0;
extern u16 d_02187E04[];

/*
 * extent: two zero alignment bytes after the return.
 */
int FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(const struct Mmdl *mmdl)
{
    return FLDMMDL_GetObjId(mmdl) - 0x80;
}

void FIELD_WFBC_DATA_LOCAL_ClearPeopleList(WfbcData *data)
{
    int i;
    for (i = 0; i < 10; i++)
        EVENT_FIELD_PROCLINK_ClearReturnEntry(&data->people[i]);
}

void FIELD_WFBC_DATA_LOCAL_ClearBackPeopleList(WfbcData *data)
{
    int i;
    for (i = 0; i < 10; i++)
        EVENT_FIELD_PROCLINK_ClearReturnEntry(&data->backPeople[i]);
}

void FIELD_WFBC_DATA_LOCAL_Init(WfbcData *data, const struct MyStatus *myStatus, int heapSeed)
{
    int i;
    int j;
    int roll;
    WfbcNpcRecord *npcRecord;
    int remaining;
    int setParent;
    int npcId;
    WfbcPerson *person;
    WfbcNpcData *npcData;
    int mood;

    data->isValid = 1;
    i = 0;
    data->cityType = 0;
    remaining = 0x1CE;
    data->playerId = func_02008530(myStatus);
    npcData = FIELD_WFBC_DATA_LOCAL_OpenNpcData(0, (u16)((heapSeed & 0x7FFF) | 0x8000));
    FIELD_WFBC_DATA_LOCAL_GetNpcRecord(npcData);
    for (i = 0; i < 10; i++) {
        roll = func_020056EC(remaining);
        person = FIELD_WFBC_DATA_LOCAL_FindEmptyPersonSlot(data->people);
        npcRecord = FIELD_WFBC_DATA_LOCAL_PickNpcByWeight(data, roll, npcData, &npcId);
        if (data->cityType == 0) {
            mood = npcRecord->initialMoodType0;
            setParent = 1;
        } else {
            mood = npcRecord->initialMoodType1;
            setParent = 0;
        }
        FIELD_WFBC_DATA_LOCAL_InitNewPerson(person, (u8)npcId, myStatus, (u16)mood, setParent);
        remaining -= npcRecord->weight;
    }
    for (j = 0; j < 3; j++) {
        roll = func_020056EC(remaining);
        person = FIELD_WFBC_DATA_LOCAL_FindEmptyPersonSlot(data->backPeople);
        npcRecord = FIELD_WFBC_DATA_LOCAL_PickNpcByWeight(data, roll, npcData, &npcId);
        FIELD_WFBC_DATA_LOCAL_InitNewPerson(person, (u8)npcId, myStatus, 0, setParent);
        remaining -= npcRecord->weight;
    }
    FIELD_WFBC_DATA_LOCAL_CloseNpcData(npcData);
}

int FIELD_WFBC_DATA_LOCAL_IsFullyPopulated(WfbcData *data)
{
    WfbcPerson *people;
    int i;
    if (data->isValid == 1 && data->cityType >= 2)
        return 0;
    i = 0;
    people = data->people;
    for (; i < 10; i++)
        if (EVENT_FIELD_PROCLINK_IsReturnEntryAllowed(&people[i]) == 0)
            return 0;
    return 1;
}

void FIELD_WFBC_DATA_LOCAL_Sanitize(WfbcData *data, const struct MyStatus *myStatus)
{
    int i;

    if (data->isValid > 1)
        data->isValid = 1;
    if (data->isValid == 0 && data->cityType != 2)
        data->cityType = 2;
    if (data->isValid == 1 && data->cityType >= 2) {
        int version = func_0200855C(myStatus);
        if (INTRUDE_COMM_NormalizeVersion((u8)version, func_02008530(myStatus)) == 0x15)
            data->cityType = 0;
        else
            data->cityType = 1;
    }
    for (i = 0; i < 10; i++)
        FIELD_WFBC_DATA_LOCAL_ValidatePerson(&data->people[i]);
}

int FIELD_WFBC_DATA_LOCAL_IsDataComplete(WfbcData *data)
{
    if (data->isValid == 0)
        return 0;
    if (FIELD_WFBC_DATA_LOCAL_IsFullyPopulated(data) != 0)
        return 1;
    return 0;
}

int FIELD_WFBC_DATA_LOCAL_CountPeople(const WfbcData *data, int which)
{
    const WfbcPerson *people;
    int i;
    int count;
    if (which == 0)
        people = data->people;
    else
        people = data->backPeople;
    count = 0;
    for (i = 0; i < 10; i++)
        if (EVENT_FIELD_PROCLINK_IsReturnEntryValid(&people[i]))
            count++;
    return count;
}

/*
 * 2026-10-04 (wD3 lane 15): DIFF, 456 bytes (right size), 200 diff bytes, all from one cause. The original spills the
 * GAME_DATA_GetPlayerZoneId result (id) to [sp,#0x14] at once and loads it later for the u16 shift (id16 at sp24); this draft
 * keeps id in r7, so every later slot is one word lower (frame 0x2c vs 0x30). Control flow, the qq/items3 double store
 * and all calls match. Tried: id16, qq, items3 as named locals (current), compiler hoist of (u16)id (slots wrong),
 * u16 callee param for FIELD_WFBC_DATA_LOCAL_SetItemSlotIfEmpty (extra mov). Next: find what makes id spill (a second use of id, decl order).
 *
 * Note 2026-10-05 (wD4 lane12): MATCH, all 456 bytes. Keys: no qq/id16
 * locals (base + 0xF8 and the id conversion are compiler loop hoists, which
 * spills id at once); ZONEDATA_IsZoneInTableDFEC takes u16 and gets id directly; p is set
 * inside the if; the item base is a named items = base + 8 assigned after
 * i = 0; the second loop uses base + 8 + off (hoisted copy-add at sp+0x2c);
 * the random third argument goes through a u16 local v; q[t%3] reads
 * (q + 4)[t % 3]. Only blocker: arm9 callee 0x02013DE0 had no label; filed
 * src/matched/arm9/ZONEDATA_IsZoneInTableDFEC.c (EXACT). EXACT once that has a shard.
 */
void FIELD_WFBC_DATA_LOCAL_AdvanceDays(struct GameData *gameData, int days, u32 heapSeed)
{
    char *base;
    char *items;
    u16 *itemSlots;
    WfbcDailyState *dailyState;
    u32 zoneId;
    u32 backCount;
    int moodDelta;
    char *person;
    int offset;
    int i;
    int j;
    WfbcNpcData *npcData;
    WfbcNpcRecord *npcRecord;
    u32 weightSum;
    u32 pick;

    zoneId = GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(gameData));
    base = (char *)GAME_DATA_GetSecondUnionInfo(gameData);
    itemSlots = GAME_DATA_GetMysteryRecvFlagA(gameData);
    dailyState = GAME_DATA_GetMysteryRecvFlagB(gameData);
    if (days <= 0) {
        days = 1;
    }
    if (days > 21) {
        days = 21;
    }
    backCount = FIELD_WFBC_DATA_LOCAL_CountPeople((WfbcData *)base, 1);
    j = 0;
    moodDelta = (j - 5) * days;
    i = 0;
    items = base + 8;
    for (; i < 10; i++) {
        if (EVENT_FIELD_PROCLINK_IsReturnEntryValid((WfbcPerson *)(items + i * 0x18)) != 0) {
            int reachedZero;
            person = base + i * 0x18;
            person[0xb] = 7;
            reachedZero = FIELD_WFBC_DATA_LOCAL_AddMood((WfbcPerson *)(items + i * 0x18), moodDelta);
            if (reachedZero != 0 && backCount + j >= 10) {
                FIELD_WFBC_DATA_LOCAL_SetMood((WfbcPerson *)(items + i * 0x18), 1);
            } else if (reachedZero != 0) {
                if (ZONEDATA_IsZoneInTableDFEC(zoneId) == 0) {
                    FIELD_WFBC_DATA_LOCAL_PushPersonFront((WfbcPerson *)(base + 0xF8), (WfbcPerson *)(items + i * 0x18));
                    EVENT_FIELD_PROCLINK_ClearReturnEntry((WfbcPerson *)(items + i * 0x18));
                } else {
                    person[0xb] = 1;
                }
                j++;
            }
        }
    }
    i = 0;
    EVENT_FIELD_PROCLINK_CompactReturnList((WfbcData *)base, 0);
    EVENT_FIELD_PROCLINK_InitIdList(itemSlots);
    npcData = FIELD_WFBC_DATA_LOCAL_OpenNpcData(0, (u16)((heapSeed & 0x7FFF) | 0x8000));
    if (((WfbcData *)base)->cityType == 1) {
        for (i = 0; i < 10; i++) {
            char *entry = base + 8 + i * 0x18;
            if (EVENT_FIELD_PROCLINK_IsReturnEntryValid((WfbcPerson *)entry) != 0) {
                FIELD_WFBC_DATA_LOCAL_LoadNpcData(npcData, *(u8 *)(base + i * 0x18 + 9));
                npcRecord = FIELD_WFBC_DATA_LOCAL_GetNpcRecord(npcData);
                if ((u16)func_020056EC(100) < npcRecord->giftChance) {
                    u16 slot = func_020056EC(10);
                    FIELD_WFBC_DATA_LOCAL_SetItemSlotIfEmpty(itemSlots, npcRecord->giftItemId, slot);
                }
            }
        }
        i = 0;
        backCount = FIELD_WFBC_DATA_LOCAL_CountPeople((WfbcData *)base, 0);
        if (backCount != 0) {
            weightSum = 0;
            pick = func_020056EC(backCount * 3);
            for (j = 0; j < 10; j++) {
                offset = j * 0x18;
                if (EVENT_FIELD_PROCLINK_IsReturnEntryValid((WfbcPerson *)(base + 8 + offset)) != 0) {
                    weightSum += 3;
                    if (weightSum > pick) {
                        FIELD_WFBC_DATA_LOCAL_LoadNpcData(npcData, *(u8 *)(base + offset + 9));
                        npcRecord = FIELD_WFBC_DATA_LOCAL_GetNpcRecord(npcData);
                        FIELD_WFBC_DATA_LOCAL_WriteValue(dailyState, (npcRecord->requestIds)[pick % 3]);
                        FIELD_WFBC_DATA_LOCAL_WriteCounter(dailyState, npcRecord->giftItemId);
                        break;
                    }
                }
            }
        }
    }
    FIELD_WFBC_DATA_LOCAL_CloseNpcData(npcData);
}

/*
 * note: 2026-10-05 (wD9r lane166): EXACT. The tests use the items local (items + i * 0x18), the body
 *   calls spell the address again as base + 8 + i * 0x18, as in the matched siblings ov010 02161DC4
 *   and ov020 021862A8 (a = p + 8 for the tests, p + 8 + i * 0x18 for the result). The second spelling
 *   is a separate invariant in the if body; LICM probably hoists it before the (u16)id conversion, so the
 *   items web is a late temp that interferes with id and takes r4 (a0 r4, id r5 as in the image).
 */
void FIELD_WFBC_DATA_LOCAL_MoveBoredPeopleToBackList(struct GameData *gameData)
{
    char *backPeople;
    u32 zoneId;
    char *base;
    char *items;
    u16 key;
    int i;

    zoneId = GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(gameData));
    base = (char *)GAME_DATA_GetSecondUnionInfo(gameData);
    i = 0;
    backPeople = base + 0xF8;
    items = base + 8;
    key = zoneId;
    for (; i < 10; i++) {
        if (EVENT_FIELD_PROCLINK_IsReturnEntryValid((WfbcPerson *)(items + i * 0x18)) != 0 && FIELD_WFBC_DATA_LOCAL_IsMoodZero((WfbcPerson *)(items + i * 0x18)) != 0 && ZONEDATA_IsZoneInTableDFEC(key) == 0) {
            FIELD_WFBC_DATA_LOCAL_PushPersonFront((WfbcPerson *)backPeople, (WfbcPerson *)(base + 8 + i * 0x18));
            EVENT_FIELD_PROCLINK_ClearReturnEntry((WfbcPerson *)(base + 8 + i * 0x18));
        }
    }
    EVENT_FIELD_PROCLINK_CompactReturnList((WfbcData *)base, 0);
}

static inline void FIELD_WFBC_DATA_LOCAL_ClearFlagBits(u8 *flags, unsigned int mask)
{
    unsigned int value = *flags;
    value &= ~mask;
    *flags = value;
}

/*
 * extent: 66 bytes of code followed by two zero alignment bytes.
 * Lever: the inline helper holds the loaded byte in a full-width unsigned
 * local before clearing its bits; the constant argument stays positive
 * and is hoisted to a spill instead of folding to the byte complement.
 */
void FIELD_WFBC_DATA_LOCAL_ApplyTalkedMoodBonus(u8 *data)
{
    int i;
    for (i = 0; i < 10; i++) {
        if (EVENT_FIELD_PROCLINK_IsReturnEntryValid((WfbcPerson *)(data + 8 + i * 0x18)) &&
            (*(u8 *)((unsigned int)data + i * 0x18 + 0xb) & 2)) {
            FIELD_WFBC_DATA_LOCAL_AddMood((WfbcPerson *)(data + 8 + i * 0x18), 3);
            FIELD_WFBC_DATA_LOCAL_ClearFlagBits((u8 *)((unsigned int)data + i * 0x18 + 0xb), 2);
        }
    }
}

void FIELD_WFBC_DATA_LOCAL_InsertPersonForCity(WfbcData *data, const struct MyStatus *myStatus, WfbcPerson *person)
{
    if (data->cityType == 0)
        FIELD_WFBC_DATA_LOCAL_InsertPerson(data, myStatus, person, 1);
    else
        FIELD_WFBC_DATA_LOCAL_InsertPerson(data, myStatus, person, 0);
}

MmdlHeader *FIELD_WFBC_DATA_LOCAL_CreateMmdlHeaders(WfbcData *data, int which, int heapSeed)
{
    int count;
    MmdlHeader *headers;
    WfbcNpcData *npcData;
    WfbcPosition *positions;
    int heapId;
    int total;
    int i;
    WfbcPerson *people;
    WfbcNpcRecord *npcRecord;
    MmdlHeader *header;
    MmdlHeader proto;

    heapId = (u16)((heapSeed & 0x7FFF) | 0x8000);
    total = FIELD_WFBC_DATA_LOCAL_CountPeople(data, which);
    if (total == 0)
        return 0;
    if (which == 0)
        people = data->people;
    else
        people = data->backPeople;
    headers = func_02030734(heapId, total * 0x24, 1, d_02187EB4, 0x2E3);
    count = 0;
    npcData = FIELD_WFBC_DATA_LOCAL_OpenNpcData(0, heapId);
    positions = FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable(npcData, data->cityType, heapId);
    i = 0;
    proto = d_02187DBC;
    for (; i < 10; i++) {
        if (EVENT_FIELD_PROCLINK_IsReturnEntryValid(&people[i])) {
            header = &headers[count];
            *header = proto;
            FIELD_WFBC_DATA_LOCAL_LoadNpcData(npcData, FIELD_WFBC_DATA_LOCAL_GetNpcId(&people[i]));
            npcRecord = FIELD_WFBC_DATA_LOCAL_GetNpcRecord(npcData);
            header->objId = FIELD_WFBC_DATA_LOCAL_GetNpcId(&people[i]) + 0x80;
            header->objCode = npcRecord->objCode;
            header->moveCode = 3;
            if (which == 0) {
                if (data->cityType == 0)
                    header->eventId = npcRecord->eventIds[1];
                else
                    header->eventId = npcRecord->eventIds[0];
            } else {
                if (data->cityType == 0)
                    header->eventId = npcRecord->eventIds[3];
                else
                    header->eventId = npcRecord->eventIds[2];
            }
            FLDMMDL_InitPosRecord(header, positions[i].x, positions[i].z, 0);
            count++;
        }
    }
    FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable(positions);
    FIELD_WFBC_DATA_LOCAL_CloseNpcData(npcData);
    return headers;
}

void FIELD_WFBC_DATA_LOCAL_FillPeopleListEntries(const WfbcData *data, WfbcListEntry *entries, u16 *entryCount, int page, u16 heapId)
{
    unsigned total;
    unsigned limit;
    int first;
    int num;
    int i;
    WfbcNpcData *npcData;
    WfbcNpcRecord *npcRecord;
    const char *pageBase;

    total = FIELD_WFBC_DATA_LOCAL_CountPeople(data, 0);
    first = page * 2;
    limit = first + 2;
    if (limit > total)
        limit = total;
    num = limit - first;
    i = 0;
    npcData = FIELD_WFBC_DATA_LOCAL_OpenNpcData(0, heapId);
    npcRecord = FIELD_WFBC_DATA_LOCAL_GetNpcRecord(npcData);
    *entryCount = 0;
    if (num > 0) {
        pageBase = (const char *)data + first * 0x18;
        do {
            FIELD_WFBC_DATA_LOCAL_LoadNpcData(npcData, (u8)pageBase[i * 0x18 + 9]);
            entries[*entryCount].entryId = npcRecord->listEntryId;
            entries[*entryCount].param = npcRecord->listEntryParam;
            *entryCount = *entryCount + 1;
            i++;
        } while (i < num);
    }
    FIELD_WFBC_DATA_LOCAL_CloseNpcData(npcData);
}

void FIELD_WFBC_DATA_LOCAL_ValidatePerson(WfbcPerson *person)
{
    int i;
    int found;
    u16 eosChar;

    eosChar = STRBUF_GetEosChar();
    if (person->npcId >= 0x1e)
        EVENT_FIELD_PROCLINK_ClearReturnEntry(person);
    if (person->mood > 0x64)
        EVENT_FIELD_PROCLINK_ClearReturnEntry(person);
    if (person->hasParent != 0) {
        found = 0;
        for (i = 0; i < 8; i++) {
            if (eosChar == person->parentName[i])
                found = 1;
        }
        if (found == 0)
            EVENT_FIELD_PROCLINK_ClearReturnEntry(person);
    }
}

/*
 * Lever: raw-byte flag test, then bitfield assignment for the bics clear.
 */
void FIELD_WFBC_DATA_LOCAL_ApplyGiftMoodBonus(WfbcPerson *person) { if (person->flags.all & 4) { FIELD_WFBC_DATA_LOCAL_AddMood(person, 10); person->flags.bits.gift = 0; } }

/*
 * Clear bit 0 of the byte at +3.
 *
 * Addresses are Black-image addresses.
 */
void FIELD_WFBC_DATA_LOCAL_ClearArrivalFlag(WfbcPerson *person)
{
person->flags.bits.arrival = 0;
}

/*
 * Test: is bit 0 of the byte at +3 set.
 *
 * Addresses are Black-image addresses.
 */
int FIELD_WFBC_DATA_LOCAL_HasArrivalFlag(const WfbcPerson *person)
{
return (person->flags.all & 1) != 0;
}

/*
 * Follower 021867A8 is already filed separately; 020084F4 returns its unchanged incoming r0.
 */
void FIELD_WFBC_DATA_LOCAL_SetPersonParent(WfbcPerson *person, const struct MyStatus *myStatus) { person->hasParent = 1; person->parentId = func_02008530(myStatus); MI_CpuCopy8(func_020084F4(myStatus), person->parentName, 16); }

/*
 * Unlabelled leaf (saves nothing, so disasm.py prints it as .word data);
 * filed as the blocker of FIELD_WFBC_DATA_LOCAL_ScrCmdGetWfbcValue (ov020).
 */
int FIELD_WFBC_DATA_LOCAL_HasParent(const WfbcPerson *person)
{
    return person->hasParent;
}

/*
 * Follower 021867B4 is already filed separately.
 */
int FIELD_WFBC_DATA_LOCAL_GetNpcId(const WfbcPerson *person) { return person->npcId; }

int FIELD_WFBC_DATA_LOCAL_IsMoodLow(const WfbcPerson *person)
{
    return person->mood <= 20;
}

WfbcNpcData *FIELD_WFBC_DATA_LOCAL_OpenNpcData(int fileId, int heapId)
{
    WfbcNpcData *npcData = func_02030734(heapId, 0x38, 1, (const char *)&d_02187EB4, 0x448);

    npcData->arc = func_020490F4(0x9a, heapId);
    ARC_TOOL_ReadHandleMember(npcData->arc, fileId, &npcData->record);
    npcData->fileId = fileId;
    return npcData;
}

void FIELD_WFBC_DATA_LOCAL_CloseNpcData(WfbcNpcData *npcData) { ARC_TOOL_DeleteHandle(npcData->arc); func_020307B0(npcData); }

void FIELD_WFBC_DATA_LOCAL_LoadNpcData(WfbcNpcData *npcData, u32 fileId) { ARC_TOOL_ReadHandleMember(npcData->arc, fileId, &npcData->record); npcData->fileId = fileId; }

WfbcNpcRecord *FIELD_WFBC_DATA_LOCAL_GetNpcRecord(WfbcNpcData *npcData)
{
    return &npcData->record;
}

WfbcPosition *FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable(WfbcNpcData *npcData, int cityType, unsigned int heapId)
{
    return ARC_TOOL_LoadHandleMember(npcData->arc, cityType + 0x22, heapId);
}

/*
 * Follower 02186844 is already filed separately.
 */
void FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable(WfbcPosition *positions) { func_020307B0(positions); }

/*
 * Unlabelled leaf: address of the i-th two-byte pair of a table.
 *
 * Addresses are Black-image addresses.
 */
WfbcPosition *FIELD_WFBC_DATA_LOCAL_GetPositionPair(WfbcPosition *positions, int index)
{
    return &positions[index];
}

WfbcPosition *FIELD_WFBC_DATA_LOCAL_GetItemPositionPair(WfbcPosition *positions, int index)
{
    return &positions[index + 10];
}

int FIELD_WFBC_DATA_LOCAL_CountItemSlots(const u16 *itemSlots) { int i; int count; count = 0; for (i = 0; i < 10; i++) { if (itemSlots[i] != 0xFFFF) count++; } return count; }

int FIELD_WFBC_DATA_LOCAL_SetItemSlotIfEmpty(u16 *itemSlots, u16 itemId, int slot) { if (itemSlots[slot] == 0xFFFF) { itemSlots[slot] = itemId; return 1; } return 0; }

u16 FIELD_WFBC_DATA_LOCAL_GetItemSlot(const u16 *itemSlots, int slot)
{
    return itemSlots[slot];
}

int FIELD_WFBC_DATA_LOCAL_IsItemSlotUsed(const u16 *itemSlots, int slot) { if (itemSlots[slot] != 0xFFFF) return 1; return 0; }

MmdlHeader *FIELD_WFBC_DATA_LOCAL_CreateItemMmdlHeaders(u16 *itemSlots, int which, int cityType, int heapSeed)
{
    MmdlHeader *headers;
    WfbcNpcData *npcData;
    WfbcPosition *positions;
    WfbcPosition *position;
    int heapId;
    int total;
    int count;
    MmdlHeader *header;
    int i;
    MmdlHeader proto;

    if (which != 0)
        return 0;
    if (cityType == 0)
        return 0;
    heapId = (u16)((heapSeed & 0x7FFF) | 0x8000);
    total = FIELD_WFBC_DATA_LOCAL_CountItemSlots(itemSlots);
    count = 0;
    headers = func_02030734(heapId, total * 0x24, 1, d_02187EB4, 0x561);
    npcData = FIELD_WFBC_DATA_LOCAL_OpenNpcData(0, heapId);
    positions = FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable(npcData, cityType, heapId);
    i = 0;
    proto = d_02187DE0;
    for (; i < 10; i++) {
        if (FIELD_WFBC_DATA_LOCAL_IsItemSlotUsed(itemSlots, i)) {
            position = FIELD_WFBC_DATA_LOCAL_GetItemPositionPair(positions, i);
            header = &headers[count];
            *header = proto;
            header->objId = i + 0xa0;
            header->eventId = FIELD_WFBC_DATA_LOCAL_GetItemSlot(itemSlots, i);
            header->eventFlag = i + 0xaa0;
            FLDMMDL_InitPosRecord(header, position->x, position->z, 0);
            count++;
        }
    }
    FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable(positions);
    FIELD_WFBC_DATA_LOCAL_CloseNpcData(npcData);
    return headers;
}

u16 FIELD_WFBC_DATA_LOCAL_GetCounter(const WfbcDailyState *dailyState)
{
    return dailyState->counter;
}

void FIELD_WFBC_DATA_LOCAL_IncCounter(WfbcDailyState *dailyState)
{
    dailyState->counter++;
}

u16 FIELD_WFBC_DATA_LOCAL_GetValue(const WfbcDailyState *dailyState)
{
    return dailyState->value;
}

void FIELD_WFBC_DATA_LOCAL_AddValuePoints(WfbcDailyState *dailyState)
{
    if (dailyState->value < 0x2710)
        dailyState->value += 10;
}

u16 FIELD_WFBC_DATA_LOCAL_ReadValue(const WfbcDailyState *dailyState)
{
    return dailyState->value;
}

void FIELD_WFBC_DATA_LOCAL_WriteValue(WfbcDailyState *dailyState, u16 value)
{
    dailyState->value = value;
}

u16 FIELD_WFBC_DATA_LOCAL_ReadCounter(const WfbcDailyState *dailyState)
{
    return dailyState->counter;
}

void FIELD_WFBC_DATA_LOCAL_WriteCounter(WfbcDailyState *dailyState, u16 counter)
{
    dailyState->counter = counter;
}

WfbcNpcRecord *FIELD_WFBC_DATA_LOCAL_PickNpcByWeight(const WfbcData *data, int limit, WfbcNpcData *npcData, int *outNpcId)
{
    WfbcNpcRecord *npcRecord;
    int i;
    u32 weightSum;
    int npcId;

    weightSum = 0;
    npcRecord = FIELD_WFBC_DATA_LOCAL_GetNpcRecord(npcData);
    for (i = 0; i < 30; i++) {
        npcId = FIELD_WFBC_DATA_LOCAL_GetNthAbsentNpcId(data, i);
        FIELD_WFBC_DATA_LOCAL_LoadNpcData(npcData, npcId);
        weightSum += npcRecord->weight;
        if (weightSum > limit) {
            *outNpcId = npcId;
            return npcRecord;
        }
    }
    return npcRecord;
}

int FIELD_WFBC_DATA_LOCAL_GetNthAbsentNpcId(const WfbcData *data, int nth) { int i; int count; count = 0; for (i = 0; i < 30; i++) { if (FIELD_WFBC_DATA_LOCAL_IsNpcPresent(data, i) == 0) { if (count == nth) return i; count++; } } return 0; }

int FIELD_WFBC_DATA_LOCAL_IsNpcPresent(const WfbcData *data, int npcId)
{
    int i;
    const WfbcPerson *backPeople;
    const WfbcPerson *people;

    i = 0;
    people = data->people;
    for (; i < 10; i++) {
        if (EVENT_FIELD_PROCLINK_IsReturnEntryValid(&people[i]) != 0 && data->people[i].npcId == npcId)
            return 1;
    }
    i = 0;
    backPeople = data->backPeople;
    for (; i < 10; i++) {
        if (EVENT_FIELD_PROCLINK_IsReturnEntryValid(&backPeople[i]) != 0 && data->backPeople[i].npcId == npcId)
            return 1;
    }
    return 0;
}

void FIELD_WFBC_DATA_LOCAL_InsertPerson(WfbcData *data, const struct MyStatus *myStatus, WfbcPerson *person, int setParent)
{
    WfbcPerson *front;

    if (FIELD_WFBC_DATA_LOCAL_IsPeopleListFull(data->people) == 1) {
        FIELD_WFBC_DATA_LOCAL_PushPersonFront(data->backPeople, &data->people[9]);
        EVENT_FIELD_PROCLINK_ClearReturnEntry(&data->people[9]);
    }
    front = data->people;
    front = FIELD_WFBC_DATA_LOCAL_PushPersonFront(front, person);
    if (setParent != 0)
        FIELD_WFBC_DATA_LOCAL_SetPersonParent(front, myStatus);
}

int FIELD_WFBC_DATA_LOCAL_IsPeopleListFull(const WfbcPerson *list) { int i; for (i = 0; i < 10; i++) { if (EVENT_FIELD_PROCLINK_IsReturnEntryValid(&list[i]) == 0) return 0; } return 1; }

/*
 * Lever: unsigned index scaling retains separate source/destination multiplies.
 */
WfbcPerson *FIELD_WFBC_DATA_LOCAL_PushPersonFront(WfbcPerson *list, const WfbcPerson *person) { int i; for (i = 9; i > 0; i--) MI_CpuCopy8(&list[(u32)(i - 1)], &list[(u32)i], 24); MI_CpuCopy8(person, list, 24); return list; }

WfbcPerson *FIELD_WFBC_DATA_LOCAL_FindEmptyPersonSlot(WfbcPerson *list)
{
    int i;
    for (i = 0; i < 10; i++) {
        if (EVENT_FIELD_PROCLINK_IsReturnEntryValid(&list[i]) == 0)
            return &list[i];
    }
    return list;
}

/*
 * lever: assign the low bitfield before the byte fields; a later bitfield store changes scheduling.
 */
void FIELD_WFBC_DATA_LOCAL_InitNewPerson(WfbcPerson *person, int npcId, const struct MyStatus *myStatus, int mood, int setParent)
{
    person->isPresent = 1;
    person->npcId = npcId;
    person->flags.all = 7;
    person->mood = mood;
    if (setParent) FIELD_WFBC_DATA_LOCAL_SetPersonParent(person, myStatus);
}

/*
 * extent: two trailing zero alignment bytes.
 */
int FIELD_WFBC_DATA_LOCAL_IsMoodZero(const WfbcPerson *person)
{
    if (person->mood == 0) return 1;
    return 0;
}

int FIELD_WFBC_DATA_LOCAL_AddMood(WfbcPerson *person, int delta)
{
    int reachedZero;
    int sum;
    reachedZero = 0;
    sum = person->mood + delta;
    if (sum > 100) person->mood = 100;
    else if (sum < 0) { person->mood = 0; reachedZero = 1; }
    else person->mood += (u8)delta;
    return reachedZero;
}

void FIELD_WFBC_DATA_LOCAL_SetMood(WfbcPerson *person, int mood)
{
    person->mood = mood;
}

int FIELD_WFBC_DATA_LOCAL_ScrCmdMarkFacingPerson(ScriptVm *vm, struct ScrcmdWork *work)
{
    ScriptFieldParam *fieldParam;
    FieldWfbc *wfbc;
    void *player;
    void *mmdlSystem;
    int personIndex;
    GridCoord frontGrid[3];

    fieldParam = SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(work));
    wfbc = FIELD_G3D_MAPPER_GetWfbc(FIELDMAP_GetG3dMapper(fieldParam->fieldSystem));
    player = FIELDMAP_GetFieldPlayer(fieldParam->fieldSystem);
    mmdlSystem = FIELDMAP_GetMmdlSys(fieldParam->fieldSystem);
    FIELD_PLAYER_GetFrontGridPos(player, &frontGrid[2], &frontGrid[1], &frontGrid[0]);
    personIndex = FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(FLDMMDL_SysSearchGridPos(mmdlSystem, frontGrid[2], frontGrid[0], 0));
    FIELD_WFBC_ApplyGiftMood(wfbc, personIndex);
    return 0;
}

int FIELD_WFBC_DATA_LOCAL_ScrCmdCheckAndMarkFacingPerson(ScriptVm *vm, struct ScrcmdWork *work)
{
    ScriptFieldParam *fieldParam;
    FieldWfbc *wfbc;
    WfbcDailyState *dailyState;
    void *player;
    void *mmdlSystem;
    int personIndex;
    GridCoord frontGrid[3];

    fieldParam = SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(work));
    wfbc = FIELD_G3D_MAPPER_GetWfbc(FIELDMAP_GetG3dMapper(fieldParam->fieldSystem));
    dailyState = GAME_DATA_GetMysteryRecvFlagB(SCRCMD_WORK_GetGameData(work));
    player = FIELDMAP_GetFieldPlayer(fieldParam->fieldSystem);
    mmdlSystem = FIELDMAP_GetMmdlSys(fieldParam->fieldSystem);
    FIELD_PLAYER_GetFrontGridPos(player, &frontGrid[2], &frontGrid[1], &frontGrid[0]);
    personIndex = FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(FLDMMDL_SysSearchGridPos(mmdlSystem, frontGrid[2], frontGrid[0], 0));
    if (FIELD_WFBC_GetPeopleArrivalFlag(wfbc, personIndex) != 0) {
        FIELD_WFBC_ClearPeopleArrivalFlag(wfbc, personIndex);
        FIELD_WFBC_DATA_LOCAL_IncCounter(dailyState);
    }
    return 0;
}

int FIELD_WFBC_DATA_LOCAL_ScrCmdSetFacingPersonParam(ScriptVm *vm, struct ScrcmdWork *work)
{
    ScriptWork *scriptWork;
    ScriptFieldParam *fieldParam;
    FieldWfbc *wfbc;
    void *player;
    void *mmdlSystem;
    void *wordSet;
    int bufIndex;
    int heapId;
    GridCoord frontGrid[3];

    scriptWork = SCRCMD_WORK_GetScriptWork(work);
    fieldParam = SCRIPT_WORK_ResetFieldParam(scriptWork);
    wfbc = FIELD_G3D_MAPPER_GetWfbc(FIELDMAP_GetG3dMapper(fieldParam->fieldSystem));
    player = FIELDMAP_GetFieldPlayer(fieldParam->fieldSystem);
    mmdlSystem = FIELDMAP_GetMmdlSys(fieldParam->fieldSystem);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    bufIndex = SCRIPT_WORK_ReadWorkValue(vm, work);
    heapId = SCRCMD_WORK_GetHeapId(work);
    FIELD_PLAYER_GetFrontGridPos(player, &frontGrid[2], &frontGrid[1], &frontGrid[0]);
    FIELD_WFBC_SetWordSetParentName(wfbc, wordSet, FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(FLDMMDL_SysSearchGridPos(mmdlSystem, frontGrid[2], frontGrid[0], 0)), bufIndex, heapId);
    return 0;
}

int FIELD_WFBC_DATA_LOCAL_ScrCmdGetWfbcValue(ScriptVm *vm, struct ScrcmdWork *work)
{
    int personIndex;
    int mmdlId;
    WfbcPerson *person;
    WfbcNpcRecord *npcRecord;
    FieldWfbcPeople *fieldPerson;
    struct Mmdl *personMmdl;
    FieldWfbc *wfbc;
    struct GameData *gameData;
    WfbcData *data;
    void *player;
    void *mmdlSystem;
    WfbcDailyState *dailyState;
    int query;
    u16 *result;
    ScriptWork *scriptWork;
    ScriptFieldParam *fieldParam;
    GridCoord frontGrid[3];

    scriptWork = SCRCMD_WORK_GetScriptWork(work);
    gameData = SCRCMD_WORK_GetGameData(work);
    data = GAME_DATA_GetSecondUnionInfo(gameData);
    query = SCRIPT_WORK_ReadWorkValue(vm, work);
    result = SCRIPT_WORK_ReadWorkPointer(vm, work);
    if (query == 3) {
        *result = FIELD_WFBC_DATA_LOCAL_CountPeople(data, 0);
    } else {
    fieldParam = SCRIPT_WORK_ResetFieldParam(scriptWork);
    wfbc = FIELD_G3D_MAPPER_GetWfbc(FIELDMAP_GetG3dMapper(fieldParam->fieldSystem));
    player = FIELDMAP_GetFieldPlayer(fieldParam->fieldSystem);
    mmdlSystem = FIELDMAP_GetMmdlSys(fieldParam->fieldSystem);
    dailyState = GAME_DATA_GetMysteryRecvFlagB(gameData);
    FIELD_PLAYER_GetFrontGridPos(player, &frontGrid[2], &frontGrid[1], &frontGrid[0]);
    personMmdl = FLDMMDL_SysSearchGridPos(mmdlSystem, frontGrid[2], frontGrid[0], 0);
    if (personMmdl != 0) {
        personIndex = FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(personMmdl);
        mmdlId = FLDMMDL_GetObjId(personMmdl);
        FIELD_WFBC_ReloadSaveData(wfbc);
        fieldPerson = FIELD_WFBC_GetPeople(wfbc, personIndex);
        if (fieldPerson != 0) {
            npcRecord = FIELD_WFBC_PEOPLE_GetNpcRecord(fieldPerson);
            person = FIELD_WFBC_PEOPLE_GetPersonData(fieldPerson);
        }
    }
    switch (query) {
    case 0:
        *result = npcRecord->queryValue;
        break;
    case 1:
        *result = FIELD_WFBC_DATA_LOCAL_IsMoodLow(person);
        break;
    case 2:
        *result = FIELD_WFBC_DATA_LOCAL_HasParent(person);
        break;
    case 3:
        break;
    case 4:
        *result = FIELD_WFBC_DATA_LOCAL_GetCounter(dailyState);
        break;
    case 5:
        *result = FIELD_WFBC_DATA_LOCAL_GetValue(dailyState);
        break;
    case 6:
        if (FIELD_WFBC_GetPeopleNum(wfbc) == 0)
            *result = 0;
        else
            *result = 1;
        break;
    case 7:
        *result = FIELD_WFBC_DATA_LOCAL_ReadCounter(dailyState);
        break;
    case 8:
        *result = FIELD_WFBC_DATA_LOCAL_ReadValue(dailyState);
        break;
    case 9:
        *result = personIndex;
        break;
    case 10:
        *result = FIELD_WFBC_GetPeopleArrivalFlag(wfbc, personIndex);
        break;
    case 11:
        *result = mmdlId;
        break;
    }
    }
    return 0;
}

/*
 * extent: two trailing zero alignment bytes.
 * interface: 020127F0's body loads only r0, forwarding r0 through 0200A864/0200A898.
 */
int FIELD_WFBC_DATA_LOCAL_ScrCmdAddPoints(ScriptVm *vm, struct ScrcmdWork *work)
{
    FIELD_WFBC_DATA_LOCAL_AddValuePoints(GAME_DATA_GetMysteryRecvFlagB(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(work))->fieldSystem))));
    return 0;
}

int FIELD_WFBC_DATA_LOCAL_ScrCmdFindTargetPokemonInParty(ScriptVm *vm, struct ScrcmdWork *work)
{
    void *s;
    void *w;
    void *b;
    u16 *f0;
    u16 *f1;
    u16 *f2;
    u32 n;
    int key;
    int d[4];
    u32 i;
    void *e;
    int v5, v92, v93, v94, v96, v4c, v8f, v90, v91;

    (void *)SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)(((void *)work)));
    s = (void *)SCRCMD_WORK_GetGameData((struct ScrcmdWork *)(((void *)work)));
    (u8 *)GAME_DATA_GetSecondUnionInfo((struct GameData *)(s));
    w = (void *)(int)GAME_DATA_GetMysteryRecvFlagB((struct GameData *)((int)s));
    b = GAME_DATA_GetMyParty(s);
    f0 = SCRIPT_WORK_ReadWorkPointer((ScriptVm *)(((void *)vm)), (struct ScrcmdWork *)(((void *)work)));
    f1 = SCRIPT_WORK_ReadWorkPointer((ScriptVm *)(((void *)vm)), (struct ScrcmdWork *)(((void *)work)));
    f2 = SCRIPT_WORK_ReadWorkPointer((ScriptVm *)(((void *)vm)), (struct ScrcmdWork *)(((void *)work)));
    n = POKEPARTY_GetCount(b);
    key = FIELD_WFBC_DATA_LOCAL_ReadValue((const WfbcDailyState *)(w));
    GF_STANDARD_SetField00_F4E4((struct RtcDate *)d);
    *f0 = 0;
    *f1 = 0;
    *f2 = 0xFFFF;
    for (i = 0; i < n; i++) {
        e = POKEPARTY_GetMember(b, i);
        v5 = POKE_TOOL_GetPartyValue(e, 5, 0);
        v92 = POKE_TOOL_GetPartyValue(e, 0x92, 0);
        v93 = POKE_TOOL_GetPartyValue(e, 0x93, 0);
        v94 = POKE_TOOL_GetPartyValue(e, 0x94, 0);
        v96 = POKE_TOOL_GetPartyValue(e, 0x96, 0);
        v4c = POKE_TOOL_GetPartyValue(e, 0x4c, 0);
        v8f = POKE_TOOL_GetPartyValue(e, 0x8f, 0);
        v90 = POKE_TOOL_GetPartyValue(e, 0x90, 0);
        v91 = POKE_TOOL_GetPartyValue(e, 0x91, 0);
        if (v5 == key && v4c == 0 && v96 == 0x33 && v8f + v91 + v90 == 0) {
            *f0 = 1;
            if (*f2 == 0xFFFF)
                *f2 = i;
            if (v92 == d[0] && v93 == d[1] && v94 == d[2]) {
                *f1 = 1;
                *f2 = i;
            }
        }
    }
    return 0;
}

int FIELD_WFBC_DATA_LOCAL_ScrCmdGetFacingPersonMessageIndex(ScriptVm *vm, struct ScrcmdWork *work)
{
    ScriptWork *scriptWork;
    ScriptFieldParam *fieldParam;
    FieldWfbc *wfbc;
    void *player;
    void *mmdlSystem;
    u16 *result;
    int messageOffset;
    int personIndex;
    GridCoord frontGrid[3];

    scriptWork = SCRCMD_WORK_GetScriptWork(work);
    fieldParam = SCRIPT_WORK_ResetFieldParam(scriptWork);
    wfbc = FIELD_G3D_MAPPER_GetWfbc(FIELDMAP_GetG3dMapper(fieldParam->fieldSystem));
    player = FIELDMAP_GetFieldPlayer(fieldParam->fieldSystem);
    mmdlSystem = FIELDMAP_GetMmdlSys(fieldParam->fieldSystem);
    SCRIPT_WORK_GetWordSet(scriptWork);
    result = SCRIPT_WORK_ReadWorkPointer(vm, work);
    messageOffset = SCRIPT_WORK_ReadWorkValue(vm, work);
    FIELD_PLAYER_GetFrontGridPos(player, &frontGrid[2], &frontGrid[1], &frontGrid[0]);
    personIndex = FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(FLDMMDL_SysSearchGridPos(mmdlSystem, frontGrid[2], frontGrid[0], 0));
    messageOffset = (u16)(messageOffset - 1);
    if (FIELD_WFBC_GetCityType(wfbc) == 0)
        *result = messageOffset + (personIndex * 4 + 1);
    else
        *result = messageOffset + (personIndex * 4 + 9);
    return 0;
}

int FIELD_WFBC_DATA_LOCAL_ScrCmdCallPersonTalkEvent(ScriptVm *vm, struct ScrcmdWork *work)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    scriptWork = SCRCMD_WORK_GetScriptWork(work);
    gameSystem = SCRCMD_WORK_GetGameSystem(work);
    SCRIPT_SYS_CallEvent(scriptWork, FIELD_WFBC_DATA_LOCAL_CreatePersonTalkEvent(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem)));
    return 1;
}

struct GameEvent *FIELD_WFBC_DATA_LOCAL_CreatePersonTalkEvent(struct GameSystem *gameSystem, void *fieldSystem)
{
    int heapId;
    int msgBgSys;
    struct GameData *gameData;
    void *returnList;
    struct GameEvent *event;
    void *player;
    GridCoord frontGrid[3];
    WfbcTalkEvent *work;
    FieldWfbc *wfbc;
    void *mmdlSystem;
    struct Mmdl *personMmdl;
    int personIndex;
    FieldWfbcPeople *personRecord;

    heapId = FIELDMAP_GetHeapId(fieldSystem);
    msgBgSys = FIELDMAP_GetMsgBg(fieldSystem);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    returnList = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(gameSystem));
    if (returnList == 0)
        return 0;
    returnList = INTRUDE_COMM_GetReturnSlots(returnList);
    event = func_020122C0(gameSystem, 0, FIELD_WFBC_DATA_LOCAL_PersonTalkEventMain, 0x58);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldSystem = fieldSystem;
    work->msgBuf = STRBUF_Create(0x100, heapId);
    work->tmpBuf = STRBUF_Create(0x100, heapId);
    work->msgData = func_02045B38(0, 3, 0x142, heapId);
    work->wordSet = GF_FONT_Create_EC64(heapId);
    work->msgBgSys = msgBgSys;
    work->returnList = returnList;
    work->firstTalk = 1;
    work->heapId = (heapId & 0x7FFF) | 0x8000;
    work->ownData = func_020127D0(gameData, 1);
    work->cityData = func_020127D0(gameData, 0);
    wfbc = FIELD_G3D_MAPPER_GetWfbc(FIELDMAP_GetG3dMapper(fieldSystem));
    player = FIELDMAP_GetFieldPlayer(fieldSystem);
    mmdlSystem = FIELDMAP_GetMmdlSys(fieldSystem);
    GAME_DATA_GetMysteryRecvFlagB(GAMESYSTEM_GetGameData(gameSystem));
    FIELD_PLAYER_GetFrontGridPos(player, &frontGrid[2], &frontGrid[1], &frontGrid[0]);
    personMmdl = FLDMMDL_SysSearchGridPos(mmdlSystem, frontGrid[2], frontGrid[0], 0);
    FLDMMDL_GetPos(personMmdl, (struct VecFx32 *)work->playerPos);
    personIndex = FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(personMmdl);
    personRecord = FIELD_WFBC_GetPeople(wfbc, personIndex);
    work->wfbcRuntime = wfbc;
    work->personRecord = personRecord;
    work->personMmdl = personMmdl;
    work->personIndex = personIndex;
    return event;
}

/*
 * The step callback FIELD_WFBC_DATA_LOCAL_CreatePersonTalkEvent registers (func_020122C0's third
 * argument) for the 0x58-byte work block it fills.
 */
int FIELD_WFBC_DATA_LOCAL_PersonTalkEventMain(struct GameEvent *event, int *state, WfbcTalkEvent *talk)
{
    if (INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(talk->gameSystem)) == 0 && talk->firstTalk != 0)
        *state = 0x11;

    switch (*state) {
    case 0:
        EVENT_FIELD_PROCLINK_ClearReturnDefaultAndPending(talk->returnList);
        EVENT_FIELD_PROCLINK_RequestReturn(talk->returnList, talk->personIndex, 0);
        *state = 1;
        break;
    case 1:
        if (EVENT_FIELD_PROCLINK_HasReturnDefaultSlot(talk->returnList, talk->personIndex) == 0)
            break;
        if (EVENT_FIELD_PROCLINK_GetReturnDefaultSlotType(talk->returnList) == 0)
            *state = 3;
        else
            *state = 2;
        break;
    case 2:
        FIELD_WFBC_DATA_LOCAL_StartTalkMessage(talk, 0, state, 0x11);
        break;
    case 3:
        if (talk->ownData->cityType != talk->cityData->cityType)
            *state = 5;
        else
            *state = 4;
        break;
    case 4:
        FIELD_WFBC_DATA_LOCAL_StartTalkMessage(talk, 1, state, 0x11);
        break;
    case 5:
        if ((unsigned int)FIELD_WFBC_DATA_LOCAL_CountPeople(talk->ownData, 0) >= 10) {
            *state = 6;
            break;
        }
        if (EVENT_FIELD_PROCLINK_HasEventdataEntry(talk->ownData, talk->personIndex, 2) != 0)
            *state = 6;
        else
            *state = 7;
        break;
    case 6:
        FIELD_WFBC_DATA_LOCAL_StartTalkMessage(talk, 2, state, 0x11);
        break;
    case 7:
        FIELD_WFBC_DATA_LOCAL_StartTalkMessageWithChoice(talk, 3, state, 9, 8);
        break;
    case 8:
        FIELD_WFBC_DATA_LOCAL_StartTalkMessage(talk, 4, state, 0x11);
        break;
    case 9:
        EVENT_FIELD_PROCLINK_ClearReturnDefaultAndPending(talk->returnList);
        EVENT_FIELD_PROCLINK_RequestReturn(talk->returnList, talk->personIndex, 1);
        *state = 10;
        break;
    case 10:
        if (EVENT_FIELD_PROCLINK_HasReturnDefaultSlot(talk->returnList, talk->personIndex) == 0)
            break;
        if (EVENT_FIELD_PROCLINK_GetReturnDefaultSlotType(talk->returnList) == 2)
            *state = 12;
        else
            *state = 11;
        break;
    case 11:
        talk->firstTalk = 0;
        FIELD_WFBC_DATA_LOCAL_StartTalkMessage(talk, 5, state, 0x11);
        break;
    case 12:
        FIELD_WFBC_DATA_LOCAL_StartTalkMessage(talk, 7, state, 0xd);
        EVENT_FIELD_PROCLINK_ClearReturnDefaultAndPending(talk->returnList);
        EVENT_FIELD_PROCLINK_RequestReturn(talk->returnList, talk->personIndex, 2);
        talk->firstTalk = 0;
        break;
    case 13:
        FADE_Start(1, 0, 0x10, 0);
        *state = 14;
        break;
    case 14:
        if (FADE_IsActive() != 0)
            break;
        EVENT_FIELD_PROCLINK_ApplyReturnEntry(talk->returnList, talk->ownData, talk->cityData, GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(talk->gameSystem)), talk->personIndex, talk->heapId);
        FIELD_WFBC_RemovePeople(talk->wfbcRuntime, talk->personIndex);
        FLDMMDL_DeleteMmdl(talk->personMmdl);
        FADE_Start(1, 0x10, 0, 0);
        *state = 15;
        break;
    case 15:
        if (FADE_IsActive() != 0)
            break;
        *state = 0x11;
        break;
    case 16:
        if (FIELD_WFBC_DATA_LOCAL_UpdateTalkMessage(talk) == 0)
            break;
        if (talk->answerYes)
            *state = talk->yesState;
        else
            *state = talk->noState;
        break;
    case 17:
        if (FIELD_WFBC_DATA_LOCAL_FreeTalkMessage(talk) == 0)
            break;
        STRBUF_Delete(talk->msgBuf);
        STRBUF_Delete(talk->tmpBuf);
        MSGDATA_Delete(talk->msgData);
        WORDSET_DeleteStrbufED04(talk->wordSet);
        return 1;
    }
    return 0;
}

void FIELD_WFBC_DATA_LOCAL_StartTalkMessage(WfbcTalkEvent *talk, int messageSlot, int *state, int nextState)
{
    int zero;

    MSGDATA_ReadString(talk->msgData,
                  (u16)(messageSlot + (d_02187E04[talk->cityData->cityType] + talk->personIndex * 8)),
                  talk->tmpBuf);
    WORDSET_CopyTaggedText(talk->wordSet, talk->msgBuf, talk->tmpBuf);
    zero = 0;
    talk->msgHandle = FIELD_MSGBG_AddTalkWin(talk->msgBgSys, 2, talk->playerPos, talk->msgBuf, zero, zero);
    *state = 0x10;
    talk->yesState = nextState;
    talk->msgState = 0;
    talk->answerYes = 1;
    talk->askYesNo = 0;
}

void FIELD_WFBC_DATA_LOCAL_StartTalkMessageWithChoice(WfbcTalkEvent *talk, int messageSlot, int *state, int yesStateId, u16 noStateId)
{
    int zero;

    MSGDATA_ReadString(talk->msgData,
                  (u16)(messageSlot + (d_02187E04[talk->cityData->cityType] + talk->personIndex * 8)),
                  talk->tmpBuf);
    WORDSET_CopyTaggedText(talk->wordSet, talk->msgBuf, talk->tmpBuf);
    zero = 0;
    talk->msgHandle = FIELD_MSGBG_AddTalkWin(talk->msgBgSys, 2, talk->playerPos, talk->msgBuf, zero, zero);
    *state = 0x10;
    talk->yesState = yesStateId;
    talk->noState = noStateId;
    talk->msgState = 0;
    talk->answerYes = 1;
    talk->askYesNo = 1;
}

int FIELD_WFBC_DATA_LOCAL_UpdateTalkMessage(WfbcTalkEvent *talk)
{
    int answer;

    switch (talk->msgState) {
    case 0:
        if (FIELD_MSGBG_TalkWinMain(talk->msgHandle) == 0)
            break;
        talk->msgState = talk->msgState + 1;
        break;
    case 1:
        if ((KEY_GetTrg() & 0xf3) == 0)
            break;
        if (talk->askYesNo == 0)
            talk->msgState = 4;
        else
            talk->msgState = 2;
        break;
    case 2:
        talk->yesNoHandle = FIELD_MSGBG_CreateYesNoMenu(talk->msgBgSys, 0);
        talk->msgState = talk->msgState + 1;
        break;
    case 3:
        answer = FIELD_MSGBG_YesNoMenuMain(talk->yesNoHandle);
        if (answer == 2)
            break;
        if (answer == 0)
            talk->answerYes = 1;
        else
            talk->answerYes = 0;
        talk->msgState = 4;
        FIELD_MSGBG_DeleteMenuFunc(talk->yesNoHandle);
        talk->yesNoHandle = 0;
        break;
    case 4:
        FIELD_MSGBG_DeleteTalkWin(talk->msgHandle);
        talk->msgState = talk->msgState + 1;
        break;
    case 5:
        if (FIELD_MSGBG_WaitTalkWinClose(talk->msgHandle) != 0) {
            talk->msgHandle = 0;
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * lever: duplicate the zero store in both arms to retain the original branch stub.
 * regargs: high r2/r3 rows are conservative SDK-depth flags in owner callee 0219131C.
 * interface: 0219131C forwards them to 02045808 -> 020307B0 only; 0203046C
 * overwrites r2/r3, while 02030164's 0202FBAC overwrites r2 and no path reads incoming r3.
 */
int FIELD_WFBC_DATA_LOCAL_FreeTalkMessage(WfbcTalkEvent *talk)
{
    if (talk->msgHandle != 0) {
        if (talk->msgState == 5) {
            if (FIELD_MSGBG_WaitTalkWinClose(talk->msgHandle) == 0) return 0;
            talk->msgHandle = 0;
        } else {
            FIELD_MSGBG_ClearTalkWin(talk->msgHandle);
            talk->msgHandle = 0;
        }
    }
    if (talk->yesNoHandle != 0) {
        FIELD_MSGBG_DeleteMenuFunc(talk->yesNoHandle);
        talk->yesNoHandle = 0;
    }
    return 1;
}
