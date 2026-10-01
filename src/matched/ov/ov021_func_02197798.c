/*
 * function: func_02197798
 * address:  0x02197798
 * packet:   pkt_ov021_02197798
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021975D0  0x021975D0  thumb  ov021
 *   func_02012DAC  0x02012DAC  thumb
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02197738  0x02197738  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 func_021975D0(u8 *);
extern void func_02012DAC(u32);
extern void func_02196034(u8 *, void (*)(), u32);
extern void func_02197738();

void func_02197798(u8 *a)
{
    if (func_021975D0(a) != 0) {
        func_02012DAC(*(u32 *)(a + 0x30));
        func_02196034(a, func_02197738, 0x78E);
    }
}
