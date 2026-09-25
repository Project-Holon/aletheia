/*
 * function: func_021BA94C
 * address:  0x021BA94C
 * packet:   pkt_021BA94C
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Destructor pair: tears down the tail field then the head.
 *
 * symbols:
 *   func_021BAA80  0x021BAA80  thumb  ov218
 *   func_021BAA18  0x021BAA18  thumb  ov218
 *
 * Addresses are Black-image addresses.
 */

extern void func_021BAA80(void *);
extern void func_021BAA18(void *);

void func_021BA94C(char *p)
{
    func_021BAA80(p + 4);
    func_021BAA18(p);
}
