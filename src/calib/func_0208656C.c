/*
 * function: OS_GetArenaHi
 * address:  0x0208656C
 * packet:   pkt_0208656C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;

u32 OS_GetArenaHi(u32 idx)
{
    return *(u32 *)((idx << 2) + 0x02FFFDC4);
}
