/*
 * function: func_021B81B0
 * address:  0x021B81B0
 * packet:   pkt_021B81B0
 * region:   ov173
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0207D658  0x0207D658  arm
 */

extern void func_0207D658(volatile unsigned short *p, int a, int b);

void func_021B81B0(int a)
{
    volatile unsigned short *p = (volatile unsigned short *)0x04001050;

    if (a == 1) {
        func_0207D658(p, 0x1e, -8);
    } else {
        *p = 0;
    }
}
