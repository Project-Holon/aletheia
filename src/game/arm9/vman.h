#ifndef GAME_ARM9_VMAN_H
#define GAME_ARM9_VMAN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of vman.c, prototypes copied from their definitions. */

struct VmanBank;
struct VmanHandle;

#include "../types.h"

u32 VMAN_GetBankSetSize(u32 bank_flags);
struct VmanBank *VMAN_Create(u16 heap_id, u32 mode, u32 bank_flags, u32 base, u32 mode_arg);
void VMAN_Delete(struct VmanBank *bank);
u32 VMAN_GetUnitSize(u32 key);
void VMAN_InvalidateHandle(struct VmanHandle *handle);
int VMAN_IsHandleInvalid(struct VmanHandle *handle);
int VMAN_Alloc(struct VmanBank *bank, u32 size, struct VmanHandle *out);
void VMAN_Free(struct VmanBank *bank, struct VmanHandle *handle);
u32 VMAN_GetOffset(struct VmanBank *bank, u32 *units_ptr);
/* END mkheaders: generated region */

#endif
