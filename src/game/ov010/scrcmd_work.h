#ifndef GAME_OV010_SCRCMD_WORK_H
#define GAME_OV010_SCRCMD_WORK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_work.c, prototypes copied from their definitions. */

struct ScrcmdCommonWork;
struct ScriptWork;
struct ScrcmdWork;
struct ScrcmdWorkParam;
struct GameSystem;
struct GameData;
struct MmdlSys;
struct MsgBank;
struct TcbTask;
struct WordSet;
struct Strbuf;
struct ScrcmdMenu;
struct BmpMenuList;
struct ScriptVm;
typedef struct ScrcmdCommonWork ScrcmdCommonWork;
typedef struct ScrcmdWork ScrcmdWork;
typedef struct ScrcmdWorkParam ScrcmdWorkParam;
typedef struct ScrcmdMenu ScrcmdMenu;

#include "../types.h"

ScrcmdCommonWork *SCRCMD_WORK_CreateCommon(struct ScriptWork *scriptWork, int heapId);
void SCRCMD_WORK_DeleteCommon(ScrcmdCommonWork *common);
ScrcmdWork *SCRCMD_WORK_Create(const ScrcmdWorkParam *param, int heapId);
void SCRCMD_WORK_Delete(ScrcmdWork *work);
u16 SCRCMD_WORK_GetHeapId(ScrcmdWork *work);
u16 SCRCMD_WORK_GetScriptId(ScrcmdWork *work);
u32 SCRCMD_WORK_GetCallMode(ScrcmdWork *work);
u32 SCRCMD_WORK_GetCallParam(ScrcmdWork *work);
struct GameSystem *SCRCMD_WORK_GetGameSystem(ScrcmdWork *work);
struct GameData *SCRCMD_WORK_GetGameData(ScrcmdWork *work);
struct MmdlSys *SCRCMD_WORK_GetMmdlSys(ScrcmdWork *work);
struct ScriptWork *SCRCMD_WORK_GetScriptWork(ScrcmdWork *work);
void *SCRCMD_WORK_GetMenuHeap(ScrcmdWork *work);
struct MsgBank *SCRCMD_WORK_GetMsgData(ScrcmdWork *work);
u16 SCRCMD_WORK_GetMsgDataId(ScrcmdWork *work);
void SCRCMD_WORK_SetMsgWindow(ScrcmdWork *work, void *window);
void *SCRCMD_WORK_GetMsgWindow(ScrcmdWork *work);
void SCRCMD_WORK_SetTimeIcon(ScrcmdWork *work, void *window);
void *SCRCMD_WORK_GetTimeIcon(ScrcmdWork *work);
u8 *SCRCMD_WORK_GetWordSetWork(ScrcmdWork *work);
void SCRCMD_WORK_SetTargetObject(ScrcmdWork *work, void *object);
void *SCRCMD_WORK_GetTargetObject(ScrcmdWork *work);
u32 SCRCMD_WORK_GetWindowState(ScrcmdWork *work);
void SCRCMD_WORK_SetWindowState(ScrcmdWork *work, u32 state);
u8 SCRCMD_WORK_GetWindowKind(ScrcmdWork *work);
void SCRCMD_WORK_SetWindowKind(ScrcmdWork *work, u8 kind);
void SCRCMD_WORK_SetWaitCount(ScrcmdWork *work, unsigned short count);
int SCRCMD_WORK_CountDownWait(ScrcmdWork *work);
int SCRCMD_WORK_GetFadeParam(ScrcmdWork *work);
void SCRCMD_WORK_SetFadeParam(ScrcmdWork *work, int param);
void *SCRCMD_WORK_GetFadeState(ScrcmdWork *work);
void SCRCMD_WORK_SetFadeState(ScrcmdWork *work, void *state);
void SCRCMD_WORK_AddAnimeTask(ScrcmdWork *work, struct TcbTask *task);
u32 SCRCMD_WORK_CheckAnimeTasks(ScrcmdWork *work);
void SCRCMD_WORK_DeleteAnimeTasks(ScrcmdWork *work);
void SCRCMD_WORK_LoadMsgData(ScrcmdWork *work, unsigned arcId, unsigned fileId);
void SCRCMD_WORK_InitMenu(ScrcmdWork *work, unsigned short x, unsigned short y, unsigned short cursorPos, unsigned short cancelable, int alignRight, u16 *result, struct WordSet *wordSet, struct MsgBank *msgData);
void SCRCMD_WORK_AddMenuItem(ScrcmdWork *work, int msgId, int helpMsgId, int param, struct Strbuf *str, struct Strbuf *tmp);
void SCRCMD_WORK_StartMenu(ScrcmdWork *work);
void SCRCMD_WORK_DeleteMenu(ScrcmdMenu *menu);
int SCRCMD_WORK_WaitMenu(ScrcmdWork *work);
int SCRCMD_WORK_WaitMenuOrCancel(ScrcmdWork *work);
void SCRCMD_WORK_MenuCursorCallback(struct BmpMenuList *list);
void SCRCMD_WORK_SaveScriptState(ScrcmdWork *work);
void SCRCMD_WORK_RestoreScriptState(ScrcmdWork *work);
void SCRCMD_WORK_SetChildScriptIndex(ScrcmdWork *work, int index);
u8 SCRCMD_WORK_GetChildScriptIndex(ScrcmdWork *work);
int SCRCMD_WORK_CmdGetRomVersion(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdToggleConfigFlag(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetConfigFlag(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetRandom(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetMsgDataId(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetTrainerCardStars(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetTimeZone(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetWeek(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetMonthAndDay(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetHourAndMinute(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetSeason(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetBirthday(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetPlayerSex(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdCheckBadge(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdSetBadge(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetBadgeCount(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetSaveStatus(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetScriptId(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdSetWarpDestination(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdSetSpecialLocationHere(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdSetSpecialLocation(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdSetMapReplaceFlag(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdCheckMapReplaceFlag(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdRegisterZukanSeen(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdCheckZukanSeenOrCaught(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetNationalZukanCount(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdEnableNationalDex(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetZukanNationalFlag(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdSetZukanObtained(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetButtonMode(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdSetFixedEventFlag(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdSetBoxFlags(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetTrainerViewGroupAndMarkSeen(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdGetMiscByte(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdSetMiscByte(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdCheckMiscByte(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdCheckExtraSaveData(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdSetBgEventGridPos(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdSetConnectGridPos(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdSetNpcGridPos(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdSetTrainerDefeatedFlag(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdClearTrainerDefeatedFlag(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdCheckTrainerDefeatedFlag(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdEndScriptStartCommProcA(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdCheckLastBattleResultA(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdEndScriptStartCommProcB(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdCheckLastBattleResultB(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_WORK_CmdLookupTable(struct ScriptVm *vm, ScrcmdWork *work);
/* END mkheaders: generated region */

#endif
