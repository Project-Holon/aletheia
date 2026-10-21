#ifndef GAME_ARM9_MI_MEMORY_H
#define GAME_ARM9_MI_MEMORY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mi_memory.c, prototypes copied from their definitions. */

#include "../types.h"

void MIi_CpuClear16(u16 data, void *destp, u32 size);
void MIi_CpuCopy16(const void *srcp, void *destp, u32 size);
void MIi_CpuClear32(u32 data, void *destp, u32 size);
void MIi_CpuCopy32(const void *srcp, void *destp, u32 size);
void MIi_CpuSend32(const void *srcp, volatile void *destp, u32 size);
void MIi_CpuClearFast(u32 data, void *destp, u32 size);
void MIi_CpuCopyFast(const void *srcp, void *destp, u32 size);
void MI_Copy32B(const void *pSrc, void *pDest);
void MI_Copy36B(const void *pSrc, void *pDest);
void MI_Copy48B(const void *pSrc, void *pDest);
void MI_Copy64B(void *pSrc, void *pDest);
void MI_CpuFill8(void *dest, u8 data, u32 size);
void MI_CpuFill(void *dest, u8 data, u32 size);
void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
int MI_CpuComp8(const void *mem1, const void *mem2, u32 size);
void MI_CpuCopy(const void *src, void *dest, u32 size);
void MI_CpuMove(const void *srcp, void *dstp, u32 size);
void MI_Zero36B(void *dst);
/* END mkheaders: generated region */

#endif
