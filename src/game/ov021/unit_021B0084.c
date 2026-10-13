/*
 * file:     unit_021B0084.c
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
 *   func_020120F4  0x020120F4  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   func_0201EFA4  0x0201EFA4  thumb
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
 *   func_0215A630  0x0215A630  thumb  ov010
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   func_0215A624  0x0215A624  thumb  ov010
 *   FIELD_MSGBG_InfoSysWinMain  0x021910C0  thumb  ov021
 *   FIELD_MSGBG_InfoSysWinPrintStr  0x02191084  thumb  ov021
 *   VM_SetWait  0x020113D0  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   FIELD_MSGBG_InfoSysWinPrintStrNow  0x02191184  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELD_MSGBG_GetInfoSysWinBmpWin  0x021911B4  thumb  ov021
 *   func_020056BC  0x020056BC  thumb
 *   TIME_ICON_Create  0x0202EE30  thumb
 *   func_020127A4  0x020127A4  thumb
 *   FIELDMAP_GetInfoWindow  0x02188D48  thumb  ov021
 *   func_02045B38  0x02045B38  arm
 *   STRBUF_Create  0x020457B0  arm
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   func_0200C274  0x0200C274  thumb
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 *   FIELD_MSGBG_CreateMsgWin  0x02190708  thumb  ov021
 *   FIELDMAP_SetInfoWindow  0x02188D4C  thumb  ov021
 *   FIELD_MSGBG_MsgWinPrintStr  0x02190758  thumb  ov021
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   FIELD_MSGBG_ClearMsgWin  0x02190788  thumb  ov021
 *   func_02048AD0  0x02048AD0  arm
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_0207CA00  0x0207CA00  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   func_0206DF3C  0x0206DF3C  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   sBalloonUpVec     0x021D9390  data
 *   sBalloonOffsetTable     0x021D939C  data
 *   func_02048B0C  0x02048B0C  arm
 *   func_0207BCA0  0x0207BCA0  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0207B0A4  0x0207B0A4  arm
 *   func_0207B51C  0x0207B51C  arm
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_MSGBG_WaitTalkWinClose  0x021912F8  thumb  ov021
 *   FIELD_MSGBG_DeleteTalkWin  0x021912D8  thumb  ov021
 *   FIELD_MSGBG_ClearTalkWin  0x0219131C  thumb  ov021
 *   FIELD_MSGBG_AddTalkWin  0x0219129C  thumb  ov021
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb  ov010
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
 *   func_02008550  0x02008550  thumb
 *   func_0202A310  0x0202A310  thumb
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

#include "../arm9/script_vm_types.h"
#include "field_msgbg_types.h"

struct GameSystem;
struct GameData;
struct FieldMap;
struct FieldCamera;
struct FieldPlayer;
struct G3dCamera;
struct GameEvent;
struct ScriptWork;
struct ScrcmdWork;
struct WordSet;
struct MsgData;
struct Strbuf;
struct TimeIcon;
struct Mmdl;
struct MmdlSys;
struct MoneyData;
struct MainTaskList;

typedef struct ScrcmdWork ScrcmdWork;
typedef struct ScriptWork ScriptWork;
typedef struct GameEvent GameEvent;

typedef struct MtxFx33 {
    s32 m[9];
} MtxFx33;

typedef struct MtxFx43 {
    s32 m[12];
} MtxFx43;

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

/* Message system and field map of the running script (SCRIPT_WORK_ResetFieldParam). */
typedef struct ScriptFieldParam {
    FieldMsgBg *msgBg;              /* 0x00 */
    struct FieldMap *fieldMap;      /* 0x04 */
} ScriptFieldParam;

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

/* Argument of the window cleanup callbacks: the work sits in the second word. */
typedef struct ScrcmdWorkRef {
    void *reserved;                 /* 0x00 */
    ScrcmdWork *cmdWork;            /* 0x04 */
} ScrcmdWorkRef;

/* Argument of the auto mode cleanup callback: the script work sits in the third word. */
typedef struct ScriptWorkRef {
    void *reserved[2];              /* 0x00 */
    ScriptWork *scriptWork;         /* 0x08 */
} ScriptWorkRef;

/* Talk balloon placement kept in the command work (0x28 bytes). */
typedef struct BalloonWinWork {
    u16 objId;                      /* 0x00, map object the balloon follows (0xFF: player) */
    u16 talkIndex;                  /* 0x02, balloon slot passed to FIELD_MSGBG_AddTalkWin */
    VecFx32 pos;                    /* 0x04, mmdlPos + offset: the point the tail aims at */
    VecFx32 mmdlPos;                /* 0x10, last position of the map object */
    VecFx32 offset;                 /* 0x1C, offset from the object to the balloon */
} BalloonWinWork;

typedef struct MyStatus {
    u8 data[0x20];
} MyStatus;

typedef struct PlayerWork {
    u8 reserved[0x20];
    MyStatus myStatus;              /* 0x20 */
} PlayerWork;

