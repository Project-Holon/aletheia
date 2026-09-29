/*
 * function: func_02173E6C
 * address:  0x02173E6C
 * packet:   pkt_ov011_02173E6C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

int func_021736D8(void);
int func_0203D1C0(int a);
int func_020399A8(void);
int func_0203D3F8(int a, int b, int c, int d, int e, int f, int g, int h);

int func_02173E6C(int a, int b, int c)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    if (func_0203D1C0(c & 0xFF) == 0) {
        return 1;
    }
    return func_0203D3F8(func_020399A8(), (unsigned char)c, 0x211, 0x38, b, 0, 0, 0);
}
