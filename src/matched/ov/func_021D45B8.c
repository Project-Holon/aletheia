/*
 * function: BTL_NET_RecvPerapVoiceDone
 * address:  0x021D45B8
 * packet:   pkt_021D45B8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (hidden in the pool run after BTL_NET_AllocPerapVoiceBuf).  Setter
 * through gBtlNet: a special value for b==4, otherwise a plain u32
 * store.
 *
 * symbols:
 *   gBtlNet  0x021F3B88  data
 */
#include "../include/Obj12142.h"

extern int gBtlNet;

void BTL_NET_RecvPerapVoiceDone(int a, int b)
{
    if (b == 4) {
        char *q = (char *)gBtlNet + 0xbf4 + a * 0xbbc;
        ((struct Obj12142 *)q)->fBB8 = b;
        ((struct Obj12142 *)q)->fBBA = 0;
    } else {
        *(int *)((char *)gBtlNet + a * 4 + 0x3af4) = b;
    }
}
