/*
 * function: func_0220B1A0
 * address:  0x0220B1A0
 * packet:   pkt_0220B1A0
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220B188 0x0220B188 thumb
 *   func_020452E8 0x020452E8 arm
 */

extern void func_0220B188(char *a);
extern void func_020452E8(int);

void func_0220B1A0(char *a)
{
    func_0220B188(a);
    func_020452E8(*(int *)(a + 0x24));
}
