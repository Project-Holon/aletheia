/*
 * function: func_021BAF30
 * address:  0x021BAF30
 * packet:   pkt_021BAF30
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020310C4  0x020310C4  arm
 *   func_021BAF48  0x021BAF48  thumb  ov223
 *
 * Addresses are Black-image addresses.
 */

extern void func_020310C4(int);
extern void func_021BAF48(void *);

void func_021BAF30(int *p)
{
    func_020310C4(p[0x95]);
    func_021BAF48(p);
}
