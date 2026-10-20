#ifndef GAME_OV021_FLDMMDL_BLACT_H
#define GAME_OV021_FLDMMDL_BLACT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldmmdl_blact.c, prototypes copied from their definitions. */

struct BbActSys;

#include "../types.h"
#include "../ov010/fldmmdl_types.h"
#include "../sdk_fx.h"
#include "../ov021/fldmmdl_blact_types.h"

int FLDMMDL_BLACT_AddVramSlot(struct BbActSys *sys, void *res, u32 mdlSize, u32 texSize);
void FLDMMDL_BLACT_DeleteVramSlot(struct BbActSys *sys, u32 slotIndex);
void FLDMMDL_BLACT_Init(MmdlSys *mmdlSys, struct BbActSys *bbdActSys, u32 resMax);
void FLDMMDL_BLACT_Exit(MmdlSys *mmdlSys);
void FLDMMDL_BLACT_Update(MmdlSys *mmdlSys);
void FLDMMDL_BLACT_RegisterLoadedRes(MmdlSys *mmdlSys);
int FLDMMDL_BLACT_IsReservePending(MmdlSys *mmdlSys);
int FLDMMDL_BLACT_GetEntryHookFlag(Mmdl *mmdl);
void FLDMMDL_BLACT_AddResByCode(MmdlSys *mmdlSys, u32 code);
void FLDMMDL_BLACT_AddCachedRes(MmdlSys *mmdlSys);
u32 FLDMMDL_BLACT_AddActorPos(MmdlSys *mmdlSys, VecFx32 *pos, int mdlSize, u32 animId, u16 slotIndex);
u32 FLDMMDL_BLACT_AddActorMmdl(Mmdl *mmdl, u16 slotIndex);
u32 FLDMMDL_BLACT_AddActorPosPalette(MmdlSys *mmdlSys, VecFx32 *pos, int mdlSize, u32 animId, u16 slotIndex, u16 paletteSlot);
u32 FLDMMDL_BLACT_AddActorMmdlPalette(Mmdl *mmdl, u16 slotIndex, u16 paletteSlot);
u32 FLDMMDL_BLACT_AddActorMmdlByCode(Mmdl *mmdl, u32 code);
int FLDMMDL_BLACT_AddActorMmdlOrReserve(Mmdl *mmdl, u16 *outBlactId);
void FLDMMDL_BLACT_DeleteActorRes(BlactSys *cont, Mmdl *mmdl, u32 blactId, u16 code);
void FLDMMDL_BLACT_DeleteActorMmdl(Mmdl *mmdl, u32 blactId);
int FLDMMDL_BLACT_AddActorPosOrReserve(MmdlSys *mmdlSys, const MmdlObjCodeParam *param, u16 *actor, VecFx32 *pos, BlactAddActorHook hook, u32 hookArg);
void FLDMMDL_BLACT_DeleteActorPos(MmdlSys *mmdlSys, u16 *actor);
void FLDMMDL_BLACT_EntryHook(struct BbActSys *sys, int entryIndex, u32 arg);
struct BbActSys *FLDMMDL_BLACT_GetBbActSys(BlactSys *cont);
void FLDMMDL_BLACT_GetActorSize(Mmdl *mmdl, u16 *width, u16 *height);
void FLDMMDL_BLACT_InitResTable(BlactResTable *table, u32 count, u32 heapId);
void FLDMMDL_BLACT_FreeResTable(BlactResTable *table);
void FLDMMDL_BLACT_AddResIndex(BlactResTable *table, u16 code, u16 slotIndex, u16 flags);
void FLDMMDL_BLACT_RemoveResIndex(BlactResTable *table, u16 code);
int FLDMMDL_BLACT_FindResIndex(BlactResTable *table, u32 code, u16 *slotIndex, u16 *flags);
void FLDMMDL_BLACT_CreateResTable(BlactSys *cont, u32 count);
void FLDMMDL_BLACT_DeleteAllRes(BlactSys *cont);
void FLDMMDL_BLACT_AddRes(BlactSys *cont, void *resHandle, u16 code, u32 mdlSize, u8 texSize, u32 flags);
void FLDMMDL_BLACT_AddResObjCodeParam(BlactSys *cont, const MmdlObjCodeParam *param, u32 flags);
void FLDMMDL_BLACT_DeleteRes(BlactSys *cont, u16 code);
int FLDMMDL_BLACT_FindRes(BlactSys *cont, u32 code, u16 *slotIndex, u16 *flags);
void FLDMMDL_BLACT_CreateReserve(BlactSys *cont);
void FLDMMDL_BLACT_DeleteReserve(BlactSys *cont);
int FLDMMDL_BLACT_CheckReserveLeft(BlactSys *cont);
void FLDMMDL_BLACT_ReserveRes(BlactSys *cont, u16 code, u8 mdlSize, u8 texSize, u16 resId, u32 flags);
void FLDMMDL_BLACT_LoadReservedRes(BlactSys *cont);
int FLDMMDL_BLACT_LoadAddRes(BlactSys *cont, u32 code, u32 mdlSize, u32 texSize, u16 resId, u32 flags);
void FLDMMDL_BLACT_RegisterAddRes(BlactSys *cont);
int FLDMMDL_BLACT_FindReservedRes(BlactSys *cont, unsigned int code, unsigned short *outFlags);
int FLDMMDL_BLACT_CancelReservedRes(BlactSys *cont, unsigned int code);
void FLDMMDL_BLACT_ReserveActor(BlactSys *cont, Mmdl *mmdl, const MmdlObjCodeParam *param, u16 *outBlactId, BlactAddActorHook hook, u32 hookArg, VecFx32 *pos);
void FLDMMDL_BLACT_AddReservedActor(BlactSys *cont, BlactEntry *entry);
void FLDMMDL_BLACT_AddReservedActors(BlactSys *cont);
int FLDMMDL_BLACT_IsActorReservedByOther(BlactSys *cont, unsigned int code, Mmdl *mmdl);
void FLDMMDL_BLACT_CancelReservedActor(BlactSys *cont, Mmdl *mmdl);
void FLDMMDL_BLACT_ClearActorReserve(BlactEntry *entry);
void FLDMMDL_BLACT_ChangeObjCode(Mmdl *mmdl, unsigned int code);
void FLDMMDL_BLACT_CreateCodeChange(BlactSys *cont);
void FLDMMDL_BLACT_DeleteCodeChange(BlactSys *cont);
void FLDMMDL_BLACT_UpdateCodeChange(BlactSys *cont, BlactCodeChange *change);
void FLDMMDL_BLACT_UpdateCodeChanges(BlactSys *cont);
int FLDMMDL_BLACT_IsCodeChangePending(BlactSys *cont, Mmdl *mmdl, u16 blactId);
BlactAnimeTable *FLDMMDL_BLACT_GetAnimeTable(int animId);
unsigned short FLDMMDL_BLACT_AddResSlot(BlactSys *cont, int code, int mdlSize, int texSize, void *resHandle, int kind);
/* END mkheaders: generated region */

#endif
