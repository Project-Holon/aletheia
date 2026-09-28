/*
 * function: func_021B9A58
 * address:  0x021B9A58
 * packet:   pkt_021B9A58
 * region:   ov224
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9B08  0x021B9B08  thumb  ov224
 *   func_021B9B74  0x021B9B74  thumb  ov224
 *
 * Addresses are Black-image addresses.
 */

extern void func_021B9B08(void *);
extern void func_021B9B74(void *);

void func_021B9A58(void *unused, char *p)
{
    func_021B9B08(p);
    func_021B9B74(p + 4);
}
