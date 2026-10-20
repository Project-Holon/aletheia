#ifndef GAME_OV009_MD5_H
#define GAME_OV009_MD5_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of md5.c, prototypes copied from their definitions. */

#include "../ov009/cps_ssl_types.h"

void CPSi_md5_block(CPSMd5Ctx *ctx, unsigned char *m);
void CPSi_md5_init(CPSMd5Ctx *ctx);
void CPSi_md5_calc(CPSMd5Ctx *ctx, void *data0, int datalen);
void CPSi_md5_result(CPSMd5Ctx *ctx, unsigned char *digest);
/* END mkheaders: generated region */

#endif
