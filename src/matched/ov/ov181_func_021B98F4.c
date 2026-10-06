/*
 * function: func_021B98F4
 * address:  0x021B98F4
 * packet:   pkt_ov181_021B98F4
 * region:   ov181
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204335C  0x0204335C  arm
 *   func_020433E0  0x020433E0  arm
 *   d_021BABFC     0x021BABFC  data  a4
 */

typedef unsigned int   u32;
extern void func_0204335C(u32 keep);
struct DispVram;
extern void func_020433E0(const struct DispVram *c);
extern int  d_021BABFC[];

void func_021B98F4(void)
{
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021BABFC);
}
