/*
 * file:     scrcmd_msgwin.c
 * unit:     yes
 * function: SCRCMD_MSGWIN_YesNoEventMain, SCRCMD_MSGWIN_CreateYesNoEvent, SCRCMD_MSGWIN_CmdYesNoWin, SCRCMD_MSGWIN_MenuEventMain, SCRCMD_MSGWIN_CreateMenuEvent, SCRCMD_MSGWIN_CmdInitMenu, SCRCMD_MSGWIN_CmdInitMenuMsgData, SCRCMD_MSGWIN_CmdInitMenuMsgDataMode1, SCRCMD_MSGWIN_CmdAddMenuItem, SCRCMD_MSGWIN_CmdStartMenu, SCRCMD_MSGWIN_CmdStartMenuEx, SCRCMD_MSGWIN_OpenInfoSysWin, SCRCMD_MSGWIN_CloseInfoSysWin, SCRCMD_MSGWIN_WaitInfoSysWin, SCRCMD_MSGWIN_CmdInfoSysWinMsg, SCRCMD_MSGWIN_CmdInfoSysWinMsgNow, SCRCMD_MSGWIN_CmdSetTimeIcon, SCRCMD_MSGWIN_CmdCloseInfoSysWin, SCRCMD_MSGWIN_CleanupInfoSysWin, SCRCMD_MSGWIN_CmdOpenMoneyWin, SCRCMD_MSGWIN_CmdUpdateMoneyWin, SCRCMD_MSGWIN_CmdCloseMoneyWin, SCRCMD_MSGWIN_CalcBalloonOffset, SCRCMD_MSGWIN_RotateOffsetByCamera, SCRCMD_MSGWIN_SelectBalloonOffset, SCRCMD_MSGWIN_GetBalloonOffset, SCRCMD_MSGWIN_GetBalloonTailParams, SCRCMD_MSGWIN_GetBalloonSide, SCRCMD_MSGWIN_WaitTalkWinClose, SCRCMD_MSGWIN_StartCloseTalkWin, SCRCMD_MSGWIN_CloseTalkWin, SCRCMD_MSGWIN_OpenTalkWin, SCRCMD_MSGWIN_UpdateBalloonPos, SCRCMD_MSGWIN_OpenBalloonWinMsg, SCRCMD_MSGWIN_WaitBalloonWin, SCRCMD_MSGWIN_CmdBalloonWinMsg, SCRCMD_MSGWIN_CmdBalloonWinMsgTarget, SCRCMD_MSGWIN_CmdBalloonWinMsgGender, SCRCMD_MSGWIN_CmdBalloonWinMsgSkipArg, SCRCMD_MSGWIN_CmdCloseTalkWin, SCRCMD_MSGWIN_CleanupTalkWin, SCRCMD_MSGWIN_CmdBalloonWinSavedText, SCRCMD_MSGWIN_WaitPlainWin, SCRCMD_MSGWIN_OpenPlainWinMsg, SCRCMD_MSGWIN_ClosePlainWin, SCRCMD_MSGWIN_CmdPlainWinMsg, SCRCMD_MSGWIN_CmdPlainWinMsgFrame1, SCRCMD_MSGWIN_CmdClosePlainWin, SCRCMD_MSGWIN_CleanupPlainWin, SCRCMD_MSGWIN_CmdAddSubWinMsg, SCRCMD_MSGWIN_CmdDeleteSubWinMsg, SCRCMD_MSGWIN_DeleteAllSubWins, SCRCMD_MSGWIN_CleanupSubWins, SCRCMD_MSGWIN_WaitBgWin, SCRCMD_MSGWIN_CloseBgWin, SCRCMD_MSGWIN_CmdBgWinMsg, SCRCMD_MSGWIN_CmdBgWinMsgFont, SCRCMD_MSGWIN_CmdCloseBgWin, SCRCMD_MSGWIN_CleanupBgWin, SCRCMD_MSGWIN_CloseSpWin, SCRCMD_MSGWIN_WaitSpWin, SCRCMD_MSGWIN_CmdSpWinMsg, SCRCMD_MSGWIN_CmdCloseSpWin, SCRCMD_MSGWIN_CleanupSpWin, SCRCMD_MSGWIN_CmdCloseAllWins, SCRCMD_MSGWIN_WaitKeyWithCursor, SCRCMD_MSGWIN_CmdWaitMsgKey, SCRCMD_MSGWIN_CmdSetAutoMode, SCRCMD_MSGWIN_CleanupAutoMode, SCRCMD_MSGWIN_ExpandMessage
 * address:  0x021B0084
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from scrcmd_screeneffects.c at 0x021B0084 (lane L135, message window and menu command handlers (calls field_msgbg.c); original unknown).
 *
 * symbols:
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   VM_ReadU16  0x02011330  thumb
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   SCRCMD_WORK_SetWaitCount  0x0215A684  thumb  ov010
 *   SCRCMD_WORK_CountDownWait  0x0215A690  thumb  ov010
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateYesNoMenu  0x02190BE4  thumb  ov021
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb  ov021
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 *   SCRCMD_WORK_StartMenu  0x0215A864  thumb  ov010
 *   SCRCMD_WORK_WaitMenuOrCancel  0x0215A990  thumb  ov010
 *   SCRCMD_WORK_WaitMenu  0x0215A954  thumb  ov010
 *   SCRIPT_WORK_GetWorkPtr  0x02158FE0  thumb  ov010
 *   SCRCMD_WORK_InitMenu  0x0215A77C  thumb  ov010
 *   SCRCMD_WORK_GetMsgData  0x0215A60C  thumb  ov010
 *   SCRIPT_WORK_GetMsgBuffer  0x02158F78  thumb  ov010
 *   SCRIPT_WORK_GetTempBuffer  0x02158F7C  thumb  ov010
 *   SCRCMD_WORK_AddMenuItem  0x0215A7F0  thumb  ov010
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   FIELD_MSGBG_ClearInfoSysWin  0x02191164  thumb  ov021
 *   SCRCMD_WORK_GetWindowState  0x0215A654  thumb  ov010
 *   FIELD_MSGBG_CreateInfoSysWin  0x02190FA0  thumb  ov021
 *   SCRCMD_WORK_SetWindowState  0x0215A660  thumb  ov010
 *   SCRCMD_WORK_SetMsgWindow  0x0215A614  thumb  ov010
 *   FIELD_MSGBG_DeleteInfoSysWin  0x02191008  thumb  ov021
 *   SCRCMD_WORK_GetTimeIcon  0x0215A630  thumb  ov010
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   SCRCMD_WORK_SetTimeIcon  0x0215A624  thumb  ov010
 *   FIELD_MSGBG_InfoSysWinMain  0x021910C0  thumb  ov021
 *   FIELD_MSGBG_InfoSysWinPrintStr  0x02191084  thumb  ov021
 *   VM_SetWait  0x020113D0  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   FIELD_MSGBG_InfoSysWinPrintStrNow  0x02191184  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELD_MSGBG_GetInfoSysWinBmpWin  0x021911B4  thumb  ov021
 *   GFL_USE_GetMainTaskList  0x020056BC  thumb
 *   TIME_ICON_Create  0x0202EE30  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   FIELDMAP_GetInfoWindow  0x02188D48  thumb  ov021
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   STRBUF_Create  0x020457B0  arm
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   MISC_GetMoney  0x0200C274  thumb
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 *   FIELD_MSGBG_CreateMsgWin  0x02190708  thumb  ov021
 *   FIELDMAP_SetInfoWindow  0x02188D4C  thumb  ov021
 *   FIELD_MSGBG_MsgWinPrintStr  0x02190758  thumb  ov021
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   FIELD_MSGBG_ClearMsgWin  0x02190788  thumb  ov021
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   G3D_CAMERA_GetCamTarget  0x02048B30  arm
 *   G3D_CAMERA_GetEye  0x02048AE8  arm
 *   VEC_Subtract  0x0207CA00  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   VEC_CrossProduct  0x0207CAE8  arm
 *   NNS_G3dWorldPosToScrPos  0x0206DF3C  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   sBalloonUpVec     0x021D9390  data
 *   sBalloonOffsetTable     0x021D939C  data
 *   G3D_CAMERA_GetCamUp  0x02048B0C  arm
 *   MTX_LookAt  0x0207BCA0  arm
 *   MI_Copy36B  0x02082B60  arm
 *   MTX_Inverse33  0x0207B0A4  arm
 *   MTX_MultVec33  0x0207B51C  arm
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_MSGBG_WaitTalkWinClose  0x021912F8  thumb  ov021
 *   FIELD_MSGBG_DeleteTalkWin  0x021912D8  thumb  ov021
 *   FIELD_MSGBG_ClearTalkWin  0x0219131C  thumb  ov021
 *   FIELD_MSGBG_AddTalkWin  0x0219129C  thumb  ov021
 *   SCRCMD_WORK_GetMmdlSys  0x0215A5EC  thumb  ov010
 *   SCRCMD_WORK_GetWordSetWork  0x0215A63C  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   SCRCMD_WORK_GetWindowKind  0x0215A66C  thumb  ov010
 *   FIELD_MSGBG_TalkWinPrintStr  0x02191348  thumb  ov021
 *   MI_CpuFill8  0x02082BCC  arm
 *   SCRCMD_WORK_SetWindowKind  0x0215A678  thumb  ov010
 *   FIELD_MSGBG_TalkWinMain  0x02191388  thumb
 *   SCRIPT_WORK_GetTargetObj  0x02158F90  thumb  ov010
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   TPOKE_DATA_ReadRecordString  0x0202A310  thumb
 *   FIELD_MSGBG_PlainWinMain  0x021916E0  thumb  ov021
 *   FIELD_MSGBG_ClearPlainWin  0x021915EC  thumb  ov021
 *   FIELD_MSGBG_CreatePlainWin  0x02191558  thumb  ov021
 *   FIELD_MSGBG_PlainWinPrintStream  0x021916A8  thumb  ov021
 *   FIELD_MSGBG_DeletePlainWin  0x021915B4  thumb  ov021
 *   FIELD_MSGBG_GetStrSizeChars  0x02191830  thumb  ov021
 *   FIELD_MSGBG_AddSubMsgWinStr  0x021918DC  thumb  ov021
 *   FIELD_MSGBG_DeleteSubMsgWin  0x0219196C  thumb  ov021
 *   FIELD_MSGBG_ExistsSubMsgWin  0x021919AC  thumb  ov021
 *   FIELD_MSGBG_DeleteAllSubMsgWin  0x02191978  thumb  ov021
 *   FIELD_MSGBG_BgWinMain  0x02191BE8  thumb  ov021
 *   FIELD_MSGBG_DeleteBgWin  0x02191B14  thumb  ov021
 *   SCRIPT_WORK_GetMsgData  0x02158F84  thumb  ov010
 *   SCRIPT_WORK_SetMsgData  0x02158F80  thumb  ov010
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   FIELD_MSGBG_CreateBgWin  0x02191A04  thumb  ov021
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   FIELD_MSGBG_CreateBgWinFont  0x02191A10  thumb  ov021
 *   FIELD_MSGBG_DeleteSpWin  0x02192628  thumb  ov021
 *   FIELD_MSGBG_SpWinWaitKey  0x021926D8  thumb  ov021
 *   FIELD_MSGBG_GetStrWidthChars  0x0219270C  thumb  ov021
 *   FIELD_MSGBG_GetStrHeightChars  0x0219272C  thumb  ov021
 *   FIELD_MSGBG_CreateSpWin  0x02192570  thumb  ov021
 *   FIELD_MSGBG_SpWinPrintStr  0x0219269C  thumb  ov021
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELD_MSGBG_SysWinDrawCursor  0x02191134  thumb  ov021
 *   FIELD_MSGBG_PlainWinDrawCursor  0x02191794  thumb  ov021
 *   FIELD_MSGBG_TalkWinDrawCursor  0x021914CC  thumb  ov021
 *   FIELD_MSGBG_SetAutoMode  0x021904DC  thumb  ov021
 */

