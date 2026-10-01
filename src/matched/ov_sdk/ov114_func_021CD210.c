/*
 * function: CRYPTOi__BN_mod_exp_mont
 * address:  0x021CD210
 * packet:   pkt_ov114_021CD210
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 2026-10-01 (wave 4): EXACT.  The object has a DWARF subprogram under the unprefixed name
 *   BN_mod_exp_mont (sdkobj looks up the CRYPTOi__ name and misses it); its locals and line
 *   table gave the real declarations: `int i, j, ret = 0, tos, top;` (int ret is
 *   the first zero holder),
 *   R_SURRENDER *surrender, int count, BN_ULONG = unsigned long, and the bn order
 *   aa/d/r/t (d expanded to top*4).  Earlier history (u8 ret etc.) superseded.
 *
 * sdk:      CRYPTOi__BN_mod_exp_mont (libcrypto.TWL.HYB.a crypto_bobj1.o)
 *
 * symbols:
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
 *
 */

typedef unsigned long BN_ULONG;

typedef struct bignum_st {
    BN_ULONG *d;
    int top;
    int max;
    int neg;
    int flags;
} BIGNUM;

typedef struct r_surrender_st {
    int (*callback)(struct r_surrender_st *, int, int);
    char *arg;
} R_SURRENDER;

typedef struct bignum_ctx {
    int tos;
    BIGNUM bn[13];
    int flags;
    R_SURRENDER *surrender;
} BN_CTX;

typedef struct bn_mont_ctx_st {
    int use_word;
    int ri;
    int riw;
    BIGNUM RR;
    BIGNUM N;
    BIGNUM Ni;
    BN_ULONG n0;
    int flags;
} BN_MONT_CTX;

extern int CRYPTOi__BN_set_word(BIGNUM *, BN_ULONG);
extern BIGNUM *CRYPTOi__BN_copy(BIGNUM *, const BIGNUM *);
extern BN_MONT_CTX *CRYPTOi__BN_MONT_CTX_new(void);
extern int CRYPTOi__BN_MONT_CTX_set_word(BN_MONT_CTX *, const BIGNUM *, BN_CTX *);
extern int CRYPTOi__BN_gen_exp_bits(const BIGNUM *, unsigned char **, int, BN_CTX *);
extern int _s32_div_f(int, int);
extern int CRYPTOi__bn_zexpand(BIGNUM *, int);
extern int CRYPTOi__BN_mod(BIGNUM *, const BIGNUM *, const BIGNUM *, BN_CTX *);
extern BIGNUM *CRYPTOi__bn_expand2(BIGNUM *, int);
extern int CRYPTOi__bn_mul_normal(BN_ULONG *, BN_ULONG *, int, BN_ULONG *, int);
extern void CRYPTOi__bn_from_montgomery_words(BN_ULONG *, BN_ULONG *, BN_ULONG *, int, BN_ULONG);
extern void CRYPTOi__bn_sqr_normal(BN_ULONG *, BN_ULONG *, int, BN_ULONG *);
extern void MI_CpuCopy8(void *, void *, unsigned long);
extern int CRYPTOi__bn_fix_top(BIGNUM *);
extern void CRYPTOi__BN_MONT_CTX_free(BN_MONT_CTX *);

#define NULL ((void *)0)
#define BN_is_zero(x) (((x)->top == 0) || ((x)->top == 1 && (x)->d[0] == 0))
#define BN_is_one(x) (((x)->top == 1) && ((x)->d[0] == 1))
#define bn_wexpand(a, words) (((words) <= (a)->max) ? (a) : CRYPTOi__bn_expand2((a), (words)))

#define GET_RUN(c, cnt, bits)     c = *bits++;     cnt = *bits++;     if (cnt == 0xff && c == 0) {         for (c = *bits++; *bits == 0xff && c == 0; c = *bits++) {             cnt += 0x100;             bits++;         }         cnt += *bits++ + 1;     }

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
