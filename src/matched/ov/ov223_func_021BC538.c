/*
 * function: func_021BC538
 * address:  0x021BC538
 * packet:   pkt_021BC538
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BC5E8  0x021BC5E8  thumb  ov223
 *   func_021BC654  0x021BC654  thumb  ov223
 *
 * Addresses are Black-image addresses.
 */

extern void func_021BC5E8(void *);
extern void func_021BC654(void *);

void func_021BC538(void *unused, char *p)
{
    func_021BC5E8(p);
    func_021BC654(p + 4);
}