extern struct Mmdl *FIELD_PLAYER_GetMmdl(struct FieldPlayer *fieldPlayer);
extern u16 FLDMMDL_GetDirDisp(struct Mmdl *mmdl);
extern struct GameData *func_020120F4(struct GameSystem *gameSystem);
extern ScriptWork *SCRCMD_WORK_GetScriptWork(ScrcmdWork *cmdWork);
extern ScriptFieldParam *SCRIPT_WORK_ResetFieldParam(ScriptWork *scriptWork);
extern u16 SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, ScrcmdWork *cmdWork);
extern u16 SCRCMD_WORK_GetHeapId(ScrcmdWork *cmdWork);
extern struct GameSystem *SCRCMD_WORK_GetGameSystem(ScrcmdWork *cmdWork);
extern void SCRIPT_SYS_CallEvent(ScriptWork *scriptWork, GameEvent *event);
extern u16 *SCRIPT_WORK_ReadWorkPointer(ScriptVm *vm, ScrcmdWork *cmdWork);
extern u16 FLDMMDL_GetObjId(struct Mmdl *mmdl);
extern struct GameData *SCRCMD_WORK_GetGameData(ScrcmdWork *cmdWork);
extern struct FieldMap *func_0201210C(struct GameSystem *gameSystem);
extern u16 func_02011330(ScriptVm *vm);
extern void SCRIPT_WORK_SetCheckFlag(int flag);
extern void VM_SetWait(ScriptVm *vm, ScrcmdWaitFn waitFn);
extern void SCRIPT_WORK_ResetCheckFlag(int flag);
extern void GFL_USE_PlaySeDefaultVolume(u32 seNo);
extern GameEvent *func_020122C0(struct GameSystem *gameSystem, GameEvent *parent, GameEventProc proc, unsigned int workSize);
extern void *func_020124E8(GameEvent *event);
extern struct WordSet *SCRIPT_WORK_GetWordSet(ScriptWork *scriptWork);
extern void func_0201EFA4(struct WordSet *wordSet, u32 index, u32 number, u32 digits, u32 dispType, u32 codeType);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);
extern void SCRCMD_WORK_SetWaitCount(ScrcmdWork *cmdWork, unsigned short count);
extern int SCRCMD_WORK_CountDownWait(ScrcmdWork *cmdWork);
extern FieldMsgBg *FIELDMAP_GetMsgBg(struct FieldMap *fieldMap);
extern FieldMenuFunc *FIELD_MSGBG_CreateYesNoMenu(FieldMsgBg *msgBg, u32 cursorPos);
extern int FIELD_MSGBG_YesNoMenuMain(FieldMenuFunc *menu);
extern int FIELD_MSGBG_DeleteMenuFunc(FieldMenuFunc *menu);
extern void SCRCMD_WORK_StartMenu(ScrcmdWork *cmdWork);
extern int SCRCMD_WORK_WaitMenuOrCancel(ScrcmdWork *cmdWork);
extern int SCRCMD_WORK_WaitMenu(ScrcmdWork *cmdWork);
extern u16 *SCRIPT_WORK_GetWorkPtr(ScriptWork *scriptWork, struct GameData *gameData, unsigned int varId);
extern u32 SCRCMD_WORK_InitMenu(ScrcmdWork *cmdWork, u32 x, u32 y, u32 cursorPos, u32 cancelable, u32 alignRight, u16 *result, struct WordSet *wordSet, struct MsgData *msgData);
extern struct MsgData *SCRCMD_WORK_GetMsgData(ScrcmdWork *cmdWork);
extern struct Strbuf *SCRIPT_WORK_GetMsgBuffer(ScriptWork *scriptWork);
extern struct Strbuf *SCRIPT_WORK_GetTempBuffer(ScriptWork *scriptWork);
extern void SCRCMD_WORK_AddMenuItem(ScrcmdWork *cmdWork, int msgId, int helpMsgId, int param, struct Strbuf *str, struct Strbuf *tmp);
extern int SCRIPT_WORK_CheckFlag(int flag);
extern void *SCRCMD_WORK_GetMsgWindow(ScrcmdWork *cmdWork);
extern void FIELD_MSGBG_ClearInfoSysWin(FieldSysWin *sysWin);
extern u32 SCRCMD_WORK_GetWindowState(ScrcmdWork *cmdWork);
extern FieldSysWin *FIELD_MSGBG_CreateInfoSysWin(FieldMsgBg *msgBg, struct MsgData *msgData, u32 y);
extern void SCRCMD_WORK_SetWindowState(ScrcmdWork *cmdWork, u32 windowState);
extern u32 SCRCMD_WORK_SetMsgWindow(ScrcmdWork *cmdWork, void *msgWin);
extern int FIELD_MSGBG_DeleteInfoSysWin(FieldSysWin *sysWin);
extern struct TimeIcon *func_0215A630(ScrcmdWork *cmdWork);
extern void TIME_ICON_Delete(struct TimeIcon *timeIcon);
extern void func_0215A624(ScrcmdWork *cmdWork, struct TimeIcon *timeIcon);
extern u32 FIELD_MSGBG_InfoSysWinMain(FieldSysWin *sysWin);
extern void FIELD_MSGBG_InfoSysWinPrintStr(FieldSysWin *sysWin, u32 x, u16 y, struct Strbuf *str);
extern void func_02045CAC(struct MsgData *msgData, u32 msgId, struct Strbuf *dest);
extern void func_0201F250(struct WordSet *wordSet, struct Strbuf *dest, struct Strbuf *src);
extern void FIELD_MSGBG_InfoSysWinPrintStrNow(FieldSysWin *sysWin, u32 x, int y, struct Strbuf *str);
extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern struct BmpWin *FIELD_MSGBG_GetInfoSysWinBmpWin(FieldSysWin *sysWin);
extern struct MainTaskList *func_020056BC(void);
extern struct TimeIcon *TIME_ICON_Create(struct MainTaskList *taskList, struct BmpWin *bmpWin, u32 x, u32 y, u32 heapId);
extern PlayerWork *func_020127A4(struct GameData *gameData);
extern FieldMsgWin *FIELDMAP_GetInfoWindow(struct FieldMap *fieldMap);
extern struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern struct MoneyData *GAME_DATA_GetMiscSave(struct GameData *gameData);
extern u32 func_0200C274(struct MoneyData *moneyData);
extern int FIELD_MSGBG_DeleteMsgWin(FieldMsgWin *msgWin);
extern FieldMsgWin *FIELD_MSGBG_CreateMsgWin(FieldMsgBg *msgBg, struct MsgData *msgData, u16 x, u16 y, u16 width, u16 height);
extern void FIELDMAP_SetInfoWindow(struct FieldMap *fieldMap, FieldMsgWin *msgWin);
extern void FIELD_MSGBG_MsgWinPrintStr(FieldMsgWin *msgWin, int x, int y, struct Strbuf *str);
extern void STRBUF_Delete(struct Strbuf *str);
extern u32 MSGDATA_Delete(struct MsgData *msgData);
extern void FIELD_MSGBG_ClearMsgWin(FieldMsgWin *msgWin);
extern void func_02048AD0(struct G3dCamera *camera);
extern void func_02048B30(struct G3dCamera *camera, VecFx32 *out);
extern void func_02048AE8(struct G3dCamera *camera, VecFx32 *out);
extern void func_0207CA00(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void VEC_Normalize(const VecFx32 *vec, VecFx32 *out);
extern void func_0207CAE8(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void func_0206DF3C(VecFx32 *pos, u32 *x, u32 *z);
extern void func_02048B0C(struct G3dCamera *camera, VecFx32 *out);
extern void func_0207BCA0(VecFx32 *eye, VecFx32 *up, VecFx32 *target, MtxFx43 *out);
extern void func_02082B60(MtxFx43 *src, MtxFx33 *dest);
extern void func_0207B0A4(MtxFx33 *src, MtxFx33 *dest);
extern void func_0207B51C(VecFx32 *vec, MtxFx33 *mtx, VecFx32 *out);
extern void FLDMMDL_GetPos(const struct Mmdl *mmdl, VecFx32 *out);
extern u32 FIELD_MSGBG_WaitTalkWinClose(FieldTalkWin *talkWin);
extern int FIELD_MSGBG_DeleteTalkWin(FieldTalkWin *talkWin);
extern int FIELD_MSGBG_ClearTalkWin(FieldTalkWin *talkWin);
extern FieldTalkWin *FIELD_MSGBG_AddTalkWin(FieldMsgBg *msgBg, int index, VecFx32 *pos, struct Strbuf *str, u32 winType, u32 tailType);
extern struct MmdlSys *SCRCMD_WORK_GetOccupyInfo(ScrcmdWork *cmdWork);
extern BalloonWinWork *SCRCMD_WORK_GetWordSetWork(ScrcmdWork *cmdWork);
extern struct Mmdl *FLDMMDL_SysSearchObjId(struct MmdlSys *mmdlSys, u32 objId);
extern struct FieldCamera *FIELDMAP_GetCamera(struct FieldMap *fieldMap);
extern struct G3dCamera *FIELD_CAMERA_GetG3dCamera(struct FieldCamera *fieldCamera);
extern u8 SCRCMD_WORK_GetWindowKind(ScrcmdWork *cmdWork);
extern u32 FIELD_MSGBG_TalkWinPrintStr(FieldTalkWin *talkWin, struct Strbuf *str);
extern void MI_CpuFill8(void *dest, int value, int size);
extern void SCRCMD_WORK_SetWindowKind(ScrcmdWork *cmdWork, u8 windowKind);
extern u32 FIELD_MSGBG_TalkWinMain(FieldTalkWin *talkWin);
extern struct Mmdl *SCRIPT_WORK_GetTargetObj(ScriptWork *scriptWork);
extern u8 func_02008550(const MyStatus *myStatus);
extern void func_0202A310(int key1, int key2, struct Strbuf *dest, u32 heapId);
extern u32 FIELD_MSGBG_PlainWinMain(FieldPlainWin *plainWin);
extern void FIELD_MSGBG_ClearPlainWin(FieldPlainWin *plainWin);
extern FieldPlainWin *FIELD_MSGBG_CreatePlainWin(FieldMsgBg *msgBg, struct MsgData *msgData, u32 winType, u16 x, u16 y, u16 width, u16 height);
extern void FIELD_MSGBG_PlainWinPrintStream(FieldPlainWin *plainWin, u32 x, u16 y, struct Strbuf *str);
extern int FIELD_MSGBG_DeletePlainWin(FieldPlainWin *plainWin);
extern void FIELD_MSGBG_GetStrSizeChars(FieldMsgBg *msgBg, struct Strbuf *str, u8 *width, u8 *height);
extern void FIELD_MSGBG_AddSubMsgWinStr(FieldMsgBg *msgBg, struct Strbuf *str, u32 id, u8 x, u8 y, u8 width, u8 height);
extern void FIELD_MSGBG_DeleteSubMsgWin(FieldMsgBg *msgBg, u32 id);
extern int FIELD_MSGBG_ExistsSubMsgWin(FieldMsgBg *msgBg);
extern void FIELD_MSGBG_DeleteAllSubMsgWin(FieldMsgBg *msgBg);
extern u32 FIELD_MSGBG_BgWinMain(FieldBgWin *bgWin, struct Strbuf *str);
extern void FIELD_MSGBG_DeleteBgWin(FieldBgWin *bgWin);
extern struct GfFont *SCRIPT_WORK_GetMsgData(ScriptWork *scriptWork);
extern void SCRIPT_WORK_SetMsgData(ScriptWork *scriptWork, struct GfFont *font);
extern u32 GF_FONT_Delete(struct GfFont *font);
extern FieldBgWin *FIELD_MSGBG_CreateBgWin(FieldMsgBg *msgBg, int winType);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, unsigned int heapId);
extern FieldBgWin *FIELD_MSGBG_CreateBgWinFont(FieldMsgBg *msgBg, u32 winType, struct GfFont *font);
extern void FIELD_MSGBG_DeleteSpWin(FieldSpWin *spWin);
extern int FIELD_MSGBG_SpWinWaitKey(FieldSpWin *spWin);
extern u32 FIELD_MSGBG_GetStrWidthChars(FieldMsgBg *msgBg, struct Strbuf *str, int margin);
extern u32 FIELD_MSGBG_GetStrHeightChars(FieldMsgBg *msgBg, struct Strbuf *str, u32 margin);
extern FieldSpWin *FIELD_MSGBG_CreateSpWin(FieldMsgBg *msgBg, u32 frameType, u32 x, u16 y, u16 width, u16 height);
extern void FIELD_MSGBG_SpWinPrintStr(FieldSpWin *spWin, u16 x, u16 y, struct Strbuf *str);
u32 KEY_GetTrg(void);
void FIELD_MSGBG_SysWinDrawCursor(FieldSysWin *sysWin);
void FIELD_MSGBG_PlainWinDrawCursor(FieldPlainWin *plainWin);
void FIELD_MSGBG_TalkWinDrawCursor(FieldTalkWin *talkWin);
extern void FIELD_MSGBG_SetAutoMode(FieldMsgBg *msgBg, u8 autoMode);
int SCRCMD_MSGWIN_YesNoEventMain(GameEvent *event, int *seq, void *work);
GameEvent *SCRCMD_MSGWIN_CreateYesNoEvent(struct GameSystem *gameSystem, ScrcmdWork *cmdWork, u16 *result);
int SCRCMD_MSGWIN_CmdYesNoWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_MenuEventMain(GameEvent *event, int *seq, void *work);
GameEvent *SCRCMD_MSGWIN_CreateMenuEvent(struct GameSystem *gameSystem, ScrcmdWork *cmdWork, int allowCancel);
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
int SCRCMD_MSGWIN_CleanupInfoSysWin(ScrcmdWorkRef *ref);
int SCRCMD_MSGWIN_CmdOpenMoneyWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdUpdateMoneyWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdCloseMoneyWin(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_MSGWIN_CalcBalloonOffset(const VecFx32 *mmdlPos, VecFx32 *out, struct G3dCamera *camera, struct FieldCamera *fieldCamera);
void SCRCMD_MSGWIN_RotateOffsetByCamera(VecFx32 *offset, struct G3dCamera *camera);
void SCRCMD_MSGWIN_SelectBalloonOffset(const VecFx32 *mmdlPos, VecFx32 *out, struct G3dCamera *camera, struct FieldCamera *fieldCamera, u8 windowKind);
void SCRCMD_MSGWIN_GetBalloonOffset(const VecFx32 *mmdlPos, VecFx32 *out, struct G3dCamera *camera, struct FieldCamera *fieldCamera, u8 windowKind);
void SCRCMD_MSGWIN_GetBalloonTailParams(int windowState, int *talkIndex, int *tailType);
int SCRCMD_MSGWIN_GetBalloonSide(struct Mmdl *playerMmdl, const VecFx32 *targetPos);
int SCRCMD_MSGWIN_WaitTalkWinClose(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_MSGWIN_StartCloseTalkWin(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_MSGWIN_CloseTalkWin(ScrcmdWork *cmdWork);
void SCRCMD_MSGWIN_OpenTalkWin(ScrcmdWork *cmdWork, FieldMsgBg *msgBg, int talkIndex, VecFx32 *pos, struct Strbuf *str, u32 winType, u32 tailType);
void SCRCMD_MSGWIN_UpdateBalloonPos(ScrcmdWork *cmdWork, int forceUpdate);
int SCRCMD_MSGWIN_OpenBalloonWinMsg(ScrcmdWork *cmdWork, u16 objId, u16 msgFileId, u16 msgId, u16 windowKind, int winType);
int SCRCMD_MSGWIN_WaitBalloonWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdBalloonWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdBalloonWinMsgTarget(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdBalloonWinMsgGender(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdBalloonWinMsgSkipArg(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdCloseTalkWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CleanupTalkWin(ScrcmdWorkRef *ref);
int SCRCMD_MSGWIN_CmdBalloonWinSavedText(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_WaitPlainWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_OpenPlainWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork, int winType);
void SCRCMD_MSGWIN_ClosePlainWin(ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdPlainWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdPlainWinMsgFrame1(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdClosePlainWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CleanupPlainWin(ScrcmdWorkRef *ref);
int SCRCMD_MSGWIN_CmdAddSubWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdDeleteSubWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_MSGWIN_DeleteAllSubWins(ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CleanupSubWins(ScrcmdWorkRef *ref);
int SCRCMD_MSGWIN_WaitBgWin(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_MSGWIN_CloseBgWin(ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdBgWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdBgWinMsgFont(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdCloseBgWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CleanupBgWin(ScrcmdWorkRef *ref);
void SCRCMD_MSGWIN_CloseSpWin(ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_WaitSpWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdSpWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdCloseSpWin(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CleanupSpWin(ScrcmdWorkRef *ref);
int SCRCMD_MSGWIN_CmdCloseAllWins(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_WaitKeyWithCursor(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdWaitMsgKey(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CmdSetAutoMode(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MSGWIN_CleanupAutoMode(ScriptWorkRef *ref);
struct Strbuf *SCRCMD_MSGWIN_ExpandMessage(ScrcmdWork *cmdWork, ScriptWork *scriptWork, u32 msgId);
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
int SCRCMD_MSGWIN_YesNoEventMain(GameEvent *event, int *seq, void *work)
{
    YesNoEventWork *yesNo = work;

    SCRCMD_WORK_GetScriptWork(yesNo->cmdWork);
    switch (*seq) {
    case 0:
        SCRCMD_WORK_SetWaitCount(yesNo->cmdWork, 8);
        (*seq)++;
    case 1:
        if (SCRCMD_WORK_CountDownWait(yesNo->cmdWork) == 1) {
            yesNo->menu = FIELD_MSGBG_CreateYesNoMenu(FIELDMAP_GetMsgBg(func_0201210C(SCRCMD_WORK_GetGameSystem(yesNo->cmdWork))), 0);
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


GameEvent *SCRCMD_MSGWIN_CreateYesNoEvent(struct GameSystem *gameSystem, ScrcmdWork *cmdWork, u16 *result)
{
    GameEvent *event;
    YesNoEventWork *yesNo;

    event = func_020122C0(gameSystem, 0, SCRCMD_MSGWIN_YesNoEventMain, 0xc);
    yesNo = func_020124E8(event);
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


int SCRCMD_MSGWIN_MenuEventMain(GameEvent *event, int *seq, void *work)
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


GameEvent *SCRCMD_MSGWIN_CreateMenuEvent(struct GameSystem *gameSystem, ScrcmdWork *cmdWork, int allowCancel)
{
    GameEvent *event;
    MenuEventWork *menu;

    event = func_020122C0(gameSystem, 0, SCRCMD_MSGWIN_MenuEventMain, 8);
    menu = func_020124E8(event);
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
    struct GameData *gameData;

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
    result = SCRIPT_WORK_GetWorkPtr(scriptWork, gameData, func_02011330(vm));
    SCRCMD_WORK_InitMenu(cmdWork, x, y, cursorPos, cancelable, 0, result, SCRIPT_WORK_GetWordSet(scriptWork), 0);
    return 1;
}


int SCRCMD_MSGWIN_CmdInitMenuMsgData(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u8 *pc;
    u32 cursorPos;
    u16 *result;
    ScriptWork *scriptWork;
    struct GameData *gameData;
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
    result = SCRIPT_WORK_GetWorkPtr(scriptWork, gameData, func_02011330(vm));
    SCRCMD_WORK_InitMenu(cmdWork, x, y, cursorPos, cancelable, 0, result, SCRIPT_WORK_GetWordSet(scriptWork), SCRCMD_WORK_GetMsgData(cmdWork));
    return 1;
}


int SCRCMD_MSGWIN_CmdInitMenuMsgDataMode1(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u8 *pc;
    u32 cursorPos;
    u16 *result;
    ScriptWork *scriptWork;
    struct GameData *gameData;
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
    result = SCRIPT_WORK_GetWorkPtr(scriptWork, gameData, func_02011330(vm));
    SCRCMD_WORK_InitMenu(cmdWork, x, y, cursorPos, cancelable, 1, result, SCRIPT_WORK_GetWordSet(scriptWork), SCRCMD_WORK_GetMsgData(cmdWork));
    return 1;
}


int SCRCMD_MSGWIN_CmdAddMenuItem(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 msgId, helpMsgId, param;
    ScriptWork *scriptWork;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    msgId = func_02011330(vm);
    helpMsgId = func_02011330(vm);
    param = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRCMD_WORK_AddMenuItem(cmdWork, msgId, helpMsgId, param, SCRIPT_WORK_GetMsgBuffer(scriptWork), SCRIPT_WORK_GetTempBuffer(scriptWork));
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
    struct MsgData *msgData;
    u32 windowState, winY;
    ScriptFieldParam *param;
    FieldSysWin *sysWin;

    winY = 1;
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_INFO_SYS_WIN)) {
        FIELD_MSGBG_ClearInfoSysWin(SCRCMD_WORK_GetMsgWindow(cmdWork));
        return;
    }
    param = SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork));
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
    sysWin = FIELD_MSGBG_CreateInfoSysWin(param->msgBg, msgData, winY);
    SCRCMD_WORK_SetWindowState(cmdWork, windowState);
    SCRCMD_WORK_SetMsgWindow(cmdWork, sysWin);
    SCRIPT_WORK_SetCheckFlag(SCRIPT_FLAG_INFO_SYS_WIN);
}


void SCRCMD_MSGWIN_CloseInfoSysWin(ScrcmdWork *cmdWork)
{
    struct TimeIcon *timeIcon;

    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_INFO_SYS_WIN)) {
        FIELD_MSGBG_DeleteInfoSysWin(SCRCMD_WORK_GetMsgWindow(cmdWork));
        timeIcon = func_0215A630(cmdWork);
        if (timeIcon) {
            TIME_ICON_Delete(timeIcon);
            func_0215A624(cmdWork, 0);
        }
        SCRCMD_WORK_SetMsgWindow(cmdWork, 0);
        SCRIPT_WORK_ResetCheckFlag(SCRIPT_FLAG_INFO_SYS_WIN);
    }
}


int SCRCMD_MSGWIN_WaitInfoSysWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
if (FIELD_MSGBG_InfoSysWinMain(SCRCMD_WORK_GetMsgWindow(cmdWork)) == 1) {
    return 1;
}
return 0;
}


int SCRCMD_MSGWIN_CmdInfoSysWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 msgId;
    struct Strbuf *str;
    ScriptWork *scriptWork;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    msgId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRCMD_MSGWIN_OpenInfoSysWin(cmdWork, (u8)func_02011330(vm));
    str = SCRCMD_MSGWIN_ExpandMessage(cmdWork, scriptWork, msgId);
    FIELD_MSGBG_InfoSysWinPrintStr(SCRCMD_WORK_GetMsgWindow(cmdWork), 0, 0, str);
    VM_SetWait(vm, SCRCMD_MSGWIN_WaitInfoSysWin);
    return 1;
}


int SCRCMD_MSGWIN_CmdInfoSysWinMsgNow(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 msgId;
    struct Strbuf *str;
    struct MsgData *msgData;
    struct WordSet *wordSet;
    struct Strbuf *tempBuffer;
    ScriptWork *scriptWork;
    FieldSysWin *sysWin;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    str = SCRIPT_WORK_GetMsgBuffer(scriptWork);
    msgId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRCMD_MSGWIN_OpenInfoSysWin(cmdWork, (u8)func_02011330(vm));
    msgData = SCRCMD_WORK_GetMsgData(cmdWork);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    tempBuffer = SCRIPT_WORK_GetTempBuffer(scriptWork);
    func_02045CAC(msgData, msgId, tempBuffer);
    func_0201F250(wordSet, str, tempBuffer);
    sysWin = SCRCMD_WORK_GetMsgWindow(cmdWork);
    FIELD_MSGBG_ClearInfoSysWin(sysWin);
    FIELD_MSGBG_InfoSysWinPrintStrNow(sysWin, 0, 0, str);
    return 0;
}


int SCRCMD_MSGWIN_CmdSetTimeIcon(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 heapId, noTimeIcon;
    struct TimeIcon *timeIcon;

    heapId = FIELDMAP_GetHeapId(func_0201210C(SCRCMD_WORK_GetGameSystem(cmdWork)));
    noTimeIcon = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    if (!SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_INFO_SYS_WIN)) {
        return 0;
    }
    timeIcon = func_0215A630(cmdWork);
    if (timeIcon) {
        TIME_ICON_Delete(timeIcon);
        func_0215A624(cmdWork, 0);
    }
    if (noTimeIcon == 0) {
        struct BmpWin *bmpWin = FIELD_MSGBG_GetInfoSysWinBmpWin(SCRCMD_WORK_GetMsgWindow(cmdWork));
        func_0215A624(cmdWork, TIME_ICON_Create(func_020056BC(), bmpWin, 0xf, 0x10, heapId));
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
int SCRCMD_MSGWIN_CleanupInfoSysWin(ScrcmdWorkRef *ref)
{
    SCRCMD_MSGWIN_CloseInfoSysWin(ref->cmdWork);
    return 1;
}


int SCRCMD_MSGWIN_CmdOpenMoneyWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 x, y;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct GameData *gameData;
    FieldMsgBg *msgBg;
    FieldMsgWin *oldWin;
    ScriptWork *scriptWork;
    struct WordSet *wordSet;
    struct Strbuf *tempBuffer;
    u32 heapId;
    struct MsgData *msgData;
    FieldMsgWin *moneyWin;
    struct Strbuf *str;
    u32 money;

    x = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    y = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = func_020120F4(gameSystem);
    func_020127A4(gameData);
    fieldMap = func_0201210C(gameSystem);
    msgBg = FIELDMAP_GetMsgBg(fieldMap);
    oldWin = FIELDMAP_GetInfoWindow(fieldMap);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    tempBuffer = SCRIPT_WORK_GetTempBuffer(scriptWork);
    heapId = FIELDMAP_GetHeapId(fieldMap);
    msgData = func_02045B38(0, 3, 0x9e, heapId);
    str = STRBUF_Create(0x80, heapId);
    money = func_0200C274(GAME_DATA_GetMiscSave(gameData));
    if (oldWin != 0)
        FIELD_MSGBG_DeleteMsgWin(oldWin);
    moneyWin = FIELD_MSGBG_CreateMsgWin(msgBg, msgData, (u16)(x - 9), (u16)y, 9, 2);
    FIELDMAP_SetInfoWindow(fieldMap, moneyWin);
    func_0201EFA4(wordSet, 2, money, 7, 1, 1);
    func_02045CAC(msgData, 1, tempBuffer);
    func_0201F250(wordSet, str, tempBuffer);
    FIELD_MSGBG_MsgWinPrintStr(moneyWin, 0, 0, str);
    STRBUF_Delete(str);
    MSGDATA_Delete(msgData);
    return 0;
}


int SCRCMD_MSGWIN_CmdUpdateMoneyWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct GameData *gameData;
    FieldMsgWin *moneyWin;
    ScriptWork *scriptWork;
    struct WordSet *wordSet;
    struct Strbuf *tempBuffer;
    u32 heapId;
    struct MsgData *msgData;
    struct Strbuf *str;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = func_020120F4(gameSystem);
    func_020127A4(gameData);
    fieldMap = func_0201210C(gameSystem);
    moneyWin = FIELDMAP_GetInfoWindow(fieldMap);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    tempBuffer = SCRIPT_WORK_GetTempBuffer(scriptWork);
    heapId = FIELDMAP_GetHeapId(fieldMap);
    msgData = func_02045B38(0, 3, 0x9e, heapId);
    str = STRBUF_Create(0x80, heapId);
    func_0201EFA4(wordSet, 2, func_0200C274(GAME_DATA_GetMiscSave(gameData)), 7, 1, 1);
    func_02045CAC(msgData, 1, tempBuffer);
    func_0201F250(wordSet, str, tempBuffer);
    FIELD_MSGBG_ClearMsgWin(moneyWin);
    FIELD_MSGBG_MsgWinPrintStr(moneyWin, 0, 0, str);
    STRBUF_Delete(str);
    MSGDATA_Delete(msgData);
    return 0;
}


int SCRCMD_MSGWIN_CmdCloseMoneyWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct FieldMap *fieldMap = func_0201210C(SCRCMD_WORK_GetGameSystem(cmdWork));
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
void SCRCMD_MSGWIN_CalcBalloonOffset(const VecFx32 *mmdlPos, VecFx32 *out, struct G3dCamera *camera, struct FieldCamera *fieldCamera)
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
    func_02048AD0(camera);
    func_02048B30(camera, &target);
    func_02048AE8(camera, &eye);
    func_0207CA00(&target, &eye, &forward);
    forwardFlat = forward;
    forwardFlat.y = column = 0;
    VEC_Normalize(&forwardFlat, &forwardFlat);
    func_0207CAE8(&forwardFlat, &sBalloonUpVec, &right);
    func_0207CAE8(&forward, &right, &shift);
    VEC_Normalize(&shift, &shift);
    pos.x += shift.x;
    pos.y += shift.y;
    pos.z += shift.z;
    func_0206DF3C(&pos, &tileX, &tileZ);
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


void SCRCMD_MSGWIN_RotateOffsetByCamera(VecFx32 *offset, struct G3dCamera *camera)
{
    VecFx32 eye, up, target;
    MtxFx43 viewMtx;
    MtxFx33 invRotation;

    func_02048AE8(camera, &eye);
    func_02048B0C(camera, &up);
    func_02048B30(camera, &target);
    func_0207BCA0(&eye, &up, &target, &viewMtx);
    func_02082B60(&viewMtx, &invRotation);
    func_0207B0A4(&invRotation, &invRotation);
    func_0207B51C(offset, &invRotation, offset);
}


void SCRCMD_MSGWIN_SelectBalloonOffset(const VecFx32 *mmdlPos, VecFx32 *out, struct G3dCamera *camera, struct FieldCamera *fieldCamera, u8 windowKind)
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


void SCRCMD_MSGWIN_GetBalloonOffset(const VecFx32 *mmdlPos, VecFx32 *out, struct G3dCamera *camera, struct FieldCamera *fieldCamera, u8 windowKind)
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


int SCRCMD_MSGWIN_GetBalloonSide(struct Mmdl *playerMmdl, const VecFx32 *targetPos)
{
    VecFx32 playerPos;
    int placement = 2;

    FLDMMDL_GetPos(playerMmdl, &playerPos);
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
if (FIELD_MSGBG_WaitTalkWinClose(SCRCMD_WORK_GetMsgWindow(cmdWork)) == 1) {
    SCRCMD_WORK_SetMsgWindow(cmdWork, 0);
    SCRIPT_WORK_ResetCheckFlag(SCRIPT_FLAG_TALK_WIN);
    return 1;
}
return 0;
}


void SCRCMD_MSGWIN_StartCloseTalkWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_TALK_WIN) != 0) {
        FIELD_MSGBG_DeleteTalkWin(SCRCMD_WORK_GetMsgWindow(cmdWork));
        VM_SetWait(vm, SCRCMD_MSGWIN_WaitTalkWinClose);
    }
}


void SCRCMD_MSGWIN_CloseTalkWin(ScrcmdWork *cmdWork)
{
    u32 flag = SCRIPT_FLAG_TALK_WIN;

    if (SCRIPT_WORK_CheckFlag(flag)) {
        FIELD_MSGBG_ClearTalkWin(SCRCMD_WORK_GetMsgWindow(cmdWork));
        SCRCMD_WORK_SetMsgWindow(cmdWork, 0);
        SCRIPT_WORK_ResetCheckFlag(flag);
    }
}


void SCRCMD_MSGWIN_OpenTalkWin(ScrcmdWork *cmdWork, FieldMsgBg *msgBg, int talkIndex, VecFx32 *pos, struct Strbuf *str, u32 winType, u32 tailType)
{
    SCRCMD_WORK_SetMsgWindow(cmdWork, FIELD_MSGBG_AddTalkWin(msgBg, talkIndex, pos, str, winType, tailType));
    SCRIPT_WORK_SetCheckFlag(SCRIPT_FLAG_TALK_WIN);
}


void SCRCMD_MSGWIN_UpdateBalloonPos(ScrcmdWork *cmdWork, int forceUpdate)
{
    struct MmdlSys *mmdlSys = SCRCMD_WORK_GetOccupyInfo(cmdWork);
    BalloonWinWork *balloon = SCRCMD_WORK_GetWordSetWork(cmdWork);
    struct Mmdl *mmdl = FLDMMDL_SysSearchObjId(mmdlSys, balloon->objId);
    VecFx32 mmdlPos;
    if (mmdl != 0) {
        FLDMMDL_GetDirDisp(mmdl);
        FLDMMDL_GetPos(mmdl, &mmdlPos);
        if (forceUpdate == 1 || mmdlPos.x != balloon->mmdlPos.x || mmdlPos.y != balloon->mmdlPos.y || mmdlPos.z != balloon->mmdlPos.z) {
            struct FieldCamera *fieldCamera;
            struct G3dCamera *g3dCamera;
            balloon->mmdlPos = mmdlPos;
            fieldCamera = FIELDMAP_GetCamera(func_0201210C(SCRCMD_WORK_GetGameSystem(cmdWork)));
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
    struct MsgData *scriptMsgData;
    ScriptWork *scriptWork;
    ScriptFieldParam *param;
    struct MmdlSys *mmdlSys;
    struct Mmdl *playerMmdl, *targetMmdl;
    struct Strbuf *msgBuffer;
    struct WordSet *wordSet;
    struct Strbuf *tempBuffer;
    struct MsgData *fileMsgData;
    int windowState;
    BalloonWinWork *balloon;
    VecFx32 targetPos;
    int talkIndex, tailType;

    windowState = windowKind;
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    scriptMsgData = SCRCMD_WORK_GetMsgData(cmdWork);
    param = SCRIPT_WORK_ResetFieldParam(scriptWork);
    mmdlSys = SCRCMD_WORK_GetOccupyInfo(cmdWork);
    playerMmdl = FLDMMDL_SysSearchObjId(mmdlSys, 0xff);
    targetMmdl = FLDMMDL_SysSearchObjId(mmdlSys, objId);
    if (targetMmdl == 0) {
        return 0;
    }
    msgBuffer = SCRIPT_WORK_GetMsgBuffer(scriptWork);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    tempBuffer = SCRIPT_WORK_GetTempBuffer(scriptWork);
    if (msgFileId == 0x400) {
        func_02045CAC(scriptMsgData, msgId, tempBuffer);
    } else {
        fileMsgData = func_02045B38(0, 3, msgFileId, SCRCMD_WORK_GetHeapId(cmdWork));
        func_02045CAC(fileMsgData, msgId, tempBuffer);
        MSGDATA_Delete(fileMsgData);
    }
    func_0201F250(wordSet, msgBuffer, tempBuffer);
    balloon = SCRCMD_WORK_GetWordSetWork(cmdWork);
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_TALK_WIN) != 0) {
        FIELD_MSGBG_TalkWinPrintStr(SCRCMD_WORK_GetMsgWindow(cmdWork), msgBuffer);
    } else {
        MI_CpuFill8(balloon, 0, 0x28);
        balloon->objId = objId;
        if (windowKind == 0) {
            SCRCMD_WORK_GetWindowState(cmdWork);
            FLDMMDL_GetPos(targetMmdl, &targetPos);
            windowState = SCRCMD_MSGWIN_GetBalloonSide(playerMmdl, &targetPos);
        }
        SCRCMD_MSGWIN_GetBalloonTailParams(windowState, &talkIndex, &tailType);
        balloon->talkIndex = talkIndex;
        SCRCMD_WORK_SetWindowState(cmdWork, (u8)windowState);
        SCRCMD_WORK_SetWindowKind(cmdWork, windowKind);
        SCRCMD_MSGWIN_UpdateBalloonPos(cmdWork, 1);
        SCRCMD_MSGWIN_OpenTalkWin(cmdWork, param->msgBg, talkIndex, &balloon->pos, msgBuffer, winType, tailType);
    }
    return 1;
}


int SCRCMD_MSGWIN_WaitBalloonWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    FieldTalkWin *talkWin;
    int done;

    talkWin = SCRCMD_WORK_GetMsgWindow(cmdWork);
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
    struct Mmdl *targetMmdl;
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
    if (func_02008550(&func_020127A4(SCRCMD_WORK_GetGameData(cmdWork))->myStatus)) {
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
    SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
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


int SCRCMD_MSGWIN_CleanupTalkWin(ScrcmdWorkRef *ref)
{
    SCRCMD_MSGWIN_CloseTalkWin(ref->cmdWork);
    return 1;
}


int SCRCMD_MSGWIN_CmdBalloonWinSavedText(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    ScriptFieldParam *param;
    int key1, key2, objId;
    struct Strbuf *msgBuffer;
    int placement, talkIndex;
    struct MmdlSys *mmdlSys;
    struct FieldPlayer *fieldPlayer;
    struct Mmdl *playerMmdl;
    BalloonWinWork *balloon;
    VecFx32 targetPos;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    param = SCRIPT_WORK_ResetFieldParam(scriptWork);
    key1 = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    key2 = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    msgBuffer = SCRIPT_WORK_GetMsgBuffer(scriptWork);
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_TALK_WIN) != 0) {
        return 1;
    }
    func_0202A310(key1, key2, msgBuffer, SCRCMD_WORK_GetHeapId(cmdWork));
    if (FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetOccupyInfo(cmdWork), objId) == 0) {
        objId = 0xff;
    }
    balloon = SCRCMD_WORK_GetWordSetWork(cmdWork);
    talkIndex = 0;
    MI_CpuFill8(balloon, 0, 0x28);
    balloon->objId = objId;
    fieldPlayer = FIELDMAP_GetFieldPlayer(param->fieldMap);
    mmdlSys = SCRCMD_WORK_GetOccupyInfo(cmdWork);
    playerMmdl = FIELD_PLAYER_GetMmdl(fieldPlayer);
    FLDMMDL_GetPos(FLDMMDL_SysSearchObjId(mmdlSys, balloon->objId), &targetPos);
    placement = SCRCMD_MSGWIN_GetBalloonSide(playerMmdl, &targetPos);
    if (placement != 1) {
        talkIndex = 1;
    }
    balloon->talkIndex = talkIndex;
    SCRCMD_MSGWIN_UpdateBalloonPos(cmdWork, 1);
    SCRCMD_MSGWIN_OpenTalkWin(cmdWork, param->msgBg, talkIndex, &balloon->pos, msgBuffer, 0, 0);
    SCRCMD_WORK_SetWindowState(cmdWork, placement);
    VM_SetWait(vm, SCRCMD_MSGWIN_WaitBalloonWin);
    return 1;
}


int SCRCMD_MSGWIN_WaitPlainWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
if (FIELD_MSGBG_PlainWinMain(SCRCMD_WORK_GetMsgWindow(cmdWork)) == 1) {
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
    struct Strbuf *str;
    ScriptFieldParam *param;
    u8 *pc;
    FieldPlainWin *plainWin;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    param = SCRIPT_WORK_ResetFieldParam(scriptWork);
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
        plainWin = SCRCMD_WORK_GetMsgWindow(cmdWork);
        FIELD_MSGBG_ClearPlainWin(plainWin);
    } else {
        plainWin = FIELD_MSGBG_CreatePlainWin(param->msgBg, 0, winType, 1, winY, 0x1e, 4);
        SCRCMD_WORK_SetMsgWindow(cmdWork, plainWin);
    }
    FIELD_MSGBG_PlainWinPrintStream(plainWin, 8, 0, str);
    SCRIPT_WORK_SetCheckFlag(SCRIPT_FLAG_PLAIN_WIN);
    VM_SetWait(vm, SCRCMD_MSGWIN_WaitPlainWin);
    return 1;
}


void SCRCMD_MSGWIN_ClosePlainWin(ScrcmdWork *cmdWork)
{
    int flag = SCRIPT_FLAG_PLAIN_WIN;
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_PLAIN_WIN) != 0) {
        FIELD_MSGBG_DeletePlainWin(SCRCMD_WORK_GetMsgWindow(cmdWork));
        SCRCMD_WORK_SetMsgWindow(cmdWork, 0);
        SCRIPT_WORK_ResetCheckFlag(flag);
    }
}


int SCRCMD_MSGWIN_CmdPlainWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork) { return SCRCMD_MSGWIN_OpenPlainWinMsg(vm, cmdWork, 0); }


int SCRCMD_MSGWIN_CmdPlainWinMsgFrame1(ScriptVm *vm, ScrcmdWork *cmdWork) { return SCRCMD_MSGWIN_OpenPlainWinMsg(vm, cmdWork, 1); }


int SCRCMD_MSGWIN_CmdClosePlainWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
SCRCMD_MSGWIN_ClosePlainWin(cmdWork);
return 0;
}


int SCRCMD_MSGWIN_CleanupPlainWin(ScrcmdWorkRef *ref)
{
    SCRCMD_MSGWIN_ClosePlainWin(ref->cmdWork);
    return 1;
}


int SCRCMD_MSGWIN_CmdAddSubWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct Strbuf *str;
    struct MsgData *msgData;
    struct WordSet *wordSet;
    struct Strbuf *tempBuffer;
    ScriptWork *scriptWork;
    u16 msgId, id;
    ScriptFieldParam *param;
    int x, y;
    u8 width;
    u8 height;
    u8 textWidth;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    param = SCRIPT_WORK_ResetFieldParam(scriptWork);
    msgId = func_02011330(vm);
    x = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    y = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    id = func_02011330(vm);
    height = 2;
    str = STRBUF_Create(0x40, SCRCMD_WORK_GetHeapId(cmdWork));
    msgData = SCRCMD_WORK_GetMsgData(cmdWork);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    tempBuffer = SCRIPT_WORK_GetTempBuffer(scriptWork);
    func_02045CAC(msgData, msgId, tempBuffer);
    func_0201F250(wordSet, str, tempBuffer);
    FIELD_MSGBG_GetStrSizeChars(param->msgBg, str, &width, &height);
    textWidth = width;
    if (x + textWidth > 0x1f) {
        x = (u16)(0x1f - textWidth);
    }
    if (y + height > 0x18) {
        y = 4;
        height = y;
    }
    FIELD_MSGBG_AddSubMsgWinStr(param->msgBg, str, id, x, y, textWidth, height);
    STRBUF_Delete(str);
    SCRIPT_WORK_SetCheckFlag(SCRIPT_FLAG_SUB_WIN);
    return 0;
}


int SCRCMD_MSGWIN_CmdDeleteSubWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptFieldParam *param = SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork));

    FIELD_MSGBG_DeleteSubMsgWin(param->msgBg, func_02011330(vm));
    if (FIELD_MSGBG_ExistsSubMsgWin(param->msgBg) == 0) {
        SCRIPT_WORK_ResetCheckFlag(SCRIPT_FLAG_SUB_WIN);
    }
    return 0;
}