#include "../version.h"
#include "../arm9/script_vm_types.h"
#include "field_msgbg_types.h"
#include "../ov010/script_work_types.h"
#include "../arm9/btl_setup_types.h"

#include "field_player.h"
typedef struct G3dCamera G3dCamera;
typedef struct ScrcmdWork ScrcmdWork;
typedef struct WordSet WordSet;
typedef struct Strbuf Strbuf;
typedef struct TimeIcon TimeIcon;
typedef struct MsgBank MsgBank;
typedef struct MoneyData MoneyData;
typedef struct MainTaskList MainTaskList;
typedef struct GfFont GfFont;
typedef struct BmpWin BmpWin;
typedef struct MyStatus MyStatus;

#include "../sdk_fx.h"

/* Script command that waits: returns 1 when the command is done. */
typedef int (*ScrcmdWaitFn)(ScriptVm *vm, ScrcmdWork *cmdWork);

/* Game event procedure: (event, step counter, work block of the event). */
typedef int (*GameEventProc)(GameEvent *event, int *seq, void *work);

/* Message window kinds, the check flags of the script work. */
enum {
    SCRIPT_FLAG_INFO_SYS_WIN = 1,
    SCRIPT_FLAG_TALK_WIN = 2,    /* talk balloon */
    SCRIPT_FLAG_PLAIN_WIN = 3,
    SCRIPT_FLAG_BG_WIN = 4,
    SCRIPT_FLAG_SUB_WIN = 5,
    SCRIPT_FLAG_SP_WIN = 6,
    SCRIPT_FLAG_AUTO_MODE = 9
};

/* Work of the yes/no event (0xC bytes). */
typedef struct YesNoEventWork {
    ScrcmdWork *cmdWork;            /* 0x00 */
    u16 *result;                    /* 0x04, script variable that receives 0 (yes) or 1 (no) */
    FieldMenuFunc *menu;            /* 0x08 */
} YesNoEventWork;

/* Work of the list menu event (8 bytes). */
typedef struct MenuEventWork {
    ScrcmdWork *cmdWork;            /* 0x00 */
    int allowCancel;                /* 0x04 */
} MenuEventWork;

/*
 * Task of the script check handlers (gScriptCheckHandlers, run by
 * SCRIPT_WORK_RunCheckTask in script_work.c, 0x18 bytes). The cleanup
 * functions below are entries of that table: each closes the window of its
 * kind when the matching check flag is still set.
 */
typedef struct ScriptCheckTask {
    GameSystem *gameSystem;         /* 0x00 */
    ScrcmdWork *cmdWork;            /* 0x04, typed ScriptVm * in script_work.c */
    ScriptWork *scriptWork;         /* 0x08 */
    int state;                      /* 0x0C */
    int index;                      /* 0x10 */
    int count;                      /* 0x14 */
} ScriptCheckTask;

/* Talk balloon placement kept in the command work (0x28 bytes). */
typedef struct BalloonWinWork {
    u16 objId;                      /* 0x00, map object the balloon follows (0xFF: player) */
    u16 talkIndex;                  /* 0x02, balloon slot passed to FIELD_MSGBG_AddTalkWin */
    VecFx32 pos;                    /* 0x04, mmdlPos + offset: the point the tail aims at */
    VecFx32 mmdlPos;                /* 0x10, last position of the map object */
    VecFx32 offset;                 /* 0x1C, offset from the object to the balloon */
} BalloonWinWork;

#include "../ov010/fldmmdl.h"
#include "../arm9/gamesystem.h"
#ifdef __MWERKS__
#define SCRCMD_WORK_InitMenu SCRCMD_WORK_InitMenu_header
#include "../ov010/scrcmd_work.h"
#include "../ov021/field_msgbg.h"
#undef SCRCMD_WORK_InitMenu
void SCRCMD_WORK_InitMenu(ScrcmdWork *cmdWork, u32 x, u32 y, u32 cursorPos, u32 cancelable, u32 alignRight, u16 *result, WordSet *wordSet, MsgBank *msgData); /* original prototype: the definition takes u16 coordinates */
#else
#include "../ov010/scrcmd_work.h"
#include "../ov021/field_msgbg.h"
#endif
#include "../ov010/script_work.h"
#include "../ov010/script_work_cmd.h"
#include "../ov010/script_sys.h"
extern u16 VM_ReadU16(ScriptVm *vm);
extern void VM_SetWait(ScriptVm *vm, ScrcmdWaitFn waitFn);
#include "../arm9/gfl_use.h"
#include "../arm9/game_event.h"
struct ScriptWork;
#include "../arm9/wordset.h"
#include "fieldmap.h"
struct FieldMsgWindow;
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define TIME_ICON_Create TIME_ICON_Create_header
#endif
#include "../arm9/time_icon.h"
#ifdef __MWERKS__
#undef TIME_ICON_Create
extern struct TimeIcon * TIME_ICON_Create(struct TcbList *, struct BmpWin *, u32, u32, u32);
#endif
struct MsgBank;
#include "../arm9/msgdata.h"
struct TcbList;
#include "../arm9/game_data.h"
#include "../arm9/strbuf.h"
struct MiscSave;
#include "../arm9/beacon.h"
#include "../arm9/g3d_camera.h"
#include "../arm9/fx_vec.h"
#include "../arm9/nns_g3d_util.h"
#include "../arm9/fx_mtx43.h"
#include "../arm9/mi_memory.h"
#include "../arm9/fx_mtx33.h"
struct VecFx32;
struct FieldTalkWin;
struct OccupyInfo;
#include "field_camera.h"
#include "../arm9/mystatus.h"
#include "../arm9/tpoke_data.h"
#include "../arm9/gf_font.h"
#include "../arm9/key.h"
int SCRCMD_MSGWIN_YesNoEventMain(struct GameEvent *event, int *seq, void *work);
GameEvent *SCRCMD_MSGWIN_CreateYesNoEvent(GameSystem *gameSystem, ScrcmdWork *cmdWork, u16 *result);
int SCRCMD_MSGWIN_CmdYesNoWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_MenuEventMain(struct GameEvent *event, int *seq, void *work);
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
extern const VecFx32 sBalloonUpVec;
extern const VecFx32 sBalloonOffsetTable[2][4];


