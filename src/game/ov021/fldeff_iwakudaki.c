/*
 * file:     fldeff_iwakudaki.c
 * unit:     yes
 * function: func_021ADC6C, func_021ADCB8, func_021ADCDC, func_021ADCF0, func_021ADD38, func_021ADD64, func_021ADD7C, func_021ADDE8, func_021ADE4C, func_021ADE70, func_021ADEA0, func_021ADEDC, func_021ADF00, func_021ADF14, func_021ADF68, func_021ADF94, func_021AE01C, func_021AE030, func_021AE04C, func_021AE050, func_021AE090, func_021AE0CC, func_021AE198, func_021AE1FC, func_021AE288, func_021AE348, func_021AE430, func_021AE454, func_021AE498, func_021AE4B4, func_021AE4E0, func_021AE524, func_021AE550, func_021AE56C, func_021AE58C, func_021AE5A8, func_021AE5BC
 * address:  0x021ADC6C
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
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_02047AC8  0x02047AC8  arm
 *   d_021D9254     0x021D9254  data  a4
 *   d_021DE10C  0x021DE10C  data
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02047180  0x02047180  arm
 *   func_020056A0  0x020056A0  thumb
 *   d_021DE0FC     0x021DE0FC  data  a4
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021ABE8C  0x021ABE8C  thumb  ov021
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9290     0x021D9290  data  a4
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   d_021D92A4  0x021D92A4  data
 *   d_021DE124  0x021DE124  data
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
 *   func_0209BDBC  0x0209BDBC  arm
 *   func_0209C95C  0x0209C95C  arm
 *   func_0209CB8C  0x0209CB8C  arm
 *   func_0209C494  0x0209C494  arm
 *   d_021D92E0     0x021D92E0  data  a1
 *   d_021D92E8     0x021D92E8  data  a4
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 *   func_02047910  0x02047910  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   d_021D92FC  0x021D92FC  data
 *   func_0215A4C8  0x0215A4C8  thumb  ov010
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0218B6AC  0x0218B6AC  thumb  ov021
 *   func_021AE930  0x021AE930  thumb  ov021
 *   func_0215A438  0x0215A438  thumb  ov010
 *   func_021AE8D4  0x021AE8D4  thumb  ov021
 *   func_021AE8B4  0x021AE8B4  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_021AE7A8  0x021AE7A8  thumb  ov021
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_021AE890  0x021AE890  thumb  ov021
 *   func_021AE79C  0x021AE79C  thumb  ov021
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   d_021D9338  0x021D9338  data  a4
 *   func_021AE754  0x021AE754  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   d_021DE138     0x021DE138  data  a4
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0216DB04  0x0216DB04  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021BB528  0x021BB528  thumb  ov021
 *   func_021BB5C8  0x021BB5C8  thumb  ov021
 */
#include "../../matched/include/Obj09607.h"
#include "../../matched/include/Obj04889.h"
#include "../../matched/include/Obj12798.h"
#include "../../matched/include/Obj07517.h"
#include "../../matched/include/Obj09181.h"
#include "../../matched/include/Obj05863.h"
#include "../../matched/include/Obj07220.h"
#include "../../matched/include/Obj12098.h"
#include "../../matched/include/Obj07221.h"
#include "../../matched/include/Obj09182.h"
#include "../../matched/include/Obj12099.h"
#include "../../matched/include/Obj12100.h"

#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))
struct Arg_021ADC6C;
struct Q;
struct Node;
struct Tagged;
struct Actor;
struct VecFx32;
struct T;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Rec;
struct Arg;
struct S;
struct Obj00020;
struct Ctx;
struct Desc;
struct Obj;
typedef unsigned char u8;

typedef struct T { int w[15]; } T;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct P { u32 f0; } P;

typedef signed int     s32_021ADC6C;

typedef struct Q_021ADD38 { u32 f0; u32 f4; u32 arr[4]; u32 f18; u32 f1c; } Q_021ADD38;

typedef struct Q_021ADD64 { u32 f0; u32 f4; u32 arr[4]; u32 f18; u32 f1c; } Q_021ADD64;

typedef int s32_021ADD38;

typedef struct Vec3 { s32_021ADD38 x, y, z; } Vec3;

typedef struct Arg_021ADC6C { unsigned a; Vec3 v; } Arg_021ADC6C;

typedef struct Src { u32 f0; u32 f4; u32 arr[4]; } Src;

