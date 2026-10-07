/*
 * file:     intrude_subdisp_p18.c
 * unit:     yes
 * function: func_021800A4, func_021802A8
 * address:  0x021800A4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217553C  0x0217553C  thumb  ov011
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_02012950  0x02012950  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0217F3C4  0x0217F3C4  thumb
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_02174258  0x02174258  thumb  ov011
 *   func_02175C40  0x02175C40  thumb  ov011
 *   func_02173AE0  0x02173AE0  thumb  ov011
 *   func_0217F40C  0x0217F40C  thumb
 *   func_02175514  0x02175514  thumb  ov011
 *   func_02173C04  0x02173C04  thumb  ov011
 *   func_0217537C  0x0217537C  thumb  ov011
 *   func_0218034C  0x0218034C  thumb
 *   func_0217F420  0x0217F420  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0217FE38  0x0217FE38  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02034714  0x02034714  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_021829F8  0x021829F8  thumb ov018
 *   func_021808C4  0x021808C4  thumb ov018
 *   d_02183B30  0x02183B30  data ov018 a1
 *   d_02183B44  0x02183B44  data ov018 a1
 *   d_0218374C  0x0218374C  data ov018 a4
 */
#include "../../matched/include/Obj12502.h"

struct Ctx;
struct Obj;
struct Rec44;
struct Sub24;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj;

typedef struct {
    u8 pad00[4];
    void *f04;          /* 0x04 */
    u8 pad08[4];
    void *f0C;          /* 0x0C */
    Ov018Obj obj;       /* 0x10 */
    u8 f40;             /* 0x40 */
    u8 f41;             /* 0x41 */
    u8 pad42[0x99 - 0x42];
    u8 f99;             /* 0x99 */
} Outer;

void *func_020124E4(struct Obj *p);
u32 func_02012138(const struct Ctx *p);
void *func_020120F4(const struct Ctx *p);
int func_02158344(int a0);
void func_0217553C(u8 *);
void *func_02188C7C(u8 *p);
void func_0216D9A0(void *);
struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0217F3C4(Ov018Obj *p, int a);
int func_0216D3CC(int a0);
void func_0216D410(void *, int);
int func_0216D480(char *p);
int func_02174258(char *a);
int func_02175C40(void *p);
int func_02173AE0(int a, int b, int c, int d);
int func_0217F40C(Ov018Obj *p);
int func_02175514(u8 *);
int func_02173C04(int, int);
u8 *func_0217537C(u8 *);
void func_0218034C(void *, Outer *, u8 *);
int func_0217F420(void);
u32 *func_0216D9E4(void *c);
void func_0217FE38(u8 *v, Outer *c);
void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u32 func_020307B0(void *p);
void func_02034714(const char *expr, u32 line, const char *file);
void MI_CpuCopy8(const void *src, void *dst, unsigned int n);
void func_021829F8(void *a, void *b);
void func_021808C4(void *task, const void *src);
int func_021800A4(void *a, int *state, Outer *c);
void func_021802A8(int x, u8 *y);
extern char d_02183B30[];
extern char d_02183B44[];


/*
 * Task callback in the shape of func_02182AA4: a 12-state sequence driving
 * the Ov018Obj at +0x10, with an early skip to state 10 while the owner
 * object is absent.
 */
int func_021800A4(void *a, int *state, Outer *c)
{
    void *sub;
    void *t;
    void *w;
    u8 *v;
    u8 *p;
    int k;
    int m;
    int flag;

    sub = func_020124E4(a);
    t = (void *)func_02012138(sub);
    w = func_020120F4(sub);
    v = (u8 *)func_02158344((int)t);
    if (v == 0) {
        if (func_0217F40C(&c->obj) == 0) {
            return 0;
        }
        if (*state < 10) {
            func_0217F3C4(&c->obj, 4);
            *state = 10;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        func_0217553C(v);
        func_0216D9A0(func_02188C7C(c->f0C));
        func_0201F02C(c->obj.f00, 0, func_02012950(w, v[0x154]));
        func_0217F3C4(&c->obj, 1);
        (*state)++;
        break;
    case 1:
        if (func_0216D3CC((int)c->f04) == 1) {
            k = *(u16 *)(v + c->f40 * 0x1C + 0x9C);
            if (k == 2) {
                m = 3;
            } else if (k == 3) {
                m = 2;
            } else {
                m = 0;
                if (k != 1) {
                    m = 1;
                }
            }
            func_0216D410(c->f04, m);
            (*state)++;
        }
        break;
    case 2:
        if (func_0216D480(c->f04) == 1) {
            (*state)++;
        }
        break;
    case 3:
        if (func_02174258((char *)v) == 1) {
            (*state)++;
        }
        break;
    case 4:
        switch (func_02175C40(v + 0x1AC)) {
        case 1:
            c->f99 = 1;
            (*state)++;
            break;
        case 2:
            (*state)++;
            break;
        }
        break;
    case 5:
        if (func_02173AE0((int)v, v[0x154], v[0x156], v[0x158]) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (func_0217F40C(&c->obj) == 1) {
            k = func_02175514(v);
            flag = 0;
            switch (k) {
            case 0:
                break;
            case 1:
                *state = 7;
                break;
            case 2:
            case 3:
            default:
                flag = 1;
                break;
            }
            if (flag == 1) {
                func_0217F3C4(&c->obj, 4);
                *state = 10;
            }
        }
        break;
    case 7:
        if (func_02173C04(v[0x154], c->f99) == 1) {
            (*state)++;
        }
        break;
    case 8:
        p = func_0217537C(v);
        if (p != 0) {
            if (p[1] != c->f99 || c->f99 == 1) {
                c->f41 = 0;
            }
            *state = 9;
        }
        break;
    case 9:
        func_0218034C(a, c, v);
        return 0;
    case 10:
        if (func_0217F420() == 1) {
            *state = 11;
        }
        break;
    case 11:
        if (func_0217F40C(&c->obj) == 1) {
            func_0216D9E4(func_02188C7C(c->f0C));
            func_0217FE38(v, c);
            return 1;
        }
        break;
    }
    return 0;
}

extern void (*d_0218374C[])(int, void *);


void func_021802A8(int x, u8 *y)
{
    void *p = func_02030734((u16)((((struct Obj12502 *)y)->f0 & 0x7fff) | 0x8000), 0x98, 1, d_02183B30, 0x329);
    unsigned int c;

    MI_CpuCopy8(y, p, 0x98);
    c = y[0x41];
    if (c == 0) {
        func_021808C4((void *)x, p);
    } else if (c == 1) {
        func_021829F8((void *)x, p);
    } else if (c == 2) {
        func_021808C4((void *)x, p);
    } else if (c >= 3) {
        if (d_0218374C[c - 8] == 0) {
            func_02034714(d_02183B44, 0, d_02183B44);
        }
        d_0218374C[y[0x41] - 8](x, p);
    } else {
        func_021808C4((void *)x, p);
    }
    func_020307B0(p);
}
