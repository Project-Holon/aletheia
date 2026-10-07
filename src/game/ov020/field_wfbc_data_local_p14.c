/*
 * file:     field_wfbc_data_local_p14.c
 * unit:     yes
 * function: func_021876B0, func_021876E0, func_0218774C, func_021877A8, func_02187808, func_02187860, func_02187884, func_021878C0, func_02187914, func_02187938, func_0218793C, func_0218794C, func_02187A10, func_02187A38, func_02187B38, func_02187BBC, func_02187C20, func_02187CCC, func_02187CEC, func_02187CFC, func_02187D20, func_02187D24, func_02187D28, func_02187D30, func_02187D40, func_02187D54, func_02187D74
 * address:  0x021876B0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02061CA4 0x02061CA4 arm
 *   d_02187ECC 0x02187ECC data ov020 a4
 *   func_020362DC  0x020362DC  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020124EC  0x020124EC  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_0202E8B8  0x0202E8B8  thumb
 *   func_02043658 0x02043658 arm
 *   func_02188DA0 0x02188DA0 thumb ov021
 *   func_02043534 0x02043534 arm
 *   func_0204047C 0x0204047C arm
 *   func_020414AC 0x020414AC arm
 *   func_020433E0  0x020433E0  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   d_02187E58     0x02187E58  data  ov020
 *   d_02187E28     0x02187E28  data  ov020
 *   d_02187E38     0x02187E38  data  ov020
 *   func_020490F4  0x020490F4  arm
 *   func_02049250  0x02049250  arm
 *   func_02062A98  0x02062A98  arm
 *   func_02040E78  0x02040E78  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02062A4C  0x02062A4C  arm
 *   func_02040B1C  0x02040B1C  arm
 *   func_02062B30  0x02062B30  arm
 *   func_020409E0  0x020409E0  arm
 *   func_02049238  0x02049238  arm
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_0207D658  0x0207D658  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_0207D534  0x0207D534  arm
 *   func_0209BE04  0x0209BE04  arm
 *   func_0209CE10  0x0209CE10  arm
 *   func_0209C77C  0x0209C77C  arm
 *   func_0209C95C  0x0209C95C  arm
 *   func_0209CB8C  0x0209CB8C  arm
 *   func_0209C494  0x0209C494  arm
 *   func_0202E8A4  0x0202E8A4  thumb
 *   func_02040588  0x02040588  arm
 *   func_02188DB0  0x02188DB0  thumb  ov021
 *   func_02187D94  0x02187D94  thumb  ov020
 *   func_02189A50 0x02189A50 thumb ov021
 */
#include "../../matched/include/Obj12549.h"
#include "../../matched/include/Obj19478.h"
#include "../../matched/include/Obj01651.h"
#include "../../matched/include/Obj01207.h"
#include "../../matched/include/Obj19482.h"
#include "../../matched/include/Obj19483.h"
#include "../../matched/include/Obj12551.h"
#include "../../matched/include/Obj12552.h"

struct Desc;
struct Obj;
struct BgTemplate;
struct DispConfig;
struct DispVram;
struct ArcFile;
struct NitroFileHeader;
typedef unsigned short u16;

typedef struct { int index; char *base; } Pair;

typedef signed int     s32;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct { int a; int b; u16 c; int d; int e; u8 f; u8 g; u8 pad[10];
                 int h; int i; } T;

typedef struct {
    void *p;        /* 0x00 */
    int f04;        /* 0x04 */
    u16 f08;        /* 0x08 */
    int f0c;        /* 0x0c */
    int f10;        /* 0x10 */
    u8 f14;         /* 0x14 */
    u8 f15;         /* 0x15 */
    u8 pad16[10];
    int f20;        /* 0x20 */
    int f24;        /* 0x24 */
} Work02187808;

extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern u32 func_020362DC(void);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u32 *func_020124EC(struct Obj *p);
extern u16 func_02188C84(u8 *p);
extern u8 func_0202E8B8(int);
extern u32 func_02043658(void);
extern void func_02188DA0(void);
extern void func_02043534(u32 planes);
extern void func_0204047C(int idx, unsigned short val);
extern void func_020414AC(int a);
void func_020433E0(const struct DispVram *c);
void func_0203F8F4(u16 heapId);
void func_0203FC28(struct DispConfig *cfg);
void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020403F4(unsigned int i);
extern void func_0203F9B4(void);
void *func_020490F4(unsigned int id, unsigned int heap);
void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
s32 func_02062A98(struct NitroFileHeader *file, void **out);
void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4);
u32 func_020307B0(void *p);
s32 func_02062A4C(struct NitroFileHeader *file, void **out);
void func_02040B1C(int index, const void *src, u32 size, u32 tile);
int func_02062B30(void *file, void **out);
void func_020409E0(u32 index, const void *src, u32 mode, u32 offset);
void func_02049238(void *x);
void func_0207D658(u32 addr, int plane, int brightness);
void func_0207D63C(u32 addr, int plane1, int plane2, int ev1, int ev2);
void func_0207D534(volatile u16 *reg, int brightness);
u32 func_0209BE04(u32 x);
u32 func_0209CE10(u32 a, u32 b);
u32 func_0209C77C(u32 a, u32 b);
u32 func_0209C95C(u32 a, u32 b);
u32 func_0209CB8C(u32 a, u32 b);
u32 func_0209C494(u32 x);
u8 func_0202E8A4(u8 x);
void func_02040588(unsigned char which, unsigned char enable);
void func_02188DB0(u8 *a);
void func_02187D94(void *o);
extern void func_02189A50(char *p, int v);
void func_021876B0(Pair *p, int tick);
int func_021876E0(void *unused, int *s, char *o);
void *func_0218774C(int a, int b, u8 c, u8 d);
void *func_021877A8(int a, int b, u8 c, u8 d, int e, int f);
void *func_02187808(void *p, u8 a1, u8 a2);
void func_02187860(char *p);
void func_02187884(char *unused);
void func_021878C0(char *o);
void func_02187914(char *p);
void func_02187938(char *p);
void func_0218793C(char *p);
void func_0218794C(int sel, int b);
void func_02187A10(char *p, int st);
void func_02187A38(const char *o, int st);
void func_02187B38(char *o, int st);
int func_02187BBC(char *o, int st);
void func_02187C20(char *o, int *p, int st);
void func_02187CCC(char *p, int *s);
void func_02187CEC(char *p);
void func_02187CFC(char *p);
u32 func_02187D20(char *p);
u32 func_02187D24(char *p);
void func_02187D28(u32 *p);
int func_02187D30(char *p);
int func_02187D40(char *p);
int func_02187D54(char *p);
int func_02187D74(char *p);
extern int d_02187ECC[];
extern char d_02187E58[];
extern char d_02187E28[];
extern char d_02187E38[];

void func_021876B0(Pair *p, int tick)
{
    func_02061CA4((void *)1, (u32)(p->base + (u16)p->index * 8), d_02187ECC[(tick & 31) / 8], 8);
}


int func_021876E0(void *unused, int *s, char *o)
{
    switch (*s) {
    case 0: func_02187CEC(o); break;
    case 1: case 3: break;
    case 2: func_02187A10(o, *s); break;
    case 4: func_02187A10(o, *s); break;
    case 5: func_02187CFC(o); return 1;
    }
    if (func_020362DC() & 1) { if (func_02187D20(o) == 0) func_02187D28((u32 *)o); }
    ((struct Obj12549 *)o)->f18 = ((struct Obj12549 *)o)->f18 + 1;
    func_02187CCC(o, s);
    return 0;
}


/*
 * c must be u8 (as in the twin func_02187808): with an int c the scheduler
 * hoists its spilled reload above the strb of d.
 */
