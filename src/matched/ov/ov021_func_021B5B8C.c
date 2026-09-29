/*
 * function: func_021B5B8C
 * address:  0x021B5B8C
 * packet:   pkt_ov021_021B5B8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012F08  0x02012F08  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0200C11C  0x0200C11C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02159B10(u32 a, u32 b);
extern int func_0215B4AC(u32 a, u32 b, u32 *out);
extern u32 func_0215A5E4(u32 a);
extern u32 func_02012F08(u32 a);
extern u32 func_02017E1C(u32 a, u32 b, u32 c);
extern void func_0200C11C(u32 a, u32 b, u32 c, u32 d, u32 e);

int func_021B5B8C(u32 a, u32 b)
{
    u32 rec;
    u32 x;
    u16 v5, v6f, v4c, v6e;

    if (func_0215B4AC(b, func_02159B10(a, b), &rec) == 1) {
        x = func_02012F08(func_0215A5E4(b));
        v5 = func_02017E1C(rec, 5, 0);
        v6f = func_02017E1C(rec, 0x6f, 0);
        v4c = func_02017E1C(rec, 0x4c, 0);
        v6e = func_02017E1C(rec, 0x6e, 0);
        func_0200C11C(x, v5, v6f, v4c, v6e);
    }
    return 0;
}
