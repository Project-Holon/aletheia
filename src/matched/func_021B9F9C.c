/*
 * function: func_021B9F9C
 * address:  0x021B9F9C
 * packet:   pkt_021B9F9C
 * region:   ov221
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BA04C  0x021BA04C  thumb  ov221
 *   func_021BA0B8  0x021BA0B8  thumb  ov221
 *
 * Addresses are Black-image addresses.
 */

extern void func_021BA04C(void *);
extern void func_021BA0B8(void *);

void func_021B9F9C(void *unused, char *p)
{
    func_021BA04C(p);
    func_021BA0B8(p + 4);
}
