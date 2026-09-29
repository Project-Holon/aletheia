/*
 * function: func_0217F188
 * address:  0x0217F188
 * packet:   pkt_ov019_0217F188
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_021916A8  0x021916A8  thumb  ov021
 *   d_021807F8     0x021807F8  data   ov019 a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02034714(const char *a, u32 b, const char *c);
extern void func_02045CAC(u32 a, u32 b, u32 c);
extern void func_0201F250(u32 a, u32 b, u32 c);
extern void func_021916A8(u32 a, u32 b, u32 c, u32 d);
extern u32 d_021807F8[];

void func_0217F188(char *p, u32 arg)
{
    if (*(u32 *)(p + 0x280c) == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    func_02045CAC(*(u32 *)(p + 0x2808), arg, *(u32 *)(p + 0x2820));
    func_0201F250(*(u32 *)(p + 0x2804), *(u32 *)(p + 0x2824), *(u32 *)(p + 0x2820));
    func_021916A8(*(u32 *)(p + 0x280c), 0, 0, *(u32 *)(p + 0x2824));
    *(u8 *)(p + 0x2828) = 1;
}
