/*
 * function: OS_GetArenaLo
 * address:  0x02086580
 * packet:   pkt_0208656C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;

u32 OS_GetArenaLo(u32 idx)
{
    return *(u32 *)((idx << 2) + 0x02FFFDA0);
}
