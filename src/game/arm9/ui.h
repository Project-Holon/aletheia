#ifndef GAME_ARM9_UI_H
#define GAME_ARM9_UI_H

/* Public functions of ui.c, prototypes copied from their definitions. */

struct UiCtx;

void UI_Create(u32 heap, u8 mode);
void UI_Main(struct UiCtx *p);
void UI_Update(void);
void UI_SetKeepAwakeFlags(struct UiCtx *p, u8 flags);
void UI_SetKeepAwakeFlagsGlobal(u8 flags);
void UI_ClearKeepAwakeFlags(struct UiCtx *p, unsigned char flags);
void UI_ClearKeepAwakeFlagsGlobal(u8 v);
u32 UI_TestKeepAwakeFlags(struct UiCtx *p, u8 flags);
u32 UI_TestKeepAwakeFlagsGlobal(u8 flags);
void UI_SetSoftResetInhibit(struct UiCtx *p, u8 mask);
void UI_SetSoftResetInhibitGlobal(u8 mask);
void UI_ClearSoftResetInhibit(struct UiCtx *p, u32 mask);
void UI_ClearSoftResetInhibitGlobal(u32 v);
u32 UI_TestSoftResetInhibit(struct UiCtx *p, u32 mask);
u32 UI_TestSoftResetInhibitGlobal(u32 mask);
void UI_SetIntrData(struct UiCtx *p, u32 a, u32 b);
void UI_SetIntrDataGlobal(u32 a, u32 b);
u32 UI_GetPointerValue(u32 *p);
struct UiCtx *UI_GetContext(void);
void UI_RunSleepHook(struct UiCtx *p);
void UI_RunWakeHook(struct UiCtx *p);
void UI_RunSuspendHook(struct UiCtx *p);
void UI_RunResumeHook(struct UiCtx *p);
void UI_PollPower(void);
int UI_IsPowerConnected(void);
void UI_RunWakePoweredHook(struct UiCtx *ui);
int UI_IsSleepInhibited(struct UiCtx *ui);
void UI_SetBottomBackLight(u32 backlightState);
void UI_ServiceLidSleep(void);
void UI_SoftReset(u32 resetParam);
u8 UI_GetInputMode(void);
void UI_SetInputMode(u8 value);
void UI_ResetFrameCounterOf(struct UiCtx *ui);
void UI_SetFrameRateOf(struct UiCtx *unused, u8 value);
u8 UI_GetFrameRateOf(struct UiCtx *ui);
void UI_SetFrameRate(u8 value);
u8 UI_GetFrameRate(void);
void UI_ResetFrameCounter(void);
void UI_ChangeFrameRate(u8 value);
int UI_GetPowerState(void);
void UI_ApplyInputBounds(int inputObj);

#endif
