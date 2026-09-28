/*
 * function: func_021BA034
 * address:  0x021BA034
 * packet:   pkt_021BA034
 * region:   ov222
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BA0E4  0x021BA0E4  thumb  ov222
 *   func_021BA150  0x021BA150  thumb  ov222
 *
 * Addresses are Black-image addresses.
 */

extern void func_021BA0E4(void *);
extern void func_021BA150(void *);

void func_021BA034(void *unused, char *p)
{
    func_021BA0E4(p);
    func_021BA150(p + 4);
}
