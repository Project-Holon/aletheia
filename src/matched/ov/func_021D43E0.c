/*
 * function: BTL_NET_RecvSetup
 * address:  0x021D43E0
 * packet:   pkt_021D43E0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr prologue, hidden in the pool run after
 * BTL_NET_SendSetup).  Copies a 32-byte aggregate into the object at
 * gBtlNet+0x18 once, gated on byte +0xa.
 *
 * symbols:
 *   gBtlNet  0x021F3B88  data
 */
#include "../include/Obj12141.h"

typedef struct {
    int w[8];
} S32;

extern int gBtlNet;

void BTL_NET_RecvSetup(int unused0, int unused1, S32 *src)
{
    char *p = (char *)gBtlNet;

    if (((struct Obj12141 *)p)->fA == 0) {
        *(S32 *)(p + 0x18) = *src;
        ((struct Obj12141 *)p)->fA = 1;
    }
}
