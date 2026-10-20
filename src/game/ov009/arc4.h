#ifndef GAME_OV009_ARC4_H
#define GAME_OV009_ARC4_H

#include "../ov009/cps_ssl_types.h"

void CPSi_rc4_init(CPSRc4Ctx *ctx, unsigned char *key, int len);
void CPSi_rc4_crypt(CPSRc4Ctx *ctx, unsigned char *data, int len);

#endif
