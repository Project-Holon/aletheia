/*
 * function: func_02072EC8
 * address:  0x02072EC8
 * packet:   pkt_02072EA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  0214E46C
 * symbols:
 *   g_0214E46C      0x0214E46C  data
 */

extern unsigned char g_0214E46C[];
int func_02072EC8(int a0)
{
    return *(unsigned short *)((char *)g_0214E46C + a0 * 0x24);
}
