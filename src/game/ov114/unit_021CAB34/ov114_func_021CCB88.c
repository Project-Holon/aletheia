/*
 * function: func_021CCB88
 * address:  0x021CCB88
 * packet:   pkt_ov114_021CCB88
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_div_recp (crypto_bobj1.o)
 *
 * symbols:
 *   func_021CB078  0x021CB078  arm  ov114
 *   func_021CAEC8  0x021CAEC8  arm  ov114
 *   func_021CAE20  0x021CAE20  arm  ov114
 *   func_021CAB94  0x021CAB94  arm  ov114
 *   func_021CCDFC  0x021CCDFC  arm  ov114
 *   func_021CB2A4  0x021CB2A4  arm  ov114
 *   func_021CB9BC  0x021CB9BC  arm  ov114
 *   func_021CB764  0x021CB764  arm  ov114
 *   func_021CB3B4  0x021CB3B4  arm  ov114
 */

typedef unsigned int BN_ULONG;

typedef struct
{
    BN_ULONG *d;
    int top;
    int dmax;
    int neg;
    int flags;
} BIGNUM;

typedef struct
{
    int tos;
    BIGNUM bn[13];
    int flags;
    int depth;
} BN_CTX;


typedef struct
{
    BIGNUM N;
    BIGNUM Nr;
    int num_bits;
    int shift;
    int flags;
} BN_RECP_CTX;

extern int func_021CB078(const BIGNUM *, const BIGNUM *);
typedef unsigned char  u8;
extern int func_021CAEC8(u8 *a, unsigned long w);
extern u8 *func_021CAE20(u8 *a, u8 *b);
extern char *func_021CAB94(u8 *p);
extern int func_021CCDFC(BIGNUM *, const BIGNUM *, int, BN_CTX *);
extern int func_021CB2A4(BIGNUM *, const BIGNUM *, int);
extern int func_021CB9BC(BIGNUM *, const BIGNUM *, const BIGNUM *, BN_CTX *);
extern int func_021CB764(BIGNUM *, const BIGNUM *, const BIGNUM *);
extern int func_021CB3B4(BIGNUM *, BN_ULONG);

int func_021CCB88(BIGNUM *dv, BIGNUM *rem, BIGNUM *m, BN_RECP_CTX *recp, BN_CTX *ctx)
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

    if (func_021CB078(m, &(recp->N)) < 0)
    {
        func_021CAEC8((u8 *)d, 0);
        func_021CAE20((u8 *)r, (u8 *)m);
        ctx->tos = tos;
        return 1;
    }

    i = (int)func_021CAB94((u8 *)m);

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
        recp->shift = func_021CCDFC(&(recp->Nr), &(recp->N), i, ctx);

    if (!func_021CB2A4(a, m, j - ex))
        goto err;
    if (!func_021CB9BC(b, a, &(recp->Nr), ctx))
        goto err;
    if (!func_021CB2A4(d, b, j + ex))
        goto err;
    d->neg = 0;
    if (!func_021CB9BC(b, &(recp->N), d, ctx))
        goto err;
    if (!func_021CB764(r, m, b))
        goto err;
    r->neg = 0;

    j = 0;
    while (func_021CB078(r, &(recp->N)) >= 0)
    {
        if (j++ > 2)
            goto err;
        if (!func_021CB764(r, r, &(recp->N)))
            goto err;
        if (!func_021CB3B4(d, 1))
            goto err;
    }

    r->neg = (r->top == 0 || (r->top == 1 && r->d[0] == 0)) ? 0 : m->neg;
    d->neg = m->neg ^ recp->N.neg;
    ret = 1;
err:
    ctx->tos = tos;
    return ret;
}
