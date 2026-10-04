/*
 * function: func_020136AC
 * address:  0x020136AC
 * packet:   pkt_02013528
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020134F4     0x020134F4  thumb
 *   func_02013284     0x02013284  thumb
 *
 * Member 3 of the four-member family at 0x02013610..0x020136E0 - the same
 * two calls with the same object, differing only in the id handed to
 * func_020134F4 (3 here, and 0, 1, 2, 3 across the family).  The fifth
 * argument arrives on the stack.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020136AC.c \
 *       --func func_020136AC --addr 0x020136AC --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020134F4(u8 *p, u32 a, u32 id, u32 c, u16 d);
extern void func_02013284(u8 *o, u32 *a1, u32 n, u32 *dst, u32 v, u32 h);

void func_020136AC(u8 *p, u32 a, u32 b, u32 c, u16 d)
{
    func_020134F4(p, a, 3, b, d);
    func_02013284(p, (u32 *)a, 1, (u32 *)(p + 0x28), c, d);
}
