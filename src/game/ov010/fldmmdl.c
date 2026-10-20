/*
 * file:     fldmmdl.c
 * unit:     yes
 * function: FLDMMDL_CreateSys, FLDMMDL_DeleteSys, FLDMMDL_ClearObjCodeParamCache, FLDMMDL_SetupSysProc, FLDMMDL_ReleaseSysProc, FLDMMDL_DeleteSysProc, FLDMMDL_UpdateSysProc, FLDMMDL_UpdateSysBlAct, FLDMMDL_SysWaitBlActResLoad, FLDMMDL_SetAreaIdRef, FLDMMDL_AddMmdlCore, FLDMMDL_AddMmdl, FLDMMDL_AddMmdlParam, FLDMMDL_AddMmdlHeaderList, FLDMMDL_AddMmdlHeaderById, FLDMMDL_DeleteMmdl, FLDMMDL_DeleteAllMmdl, FLDMMDL_SetHeaderParams, FLDMMDL_SetHeaderPos, FLDMMDL_InitWithHeader, FLDMMDL_SetupRailPosFromHeader, FLDMMDL_SetGridPosFromHeader, FLDMMDL_InitWork, FLDMMDL_InitDir, FLDMMDL_InitMoveProcList, FLDMMDL_RestartMoveTcb, FLDMMDL_InitMove, FLDMMDL_UpdateMove, FLDMMDL_SysPushAll, FLDMMDL_SysPopAll, FLDMMDL_ExecMove, FLDMMDL_MoveTcbProc, FLDMMDL_UpdateDraw, FLDMMDL_CheckPossibleAcmd, FLDMMDL_SetAcmd, FLDMMDL_SetLocalAcmd, FLDMMDL_CheckEndAcmd, FLDMMDL_EndAcmd, FLDMMDL_FreeAcmd, FLDMMDL_SysCheckStatusBit, FLDMMDL_SysSetStatusBit, FLDMMDL_SysClearStatusBit, FLDMMDL_SysGetMmdlMax, FLDMMDL_SysGetTcbPriority, FLDMMDL_SysGetHeapId, FLDMMDL_SysIncMmdlCount, FLDMMDL_SysDecMmdlCount, FLDMMDL_SysGetTcbSys, FLDMMDL_SysGetResArcHandle, FLDMMDL_SysSetBlActCont, FLDMMDL_SysGetBlActCont, FLDMMDL_SysSetG3dObjCont, FLDMMDL_SysGetG3dObjCont, FLDMMDL_SysGetG3dMapper, FLDMMDL_SysGetNogridMapper, FLDMMDL_SysGetFieldMap, FLDMMDL_SysGetAreaId, FLDMMDL_SetStatusBit, FLDMMDL_ClearStatusBit, FLDMMDL_CheckStatusBit, FLDMMDL_GetMoveBit, FLDMMDL_SetMoveBit, FLDMMDL_ClearMoveBit, FLDMMDL_CheckMoveBit, FLDMMDL_SetObjId, FLDMMDL_GetObjId, FLDMMDL_SetZoneId, FLDMMDL_GetZoneId, FLDMMDL_SetObjCode, FLDMMDL_GetObjCode, FLDMMDL_SetMoveCode, FLDMMDL_GetMoveCode, FLDMMDL_SetEventType, FLDMMDL_GetEventType, FLDMMDL_SetEventFlag, FLDMMDL_GetEventFlag, FLDMMDL_SetEventId, FLDMMDL_GetEventId, FLDMMDL_IsAliasEventId, FLDMMDL_GetDirHeader, FLDMMDL_SetDirDisp, FLDMMDL_SetDirDispCheckPause, FLDMMDL_GetDirDisp, FLDMMDL_GetDirDispOld, FLDMMDL_SetDirMove, FLDMMDL_GetDirMove, FLDMMDL_SetDirAll, FLDMMDL_SetParam, FLDMMDL_GetParam, FLDMMDL_SetMoveLimitX, FLDMMDL_GetMoveLimitX, FLDMMDL_SetMoveLimitZ, FLDMMDL_GetMoveLimitZ, FLDMMDL_SetDrawStatus, FLDMMDL_GetDrawStatus, FLDMMDL_GetMmdlSys, FLDMMDL_InitMoveProcWork, FLDMMDL_GetMoveProcWork, FLDMMDL_InitMoveSubProcWork, FLDMMDL_GetMoveSubProcWork, FLDMMDL_InitMoveCmdWork, FLDMMDL_GetMoveCmdWork, FLDMMDL_InitDrawProcWork, FLDMMDL_GetDrawProcWork, FLDMMDL_CallMoveInitProc, FLDMMDL_CallMoveProc, FLDMMDL_CallMoveDeleteProc, FLDMMDL_CallMoveRecoverProc, FLDMMDL_CallDrawInitProc, FLDMMDL_CallDrawProc, FLDMMDL_CallDrawDeleteProc, FLDMMDL_CallDrawPushProc, FLDMMDL_CallDrawPopProc, FLDMMDL_CallDrawGetProc, FLDMMDL_SetAcmdCode, FLDMMDL_GetAcmdCode, FLDMMDL_SetAcmdSeq, FLDMMDL_IncAcmdSeq, FLDMMDL_GetAcmdSeq, FLDMMDL_SetNowAttr, FLDMMDL_GetNowAttr, FLDMMDL_SetOldAttr, FLDMMDL_GetOldAttr, FLDMMDL_GetGridInitX, FLDMMDL_SetGridInitX, FLDMMDL_SetGridInitY, FLDMMDL_GetGridInitZ, FLDMMDL_SetGridInitZ, FLDMMDL_GetGridOldX, FLDMMDL_SetGridOldX, FLDMMDL_GetGridOldY, FLDMMDL_SetGridOldY, FLDMMDL_GetGridOldZ, FLDMMDL_SetGridOldZ, FLDMMDL_GetGridNowPos, FLDMMDL_GetGridNowX, FLDMMDL_SetGridNowX, FLDMMDL_AddGridNowX, FLDMMDL_GetGridNowY, FLDMMDL_SetGridNowY, FLDMMDL_AddGridNowY, FLDMMDL_GetGridNowZ, FLDMMDL_SetGridNowZ, FLDMMDL_AddGridNowZ, FLDMMDL_GetPosPtr, FLDMMDL_GetPos, FLDMMDL_SetPos, FLDMMDL_GetPosY, FLDMMDL_GetDrawOffset, FLDMMDL_SetDrawOffset, FLDMMDL_GetDrawOffsetOutside, FLDMMDL_SetDrawOffsetOutside, FLDMMDL_GetAttrOffset, FLDMMDL_SetAttrOffset, FLDMMDL_GetBlActCont, FLDMMDL_GetSizeWidth, FLDMMDL_GetSizeDepth, FLDMMDL_GetModelOffset, FLDMMDL_SysCheckDrawInit, FLDMMDL_SysSetDrawInit, FLDMMDL_SysSetDrawEnable, FLDMMDL_SysIsDrawEnable, FLDMMDL_SysPauseMove, FLDMMDL_SysResumeMove, FLDMMDL_CheckSysStatusBit, FLDMMDL_CheckStatusBitUse, FLDMMDL_OnMoveBitMove, FLDMMDL_OffMoveBitMove, FLDMMDL_CheckMoveBitMove, FLDMMDL_OnMoveBitMoveStart, FLDMMDL_OffMoveBitMoveEnd, FLDMMDL_OnMoveBitDrawInitComp, FLDMMDL_OffMoveBitDrawInitComp, FLDMMDL_CheckMoveBitDrawInitComp, FLDMMDL_CheckStatusBitVanish, FLDMMDL_SetStatusBitVanish, FLDMMDL_SetStatusBitFellowHit, FLDMMDL_OnMoveBitMovePause, FLDMMDL_OffMoveBitMovePause, FLDMMDL_CheckMoveBitMovePause, FLDMMDL_CheckDrawInitComp, FLDMMDL_SetStatusBitHeightGetOff, FLDMMDL_CheckStatusBitHeightGetOff, FLDMMDL_SetStatusBitZoneDeleteOff, FLDMMDL_SetStatusBitAlias, FLDMMDL_CheckStatusBitAlias, FLDMMDL_SetMoveBitSplash, FLDMMDL_CheckMoveBitSplash, FLDMMDL_CheckStatusBitAttrOffsetOff, FLDMMDL_SetMoveBitReflect, FLDMMDL_CheckMoveBitReflect, FLDMMDL_CheckMoveBitAcmd, FLDMMDL_SetMoveBitSysPauseOff, FLDMMDL_CheckMoveBitSysPauseOff, FLDMMDL_SetStatusBitAttrGetOff, FLDMMDL_CheckStatusBitAttrGetOff, FLDMMDL_SetMoveBitAttrEffectOff, FLDMMDL_SetMoveBitShadowVanish, FLDMMDL_CheckMoveBitShadowVanish, FLDMMDL_SysSearchUseMmdl, FLDMMDL_SysSearchGridPosList, FLDMMDL_SysSearchGridPos, FLDMMDL_SysSearchGridPosHeight, FLDMMDL_SysSearchMoveCode, FLDMMDL_SysSearchObjId, FLDMMDL_SysSearchPlayer, FLDMMDL_SysGetFreeMmdl, FLDMMDL_SysDeleteZoneChangeMmdl, FLDMMDL_AddMoveTcb, FLDMMDL_DeleteMoveTcb, FLDMMDL_CheckSameObjCodeOther, FLDMMDL_InitPosition, FLDMMDL_InitGridPosition, FLDMMDL_ChangeHeader, FLDMMDL_ChangeMoveCode, FLDMMDL_InitDraw, FLDMMDL_SetDrawProcList, FLDMMDL_ResetDrawStatusBits, FLDMMDL_ClearMmdlWork, FLDMMDL_ResetMoveStart, FLDMMDL_GetCheckInfo, FLDMMDL_CheckCheckInfo, FLDMMDL_ChangeObjCode, FLDMMDL_OpenObjCodeArc, FLDMMDL_CloseObjCodeArc, FLDMMDL_SysLoadObjCodeParamCache, FLDMMDL_GetCachedObjCodeParam, FLDMMDL_GetCachedObjCodeCount, FLDMMDL_LoadObjCodeParam, FLDMMDL_LoadMmdlObjCodeParam, FLDMMDL_GetObjCodeParam, FLDMMDL_GetObjCodeParamBlActRes, FLDMMDL_GetObjCodeParamMdlRes, FLDMMDL_GetRealObjCode, FLDMMDL_GetEventWorkObjCode, FLDMMDL_GetMoveProcList, FLDMMDL_GetDrawProcList, FLDMMDL_HeaderIsEventIdNone, FLDMMDL_CheckEventFlagBit, FLDMMDL_NormalizeEventType, FLDMMDL_MoveInitProcDummy, FLDMMDL_MoveProcDummy, FLDMMDL_MoveDeleteProcDummy, FLDMMDL_MoveRecoverProcDummy
 * address:  0x0216CC58
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldmmdl.c at 0x0216BFD4 and 0x0216CC58 (__FILE__ anchors: namein_setup.c up to 0x0216CC40, fldmmdl.c from 0x0216CC58).
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   d_02172B48     0x02172B48  data  ov010  a1
 *   TCB_GetTaskOffset  0x02030CB0  arm
 *   TCB_Init  0x02030CBC  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   TCB_Noop  0x02030DA4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   FLDMMDL_ACMD_DeleteDrawSys  0x02197C4C  thumb
 *   TCB_Main  0x02030D28  arm
 *   FLDMMDL_BLACT_Update  0x0219C5FC  thumb
 *   FLDMMDL_BLACT_RegisterLoadedRes  0x0219C624  thumb
 *   FLDMMDL_BLACT_IsReservePending  0x0219C630  thumb
 *   OS_WaitInterrupt  0x02087A3C  arm
 *   FLDMMDL_HasMovedPos  0x0216E51C  thumb  ov010
 *   FLDMMDL_MOVE_SetStatusPauseDraw 0x021642F8 thumb ov010
 *   FLDMMDL_MOVE_RequestRailMove 0x02164304 thumb ov010
 *   FLDMMDL_GetMovedPos  0x0216E544  thumb  ov010
 *   FLDMMDL_MOVE_SetupMove  0x02163010  thumb  ov010
 *   FLDMMDL_RAIL_MOVE_InitMove  0x0219D6B8  thumb
 *   FLDMMDL_MOVE_UpdateMove   0x02163028  thumb  ov010
 *   FLDMMDL_RAIL_MOVE_UpdateMove   0x0219D6CC  thumb
 *   FLDMMDL_ACMD_DrawIfInitialized  0x02197C78  thumb
 *   FLDMMDL_MOVE_IsGridInObjectRect  0x02163C04  thumb  ov010
 *   TCB_AddTask  0x02030DA8  arm
 *   TCB_DeleteTask  0x02030EAC  arm
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 *   FLDMMDL_MOVE_UpdateHeight  0x02164010  thumb  ov010
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   FLDMMDL_ObjCodeToTableIndex 0x0200F128 thumb
 *   ARC_TOOL_ReadHandleMemberRange 0x0204944C arm
 *   ZONEDATA_GetEventWorkAddress 0x020143CC thumb
 *   d_021D5E04  0x021D5E04  data  ov021  a4
 *   d_021D770C  0x021D770C  data  ov021  a4
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 */
#include "../types.h"
#include "fldmmdl_types.h"

