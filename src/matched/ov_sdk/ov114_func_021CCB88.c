/*
 * function: CRYPTOi__BN_div_recp
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
 *   CRYPTOi__BN_ucmp  0x021CB078  arm  ov114
 *   CRYPTOi__BN_set_word  0x021CAEC8  arm  ov114
 *   CRYPTOi__BN_copy  0x021CAE20  arm  ov114
 *   CRYPTOi__BN_num_bits  0x021CAB94  arm  ov114
 *   CRYPTOi__BN_reciprocal  0x021CCDFC  arm  ov114
 *   CRYPTOi__BN_rshift  0x021CB2A4  arm  ov114
 *   CRYPTOi__BN_mul  0x021CB9BC  arm  ov114
 *   CRYPTOi__BN_usub  0x021CB764  arm  ov114
 *   CRYPTOi__BN_add_word  0x021CB3B4  arm  ov114
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

extern int CRYPTOi__BN_ucmp(const BIGNUM *, const BIGNUM *);
typedef unsigned char  u8;
extern int CRYPTOi__BN_set_word(u8 *a, unsigned long w);
extern u8 *CRYPTOi__BN_copy(u8 *a, u8 *b);
extern char *CRYPTOi__BN_num_bits(u8 *p);
extern int CRYPTOi__BN_reciprocal(BIGNUM *, const BIGNUM *, int, BN_CTX *);
extern int CRYPTOi__BN_rshift(BIGNUM *, const BIGNUM *, int);
extern int CRYPTOi__BN_mul(BIGNUM *, const BIGNUM *, const BIGNUM *, BN_CTX *);
extern int CRYPTOi__BN_usub(BIGNUM *, const BIGNUM *, const BIGNUM *);
extern int CRYPTOi__BN_add_word(BIGNUM *, BN_ULONG);

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

    if (CRYPTOi__BN_ucmp(m, &(recp->N)) < 0)
    {
        CRYPTOi__BN_set_word((u8 *)d, 0);
        CRYPTOi__BN_copy((u8 *)r, (u8 *)m);
        ctx->tos = tos;
        return 1;
    }

    i = (int)CRYPTOi__BN_num_bits((u8 *)m);

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
        recp->shift = CRYPTOi__BN_reciprocal(&(recp->Nr), &(recp->N), i, ctx);

    if (!CRYPTOi__BN_rshift(a, m, j - ex))
        goto err;
    if (!CRYPTOi__BN_mul(b, a, &(recp->Nr), ctx))
        goto err;
    if (!CRYPTOi__BN_rshift(d, b, j + ex))
        goto err;
    d->neg = 0;
    if (!CRYPTOi__BN_mul(b, &(recp->N), d, ctx))
        goto err;
    if (!CRYPTOi__BN_usub(r, m, b))
        goto err;
    r->neg = 0;

    j = 0;
    while (CRYPTOi__BN_ucmp(r, &(recp->N)) >= 0)
    {
        if (j++ > 2)
            goto err;
        if (!CRYPTOi__BN_usub(r, r, &(recp->N)))
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
