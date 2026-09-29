/*
 * function: func_02173DA0
 * address:  0x02173DA0
 * packet:   pkt_ov011_02173DA0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

int func_021736D8(void);
int func_020399A8(void);
int func_0203D3F8(int a, int b, int c, int d, int e, int f, int g, int h);

int func_02173DA0(int a, int b, int c)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D3F8(func_020399A8(), 0xFF, 0x20F, 0x28, b + c * 0x28, 0, 0, 1);
}
