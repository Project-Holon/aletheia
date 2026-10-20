#ifndef GAME_OV230_LOADER_DECRYPT_H
#define GAME_OV230_LOADER_DECRYPT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of loader_decrypt.c, prototypes copied from their definitions. */

#include "../types.h"

void LOADER_DECRYPT_SyncCacheRange(void *addr, unsigned int size);
int LOADER_DECRYPT_ClassifyOpcode(unsigned instr);
void LOADER_DECRYPT_DecodeBlocks(u32 *desc);
/* END mkheaders: generated region */

#endif
