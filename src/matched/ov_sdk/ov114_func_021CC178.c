/*
 * function: CRYPTOi__BN_sqr
 * address:  0x021CC178
 * packet:   pkt_ov114_021CC178
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_sqr (crypto_bobj1.o)
 *
 * symbols:
 *   CRYPTOi__bn_expand2  0x021CADAC  arm  ov114
 *   CRYPTOi__bn_sqr_normal  0x021CC2B0  arm  ov114
 *   CRYPTOi__BN_copy  0x021CAE20  arm  ov114
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

extern BIGNUM *CRYPTOi__bn_expand2(BIGNUM *, int);
typedef unsigned char  u8;
extern void CRYPTOi__bn_sqr_normal(unsigned long *r, unsigned long *a, int n, unsigned long *tmp);
extern u8 *CRYPTOi__BN_copy(u8 *a, u8 *b);

#define bn_wexpand(a, w) (((w) <= (a)->dmax) ? (a) : CRYPTOi__bn_expand2((a), (w)))

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
        CRYPTOi__BN_copy((u8 *)r, (u8 *)rr);
    return 1;
}
