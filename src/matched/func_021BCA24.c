/*
 * function: func_021BCA24
 * address:  0x021BCA24
 * packet:   pkt_021BCA24
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BCB90  0x021BCB90  thumb  ov216
 *   func_021BCAF0  0x021BCAF0  thumb  ov216
 *
 * Addresses are Black-image addresses.
 */

extern void func_021BCB90(void *);
extern void func_021BCAF0(void *);

void func_021BCA24(char *p)
{
    func_021BCB90(p + 4);
    func_021BCAF0(p);
}
