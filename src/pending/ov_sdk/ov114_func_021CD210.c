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
 * rewritten from the vendor listing (2026-10-01): 1904 of 1908 B, 30/30 relocations,
 *   44 aligned blocks.  BN_gen_exp_bits takes ctx as a 4th argument; the window stream is
 *   decoded by GET_RUN (pairs, 0x00/0xff runs add 0x100); four BN_CTX_get-style bns
 *   (table storage, scratch t, accumulator r, product d) at tos..tos+3; table[i] carved at
 *   stride n; the c==1 && cnt==0 step multiplies by aa straight into rr; the copy size is
 *   n * sizeof(BN_ULONG) so n*4 is not CSE'd; locals declared so the stack slots match.
 *   Left: the image pools the 0 for bits/cb/counter/ret into r4 and returns it on the
 *   even-modulus path (ours stores then reloads), and register colour drift in the
 *   GET_RUN decode.
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
 * blocker:  codegen -- no DWARF subprogram.  The C body below is still the
 *           W7 draft (1764/1908, 37/37 relocs); it is wrong from
 *           CRYPTOi__BN_gen_exp_bits onward and must be rewritten to the
 *           decoded structure in the header comment above.  Known required
 *           changes: (a) drop bits=(p[2]<<8)|p[3] and the bit-indexed
 *           BN_is_bit_set-style loop entirely -- gen_exp_bits emits a byte
 *           stream walked by a moving cursor, with (0x00,0xff) padding runs
 *           and 0xNN+1 squaring counts; (b) count=p[3] is the table size
 *           2^(window-1) and the table is count BIGNUMs carved at stride n
 *           from one storage bn, table[i]=mont_mul(table[i-1],table[0]);
 *           (c) the callback at ctx+0x10c is an object invoked through its
 *           vtable[0] as (0xff, counter) with counter at [sp+0xc], not a
 *           bare function pointer; (d) add the a-already-reduced alias
 *           (a->top==n && a->d[n-1]<m->d[n-1] -> aa=(BIGNUM*)a) and the
 *           four per-loop scratch bn allocations.  No witness problem.
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

#define BN_is_zero(x) (((x)->top == 0) || ((x)->top == 1 && (x)->d[0] == 0))
#define BN_is_one(x) (((x)->top == 1) && ((x)->d[0] == 1))
#define bn_wexpand(a, words) (((words) <= (a)->dmax) ? (a) : CRYPTOi__bn_expand2((a), (words)))

typedef struct BN_CB {
    int (*func)(struct BN_CB *cb, int a, int b);
} BN_CB;

#define GET_RUN(c, cnt, bits) \
    c = *bits++; \
    cnt = *bits++; \
    if (cnt == 0xff && c == 0) { \
        while ((c = *bits++, *bits == 0xff) && c == 0) { \
            cnt += 0x100; \
            bits++; \
        } \
        cnt += *bits++ + 1; \
    }

