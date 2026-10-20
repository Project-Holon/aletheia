#ifndef GAME_ARM9_AREAMAN_H
#define GAME_ARM9_AREAMAN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of areaman.c, prototypes copied from their definitions. */

struct AreaMan;

#include "../types.h"

struct AreaMan *AREAMAN_Create(u32 area_count, u32 heap_id);
u32 AREAMAN_Delete(void *areaman);
s32 AREAMAN_Alloc(struct AreaMan *areaman, u32 len);
s32 AREAMAN_AllocUp(struct AreaMan *areaman, u32 start, u32 limit, u32 len);
s32 AREAMAN_AllocShortUp(struct AreaMan *areaman, u32 start, u32 limit, u32 len);
s32 AREAMAN_AllocLongUp(struct AreaMan *areaman, u32 start, u32 limit, u32 len);
s32 AREAMAN_AllocDown(struct AreaMan *areaman, u32 start, u32 limit, u32 len);
s32 AREAMAN_AllocShortDown(struct AreaMan *areaman, u32 start, u32 limit, u32 len);
s32 AREAMAN_AllocLongDown(struct AreaMan *areaman, u32 start, u32 limit, u32 len);
s32 AREAMAN_AllocAt(struct AreaMan *areaman, u32 start, u32 len);
void AREAMAN_Free(struct AreaMan *areaman, u32 start, s32 len);
s32 AREAMAN_FindClearRunUp(u32 byte_bits, u32 start, u32 len);
s32 AREAMAN_FindClearRunDown(u32 byte_bits, u32 start, u32 len);
void AREAMAN_ClearByteRun(u8 *byte_ptr, u32 start, u32 len);
s32 AREAMAN_MarkUsed(struct AreaMan *areaman, s32 start, u32 len);
void AREAMAN_TraceByte(u8 byte_value);
void AREAMAN_TraceBitmap(struct AreaMan *areaman);
void AREAMAN_TraceAlloc(struct AreaMan *areaman, s32 pos, u32 len, u32 line);
/* END mkheaders: generated region */

#endif