void SCRCMD_MSGWIN_DeleteAllSubWins(ScrcmdWork *cmdWork)
{
    u32 flag = SCRIPT_FLAG_SUB_WIN;

    if (SCRIPT_WORK_CheckFlag(flag)) {
        FIELD_MSGBG_DeleteAllSubMsgWin(SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork))->msgBg);
        SCRIPT_WORK_ResetCheckFlag(flag);
    }
}


int SCRCMD_MSGWIN_CleanupSubWins(ScrcmdWorkRef *ref)
{
    SCRCMD_MSGWIN_DeleteAllSubWins(ref->cmdWork);
    return 1;
}


int SCRCMD_MSGWIN_WaitBgWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct Strbuf *tempBuffer = SCRIPT_WORK_GetMsgBuffer(SCRCMD_WORK_GetScriptWork(cmdWork));

    if (FIELD_MSGBG_BgWinMain(SCRCMD_WORK_GetMsgWindow(cmdWork), tempBuffer) == 1) {
        return 1;
    }
    return 0;
}


void SCRCMD_MSGWIN_CloseBgWin(ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GfFont *font;
    if (SCRIPT_WORK_CheckFlag(SCRIPT_FLAG_BG_WIN) != 0) {
        FIELD_MSGBG_DeleteBgWin(SCRCMD_WORK_GetMsgWindow(cmdWork));
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
    ScriptFieldParam *param;
    struct MsgData *msgData;
    struct Strbuf *msgBuffer;
    struct WordSet *wordSet;
    struct Strbuf *tempBuffer;
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    msgId = func_02011330(vm);
    winType = func_02011330(vm);
    param = SCRIPT_WORK_ResetFieldParam(scriptWork);
    msgData = SCRCMD_WORK_GetMsgData(cmdWork);
    SCRCMD_WORK_SetMsgWindow(cmdWork, FIELD_MSGBG_CreateBgWin(param->msgBg, winType));
    msgBuffer = SCRIPT_WORK_GetMsgBuffer(scriptWork);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    tempBuffer = SCRIPT_WORK_GetTempBuffer(scriptWork);
    func_02045CAC(msgData, msgId, tempBuffer);
    func_0201F250(wordSet, msgBuffer, tempBuffer);
    VM_SetWait(vm, SCRCMD_MSGWIN_WaitBgWin);
    SCRIPT_WORK_SetCheckFlag(SCRIPT_FLAG_BG_WIN);
    return 1;
}


int SCRCMD_MSGWIN_CmdBgWinMsgFont(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    ScriptFieldParam *param, *fontParam;
    int msgId, winType, heapId;
    struct MsgData *msgData;
    struct GfFont *font;
    struct Strbuf *msgBuffer;
    struct WordSet *wordSet;
    struct Strbuf *tempBuffer;
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    param = SCRIPT_WORK_ResetFieldParam(scriptWork);
    msgId = func_02011330(vm);
    winType = func_02011330(vm);
    heapId = FIELDMAP_GetHeapId(param->fieldMap);
    fontParam = SCRIPT_WORK_ResetFieldParam(scriptWork);
    msgData = SCRCMD_WORK_GetMsgData(cmdWork);
    font = GF_FONT_Create(0x17, 4, 0, 0, heapId);
    SCRIPT_WORK_SetMsgData(scriptWork, font);
    SCRCMD_WORK_SetMsgWindow(cmdWork, FIELD_MSGBG_CreateBgWinFont(fontParam->msgBg, winType, font));
    msgBuffer = SCRIPT_WORK_GetMsgBuffer(scriptWork);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    tempBuffer = SCRIPT_WORK_GetTempBuffer(scriptWork);
    func_02045CAC(msgData, msgId, tempBuffer);
    func_0201F250(wordSet, msgBuffer, tempBuffer);
    VM_SetWait(vm, SCRCMD_MSGWIN_WaitBgWin);
    SCRIPT_WORK_SetCheckFlag(SCRIPT_FLAG_BG_WIN);
    return 1;
}


int SCRCMD_MSGWIN_CmdCloseBgWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
SCRCMD_MSGWIN_CloseBgWin(cmdWork);
return 0;
}


