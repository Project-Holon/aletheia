/*
 * function: func_021C602C
 * address:  0x021C602C
 * packet:   pkt_ov021_021C602C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021ADF94  0x021ADF94  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_02188CD0(u32 a);
extern u32 func_021ADF94(u32 a, void *b, u32 c, int d);
void func_021C602C(u8 *p)
{
    *(u32 *)(p + 0x30) = func_021ADF94(func_02188CD0(*(u32 *)(p + 8)), p + 0x40, *(u8 *)(p + 0x58), *(u32 *)(p + 0x44) == *(u32 *)(p + 0x38));
}
