/*
 * function: func_021CB764
 * address:  0x021CB764
 * packet:   pkt_ov114_021CB764
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      CRYPTOi__BN_usub (crypto_bobj1.o)
 *
 * symbols:
 *   func_021CADAC  0x021CADAC  arm  ov114
 *   func_021CAC8C  0x021CAC8C  arm  ov114
 *
 * notes: DIFF, 44 lines, register permutation only (code shape identical). Target: max r4, min r5, b r6, a r7, r r8, zero sb; this build gives max/min the top registers. Declaring i as long (not int) gets to 23 lines with only max/min swapped; declaration order, register keyword, dif form and a->top<b->top guard do not move it.
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

extern BIGNUM *func_021CADAC(BIGNUM *, int);
extern void func_021CAC8C(BIGNUM *);

#define bn_wexpand(a, w) (((w) <= (a)->dmax) ? (a) : func_021CADAC((a), (w)))

int func_021CB764(BIGNUM *r, const BIGNUM *a, const BIGNUM *b)
{
    int max, min;
    register BN_ULONG t1, t2, *ap, *bp, *rp;
    int i, carry;

    max = a->top;
    min = b->top;
    if (max < min)
        return 0;
    if (bn_wexpand(r, max) == 0)
        return 0;

    ap = a->d;
    bp = b->d;
    rp = r->d;

    carry = 0;
    for (i = 0; i < min; i++)
    {
        t1 = *(ap++);
        t2 = *(bp++);
        if (carry)
        {
            carry = (t1 <= t2);
            t1 = t1 - t2 - 1;
        }
        else
        {
            carry = (t1 < t2);
            t1 = t1 - t2;
        }
        *(rp++) = t1;
    }
    if (carry)
    {
        while (i < max)
        {
            i++;
            t1 = *(ap++);
            t2 = t1 - 1;
            *(rp++) = t2;
            if (t1 > t2)
                break;
        }
    }
    if (rp != ap)
    {
        for (;;)
        {
            if (i++ >= max) break;
            rp[0] = ap[0];
            if (i++ >= max) break;
            rp[1] = ap[1];
            if (i++ >= max) break;
            rp[2] = ap[2];
            if (i++ >= max) break;
            rp[3] = ap[3];
            rp += 4;
            ap += 4;
        }
    }
    r->top = max;
    func_021CAC8C(r);
    return 1;
}
