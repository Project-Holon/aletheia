/*
 * function: func_021CFDBC
 * address:  0x021CFDBC
 * packet:   pkt_ov021_021CFDBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02012F38  0x02012F38  thumb
 *   func_0200973C  0x0200973C  thumb
 *   func_0201F048  0x0201F048  thumb
 *   func_02025B64  0x02025B64  thumb
 *   func_02008570  0x02008570  thumb
 *   func_0201F094  0x0201F094  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02009634  0x02009634  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   func_02009628  0x02009628  thumb
 *   func_0201F198  0x0201F198  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02012EBC(u32 a);
extern u32 func_02009470(u32 a);
extern u8 *func_02012F38(u32 a);
extern u32 func_0200973C(u32 a, u32 b);
extern void func_0201F048(void *p, u32 i, u32 n);
extern u8 func_02025B64(u32 v);
extern u8 func_02008570(u32 a);
extern void func_0201F094(void *p, u32 i, u32 a, u32 n);
extern u32 func_02012944(u32 a);
extern void func_0201F02C(void *p, u32 i, u32 a);
extern u32 func_02009634(u32 a, u32 b, u32 c);
extern void func_0201EE60(void *p, u32 i, u16 v);
extern u8 func_02009628(u32 a);
extern void func_0201F198(void *p, u32 i, u8 v);
extern void func_0201EFA4(void *p, u32 i, u32 a, u32 b, u32 c, u32 d);

void func_021CFDBC(void *ws, u32 h, u32 x)
{
    u32 g, e, v;
    u8 k;

    g = func_02009470(func_02012EBC(h));
    k = *func_02012F38(h);
    e = func_0200973C(g, x);
    func_0201F048(ws, 0, k);
    if (func_02025B64(k)) {
        func_0201F094(ws, 1, k, func_02008570(e));
    }
    func_0201F02C(ws, 3, func_02012944(h));
    func_0201EE60(ws, 5, func_02009634(g, x, 0));
    func_0201F198(ws, 6, func_02009628(g));
    func_0201F02C(ws, 7, e);
    v = func_02009634(g, x, 3);
    if (v == 0) {
        v = 1;
    }
    func_0201EFA4(ws, 8, v, 3, 0, 1);
    func_0201EE60(ws, 9, func_02009634(g, x, 1));
    k = func_02009634(g, x, 2);
    func_0201F198(ws, 10, k);
}
