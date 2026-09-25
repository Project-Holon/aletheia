/*
 * function: func_021B9C0C
 * address:  0x021B9C0C
 * packet:   pkt_021B9C0C
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9CE0  0x021B9CE0  thumb  ov225
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern int func_021B9CE0(char *);

u16 func_021B9C0C(char *p, void *unused, int c)
{
    return ((u16 *)func_021B9CE0(p))[(c << 1) + 8];
}