typedef struct Q_021ADDE8 { Src *src; u32 f4; u32 arr[4]; u32 f18; } Q_021ADDE8;

typedef struct Q_021ADE4C { u32 f0; u32 f4; u32 arr[4]; u32 f18; u32 f1c; } Q_021ADE4C;

typedef struct Q_021ADE70 { u32 f0; u32 f4; u32 arr[4]; u32 f18; u32 f1c; } Q_021ADE70;

typedef struct V3 { int x, y, z; } V3;

typedef struct M33 { int m[9]; } M33;

typedef struct Xf { V3 pos; V3 scale; M33 rot; } Xf;

typedef struct Q_021ADEA0 { u32 f0; u32 f4; u32 f8; u32 fc; } Q_021ADEA0;

typedef signed int     s32;

typedef struct Tb { u8 b[8]; } Tb;

typedef struct V { int x, y, z; } V;

typedef struct Arg_021ADE70 { int a; V v; } Arg_021ADE70;

typedef struct Owner {
    char pad00[0xC];
    void *obj;
} Owner;

typedef struct Arg {
    Owner *owner;
    unsigned short n;
} Arg;

typedef signed short   s16_021AE090;

typedef struct Q { u32 f0; u32 f4; u32 f8; u32 fc; } Q;

typedef struct Rec {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
} Rec;

typedef short s16_021AE198;

typedef short s16_021AE288;

typedef short s16_021AE348;

typedef int (*CmpFn)(int, const s16_021AE348 *, const s16_021AE348 *);

typedef signed short   s16_021AE430;

typedef struct { int w[6]; } S24;

typedef struct Task {
    int state;              /* 0x00 */
    int f04;
    void *f08;              /* 0x08 */
    int f0C[4];
    int f1C;                /* 0x1C */
    int f20;
    int f24;                /* 0x24 */
    int f28[3];
    unsigned char *f34;     /* 0x34 */
} Task;

