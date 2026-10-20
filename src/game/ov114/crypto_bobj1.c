/*
 * file:     crypto_bobj1.c
 * unit:     yes
 * function: CRYPTOi__BN_num_bits_word, CRYPTOi__BN_num_bits, CRYPTOi__BN_clear_free, CRYPTOi__BN_free, CRYPTOi__bn_zexpand, CRYPTOi__bn_fix_top, CRYPTOi__BN_init, CRYPTOi__BN_new, CRYPTOi__BN_CTX_new, CRYPTOi__BN_CTX_init, CRYPTOi__BN_CTX_free, CRYPTOi__bn_expand2, CRYPTOi__BN_copy, CRYPTOi__BN_clear, CRYPTOi__BN_set_word, CRYPTOi__BN_bin2bn, CRYPTOi__BN_bn2bin, CRYPTOi__BN_ucmp, CRYPTOi__BN_set_bit, CRYPTOi__BN_is_bit_set, CRYPTOi__BN_lshift, CRYPTOi__BN_rshift, CRYPTOi__BN_add_word, CRYPTOi__BN_sub_word, CRYPTOi__BN_add, CRYPTOi__BN_uadd, CRYPTOi__BN_usub, CRYPTOi__BN_sub, CRYPTOi__BN_mul, CRYPTOi__bn_mul_normal, CRYPTOi__BN_div, CRYPTOi__BN_mod, CRYPTOi__BN_mod_exp, CRYPTOi__BN_sqr, CRYPTOi__bn_sqr_normal, CRYPTOi__bn_from_montgomery_words, CRYPTOi__BN_mod_inverse_word, CRYPTOi__BN_gen_exp_bits, CRYPTOi__BN_gen_exp_string, CRYPTOi__BN_MONT_CTX_set_word, CRYPTOi__BN_MONT_CTX_new, CRYPTOi__BN_MONT_CTX_init, CRYPTOi__BN_MONT_CTX_free, CRYPTOi__BN_RECP_CTX_init, CRYPTOi__BN_RECP_CTX_free, CRYPTOi__BN_RECP_CTX_set, CRYPTOi__BN_mod_mul_reciprocal, CRYPTOi__BN_div_recp, CRYPTOi__BN_reciprocal, CRYPTOi__BN_mod_exp_recp, CRYPTOi__BN_mod_exp_mont
 * address:  0x021CAB34
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sCryptoBnNumBitsWordBits  0x021CE202  data
 *   CRYPTOi_MyFree  0x021CAAE8  arm  ov114
 *   CRYPTOi_MyAlloc  0x021CAAB4  arm  ov114
 *   MI_CpuCopy8  0x02082D44  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   CRYPTOi__bn_add_words                    0x021cdb08 arm ov114
 *   CRYPTOi__bn_mul_words  0x021CDA38  arm  ov114
 *   CRYPTOi__bn_mul_add_words  0x021CD984  arm  ov114
 *   CRYPTOi__bn_div_words  0x021CDAE8  arm  ov114
 *   CRYPTOi__BN_mod_exp_mont  0x021CD210  arm  ov114
 *   CRYPTOi__bn_sqr_words  0x021CDAC0  arm  ov114
 *   CRYPTOi__bn_sub_words                    0x021cdb9c arm ov114
 *   _u32_div_f     0x0209C2B0  arm
 *   sCryptoBnGenExpBitsTable16  0x021CE1F8  data  ov114
 *   sCryptoBnGenExpBitsTable4  0x021CE1EE  data  ov114
 *   sCryptoBnGenExpBitsTable2  0x021CE1E4  data  ov114
 *   sCryptoBnGenExpStringShifts  0x021CF930  data  ov114
 *   CRYPTOi__BN_set_word             0x021caec8 arm
 *   CRYPTOi__BN_copy                 0x021cae20 arm
 *   CRYPTOi__BN_MONT_CTX_new         0x021cc9c4 arm
 *   CRYPTOi__BN_MONT_CTX_set_word    0x021cc80c arm
 *   CRYPTOi__BN_gen_exp_bits         0x021cc530 arm
 *   _s32_div_f                       0x0209c0a4 arm
 *   CRYPTOi__bn_zexpand              0x021cac24 arm
 *   CRYPTOi__BN_mod                  0x021cc0fc arm
 *   CRYPTOi__bn_expand2              0x021cadac arm
 *   CRYPTOi__bn_mul_normal           0x021cba90 arm
 *   CRYPTOi__bn_from_montgomery_words 0x021cc38c arm
 *   CRYPTOi__bn_sqr_normal           0x021cc2b0 arm
 *   MI_CpuCopy8                      0x02082d44 arm
 *   CRYPTOi__bn_fix_top              0x021cac8c arm
 *   CRYPTOi__BN_MONT_CTX_free        0x021cca24 arm
 */
#include "crypto_types.h"

#define BN_MASK2   0xffffffffUL
#define BN_MASK2l  0xffffUL
#define LBITS(a)   ((a) & BN_MASK2l)
#define HBITS(a)   (((a) >> 16) & BN_MASK2l)
#define L2HBITS(a) ((BN_ULONG)((a) & BN_MASK2l) << 16)
#define mul64(l, h, bl, bh)                  \
    {                                        \
        BN_ULONG m, m1, lt, ht;              \
        lt = l;                              \
        ht = h;                              \
        m = (bh) * (lt);                     \
        lt = (bl) * (lt);                    \
        m1 = (bl) * (ht);                    \
        ht = (bh) * (ht);                    \
        m = (m + m1) & BN_MASK2;             \
        if (m < m1) ht += L2HBITS(1L);       \
        ht += HBITS(m);                      \
        m1 = L2HBITS(m);                     \
        lt = (lt + m1) & BN_MASK2;           \
        if (lt < m1) ht++;                   \
        l = lt;                              \
        h = ht;                              \
    }
#define NULL ((void *)0)
#define GET_RUN(c, cnt, sCryptoBnNumBitsWordBits)     c = *sCryptoBnNumBitsWordBits++;     cnt = *sCryptoBnNumBitsWordBits++;     if (cnt == 0xff && c == 0) {         for (c = *sCryptoBnNumBitsWordBits++; *sCryptoBnNumBitsWordBits == 0xff && c == 0; c = *sCryptoBnNumBitsWordBits++) {             cnt += 0x100;             sCryptoBnNumBitsWordBits++;         }         cnt += *sCryptoBnNumBitsWordBits++ + 1;     }

#include "crypto_util.h"
#include "../arm9/mi_memory.h"
#include "crypto_bobj2.h"
int CRYPTOi__BN_mod_exp_mont(BIGNUM *rr_in, BIGNUM *a_in, BIGNUM *p,
                             BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *in_mont);
extern int CRYPTOi__BN_set_word(BIGNUM *, BN_ULONG);
extern BIGNUM *CRYPTOi__BN_copy(BIGNUM *, const BIGNUM *);
extern BN_MONT_CTX *CRYPTOi__BN_MONT_CTX_new(void);
extern int CRYPTOi__BN_MONT_CTX_set_word(BN_MONT_CTX *, const BIGNUM *, BN_CTX *);
extern int CRYPTOi__BN_gen_exp_bits(const BIGNUM *, unsigned char **, int, BN_CTX *);
BIGNUM *CRYPTOi__bn_zexpand(BIGNUM *a, int n);
extern int CRYPTOi__BN_mod(BIGNUM *, const BIGNUM *, const BIGNUM *, BN_CTX *);
extern BIGNUM *CRYPTOi__bn_expand2(BIGNUM *, int);
void CRYPTOi__bn_mul_normal(unsigned long *r, unsigned long *a, int na, unsigned long *b, int nb);
void CRYPTOi__bn_from_montgomery_words(BN_ULONG *ret, BN_ULONG *a, const BN_ULONG *np, int num, BN_ULONG n0);
extern void CRYPTOi__bn_sqr_normal(BN_ULONG *, BN_ULONG *, int, BN_ULONG *);
void CRYPTOi__bn_fix_top(BIGNUM *a);
extern void CRYPTOi__BN_MONT_CTX_free(BN_MONT_CTX *);
int CRYPTOi__BN_num_bits_word(BN_ULONG l);
int CRYPTOi__BN_num_bits(const BIGNUM *a);
void CRYPTOi__BN_clear_free(BIGNUM *a);
void CRYPTOi__BN_free(BIGNUM *a);
void CRYPTOi__BN_init(BIGNUM *a);
BIGNUM *CRYPTOi__BN_new(void);
BN_CTX *CRYPTOi__BN_CTX_new(void);
void CRYPTOi__BN_CTX_init(BN_CTX *ctx);
void CRYPTOi__BN_CTX_free(BN_CTX *ctx);
void CRYPTOi__BN_clear(BIGNUM *p);
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
int CRYPTOi__BN_div(BIGNUM *dv, BIGNUM *rm, const BIGNUM *num, const BIGNUM *divisor, BN_CTX *ctx);
int CRYPTOi__BN_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx);
int CRYPTOi__BN_sqr(BIGNUM *r, const BIGNUM *a, BN_CTX *ctx);
unsigned long CRYPTOi__BN_mod_inverse_word(unsigned long n);
int CRYPTOi__BN_gen_exp_string(unsigned char *str, BIGNUM *p, int sCryptoBnNumBitsWordBits);
void CRYPTOi__BN_MONT_CTX_init(BN_MONT_CTX *mont);
void CRYPTOi__BN_RECP_CTX_init(BN_RECP_CTX *recp);
void CRYPTOi__BN_RECP_CTX_free(BN_RECP_CTX *recp);
int CRYPTOi__BN_RECP_CTX_set(BN_RECP_CTX *recp, const BIGNUM *d, BN_CTX *ctx);
int CRYPTOi__BN_mod_mul_reciprocal(BIGNUM *r, const BIGNUM *x, const BIGNUM *y, const BN_RECP_CTX *recp, BN_CTX *ctx);
int CRYPTOi__BN_div_recp(BIGNUM *dv, BIGNUM *rem, BIGNUM *m, BN_RECP_CTX *recp, BN_CTX *ctx);
int CRYPTOi__BN_reciprocal(BIGNUM *r, const BIGNUM *m, int len, BN_CTX *ctx);
int CRYPTOi__BN_mod_exp_recp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx);
extern const char sCryptoBnNumBitsWordBits[];
extern unsigned char sCryptoBnGenExpBitsTable16[10];
extern unsigned char sCryptoBnGenExpBitsTable4[10];
extern unsigned char sCryptoBnGenExpBitsTable2[10];
extern unsigned char *sCryptoBnGenExpStringShifts[7];









