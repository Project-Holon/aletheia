/*
 * function: func_02086760
 * address:  0x02086760
 * packet:   pkt_02086760
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;

void func_02086760(u32 idx, u32 val)
{
    *(u32 *)((idx << 2) + 0x02FFFDC4) = val;
}
