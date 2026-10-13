/*
 * function: CRYPTOi__BN_ucmp
 * address:  0x021CB078
 * packet:   pkt_ov114_021CB078
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_ucmp (crypto_bobj1.o)
 *
 * Unsigned magnitude compare.  The early return yields the signed word
 * difference; the pointer locals are declared before the loop index so the
 * allocator keeps the two data cursors in r2/r3 and the index in ip.
 */

typedef struct
{
    unsigned int *d;
    int top;
} BIGNUM;

int CRYPTOi__BN_ucmp(BIGNUM *a, BIGNUM *b)
{
    unsigned int *ap, *bp;
    int i;
    if (a->top - b->top)
        return a->top - b->top;
    ap = a->d;
    bp = b->d;
    for (i = a->top - 1; i >= 0; i--) {
        unsigned int t1 = ap[i];
        unsigned int t2 = bp[i];
        if (t1 != t2)
            return (t1 > t2) ? 1 : -1;
    }
    return 0;
}
