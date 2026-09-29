/*
 * function: func_021991C8
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
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_02184324  0x02184324  arm  ov009
 *   g_021AE698  0x021AE698  data
 */

typedef struct _NATNegotiator {
    int state;
    int cookie;
} NATNegotiator;

extern void *g_021AE698;
extern int func_02184200(void *array);
extern void *func_02184208(void *array, int n);
extern void func_02184324(void *array, int n);

void func_021991C8(NATNegotiator *neg)
{
    int i;

    for (i = 0; i < func_02184200(g_021AE698); i++) {
        if (neg == func_02184208(g_021AE698, i)) {
            func_02184324(g_021AE698, i);
            return;
        }
    }
}
