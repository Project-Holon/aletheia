/*
 * function: func_021B40A8
 * address:  0x021B40A8
 * packet:   pkt_ov021_021B40A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_020452E8  0x020452E8  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_0201C6EC(u32);
extern void func_0201C4C0(u32);
extern void func_020452E8(u32);

void func_021B40A8(u8 *w)
{
    int i;

    func_0201C6EC(*(u32 *)(w + 0x1B0));
    func_0201C4C0(*(u32 *)(w + 0x1B0));
    for (i = 0; i < 7; i++) {
        func_020452E8(*(u32 *)(w + 0x164 + i * 4));
    }
}
