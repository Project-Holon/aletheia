/*
 * function: func_021CFD08
 * address:  0x021CFD08
 * packet:   pkt_ov021_021CFD08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_021CFDBC  0x021CFDBC  thumb  ov021
 *   func_0200973C  0x0200973C  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02009634  0x02009634  thumb
 *   func_02008530  0x02008530  thumb
 *   func_02012F38  0x02012F38  thumb
 *   func_02025B64  0x02025B64  thumb
 *   func_021CFD88  0x021CFD88  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020120F4(u32 a);
extern u32 func_02012EBC(u32 a);
extern u32 func_02009470(u32 a);
extern void func_021CFDBC(u32 a, u32 b, u32 c);
extern u32 func_0200973C(u32 a, u32 b);
extern u32 func_02008550(u32 a);
extern u32 func_02009634(u32 a, u32 b, u32 c);
extern u32 func_02008530(u32 a);
extern u8 *func_02012F38(u32 a);
extern int func_02025B64(u32 a);
extern int func_021CFD88(u32 a, u32 b, u32 c, u32 d, u32 e);

int func_021CFD08(u32 a, u32 b, u8 *c, int d, u32 e)
{
    u32 v, t, w, s, x, g, h;
    u32 flag;

    flag = 0;
    h = func_020120F4(b);
    g = func_02009470(func_02012EBC(h));
    if (d >= 5) {
        return 4;
    }
    x = ((u8 *)(c + d))[8];
    func_021CFDBC(a, h, x);
    v = func_0200973C(g, x);
    s = func_02008550(v);
    w = func_02009634(g, x, 4);
    t = func_02008530(v);
    if (func_02025B64(*func_02012F38(h))) {
        flag = 1;
    }
    return func_021CFD88(s, t, w, e, flag);
}
