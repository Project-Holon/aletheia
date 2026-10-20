#ifndef GAME_ARM9_ARC_UTIL_H
#define GAME_ARM9_ARC_UTIL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of arc_util.c, prototypes copied from their definitions. */

#include "../types.h"

u32 ARC_UTIL_UploadBgCharFromArchive(void *archiveID, void *memberIdx, void *bgId, void *tileOffset, u32 size, u32 heapID, u16 allocFlags);
u32 ARC_UTIL_UploadBgCharFromHandle(void *arc, u32 memberIdx, u32 bgId, u32 tileOffset, u32 size, u32 heapID, u16 allocFlags);
u32 ARC_UTIL_UploadBgChar(void *buf, u32 bgId, u32 tileOffset, u32 size, u32 unused);
u32 ARC_UTIL_RegisterObjCharFromArchive(u32 archiveID, u32 memberIdx, u32 bgId, u32 size, u32 heapID, u16 flags);
u32 ARC_UTIL_RegisterObjCharFromHandle(void *arc, u32 memberIdx, u32 bgId, u32 size, u32 heapID, u16 flags);
u32 ARC_UTIL_RegisterObjChar(void *buf, u32 bgId, u32 size);
u32 ARC_UTIL_UploadScreenFromHandle(void *arc, u32 memberIdx, int kind, int dest, int size, int heapID, u16 allocFlags);
u32 ARC_UTIL_UploadScreen(void *buf, u32 kind, u32 dest, u32 size);
void ARC_UTIL_UploadBgPaletteFromArchive(u32 archiveID, u32 memberIdx, u32 channel, u32 offset, u32 size, u32 heapID, u16 flags);
void ARC_UTIL_UploadBgPaletteFromHandle(void *arc, u32 memberIdx, u32 channel, u32 offset, u32 size, u32 heapID, u16 flags);
u32 ARC_UTIL_UploadBgPaletteAddFromArchive(u32 archiveID, u32 memberIdx, u32 channel, u32 offset, u32 add, u32 size, u32 heapID, u16 flags);
u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *arc, u32 memberIdx, u32 channel, u32 offset, u32 add, u32 size, u32 heapID, u16 flags);
u32 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *arc, u32 memberIdx, u32 channel, u32 offset, u32 add, u32 size, u32 heapID, u16 flags);
u32 ARC_UTIL_UploadBgPalette(void *file, u32 channel, u32 offset, u32 add, u32 size, u32 flag);
void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 archiveID, u32 memberIdx, u32 kind, u32 dest, u32 size, u16 flags);
void ARC_UTIL_UploadPaletteFromHandleWhole(void *arc, u32 memberIdx, int kind, int dest, int size, u16 flags);
void ARC_UTIL_UploadPaletteFromArchive(u32 archiveID, u32 memberIdx, u32 kind, u32 offset, u32 dest, u32 size, u16 flags);
void ARC_UTIL_UploadPaletteFromHandle(void *arc, u32 memberIdx, u32 kind, u32 offset, u32 dest, u32 size, u16 flags);
void ARC_UTIL_UploadPalette(void *file, u32 kind, u32 offset, u32 dest, u32 size);
void *ARC_UTIL_LoadBgCharDataFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, void *unpackedOut, u16 flags);
void *ARC_UTIL_LoadBgCharDataFromHandle(void *arc, u32 memberIdx, u32 heapID, void *unpackedOut, u16 flags);
void *ARC_UTIL_LoadScreenDataFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, void *unpackedOut, u16 flags);
void *ARC_UTIL_LoadScreenDataFromHandle(void *arc, u32 memberIdx, u32 heapID, void *unpackedOut, u16 flags);
void *ARC_UTIL_LoadPaletteDataFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, void *unpackedOut, u16 flags);
void *ARC_UTIL_LoadPaletteDataFromHandle(void *arc, u32 memberIdx, u32 heapID, void **out, u16 flags);
void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 archiveID, u32 memberIdx, void *unpackedOut, u16 flags);
void *ARC_UTIL_LoadPaletteBlockFromHandle(void *arc, u32 memberIdx, void *unpackedOut, u16 flags);
void *ARC_UTIL_LoadCellBankFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, u8 *unpackedOut, u16 flags);
void *ARC_UTIL_LoadCellBankFromHandle(void *arc, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);
void *ARC_UTIL_LoadMultiCellBankFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);
void *ARC_UTIL_LoadMultiCellBankFromHandle(void *arc, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);
void *ARC_UTIL_LoadAnimBankFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, u8 *unpackedOut, u16 flags);
void *ARC_UTIL_LoadAnimBankFromHandle(void *arc, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);
void *ARC_UTIL_LoadMultiAnimBankFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);
void *ARC_UTIL_LoadMultiAnimBankFromHandle(void *arc, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);
int ARC_UTIL_LoadMember(int archiveID, int memberIdx, int decompress, u16 heapID);
void *ARC_UTIL_LoadMemberWithSize(int archiveID, int memberIdx, int decompress, u16 heapID, u32 *out);
void *ARC_UTIL_LoadHandleMember(void *narc, u32 fileID, u32 decompress, u16 heapID);
void *ARC_UTIL_LoadHandleMemberWithSize(void *narc, int fileID, int decompress, u32 heapID, u32 *out_size);
/* END mkheaders: generated region */

#endif
