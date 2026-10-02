/*
 * function: func_021B9CE0
 * address:  0x021B9CE0
 * packet:   pkt_021B9CE0
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9CF0  0x021B9CF0  thumb  ov225
 *
 * Addresses are Black-image addresses.
 */

extern int func_021B9CF0(char *, int);

int func_021B9CE0(char *p, int idx)
{
    return func_021B9CF0(p, idx) + *(int *)p;
}
