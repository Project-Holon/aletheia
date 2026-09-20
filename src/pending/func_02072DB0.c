/*
 * function: func_02072DB0
 * address:  0x02072DB0
 * packet:   pkt_02072A44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocker:  0214E47C
 * symbols:
 *   g_0214DEC0      0x0214DEC0  data
 *   g_0214E484      0x0214E484  data
 *   g_0214E47C      0x0214E47C  data
 *   g_0214E480      0x0214E480  data
 */

extern char g_0214E47C[];
void func_02072DB0(int idx, int v)
{
    *(int *)(g_0214E47C + idx * 0x24) = (unsigned short)v;
}
