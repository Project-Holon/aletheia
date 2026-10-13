/*
 * function: GFL_NET_STATE_GetChildWaitTime
 * address:  0x0203B2FC
 * packet:   pkt_0203B2FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;
typedef unsigned long long u64;

u32 GFL_NET_STATE_GetChildWaitTime(char *p)
{
    u32 hi;
    u64 acc = *(u64 *)(p + 0x14) * *(u64 *)(p + 0xc) + *(u64 *)(p + 0x1c);
    *(u64 *)(p + 0xc) = acc;
    hi = (u32)(acc >> 32);
    return (u32)(((u64)hi * 40) >> 32) + 0x3c;
}
