/*
 * file:     field_g3dobj_p06.c
 * unit:     yes
 * function: func_021C6658, func_021C6664, func_021C6678, func_021C6694, func_021C66EC, func_021C6744, func_021C67A8, func_021C67D8, func_021C67F4, func_021C6828, func_021C6844, func_021C6854, func_021C6874, func_021C6940, func_021C69B4, func_021C6A90, func_021C6AE0, func_021C6AF0, func_021C6AF8, func_021C6AFC, func_021C6B18, func_021C6B8C, func_021C6BB4
 * address:  0x021C6658
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
 *   func_020478B8  0x020478B8  arm
 *   func_02047910  0x02047910  arm
 *   func_0204784C  0x0204784C  arm
 *   func_02047828  0x02047828  arm
 *   func_02047A60  0x02047A60  arm
 *   func_02047AC8  0x02047AC8  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02046E24   0x02046E24  arm
 *   func_02046F50   0x02046F50  arm
 *   func_02046F48   0x02046F48  arm
 *   func_0206E964   0x0206E964  arm
 *   func_02022040   0x02022040  thumb
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_02082C60  0x02082C60  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047788  0x02047788  arm
 *   func_02047738  0x02047738  arm
 *   func_02047504  0x02047504  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_0218ED54  0x0218ED54  thumb  ov021
 *   func_02030DA8  0x02030DA8  arm
 *   d_021DE4B8     0x021DE4B8  data  ov021  a4
 *   func_0218ED58  0x0218ED58  thumb  ov021
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _fsub          0x0209CB8C  arm
 *   _fadd          0x0209C95C  arm
 *   _ffix          0x0209C494  arm
 *   _fflt          0x0209BDBC  arm
 *   _f2d           0x0209BD38  arm
 *   _d2f           0x0209B64C  arm
 *   _dsqrt         0x0209C5E0  arm
 *   _fgr           0x0209BBB0  arm
 */
#include "../../matched/include/Obj18311.h"
#include "../../matched/include/Obj12952.h"
#include "../../matched/include/Obj12953.h"
#include "../../matched/include/Obj09694.h"
#include "../../matched/include/Obj18312.h"
#include "../../matched/include/Obj01866.h"
#include "../../matched/include/Obj06084.h"
#include "../../matched/include/Obj18313.h"
#include "../../matched/include/Obj06085.h"
#include "../../matched/include/Obj03145.h"

struct AnmCtl;
struct Arg;
struct Tagged;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Rec;
struct Node;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u32 a, b, c; } V_021C6664;

typedef struct { u32 f0; u32 f4; V_021C6664 f8; u8 pad[0x68 - 0x14]; } Elem_021C6664;

typedef struct { u8 pad[0xc]; Elem_021C6664 *fC; } Mgr_021C6664;

typedef struct { u32 k:2; u32 x:1; u32 b:1; u32 rest:28; u8 pad[0x64]; } Elem_021C6678;

typedef struct { u8 pad[0xc]; Elem_021C6678 *fC; } Mgr_021C6678;

typedef struct { u32 k : 2; } K;

typedef signed int     s32;

typedef struct { u32 a, b, c; } V_021C67A8;

typedef struct {
    u32 k:2;
    u32 b2:1;
    u32 b3:1;
    u32 b4:1;
    u32 b5:1;
    u32 rest:26;
    u16 f4;
    u16 f6;
    V_021C67A8 f8;
    u8 pad14[0x30];
    u32 f44;
    u8 pad48[0x20];
} Elem_021C67A8;

typedef struct { u8 pad[0x2c]; } Item;

typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; Item *f8; Elem_021C67A8 *fC; } Mgr_021C67A8;

typedef struct { u32 a, b, c; } V_021C67D8;

typedef struct {
    u32 k:2;
    u32 b2:1;
    u32 b3:1;
    u32 b4:1;
    u32 b5:1;
    u32 rest:26;
    u16 f4;
    u16 f6;
    V_021C67D8 f8;
    u8 pad14[0x30];
    u32 f44;
    u8 pad48[0x20];
} Elem_021C67D8;

typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; Item *f8; Elem_021C67D8 *fC; } Mgr_021C67D8;

typedef struct { u32 a, b, c; } V_021C67F4;

typedef struct {
    u32 k:2;
    u32 b2:1;
    u32 b3:1;
    u32 b4:1;
    u32 b5:1;
    u32 rest:26;
    u16 f4;
    u16 f6;
    V_021C67F4 f8;
    u8 pad14[0x30];
    u32 f44;
    u8 pad48[0x20];
} Elem_021C67F4;

typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; Item *f8; Elem_021C67F4 *fC; } Mgr_021C67F4;

typedef struct { u32 a, b, c; } V_021C6828;

typedef struct {
    u32 k:2;
    u32 b2:1;
    u32 b3:1;
    u32 b4:1;
    u32 b5:1;
    u32 rest:26;
    u16 f4;
    u16 f6;
    V_021C6828 f8;
    u8 pad14[0x30];
    u32 f44;
    u8 pad48[0x20];
} Elem_021C6828;

typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; Item *f8; Elem_021C6828 *fC; } Mgr_021C6828;

typedef struct { u32 f0; u32 f4; u32 f8[8]; u8 f28; u8 f29; } S;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u16 fC;
    u16 fE;
    u16 f10[8];
    u8 f20;
} D;

typedef struct {
    u8 pad0[0x30];
    u16 f30;
    u8 pad32[6];
    u32 f38;
} Pal;

typedef struct { u32 x, y, z; } V_021C69B4;

typedef struct {
    u32 k:2;
    u32 b2:1;
    u32 b3:1;
    u32 b4:1;
    u32 b5:1;
    u32 rest:26;
    u16 f4;
    u16 f6;
    V_021C69B4 f8;
    u32 f14;
    u32 f18;
    u32 f1C;
    u8 f20[0x24];
    u32 f44;
    u32 f48[8];
} Elem_021C69B4;

typedef struct { u32 f0; u16 f4; u16 f6; } P;

