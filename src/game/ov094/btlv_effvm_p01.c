/*
 * file:     btlv_effvm_p01.c
 * unit:     yes
 * function: func_021F6560, func_021F6898, func_021F6934, func_021F69B0, func_021F69E8, func_021F6A18, func_021F6A28, func_021F6AA8, func_021F6AD0, func_021F6B04, func_021F6CF0, func_021F6D5C, func_021F6DD4, func_021F6DEC, func_021F6E1C
 * address:  0x021F6560
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
 *   sub_02030734 0x02030734 arm
 *   func_02048F60 0x02048F60 arm
 *   func_02046DB8 0x02046DB8 arm
 *   func_02046FF8 0x02046FF8 arm
 *   func_02047400 0x02047400 arm
 *   func_02047564 0x02047564 arm
 *   func_0204767C 0x0204767C arm
 *   func_020477A4 0x020477A4 arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   func_02046F48 0x02046F48 arm
 *   func_0206E964 0x0206E964 arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   sub_020307B0 0x020307B0 arm
 *   d_0220AC40 0x0220AC40 data
 *   func_0204762C  0x0204762C  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02047738  0x02047738  arm
 *   func_02047504  0x02047504  arm
 *   func_02047910  0x02047910  arm
 *   func_021F9364  0x021F9364  thumb  ov094
 *   func_02047A60 0x02047A60 arm
 *   d_0220AC50 0x0220AC50 data ov094 a1
 */
#include "../../matched/include/Obj18549.h"
#include "../../matched/include/Obj18551.h"

struct G3dOwner;
struct G3dRec;
struct Tagged;
struct G3dSys;
struct Rec;
struct Arg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int kind, a, b, c; } Ent_021F6560;

typedef struct {
    int f0;
    int ids[4][4];
} Rec;

typedef struct {
    int f0, f4, f8;
    int sx, sy, sz;
    int matrix[9];
} Xf;

typedef struct {
    void *f0;
    int n;
    Ent_021F6560 *arr[2];
    void **f10;
    void **f14[2];
    void *h1c[2];
    void *h24[2];
    Xf xf[2];
    void **fa4;
    void **fa8;
    u8 fac, fad;
    u8 padae[10];
    u16 heap;
    u16 padba;
} Obj_021F6560;

typedef struct {
    void *f0;           /* 0x00 */
    int n;              /* 0x04 */
    void *f8[2];        /* 0x08 */
    void **f10;         /* 0x10 */
    void **f14[2];      /* 0x14 */
    void *f1c[2];       /* 0x1c */
    void *f24[2];       /* 0x24 */
    char pad2c[0xa4 - 0x2c];
    void *fa4;          /* 0xa4 */
    void **fa8;         /* 0xa8 */
} Obj_021F6898;

typedef struct {
    int kind;       /* 0x00 */
    int f4;
    int f8;
    int fc;
} Ent_021F6934;

typedef struct {
    int f0;
    int n;              /* 0x04 */
    Ent_021F6934 *arr[2];        /* 0x08 */
    char pad10[0x24 - 0x10];
    void *h[2];         /* 0x24 */
    char pad2c[0xa4 - 0x2c];
    char sub[0x10];     /* 0xa4 */
} Obj_021F6934;

typedef struct {
    char pad[0x24];
    void *h[2];             /* 0x24 */
    char xf[2][0x3c];       /* 0x2c */
    char padA4[0xb4 - 0xa4];
    unsigned off : 2;       /* 0xb4 */
} Obj_021F69B0;

typedef struct {
    char pad[0xac];
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    unsigned char f5;
    unsigned short f6;
} S69E8;

typedef struct { char pad[0xB4]; u32 f : 2; u32 rest : 30; } Obj_021F6A28;

typedef struct {
    int state;
    int armed;
    int a;
    int b;
} Entry;

typedef struct {
    char pad[8];
    Entry *tab[1];
} Obj_021F6AA8;

typedef struct {
    int pad0;
    int n;              /* 0x04 */
    Entry *x;           /* 0x08 */
    Entry *y;           /* 0x0c */
} Obj_021F6AD0;

typedef struct { int kind, a, b, c; } Ent_021F6B04;

