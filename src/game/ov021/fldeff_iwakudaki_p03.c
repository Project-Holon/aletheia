/*
 * file:     fldeff_iwakudaki_p03.c
 * unit:     yes
 * function: func_021ADE70, func_021ADEA0, func_021ADEDC, func_021ADF00, func_021ADF14, func_021ADF68, func_021ADF94, func_021AE01C, func_021AE030
 * address:  0x021ADE70
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
 *   func_021AC154  0x021AC154  thumb  ov021
 *   d_021D92A4  0x021D92A4  data
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   d_021DE124  0x021DE124  data
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   d_021DE120     0x021DE120  data  a2
 *   func_02047738  0x02047738  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047504  0x02047504  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_020470D0  0x020470D0  arm
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0209BDBC  0x0209BDBC  arm
 *   func_0209C95C  0x0209C95C  arm
 *   func_0209CB8C  0x0209CB8C  arm
 *   func_0209C494  0x0209C494  arm
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D92E0     0x021D92E0  data  a1
 *   d_021D92E8     0x021D92E8  data  a4
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 */
#include "../../matched/include/Obj04889.h"
#include "../../matched/include/Obj12798.h"

struct Arg;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Rec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Q_021ADE70 { u32 f0; u32 f4; u32 arr[4]; u32 f18; u32 f1c; } Q_021ADE70;

typedef struct V3 { int x, y, z; } V3;

typedef struct M33 { int m[9]; } M33;

typedef struct Xf { V3 pos; V3 scale; M33 rot; } Xf;

typedef struct Q_021ADEA0 { u32 f0; u32 f4; u32 f8; u32 fc; } Q_021ADEA0;

typedef struct P { u32 f0; } P;

typedef signed int     s32;

typedef struct Tb { u8 b[8]; } Tb;

typedef struct V { int x, y, z; } V;

typedef struct Arg { int a; V v; } Arg;

extern int func_020478B8(void *a, int idx, int amount);
extern void func_021AC154(u32 a);
extern void func_0207ADC4(M33 *m);
extern void func_021AC1B8(u32 a, V3 *out);
extern int func_02047AC8(void *a0, struct Arg *a1);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern int func_02046FF8(int *self);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern u32 func_02046EFC(u32);
extern int func_020470D0(u32 *p);
extern void func_02047504(struct Rec *p);
extern void func_0204762C(struct Rec *p);
extern void func_02047738(struct Rec *p);
extern int func_021ABEA0(u32 a, u32 b);
extern int func_0209BDBC(int a);
extern int func_0209C95C(int a, int b);
extern int func_0209CB8C(int a, int b);
extern int func_0209C494(int a);
extern void func_021ABFA8(int a, u8 *b, int c, int d, Arg *e, int f);
extern int func_021AC1E0(u32 a);
extern int func_021AC1AC(u32 a);
extern void func_021AC1CC(u32 a, u32 *b);
void func_021ADE70(u32 a, Q_021ADE70 *q);
void func_021ADEA0(u32 a, Q_021ADEA0 *q);
P *func_021ADEDC(u32 a, int heap);
void func_021ADF00(u32 a, u8 *p);
void func_021ADF14(int *p);
int func_021ADF68(void *a);
void func_021ADF94(int a, V *b, int c, int d);
void func_021AE01C(u32 a, u16 v);
void func_021AE030(u32 a, u32 *out);
extern Xf d_021D92A4;
extern char d_021DE124[];
extern u16 d_021DE120;
extern Tb d_021D92E0;
extern u8 d_021D92E8[];


void func_021ADE70(u32 a, Q_021ADE70 *q)
{
    int done = 1;
    int i;

    for (i = 0; i < 4; i++) {
        if (func_020478B8((void *)q->f4, (u16)i, (u32)0x1000) == 1)
            done = 0;
    }
    if (done)
        func_021AC154(a);
}


void func_021ADEA0(u32 a, Q_021ADEA0 *q)
{

    Xf x = d_021D92A4;

    func_0207ADC4(&x.rot);
    func_021AC1B8(a, &x.pos);
    func_02047AC8((void *)q->f4, (struct Arg *)(&x));
}


P *func_021ADEDC(u32 a, int heap)
{
    P *p;

    p = (P *)func_02030734(heap, 0x18, 1, d_021DE124, 0x60);
    p->f0 = a;
    func_021ADF14((int *)p);
    return p;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021ADF00(u32 a, u8 *p)
{
    func_021ADF68(p);
    func_020307B0(p);
}


void func_021ADF14(int *p)
{
    int r5 = func_021ABE24((u8 *)p[0]);

    func_02046FF8((int *)(p[1] = (int)func_02046E24(r5, 0x54)));
    p[2] = (int)func_02046E24(r5, d_021DE120);
    p[5] = (int)func_02047400((void *)p[1], 0, (void *)p[1]);
    p[4] = (int)func_02047564((struct G3dOwner *)p[5], (const struct G3dOwner *)p[2], 0);
    p[3] = (int)func_0204767C(p[5], (u32 *)(&p[4]), 1);
    func_020477A4((struct G3dSys *)p[3], 0);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021ADF68(void *a)
{
func_02047738((struct Rec *)(((struct Obj04889 *)((u8 *)(a)))->fC));
func_0204762C((struct Rec *)(((struct Obj04889 *)((u8 *)(a)))->f10));
func_02047504((struct Rec *)(((struct Obj04889 *)((u8 *)(a)))->f14));
func_02046EFC(((struct Obj04889 *)((u8 *)(a)))->f8);
func_020470D0((u32 *)(((struct Obj04889 *)((u8 *)(a)))->f4));
return func_02046EFC(((struct Obj04889 *)((u8 *)(a)))->f4);
}


void func_021ADF94(int a, V *b, int c, int d)
{
    Tb t = d_021D92E0;
    Arg s;
    int v;
    int r;

    s.a = func_021ABEA0(a, 13);
    s.v = *b;
    v = (t.b + d * 4)[c];
    if (v != 0) {
        r = func_0209C95C(0x3f000000, func_0209BDBC(v << 12));
    } else {
        r = func_0209CB8C(func_0209BDBC(v << 12), 0x3f000000);
    }
    s.v.z +=func_0209C494(r);
    func_021ABFA8(a, d_021D92E8, 0, 0, &s, 0);
}


void func_021AE01C(u32 a, u16 v)
{
    u8 *p;

    if (a != 0) {
        p = (u8 *)func_021AC1E0(a);
        ((struct Obj12798 *)p)->f6 = 1;
        ((struct Obj12798 *)p)->f4 = v;
    }
}


void func_021AE030(u32 a, u32 *out)
{
    u32 *p = (u32 *)func_021AC1AC(a);

    *out = p[0];
    func_021AC1CC(a, p + 1);
}
