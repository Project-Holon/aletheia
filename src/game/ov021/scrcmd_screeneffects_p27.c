/*
 * file:     scrcmd_screeneffects_p27.c
 * unit:     yes
 * function: func_021B0EF4, func_021B0FF0, func_021B1008, func_021B10A4
 * address:  0x021B0EF4
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
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02158F78  0x02158F78  thumb  ov010
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0202A310  0x0202A310  thumb
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0215A63C  0x0215A63C  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021B0A40  0x021B0A40  thumb  ov021
 *   func_021B0B08  0x021B0B08  thumb  ov021
 *   func_021B0ADC  0x021B0ADC  thumb  ov021
 *   func_0215A660  0x0215A660  thumb  ov010
 *   func_020113D0  0x020113D0  thumb
 *   func_021B0CEC  0x021B0CEC  thumb
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_021916E0  0x021916E0  thumb  ov021
 *   func_021B162C  0x021B162C  thumb
 *   func_021915EC  0x021915EC  thumb  ov021
 *   func_02191558  0x02191558  thumb  ov021
 *   func_0215A614  0x0215A614  thumb  ov010
 *   func_021916A8  0x021916A8  thumb  ov021
 *   func_02159144  0x02159144  thumb  ov010
 *   func_021915B4  0x021915B4  thumb  ov021
 *   func_02159168  0x02159168  thumb  ov010
 */
#include "../../matched/include/Obj12833.h"

struct Q;
struct Obj00020;
struct Actor;
struct VecFx32;
struct R;
typedef unsigned short u16;

typedef struct V3 {
    int y;
    void *x;
    void *z;
} V3;

typedef struct S {
    u16 id;
    u16 flag;
    V3 sum;
    V3 a;
    V3 b;
} S;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed char    s8;

extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern unsigned int func_02159B10(void *, void *);
extern u32 func_02158F78(u8 *p);
extern int func_02159190(int);
extern u16 func_0215A5CC(void *a0);
extern void func_0202A310(int key, int want, void *dest, u32 heap);
extern void *func_0215A5EC(void *p);
extern void *func_0216DE94(void *map, u32 id);
extern u8 *func_0215A63C(u8 *p);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern int func_021B0A40(u32 a, struct Q *q);
extern void func_021B0B08(void *a, int b);
extern void func_021B0ADC(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_0215A660(u8 *p, u32 v);
extern void func_020113D0(char *p, int val);
extern int func_021B0CEC(int, int);
extern int func_0215A61C(int a0);
extern u32 func_021916E0(u32 *a);
extern u32 func_021B162C(u32 a, u32 b, u32 c);
extern void func_021915EC(struct R *r);
extern int func_02191558(int, int, int, int, int, int, int);
extern void func_0215A614(u8 *p, u32 v);
extern void func_021916A8(struct R *r, u32 b, u16 c, u32 d);
extern void func_02159144(int);
extern int func_021915B4(void *a);
extern void func_02159168(int);
int func_021B0EF4(void *a, int b);
int func_021B0FF0(u32 a, u32 b, u32 c, u32 d);
int func_021B1008(void *a, int b, int c);
void func_021B10A4(void *p);


int func_021B0EF4(void *a, int b)
{
    void *o;
    unsigned char **q;
    int k0, k1, k2, m, r, flag;
    int y;
    void *x;
    void *z;
    S *s;
    V3 v;

    o = func_0215A5F4((void *)b);
    q = (unsigned char **)func_02158F58((int)o);
    k0 = func_02159B10(a, (void *)b);
    k1 = func_02159B10(a, (void *)b);
    k2 = func_02159B10(a, (void *)b);
    m = func_02158F78(o);
    if (func_02159190(2) != 0) {
        return 1;
    }
    func_0202A310(k0, k1, (void *)m, func_0215A5CC((void *)b));
    if (func_0216DE94(func_0215A5EC((void *)b), k2) == 0) {
        k2 = 0xff;
    }
    s = (S *)func_0215A63C((u8 *)b);
    flag = 0;
    func_02082BCC(s, 0, 0x28);
    s->id = k2;
    x = func_02188CB4((struct Obj00020 *)q[1]);
    y = (int)func_0215A5EC((void *)b);
    z = func_021A3074((void *)x);
    func_0216D88C(func_0216DE94((void *)y, s->id), (struct VecFx32 *)&v);
    r = func_021B0A40((u32)z, (struct Q *)(&v));
    if (r != 1) {
        flag = 1;
    }
    s->flag = flag;
    func_021B0B08((void *)b, 1);
    func_021B0ADC(b, (u32)(*q), flag, (u32)(&s->sum), m, 0, 0);
    func_0215A660((u8 *)b, r);
    func_020113D0(a, (int)func_021B0CEC);
    return 1;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B0FF0(u32 a, u32 b, u32 c, u32 d)
{
if (func_021916E0((u32 *)func_0215A61C(b)) == 1) {
    return 1;
}
return 0;
}


int func_021B1008(void *a, int b, int c)
{
    void *o;
    int n, r, t, m;
    int *q;
    u8 *p;
    o = func_0215A5F4((void *)b);
    q = (int *)func_02158F58((int)o);
    t = func_02159B10(a, (void *)b);
    p = *(u8 * *)&((struct Obj12833 *)a)->f14;
    n = *p;
    *(u8 * *)&((struct Obj12833 *)a)->f14 = p + 1;
    r = 1;
    m = func_021B162C(b, (u32)o, t);
    if (n != 1) {
        r = 0x13;
    }
    if (func_02159190(3) != 0) {
        r = func_0215A61C(b);
        func_021915EC((struct R *)r);
    } else {
        r = func_02191558(*q, 0, c, 1, r, 0x1e, 4);
        func_0215A614((u8 *)b, r);
    }
    func_021916A8((struct R *)r, 8, 0, m);
    func_02159144(3);
    func_020113D0(a, (int)func_021B0FF0);
    return 1;
}


void func_021B10A4(void *p)
{
    int n = 3;
    if (func_02159190(3) != 0) {
        func_021915B4((void *)func_0215A61C((int)p));
        func_0215A614(p, 0);
        func_02159168(n);
    }
}
