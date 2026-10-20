#ifndef GAME_TWL_AES_FIFO_H
#define GAME_TWL_AES_FIFO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of aes_fifo.c, prototypes copied from their definitions. */

#include "../types.h"

void AESi_PxiSendFirst(int tag, u32 command, u32 param);
void AESi_PxiSendSecond(int tag, u32 payload);
void AESi_PxiSendData(int tag, const u8 *buf, u32 len);
void AESi_PxiSendCmd(u32 command, const u8 *buf, u32 len);
void AESi_PxiSendResult(u32 command, u32 result);
/* END mkheaders: generated region */

#endif