/*
 * State 2 is a nested switch on FIELD_MSGBG_YesNoMenuMain's result (case 0, case 2
 * empty, default) with the flag store and the state increment written out
 * in each arm: the compiler cross-jumps the default arm into case 0's
 * tail, which is why `movs r1,#1; b` sits after the shared increment.
 * An if/else chain puts that arm inline. The listing extent includes two
 * bytes of padding.
 * Addresses are Black-image addresses.
 */
int SCRCMD_MSGWIN_YesNoEventMain(struct GameEvent *event, int *seq, void *work)
{
    YesNoEventWork *yesNo = work;

    SCRCMD_WORK_GetScriptWork(yesNo->cmdWork);
    switch (*seq) {
    case 0:
        SCRCMD_WORK_SetWaitCount(yesNo->cmdWork, 8);
        (*seq)++;
    case 1:
        if (SCRCMD_WORK_CountDownWait(yesNo->cmdWork) == 1) {
            yesNo->menu = FIELD_MSGBG_CreateYesNoMenu(FIELDMAP_GetMsgBg(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(yesNo->cmdWork))), 0);
            (*seq)++;
        }
        break;
    case 2:
        switch (FIELD_MSGBG_YesNoMenuMain(yesNo->menu)) {
        case 0:
            *yesNo->result = 0;
            (*seq)++;
            break;
        case 2:
            break;
        default:
            *yesNo->result = 1;
            (*seq)++;
            break;
        }
        break;
    case 3:
        FIELD_MSGBG_DeleteMenuFunc(yesNo->menu);
        return 1;
    }
    return 0;
}


GameEvent *SCRCMD_MSGWIN_CreateYesNoEvent(GameSystem *gameSystem, ScrcmdWork *cmdWork, u16 *result)
{
    GameEvent *event;
    YesNoEventWork *yesNo;

    event = GAME_EVENT_Create(gameSystem, 0, SCRCMD_MSGWIN_YesNoEventMain, sizeof(YesNoEventWork));
    yesNo = GAME_EVENT_GetWork(event);
    yesNo->cmdWork = cmdWork;
    yesNo->result = result;
    return event;
}


int SCRCMD_MSGWIN_CmdYesNoWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *result = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);

    SCRIPT_SYS_CallEvent(scriptWork, SCRCMD_MSGWIN_CreateYesNoEvent(SCRCMD_WORK_GetGameSystem(cmdWork), cmdWork, result));
    return 1;
}


int SCRCMD_MSGWIN_MenuEventMain(struct GameEvent *event, int *seq, void *work)
{
    MenuEventWork *menu = work;
    int done;

    switch (*seq) {
    case 0:
        SCRCMD_WORK_SetWaitCount(menu->cmdWork, 8);
        (*seq)++;
    case 1:
        if (SCRCMD_WORK_CountDownWait(menu->cmdWork) == 1) {
            SCRCMD_WORK_StartMenu(menu->cmdWork);
            (*seq)++;
        }
        break;
    case 2:
        if (menu->allowCancel != 0)
            done = SCRCMD_WORK_WaitMenuOrCancel(menu->cmdWork);
        else
            done = SCRCMD_WORK_WaitMenu(menu->cmdWork);
        if (done == 1)
            return 1;
        break;
    }
    return 0;
}


GameEvent *SCRCMD_MSGWIN_CreateMenuEvent(GameSystem *gameSystem, ScrcmdWork *cmdWork, int allowCancel)
{
    GameEvent *event;
    MenuEventWork *menu;

    event = GAME_EVENT_Create(gameSystem, 0, SCRCMD_MSGWIN_MenuEventMain, sizeof(MenuEventWork));
    menu = GAME_EVENT_GetWork(event);
    menu->cmdWork = cmdWork;
    menu->allowCancel = allowCancel;
    return event;
}


int SCRCMD_MSGWIN_CmdInitMenu(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u8 *pc;
    u32 x, y, cursorPos, cancelable;
    u16 *result;
    ScriptWork *scriptWork;
    GameData *gameData;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    x = *vm->pc;
    vm->pc = vm->pc + 1;
    y = *vm->pc;
    vm->pc = vm->pc + 1;
    cursorPos = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    pc = vm->pc;
    cancelable = pc[0];
    vm->pc = pc + 1;
    result = SCRIPT_WORK_GetWorkPtr(scriptWork, gameData, VM_ReadU16(vm));
    SCRCMD_WORK_InitMenu(cmdWork, x, y, cursorPos, cancelable, 0, result, SCRIPT_WORK_GetWordSet(scriptWork), 0);
    return 1;
}


int SCRCMD_MSGWIN_CmdInitMenuMsgData(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u8 *pc;
    u32 cursorPos;
    u16 *result;
    ScriptWork *scriptWork;
    GameData *gameData;
    u8 x, y, cancelable;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    x = *vm->pc;
    vm->pc = vm->pc + 1;
    y = *vm->pc;
    vm->pc = vm->pc + 1;
    cursorPos = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    pc = vm->pc;
    cancelable = pc[0];
    vm->pc = pc + 1;
    result = SCRIPT_WORK_GetWorkPtr(scriptWork, gameData, VM_ReadU16(vm));
    SCRCMD_WORK_InitMenu(cmdWork, x, y, cursorPos, cancelable, 0, result, SCRIPT_WORK_GetWordSet(scriptWork), SCRCMD_WORK_GetMsgData(cmdWork));
    return 1;
}


int SCRCMD_MSGWIN_CmdInitMenuMsgDataMode1(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u8 *pc;
    u32 cursorPos;
    u16 *result;
    ScriptWork *scriptWork;
    GameData *gameData;
    u8 x, y, cancelable;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    x = *vm->pc;
    vm->pc = vm->pc + 1;
    y = *vm->pc;
    vm->pc = vm->pc + 1;
    cursorPos = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    pc = vm->pc;
    cancelable = pc[0];
    vm->pc = pc + 1;
    result = SCRIPT_WORK_GetWorkPtr(scriptWork, gameData, VM_ReadU16(vm));
    SCRCMD_WORK_InitMenu(cmdWork, x, y, cursorPos, cancelable, 1, result, SCRIPT_WORK_GetWordSet(scriptWork), SCRCMD_WORK_GetMsgData(cmdWork));
    return 1;
}


int SCRCMD_MSGWIN_CmdAddMenuItem(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 msgId, helpMsgId, itemValue;
    ScriptWork *scriptWork;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    msgId = VM_ReadU16(vm);
    helpMsgId = VM_ReadU16(vm);
    itemValue = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRCMD_WORK_AddMenuItem(cmdWork, msgId, helpMsgId, itemValue, SCRIPT_WORK_GetMsgBuffer(scriptWork), SCRIPT_WORK_GetTempBuffer(scriptWork));
    return 0;
}


int SCRCMD_MSGWIN_CmdStartMenu(ScriptVm *vm, ScrcmdWork *cmdWork)
{
SCRIPT_SYS_CallEvent(SCRCMD_WORK_GetScriptWork(cmdWork), SCRCMD_MSGWIN_CreateMenuEvent(SCRCMD_WORK_GetGameSystem(cmdWork), cmdWork, 0));
return 1;
}


int SCRCMD_MSGWIN_CmdStartMenuEx(ScriptVm *vm, ScrcmdWork *cmdWork)
{
SCRIPT_SYS_CallEvent(SCRCMD_WORK_GetScriptWork(cmdWork), SCRCMD_MSGWIN_CreateMenuEvent(SCRCMD_WORK_GetGameSystem(cmdWork), cmdWork, 0));
return 1;
}