void *func_0218774C(int a, int b, u8 c, u8 d)
{
    void *r7 = func_020122C0((void *)a, 0, func_021876E0, 0x28);
    T *t = func_020124E8(r7);
    int x = (int)func_020124EC(r7);
    t->a = a; t->b = b; t->c = func_02188C84((u8 *)b); t->d = 0; t->e = 0;
    t->f = d; t->g = func_0202E8B8(c); t->h = 0; t->i = 0;
    func_02187C20((char *)t, (int *)x, 0);
    return r7;
}


void *func_021877A8(int a, int b, u8 c, u8 d, int e, int f)
{
    void *r7 = func_020122C0((void *)a, 0, func_021876E0, 0x28);
    T *t = func_020124E8(r7);
    int x = (int)func_020124EC(r7);
    t->a = a; t->b = b; t->c = func_02188C84((u8 *)b); t->d = 0; t->e = 0;
    t->f = d; t->g = func_0202E8B8(c); t->h = e; t->i = f;
    func_02187C20((char *)t, (int *)x, 0);
    return r7;
}


/*
 * Allocator with callback (0x28-byte work area), then field setup and a
 * state-set call. a1 must be u8: with int a1 (a2 either int or u8) the
 * scheduler hoists the spilled a1 reload above the strb of a2.
 */
void *func_02187808(void *p, u8 a1, u8 a2)
{
    void *r0v = func_020122C0(p, 0, func_021876E0, 0x28);
    Work02187808 *w = func_020124E8(r0v);
    void *h = func_020124EC(r0v);

    w->p = p;
    w->f04 = 0;
    w->f08 = 4;
    w->f0c = 1;
    w->f10 = 0;
    w->f14 = a2;
    w->f15 = func_0202E8B8(a1);
    w->f20 = 0;
    w->f24 = 0;
    func_02187C20((char *)w, h, 0);
    return r0v;
}

/*
 * extent: two trailing zero alignment bytes.
 */
void func_02187860(char *p)
{
    switch (func_02187D20(p)) {
    case 0: func_02187884(p); break;
    case 1: func_021878C0(p); break;
    }
}

void func_02187884(char *unused)
{
    int n;
    n = func_02043658();
    func_02188DA0();
    func_02043534(n);
    func_0204047C(0, 1);
    func_0204047C(3, 0);
    func_0204047C(1, 3);
    func_0204047C(2, 3);
    func_020414AC(3);
}


void func_021878C0(char *o)
{
    func_020433E0((const struct DispVram *)d_02187E58);
    func_0203F8F4(((struct Obj19478 *)o)->f8);
    func_0203FC28((struct DispConfig *)d_02187E28);
    func_0203FCA0(3, (const struct BgTemplate *)d_02187E38, 0);
    func_0204047C(0, 1);
    func_0204047C(3, 0);
    func_0204047C(1, 3);
    func_0204047C(2, 3);
    func_020414AC(3);
}

void func_02187914(char *p)
{
    switch (func_02187D20(p)) {
    case 0: func_02187938(p); break;
    case 1: func_0218793C(p); break;
    }
}

void func_02187938(char *p)
{
}


/*
 * \n * symbols:\n *   func_020403F4  0x020403F4  arm\n *   func_0203F9B4  0x0203F9B4  arm\n
 */
void func_0218793C(char *p)
{
    func_020403F4(3);
    func_0203F9B4();
}


