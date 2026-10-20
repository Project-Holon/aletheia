#ifndef GAME_OV230_SEALED_CIPHER_H
#define GAME_OV230_SEALED_CIPHER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sealed_cipher.c, prototypes copied from their definitions. */

struct OvStream;
typedef struct OvStream OvStream;

#include "../types.h"

void OV230_StreamInit(OvStream *st, const u8 *key, u32 keyLen);
u8 OV230_StreamNextByte(OvStream *st);
int OV230_FillReverseTable(u8 *table);
int OV230_SealStream(OvStream *st, u8 *src, u8 *dst, u32 size);
int OV230_OpenStream(OvStream *st, u8 *src, u8 *dst, u32 size);
int OV230_SealBuffer(const u8 *key, u8 *src, u8 *dst, u32 size);
int OV230_OpenBuffer(const u8 *key, u8 *src, u8 *dst, u32 size);
void LOADER_ENTRY_DecryptCipher(void);
/* END mkheaders: generated region */

#endif
