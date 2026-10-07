/*
 * file:     btlv_effvm_p58.c
 * unit:     yes
 * function: func_021FE9BC, func_021FE9F0, func_021FEAA0, func_021FEAC0, func_021FEB78, func_021FEBAC, func_021FEE9C, func_021FEEA8
 * address:  0x021FE9BC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02051394  0x02051394  arm
 *   func_021F89BC  0x021F89BC  thumb  ov094
 *   _ll_mul        0x0209C054  arm
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FF134  0x021FF134  thumb  ov094
 *   func_021FFD9C  0x021FFD9C  thumb  ov094
 *   func_021FF468  0x021FF468  thumb  ov094
 *   func_021FF630  0x021FF630  thumb  ov094
 *   d_02209DD8  0x02209DD8  data  ov094
 *   func_02030734  0x02030734  arm
 *   func_02014B08  0x02014B08  thumb
 *   func_020163B0  0x020163B0  thumb
 *   func_020163B4  0x020163B4  thumb
 *   d_0220AE7C     0x0220AE7C  data   ov094
 *   func_021FF0F8  0x021FF0F8  thumb  ov094
 *   func_02014BA8  0x02014BA8  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_022019F4 0x022019F4 thumb ov094
 *   func_02016374 0x02016374 thumb
 *   func_02014C08 0x02014C08 thumb
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   func_021F935C 0x021F935C thumb ov094
 *   func_021FF2D8 0x021FF2D8 thumb ov094
 *   func_021FF870 0x021FF870 thumb ov094
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021FFF38 0x021FFF38 thumb ov094
 *   func_021F821C 0x021F821C thumb ov094
 *   func_021FFE24 0x021FFE24 thumb ov094
 *   func_021FF260 0x021FF260 thumb ov094
 *   func_021FF304 0x021FF304 thumb ov094
 *   func_021FF498 0x021FF498 thumb ov094
 *   func_021FFDF8 0x021FFDF8 thumb ov094
 *   func_02014D2C  0x02014D2C  thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017EAC 0x02017EAC thumb
 *   func_02019C90 0x02019C90 thumb
 *   func_0202D034 0x0202D034 thumb
 *   func_020159C8 0x020159C8 thumb
 *   func_02015FD4 0x02015FD4 thumb
 *   func_02015D94 0x02015D94 thumb
 *   func_02015D88 0x02015D88 thumb
 *   func_02015F2C 0x02015F2C thumb
 *   func_022003EC 0x022003EC thumb ov094
 *   func_022018A8 0x022018A8 thumb ov094
 *   func_0220055C 0x0220055C thumb ov094
 *   func_02201A20 0x02201A20 thumb ov094
 *   func_022006B4 0x022006B4 thumb ov094
 *   func_02201718 0x02201718 thumb ov094
 */
#include "../../matched/include/Obj13604.h"

struct McssSys;
struct Obj;
struct Rec;
struct Sub150;
typedef unsigned short u16;

typedef struct {
    unsigned int *reg;      /* 0x00 */
    void *obj;              /* 0x04 */
} Ctx;

typedef unsigned int   u32;

typedef int fx32;

typedef long long fx64;

typedef struct { fx32 x, y, z; } VecFx32;

typedef enum { SLOT_0, SLOT_MAX = 8 } Slot;

typedef struct {
    void *h;
    char pad04[0x44];
    int k48;
    unsigned int f0 : 1;
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FEAC0;

typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
} Flags_021FEAC0;

typedef struct {
    int *cb;                /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FEAC0 e[14];            /* 0x008 */
    Flags_021FEAC0 flags;            /* 0x510 */
    char pad514[0x534 - 0x514];
    int active;             /* 0x534 */
    int scaleEven;          /* 0x538 */
    int scaleOdd;           /* 0x53c */
    u16 heap;               /* 0x540 */
} Work_021FEAC0;

typedef enum { KEY_0 } Key;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x24];
    void *task;             /* 0x28 */
    char pad2c[0x30];
} Entry_021FEB78;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FEB78 e[14];            /* 0x008 */
} Work_021FEB78;

typedef unsigned char  u8;

typedef unsigned long long u64;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int f2 : 5;
    unsigned int f7 : 1;
    unsigned int f8 : 1;
    unsigned int f9 : 2;
    unsigned int f11 : 1;
    int f50;                /* 0x50 */
    int f54;                /* 0x54 */
    int f58;                /* 0x58 */
} Entry_021FEBAC;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FEBAC e[14];            /* 0x008 */
    unsigned int pad510 : 2;    /* 0x510 */
    unsigned int f510 : 1;
    int m514;
    int m518;
    int m51c;
    int m520;
    int m524;
    int m528;               /* 0x528 */
} Work_021FEBAC;

