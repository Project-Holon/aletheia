#ifndef GAME_ARM9_ISS_SWITCH_H
#define GAME_ARM9_ISS_SWITCH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of iss_switch.c, prototypes copied from their definitions. */

struct IssSwitch;

#include "../types.h"

void *ISS_SWITCH_Create(u32 heapId);
u32 ISS_SWITCH_Delete(void *sw);
u32 ISS_SWITCH_Setup(void *sw, u16 fadeFrames, u16 trackBits);
u32 ISS_SWITCH_IsOn(void *sw);
u32 ISS_SWITCH_On(void *sw);
u32 ISS_SWITCH_Off(void *sw);
u32 ISS_SWITCH_ForceOn(void *sw);
u32 ISS_SWITCH_ForceOff(void *sw);
void ISS_SWITCH_Main(void *sw);
void ISS_SWITCH_SetVolume(void *sw, u32 maxVolume);
void *ISS_SWITCH_Alloc(u32 heapId);
u32 ISS_SWITCH_Free(void *sw);
void ISS_SWITCH_Init(struct IssSwitch *sw);
u32 ISS_SWITCH_SetParam(struct IssSwitch *sw, u16 fadeFrames, u16 trackBits);
void ISS_SWITCH_CountUpFade(struct IssSwitch *sw);
u32 ISS_SWITCH_IsFadeEnd(struct IssSwitch *sw);
void ISS_SWITCH_Update(void *sw);
void ISS_SWITCH_UpdateOn(void *sw);
void ISS_SWITCH_UpdateOff(void *sw);
u32 ISS_SWITCH_UpdateFadeIn(void *sw);
u32 ISS_SWITCH_UpdateFadeOut(void *sw);
u32 ISS_SWITCH_StartFadeIn(void *sw);
u32 ISS_SWITCH_StartFadeOut(void *sw);
u32 ISS_SWITCH_SetOnState(void *sw);
u32 ISS_SWITCH_SetOffState(void *sw);
u32 ISS_SWITCH_GetState(struct IssSwitch *sw);
struct IssSwitch *ISS_SWITCH_SetState(struct IssSwitch *sw, u32 state);
s32 ISS_SWITCH_GetVolume(struct IssSwitch *sw);
void ISS_SWITCH_ApplyVolume(struct IssSwitch *sw, s32 maxVolume);
u32 ISS_SWITCH_IsOnState(void *sw);
u32 ISS_SWITCH_IsOffState(void *sw);
/* END mkheaders: generated region */

#endif
