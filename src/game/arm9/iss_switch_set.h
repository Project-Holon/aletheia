#ifndef GAME_ARM9_ISS_SWITCH_SET_H
#define GAME_ARM9_ISS_SWITCH_SET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of iss_switch_set.c, prototypes copied from their definitions. */

struct IssSwitchSet;

#include "../types.h"

u32 ISS_SWITCH_SET_Create(void *heapId);
void ISS_SWITCH_SET_Delete(void *set);
u32 ISS_SWITCH_SET_Load(void *set, u32 datId, u32 heapId);
u32 ISS_SWITCH_SET_Main(void *set);
u32 ISS_SWITCH_SET_SwitchOn(void *set, u32 switchIdx);
u32 ISS_SWITCH_SET_SwitchOff(void *set, u32 switchIdx);
void ISS_SWITCH_SET_ResetSwitch(void *set);
u32 ISS_SWITCH_SET_GetBgmNo(void *set);
u32 ISS_SWITCH_SET_IsValidZone(void *set, void *zoneId);
u32 ISS_SWITCH_SET_IsSwitchOn(void *set, u32 switchIdx);
void ISS_SWITCH_SET_UpdateVolume(void *set);
void ISS_SWITCH_SET_Init(struct IssSwitchSet *set);
void *ISS_SWITCH_SET_Alloc(void *heapId);
u32 ISS_SWITCH_SET_Free(void *set);
void ISS_SWITCH_SET_CreateSwitches(char *p, int heapId);
void ISS_SWITCH_SET_DeleteSwitches(struct IssSwitchSet *set);
u32 ISS_SWITCH_SET_LoadData(struct IssSwitchSet *set, void *datId);
u32 ISS_SWITCH_SET_UpdateSwitches(void *set);
u32 ISS_SWITCH_SET_StartSwitchOn(void *set, u32 switchIdx);
u32 ISS_SWITCH_SET_StartSwitchOff(void *set, u32 switchIdx);
void ISS_SWITCH_SET_ResetSwitches(void *set);
u32 ISS_SWITCH_SET_ReadBgmNo(u32 *set);
u32 ISS_SWITCH_SET_GetZoneCount(struct IssSwitchSet *set);
u32 ISS_SWITCH_SET_GetZone(struct IssSwitchSet *set, u32 idx);
u32 ISS_SWITCH_SET_CheckZone(void *set, u32 zoneId);
u32 ISS_SWITCH_SET_CheckSwitchOn(void *set, u32 switchIdx);
u32 ISS_SWITCH_SET_GetSwitch(struct IssSwitchSet *set, u32 idx);
void ISS_SWITCH_SET_ApplySwitchVolumes(void *set);
/* END mkheaders: generated region */

#endif
