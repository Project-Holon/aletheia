#ifndef GAME_OV114_CRYPTO_BOBJ1_H
#define GAME_OV114_CRYPTO_BOBJ1_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of crypto_bobj1.c, prototypes copied from their definitions. */

#include "../ov114/crypto_types.h"

int CRYPTOi__BN_num_bits_word(BN_ULONG l);
int CRYPTOi__BN_num_bits(const BIGNUM *a);
void CRYPTOi__BN_clear_free(BIGNUM *a);
void CRYPTOi__BN_free(BIGNUM *a);
BIGNUM *CRYPTOi__bn_zexpand(BIGNUM *a, int n);
void CRYPTOi__bn_fix_top(BIGNUM *a);
void CRYPTOi__BN_init(BIGNUM *a);
BIGNUM *CRYPTOi__BN_new(void);
BN_CTX *CRYPTOi__BN_CTX_new(void);
void CRYPTOi__BN_CTX_init(BN_CTX *ctx);
void CRYPTOi__BN_CTX_free(BN_CTX *ctx);
BIGNUM *CRYPTOi__bn_expand2(BIGNUM *a, int n);
BIGNUM *CRYPTOi__BN_copy(BIGNUM *a, const BIGNUM *b);
void CRYPTOi__BN_clear(BIGNUM *p);
int CRYPTOi__BN_set_word(BIGNUM *a, unsigned long w);
BIGNUM *CRYPTOi__BN_bin2bn(unsigned char *s, unsigned int len, BIGNUM *ret);
int CRYPTOi__BN_bn2bin(const BIGNUM *a, unsigned char *to);
int CRYPTOi__BN_ucmp(const BIGNUM *a, const BIGNUM *b);
int CRYPTOi__BN_set_bit(BIGNUM *a, int n);
int CRYPTOi__BN_is_bit_set(const BIGNUM *a, int n);
int CRYPTOi__BN_lshift(BIGNUM *r, BIGNUM *a, int n);
int CRYPTOi__BN_rshift(BIGNUM *r, const BIGNUM *a, int n);
int CRYPTOi__BN_add_word(BIGNUM *a, unsigned long w);
int CRYPTOi__BN_sub_word(BIGNUM *a, BN_ULONG w);
int CRYPTOi__BN_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int CRYPTOi__BN_uadd(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int CRYPTOi__BN_usub(BIGNUM *r, BIGNUM *a, BIGNUM *b);
int CRYPTOi__BN_sub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int CRYPTOi__BN_mul(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx);
void CRYPTOi__bn_mul_normal(unsigned long *r, unsigned long *a, int na, unsigned long *b, int nb);
int CRYPTOi__BN_div(BIGNUM *dv, BIGNUM *rm, const BIGNUM *num, const BIGNUM *divisor, BN_CTX *ctx);
int CRYPTOi__BN_mod(BIGNUM *r, const BIGNUM *a, const BIGNUM *m, BN_CTX *ctx);
int CRYPTOi__BN_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx);
int CRYPTOi__BN_sqr(BIGNUM *r, const BIGNUM *a, BN_CTX *ctx);
void CRYPTOi__bn_sqr_normal(unsigned long *r, unsigned long *a, int n, unsigned long *tmp);
void CRYPTOi__bn_from_montgomery_words(BN_ULONG *ret, BN_ULONG *a, const BN_ULONG *np, int num, BN_ULONG n0);
unsigned long CRYPTOi__BN_mod_inverse_word(unsigned long n);
int CRYPTOi__BN_gen_exp_bits(const BIGNUM *e, unsigned char **out, int unused, BN_CTX *ctx);
int CRYPTOi__BN_gen_exp_string(unsigned char *str, BIGNUM *p, int sCryptoBnNumBitsWordBits);
int CRYPTOi__BN_MONT_CTX_set_word(BN_MONT_CTX *mont, const BIGNUM *mod, BN_CTX *ctx);
BN_MONT_CTX *CRYPTOi__BN_MONT_CTX_new(void);
void CRYPTOi__BN_MONT_CTX_init(BN_MONT_CTX *mont);
void CRYPTOi__BN_MONT_CTX_free(BN_MONT_CTX *mont);
void CRYPTOi__BN_RECP_CTX_init(BN_RECP_CTX *recp);
void CRYPTOi__BN_RECP_CTX_free(BN_RECP_CTX *recp);
int CRYPTOi__BN_RECP_CTX_set(BN_RECP_CTX *recp, const BIGNUM *d, BN_CTX *ctx);
int CRYPTOi__BN_mod_mul_reciprocal(BIGNUM *r, const BIGNUM *x, const BIGNUM *y, const BN_RECP_CTX *recp, BN_CTX *ctx);
int CRYPTOi__BN_div_recp(BIGNUM *dv, BIGNUM *rem, BIGNUM *m, BN_RECP_CTX *recp, BN_CTX *ctx);
int CRYPTOi__BN_reciprocal(BIGNUM *r, const BIGNUM *m, int len, BN_CTX *ctx);
int CRYPTOi__BN_mod_exp_recp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx);
int CRYPTOi__BN_mod_exp_mont(BIGNUM *rr_in, BIGNUM *a_in, BIGNUM *p, BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *in_mont);
/* END mkheaders: generated region */

#endif