typedef struct { int x, y, z; } Vec;

typedef struct { Vec orient, pos; } Vectors;

typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b34 : 2;
    unsigned int b5 : 1;
} Flags_021FEEA8;

extern void func_02051394(u32 *p);
extern void func_021F89BC(void *h);
extern int func_021F8694(void);
extern void func_021FF134(char *p, int a, int b);
extern int func_021FFD9C(char *p, int key);
extern int func_021FF468(void *u, int i, int mode);
extern void func_021FF630(char *w, int i, int kind, VecFx32 *q, int n, int f48, int f4c);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02014B08(u32 id, void *heap);
extern void func_020163B0(char *p, int v);
extern void func_020163B4(void *o, int v);
extern void func_021FF0F8(Work_021FEB78 *w, int key);
extern void func_02014BA8(u8 *a0);
extern u32 func_020307B0(void *p);
extern int func_022019F4(char *p, int key);
extern void func_02016374(void *h);
extern void func_02014C08(char *self);
extern u32 func_0203F0A8(void);
extern int func_021F935C(int x);
extern int func_021FF2D8(Work_021FEBAC *w, int key);
extern void func_021FF870(Work_021FEBAC *w, int key, int kind, int a, int b);
extern int func_021F7EB4(void);
extern int func_021FFF38(char *p, int key);
extern int func_021F821C(int key, int *a, int *b);
extern void func_021FFE24(Work_021FEBAC *w, int key);
extern void func_021FF260(Work_021FEBAC *w, int key, int mode);
extern void func_021FF304(Work_021FEBAC *w, int key, int mode);
extern void func_021FF498(char *p, int key, void *v);
extern void func_021FFDF8(Work_021FEBAC *w, int key, int a, int b);
void func_02014D2C(struct McssSys *sys);
extern u32 func_02017E1C(void *, u32, u32);
extern u32 func_02017EAC(void *p);
extern u32 func_02019C90(u16, u16, u32);
extern int func_0202D034(u32, u32);
extern struct Rec *func_020159C8(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
extern void func_02015FD4(char *p, int v);
extern void func_02015D94(char *p, int *src);
extern void func_02015D88(char *p, u16 value);
extern void func_02015F2C(void *, u32, void *, u32);
extern void func_022003EC(void *, void *, int *, int);
extern void func_022018A8(void *, Vec *, int);
extern void func_0220055C(void *, int, int);
extern int func_02201A20(int a, int b, int *o1, u16 *o2, int *o3);
extern void func_022006B4(void *, int);
extern void func_02201718(int i);
void func_021FE9BC(void *h, Ctx *c);
void func_021FE9F0(fx32 a, fx32 b, int n, int f48, int f4c);
int func_021FEAA0(int v);
Work_021FEAC0 *func_021FEAC0(int mode, int a1, u16 a2);
void func_021FEB78(Work_021FEB78 *w);
void func_021FEBAC(Work_021FEBAC *w);
void func_021FEE9C(int *p);
void func_021FEEA8(char *w, void *src, int key);
extern int d_02209DD8[];
extern char d_0220AE7C[];


void func_021FE9BC(void *h, Ctx *c)
{
    u16 line = *(volatile u16 *)0x04000006;

    if (line >= 0xc0 && line <= 0xc8) {
        func_02051394(c->obj);
        *c->reg &= ~0x10000u;
        func_021F89BC(h);
    }
}


/*
 * Lever: the loop counter is an enum (keeps the `cmp r4,#8; bge` entry guard
 * and the unfolded (1<<12)>>1 rounding constants after it), see
 * docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md.
 */
void func_021FE9F0(fx32 a, fx32 b, int n, int f48, int f4c)
{
    Slot i;
    VecFx32 v;
    fx32 s;
    fx32 t;

    func_021FF134((char *)func_021F8694(), a, b);
    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)func_021F8694(), i)) {
            s = func_021FF468((void *)func_021F8694(), i, 1);
            if (i & 1)
                t = (fx32)(((fx64)s * b + ((fx64)(1 << 12) >> 1)) >> 12);
            else
                t = (fx32)(((fx64)s * a + ((fx64)(1 << 12) >> 1)) >> 12);
            v.x = t;
            v.y = t;
            v.z = 1 << 12;
            func_021FF630((char *)func_021F8694(), i, 1, &v, n, f48, f4c);
        }
    }
}


int func_021FEAA0(int v)
{
    unsigned int i;

    for (i = 0; i < 11; i++) {
        if (v == d_02209DD8[i])
            return 1;
    }
    return 0;
}


