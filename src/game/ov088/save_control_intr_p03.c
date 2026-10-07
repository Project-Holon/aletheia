/*
 * file:     save_control_intr_p03.c
 * unit:     yes
 * function: func_021BC8AC, func_021BC944, func_021BC9C0, func_021BC9E8, func_021BCCBC, func_021BCCCC, func_021BCCF4, func_021BCD64, func_021BCD88, func_021BCDB4, func_021BCDD0, func_021BCDEC, func_021BCE20, func_021BCE3C
 * address:  0x021BC8AC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_021BC870  0x021BC870  thumb  ov088
 *   func_020061E4  0x020061E4  thumb
 *   func_02035C08  0x02035C08  arm
 *   d_021BD83C     0x021BD83C  data  a1
 *   tbl_020A1B38   0x020A1B38  data
 *   func_02061CA4  0x02061CA4  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_020433E0  0x020433E0  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_0207D534  0x0207D534  arm
 *   func_02049624  0x02049624  arm
 *   func_0204989C  0x0204989C  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02040588  0x02040588  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0204361C  0x0204361C  arm
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   d_021BD944     0x021BD944  data  a4
 *   d_021BD8F4     0x021BD8F4  data  a4
 *   d_021BD904     0x021BD904  data  a4
 *   d_021BD924     0x021BD924  data  a4
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_021BCE80  0x021BCE80  thumb  ov088
 *   func_021BCF18  0x021BCF18  thumb  ov088
 *   func_020312F8  0x020312F8  arm
 *   d_021BD574     0x021BD574  data  a4
 *   ov088_id       0x00000058  data  a1
 *   func_021BCF44  0x021BCF44  thumb  ov088
 *   func_021BCF6C  0x021BCF6C  thumb  ov088
 *   func_021BCFEC  0x021BCFEC  thumb  ov088
 *   func_021BD078  0x021BD078  thumb  ov088
 *   func_021BD0F4  0x021BD0F4  thumb  ov088
 *   func_021BD21C  0x021BD21C  thumb  ov088
 *   func_020221A4  0x020221A4  thumb
 *   func_021BD118  0x021BD118  thumb  ov088
 *   func_021BD188  0x021BD188  thumb  ov088
 *   func_021BD1EC  0x021BD1EC  thumb  ov088
 *   func_0201FEBC  0x0201FEBC  thumb
 *   func_021BD23C  0x021BD23C  thumb  ov088
 */
#include "../../matched/include/Obj00578.h"

#define reg_G2_BLDCNT      (*(volatile u16 *)0x04000050)
#define reg_G2S_DB_BLDCNT  (*(volatile u16 *)0x04001050)
#define reg_GX_DISPCNT     (*(volatile u32 *)0x04000000)
#define reg_GXS_DB_DISPCNT (*(volatile u32 *)0x04001000)
struct Obj0203159C;
struct BgTemplate;
struct DispConfig;
struct DispVram;
struct S020315D4;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct C12 {
    char c[12];
} C12;

typedef unsigned short u16;

typedef signed short s16;

typedef signed int s32;

typedef struct W {
    u8 pad[0x18];
    u16 f18;
    u16 f1a;
} W;

typedef enum { Z0 } Zero;

typedef struct {
    u16 state;
    u16 pad;
    int count;
} St;

extern u32 func_020362DC(void);
extern void func_021BC870(u8 *);
extern void func_020061E4(u32);
extern int func_02035C08(const void *p);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void  func_0203064C(unsigned int a, unsigned int heap, unsigned int size);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void  func_02082BCC(void *p, int v, int n);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_020409B4(u32 layer);
extern void func_0203F9B4(void);
extern void func_020315D4(struct S020315D4 *a);
extern void func_020306F0(unsigned int heap);
extern void func_021BCE80(u8 *p, int *a1);
extern void func_021BCF18(void *, int *);
extern void func_020312F8(u32 a1, u32 a2, u32 a3);
extern void func_021BCF44(void);
extern void func_021BCF6C(void);
extern void func_021BCFEC(u8 *p);
extern void func_021BD078(int *p);
extern void func_021BD0F4(void **p);
extern void func_021BD21C(void);
extern u32 func_020221A4(void);
extern void func_021BD118(int *p, u32 mode);
extern int func_021BD188(char *p);
extern void func_021BD1EC(unsigned char *p);
extern u32 func_0201FEBC(u8 *p);
extern void func_021BD23C(void);
int func_021BC8AC(u8 *p);
s32 func_021BC944(W *w);
int func_021BC9C0(struct Obj0203159C *a0);
int func_021BC9E8(int a0, int a1, int *mode, St *st);
int func_021BCCBC(int a0);
int func_021BCCCC(struct Obj0203159C *a0);
int func_021BCCF4(int a, int *st, int c, void *p);
int func_021BCD64(int a0);
void func_021BCD88(void *p, int *st);
void func_021BCDB4(void *p, int *st);
void func_021BCDD0(void *p, int *st);
void func_021BCDEC(void *p, int *st);
void func_021BCE20(void *p, int *st);
void func_021BCE3C(char *p, int *out);
extern C12 d_021BD83C;
extern s16 tbl_020A1B38[];
extern const u8 d_021BD944[];
extern const u8 d_021BD8F4[];
extern const u8 d_021BD904[];
extern const u8 d_021BD924[];
extern char d_021BD574[];
extern char ov088_id[];


