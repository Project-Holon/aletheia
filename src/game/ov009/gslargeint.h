#ifndef GAME_OV009_GSLARGEINT_H
#define GAME_OV009_GSLARGEINT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gslargeint.c, prototypes copied from their definitions. */

struct GSMD5_CTX;

#include "../types.h"
#include "../ov175/auth_types.h"
#include "../ov175/auth_types.h"
#include "../ov175/auth_types.h"
#include "../ov175/auth_types.h"

int gsiLargeIntCompare(const u32 *a, u32 n, const u32 *b, u32 m);
int gsiLargeIntAdd(u32 *data1, u32 length1, u32 *data2, u32 length2, u32 *dest, u32 *lenout, u32 maxlen);
int gsiLargeIntSub(u32 *src1, u32 length1, u32 *src2, u32 length2, u32 *dest, u32 *lenout);
gsi_bool gsLargeIntDiv(const gsLargeInt_t *src1, const gsLargeInt_t *divisor, gsLargeInt_t *dest, gsLargeInt_t *remainder);
int gsiLargeIntDiv(unsigned int *src, unsigned int len, gsLargeInt_t *div, gsLargeInt_t *dest, gsLargeInt_t *remainder);
int gsLargeIntSquareMod(const gsLargeInt_t *lint, gsLargeInt_t *mod, gsLargeInt_t *dest);
int gsLargeIntPowerMod(gsLargeInt_t *b, gsLargeInt_t *p, gsLargeInt_t *m, gsLargeInt_t *dest);
int gsiLargeIntMultM(gsLargeInt_t *x, gsLargeInt_t *y, const gsLargeInt_t *m, unsigned int modPrime, gsLargeInt_t *dest);
int gsiLargeIntInverseMod(gsLargeInt_t *mod, unsigned int *dest);
int gsLargeIntSetFromHexString(gsLargeInt_t *lint, char *hexstream);
int gsLargeIntReverseBytes(char *p);
void gsLargeIntAddToMD5(gsLargeInt_t * _lint, struct GSMD5_CTX * md5);
unsigned int gsLargeIntGetByteLength(gsLargeInt_t * lint);
void *gsiMemoryMalloc(unsigned long size);
void gsiMemoryFree(void *p);
void *gsiMemoryRealloc(unsigned long block, unsigned long size);
/* END mkheaders: generated region */

#endif
