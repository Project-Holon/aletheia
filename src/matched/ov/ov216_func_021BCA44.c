/*
 * function: func_021BCA44
 * address:  0x021BCA44
 * packet:   pkt_021BCA44
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BCAF4  0x021BCAF4  thumb  ov216
 *   func_021BCB98  0x021BCB98  thumb  ov216
 *
 * Addresses are Black-image addresses.
 */

extern void func_021BCAF4(void *);
extern void func_021BCB98(void *);

void func_021BCA44(void *unused, char *p)
{
    func_021BCAF4(p);
    func_021BCB98(p + 4);
}