int func_021BC8AC(u8 *p)
{
    int r;
    u32 k;
    int t;
    C12 s;

    if ((func_020362DC() & 0x40) || (func_020362DC() & 0x80)) {
        if (p[0] == 0)
            p[0] = 1;
        else
            p[0] = 0;
        func_021BC870(p);
        func_020061E4(0x548);
    }
    k = func_020362DC();
    r = 1;
    if (k & r) {
        func_020061E4(0x54C);
        if (p[0] != 0)
            r = 2;
        return r;
    }
    s = d_021BD83C;
    t = func_02035C08(&s);
    if (t != -1) {
        func_020061E4(0x54C);
        return t == 0 ? 1 : 2;
    }
    return 0;
}


s32 func_021BC944(W *w)
{
    s32 n = w->f18 + 0x400;
    s32 v;
    s16 s;
    u32 b, g, r;

    if (n >= 0x10000)
        w->f18 = w->f18 - 0xFC00;
    else
        w->f18 = n;
    v = tbl_020A1B38[(w->f18 >> 4) * 2 + 1] + 0x1000;
    s = v / 2;
    b = (u8)(0x1d + (-(s * 8) >> 12));
    r = (u8)(0x19 + (s * -0x14 >> 12));
    g = (u8)(0x1e + (s * -0xf >> 12));
    w->f1a = r | (g << 5) | (b << 10);
    return func_02061CA4((void *)0xf, 0x6c, (u32)(&w->f1a), 2);
}


int func_021BC9C0(struct Obj0203159C *a0)
{
    func_0203064C(1, 0x16, 0x70000);
    func_02082BCC(func_0203159C(a0, 8, 0x16), 0, 8);
    return 1;
}


static inline void GX_SetVisibleWnd(int window)
{
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xE000 | (window << 13);
}


static inline void GXS_SetVisibleWnd(int window)
{
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~0xE000 | (window << 13);
}


/*
 * Case 1's fade call takes its zero from an enum local set at the top of
 * the arm: the enum is not folded, so the zero stays in r5 (the register
 * the stack-argument zeros use) through to `adds r2, r5, #0`. A literal 0,
 * an int local set to 0, and int-typed func_02049624 parameters all give
 * `movs r2, #0` scheduled after r0/r1 (6 bytes out); the permuter (300,
 * --types) found nothing.
 * volatile: DISPCNT 0x04000000 and DB_DISPCNT 0x04001000 read-modify-written by the SDK inlines GX_SetVisibleWnd/GXS_SetVisibleWnd (0x021BCA3A, 0x021BCA46)
 */
int func_021BC9E8(int a0, int a1, int *mode, St *st)
{
    Zero z;

    switch (st->state) {
    case 0:
        func_02043534(0);
        func_020435F4(0);
        reg_G2_BLDCNT = 0;
        reg_G2S_DB_BLDCNT = 0;
        GX_SetVisibleWnd(0);
        GXS_SetVisibleWnd(0);
        func_020433E0((const struct DispVram *)d_021BD944);
        func_0203F8F4(0x16);
        func_0203FC28((struct DispConfig *)d_021BD8F4);
        func_0203FCA0(1, (const struct BgTemplate *)d_021BD904, 0);
        func_0203FCA0(5, (const struct BgTemplate *)d_021BD924, 0);
        if (*mode == 1) {
            func_0207D534((volatile u16 *)0x0400006C, -16);
            func_0207D534((volatile u16 *)0x0400106C, -16);
            st->state = 7;
        } else {
            func_0207D534((volatile u16 *)0x0400006C, 16);
            func_0207D534((volatile u16 *)0x0400106C, 16);
            st->state = 1;
        }
        break;
    case 1:
        z = Z0;
        func_02049624((void *)0x1a, (void *)0xc, (void *)1, 0, 0, 1, 0x16);
        func_0204989C(0x1a, 0xd, 1, 0, 0, 1, 0x16);
        func_02049B40(0x1a, 0xb, 0, 0, 0, 0x16);
        func_02049624((void *)0x1a, (void *)0xc, (void *)5, 0, 0, 1, 0x16);
        func_0204989C(0x1a, 0xe, 5, 0, 0, 1, 0x16);
        func_02049B40(0x1a, 0xb, 4, 0, 0, 0x16);
        func_02040588(1, 1);
        func_02040588(5, 1);
        func_0204363C(1);
        func_0204361C();
        func_0204E720(0xc, 0x10, z, 2);
        st->state = 2;
        break;
    case 2:
        if (func_0204E804() == 0) {
            st->state = 3;
            st->count = 0;
        }
        break;
    case 3:
        if (++st->count > 0x5a)
            st->state = 4;
        if (func_020362DC() & 0xb)
            st->state = 4;
        break;
    case 4:
        func_0204E720(3, 0, 0x10, 2);
        st->state = 5;
        break;
    case 5:
        if (func_0204E804() == 0) {
            st->state = 6;
            st->count = 0;
        }
        break;
    case 6:
        if (++st->count > 0x1e) {
            st->state = 7;
            st->count = 0;
        }
        break;
    case 7:
        func_02049624((void *)0xa4, (void *)1, (void *)1, 0, 0x8000, 0, 0x16);
        func_0204989C(0xa4, 2, 1, 0, 0, 0, 0x16);
        func_02049B40(0xa4, 0, 0, 0, 0, 0x16);
        func_02049624((void *)0xa4, (void *)3, (void *)5, 0, 0x8000, 0, 0x16);
        func_0204989C(0xa4, 4, 5, 0, 0, 0, 0x16);
        func_02049B40(0xa4, 0, 4, 0, 0, 0x16);
        func_020409B4(1);
        func_020409B4(5);
        func_02040588(1, 1);
        func_02040588(5, 1);
        func_0204363C(1);
        func_0204361C();
        func_0204E720(3, 0x10, 0, 2);
        st->state = 8;
        break;
    case 8:
        if (func_0204E804() == 0)
            st->state = 9;
        break;
    case 9:
        if (++st->count > 0x5a) {
            st->state = 10;
            st->count = 0;
        }
        break;
    case 10:
        func_0204E720(3, 0, 0x10, 2);
        st->state = 0xb;
        break;
    case 11:
        if (func_0204E804() == 0)
            st->state = 0xc;
        break;
    case 12:
        if (++st->count > 0x1e)
            st->state = 0xd;
        break;
    case 13:
        func_0203F9B4();
        return 1;
    }
    return 0;
}


