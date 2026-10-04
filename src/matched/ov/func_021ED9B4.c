/*
 * function: func_021ED9B4
 * address:  0x021ED9B4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC08C  0x021EC08C  thumb  ov170
 *
 * One range call with fixed arguments.
 */



extern void func_021EC08C(char *p, int i, unsigned short a, unsigned short b, unsigned short c);
void func_021ED9B4(int a)
{
    func_021EC08C((char *)a, 2, 0x4b * 4, 0x22, 0);
}
