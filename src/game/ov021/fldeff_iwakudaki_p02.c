/*
 * file:     fldeff_iwakudaki_p02.c
 * unit:     yes
 * function: func_021ADD38, func_021ADD64, func_021ADD7C, func_021ADDE8, func_021ADE4C
 * address:  0x021ADD38
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
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021ABE8C  0x021ABE8C  thumb  ov021
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9290     0x021D9290  data  a4
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 */
struct Node;
struct Tagged;
struct Actor;
struct VecFx32;
struct T;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Rec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Q_021ADD38 { u32 f0; u32 f4; u32 arr[4]; u32 f18; u32 f1c; } Q_021ADD38;

typedef struct Q_021ADD64 { u32 f0; u32 f4; u32 arr[4]; u32 f18; u32 f1c; } Q_021ADD64;

typedef int s32;

typedef struct Vec3 { s32 x, y, z; } Vec3;

typedef struct Arg { unsigned a; Vec3 v; } Arg;

typedef struct Src { u32 f0; u32 f4; u32 arr[4]; } Src;

typedef struct Q_021ADDE8 { Src *src; u32 f4; u32 arr[4]; u32 f18; } Q_021ADDE8;

typedef struct Q_021ADE4C { u32 f0; u32 f4; u32 arr[4]; u32 f18; u32 f1c; } Q_021ADE4C;

extern void func_02046EFC(struct Tagged *p);
extern int func_020470D0(u32 *p);
extern void func_02030EAC(struct Node *n);
extern u32 func_02047204(struct Tagged *p);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
extern int func_021ABE8C(struct T *a, int b);
extern void func_021ABE30(int a, int *b, int c);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(int a, u8 *b, int c, int d, Arg *e, int f);
extern int func_021AC1AC(u32 a);
extern void func_021AC1CC(u32 a, u32 *b);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_0204762C(struct Rec *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
void func_021ADD38(Q_021ADD38 *q);
void func_021ADD64(u32 a, Q_021ADD64 *q);
void func_021ADD7C(int a, int b);
void func_021ADDE8(u32 a, Q_021ADDE8 *q);
void func_021ADE4C(u32 a, Q_021ADE4C *q);
extern u8 d_021D9290[];


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
    Arg s;
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
    func_021ABFA8(b, d_021D9290, 0, 0, &s, 0);
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
