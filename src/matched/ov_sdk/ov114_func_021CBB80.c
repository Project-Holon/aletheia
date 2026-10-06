/*
 * function: func_021CBB80
 * address:  0x021CBB80
 * packet:   pkt_ov114_021CBB80
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_div (libcrypto.TWL.HYB.a crypto_bobj1.o)
 *
 * symbols:
 *   func_021CB078  0x021CB078  arm  ov114
 *   func_021CAE20  0x021CAE20  arm  ov114
 *   func_021CAEC8  0x021CAEC8  arm  ov114
 *   func_021CAB94  0x021CAB94  arm  ov114
 *   func_021CB1A8  0x021CB1A8  arm  ov114
 *   func_021CACD0  0x021CACD0  arm  ov114
 *   func_021CADAC  0x021CADAC  arm  ov114
 *   func_021CB764  0x021CB764  arm  ov114
 *   func_021CDAE8  0x021CDAE8  arm  ov114
 *   func_021CDA38  0x021CDA38  arm  ov114
 *   func_021CB8B0  0x021CB8B0  arm  ov114
 *   func_021CB5A0  0x021CB5A0  arm  ov114
 *   func_021CAC8C  0x021CAC8C  arm  ov114
 *   func_021CB2A4  0x021CB2A4  arm  ov114
 *
 * The object has no DWARF for this function; the shape follows the
 * relocations and the BN_CTX layout of the other crypto_bobj1.o rows.
 */

typedef unsigned long BN_ULONG;

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

