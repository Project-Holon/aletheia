/*
 * function: func_021747F4
 * address:  0x021747F4
 * packet:   pkt_ov011_021747F4
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

int func_021736D8(void);
int func_020399A8(void);
int func_0203D3F8(int a, int b, int c, int d, int e, int f, int g, int h);

int func_021747F4(int a, int b)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8(func_020399A8(), b, 0x227, 8, a, 0, 0, 0);
}
