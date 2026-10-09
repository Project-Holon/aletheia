/*
 * file:     sp_poke_gimmick.c
 * unit:     yes
 * function: func_021F36C0, func_021F376C, func_021F3788, func_021F3794, func_021F3840, func_021F385C, func_021F3868, func_021F3980, func_021F39AC, func_021F39B8, func_021F3AA0, func_021F3B40, func_021F3B68, func_021F3B90, func_021F3C6C, func_021F3CB8, func_021F3CFC
 * address:  0x021F36C0
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   d_021F3E94  0x021F3E94  data  a4
 *   func_021897A0  0x021897A0  thumb  ov021
 *   func_021BE418  0x021BE418  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   d_021F3E84     0x021F3E84  data  a4
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_021BE310  0x021BE310  thumb  ov021
 *   d_021F4080     0x021F4080  data  ov059  a1
 *   d_021F3E74     0x021F3E74  data  a4
 *   func_020307B0  0x020307B0  arm
 *   func_0201210C  0x0201210C  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_021BE6E8  0x021BE6E8  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_021F3D9C  0x021F3D9C  thumb  ov059
 */
#include "../../matched/include/Obj20584.h"

struct Ctx;
struct Desc;
struct Obj;
typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef struct {
    int b;
    V c;
    V d;
    int e;
    u16 f;
    u16 g;
} W;

typedef struct {
    int b;
    V c;
    V d;
    int e;
    u16 f;
    u16 g;
} W_021F3B90;

typedef struct {
    u8 pad[0x24];
    u16 *p24;
} W_021F3CFC;

