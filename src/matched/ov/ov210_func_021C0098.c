/*
 * function: func_021C0098
 * address:  0x021C0098
 * packet:   pkt_ov210_021C0098
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BFF30 0x021BFF30 thumb ov210
 * Addresses are Black-image addresses.
 */

extern void func_021BFF30(int p, unsigned a, unsigned b);

void func_021C0098(int p, unsigned a, unsigned b)
{
    func_021BFF30(p, b, 1);
    func_021BFF30(p, a, 1);
}
