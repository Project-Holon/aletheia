/*
 * function: func_021BB860
 * address:  0x021BB860
 * packet:   pkt_ov091_021BB860
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
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02028470  0x02028470  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CD10  0x0201CD10  thumb
 *   func_021BB910  0x021BB910  thumb  ov091
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern u32 func_02045EC0(u32 a, u32 b);
extern u32 func_020457B0(u32 a, u32 b);
extern void func_0201F250(u32 a, u32 b, u32 c);
extern void func_02045808(u32 a);
extern void func_021BBA28(u8 *a, u32 *s);
extern void func_0201CE48(u32 a);
extern void func_02028470(void *a, u32 b);
extern signed char func_02012FFC(void);
extern u32 func_0201CD10(u32 a, s16 b, s16 c, u32 d, u32 e, u32 f, u32 g, u32 h,
                         u32 i, u32 j, u32 k);
extern int func_021BB910(int k);

void func_021BB860(u8 *a, u32 *s, u32 x, u32 y)
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
    if (s[3] != 0) {
        func_0201CE48(s[3]);
        func_02045808(s[4]);
    }
    s[8] = y;
    s[4] = t;
    func_02028470(s + 6, 6);
    s[3] = func_0201CD10(s[1], 0, 0, s[4], *(u32 *)(a + 0x138), func_02012FFC(), s[2], 0,
                         *(u16 *)a, 0xf, (u32)func_021BB910);
}
