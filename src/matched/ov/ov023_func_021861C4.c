/*
 * function: func_021861C4
 * address:  0x021861C4
 * packet:   pkt_ov023_021861C4
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020457B0(u32 n, u32 heap);
extern void func_02045CAC(void *a, u32 b, void *c);
extern void func_0201F250(void *a, void *b, void *c);
extern void func_02045808(void *p);
extern void *func_02045770(void *p);
extern void func_02043B5C(void *p, u32 v);
extern void func_0201F73C(void *p, u32 a, u32 b, u32 c);
extern void func_0201CE48(void *h);
extern void func_0201C724(void *a, void *bmp, u32 x, u32 y, void *text, u32 f, u16 color);
extern u32 func_02012FFC(void);
extern void *func_0201CCE4(void *a0, u32 a1, u32 a2, void *a3, u32 a4, u32 a5, void *a6, u32 a7, u16 a8, u32 a9);
extern void func_02045334(void *p);
extern void func_02045374(void *p);
extern u32 func_02045730(void *p);
extern void func_020409B4(u32 layer);

void func_021861C4(u8 *w, u32 msg, int mode)
{
    void *str;
    void *t;
    void *p;

    str = func_020457B0(0x50, 0x28);
    func_02045CAC(*(void **)(w + 0x14), msg, str);
    func_0201F250(*(void **)(w + 0x10), *(void **)(w + 0x30), str);
    func_02045808(str);
    func_02043B5C(func_02045770(*(void **)(w + 0x11C)), 15);
    func_0201F73C(*(void **)(w + 0x11C), 0, 1, 10);
    if (*(void **)(w + 0x16C) != 0) {
        func_0201CE48(*(void **)(w + 0x16C));
        *(void **)(w + 0x16C) = 0;
    }
    if (mode == 0) {
        t = *(void **)(w + 0x168);
        func_0201C724(t, func_02045770(*(void **)(w + 0x15C)), 0, 0, *(void **)(w + 0x30), *(u32 *)(w + 0xC), 0x44F);
        *(u8 *)(w + 0x160) = 1;
    } else {
        *(void **)(w + 0x16C) = func_0201CCE4(*(void **)(w + 0x11C), 0, 0, *(void **)(w + 0x30),
                                              *(u32 *)(w + 0xC), func_02012FFC(),
                                              *(void **)(w + 0x170), 1, 0x28, 0xF0F);
    }
    p = *(void **)(w + 0x11C);
    func_02045334(p);
    func_02045374(p);
    func_020409B4(func_02045730(p));
}