/* Result block of a grid position search: count, then up to 16 models. */
typedef struct MmdlSearchList {
    int count;
    Mmdl *mmdl[16];
} MmdlSearchList;

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/mi_memory.h"
struct TcbSystem;
#include "../arm9/arc_tool.h"
#include "../ov021/fldmmdl_acmd.h"
#include "../ov021/fldmmdl_blact.h"
#include "../arm9/os_system.h"
extern int FLDMMDL_HasMovedPos();
extern void FLDMMDL_MOVE_SetStatusPauseDraw(Mmdl *mmdl);
extern void FLDMMDL_MOVE_RequestRailMove(Mmdl *mmdl, const MmdlHeader *header);
#include "fldmmdl_poslog.h"
struct Mmdl;
extern void FLDMMDL_MOVE_SetupMove(struct Mmdl*);
#include "../ov021/fldmmdl_rail_move.h"
extern void FLDMMDL_MOVE_UpdateMove(Mmdl *mmdl);
extern int FLDMMDL_MOVE_IsGridInObjectRect(struct Mmdl *mmdl, s32 gridX, s32 gridZ, s32 checkNext);
struct TcbTask;
#include "../arm9/tcb_list.h"
struct TcbTask;
extern void FLDMMDL_MOVE_UpdateOldGridPos(Mmdl *mmdl);
extern s32 FLDMMDL_MOVE_UpdateHeight(Mmdl *mmdl);
#include "../arm9/fldmmdl_save.h"
struct ArcHandle;
struct EventWork;
#include "../arm9/zonedata.h"
MmdlSys *FLDMMDL_CreateSys(int heapId, int mmdlMax, void *saveData);
void FLDMMDL_DeleteSys(MmdlSys *sys);
void FLDMMDL_ClearObjCodeParamCache(MmdlSys *sys);
void FLDMMDL_SetupSysProc(MmdlSys *sys, int heapId, void *gameData, void *fieldMap, void *g3dMapper, void *nogridMapper);
void FLDMMDL_ReleaseSysProc(MmdlSys *sys);
void FLDMMDL_DeleteSysProc(MmdlSys *sys);
void FLDMMDL_UpdateSysProc(MmdlSys *sys);
void FLDMMDL_UpdateSysBlAct(MmdlSys *sys);
void FLDMMDL_SysWaitBlActResLoad(MmdlSys *sys);
void FLDMMDL_SetAreaIdRef(MmdlSys *sys, const unsigned short *areaIdRef);
Mmdl *FLDMMDL_AddMmdlCore(MmdlSys *sys, const MmdlHeader *src, int zoneId, void *evWork);
Mmdl *FLDMMDL_AddMmdl(MmdlSys *sys, const MmdlHeader *header, int zoneId);
Mmdl *FLDMMDL_AddMmdlParam(MmdlSys *sys, u16 gridX, u16 gridZ, u16 dir, u16 objId, u16 objCode, u16 moveCode, int zoneId);
void FLDMMDL_AddMmdlHeaderList(MmdlSys *sys, const MmdlHeader *header, int zoneId, u32 count, void *evWork);
Mmdl *FLDMMDL_AddMmdlHeaderById(MmdlSys *sys, const MmdlHeader *header, int zoneId, int count, void *evWork, u32 objId);
void FLDMMDL_DeleteMmdl(Mmdl *mmdl);
void FLDMMDL_DeleteAllMmdl(MmdlSys *sys);
void FLDMMDL_SetHeaderParams(Mmdl *mmdl, const MmdlHeader *header);
void FLDMMDL_SetHeaderPos(Mmdl *mmdl, const MmdlHeader *header);
void FLDMMDL_InitWithHeader(Mmdl *mmdl, const MmdlHeader *header, void *evWork, MmdlSys *sys);
void FLDMMDL_SetupRailPosFromHeader(Mmdl *mmdl, const MmdlHeader *header, int unused);
void FLDMMDL_SetGridPosFromHeader(Mmdl *mmdl, const MmdlHeader *header);
void FLDMMDL_InitWork(Mmdl *mmdl, MmdlSys *sys, int zoneId);
void FLDMMDL_InitDir(Mmdl *mmdl);
void FLDMMDL_InitMoveProcList(Mmdl *mmdl);
void FLDMMDL_RestartMoveTcb(MmdlSys *sys, Mmdl *mmdl);
void FLDMMDL_InitMove(MmdlSys *sys, Mmdl *mmdl);
void FLDMMDL_UpdateMove(Mmdl *mmdl);
void FLDMMDL_SysPushAll(MmdlSys *sys);
void FLDMMDL_SysPopAll(MmdlSys *sys);
void FLDMMDL_ExecMove(Mmdl *mmdl);
void FLDMMDL_MoveTcbProc(struct TcbTask *tcb, void *work);
void FLDMMDL_UpdateDraw(Mmdl *mmdl);
int FLDMMDL_CheckPossibleAcmd(Mmdl *mmdl);
void FLDMMDL_SetAcmd(Mmdl *mmdl, u16 code);
void FLDMMDL_SetLocalAcmd(Mmdl *mmdl, u16 code);
int FLDMMDL_CheckEndAcmd(Mmdl *mmdl);
int FLDMMDL_EndAcmd(Mmdl *mmdl);
void FLDMMDL_FreeAcmd(Mmdl *mmdl);
u32 FLDMMDL_SysCheckStatusBit(MmdlSys *sys, u32 bit);
void FLDMMDL_SysSetStatusBit(MmdlSys *sys, u32 bit);
void FLDMMDL_SysClearStatusBit(MmdlSys *sys, u32 bit);
u16 FLDMMDL_SysGetMmdlMax(const MmdlSys *sys);
u16 FLDMMDL_SysGetTcbPriority(MmdlSys *sys);
u32 FLDMMDL_SysGetHeapId(MmdlSys *sys);
void FLDMMDL_SysIncMmdlCount(MmdlSys *sys);
void FLDMMDL_SysDecMmdlCount(MmdlSys *sys);
void *FLDMMDL_SysGetTcbSys(MmdlSys *sys);
void *FLDMMDL_SysGetResArcHandle(MmdlSys *sys);
void FLDMMDL_SysSetBlActCont(MmdlSys *sys, void *blActCont);
void *FLDMMDL_SysGetBlActCont(MmdlSys *sys);
void FLDMMDL_SysSetG3dObjCont(MmdlSys *sys, void *g3dObjCont);
void *FLDMMDL_SysGetG3dObjCont(MmdlSys *sys);
void *FLDMMDL_SysGetG3dMapper(MmdlSys *sys);
void *FLDMMDL_SysGetNogridMapper(MmdlSys *sys);
void *FLDMMDL_SysGetFieldMap(MmdlSys *sys);
u32 FLDMMDL_SysGetAreaId(MmdlSys *sys);
void FLDMMDL_SetStatusBit(Mmdl *mmdl, u32 bit);
void FLDMMDL_ClearStatusBit(Mmdl *mmdl, u32 bit);
u32 FLDMMDL_CheckStatusBit(Mmdl *mmdl, u32 bit);
u32 FLDMMDL_GetMoveBit(Mmdl *mmdl);
void FLDMMDL_SetMoveBit(Mmdl *mmdl, u32 bit);
void FLDMMDL_ClearMoveBit(Mmdl *mmdl, u32 bit);
u32 FLDMMDL_CheckMoveBit(Mmdl *mmdl, u32 bit);
void FLDMMDL_SetObjId(Mmdl *mmdl, u16 objId);
u16 FLDMMDL_GetObjId(Mmdl *mmdl);
void FLDMMDL_SetZoneId(Mmdl *mmdl, u16 zoneId);
u16 FLDMMDL_GetZoneId(Mmdl *mmdl);
void FLDMMDL_SetObjCode(Mmdl *mmdl, u32 objCode);
u16 FLDMMDL_GetObjCode(Mmdl *mmdl);
void FLDMMDL_SetMoveCode(Mmdl *mmdl, u16 moveCode);
u16 FLDMMDL_GetMoveCode(Mmdl *mmdl);
void FLDMMDL_SetEventType(Mmdl *mmdl, u16 eventType);
u16 FLDMMDL_GetEventType(Mmdl *mmdl);
void FLDMMDL_SetEventFlag(Mmdl *mmdl, u16 eventFlag);
u16 FLDMMDL_GetEventFlag(Mmdl *mmdl);
void FLDMMDL_SetEventId(Mmdl *mmdl, u16 eventId);
u32 FLDMMDL_GetEventId(Mmdl *mmdl);
int FLDMMDL_IsAliasEventId(Mmdl *mmdl);
int FLDMMDL_GetDirHeader(Mmdl *mmdl);
void FLDMMDL_SetDirDisp(Mmdl *mmdl, int dir);
void FLDMMDL_SetDirDispCheckPause(Mmdl *mmdl, int dir);
u16 FLDMMDL_GetDirDisp(Mmdl *mmdl);
u16 FLDMMDL_GetDirDispOld(Mmdl *mmdl);
void FLDMMDL_SetDirMove(Mmdl *mmdl, u16 dir);
u16 FLDMMDL_GetDirMove(Mmdl *mmdl);
void FLDMMDL_SetDirAll(Mmdl *mmdl, u16 dir);
void FLDMMDL_SetParam(Mmdl *mmdl, int param, int no);
int FLDMMDL_GetParam(Mmdl *mmdl, int no);
void FLDMMDL_SetMoveLimitX(Mmdl *mmdl, short limit);
int FLDMMDL_GetMoveLimitX(Mmdl *mmdl);
void FLDMMDL_SetMoveLimitZ(Mmdl *mmdl, short limit);
int FLDMMDL_GetMoveLimitZ(Mmdl *mmdl);
void FLDMMDL_SetDrawStatus(Mmdl *mmdl, u16 drawStatus);
u16 FLDMMDL_GetDrawStatus(Mmdl *mmdl);
MmdlSys *FLDMMDL_GetMmdlSys(Mmdl *mmdl);
void *FLDMMDL_InitMoveProcWork(Mmdl *mmdl, int size);
void *FLDMMDL_GetMoveProcWork(Mmdl *mmdl);
void *FLDMMDL_InitMoveSubProcWork(Mmdl *mmdl, int size);
void *FLDMMDL_GetMoveSubProcWork(Mmdl *mmdl);
void *FLDMMDL_InitMoveCmdWork(Mmdl *mmdl, int size);
void *FLDMMDL_GetMoveCmdWork(Mmdl *mmdl);
void *FLDMMDL_InitDrawProcWork(Mmdl *mmdl, int size);
void *FLDMMDL_GetDrawProcWork(Mmdl *mmdl);
void FLDMMDL_CallMoveInitProc(Mmdl *mmdl);
void FLDMMDL_CallMoveProc(Mmdl *mmdl);
void FLDMMDL_CallMoveDeleteProc(Mmdl *mmdl);
void FLDMMDL_CallMoveRecoverProc(Mmdl *mmdl);
void FLDMMDL_CallDrawInitProc(Mmdl *mmdl);
void FLDMMDL_CallDrawProc(Mmdl *mmdl);
void FLDMMDL_CallDrawDeleteProc(Mmdl *mmdl);
void FLDMMDL_CallDrawPushProc(Mmdl *mmdl);
void FLDMMDL_CallDrawPopProc(Mmdl *mmdl);
int FLDMMDL_CallDrawGetProc(Mmdl *mmdl, unsigned int kind);
void FLDMMDL_SetAcmdCode(Mmdl *mmdl, u16 code);
u16 FLDMMDL_GetAcmdCode(Mmdl *mmdl);
void FLDMMDL_SetAcmdSeq(Mmdl *mmdl, u16 seq);
void FLDMMDL_IncAcmdSeq(Mmdl *mmdl);
u16 FLDMMDL_GetAcmdSeq(Mmdl *mmdl);
void FLDMMDL_SetNowAttr(Mmdl *mmdl, u32 attr);
u32 FLDMMDL_GetNowAttr(Mmdl *mmdl);
void FLDMMDL_SetOldAttr(Mmdl *mmdl, u32 attr);
u32 FLDMMDL_GetOldAttr(Mmdl *mmdl);
int FLDMMDL_GetGridInitX(Mmdl *mmdl);
void FLDMMDL_SetGridInitX(Mmdl *mmdl, short x);
void FLDMMDL_SetGridInitY(Mmdl *mmdl, short y);
int FLDMMDL_GetGridInitZ(Mmdl *mmdl);
void FLDMMDL_SetGridInitZ(Mmdl *mmdl, short z);
int FLDMMDL_GetGridOldX(Mmdl *mmdl);
void FLDMMDL_SetGridOldX(Mmdl *mmdl, s16 x);
int FLDMMDL_GetGridOldY(Mmdl *mmdl);
void FLDMMDL_SetGridOldY(Mmdl *mmdl, s16 y);
int FLDMMDL_GetGridOldZ(Mmdl *mmdl);
void FLDMMDL_SetGridOldZ(Mmdl *mmdl, s16 z);
void FLDMMDL_GetGridNowPos(Mmdl *mmdl, MmdlGridVec *out);
short FLDMMDL_GetGridNowX(Mmdl *mmdl);
void FLDMMDL_SetGridNowX(Mmdl *mmdl, short x);
void FLDMMDL_AddGridNowX(Mmdl *mmdl, short dx);
short FLDMMDL_GetGridNowY(Mmdl *mmdl);
void FLDMMDL_SetGridNowY(Mmdl *mmdl, int y);
void FLDMMDL_AddGridNowY(Mmdl *mmdl, short dy);
short FLDMMDL_GetGridNowZ(Mmdl *mmdl);
void FLDMMDL_SetGridNowZ(Mmdl *mmdl, int z);
void FLDMMDL_AddGridNowZ(Mmdl *mmdl, short dz);
VecFx32 *FLDMMDL_GetPosPtr(Mmdl *mmdl);
void FLDMMDL_GetPos(const Mmdl *mmdl, VecFx32 *out);
void FLDMMDL_SetPos(Mmdl *mmdl, const VecFx32 *pos);
s32 FLDMMDL_GetPosY(Mmdl *mmdl);
void FLDMMDL_GetDrawOffset(Mmdl *mmdl, VecFx32 *out);
void FLDMMDL_SetDrawOffset(Mmdl *mmdl, const VecFx32 *offset);
void FLDMMDL_GetDrawOffsetOutside(Mmdl *mmdl, VecFx32 *out);
void FLDMMDL_SetDrawOffsetOutside(Mmdl *mmdl, const VecFx32 *offset);
void FLDMMDL_GetAttrOffset(Mmdl *mmdl, VecFx32 *out);
void FLDMMDL_SetAttrOffset(Mmdl *mmdl, const VecFx32 *offset);
void *FLDMMDL_GetBlActCont(Mmdl *mmdl);
u8 FLDMMDL_GetSizeWidth(Mmdl *mmdl);
u8 FLDMMDL_GetSizeDepth(Mmdl *mmdl);
void FLDMMDL_GetModelOffset(Mmdl *mmdl, VecFx32 *offset);
int FLDMMDL_SysCheckDrawInit(MmdlSys *sys);
void FLDMMDL_SysSetDrawInit(MmdlSys *sys, int flag);
void FLDMMDL_SysSetDrawEnable(MmdlSys *sys, int flag);
int FLDMMDL_SysIsDrawEnable(MmdlSys *sys);
void FLDMMDL_SysPauseMove(MmdlSys *sys);
void FLDMMDL_SysResumeMove(MmdlSys *sys);
u32 FLDMMDL_CheckSysStatusBit(Mmdl *mmdl, u32 bit);
int FLDMMDL_CheckStatusBitUse(Mmdl *mmdl);
void FLDMMDL_OnMoveBitMove(Mmdl *mmdl);
void FLDMMDL_OffMoveBitMove(Mmdl *mmdl);
int FLDMMDL_CheckMoveBitMove(Mmdl *mmdl);
void FLDMMDL_OnMoveBitMoveStart(Mmdl *mmdl);
void FLDMMDL_OffMoveBitMoveEnd(Mmdl *mmdl);
void FLDMMDL_OnMoveBitDrawInitComp(Mmdl *mmdl);
void FLDMMDL_OffMoveBitDrawInitComp(Mmdl *mmdl);
int FLDMMDL_CheckMoveBitDrawInitComp(Mmdl *mmdl);
int FLDMMDL_CheckStatusBitVanish(Mmdl *mmdl);
void FLDMMDL_SetStatusBitVanish(Mmdl *mmdl, int flag);
void FLDMMDL_SetStatusBitFellowHit(Mmdl *mmdl, int flag);
void FLDMMDL_OnMoveBitMovePause(Mmdl *mmdl);
void FLDMMDL_OffMoveBitMovePause(Mmdl *mmdl);
int FLDMMDL_CheckMoveBitMovePause(Mmdl *mmdl);
int FLDMMDL_CheckDrawInitComp(Mmdl *mmdl);
void FLDMMDL_SetStatusBitHeightGetOff(Mmdl *mmdl, int flag);
int FLDMMDL_CheckStatusBitHeightGetOff(Mmdl *mmdl);
void FLDMMDL_SetStatusBitZoneDeleteOff(Mmdl *mmdl, int flag);
void FLDMMDL_SetStatusBitAlias(Mmdl *mmdl, int flag);
int FLDMMDL_CheckStatusBitAlias(Mmdl *mmdl);
void FLDMMDL_SetMoveBitSplash(Mmdl *mmdl, u32 flag);
int FLDMMDL_CheckMoveBitSplash(Mmdl *mmdl);
int FLDMMDL_CheckStatusBitAttrOffsetOff(Mmdl *mmdl);
void FLDMMDL_SetMoveBitReflect(Mmdl *mmdl, int flag);
int FLDMMDL_CheckMoveBitReflect(Mmdl *mmdl);
int FLDMMDL_CheckMoveBitAcmd(Mmdl *mmdl);
void FLDMMDL_SetMoveBitSysPauseOff(Mmdl *mmdl, int flag);
int FLDMMDL_CheckMoveBitSysPauseOff(Mmdl *mmdl);
void FLDMMDL_SetStatusBitAttrGetOff(Mmdl *mmdl, int flag);
int FLDMMDL_CheckStatusBitAttrGetOff(Mmdl *mmdl);
void FLDMMDL_SetMoveBitAttrEffectOff(Mmdl *mmdl, int flag);
void FLDMMDL_SetMoveBitShadowVanish(Mmdl *mmdl, int flag);
int FLDMMDL_CheckMoveBitShadowVanish(Mmdl *mmdl);
int FLDMMDL_SysSearchUseMmdl(const MmdlSys *sys, Mmdl **out, u32 *iter);
int FLDMMDL_SysSearchGridPosList(MmdlSys *sys, u32 gridX, u32 gridZ, u32 flag, MmdlSearchList *out);
Mmdl *FLDMMDL_SysSearchGridPos(MmdlSys *sys, u32 gridX, u32 gridZ, u32 flag);
Mmdl *FLDMMDL_SysSearchGridPosHeight(MmdlSys *sys, u32 gridX, u32 gridZ, s32 posY, s32 range, u32 flag);
Mmdl *FLDMMDL_SysSearchMoveCode(MmdlSys *sys, u32 moveCode);
Mmdl *FLDMMDL_SysSearchObjId(MmdlSys *sys, u32 objId);
Mmdl *FLDMMDL_SysSearchPlayer(MmdlSys *sys);
Mmdl *FLDMMDL_SysGetFreeMmdl(MmdlSys *sys);
void FLDMMDL_SysDeleteZoneChangeMmdl(MmdlSys *sys);
void FLDMMDL_AddMoveTcb(Mmdl *mmdl, MmdlSys *sys);
void FLDMMDL_DeleteMoveTcb(Mmdl *mmdl);
int FLDMMDL_CheckSameObjCodeOther(Mmdl *mmdl, u32 objCode);
void FLDMMDL_InitPosition(Mmdl *mmdl, const VecFx32 *pos, int dir);
void FLDMMDL_InitGridPosition(Mmdl *mmdl, unsigned int gridX, unsigned int y, unsigned int gridZ, u16 dir);
void FLDMMDL_ChangeHeader(Mmdl *mmdl, const MmdlHeader *header);
void FLDMMDL_ChangeMoveCode(Mmdl *mmdl, u16 moveCode);
void FLDMMDL_InitDraw(Mmdl *mmdl);
void FLDMMDL_SetDrawProcList(Mmdl *mmdl);
void FLDMMDL_ResetDrawStatusBits(Mmdl *mmdl);
void FLDMMDL_ClearMmdlWork(Mmdl *mmdl);
void FLDMMDL_ResetMoveStart(Mmdl *mmdl);
void FLDMMDL_GetCheckInfo(Mmdl *mmdl, MmdlCheckInfo *info);
int FLDMMDL_CheckCheckInfo(Mmdl *mmdl, const MmdlCheckInfo *info);
void FLDMMDL_ChangeObjCode(Mmdl *mmdl, u32 objCode);
void FLDMMDL_OpenObjCodeArc(MmdlSys *sys, int heapId);
void FLDMMDL_CloseObjCodeArc(MmdlSys *sys);
void FLDMMDL_SysLoadObjCodeParamCache(MmdlSys *sys, int member);
void FLDMMDL_GetCachedObjCodeParam(MmdlSys *sys, u32 no, MmdlObjCodeParam *out);
u16 FLDMMDL_GetCachedObjCodeCount(MmdlSys *sys);
void FLDMMDL_LoadObjCodeParam(const MmdlSys *sys, u32 objCode, MmdlObjCodeParam *out);
void FLDMMDL_LoadMmdlObjCodeParam(const MmdlSys *sys, u32 objCode, Mmdl *mmdl);
MmdlObjCodeParam *FLDMMDL_GetObjCodeParam(Mmdl *mmdl);
void *FLDMMDL_GetObjCodeParamBlActRes(MmdlObjCodeParam *param);
void *FLDMMDL_GetObjCodeParamMdlRes(MmdlObjCodeParam *param);
u32 FLDMMDL_GetRealObjCode(void *evWork, u32 objCode);
u32 FLDMMDL_GetEventWorkObjCode(void *evWork, u32 objCode);
const MmdlMoveProcList *FLDMMDL_GetMoveProcList(int moveCode);
const MmdlDrawProcList *FLDMMDL_GetDrawProcList(int drawProcNo);
int FLDMMDL_HeaderIsEventIdNone(const MmdlHeader *header);
unsigned int FLDMMDL_CheckEventFlagBit(void *evWork, int flag);
u32 FLDMMDL_NormalizeEventType(u32 eventType);
void FLDMMDL_MoveInitProcDummy(void);
void FLDMMDL_MoveProcDummy(void);
void FLDMMDL_MoveDeleteProcDummy(void);
void FLDMMDL_MoveRecoverProcDummy(void);
extern char d_02172B48[];
extern const MmdlMoveProcList *d_021D5E04[];
extern const MmdlDrawProcList *d_021D770C[];

