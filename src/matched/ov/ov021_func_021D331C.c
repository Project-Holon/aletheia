/*
 * unit:     yes
 * function: func_021D331C, func_021D335C
 * address:  0x021D331C
 * packet:   pkt_ov021_021D331C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D67C  0x0207D67C  arm
 * Addresses are Black-image addresses.
 * func_021D335C is an unlabelled leaf after the first function's pool.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern void func_0207D67C(u32 reg, int a, int b, int c, int d, int e);

void func_021D331C(const int *p, int sub)
{
    if (sub) {
        func_0207D67C(0x04000050, p[0], p[1], p[2], p[3], p[4]);
    } else {
        func_0207D67C(0x04001050, p[0], p[1], p[2], p[3], p[4]);
    }
}

void func_021D335C(u32 *p, int sub)
{
    if (sub) {
        *(volatile u16 *)0x04000052 = p[0] | (p[1] << 8);
    } else {
        *(volatile u16 *)0x04001052 = p[0] | (p[1] << 8);
    }
}
