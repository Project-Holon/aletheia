/*
 * function: func_021B99F4
 * address:  0x021B99F4
 * packet:   pkt_021B99F4
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Destructor pair: tears down the tail field then the head.
 *
 * symbols:
 *   func_021B9B28  0x021B9B28  thumb  ov225
 *   func_021B9AC0  0x021B9AC0  thumb  ov225
 *
 * Addresses are Black-image addresses.
 */

extern void func_021B9B28(void *);
extern void func_021B9AC0(void *);

void func_021B99F4(char *p)
{
    func_021B9B28(p + 4);
    func_021B9AC0(p);
}
