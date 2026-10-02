/*
 * function: func_021B9BF8
 * address:  0x021B9BF8
 * packet:   pkt_021B9BF8
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

extern int func_021B9CE0(char *, int);

u16 func_021B9BF8(char *p, int idx, int c)
{
    return ((u16 *)func_021B9CE0(p, idx))[(c << 1) + 7];
}
