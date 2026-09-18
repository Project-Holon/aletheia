/*
 * function: func_02072D98
 * address:  0x02072D98
 * packet:   pkt_02072A44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  0214E484
 * symbols:
 *   g_0214DEC0      0x0214DEC0  data
 *   g_0214E484      0x0214E484  data
 *   g_0214E47C      0x0214E47C  data
 *   g_0214E480      0x0214E480  data
 */

extern char g_0214E484[];
void func_02072D98(int idx, int v)
{
    *(unsigned char *)(g_0214E484 + idx * 0x24) = (unsigned char)v;
}