/*
 * sdk:      CRYPTOi__BN_num_bits_word (crypto_bobj1.o)
 *
 * The static nibble->bit-count table BN_num_bits_word::sCryptoBnNumBitsWordBits, 16 signed
 * bytes, is pinned at its image address rather than defined locally so the
 * pool word resolves to the vendor object's datum.
 */
int CRYPTOi__BN_num_bits_word(BN_ULONG l)
{
    int sh;
    if (l & 0xffff0000UL) {
        if (l & 0xff000000UL)
            sh = 24;
        else
            sh = 16;
    } else {
        if (l & 0xff00UL)
            sh = 8;
        else
            sh = 0;
    }
    l >>= sh;
    if (l & 0xf0)
        return sCryptoBnNumBitsWordBits[l >> 4] + sh + 4;
    return sCryptoBnNumBitsWordBits[l] + sh;
}









/*
 * sdk:      CRYPTOi__BN_num_bits (crypto_bobj1.o)
 */
int CRYPTOi__BN_num_bits(const BIGNUM *a)
{
    int i;

    if (a->top == 0)
        return 0;
    i = a->top - 1;
    return CRYPTOi__BN_num_bits_word(a->d[i]) + i * BN_BITS2;
}









/*
 * Null-guarded flush: seals the pending batch, then drains `a`.
 */
void CRYPTOi__BN_clear_free(BIGNUM *a)
{
    if (a == 0)
        return;
    CRYPTOi__BN_clear(a);
    CRYPTOi__BN_free(a);
}









/*
 * sdk:      CRYPTOi__BN_free (crypto_bobj1.o)
 * extra:    callee of CRYPTOi__BN_MONT_CTX_free / CRYPTOi__BN_RECP_CTX_free
 */
void CRYPTOi__BN_free(BIGNUM *a)
{
    if (a == NULL)
        return;
    if (a->d != NULL && !(a->flags & BN_FLG_STATIC_DATA))
        CRYPTOi_MyFree(a->d);
    a->flags |= BN_FLG_FREE;
    if (a->flags & BN_FLG_MALLOCED)
        CRYPTOi_MyFree(a);
}









/*
 * sdk:      CRYPTOi__bn_zexpand (crypto_bobj1.o)
 *
 * bn_wexpand shape: grow to n words then zero the newly exposed words.
 */
BIGNUM *CRYPTOi__bn_zexpand(BIGNUM *a, int n)
{
    int i;
    if (a->top < n) {
        if ((n > a->dmax ? CRYPTOi__bn_expand2(a, n) : a) == 0)
            return 0;
        if (a->d != 0) {
            for (i = a->top; i < n; i++)
                a->d[i] = 0;
        }
    }
    return a;
}









void CRYPTOi__bn_fix_top(BIGNUM *a)
{
    BN_ULONG *ftl;

    if (a->top <= 0)
        return;
    ftl = &a->d[a->top - 1];
    while (a->top > 0) {
        if (*ftl-- != 0)
            return;
        a->top--;
    }
}









/*
 * sdk:      CRYPTOi__BN_init (crypto_bobj1.o)
 */
void CRYPTOi__BN_init(BIGNUM *a)
{
    MI_CpuFill8(a, 0, sizeof(BIGNUM));
}









/*
 * sdk:      CRYPTOi__BN_new (crypto_bobj1.o)
 */
BIGNUM *CRYPTOi__BN_new(void)
{
    BIGNUM *ret = CRYPTOi_MyAlloc(sizeof(BIGNUM));

    if (ret == NULL)
        return NULL;
    ret->flags = BN_FLG_MALLOCED;
    ret->top = 0;
    ret->neg = 0;
    ret->dmax = 0;
    ret->d = NULL;
    return ret;
}









/*
 * sdk:      CRYPTOi__BN_CTX_new (crypto_bobj1.o)
 */
BN_CTX *CRYPTOi__BN_CTX_new(void)
{
    BN_CTX *ret = CRYPTOi_MyAlloc(sizeof(BN_CTX));

    if (ret == NULL)
        return NULL;
    CRYPTOi__BN_CTX_init(ret);
    ret->flags = 1;
    return ret;
}








/*
 * sdk:      CRYPTOi__BN_CTX_init (crypto_bobj1.o)
 */
void CRYPTOi__BN_CTX_init(BN_CTX *ctx)
{
    MI_CpuFill8(ctx, 0, sizeof(BN_CTX));
    ctx->tos = 0;
    ctx->flags = 0;
}








/*
 * sdk:      CRYPTOi__BN_CTX_free (crypto_bobj1.o)
 *
 * The first twelve BIGNUMs of the context are cleared, then the context itself is
 * released when its malloc flag is set.
 */
void CRYPTOi__BN_CTX_free(BN_CTX *ctx)
{
    int i;

    for (i = 0; i < 12; i++)
        CRYPTOi__BN_clear_free(&ctx->bn[i]);
    if (ctx->flags & 1)
        CRYPTOi_MyFree(ctx);
}








BIGNUM *CRYPTOi__bn_expand2(BIGNUM *a, int n)
{
    if (n > a->dmax) {
        BN_ULONG *newd;
        if (a->flags & 2)
            return 0;
        newd = CRYPTOi_MyAlloc((n + 1) * 4);
        if (newd == 0)
            return 0;
        if (a->d != 0) {
            MI_CpuCopy8(a->d, newd, a->top * 4);
            CRYPTOi_MyFree(a->d);
        }
        a->d = newd;
        a->dmax = n;
    }
    return a;
}







/*
 * sdk:      CRYPTOi__BN_copy (crypto_bobj1.o)
 * extra:    callee of CRYPTOi__BN_RECP_CTX_set
 */
BIGNUM *CRYPTOi__BN_copy(BIGNUM *a, const BIGNUM *b)
{
    BIGNUM *A;
    if (a == b)
        return a;
    A = (b->top <= a->dmax) ? a : CRYPTOi__bn_expand2(a, b->top);
    if (A == 0)
        return 0;
    MI_CpuCopy8(b->d, a->d, b->top * 4);
    {
        int t = b->top;
        a->top = t;
        if (t == 0) {
            if (a->d != 0)
                a->d[0] = 0;
        }
    }
    a->neg = b->neg;
    return a;
}







/*
 * sdk:      CRYPTOi__BN_clear (crypto_bobj1.o)
 */
void CRYPTOi__BN_clear(BIGNUM *p)
{
    if (p->d != 0)
        MI_CpuFill8(p->d, 0, p->dmax * 4);
    p->top = 0;
    p->neg = 0;
}







/*
 * sdk:      CRYPTOi__BN_set_word (crypto_bobj1.o)
 * extra:    callee of CRYPTOi__BN_RECP_CTX_set
 */