/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * Lever: `u16 a2` (the strh of the heap id makes the parameter 16-bit; it
 * is spilled at entry and reloaded, as the image does).
 *
 * witness outside the range): func_020163B0 (0x020163B0) and func_020163B4
 * (0x020163B4).  Both are Ilias's; verified C (one --thumb, no --region,
 * EXACT each):
 *     void func_020163B0(char *p, int v) { *(int *)(p + 0x48) = v; }
 *     typedef struct { char pad[0x2c]; unsigned int b0 : 1; unsigned int b1 : 1; } Obj;
 *     void func_020163B4(Obj *p, int v) { p->b1 = v; }
 * Re-run this file once layout/matched/arm9 shards for both exist.
 */
Work_021FEAC0 *func_021FEAC0(int mode, int a1, u16 a2)
{
    Work_021FEAC0 *w;
    int v = 0xe;
    int i;

    w = func_02030734(a2, 0x5b4, 1, d_0220AE7C, 0x184);
    w->obj = func_02014B08(v, (void *)a2);
    w->cb = (int *)a1;
    w->heap = a2;
    v += 0xf2;
    func_020163B0(w->obj, v);
    func_020163B4(w->obj, 1);
    w->active = 1;
    w->scaleEven = 0x1000;
    w->scaleOdd = 0x1000;
    w->flags.b0 = (mode == 2);
    w->flags.b1 = (mode == 3);
    for (i = 0; i < 14; i++)
        w->e[i].k48 = 0xff;
    return w;
}


void func_021FEB78(Work_021FEB78 *w)
{
    Key i;

    for (i = 0; i < 14; i++) {
        if (func_021FFD9C((char *)w, i))
            func_021FF0F8(w, i);
    }
    func_02014BA8(w->obj);
    func_020307B0(w);
}


/*
 * lever: enum loop counter keeps both entry guards; a separate local k for the
 *   first loop index puts idx at sp+8 and flag at sp+4 (one shared idx swapped them).
 */
void func_021FEBAC(Work_021FEBAC *w)
{
    Key i;
    int k;
    int idx;
    int flag;
    int a;
    int b;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)w, i)) {
            k = func_022019F4((char *)w, i);
            if (w->e[k].f11) {
                w->e[k].f11 = 0;
                func_02016374(w->e[k].h);
            }
        }
    }
    func_02014C08(w->obj);
    if (w->f510 == 0) {
        for (i = 0; i < 8; i++) {
            if (func_021FFD9C((char *)w, i)
                && (u32)(((u64)func_0203F0A8() * 100) >> 32) == 0
                && (func_021F935C(i) & w->m528) == 0
                && func_021FF2D8(w, i) == 0)
                func_021FF870(w, i, 2, 4, 1);
            if (func_021FFD9C((char *)w, i) == 0)
                continue;
            idx = func_022019F4((char *)w, i);
            flag = 0;
            if (func_021F7EB4() && w->e[idx].f8) {
                w->e[idx].f8 = 0;
                w->e[idx].f7 = 1;
            }
            if (func_021F7EB4() && w->e[idx].f7)
                continue;
            w->e[idx].f7 = 0;
            if (func_021FFF38((char *)w, i) & 4)
                continue;
            if (func_021F821C(i, &a, &b) == 0)
                continue;
            if (w->e[idx].f1 == 1) {
                if (w->e[idx].f54 == 0)
                    w->e[idx].f54 = 1;
                if (w->e[idx].f58++ > 0x18) {
                    flag = 1;
                    w->e[idx].f58 = 0;
                    w->e[idx].f50 += w->e[idx].f54;
                    if (w->e[idx].f50 == 0 || w->e[idx].f50 == 12)
                        w->e[idx].f54 *= -1;
                }
            }
            switch (b) {
            case 3:
                func_021FFE24(w, i);
                func_021FF260(w, i, 3);
                func_021FF304(w, i, 3);
                func_021FF498((char *)w, i, (void *)0x555);
                w->e[idx].f1 = 1;
                break;
            case 1:
                if (flag == 1)
                    func_021FFDF8(w, i, (u8)w->e[idx].f50, 0x1ef);
                func_021FF260(w, i, 4);
                func_021FF304(w, i, 3);
                w->e[idx].f1 = 1;
                break;
            case 2:
                if (flag == 1)
                    func_021FFDF8(w, i, 8, 0x7def);
                func_021FF260(w, i, 4);
                func_021FF304(w, i, 2);
                w->e[idx].f1 = 1;
                break;
            case 5:
                if (flag == 1)
                    func_021FFDF8(w, i, (u8)w->e[idx].f50, 0xf);
                func_021FF260(w, i, 4);
                func_021FF304(w, i, 3);
                w->e[idx].f1 = 1;
                break;
            case 4:
            case 7:
                if (flag == 1)
                    func_021FFDF8(w, i, (u8)w->e[idx].f50, 0x3c0f);
                func_021FF260(w, i, 4);
                func_021FF304(w, i, 3);
                w->e[idx].f1 = 1;
                break;
            case 8:
            default:
                if (w->e[idx].f1 == 1) {
                    func_021FFE24(w, i);
                    func_021FF260(w, i, 4);
                    func_021FF304(w, i, 3);
                    func_021FF498((char *)w, i, (void *)0x1000);
                    w->e[idx].f1 = 0;
                    w->e[idx].f54 = 0;
                    w->e[idx].f50 = 0;
                    w->e[idx].f58 = 0;
                }
                break;
            }
            if (b == 8) {
                if ((u32)(a - 2) <= 1)
                    func_021FF498((char *)w, i, (void *)0x555);
                else
                    func_021FF498((char *)w, i, (void *)0x1000);
            }
        }
    }
}


