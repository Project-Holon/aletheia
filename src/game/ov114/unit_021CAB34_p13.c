/*
 * file:     unit_021CAB34_p13.c
 * unit:     yes
 * function: func_021CCE7C, func_021CD210
 * address:  0x021CCE7C
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
 *   func_021CAB94  0x021CAB94  arm  ov114
 *   func_021CAEC8  0x021CAEC8  arm  ov114
 *   func_021CAE20  0x021CAE20  arm  ov114
 *   func_021CCA5C  0x021CCA5C  arm  ov114
 *   func_021CCAAC  0x021CCAAC  arm  ov114
 *   func_021CACD0  0x021CACD0  arm  ov114
 *   func_021CC0FC  0x021CC0FC  arm  ov114
 *   func_021CCAE4  0x021CCAE4  arm  ov114
 *   func_021CB15C  0x021CB15C  arm  ov114
 *   func_021CABC0  0x021CABC0  arm  ov114
 *   func_021CCA80  0x021CCA80  arm  ov114
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
#define NULL ((void *)0)
#define bn_wexpand(a, words) (((words) <= (a)->max) ? (a) : CRYPTOi__bn_expand2((a), (words)))
#define GET_RUN(c, cnt, bits)     c = *bits++;     cnt = *bits++;     if (cnt == 0xff && c == 0) {         for (c = *bits++; *bits == 0xff && c == 0; c = *bits++) {             cnt += 0x100;             bits++;         }         cnt += *bits++ + 1;     }
typedef unsigned int BN_ULONG_021CCE7C;

typedef struct
{
    BN_ULONG_021CCE7C *d;
    int top;
    int dmax;
    int neg;
    int flags;
} BIGNUM_021CCE7C;

typedef struct
{
    int tos;
    BIGNUM_021CCE7C bn[13];
    int flags;
    int depth;
} BN_CTX_021CCE7C;

typedef struct
{
    BIGNUM_021CCE7C N;
    BIGNUM_021CCE7C Nr;
    int num_bits;
    int shift;
    int flags;
} BN_RECP_CTX;

typedef unsigned char  u8;

typedef unsigned long BN_ULONG_021CD210;

typedef struct bignum_st {
    BN_ULONG_021CD210 *d;
    int top;
    int max;
    int neg;
    int flags;
} BIGNUM_021CD210;

typedef struct r_surrender_st {
    int (*callback)(struct r_surrender_st *, int, int);
    char *arg;
} R_SURRENDER;

typedef struct bignum_ctx {
    int tos;
    BIGNUM_021CD210 bn[13];
    int flags;
    R_SURRENDER *surrender;
} BN_CTX_021CD210;

typedef struct bn_mont_ctx_st {
    int use_word;
    int ri;
    int riw;
    BIGNUM_021CD210 RR;
    BIGNUM_021CD210 N;
    BIGNUM_021CD210 Ni;
    BN_ULONG_021CD210 n0;
    int flags;
} BN_MONT_CTX;

extern char *func_021CAB94(u8 *p);
extern int func_021CAEC8(u8 *a, unsigned long w);
extern u8 *func_021CAE20(u8 *a, u8 *b);
extern void func_021CCA5C(u8 *p);
extern int func_021CCAAC(BN_RECP_CTX *, const BIGNUM_021CCE7C *, BN_CTX_021CCE7C *);
extern void func_021CACD0(int a);
extern int func_021CC0FC(BIGNUM_021CCE7C *, const BIGNUM_021CCE7C *, const BIGNUM_021CCE7C *, BN_CTX_021CCE7C *);
extern int func_021CCAE4(BIGNUM_021CCE7C *, BIGNUM_021CCE7C *, BIGNUM_021CCE7C *, BN_RECP_CTX *, BN_CTX_021CCE7C *);
extern int func_021CB15C(const BIGNUM_021CCE7C *, int);
extern void func_021CABC0(int a);
extern void func_021CCA80(u8 *p);
extern int CRYPTOi__BN_set_word(BIGNUM_021CD210 *, BN_ULONG_021CD210);
extern BIGNUM_021CD210 *CRYPTOi__BN_copy(BIGNUM_021CD210 *, const BIGNUM_021CD210 *);
extern BN_MONT_CTX *CRYPTOi__BN_MONT_CTX_new(void);
extern int CRYPTOi__BN_MONT_CTX_set_word(BN_MONT_CTX *, const BIGNUM_021CD210 *, BN_CTX_021CD210 *);
extern int CRYPTOi__BN_gen_exp_bits(const BIGNUM_021CD210 *, unsigned char **, int, BN_CTX_021CD210 *);
extern int _s32_div_f(int, int);
extern int CRYPTOi__bn_zexpand(BIGNUM_021CD210 *, int);
extern int CRYPTOi__BN_mod(BIGNUM_021CD210 *, const BIGNUM_021CD210 *, const BIGNUM_021CD210 *, BN_CTX_021CD210 *);
extern BIGNUM_021CD210 *CRYPTOi__bn_expand2(BIGNUM_021CD210 *, int);
extern int CRYPTOi__bn_mul_normal(BN_ULONG_021CD210 *, BN_ULONG_021CD210 *, int, BN_ULONG_021CD210 *, int);
extern void CRYPTOi__bn_from_montgomery_words(BN_ULONG_021CD210 *, BN_ULONG_021CD210 *, BN_ULONG_021CD210 *, int, BN_ULONG_021CD210);
extern void CRYPTOi__bn_sqr_normal(BN_ULONG_021CD210 *, BN_ULONG_021CD210 *, int, BN_ULONG_021CD210 *);
extern void MI_CpuCopy8(void *, void *, unsigned long);
extern int CRYPTOi__bn_fix_top(BIGNUM_021CD210 *);
extern void CRYPTOi__BN_MONT_CTX_free(BN_MONT_CTX *);
int func_021CCE7C(BIGNUM_021CCE7C *r, const BIGNUM_021CCE7C *a, const BIGNUM_021CCE7C *p, const BIGNUM_021CCE7C *m, BN_CTX_021CCE7C *ctx);
int CRYPTOi__BN_mod_exp_mont(BIGNUM_021CD210 *rr_in, BIGNUM_021CD210 *a_in, BIGNUM_021CD210 *p, BIGNUM_021CD210 *m, BN_CTX_021CD210 *ctx, BN_MONT_CTX *in_mont);


#define BN_is_zero(a) (((a)->top == 0) || (((a)->top == 1) && ((a)->d[0] == 0)))

#define BN_is_one(a) (((a)->top == 1) && ((a)->d[0] == 1))


/*
 * sdk:      CRYPTOi__BN_mod_exp_recp (crypto_bobj1.o)
 */