int CRYPTOi__BN_set_word(BIGNUM *a, unsigned long w)
{
    BIGNUM *A;
    A = (a->dmax < 1) ? CRYPTOi__bn_expand2(a, 2) : a;
    if (A == 0)
        return 0;
    a->neg = 0;
    a->top = 0;
    a->d[0] = w;
    if (a->d[0] != 0)
        a->top = 1;
    return 1;
}






/*
 * sdk:      CRYPTOi__BN_bin2bn (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 */
BIGNUM *CRYPTOi__BN_bin2bn(unsigned char *s, unsigned int len, BIGNUM *ret)
{
    unsigned int i, m;
    unsigned long l;

    if (ret == 0)
        ret = CRYPTOi__BN_new();
    if (ret == 0)
        return 0;
    l = 0;
    if (len == 0) {
        ret->top = 0;
        return ret;
    }
    if ((((((int)len + 2) * 8 + 31) / 32 <= ret->dmax) ? ret : CRYPTOi__bn_expand2(ret, (((int)len + 2) * 8) / 32 + 1)) == 0)
        return 0;
    i = ((len - 1) / 4) + 1;
    m = ((len - 1) % 4);
    ret->top = i;
    while (len--) {
        l = (l << 8) | *(s++);
        if (m-- == 0) {
            ret->d[--i] = l;
            l = 0;
            m = 3;
        }
    }
    CRYPTOi__bn_fix_top(ret);
    return ret;
}






/*
 * sdk:      CRYPTOi__BN_bn2bin (crypto_bobj1.o)
 *
 * Big-endian byte serialisation; returns the byte count.
 */
int CRYPTOi__BN_bn2bin(const BIGNUM *a, unsigned char *to)
{
    int n = CRYPTOi__BN_num_bits(a);
    int i = (n + 7) / 8;
    int j = i - 1;
    if (i <= 0)
        return i;
    do {
        unsigned int l = a->d[j / 4];
        *to++ = (unsigned char)(l >> (8 * (j % 4)));
    } while (j-- > 0);
    return i;
}






/*
 * sdk:      CRYPTOi__BN_ucmp (crypto_bobj1.o)
 *
 * Unsigned magnitude compare.  The early return yields the signed word
 * difference; the pointer locals are declared before the loop index so the
 * allocator keeps the two data cursors in r2/r3 and the index in ip.
 */
int CRYPTOi__BN_ucmp(const BIGNUM *a, const BIGNUM *b)
{
    BN_ULONG *ap, *bp;
    int i;
    if (a->top - b->top)
        return a->top - b->top;
    ap = a->d;
    bp = b->d;
    for (i = a->top - 1; i >= 0; i--) {
        unsigned int t1 = ap[i];
        unsigned int t2 = bp[i];
        if (t1 != t2)
            return (t1 > t2) ? 1 : -1;
    }
    return 0;
}





/*
 * sdk:      CRYPTOi__BN_set_bit (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 */
int CRYPTOi__BN_set_bit(BIGNUM *a, int n)
{
    int i, j, k;

    i = n / 32;
    j = n % 32;
    if (a->top <= i) {
        if (((i + 1 > a->dmax) ? CRYPTOi__bn_expand2(a, i + 1) : a) == 0)
            return 0;
        for (k = a->top; k < i + 1; k++)
            a->d[k] = 0;
        a->top = i + 1;
    }
    a->d[i] |= (1 << j);
    return 1;
}





/*
 * sdk:      CRYPTOi__BN_is_bit_set (crypto_bobj1.o)
 */
int CRYPTOi__BN_is_bit_set(const BIGNUM *a, int n)
{
    int i;
    int j;

    if (n < 0)
        return 0;
    i = n / 32;
    j = n % 32;
    if (a->top <= i)
        return 0;
    return (a->d[i] & (1u << j)) ? 1 : 0;
}





/*
 * sdk:      CRYPTOi__BN_lshift (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 */
int CRYPTOi__BN_lshift(BIGNUM *r, BIGNUM *a, int n)
{
    int i, nw, lb, rb;
    unsigned long *t, *f;
    unsigned long l;

    nw = n / 32;
    if (((a->top + nw + 1 > r->dmax) ? CRYPTOi__bn_expand2(r, a->top + nw + 1) : r) == 0)
        return 0;
    r->neg = a->neg;
    lb = n % 32;
    rb = 32 - lb;
    f = a->d;
    t = r->d;
    t[a->top + nw] = 0;
    if (lb == 0)
        for (i = a->top - 1; i >= 0; i--)
            t[nw + i] = f[i];
    else
        for (i = a->top - 1; i >= 0; i--) {
            l = f[i];
            t[nw + i + 1] |= (l >> rb);
            t[nw + i] = (l << lb);
        }
    MI_CpuFill8(t, 0, nw * 4);
    r->top = a->top + nw + 1;
    CRYPTOi__bn_fix_top(r);
    return 1;
}








#define bn_wexpand(a, words) (((words) <= (a)->dmax) ? (a) : CRYPTOi__bn_expand2(a, (words)))












/*
 * sdk:      CRYPTOi__BN_rshift (libcrypto.TWL.HYB.a crypto_bobj1.o)
 */
int CRYPTOi__BN_rshift(BIGNUM *r, const BIGNUM *a, int n)
{
    int i, j, nw, lb, rb;
    BN_ULONG *t, *f;
    BN_ULONG l, tmp;

    nw = n / 32;
    rb = n % 32;
    lb = 32 - rb;
    if (nw > a->top) {
        CRYPTOi__BN_set_word(r, 0);
        return 1;
    }
    if (r != a) {
        if (bn_wexpand(r, a->top - nw + 2) == 0)
            return 0;
        r->neg = a->neg;
    }

    f = &(a->d[nw]);
    t = r->d;
    j = a->top - nw;
    r->top = j;

    if (rb == 0) {
        for (i = j + 1; i > 0; i--)
            *(t++) = *(f++);
    } else {
        l = *(f++);
        for (i = 1; i < j; i++) {
            tmp = l >> rb;
            l = *(f++);
            *(t++) = tmp | (l << lb);
        }
        *(t++) = l >> rb;
        *t = 0;
    }
    CRYPTOi__bn_fix_top(r);
    return 1;
}












/*
 * sdk:      CRYPTOi__BN_add_word (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 *
 * BN_add_word: negative-a path either delegates to BN_sub_word (>1 word) or
 * inlines the single-word subtract, else expands and ripple-adds w.
 *
 * The vendor build pools the literal 0 in one register hoisted to the frame
 * head, and it is shared by all three sign/top stores (a->neg = 0 in the
 * multi-word branch, a->neg = 0 and a->top = 0 in the two single-word
 * branches).  Folding the shared `a->neg = 0` out of the inner if/else -- the
 * obvious spelling, and two literals instead of three -- loses the pool and
 * costs 46 bytes of register churn.  `l = w + a->d[i]` keeps the loop add's
 * operand order.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/CRYPTOi__BN_add_word.c \
 *       --func CRYPTOi__BN_add_word --addr 0x021CB3B4 --region ov114 --arm --cc 1.1p1 \
 *       --lang c99
 */
int CRYPTOi__BN_add_word(BIGNUM *a, unsigned long w)
{
    unsigned long l;
    int i;

    if (w == 0)
        return 1;
    if (a->neg) {
        if (a->top > 1) {
            a->neg = 0;
            i = CRYPTOi__BN_sub_word(a, w);
            a->neg = 1;
            return i;
        }
        l = a->d[0];
        if (l > w) {
            a->d[0] = l - w;
        } else if (l < w) {
            a->neg = 0;
            a->d[0] = w - l;
        } else {
            a->neg = 0;
            a->top = 0;
        }
        return 1;
    }
    if (((a->top + 1 > a->dmax) ? CRYPTOi__bn_expand2(a, a->top + 1) : a) == 0)
        return 0;
    a->d[a->top] = 0;
    i = 0;
    for (;;) {
        l = w + a->d[i];
        a->d[i] = l;
        if (w > l) {
            w = 1;
            i++;
        } else {
            break;
        }
    }
    if (i >= a->top)
        a->top++;
    return 1;
}












/*
 * sdk:      CRYPTOi__BN_sub_word (libcrypto.TWL.HYB.a crypto_bobj1.o)
 */
int CRYPTOi__BN_sub_word(BIGNUM *a, BN_ULONG w)
{
    int i;

    if (w == 0)
        return 1;
    if (a->neg) {
        a->neg = 0;
        i = CRYPTOi__BN_add_word(a, w);
        a->neg = 1;
        return i;
    }
    if (a->top <= 1) {
        if (a->top == 0) {
            if (bn_wexpand(a, 1) == 0)
                return 0;
            a->d[0] = w;
            a->neg = 1;
            a->top = 1;
            return 1;
        }
        if (a->d[0] == w)
            a->top = 0;
        else if (a->d[0] > w)
            a->d[0] -= w;
        else {
            w -= a->d[0];
            a->neg = 1;
            a->d[0] = w;
        }
        return 1;
    }
    i = 0;
    for (;;) {
        if (a->d[i] >= w) {
            a->d[i] -= w;
            break;
        } else {
            a->d[i] -= w;
            i++;
            w = 1;
        }
    }
    if (a->d[i] == 0 && i == a->top - 1)
        a->top--;
    return 1;
}