MmdlSys *FLDMMDL_CreateSys(int heapId, int mmdlMax, void *saveData)
{
    MmdlSys *sys = GFL_HEAP_Alloc(heapId, sizeof(MmdlSys), 1, d_02172B48, 0xc3);
    sys->mmdlBuf = GFL_HEAP_Alloc(heapId, mmdlMax * sizeof(Mmdl), 1, d_02172B48, 0xc4);
    sys->mmdlMax = mmdlMax;
    sys->sysHeapId = heapId;
    sys->saveData = saveData;
    sys->tcbPriority = 0x80;
    FLDMMDL_OpenObjCodeArc(sys, heapId);
    sys->objCodeParamCache = GFL_HEAP_Alloc(heapId, 0x310, 1, d_02172B48, 0xcf);
    return sys;
}

void FLDMMDL_DeleteSys(MmdlSys *sys)
{
    FLDMMDL_CloseObjCodeArc(sys);
    GFL_HEAP_Free(sys->objCodeParamCache);
    GFL_HEAP_Free(sys->mmdlBuf);
    GFL_HEAP_Free(sys);
}

void FLDMMDL_ClearObjCodeParamCache(MmdlSys *sys)
{
    MI_CpuFill8(sys->objCodeParamCache, 0, 0x310);
}

void FLDMMDL_SetupSysProc(MmdlSys *sys, int heapId, void *gameData, void *fieldMap, void *g3dMapper, void *nogridMapper)
{
    void *tcbWork;
    unsigned short mmdlMax;
    sys->g3dMapper = g3dMapper;
    sys->heapId = heapId;
    sys->gameData = gameData;
    sys->fieldMap = fieldMap;
    tcbWork = GFL_HEAP_Alloc(heapId, TCB_GetTaskOffset(sys->mmdlMax), 0, d_02172B48, 0x109);
    mmdlMax = sys->mmdlMax;
    sys->tcbSysWork = tcbWork;
    sys->tcbSys = TCB_Init(mmdlMax, tcbWork);
    sys->resArcHandle = ARC_TOOL_CreateHandle(0x31, heapId);
    sys->nogridMapper = nogridMapper;
    FLDMMDL_SysSetStatusBit(sys, MMDLSYS_STABIT_MOVE_INIT);
}

