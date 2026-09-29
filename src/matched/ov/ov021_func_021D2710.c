/*
 * function: func_021D2710
 * address:  0x021D2710
 * packet:   pkt_ov021_021D2710
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0216BF9C  0x0216BF9C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02159B10(u32 a, u32 b);
extern u16 *func_02159AE8(u32 a, u32 b);
extern u32 func_0215A5DC(u32 a);
extern u32 func_020120F4(void);
extern u32 func_02012F08(u32 a);
extern u32 func_02012944(u32 a);
extern u16 func_0216BF9C(u32 a, u32 b, u32 c);

u32 func_021D2710(u32 a, u32 b)
{
    u32 r7;
    u16 *r5;
    u32 t;
    u32 r6;

    r7 = func_02159B10(a, b);
    r5 = func_02159AE8(a, b);
    func_0215A5DC(b);
    t = func_020120F4();
    r6 = func_02012F08(t);
    *r5 = func_0216BF9C(r6, r7, func_02012944(t));
    return 0;
}
