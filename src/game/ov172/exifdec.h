#ifndef GAME_OV172_EXIFDEC_H
#define GAME_OV172_EXIFDEC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of exifdec.c, prototypes copied from their definitions. */

#include "../types.h"

unsigned short GetWord(unsigned char *src, unsigned long cur, short Endian);
unsigned long GetLong(unsigned char *src, unsigned long cur, short Endian);
s16 GetAPP1(u8 *src, u32 src_size, u32 cur, long *soi_addr, int option);
long SSP_ExifDecode(unsigned char *src, unsigned long src_size, int *cur, int option);
/* END mkheaders: generated region */

#endif
