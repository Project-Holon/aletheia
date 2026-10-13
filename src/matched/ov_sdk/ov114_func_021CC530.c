/*
 * function: CRYPTOi__BN_gen_exp_bits
 * address:  0x021CC530
 * packet:   pkt_ov114_021CC530
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_gen_exp_bits (crypto_bobj1.o)
 *
 * symbols:
 *   CRYPTOi__bn_expand2  0x021CADAC  arm  ov114
 *   CRYPTOi__BN_gen_exp_string  0x021CC674  arm  ov114
 *   sCryptoBnGenExpBitsTable16  0x021CE1F8  data  ov114
 *   sCryptoBnGenExpBitsTable4  0x021CE1EE  data  ov114
 *   sCryptoBnGenExpBitsTable2  0x021CE1E4  data  ov114
 *   sCryptoBnNumBitsWordBits  0x021CE202  data
 *
 * sCryptoBnGenExpBitsTable16, sCryptoBnGenExpBitsTable4, sCryptoBnGenExpBitsTable2 are the object's local tables p16, p4, p2.
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
extern int CRYPTOi__BN_gen_exp_string(unsigned char *, const BIGNUM *, int);
extern unsigned char sCryptoBnGenExpBitsTable16[10];
extern unsigned char sCryptoBnGenExpBitsTable4[10];
extern unsigned char sCryptoBnGenExpBitsTable2[10];

#define bn_wexpand(a, w) (((w) <= (a)->dmax) ? (a) : CRYPTOi__bn_expand2((a), (w)))

int CRYPTOi__BN_gen_exp_bits(const BIGNUM *e, unsigned char **out, int unused, BN_CTX *ctx)
{
    int top, sCryptoBnNumBitsWordBits, window, count, step, words, len;
    unsigned char *p;
    BIGNUM *tmp;

    tmp = &ctx->bn[ctx->tos];
    p = 0;
    top = e->top;
    sCryptoBnNumBitsWordBits = top << 5;
    if (top == 0)
        return 0;

    if (top == 1)
    {
        if (top == 1 && e->d[0] == 0x10001)
            p = sCryptoBnGenExpBitsTable16;
        else if (e->d[0] == 0x11 && top == 1)
            p = sCryptoBnGenExpBitsTable4;
        else if (e->d[0] == 3 && top == 1)
            p = sCryptoBnGenExpBitsTable2;
        window = 1;
        count = 1;
        step = 32;
    }
    else if (sCryptoBnNumBitsWordBits >= 256)
    {
        window = 5;
        count = 16;
        step = 7;
    }
    else if (sCryptoBnNumBitsWordBits >= 128)
    {
        window = 4;
        count = 8;
        step = 8;
    }
    else
    {
        window = 3;
        count = 4;
        step = 11;
    }

    words = (top * step * 2 + 7) / 4;
    if (p == 0)
    {
        if (bn_wexpand(tmp, words) == 0)
            return 0;
        p = (unsigned char *)tmp->d;
        len = CRYPTOi__BN_gen_exp_string(p + 4, e, window) + 2;
        p[0] = len >> 8;
        p[1] = len;
        p[2] = window;
        p[3] = count;
    }
    else
    {
        len = 8;
    }
    *out = p;
    return len + 2;
}
