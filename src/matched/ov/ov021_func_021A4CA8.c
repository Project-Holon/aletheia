/*
 * function: func_021A4CA8
 * address:  0x021A4CA8
 * packet:   pkt_ov021_021A4CA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A4CF4  0x021A4CF4  thumb  ov021
 *   func_021A4FA8  0x021A4FA8  thumb  ov021
 *   func_021A5148  0x021A5148  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021A3974(u32);
extern void func_021A4CF4(u32, u32, u32);
extern void func_021A4FA8(u32, u32, u32);
extern void func_021A5148(u32, u32, u32);

void func_021A4CA8(u32 a, u32 b, u32 c)
{
    switch (func_021A3974(*(u32 *)(a + 12))) {
    case 0:
        func_021A4CF4(a, b, c);
        return;
    case 1:
        func_021A4FA8(a, b, c);
        return;
    case 2:
    case 3:
        func_021A5148(a, b, c);
        break;
    }
}