void FLDMMDL_ReleaseSysProc(MmdlSys *sys)
{
    TCB_Noop(sys->tcbSys);
    GFL_HEAP_Free(sys->tcbSysWork);
    ARC_TOOL_DeleteHandle(sys->resArcHandle);
    FLDMMDL_SysClearStatusBit(sys, MMDLSYS_STABIT_MOVE_INIT);
}

void FLDMMDL_DeleteSysProc(MmdlSys *sys)
{
    FLDMMDL_ACMD_DeleteDrawSys(sys);
    sys->areaIdRef = 0;
    FLDMMDL_ReleaseSysProc(sys);
}

void FLDMMDL_UpdateSysProc(MmdlSys *sys)
{
    TCB_Main(sys->tcbSys);
    FLDMMDL_BLACT_Update(sys);
}

void FLDMMDL_UpdateSysBlAct(MmdlSys *sys)
{
    if (sys->blActCont != 0)
        FLDMMDL_BLACT_RegisterLoadedRes(sys);
}

void FLDMMDL_SysWaitBlActResLoad(MmdlSys *sys)
{
    while (FLDMMDL_BLACT_IsReservePending(sys) == 1) {
        FLDMMDL_UpdateSysProc(sys);
        OS_WaitInterrupt(1, 1);
        FLDMMDL_UpdateSysBlAct(sys);
    }
}

void FLDMMDL_SetAreaIdRef(MmdlSys *sys, const unsigned short *areaIdRef)
{
    sys->areaIdRef = areaIdRef;
    FLDMMDL_SysSetDrawInit(sys, 1);
}

Mmdl *FLDMMDL_AddMmdlCore(MmdlSys *sys, const MmdlHeader *src, int zoneId, void *evWork)
{
    MmdlHeader header = *src;
    Mmdl *mmdl;
    mmdl = FLDMMDL_SysGetFreeMmdl(sys);
    FLDMMDL_InitWork(mmdl, sys, zoneId);
    FLDMMDL_InitWithHeader(mmdl, &header, evWork, sys);
    FLDMMDL_InitDir(mmdl);
    if (FLDMMDL_HasMovedPos(mmdl) == 1)
        FLDMMDL_SetStatusBit(mmdl, MMDL_STABIT_FELLOW_HIT_OFF | MMDL_STABIT_HEIGHT_GET_OFF);
    if (FLDMMDL_SysCheckStatusBit(sys, MMDLSYS_STABIT_MOVE_INIT)) {
        FLDMMDL_RestartMoveTcb(sys, mmdl);
        FLDMMDL_InitMove(sys, mmdl);
    }
    if (FLDMMDL_SysCheckStatusBit(sys, MMDLSYS_STABIT_DRAW_INIT))
        FLDMMDL_InitDraw(mmdl);
    FLDMMDL_SysIncMmdlCount(FLDMMDL_GetMmdlSys(mmdl));
    FLDMMDL_SetupRailPosFromHeader(mmdl, &header, 0);
    return mmdl;
}

Mmdl *FLDMMDL_AddMmdl(MmdlSys *sys, const MmdlHeader *header, int zoneId)
{
    return FLDMMDL_AddMmdlCore(sys, header, zoneId, 0);
}

Mmdl *FLDMMDL_AddMmdlParam(MmdlSys *sys, u16 gridX, u16 gridZ, u16 dir, u16 objId, u16 objCode, u16 moveCode, int zoneId)
{
    MmdlHeader header;
    MmdlHeader *p = &header;
    MmdlHeaderGridPos *gridPos;
    MI_CpuFill8(&header, 0, sizeof(MmdlHeader));
    p->objId = objId;
    p->objCode = objCode;
    p->moveCode = moveCode;
    p->dirHeader = dir;
    header.posType = 0;
    gridPos = (MmdlHeaderGridPos *)header.pos;
    gridPos->gridX = gridX;
    gridPos->gridZ = gridZ;
    return FLDMMDL_AddMmdl(sys, &header, zoneId);
}

/*
 * extent: zero alignment halfword at 0x0216CEE2, then labelled 0x0216CEE4.
 */
void FLDMMDL_AddMmdlHeaderList(MmdlSys *sys, const MmdlHeader *header, int zoneId, u32 count, void *evWork)
{
    do {
        if (FLDMMDL_HeaderIsEventIdNone(header) == 1 || FLDMMDL_CheckEventFlagBit(evWork, header->eventFlag) == 0)
            FLDMMDL_AddMmdlCore(sys, header, zoneId, evWork);
        header++;
    } while (--count);
}

/*
 * The result local is never initialised on the not-found path (the
 * original returns whatever stack slot it had).
 */
Mmdl *FLDMMDL_AddMmdlHeaderById(MmdlSys *sys, const MmdlHeader *header, int zoneId, int count, void *evWork, u32 objId)
{
    Mmdl *mmdl;
    do {
        if (FLDMMDL_HeaderIsEventIdNone(header) == 0 && header->objId == objId && FLDMMDL_CheckEventFlagBit(evWork, header->eventFlag) == 0) {
            mmdl = FLDMMDL_AddMmdlCore(sys, header, zoneId, evWork);
            break;
        }
        header++;
    } while (--count);
    return mmdl;
}

void FLDMMDL_DeleteMmdl(Mmdl *mmdl)
{
    if (FLDMMDL_SysCheckDrawInit(FLDMMDL_GetMmdlSys(mmdl)) == 1)
        FLDMMDL_CallDrawDeleteProc(mmdl);
    if (FLDMMDL_CheckStatusBit(mmdl, MMDL_STABIT_MOVE_INIT) != 0) {
        FLDMMDL_CallMoveDeleteProc(mmdl);
        FLDMMDL_DeleteMoveTcb(mmdl);
    }
    FLDMMDL_SysDecMmdlCount(mmdl->mmdlSys);
    FLDMMDL_ClearMmdlWork(mmdl);
}

void FLDMMDL_DeleteAllMmdl(MmdlSys *sys)
{
    u32 iter;
    Mmdl *mmdl;
    u32 moveInit = MMDL_STABIT_MOVE_INIT;
    iter = 0;
    while (FLDMMDL_SysSearchUseMmdl(sys, &mmdl, &iter)) {
        if (FLDMMDL_SysCheckDrawInit(sys) == 1)
            FLDMMDL_CallDrawDeleteProc(mmdl);
        FLDMMDL_CheckStatusBit(mmdl, moveInit);
        FLDMMDL_SysDecMmdlCount(mmdl->mmdlSys);
        FLDMMDL_ClearMmdlWork(mmdl);
    }
}

void FLDMMDL_SetHeaderParams(Mmdl *mmdl, const MmdlHeader *header)
{
    FLDMMDL_SetObjId(mmdl, header->objId);
    FLDMMDL_SetMoveCode(mmdl, header->moveCode);
    FLDMMDL_SetEventType(mmdl, header->eventType);
    FLDMMDL_SetEventFlag(mmdl, header->eventFlag);
    FLDMMDL_SetEventId(mmdl, header->eventId);
    mmdl->dirHeader = header->dirHeader;
    mmdl->dirMove = header->dirHeader;
    FLDMMDL_SetParam(mmdl, header->param0, 0);
    FLDMMDL_SetParam(mmdl, header->param1, 1);
    FLDMMDL_SetParam(mmdl, header->param2, 2);
    FLDMMDL_SetMoveLimitX(mmdl, header->moveLimitX);
    FLDMMDL_SetMoveLimitZ(mmdl, header->moveLimitZ);
}

void FLDMMDL_SetHeaderPos(Mmdl *mmdl, const MmdlHeader *header)
{
    if (header->posType == 0)
        FLDMMDL_SetGridPosFromHeader(mmdl, header);
    else
        FLDMMDL_MOVE_SetStatusPauseDraw(mmdl);
}

void FLDMMDL_InitWithHeader(Mmdl *mmdl, const MmdlHeader *header, void *evWork, MmdlSys *sys)
{
    u32 objCode;
    const MmdlObjCodeParam *param;
    FLDMMDL_SetHeaderParams(mmdl, header);
    objCode = FLDMMDL_GetEventWorkObjCode(evWork, header->objCode);
    FLDMMDL_SetObjCode(mmdl, objCode);
    FLDMMDL_LoadMmdlObjCodeParam(sys, objCode, mmdl);
    param = &mmdl->objCodeParam;
    if (objCode == 0xb9) {
        mmdl->sizeWidth = header->param0;
        mmdl->sizeDepth = header->param1;
        if (mmdl->sizeWidth == 0)
            mmdl->sizeWidth += 1;
        if (mmdl->sizeDepth == 0)
            mmdl->sizeDepth += 1;
    } else {
        mmdl->sizeWidth = param->sizeWidth;
        mmdl->sizeDepth = param->sizeDepth;
    }
    mmdl->offsetX = param->offsetX;
    mmdl->offsetY = param->offsetY;
    mmdl->offsetZ = param->offsetZ;
    FLDMMDL_SetHeaderPos(mmdl, header);
}

void FLDMMDL_SetupRailPosFromHeader(Mmdl *mmdl, const MmdlHeader *header, int unused)
{
    if (header->posType == 1)
        FLDMMDL_MOVE_RequestRailMove(mmdl, header);
}

#pragma opt_propagation off

/*
 * The last argument of FLDMMDL_SetGridInitY is a named int local set from the
 * field just before the call, with opt_propagation off around the
 * function. With propagation on the local is folded into the call and the
 * model copy is born before the argument chain (chain in r1); with it off
 * the chain is born first and takes r0, as in the image.
 */
void FLDMMDL_SetGridPosFromHeader(Mmdl *mmdl, const MmdlHeader *header)
{
    const MmdlHeaderGridPos *gridPos = (const MmdlHeaderGridPos *)header->pos;
    VecFx32 pos;
    s32 gridX;
    s32 gridZ;
    s32 posY;
    if (FLDMMDL_HasMovedPos(mmdl, (sptr)header) == 0) {
        gridX = gridPos->gridX;
        gridZ = gridPos->gridZ;
        posY = gridPos->posY;
    } else {
        FLDMMDL_GetMovedPos(mmdl, &pos);
        gridX = (pos.x >> 4) / 4096;
        gridZ = (pos.z >> 4) / 4096;
        posY = pos.y;
    }
    pos.x = (gridX << 16) + 0x8000;
    FLDMMDL_SetGridInitX(mmdl, gridPos->gridX);
    FLDMMDL_SetGridOldX(mmdl, gridX);
    FLDMMDL_SetGridNowX(mmdl, gridX);
    {
        int gridInitY = (gridPos->posY >> 4) / 4096;
        FLDMMDL_SetGridInitY(mmdl, gridInitY);
    }
    pos.y = posY;
    gridX = (posY >> 4) / 4096;
    FLDMMDL_SetGridOldY(mmdl, gridX);
    FLDMMDL_SetGridNowY(mmdl, (s16)gridX);
    pos.z = (gridZ << 16) + 0x8000;
    FLDMMDL_SetGridInitZ(mmdl, gridPos->gridZ);
    FLDMMDL_SetGridOldZ(mmdl, gridZ);
    FLDMMDL_SetGridNowZ(mmdl, (s16)gridZ);
    FLDMMDL_SetPos(mmdl, &pos);
}

#pragma opt_propagation reset

void FLDMMDL_InitWork(Mmdl *mmdl, MmdlSys *sys, int zoneId)
{
    mmdl->mmdlSys = sys;
    FLDMMDL_SetZoneId(mmdl, zoneId);
    FLDMMDL_SetStatusBit(mmdl, MMDL_STABIT_USE);
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_ATTR_GET_ERROR | MMDL_MOVEBIT_HEIGHT_GET_ERROR);
    if (FLDMMDL_IsAliasEventId(mmdl) == 1)
        FLDMMDL_SetStatusBitAlias(mmdl, 1);
    FLDMMDL_FreeAcmd(mmdl);
}

void FLDMMDL_InitDir(Mmdl *mmdl)
{
    FLDMMDL_SetDirDisp(mmdl, (u16)FLDMMDL_GetDirHeader(mmdl));
    FLDMMDL_SetDirMove(mmdl, (u16)FLDMMDL_GetDirHeader(mmdl));
}

void FLDMMDL_InitMoveProcList(Mmdl *mmdl)
{
    mmdl->moveProcList = FLDMMDL_GetMoveProcList(FLDMMDL_GetMoveCode(mmdl));
}

void FLDMMDL_RestartMoveTcb(MmdlSys *sys, Mmdl *mmdl)
{
    FLDMMDL_InitMoveProcList(mmdl);
    FLDMMDL_AddMoveTcb(mmdl, sys);
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_MOVE_START | MMDL_MOVEBIT_ATTR_GET_ERROR | MMDL_MOVEBIT_HEIGHT_GET_ERROR);
}