void SCRCMD_MSGWIN_OpenInfoSysWin(ScrcmdWork *cmdWork, u32 windowKind)
{
    MsgBank *msgData;
    u32 windowState, winY;
    ScriptFieldParam *fieldParam;
    FieldSysWin *sysWin;

    winY = 1;
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_INFO_SYS_WIN)) {
        FIELD_MSGBG_ClearInfoSysWin((struct FieldSysWin *)SCRCMD_WORK_GetMsgWindow(cmdWork));
        return;
    }
    fieldParam = SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork));
    msgData = SCRCMD_WORK_GetMsgData(cmdWork);
    windowState = windowKind;
    if (windowKind == 1) {
    } else if (windowKind == 2) {
        winY = 0x13;
    } else if (windowKind == 0) {
        switch (SCRCMD_WORK_GetWindowState(cmdWork)) {
        case 1:
        case 3:
        case 5:
            windowState = winY;
            break;
        case 2:
        case 4:
        case 6:
            winY = 0x13;
            windowState = 2;
            break;
        case 7:
            winY = 0x13;
            windowState = 2;
            break;
        default:
            winY = 0x13;
            windowState = 2;
            break;
        }
    } else {
        winY = 0x13;
        windowState = 2;
    }
    sysWin = FIELD_MSGBG_CreateInfoSysWin(fieldParam->mapSystem, msgData, winY);
    SCRCMD_WORK_SetWindowState(cmdWork, windowState);
    SCRCMD_WORK_SetMsgWindow(cmdWork, sysWin);
    SCRIPT_WORK_SetCheckFlag(SCRIPT_FLAG_INFO_SYS_WIN);
}


void SCRCMD_MSGWIN_CloseInfoSysWin(ScrcmdWork *cmdWork)
{
    TimeIcon *timeIcon;

    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_INFO_SYS_WIN)) {
        FIELD_MSGBG_DeleteInfoSysWin((struct FieldSysWin *)SCRCMD_WORK_GetMsgWindow(cmdWork));
        timeIcon = SCRCMD_WORK_GetTimeIcon(cmdWork);
        if (timeIcon) {
            TIME_ICON_Delete(timeIcon);
            SCRCMD_WORK_SetTimeIcon(cmdWork, 0);
        }
        SCRCMD_WORK_SetMsgWindow(cmdWork, 0);
        SCRIPT_WORK_ResetCheckFlag(SCRIPT_FLAG_INFO_SYS_WIN);
    }
}


int SCRCMD_MSGWIN_WaitInfoSysWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
if (FIELD_MSGBG_InfoSysWinMain((struct FieldSysWin *)SCRCMD_WORK_GetMsgWindow(cmdWork)) == 1) {
    return 1;
}
return 0;
}


int SCRCMD_MSGWIN_CmdInfoSysWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 msgId;
    Strbuf *str;
    ScriptWork *scriptWork;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    msgId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRCMD_MSGWIN_OpenInfoSysWin(cmdWork, (u8)VM_ReadU16(vm));
    str = SCRCMD_MSGWIN_ExpandMessage(cmdWork, scriptWork, msgId);
    FIELD_MSGBG_InfoSysWinPrintStr((struct FieldSysWin *)SCRCMD_WORK_GetMsgWindow(cmdWork), 0, 0, str);
    VM_SetWait(vm, SCRCMD_MSGWIN_WaitInfoSysWin);
    return 1;
}


int SCRCMD_MSGWIN_CmdInfoSysWinMsgNow(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 msgId;
    Strbuf *str;
    MsgBank *msgData;
    WordSet *wordSet;
    Strbuf *tempBuffer;
    ScriptWork *scriptWork;
    FieldSysWin *sysWin;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    str = SCRIPT_WORK_GetMsgBuffer(scriptWork);
    msgId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRCMD_MSGWIN_OpenInfoSysWin(cmdWork, (u8)VM_ReadU16(vm));
    msgData = SCRCMD_WORK_GetMsgData(cmdWork);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    tempBuffer = SCRIPT_WORK_GetTempBuffer(scriptWork);
    MSGDATA_ReadString((struct MsgBank *)msgData, msgId, tempBuffer);
    WORDSET_CopyTaggedText(wordSet, str, tempBuffer);
    sysWin = (struct FieldSysWin *)SCRCMD_WORK_GetMsgWindow(cmdWork);
    FIELD_MSGBG_ClearInfoSysWin(sysWin);
    FIELD_MSGBG_InfoSysWinPrintStrNow(sysWin, 0, 0, str);
    return 0;
}


int SCRCMD_MSGWIN_CmdSetTimeIcon(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 heapId, noTimeIcon;
    TimeIcon *timeIcon;

    heapId = FIELDMAP_GetHeapId(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork)));
    noTimeIcon = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    if (!SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_INFO_SYS_WIN)) {
        return 0;
    }
    timeIcon = SCRCMD_WORK_GetTimeIcon(cmdWork);
    if (timeIcon) {
        TIME_ICON_Delete(timeIcon);
        SCRCMD_WORK_SetTimeIcon(cmdWork, 0);
    }
    if (noTimeIcon == 0) {
        BmpWin *bmpWin = FIELD_MSGBG_GetInfoSysWinBmpWin((struct FieldSysWin *)SCRCMD_WORK_GetMsgWindow(cmdWork));
        SCRCMD_WORK_SetTimeIcon(cmdWork, TIME_ICON_Create(GFL_USE_GetMainTaskList(), bmpWin, 0xf, 0x10, heapId));
    }
    return 0;
}


int SCRCMD_MSGWIN_CmdCloseInfoSysWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
SCRCMD_MSGWIN_CloseInfoSysWin(cmdWork);
return 0;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
int SCRCMD_MSGWIN_CleanupInfoSysWin(ScriptCheckTask *task, int *state)
{
    SCRCMD_MSGWIN_CloseInfoSysWin(task->cmdWork);
    return 1;
}


int SCRCMD_MSGWIN_CmdOpenMoneyWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 x, y;
    GameSystem *gameSystem;
    FieldMap *fieldMap;
    GameData *gameData;
    FieldMsgBg *msgBg;
    FieldMsgWin *oldWin;
    ScriptWork *scriptWork;
    WordSet *wordSet;
    Strbuf *tempBuffer;
    u32 heapId;
    MsgBank *msgData;
    FieldMsgWin *moneyWin;
    Strbuf *str;
    u32 money;

    x = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    y = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    GAME_DATA_GetMyPlayerWork(gameData);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    msgBg = FIELDMAP_GetMsgBg(fieldMap);
    oldWin = FIELDMAP_GetInfoWindow(fieldMap);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    tempBuffer = SCRIPT_WORK_GetTempBuffer(scriptWork);
    heapId = FIELDMAP_GetHeapId(fieldMap);
    msgData = (struct MsgBank *)MSGDATA_CreateFromArchive(0, 3, 0x9e, heapId);
    str = STRBUF_Create(0x80, heapId);
    money = MISC_GetMoney(GAME_DATA_GetMiscSave(gameData));
    if (oldWin != 0)
        FIELD_MSGBG_DeleteMsgWin(oldWin);
    moneyWin = FIELD_MSGBG_CreateMsgWin(msgBg, msgData, (u16)(x - 9), (u16)y, 9, 2);
    FIELDMAP_SetInfoWindow(fieldMap, moneyWin);
    WORDSET_SetSlotNumber(wordSet, 2, money, 7, 1, 1);
    MSGDATA_ReadString((struct MsgBank *)msgData, 1, tempBuffer);
    WORDSET_CopyTaggedText(wordSet, str, tempBuffer);
    FIELD_MSGBG_MsgWinPrintStr(moneyWin, 0, 0, str);
    STRBUF_Delete(str);
    MSGDATA_Delete((struct MsgBank *)msgData);
    return 0;
}


int SCRCMD_MSGWIN_CmdUpdateMoneyWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameSystem *gameSystem;
    FieldMap *fieldMap;
    GameData *gameData;
    FieldMsgWin *moneyWin;
    ScriptWork *scriptWork;
    WordSet *wordSet;
    Strbuf *tempBuffer;
    u32 heapId;
    MsgBank *msgData;
    Strbuf *str;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    GAME_DATA_GetMyPlayerWork(gameData);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    moneyWin = FIELDMAP_GetInfoWindow(fieldMap);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    tempBuffer = SCRIPT_WORK_GetTempBuffer(scriptWork);
    heapId = FIELDMAP_GetHeapId(fieldMap);
    msgData = (struct MsgBank *)MSGDATA_CreateFromArchive(0, 3, 0x9e, heapId);
    str = STRBUF_Create(0x80, heapId);
    WORDSET_SetSlotNumber(wordSet, 2, MISC_GetMoney(GAME_DATA_GetMiscSave(gameData)), 7, 1, 1);
    MSGDATA_ReadString((struct MsgBank *)msgData, 1, tempBuffer);
    WORDSET_CopyTaggedText(wordSet, str, tempBuffer);
    FIELD_MSGBG_ClearMsgWin(moneyWin);
    FIELD_MSGBG_MsgWinPrintStr(moneyWin, 0, 0, str);
    STRBUF_Delete(str);
    MSGDATA_Delete((struct MsgBank *)msgData);
    return 0;
}


