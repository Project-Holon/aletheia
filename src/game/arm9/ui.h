#ifndef GAME_ARM9_UI_H
#define GAME_ARM9_UI_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ui.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../arm9/touchpanel_shared_types.h"

void UI_Create(u32 heap, u8 mode);
void UI_Main(UiCtx *p);
void UI_Update(void);
void UI_SetKeepAwakeFlags(UiCtx *p, u8 flags);
void UI_SetKeepAwakeFlagsGlobal(u8 flags);
void UI_ClearKeepAwakeFlags(UiCtx *p, unsigned char flags);
void UI_ClearKeepAwakeFlagsGlobal(u8 v);
u32 UI_TestKeepAwakeFlags(UiCtx *p, u8 flags);
u32 UI_TestKeepAwakeFlagsGlobal(u8 flags);
void UI_SetSleepHook(UiCtx *o, UiCb a, void *b);
void UI_SetSleepHookGlobal(UiCb a, void *b);
void UI_SetWakeHook(UiCtx *o, UiCb a, void *b);
void UI_SetWakeHookGlobal(UiCb a, void *b);
void UI_SetKeepAwakePred(UiPred fn, void *arg);
void UI_SetSuspendHook(UiCtx *p, UiCb fn, void *arg);
void UI_SetResumeAndSuspendHooks(UiCb a, UiCb b, void *c);
UiCb UI_GetSuspendHook(UiCtx *p);
UiCb UI_GetSuspendHookGlobal(void);
void UI_SetResumeHook(UiCtx *p, UiCb fn, void *arg);
void UI_SetWakePoweredHook(UiCtx *p, UiCb fn, void *arg);
void UI_SetWakePoweredHookGlobal(UiCb fn, void *arg);
void UI_SetSoftResetInhibit(UiCtx *p, u8 mask);
void UI_SetSoftResetInhibitGlobal(u8 mask);
void UI_ClearSoftResetInhibit(UiCtx *p, u32 mask);
void UI_ClearSoftResetInhibitGlobal(u32 v);
u32 UI_TestSoftResetInhibit(UiCtx *p, u32 mask);
u32 UI_TestSoftResetInhibitGlobal(u32 mask);
void UI_SetIntrData(UiCtx *p, UiIntrFunc func, void *arg);
void UI_SetIntrDataGlobal(UiIntrFunc func, void *arg);
void *UI_GetPointerValue(void **p);
UiCtx *UI_GetContext(void);
void UI_RunSleepHook(UiCtx *p);
void UI_RunWakeHook(UiCtx *p);
void UI_RunSuspendHook(UiCtx *p);
void UI_RunResumeHook(UiCtx *p);
void UI_PollPower(void);
int DWCi_IsFold(void);
int UI_IsPowerConnected(void);
void UI_RunWakePoweredHook(UiCtx *ui);
int UI_IsSleepInhibited(UiCtx *ui);
void UI_SetBottomBackLight(u32 backlightState);
void UI_ServiceLidSleep(void);
void UI_SoftReset(u32 resetParam);
u8 UI_GetInputMode(void);
void UI_SetInputMode(u32 value);
void UI_ResetFrameCounterOf(UiCtx *ui);
void UI_SetFrameRateOf(UiCtx *unused, u8 value);
u8 UI_GetFrameRateOf(UiCtx *ui);
void UI_SetFrameRate(u8 value);
u8 UI_GetFrameRate(void);
void UI_ResetFrameCounter(void);
void UI_ChangeFrameRate(u8 value);
int UI_GetPowerState(void);
void UI_ApplyInputBounds(UiCtx *inputObj);
/* END mkheaders: generated region */

#endif