extern int func_02188D2C(int *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void func_021BE760(int a, void *b, int c);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern void *func_021BE674(void *p, int i, u16 j, u16 k);
extern void func_021BE6B8(unsigned char *p, int v);
extern void func_021BE6B0(unsigned char *p, int v);
extern void func_021BE700(void *p, int i, u16 j, u16 k, int flag);
extern void func_021897A0(unsigned char *p, int id);
extern void func_021BE418(unsigned char *p, unsigned short i);
extern void func_021BE580(void *p);
extern int *func_021897BC(char *p, int idx);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021BE310(void *a, void *b, int c);
extern u32 func_020307B0(void *p);
extern void *func_0201210C(const struct Ctx *p);
extern void func_020061E4(u32 a);
extern V *func_021BE480(void *p, int i, u16 j);
extern void func_021BE6CC(void *p, int i, u16 j, u16 k, int flag);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E4(struct Obj *p);
extern int func_021BE6E8(int a, int b, int c, int d);
extern int func_021BE6BC(int *p);
extern int func_021F3D9C(void *a);
void func_021F36C0(int a);
void func_021F376C(unsigned char *p);
void func_021F3788(void *p);
void func_021F3794(void *a);
void func_021F3840(unsigned char *p);
void func_021F385C(void *p);
void func_021F3868(void *a);
void func_021F3980(unsigned char *p);
void func_021F39AC(void *p);
void *func_021F39B8(void *a, int b, V *c, const V *d, int e, int f);
void func_021F3AA0(void *a, int b, V *c);
void func_021F3B40(void *p, int v);
void func_021F3B68(void *p, int v);
int func_021F3B90(void *a);
int func_021F3C6C(void *a);
int func_021F3CB8(void *a);
void func_021F3CFC(void *a, V *b, u16 c, u16 d);
extern char d_021F3E94[];
extern char d_021F3E84[];
extern char d_021F4080[];
extern char d_021F3E74[];








void func_021F36C0(int a)
{
    int i;
    int r5;
    int z;
    int r7;

    r5 = func_02188D2C((int *)a);
    func_02189764((unsigned char *)a, 1, func_02188C84((u8 *)a), 0x28);
    func_021BE760(r5, d_021F3E94, 0);
    i = 0;
    func_021BE4B4((char *)r5, 0, 1, 1);
    func_021BE4B4((char *)r5, 0, 0, 1);
    for (i = 0; i < 3; i++) {
        z = 0;
        r7 = (int)func_021BE674((void *)r5, z, z, i);
        func_021BE6B8((unsigned char *)r7, z);
        func_021BE6B0((unsigned char *)r7, 1);
        func_021BE700((void *)r5, z, z, i, z);
        r7 = (int)func_021BE674((void *)r5, z, 1, i);
        func_021BE6B8((unsigned char *)r7, z);
        func_021BE6B0((unsigned char *)r7, 1);
        func_021BE700((void *)r5, z, 1, i, z);
    }
}








void func_021F376C(unsigned char *p)
{
    void *s;
    s = (void *)func_02188D2C((int *)p);
    func_021897A0(p, 1);
    func_021BE418(s, 0);
}






void func_021F3788(void *p)
{
    func_021BE580((void *)func_02188D2C((int *)p));
}







void func_021F3794(void *a)
{
    int i;
    void *s;
    u8 *e;

    s = (void *)func_02188D2C(a);
    func_02189764(a, 1, func_02188C84(a), 0x28);
    func_021BE760((int)s, d_021F3E84, 0);
    func_021BE4B4(s, 0, 1, 1);
    func_021BE4B4(s, 0, 0, 1);
    for (i = 0; i < 3; i++) {
        e = (u8 *)func_021BE674(s, 0, 0, i);
        func_021BE6B8(e, 0);
        func_021BE6B0(e, 1);
        func_021BE700(s, 0, 0, (u16)i, 0);
        e = (u8 *)func_021BE674(s, 0, 1, i);
        func_021BE6B8(e, 0);
        func_021BE6B0(e, 1);
        func_021BE700(s, 0, 1, (u16)i, 0);
    }
}







void func_021F3840(unsigned char *p)
{
    void *s;
    s = (void *)func_02188D2C((int *)p);
    func_021897A0(p, 1);
    func_021BE418(s, 0);
}




void func_021F385C(void *p)
{
    func_021BE580((void *)func_02188D2C((int *)p));
}





void func_021F3868(void *a)
{
    int i;
    void *s;
    int z;
    u8 *e;
    int h;
    u8 *w;

    s = (void *)func_02188D2C(a);
    h = (func_02188C84(a) & 0x7FFF) | 0x8000;
    func_02189764(a, 1, (u16)h, 0x28);
    w = (u8 *)func_021897BC(a, 1);
    ((struct Obj20584 *)w)->f24 = func_02030734((u16)h, 4, 1, d_021F4080, 0x1D1);
    i = 0;
    func_021BE310(s, d_021F3E74, 0);
    func_021BE4B4(s, 0, 1, 1);
    func_021BE4B4(s, 0, 0, 1);
    for (i = 0; i < 3; i++) {
        z = 0;
        e = (u8 *)func_021BE674(s, z, z, i);
        func_021BE6B8(e, z);
        func_021BE6B0(e, 1);
        func_021BE700(s, z, z, i, z);
        e = (u8 *)func_021BE674(s, z, 1, i);
        func_021BE6B8(e, z);
        func_021BE6B0(e, 1);
        func_021BE700(s, z, 1, i, z);
    }
    for (i = 0; i < 3; i++) {
        e = (u8 *)func_021BE674(s, 0, 2, i);
        func_021BE6B8(e, 0);
        func_021BE6B0(e, 1);
        func_021BE700(s, 0, 2, i, 0);
    }
}





void func_021F3980(unsigned char *p)
{
    void *s;
    int *o;
    s = (void *)func_02188D2C((int *)p);
    o = func_021897BC((char *)p, 1);
    func_020307B0((void *)o[9]);
    func_021897A0(p, 1);
    func_021BE418(s, 0);
}


void func_021F39AC(void *p)
{
    func_021BE580((void *)func_02188D2C((int *)p));
}




void *func_021F39B8(void *a, int b, V *c, const V *d, int e, int f)
{
    int i;
    void *t;
    void *s;
    void *r;
    W *w;
    int flag;

    t = func_0201210C(a);
    flag = 1;
    w = (W *)func_021897BC(t, 1);
    s = (void *)func_02188D2C(t);
    if (b == 0) {
        flag = 0;
        func_020061E4(0x566);
    }
    *func_021BE480(s, 0, flag) = *c;
    func_021BE4B4(s, 0, (u16)flag, 0);
    for (i = 0; i < 3; i++) {
        func_021BE6B0(func_021BE674(s, 0, flag, i), 1);
        func_021BE700(s, 0, flag, i, 0);
        func_021BE6CC(s, 0, flag, i, 0);
    }
    w->c = *c;
    w->d = *d;
    w->f = f;
    w->g = 0;
    w->e = e;
    r = func_020122C0(a, 0, func_021F3B90, 0);
    w->b = b;
    return r;
}





void func_021F3AA0(void *a, int b, V *c)
{
    int i;
    void *t;
    void *s;
    int flag;

    t = func_0201210C(a);
    func_021897BC(t, 1);
    flag = 1;
    s = (void *)func_02188D2C(t);
    if (b == 0) {
        flag = 0;
        func_020061E4(0x567);
    } else {
        func_020061E4(0x793);
    }
    *func_021BE480(s, 0, flag) = *c;
    func_021BE4B4(s, 0, (u16)flag, 0);
    for (i = 0; i < 3; i++) {
        func_021BE6B0(func_021BE674(s, 0, flag, i), 0);
        func_021BE700(s, 0, flag, i, 1);
        func_021BE6CC(s, 0, flag, i, 0);
    }
}





void func_021F3B40(void *p, int v)
{
    int *o;
    o = func_021897BC(func_0201210C(p), 1);
    func_020122C0(p, 0, func_021F3C6C, 0);
    *o = v;
}




void func_021F3B68(void *p, int v)
{
    int *o;
    o = func_021897BC(func_0201210C(p), 1);
    func_020122C0(p, 0, func_021F3CB8, 0);
    *o = v;
}




/*
 * note:     the task callback func_021F39B8 installs: steps w->g towards
 *           w->f and interpolates a position between w->c and w->d with a
 *           bump of w->e on the middle axis. Each difference goes through
 *           the named temporary k (the original computes it into r1 and
 *           copies it to r0 for muls; inline, it lands in r0 and the
 *           function is 6 bytes short). The tail is one if with the
 *           return 1 inside it (the inverse early return flips the blo).
 */
int func_021F3B90(void *a)
{
    void *t;
    void *s;
    W_021F3B90 *w;
    int flag;
    int n;
    int d;
    int k;
    V pos;

    t = func_0201210C(func_020124E4(a));
    s = (void *)func_02188D2C(t);
    flag = 1;
    w = (W_021F3B90 *)func_021897BC(t, 1);
    if (w->b == 0)
        flag = 0;
    w->g++;
    n = w->g;
    d = w->f;
    k = w->d.a - w->c.a;
    pos.a = w->c.a + k * n / d;
    k = w->d.b - w->c.b;
    pos.b = w->c.b + k * n / d;
    k = w->d.c - w->c.c;
    pos.c = w->c.c + k * n / d;
    if (n >= (d + 1) / 2)
        n = d - n;
    pos.b += w->e * n / d;
    *func_021BE480(s, 0, flag) = pos;
    if (w->g >= w->f) {
        if (w->b == 1)
            func_021BE4B4(s, 0, (u16)flag, 1);
        return 1;
    }
    return 0;
}




int func_021F3C6C(void *a)
{
    void *t;
    void *s;
    int lim;
    int flag;
    int *p;

    t = func_0201210C(func_020124E4(a));
    s = (void *)func_02188D2C(t);
    p = func_021897BC(t, 1);
    flag = 1;
    if (*p == 0) {
        lim = 0x5000;
        flag = 0;
    } else {
        lim = 0x22000;
    }
    if (func_021BE6E8((int)s, 0, (u16)flag, 0) >= lim) {
        return 1;
    }
    return 0;
}




int func_021F3CB8(void *a)
{
    void *t;
    void *s;
    int flag;
    int *p;

    t = func_0201210C(func_020124E4(a));
    s = (void *)func_02188D2C(t);
    p = func_021897BC(t, 1);
    flag = 1;
    if (*p == 0) {
        flag = 0;
    }
    if (func_021BE6BC((void *)func_021BE674(s, 0, (u16)flag, 0))) {
        return 1;
    }
    return 0;
}




void func_021F3CFC(void *a, V *b, u16 c, u16 d)
{
    int i;
    void *t;
    void *s;
    W_021F3CFC *w;
    u16 *q;

    t = func_0201210C(a);
    w = (W_021F3CFC *)func_021897BC(t, 1);
    s = (void *)func_02188D2C(t);
    q = w->p24;
    q[0] = c;
    q[1] = d;
    *func_021BE480(s, 0, 2) = *b;
    func_021BE4B4(s, 0, 2, 0);
    for (i = 0; i < 3; i++) {
        func_021BE6B0((void *)func_021BE674(s, 0, (u16)2, (u16)i), 0);
        func_021BE700(s, 0, 2, i, 1);
        func_021BE6CC(s, 0, 2, i, 0);
    }
    func_020122C0(a, 0, func_021F3D9C, 0);
}
