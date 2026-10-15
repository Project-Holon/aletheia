/*
 * function: RemoveNegotiator
 * address:  0x021991C8
 * packet:   pkt_ov009_021991C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      RemoveNegotiator (natneg.o)
 *
 * symbols:
 *   ArrayLength  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_02184324  0x02184324  arm  ov009
 *   gNatnegGlobals  0x021AE698  data
 */

typedef struct _NATNegotiator {
    int state;
    int cookie;
} NATNegotiator;

extern void *gNatnegGlobals;
extern int ArrayLength(const int *p);
extern void *func_02184208(void *array, int n);
extern void func_02184324(void *array, int n);

void RemoveNegotiator(NATNegotiator *neg)
{
    int i;

    for (i = 0; i < ArrayLength(gNatnegGlobals); i++) {
        if (neg == func_02184208(gNatnegGlobals, i)) {
            func_02184324(gNatnegGlobals, i);
            return;
        }
    }
}