typedef struct {
    void *f0;
    int n;
    Ent_021F6B04 *f8;
    void **fc;
    void **f10;
    void *f14;
    void *f18;
    int f1c, f20, f24;
    int f28, f2c, f30;
    int matrix[9];
    void **f58;
    void **f5c;
    u8 f60, f61;
    u8 pad62[10];
    u16 heap;
    u16 pad6e;
} Obj_021F6B04;

typedef struct {
    void *f0;
    int n;              /* 0x04 */
    void *f8;
    void **fc;
    void **f10;
    void *f14;
    void *f18;
    char pad1c[0x58 - 0x1c];
    void *f58;
    void **f5c;
} Obj_021F6CF0;

typedef struct {
    int kind;       /* 0x00 */
    int f4;
    int f8;
    int fc;
} Ent_021F6D5C;

typedef struct {
    int f0;
    int n;              /* 0x04 */
    Ent_021F6D5C *arr;           /* 0x08 */
    char pad0c[0x0c];
    void *h18;          /* 0x18 */
    char pad1c[0x58 - 0x1c];
    char sub[0x10];     /* 0x58 */
    u32 bit0 : 1;       /* 0x68 */
    u32 bit1 : 1;
} Obj_021F6D5C;

typedef struct {
    char pad[0x18];
    void *h;            /* 0x18 */
    int v[3];           /* 0x1c */
    char pad28[0x68 - 0x28];
    unsigned b0 : 1;    /* 0x68 */
} Obj_021F6DD4;

typedef struct {
    char pad[0x60];
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    unsigned char f5;
    unsigned short f6;
} S6DEC;

