/*
 * function: func_02072D98
 * address:  0x02072D98
 * packet:   pkt_020720
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 *
 * blocker:  +0014 ABS32 g_0214E484             -> unresolved: 0214E484 (data, from header) has no witness outside 02072D98..02072DB0
 *
 * symbols:
 *   g_0214E484       0x0214E484  data
 *
 * Byte field of record `idx` in the stride-0x24 table.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02072D98.c \
 *       --func func_02072D98 --addr 0x02072D98 --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern u8 g_0214E484[];

void func_02072D98(u32 idx, u8 val)
{
    g_0214E484[idx * 0x24] = val;
}
