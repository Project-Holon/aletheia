#ifndef GAME_ARM9_ARC_TOOL_H
#define GAME_ARM9_ARC_TOOL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of arc_tool.c, prototypes copied from their definitions. */

struct ArcHandle;
struct ArcHandleRaw;
struct FSFile;

#include "../types.h"
#include "../sdk_fs.h"

void ARC_TOOL_SetTable(void **entries, u32 count);
void ARC_TOOL_ReadMemberRangeImpl(void *dst, u32 archiveID, u32 memberIdx, u32 offset, u32 size);
void *ARC_TOOL_LoadMemberRangeImpl(u32 archiveID, u32 memberIdx, u16 heapID, u32 offset, u32 size);
void ARC_TOOL_OpenArchive(FSFile *arc, u32 archiveID);
u32 ARC_TOOL_SeekMember(struct ArcHandle *arc, u32 memberIdx, u32 skip, u32 size);
void ARC_TOOL_ReadMember(void *dst, u32 archiveID, u32 memberIdx);
void *ARC_TOOL_LoadMember(u32 archiveID, u32 memberIdx, u16 heapID);
void ARC_TOOL_ReadMemberRange(void *dst, u32 archiveID, u32 memberIdx, u32 offset, u32 size);
void *ARC_TOOL_LoadMemberRange(u32 archiveID, u32 memberIdx, u16 heapID, u32 offset, u32 size);
void *ARC_TOOL_LoadMemberFromPath(const char *path, u32 memberIdx, u16 heapID);
u32 ARC_TOOL_GetArchiveFileCount(u32 archiveID);
u32 ARC_TOOL_GetMemberSize(u32 archiveID, u32 memberIdx);
void *ARC_TOOL_CreateHandle(u32 archiveID, unsigned int heapID);
void *ARC_TOOL_CreateHandleFromMemory(void *buf, u32 size, u16 heapID);
void ARC_TOOL_ReadHandleHeader(struct ArcHandle *arc);
void ARC_TOOL_DeleteHandle(void *handle);
void *ARC_TOOL_LoadHandleMember(struct ArcHandle *arc, u32 memberIdx, u32 heapID);
void ARC_TOOL_ReadHandleMember(struct ArcHandle *arc, u32 memberIdx, void *dst);
u32 ARC_TOOL_GetHandleMemberSize(struct ArcHandle *arc, u32 memberIdx);
void ARC_TOOL_ReadHandleMemberRange(struct ArcHandle *arc, u32 memberIdx, u32 offset, u32 size, void *dst);
void ARC_TOOL_GetHandleMemberOffsetOut(struct ArcHandle *arc, u32 memberIdx, u32 *out);
u32 ARC_TOOL_GetHandleMemberOffset(struct ArcHandle *arc, u32 memberIdx);
void ARC_TOOL_ReadHandle(struct ArcHandleRaw *arc, u32 size, void *dst);
int ARC_TOOL_SeekHandle(struct FSFile *file, u32 offset);
u16 ARC_TOOL_GetHandleFileCount(void *arc);
/* END mkheaders: generated region */

#endif
