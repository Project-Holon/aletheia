/*
 * function: func_021BA96C
 * address:  0x021BA96C
 * packet:   pkt_021BA96C
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Constructor pair, parameter arrives in r1.
 *
 * symbols:
 *   func_021BAA1C  0x021BAA1C  thumb  ov218
 *   func_021BAA88  0x021BAA88  thumb  ov218
 *
 * Addresses are Black-image addresses.
 */

extern void func_021BAA1C(void *);
extern void func_021BAA88(void *);

void func_021BA96C(void *unused, char *p)
{
    func_021BAA1C(p);
    func_021BAA88(p + 4);
}
