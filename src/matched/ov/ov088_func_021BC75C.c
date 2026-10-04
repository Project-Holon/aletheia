/*
 * function: func_021BC75C
 * address:  0x021BC75C
 * packet:   pkt_ov088_021BC75C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045374  0x02045374  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045334  0x02045334  arm
 *   func_02045C04  0x02045C04  arm
 *   func_021BC870  0x021BC870  thumb  ov088
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

extern u32 func_02045B38(u32, u32, u32, u32);
extern u32 func_020450F0(int, int, u8, int, int, int, int);
extern void func_02045374(u32 win);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(u32 win, u32 c);
extern u32 func_02045EC0(u32 a, u32 b);
extern void func_0201F73C(u32 desc, u32 kind, u16 base, u32 pal);
extern void func_0201C7A4(u32 x, s16 y, s16 z, u32 s, u32 w);
extern void func_02045808(u32 a);
extern void func_02045334(u32 win);
extern void func_02045C04(u32 a);
extern void func_021BC870(u8 *p);

#define W(o) (*(u32 *)(p + (o)))

void func_021BC75C(u8 *p)
{
    u32 arc;
    u32 s;
    u8 i;
    u8 *q;

    arc = func_02045B38(0, 2, 0xab, 0x39);
    p[0] = 0;
    W(0xc) = func_020450F0(5, 1, 0x13, 0x1d, 4, 0, 1);
    func_02045374(W(0xc));
    func_02043B5C((u32)func_02045770((struct Descriptor *)W(0xc)), 0xf);
    s = func_02045EC0(arc, W(4));
    func_0201F73C(W(0xc), 0, 1, 1);
    func_0201C7A4((u32)func_02045770((struct Descriptor *)W(0xc)), 2, 2, s, W(8));
    func_02045808(s);
    func_02045334(W(0xc));
    for (i = 0; i < 2; i++) {
        q = p + i * 4;
        *(u32 *)(q + 0x10) = func_020450F0(1, 6, i * 4 + 0xc, 0x14, 2, 0, 1);
        func_02045374(*(u32 *)(q + 0x10));
        func_02043B5C((u32)func_02045770((struct Descriptor *)*(u32 *)(q + 0x10)), 0xf);
        s = func_02045EC0(arc, i + 5 + W(4) * 2);
        func_0201C7A4((u32)func_02045770((struct Descriptor *)*(u32 *)(q + 0x10)), 2, 2, s, W(8));
        func_02045808(s);
        func_02045334(*(u32 *)(q + 0x10));
    }
    func_02045C04(arc);
    func_021BC870(p);
}
