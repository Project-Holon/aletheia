/*
 * function: func_021B44CC
 * address:  0x021B44CC
 * packet:   pkt_ov021_021B44CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_0201C724 0x0201C724 thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern void func_0201C7D0(u32 a, s16 b, s16 c, u32 d, u32 e, u32 f);
extern void func_0201C724(u32 a, u32 b, s16 c, s16 d, u32 e, u32 f, u32 g);

void func_021B44CC(u32 a, u32 b, int c, int d, u32 e, u32 f, u16 g)
{
    if (d <= 8) {
        func_0201C7D0(b, c, d, e, f, g);
    } else {
        func_0201C724(a, b, c, d, e, f, g);
    }
}
