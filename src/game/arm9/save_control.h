#ifndef GAME_ARM9_SAVE_CONTROL_H
#define GAME_ARM9_SAVE_CONTROL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of save_control.c, prototypes copied from their definitions. */

struct SaveControl;

#include "../types.h"

struct SaveControl *SAVE_CONTROL_Create(int heapId);
void SAVE_CONTROL_Delete(void);
struct SaveControl *SAVE_CONTROL_Get(void);
int SAVE_CONTROL_Reload(struct SaveControl *saveControl);
int SAVE_CONTROL_StartSave(struct SaveControl *saveControl);
u32 SAVE_CONTROL_MainSave(struct SaveControl *saveControl);
void SAVE_CONTROL_CancelSave(struct SaveControl *saveControl);
u32 SAVE_CONTROL_GetWrittenSize(struct SaveControl *saveControl);
void *SAVE_CONTROL_GetBlock(struct SaveControl *saveControl, u32 blockId);
void *SAVE_CONTROL_GetWorkArea(struct SaveControl *saveControl, u32 *size);
u8 SAVE_CONTROL_IsNewGame(const struct SaveControl *saveControl);
u32 SAVE_CONTROL_GetLoadFlags(const struct SaveControl *saveControl);
u8 SAVE_CONTROL_HasFlashSave(const struct SaveControl *saveControl);
int SAVE_CONTROL_WouldOverwriteSave(struct SaveControl *saveControl);
u8 SAVE_CONTROL_GetOutsideSaveLoaded(const struct SaveControl *saveControl);
void SAVE_CONTROL_SetOutsideSaveLoaded(struct SaveControl *saveControl, u8 outsideSaveLoaded);
u8 SAVE_CONTROL_GetOutsideSaveBroken(const struct SaveControl *saveControl);
void SAVE_CONTROL_SetOutsideSaveBroken(struct SaveControl *saveControl, u8 outsideSaveBroken);
void SAVE_CONTROL_ResetToNewGame(struct SaveControl *saveControl);
int SAVE_CONTROL_EraseMainSave(struct SaveControl *saveControl);
void SAVE_CONTROL_GetDiffSize(struct SaveControl *saveControl, u32 *diffSize, u32 *totalSize);
int SAVE_CONTROL_ReadRecordFromFlash(struct SaveControl *saveControl, u32 recordId, u32 areaIndex, void *dest, u32 size);
u32 SAVE_CONTROL_LoadExtraSave(struct SaveControl *saveControl, u32 slot, u8 heapId);
void SAVE_CONTROL_DeleteExtraSave(struct SaveControl *saveControl, u32 slot);
u32 SAVE_CONTROL_LoadExtraSaveWithBuffer(struct SaveControl *saveControl, u32 slot, u16 heapId, void *work, u32 workSize);
void SAVE_CONTROL_CreateExtraSaveWithBuffer(struct SaveControl *saveControl, u32 slot, u32 heapId, void *work, u32 workSize);
void SAVE_CONTROL_DeleteExtraSaveBuffered(struct SaveControl *saveControl, u32 slot);
void SAVE_CONTROL_BeginExtraSaveWrite(struct SaveControl *saveControl, u32 slot);
int SAVE_CONTROL_StepExtraSaveWrite(struct SaveControl *saveControl, u32 slot);
void *SAVE_CONTROL_GetExtraSaveRecord(struct SaveControl *saveControl, u32 slot, u32 recordId);
void SAVE_CONTROL_EraseExtraSave(struct SaveControl *saveControl, u32 slot, u32 heapId);
void SAVE_CONTROL_EraseOutsideSave(void);
/* END mkheaders: generated region */

#endif