void FLDMMDL_InitMove(MmdlSys *sys, Mmdl *mmdl)
{
    if (FLDMMDL_CheckStatusBit(mmdl, MMDL_STABIT_RAIL_MOVE) == 0)
        FLDMMDL_MOVE_SetupMove(mmdl);
    else
        FLDMMDL_RAIL_MOVE_InitMove(mmdl);
}

void FLDMMDL_UpdateMove(Mmdl *mmdl)
{
    if (FLDMMDL_CheckStatusBit(mmdl, MMDL_STABIT_RAIL_MOVE) == 0)
        FLDMMDL_MOVE_UpdateMove(mmdl);
    else
        FLDMMDL_RAIL_MOVE_UpdateMove(mmdl);
}

void FLDMMDL_SysPushAll(MmdlSys *sys)
{
    u32 iter;
    Mmdl *mmdl;
    u32 pushBits = MMDL_MOVEBIT_MOVE_PUSH | MMDL_MOVEBIT_DRAW_PUSH;

    iter = 0;
    if (FLDMMDL_SysCheckDrawInit(sys)) {
        while (FLDMMDL_SysSearchUseMmdl(sys, &mmdl, &iter) == 1) {
            FLDMMDL_DeleteMoveTcb(mmdl);
            FLDMMDL_CallDrawPushProc(mmdl);
            FLDMMDL_SetMoveBit(mmdl, pushBits);
        }
    }
}

void FLDMMDL_SysPopAll(MmdlSys *sys)
{
    u32 iter;
    Mmdl *mmdl;
    u32 movePush = MMDL_MOVEBIT_MOVE_PUSH;
    u32 drawPush = MMDL_MOVEBIT_DRAW_PUSH;
    u32 moveInit = MMDL_STABIT_MOVE_INIT;

    iter = 0;
    if (FLDMMDL_SysSearchUseMmdl(sys, &mmdl, &iter) == 1) {
        do {
            FLDMMDL_RestartMoveTcb(sys, mmdl);
            if (FLDMMDL_CheckStatusBit(mmdl, moveInit) == 0)
                FLDMMDL_InitMove(sys, mmdl);
            if (FLDMMDL_CheckMoveBit(mmdl, movePush)) {
                FLDMMDL_CallMoveRecoverProc(mmdl);
                FLDMMDL_ClearMoveBit(mmdl, movePush);
            }
            if (FLDMMDL_CheckMoveBitDrawInitComp(mmdl) == 0)
                FLDMMDL_InitDraw(mmdl);
            if (FLDMMDL_CheckMoveBit(mmdl, drawPush)) {
                FLDMMDL_CallDrawPopProc(mmdl);
                FLDMMDL_ClearMoveBit(mmdl, drawPush);
            }
            FLDMMDL_ResetDrawStatusBits(mmdl);
        } while (FLDMMDL_SysSearchUseMmdl(sys, &mmdl, &iter) == 1);
    }
}

void FLDMMDL_ExecMove(Mmdl *mmdl)
{
    FLDMMDL_UpdateMove(mmdl);
    if (FLDMMDL_CheckStatusBitUse(mmdl) == 1)
        FLDMMDL_UpdateDraw(mmdl);
}

/*
 * Move task procedure (added by FLDMMDL_AddMoveTcb): the task work is the model.
 */
void FLDMMDL_MoveTcbProc(struct TcbTask *tcb, void *work)
{
    FLDMMDL_ExecMove(work);
}

void FLDMMDL_UpdateDraw(Mmdl *mmdl)
{
    if (FLDMMDL_SysCheckDrawInit(FLDMMDL_GetMmdlSys(mmdl)) == 1)
        FLDMMDL_ACMD_DrawIfInitialized(mmdl);
}

int FLDMMDL_CheckPossibleAcmd(Mmdl *mmdl)
{
    if (FLDMMDL_CheckStatusBit(mmdl, MMDL_STABIT_USE) == 0)
        return 0;
    if (FLDMMDL_CheckMoveBit(mmdl, MMDL_MOVEBIT_MOVE))
        return 0;
    if (FLDMMDL_CheckMoveBit(mmdl, MMDL_MOVEBIT_ACMD) && FLDMMDL_CheckMoveBit(mmdl, MMDL_MOVEBIT_ACMD_END) == 0)
        return 0;
    return 1;
}

void FLDMMDL_SetAcmd(Mmdl *mmdl, u16 code)
{
    FLDMMDL_SetAcmdCode(mmdl, code);
    FLDMMDL_SetAcmdSeq(mmdl, 0);
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_ACMD);
    FLDMMDL_ClearMoveBit(mmdl, MMDL_MOVEBIT_ACMD_END);
}

void FLDMMDL_SetLocalAcmd(Mmdl *mmdl, u16 code)
{
    FLDMMDL_SetAcmdCode(mmdl, code);
    FLDMMDL_SetAcmdSeq(mmdl, 0);
    FLDMMDL_ClearMoveBit(mmdl, MMDL_MOVEBIT_ACMD_END);
}

int FLDMMDL_CheckEndAcmd(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBit(mmdl, MMDL_MOVEBIT_ACMD) == 0)
        return 1;
    if (FLDMMDL_CheckMoveBit(mmdl, MMDL_MOVEBIT_ACMD_END))
        return 1;
    return 0;
}

int FLDMMDL_EndAcmd(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBit(mmdl, MMDL_MOVEBIT_ACMD) == 0)
        return 1;
    if (FLDMMDL_CheckMoveBit(mmdl, MMDL_MOVEBIT_ACMD_END) == 0)
        return 0;
    FLDMMDL_ClearMoveBit(mmdl, MMDL_MOVEBIT_ACMD | MMDL_MOVEBIT_ACMD_END);
    return 1;
}

void FLDMMDL_FreeAcmd(Mmdl *mmdl)
{
    FLDMMDL_ClearMoveBit(mmdl, MMDL_MOVEBIT_ACMD | MMDL_MOVEBIT_ACMD_END);
    FLDMMDL_SetAcmdCode(mmdl, 0xff);
    FLDMMDL_SetAcmdSeq(mmdl, 0);
}

u32 FLDMMDL_SysCheckStatusBit(MmdlSys *sys, u32 bit)
{
    return sys->statusBit & bit;
}

void FLDMMDL_SysSetStatusBit(MmdlSys *sys, u32 bit)
{
    sys->statusBit |= bit;
}

void FLDMMDL_SysClearStatusBit(MmdlSys *sys, u32 bit)
{
    sys->statusBit &= ~bit;
}

u16 FLDMMDL_SysGetMmdlMax(const MmdlSys *sys)
{
    return sys->mmdlMax;
}

u16 FLDMMDL_SysGetTcbPriority(MmdlSys *sys)
{
    return sys->tcbPriority;
}

u32 FLDMMDL_SysGetHeapId(MmdlSys *sys)
{
    return sys->heapId;
}

void FLDMMDL_SysIncMmdlCount(MmdlSys *sys)
{
    sys->mmdlCount++;
}

void FLDMMDL_SysDecMmdlCount(MmdlSys *sys)
{
    sys->mmdlCount--;
}

void *FLDMMDL_SysGetTcbSys(MmdlSys *sys)
{
    return sys->tcbSys;
}

void *FLDMMDL_SysGetResArcHandle(MmdlSys *sys)
{
    return sys->resArcHandle;
}

void FLDMMDL_SysSetBlActCont(MmdlSys *sys, void *blActCont)
{
    sys->blActCont = blActCont;
}

void *FLDMMDL_SysGetBlActCont(MmdlSys *sys)
{
    return sys->blActCont;
}

void FLDMMDL_SysSetG3dObjCont(MmdlSys *sys, void *g3dObjCont)
{
    sys->g3dObjCont = g3dObjCont;
}

void *FLDMMDL_SysGetG3dObjCont(MmdlSys *sys)
{
    return sys->g3dObjCont;
}

void *FLDMMDL_SysGetG3dMapper(MmdlSys *sys)
{
    return sys->g3dMapper;
}

void *FLDMMDL_SysGetNogridMapper(MmdlSys *sys)
{
    return sys->nogridMapper;
}

void *FLDMMDL_SysGetFieldMap(MmdlSys *sys)
{
    return sys->fieldMap;
}

u32 FLDMMDL_SysGetAreaId(MmdlSys *sys)
{
    const u16 *areaId = sys->areaIdRef;
    if (areaId != 0)
        return *areaId;
    return 0;
}

void FLDMMDL_SetStatusBit(Mmdl *mmdl, u32 bit)
{
    mmdl->statusBit |= bit;
}

void FLDMMDL_ClearStatusBit(Mmdl *mmdl, u32 bit)
{
    mmdl->statusBit &= ~bit;
}

u32 FLDMMDL_CheckStatusBit(Mmdl *mmdl, u32 bit)
{
    return mmdl->statusBit & bit;
}

u32 FLDMMDL_GetMoveBit(Mmdl *mmdl)
{
    return mmdl->moveBit;
}

void FLDMMDL_SetMoveBit(Mmdl *mmdl, u32 bit)
{
    mmdl->moveBit |= bit;
}

void FLDMMDL_ClearMoveBit(Mmdl *mmdl, u32 bit)
{
    mmdl->moveBit &= ~bit;
}

u32 FLDMMDL_CheckMoveBit(Mmdl *mmdl, u32 bit)
{
    return mmdl->moveBit & bit;
}

void FLDMMDL_SetObjId(Mmdl *mmdl, u16 objId)
{
    mmdl->objId = objId;
}

u16 FLDMMDL_GetObjId(Mmdl *mmdl)
{
    return mmdl->objId;
}

void FLDMMDL_SetZoneId(Mmdl *mmdl, u16 zoneId)
{
    mmdl->zoneId = zoneId;
}

u16 FLDMMDL_GetZoneId(Mmdl *mmdl)
{
    return mmdl->zoneId;
}

void FLDMMDL_SetObjCode(Mmdl *mmdl, u32 objCode)
{
    mmdl->objCode = objCode;
}

u16 FLDMMDL_GetObjCode(Mmdl *mmdl)
{
    return mmdl->objCode;
}

void FLDMMDL_SetMoveCode(Mmdl *mmdl, u16 moveCode)
{
    mmdl->moveCode = moveCode;
}

u16 FLDMMDL_GetMoveCode(Mmdl *mmdl)
{
    return mmdl->moveCode;
}

void FLDMMDL_SetEventType(Mmdl *mmdl, u16 eventType)
{
    mmdl->eventType = eventType;
}

u16 FLDMMDL_GetEventType(Mmdl *mmdl)
{
    return mmdl->eventType;
}

void FLDMMDL_SetEventFlag(Mmdl *mmdl, u16 eventFlag)
{
    mmdl->eventFlag = eventFlag;
}

u16 FLDMMDL_GetEventFlag(Mmdl *mmdl)
{
    return mmdl->eventFlag;
}

void FLDMMDL_SetEventId(Mmdl *mmdl, u16 eventId)
{
    mmdl->eventId = eventId;
}

u32 FLDMMDL_GetEventId(Mmdl *mmdl)
{
    return mmdl->eventId;
}

int FLDMMDL_IsAliasEventId(Mmdl *mmdl)
{
    return FLDMMDL_GetEventId(mmdl) == 0xFFFF;
}

int FLDMMDL_GetDirHeader(Mmdl *mmdl)
{
    return mmdl->dirHeader;
}

void FLDMMDL_SetDirDisp(Mmdl *mmdl, int dir)
{
    mmdl->dirDispOld = mmdl->dirDisp;
    mmdl->dirDisp = dir;
}

void FLDMMDL_SetDirDispCheckPause(Mmdl *mmdl, int dir)
{
    if (FLDMMDL_CheckStatusBit(mmdl, MMDL_STABIT_PAUSE_DIR) == 0) {
        mmdl->dirDispOld = mmdl->dirDisp;
        mmdl->dirDisp = dir;
    }
}

u16 FLDMMDL_GetDirDisp(Mmdl *mmdl)
{
    return mmdl->dirDisp;
}

u16 FLDMMDL_GetDirDispOld(Mmdl *mmdl)
{
    return mmdl->dirDispOld;
}

void FLDMMDL_SetDirMove(Mmdl *mmdl, u16 dir)
{
    mmdl->dirMoveOld = mmdl->dirMove;
    mmdl->dirMove = dir;
}

u16 FLDMMDL_GetDirMove(Mmdl *mmdl)
{
    return mmdl->dirMove;
}

void FLDMMDL_SetDirAll(Mmdl *mmdl, u16 dir)
{
    FLDMMDL_SetDirDispCheckPause(mmdl, dir);
    FLDMMDL_SetDirMove(mmdl, dir);
}

void FLDMMDL_SetParam(Mmdl *mmdl, int param, int no)
{
    switch (no) {
    case 0:
        mmdl->param0 = param;
        break;
    case 1:
        mmdl->param1 = param;
        break;
    case 2:
        mmdl->param2 = param;
        break;
    }
}