int SCRCMD_MSGWIN_CmdCloseMoneyWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork));
    FieldMsgWin *moneyWin = FIELDMAP_GetInfoWindow(fieldMap);

    if (moneyWin != 0) {
        FIELD_MSGBG_DeleteMsgWin(moneyWin);
        FIELDMAP_SetInfoWindow(fieldMap, 0);
    }
    return 0;
}


/*
 * The quotient is written back into tileZ (the address-taken output local)
 * rather than a fresh row: with a separate local the divisor 12 and the
 * table stride 12 pool into r6 across the _u32_div_f call.
 */
void SCRCMD_MSGWIN_CalcBalloonOffset(const VecFx32 *mmdlPos, VecFx32 *out, G3dCamera *camera, FieldCamera *fieldCamera)
{
    VecFx32 pos;
    VecFx32 forward;
    VecFx32 forwardFlat;
    VecFx32 right;
    VecFx32 shift;
    VecFx32 eye;
    VecFx32 target;
    u32 tileX;
    u32 tileZ;
    u32 chunkX;
    u32 column;

    pos = *mmdlPos;
    G3D_CAMERA_Reset(camera);
    G3D_CAMERA_GetCamTarget(camera, &target);
    G3D_CAMERA_GetEye(camera, &eye);
    VEC_Subtract(&target, &eye, &forward);
    forwardFlat = forward;
    forwardFlat.y = column = 0;
    VEC_Normalize(&forwardFlat, &forwardFlat);
    VEC_CrossProduct(&forwardFlat, &sBalloonUpVec, &right);
    VEC_CrossProduct(&forward, &right, &shift);
    VEC_Normalize(&shift, &shift);
    pos.x += shift.x;
    pos.y += shift.y;
    pos.z += shift.z;
    NNS_G3dWorldPosToScrPos(&pos, (s32 *)&tileX, (s32 *)&tileZ);
    chunkX = tileX >> 3;
    if (chunkX < 10) {
        column = 0;
    } else if (chunkX >= 10 && chunkX <= 15) {
        column = 1;
    } else if (chunkX >= 16 && chunkX < 22) {
        column = 2;
    } else {
        column = 3;
    }
    tileZ = (tileZ >> 3) / 12;
    if (column < 4 && tileZ < 2) {
        *out = sBalloonOffsetTable[tileZ][column];
    } else {
        VecFx32 zero = {0, 0, 0};
        *out = zero;
    }
}


void SCRCMD_MSGWIN_RotateOffsetByCamera(VecFx32 *offset, G3dCamera *camera)
{
    VecFx32 eye, up, target;
    MtxFx43 viewMtx;
    MtxFx33 invRotation;

    G3D_CAMERA_GetEye(camera, &eye);
    G3D_CAMERA_GetCamUp(camera, &up);
    G3D_CAMERA_GetCamTarget(camera, &target);
    MTX_LookAt(&eye, &up, &target, &viewMtx);
    MI_Copy36B(&viewMtx, &invRotation);
    MTX_Inverse33(&invRotation, &invRotation);
    MTX_MultVec33(offset, &invRotation, offset);
}


void SCRCMD_MSGWIN_SelectBalloonOffset(const VecFx32 *mmdlPos, VecFx32 *out, G3dCamera *camera, FieldCamera *fieldCamera, u8 windowKind)
{
    int column = 0;
    int row = 0;

    switch (windowKind) {
    case 3:
        column = 1;
        break;
    case 4:
        column = 1;
        row = 1;
        break;
    case 5:
        column = 2;
        break;
    case 6:
        column = 2;
        row = 1;
        break;
    case 0:
    case 1:
    case 2:
        SCRCMD_MSGWIN_CalcBalloonOffset(mmdlPos, out, camera, fieldCamera);
        SCRCMD_MSGWIN_RotateOffsetByCamera(out, camera);
        return;
    }
    *out = sBalloonOffsetTable[row][column];
    SCRCMD_MSGWIN_RotateOffsetByCamera(out, camera);
}


void SCRCMD_MSGWIN_GetBalloonOffset(const VecFx32 *mmdlPos, VecFx32 *out, G3dCamera *camera, FieldCamera *fieldCamera, u8 windowKind)
{
    SCRCMD_MSGWIN_SelectBalloonOffset(mmdlPos, out, camera, fieldCamera, windowKind);
}


void SCRCMD_MSGWIN_GetBalloonTailParams(int windowState, int *talkIndex, int *tailType)
{
    *talkIndex = 0;
    *tailType = 0;
    switch (windowState) {
    case 3:
        *tailType = 7;
        break;
    case 4:
        *talkIndex = 1;
        *tailType = 5;
        break;
    case 5:
        *tailType = 8;
        break;
    case 6:
        *talkIndex = 1;
        *tailType = 6;
        break;
    case 2:
        *talkIndex = 1;
        break;
    case 1:
        break;
    case 0:
        *talkIndex = 1;
        *tailType = 2;
        break;
    }
}


int SCRCMD_MSGWIN_GetBalloonSide(Mmdl *playerMmdl, const VecFx32 *targetPos)
{
    VecFx32 playerPos;
    int placement = 2;

    FLDMMDL_GetPos(playerMmdl, (struct VecFx32 *)(&playerPos));
    if (targetPos->z < playerPos.z)
        placement = 1;
    return placement;
}


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * SCRCMD_WORK_SetMsgWindow (0x0215A614) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int SCRCMD_MSGWIN_WaitTalkWinClose(ScriptVm *vm, ScrcmdWork *cmdWork)
{
if (FIELD_MSGBG_WaitTalkWinClose((struct FieldTalkWin *)SCRCMD_WORK_GetMsgWindow(cmdWork)) == 1) {
    SCRCMD_WORK_SetMsgWindow(cmdWork, 0);
    SCRIPT_WORK_ResetCheckFlag(SCRIPT_FLAG_TALK_WIN);
    return 1;
}
return 0;
}


void SCRCMD_MSGWIN_StartCloseTalkWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_TALK_WIN) != 0) {
        FIELD_MSGBG_DeleteTalkWin((struct FieldTalkWin *)SCRCMD_WORK_GetMsgWindow(cmdWork));
        VM_SetWait(vm, SCRCMD_MSGWIN_WaitTalkWinClose);
    }
}


void SCRCMD_MSGWIN_CloseTalkWin(ScrcmdWork *cmdWork)
{
    u32 checkFlag = SCRIPT_FLAG_TALK_WIN;

    if (SCRIPT_WORK_CheckFlag(checkFlag)) {
        FIELD_MSGBG_ClearTalkWin((struct FieldTalkWin *)SCRCMD_WORK_GetMsgWindow(cmdWork));
        SCRCMD_WORK_SetMsgWindow(cmdWork, 0);
        SCRIPT_WORK_ResetCheckFlag(checkFlag);
    }
}


void SCRCMD_MSGWIN_OpenTalkWin(ScrcmdWork *cmdWork, FieldMsgBg *msgBg, int talkIndex, VecFx32 *pos, Strbuf *str, u32 winType, u32 tailType)
{
    SCRCMD_WORK_SetMsgWindow(cmdWork, FIELD_MSGBG_AddTalkWin(msgBg, talkIndex, pos, str, winType, tailType));
    SCRIPT_WORK_SetCheckFlag(SCRIPT_FLAG_TALK_WIN);
}


void SCRCMD_MSGWIN_UpdateBalloonPos(ScrcmdWork *cmdWork, int forceUpdate)
{
    MmdlSys *mmdlSys = (struct MmdlSys *)SCRCMD_WORK_GetMmdlSys(cmdWork);
    BalloonWinWork *balloon = (struct BalloonWinWork *)SCRCMD_WORK_GetWordSetWork(cmdWork);
    Mmdl *mmdl = FLDMMDL_SysSearchObjId(mmdlSys, balloon->objId);
    VecFx32 mmdlPos;
    if (mmdl != 0) {
        FLDMMDL_GetDirDisp(mmdl);
        FLDMMDL_GetPos(mmdl, (struct VecFx32 *)(&mmdlPos));
        if (forceUpdate == 1 || mmdlPos.x != balloon->mmdlPos.x || mmdlPos.y != balloon->mmdlPos.y || mmdlPos.z != balloon->mmdlPos.z) {
            FieldCamera *fieldCamera;
            G3dCamera *g3dCamera;
            balloon->mmdlPos = mmdlPos;
            fieldCamera = FIELDMAP_GetCamera(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork)));
            g3dCamera = FIELD_CAMERA_GetG3dCamera(fieldCamera);
            SCRCMD_MSGWIN_SelectBalloonOffset(&balloon->mmdlPos, &balloon->offset, g3dCamera, fieldCamera, SCRCMD_WORK_GetWindowKind(cmdWork));
        }
        balloon->pos.x = balloon->mmdlPos.x + balloon->offset.x;
        balloon->pos.y = balloon->mmdlPos.y + balloon->offset.y;
        balloon->pos.z = balloon->mmdlPos.z + balloon->offset.z;
    }
}


