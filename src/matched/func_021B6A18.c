/*
 * function: func_021B6A18
 * address:  0x021B6A18
 * packet:   pkt_021B6A18
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B6A88  0x021B6A88  thumb  ov172
 */

extern int func_021B6A88(int, int, int, void *);

int func_021B6A18(int a, int b, int c)
{
    func_021B6A88(a, c, b * 2, (void *)0x021C88E4);
    return b * 4;
}
