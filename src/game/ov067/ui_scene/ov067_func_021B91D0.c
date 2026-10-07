/*
 * function: func_021B91D0
 * address:  0x021B91D0
 * packet:   pkt_ov067_021B91D0
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8FE4  0x021B8FE4  thumb
 *   func_021B90B8  0x021B90B8  thumb
 *   func_021B9138  0x021B9138  thumb
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

struct Ops {
    void (*fn)(void *a, int b, u8 *c, s16 d, int e);
};

struct S {
    u8 f0;
    u8 _1[0x20 - 1];
    struct Ops *f20;
    void *f24;
    u8 _28[0x38 - 0x28];
    u8 *f38;
    u8 _3c[0x46 - 0x3c];
    s8 f46;
    u8 _47[0x4c - 0x47];
    u16 f4c;
    u8 _4e[0x66 - 0x4e];
    s8 f66;
};

extern void func_021B8FE4(struct S *s, u32 a1, u32 a2);
extern void func_021B90B8(struct S *p, int a1, int a2);
extern void func_021B9138(struct S *p, int a1, int a2);

void func_021B91D0(struct S *p, int i, int a2)
{
    if (i >= 0 && i < p->f4c) {
        func_021B8FE4(p, i, p->f46);
        func_021B90B8(p, p->f46, a2);
        p->f20->fn(p->f24, i, p->f38 + p->f46 * 8, a2 * 8 - p->f66, 1);
    } else {
        func_021B9138(p, p->f0, a2);
    }
}