void func_021FEE9C(int *p)
{
    func_02014D2C((struct McssSys *)p[1]);
}

/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 * levers: grouped vectors fix stack order; integer address arithmetic on the
 * second buffer argument prevents CSE; b34 is one two-bit assignment.
 * Verified scratch C, EXACT (blocker_02015D94_r1.log):
 * void func_02015D94(char *p, int *src) {
 *     *(int *)(p + 0x17c) = src[0];
 *     *(int *)(p + 0x180) = src[1];
 *     *(int *)(p + 0x184) = src[2];
 * }
 * Verified scratch C, EXACT (blocker_02015D88_r1.log):
 * typedef unsigned short u16;
 * void func_02015D88(char *p, u16 value) { *(u16 *)(p + 0x17a) = value; }
 */
void func_021FEEA8(char *w, void *src, int key)
{
    int i;
    int off;
    int visible;
    u16 angle;
    Vectors vectors;
    u32 a, b;
    for (i = 0; i < 14; i++) {
        if (*(void **)(w + i * 0x5c + 8) == 0)
            break;
    }
    if (key < 14 && i < 14) {
        off = i * 0x5c;
        *(int *)(w + 0x48 + off) = 0;
        ((Flags_021FEEA8 *)(w + 0x54 + off))->b0 = 0;
        ((Flags_021FEEA8 *)(w + 0x54 + off))->b1 = 0;
        ((Flags_021FEEA8 *)(w + 0x54 + off))->b5 = 0;
        ((Flags_021FEEA8 *)(w + 0x54 + off))->b2 = ((struct Obj13604 *)w)->f534;
        *(int *)(w + 0x50 + off) = key;
        *(u32 *)(w + 0x3c + off) = func_02017E1C(src, 0, 0);
        *(u32 *)(w + 0x44 + off) = func_02017E1C(src, 0x98, 0);
        if (func_02017EAC(src) == 1)
            *(int *)(w + 0x48 + off) |= 2;
        func_022003EC(w, src, (int *)(w + 0xc + off), key);
        func_022018A8(w, &vectors.pos, key);
        *(void **)(w + 8 + off) = func_020159C8(((struct Obj13604 *)w)->f4, vectors.pos.x, vectors.pos.y, vectors.pos.z, (void *)((u32)w + 0xc + off));
        func_0220055C(w, key, 1);
        *(u32 *)(w + 0x34 + off) = func_02017E1C(src, 5, 0);
        *(u32 *)(w + 0x38 + off) = func_02017E1C(src, 0x6f, 0);
        *(u16 *)(w + 0x40 + off) = func_02019C90(*(u32 *)(w + 0x34 + off), *(u32 *)(w + 0x38 + off), 0x26);
        a = func_02017E1C(src, 0xa0, 0);
        b = func_02017E1C(src, 0xa1, 0);
        *(u16 *)(w + 0x42 + off) = func_0202D034(a, b);
        if (func_02201A20(*(int *)(w + 0x34 + off), key, (int *)(&vectors.orient), &angle, &visible) == 0) {
            vectors.orient.x = -0x400;
            vectors.orient.y = 0;
            vectors.orient.z = -0x600;
            angle = 0xf800;
            visible = 1;
        }
        if (visible == 0)
            func_02015FD4(*(void **)(w + 8 + off), 0);
        else {
            func_02015D94(*(void **)(w + 8 + off), (int *)(&vectors.orient));
            func_02015D88(*(void **)(w + 8 + off), angle);
        }
        ((Flags_021FEEA8 *)(w + 0x54 + off))->b34 = 3;
        func_022006B4(w, key);
        func_02015F2C(*(void **)(w + 8 + off), i, (void *)func_02201718, 1);
    }
}
