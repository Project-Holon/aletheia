/*
 * function: func_021ED888
 * address:  0x021ED888
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EC000  0x021EC000  thumb  ov170
 *
 * Release slots 0 and 1 of the 0x9E74 array.
 */


extern void func_021EC000(char *, int, int);
void func_021ED888(char *p, int a)
{
    func_021EC000(p, 0, a);
    func_021EC000(p, 1, a);
}
