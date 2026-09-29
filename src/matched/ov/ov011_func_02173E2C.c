/*
 * function: func_02173E2C
 * address:  0x02173E2C
 * packet:   pkt_ov011_02173E2C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_02176200  0x02176200  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 */

int func_021736D8(void);
void func_02176200(char *a);
int func_020399A8(void);
int func_0203D3A8(int a, int b, int c, int d);

int func_02173E2C(char *a, int b)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    func_02176200(a + 0x1AC);
    return func_0203D3A8(func_020399A8(), 0x210, 0x30, b);
}
