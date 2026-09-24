/*
 * function: func_021DC9C4
 * address:  0x021DC9C4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204335C  0x0204335C  arm  arm9
 *   func_020433E0  0x020433E0  arm  arm9
 *
 * Two calls after setting the first argument.
 */

extern void func_0204335C(int);
extern void func_020433E0(void *);

void func_021DC9C4(void)
{
    func_0204335C(0);
    func_020433E0((void *)0x021EF7CC);
}

