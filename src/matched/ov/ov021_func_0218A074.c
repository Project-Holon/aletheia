/*
 * function: func_0218A074
 * address:  0x0218A074
 * packet:   pkt_ov021_0218A074
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AA8F8  0x021AA8F8  thumb  ov021
 *   func_02189BD0  0x02189BD0  thumb  ov021
 *   func_021AA8EC  0x021AA8EC  thumb  ov021
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC5BC  0x021BC5BC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3550  0x021A3550  thumb  ov021
 *   func_021A356C  0x021A356C  thumb  ov021
 *   func_02189A70  0x02189A70  thumb  ov021
 *   func_021F3B10  0x021F3B10  thumb  ov053
 *   func_0218A6E8  0x0218A6E8  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188CE8(u8 *p);
extern void func_021AA8F8(void);
struct Obj00020;
extern int func_02189BD0(void *sys, struct Obj00020 *pos, int *outA, int *outB);
extern void func_021AA8EC(u8 *p);
extern u32 func_02188D20(u8 *p);
extern int func_021BC5BC(u8 *a);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3550(u32 *p, int a);
extern void func_021A356C(void **p);
extern u32 func_02189A70(u8 *p);
extern void func_021F3B10(void);
extern void func_0218A6E8(void *a, void *b);

int func_0218A074(void *a, int b)
{
    int u;
    int v;
    int r;
    void *p;
    void *q;

    p = func_0201210C(a);
    q = (void *)func_02188CE8(p);
    func_021AA8F8();
    r = func_02189BD0(a, (struct Obj00020 *)b, &u, &v);
    if (r != 0) {
        if (u != 0)
            func_021AA8EC(q);
        func_021BC5BC((u8 *)((void *)func_02188D20(p)));
        func_021A3550(func_02188CB4(p), v);
        func_021A356C(func_02188CB4(p));
        if (func_02189A70(p) != 0)
            func_021F3B10();
        func_0218A6E8(a, p);
    }
    return r;
}
