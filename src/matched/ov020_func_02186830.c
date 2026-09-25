/*
 * function: func_02186830
 * address:  0x02186830
 * packet:   pkt_02186830
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02049250  0x02049250  arm
 */

void func_02049250(int a, int b);

void func_02186830(unsigned int *p, int b)
{
    func_02049250(*p, b + 0x22);
}
