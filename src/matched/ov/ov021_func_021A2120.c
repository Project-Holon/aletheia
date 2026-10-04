/*
 * function: func_021A2120
 * address:  0x021A2120
 * packet:   pkt_ov021_021A2120
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A05D8  0x021A05D8  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
void func_021A05D8(u8 *a);

void func_021A2120(u32 *p, int x)
{
    if (x == 1)
        func_021A05D8((u8 *)p[2]);
}
