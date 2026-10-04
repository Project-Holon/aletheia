/*
 * function: func_0219499C
 * address:  0x0219499C
 * packet:   pkt_ov021_0219499C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec3;
extern void func_0201CE48(struct Rec3 *p);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);

void func_0219499C(u8 *p, int i, u32 b, u32 c)
{
    u8 *e;

    e = p + 0x18 + i * 100;
    if (*(u32 *)(e + 8) != 0) {
        func_0201CE48((struct Rec3 *)(*(u32 *)(e + 8)));
        *(u32 *)(e + 8) = 0;
    }
    if (b != 0) {
        *(u32 *)(e + 0x60) = c;
        *(u32 *)(e + 0x14) = b;
        *(u32 *)(e + 8) = func_0201CCE4(*(u32 *)(e + 0xC), e[0x5C], e[0x5D], *(u32 *)(e + 0x14),
                                        *(u32 *)(p + 8), c, *(u32 *)(p + 0xC98), 0, *(u16 *)p, 15);
        *(u16 *)e = 4;
    }
}
