#ifndef GAME_ARM9_FLDMMDL_SAVE_H
#define GAME_ARM9_FLDMMDL_SAVE_H

typedef struct NetDeviceRecord NetDeviceRecord;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldmmdl_save.c, prototypes copied from their definitions. */

struct NetDeviceRecord;
typedef struct NetDeviceRecord NetDeviceRecord;

#include "../types.h"
#include "../ov010/fldmmdl_types.h"

u32 FLDMMDL_GetSaveTableSize(void);
void FLDMMDL_ClearSaveTable(void *dest);
void FLDMMDL_StoreSaveTable(MmdlSys *producer, u8 *records);
void FLDMMDL_LoadSaveTable(MmdlSys *sys, const u8 *records);
void FLDMMDL_StoreSaveRecord(const Mmdl *mmdl, NetDeviceRecord *record);
void FLDMMDL_RestoreFromSaveRecord(Mmdl *mmdl, const NetDeviceRecord *record, MmdlSys *sys);
u32 FLDMMDL_GetNextUsed(const void *obj, void *out, u32 *idxptr);
void *FLDMMDL_GetFreeSlot(void *ctx);
u32 FLDMMDL_ObjCodeToTableIndex(u32 x);
/* END mkheaders: generated region */

#endif