int SCRCMD_MSGWIN_OpenBalloonWinMsg(ScrcmdWork *cmdWork, u16 objId, u16 msgFileId, u16 msgId, u16 windowKind, int winType)
{
    MsgBank *scriptMsgData;
    ScriptWork *scriptWork;
    ScriptFieldParam *fieldParam;
    MmdlSys *mmdlSys;
    Mmdl *playerMmdl, *targetMmdl;
    Strbuf *msgBuffer;
    WordSet *wordSet;
    Strbuf *tempBuffer;
    MsgBank *fileMsgData;
    int windowState;
    BalloonWinWork *balloon;
    VecFx32 targetPos;
    int talkIndex, tailType;

    windowState = windowKind;
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    scriptMsgData = SCRCMD_WORK_GetMsgData(cmdWork);
    fieldParam = SCRIPT_WORK_ResetFieldParam(scriptWork);
    mmdlSys = (struct MmdlSys *)SCRCMD_WORK_GetMmdlSys(cmdWork);
    playerMmdl = FLDMMDL_SysSearchObjId(mmdlSys, 0xff);
    targetMmdl = FLDMMDL_SysSearchObjId(mmdlSys, objId);
    if (targetMmdl == 0) {
        return 0;
    }
    msgBuffer = SCRIPT_WORK_GetMsgBuffer(scriptWork);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    tempBuffer = SCRIPT_WORK_GetTempBuffer(scriptWork);
    if (msgFileId == 0x400) {
        MSGDATA_ReadString((struct MsgBank *)scriptMsgData, msgId, tempBuffer);
    } else {
        fileMsgData = (struct MsgBank *)MSGDATA_CreateFromArchive(0, 3, msgFileId, SCRCMD_WORK_GetHeapId(cmdWork));
        MSGDATA_ReadString((struct MsgBank *)fileMsgData, msgId, tempBuffer);
        MSGDATA_Delete((struct MsgBank *)fileMsgData);
    }
    WORDSET_CopyTaggedText(wordSet, msgBuffer, tempBuffer);
    balloon = (struct BalloonWinWork *)SCRCMD_WORK_GetWordSetWork(cmdWork);
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_TALK_WIN) != 0) {
        FIELD_MSGBG_TalkWinPrintStr((struct FieldTalkWin *)SCRCMD_WORK_GetMsgWindow(cmdWork), msgBuffer);
    } else {
        MI_CpuFill8(balloon, 0, 0x28);
        balloon->objId = objId;
        if (windowKind == 0) {
            SCRCMD_WORK_GetWindowState(cmdWork);
            FLDMMDL_GetPos(targetMmdl, (struct VecFx32 *)(&targetPos));
            windowState = SCRCMD_MSGWIN_GetBalloonSide(playerMmdl, &targetPos);
        }
        SCRCMD_MSGWIN_GetBalloonTailParams(windowState, &talkIndex, &tailType);
        balloon->talkIndex = talkIndex;
        SCRCMD_WORK_SetWindowState(cmdWork, (u8)windowState);
        SCRCMD_WORK_SetWindowKind(cmdWork, windowKind);
        SCRCMD_MSGWIN_UpdateBalloonPos(cmdWork, 1);
        SCRCMD_MSGWIN_OpenTalkWin(cmdWork, fieldParam->mapSystem, talkIndex, &balloon->pos, msgBuffer, winType, tailType);
    }
    return 1;
}


int SCRCMD_MSGWIN_WaitBalloonWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    FieldTalkWin *talkWin;
    int done;

    talkWin = (struct FieldTalkWin *)SCRCMD_WORK_GetMsgWindow(cmdWork);
    SCRCMD_MSGWIN_UpdateBalloonPos(cmdWork, 0);
    done = 0;
    if (FIELD_MSGBG_TalkWinMain(talkWin) == 1) {
        done = 1;
    }
    return done;
}


int SCRCMD_MSGWIN_CmdBalloonWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 msgFileId, msgId, objId, windowKind, winType;
    msgFileId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    msgId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    windowKind = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    winType = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    if (SCRCMD_MSGWIN_OpenBalloonWinMsg(cmdWork, objId, msgFileId, msgId, windowKind, winType) == 1) {
        VM_SetWait(vm, SCRCMD_MSGWIN_WaitBalloonWin);
        return 1;
    }
    return 0;
}


int SCRCMD_MSGWIN_CmdBalloonWinMsgTarget(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    Mmdl *targetMmdl;
    u16 msgFileId, msgId, windowKind, winType;
    unsigned char objId;
    targetMmdl = SCRIPT_WORK_GetTargetObj(SCRCMD_WORK_GetScriptWork(cmdWork));
    msgFileId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    msgId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    windowKind = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    winType = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    if (targetMmdl == 0) {
        return 1;
    }
    objId = FLDMMDL_GetObjId(targetMmdl);
    if (SCRCMD_MSGWIN_OpenBalloonWinMsg(cmdWork, objId, msgFileId, msgId, windowKind, winType) == 1) {
        VM_SetWait(vm, SCRCMD_MSGWIN_WaitBalloonWin);
        return 1;
    }
    return 0;
}


int SCRCMD_MSGWIN_CmdBalloonWinMsgGender(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 msgFileId, msgId, outfitMsgId, objId, windowKind, winType;
    msgFileId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    msgId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    outfitMsgId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    windowKind = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    winType = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    if (MYSTATUS_GetSex(&GAME_DATA_GetMyPlayerWork(SCRCMD_WORK_GetGameData(cmdWork))->status)) {
        msgId = outfitMsgId;
    }
    if (SCRCMD_MSGWIN_OpenBalloonWinMsg(cmdWork, objId, msgFileId, msgId, windowKind, winType) == 1) {
        VM_SetWait(vm, SCRCMD_MSGWIN_WaitBalloonWin);
        return 1;
    }
    return 0;
}


int SCRCMD_MSGWIN_CmdBalloonWinMsgSkipArg(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 msgFileId, msgId, objId, windowKind, winType;
    msgFileId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
#if VERSION == VERSION_WHITE
    msgId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRIPT_WORK_ReadWorkValue(vm, cmdWork);       /* the skipped argument is the third one in White */
#else
    SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    msgId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
#endif
    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    windowKind = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    winType = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    if (SCRCMD_MSGWIN_OpenBalloonWinMsg(cmdWork, objId, msgFileId, msgId, windowKind, winType) == 1) {
        VM_SetWait(vm, SCRCMD_MSGWIN_WaitBalloonWin);
        return 1;
    }
    return 0;
}


/*
 * Calls SCRCMD_MSGWIN_StartCloseTalkWin(a, b) and returns 0x1.
 */
/*
 * Calls SCRCMD_MSGWIN_StartCloseTalkWin() and returns 0x1.
 */
int SCRCMD_MSGWIN_CmdCloseTalkWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    SCRCMD_MSGWIN_StartCloseTalkWin(vm, cmdWork);

    return 0x1;
}


int SCRCMD_MSGWIN_CleanupTalkWin(ScriptCheckTask *task, int *state)
{
    SCRCMD_MSGWIN_CloseTalkWin(task->cmdWork);
    return 1;
}


