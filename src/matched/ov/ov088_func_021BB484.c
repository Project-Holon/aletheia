/*
 * function: func_021BB484
 * address:  0x021BB484
 * packet:   pkt_ov088_021BB484
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets the alpha-blend registers of both engines (main 0x04000050,
 * sub 0x04001050) for the title menu.
 *
 * symbols:
 *   func_0207D63C  0x0207D63C  arm
 */

extern void func_0207D63C(void *reg, int a, int b, int c, int d);

void func_021BB484(void)
{
    func_0207D63C((void *)0x04000050, 4, 8, 16, 3);
    func_0207D63C((void *)0x04001050, 2, 4, 16, 3);
}