/*
 * sdk:      CRYPTOi__BN_add (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 */
int CRYPTOi__BN_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b)
{
    const BIGNUM *tmp;
    int a_neg = a->neg;

    if (a_neg ^ b->neg) {
        if (a_neg) {
            tmp = a;
            a = b;
            b = tmp;
        }
        if (CRYPTOi__BN_ucmp(a, b) < 0) {
            if (CRYPTOi__BN_usub(r, (BIGNUM *)b, (BIGNUM *)a) == 0)
                return 0;
            r->neg = 1;
        } else {
            if (CRYPTOi__BN_usub(r, (BIGNUM *)a, (BIGNUM *)b) == 0)
                return 0;
            r->neg = 0;
        }
        return 1;
    }
    if (a_neg)
        r->neg = 1;
    else
        r->neg = 0;
    if (CRYPTOi__BN_uadd(r, a, b) == 0)
        return 0;
    return 1;
}










/*
 * sdk:      CRYPTOi__BN_uadd (libcrypto.TWL.HYB.a crypto_bobj1.o)
 */
int CRYPTOi__BN_uadd(BIGNUM *r, const BIGNUM *a, const BIGNUM *b)
{
    int max, min, i;
    BN_ULONG *ap, *bp, *rp, carry, t1;
    const BIGNUM *tmp;

    if (a->top < b->top) {
        tmp = a;
        a = b;
        b = tmp;
    }
    max = a->top;
    min = b->top;

    if (bn_wexpand(r, max + 1) == 0)
        return 0;

    r->top = max;

    ap = a->d;
    bp = b->d;
    rp = r->d;

    carry = CRYPTOi__bn_add_words(rp, ap, bp, min);
    rp += min;
    ap += min;
    bp += min;
    i = min;

    if (carry) {
        while (i < max) {
            i++;
            t1 = *(ap++);
            if ((*(rp++) = t1 + 1) >= t1) {
                carry = 0;
                break;
            }
        }
        if ((i >= max) && carry) {
            *(rp++) = 1;
            r->top++;
        }
    }
    if (rp != ap) {
        for (; i < max; i++)
            *(rp++) = *(ap++);
    }
    return 1;
}








#undef bn_wexpand







#undef bn_wexpand






#undef bn_wexpand





#undef bn_wexpand




#undef bn_wexpand



#undef bn_wexpand


#undef bn_wexpand

#undef bn_wexpand


#define bn_wexpand(a, w) (((w) <= (a)->dmax) ? (a) : CRYPTOi__bn_expand2(a, (w)))










/*
 * sdk:      CRYPTOi__BN_usub (crypto_bobj1.o)
 *
 * a and b are plain `BIGNUM *` (no const) with OpenSSL's `int i, carry`. The const
 * qualifier puts max/min after the parameters in the colouring order; `long i` only
 * half-compensates.  OpenSSL's `& BN_MASK2` on every t1/t2 expression is inert.
 */
int CRYPTOi__BN_usub(BIGNUM *r, BIGNUM *a, BIGNUM *b)
{
    int max, min;
    register BN_ULONG t1, t2, *ap, *bp, *rp;
    int i, carry;

    if (a->top < b->top)
        return 0;
    max = a->top;
    min = b->top;
    if (bn_wexpand(r, max) == 0)
        return 0;

    ap = a->d;
    bp = b->d;
    rp = r->d;

    carry = 0;
    for (i = 0; i < min; i++)
    {
        t1 = *(ap++);
        t2 = *(bp++);
        if (carry)
        {
            carry = (t1 <= t2);
            t1 = t1 - t2 - 1;
        }
        else
        {
            carry = (t1 < t2);
            t1 = t1 - t2;
        }
        *(rp++) = t1;
    }
    if (carry)
    {
        while (i < max)
        {
            i++;
            t1 = *(ap++);
            t2 = t1 - 1;
            *(rp++) = t2;
            if (t1 > t2)
                break;
        }
    }
    if (rp != ap)
    {
        for (;;)
        {
            if (i++ >= max) break;
            rp[0] = ap[0];
            if (i++ >= max) break;
            rp[1] = ap[1];
            if (i++ >= max) break;
            rp[2] = ap[2];
            if (i++ >= max) break;
            rp[3] = ap[3];
            rp += 4;
            ap += 4;
        }
    }
    r->top = max;
    CRYPTOi__bn_fix_top(r);
    return 1;
}









#undef bn_wexpand








#undef bn_wexpand







#undef bn_wexpand






#undef bn_wexpand





#undef bn_wexpand




#undef bn_wexpand



#undef bn_wexpand


#undef bn_wexpand

#undef bn_wexpand

#define bn_wexpand(a, words) (((words) <= (a)->dmax) ? (a) : CRYPTOi__bn_expand2(a, (words)))










/*
 * sdk:      CRYPTOi__BN_sub (libcrypto.TWL.HYB.a crypto_bobj1.o)
 */
int CRYPTOi__BN_sub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b)
{
    int max;
    int add = 0, neg = 0;
    const BIGNUM *tmp;

    if (a->neg) {
        if (b->neg) {
            tmp = a;
            a = b;
            b = tmp;
        } else {
            add = 1;
            neg = 1;
        }
    } else {
        if (b->neg) {
            add = 1;
            neg = 0;
        }
    }

    if (add) {
        if (!CRYPTOi__BN_uadd(r, a, b))
            return 0;
        r->neg = neg;
        return 1;
    }

    max = (a->top > b->top) ? a->top : b->top;
    if (bn_wexpand(r, max) == 0)
        return 0;
    if (CRYPTOi__BN_ucmp(a, b) < 0) {
        if (!CRYPTOi__BN_usub(r, (BIGNUM *)b, (BIGNUM *)a))
            return 0;
        r->neg = 1;
    } else {
        if (!CRYPTOi__BN_usub(r, (BIGNUM *)a, (BIGNUM *)b))
            return 0;
        r->neg = 0;
    }
    return 1;
}








int CRYPTOi__BN_mul(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx)
{
    int top, al, bl;
    BIGNUM *rr;
    int neg;

    al = a->top;
    bl = b->top;
    if (al == 0 || bl == 0) {
        CRYPTOi__BN_set_word(r, 0);
        return 1;
    }
    top = al + bl;
    neg = a->neg ^ b->neg;
    if (r == a || r == b)
        rr = &ctx->bn[ctx->tos + 1];
    else
        rr = r;
    if (((top > rr->dmax) ? CRYPTOi__bn_expand2(rr, top) : rr) == 0)
        return 0;
    rr->top = top;
    CRYPTOi__bn_mul_normal(rr->d, a->d, al, b->d, bl);
    r->neg = neg;
    CRYPTOi__bn_fix_top(rr);
    if (r != rr)
        CRYPTOi__BN_copy(r, rr);
    return 1;
}






#undef bn_wexpand





#undef bn_wexpand




#undef bn_wexpand



#undef bn_wexpand


#undef bn_wexpand

#undef bn_wexpand
#define bn_wexpand(a, w) (((w) <= (a)->dmax) ? (a) : CRYPTOi__bn_expand2(a, (w)))








/*
 * sdk:      CRYPTOi__bn_mul_normal (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 */
void CRYPTOi__bn_mul_normal(unsigned long *r, unsigned long *a, int na, unsigned long *b, int nb)
{
    unsigned long *rr;

    if (na < nb) {
        int itmp;
        unsigned long *ltmp;

        itmp = na;
        na = nb;
        nb = itmp;
        ltmp = a;
        a = b;
        b = ltmp;
    }
    rr = &(r[na]);
    rr[0] = CRYPTOi__bn_mul_words(r, a, na, b[0]);
    for (;;) {
        if (--nb <= 0)
            return;
        rr[1] = CRYPTOi__bn_mul_add_words(&(r[1]), a, na, b[1]);
        if (--nb <= 0)
            return;
        rr[2] = CRYPTOi__bn_mul_add_words(&(r[2]), a, na, b[2]);
        if (--nb <= 0)
            return;
        rr[3] = CRYPTOi__bn_mul_add_words(&(r[3]), a, na, b[3]);
        if (--nb <= 0)
            return;
        rr[4] = CRYPTOi__bn_mul_add_words(&(r[4]), a, na, b[4]);
        rr += 4;
        r += 4;
        b += 4;
    }
}