extern int func_021CB078(const BIGNUM *a, const BIGNUM *b);
typedef unsigned char  u8;
extern u8 *func_021CAE20(u8 *a, u8 *b);
extern int func_021CAEC8(u8 *a, unsigned long w);
extern int func_021CAB94(const BIGNUM *a);
extern int func_021CB1A8(BIGNUM *r, const BIGNUM *a, int n);
extern void func_021CACD0(int a);
extern BIGNUM *func_021CADAC(BIGNUM *a, int words);
extern int func_021CB764(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
extern BN_ULONG func_021CDAE8(BN_ULONG h, BN_ULONG l, BN_ULONG d);
extern BN_ULONG func_021CDA38(BN_ULONG *rp, BN_ULONG *ap, int num, BN_ULONG w);
extern int func_021CB8B0(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
extern int func_021CB5A0(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
extern void func_021CAC8C(BIGNUM *a);
extern int func_021CB2A4(BIGNUM *r, const BIGNUM *a, int n);

#define BN_BITS2   32
#define BN_MASK2   0xffffffffUL
#define BN_MASK2l  0xffffUL
#define LBITS(a)   ((a) & BN_MASK2l)
#define HBITS(a)   (((a) >> 16) & BN_MASK2l)
#define L2HBITS(a) ((BN_ULONG)((a) & BN_MASK2l) << 16)

#define bn_wexpand(a, w) (((w) <= (a)->dmax) ? (a) : func_021CADAC((a), (w)))

#define mul64(l, h, bl, bh)                  \
    {                                        \
        BN_ULONG m, m1, lt, ht;              \
        lt = l;                              \
        ht = h;                              \
        m = (bh) * (lt);                     \
        lt = (bl) * (lt);                    \
        m1 = (bl) * (ht);                    \
        ht = (bh) * (ht);                    \
        m = (m + m1) & BN_MASK2;             \
        if (m < m1) ht += L2HBITS(1L);       \
        ht += HBITS(m);                      \
        m1 = L2HBITS(m);                     \
        lt = (lt + m1) & BN_MASK2;           \
        if (lt < m1) ht++;                   \
        l = lt;                              \
        h = ht;                              \
    }

int func_021CBB80(BIGNUM *dv, BIGNUM *rm, const BIGNUM *num, const BIGNUM *divisor, BN_CTX *ctx)
{
    int norm_shift, i, j, loop;
    BIGNUM *tmp, wnum, *snum, *sdiv, *res;
    BN_ULONG *resp, *wnump;
    BN_ULONG d0, d1;
    int num_n, div_n;

    if (divisor->top == 0 || (divisor->top == 1 && divisor->d[0] == 0))
        return 0;

    if (func_021CB078(num, divisor) < 0)
    {
        if (rm != 0)
        {
            if (func_021CAE20((u8 *)rm, (u8 *)num) == 0)
                return 0;
        }
        if (dv != 0)
            func_021CAEC8((u8 *)dv, 0);
        return 1;
    }

    tmp = &ctx->bn[ctx->tos];
    tmp->neg = 0;
    snum = &ctx->bn[ctx->tos + 1];
    sdiv = &ctx->bn[ctx->tos + 2];
    if (dv == 0)
        res = &ctx->bn[ctx->tos + 3];
    else
        res = dv;

    norm_shift = BN_BITS2 - (func_021CAB94(divisor) % BN_BITS2);
    if (!func_021CB1A8(sdiv, divisor, norm_shift))
        return 0;
    sdiv->neg = 0;
    if (!func_021CB1A8(snum, num, norm_shift + BN_BITS2))
        return 0;
    snum->neg = 0;
    div_n = sdiv->top;
    num_n = snum->top;
    loop = num_n - div_n;

    func_021CACD0((int)(&wnum));
    wnum.d = &snum->d[loop];
    wnum.top = div_n;
    wnum.dmax = snum->dmax + 1;

    d0 = sdiv->d[div_n - 1];
    d1 = (div_n == 1) ? 0 : sdiv->d[div_n - 2];

    wnump = &snum->d[num_n - 1];

    if (!bn_wexpand(res, loop + 1))
        goto err;
    res->neg = num->neg ^ divisor->neg;
    res->top = loop;
    resp = &res->d[loop - 1];

    if (!bn_wexpand(tmp, div_n + 1))
        goto err;

    if (func_021CB078(&wnum, sdiv) >= 0)
    {
        if (!func_021CB764(&wnum, &wnum, sdiv))
            goto err;
        *resp = 1;
        res->d[res->top - 1] = 1;
    }
    else
        res->top--;
    resp--;

    for (i = 0; i < loop - 1; i++)
    {
        BN_ULONG q, n0, n1;
        BN_ULONG l0;

        wnum.d--;
        wnum.top++;
        n0 = wnump[0];
        n1 = wnump[-1];
        if (n0 == d0)
            q = BN_MASK2;
        else
            q = func_021CDAE8(n0, n1, d0);
        {
            BN_ULONG t1l, t1h, t2l, t2h, t3l, t3h, ql, qh, t3t;
            t1h = n0;
            t1l = n1;
            for (;;)
            {
                t2l = LBITS(d1);
                t2h = HBITS(d1);
                ql = LBITS(q);
                qh = HBITS(q);
                mul64(t2l, t2h, ql, qh);

                t3t = LBITS(d0);
                t3h = HBITS(d0);
                mul64(t3t, t3h, ql, qh);
                t3l = (t1l - t3t) & BN_MASK2;
                if (t3l > t1l)
                    t3h++;
                t3h = (t1h - t3h) & BN_MASK2;

                if (t3h)
                    break;
                if (t2h < t3l)
                    break;
                if ((t2h == t3l) && (t2l <= wnump[-2]))
                    break;

                q--;
            }
        }
        l0 = func_021CDA38(tmp->d, sdiv->d, div_n, q);
        tmp->d[div_n] = l0;
        for (j = div_n + 1; j > 0; j--)
            if (tmp->d[j - 1])
                break;
        tmp->top = j;

        j = wnum.top;
        func_021CB8B0(&wnum, &wnum, tmp);

        snum->top = snum->top + wnum.top - j;

        if (wnum.neg)
        {
            q--;
            j = wnum.top;
            func_021CB5A0(&wnum, &wnum, sdiv);
            snum->top += wnum.top - j;
        }
        *(resp--) = q;
        wnump--;
    }
    func_021CAC8C(snum);
    if (rm != 0)
    {
        int neg = num->neg;
        if (!func_021CB2A4(rm, snum, norm_shift + BN_BITS2))
            return 0;
        rm->neg = neg;
    }
    return 1;
err:
    return 0;
}
