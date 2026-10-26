#ifndef GAME_ARM9_FLASH_ACCESS_H
#define GAME_ARM9_FLASH_ACCESS_H

#include "../types.h"

/* Handed to a failed flash write; no_response is set when the device did not answer. */
typedef void (*FlashErrorFunc)(u32 no_response);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of flash_access.c, prototypes copied from their definitions. */

int FLASH_ACCESS_Identify(u32 unused_arg);
u32 FLASH_ACCESS_Write(u32 flash_addr, const void *ram_src, u32 size, FlashErrorFunc on_error);
int FLASH_ACCESS_Read(u32 flash_addr, void *ram_dst, u32 size, void (*on_error)(void));
void FLASH_ACCESS_OnWriteDone(void * unused0);
u16 FLASH_ACCESS_StartWrite(u32 flash_addr, const void *ram_src, u32 size, FlashErrorFunc on_error);
int FLASH_ACCESS_PollWrite(u16 lock_id, u32 *success, FlashErrorFunc on_error);
void FLASH_ACCESS_CancelWrite(u16 lock_id);
u32 FLASH_ACCESS_GetBusyFlag(void);
/* END mkheaders: generated region */

#endif