int SCRCMD_MSGWIN_CleanupBgWin(ScrcmdWorkRef *ref)
{
    SCRCMD_MSGWIN_CloseBgWin(ref->cmdWork);
    return 1;
}


void SCRCMD_MSGWIN_CloseSpWin(ScrcmdWork *cmdWork)
{
    u32 flag = SCRIPT_FLAG_SP_WIN;

    if (SCRIPT_WORK_CheckFlag(flag)) {
        FIELD_MSGBG_DeleteSpWin(SCRCMD_WORK_GetMsgWindow(cmdWork));
        SCRCMD_WORK_SetMsgWindow(cmdWork, 0);
        SCRIPT_WORK_ResetCheckFlag(flag);
    }
}


int SCRCMD_MSGWIN_WaitSpWin(ScriptVm *vm, ScrcmdWork *cmdWork)
{
if (FIELD_MSGBG_SpWinWaitKey(SCRCMD_WORK_GetMsgWindow(cmdWork)) == 1) {
    return 1;
}
return 0;
}


int SCRCMD_MSGWIN_CmdSpWinMsg(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    int msgId, frameType;
    struct Strbuf *str;
    u8 x, y;
    ScriptFieldParam *param;
    u16 width, height;
    u8 **pcPtr = &vm->pc;
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    msgId = func_02011330(vm);
    x = **pcPtr;
    (*pcPtr)++;
    y = **pcPtr;
    (*pcPtr)++;
    frameType = func_02011330(vm);
    str = SCRCMD_MSGWIN_ExpandMessage(cmdWork, scriptWork, msgId);
    param = SCRIPT_WORK_ResetFieldParam(scriptWork);
    width = FIELD_MSGBG_GetStrWidthChars(param->msgBg, str, 4);
    height = FIELD_MSGBG_GetStrHeightChars(param->msgBg, str, 4);
    {
        FieldSpWin *spWin = FIELD_MSGBG_CreateSpWin(param->msgBg, frameType, x, y, width, height);
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


int SCRCMD_MSGWIN_CleanupSpWin(ScrcmdWorkRef *ref)
{
    SCRCMD_MSGWIN_CloseSpWin(ref->cmdWork);
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
    ScriptFieldParam *param = SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork));

    if (func_02011330(vm)) {
        FIELD_MSGBG_SetAutoMode(param->msgBg, 1);
        SCRIPT_WORK_SetCheckFlag(SCRIPT_FLAG_AUTO_MODE);
    } else {
        FIELD_MSGBG_SetAutoMode(param->msgBg, 0);
        SCRIPT_WORK_ResetCheckFlag(SCRIPT_FLAG_AUTO_MODE);
    }
    return 0;
}


int SCRCMD_MSGWIN_CleanupAutoMode(ScriptWorkRef *ref)
{
    ScriptFieldParam *param = SCRIPT_WORK_ResetFieldParam(ref->scriptWork);
    u32 flag = SCRIPT_FLAG_AUTO_MODE;

    if (SCRIPT_WORK_CheckFlag(flag)) {
        FIELD_MSGBG_SetAutoMode(param->msgBg, 0);
        SCRIPT_WORK_ResetCheckFlag(flag);
    }
    return 1;
}


struct Strbuf *SCRCMD_MSGWIN_ExpandMessage(ScrcmdWork *cmdWork, ScriptWork *scriptWork, u32 msgId)
{
    struct MsgData *msgData;
    struct Strbuf *msgBuffer;
    struct WordSet *wordSet;
    struct Strbuf *tempBuffer;

    msgData = SCRCMD_WORK_GetMsgData(cmdWork);
    msgBuffer = SCRIPT_WORK_GetMsgBuffer(scriptWork);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    tempBuffer = SCRIPT_WORK_GetTempBuffer(scriptWork);
    func_02045CAC(msgData, msgId, tempBuffer);
    func_0201F250(wordSet, msgBuffer, tempBuffer);
    return msgBuffer;
}
