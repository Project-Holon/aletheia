/*
 * function: func_021B3350
 * address:  0x021B3350
 * packet:   pkt_ov021_021B3350
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200C274  0x0200C274  thumb
 *   func_0200DABC  0x0200DABC  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_0200C274(u32);
extern void func_0200DABC(u32);

void func_021B3350(u8 *w)
{
    if (w[0x163] == 0) {
        func_0200C274(*(u32 *)(w + 0xC));
    } else {
        func_0200DABC(*(u32 *)(w + 0x18));
    }
}