int FLDMMDL_GetParam(Mmdl *mmdl, int no)
{
    switch (no) {
    case 0:
        return mmdl->param0;
    case 1:
        return mmdl->param1;
    case 2:
        return mmdl->param2;
    default:
        return 0;
    }
}

void FLDMMDL_SetMoveLimitX(Mmdl *mmdl, short limit)
{
    mmdl->moveLimitX = limit;
}

int FLDMMDL_GetMoveLimitX(Mmdl *mmdl)
{
    return mmdl->moveLimitX;
}

void FLDMMDL_SetMoveLimitZ(Mmdl *mmdl, short limit)
{
    mmdl->moveLimitZ = limit;
}

int FLDMMDL_GetMoveLimitZ(Mmdl *mmdl)
{
    return mmdl->moveLimitZ;
}

void FLDMMDL_SetDrawStatus(Mmdl *mmdl, u16 drawStatus)
{
    mmdl->drawStatus = drawStatus;
}

u16 FLDMMDL_GetDrawStatus(Mmdl *mmdl)
{
    return mmdl->drawStatus;
}

MmdlSys *FLDMMDL_GetMmdlSys(Mmdl *mmdl)
{
    return mmdl->mmdlSys;
}

void *FLDMMDL_InitMoveProcWork(Mmdl *mmdl, int size)
{
    void *work = FLDMMDL_GetMoveProcWork(mmdl);
    MI_CpuFill8(work, 0, size);
    return work;
}

void *FLDMMDL_GetMoveProcWork(Mmdl *mmdl)
{
    return mmdl->moveProcWork;
}

void *FLDMMDL_InitMoveSubProcWork(Mmdl *mmdl, int size)
{
    void *work = FLDMMDL_GetMoveSubProcWork(mmdl);
    MI_CpuFill8(work, 0, size);
    return work;
}

void *FLDMMDL_GetMoveSubProcWork(Mmdl *mmdl)
{
    return mmdl->moveSubProcWork;
}

void *FLDMMDL_InitMoveCmdWork(Mmdl *mmdl, int size)
{
    void *work = FLDMMDL_GetMoveCmdWork(mmdl);
    MI_CpuFill8(work, 0, size);
    return work;
}

void *FLDMMDL_GetMoveCmdWork(Mmdl *mmdl)
{
    return mmdl->moveCmdWork;
}

void *FLDMMDL_InitDrawProcWork(Mmdl *mmdl, int size)
{
    void *work = FLDMMDL_GetDrawProcWork(mmdl);
    MI_CpuFill8(work, 0, size);
    return work;
}

void *FLDMMDL_GetDrawProcWork(Mmdl *mmdl)
{
    return mmdl->drawProcWork;
}

void FLDMMDL_CallMoveInitProc(Mmdl *mmdl)
{
    void (*proc)(Mmdl *) = mmdl->moveProcList->init;
    if (proc != 0)
        proc(mmdl);
}

void FLDMMDL_CallMoveProc(Mmdl *mmdl)
{
    void (*proc)(Mmdl *) = mmdl->moveProcList->move;
    if (proc != 0)
        proc(mmdl);
}

void FLDMMDL_CallMoveDeleteProc(Mmdl *mmdl)
{
    void (*proc)(Mmdl *) = mmdl->moveProcList->remove;
    if (proc != 0)
        proc(mmdl);
}

void FLDMMDL_CallMoveRecoverProc(Mmdl *mmdl)
{
    void (*proc)(Mmdl *) = mmdl->moveProcList->recover;
    if (proc != 0)
        proc(mmdl);
}

void FLDMMDL_CallDrawInitProc(Mmdl *mmdl)
{
    void (*proc)(Mmdl *) = mmdl->drawProcList->init;
    if (proc != 0)
        proc(mmdl);
}

void FLDMMDL_CallDrawProc(Mmdl *mmdl)
{
    void (*proc)(Mmdl *) = mmdl->drawProcList->draw;
    if (proc != 0)
        proc(mmdl);
}

void FLDMMDL_CallDrawDeleteProc(Mmdl *mmdl)
{
    void (*proc)(Mmdl *) = mmdl->drawProcList->remove;
    if (proc != 0)
        proc(mmdl);
}

void FLDMMDL_CallDrawPushProc(Mmdl *mmdl)
{
    void (*proc)(Mmdl *) = mmdl->drawProcList->push;
    if (proc != 0)
        proc(mmdl);
}

void FLDMMDL_CallDrawPopProc(Mmdl *mmdl)
{
    void (*proc)(Mmdl *) = mmdl->drawProcList->pop;
    if (proc != 0)
        proc(mmdl);
}

int FLDMMDL_CallDrawGetProc(Mmdl *mmdl, unsigned int kind)
{
    int (*proc)(Mmdl *, unsigned int);
    proc = mmdl->drawProcList->getParam;
    if (proc != 0)
        return proc(mmdl, kind);
    return 0;
}

void FLDMMDL_SetAcmdCode(Mmdl *mmdl, u16 code)
{
    mmdl->acmdCode = code;
}

u16 FLDMMDL_GetAcmdCode(Mmdl *mmdl)
{
    return mmdl->acmdCode;
}

void FLDMMDL_SetAcmdSeq(Mmdl *mmdl, u16 seq)
{
    mmdl->acmdSeq = seq;
}

void FLDMMDL_IncAcmdSeq(Mmdl *mmdl)
{
    mmdl->acmdSeq = mmdl->acmdSeq + 1;
}

u16 FLDMMDL_GetAcmdSeq(Mmdl *mmdl)
{
    return mmdl->acmdSeq;
}

void FLDMMDL_SetNowAttr(Mmdl *mmdl, u32 attr)
{
    mmdl->nowAttr = attr;
}

u32 FLDMMDL_GetNowAttr(Mmdl *mmdl)
{
    return mmdl->nowAttr;
}

void FLDMMDL_SetOldAttr(Mmdl *mmdl, u32 attr)
{
    mmdl->oldAttr = attr;
}

u32 FLDMMDL_GetOldAttr(Mmdl *mmdl)
{
    return mmdl->oldAttr;
}

int FLDMMDL_GetGridInitX(Mmdl *mmdl)
{
    return mmdl->gridInitX;
}

void FLDMMDL_SetGridInitX(Mmdl *mmdl, short x)
{
    mmdl->gridInitX = x;
}

void FLDMMDL_SetGridInitY(Mmdl *mmdl, short y)
{
    mmdl->gridInitY = y;
}

int FLDMMDL_GetGridInitZ(Mmdl *mmdl)
{
    return mmdl->gridInitZ;
}

void FLDMMDL_SetGridInitZ(Mmdl *mmdl, short z)
{
    mmdl->gridInitZ = z;
}

int FLDMMDL_GetGridOldX(Mmdl *mmdl)
{
    return mmdl->gridOldX;
}

void FLDMMDL_SetGridOldX(Mmdl *mmdl, s16 x)
{
    mmdl->gridOldX = x;
}

int FLDMMDL_GetGridOldY(Mmdl *mmdl)
{
    return mmdl->gridOldY;
}

void FLDMMDL_SetGridOldY(Mmdl *mmdl, s16 y)
{
    mmdl->gridOldY = y;
}

int FLDMMDL_GetGridOldZ(Mmdl *mmdl)
{
    return mmdl->gridOldZ;
}

void FLDMMDL_SetGridOldZ(Mmdl *mmdl, s16 z)
{
    mmdl->gridOldZ = z;
}

void FLDMMDL_GetGridNowPos(Mmdl *mmdl, MmdlGridVec *out)
{
    out->x = mmdl->gridNowX;
    out->y = mmdl->gridNowY;
    out->z = mmdl->gridNowZ;
}

short FLDMMDL_GetGridNowX(Mmdl *mmdl)
{
    return mmdl->gridNowX;
}

void FLDMMDL_SetGridNowX(Mmdl *mmdl, short x)
{
    mmdl->gridNowX = x;
}

void FLDMMDL_AddGridNowX(Mmdl *mmdl, short dx)
{
    mmdl->gridNowX += dx;
}

short FLDMMDL_GetGridNowY(Mmdl *mmdl)
{
    return mmdl->gridNowY;
}

void FLDMMDL_SetGridNowY(Mmdl *mmdl, int y)
{
    mmdl->gridNowY = y;
}

void FLDMMDL_AddGridNowY(Mmdl *mmdl, short dy)
{
    mmdl->gridNowY += dy;
}

short FLDMMDL_GetGridNowZ(Mmdl *mmdl)
{
    return mmdl->gridNowZ;
}

void FLDMMDL_SetGridNowZ(Mmdl *mmdl, int z)
{
    mmdl->gridNowZ = z;
}

void FLDMMDL_AddGridNowZ(Mmdl *mmdl, short dz)
{
    mmdl->gridNowZ += dz;
}

VecFx32 *FLDMMDL_GetPosPtr(Mmdl *mmdl)
{
    return &mmdl->pos;
}

void FLDMMDL_GetPos(const Mmdl *mmdl, VecFx32 *out)
{
    *out = mmdl->pos;
}

void FLDMMDL_SetPos(Mmdl *mmdl, const VecFx32 *pos)
{
    mmdl->pos = *pos;
}

s32 FLDMMDL_GetPosY(Mmdl *mmdl)
{
    return mmdl->pos.y;
}

void FLDMMDL_GetDrawOffset(Mmdl *mmdl, VecFx32 *out)
{
    *out = mmdl->drawOffset;
}

void FLDMMDL_SetDrawOffset(Mmdl *mmdl, const VecFx32 *offset)
{
    mmdl->drawOffset = *offset;
}

void FLDMMDL_GetDrawOffsetOutside(Mmdl *mmdl, VecFx32 *out)
{
    *out = mmdl->drawOffsetOutside;
}

void FLDMMDL_SetDrawOffsetOutside(Mmdl *mmdl, const VecFx32 *offset)
{
    mmdl->drawOffsetOutside = *offset;
}

void FLDMMDL_GetAttrOffset(Mmdl *mmdl, VecFx32 *out)
{
    *out = mmdl->attrOffset;
}

void FLDMMDL_SetAttrOffset(Mmdl *mmdl, const VecFx32 *offset)
{
    mmdl->attrOffset = *offset;
}

void *FLDMMDL_GetBlActCont(Mmdl *mmdl)
{
    return FLDMMDL_SysGetBlActCont(FLDMMDL_GetMmdlSys(mmdl));
}

u8 FLDMMDL_GetSizeWidth(Mmdl *mmdl)
{
    return mmdl->sizeWidth;
}

u8 FLDMMDL_GetSizeDepth(Mmdl *mmdl)
{
    return mmdl->sizeDepth;
}

void FLDMMDL_GetModelOffset(Mmdl *mmdl, VecFx32 *offset)
{
    offset->x = mmdl->offsetX << 12;
    offset->y = mmdl->offsetY << 12;
    offset->z = mmdl->offsetZ << 12;
}

int FLDMMDL_SysCheckDrawInit(MmdlSys *sys)
{
    int ret = 1;
    if (FLDMMDL_SysCheckStatusBit(sys, MMDLSYS_STABIT_DRAW_INIT) == 0)
        ret = 0;
    return ret;
}

void FLDMMDL_SysSetDrawInit(MmdlSys *sys, int flag)
{
    if (flag == 1)
        FLDMMDL_SysSetStatusBit(sys, MMDLSYS_STABIT_DRAW_INIT);
    else
        FLDMMDL_SysClearStatusBit(sys, MMDLSYS_STABIT_DRAW_INIT);
}

void FLDMMDL_SysSetDrawEnable(MmdlSys *sys, int flag)
{
    if (flag == 0)
        FLDMMDL_SysSetStatusBit(sys, MMDLSYS_STABIT_DRAW_OFF);
    else
        FLDMMDL_SysClearStatusBit(sys, MMDLSYS_STABIT_DRAW_OFF);
}

int FLDMMDL_SysIsDrawEnable(MmdlSys *sys)
{
    if (FLDMMDL_SysCheckStatusBit(sys, MMDLSYS_STABIT_DRAW_OFF) == 0)
        return 1;
    return 0;
}

void FLDMMDL_SysPauseMove(MmdlSys *sys)
{
    u32 iter = 0;
    Mmdl *mmdl;

    while (FLDMMDL_SysSearchUseMmdl(sys, &mmdl, &iter) == 1) {
        if (FLDMMDL_CheckMoveBitSysPauseOff(mmdl) == 0)
            FLDMMDL_OnMoveBitMovePause(mmdl);
    }
    FLDMMDL_SysSetStatusBit(sys, MMDLSYS_STABIT_MOVE_PAUSE);
}

