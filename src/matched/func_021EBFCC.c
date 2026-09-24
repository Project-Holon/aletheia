/*
 * function: func_021EBFCC
 * address:  0x021EBFCC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EBFA8  0x021EBFA8  thumb  ov170
 *
 * Release-and-flag slot i of the 0x9E74 array.
 */


extern void func_021EBFA8(char *);
extern void func_0204B92C(int, int);
void func_021EBFCC(char *p, int i)
{
    func_021EBFA8(p);
    func_0204B92C(*(int *)(p + i * 4 + 0x9E74), 1);
}