int func_021CCE7C(BIGNUM_021CCE7C *r, const BIGNUM_021CCE7C *a, const BIGNUM_021CCE7C *p, const BIGNUM_021CCE7C *m, BN_CTX_021CCE7C *ctx)
{
    int i, j, bits, ret = 0, wstart, wend, window, wvalue;
    int start = 1, ts = 0;
    BIGNUM_021CCE7C *aa;
    BIGNUM_021CCE7C val[16];
    BN_RECP_CTX recp;

    bits = (int)func_021CAB94((u8 *)p);

    if (BN_is_zero(a))
    {
        func_021CAEC8((u8 *)r, 0);
        return 1;
    }
    if (BN_is_zero(p))
    {
        func_021CAEC8((u8 *)r, 1);
        return 1;
    }
    if (BN_is_one(p))
    {
        func_021CAE20((u8 *)r, (u8 *)a);
        return 1;
    }

    func_021CCA5C((u8 *)(&recp));
    if (func_021CCAAC(&recp, m, ctx) <= 0)
        goto err;

    func_021CACD0((int)(&(val[0])));
    ts = 1;
    aa = &(ctx->bn[ctx->tos++]);

    if (!func_021CC0FC(&(val[0]), a, m, ctx))
        goto err;
    if (!func_021CCAE4(aa, &(val[0]), &(val[0]), &recp, ctx))
        goto err;

    if (bits <= 17)
        window = 1;
    else if (bits >= 256)
        window = 5;
    else if (bits >= 128)
        window = 4;
    else
        window = 3;

    j = 1 << (window - 1);
    for (i = 1; i < j; i++)
    {
        func_021CACD0((int)(&(val[i])));
        if (!func_021CCAE4(&(val[i]), &(val[i - 1]), aa, &recp, ctx))
            goto err;
    }
    ts = i;

    start = 1;
    wvalue = 0;
    wstart = bits - 1;
    wend = 0;

    if (!func_021CAEC8((u8 *)r, 1))
        goto err;

    for (;;)
    {
        if (func_021CB15C(p, wstart) == 0)
        {
            if (!start)
                if (!func_021CCAE4(r, r, r, &recp, ctx))
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
            if (func_021CB15C(p, wstart - i))
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
                if (!func_021CCAE4(r, r, r, &recp, ctx))
                    goto err;
            }

        if (!func_021CCAE4(r, r, &(val[wvalue >> 1]), &recp, ctx))
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
        func_021CABC0((int)(&(val[i])));
    func_021CCA80((u8 *)(&recp));
    return ret;
}

#undef BN_is_zero
#define BN_is_zero(x) (((x)->top == 0) || ((x)->top == 1 && (x)->d[0] == 0))

#undef BN_is_one
#define BN_is_one(x) (((x)->top == 1) && ((x)->d[0] == 1))


int CRYPTOi__BN_mod_exp_mont(BIGNUM_021CD210 *rr_in, BIGNUM_021CD210 *a_in, BIGNUM_021CD210 *p,
                             BIGNUM_021CD210 *m, BN_CTX_021CD210 *ctx, BN_MONT_CTX *in_mont)
{
    int i, j, ret = 0, tos, top;
    int mul, sqr, num;
    BIGNUM_021CD210 *d, *aa, *r, *a, *t;
    BN_ULONG_021CD210 *vall[16], *dp, *rp, n0, *tmp, *np;
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
    MI_CpuCopy8(vall[mul >> 1], rp, top * sizeof(BN_ULONG_021CD210));
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
