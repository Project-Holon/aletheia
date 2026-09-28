/*
 * function: func_021CAC24
 * address:  0x021CAC24
 * packet:   pkt_ov114_021CAC24
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__bn_zexpand (crypto_bobj1.o)
 *
 * symbols:
 *   func_021CADAC  0x021CADAC  arm  ov114
 *
 * bn_wexpand shape: grow to n words then zero the newly exposed words.
 */

typedef struct
{
    unsigned int *d;
    int top;
    int max;
} BIGNUM;

extern BIGNUM *func_021CADAC(BIGNUM *, int);

BIGNUM *func_021CAC24(BIGNUM *a, int n)
{
    int i;
    if (a->top < n) {
        if ((n > a->max ? func_021CADAC(a, n) : a) == 0)
            return 0;
        if (a->d != 0) {
            for (i = a->top; i < n; i++)
                a->d[i] = 0;
        }
    }
    return a;
}
