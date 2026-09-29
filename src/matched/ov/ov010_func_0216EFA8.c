/*
 * function: func_0216EFA8
 * address:  0x0216EFA8
 * packet:   pkt_ov010_0216EFA8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021725D8  0x021725D8  data  ov010  a1
 */

typedef unsigned char u8;

extern u8 d_021725D8[][5];

int func_0216EFA8(int a, int b)
{
    if (b == 4)
        return 0;
    if (d_021725D8[a][b] == 0)
        return 1;
    return 0;
}
