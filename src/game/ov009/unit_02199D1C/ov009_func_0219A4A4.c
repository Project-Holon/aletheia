/*
 * function: func_0219A4A4
 * address:  0x0219A4A4
 * packet:   pkt_ov009_0219A4A4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NNThink (natneg.o)
 *
 * symbols:
 *   func_02199BE4  0x02199BE4  arm  ov009
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_0219A054  0x0219A054  arm  ov009
 *   g_021AE698  0x021AE698  data
 *   g_021A5A70  0x021A5A70  data
 */

#include "../../../matched/include/G_NatSocks.h"

typedef struct {
    void *list;
    int pad4[7];
    int natifyActive;
} NegotiateGlobals;

extern NegotiateGlobals g_021AE698;
extern struct NatSocks g_021A5A70;
extern int func_02199BE4(int sock);
struct _NATNegotiator;
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern void func_0219A054(struct _NATNegotiator *neg);

void func_0219A4A4(void *p)
{
    int i;

    if (g_021AE698.natifyActive)
        g_021AE698.natifyActive = func_02199BE4(g_021A5A70.mappingSock) && func_02199BE4(g_021A5A70.ertSock);
    if (!g_021AE698.list)
        return;
    for (i = func_02184200(g_021AE698.list) - 1; i >= 0; i--)
        func_0219A054(func_02184208(g_021AE698.list, i));
}