extern void *sub_02030734(u32, u32, int, const char *, u16);
extern void *func_02048F60(u32, u32, u32);
extern void *func_02046DB8(u32, u32);
extern int func_02046FF8(int *);
extern void *func_02047400(void *, u32, void *);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_0207ADC4(int *);
extern void *func_02046F48(struct Tagged *p);
extern unsigned char *func_0206E964(unsigned char *p);
extern void func_0207DCF8(void *);
extern u32 sub_020307B0(void *p);
extern void func_0204762C(struct Rec *p);
extern void func_02046EFC(struct Tagged *p);
extern u32 func_020307B0(void *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern int func_02047910(void *a, int idx, int amount);
extern void func_021F9364(void *p);
extern void func_02047A60(void *a0, struct Arg *a1);
Obj_021F6560 *func_021F6560(int mode, int group, int variant, u16 heap);
void func_021F6898(Obj_021F6898 *o);
void func_021F6934(Obj_021F6934 *o);
void func_021F69B0(Obj_021F69B0 *p);
void func_021F69E8(S69E8 *p, unsigned char a, unsigned char b, unsigned char c, unsigned short d);
int func_021F6A18(char *p);
void func_021F6A28(Obj_021F6A28 *o, u32 mode, u32 on);
void func_021F6AA8(Obj_021F6AA8 *p, int i, int j, int a, int b);
int func_021F6AD0(Obj_021F6AD0 *p);
Obj_021F6B04 *func_021F6B04(int unused, int group, u8 variant, u16 heap);
void func_021F6CF0(Obj_021F6CF0 *o);
void func_021F6D5C(Obj_021F6D5C *o);
void func_021F6DD4(Obj_021F6DD4 *p);
void func_021F6DEC(S6DEC *p, unsigned char a, unsigned char b, unsigned char c, unsigned short d);
int func_021F6E1C(char *p);
extern const char d_0220AC40[];
extern const char d_0220AC50[];


Obj_021F6560 *func_021F6560(int mode, int group, int variant, u16 heap)
{
    Obj_021F6560 *o;
    Rec *table;
    int i, k, m;
    int bytes;
    o = sub_02030734(heap, 0xbc, 1, d_0220AC40, 0x63);
    table = func_02048F60(0x98, 2, (u16)((heap & 0x7fff) | 0x8000));
    o->heap = heap;
    if (mode == 3)
        o->f0 = func_02046DB8(11, 0x56);
    else if (table[group].ids[0][variant] != -1)
        o->f0 = func_02046DB8(11, table[group].ids[0][variant]);
    else
        o->f0 = func_02046DB8(11, table[group].ids[0][0]);
    func_02046FF8(o->f0);
    o->n = 0;
    for (i = 1; i < 4; i++)
        if (table[group].ids[i][variant] != -1) o->n++;
    o->h1c[0] = func_02047400(o->f0, 0, o->f0);
    o->h1c[1] = func_02047400(o->f0, 0, o->f0);
    if (mode == 3) {
        o->n = 1;
        o->f10 = sub_02030734(o->heap, 4, 0, d_0220AC40, 0x93);
        *o->f10 = func_02046DB8(11, 0x57);
        for (i = 0; i < 2; i++) {
            o->f14[i] = sub_02030734(o->heap, 4, 0, d_0220AC40, 0x98);
            o->arr[i] = sub_02030734(o->heap, 0x10, 1, d_0220AC40, 0x99);
            *o->f14[i] = func_02047564(o->h1c[i], *o->f10, 0);
            o->arr[i]->kind = 1;
            o->h24[i] = func_0204767C((u32)o->h1c[i], (u32 *)o->f14[i], (u16)o->n);
            func_020477A4(o->h24[i], (u16)0);
        }
    } else if (o->n != 0) {
        o->f10 = sub_02030734(o->heap, o->n * 4, 0, d_0220AC40, 0xa7);
        for (i = 0; i < 2; i++) {
            o->f14[i] = sub_02030734(o->heap, o->n * 4, 0, d_0220AC40, 0xab);
            o->arr[i] = sub_02030734(o->heap, o->n * 16, 1, d_0220AC40, 0xac);
        }
        k = 0;
        for (i = 1; i < 4; i++) {
            if (table[group].ids[i][variant] != -1) {
                o->f10[k] = func_02046DB8(11, table[group].ids[i][variant]);
                for (m = 0; m < 2; m++) {
                    o->f14[m][k] = func_02047564(o->h1c[m], o->f10[k], 0);
                    o->arr[m][k].kind = 0;
                }
                k++;
            }
        }
        for (i = 0; i < 2; i++) {
            o->h24[i] = func_0204767C((u32)o->h1c[i], (u32 *)o->f14[i], (u16)o->n);
            for (m = 0; m < o->n; m++) func_020477A4(o->h24[i], (u16)m);
        }
    } else {
        o->h24[0] = func_0204767C((u32)o->h1c[0], 0, (u16)0);
        o->h24[1] = func_0204767C((u32)o->h1c[1], 0, (u16)0);
    }
    bytes = *(u16 *)(func_0206E964(func_02046F48(o->f0)) + 0x30) * 8;
    o->fa4 = sub_02030734(o->heap, 4, 0, d_0220AC40, 0xd6);
    o->fa8 = sub_02030734(o->heap, 4, 0, d_0220AC40, 0xd7);
    *o->fa4 = o->f0;
    *o->fa8 = sub_02030734(o->heap, bytes, 0, d_0220AC40, 0xda);
    o->fac = 0;
    o->fad = 1;
    o->xf[0].f0 = 0;
    o->xf[0].f4 = 0;
    o->xf[0].f8 = 0x572f;
    o->xf[0].sx = 0x1000;
    o->xf[0].sy = 0x1000;
    o->xf[0].sz = 0x1000;
    func_0207ADC4(o->xf[0].matrix);
    o->xf[1].f0 = 0;
    o->xf[1].f4 = 0;
    o->xf[1].f8 = -0xcb7d;
    o->xf[1].sx = 0x1000;
    o->xf[1].sy = 0x1000;
    o->xf[1].sz = 0x1000;
    func_0207ADC4(o->xf[1].matrix);
    if (mode == 3) {
        o->xf[0].f8 = 0xa000;
        o->xf[1].f8 = -0xf000;
    }
    func_0207DCF8(&table[group]);
    sub_020307B0(table);
    return o;
}


void func_021F6898(Obj_021F6898 *o)
{
    int i;
    int j;

    if (o->n != 0) {
        for (i = 0; i < o->n; i++) {
            for (j = 0; j < 2; j++)
                func_0204762C(o->f14[j][i]);
            func_02046EFC(o->f10[i]);
        }
        for (j = 0; j < 2; j++) {
            func_020307B0(o->f14[j]);
            func_020307B0(o->f8[j]);
        }
        func_020307B0(o->f10);
    }
    for (j = 0; j < 2; j++) {
        func_02047738(o->f24[j]);
        func_02047504(o->f1c[j]);
    }
    func_02046EFC(o->f0);
    func_020307B0(*o->fa8);
    func_020307B0(o->fa8);
    func_020307B0(o->fa4);
    func_020307B0(o);
}


/*
 * Lever: the element address is `i * 16 + (u32)o->arr[j]` (integer first);
 * `&o->arr[j][i]` is normalised pointer-first and swaps the add operands.
 */
void func_021F6934(Obj_021F6934 *o)
{
    int i;
    int j;
    int amt;

    if (o->n != 0) {
        for (i = 0; i < o->n; i++) {
            for (j = 0; j < 2; j++) {
                Ent_021F6934 *e;

                e = (Ent_021F6934 *)(i * 16 + (u32)o->arr[j]);
                amt = 0;
                switch (e->kind) {
                case 0:
                    amt = 0x1000;
                    break;
                case 1:
                    if (e->f4 == 1) {
                        amt = e->f8;
                        e->fc--;
                        if (((Ent_021F6934 *)(i * 16 + (u32)o->arr[j]))->fc == 0)
                            ((Ent_021F6934 *)(i * 16 + (u32)o->arr[j]))->f4 = 0;
                    }
                    break;
                }
                if (amt != 0)
                    func_02047910(o->h[j], (u16)i, amt);
            }
        }
    }
    func_021F9364(o->sub);
}


/*
 * Applies each of the two transforms whose disable bit is clear.
 */
void func_021F69B0(Obj_021F69B0 *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (!(p->off & (1 << i)))
            func_02047A60(p->h[i], (struct Arg *)p->xf[i]);
    }
}


