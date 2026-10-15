/*
 * function: FindNegotiatorForCookie
 * address:  0x021990D4
 * packet:   pkt_ov009_021990D4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FindNegotiatorForCookie (natneg.o)
 *
 * symbols:
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   gNatnegGlobals  0x021AE698  data
 */

typedef struct _NATNegotiator {
    int state;
    int cookie;
} NATNegotiator;

extern void *gNatnegGlobals;
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);

NATNegotiator *FindNegotiatorForCookie(int cookie)
{
    int i;
    NATNegotiator *neg;

    if (!gNatnegGlobals)
        return 0;
    for (i = 0; i < func_02184200(gNatnegGlobals); i++) {
        neg = (NATNegotiator *)func_02184208(gNatnegGlobals, i);
        if (neg->cookie == cookie)
            return neg;
    }
    return 0;
}
