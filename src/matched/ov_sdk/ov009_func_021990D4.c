/*
 * function: func_021990D4
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
 *   g_021AE698  0x021AE698  data
 */

typedef struct _NATNegotiator {
    int state;
    int cookie;
} NATNegotiator;

extern void *g_021AE698;
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);

NATNegotiator *func_021990D4(int cookie)
{
    int i;
    NATNegotiator *neg;

    if (!g_021AE698)
        return 0;
    for (i = 0; i < func_02184200(g_021AE698); i++) {
        neg = (NATNegotiator *)func_02184208(g_021AE698, i);
        if (neg->cookie == cookie)
            return neg;
    }
    return 0;
}
