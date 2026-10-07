/*
 * file:     unit_021F36C0_p02.c
 * unit:     yes
 * function: func_021F3834, func_021F3888, func_021F38D4
 * address:  0x021F3834
 * region:   ov042
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_021F3980  0x021F3980  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 */
struct Ctx;
struct Big;
struct Desc;
struct Rec94;
struct Obj;
typedef unsigned int u32;

typedef unsigned char u8;

typedef signed int     s32;

typedef unsigned short u16;

extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F3980(void *a, int *st);
extern void *func_020124E4(struct Obj *p);
extern void func_021BE700(u32 a, int b, u16 c, u16 d, int e);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE6B8(u8 *p, int v);
extern void func_021BE6CC(int a, int b, int c, int d, int e);
extern int func_021BE748(u32 a);
int func_021F3834(void *a, u32 b, u32 c);
int func_021F3888(void *a, u32 b);
int func_021F38D4(void *a, int *st);


int func_021F3834(void *a, u32 b, u32 c)
{
    void *s;
    u8 *p;
    int r;

    s = func_0201210C((void *)a);
    func_02188D2C(s);
    p = (u8 *)func_021897BC(s, 1);
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(s))), 4);
    if (b >= 9) {
        return 0;
    }
    r = (int)func_020122C0(a, 0, func_021F38D4, 0);
    if (r != 0) {
        p[0] = b;
        p[2] = c;
    }
    return r;
}


int func_021F3888(void *a, u32 b)
{
    void *s;
    u8 *p;
    int r;

    s = func_0201210C((void *)a);
    func_02188D2C(s);
    p = (u8 *)func_021897BC(s, 1);
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(s))), 4);
    if (b > 3) {
        return 0;
    }
    r = (int)func_020122C0(a, 0, func_021F3980, 0);
    p[1] = b;
    return r;
}


int func_021F38D4(void *a, int *st)
{
    void *s;
    u32 t;
    u8 *p;
    u8 *e;
    u8 x;
    int z;

    s = func_0201210C(func_020124E4(a));
    t = func_02188D2C(s);
    p = (u8 *)func_021897BC(s, 1);
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(s))), 4);
    switch (*st) {
    case 0:
        x = p[0];
        z = 0;
        func_021BE700(t, 0, x, 0, 1);
        e = func_021BE674((char *)t, 0, x, 0);
        if (p[2] != 0) {
            func_021BE6B0(e, z);
            z = func_021BE748((u32)e);
        } else {
            func_021BE6B0(e, 1);
        }
        func_021BE6CC(t, 0, x, 0, z);
        func_021BE6B8(e, 0);
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
