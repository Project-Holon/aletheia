/*
 * function: func_0202DA18
 * address:  0x0202DA18
 * packet:   pkt_0202DA18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_0202D61C(u32 a, u32 b);
extern void func_0204AC18(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

void func_0202DA18(u32 a, u32 b, u32 c, u32 d, u16 e)
{
    func_0204AC18(a, func_0202D61C(b, 0), c, d, 0, 1, e);
}