int SCRCMD_MSGWIN_CmdBalloonWinSavedText(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    ScriptFieldParam *fieldParam;
    int key1, key2, objId;
    Strbuf *msgBuffer;
    int placement, talkIndex;
    MmdlSys *mmdlSys;
    FieldPlayer *fieldPlayer;
    Mmdl *playerMmdl;
    BalloonWinWork *balloon;
    VecFx32 targetPos;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    fieldParam = SCRIPT_WORK_ResetFieldParam(scriptWork);
    key1 = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    key2 = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    msgBuffer = SCRIPT_WORK_GetMsgBuffer(scriptWork);
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_TALK_WIN) != 0) {
        return 1;
    }
    TPOKE_DATA_ReadRecordString(key1, key2, msgBuffer, SCRCMD_WORK_GetHeapId(cmdWork));
    if (FLDMMDL_SysSearchObjId((struct MmdlSys *)SCRCMD_WORK_GetMmdlSys(cmdWork), objId) == 0) {
        objId = 0xff;
    }
    balloon = (struct BalloonWinWork *)SCRCMD_WORK_GetWordSetWork(cmdWork);
    talkIndex = 0;
    MI_CpuFill8(balloon, 0, 0x28);
    balloon->objId = objId;
    fieldPlayer = FIELDMAP_GetFieldPlayer(fieldParam->fieldSystem);
    mmdlSys = (struct MmdlSys *)SCRCMD_WORK_GetMmdlSys(cmdWork);
    playerMmdl = FIELD_PLAYER_GetMmdl(fieldPlayer);
    FLDMMDL_GetPos(FLDMMDL_SysSearchObjId(mmdlSys, balloon->objId), (struct VecFx32 *)(&targetPos));
    placement = SCRCMD_MSGWIN_GetBalloonSide(playerMmdl, &targetPos);
    if (placement != 1) {
        talkIndex = 1;
    }
    balloon->talkIndex = talkIndex;
    SCRCMD_MSGWIN_UpdateBalloonPos(cmdWork, 1);
    SCRCMD_MSGWIN_OpenTalkWin(cmdWork, fieldParam->mapSystem, talkIndex, &balloon->pos, msgBuffer, 0, 0);
    SCRCMD_WORK_SetWindowState(cmdWork, placement);
    VM_SetWait(vm, SCRCMD_MSGWIN_WaitBalloonWin);
    return 1;
}


int SCRCMD_MSGWIN_WaitPlainWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
if (FIELD_MSGBG_PlainWinMain((struct FieldPlainWin *)SCRCMD_WORK_GetMsgWindow(cmdWork)) == 1) {
    return 1;
}
return 0;
}


int SCRCMD_MSGWIN_OpenPlainWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork, int winType)
{
    ScriptWork *scriptWork;
    int posKind;
    u16 winY;
    int msgId;
    Strbuf *str;
    ScriptFieldParam *fieldParam;
    u8 *pc;
    FieldPlainWin *plainWin;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    fieldParam = SCRIPT_WORK_ResetFieldParam(scriptWork);
    msgId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    pc = vm->pc;
    posKind = *pc;
    vm->pc = pc + 1;
    winY = 1;
    str = SCRCMD_MSGWIN_ExpandMessage(cmdWork, scriptWork, msgId);
    if (posKind != 1) {
        winY = 0x13;
    }
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_PLAIN_WIN) != 0) {
        plainWin = (struct FieldPlainWin *)SCRCMD_WORK_GetMsgWindow(cmdWork);
        FIELD_MSGBG_ClearPlainWin(plainWin);
    } else {
        plainWin = FIELD_MSGBG_CreatePlainWin(fieldParam->mapSystem, 0, winType, 1, winY, 0x1e, 4);
        SCRCMD_WORK_SetMsgWindow(cmdWork, plainWin);
    }
    FIELD_MSGBG_PlainWinPrintStream(plainWin, 8, 0, str);
    SCRIPT_WORK_SetCheckFlag(SCRIPT_FLAG_PLAIN_WIN);
    VM_SetWait(vm, SCRCMD_MSGWIN_WaitPlainWin);
    return 1;
}


void SCRCMD_MSGWIN_ClosePlainWin(ScrcmdWork *cmdWork)
{
    int checkFlag = SCRIPT_FLAG_PLAIN_WIN;
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_PLAIN_WIN) != 0) {
        FIELD_MSGBG_DeletePlainWin((struct FieldPlainWin *)SCRCMD_WORK_GetMsgWindow(cmdWork));
        SCRCMD_WORK_SetMsgWindow(cmdWork, 0);
        SCRIPT_WORK_ResetCheckFlag(checkFlag);
    }
}


int SCRCMD_MSGWIN_CmdPlainWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork) { return SCRCMD_MSGWIN_OpenPlainWinMsg(vm, cmdWork, 0); }


int SCRCMD_MSGWIN_CmdPlainWinMsgFrame1(ScriptVm *vm, ScrcmdWork *cmdWork) { return SCRCMD_MSGWIN_OpenPlainWinMsg(vm, cmdWork, 1); }


int SCRCMD_MSGWIN_CmdClosePlainWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
SCRCMD_MSGWIN_ClosePlainWin(cmdWork);
return 0;
}


int SCRCMD_MSGWIN_CleanupPlainWin(ScriptCheckTask *task, int *state)
{
    SCRCMD_MSGWIN_ClosePlainWin(task->cmdWork);
    return 1;
}


int SCRCMD_MSGWIN_CmdAddSubWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    Strbuf *str;
    MsgBank *msgData;
    WordSet *wordSet;
    Strbuf *tempBuffer;
    ScriptWork *scriptWork;
    u16 msgId, id;
    ScriptFieldParam *fieldParam;
    int x, y;
    u8 width;
    u8 height;
    u8 textWidth;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    fieldParam = SCRIPT_WORK_ResetFieldParam(scriptWork);
    msgId = VM_ReadU16(vm);
    x = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    y = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    id = VM_ReadU16(vm);
    height = 2;
    str = STRBUF_Create(0x40, SCRCMD_WORK_GetHeapId(cmdWork));
    msgData = SCRCMD_WORK_GetMsgData(cmdWork);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    tempBuffer = SCRIPT_WORK_GetTempBuffer(scriptWork);
    MSGDATA_ReadString((struct MsgBank *)msgData, msgId, tempBuffer);
    WORDSET_CopyTaggedText(wordSet, str, tempBuffer);
    FIELD_MSGBG_GetStrSizeChars(fieldParam->mapSystem, str, &width, &height);
    textWidth = width;
    if (x + textWidth > 0x1f) {
        x = (u16)(0x1f - textWidth);
    }
    if (y + height > 0x18) {
        y = 4;
        height = y;
    }
    FIELD_MSGBG_AddSubMsgWinStr(fieldParam->mapSystem, str, id, x, y, textWidth, height);
    STRBUF_Delete(str);
    SCRIPT_WORK_SetCheckFlag(SCRIPT_FLAG_SUB_WIN);
    return 0;
}


int SCRCMD_MSGWIN_CmdDeleteSubWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptFieldParam *fieldParam = SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork));

    FIELD_MSGBG_DeleteSubMsgWin(fieldParam->mapSystem, VM_ReadU16(vm));
    if (FIELD_MSGBG_ExistsSubMsgWin(fieldParam->mapSystem) == 0) {
        SCRIPT_WORK_ResetCheckFlag(SCRIPT_FLAG_SUB_WIN);
    }
    return 0;
}


void SCRCMD_MSGWIN_DeleteAllSubWins(ScrcmdWork *cmdWork)
{
    u32 checkFlag = SCRIPT_FLAG_SUB_WIN;

    if (SCRIPT_WORK_CheckFlag(checkFlag)) {
        FIELD_MSGBG_DeleteAllSubMsgWin(SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork))->mapSystem);
        SCRIPT_WORK_ResetCheckFlag(checkFlag);
    }
}


int SCRCMD_MSGWIN_CleanupSubWins(ScriptCheckTask *task, int *state)
{
    SCRCMD_MSGWIN_DeleteAllSubWins(task->cmdWork);
    return 1;
}


int SCRCMD_MSGWIN_WaitBgWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    Strbuf *tempBuffer = SCRIPT_WORK_GetMsgBuffer(SCRCMD_WORK_GetScriptWork(cmdWork));

    if (FIELD_MSGBG_BgWinMain((struct FieldBgWin *)SCRCMD_WORK_GetMsgWindow(cmdWork), tempBuffer) == 1) {
        return 1;
    }
    return 0;
}


void SCRCMD_MSGWIN_CloseBgWin(ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    GfFont *font;
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_BG_WIN) != 0) {
        FIELD_MSGBG_DeleteBgWin((struct FieldBgWin *)SCRCMD_WORK_GetMsgWindow(cmdWork));
        font = SCRIPT_WORK_GetMsgData(scriptWork);
        SCRIPT_WORK_SetMsgData(scriptWork, 0);
        if (font != 0) {
            GF_FONT_Delete(font);
        }
        SCRCMD_WORK_SetMsgWindow(cmdWork, 0);
        SCRIPT_WORK_ResetCheckFlag(SCRIPT_FLAG_BG_WIN);
    }
}


