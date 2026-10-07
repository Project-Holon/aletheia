/*
 * file:     scrcmd_screeneffects_p05.c
 * unit:     yes
 * function: func_021AEDAC, func_021AEDE0
 * address:  0x021AEDAC
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
 *   func_02014024  0x02014024  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_02029984  0x02029984  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02028BA0  0x02028BA0  thumb
 *   func_02159144  0x02159144  thumb  ov010
 */
struct Sub02008C20Obj;
struct Ctx;
struct Stream;
struct BigObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct R { u32 f0; u32 f4; } R;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern int func_02158F58(int a0);
extern void *func_02012F2C(int *p);
extern u16 func_02188C9C(u8 *p);
extern int func_02014024(u32 a);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void *func_0215A5DC(void *a0);
extern u16 func_02011330(struct Stream *s);
extern void *func_02029984(void *a, u32 b);
extern void func_0215897C(void *vm, void *task);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02028BA0(u8 *o, u32 v);
extern void func_02159144(int n);
void func_021AEDAC(u32 a);
int func_021AEDE0(u32 a, u32 b);


void func_021AEDAC(u32 a)
{
    R *p = (R *)func_02158F58((int)func_0215A5F4((void *)a));
    u32 q = (u32)func_02012F2C(func_0215A5E4((void *)a));

    if (func_02014024(func_02188C9C((u8 *)p->f4)) != 0)
        func_02008DF0((struct Sub02008C20Obj *)q, 0x20);
}


/*
 * Addresses are Black-image addresses.
 */
int func_021AEDE0(u32 a, u32 b)
{
    void *x;
    void *y;

    x = func_0215A5DC((void *)b);
    y = func_0215A5F4((void *)b);
    func_0215897C(y, func_02029984(x, func_02011330((struct Stream *)a)));
    func_02028BA0((u8 *)func_02012A30((const struct BigObj *)func_020120F4(x)), 2);
    func_02159144(13);
    return 1;
}
