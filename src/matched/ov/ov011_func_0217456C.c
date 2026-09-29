/*
 * function: func_0217456C
 * address:  0x0217456C
 * packet:   pkt_ov011_0217456C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Handed as 0x0217456E; the function starts at the push {r0-r3} at 0x0217456C.
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

int func_021736D8(void);
int func_020399A8(void);
int func_0203D3F8(int a, int b, int c, int d, void *e, int f, int g, int h);

int func_0217456C(int a, int b, int c, ...)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D3F8(func_020399A8(), b, 0x221, 4, &c, 0, 0, 0);
}
