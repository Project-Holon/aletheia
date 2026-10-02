/*
 * function: func_02173A04
 * address:  0x02173A04
 * packet:   pkt_ov012_02173A04
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *
 * Varargs function whose listing label (func_02173A06) sits after the
 * push {r0-r3} home area; ov019 calls it at 0x02173A04.
 */

int func_020399A8(void);
int func_0203D3A8(void *a, unsigned int b, unsigned int c, void *d);

int func_02173A04(int a, int b, int c, int d)
{
    return func_0203D3A8(func_020399A8(), 0x1401, 4, &a);
}
