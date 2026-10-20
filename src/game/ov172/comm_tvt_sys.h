#ifndef GAME_OV172_COMM_TVT_SYS_H
#define GAME_OV172_COMM_TVT_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of comm_tvt_sys.c, prototypes copied from their definitions. */

struct CtvtComm;
struct DrawCanvas;
struct ArcHandle;
struct Unit;
struct MsgBank;
struct PrintQueue;
struct TaskMenu;
struct PeerObj;
struct ProcSys;

#include "../ov172/ctvt_camera_types.h"
#include "../ov172/ctvt_types.h"
#include "../types.h"

CtvtCamView *COMM_TVT_SYS_GetCamView(CtvtWork *work);
struct CtvtComm *COMM_TVT_SYS_GetComm(CtvtWork *work);
int COMM_TVT_SYS_GetTalkStatus(CtvtWork *work);
struct DrawCanvas *COMM_TVT_SYS_GetSprites(CtvtWork *work);
CtvtLaunchParams *COMM_TVT_SYS_GetLaunchParams(CtvtWork *work);
u16 COMM_TVT_SYS_GetHeapId(CtvtWork *work);
struct ArcHandle *COMM_TVT_SYS_GetArc(CtvtWork *work);
u32 COMM_TVT_SYS_GetResId(CtvtWork *work, int index);
struct Unit *COMM_TVT_SYS_GetClactUnit(CtvtWork *work);
s32 COMM_TVT_SYS_GetReturnedFromChild(CtvtWork *work);
void COMM_TVT_SYS_SetReturnedFromChild(CtvtWork *work, s32 value);
u32 COMM_TVT_SYS_GetFont(CtvtWork *work);
struct MsgBank *COMM_TVT_SYS_GetMsgData(CtvtWork *work);
struct PrintQueue *COMM_TVT_SYS_GetPrintQue(CtvtWork *work);
struct TaskMenu *COMM_TVT_SYS_GetTaskMenu(CtvtWork *work);
u8 COMM_TVT_SYS_GetMemberCount(CtvtWork *work);
void COMM_TVT_SYS_SetMemberCount(CtvtWork *work, u32 count);
int COMM_TVT_SYS_GetLayoutMode(CtvtWork *work);
s32 COMM_TVT_SYS_GetHalfRes(CtvtWork *work);
void COMM_TVT_SYS_ApplyHalfRes(CtvtWork *work, s32 halfRes);
void COMM_TVT_SYS_ToggleHalfRes(CtvtWork *work);
void COMM_TVT_SYS_SetHalfRes(CtvtWork *work, s32 halfRes);
u8 COMM_TVT_SYS_GetSelfSlot(CtvtWork *work);
void COMM_TVT_SYS_SetSelfSlot(CtvtWork *work, u32 slot);
s32 COMM_TVT_SYS_GetMessageActive(CtvtWork *work);
void COMM_TVT_SYS_SetMessageActive(CtvtWork *work, s32 value);
s32 COMM_TVT_SYS_GetViewSwapped(CtvtWork *work);
void COMM_TVT_SYS_ToggleViewSwapped(CtvtWork *work);
s32 COMM_TVT_SYS_GetInputLocked(CtvtWork *work);
void COMM_TVT_SYS_SetInputLocked(CtvtWork *work, s32 value);
s32 COMM_TVT_SYS_GetEndRequested(CtvtWork *work);
void COMM_TVT_SYS_SetEndRequested(CtvtWork *work, s32 value);
int COMM_TVT_SYS_IsLaunchModeCall(CtvtWork *work);
s32 COMM_TVT_SYS_GetHostBusy(CtvtWork *work);
void COMM_TVT_SYS_ClearHostBusy(CtvtWork *work);
s32 COMM_TVT_SYS_GetCameraBusy(CtvtWork *work);
void COMM_TVT_SYS_SetCameraBusy(CtvtWork *work, s32 value);
int COMM_TVT_SYS_IsNetIdle(void);
struct TaskMenu *COMM_TVT_SYS_OpenConfirmMenu(CtvtWork *work);
void COMM_TVT_SYS_ClearNameWindows(CtvtWork *work);
void COMM_TVT_SYS_ClearAndTransferNameWindows(CtvtWork *work);
void COMM_TVT_SYS_PlaceSlotMarker(CtvtWork *work, u8 idx);
void COMM_TVT_SYS_HideSlotMarker(CtvtWork *work);
void COMM_TVT_SYS_SavePeerRecord(CtvtWork *work, struct PeerObj *peer);
void COMM_TVT_SYS_CreateTimeIcon(CtvtWork *work, void *arg);
void COMM_TVT_SYS_DeleteTimeIcon(CtvtWork *work);
int COMM_TVT_SYS_ProcInit(struct ProcSys *proc, int unused, CtvtLaunchParams *launch);
int COMM_TVT_SYS_ProcExit(struct ProcSys *proc, void *unused, int keepLaunch, CtvtWork *work);
int COMM_TVT_SYS_ProcMain(void *proc, void *unused1, void *unused2, CtvtWork *work);
/* END mkheaders: generated region */

#endif
