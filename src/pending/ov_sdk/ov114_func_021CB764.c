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
 * lane07 (2026-10-01): OpenSSL's `& BN_MASK2` on every t1/t2 expression is inert (24 B),
 *   and with it `int i, carry` is still 51 B.
 *
 * sdk:      CRYPTOi__BN_usub (crypto_bobj1.o)
 *
 * symbols:
 *   func_021CADAC  0x021CADAC  arm  ov114
 *   func_021CAC8C  0x021CAC8C  arm  ov114
 *
 * notes: DIFF, 23 lines / 24 concrete bytes (down from 44 lines): `long i` plus hoisting
 * `if (a->top < b->top) return 0;` ahead of the loads. Residue is a single exchange:
 * max holds r5 and min r4 here, r4/r5 in the object, so every use of the pair differs
 * (`ldr r5,[r6,#4] | ldr r4,[r6,#4]` at +000C). 22 further spellings inert -- declaration
 * and assignment order (`min` first, `int min, max`), hoist/no-hoist, comma form, named
 * temp, min-after-wexpand, `long`/`unsigned` max/min, carry types, split register decls,
 * BN_ULONG max/min -- all land on the same exchange; the `long i` change is what buys the
 * other 20 bytes.
 * Wave-8 retry: `if (b->top > a->top)` only swaps which operand is loaded first
 * (a->top into r5) and leaves max still r5/min r4; assigning `max=a->top;min=b->top;`
 * before the guard (guard on max<min) is inert; declaration `int min, max;` inert.
 * max is pinned to the higher callee-saved register regardless of load/assign/decl
 * order -- the allocator's value-number choice, not a source order lever.
 *
 * blocker: max allocated r5 (object r4), min r4 (object r5); every load/assign/decl
 * order spelling lands on the same exchange of the whole 332-byte body.
 * Wave-8 sweep (permanent negative result, do not re-run): 192 spellings crossing
 * decl order, `int max=a->top,min=b->top` initialiser, `register` on/off, `long`
 * i/carry order, assign order and `a<b`/`b>a` guard all leave int at 24; only the
 * type moves it (unsigned 152, long 51). 122 more spellings over the three
 * declaration statements (max/min, `BN_ULONG t1,t2,*ap,*bp,*rp`, `long i,carry`)
 * in every order, plus t1/t2 and ap/bp swaps, are also 24; swapping t1/t2 is 37.
 * The r4/r5 tie is therefore a global value-number/colouring choice, not a source
 * declaration-order lever.
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
    long i, carry;

    if (a->top < b->top)
        return 0;
    max = a->top;
    min = b->top;
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
