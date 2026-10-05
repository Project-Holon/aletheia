/*
 * function: func_021EBD78
 * address:  0x021EBD78
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EBA84  0x021EBA84  thumb  ov170
 *
 * Index 0x35 when the flag is clear, 0x36 when set.
 */


extern void func_021EBA84(char *, int, int);
void func_021EBD78(char *p, int b)
{
    if (b == 0)
        func_021EBA84(p, 0x35, 0x1b);
    else
        func_021EBA84(p, 0x36, 0x1b);
}