/*
 * sdk:      CRYPTOi__BN_div (libcrypto.TWL.HYB.a crypto_bobj1.o)
 *
 * The object has no DWARF for this function; the shape follows the
 * relocations and the BN_CTX layout of the other crypto_bobj1.o rows.
 */
int CRYPTOi__BN_div(BIGNUM *dv, BIGNUM *rm, const BIGNUM *num, const BIGNUM *divisor, BN_CTX *ctx)
{
    int norm_shift, i, j, loop;
    BIGNUM *tmp, wnum, *snum, *sdiv, *res;
    BN_ULONG *resp, *wnump;
    BN_ULONG d0, d1;
    int num_n, div_n;

    if (divisor->top == 0 || (divisor->top == 1 && divisor->d[0] == 0))
        return 0;

    if (CRYPTOi__BN_ucmp(num, divisor) < 0)
    {
        if (rm != 0)
        {
            if (CRYPTOi__BN_copy(rm, num) == 0)
                return 0;
        }
        if (dv != 0)
            CRYPTOi__BN_set_word(dv, 0);
        return 1;
    }

    tmp = &ctx->bn[ctx->tos];
    tmp->neg = 0;
    snum = &ctx->bn[ctx->tos + 1];
    sdiv = &ctx->bn[ctx->tos + 2];
    if (dv == 0)
        res = &ctx->bn[ctx->tos + 3];
    else
        res = dv;

    norm_shift = BN_BITS2 - (CRYPTOi__BN_num_bits(divisor) % BN_BITS2);
    if (!CRYPTOi__BN_lshift(sdiv, (BIGNUM *)divisor, norm_shift))
        return 0;
    sdiv->neg = 0;
    if (!CRYPTOi__BN_lshift(snum, (BIGNUM *)num, norm_shift + BN_BITS2))
        return 0;
    snum->neg = 0;
    div_n = sdiv->top;
    num_n = snum->top;
    loop = num_n - div_n;

    CRYPTOi__BN_init(&wnum);
    wnum.d = &snum->d[loop];
    wnum.top = div_n;
    wnum.dmax = snum->dmax + 1;

    d0 = sdiv->d[div_n - 1];
    d1 = (div_n == 1) ? 0 : sdiv->d[div_n - 2];

    wnump = &snum->d[num_n - 1];

    if (!bn_wexpand(res, loop + 1))
        goto err;
    res->neg = num->neg ^ divisor->neg;
    res->top = loop;
    resp = &res->d[loop - 1];

    if (!bn_wexpand(tmp, div_n + 1))
        goto err;

    if (CRYPTOi__BN_ucmp(&wnum, sdiv) >= 0)
    {
        if (!CRYPTOi__BN_usub(&wnum, &wnum, sdiv))
            goto err;
        *resp = 1;
        res->d[res->top - 1] = 1;
    }
    else
        res->top--;
    resp--;

    for (i = 0; i < loop - 1; i++)
    {
        BN_ULONG q, n0, n1;
        BN_ULONG l0;

        wnum.d--;
        wnum.top++;
        n0 = wnump[0];
        n1 = wnump[-1];
        if (n0 == d0)
            q = BN_MASK2;
        else
            q = CRYPTOi__bn_div_words(n0, n1, d0);
        {
            BN_ULONG t1l, t1h, t2l, t2h, t3l, t3h, ql, qh, t3t;
            t1h = n0;
            t1l = n1;
            for (;;)
            {
                t2l = LBITS(d1);
                t2h = HBITS(d1);
                ql = LBITS(q);
                qh = HBITS(q);
                mul64(t2l, t2h, ql, qh);

                t3t = LBITS(d0);
                t3h = HBITS(d0);
                mul64(t3t, t3h, ql, qh);
                t3l = (t1l - t3t) & BN_MASK2;
                if (t3l > t1l)
                    t3h++;
                t3h = (t1h - t3h) & BN_MASK2;

                if (t3h)
                    break;
                if (t2h < t3l)
                    break;
                if ((t2h == t3l) && (t2l <= wnump[-2]))
                    break;

                q--;
            }
        }
        l0 = CRYPTOi__bn_mul_words(tmp->d, sdiv->d, div_n, q);
        tmp->d[div_n] = l0;
        for (j = div_n + 1; j > 0; j--)
            if (tmp->d[j - 1])
                break;
        tmp->top = j;

        j = wnum.top;
        CRYPTOi__BN_sub(&wnum, &wnum, tmp);

        snum->top = snum->top + wnum.top - j;

        if (wnum.neg)
        {
            q--;
            j = wnum.top;
            CRYPTOi__BN_add(&wnum, &wnum, sdiv);
            snum->top += wnum.top - j;
        }
        *(resp--) = q;
        wnump--;
    }
    CRYPTOi__bn_fix_top(snum);
    if (rm != 0)
    {
        int neg = num->neg;
        if (!CRYPTOi__BN_rshift(rm, snum, norm_shift + BN_BITS2))
            return 0;
        rm->neg = neg;
    }
    return 1;
err:
    return 0;
}





#undef bn_wexpand




#undef bn_wexpand



#undef bn_wexpand


#undef bn_wexpand

#undef bn_wexpand
#define bn_wexpand(a, w) (((w) <= (a)->dmax) ? (a) : CRYPTOi__bn_expand2(a, (w)))









/*
 * Forwards four arguments behind a leading zero to CRYPTOi__BN_div.
 */
int CRYPTOi__BN_mod(BIGNUM *r, const BIGNUM *a, const BIGNUM *m, BN_CTX *ctx)
{
    return CRYPTOi__BN_div(0, r, a, m, ctx);
}









/*
 * sdk:      CRYPTOi__BN_mod_exp (crypto_bobj1.o)
 *
 * Montgomery path when the modulus is odd, reciprocal path otherwise.
 * Deferred callees (same object, open SDK, too large for this lane):
 * CRYPTOi__BN_mod_exp_mont (0x021CD210, 1908 B) and
 * CRYPTOi__BN_mod_exp_recp (0x021CCE7C, 916 B).
 */
int CRYPTOi__BN_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx)
{
    if (m->top > 0 && (m->d[0] & 1))
        return CRYPTOi__BN_mod_exp_mont(r, (BIGNUM *)a, (BIGNUM *)p, (BIGNUM *)m, ctx, 0);
    return CRYPTOi__BN_mod_exp_recp(r, a, p, m, ctx);
}









int CRYPTOi__BN_sqr(BIGNUM *r, const BIGNUM *a, BN_CTX *ctx)
{
    int max, al;
    BIGNUM *tmp, *rr;
    BN_ULONG t2[8];
    BN_ULONG t[16];

    tmp = &ctx->bn[ctx->tos];
    rr = (a != r) ? r : &ctx->bn[ctx->tos + 1];

    al = a->top;
    if (al <= 0)
    {
        r->top = 0;
        return 1;
    }

    max = al + al;
    if (bn_wexpand(rr, max) == 0)
        return 0;

    rr->top = max;
    rr->neg = 0;
    if (al == 4)
    {
        CRYPTOi__bn_sqr_normal((long unsigned int *)rr->d, (long unsigned int *)a->d, 4, (long unsigned int *)t2);
    }
    else if (al == 8)
    {
        CRYPTOi__bn_sqr_normal((long unsigned int *)rr->d, (long unsigned int *)a->d, 8, (long unsigned int *)t);
    }
    else
    {
        if (bn_wexpand(tmp, max) == 0)
            return 0;
        CRYPTOi__bn_sqr_normal((long unsigned int *)rr->d, (long unsigned int *)a->d, al, (long unsigned int *)tmp->d);
    }

    if (max > 0 && rr->d[max - 1] == 0)
        rr->top--;
    if (rr != r)
        CRYPTOi__BN_copy(r, rr);
    return 1;
}








/*
 * sdk:      CRYPTOi__bn_sqr_normal (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 */
void CRYPTOi__bn_sqr_normal(unsigned long *r, unsigned long *a, int n, unsigned long *tmp)
{
    int i, j, max;
    unsigned long *ap, *rp;

    max = n * 2;
    ap = a;
    rp = r;
    rp[0] = rp[max - 1] = 0;
    rp++;
    j = n;

    if (--j > 0) {
        ap++;
        rp[j] = CRYPTOi__bn_mul_words(rp, ap, j, a[0]);
        rp += 2;
    }

    for (i = n - 2; i > 0; i--) {
        unsigned long *prev = ap;
        j--;
        ap++;
        rp[j] = CRYPTOi__bn_mul_add_words(rp, ap, j, *prev);
        rp += 2;
    }

    CRYPTOi__bn_add_words((BN_ULONG *)r, (const BN_ULONG *)r, (const BN_ULONG *)r, max);
    CRYPTOi__bn_sqr_words(tmp, a, n);
    CRYPTOi__bn_add_words((BN_ULONG *)r, (const BN_ULONG *)r, (const BN_ULONG *)tmp, max);
}







