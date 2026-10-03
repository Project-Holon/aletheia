/*
 * function: func_021D8F3C
 * address:  0x021D8F3C
 * packet:   pkt_021D8F3C
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9774  0x021B9774  thumb  ov114
 *   func_021B9838  0x021B9838  thumb  ov114
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern void func_021B9774(u8 *p);
extern void func_021B9838(u8 *p);

void func_021D8F3C(char *p)
{
    if (*(u32 *)(p + 0x10) != 0) {
        func_021B9774(*(void **)(p + 0x10));
        func_021B9838(*(void **)(p + 0x10));
        *(u32 *)(p + 0x10) = 0;
    }
}
