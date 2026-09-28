/*
 * function: func_021B9A14
 * address:  0x021B9A14
 * packet:   pkt_ov225_021B9A14
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9AC4  0x021B9AC4  thumb  ov225
 *   func_021B9B30  0x021B9B30  thumb  ov225
 *
 * Addresses are Black-image addresses.
 */

extern void func_021B9AC4(void *);
extern void func_021B9B30(void *);

void func_021B9A14(void *unused, char *p)
{
    func_021B9AC4(p);
    func_021B9B30(p + 4);
}
