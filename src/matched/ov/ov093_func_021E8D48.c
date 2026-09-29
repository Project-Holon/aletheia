/*
 * function: func_021E8D48
 * address:  0x021E8D48
 * packet:   pkt_ov093_021E8D48
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E8CFC  0x021E8CFC  thumb  ov093
 *   func_021E8D04  0x021E8D04  thumb  ov093
 */
typedef unsigned char u8;
extern u8 func_021E8CFC(int v);
extern u8 func_021E8D04(int v);

int func_021E8D48(int a, int b)
{
    if (func_021E8CFC(a) == func_021E8CFC(b)) return 1;
    if (func_021E8CFC(a) == func_021E8D04(b)) return 1;
    if (func_021E8D04(a) == func_021E8CFC(b)) return 1;
    if (func_021E8D04(a) == func_021E8D04(b)) return 1;
    return 0;
}
