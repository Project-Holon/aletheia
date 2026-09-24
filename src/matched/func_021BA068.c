/*
 * function: func_021BA068
 * address:  0x021BA068
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BEFCC  0x021BEFCC  arm  ov114
 *   func_021BEFD8  0x021BEFD8  arm  ov114
 *
 *
 * Releases a resource id (>= 0) then tears the +0x3b4 object down.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BEFCC(void);
extern void func_021BEFD8(int);
extern void func_0215F638(int, int);

void func_021BA068(int a, int b, int c)
{
    func_021BEFCC();
    if (c >= 0)
        func_0215F638(c, 2);
    func_021BEFD8(a);
}
