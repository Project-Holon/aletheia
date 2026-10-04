/*
 * function: func_021A2F20
 * address:  0x021A2F20
 * packet:   pkt_ov021_021A2F20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021C0CA4  0x021C0CA4  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
u32 func_02188CFC(u8 *p);
int func_021C0CA4(int a, int b, int c, int d);

int func_021A2F20(u32 *p, int a, int b, int c)
{
    int r = 0;

    if (func_02188CFC((u8 *)p[0]) == 0)
        r = func_021C0CA4(p[2], a, b, c);
    return r;
}
