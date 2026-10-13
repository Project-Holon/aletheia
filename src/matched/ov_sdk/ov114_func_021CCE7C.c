/*
 * function: CRYPTOi__BN_mod_exp_recp
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
 *   CRYPTOi__BN_num_bits  0x021CAB94  arm  ov114
 *   CRYPTOi__BN_set_word  0x021CAEC8  arm  ov114
 *   CRYPTOi__BN_copy  0x021CAE20  arm  ov114
 *   CRYPTOi__BN_RECP_CTX_init  0x021CCA5C  arm  ov114
 *   CRYPTOi__BN_RECP_CTX_set  0x021CCAAC  arm  ov114
 *   CRYPTOi__BN_init  0x021CACD0  arm  ov114
 *   CRYPTOi__BN_mod  0x021CC0FC  arm  ov114
 *   CRYPTOi__BN_mod_mul_reciprocal  0x021CCAE4  arm  ov114
 *   CRYPTOi__BN_is_bit_set  0x021CB15C  arm  ov114
 *   CRYPTOi__BN_clear_free  0x021CABC0  arm  ov114
 *   CRYPTOi__BN_RECP_CTX_free  0x021CCA80  arm  ov114
 *   sCryptoBnNumBitsWordBits  0x021CE202  data
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
extern char *CRYPTOi__BN_num_bits(u8 *p);
extern int CRYPTOi__BN_set_word(u8 *a, unsigned long w);
extern u8 *CRYPTOi__BN_copy(u8 *a, u8 *b);
extern void CRYPTOi__BN_RECP_CTX_init(u8 *p);
extern int CRYPTOi__BN_RECP_CTX_set(BN_RECP_CTX *, const BIGNUM *, BN_CTX *);
extern void CRYPTOi__BN_init(int a);
extern int CRYPTOi__BN_mod(BIGNUM *, const BIGNUM *, const BIGNUM *, BN_CTX *);
extern int CRYPTOi__BN_mod_mul_reciprocal(BIGNUM *, BIGNUM *, BIGNUM *, BN_RECP_CTX *, BN_CTX *);
extern int CRYPTOi__BN_is_bit_set(const BIGNUM *, int);
extern void CRYPTOi__BN_clear_free(int a);
extern void CRYPTOi__BN_RECP_CTX_free(u8 *p);

#define BN_is_zero(a) (((a)->top == 0) || (((a)->top == 1) && ((a)->d[0] == 0)))
#define BN_is_one(a) (((a)->top == 1) && ((a)->d[0] == 1))

int CRYPTOi__BN_mod_exp_recp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx)
{
    int i, j, sCryptoBnNumBitsWordBits, ret = 0, wstart, wend, window, wvalue;
    int start = 1, ts = 0;
    BIGNUM *aa;
    BIGNUM val[16];
    BN_RECP_CTX recp;

    sCryptoBnNumBitsWordBits = (int)CRYPTOi__BN_num_bits((u8 *)p);

    if (BN_is_zero(a))
    {
        CRYPTOi__BN_set_word((u8 *)r, 0);
        return 1;
    }
    if (BN_is_zero(p))
    {
        CRYPTOi__BN_set_word((u8 *)r, 1);
        return 1;
    }
    if (BN_is_one(p))
    {
        CRYPTOi__BN_copy((u8 *)r, (u8 *)a);
        return 1;
    }

    CRYPTOi__BN_RECP_CTX_init((u8 *)(&recp));
    if (CRYPTOi__BN_RECP_CTX_set(&recp, m, ctx) <= 0)
        goto err;

    CRYPTOi__BN_init((int)(&(val[0])));
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
        CRYPTOi__BN_init((int)(&(val[i])));
        if (!CRYPTOi__BN_mod_mul_reciprocal(&(val[i]), &(val[i - 1]), aa, &recp, ctx))
            goto err;
    }
    ts = i;

    start = 1;
    wvalue = 0;
    wstart = sCryptoBnNumBitsWordBits - 1;
    wend = 0;

    if (!CRYPTOi__BN_set_word((u8 *)r, 1))
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
        CRYPTOi__BN_clear_free((int)(&(val[i])));
    CRYPTOi__BN_RECP_CTX_free((u8 *)(&recp));
    return ret;
}
