/*
 * function: func_021AEBB0
 * address:  0x021AEBB0
 * packet:   pkt_ov021_021AEBB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F8C  0x02158F8C  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A460  0x0215A460  thumb  ov010
 *   func_0215A4B4  0x0215A4B4  thumb  ov010
 *   func_0215A4A0  0x0215A4A0  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern u32 func_0215A5F4(u32 a);
extern u32 func_02158F8C(void);
extern u16 *func_02159AE8(u32 a, u32 b);
extern u32 func_0215A460(u32 a);
extern u32 func_0215A4B4(u32 a);
extern u32 func_0215A4A0(u32 a);

int func_021AEBB0(u32 a, u32 b)
{
    u32 h;
    u16 *x, *y, *z;
    u32 v0, v1, v2;

    func_0215A5F4(b);
    h = func_02158F8C();
    x = func_02159AE8(a, b);
    y = func_02159AE8(a, b);
    z = func_02159AE8(a, b);
    if ((u16)func_0215A4B4(func_0215A460(h)) == 0) {
        v0 = 0;
        v1 = 2;
        v2 = 24;
    } else if ((u16)func_0215A4A0(h) == 0) {
        v0 = 3;
        v1 = 5;
        v2 = 6;
    } else {
        v0 = 7;
        v1 = 9;
        v2 = 10;
    }
    *x = v0;
    *y = v1;
    *z = v2;
    return 0;
}
