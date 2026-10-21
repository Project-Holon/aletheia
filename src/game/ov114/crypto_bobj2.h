#ifndef GAME_OV114_CRYPTO_BOBJ2_H
#define GAME_OV114_CRYPTO_BOBJ2_H

#include "crypto_types.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of crypto_bobj2.c, prototypes copied from their definitions. */

BN_ULONG CRYPTOi__bn_mul_add_words(BN_ULONG *rp, const BN_ULONG *ap, int num, BN_ULONG w);
BN_ULONG CRYPTOi__bn_mul_words(BN_ULONG *rp, const BN_ULONG *ap, int num, BN_ULONG w);
void CRYPTOi__bn_sqr_words(BN_ULONG *r, const BN_ULONG *a, int n);
unsigned long long CRYPTOi__bn_div_words(BN_ULONG h, BN_ULONG l, BN_ULONG d);
BN_ULONG CRYPTOi__bn_add_words(BN_ULONG *r, const BN_ULONG *a, const BN_ULONG *b, int n);
BN_ULONG CRYPTOi__bn_sub_words(BN_ULONG *r, const BN_ULONG *a, const BN_ULONG *b, int n);
/* END mkheaders: generated region */

#endif
