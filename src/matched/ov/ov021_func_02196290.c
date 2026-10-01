/*
 * function: func_02196290
 * address:  0x02196290
 * packet:   pkt_ov021_02196290
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202F038  0x0202F038  thumb
 *   func_0202EE8C  0x0202EE8C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void func_0202F038(u32);
extern u32 func_0202EE8C(u32 a, u32 b, u32 c, u32 d, u32 e);

void func_02196290(u8 *a)
{
    if (*(u32 *)(a + 0x2E8) != 0) {
        func_0202F038(*(u32 *)(a + 0x2E8));
        *(u32 *)(a + 0x2E8) = 0;
    }
    *(u32 *)(a + 0x2E8) = func_0202EE8C(*(u32 *)(a + 0x2B8), *(u32 *)(a + 0x2B0), 15, 16, *(u16 *)(a + 0x10));
}
