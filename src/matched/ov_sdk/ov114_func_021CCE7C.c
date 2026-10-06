/*
 * function: func_021CCE7C
 * address:  0x021CCE7C
 * packet:   pkt_ov114_021CCE7C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_mod_exp_recp (crypto_bobj1.o)
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

typedef unsigned char  u8;
extern char *func_021CAB94(u8 *p);
extern int func_021CAEC8(u8 *a, unsigned long w);
extern u8 *func_021CAE20(u8 *a, u8 *b);
extern void func_021CCA5C(u8 *p);
extern int func_021CCAAC(BN_RECP_CTX *, const BIGNUM *, BN_CTX *);
extern void func_021CACD0(int a);
extern int func_021CC0FC(BIGNUM *, const BIGNUM *, const BIGNUM *, BN_CTX *);
extern int func_021CCAE4(BIGNUM *, BIGNUM *, BIGNUM *, BN_RECP_CTX *, BN_CTX *);
extern int func_021CB15C(const BIGNUM *, int);
extern void func_021CABC0(int a);
extern void func_021CCA80(u8 *p);

#define BN_is_zero(a) (((a)->top == 0) || (((a)->top == 1) && ((a)->d[0] == 0)))
#define BN_is_one(a) (((a)->top == 1) && ((a)->d[0] == 1))

int func_021CCE7C(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx)
{
    int i, j, bits, ret = 0, wstart, wend, window, wvalue;
    int start = 1, ts = 0;
    BIGNUM *aa;
    BIGNUM val[16];
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
