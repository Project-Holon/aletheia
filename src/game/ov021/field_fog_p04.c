/*
 * file:     field_fog_p04.c
 * unit:     yes
 * function: func_0219F8C8, func_0219F8E0, func_0219F8F4, func_0219F990, func_0219FAB4, func_0219FADC, func_0219FB20, func_0219FB2C
 * address:  0x0219F8C8
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
 *   func_0216D6D8  0x0216D6D8  thumb  ov010
 *   func_0219C814  0x0219C814  thumb  ov021
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0219C8D4  0x0219C8D4  thumb  ov021
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_0219FFBC  0x0219FFBC  thumb  ov021
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_021A000C  0x021A000C  thumb  ov021
 *   func_0205082C  0x0205082C  arm
 *   func_02050080  0x02050080  arm
 *   func_0204F638  0x0204F638  arm
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_02197C9C  0x02197C9C  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188CBC  0x02188CBC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3080  0x021A3080  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_02013D9C  0x02013D9C  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   func_0219FE9C  0x0219FE9C  thumb  ov021
 */
#include "../../matched/include/Obj17981.h"
#include "../../matched/include/Obj17982.h"

struct Trip;
struct Obj00020;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef struct {
    u32 x, y, z;
} V3;

typedef struct {
    u16 id;
    u8 f2;
    u8 f3;
    u8 pad[4];
    u32 f8;
} St;

typedef signed int     s32;

typedef struct { s32 x, y, z; } Vec;

extern void *func_0216D6D8(int a0, int a1);
extern int func_0219C814(u32 a, u16 *b);
extern void *func_0216D6F0(void *p);
extern u32 func_0219C8D4(u32, u32);
extern int func_0216D910(int a0);
extern u16 func_0216D5F8(void *p);
extern void func_0216D8B0(u8 *p, u8 *q);
extern u32 func_0219C9DC(u8 *p);
extern void func_0219FFBC(u32, u32 *);
extern void func_02197CCC(u8 *p, s32 *out);
extern void func_021A000C(u32, u32, u32, u32, u32);
extern void func_0205082C(void *p, int idx, u32 h);
extern u32 func_02050080(u32 *p);
extern void func_0204F638(u8 *a0, int i, struct Trip *src);
extern void *func_0216E3C4(void *p);
extern s32 func_02197C9C(u32);
extern int func_0216D83C(void *p);
extern u16 func_0216D590(void *p);
extern u16 func_0216D588(void *p);
extern void *func_0216D67C(void *a0);
extern u32 func_0216D534(void *p);
extern int func_02188CBC(u32);
extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_021A3080(u8 *p);
extern void func_0216D8C0(u32, Vec *);
extern u32 func_02013D9C(u32 id);
extern void func_0219FE9C(u8 *);
void func_0219F8C8(u32 a);
int func_0219F8E0(u32 a, u32 b, u32 c, u32 d);
void func_0219F8F4(u32 a);
void func_0219F990(u32 a, u8 *p, u8 b);
void func_0219FAB4(u32 a, u32 b, u8 *c, int *d);
int func_0219FADC(u8 *p, int a, u8 *q);
int func_0219FB20(u32 a, u32 b, u32 c, u32 d);
void func_0219FB2C(u32 a);


/*
 * Addresses are Black-image addresses.
 */
void func_0219F8C8(u32 a)
{
    u8 *q = func_0216D6D8(a, 8);
    q[2] = 9;
    func_0219C814(a, (u16 *)q);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219F8E0(u32 a, u32 b, u32 c, u32 d)
{
return func_0219C8D4(a, ((struct Obj17981 *)((u8 *)(func_0216D6F0((void *)a))))->f0);
}


void func_0219F8F4(u32 a)
{
    St *p;
    u8 flag;
    u32 h;
    u32 n;
    u32 buf[3];
    u32 v[3];

    p = func_0216D6F0((void *)a);
    if (p->id != 0xFFFF) {
        flag = 0;
        h = func_0219C9DC((u8 *)func_0216D910(a));
        n = func_0216D5F8((void *)a);
        if (n != p->f2) {
            flag = 1;
            p->f2 = n;
            p->f3 = 0;
            p->f8 = 0;
            func_0205082C((void *)h, p->id, p->f2);
            {
                V3 *pv = (V3 *)v;
                pv->x = 0;
                pv->y = 0;
                pv->z = 0;
                func_0216D8B0((u8 *)a, (u8 *)pv);
            }
        }
        func_0219F990(a, (u8 *)p, n);
        func_02197CCC((u8 *)a, (s32 *)buf);
        func_0219FFBC(a, buf);
        func_0204F638((u8 *)func_02050080((u32 *)h), p->id, (struct Trip *)buf);
        func_021A000C(a, h, p->id, flag, 0);
    }
}


void func_0219F990(u32 a, u8 *p, u8 b)
{
    Vec d;
    Vec v;
    u32 u;
    s32 s14;
    u32 s10;
    s32 sc;
    u8 *info;
    int clr;
    int ok;
    int ff;
    u32 t;
    u8 m;
    void *x;

    ok = 1;
    info = func_0216E3C4((void *)a);
    ff = 0;
    d.x = 0;
    d.y = 0;
    d.z = 0;
    s14 = func_02197C9C(a);
    func_0216D8B0((u8 *)a, (u8 *)(&v));
    sc = func_0216D83C((void *)a);
    s10 = func_0216D590((void *)a);
    t = func_0216D588((void *)a);
    if (t == 0xff)
        ff = ok;
    clr = (t == 0xfc) ? 1 : 0;
    if (ff != 0) {
        u = func_0216D534(func_0216D67C((void *)a));
        if (func_02188CBC(u) != 0 && (x = func_02188CB4((void *)u)) != 0) {
            ok = func_021A3080(x) != 0;
        }
    }
    if (s14 != 0 || (v.y > 0x1800 && info[3] != 11)) {
        d.y = v.y;
    } else if (func_0219FADC(p, b, info) == 0 && ok != 0) {
        d.y = d.y + 0x1800;
    }
    if (func_02013D9C(s10) != 0 && ff == 0) {
        m = sc % 3;
        if (m == 0)
            d.z = d.z - 0x219a;
        else if (m == 2)
            d.z = d.z + 0x219a;
        d.z = d.z - 0x2000;
    }
    func_0219FAB4(a, b, info, (int *)(&d));
    if (clr) {
        d.x = 0;
        d.y = 0;
        d.z = 0;
    }
    func_0216D8C0(a, &d);
    p[3]++;
}


void func_0219FAB4(u32 a, u32 b, u8 *c, int *d)
{
    if (c[7] == 0) {
        switch (b) {
        case 2:
            *d -= 0x2000;
            break;
        case 3:
            *d += 0x2000;
            break;
        }
    }
}


int func_0219FADC(u8 *p, int a, u8 *q)
{
    int m = p[3] % 20;
    u8 k = q[3];
    p[3] = m;
    if (k == 11) {
        if (a == 1) {
            if (m < 5 || m >= 15)
                return 1;
        } else {
            if (m < 10)
                return 1;
        }
    } else {
        if ((m >= 5 && m < 10) || m >= 15)
            return 1;
    }
    return 0;
}


int func_0219FB20(u32 a, u32 b, u32 c, u32 d)
{
return ((struct Obj17982 *)((u8 *)(func_0216D6F0((void *)a))))->f0;
}


void func_0219FB2C(u32 a)
{
    u8 *q = func_0216D6D8(a, 8);
    func_0219FE9C(q + 4);
    func_0219C814(a, (u16 *)q);
}
