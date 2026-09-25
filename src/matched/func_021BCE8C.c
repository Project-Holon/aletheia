/*
 * function: func_021BCE8C
 * address:  0x021BCE8C
 * packet:   pkt_021BCE8C
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B404  0x0204B404  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern void func_0204B404(void *, u16 *, int);

void func_021BCE8C(void *a0, u16 a1, u16 a2, int a3)
{
    u16 tmp[2];
    tmp[0] = a1;
    tmp[1] = a2;
    func_0204B404(a0, tmp, a3);
}
