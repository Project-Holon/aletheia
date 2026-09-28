/*
 * function: func_02011014
 * address:  0x02011014
 * packet:   pkt_02011014
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_02146208      0x02146208  data
 *   g_02146228      0x02146228  data
 */

extern unsigned char g_02146208[];
extern unsigned char g_02146228[];
int func_02011014(int a0)
{
    if (g_02146208[0x17] != 0x30)
        a0 += *(unsigned short *)(g_02146228 + 8);
    return a0;
}
