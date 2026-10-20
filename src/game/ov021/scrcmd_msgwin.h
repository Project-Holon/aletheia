#ifndef GAME_OV021_SCRCMD_MSGWIN_H
#define GAME_OV021_SCRCMD_MSGWIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_msgwin.c, prototypes copied from their definitions. */

struct ScrcmdWork;
struct ScriptCheckTask;
struct G3dCamera;
typedef struct ScrcmdWork ScrcmdWork;
typedef struct ScriptCheckTask ScriptCheckTask;
typedef struct G3dCamera G3dCamera;

#include "../ov020/event_mapchange_types.h"
#include "../types.h"
#include "../arm9/script_vm_types.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"
#include "../ov021/field_camera_types.h"
#include "../ov010/fldmmdl_types.h"
#include "../ov021/field_msgbg_types.h"
#include "../arm9/strbuf_types.h"
#include "../ov010/script_work_types.h"

int SCRCMD_MSGWIN_YesNoEventMain(GameEvent *event, int *seq, void *work);
GameEvent *SCRCMD_MSGWIN_CreateYesNoEvent(GameSystem *gameSystem, ScrcmdWork *cmdWork, u16 *result);
int SCRCMD_MSGWIN_CmdYesNoWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_MenuEventMain(GameEvent *event, int *seq, void *work);
GameEvent *SCRCMD_MSGWIN_CreateMenuEvent(GameSystem *gameSystem, ScrcmdWork *cmdWork, int allowCancel);
int SCRCMD_MSGWIN_CmdInitMenu(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdInitMenuMsgData(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdInitMenuMsgDataMode1(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdAddMenuItem(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdStartMenu(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdStartMenuEx(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_MSGWIN_OpenInfoSysWin(ScrcmdWork *cmdWork, u32 windowKind);
void SCRCMD_MSGWIN_CloseInfoSysWin(ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_WaitInfoSysWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdInfoSysWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdInfoSysWinMsgNow(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdSetTimeIcon(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdCloseInfoSysWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CleanupInfoSysWin(ScriptCheckTask *task, int *state);
int SCRCMD_MSGWIN_CmdOpenMoneyWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdUpdateMoneyWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdCloseMoneyWin(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_MSGWIN_CalcBalloonOffset(const VecFx32 *mmdlPos, VecFx32 *out, G3dCamera *camera, FieldCamera *fieldCamera);
void SCRCMD_MSGWIN_RotateOffsetByCamera(VecFx32 *offset, G3dCamera *camera);
void SCRCMD_MSGWIN_SelectBalloonOffset(const VecFx32 *mmdlPos, VecFx32 *out, G3dCamera *camera, FieldCamera *fieldCamera, u8 windowKind);
void SCRCMD_MSGWIN_GetBalloonOffset(const VecFx32 *mmdlPos, VecFx32 *out, G3dCamera *camera, FieldCamera *fieldCamera, u8 windowKind);
void SCRCMD_MSGWIN_GetBalloonTailParams(int windowState, int *talkIndex, int *tailType);
int SCRCMD_MSGWIN_GetBalloonSide(Mmdl *playerMmdl, const VecFx32 *targetPos);
int SCRCMD_MSGWIN_WaitTalkWinClose(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_MSGWIN_StartCloseTalkWin(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_MSGWIN_CloseTalkWin(ScrcmdWork *cmdWork);
void SCRCMD_MSGWIN_OpenTalkWin(ScrcmdWork *cmdWork, FieldMsgBg *msgBg, int talkIndex, VecFx32 *pos, Strbuf *str, u32 winType, u32 tailType);
void SCRCMD_MSGWIN_UpdateBalloonPos(ScrcmdWork *cmdWork, int forceUpdate);
int SCRCMD_MSGWIN_OpenBalloonWinMsg(ScrcmdWork *cmdWork, u16 objId, u16 msgFileId, u16 msgId, u16 windowKind, int winType);
int SCRCMD_MSGWIN_WaitBalloonWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdBalloonWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdBalloonWinMsgTarget(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdBalloonWinMsgGender(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdBalloonWinMsgSkipArg(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdCloseTalkWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CleanupTalkWin(ScriptCheckTask *task, int *state);
int SCRCMD_MSGWIN_CmdBalloonWinSavedText(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_WaitPlainWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_OpenPlainWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork, int winType);
void SCRCMD_MSGWIN_ClosePlainWin(ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdPlainWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdPlainWinMsgFrame1(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdClosePlainWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CleanupPlainWin(ScriptCheckTask *task, int *state);
int SCRCMD_MSGWIN_CmdAddSubWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdDeleteSubWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_MSGWIN_DeleteAllSubWins(ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CleanupSubWins(ScriptCheckTask *task, int *state);
int SCRCMD_MSGWIN_WaitBgWin(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_MSGWIN_CloseBgWin(ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdBgWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdBgWinMsgFont(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdCloseBgWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CleanupBgWin(ScriptCheckTask *task, int *state);
void SCRCMD_MSGWIN_CloseSpWin(ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_WaitSpWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdSpWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdCloseSpWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CleanupSpWin(ScriptCheckTask *task, int *state);
int SCRCMD_MSGWIN_CmdCloseAllWins(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_WaitKeyWithCursor(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdWaitMsgKey(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdSetAutoMode(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CleanupAutoMode(ScriptCheckTask *task, int *state);
Strbuf *SCRCMD_MSGWIN_ExpandMessage(ScrcmdWork *cmdWork, ScriptWork *scriptWork, u32 msgId);
/* END mkheaders: generated region */

#endif
