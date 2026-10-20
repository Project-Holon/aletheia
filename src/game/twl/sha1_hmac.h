#ifndef GAME_TWL_SHA1_HMAC_H
#define GAME_TWL_SHA1_HMAC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sha1_hmac.c, prototypes copied from their definitions. */

struct Sha1HmacCtx;
typedef struct Sha1HmacCtx Sha1HmacCtx;

#include "../types.h"

void SHA1_HMAC_Init(void *ctx);
void SHA1_HMAC_Update(void *ctx, const void *data, u32 len);
void SHA1_HMAC_GetHash(void *ctx, void *digest);
void SHA1_HMAC_HashRange(void *dst, const void *src, u32 len);
void SHA1_HMAC_Start(Sha1HmacCtx *ctx, const void *key, u32 key_len);
void SHA1_HMAC_UpdateData(void *ctx, const void *data, u32 length);
void SHA1_HMAC_Finish(Sha1HmacCtx *ctx, u8 *digest);
void SHA1_HMAC_Calc(u8 *digest, const void *data, u32 data_len, const void *key, u32 key_len);
/* END mkheaders: generated region */

#endif
