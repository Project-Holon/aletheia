/*
 * function: OS_SetArenaLo
 * address:  0x02086774
 * packet:   pkt_02086760
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;

void OS_SetArenaLo(u32 idx, u32 val)
{
    *(u32 *)((idx << 2) + 0x02FFFDA0) = val;
}
