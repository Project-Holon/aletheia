/*
 * function: func_0217EF70
 * address:  0x0217EF70
 * packet:   pkt_ov018_0217EF70
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020413B0  0x020413B0  arm
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern void func_020413B0(u32 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02045374(int);
extern void func_02041B6C(u32 bit);

void func_0217EF70(int *p, int x)
{
    func_020413B0(7, 0, 2, 0x20, 0x10, (u8)(x + 5));
    func_020413B0(6, 0, 2, 0x20, 0x10, (u8)(x + 1));
    if (p[0x44 / 4] != 0) {
        func_02045374(p[0x44 / 4]);
        func_02045374(p[0x4c / 4]);
    }
    func_02041B6C(7);
    func_02041B6C(6);
    *((u8 *)p + 0x105) = x;
}
