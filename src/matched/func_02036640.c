/*
 * function: func_02036640
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
 * The used count is the body of the matched sibling func_020365E8 inlined
 * verbatim (its two volatile re-reads of the +0xE cursor are what keep the
 * per-arm reloads the earlier DIFF note could not reproduce).
 */

typedef unsigned int u32;

static inline int RingUsed(char *p)
{
    int a = *(short *)(p + 0x0C);
    if (a > *(short *)(p + 0x0E))
        return *(u32 *)(p + 4) + *(volatile short *)(p + 0x0E) - a;
    return *(volatile short *)(p + 0x0E) - a;
}

int func_02036640(char *p)
{
    return *(int *)(p + 4) - RingUsed(p);
}
