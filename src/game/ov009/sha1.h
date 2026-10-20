#ifndef GAME_OV009_SHA1_H
#define GAME_OV009_SHA1_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sha1.c, prototypes copied from their definitions. */

#include "../ov009/cps_ssl_types.h"
#include "../types.h"

void CPSi_sha1_block(CPSSha1Ctx *ctx, u8 *m);
void CPSi_sha1_init(CPSSha1Ctx *ctx);
void CPSi_sha1_calc(CPSSha1Ctx *ctx, void *data0, int datalen);
void CPSi_sha1_result(CPSSha1Ctx *ctx, unsigned char *digest);
void CPSi_sha1_result_prng(void *ctx, unsigned char *digest);
/* END mkheaders: generated region */

#endif
