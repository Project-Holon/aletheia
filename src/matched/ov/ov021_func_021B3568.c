/*
 * function: func_021B3568
 * address:  0x021B3568
 * packet:   pkt_ov021_021B3568
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008DAC  0x02008DAC  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_0200C29C  0x0200C29C  thumb
 *   func_0200DA98  0x0200DA98  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0200C29C(u32);
extern void func_0200DA98(u32, u16);
extern void func_02008DAC(u32, u32, u32);
extern void func_02008DF0(u32, u32);

void func_021B3568(u8 *w, u32 b)
{
    if (w[0x163] == 0) {
        func_0200C29C(*(u32 *)(w + 0xC));
        func_02008DAC(*(u32 *)(w + 0x14), 0x16, b);
    } else {
        func_0200DA98(*(u32 *)(w + 0x18), b);
        func_02008DAC(*(u32 *)(w + 0x14), 0x22, b);
    }
    func_02008DF0(*(u32 *)(w + 0x14), 0x15);
}
