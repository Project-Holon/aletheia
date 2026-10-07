/*
 * function: func_02199138
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
 *   func_02184234  0x02184234  arm  ov009
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   g_021AE698  0x021AE698  data
 */

typedef struct _NATNegotiator {
    int data[0x15];
} NATNegotiator;

extern void *g_021AE698;
extern void *func_02184144(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void func_02184234(void *array, void *newElem);
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);

NATNegotiator *func_02199138(void)
{
    NATNegotiator _neg = {0};

    if (!g_021AE698)
        g_021AE698 = func_02184144(sizeof(NATNegotiator), 4, 0);
    func_02184234(g_021AE698, &_neg);
    return (NATNegotiator *)func_02184208(g_021AE698, func_02184200(g_021AE698) - 1);
}
