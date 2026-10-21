#ifndef GAME_ARM9_ISS_SWITCH_SYS_H
#define GAME_ARM9_ISS_SWITCH_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of iss_switch_sys.c, prototypes copied from their definitions. */

struct IssSwitchSys;

#include "../types.h"

u8 *ISS_SWITCH_SYS_Create(u16 heapId);
void ISS_SWITCH_SYS_Delete(u8 *sys);
void ISS_SWITCH_SYS_Main(u8 *sys);
void ISS_SWITCH_SYS_On(u8 *sys);
void ISS_SWITCH_SYS_Off(u32 *sys);
void ISS_SWITCH_SYS_ZoneChange(u32 *sys, u32 zoneId);
void ISS_SWITCH_SYS_SwitchOn(u8 *sys, u32 switchIdx);
void ISS_SWITCH_SYS_SwitchOff(u8 *sys, u32 switchIdx);
u32 ISS_SWITCH_SYS_IsSwitchOn(struct IssSwitchSys *sys, u32 switchIdx);
void ISS_SWITCH_SYS_ResetSwitch(void *sys);
void ISS_SWITCH_SYS_Init(void *obj);
void *ISS_SWITCH_SYS_Alloc(u32 heapId);
void ISS_SWITCH_SYS_Free(void *sys);
void ISS_SWITCH_SYS_CreateSets(u8 *p, u16 heapId);
void ISS_SWITCH_SYS_DeleteSets(u8 *p);
u32 ISS_SWITCH_SYS_UpdateActiveSet(struct IssSwitchSys *sys);
void ISS_SWITCH_SYS_TurnOn(u8 *p);
void ISS_SWITCH_SYS_TurnOff(u32 *sys);
void ISS_SWITCH_SYS_CheckZoneChange(u32 *sys, u32 zoneId);
u32 ISS_SWITCH_SYS_GetSetCount(void *sys);
struct IssSwitchSet *ISS_SWITCH_SYS_GetSet(struct IssSwitchSys *sys, u32 idx);
struct IssSwitchSet *ISS_SWITCH_SYS_GetActiveSet(struct IssSwitchSys *sys);
u32 ISS_SWITCH_SYS_IsActiveSetZone(u32 *sys, u32 zoneId);
struct IssSwitchSet *ISS_SWITCH_SYS_FindSetByBgm(u8 *sys, u32 bgmNo);
int ISS_SWITCH_SYS_ChangeActiveSet(u32 *p, u32 bgmNo);
void ISS_SWITCH_SYS_UpdateVolume(void *sys);
u32 ISS_SWITCH_SYS_GetPlayingBgm(u32 unused);
u32 ISS_SWITCH_SYS_IsOn(u32 *sys);
void ISS_SWITCH_SYS_ResetActiveSet(void *sys);
/* END mkheaders: generated region */

#endif