int SCRCMD_MSGWIN_CmdBgWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    int msgId, winType;
    ScriptFieldParam *fieldParam;
    MsgBank *msgData;
    Strbuf *msgBuffer;
    WordSet *wordSet;
    Strbuf *tempBuffer;
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    msgId = VM_ReadU16(vm);
    winType = VM_ReadU16(vm);
    fieldParam = SCRIPT_WORK_ResetFieldParam(scriptWork);
    msgData = SCRCMD_WORK_GetMsgData(cmdWork);
    SCRCMD_WORK_SetMsgWindow(cmdWork, FIELD_MSGBG_CreateBgWin(fieldParam->mapSystem, winType));
    msgBuffer = SCRIPT_WORK_GetMsgBuffer(scriptWork);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    tempBuffer = SCRIPT_WORK_GetTempBuffer(scriptWork);
    MSGDATA_ReadString((struct MsgBank *)msgData, msgId, tempBuffer);
    WORDSET_CopyTaggedText(wordSet, msgBuffer, tempBuffer);
    VM_SetWait(vm, SCRCMD_MSGWIN_WaitBgWin);
    SCRIPT_WORK_SetCheckFlag(SCRIPT_FLAG_BG_WIN);
    return 1;
}


int SCRCMD_MSGWIN_CmdBgWinMsgFont(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    ScriptFieldParam *fieldParam, *fontFieldParam;
    int msgId, winType, heapId;
    MsgBank *msgData;
    GfFont *font;
    Strbuf *msgBuffer;
    WordSet *wordSet;
    Strbuf *tempBuffer;
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    fieldParam = SCRIPT_WORK_ResetFieldParam(scriptWork);
    msgId = VM_ReadU16(vm);
    winType = VM_ReadU16(vm);
    heapId = FIELDMAP_GetHeapId(fieldParam->fieldSystem);
    fontFieldParam = SCRIPT_WORK_ResetFieldParam(scriptWork);
    msgData = SCRCMD_WORK_GetMsgData(cmdWork);
    font = GF_FONT_Create(0x17, 4, 0, 0, heapId);
    SCRIPT_WORK_SetMsgData(scriptWork, font);
    SCRCMD_WORK_SetMsgWindow(cmdWork, FIELD_MSGBG_CreateBgWinFont(fontFieldParam->mapSystem, winType, font));
    msgBuffer = SCRIPT_WORK_GetMsgBuffer(scriptWork);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    tempBuffer = SCRIPT_WORK_GetTempBuffer(scriptWork);
    MSGDATA_ReadString((struct MsgBank *)msgData, msgId, tempBuffer);
    WORDSET_CopyTaggedText(wordSet, msgBuffer, tempBuffer);
    VM_SetWait(vm, SCRCMD_MSGWIN_WaitBgWin);
    SCRIPT_WORK_SetCheckFlag(SCRIPT_FLAG_BG_WIN);
    return 1;
}


int SCRCMD_MSGWIN_CmdCloseBgWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
SCRCMD_MSGWIN_CloseBgWin(cmdWork);
return 0;
}


int SCRCMD_MSGWIN_CleanupBgWin(ScriptCheckTask *task, int *state)
{
    SCRCMD_MSGWIN_CloseBgWin(task->cmdWork);
    return 1;
}


void SCRCMD_MSGWIN_CloseSpWin(ScrcmdWork *cmdWork)
{
    u32 checkFlag = SCRIPT_FLAG_SP_WIN;

    if (SCRIPT_WORK_CheckFlag(checkFlag)) {
        FIELD_MSGBG_DeleteSpWin((struct FieldSpWin *)SCRCMD_WORK_GetMsgWindow(cmdWork));
        SCRCMD_WORK_SetMsgWindow(cmdWork, 0);
        SCRIPT_WORK_ResetCheckFlag(checkFlag);
    }
}


int SCRCMD_MSGWIN_WaitSpWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
if (FIELD_MSGBG_SpWinWaitKey((struct FieldSpWin *)SCRCMD_WORK_GetMsgWindow(cmdWork)) == 1) {
    return 1;
}
return 0;
}


int SCRCMD_MSGWIN_CmdSpWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    int msgId, frameType;
    Strbuf *str;
    u8 x, y;
    ScriptFieldParam *fieldParam;
    u16 width, height;
    u8 **pcPtr = &vm->pc;
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    msgId = VM_ReadU16(vm);
    x = **pcPtr;
    (*pcPtr)++;
    y = **pcPtr;
    (*pcPtr)++;
    frameType = VM_ReadU16(vm);
    str = SCRCMD_MSGWIN_ExpandMessage(cmdWork, scriptWork, msgId);
    fieldParam = SCRIPT_WORK_ResetFieldParam(scriptWork);
    width = FIELD_MSGBG_GetStrWidthChars(fieldParam->mapSystem, str, 4);
    height = FIELD_MSGBG_GetStrHeightChars(fieldParam->mapSystem, str, 4);
    {
        FieldSpWin *spWin = FIELD_MSGBG_CreateSpWin(fieldParam->mapSystem, frameType, x, y, width, height);
        SCRCMD_WORK_SetMsgWindow(cmdWork, spWin);
        FIELD_MSGBG_SpWinPrintStr(spWin, 4, 4, str);
    }
    VM_SetWait(vm, SCRCMD_MSGWIN_WaitSpWin);
    SCRIPT_WORK_SetCheckFlag(SCRIPT_FLAG_SP_WIN);
    return 1;
}


int SCRCMD_MSGWIN_CmdCloseSpWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
SCRCMD_MSGWIN_CloseSpWin(cmdWork);
return 0;
}


int SCRCMD_MSGWIN_CleanupSpWin(ScriptCheckTask *task, int *state)
{
    SCRCMD_MSGWIN_CloseSpWin(task->cmdWork);
    return 1;
}


int SCRCMD_MSGWIN_CmdCloseAllWins(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_INFO_SYS_WIN)) {
        SCRCMD_MSGWIN_CloseInfoSysWin(cmdWork);
    }
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_PLAIN_WIN)) {
        SCRCMD_MSGWIN_ClosePlainWin(cmdWork);
    }
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_BG_WIN)) {
        SCRCMD_MSGWIN_CloseBgWin(cmdWork);
    }
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_SP_WIN)) {
        SCRCMD_MSGWIN_CloseSpWin(cmdWork);
    }
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_TALK_WIN)) {
        SCRCMD_MSGWIN_StartCloseTalkWin(vm, cmdWork);
    }
    return 1;
}


int SCRCMD_MSGWIN_WaitKeyWithCursor(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 keys;
    void *msgWin;

    keys = KEY_GetTrg();
    msgWin = SCRCMD_WORK_GetMsgWindow(cmdWork);
    if (keys & 3) {
        GFL_USE_PlaySeDefaultVolume(0x547);
        return 1;
    }
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_INFO_SYS_WIN)) {
        FIELD_MSGBG_SysWinDrawCursor(msgWin);
    } else if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_PLAIN_WIN)) {
        FIELD_MSGBG_PlainWinDrawCursor(msgWin);
    } else if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_TALK_WIN)) {
        FIELD_MSGBG_TalkWinDrawCursor(msgWin);
    } else {
        return 1;
    }
    return 0;
}


int SCRCMD_MSGWIN_CmdWaitMsgKey(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VM_SetWait(vm, SCRCMD_MSGWIN_WaitKeyWithCursor);
    return 1;
}


int SCRCMD_MSGWIN_CmdSetAutoMode(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptFieldParam *fieldParam = SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork));

    if (VM_ReadU16(vm)) {
        FIELD_MSGBG_SetAutoMode(fieldParam->mapSystem, 1);
        SCRIPT_WORK_SetCheckFlag(SCRIPT_FLAG_AUTO_MODE);
    } else {
        FIELD_MSGBG_SetAutoMode(fieldParam->mapSystem, 0);
        SCRIPT_WORK_ResetCheckFlag(SCRIPT_FLAG_AUTO_MODE);
    }
    return 0;
}


int SCRCMD_MSGWIN_CleanupAutoMode(ScriptCheckTask *task, int *state)
{
    ScriptFieldParam *fieldParam = SCRIPT_WORK_ResetFieldParam(task->scriptWork);
    u32 checkFlag = SCRIPT_FLAG_AUTO_MODE;

    if (SCRIPT_WORK_CheckFlag(checkFlag)) {
        FIELD_MSGBG_SetAutoMode(fieldParam->mapSystem, 0);
        SCRIPT_WORK_ResetCheckFlag(checkFlag);
    }
    return 1;
}


Strbuf *SCRCMD_MSGWIN_ExpandMessage(ScrcmdWork *cmdWork, ScriptWork *scriptWork, u32 msgId)
{
    MsgBank *msgData;
    Strbuf *msgBuffer;
    WordSet *wordSet;
    Strbuf *tempBuffer;

    msgData = SCRCMD_WORK_GetMsgData(cmdWork);
    msgBuffer = SCRIPT_WORK_GetMsgBuffer(scriptWork);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    tempBuffer = SCRIPT_WORK_GetTempBuffer(scriptWork);
    MSGDATA_ReadString((struct MsgBank *)msgData, msgId, tempBuffer);
    WORDSET_CopyTaggedText(wordSet, msgBuffer, tempBuffer);
    return msgBuffer;
}
