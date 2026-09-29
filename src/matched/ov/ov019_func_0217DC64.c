/*
 * function: func_0217DC64
 * address:  0x0217DC64
 * packet:   pkt_ov019_0217DC64
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02008554  0x02008554  thumb
 *   func_02008550  0x02008550  thumb
 *   func_0217357C  0x0217357C  thumb  ov012
 */

typedef unsigned char  u8;

extern int func_02008554(int a);
extern int func_02008550(int a);
extern void func_0217357C(u8 *p, int a, int b, int c);

void func_0217DC64(u8 *base, int obj, int x)
{
    int a = func_02008554(obj);
    int b = func_02008550(obj);
    func_0217357C(base + 0x2844, x, a, (u8)b);
}