void FLDMMDL_SysResumeMove(MmdlSys *sys)
{
    u32 iter;
    Mmdl *mmdl;

    iter = 0;
    while (FLDMMDL_SysSearchUseMmdl(sys, &mmdl, &iter) == 1)
        FLDMMDL_OffMoveBitMovePause(mmdl);
    FLDMMDL_SysClearStatusBit(sys, MMDLSYS_STABIT_MOVE_PAUSE);
}

u32 FLDMMDL_CheckSysStatusBit(Mmdl *mmdl, u32 bit)
{
    return FLDMMDL_SysCheckStatusBit(FLDMMDL_GetMmdlSys(mmdl), bit);
}

int FLDMMDL_CheckStatusBitUse(Mmdl *mmdl)
{
    int ret = 1;
    if (FLDMMDL_CheckStatusBit(mmdl, MMDL_STABIT_USE) == 0)
        ret = 0;
    return ret;
}

void FLDMMDL_OnMoveBitMove(Mmdl *mmdl)
{
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_MOVE);
}

void FLDMMDL_OffMoveBitMove(Mmdl *mmdl)
{
    FLDMMDL_ClearMoveBit(mmdl, MMDL_MOVEBIT_MOVE);
}

int FLDMMDL_CheckMoveBitMove(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBit(mmdl, MMDL_MOVEBIT_MOVE))
        return 1;
    return 0;
}

void FLDMMDL_OnMoveBitMoveStart(Mmdl *mmdl)
{
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_MOVE_START);
}

void FLDMMDL_OffMoveBitMoveEnd(Mmdl *mmdl)
{
    FLDMMDL_ClearMoveBit(mmdl, MMDL_MOVEBIT_MOVE_END);
}

void FLDMMDL_OnMoveBitDrawInitComp(Mmdl *mmdl)
{
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_DRAW_INIT_COMP);
}

void FLDMMDL_OffMoveBitDrawInitComp(Mmdl *mmdl)
{
    FLDMMDL_ClearMoveBit(mmdl, MMDL_MOVEBIT_DRAW_INIT_COMP);
}

int FLDMMDL_CheckMoveBitDrawInitComp(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBit(mmdl, MMDL_MOVEBIT_DRAW_INIT_COMP))
        return 1;
    return 0;
}

int FLDMMDL_CheckStatusBitVanish(Mmdl *mmdl)
{
    if (FLDMMDL_CheckStatusBit(mmdl, MMDL_STABIT_VANISH))
        return 1;
    return 0;
}

void FLDMMDL_SetStatusBitVanish(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        FLDMMDL_SetStatusBit(mmdl, MMDL_STABIT_VANISH);
    else
        FLDMMDL_ClearStatusBit(mmdl, MMDL_STABIT_VANISH);
}

void FLDMMDL_SetStatusBitFellowHit(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        FLDMMDL_ClearStatusBit(mmdl, MMDL_STABIT_FELLOW_HIT_OFF);
    else
        FLDMMDL_SetStatusBit(mmdl, MMDL_STABIT_FELLOW_HIT_OFF);
}

void FLDMMDL_OnMoveBitMovePause(Mmdl *mmdl)
{
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_MOVE_PAUSE);
}

void FLDMMDL_OffMoveBitMovePause(Mmdl *mmdl)
{
    FLDMMDL_ClearMoveBit(mmdl, MMDL_MOVEBIT_MOVE_PAUSE);
}

int FLDMMDL_CheckMoveBitMovePause(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBit(mmdl, MMDL_MOVEBIT_MOVE_PAUSE))
        return 1;
    return 0;
}

int FLDMMDL_CheckDrawInitComp(Mmdl *mmdl)
{
    if (FLDMMDL_SysCheckDrawInit(FLDMMDL_GetMmdlSys(mmdl)) == 0)
        return 0;
    if (FLDMMDL_CheckMoveBitDrawInitComp(mmdl))
        return 1;
    return 0;
}

void FLDMMDL_SetStatusBitHeightGetOff(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        FLDMMDL_SetStatusBit(mmdl, MMDL_STABIT_HEIGHT_GET_OFF);
    else
        FLDMMDL_ClearStatusBit(mmdl, MMDL_STABIT_HEIGHT_GET_OFF);
}

int FLDMMDL_CheckStatusBitHeightGetOff(Mmdl *mmdl)
{
    if (FLDMMDL_CheckStatusBit(mmdl, MMDL_STABIT_HEIGHT_GET_OFF))
        return 1;
    return 0;
}

void FLDMMDL_SetStatusBitZoneDeleteOff(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        FLDMMDL_SetStatusBit(mmdl, MMDL_STABIT_ZONE_DEL_OFF);
    else
        FLDMMDL_ClearStatusBit(mmdl, MMDL_STABIT_ZONE_DEL_OFF);
}

void FLDMMDL_SetStatusBitAlias(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        FLDMMDL_SetStatusBit(mmdl, MMDL_STABIT_ALIAS);
    else
        FLDMMDL_ClearStatusBit(mmdl, MMDL_STABIT_ALIAS);
}

int FLDMMDL_CheckStatusBitAlias(Mmdl *mmdl)
{
    if (FLDMMDL_CheckStatusBit(mmdl, MMDL_STABIT_ALIAS))
        return 1;
    return 0;
}

void FLDMMDL_SetMoveBitSplash(Mmdl *mmdl, u32 flag)
{
    if (flag == 1)
        FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_SPLASH_SET);
    else
        FLDMMDL_ClearMoveBit(mmdl, MMDL_MOVEBIT_SPLASH_SET);
}

int FLDMMDL_CheckMoveBitSplash(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBit(mmdl, MMDL_MOVEBIT_SPLASH_SET))
        return 1;
    return 0;
}

int FLDMMDL_CheckStatusBitAttrOffsetOff(Mmdl *mmdl)
{
    if (FLDMMDL_CheckStatusBit(mmdl, MMDL_STABIT_ATTR_OFFSET_OFF))
        return 1;
    return 0;
}

void FLDMMDL_SetMoveBitReflect(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_REFLECT_SET);
    else
        FLDMMDL_ClearMoveBit(mmdl, MMDL_MOVEBIT_REFLECT_SET);
}

int FLDMMDL_CheckMoveBitReflect(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBit(mmdl, MMDL_MOVEBIT_REFLECT_SET))
        return 1;
    return 0;
}

int FLDMMDL_CheckMoveBitAcmd(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBit(mmdl, MMDL_MOVEBIT_ACMD))
        return 1;
    return 0;
}

void FLDMMDL_SetMoveBitSysPauseOff(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_SYS_PAUSE_OFF);
    else
        FLDMMDL_ClearMoveBit(mmdl, MMDL_MOVEBIT_SYS_PAUSE_OFF);
}

int FLDMMDL_CheckMoveBitSysPauseOff(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBit(mmdl, MMDL_MOVEBIT_SYS_PAUSE_OFF))
        return 1;
    return 0;
}

void FLDMMDL_SetStatusBitAttrGetOff(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        FLDMMDL_SetStatusBit(mmdl, MMDL_STABIT_ATTR_GET_OFF);
    else
        FLDMMDL_ClearStatusBit(mmdl, MMDL_STABIT_ATTR_GET_OFF);
}

int FLDMMDL_CheckStatusBitAttrGetOff(Mmdl *mmdl)
{
    if (FLDMMDL_CheckStatusBit(mmdl, MMDL_STABIT_ATTR_GET_OFF))
        return 1;
    return 0;
}

void FLDMMDL_SetMoveBitAttrEffectOff(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_ATTR_EFFECT_OFF);
    else
        FLDMMDL_ClearMoveBit(mmdl, MMDL_MOVEBIT_ATTR_EFFECT_OFF);
}

void FLDMMDL_SetMoveBitShadowVanish(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_SHADOW_VANISH);
    else
        FLDMMDL_ClearMoveBit(mmdl, MMDL_MOVEBIT_SHADOW_VANISH);
}

int FLDMMDL_CheckMoveBitShadowVanish(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBit(mmdl, MMDL_MOVEBIT_SHADOW_VANISH))
        return 1;
    return 0;
}

/*
 * Iterator over the models in use: advances *iter and returns TRUE with
 * *out set at the next model whose use bit is on.
 */
int FLDMMDL_SysSearchUseMmdl(const MmdlSys *sys, Mmdl **out, u32 *iter)
{
    u32 max;
    Mmdl *mmdl;

    max = FLDMMDL_SysGetMmdlMax(sys);
    if (*iter < max) {
        mmdl = &sys->mmdlBuf[*iter];
        do {
            (*iter)++;
            if (FLDMMDL_CheckStatusBit(mmdl, MMDL_STABIT_USE)) {
                *out = mmdl;
                return 1;
            }
            mmdl++;
        } while (*iter < max);
    }
    return 0;
}

/*
 * Collects up to 16 models on the grid position into a 0x44-byte result
 * block (count word, then the pointers).
 */
int FLDMMDL_SysSearchGridPosList(MmdlSys *sys, u32 gridX, u32 gridZ, u32 flag, MmdlSearchList *out)
{
    u32 iter;
    Mmdl *mmdl;

    iter = 0;
    MI_CpuFill8(out, 0, sizeof(MmdlSearchList));
    while (FLDMMDL_SysSearchUseMmdl(sys, &mmdl, &iter) == 1) {
        if (FLDMMDL_MOVE_IsGridInObjectRect(mmdl, gridX, gridZ, flag) == 1) {
            int i = out->count++;
            out->mmdl[i] = mmdl;
            if (out->count >= 16)
                break;
        }
    }
    return out->count;
}

Mmdl *FLDMMDL_SysSearchGridPos(MmdlSys *sys, u32 gridX, u32 gridZ, u32 flag)
{
    MmdlSearchList list;
    if (FLDMMDL_SysSearchGridPosList(sys, gridX, gridZ, flag, &list) != 0)
        return list.mmdl[0];
    return 0;
}

Mmdl *FLDMMDL_SysSearchGridPosHeight(MmdlSys *sys, u32 gridX, u32 gridZ, s32 posY, s32 range, u32 flag)
{
    MmdlSearchList list;
    u32 i;
    u32 count;

    count = FLDMMDL_SysSearchGridPosList(sys, gridX, gridZ, flag, &list);
    if (count == 0)
        return 0;
    for (i = 0; i < count; i++) {
        s32 diff = FLDMMDL_GetPosY(list.mmdl[i]) - posY;

        if (diff < 0)
            diff = (s32)(((s64)diff * (s64)(s32)0xFFFFF000 + 0x800) >> 12);
        if (diff < range)
            return list.mmdl[i];
    }
    return 0;
}

Mmdl *FLDMMDL_SysSearchMoveCode(MmdlSys *sys, u32 moveCode)
{
    u32 iter;
    Mmdl *mmdl;

    iter = 0;
    while (FLDMMDL_SysSearchUseMmdl(sys, &mmdl, &iter) == 1) {
        if (FLDMMDL_GetMoveCode(mmdl) == moveCode)
            return mmdl;
    }
    return 0;
}

Mmdl *FLDMMDL_SysSearchObjId(MmdlSys *sys, u32 objId)
{
    u32 iter;
    Mmdl *mmdl;

    iter = 0;
    while (FLDMMDL_SysSearchUseMmdl(sys, &mmdl, &iter) == 1) {
        if (FLDMMDL_CheckStatusBitAlias(mmdl) == 0 && FLDMMDL_GetObjId(mmdl) == objId)
            return mmdl;
    }
    return 0;
}

Mmdl *FLDMMDL_SysSearchPlayer(MmdlSys *sys)
{
    return FLDMMDL_SysSearchObjId(sys, 0xff);
}

Mmdl *FLDMMDL_SysGetFreeMmdl(MmdlSys *sys)
{
    int i = 0;
    int max = FLDMMDL_SysGetMmdlMax(sys);
    Mmdl *mmdl = sys->mmdlBuf;

    do {
        if (FLDMMDL_CheckStatusBit(mmdl, MMDL_STABIT_USE) == 0)
            return mmdl;
        i++;
        mmdl++;
    } while (i < max);
    return 0;
}

void FLDMMDL_SysDeleteZoneChangeMmdl(MmdlSys *sys)
{
    u32 iter;
    Mmdl *mmdl;
    u32 zoneDelOff = MMDL_STABIT_ZONE_DEL_OFF;

    iter = 0;
    while (FLDMMDL_SysSearchUseMmdl(sys, &mmdl, &iter)) {
        if (FLDMMDL_CheckStatusBit(mmdl, zoneDelOff) == 0) {
            FLDMMDL_GetObjId(mmdl);
            FLDMMDL_DeleteMmdl(mmdl);
        }
    }
}

void FLDMMDL_AddMoveTcb(Mmdl *mmdl, MmdlSys *sys)
{
    int offset = 0;
    int priority = FLDMMDL_SysGetTcbPriority(sys);
    int moveCode = FLDMMDL_GetMoveCode(mmdl);

    if (moveCode == 0x30 || moveCode == 0x32)
        offset = 1;
    else if (FLDMMDL_GetObjId(mmdl) == 0xff)
        offset--;
    mmdl->moveTcb = TCB_AddTask(FLDMMDL_SysGetTcbSys(sys), FLDMMDL_MoveTcbProc, mmdl, priority + offset);
}