/*
 * lane O10 candidate
 */
void func_021F69E8(S69E8 *p, unsigned char a, unsigned char b, unsigned char c, unsigned short d)
{
    p->f0 = 1;
    p->f2 = a;
    p->f3 = b;
    p->f4 = 0;
    p->f5 = c;
    p->f6 = d;
}


int func_021F6A18(char *p)
{
    return ((struct Obj18549 *)p)->fAC != 0;
}


void func_021F6A28(Obj_021F6A28 *o, u32 mode, u32 on)
{
    if (mode == 2) {
        if (on)
            o->f = 3;
        else
            o->f = 0;
    } else {
        if (on)
            o->f = o->f | (1 << mode);
        else
            o->f = o->f & ((1 << mode) ^ 3);
    }
}


/*
 * Arms entry j of table i when its state is 1: sets the flag and stores the two values.
 */
void func_021F6AA8(Obj_021F6AA8 *p, int i, int j, int a, int b)
{
    if (p->tab[i][j].state == 1) {
        p->tab[i][j].armed = 1;
        p->tab[i][j].a = a;
        p->tab[i][j].b = b;
    }
}


/*
 * Returns 1 when any entry of either table is armed.
 */
int func_021F6AD0(Obj_021F6AD0 *p)
{
    int i;

    for (i = 0; i < p->n; i++) {
        if (p->x[i].armed == 1 || p->y[i].armed == 1)
            return 1;
    }
    return 0;
}


/*
 * Lever: u8 variant spills at entry before the other parameter copies;
 * int variant moves that spill three instructions later (8 differing bytes).
 * The ov094 caller at 021F76D6 passes the byte-derived selector.
 */