extern int func_020478B8(void *a, int idx, int amount);
extern int func_02047910(void *a, int idx, int amount);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);
extern int func_02047AC8(void *a0, struct Arg *a1);
extern void func_02047A60(void *a0, struct Arg *a1);
extern int func_02046FF8(int *self);
extern void *func_02046E24(u32 a0, u32 a1);
extern u32 func_02046F50(struct Tagged *p, u32 sel);
extern void *func_02046F48(struct Tagged *p);
extern unsigned char *func_0206E964(unsigned char *p);
extern void func_02022040(u16 *pal, int n, const u8 *table);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);
extern void func_02082C60(void *p, int v, int n);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_0207ADC4(void *p);
extern void func_0204762C(struct Rec *p);
extern int func_02047788(int *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern void func_02082A7C(u32 a, u32 b, u32 c);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u16 func_02188C84(u8 *p);
extern void *func_02188C58(void *p);
extern u32 func_02188D30(u8 *p);
extern u32 func_0218ED54(u8 *p);
extern void func_02030DA8(u32 a, void *cb, void *arg, int z);
extern void func_0218ED58(u8 *p, u32 v);
extern double _dsqrt(double x);
int func_021C6658(u32 a, u32 b);
void func_021C6664(Mgr_021C6664 *m, int idx, V_021C6664 *v);
void func_021C6678(Mgr_021C6678 *m, int idx, int v);
int func_021C6694(u32 *a, int idx, int v);
int func_021C66EC(u32 *a, int idx, int v);
void func_021C6744(u32 *a, int idx, int mode, u32 val);
int func_021C67A8(Mgr_021C67A8 *m, int idx, int i);
void func_021C67D8(Mgr_021C67D8 *m, int idx, int v);
void func_021C67F4(Mgr_021C67F4 *m, int idx);
void func_021C6828(Mgr_021C6828 *m, int idx, int v);
int func_021C6844(int a, int b);
void func_021C6854(S *s);
void func_021C6874(S *s, int unused, D *d, int mode, int flag);
void func_021C6940(u8 *p);
void func_021C69B4(Elem_021C69B4 *e, S *s, u16 idx, u16 id, u32 unused, V_021C69B4 *pos, int flag);
void func_021C6A90(u32 *p, u8 *q);
void func_021C6AE0(u32 a);
int func_021C6AF0(u32 a, u32 b, u32 c);
void func_021C6AF8(u32 *p, u32 v);
void func_021C6AFC(D *d, u16 v);
void func_021C6B18(u32 a, u16 b, u32 c);
void func_021C6B8C(void *task, P *p);
void func_021C6BB4(u8 *p);
extern int d_021DE4B8;


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C6658(u32 a, u32 b)
{
return ((((struct Obj18311 *)((u8 *)(a)))->fC + (b * 104)) + 8);
}

void func_021C6664(Mgr_021C6664 *m, int idx, V_021C6664 *v)
{
    m->fC[idx].f8 = *v;
}

void func_021C6678(Mgr_021C6678 *m, int idx, int v)
{
    m->fC[idx].b = v;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021C6694(u32 *a, int idx, int v)
{
    int r = 0;
    u8 *e = (u8 *)a[3] + idx * 0x68;
    int n, i;

    if (((K *)e)->k == 1) {
        n = *(u8 *)((u8 *)a[2] + ((struct Obj12952 *)e)->f4 * 0x2c + 0x28);
        for (i = r; i < n; i++) {
            if (func_020478B8((void *)(((struct Obj12952 *)e)->f44), (u16)i, v))
                r = 1;
        }
    } else if (((K *)e)->k == 2) {
        r = 1;
    }
    return r;
}


int func_021C66EC(u32 *a, int idx, int v)
{
    int r = 0;
    u8 *e = (u8 *)a[3] + idx * 0x68;
    int n, i;

    if (((K *)e)->k == 1) {
        n = *(u8 *)((u8 *)a[2] + ((struct Obj12953 *)e)->f4 * 0x2c + 0x28);
        for (i = r; i < n; i++) {
            if (func_02047910((void *)(((struct Obj12953 *)e)->f44), (u16)i, v))
                r = 1;
        }
    } else if (((K *)e)->k == 2) {
        r = 1;
    }
    return r;
}


/*
 * push {r0-r3} entry (0x021C6744); the fourth parameter's address is taken.
 *
 * Addresses are Black-image addresses.
 */
void func_021C6744(u32 *a, int idx, int mode, u32 val)
{
    u8 *e = (u8 *)a[3] + idx * 0x68;
    int n, i;

    if (((K *)e)->k == 1) {
        n = *(u8 *)((u8 *)a[2] + ((struct Obj09694 *)e)->f4 * 0x2c + 0x28);
        if (mode == 8) {
            i = 0;
            if (n > 0) {
                do {
                    func_0204784C((struct AnmCtl *)(((struct Obj09694 *)e)->f44), (u16)i, (s32 *)(&val));
                    i++;
                } while (i < n);
            }
        } else if (mode < n) {
            func_0204784C((struct AnmCtl *)(((struct Obj09694 *)e)->f44), (u16)mode, (s32 *)(&val));
        }
    }
}

int func_021C67A8(Mgr_021C67A8 *m, int idx, int i)
{
    int r = 0;
    Elem_021C67A8 *e = &m->fC[idx];
    if (e->k == 1) {
        if ((int)func_02047828((struct AnmCtl *)e->f44, (u16)i, &r) == 0)
            r = 0;
    }
    return r;
}

void func_021C67D8(Mgr_021C67D8 *m, int idx, int v)
{
    m->fC[idx].b4 = v;
}

void func_021C67F4(Mgr_021C67F4 *m, int idx)
{
    Elem_021C67F4 *e = &m->fC[idx];
    if (e->k == 1 && e->b3 == 0) {
        if (e->b2 == 1)
            func_02047AC8((void *)e->f44, (struct Arg *)(&e->f8));
        else
            func_02047A60((void *)e->f44, (struct Arg *)(&e->f8));
    }
}

void func_021C6828(Mgr_021C6828 *m, int idx, int v)
{
    m->fC[idx].b5 = v;
}


int func_021C6844(int a, int b)
{
return ((*(u32 *)((u8 *)(((struct Obj18312 *)((u8 *)(a)))->fC) + ((b * 104))) << 26) >> 31);
}

void func_021C6854(S *s)
{
    s->f29 = 0; if (s->f4 != 0) func_02046FF8((int *)s->f4); else func_02046FF8((int *)s->f0); s->f29 = 1;
}


void func_021C6874(S *s, int unused, D *d, int mode, int flag)
{
    u32 h;
    Pal *p;
    int i;

    if (d->f0 != 0)
        s->f0 = (u32)func_02046E24(d->f0, d->fC);
    if (d->f4 != 0)
        s->f4 = (u32)func_02046E24(d->f4, d->fE);
    if (flag != 0) {
        h = 0;
        if (s->f0 != 0)
            h = s->f0;
        if (s->f4 != 0)
            h = s->f4;
        if (func_02046F50((struct Tagged *)h, 2)) {
            p = (Pal *)func_0206E964((unsigned char *)((u32)func_02046F48((struct Tagged *)h)));
            func_02022040((u16 *)((u8 *)p + p->f38), (u32)(p->f30 << 3) / sizeof(u16), (const u8 *)flag);
        }
    }
    if (s->f0 != 0 || s->f4 != 0) {
        if (mode == 1)
            func_021C6854(s);
        else
            s->f29 = 2;
    }
    if (d->f20 != 0) {
        s->f28 = d->f20;
        MIi_CpuClear32(0, s->f8, sizeof(s->f8));
        for (i = 0; i < s->f28; i++)
            s->f8[i] = (u32)func_02046E24(d->f8, d->f10[i]);
    }
}


void func_021C6940(u8 *p)
{
    int i;
    u8 f = p[0x29];

    p[0x29] = 0;
    if (f == 1) {
        if (((struct Obj01866 *)p)->f4 != 0)
            func_020470D0((u32 *)(((struct Obj01866 *)p)->f4));
        else if (((struct Obj01866 *)p)->f0 != 0)
            func_020470D0((u32 *)(((struct Obj01866 *)p)->f0));
    }
    if (((struct Obj01866 *)p)->f4 != 0)
        func_02046EFC((struct Tagged *)(((struct Obj01866 *)p)->f4));
    if (((struct Obj01866 *)p)->f0 != 0)
        func_02046EFC((struct Tagged *)(((struct Obj01866 *)p)->f0));
    if (p[0x28] != 0) {
        for (i = 0; i < p[0x28]; i++)
            func_02046EFC((struct Tagged *)(*(u32 *)(p + 8 + i * 4)));
    }
    func_02082C60(p, 0, 0x2c);
    p[0x29] = 1;
}

/*
 * Unused 5th parameter puts pos/flag at sp+0x1c/0x20.  func_0204767C takes
 * the count as a third argument (the last f28 load is reused in r2).  The
 * h value starts (i = 0) before the e->f4/f6 stores, so it interferes with
 * idx in r2 and lands in r5, copied to r2 at the call.
 */
void func_021C69B4(Elem_021C69B4 *e, S *s, u16 idx, u16 id, u32 unused, V_021C69B4 *pos, int flag)
{
    int i;
    u32 m;

    i = 0;
    e->f4 = idx;
    e->f6 = id;
    if (s->f29 == 1) {
        i = s->f0;
        if (s->f4 != 0)
            i = s->f4;
    }
    m = (u32)func_02047400((void *)s->f0, id, (void *)i);
    if (s->f28 != 0) {
        MIi_CpuClear32(0, e->f48, sizeof(e->f48));
        for (i = 0; i < s->f28; i++)
            e->f48[i] = (u32)func_02047564((struct G3dOwner *)m, (const struct G3dOwner *)s->f8[i], 0);
    }
    e->f44 = (u32)func_0204767C(m, e->f48, s->f28);
    if (s->f28 != 0) {
        for (i = 0; i < s->f28; i++)
            func_020477A4((struct G3dSys *)e->f44, (u16)i);
    }
    if (pos != 0)
        e->f8 = *pos;
    if (flag != 0) {
        e->b2 = 1;
        e->f14 = 0x1000;
        e->f18 = 0x1000;
        e->f1C = 0x1000;
        func_0207ADC4(e->f20);
    }
    e->k = 1;
}


void func_021C6A90(u32 *p, u8 *q)
{
    u32 t;
    int i;

    if (p + 0x12) {
        for (i = 0; i < q[0x28]; i++)
            func_0204762C((struct Rec *)p[0x12 + i]);
    }
    if (p[0x11] != 0) {
        t = func_02047788((int *)p[0x11]);
        func_02047738((struct Rec *)p[0x11]);
        func_02047504((struct Rec *)t);
    }
    func_02082C60(p, 0, 0x68);
}


/*
 * Tail call with a zero first argument and a constant size.
 *
 * Addresses are Black-image addresses.
 */
void func_021C6AE0(u32 a)
{
    func_02082A7C(0, a, 0x24);
}


int func_021C6AF0(u32 a, u32 b, u32 c)
{
((struct Obj06084 *)((u8 *)(a)))->f0 = b;
((struct Obj06084 *)((u8 *)(a)))->fC = c;
return a;
}


/*
 * Field setter at +0x8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C6AF8(u32 *p, u32 v)
{
    ((struct Obj18313 *)p)->f8 = v;
}

void func_021C6AFC(D *d, u16 v)
{
    d->f10[d->f20] = v;
    d->f20++;
}


void func_021C6B18(u32 a, u16 b, u32 c)
{
    u32 h = func_02188C84((u8 *)a);
    u32 x = (u32)func_02188C58((void *)a);
    u32 y = func_02188D30((u8 *)a);
    u32 *e;

    e = (u32 *)func_02030734((u16)((h & 0x7FFF) | 0x8000), 0x10, 0, (const char *)&d_021DE4B8, 0x5F);
    ((struct Obj06085 *)e)->f4 = 0;
    ((struct Obj06085 *)e)->f6 = b;
    e[2] = func_0218ED54((u8 *)x);
    e[3] = c + func_0218ED54((u8 *)x);
    e[0] = a;
    func_02030DA8(y, (void *)func_021C6B8C, e, 0);
}

void func_021C6B8C(void *task, P *p)
{
    func_021C6BB4((u8 *)p);
    p->f4++;
    if (p->f6 < p->f4) {
        func_020307B0(p);
        func_02030EAC(task);
    }
}


/*
 * Lever: `t = 1.0f; t *= a / b;` keeps the fmul by 1.0f; a plain `1.0f * x`
 * or `x * 1.0f` folds away. The FX32 round (x > 0 ? x*4096+0.5 : x*4096-0.5)
 * must go through one float temp so the _ffix and the call are shared.
 *
 * Addresses are Black-image addresses.
 */
void func_021C6BB4(u8 *p)
{
    u32 h = (u32)func_02188C58((void *)(((struct Obj03145 *)p)->f0));
    u32 n = ((struct Obj03145 *)p)->f6;
    float t, a, b, v;

    if (((struct Obj03145 *)p)->f4 <= n) {
        t = 1.0f;
        t *= (float)(u32)((struct Obj03145 *)p)->f4 / (float)n;
        t = (float)_dsqrt((double)t);
        a = (float)((struct Obj03145 *)p)->f8 / 4096.0f;
        b = (float)((struct Obj03145 *)p)->fC / 4096.0f;
        v = (1.0f - t) * a + t * b;
        if (v > 0.0f)
            v = 4096.0f * v + 0.5f;
        else
            v = 4096.0f * v - 0.5f;
        func_0218ED58((u8 *)h, (int)v);
    }
}
