#ifndef GAME_ARM9_ISS_SWITCH_SET_H
#define GAME_ARM9_ISS_SWITCH_SET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of iss_switch_set.c, prototypes copied from their definitions. */

struct IssSwitchSet;

#include "../types.h"

struct IssSwitchSet *ISS_SWITCH_SET_Create(u32 heapId);
void ISS_SWITCH_SET_Delete(struct IssSwitchSet *set);
u32 ISS_SWITCH_SET_Load(struct IssSwitchSet *set, u32 datId, u32 heapId);
u32 ISS_SWITCH_SET_Main(struct IssSwitchSet *set);
u32 ISS_SWITCH_SET_SwitchOn(struct IssSwitchSet *set, u32 switchIdx);
u32 ISS_SWITCH_SET_SwitchOff(struct IssSwitchSet *set, u32 switchIdx);
void ISS_SWITCH_SET_ResetSwitch(struct IssSwitchSet *set);
u32 ISS_SWITCH_SET_GetBgmNo(struct IssSwitchSet *set);
u32 ISS_SWITCH_SET_IsValidZone(struct IssSwitchSet *set, u32 zoneId);
u32 ISS_SWITCH_SET_IsSwitchOn(struct IssSwitchSet *set, u32 switchIdx);
void ISS_SWITCH_SET_UpdateVolume(struct IssSwitchSet *set);
void ISS_SWITCH_SET_Init(struct IssSwitchSet *set);
void *ISS_SWITCH_SET_Alloc(u32 heapId);
u32 ISS_SWITCH_SET_Free(struct IssSwitchSet *set);
void ISS_SWITCH_SET_CreateSwitches(struct IssSwitchSet *set, int heapId);
void ISS_SWITCH_SET_DeleteSwitches(struct IssSwitchSet *set);
u32 ISS_SWITCH_SET_LoadData(struct IssSwitchSet *set, u32 datId);
u32 ISS_SWITCH_SET_UpdateSwitches(struct IssSwitchSet *set);
u32 ISS_SWITCH_SET_StartSwitchOn(struct IssSwitchSet *set, u32 switchIdx);
u32 ISS_SWITCH_SET_StartSwitchOff(struct IssSwitchSet *set, u32 switchIdx);
void ISS_SWITCH_SET_ResetSwitches(struct IssSwitchSet *set);
u32 ISS_SWITCH_SET_ReadBgmNo(struct IssSwitchSet *set);
u32 ISS_SWITCH_SET_GetZoneCount(struct IssSwitchSet *set);
u32 ISS_SWITCH_SET_GetZone(struct IssSwitchSet *set, u32 idx);
u32 ISS_SWITCH_SET_CheckZone(struct IssSwitchSet *set, u32 zoneId);
u32 ISS_SWITCH_SET_CheckSwitchOn(struct IssSwitchSet *set, u32 switchIdx);
struct IssSwitch *ISS_SWITCH_SET_GetSwitch(struct IssSwitchSet *set, u32 idx);
void ISS_SWITCH_SET_ApplySwitchVolumes(struct IssSwitchSet *set);
/* END mkheaders: generated region */

#endif
