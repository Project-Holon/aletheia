/*
 * function: func_021BA1EC
 * address:  0x021BA1EC
 * packet:   pkt_021BA1EC
 * region:   ov220
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Constructor pair: builds the head then the tail field.
 *
 * symbols:
 *   func_021BA29C  0x021BA29C  thumb  ov220
 *   func_021BA308  0x021BA308  thumb  ov220
 *
 * Addresses are Black-image addresses.
 */

extern void func_021BA29C(void *);
extern void func_021BA308(void *);

void func_021BA1EC(void *unused, char *p)
{
    func_021BA29C(p);
    func_021BA308(p + 4);
}
