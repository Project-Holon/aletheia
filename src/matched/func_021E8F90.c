/*
 * function: func_021E8F90
 * address:  0x021E8F90
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Same body as func_021E8F60 with the first four arguments zero;
 * the state word goes to +0xA188, return 2.
 */

extern void func_0202208C(int, int, int, int, int, int, int);


int func_021E8F90(void *p, int a)
{
    func_0202208C(0, 0, 0, 0, 6, 1, 0x4c);
    *(int *)(*(int *)((char *)p + 0x2c) + 0xA188) = a;
    return 2;
}
