/*
 * function: NNThink
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
 *   CheckNatifyStatus  0x02199BE4  arm  ov009
 *   ArrayLength  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   NegotiateThink  0x0219A054  arm  ov009
 *   gNatnegGlobals  0x021AE698  data
 *   gNatSocks  0x021A5A70  data
 */

#include "../include/G_NatSocks.h"

typedef struct {
    void *list;
    int pad4[7];
    int natifyActive;
} NegotiateGlobals;

extern NegotiateGlobals gNatnegGlobals;
extern struct NatSocks gNatSocks;
extern int CheckNatifyStatus(int sock);
struct _NATNegotiator;
extern int ArrayLength(const int *p);
extern void *func_02184208(void *array, int n);
extern void NegotiateThink(struct _NATNegotiator *neg);

void NNThink(void *p)
{
    int i;

    if (gNatnegGlobals.natifyActive)
        gNatnegGlobals.natifyActive = CheckNatifyStatus(gNatSocks.mappingSock) && CheckNatifyStatus(gNatSocks.ertSock);
    if (!gNatnegGlobals.list)
        return;
    for (i = ArrayLength(gNatnegGlobals.list) - 1; i >= 0; i--)
        NegotiateThink(func_02184208(gNatnegGlobals.list, i));
}
