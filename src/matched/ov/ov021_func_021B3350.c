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

typedef unsigned short u16;
struct Blk1AC;
struct Blk34;
extern u32 func_0200C274(struct Blk34 *p);
extern u16 func_0200DABC(struct Blk1AC *p);

void func_021B3350(u8 *w)
{
    if (w[0x163] == 0) {
        func_0200C274((struct Blk34 *)(*(u32 *)(w + 0xC)));
    } else {
        func_0200DABC((struct Blk1AC *)(*(u32 *)(w + 0x18)));
    }
}
