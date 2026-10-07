/*
 * file:     scrcmd_screeneffects_p29.c
 * unit:     yes
 * function: func_021B1234, func_021B1240, func_021B1268, func_021B12B0, func_021B1334, func_021B13E0, func_021B13EC, func_021B13F8, func_021B1424, func_021B143C, func_021B14DC, func_021B14E8, func_021B14F4, func_021B1550, func_021B15B8, func_021B15C8, func_021B1604
 * address:  0x021B1234
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
 *   func_021B120C  0x021B120C  thumb  ov021
 *   func_02158F78  0x02158F78  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_02191BE8  0x02191BE8  thumb  ov021
 *   func_02159190  0x02159190  thumb  ov010
 *   func_02191B14  0x02191B14  thumb  ov021
 *   func_02158F84  0x02158F84  thumb  ov010
 *   func_02158F80  0x02158F80  thumb  ov010
 *   func_0201D83C  0x0201D83C  thumb
 *   func_0215A614  0x0215A614  thumb  ov010
 *   func_02159168  0x02159168  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_0215A60C  0x0215A60C  thumb  ov010
 *   func_02191A04  0x02191A04  thumb  ov021
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02158F7C  0x02158F7C  thumb  ov010
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_020113D0  0x020113D0  thumb
 *   func_02159144  0x02159144  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02191A10  0x02191A10  thumb  ov021
 *   func_02192628  0x02192628  thumb  ov021
 *   func_021926D8  0x021926D8  thumb  ov021
 *   func_021B162C  0x021B162C  thumb
 *   func_0219270C  0x0219270C  thumb  ov021
 *   func_0219272C  0x0219272C  thumb  ov021
 *   func_02192570  0x02192570  thumb  ov021
 *   func_0219269C  0x0219269C  thumb  ov021
 *   func_021B0480  0x021B0480  thumb  ov021
 *   func_021B10A4  0x021B10A4  thumb  ov021
 *   func_021B0A88  0x021B0A88  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02191134  0x02191134  thumb  ov021
 *   func_02191794  0x02191794  thumb  ov021
 *   func_021914CC  0x021914CC  thumb  ov021
 *   func_021904DC  0x021904DC  thumb  ov021
 */
#include "../../matched/include/Obj18093.h"
#include "../../matched/include/Obj18094.h"
#include "../../matched/include/Obj18095.h"

struct Stream;
struct WordSet;
struct MsgBank;
struct GfFont;
struct U;
struct Q;
struct T;
struct P;
struct R;
struct S;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

extern void func_021B120C(u32 v);
extern void *func_0215A5F4(void *p);
extern u32 func_02158F78(u8 *p);
extern int func_0215A61C(int a0);
extern u32 func_02191BE8(u32 *p, u32 b);
extern int func_02159190(int);
extern void func_02191B14(u32 *a);
extern u32 func_02158F84(u8 *p);
extern void func_02158F80(u8 *p, u32 v);
extern u32 func_0201D83C(void *ptr);
extern void func_0215A614(u8 *p, u32 v);
extern void func_02159168(int);
extern u16 func_02011330(struct Stream *s);
extern int func_02158F58(int a0);
extern unsigned int func_0215A60C(unsigned char *p);
extern int func_02191A04(int, int);
extern void *func_02158F74(void *p);
extern u32 func_02158F7C(u8 *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_020113D0(char *p, int val);
extern void func_02159144(int);
extern u16 func_02188C84(unsigned char *p);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, unsigned int heapId);
extern u32 *func_02191A10(u16 *a, u32 b, u32 c);
extern void func_02192628(u32 *a);
extern int func_021926D8(struct U *u);
extern u32 func_021B162C(u32 a, u32 b, u32 c);
extern u32 func_0219270C(struct Q *q, int a, int n);
extern u32 func_0219272C(u16 *a, u32 b, u32 c);
extern u32 *func_02192570(u16 *a, u32 b, u32 c, u16 d, u16 e, u16 f);
extern void func_0219269C(struct T *t, u16 b, u16 c, u32 d);
void func_021B0480(u32 a);
void func_021B10A4(void *p);
void func_021B0A88(u32 a, u32 b);
u32 func_020362DC(void);
void func_020061E4(u32 a);
void func_02191134(struct P *p);
void func_02191794(struct R *r);
void func_021914CC(struct S *s);
extern void func_021904DC(u8 *p, u8 v);
int func_021B1234(u8 *p);
int func_021B1240(int a, int b);
void func_021B1268(void *p);
int func_021B12B0(int a, unsigned char *b);
int func_021B1334(int a, unsigned char *b);
int func_021B13E0(u32 a, u32 b, u32 c, u32 d);
int func_021B13EC(u8 *p);
void func_021B13F8(u32 a);
int func_021B1424(int a, int b, int c, int d);
int func_021B143C(void *a, int b);
int func_021B14DC(u32 a, u32 b, u32 c, u32 d);
int func_021B14E8(u8 *p);
int func_021B14F4(int a, int b);
int func_021B1550(int a, int b);
int func_021B15B8(u32 a);
int func_021B15C8(u32 a, u32 b);
int func_021B1604(u32 *a);


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
int func_021B1234(u8 *p)
{
    func_021B120C(((struct Obj18093 *)p)->f4);
    return 1;
}


int func_021B1240(int a, int b)
{
    u32 x = func_02158F78(func_0215A5F4((void *)b));

    if (func_02191BE8((u32 *)func_0215A61C(b), x) == 1) {
        return 1;
    }
    return 0;
}


void func_021B1268(void *p)
{
    void *q = func_0215A5F4(p);
    void *r;
    if (func_02159190(4) != 0) {
        func_02191B14((void *)func_0215A61C((int)p));
        r = (void *)func_02158F84(q);
        func_02158F80(q, 0);
        if (r != 0) {
            func_0201D83C(r);
        }
        func_0215A614(p, 0);
        func_02159168(4);
    }
}


