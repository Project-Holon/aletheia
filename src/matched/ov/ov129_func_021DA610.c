/*
 * function: func_021DA610
 * address:  0x021DA610
 * packet:   pkt_021DA610
 * region:   ov129
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DA578  0x021DA578  thumb
 */

extern void func_021DA578(int a, int b);

void func_021DA610(int a, int b)
{
    if (b == 1) {
        func_021DA578(a, 5);
        return;
    }
    if (b == 2)
        func_021DA578(a, 6);
}
