/*
 * function: func_02173D2C
 * address:  0x02173D2C
 * packet:   pkt_ov011_02173D2C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021736D8  0x021736D8  thumb  ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 */

int func_021736D8(int a0);
int func_020399A8(void);
int func_0203D3A8(int a0, int a1, int a2, void *a3);

int func_02173D2C(int a0, int a1)
{
    if (func_021736D8(a0) == 0) {
        return 0;
    }
    return func_0203D3A8(func_020399A8(), 0x20E, 4, &a1);
}
