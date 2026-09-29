/*
 * function: func_02191D88
 * address:  0x02191D88
 * packet:   pkt_ov021_02191D88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049624  0x02049624  arm
 *   func_02049B90  0x02049B90  arm
 */

typedef unsigned int u32;

extern void func_02049624(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02049B90(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);

void func_02191D88(u32 a, u32 b, u32 c, u32 d)
{
    if (c >= 4)
        c = 0;
    func_02049624(5, 6, a, 0x33, 0, 0, d);
    func_02049B90(5, 1, 0, c << 5, b << 5, 0x20, d);
}
