#ifndef GAME_OV067_TOUCHBAR_H
#define GAME_OV067_TOUCHBAR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of touchbar.c, prototypes copied from their definitions. */

struct Unit;
struct Strbuf;
struct GfFont;

#include "../ov067/touchbar_types.h"
#include "../ov067/touchbar_types.h"
#include "../types.h"

TouchBar *TOUCHBAR_Create(TouchBarParams *params, u16 heapId);
void TOUCHBAR_Delete(TouchBar *bar);
void TOUCHBAR_Update(TouchBar *bar);
int TOUCHBAR_GetPressedButtonIdIfDone(TouchBar *bar);
int TOUCHBAR_GetPressedButtonIdIfPressing(TouchBar *bar);
int TOUCHBAR_IsBusy(TouchBar *bar);
void TOUCHBAR_SetAllButtonsEnabled(TouchBar *bar, u32 enabled);
void TOUCHBAR_SetAllButtonsVisible(TouchBar *bar, u32 visible);
void TOUCHBAR_SetAllButtonsBgPriority(TouchBar *bar, u32 bgPriority);
void TOUCHBAR_SetAllButtonsPriority(TouchBar *bar, u32 priority);
void TOUCHBAR_SetButtonEnabled(TouchBar *bar, unsigned int buttonId, int enabled);
void TOUCHBAR_SetButtonVisible(TouchBar *bar, unsigned int buttonId, unsigned int visible);
void TOUCHBAR_SetButtonSound(TouchBar *bar, unsigned int buttonId, int soundId);
void TOUCHBAR_SetButtonKeyMask(TouchBar *bar, unsigned int buttonId, int keyMask);
void TOUCHBAR_SetButtonBgPriority(TouchBar *bar, unsigned int buttonId, unsigned int bgPriority);
void TOUCHBAR_SetButtonToggled(TouchBar *bar, unsigned int buttonId, unsigned int toggled);
int TOUCHBAR_IsButtonToggled(TouchBar *bar, int buttonId);
void TOUCHBAR_ResetAndEnableButton(TouchBar *bar, unsigned int buttonId);
TouchBarButton *TOUCHBAR_FindButton(TouchBar *bar, u32 buttonId);
TouchBarButton *TOUCHBAR_GetButton(TouchBar *bar, unsigned int buttonId);
void TOUCHBAR_LoadGfx(TouchBarGfx *gfx, u8 bgLayer, u32 screen, u32 bgPlttTarget, u32 iconSet, u8 bgPlttSlot, u8 actorPlttSlot, u32 skipBgGfx, u32 heapId);
void TOUCHBAR_FreeGfx(TouchBarGfx *gfx);
int TOUCHBAR_GetGfxWord(const TouchBarGfx *gfx, int index);
void TOUCHBAR_LoadCharToBg(void *arc, u32 fileId, u32 bgLayer, u32 tileOffset, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight, u8 dstX, u8 dstY, u8 dstWidth, u8 dstHeight, u8 plttSlot, u32 loadMode, u32 heapId);
void TOUCHBAR_InitButton(TouchBarButton *button, struct Unit *actorSys, const TouchBarGfx *gfx, const TouchBarButtonDef *def, u32 screen, u16 heapId);
void TOUCHBAR_FreeButton(TouchBarButton *button);
int TOUCHBAR_PollButtonPress(TouchBarButton *button);
int TOUCHBAR_IsButtonActorIdle(TouchBarButton *button);
int TOUCHBAR_GetButtonId(TouchBarButton *button);
void TOUCHBAR_SetButtonActorVisible(TouchBarButton *button, unsigned int visible);
void TOUCHBAR_CallSetEnabled(TouchBarButton *button, int enabled);
void TOUCHBAR_SetButtonSoundId(TouchBarButton *button, int soundId);
void TOUCHBAR_SetButtonKeys(TouchBarButton *button, int keyMask);
void TOUCHBAR_SetButtonToggle(TouchBarButton *button, u32 down);
u32 TOUCHBAR_IsButtonDown(TouchBarButton *button);
void TOUCHBAR_SetButtonActorPriority(TouchBarButton *button, unsigned int priority);
void TOUCHBAR_SetButtonActorBgPriority(TouchBarButton *button, unsigned int bgPriority);
void TOUCHBAR_OnPressPlain(TouchBarButton *button);
void TOUCHBAR_OnPressToggle(TouchBarButton *button);
void TOUCHBAR_SetEnabledPlain(TouchBarButton *button, u32 enabled);
void TOUCHBAR_SetEnabledToggle(TouchBarButton *button, u32 enabled);
void TOUCHBAR_PrintAligned(TouchBarWindow *window, void *textCtx, u16 x, u16 y, struct Strbuf *str, struct GfFont *fontId, u16 color, u32 alignMode);
void TOUCHBAR_PrintYesNoCancelLabels(TouchBarWindow *window, void *textCtx, struct GfFont *fontId, u16 x, u16 y, u16 color, u32 firstNumber, u32 secondNumber, u16 heapId);
u16 TOUCHBAR_GetStringAlignOffset(struct Strbuf *str, struct GfFont *fontId, u32 alignMode);
/* END mkheaders: generated region */

#endif
