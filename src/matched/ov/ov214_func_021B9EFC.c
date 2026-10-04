/*
 * function: func_021B9EFC
 * address:  0x021B9EFC
 * packet:   pkt_021B9EFC
 * region:   ov214
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9F10 0x021B9F10 thumb
 */

extern void func_021B9F10(int unused, char *b, int c, int d);

void func_021B9EFC(int *out, int a, int b, int c, int d)
{
    *out = 4;
    func_021B9F10(a, (char *)b, c, d);
}