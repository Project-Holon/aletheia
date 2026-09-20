/*
 * function: func_02073D5C
 * address:  0x02073D5C
 * packet:   pkt_02073D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 *
 * blocker:  +0018 ABS32 g_0214E9B4             -> unresolved: 0214E9B4 (data, from header) has no witness outside 02073D5C..02073D7C
 *
 * symbols:
 *   g_0214E9B4       0x0214E9B4  data
 *   g_0214E9FC       0x0214E9FC  data
 *
 * Clears the two words of the sequence/index pair to zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02073D5C.c \
 *       --func func_02073D5C --addr 0x02073D5C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 g_0214E9B4;
extern u32 g_0214E9FC;

void func_02073D5C(void)
{
    g_0214E9B4 = 0;
    g_0214E9FC = 0;
}
