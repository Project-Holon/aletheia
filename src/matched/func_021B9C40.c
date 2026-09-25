/*
 * function: func_021B9C40
 * address:  0x021B9C40
 * packet:   pkt_021B9C40
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9CFC  0x021B9CFC  thumb  ov225
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern int func_021B9CFC(char *);

u16 func_021B9C40(char *p, void *unused, int c)
{
    return ((u16 *)func_021B9CFC(p))[c + 3];
}