Obj_021F6B04 *func_021F6B04(int unused, int group, u8 variant, u16 heap)
{
    Obj_021F6B04 *o;
    int (*table)[4][4];
    int i, j;
    int bytes;
    o = sub_02030734(heap, 0x70, 1, d_0220AC50, 0x56);
    table = func_02048F60(0x98, 1, (u16)((heap & 0x7fff) | 0x8000));
    o->heap = heap;
    if (table[group][0][variant] != -1)
        o->f0 = func_02046DB8(11, table[group][0][variant]);
    else
        o->f0 = func_02046DB8(11, table[group][0][0]);
    func_02046FF8(o->f0);
    o->n = 0;
    for (i = 1; i < 4; i++)
        if (table[group][i][variant] != -1) o->n++;
    o->f14 = func_02047400(o->f0, 0, o->f0);
    j = 0;
    if (o->n != 0) {
        o->fc = sub_02030734(o->heap, o->n * 4, 0, d_0220AC50, 0x7e);
        o->f10 = sub_02030734(o->heap, o->n * 4, 0, d_0220AC50, 0x7f);
        o->f8 = sub_02030734(o->heap, o->n * 16, 1, d_0220AC50, 0x80);
        for (i = 1; i < 4; i++) {
            if (table[group][i][variant] != -1) {
                o->fc[j] = func_02046DB8(11, table[group][i][variant]);
                o->f10[j] = func_02047564(o->f14, o->fc[j], 0);
                o->f8[j].kind = 0;
                j++;
            }
        }
        o->f18 = func_0204767C((u32)o->f14, (u32 *)o->f10, (u16)o->n);
        for (j = 0; j < o->n; j++) func_020477A4(o->f18, (u16)j);
    } else {
        o->f18 = func_0204767C((u32)o->f14, 0, (u16)0);
    }
    o->f1c = 0;
    o->f20 = 0;
    o->f24 = 0;
    o->f28 = 0x1000;
    o->f2c = 0x1000;
    o->f30 = 0x1000;
    func_0207ADC4(o->matrix);
    bytes = *(u16 *)(func_0206E964(func_02046F48(o->f0)) + 0x30) * 8;
    o->f58 = sub_02030734(o->heap, 4, 0, d_0220AC50, 0xaa);
    o->f5c = sub_02030734(o->heap, 4, 0, d_0220AC50, 0xab);
    *o->f58 = o->f0;
    *o->f5c = sub_02030734(o->heap, bytes, 0, d_0220AC50, 0xae);
    o->f60 = 0;
    o->f61 = 1;
    sub_020307B0(table);
    return o;
}


void func_021F6CF0(Obj_021F6CF0 *o)
{
    int i;

    func_02047738(o->f18);
    if (o->n != 0) {
        for (i = 0; i < o->n; i++) {
            func_0204762C(o->f10[i]);
            func_02046EFC(o->fc[i]);
        }
        func_020307B0(o->f8);
        func_020307B0(o->f10);
        func_020307B0(o->fc);
    }
    func_02047504(o->f14);
    func_02046EFC(o->f0);
    func_020307B0(*o->f5c);
    func_020307B0(o->f5c);
    func_020307B0(o->f58);
    func_020307B0(o);
}


/*
 * Lever: the `adds r6, r4, #0` before the loop is a zero (r4 is 0 there) that
 * the loop-back branch skips; it is the constant 0 (default amount and the
 * cleared field), not a copy of i. Flags word is a bitfield (lsls/lsrs).
 */
void func_021F6D5C(Obj_021F6D5C *o)
{
    int i;
    int amt;

    if (o->bit1) {
        o->bit1 = 0;
        return;
    }
    if (o->n != 0) {
        for (i = 0; i < o->n; i++) {
            Ent_021F6D5C *e;

            e = &o->arr[i];
            amt = 0;
            switch (e->kind) {
            case 0:
                amt = 0x1000;
                break;
            case 1:
                if (e->f4 == 1) {
                    amt = e->f8;
                    e->fc--;
                    if (o->arr[i].fc == 0)
                        o->arr[i].f4 = 0;
                }
                break;
            }
            if (amt != 0)
                func_02047910(o->h18, (u16)i, amt);
        }
    }
    func_021F9364(o->sub);
}


/*
 * Unless flag bit 0 at 0x68 is set, applies the vector at 0x1c to the handle at 0x18.
 */
void func_021F6DD4(Obj_021F6DD4 *p)
{
    if (!p->b0)
        func_02047A60(p->h, (struct Arg *)p->v);
}


void func_021F6DEC(S6DEC *p, unsigned char a, unsigned char b, unsigned char c, unsigned short d)
{
    p->f0 = 1;
    p->f2 = a;
    p->f3 = b;
    p->f4 = 0;
    p->f5 = c;
    p->f6 = d;
}


int func_021F6E1C(char *p)
{
    return ((struct Obj18551 *)p)->f60 != 0;
}
