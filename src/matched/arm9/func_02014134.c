/*
 * function: func_02014134
 * address:  0x02014134
 * packet:   pkt_02014134
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014134.c \
 *       --func func_02014134 --addr 0x02014134 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;
typedef signed int s32;

extern u32  func_02014274(u32 a);
extern u8 func_0201441C(int i);

void func_02014134(u8 *p, u16 b, u16 c, u16 d, u16 e, u16 f, u16 g, s16 h)
{
    *(u32 *)p = 0;
    *(u16 *)(p + 4) = b;
    *(u16 *)(p + 6) = c;
    *(u16 *)(p + 8) = d;
    *(u16 *)(p + 0xa) = e;
    *(u32 *)(p + 0xc) = 1;
    *(u8 *)(p + 0x12) = 1;
    *(u16 *)(p + 0x10) = f;
    *(u16 *)(p + 0x16) = g;
    *(u16 *)(p + 0x14) = h;
    *(u8 *)(p + 0x13) = func_0201441C(func_02014274(d));
}
