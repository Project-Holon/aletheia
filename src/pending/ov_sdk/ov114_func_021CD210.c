/*
 * function: CRYPTOi__BN_mod_exp_mont
 * address:  0x021CD210
 * packet:   pkt_ov114_021CD210
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * lane W7 (2026-09-30): re-measured 1764/1908, 37/37 relocations, 1505
 * concrete bytes -- the draft's structure diverges from the top, so the
 * residue is not a near miss.  Disassembly walk (0x021CD210..0x021CD984)
 * confirms the shape: BN_MONT_CTX_new/BN_MONT_CTX_set_word at [sp+0x14];
 * callback = ctx->depth (ctx+0x10c) into [sp+0x10]; CRYPTOi__BN_gen_exp_bits
 * returns the windowed-exponent header (p[0..1] len, p[2] window, p[3] count;
 * see the EXACT sibling ov114_func_021CC530.c) and ctx->tos is bumped for it;
 * then aa is a fresh ctx->bn BIGNUM, and val[] is built with
 * CRYPTOi__bn_mul_normal / bn_from_montgomery_words.  The draft's
 * `bits=(bitsbuf[2]<<8)|bitsbuf[3]` and
 * `window=(bitsbuf[2]+0x3f)/bitsbuf[2]` misread that header, and the windowed
 * loop's table size, sqr chain and callback accounting need rewriting from
 * the listing.  This is real decomp work still outstanding, not a witness
 * problem.
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
 * blocker:  codegen -- no DWARF subprogram. Full windowed Montgomery
 *           exponentiation reconstructed from the listing and the EXACT
 *           reciprocal sibling CRYPTOi__BN_mod_exp_recp (0x021CCE7C). The
 *           object computes the exponent bit windows through
 *           CRYPTOi__BN_gen_exp_bits (not BN_is_bit_set) and does its
 *           Montgomery reduction with CRYPTOi__bn_mul_normal /
 *           CRYPTOi__bn_sqr_normal + CRYPTOi__bn_from_montgomery_words,
 *           with a progress callback off BN_CTX+0x10c. Not yet iterated
 *           against --diff; the helper prototypes in this file are inferred
 *           from the call sites and may need tightening.
 */

typedef unsigned int BN_ULONG;

typedef struct {
    BN_ULONG *d;
    int top;
    int dmax;
    int neg;
    int flags;
} BIGNUM;

typedef struct {
    int tos;
    BIGNUM bn[13];
    int flags;
    int depth;                  /* 0x10c: progress callback object */
} BN_CTX;

typedef struct {
    int field00;
    int field04;
    int ri;                     /* 0x08 */
    BIGNUM RR;                  /* 0x0c */
    BIGNUM N;                   /* 0x20 */
    BIGNUM Ni;                  /* 0x34 */
    BN_ULONG n0;                /* 0x48 */
    int flags;                  /* 0x4c */
} BN_MONT_CTX;

extern int CRYPTOi__BN_set_word(BIGNUM *, BN_ULONG);
extern BIGNUM *CRYPTOi__BN_copy(BIGNUM *, const BIGNUM *);
extern BN_MONT_CTX *CRYPTOi__BN_MONT_CTX_new(void);
extern int CRYPTOi__BN_MONT_CTX_set_word(BN_MONT_CTX *, const BIGNUM *, BN_CTX *);
extern int CRYPTOi__BN_gen_exp_bits(const BIGNUM *, unsigned char **, int);
extern int _s32_div_f(int, int);
extern int CRYPTOi__bn_zexpand(BIGNUM *, int);
extern int CRYPTOi__BN_mod(BIGNUM *, const BIGNUM *, const BIGNUM *, BN_CTX *);
extern int CRYPTOi__bn_expand2(BIGNUM *, int);
extern int CRYPTOi__bn_mul_normal(BN_ULONG *, BN_ULONG *, int, BN_ULONG *, int);
extern void CRYPTOi__bn_from_montgomery_words(BN_ULONG *, BN_ULONG *, BN_ULONG *, int, BN_ULONG);
extern void CRYPTOi__bn_sqr_normal(BN_ULONG *, BN_ULONG *, int, BN_ULONG *);
extern void MI_CpuCopy8(void *, void *, unsigned long);
extern int CRYPTOi__bn_fix_top(BIGNUM *);
extern void CRYPTOi__BN_MONT_CTX_free(BN_MONT_CTX *);

#define BN_is_zero(x) (((x)->top == 0) || ((x)->top == 1 && (x)->d[0] == 0))
#define BN_is_one(x) (((x)->top == 1) && ((x)->d[0] == 1))