extern void func_0207ADC4(M33 *m);
extern void func_021AC1B8(u32 a, V3 *out);
extern int func_02047AC8(void *a0, struct Arg *a1);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern unsigned int func_021ABE24(u8 *p);
extern void *func_02046E24(unsigned int a0, unsigned int a1);
extern int func_02047180(unsigned int *p);
extern int func_020056A0(void *fn, void *arg, int z);
extern u32 func_02046EFC(struct Tagged *p);
extern int func_020470D0(u32 *p);
extern void func_02030EAC(struct Node *n);
extern u32 func_02047204(struct Tagged *p);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
extern int func_021ABE8C(struct T *a, int b);
extern void func_021ABE30(int a, int *b, int c);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(int a, u8 *b, int c, int d, Arg_021ADC6C *e, int f);
extern int func_021AC1AC(u32 a);
extern void func_021AC1CC(u32 a, u32 *b);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_0204762C(struct Rec *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern int func_020478B8(void *a, int idx, int amount);
extern u32 func_021AC154(u32 a);
extern int func_02046FF8(int *self);
extern int func_0209BDBC(int a);
extern int func_0209C95C(int a, int b);
extern int func_0209CB8C(int a, int b);
extern int func_0209C494(int a);
extern int func_021AC1E0(u32 a);
extern int func_02047910(void *a, int idx, int amount);
extern int func_0215A4C8(int a0);
extern void *func_02188C80(void *p);
extern int func_0218B6AC(void *ctx);
extern int func_021AE930(int a, u32 b);
extern void func_0215A438(int a, int b, Rec *src);
extern u32 func_021AE8D4(u32 a, u16 b);
extern void func_021AE8B4(struct S *s, u32 a, u32 b, u32 c);
extern void *func_0216D67C(void *a0);
extern void *func_0216DE94(void *map, u32 id);
extern void func_0216D828(int a, int *b);
extern int func_021AE7A8(u32 a, u32 dir, int n, void *p);
extern u32 func_02188CE8(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern void *func_02188C7C(unsigned char *p);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_021AE890(u32 a, u32 b);
extern int func_021AE79C(u32 a);
extern int func_0216D63C(char *a0, int a1);
extern u16 func_0216D5F8(void *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_021AE754(u32 a, u32 b, u32 *c);
extern int func_0216DA5C(void *a0);
extern char *func_0216DB04(void *a0);
extern void func_0216D5E0(int a0, int a1);
extern void func_0216DAF8(void *a0);
extern int func_0216D454(void *a0);
extern u16 func_0216D5A0(void *p);
extern int func_0216D3CC(int a0);
extern void func_0216D410(void *a0, u32 a1);
extern int func_02197E7C(int a, int b);
extern u32 func_02188CD0(u8 *p);
extern u32 func_021BB528(u32, u32, u32, u32);
extern int func_021BB5C8(u32 a);
void func_021ADC6C(int a, u8 *b);
P *func_021ADCB8(u32 a, int heap);
void func_021ADCDC(u32 a, u8 *p);
void func_021ADCF0(int *p);
void func_021ADD38(Q_021ADD38 *q);
void func_021ADD64(u32 a, Q_021ADD64 *q);
void func_021ADD7C(int a, int b);
void func_021ADDE8(u32 a, Q_021ADDE8 *q);
void func_021ADE4C(u32 a, Q_021ADE4C *q);
void func_021ADE70(u32 a, Q_021ADE70 *q);
void func_021ADEA0(u32 a, Q_021ADEA0 *q);
P *func_021ADEDC(u32 a, int heap);
void func_021ADF00(u32 a, u8 *p);
void func_021ADF14(int *p);
int func_021ADF68(void *a);
void func_021ADF94(int a, V *b, int c, int d);
void func_021AE01C(u32 a, u16 v);
void func_021AE030(u32 a, u32 *out);
void func_021AE04C(void);
void func_021AE050(void *self, Arg *arg);
void func_021AE090(u32 a, Q **pq);
int func_021AE0CC(int a);
int func_021AE198(int a, int b, int c, int d);
int func_021AE1FC(int a, void *b, int c);
int func_021AE288(int a, int b, int c, u16 *d);
int func_021AE348(int idx, int a, const s16_021AE348 *p, const s16_021AE348 *q);
int func_021AE360(int a, const s16_021AE348 *p, const s16_021AE348 *q);
int func_021AE394(int a, const s16_021AE348 *p, const s16_021AE348 *q);
int func_021AE3C8(int a, const s16_021AE348 *p, const s16_021AE348 *q);
int func_021AE3FC(int a, const s16_021AE348 *p, const s16_021AE348 *q);
u32 func_021AE430(u32 a, u32 x, u32 y);
void *func_021AE454(int a, int b, S24 *src, int c);
int func_021AE498(u32 a, u32 b, u32 c, u32 d);
int func_021AE4B4(u32 a, u32 b, u32 c, u32 d);
int func_021AE4E0(Task *p);
int func_021AE524(u32 a);
int func_021AE550(u32 a, u32 b, u32 c, u32 d);
int func_021AE56C(u32 a, u32 b, u32 c, u32 d);
int func_021AE58C(u32 a, u32 b, u32 c, u32 d);
int func_021AE5A8(u32 a, u32 b, u32 c, u32 d);
int func_021AE5BC(u32 a, u32 b, u32 c, u32 d);
extern T d_021D9254;
extern char d_021DE10C[];
extern int d_021DE0FC[];
extern u8 d_021D9290[];
extern Xf d_021D92A4;
extern char d_021DE124[];
extern u16 d_021DE120;
extern Tb d_021D92E0;
extern u8 d_021D92E8[];
extern Xf d_021D92FC;
extern CmpFn d_021D9338[];
extern int d_021DE138;





void func_021ADC6C(int a, u8 *b)
{
    T t = d_021D9254;
    int c = ((struct Obj09607 *)b)->f8;

    if (b[3] == 0) {
        func_0207ADC4((M33 *)(&t.w[6]));
        func_021AC1B8(a, (V3 *)(&t));
        func_02047AC8((void *)(*(int *)(c + b[0x1c] * 0x18 + 0x28)), (struct Arg *)(&t));
    }
}





P *func_021ADCB8(u32 a, int heap)
{
    P *p;

    p = (P *)func_02030734(heap, 0x20, 1, d_021DE10C, 0x67);
    p->f0 = a;
    func_021ADCF0((int *)p);
    return p;
}





/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021ADCDC(u32 a, u8 *p)
{
    func_021ADD38((Q_021ADD38 *)((struct Q *)p));
    func_020307B0(p);
}





void func_021ADCF0(int *p)
{
    int r7 = func_021ABE24((u8 *)p[0]);
    int i;

    func_02047180((unsigned int *)(p[1] = (int)func_02046E24(r7, 0x4d)));
    p[6] = func_020056A0((void *)func_021ADD64, p, 0);
    for (i = 0; i < 4; i++)
        p[2 + i] = (int)func_02046E24(r7, d_021DE0FC[i]);
}





void func_021ADD38(Q_021ADD38 *q)
{
    int i;

    for (i = 0; i < 4; i++)
        func_02046EFC((struct Tagged *)q->arr[i]);
    func_020470D0((u32 *)q->f4);
    func_02046EFC((struct Tagged *)q->f4);
    func_02030EAC((struct Node *)q->f18);
}





void func_021ADD64(u32 a, Q_021ADD64 *q)
{
    if (q->f1c == 0) {
        func_02047204((struct Tagged *)q->f4);
        q->f1c = 1;
    }
}





void func_021ADD7C(int a, int b)
{
    Vec3 v;
    Arg_021ADC6C s;
    int n;

    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    v.y += 0x1000;
    v.z += 0xc000;
    if (func_021ABE8C((struct T *)b, 10) == 0) {
        n = 10;
        func_021ABE30(b, &n, 1);
    }
    s.a = func_021ABEA0(b, 10);
    s.v = v;
    func_021ABFA8(b, d_021D9290, 0, 0, (Arg_021ADC6C *)&s, 0);
}





void func_021ADDE8(u32 a, Q_021ADDE8 *q)
{
    u32 *p = (u32 *)func_021AC1AC(a);
    int i;

    q->src = (Src *)p[0];
    func_021AC1CC(a, p + 1);
    q->f18 = (u32)func_02047400((void *)q->src->f4, 0, (void *)q->src->f4);
    for (i = 0; i < 4; i++)
        q->arr[i] = (u32)func_02047564((struct G3dOwner *)q->f18, (const struct G3dOwner *)q->src->arr[i], 0);
    q->f4 = (u32)func_0204767C(q->f18, q->arr, 4);
    for (i = 0; i < 4; i++)
        func_020477A4((struct G3dSys *)q->f4, (u16)i);
}





void func_021ADE4C(u32 a, Q_021ADE4C *q)
{
    int i;

    for (i = 0; i < 4; i++)
        func_0204762C((struct Rec *)q->arr[i]);
    func_02047738((struct Rec *)q->f4);
    func_02047504((struct Rec *)q->f18);
}




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

    func_0207ADC4((M33 *)(&x.rot));
    func_021AC1B8(a, (V3 *)(&x.pos));
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
func_02046EFC((struct Tagged *)(((struct Obj04889 *)((u8 *)(a)))->f8));
func_020470D0((u32 *)(((struct Obj04889 *)((u8 *)(a)))->f4));
return func_02046EFC((struct Tagged *)(((struct Obj04889 *)((u8 *)(a)))->f4));
}




void func_021ADF94(int a, V *b, int c, int d)
{
    Tb t = d_021D92E0;
    Arg_021ADE70 s;
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
    func_021ABFA8(a, d_021D92E8, 0, 0, (Arg_021ADC6C *)&s, 0);
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





/*
 * Set channel 0 of the object at +0xC of *arg->owner to (2*arg->n + 1)
 * converted through FX_F32_TO_FX32.
 */
void func_021AE04C(void)
{
}


void func_021AE050(void *self, Arg *arg)
{
    Owner *owner = arg->owner;
    func_02047910(owner->obj, 0, FX_F32_TO_FX32(arg->n * 2 + 1));
}





void func_021AE090(u32 a, Q **pq)
{
    Q *q = *pq;
    Xf x = d_021D92FC;

    func_0207ADC4(&x.rot);
    func_021AC1B8(a, &x.pos);
    func_02047AC8((void *)q->fc, (struct Arg *)(&x));
}





int func_021AE0CC(int a)
{
    Rec b;
    Rec c;
    u32 kind;
    u32 n;
    int z = 0;
    int ret = 0;

    if (func_021AE1FC(a, 0, (int)(&b)) == 1) {
        kind = (u32)func_0215A4C8((u16)b.f10);
        n = func_0218B6AC(func_02188C80((void *)a));
        if (kind == 0) {
            if (n < 2 || func_021AE1FC(a, (void *)b.f0, (int)(&c)) == 0) {
                ret = func_021AE930(a, b.f0);
                b.f14 = 0;
                func_0215A438(ret, 0, &b);
            } else {
                ret = func_021AE930(a, b.f0);
                b.f14 = 2;
                func_0215A438(ret, z, &b);
                c.f14 = 2;
                func_0215A438(ret, 1, &c);
            }
        } else if (kind == 1) {
            if (n >= 2) {
                func_021AE8B4((struct S *)(&c), func_021AE8D4(b.f0, b.f10), b.f4, (u16)b.f8);
                ret = func_021AE930(a, b.f0);
                b.f14 = 1;
                func_0215A438(ret, z, &b);
                c.f14 = 1;
                func_0215A438(ret, 1, &c);
            }
        } else if (kind == 2 || kind == 3) {
            if (n >= 3) {
                ret = func_021AE930(a, b.f0);
                b.f14 = z;
                func_0215A438(ret, z, &b);
            }
        }
    }
    return ret;
}





int func_021AE198(int a, int b, int c, int d)
{
    int q[2];
    int p[2];
    int h;
    int r;

    h = (int)func_0216DE94(func_0216D67C((void *)a), 0xff);
    if (h == 0)
        return -1;
    func_0216D828(h, p);
    func_0216D828(a, q);
    r = func_021AE348(b, (s16_021AE198)c, (const s16_021AE198 *)q, (const s16_021AE198 *)p);
    if (r != -1) {
        if (func_021AE7A8(a, b, r, (void *)d) == 1)
            r = -1;
    }
    return r;
}





int func_021AE1FC(int a, void *b, int c)
{
    int s0, s4, s8;
    u16 sc;
    void *s14;
    int s10;
    void *r4;
    void *r7;

    s0 = c;
    s4 = func_02188CE8((void *)a);
    r4 = func_021A3074(func_02188CB4((void *)a));
    r7 = func_02188C7C((void *)a);
    s14 = 0;
    s10 = 0;
    while (func_0216DD1C(r7, (struct Rec **)(&s14), (u32 *)(&s10)) == 1) {
        if (s14 != r4 && (b == 0 || b != s14)) {
            s8 = func_021AE288(s4, (int)s14, (int)r4, &sc);
            if (s8 != -1 && func_021AE890((u32)((void *)a), (u32)s14) == 0) {
                func_021AE8B4((struct S *)s0, (u32)s14, s8, sc);
                return 1;
            }
        }
    }
    return 0;
}





int func_021AE288(int a, int b, int c, u16 *d)
{
    int q[2];
    int p[2];
    int r4, r7, sc;
    u16 r5;

    r4 = func_021AE79C(b);
    if ((u16)(r4 + 0xffff) <= 1) {
        r5 = 0;
        r7 = (s16_021AE288)func_0216D63C((char *)b, 0);
        func_0216D828(b, q);
        func_0216D828(c, p);
        if (r4 == 1) {
            sc = func_0216D5F8((void *)b);
            r4 = func_021AE348(sc, r7, (const s16_021AE288 *)q, (const s16_021AE288 *)p);
            if (r4 != r5 - 1 && func_021AE7A8(b, sc, r4, (void *)a) == 0) {
                *d = sc;
                return r4;
            }
        } else {
            do {
                r4 = func_021AE348(r5, r7, (const s16_021AE288 *)q, (const s16_021AE288 *)p);
                if (r4 != -1 && func_021AE7A8(b, r5, r4, (void *)a) == 0) {
                    *d = r5;
                    return r4;
                }
                r5++;
            } while (r5 < 4);
        }
    }
    return -1;
}





/*
 * Addresses are Black-image addresses.
 * func_021AE348 dispatches through the four-entry table at 0x021D9338,
 * whose entries are the four unlabelled leaves that follow it; the unit
 * covers the whole 232-byte run.
 */
int func_021AE348(int idx, int a, const s16_021AE348 *p, const s16_021AE348 *q)
{
    return d_021D9338[idx](a, p, q);
}





int func_021AE360(int a, const s16_021AE348 *p, const s16_021AE348 *q)
{
    if (p[0] == q[0] && p[1] == q[1] && q[2] < p[2] && q[2] >= p[2] - a)
        return p[2] - q[2];
    return -1;
}





int func_021AE394(int a, const s16_021AE348 *p, const s16_021AE348 *q)
{
    if (p[0] == q[0] && p[1] == q[1] && q[2] > p[2] && q[2] <= p[2] + a)
        return q[2] - p[2];
    return -1;
}





int func_021AE3C8(int a, const s16_021AE348 *p, const s16_021AE348 *q)
{
    if (p[2] == q[2] && p[1] == q[1] && q[0] < p[0] && q[0] >= p[0] - a)
        return p[0] - q[0];
    return -1;
}





int func_021AE3FC(int a, const s16_021AE348 *p, const s16_021AE348 *q)
{
    if (p[2] == q[2] && p[1] == q[1] && q[0] > p[0] && q[0] <= p[0] + a)
        return q[0] - p[0];
    return -1;
}





u32 func_021AE430(u32 a, u32 x, u32 y)
{
    u32 h;
    u32 *p;

    h = (u32)func_020122C0((void *)a, 0, func_021AE754, 8);
    p = func_020124E8((struct Obj *)h);
    p[0] = x;
    p[1] = y;
    return h;
}





void *func_021AE454(int a, int b, S24 *src, int c)
{
    char *p = (char *)func_02030734(a, 0x38, 1, (const char *)&d_021DE138, 0x1fa);

    *(S24 *)(p + 8) = *src;
    ((struct Obj07517 *)p)->f20 = 0;
    ((struct Obj07517 *)p)->f24 = c;
    ((struct Obj07517 *)p)->f30 = b;
    ((struct Obj07517 *)p)->f34 = func_02188CB4((void *)b);
    return p;
}





int func_021AE498(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216DA5C((void *)(((struct Obj09181 *)((u8 *)(a)))->f8)) == 1) {
    func_0216DB04((void *)(((struct Obj09181 *)((u8 *)(a)))->f8));
}
((struct Obj09181 *)((u8 *)(a)))->f0 = 1;
return 1;
}





int func_021AE4B4(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216DA5C((void *)(((struct Obj05863 *)((u8 *)(a)))->f8)) == 1) {
    return 0;
}
func_0216D5E0(((struct Obj05863 *)((u8 *)(a)))->f8, ((((struct Obj05863 *)((u8 *)(a)))->f10 << 16) >> 16));
func_0216DAF8((void *)(((struct Obj05863 *)((u8 *)(a)))->f8));
((struct Obj05863 *)((u8 *)(a)))->f0 = 2;
return 1;
}





int func_021AE4E0(Task *p)
{
    if (func_0216D454(func_021A3074(p->f34)) == 0)
        return 0;
    p->state = 3;
    switch (func_0216D5A0(p->f08)) {
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
        p->state = 7;
        break;
    }
    return 1;
}





int func_021AE524(u32 a)
{
if (func_0216D3CC(((struct Obj07220 *)((u8 *)(a)))->f8) == 1) {
    func_0216D410((void *)(((struct Obj07220 *)((u8 *)(a)))->f8), func_02197E7C(((((struct Obj07220 *)((u8 *)(a)))->f10 << 16) >> 16), 0));
    ((struct Obj07220 *)((u8 *)(a)))->f0 = 4;
}
return 0;
}




int func_021AE550(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216D454((void *)((struct Obj12098 *)((u8 *)(a)))->f8) == 0) {
    return 0;
}
((struct Obj12098 *)((u8 *)(a)))->f0 = 5;
return 1;
}




int func_021AE56C(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj07221 *)((u8 *)(a)))->f2C = func_021BB528(func_02188CD0((u8 *)(((struct Obj07221 *)((u8 *)(a)))->f30)), ((struct Obj07221 *)((u8 *)(a)))->f8, 0, 0);
((struct Obj07221 *)((u8 *)(a)))->f0 = 6;
return 0;
}




int func_021AE58C(u32 a, u32 b, u32 c, u32 d)
{
if (func_021BB5C8(((struct Obj09182 *)((u8 *)(a)))->f2C) == 1) {
    func_021AC154(((struct Obj09182 *)((u8 *)(a)))->f2C);
    ((struct Obj09182 *)((u8 *)(a)))->f0 = 9;
}
return 0;
}




int func_021AE5A8(u32 a, u32 b, u32 c, u32 d)
{
func_0216D410((void *)(((struct Obj12099 *)((u8 *)(a)))->f8), 101);
((struct Obj12099 *)((u8 *)(a)))->f0 = 8;
return 0;
}




int func_021AE5BC(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216D454((void *)((struct Obj12100 *)((u8 *)(a)))->f8) == 1) {
    ((struct Obj12100 *)((u8 *)(a)))->f0 = 9;
}
return 0;
}