void FLDMMDL_DeleteMoveTcb(Mmdl *mmdl)
{
    if (mmdl->moveTcb != 0) {
        TCB_DeleteTask(mmdl->moveTcb);
        mmdl->moveTcb = 0;
    }
}

int FLDMMDL_CheckSameObjCodeOther(Mmdl *mmdl, u32 objCode)
{
    u32 iter = 0;
    Mmdl *other;
    MmdlSys *sys;

    sys = FLDMMDL_GetMmdlSys(mmdl);
    while (FLDMMDL_SysSearchUseMmdl(sys, &other, &iter) == 1) {
        if (other != mmdl) {
            u32 code = FLDMMDL_GetObjCode(other);
            if (code != 0xFFFF && code == objCode)
                return 1;
        }
    }
    return 0;
}

void FLDMMDL_InitPosition(Mmdl *mmdl, const VecFx32 *pos, int dir)
{
    FLDMMDL_SetGridNowX(mmdl, (s16)((pos->x >> 4) / 4096));
    FLDMMDL_SetGridNowY(mmdl, (s16)((pos->y >> 4) / 4096));
    FLDMMDL_SetGridNowZ(mmdl, (s16)((pos->z >> 4) / 4096));
    FLDMMDL_SetPos(mmdl, pos);
    FLDMMDL_MOVE_UpdateOldGridPos(mmdl);
    FLDMMDL_SetDirDisp(mmdl, dir);
    FLDMMDL_FreeAcmd(mmdl);
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_MOVE_START);
    FLDMMDL_ClearMoveBit(mmdl, MMDL_MOVEBIT_MOVE | MMDL_MOVEBIT_MOVE_END);
}

void FLDMMDL_InitGridPosition(Mmdl *mmdl, unsigned int gridX, unsigned int y, unsigned int gridZ, u16 dir)
{
    VecFx32 pos;
    pos.x = (gridX << 16) + 0x8000;
    pos.y = y << 16;
    pos.z = (gridZ << 16) + 0x8000;
    FLDMMDL_InitPosition(mmdl, &pos, dir);
}

void FLDMMDL_ChangeHeader(Mmdl *mmdl, const MmdlHeader *header)
{
    MmdlSys *sys = FLDMMDL_GetMmdlSys(mmdl);
    FLDMMDL_CallMoveDeleteProc(mmdl);
    FLDMMDL_SetHeaderParams(mmdl, header);
    FLDMMDL_SetHeaderPos(mmdl, header);
    FLDMMDL_InitMoveProcList(mmdl);
    FLDMMDL_InitMove(sys, mmdl);
    FLDMMDL_SetupRailPosFromHeader(mmdl, header, 0);
}

void FLDMMDL_ChangeMoveCode(Mmdl *mmdl, u16 moveCode)
{
    MmdlSys *sys = FLDMMDL_GetMmdlSys(mmdl);
    FLDMMDL_CallMoveDeleteProc(mmdl);
    FLDMMDL_SetMoveCode(mmdl, moveCode);
    FLDMMDL_InitMoveProcList(mmdl);
    FLDMMDL_InitMove(sys, mmdl);
}

void FLDMMDL_InitDraw(Mmdl *mmdl)
{
    if (FLDMMDL_SysCheckDrawInit(FLDMMDL_GetMmdlSys(mmdl)) == 0)
        return;
    if (FLDMMDL_CheckMoveBit(mmdl, MMDL_MOVEBIT_HEIGHT_GET_ERROR) != 0)
        FLDMMDL_MOVE_UpdateHeight(mmdl);
    FLDMMDL_SetDrawStatus(mmdl, 0);
    if (FLDMMDL_CheckMoveBitDrawInitComp(mmdl) != 0)
        return;
    FLDMMDL_SetDrawProcList(mmdl);
    FLDMMDL_CallDrawInitProc(mmdl);
    FLDMMDL_OnMoveBitDrawInitComp(mmdl);
}

void FLDMMDL_SetDrawProcList(Mmdl *mmdl)
{
    mmdl->drawProcList = FLDMMDL_GetDrawProcList(FLDMMDL_GetObjCodeParam(mmdl)->drawProcNo);
}

void FLDMMDL_ResetDrawStatusBits(Mmdl *mmdl)
{
    FLDMMDL_ClearMoveBit(mmdl, MMDL_MOVEBIT_SHADOW_SET | MMDL_MOVEBIT_SHOAL_SET | MMDL_MOVEBIT_REFLECT_SET | MMDL_MOVEBIT_SPLASH_SET);
}

void FLDMMDL_ClearMmdlWork(Mmdl *mmdl)
{
    MI_CpuFill8(mmdl, 0, sizeof(Mmdl));
}

void FLDMMDL_ResetMoveStart(Mmdl *mmdl)
{
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_MOVE_START);
    FLDMMDL_ResetDrawStatusBits(mmdl);
}

void FLDMMDL_GetCheckInfo(Mmdl *mmdl, MmdlCheckInfo *info)
{
    info->objId = FLDMMDL_GetObjId(mmdl);
    info->objCode = FLDMMDL_GetObjCode(mmdl);
    info->zoneId = FLDMMDL_GetZoneId(mmdl);
}

int FLDMMDL_CheckCheckInfo(Mmdl *mmdl, const MmdlCheckInfo *info)
{
    if (FLDMMDL_CheckStatusBit(mmdl, MMDL_STABIT_USE) != 0
        && info->objId == FLDMMDL_GetObjId(mmdl)
        && info->objCode == FLDMMDL_GetObjCode(mmdl)
        && info->zoneId == FLDMMDL_GetZoneId(mmdl))
        return 1;
    return 0;
}

void FLDMMDL_ChangeObjCode(Mmdl *mmdl, u32 objCode)
{
    MmdlSys *sys;
    const MmdlObjCodeParam *param;

    sys = FLDMMDL_GetMmdlSys(mmdl);
    if (FLDMMDL_SysCheckDrawInit(sys) == 1 && FLDMMDL_CheckMoveBitDrawInitComp(mmdl) == 1)
        FLDMMDL_CallDrawDeleteProc(mmdl);
    FLDMMDL_SetObjCode(mmdl, objCode);
    FLDMMDL_LoadMmdlObjCodeParam(sys, objCode, mmdl);
    param = &mmdl->objCodeParam;
    mmdl->sizeWidth = param->sizeWidth;
    mmdl->sizeDepth = param->sizeDepth;
    mmdl->offsetX = param->offsetX;
    mmdl->offsetY = param->offsetY;
    mmdl->offsetZ = param->offsetZ;
    FLDMMDL_OffMoveBitDrawInitComp(mmdl);
    FLDMMDL_ResetMoveStart(mmdl);
    FLDMMDL_InitDraw(mmdl);
}

void FLDMMDL_OpenObjCodeArc(MmdlSys *sys, int heapId)
{
    sys->objCodeArcHandle = ARC_TOOL_CreateHandle(0x30, heapId);
}

void FLDMMDL_CloseObjCodeArc(MmdlSys *sys)
{
    ARC_TOOL_DeleteHandle(sys->objCodeArcHandle);
}

void FLDMMDL_SysLoadObjCodeParamCache(MmdlSys *sys, int member)
{
    ARC_TOOL_ReadMember(sys->objCodeParamCache, 0x3a, member);
}

/*
 * The cache holds a count halfword, the object codes (padded to an even
 * count), then one 0x1C-byte parameter record per code.
 */
void FLDMMDL_GetCachedObjCodeParam(MmdlSys *sys, u32 no, MmdlObjCodeParam *out)
{
    u16 *cache = sys->objCodeParamCache;

    if (no < cache[0]) {
        u16 codeSlots = (cache[0] + 1) / 2 * 2;
        MmdlObjCodeParam *params = (MmdlObjCodeParam *)(cache + (codeSlots + 2));

        *out = params[no];
    }
}

u16 FLDMMDL_GetCachedObjCodeCount(MmdlSys *sys)
{
    return *sys->objCodeParamCache;
}

/*
 * The 28-byte record assignments keep sys in r5, objCode in r4 and out in
 * r6; the named u16 offset and the const system parameter give the last
 * stack store.
 */
void FLDMMDL_LoadObjCodeParam(const MmdlSys *sys, u32 objCode, MmdlObjCodeParam *out)
{
    u16 offset;
    int i;
    u16 count;
    u16 *cache;
    u32 iter;
    Mmdl *mmdl;

    cache = sys->objCodeParamCache;
    count = cache[0];

    if (count < 0x1a) {
        u16 codeSlots = ((count + 1) / 2) * 2;
        MmdlObjCodeParam *params = (MmdlObjCodeParam *)(cache + (codeSlots + 2));
        for (i = 0; i < count; i++) {
            if (objCode == cache[i + 1]) {
                *out = params[i];
                return;
            }
        }
    }
    iter = 0;
    if (FLDMMDL_SysSearchUseMmdl(sys, &mmdl, &iter)) {
        do {
            if (objCode == FLDMMDL_GetObjCode(mmdl)) {
                *out = mmdl->objCodeParam;
                return;
            }
        } while (FLDMMDL_SysSearchUseMmdl(sys, &mmdl, &iter));
    }
    offset = FLDMMDL_ObjCodeToTableIndex(objCode) * 0x1c + 4;
    ARC_TOOL_ReadHandleMemberRange(sys->objCodeArcHandle, 0, offset, 0x1c, out);
}

void FLDMMDL_LoadMmdlObjCodeParam(const MmdlSys *sys, u32 objCode, Mmdl *mmdl)
{
    FLDMMDL_ClearStatusBit(mmdl, MMDL_STABIT_USE);
    FLDMMDL_LoadObjCodeParam(sys, objCode, &mmdl->objCodeParam);
    FLDMMDL_SetStatusBit(mmdl, MMDL_STABIT_USE);
}

MmdlObjCodeParam *FLDMMDL_GetObjCodeParam(Mmdl *mmdl)
{
    return &mmdl->objCodeParam;
}

void *FLDMMDL_GetObjCodeParamBlActRes(MmdlObjCodeParam *param)
{
    return param->resource;
}

void *FLDMMDL_GetObjCodeParamMdlRes(MmdlObjCodeParam *param)
{
    return param->resource;
}

u32 FLDMMDL_GetRealObjCode(void *evWork, u32 objCode)
{
    return FLDMMDL_GetEventWorkObjCode(evWork, objCode);
}

u32 FLDMMDL_GetEventWorkObjCode(void *evWork, u32 objCode)
{
    if (objCode >= 162 && objCode <= 177) {
        if (evWork == 0)
            objCode = 10;
        else
            objCode = *ZONEDATA_GetEventWorkAddress(evWork, (u16)(objCode + 0x3f7e));
    }
    return objCode;
}

/*
 * note: un-hinted, sole-ref/data sees several overlays over 0x021D5E04 and
 * refuses.  ov021 is the only one with data there (a pointer table after a
 * zero word at 0x021D5E00); ov093, ov016 and the rest hold code.  ov021 is
 * resident with ov010: ov010 branches straight into 62 ov021 functions
 * (bl 0x021C3400 and others).  The ov021 hint fixes the choice.
 */
const MmdlMoveProcList *FLDMMDL_GetMoveProcList(int moveCode)
{
    return d_021D5E04[moveCode];
}

/*
 * note: the parked file gave no overlay hint; un-hinted, sole-ref saw data at
 * 0x021D770C in several overlapping overlays and refused.  ov021 is the
 * pointer-table home of the word (the ov021 datum is 0x021D86C0), so the hint
 * fixes the choice and the site resolves as sole-ref/self.
 */
const MmdlDrawProcList *FLDMMDL_GetDrawProcList(int drawProcNo)
{
    return d_021D770C[drawProcNo];
}

int FLDMMDL_HeaderIsEventIdNone(const MmdlHeader *header)
{
    if (header->eventId == 0xFFFF)
        return 1;
    return 0;
}

unsigned int FLDMMDL_CheckEventFlagBit(void *evWork, int flag)
{
    return ZONEDATA_CheckEventFlag(evWork, flag);
}

/*
 * Event types 4..8 and 11..13 count as type 1; the others stay as they are.
 */
u32 FLDMMDL_NormalizeEventType(u32 eventType)
{
    switch (eventType) {
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 11:
    case 12:
    case 13:
        return 1;
    }
    return eventType;
}

void FLDMMDL_MoveInitProcDummy(void)
{
}

void FLDMMDL_MoveProcDummy(void)
{
}

void FLDMMDL_MoveDeleteProcDummy(void)
{
}

void FLDMMDL_MoveRecoverProcDummy(void)
{
}
