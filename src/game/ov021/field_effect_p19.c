/*
 * file:     field_effect_p19.c
 * unit:     yes
 * function: func_021AC68C, func_021AC6C0, func_021AC6D4, func_021AC740, func_021AC760
 * address:  0x021AC68C
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
 *   d_021DE070  0x021DE070  data
 *   func_02188C90  0x02188C90  thumb  ov021
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021ABE28  0x021ABE28  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_021AC1F0  0x021AC1F0  thumb  ov021
 *   func_020500F0  0x020500F0  arm
 *   d_021D911C     0x021D911C  data  a2
 *   d_021D90EC  0x021D90EC  data
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 */
struct X;
struct BbActRec;
struct BbActSys;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct P { u32 f0; u32 f4; u32 w[4]; } P;

typedef signed int     s32;

typedef struct Arg_021AC6D4 { u32 a; u8 b4, b5, b6, b7; u32 c; } Arg_021AC6D4;

typedef struct X { u32 f0; u32 f4; u16 h[8]; } X;

typedef struct V3 { int x, y, z; } V3;

typedef struct Arg_021AC760 {
    u32 f0;
    u32 f4;
    int f8;
    int fc;
    u16 h10;
    u16 h12;
    V3 pos;
    int f20;
} Arg_021AC760;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021ABE14(u8 *p);
extern u32 func_02188C90(u8 *p);
extern u32 func_020307B0(void *p);
extern u32 func_021ABE24(u8 *p);
extern void *func_02188C80(void *p);
extern u8 func_021ABE28(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern void func_021AC1F0(struct X *x, void *b);
extern u16 func_020500F0(struct BbActSys *o, const struct BbActRec *recs, u32 n);
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
extern int func_021ABEA0(u32 a, u32 b);
extern u16 func_0216D588(void *p);
extern u16 func_0216D590(void *p);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern void func_02164280(int x, int y, int *p);
extern u32 func_0216D8AC(void *p);
extern int func_0216D55C(int a0, int a1);
extern void func_02163E58(u32 a, V3 *v, int *out);
extern void func_021ABFA8(u32 a, u8 *b, u32 c, u32 d, Arg_021AC760 *e, u32 f);
P *func_021AC68C(int a, int heap);
void func_021AC6C0(u32 a, u8 *p);
void func_021AC6D4(u32 *p);
void func_021AC740(X *x);
void func_021AC760(u32 a, u32 b, u32 c, int d);
extern char d_021DE070[];
extern u16 d_021D911C[];
extern u8 d_021D90EC[];


P *func_021AC68C(int a, int heap)
{
    P *p;

    p = (P *)func_02030734(heap, 0x18, 1, d_021DE070, 0x6c);
    p->f0 = a;
    p->f4 = func_02188C90((u8 *)func_021ABE14((u8 *)a));
    func_021AC6D4((u32 *)p);
    return p;
}



/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AC6C0(u32 a, u8 *p)
{
    func_021AC740((struct X *)p);
    func_020307B0(p);
}



/*
 * Addresses are Black-image addresses.
 */
void func_021AC6D4(u32 *p)
{
    Arg_021AC6D4 s;
    int i;
    u32 r7 = func_021ABE24((u8 *)p[0]);
    u16 *t;
    u32 lv;
    func_02188C80((void *)func_021ABE14((u8 *)p[0]));
    lv = func_021ABE28((u8 *)p[0]);
    s.b4 = 0;
    s.b5 = 0x24;
    s.b6 = 0x20;
    s.b7 = 0x20;
    s.c = 1;
    t = d_021D911C + lv;
    for (i = 0; i < 8; i++) {
        s.a = (u32)func_02046E24(r7, t[i * 4]);
        func_021AC1F0((struct X *)p[0], (void *)s.a);
        ((u16 *)p)[4 + i] = func_020500F0((struct BbActSys *)p[1], (const struct BbActRec *)(&s), 1);
    }
}



void func_021AC740(X *x)
{
    int i;

    for (i = 0; i < 8; i++)
        func_02050278((struct BbActSys *)x->f4, x->h[i], 1);
}



/*
 * The v.z -= 0x2000 adjust is written in both arms of the if; the
 * compiler tail-merges the arms and keeps the 2 of 0x2000 in r6
 * (docs/idioms/a-constant-shifted-in-a-merged-tail-is-a-statement-repeated-in-each-arm.md).
 */
void func_021AC760(u32 a, u32 b, u32 c, int d)
{
    V3 v;
    Arg_021AC760 s;
    int tmp;

    if (d >= 8)
        return;
    s.f0 = func_021ABEA0(a, 2);
    s.f4 = b;
    s.f20 = d;
    s.h10 = func_0216D588((void *)b);
    s.h12 = func_0216D590((void *)b);
    s.f8 = func_0216D83C((void *)b);
    s.fc = func_0216D86C((void *)b);
    func_02164280((s16)s.f8, (s16)s.fc, (int *)(&v));
    v.y = func_0216D8AC((void *)b);
    if (func_0216D55C(b, 0x2000) != 0) {
        v.y += 7 * 0x1000;
        v.z -= 0x2000;
    } else {
        func_02163E58(b, &v, &tmp);
        v.y = tmp + 9 * 0x1000;
        v.z -= 0x2000;
    }
    s.pos = v;
    func_021ABFA8(a, d_021D90EC, 0, c, &s, 0);
}
