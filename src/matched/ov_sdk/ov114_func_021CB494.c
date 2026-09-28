/*
 * function: func_021CB494
 * address:  0x021CB494
 * packet:   pkt_ov114_021CB494
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_sub_word (libcrypto.TWL.HYB.a crypto_bobj1.o)
 * symbols:
 *   func_021CADAC                    0x021cadac arm ov114
 *   func_021CB3B4                    0x021cb3b4 arm ov114
 */

typedef unsigned long BN_ULONG;

typedef struct {
    BN_ULONG *d;
    int top;
    int dmax;
    int neg;
    int flags;
} BIGNUM;

extern BIGNUM *func_021CADAC(BIGNUM *a, int words);
extern int func_021CB3B4(BIGNUM *a, BN_ULONG w);

#define bn_wexpand(a, words) (((words) <= (a)->dmax) ? (a) : func_021CADAC((a), (words)))

int func_021CB494(BIGNUM *a, BN_ULONG w)
{
    int i;

    if (w == 0)
        return 1;
    if (a->neg) {
        a->neg = 0;
        i = func_021CB3B4(a, w);
        a->neg = 1;
        return i;
    }
    if (a->top <= 1) {
        if (a->top == 0) {
            if (bn_wexpand(a, 1) == 0)
                return 0;
            a->d[0] = w;
            a->neg = 1;
            a->top = 1;
            return 1;
        }
        if (a->d[0] == w)
            a->top = 0;
        else if (a->d[0] > w)
            a->d[0] -= w;
        else {
            w -= a->d[0];
            a->neg = 1;
            a->d[0] = w;
        }
        return 1;
    }
    i = 0;
    for (;;) {
        if (a->d[i] >= w) {
            a->d[i] -= w;
            break;
        } else {
            a->d[i] -= w;
            i++;
            w = 1;
        }
    }
    if (a->d[i] == 0 && i == a->top - 1)
        a->top--;
    return 1;
}