void CRYPTOi__bn_from_montgomery_words(BN_ULONG *ret, BN_ULONG *a, const BN_ULONG *np, int num, BN_ULONG n0)
{
    BN_ULONG carry, v;
    BN_ULONG *ap2;
    int i;

    carry = 0;
    ap2 = a + num;
    for (i = 0; i < num; i++, a++, ap2++) {
        v = CRYPTOi__bn_mul_add_words((unsigned long *)a, (unsigned long *)np, num, a[0] * n0);
        v += carry;
        carry = (v < carry) ? 1 : 0;
        *ap2 += v;
        if (*ap2 < v)
            carry++;
    }
    i = num - 1;
    if (carry == 0) {
        if (a[i] == np[i]) {
            for (; i > 0; i--) {
                if (a[i] != np[i])
                    break;
            }
        }
        carry = (a[i] >= np[i]) ? 1 : 0;
    }
    if (carry) {
        CRYPTOi__bn_sub_words((BN_ULONG *)ret, (const BN_ULONG *)a, (const BN_ULONG *)np, num);
    } else {
        for (i = 0; i < num; i++)
            ret[i] = a[i];
    }
}




#undef bn_wexpand



#undef bn_wexpand


#undef bn_wexpand

#undef bn_wexpand
#define bn_wexpand(a, w) (((w) <= (a)->dmax) ? (a) : CRYPTOi__bn_expand2(a, (w)))






/*
 * sdk:      CRYPTOi__BN_mod_inverse_word (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 */
unsigned long CRYPTOi__BN_mod_inverse_word(unsigned long n)
{
    unsigned long a, b, q, r, t, res;
    unsigned long x0, x1;
    long sign;

    b = (0 - n) % n;
    x0 = 1;
    a = n;
    sign = -1;
    x1 = 0;
    while (b != 0) {
        q = a / b;
        r = a % b;
        t = q * x0 + x1;
        x1 = x0;
        x0 = t;
        a = b;
        b = r;
        sign = -sign;
    }
    if (sign < 0)
        x1 = n - x1;
    if (a == 1)
        res = x1 % n;
    else
        res = 0;
    return res;
}







/*
 * sdk:      CRYPTOi__BN_gen_exp_bits (crypto_bobj1.o)
 *
 * sCryptoBnGenExpBitsTable16, sCryptoBnGenExpBitsTable4, sCryptoBnGenExpBitsTable2 are the object's local tables p16, p4, p2.
 */
int CRYPTOi__BN_gen_exp_bits(const BIGNUM *e, unsigned char **out, int unused, BN_CTX *ctx)
{
    int top, sCryptoBnNumBitsWordBits, window, count, step, words, len;
    unsigned char *p;
    BIGNUM *tmp;

    tmp = &ctx->bn[ctx->tos];
    p = 0;
    top = e->top;
    sCryptoBnNumBitsWordBits = top << 5;
    if (top == 0)
        return 0;

    if (top == 1)
    {
        if (top == 1 && e->d[0] == 0x10001)
            p = sCryptoBnGenExpBitsTable16;
        else if (e->d[0] == 0x11 && top == 1)
            p = sCryptoBnGenExpBitsTable4;
        else if (e->d[0] == 3 && top == 1)
            p = sCryptoBnGenExpBitsTable2;
        window = 1;
        count = 1;
        step = 32;
    }
    else if (sCryptoBnNumBitsWordBits >= 256)
    {
        window = 5;
        count = 16;
        step = 7;
    }
    else if (sCryptoBnNumBitsWordBits >= 128)
    {
        window = 4;
        count = 8;
        step = 8;
    }
    else
    {
        window = 3;
        count = 4;
        step = 11;
    }

    words = (top * step * 2 + 7) / 4;
    if (p == 0)
    {
        if (bn_wexpand(tmp, words) == 0)
            return 0;
        p = (unsigned char *)tmp->d;
        len = CRYPTOi__BN_gen_exp_string(p + 4, (BIGNUM *)e, window) + 2;
        p[0] = len >> 8;
        p[1] = len;
        p[2] = window;
        p[3] = count;
    }
    else
    {
        len = 8;
    }
    *out = p;
    return len + 2;
}







/*
 * sdk:      CRYPTOi__BN_gen_exp_string (crypto_bobj1.o)
 *
 * Locals and types from the object's
 *        DWARF 1 entry (str, p, sCryptoBnNumBitsWordBits; sp, mask, shift, w, wh, wl, d, i,
 *        sqr, t, s, ss, top; d is the walking word pointer, i is both the
 *        string length and the return count). Closed by three source-shape
 *        changes, each fixing a scheduler tie: `w = wl = d[0];` before the
 *        top test (ldr above cmp), and post-decrement byte stores
 *        `*sp-- = x;` for every pair (terminator: add sp above strb; the
 *        256-run loop: sub above strb and 0xff in fp, which restores the
 *        r3/fp frame words). The declaration order
 *        below matches; the DWARF order recolours the whole body.
 */
int CRYPTOi__BN_gen_exp_string(unsigned char *str, BIGNUM *p, int sCryptoBnNumBitsWordBits)
{
    unsigned char *shift;
    unsigned char *sp;
    BN_ULONG *d;
    BN_ULONG wl;
    unsigned int sqr;
    int top;
    BN_ULONG wh;
    BN_ULONG w;
    unsigned int ss;
    unsigned int mask;
    unsigned int t;
    unsigned int s;
    unsigned int i;

    if (sCryptoBnNumBitsWordBits > 6)
        sCryptoBnNumBitsWordBits = 6;
    shift = sCryptoBnGenExpStringShifts[sCryptoBnNumBitsWordBits];
    mask = (1 << sCryptoBnNumBitsWordBits) - 1;
    ss = 0;
    i = ((p->top << 5) + sCryptoBnNumBitsWordBits - 1) / sCryptoBnNumBitsWordBits;
    i = i * 2 + 2;
    sp = str + i;
    *sp-- = 0;
    *sp-- = 0;

    d = p->d;
    top = p->top;
    w = wl = d[0];
    d++;
    if (top <= 1)
        wh = 0;
    else
        wh = *d++;
    sqr = 0;
    for (;;)
    {
        for (;;)
        {
            t = w & mask;
            s = shift[t];
            if (s == 0)
                break;
            ss += s;
            sqr += s;
            if (ss >= 32)
            {
                if (top <= 1)
                    break;
                top--;
                wl = wh;
                wh = 0;
                if (top > 1)
                    wh = *d++;
                ss -= 32;
            }
            if (ss == 0)
                w = wl;
            else
                w = (wl >> ss) | (wh << (32 - ss));
        }
        if (t == 0)
            break;
        *sp-- = sqr;
        *sp-- = t;
        if (sqr >= 256)
        {
            while (sqr >= 256)
            {
                sqr -= 256;
                *sp-- = 0xff;
                *sp-- = 0;
            }
        }
        ss += sCryptoBnNumBitsWordBits;
        sqr = sCryptoBnNumBitsWordBits;
        if (ss >= 32)
        {
            if (top <= 1)
                break;
            top--;
            wl = wh;
            wh = 0;
            if (top > 1)
                wh = *d++;
            ss -= 32;
        }
        if (ss == 0)
            w = wl;
        else
            w = (wl >> ss) | (wh << (32 - ss));
    }

    sp++;
    i = 2;
    while (sp[0] != 0 || sp[1] != 0)
    {
        str[0] = sp[0];
        str[1] = sp[1];
        sp += 2;
        i += 2;
        str += 2;
    }
    str[0] = 0;
    str[1] = 0;
    return i;
}







/*
 * sdk:      CRYPTOi__BN_MONT_CTX_set_word (crypto_bobj1.o)
 */
