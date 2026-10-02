/*
 * function: func_021BC508
 * address:  0x021BC508
 * packet:   pkt_021BC508
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC520 0x021BC520  thumb  ov208
 *
 * Zeroes +8, +0xC and +0x10, then tail-calls func_021BC520 with both arguments.
 */

extern void func_021BC520(int flag, int *p);

void func_021BC508(int flag, int *p)
{
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    func_021BC520(flag, p);
}
