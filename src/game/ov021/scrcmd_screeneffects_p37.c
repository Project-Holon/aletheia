/*
 * file:     scrcmd_screeneffects_p37.c
 * unit:     yes
 * function: func_021B1D20, func_021B1D64, func_021B1DEC, func_021B1E74
 * address:  0x021B1D20
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A2F48  0x021A2F48  thumb  ov021
 *   func_021A2F54  0x021A2F54  thumb  ov021
 *   func_020113D0  0x020113D0  thumb
 *   func_021B1CFC  0x021B1CFC  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021C78DC  0x021C78DC  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_0215A5EC  0x0215A5EC  thumb
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 */
struct Stream;
struct Obj00020;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern u16 func_02011330(struct Stream *s);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A2F48(u8 *p, u32 a1);
extern int func_021A2F54(u8 *p);
extern void func_020113D0(char *p, int val);
extern int func_021B1CFC(u32 a, u32 b, u32 c, u32 d);
extern u32 func_02188D38(u8 *p);
extern unsigned int func_02159B10(void *a, void *b);
extern void *func_021A3074(unsigned char *p);
extern u32 func_021C78DC(u32, int, void *, void *);
extern void func_021C6DE0(u8 *p, u32 *a, u32 b);
extern u32 func_0215A5EC(u32);
extern void *func_0216DEE0(void *a0);
int func_021B1D20(u32 a, u32 b);
int func_021B1D64(u32 a, u32 b);
int func_021B1DEC(u32 a, u32 b);
int func_021B1E74(u32 a);


/*
 * Addresses are Black-image addresses.
 */
int func_021B1D20(u32 a, u32 b)
{
    u32 *e;
    u32 v;
    void *o;

    e = (u32 *)func_02158F58((int)func_0215A5F4((void *)b));
    v = func_02011330((struct Stream *)a);
    o = func_02188CB4((struct Obj00020 *)e[1]);
    func_021A2F48(o, v);
    if (func_021A2F54(o) == 1)
        return 0;
    func_020113D0((char *)a, (int)func_021B1CFC);
    return 1;
}


int func_021B1D64(u32 a, u32 b)
{
    struct { int x, y, z; } v;
    u32 x;
    u32 y;
    int neg;
    int q;
    int p;
    int z;
    int zero;
    void *w;

    x = ((u32 *)func_02158F58((int)func_0215A5F4((void *)b)))[1];
    y = func_02188D38((u8 *)x);
    neg = func_02159B10((void *)a, (void *)b);
    p = func_02159B10((void *)a, (void *)b);
    q = func_02159B10((void *)a, (void *)b);
    z = func_02159B10((void *)a, (void *)b);
    if (neg != 0)
        p = -p;
    if (z == 0) {
        zero = 0;
        v.x = zero;
        v.y = -q << 12;
        v.z = zero;
    } else {
        zero = 0;
        v.x = zero;
        v.y = q << 12;
        v.z = zero;
    }
    w = func_021A3074(func_02188CB4((void *)x));
    func_021C6DE0((u8 *)y, (u32 *)func_021C78DC(x, p, &v, w), 0);
    return 0;
}


int func_021B1DEC(u32 a, u32 b)
{
    struct { int x, y, z; } v;
    u32 x;
    u32 y;
    int neg;
    int q;
    int p;
    int z;
    int zero;
    void *w;

    x = ((u32 *)func_02158F58((int)func_0215A5F4((void *)b)))[1];
    y = func_02188D38((u8 *)x);
    neg = func_02159B10((void *)a, (void *)b);
    p = func_02159B10((void *)a, (void *)b);
    q = func_02159B10((void *)a, (void *)b);
    z = func_02159B10((void *)a, (void *)b);
    if (neg != 0)
        p = -p;
    if (z == 0) {
        zero = 0;
        v.x = zero;
        v.y = -q << 12;
        v.z = zero;
    } else {
        zero = 0;
        v.x = zero;
        v.y = q << 12;
        v.z = zero;
    }
    w = func_021A3074(func_02188CB4((void *)x));
    func_021C6DE0((u8 *)y, (u32 *)func_021C78DC(x, p, &v, w), 0);
    return 0;
}


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0215A5EC (0x0215A5EC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B1E74(u32 a)
{
return (int)func_0216DEE0((void *)func_0215A5EC(a));
}
