#ifndef GAME_OV107_MB_COMMON_H
#define GAME_OV107_MB_COMMON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mb_common.c, prototypes copied from their definitions. */

#include "../types.h"

int MBi_BlockHeaderEnd(int body_len, u16 pollbmp, u32 *sendbuf);
u16 MBi_calc_cksum(u16 *buf, int length);
/* END mkheaders: generated region */

#endif
