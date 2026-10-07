/*
 * file:     fldeff_namipoke_p10.c
 * unit:     yes
 * function: func_021ADAAC, func_021ADB4C, func_021ADB5C
 * address:  0x021ADAAC
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
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9238     0x021D9238  data  a1
 *   d_021D9240     0x021D9240  data  a4
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct L {
    int f0;
    int f4;
    void *f8;
    int fc;
    u16 h10;
    u16 h12;
    int f14;
    u8 b18;
    u8 pad19[3];
    int f1c;
    int f20;
    int f24;
} L;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern unsigned int func_021ABE14(u8 *p);
extern unsigned int func_02188CFC(u8 *p);
extern int func_021ABEA0(u32 a, u32 b);
extern void *func_02082BCC(void *p, u8 v, unsigned n);
extern void *func_02188C7C(unsigned char *p);
extern u8 func_021ABFA8(int a, void *b, int c, int d, void *e, int f);
extern int func_021AC1E0(u32 a);
u8 func_021ADAAC(int a, u8 *b, int c, int d, int e, int f);
void func_021ADB4C(u32 a, int v);
void func_021ADB5C(int a, int v);
extern u8 d_021D9238[];
extern int d_021D9240[];


u8 func_021ADAAC(int a, u8 *b, int c, int d, int e, int f)
{
    int t;
    int k;
    int r;
    L l;

    t = func_021ABE14(b);
    if (func_02188CFC((u8 *)t) != 0) {
        return 0;
    }
    k = d_021D9238[f];
    r = func_021ABEA0((u32)b, k + 0x12);
    if (r == 0) {
        return 0;
    }
    func_02082BCC(&l, 0, 0x28);
    l.f0 = a;
    l.f4 = r;
    l.f8 = func_02188C7C((void *)t);
    l.h10 = c;
    l.h12 = d;
    l.f14 = k;
    if (k == 0) {
        l.b18 = f;
    } else {
        l.b18 = 0;
    }
    l.f1c = (c << 16) + 0x8000;
    l.f24 = (d << 16) + 0x8000;
    l.f20 = e;
    return func_021ABFA8((int)b, d_021D9240, 0, 1, &l, 0);
}


void func_021ADB4C(u32 a, int v)
{
    if (a != 0)
        ((u8 *)func_021AC1E0(a))[2] = v;
}


void func_021ADB5C(int a, int v)
{
    if (a != 0)
        ((u8 *)func_021AC1E0(a))[3] = v;
}
