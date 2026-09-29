/*
 * function: func_021F7308
 * address:  0x021F7308
 * packet:   pkt_ov097_021F7308
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F72DC  0x021F72DC  thumb  ov097
 */

extern void func_021F72DC(int a, unsigned b, int c);

void func_021F7308(int a, unsigned b, int c)
{
    unsigned i;

    for (i = b; i < b + 3; i++) {
        func_021F72DC(a, i, c);
        func_021F72DC(a, i + 6, c);
        func_021F72DC(a, i + 12, c);
        func_021F72DC(a, i + 18, c);
    }
}
