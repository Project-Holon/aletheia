/*
 * function: func_021FFAEC
 * address:  0x021FFAEC
 * packet:   pkt_021FFAEC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B404  0x0204B404  arm

 *
 * Send a one-entry u16 table {(u16)(b - 8), c} to func_0204B404.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_0204B404(u32 a, u16 *t, int n);

void func_021FFAEC(u32 a, u16 b, u16 c)
{
    u16 t[2];

    t[0] = b;
    t[1] = c - 8;
    func_0204B404(a, t, 1);
}
