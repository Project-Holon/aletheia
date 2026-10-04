/*
 * function: func_021DC910
 * address:  0x021DC910
 * packet:   pkt_021DC910
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204335C  0x0204335C  arm
 *   func_020433E0  0x020433E0  arm
 */

typedef unsigned int   u32;
extern void func_0204335C(u32 keep);
struct DispVram;
extern void func_020433E0(const struct DispVram *c);

void func_021DC910(void)
{
    func_0204335C(0);
    func_020433E0((const struct DispVram *)0x021DEB20);
}
