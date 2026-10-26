#ifndef GAME_OV021_FIELD_SUBSCREEN_H
#define GAME_OV021_FIELD_SUBSCREEN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_subscreen.c, prototypes copied from their definitions. */

struct GameEvent;

#include "../ov021/field_subscreen_types.h"
#include "../types.h"

FieldSubscreen *FIELD_SUBSCREEN_Create(u32 heapId, void *fieldMap, u32 mode);
u8 FIELD_SUBSCREEN_Delete(FieldSubscreen *work);
void FIELD_SUBSCREEN_Main(FieldSubscreen *work);
void FIELD_SUBSCREEN_MainNoTransition(FieldSubscreen *work);
struct GameEvent *FIELD_SUBSCREEN_CheckModeRequest(FieldSubscreen *work, u32 mode);
int FIELD_SUBSCREEN_IsIdle(FieldSubscreen *work);
u32 FIELD_SUBSCREEN_ResolveMode(FieldSubscreen *work, u32 mode);
int FIELD_SUBSCREEN_RequestMode(FieldSubscreen *work, u32 mode);
void FIELD_SUBSCREEN_ChangeModeNow(FieldSubscreen *work, u32 mode);
int FIELD_SUBSCREEN_RequestModeWithCallback(FieldSubscreen *work, u32 mode, void (*callback)(void *), void *callbackArg);
u32 FIELD_SUBSCREEN_GetMode(FieldSubscreen *work);
int FIELD_SUBSCREEN_GetPanelResult(FieldSubscreen *work);
void FIELD_SUBSCREEN_SetPanelResult(FieldSubscreen *work, int result);
void FIELD_SUBSCREEN_ClearPanelResult(FieldSubscreen *work);
void FIELD_SUBSCREEN_ResumeField(FieldSubscreen *work, u16 heapId);
void FIELD_SUBSCREEN_InitCGear(FieldSubscreen *work);
void FIELD_SUBSCREEN_InitCGearWithCallback(FieldSubscreen *work);
void FIELD_SUBSCREEN_ExitCGear(FieldSubscreen *work);
u32 FIELD_3DBG_ExitCGear(FieldSubscreen *work);
u32 FIELD_SUBSCREEN_UpdateCGear(FieldSubscreen *work, u32 active);
struct GameEvent *FIELD_SUBSCREEN_HandleCGearInput(FieldSubscreen *work, int button);
void FIELD_SUBSCREEN_InitNoGear(FieldSubscreen *work);
void FIELD_SUBSCREEN_ExitNoGear(FieldSubscreen *work);
void FIELD_SUBSCREEN_NoGearHook(FieldSubscreen *work);
void FIELD_SUBSCREEN_UpdateNoGear(FieldSubscreen *work);
void FIELD_SUBSCREEN_InitMenu(FieldSubscreen *work, u32 prevMode);
void FIELD_SUBSCREEN_ExitMenu(FieldSubscreen *work);
void FIELD_SUBSCREEN_UpdateMenu(FieldSubscreen *work);
void FIELD_SUBSCREEN_UpdateMenuNoTransition(FieldSubscreen *work);
u32 FIELD_SUBSCREEN_GetMenuSelectedButton(FieldSubscreen *work);
void FIELD_SUBSCREEN_SetMenuSelectedButton(FieldSubscreen *work, u32 buttonId);
void FIELD_SUBSCREEN_LoadBackdrop(FieldSubscreen *work, u32 heapId);
void *FIELD_SUBSCREEN_GetCGear(FieldSubscreen *work);
void FIELD_SUBSCREEN_InitUnion(FieldSubscreen *work);
void FIELD_SUBSCREEN_ExitUnion(FieldSubscreen *work);
void FIELD_SUBSCREEN_UpdateUnion(FieldSubscreen *work, u32 isFieldIdle);
void FIELD_SUBSCREEN_UpdateUnionNoTransition(FieldSubscreen *work, u32 isFieldIdle);
void FIELD_SUBSCREEN_InitIntrude(FieldSubscreen *work);
void FIELD_SUBSCREEN_ExitIntrude(FieldSubscreen *work);
void FIELD_SUBSCREEN_UpdateIntrude(FieldSubscreen *work, int isFieldIdle);
void FIELD_SUBSCREEN_DrawIntrude(FieldSubscreen *work);
struct GameEvent *FIELD_SUBSCREEN_CheckIntrudeRequest(FieldSubscreen *work, int mode);
void FIELD_SUBSCREEN_InitBeaconView(FieldSubscreen *work);
void FIELD_SUBSCREEN_ExitBeaconView(FieldSubscreen *work);
void FIELD_SUBSCREEN_UpdateBeaconView(FieldSubscreen *work, s32 isFieldIdle);
int FIELD_SUBSCREEN_UpdateBeaconViewNoTransition(FieldSubscreen *work);
struct GameEvent *FIELD_SUBSCREEN_CheckBeaconViewRequest(FieldSubscreen *work, u32 mode);
void FIELD_SUBSCREEN_InitDowsing(FieldSubscreen *work);
void FIELD_SUBSCREEN_ExitDowsing(FieldSubscreen *work);
void FIELD_SUBSCREEN_UpdateDowsing(FieldSubscreen *work, s32 isFieldIdle);
void FIELD_SUBSCREEN_UpdateDowsingNoTransition(FieldSubscreen *work, s32 isFieldIdle);
void FIELD_SUBSCREEN_InitReport(FieldSubscreen *work);
void FIELD_SUBSCREEN_ExitReport(FieldSubscreen *work);
void FIELD_SUBSCREEN_UpdateReport(FieldSubscreen *work);
void FIELD_SUBSCREEN_UpdateReportNoTransition(FieldSubscreen *work);
int FIELD_SUBSCREEN_IsReportReady(FieldSubscreen *work);
void FIELD_SUBSCREEN_PrepareReportSave(FieldSubscreen *work);
void FIELD_SUBSCREEN_StartReportSaveAnim(FieldSubscreen *work);
int FIELD_SUBSCREEN_IsReportSaveAnimDone(FieldSubscreen *work);
void FIELD_SUBSCREEN_StopReportSaveAnim(FieldSubscreen *work);
int FIELD_SUBSCREEN_CheckReportSaveCounter(FieldSubscreen *work);
void FIELD_SUBSCREEN_InitPowerOnoff(FieldSubscreen *work);
void FIELD_SUBSCREEN_UpdatePowerOnoff(FieldSubscreen *work, s32 isFieldIdle);
void FIELD_SUBSCREEN_ExitPowerOnoff(FieldSubscreen *work);
/* END mkheaders: generated region */

#endif