void func_0218794C(int sel, int b)
{
    int *l_c;
    int *l_8;
    int *l_4;
    void *x;
    void *v;
    int i0, i1, i2;

    switch (sel) {
    default:
    case 0:
        i0 = 0; i1 = 1; i2 = 2;
        break;
    case 1:
        i0 = 3; i1 = 4; i2 = 5;
        break;
    case 2:
        i0 = 6; i1 = 7; i2 = 8;
        break;
    case 3:
        i0 = 9; i1 = 10; i2 = 11;
        break;
    }
    x = func_020490F4(0x97, b);
    v = func_02049250(x, i0, b);
    func_02062A98(v, (void **)(&l_c));
    func_02040E78(3, (void *)l_c[3], 0x20, 0);
    func_020307B0(v);
    v = func_02049250(x, i1, b);
    func_02062A4C(v, (void **)(&l_8));
    func_02040B1C(3, (const void *)l_8[5], l_8[4], 0);
    func_020307B0(v);
    v = func_02049250(x, i2, b);
    func_02062B30(v, (void **)(&l_4));
    func_020409E0(3, l_4 + 3, l_4[2], 0);
    func_020307B0(v);
    func_02049238(x);
}

void func_02187A10(char *p, int st)
{
    switch (func_02187D20(p)) {
    case 0: func_02187A38(p, st); break;
    case 1: func_02187B38(p, st); break;
    }
}


/*
 * Blend fade on the main engine (BLDCNT 0x04000050) plus the sub engine's
 * master brightness (0x0400106C), driven by the ratio o->0x18 / o->0x1c.
 * The object pointer is `const char *`: through a const pointer mwcc lets the
 * loads after the G2x_SetBlendAlpha_ call ignore the outgoing stack-argument
 * store, so that store is scheduled last (+0x7E). With a plain `char *` it
 * moves up to +0x78 (8 bytes out); const casts on the loads alone do not.
 */
void func_02187A38(const char *o, int st)
{
    int v;

    if (st == 2) {
        func_0207D658(0x04000050, 8,
            (int)(16.0f * ((float)*(const u32 *)&((struct Obj01651 *)o)->f18 / (float)*(const u32 *)&((struct Obj01651 *)o)->f1C) + -16.0f));
    } else if (st == 4) {
        if (*(const u8 *)&((struct Obj01651 *)o)->f15 == *(const u8 *)&((struct Obj01651 *)o)->f14) {
            v = (int)(16.0f * ((float)*(const u32 *)&((struct Obj01651 *)o)->f18 / (float)*(const u32 *)&((struct Obj01651 *)o)->f1C));
            func_0207D63C(0x04000050, 8, 0x11, 16 - v, v);
            func_0207D534((volatile u16 *)0x0400106C,
                (int)(16.0f * ((float)*(const u32 *)&((struct Obj01651 *)o)->f18 / (float)*(const u32 *)&((struct Obj01651 *)o)->f1C) + -16.0f));
        } else {
            func_0207D658(0x04000050, 8,
                (int)(0.0f - 16.0f * ((float)*(const u32 *)&((struct Obj01651 *)o)->f18 / (float)*(const u32 *)&((struct Obj01651 *)o)->f1C)));
        }
    }
}


void func_02187B38(char *o, int st)
{
    u32 a, b;

    if (st == 2) {
        a = func_0209BE04(((struct Obj01651 *)o)->f18);
        b = func_0209BE04(((struct Obj01651 *)o)->f1C);
        b = func_0209CE10(a, b);
        b = func_0209C77C(0x41800000, b);
        b = func_0209C95C(0xC1800000, b);
        func_0207D658(0x04000050, 8, func_0209C494(b));
    } else if (st == 4) {
        a = func_0209BE04(((struct Obj01651 *)o)->f18);
        b = func_0209BE04(((struct Obj01651 *)o)->f1C);
        b = func_0209CE10(a, b);
        b = func_0209C77C(0x41800000, b);
        b = func_0209CB8C(0, b);
        func_0207D658(0x04000050, 8, func_0209C494(b));
    }
}


int func_02187BBC(char *o, int st)
{
    switch (st) {
    case 0:
        st = 1;
        break;
    case 1:
        st = 2;
        break;
    case 2:
        if (func_02187D30(o) == 1)
            st = 3;
        break;
    case 3:
        if (func_02187D30(o) == 1 || func_02187D24(o) == 1)
            st = 4;
        break;
    case 4:
        if (func_02187D30(o) == 1) {
            st = 5;
            if (((struct Obj01207 *)o)->f14 != ((struct Obj01207 *)o)->f15)
                st = 1;
        }
        break;
    case 5:
        break;
    }
    return st;
}