int CRYPTOi__BN_MONT_CTX_set_word(BN_MONT_CTX *mont, const BIGNUM *mod, BN_CTX *ctx)
{
    BIGNUM Ri;
    int ret;
    BN_ULONG w;

    ret = 0;
    if (mod->top == 0)
        return ret;
    if (CRYPTOi__BN_copy(&mont->N, mod) == 0)
        return ret;

    CRYPTOi__BN_init(&Ri);
    mont->use_word = 1;
    mont->ri = (CRYPTOi__BN_num_bits(mod) + 31) / 32;
    if (!CRYPTOi__BN_set_word(&mont->RR, 0))
        return ret;
    if (!CRYPTOi__BN_set_bit(&mont->RR, 32))
        goto err;

    w = mod->d[0];
    if (!CRYPTOi__BN_set_word(&Ri, CRYPTOi__BN_mod_inverse_word(w)))
        goto err;
    if (!CRYPTOi__BN_lshift(&Ri, &Ri, 32))
        goto err;
    if (!(Ri.top == 0 || (Ri.top == 1 && Ri.d[0] == 0)))
    {
        CRYPTOi__BN_sub_word(&Ri, 1);
    }
    else if (!CRYPTOi__BN_set_word(&Ri, 0xffffffff))
    {
        goto err;
    }

    mont->n0 = CRYPTOi__bn_div_words((Ri.top >= 2) ? Ri.d[1] : 0, (Ri.top >= 1) ? Ri.d[0] : 0, w);

    CRYPTOi__BN_set_word(&mont->RR, 0);
    if (!CRYPTOi__BN_set_bit(&mont->RR, mont->ri * 64))
        goto err;
    CRYPTOi__BN_mod(&mont->RR, &mont->RR, &mont->N, ctx);
    if (CRYPTOi__bn_zexpand(&mont->RR, mont->ri))
        ret = 1;

err:
    CRYPTOi__BN_free((&Ri));
    return ret;
}







/*
 * sdk:      CRYPTOi__BN_MONT_CTX_new (crypto_bobj1.o)
 */
BN_MONT_CTX *CRYPTOi__BN_MONT_CTX_new(void)
{
    BN_MONT_CTX *ret = CRYPTOi_MyAlloc(sizeof(BN_MONT_CTX));

    if (ret == NULL)
        return NULL;
    CRYPTOi__BN_MONT_CTX_init(ret);
    ret->flags = 1;
    return ret;
}







/*
 * sdk:      CRYPTOi__BN_MONT_CTX_init (crypto_bobj1.o)
 */
void CRYPTOi__BN_MONT_CTX_init(BN_MONT_CTX *mont)
{
    mont->use_word = 0;
    mont->ri = 0;
    CRYPTOi__BN_init(&mont->RR);
    CRYPTOi__BN_init(&mont->N);
    CRYPTOi__BN_init(&mont->Ni);
    mont->flags = 0;
}







/*
 * sdk:      CRYPTOi__BN_MONT_CTX_free (crypto_bobj1.o)
 */
void CRYPTOi__BN_MONT_CTX_free(BN_MONT_CTX *mont)
{
    CRYPTOi__BN_free(&mont->RR);
    CRYPTOi__BN_free(&mont->N);
    CRYPTOi__BN_free(&mont->Ni);
    if (mont->flags & 1)
        CRYPTOi_MyFree(mont);
}







/*
 * sdk:      CRYPTOi__BN_RECP_CTX_init (crypto_bobj1.o)
 */
void CRYPTOi__BN_RECP_CTX_init(BN_RECP_CTX *recp)
{
    CRYPTOi__BN_init(&recp->N);
    CRYPTOi__BN_init(&recp->Nr);
    recp->num_bits = 0;
    recp->flags = 0;
}






/*
 * sdk:      CRYPTOi__BN_RECP_CTX_free (crypto_bobj1.o)
 */
void CRYPTOi__BN_RECP_CTX_free(BN_RECP_CTX *recp)
{
    CRYPTOi__BN_free(&recp->N);
    CRYPTOi__BN_free(&recp->Nr);
    if (recp->flags & 1)
        CRYPTOi_MyFree(recp);
}






/*
 * sdk:      CRYPTOi__BN_RECP_CTX_set (crypto_bobj1.o)
 */
int CRYPTOi__BN_RECP_CTX_set(BN_RECP_CTX *recp, const BIGNUM *d, BN_CTX *ctx)
{
    CRYPTOi__BN_copy(&recp->N, d);
    CRYPTOi__BN_set_word(&recp->Nr, 0);
    recp->num_bits = CRYPTOi__BN_num_bits(d);
    recp->shift = 0;
    return 1;
}






/*
 * sdk:      CRYPTOi__BN_mod_mul_reciprocal (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 */
int CRYPTOi__BN_mod_mul_reciprocal(BIGNUM *r, const BIGNUM *x, const BIGNUM *y, const BN_RECP_CTX *recp, BN_CTX *ctx)
{
    int ret = 0;
    BIGNUM *a;

    a = &ctx->bn[ctx->tos++];
    if (y != 0) {
        if (x == y) {
            if (CRYPTOi__BN_sqr(a, (x), ctx) == 0)
                goto err;
        } else {
            if (CRYPTOi__BN_mul(a, x, y, ctx) == 0)
                goto err;
        }
    } else {
        a = (BIGNUM *)x;
    }
    CRYPTOi__BN_div_recp(0, r, a, (BN_RECP_CTX *)recp, ctx);
    ret = 1;
err:
    ctx->tos--;
    return ret;
}





/*
 * sdk:      CRYPTOi__BN_div_recp (crypto_bobj1.o)
 */
int CRYPTOi__BN_div_recp(BIGNUM *dv, BIGNUM *rem, BIGNUM *m, BN_RECP_CTX *recp, BN_CTX *ctx)
{
    int i, j, tos, ret = 0, ex;
    BIGNUM *a, *b, *d, *r;

    tos = ctx->tos;
    a = &(ctx->bn[ctx->tos++]);
    b = &(ctx->bn[ctx->tos++]);
    if (dv != 0)
        d = dv;
    else
        d = &(ctx->bn[ctx->tos++]);
    if (rem != 0)
        r = rem;
    else
        r = &(ctx->bn[ctx->tos++]);

    if (CRYPTOi__BN_ucmp(m, &recp->N) < 0)
    {
        CRYPTOi__BN_set_word(d, 0);
        CRYPTOi__BN_copy(r, m);
        ctx->tos = tos;
        return 1;
    }

    i = CRYPTOi__BN_num_bits(m);

    j = recp->num_bits * 2;
    if (j > i)
    {
        i = j;
        ex = 0;
    }
    else
    {
        ex = (i - j) / 2;
    }

    j = i / 2;

    if (i != recp->shift)
        recp->shift = CRYPTOi__BN_reciprocal(&recp->Nr, &recp->N, i, ctx);

    if (!CRYPTOi__BN_rshift(a, m, j - ex))
        goto err;
    if (!CRYPTOi__BN_mul(b, a, &recp->Nr, ctx))
        goto err;
    if (!CRYPTOi__BN_rshift(d, b, j + ex))
        goto err;
    d->neg = 0;
    if (!CRYPTOi__BN_mul(b, &recp->N, d, ctx))
        goto err;
    if (!CRYPTOi__BN_usub(r, (BIGNUM *)m, (BIGNUM *)b))
        goto err;
    r->neg = 0;

    j = 0;
    while (CRYPTOi__BN_ucmp(r, &recp->N) >= 0)
    {
        if (j++ > 2)
            goto err;
        if (!CRYPTOi__BN_usub(r, r, &recp->N))
            goto err;
        if (!CRYPTOi__BN_add_word(d, 1))
            goto err;
    }

    r->neg = (r->top == 0 || (r->top == 1 && r->d[0] == 0)) ? 0 : m->neg;
    d->neg = m->neg ^ recp->N.neg;
    ret = 1;
err:
    ctx->tos = tos;
    return ret;
}

#undef bn_wexpand
#define bn_wexpand(a, words) (((words) <= (a)->dmax) ? (a) : CRYPTOi__bn_expand2(a, (words)))



/*
 * sdk:      CRYPTOi__BN_reciprocal (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 */
int CRYPTOi__BN_reciprocal(BIGNUM *r, const BIGNUM *m, int len, BN_CTX *ctx)
{
    BIGNUM t;
    int ret = -1;

    CRYPTOi__BN_init(&t);
    CRYPTOi__BN_set_word(&t, 0);
    if (CRYPTOi__BN_set_bit(&t, len) != 0) {
        if (CRYPTOi__BN_div(r, 0, &t, m, ctx) != 0)
            ret = len;
    }
    CRYPTOi__BN_free((&t));
    return ret;
}




#define BN_is_zero(a) (((a)->top == 0) || (((a)->top == 1) && ((a)->d[0] == 0)))



#define BN_is_one(a) (((a)->top == 1) && ((a)->d[0] == 1))




/*
 * sdk:      CRYPTOi__BN_mod_exp_recp (crypto_bobj1.o)
 */
