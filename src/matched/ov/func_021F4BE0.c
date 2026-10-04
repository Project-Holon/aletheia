/*
 * function: func_021F4BE0
 * address:  0x021F4BE0
 * packet:   pkt_021F4BE0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F4BF8  0x021F4BF8  thumb  ov135

 *
 * Forward four register arguments plus a zero and the u8 stack argument.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef void (*Fn)(void);
extern void func_021F4BF8(u8 *p, int b, int unused, int a, int c, u8 flag);

void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    func_021F4BF8((u8 *)a, b, c, d, 0, e);
}
