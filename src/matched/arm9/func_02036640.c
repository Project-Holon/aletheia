/*
 * function: GFL_NET_RING_BUFF_GetWritableSize
 * address:  0x02036640
 * packet:   pkt_02036640
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Free space of a net_ring_buff.c ring: capacity (+4) minus the used count.
 * The used count is the body of the matched sibling GFL_NET_RING_BUFF_GetDataSize inlined
 * verbatim (its two volatile re-reads of the +0xE cursor are what keep the
 * per-arm reloads the earlier DIFF note could not reproduce).
 */
#include "../include/Obj05731.h"
#include "../include/Obj15901.h"

typedef unsigned int u32;

static inline int RingUsed(char *p)
{
    int a = ((struct Obj05731 *)p)->fC;
    if (a > ((struct Obj05731 *)p)->fE)
        return ((struct Obj05731 *)p)->f4 + *(volatile short *)&((struct Obj05731 *)p)->fE - a;
    return *(volatile short *)&((struct Obj05731 *)p)->fE - a;
}

int GFL_NET_RING_BUFF_GetWritableSize(char *p)
{
    return ((struct Obj15901 *)p)->f4 - RingUsed(p);
}
