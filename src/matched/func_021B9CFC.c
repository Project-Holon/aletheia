/*
 * function: func_021B9CFC
 * address:  0x021B9CFC
 * packet:   pkt_021B9CFC
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9D0C  0x021B9D0C  thumb  ov225
 *
 * Addresses are Black-image addresses.
 */

extern int func_021B9D0C(char *);

int func_021B9CFC(char *p)
{
    return func_021B9D0C(p) + *(int *)(p + 8);
}