void func_02187C20(char *o, int *p, int st)
{
    switch (st) {
    case 0:
        func_02187860(o);
        break;
    case 1:
        ((struct Obj01207 *)o)->f15 = func_0202E8A4(((struct Obj01207 *)o)->f15);
        func_0218794C(((struct Obj01207 *)o)->f15, ((struct Obj01207 *)o)->f8);
        break;
    case 2:
        func_02040588(3, 1);
        func_02040588(0, 0);
        func_0207D534((volatile u16 *)0x0400006C, 0);
        func_0207D658(0x04000050, 8, -16);
        ((struct Obj01207 *)o)->f1C = func_02187D40(o);
        break;
    case 3:
        ((struct Obj01207 *)o)->f1C = func_02187D74(o);
        break;
    case 4:
        ((struct Obj01207 *)o)->f1C = func_02187D54(o);
        if (func_02187D20(o) == 0 && ((struct Obj01207 *)o)->f15 == ((struct Obj01207 *)o)->f14) {
            func_02188DB0((u8 *)(((struct Obj01207 *)o)->f4));
            func_02040588(3, 1);
            func_02187D94(o);
        }
        break;
    case 5:
        break;
    }
    *p = st;
    *(int *)&((struct Obj01207 *)o)->f18 = 0;
}

void func_02187CCC(char *p, int *s)
{
    int st;
    st = func_02187BBC(p, *s);
    if (*s != st) func_02187C20(p, s, st);
}

/*
 * sole setter body stores r1 at [r0 + 0x144], then returns. No code-start
 * witness. No owner source or ARM9/SDK matching performed.
 * 2026-10-04 (wD2 lane 02): witness filed: src/matched/ov/ov021_func_02189A50.c (EXACT, 8 bytes, str r1,[r0,#0x144]).
 * The symbols line already carries ov021. Expected EXACT after the integrator's manifest refresh.
 */
void func_02187CEC(char *p)
{
    void *q;
    q = *(void **)(p + 4);
    if (q != 0) func_02189A50(q, 1);
}

/*
 * sole setter body stores r1 at [r0 + 0x144], then returns. No code-start
 * witness. No owner source or ARM9/SDK matching performed.
 * 2026-10-04 (wD2 lane 02): witness filed: src/matched/ov/ov021_func_02189A50.c (EXACT). Compiled 34 vs listing 36
 * bytes is the trailing pool padding. Expected EXACT* after the integrator's manifest refresh.
 */
void func_02187CFC(char *p)
{
    func_02040588(3, 0);
    if (*(void **)(p + 4) != 0) func_02189A50(*(void **)(p + 4), 0);
    func_02187914(p);
}


u32 func_02187D20(char *p)
{
    return ((struct Obj19482 *)p)->fC;
}


u32 func_02187D24(char *p)
{
    return ((struct Obj19483 *)p)->f10;
}


void func_02187D28(u32 *p)
{
    p[4] = 1;
}


int func_02187D30(char *p)
{
    if (*(u32 *)&((struct Obj01207 *)p)->f1C < ((struct Obj01207 *)p)->f18)
        return 1;
    return 0;
}

int func_02187D40(char *p)
{
    if (func_02187D20(p) == 1) return 30;
    return 10;
}

int func_02187D54(char *p)
{
    if (func_02187D20(p) == 1) return 60;
    if (((struct Obj12551 *)p)->f15 == ((struct Obj12551 *)p)->f14) return 20;
    return 10;
}

int func_02187D74(char *p)
{
    if (func_02187D20(p) == 1) return 120;
    if (((struct Obj12552 *)p)->f15 == ((struct Obj12552 *)p)->f14) return 60;
    return 30;
}
