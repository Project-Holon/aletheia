/*
 * file:     fldeff_ripple_p09.c
 * unit:     yes
 * function: func_021C452C, func_021C457C, func_021C459C, func_021C4608, func_021C4628, func_021C4678, func_021C46A4
 * address:  0x021C452C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_021C1094  0x021C1094  thumb  ov021
 *   func_021C10A0  0x021C10A0  thumb  ov021
 *   func_0215A64C  0x0215A64C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_021A3364  0x021A3364  thumb  ov021
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021C1024  0x021C1024  thumb  ov021
 *   func_0215A644  0x0215A644  thumb  ov010
 *   func_020113D0  0x020113D0  thumb
 *   func_021C12C4  0x021C12C4  thumb  ov021
 *   func_021C12D0  0x021C12D0  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021C1228  0x021C1228  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021C9550  0x021C9550  thumb  ov021
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021D2418  0x021D2418  thumb  ov021
 *   func_021D2440  0x021D2440  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 */
struct Personal;
struct Ctx;
struct Obj00020;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern void *func_0201ADE4(u32 a, int b, u32 c);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern void *func_0215A64C(void *a);
extern int func_021C1094(void *x);
extern int func_021C10A0(u32 a);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern u16 func_0216D5F8(void *p);
extern u32 func_02188C98(u8 *p);
extern u16 func_0215A5CC(void *a0);
extern void func_021A3364(u32 *a, int b, int *out);
extern int func_021AB0D4(void *a, void *b);
extern u32 func_021C1024(void *a, u32 b, u32 c, u32 d);
extern void func_0215A644(void *p, u32 v);
extern void func_020113D0(char *p, int val);
extern int func_021C12C4(void *x);
extern void func_021C12D0(void *x);
extern u16 func_021A3050(u8 *p);
extern u32 func_02159B10(void *a, void *b);
extern u32 func_021C1228(void *a, u32 b, u32 c, u32 d);
extern u32 func_02188CD0(u8 *p);
extern void func_021C9550(u32 a, u32 b);
extern void *func_0215A5F4(void *p);
extern void *func_021D2418(void *a, u32 b);
extern void *func_021D2440(void *a, u32 b, u32 c);
extern void func_0215897C(void *a, void *b);
u8 func_021C452C(u32 a, u32 b, u32 c, u32 d);
int func_021C457C(void *a, void *b);
u32 func_021C459C(u32 a, u32 b);
int func_021C4608(void *a, void *b);
u32 func_021C4628(u32 a, void *b);
int func_021C4678(void *a, void *b);
int func_021C46A4(void *a, void *b);


u8 func_021C452C(u32 a, u32 b, u32 c, u32 d)
{
    u32 s[3];
    u32 x = (u32)func_0201ADE4(a, b, d);
    u32 i;

    s[0] = func_0201AE1C((const struct Personal *)x, 0x1a);
    s[1] = func_0201AE1C((const struct Personal *)x, 0x1b);
    s[2] = func_0201AE1C((const struct Personal *)x, 0x1c);
    func_0201AE14((void *)x);
    for (i = 0; i < 3; i++) {
        if (c == s[i])
            break;
    }
    if (i >= 3)
        i = 0;
    return i;
}


/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
int func_021C457C(void *a, void *b)
{
    void *x = func_0215A64C(b);

    if (func_021C1094(x) == 1) {
        func_021C10A0((u32)x);
        return 1;
    }
    return 0;
}


u32 func_021C459C(u32 a, u32 b)
{
    u32 buf[3];
    u32 z, w, t;
    void *x;
    void *y;

    x = func_0201210C(func_0215A5DC((void *)b));
    y = func_02188CB4((void *)x);
    z = func_0216D5F8(func_021A3074(y));
    x = (void *)func_02188C98(x);
    w = func_0215A5CC((void *)b);
    func_021A3364(y, z, (int *)buf);
    t = func_021AB0D4(x, buf);
    t = func_021C1024(y, z, t, w);
    func_0215A644((void *)b, t);
    func_020113D0((char *)a, (int)func_021C457C);
    return 1;
}


int func_021C4608(void *a, void *b)
{
    void *x = func_0215A64C(b);

    if (func_021C12C4(x) == 1) {
        func_021C12D0(x);
        return 1;
    }
    return 0;
}


u32 func_021C4628(u32 a, void *b)
{
    u32 w, y, t;
    void *x;

    w = func_0215A5CC(b);
    x = func_02188CB4(func_0201210C(func_0215A5DC((void *)b)));
    y = func_021A3050(x);
    t = func_02159B10((void *)a, (void *)b);
    t = func_021C1228(x, y, t, w);
    func_0215A644((void *)b, t);
    func_020113D0((char *)a, (int)func_021C4608);
    return 1;
}


/*
 * Refreshes the field object from the day-care state (EXACT*: pad).
 */
int func_021C4678(void *a, void *b)
{
    void *g = func_0201210C(func_0215A5DC(b));
    void *h = func_021A3074(func_02188CB4((void *)g));

    func_021C9550((u32)h, func_02188CD0(g));
    return 0;
}


/*
 * The shared func_0215897C call is written out in every arm and
 * cross-jumped by the compiler; a result local merged after the if chain
 * spills z instead of b.
 */
int func_021C46A4(void *a, void *b)
{
    u32 t;
    void *y;
    void *x;
    void *z;

    x = func_0215A5DC(b);
    y = func_0201210C(x);
    z = func_0215A5F4(b);
    t = func_02159B10(a, b);
    if (t == 0)
        func_0215897C(z, func_021D2418(x, (u32)y));
    else if (t == 1)
        func_0215897C(z, func_021D2440(x, (u32)y, 0));
    else
        func_0215897C(z, func_021D2440(x, (u32)y, 1));
    return 1;
}
