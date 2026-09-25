/*
 * function: func_021FB578
 * address:  0x021FB578
 * packet:   pkt_021FB578
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B800  0x0204B800  arm
 *   func_020259C4  0x020259C4  thumb
 */

extern void func_0204B800(int);
extern void func_020259C4(int, unsigned char);

void func_021FB578(int *p, unsigned char b)
{
    func_0204B800(p[0]);
    func_020259C4(p[1], (unsigned char)(b - 1));
}