int func_021BCCBC(int a0)
{
    func_020315D4((struct S020315D4 *)a0);
    func_020306F0(0x16);
    return 1;
}


int func_021BCCCC(struct Obj0203159C *a0)
{
    func_0203064C(1, 0x81, 0x30000);
    func_02082BCC(func_0203159C(a0, 0x2c, 0x81), 0, 0x2c);
    return 1;
}


/*
 * EXACT*: the extent runs two bytes long (trailing padding pair).
 */
int func_021BCCF4(int a, int *st, int c, void *p)
{
    switch (*st) {
    case 0:
        func_021BCD88(p, st);
        break;
    case 1:
        func_021BCDB4(p, st);
        break;
    case 2:
        func_021BCDD0(p, st);
        break;
    case 3:
        func_021BCDEC(p, st);
        break;
    case 4:
        func_021BCE20(p, st);
        break;
    case 5:
        func_021BCE3C(p, st);
        break;
    case 6:
        func_021BCE80(p, st);
        break;
    case 7:
        func_021BCF18(p, st);
        break;
    case 8:
        return 1;
    }
    return 0;
}


int func_021BCD64(int a0)
{
    func_020315D4((struct S020315D4 *)a0);
    func_020306F0(0x81);
    func_020312F8((u32)ov088_id, (u32)d_021BD574, 0);
    return 1;
}


void func_021BCD88(void *p, int *st)
{
    func_021BCF44();
    func_021BCF6C();
    func_021BCFEC(p);
    func_021BD078(p);
    func_021BD0F4(p);
    func_021BD21C();
    *st = 1;
}


void func_021BCDB4(void *p, int *st)
{
    if (func_020221A4() == 1) {
        func_021BD118(p, 0);
        *st = 2;
    }
}


void func_021BCDD0(void *p, int *st)
{
    if (func_021BD188(p) == 0) {
        func_021BD1EC(p);
        *st = 3;
    }
}


void func_021BCDEC(void *p, int *st)
{
    int r = func_0201FEBC(((struct Obj00578 *)p)->f20);

    if (r == 0)
        goto a;
    if (r == -2)
        goto b;
    return;
a:
    func_021BD118(p, 1);
    *st = 4;
    return;
b:
    func_021BD23C();
    *st = 7;
}


void func_021BCE20(void *p, int *st)
{
    if (func_021BD188(p) == 0) {
        func_021BD1EC(p);
        *st = 5;
    }
}


/*
 * EXACT*: the extent runs 20 bytes long; the follower at 0x021BCE70 is an
 * unlabelled tail-call stub (ldr r0,[pc]; ldr r3,[pc]; ldr r0,[r0]; bx r3).
 * The switch value is unsigned so that case 0xFFFFFFFE sorts after case 0.
 */
void func_021BCE3C(char *p, int *out)
{
    unsigned r = func_0201FEBC((u8 *)(*(char * *)&((struct Obj00578 *)p)->f20));
    switch (r) {
    case 0:
        func_021BD118((int *)p, 2);
        *out = 6;
        break;
    case 0xFFFFFFFE:
        func_021BD23C();
        *out = 7;
        break;
    }
}
