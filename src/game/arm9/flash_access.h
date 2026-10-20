#ifndef GAME_ARM9_FLASH_ACCESS_H
#define GAME_ARM9_FLASH_ACCESS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of flash_access.c, prototypes copied from their definitions. */

#include "../types.h"

int FLASH_ACCESS_Identify(u32 unused_arg);
u32 FLASH_ACCESS_Write(u32 flash_addr, u32 ram_src, u32 size, u32 on_error);
int FLASH_ACCESS_Read(u32 flash_addr, u32 ram_dst, u32 size, void (*on_error)(void));
void FLASH_ACCESS_OnWriteDone(void);
u16 FLASH_ACCESS_StartWrite(u32 flash_addr, u32 ram_src, u32 size, void *on_error);
int FLASH_ACCESS_PollWrite(u16 lock_id, u32 *success, u32 on_error);
void FLASH_ACCESS_CancelWrite(u16 lock_id);
void *FLASH_ACCESS_GetBusyFlag(void);
/* END mkheaders: generated region */

#endif