int CRYPTOi__BN_mod_exp_mont(BIGNUM *rr, const BIGNUM *a, const BIGNUM *p,
                             const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *in_mont)
{
    int i, j, bits, ret = 0, wstart, wend, window, wvalue;
    int start = 1, ts = 0;
    int n;
    int savedtos;
    BIGNUM *d, *r, *aa;
    BIGNUM *val[16];
    BN_MONT_CTX *mont = 0;
    unsigned char *bitsbuf = 0;
    BN_ULONG valword;
    int (*callback)(int, int);

    if ((m->d[0] & 1) == 0)
        return 0;

    if (BN_is_zero(a)) {
        CRYPTOi__BN_set_word(rr, 0);
        return 1;
    }
    if (BN_is_zero(p)) {
        CRYPTOi__BN_set_word(rr, 1);
        return 1;
    }
    if (BN_is_one(p)) {
        CRYPTOi__BN_copy(rr, a);
        return 1;
    }

    if (in_mont != 0) {
        mont = in_mont;
    } else {
        mont = CRYPTOi__BN_MONT_CTX_new();
        if (mont == 0)
            goto err;
        if (CRYPTOi__BN_MONT_CTX_set_word(mont, m, ctx) == 0)
            goto err;
    }

    savedtos = ctx->tos;
    callback = (int (*)(int, int))ctx->depth;

    if (CRYPTOi__BN_gen_exp_bits(p, &bitsbuf, 0) == 0)
        goto err;
    bits = ((int)bitsbuf[2] << 8) | bitsbuf[3];
    if (bits == 0) {
        CRYPTOi__BN_set_word(rr, 1);
        ret = 1;
        goto err;
    }

    window = (bitsbuf[2] + 0x3f) / bitsbuf[2];
    if (window < 1)
        window = 1;
    j = 1 << (window - 1);

    n = mont->N.top;
    d = &ctx->bn[ctx->tos++];
    CRYPTOi__BN_set_word(d, 0);
    r = &ctx->bn[ctx->tos++];
    CRYPTOi__BN_set_word(r, 0);

    for (i = 0; i < j; i++) {
        val[i] = &ctx->bn[ctx->tos++];
        val[i]->d = 0;
        val[i]->top = 0;
        val[i]->dmax = 0;
        val[i]->neg = 0;
        val[i]->flags = 0;
    }
    ts = j;
    aa = &ctx->bn[ctx->tos++];

    if (CRYPTOi__bn_expand2(val[0], n) == 0)
        goto err;
    if (CRYPTOi__bn_expand2(aa, n) == 0)
        goto err;

    if (a->top != n) {
        if (a->top > n) {
            if (CRYPTOi__BN_mod(aa, a, &mont->N, ctx) == 0)
                goto err;
        } else {
            CRYPTOi__bn_zexpand(aa, n);
            for (i = 0; i < a->top; i++)
                aa->d[i] = a->d[i];
        }
    } else {
        for (i = 0; i < n; i++)
            aa->d[i] = a->d[i];
    }
    aa->top = n;

    /* val[0] = a * R mod N (Montgomery form) via bn_mul by RR then reduce */
    CRYPTOi__bn_mul_normal(val[0]->d, aa->d, n, mont->RR.d, n);
    CRYPTOi__bn_from_montgomery_words(val[0]->d, val[0]->d, mont->N.d, n, mont->n0);
    val[0]->top = 2 * n;
    CRYPTOi__bn_fix_top(val[0]);

    for (i = 1; i < j; i++) {
        CRYPTOi__bn_mul_normal(val[i]->d, val[i - 1]->d, n, val[0]->d, n);
        CRYPTOi__bn_from_montgomery_words(val[i]->d, val[i]->d, mont->N.d, n, mont->n0);
        val[i]->top = 2 * n;
        CRYPTOi__bn_fix_top(val[i]);
    }

    start = 1;
    wvalue = 0;
    wstart = bits - 1;
    wend = 0;

    if (CRYPTOi__BN_set_word(r, 1) == 0)
        goto err;
    /* r in Montgomery form */
    CRYPTOi__bn_mul_normal(r->d, r->d, n, mont->RR.d, n);
    CRYPTOi__bn_from_montgomery_words(r->d, r->d, mont->N.d, n, mont->n0);
    r->top = 2 * n;
    CRYPTOi__bn_fix_top(r);

    for (;;) {
        valword = (bitsbuf[bitsbuf[0] - 1 - (wstart >> 3)] >> (wstart & 7)) & 1;
        if (valword == 0) {
            if (!start) {
                CRYPTOi__bn_sqr_normal(d->d, r->d, n, val[0]->d);
                CRYPTOi__bn_from_montgomery_words(r->d, d->d, mont->N.d, n, mont->n0);
                r->top = 2 * n;
                CRYPTOi__bn_fix_top(r);
            }
            if (wstart == 0)
                break;
            wstart--;
            continue;
        }
        j = wstart;
        wvalue = 1;
        wend = 0;
        for (i = 1; i < window; i++) {
            if (wstart - i < 0)
                break;
            if (((bitsbuf[bitsbuf[0] - 1 - ((wstart - i) >> 3)] >> ((wstart - i) & 7)) & 1) != 0) {
                wvalue <<= (i - wend);
                wvalue |= 1;
                wend = i;
            }
        }

        j = wend + 1;
        if (!start) {
            for (i = 0; i < j; i++) {
                CRYPTOi__bn_sqr_normal(d->d, r->d, n, val[0]->d);
                CRYPTOi__bn_from_montgomery_words(r->d, d->d, mont->N.d, n, mont->n0);
                r->top = 2 * n;
                CRYPTOi__bn_fix_top(r);
            }
        }

        if (callback != 0) {
            callback(0xff, 0);
        }

        CRYPTOi__bn_mul_normal(d->d, r->d, n, val[wvalue >> 1]->d, n);
        CRYPTOi__bn_from_montgomery_words(r->d, d->d, mont->N.d, n, mont->n0);
        r->top = 2 * n;
        CRYPTOi__bn_fix_top(r);

        wstart -= wend + 1;
        wvalue = 0;
        start = 0;
        if (wstart < 0)
            break;
    }

    /* convert r back out of Montgomery form */
    CRYPTOi__bn_from_montgomery_words(rr->d, r->d, mont->N.d, n, mont->n0);
    rr->top = 2 * n;
    CRYPTOi__bn_fix_top(rr);
    CRYPTOi__BN_copy(rr, rr);
    ret = 1;

err:
    if (callback != 0) {
        if (callback(0xff, -1) != 0)
            ret = 0;
    }
    ctx->tos = savedtos;
    if (in_mont == 0 && mont != 0)
        CRYPTOi__BN_MONT_CTX_free(mont);
    return ret;
}