int func_021B12B0(int a, unsigned char *b)
{
    void *o;
    int s0, s1, s2;
    int *q;
    int x, y, z;
    o = func_0215A5F4((void *)b);
    s0 = func_02011330((struct Stream *)a);
    s1 = func_02011330((struct Stream *)a);
    q = (int *)func_02158F58((int)o);
    s2 = func_0215A60C(b);
    func_0215A614(b, func_02191A04(*q, s1));
    x = func_02158F78(o);
    y = (int)func_02158F74(o);
    z = func_02158F7C(o);
    func_02045CAC((struct MsgBank *)s2, s0, (void *)z);
    func_0201F250((struct WordSet *)y, (void *)x, (void *)z);
    func_020113D0((char *)a, (int)func_021B1240);
    func_02159144(4);
    return 1;
}


int func_021B1334(int a, unsigned char *b)
{
    void *o;
    int *q, *q2;
    int s0, s1, s2, h, m;
    int x, y, z;
    o = func_0215A5F4((void *)b);
    q = (int *)func_02158F58((int)o);
    s0 = func_02011330((struct Stream *)a);
    s1 = func_02011330((struct Stream *)a);
    h = func_02188C84((unsigned char *)q[1]);
    q2 = (int *)func_02158F58((int)o);
    s2 = func_0215A60C(b);
    m = (int)func_0201D7EC(0x17, 4, 0, 0, h);
    func_02158F80(o, m);
    func_0215A614((u8 *)b, (u32)func_02191A10((u16 *)(*q2), s1, m));
    x = func_02158F78(o);
    y = (int)func_02158F74(o);
    z = func_02158F7C(o);
    func_02045CAC((struct MsgBank *)s2, s0, (void *)z);
    func_0201F250((struct WordSet *)y, (void *)x, (void *)z);
    func_020113D0((char *)a, (int)func_021B1240);
    func_02159144(4);
    return 1;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B13E0(u32 a, u32 b, u32 c, u32 d)
{
func_021B1268((void *)b);
return 0;
}


int func_021B13EC(u8 *p)
{
    func_021B1268((void *)(((struct Obj18094 *)p)->f4));
    return 1;
}


void func_021B13F8(u32 a)
{
    u32 id = 6;

    if (func_02159190(id)) {
        func_02192628((u32 *)func_0215A61C(a));
        func_0215A614((u8 *)a, 0);
        func_02159168(id);
    }
}


int func_021B1424(int a, int b, int c, int d)
{
if (func_021926D8((struct U *)func_0215A61C(b)) == 1) {
    return 1;
}
return 0;
}


int func_021B143C(void *a, int b)
{
    void *o;
    int s0, k, n;
    u8 s1, s2;
    int *q;
    u16 h0, h1;
    u8 *p;
    u8 **pp =(u8 **)((char *)a + 0x14);
    o = func_0215A5F4((void *)b);
    s0 = func_02011330(a);
    s1 = **pp;
    (*pp)++;
    s2 = **pp;
    (*pp)++;
    k = func_02011330(a);
    n = func_021B162C(b, (u32)o, s0);
    q = (int *)func_02158F58((int)o);
    h0 = func_0219270C((struct Q *)(*q), n, 4);
    h1 = func_0219272C((u16 *)(*q), n, 4);
    {
        int m = (int)func_02192570((u16 *)(*q), k, s1, s2, h0, h1);
        func_0215A614((u8 *)b, m);
        func_0219269C((struct T *)m, 4, 4, n);
    }
    func_020113D0(a, (int)func_021B1424);
    func_02159144(6);
    return 1;
}


int func_021B14DC(u32 a, u32 b, u32 c, u32 d)
{
func_021B13F8(b);
return 0;
}


int func_021B14E8(u8 *p)
{
    func_021B13F8(((struct Obj18095 *)p)->f4);
    return 1;
}


int func_021B14F4(int a, int b)
{
    if (func_02159190(1)) {
        func_021B0480(b);
    }
    if (func_02159190(3)) {
        func_021B10A4((void *)b);
    }
    if (func_02159190(4)) {
        func_021B1268((void *)b);
    }
    if (func_02159190(6)) {
        func_021B13F8(b);
    }
    if (func_02159190(2)) {
        func_021B0A88(a, b);
    }
    return 1;
}


int func_021B1550(int a, int b)
{
    int r5;
    int r4;

    r5 = func_020362DC();
    r4 = func_0215A61C(b);
    if (r5 & 3) {
        func_020061E4(0x547);
        return 1;
    }
    if (func_02159190(1)) {
        func_02191134((struct P *)r4);
    } else if (func_02159190(3)) {
        func_02191794((struct R *)r4);
    } else if (func_02159190(2)) {
        func_021914CC((struct S *)r4);
    } else {
        return 1;
    }
    return 0;
}


int func_021B15B8(u32 a)
{
    func_020113D0((char *)a, (u32)func_021B1550);
    return 1;
}


int func_021B15C8(u32 a, u32 b)
{
    u32 *p = (u32 *)func_02158F58((int)func_0215A5F4((void *)b));

    if (func_02011330((struct Stream *)a)) {
        func_021904DC((u8 *)(*p), 1);
        func_02159144(9);
    } else {
        func_021904DC((u8 *)(*p), 0);
        func_02159168(9);
    }
    return 0;
}


int func_021B1604(u32 *a)
{
    u32 *p = (u32 *)func_02158F58(a[2]);
    u32 id = 9;

    if (func_02159190(id)) {
        func_021904DC((u8 *)(*p), 0);
        func_02159168(id);
    }
    return 1;
}
