/*
 * function: func_021A2390
 * address:  0x021A2390
 * packet:   pkt_ov021_021A2390
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A01D4  0x021A01D4  thumb  ov021
 *   func_021A01FC  0x021A01FC  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
u8 func_021A01D4(u8 *p);
void func_021A01FC(u8 *p, u32 a, u32 b, u32 c);

void func_021A2390(u32 *p, int a, int b, int c)
{
    if (c == 1)
        func_021A01FC((u8 *)p[1], a, func_021A01D4((u8 *)p[1]), b);
}
