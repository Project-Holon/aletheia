/*
 * file:     unit_021CAB34_p09.c
 * unit:     yes
 * function: func_021CC0FC, func_021CC124, func_021CC178
 * address:  0x021CC0FC
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
 *   func_021CBB80  0x021CBB80  arm  ov114
 *   func_021CD210  0x021CD210  arm  ov114
 *   func_021CCE7C  0x021CCE7C  arm  ov114
 *   func_021CADAC  0x021CADAC  arm  ov114
 *   func_021CC2B0  0x021CC2B0  arm  ov114
 *   func_021CAE20  0x021CAE20  arm  ov114
 */
#define bn_wexpand(a, w) (((w) <= (a)->dmax) ? (a) : func_021CADAC((a), (w)))
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct
{
    unsigned int *d;
    int top;
} BIGNUM_021CC124;

typedef unsigned int BN_ULONG;

typedef struct
{
    BN_ULONG *d;
    int top;
    int dmax;
    int neg;
    int flags;
} BIGNUM_021CC178;

typedef struct
{
    int tos;
    BIGNUM_021CC178 bn[13];
    int flags;
    int depth;
} BN_CTX;

extern void func_021CBB80(int, int, int, int, int);
extern int func_021CD210(BIGNUM_021CC124 *, const BIGNUM_021CC124 *, const BIGNUM_021CC124 *, const BIGNUM_021CC124 *, void *, void *);
extern int func_021CCE7C(BIGNUM_021CC124 *, const BIGNUM_021CC124 *, const BIGNUM_021CC124 *, const BIGNUM_021CC124 *, void *);
extern BIGNUM_021CC178 *func_021CADAC(BIGNUM_021CC178 *, int);
extern void func_021CC2B0(unsigned long *r, unsigned long *a, int n, unsigned long *tmp);
extern u8 *func_021CAE20(u8 *a, u8 *b);
void func_021CC0FC(int a, int b, int c, int d);
int func_021CC124(BIGNUM_021CC124 *r, const BIGNUM_021CC124 *a, const BIGNUM_021CC124 *p, const BIGNUM_021CC124 *m, void *ctx);
int func_021CC178(BIGNUM_021CC178 *r, const BIGNUM_021CC178 *a, BN_CTX *ctx);


/*
 * Forwards four arguments behind a leading zero to func_021CBB80.
 */
void func_021CC0FC(int a, int b, int c, int d)
{
    func_021CBB80(0, a, b, c, d);
}


/*
 * sdk:      CRYPTOi__BN_mod_exp (crypto_bobj1.o)
 *
 * Montgomery path when the modulus is odd, reciprocal path otherwise.
 * Deferred callees (same object, open SDK, too large for this lane):
 * CRYPTOi__BN_mod_exp_mont (0x021CD210, 1908 B) and
 * CRYPTOi__BN_mod_exp_recp (0x021CCE7C, 916 B).
 */
int func_021CC124(BIGNUM_021CC124 *r, const BIGNUM_021CC124 *a, const BIGNUM_021CC124 *p, const BIGNUM_021CC124 *m, void *ctx)
{
    if (m->top > 0 && (m->d[0] & 1))
        return func_021CD210(r, a, p, m, ctx, 0);
    return func_021CCE7C(r, a, p, m, ctx);
}


int func_021CC178(BIGNUM_021CC178 *r, const BIGNUM_021CC178 *a, BN_CTX *ctx)
{
    int max, al;
    BIGNUM_021CC178 *tmp, *rr;
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
        func_021CC2B0((long unsigned int *)rr->d, (long unsigned int *)a->d, 4, (long unsigned int *)t2);
    }
    else if (al == 8)
    {
        func_021CC2B0((long unsigned int *)rr->d, (long unsigned int *)a->d, 8, (long unsigned int *)t);
    }
    else
    {
        if (bn_wexpand(tmp, max) == 0)
            return 0;
        func_021CC2B0((long unsigned int *)rr->d, (long unsigned int *)a->d, al, (long unsigned int *)tmp->d);
    }

    if (max > 0 && rr->d[max - 1] == 0)
        rr->top--;
    if (rr != r)
        func_021CAE20((u8 *)r, (u8 *)rr);
    return 1;
}