int CRYPTOi__BN_mod_exp_recp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx)
{
    int i, j, sCryptoBnNumBitsWordBits, ret = 0, wstart, wend, window, wvalue;
    int start = 1, ts = 0;
    BIGNUM *aa;
    BIGNUM val[16];
    BN_RECP_CTX recp;

    sCryptoBnNumBitsWordBits = CRYPTOi__BN_num_bits(p);

    if (BN_is_zero(a))
    {
        CRYPTOi__BN_set_word(r, 0);
        return 1;
    }
    if (BN_is_zero(p))
    {
        CRYPTOi__BN_set_word(r, 1);
        return 1;
    }
    if (BN_is_one(p))
    {
        CRYPTOi__BN_copy(r, a);
        return 1;
    }

    CRYPTOi__BN_RECP_CTX_init((&recp));
    if (CRYPTOi__BN_RECP_CTX_set(&recp, m, ctx) <= 0)
        goto err;

    CRYPTOi__BN_init(&(val[0]));
    ts = 1;
    aa = &(ctx->bn[ctx->tos++]);

    if (!CRYPTOi__BN_mod(&(val[0]), a, m, ctx))
        goto err;
    if (!CRYPTOi__BN_mod_mul_reciprocal(aa, &(val[0]), &(val[0]), &recp, ctx))
        goto err;

    if (sCryptoBnNumBitsWordBits <= 17)
        window = 1;
    else if (sCryptoBnNumBitsWordBits >= 256)
        window = 5;
    else if (sCryptoBnNumBitsWordBits >= 128)
        window = 4;
    else
        window = 3;

    j = 1 << (window - 1);
    for (i = 1; i < j; i++)
    {
        CRYPTOi__BN_init(&(val[i]));
        if (!CRYPTOi__BN_mod_mul_reciprocal(&(val[i]), &(val[i - 1]), aa, &recp, ctx))
            goto err;
    }
    ts = i;

    start = 1;
    wvalue = 0;
    wstart = sCryptoBnNumBitsWordBits - 1;
    wend = 0;

    if (!CRYPTOi__BN_set_word(r, 1))
        goto err;

    for (;;)
    {
        if (CRYPTOi__BN_is_bit_set(p, wstart) == 0)
        {
            if (!start)
                if (!CRYPTOi__BN_mod_mul_reciprocal(r, r, r, &recp, ctx))
                    goto err;
            if (wstart == 0)
                break;
            wstart--;
            continue;
        }
        j = wstart;
        wvalue = 1;
        wend = 0;
        for (i = 1; i < window; i++)
        {
            if (wstart - i < 0)
                break;
            if (CRYPTOi__BN_is_bit_set(p, wstart - i))
            {
                wvalue <<= (i - wend);
                wvalue |= 1;
                wend = i;
            }
        }

        j = wend + 1;
        if (!start)
            for (i = 0; i < j; i++)
            {
                if (!CRYPTOi__BN_mod_mul_reciprocal(r, r, r, &recp, ctx))
                    goto err;
            }

        if (!CRYPTOi__BN_mod_mul_reciprocal(r, r, &(val[wvalue >> 1]), &recp, ctx))
            goto err;

        wstart -= wend + 1;
        wvalue = 0;
        start = 0;
        if (wstart < 0)
            break;
    }
    ret = 1;
err:
    ctx->tos--;
    for (i = 0; i < ts; i++)
        CRYPTOi__BN_clear_free(&val[i]);
    CRYPTOi__BN_RECP_CTX_free((&recp));
    return ret;
}



#undef BN_is_zero


#undef BN_is_zero

#undef BN_is_zero
#define BN_is_zero(x) (((x)->top == 0) || ((x)->top == 1 && (x)->d[0] == 0))



#undef BN_is_one


#undef BN_is_one

#undef BN_is_one
#define BN_is_one(x) (((x)->top == 1) && ((x)->d[0] == 1))




int CRYPTOi__BN_mod_exp_mont(BIGNUM *rr_in, BIGNUM *a_in, BIGNUM *p,
                             BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *in_mont)
{
    int i, j, ret = 0, tos, top;
    int mul, sqr, num;
    BIGNUM *d, *aa, *r, *a, *t;
    BN_ULONG *vall[16], *dp, *rp, n0, *tmp, *np;
    BN_MONT_CTX *mont;
    unsigned char *str = NULL;
    R_SURRENDER *surrender = NULL;
    int count = 0;

    if ((m->d[0] & 1) == 0)
        return 0;
    tos = ctx->tos;
    if (BN_is_zero(a_in)) {
        CRYPTOi__BN_set_word(rr_in, 0);
        return 1;
    }
    if (BN_is_zero(p)) {
        CRYPTOi__BN_set_word(rr_in, 1);
        return 1;
    }
    if (BN_is_one(p)) {
        CRYPTOi__BN_copy(rr_in, a_in);
        return 1;
    }

    mont = in_mont;
    if (mont == NULL) {
        mont = CRYPTOi__BN_MONT_CTX_new();
        if (mont == NULL)
            goto err;
        if (CRYPTOi__BN_MONT_CTX_set_word(mont, m, ctx) == 0)
            goto err;
    }
    surrender = ctx->surrender;
    if (CRYPTOi__BN_gen_exp_bits(p, &str, 0, ctx) == 0)
        goto err;
    ctx->tos++;
    num = str[3];
    j = (str[2] + 0x3f) / str[2];
    str += 4;

    top = mont->N.top;
    if (a_in->top == top && a_in->d[top - 1] < m->d[top - 1]) {
        a = a_in;
    } else if (a_in->top < top) {
        a = &ctx->bn[ctx->tos++];
        a->top = a_in->top;
        if (CRYPTOi__bn_zexpand(a, top) == 0)
            goto err;
        for (i = 0; i < a_in->top; i++)
            a->d[i] = a_in->d[i];
    } else {
        a = &ctx->bn[ctx->tos++];
        if (CRYPTOi__BN_mod(a, a_in, m, ctx) == 0)
            goto err;
        if (CRYPTOi__bn_zexpand(a, top) == 0)
            goto err;
    }

    i = num * top + (p->top * j * 2 + 7) / 4;
    aa = &ctx->bn[ctx->tos++];
    d = &ctx->bn[ctx->tos++];
    r = &ctx->bn[ctx->tos++];
    t = &ctx->bn[ctx->tos++];
    if (bn_wexpand(rr_in, top) == NULL)
        goto err;
    if (bn_wexpand(d, top * 4) == NULL)
        goto err;
    if (bn_wexpand(r, top * 2) == NULL)
        goto err;
    if (bn_wexpand(aa, i) == NULL)
        goto err;
    if (bn_wexpand(t, top * 2) == NULL)
        goto err;

    dp = d->d;
    rp = r->d;
    tmp = t->d;
    n0 = mont->n0;
    np = mont->N.d;
    vall[0] = aa->d;
    CRYPTOi__bn_mul_normal(tmp, a->d, top, mont->RR.d, top);
    CRYPTOi__bn_from_montgomery_words(vall[0], tmp, np, top, n0);
    if (num > 1) {
        CRYPTOi__bn_sqr_normal(tmp, vall[0], top, dp);
        CRYPTOi__bn_from_montgomery_words(dp, tmp, np, top, n0);
        for (i = 1; i < num; i++) {
            vall[i] = vall[i - 1] + top;
            CRYPTOi__bn_mul_normal(tmp, vall[i - 1], top, dp, top);
            CRYPTOi__bn_from_montgomery_words(vall[i], tmp, np, top, n0);
        }
    }

    GET_RUN(mul, sqr, str);
    MI_CpuCopy8(vall[mul >> 1], rp, top * sizeof(BN_ULONG));
    while (sqr != 0) {
        if (surrender != NULL) {
            j = surrender->callback(surrender, 0xff, count);
            count++;
            if (j != 0)
                goto err;
        }
        if (ctx->flags & 0x4000)
            goto err;
        for (j = 0; j < sqr; j++) {
            CRYPTOi__bn_sqr_normal(tmp, rp, top, dp);
            CRYPTOi__bn_from_montgomery_words(rp, tmp, np, top, n0);
        }
        GET_RUN(mul, sqr, str);
        if (mul == 0 && sqr == 0)
            break;
        if (sqr != 0 || mul != 1) {
            CRYPTOi__bn_mul_normal(tmp, rp, top, vall[mul >> 1], top);
            CRYPTOi__bn_from_montgomery_words(rp, tmp, np, top, n0);
        } else {
            CRYPTOi__bn_mul_normal(tmp, rp, top, a->d, top);
            CRYPTOi__bn_from_montgomery_words(rr_in->d, tmp, np, top, n0);
            goto done;
        }
    }
    for (i = top; i < top * 2; i++)
        rp[i] = 0;
    CRYPTOi__bn_from_montgomery_words(rr_in->d, rp, np, top, n0);
done:
    if (ctx->flags & 0x4000)
        goto err;
    rr_in->top = top;
    CRYPTOi__bn_fix_top(rr_in);
    ret = 1;
err:
    if (surrender != NULL) {
        if (surrender->callback(surrender, 0xff, -1) != 0)
            ret = 0;
    }
    if (in_mont == NULL && mont != NULL)
        CRYPTOi__BN_MONT_CTX_free(mont);
    ctx->tos = tos;
    return ret;
}
