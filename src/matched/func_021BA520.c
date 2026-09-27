/*
 * function: func_021BA520
 * address:  0x021BA520
 * packet:   pkt_021BA520
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_0202CEBC  0x0202CEBC  thumb
 *   func_0202CC58  0x0202CC58  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32  func_02045770(void *p);
extern void func_02043B5C(u32 a, u32 b);
extern void func_02045334(void *a);
extern void func_0201C7D0(void *x, int y, int z, void *s, void *w, u32 v);
extern void func_0202CEBC(u32 a, int b, void *c);
extern void func_0202CC58(u32 a, int b);

void func_021BA520(u8 *a0, int a1, void *a2, int a3)
{
    func_02043B5C(func_02045770(*(void **)(a0 + 0x10 + a1 * 4)), 4);
    if (a3 == 0)
        func_0201C7D0((void *)func_02045770(*(void **)(a0 + 0x10 + a1 * 4)), 0, 0, a2,
                      *(void **)(a0 + 0xc), 0x3584);
    else
        func_0201C7D0((void *)func_02045770(*(void **)(a0 + 0x10 + a1 * 4)), 0, 0, a2,
                      *(void **)(a0 + 0xc), 0x2D44);
    func_02045334(*(void **)(a0 + 0x10 + a1 * 4));
    func_0202CEBC(*(u32 *)(a0 + 4), a1, *(void **)(a0 + 0x10 + a1 * 4));
    func_0202CC58(*(u32 *)(a0 + 4), a1);
}
