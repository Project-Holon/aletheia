/*
 * function: func_021F06E0
 * address:  0x021F06E0
 * packet:   pkt_ov032_021F06E0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F0684  0x021F0684  thumb  ov032
 *   func_02165C50  0x02165C50  thumb  ov010
 *   func_021F079C  0x021F079C  thumb  ov032
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021F0820  0x021F0820  thumb  ov032
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021F0684(u8 *p, u8 *a, u8 *b);
extern u32 func_02165C50(u32 x);
extern void func_021F079C(u8 *p, int k);
extern int func_021F0820(u32 x);

void func_021F06E0(u8 *p, u32 x, int y)
{
    u8 v[2];

    v[1] = 0;
    v[0] = 0;
    func_021F0684(p, &v[0], &v[1]);
    if (func_02165C50(x) != 2)
        func_021F079C(p, 1);
    if (p[0x59] != v[1] && v[1] == 0x14)
        func_021F079C(p, 2);
    if (*(u32 *)(p + 0x2d4) % 100 == 0)
        func_021F079C(p, 3);
    if (y == 0x1d && p[0x7b] == 0x1e)
        func_021F079C(p, 4);
    if (p[0x58] != v[0] && v[0] == 0x14)
        func_021F079C(p, 5);
    if (func_021F0820(*(u32 *)(p + 0x2d4)) != 0)
        func_021F079C(p, 6);
    p[0x58] = v[0];
    p[0x59] = v[1];
}
