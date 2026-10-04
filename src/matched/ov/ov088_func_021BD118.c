/*
 * function: func_021BD118
 * address:  0x021BD118
 * packet:   pkt_ov088_021BD118
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02013080  0x02013080  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_02045CAC(u32 a0, u32 a1, u32 a2);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(int, int);
extern void func_0201F73C(u32 h, u32 a, u32 b, u32 c);
extern signed char func_02013080(u32 idx);
extern int func_0201CCE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a5, u32 a6, u32 a7,
                          u32 a8, u16 a9, u16 a10);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(int);
extern int func_02045730(int);
extern void func_02041B6C(u32 bit);

void func_021BD118(int *p, u32 mode)
{
    int t;

    func_02045CAC(p[2], mode, p[4]);
    func_02043B5C((int)func_02045770((struct Descriptor *)p[7]), 15);
    func_0201F73C(p[7], 2, 1, 14);
    p[5] = func_0201CCE4(p[7], 0, 0, p[4], p[1], func_02013080(0), p[6], 10, 0x81, 15);
    p[10] = 0;
    t = p[7];
    func_02045334((struct Descriptor *)t);
    func_02045374(t);
    func_02041B6C(func_02045730(t));
}
