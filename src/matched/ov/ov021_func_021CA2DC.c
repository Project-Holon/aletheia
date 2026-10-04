/*
 * function: func_021CA2DC
 * address:  0x021CA2DC
 * packet:   pkt_ov021_021CA2DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Refreshes the panel for kinds 0 and 4; kind 4 also pushes the kind and the next page number and relinks +0x74 to +0x70.
 *
 * symbols:
 *   func_021CA4C0  0x021CA4C0  thumb
 *   func_0200D914  0x0200D914  thumb
 *   func_0200DA54  0x0200DA54  thumb
 *   func_0200DC94  0x0200DC94  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021CA4C0(u8 *p, u32 unused, int flag);
struct Blk1AC;
struct Blk3C;
struct Src;
extern void func_0200D914(struct Blk3C *p, u32 id, const void *src);
extern u16 func_0200DA54(struct Blk3C *p);
extern void func_0200DC94(struct Blk1AC *p, const struct Src *q);

void func_021CA2DC(u8 *p, u32 h, int flag, u16 v)
{
    u8 b;

    switch (p[9]) {
    case 0:
        func_021CA4C0(p, h, 0);
        break;
    case 1:
        break;
    case 4:
        func_021CA4C0(p, h, 1);
        b = p[9];
        func_0200D914((struct Blk3C *)(*(u32 *)(p + 0x70)), 0, &b);
        b = func_0200DA54((struct Blk3C *)(*(u32 *)(p + 0x70))) + 1;
        func_0200D914((struct Blk3C *)(*(u32 *)(p + 0x70)), 1, &b);
        func_0200DC94((struct Blk1AC *)(*(u32 *)(p + 0x74)), (const struct Src *)(*(u32 *)(p + 0x70)));
        break;
    }
}
