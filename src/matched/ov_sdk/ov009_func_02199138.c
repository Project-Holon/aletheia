/*
 * function: AddNegotiator
 * address:  0x02199138
 * packet:   pkt_ov009_02199138
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      AddNegotiator (natneg.o)
 *
 * symbols:
 *   func_02184144  0x02184144  arm  ov009
 *   ArrayAppend  0x02184234  arm  ov009
 *   ArrayLength  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   gNatnegGlobals  0x021AE698  data
 */

typedef struct _NATNegotiator {
    int data[0x15];
} NATNegotiator;

extern void *gNatnegGlobals;
extern void *func_02184144(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void ArrayAppend(void *array, void *newElem);
extern int ArrayLength(const int *p);
extern void *func_02184208(void *array, int n);

NATNegotiator *AddNegotiator(void)
{
    NATNegotiator _neg = {0};

    if (!gNatnegGlobals)
        gNatnegGlobals = func_02184144(sizeof(NATNegotiator), 4, 0);
    ArrayAppend(gNatnegGlobals, &_neg);
    return (NATNegotiator *)func_02184208(gNatnegGlobals, ArrayLength(gNatnegGlobals) - 1);
}
