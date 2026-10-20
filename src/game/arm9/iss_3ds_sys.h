#ifndef GAME_ARM9_ISS_3DS_SYS_H
#define GAME_ARM9_ISS_3DS_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of iss_3ds_sys.c, prototypes copied from their definitions. */

struct VecFx32;

#include "../arm9/iss_sys_shared_types.h"
#include "../types.h"
#include "../sdk_fx.h"

Iss3dsSys *ISS_3DS_SYS_Create(u32 heapId);
void ISS_3DS_SYS_Delete(Iss3dsSys *sys);
void ISS_3DS_SYS_Update(Iss3dsSys *sys);
void ISS_3DS_SYS_Enter(Iss3dsSys *sys);
void ISS_3DS_SYS_Leave(Iss3dsSys *sys);
void ISS_3DS_SYS_OnZoneChange(Iss3dsSys *sys);
void ISS_3DS_SYS_SetVolume(Iss3dsSys *sys, u32 volume);
void ISS_3DS_SYS_StartSource(Iss3dsSys *sys, int slot, int radius, int amp);
int ISS_3DS_SYS_IsSourceActive(Iss3dsSys *sys, int slot);
void ISS_3DS_SYS_SetSourcePos(Iss3dsSys *sys, int slot, const VecFx32 *pos);
void ISS_3DS_SYS_SetCamera(Iss3dsSys *sys, const VecFx32 *cameraPos, const VecFx32 *cameraTarget);
void ISS_3DS_SYS_ClearTable(Iss3dsSys *sys);
void ISS_3DS_SYS_LoadTable(Iss3dsSys *sys);
void ISS_3DS_SYS_FreeTable(Iss3dsSys *sys);
Iss3dsSys *ISS_3DS_SYS_SetTableIndex(Iss3dsSys *sys, u32 index);
u8 ISS_3DS_SYS_FindTableIndex(const Iss3dsSys *sys, u32 bgmId);
void ISS_3DS_SYS_ResetSources(Iss3dsSys *sys);
void ISS_3DS_SYS_StartSourceImpl(Iss3dsSys *sys, int slot, int radius, int amp);
void ISS_3DS_SYS_SetSourcePosImpl(Iss3dsSys *sys, int slot, const VecFx32 *pos);
void ISS_3DS_SYS_SetCameraImpl(Iss3dsSys *sys, const VecFx32 *cameraPos, const VecFx32 *cameraTarget);
void ISS_3DS_SYS_EnterImpl(Iss3dsSys *sys);
void ISS_3DS_SYS_LeaveImpl(Iss3dsSys *sys);
void ISS_3DS_SYS_UpdateImpl(Iss3dsSys *sys);
void ISS_3DS_SYS_OnZoneChangeImpl(Iss3dsSys *sys);
void ISS_3DS_SYS_SilenceActiveTracks(Iss3dsSys *sys);
void ISS_3DS_SYS_StepSourceVolume(Iss3dsSys *sys, int sourceIndex);
void ISS_3DS_SYS_StepSourcePan(Iss3dsSys *sys, int sourceIndex);
s32 ISS_3DS_SYS_CalcSourceVolume(Iss3dsSource *source, const struct VecFx32 *cameraPos);
void ISS_3DS_SYS_RampVolumeUp(Iss3dsSys *sys, u32 sourceIndex, s32 cap);
void ISS_3DS_SYS_RampVolumeDown(Iss3dsSys *sys, u32 sourceIndex, s32 cap);
void ISS_3DS_SYS_ApplySourceVolume(Iss3dsSys *sys, u32 sourceIndex);
s32 ISS_3DS_SYS_CalcSourcePan(const Iss3dsSource *source, const struct VecFx32 *cameraPos, const struct VecFx32 *cameraTarget);
void ISS_3DS_SYS_RampPanDown(Iss3dsSys *sys, u32 sourceIndex, s32 cap);
void ISS_3DS_SYS_RampPanUp(Iss3dsSys *sys, u32 sourceIndex, s32 cap);
void ISS_3DS_SYS_ApplySourcePan(Iss3dsSys *sys, u32 sourceIndex);
void ISS_3DS_SYS_StepMasterVolume(Iss3dsSys *sys);
u32 ISS_3DS_SYS_ScaleVolume(Iss3dsSys *sys, u32 level, void *unused);
/* END mkheaders: generated region */

#endif
