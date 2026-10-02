/*
 * function: func_021740AC
 * address:  0x021740AC
 * packet:   pkt_ov011_021740AC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Handed as 0x021740AE; the function starts at the push {r0-r3} at 0x021740AC.
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

int func_021736D8(void);
int func_0203D1C0(unsigned char a);
int func_020399A8(void);
int func_0203D3F8(int a, unsigned char b, int c, int d, void *e, int f, int g, int h);

int func_021740AC(int a, int b, int c, ...)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    if (func_0203D1C0(c) == 0) {
        return 1;
    }
    return func_0203D3F8(func_020399A8(), c, 0x217, 4, &b, 0, 0, 0);
}
