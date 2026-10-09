/*
 * file:     unit_02072DD0.c
 * function: func_02072DD0
 * address:  0x02072DD0
 * packet:   pkt_02072D20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  ABS32 g_0214E480 at +0x14: the address has no witness outside this function's own pool word
 *
 * symbols:
 *   g_0214E480       0x0214E480  data
 *
 * Word field of record `idx` in the same stride-0x24 table.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02072DD0.c \
 *       --func func_02072DD0 --addr 0x02072DD0 --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern u8 g_0214E480[];

void func_02072DD0(u32 idx, u32 val)
{
    *(u32 *)(g_0214E480 + idx * 0x24) = val;
}