int CRYPTOi__BN_mod_exp_mont(BIGNUM *rr, const BIGNUM *a, const BIGNUM *p,
                             const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *in_mont)
{
    BN_ULONG *table[16];
    unsigned char *bits = 0;
    int ret = 0;
    int savedtos;
    int count;
    BIGNUM *aa;
    BN_MONT_CTX *mont;
    BN_CB *cb = 0;
    int counter = 0;
    int n, sz, i, j, c, cnt, tos;
    BIGNUM *tbn, *rbn, *vbn, *dbn;
    BN_ULONG *t, *r, *d, *N, n0;

    if ((m->d[0] & 1) == 0)
        return 0;
    savedtos = ctx->tos;
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

    mont = in_mont;
    if (mont == 0) {
        mont = CRYPTOi__BN_MONT_CTX_new();
        if (mont == 0)
            goto err;
        if (CRYPTOi__BN_MONT_CTX_set_word(mont, m, ctx) == 0)
            goto err;
    }
    cb = (BN_CB *)ctx->depth;
    if (CRYPTOi__BN_gen_exp_bits(p, &bits, 0, ctx) == 0)
        goto err;
    ctx->tos++;
    count = bits[3];
    sz = (bits[2] + 0x3f) / bits[2];
    bits += 4;

    n = mont->N.top;
    if (a->top == n && a->d[n - 1] < m->d[n - 1]) {
        aa = (BIGNUM *)a;
    } else if (a->top < n) {
        aa = &ctx->bn[ctx->tos++];
        aa->top = a->top;
        if (CRYPTOi__bn_zexpand(aa, n) == 0)
            goto err;
        for (i = 0; i < a->top; i++)
            aa->d[i] = a->d[i];
    } else {
        aa = &ctx->bn[ctx->tos++];
        if (CRYPTOi__BN_mod(aa, a, m, ctx) == 0)
            goto err;
        if (CRYPTOi__bn_zexpand(aa, n) == 0)
            goto err;
    }

    i = count * n + (p->top * sz * 2 + 7) / 4;
    vbn = &ctx->bn[ctx->tos++];
    tbn = &ctx->bn[ctx->tos++];
    rbn = &ctx->bn[ctx->tos++];
    dbn = &ctx->bn[ctx->tos++];
    if (bn_wexpand(rr, n) == 0)
        goto err;
    if (bn_wexpand(tbn, n * 4) == 0)
        goto err;
    if (bn_wexpand(rbn, n * 2) == 0)
        goto err;
    if (bn_wexpand(vbn, i) == 0)
        goto err;
    if (bn_wexpand(dbn, n * 2) == 0)
        goto err;

    table[0] = vbn->d;
    t = tbn->d;
    r = rbn->d;
    d = dbn->d;
    n0 = mont->n0;
    N = mont->N.d;
    CRYPTOi__bn_mul_normal(d, aa->d, n, mont->RR.d, n);
    CRYPTOi__bn_from_montgomery_words(table[0], d, N, n, n0);
    if (count > 1) {
        CRYPTOi__bn_sqr_normal(d, table[0], n, t);
        CRYPTOi__bn_from_montgomery_words(t, d, N, n, n0);
        for (i = 1; i < count; i++) {
            table[i] = table[i - 1] + n;
            CRYPTOi__bn_mul_normal(d, table[i - 1], n, t, n);
            CRYPTOi__bn_from_montgomery_words(table[i], d, N, n, n0);
        }
    }

    GET_RUN(c, cnt, bits);
    MI_CpuCopy8(table[c >> 1], r, n * sizeof(BN_ULONG));
    while (cnt != 0) {
        if (cb != 0) {
            j = cb->func(cb, 0xff, counter);
            counter++;
            if (j != 0)
                goto err;
        }
        if (ctx->flags & 0x4000)
            goto err;
        for (j = 0; j < cnt; j++) {
            CRYPTOi__bn_sqr_normal(d, r, n, t);
            CRYPTOi__bn_from_montgomery_words(r, d, N, n, n0);
        }
        GET_RUN(c, cnt, bits);
        if (c == 0 && cnt == 0)
            break;
        if (cnt != 0 || c != 1) {
            CRYPTOi__bn_mul_normal(d, r, n, table[c >> 1], n);
            CRYPTOi__bn_from_montgomery_words(r, d, N, n, n0);
        } else {
            CRYPTOi__bn_mul_normal(d, r, n, aa->d, n);
            CRYPTOi__bn_from_montgomery_words(rr->d, d, N, n, n0);
            goto done;
        }
    }
    for (i = n; i < n * 2; i++)
        r[i] = 0;
    CRYPTOi__bn_from_montgomery_words(rr->d, r, N, n, n0);
done:
    if (ctx->flags & 0x4000)
        goto err;
    rr->top = n;
    CRYPTOi__bn_fix_top(rr);
    ret = 1;
err:
    if (cb != 0) {
        if (cb->func(cb, 0xff, -1) != 0)
            ret = 0;
    }
    if (in_mont == 0 && mont != 0)
        CRYPTOi__BN_MONT_CTX_free(mont);
    ctx->tos = savedtos;
    return ret;
}
