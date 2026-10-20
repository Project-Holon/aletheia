#ifndef GAME_OV035_C_GEAR_POWER_ONOFF_H
#define GAME_OV035_C_GEAR_POWER_ONOFF_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of c_gear_power_onoff.c, prototypes copied from their definitions. */

struct BmpWin;

#include "../ov035/c_gear_power_onoff_types.h"
#include "../ov021/field_subscreen_types.h"
#include "../types.h"

CGearPowerOnOffWork *C_GEAR_POWER_ONOFF_Create(FieldSubscreen *subscreen, void *gameSystem, u16 heapId);
void C_GEAR_POWER_ONOFF_Delete(CGearPowerOnOffWork *work);
void C_GEAR_POWER_ONOFF_Update(CGearPowerOnOffWork *work, int isInitialUpdate);
void C_GEAR_POWER_ONOFF_InitScreen(CGearPowerOnOffWork *work, u16 heapId);
void C_GEAR_POWER_ONOFF_ExitScreen(CGearPowerOnOffWork *work);
void C_GEAR_POWER_ONOFF_InitBgs(CGearPowerOnOffWork *work, u16 heapId);
void C_GEAR_POWER_ONOFF_ExitBgs(CGearPowerOnOffWork *work);
void C_GEAR_POWER_ONOFF_CreateTaskMenuRes(CGearPowerOnOffWork *work, u16 heapId);
void C_GEAR_POWER_ONOFF_DeleteTaskMenuRes(CGearPowerOnOffWork *work);
void C_GEAR_POWER_ONOFF_InitWindows(CGearPowerOnOffWork *work, u16 heapId);
void C_GEAR_POWER_ONOFF_ExitWindows(CGearPowerOnOffWork *work);
void C_GEAR_POWER_ONOFF_PrintMessage(CGearPowerOnOffWork *work, struct BmpWin *window, int msgId);
void C_GEAR_POWER_ONOFF_ResetAndPrintMessage(CGearPowerOnOffWork *work, struct BmpWin *window, int msgId, int height);
void C_GEAR_POWER_ONOFF_OpenYesNoMenu(CGearPowerOnOffWork *work, u16 heapId);
void C_GEAR_POWER_ONOFF_CloseMenu(CGearPowerOnOffWork *work);
void C_GEAR_POWER_ONOFF_UpdateMenu(CGearPowerOnOffWork *work);
u8 C_GEAR_POWER_ONOFF_GetMenuResult(CGearPowerOnOffWork *work);
u32 C_GEAR_POWER_ONOFF_IsMenuDecided(CGearPowerOnOffWork *work);
int C_GEAR_POWER_ONOFF_StepTurnOn(CGearPowerOnOffWork *work);
int C_GEAR_POWER_ONOFF_StepTurnOff(CGearPowerOnOffWork *work);
int C_GEAR_POWER_ONOFF_RunMessageStep(CGearPowerOnOffWork *work);
/* END mkheaders: generated region */

#endif
