#ifndef GAME_ARM9_FILE_UTIL_H
#define GAME_ARM9_FILE_UTIL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of file_util.c, prototypes copied from their definitions. */

struct FSFile;
struct ArcFile;
struct ItemRecord;
struct ItemExt;

#include "../types.h"

void FILE_UTIL_OpenById(struct FSFile *file, u32 archiveId);
void *FILE_UTIL_LoadRange(u32 archiveId, u32 heap, u32 offset, u32 size);
u32 FILE_UTIL_Get(u32 item, u32 which);
u32 FILE_UTIL_GetItemCount(void);
u32 FILE_UTIL_GetBankCount(void);
u32 FILE_UTIL_GetBaseIndex(void);
void *FILE_UTIL_CreateItemArcHandle(u32 heap);
void *FILE_UTIL_LoadArcMember(struct ArcFile *arc, u32 item, u32 heap);
void *FILE_UTIL_LoadItemRecord(u32 item, u32 which, u32 heap);
void FILE_UTIL_ReadString(void *dst, u32 entry, u32 heap);
void FILE_UTIL_ReadStringAlt(void *dst, u32 entry, u32 heap);
u32 FILE_UTIL_GetItemParam(u32 item, u32 sel, u32 heap);
u32 FILE_UTIL_GetItemRecordParam(struct ItemRecord *record, u32 prop);
int FILE_UTIL_GetItemExtParam(struct ItemExt *ext, u32 prop);
u32 FILE_UTIL_IsMachineItem(u32 id);
u16 FILE_UTIL_GetMachineMove(u16 machineId);
u32 FILE_UTIL_IsHmMove(u16 moveId);
u32 FILE_UTIL_GetId(u32 machineId);
u8 FILE_UTIL_GetMachineIndex(u16 machineId);
u32 FILE_UTIL_IsMailItem(u16 itemId);
u8 FILE_UTIL_GetItemSlot(u16 itemId);
u16 FILE_UTIL_GetItemId(u32 idx);
/* END mkheaders: generated region */

#endif
