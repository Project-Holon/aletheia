/*
 * function: func_02202670
 * address:  0x02202670
 * packet:   pkt_02202670
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 *
 * Encode one record through the two stage helpers and flush it to the writer.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern u32 func_02045EC0(u32 a, u32 b);
extern u32 func_020457B0(u32 a, u32 b);
extern void func_0201F250(u32 a, u32 b, u32 c);
extern void func_02045808(u32 a);

u32 func_02202670(u32 a, u32 b, u32 c, u32 d)
{
    u32 t1 = func_02045EC0(b, c);
    u32 t2 = func_020457B0(0x200, d);

    func_0201F250(a, t2, t1);
    func_02045808(t1);
    return t2;
}
