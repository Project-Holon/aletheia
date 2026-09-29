/*
 * function: func_021BB7E8
 * address:  0x021BB7E8
 * packet:   pkt_ov091_021BB7E8
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_021BBA28  0x021BBA28  thumb  ov091
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02045EC0(u32 a, u32 b);
extern u32 func_020457B0(u32 a, u32 b);
extern void func_0201F250(u32 a, u32 b, u32 c);
extern void func_02045808(u32 a);
extern void func_021BBA28(u8 *a, u32 *s);
extern void func_0201C6EC(u32 a);
extern u32 func_02045770(u32 a);
extern void func_0201C724(u32 a, u32 b, int c, int d, u32 e, u32 f, u32 g);

void func_021BB7E8(u8 *a, u32 *s, u32 x)
{
    u32 t;
    u32 n;

    t = func_02045EC0(*(u32 *)(a + 0x134), x);
    if (s[11] != 0) {
        n = func_020457B0(0x100, *(u16 *)a);
        func_0201F250(s[11], n, t);
        func_02045808(t);
        t = n;
    }
    func_021BBA28(a, s);
    func_0201C6EC(s[10]);
    func_0201C724(s[10], func_02045770(s[1]), 1, 1, t, *(u32 *)(a + 0x138), 0x440);
    s[9] = 1;
    func_02045808(t);
}
