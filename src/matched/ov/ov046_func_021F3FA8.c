/*
 * function: func_021F3FA8
 * address:  0x021F3FA8
 * packet:   pkt_ov046_021F3FA8
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE4B4  0x021BE4B4  thumb  ov203
 *   func_021F4064  0x021F4064  thumb  ov046
 */

typedef unsigned int u32;
extern void func_021BE4B4(char *ctx, int b, int c, u32 d);
extern void func_021F4064(u32, int, u32);

void func_021F3FA8(char *a, u32 b, u32 c)
{
    func_021BE4B4(a, 0, 15, c);
    func_021BE4B4(a, 0, 10, c);
    func_021BE4B4(a, 0, 11, c);
    func_021BE4B4(a, 0, 12, c);
    func_021BE4B4(a, 0, 13, c);
    func_021BE4B4(a, 0, 14, c);
    func_021F4064(b, 4, c);
    func_021F4064(b, 5, c);
    func_021F4064(b, 9, c);
    func_021F4064(b, 6, c);
}
