/*
 * file:     unit_021F36C0_p01.c
 * unit:     yes
 * function: func_021F36C0, func_021F36C8, func_021F36D4, func_021F36E4, func_021F36F0, func_021F3734
 * address:  0x021F36C0
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F42B0  0x021F42B0  data
 *   func_02047674  0x02047674  arm
 *   func_021F3D2C  0x021F3D2C  thumb  ov056
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_02188D24  0x02188D24  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_021BB990  0x021BB990  thumb  ov021
 *   func_021BBA6C  0x021BBA6C  thumb  ov021
 *   func_021BBA1C  0x021BBA1C  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_021F3B10  0x021F3B10  thumb  ov056
 *   func_021F392C  0x021F392C  thumb  ov056
 *   func_021F3D60  0x021F3D60  thumb  ov056
 *   func_021F3890  0x021F3890  thumb  ov056
 *   func_021F3BF0  0x021F3BF0  thumb  ov056
 *   func_021F3CC4  0x021F3CC4  thumb  ov056
 *   func_021F3904  0x021F3904  thumb  ov056
 *   func_021F3A78  0x021F3A78  thumb  ov056
 *   func_021F3C84  0x021F3C84  thumb  ov056
 *   func_021F3DB8  0x021F3DB8  thumb  ov056
 *   func_021F3918  0x021F3918  thumb  ov056
 *   func_021F3C4C  0x021F3C4C  thumb  ov056
 *   func_021F3D9C  0x021F3D9C  thumb  ov056
 *   func_021F3A14  0x021F3A14  thumb  ov056
 *   func_021F38D4  0x021F38D4  thumb  ov056
 *   d_021F42C0     0x021F42C0  data  a4
 */
#include "../../matched/include/Obj07668.h"

struct Desc;
struct Obj;
struct Work;
struct Ctx;
struct Obj00020;
struct Node;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct { char pad[4]; u16 f4; } Inner;

typedef struct { char pad[8]; Inner *f8; } Outer;

typedef struct Work {
    int f0;
    int f4;
    int idx;
    u8 cam[0x30];
    u8 obj[0x80];
    u8 f_bc[0xc];
    u8 f_c8[4];
    u32 task;
    void *fd0;
} Work;

extern Outer *func_02047674(u32 a);
extern void func_021F3D2C(u8 *p);
extern u16 func_02188C84(u8 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_020056A0(void (*cb)(void), void *ctx, int a);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_02188C58(void *p);
extern u32 func_02188C98(u8 *p);
extern u32 func_02188D24(u8 *p);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern u32 func_0218DC6C(u8 *p);
extern int *func_021BB990(int a, int *d, const int *c);
extern u32 func_021BBA6C(const void *p);
extern void func_021BBA1C(int *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern void func_02030EAC(struct Node *n);
extern void func_021F3B10(struct Obj *o, void *a1, int a2, int a3, int idx);
extern void func_021F392C(struct Obj *o, int a1, int heap, int idx);
extern void func_021F3D60(void *o, int idx, int heap);
extern void func_021F3890(u32 *out, int a, int idx);
extern void func_021F3BF0(u32 *p);
extern void func_021F3CC4(u8 *p, int flag);
extern void func_021F3904(unsigned char **p);
extern int func_021F3A78(u8 *p);
extern int func_021F3C84(u32 *p);
extern int func_021F3DB8(int **pp);
extern int func_021F3918(void **p);
extern void func_021F3C4C(u8 *p);
extern void func_021F3D9C(void *o);
extern void func_021F3A14(u8 *p);
extern void func_021F38D4(unsigned char *p);
void *func_021F36C0(void *a, u8 *b, u32 c);
u32 func_021F36C8(u32 idx);
int func_021F36D4(u32 a);
void func_021F36E4(u8 *a, u8 *b);
void *func_021F36F0(void *a, u8 *b, u32 c);
int func_021F3734(void *a0, int *state, Work *p);
extern const u32 d_021F42B0[];
extern const u8 d_021F42C0[];


void *func_021F36C0(void *a, u8 *b, u32 c)
{
    return func_021F36F0(a, b, c);
}


/*
 * Word table lookup in d_021F42B0 ({0x1C, 0x1D, 0x1E, 0x1F}), the table ov056
 * func_021F392C also indexes. Region ov056: of the 33 overlays mapped at this
 * address it is the only one with a function entry here (the bytes before are
 * the tail-call thunk at 0x021F36C0 and its pool word); ov036..ov065 except
 * ov056 are mid-function at 0x021F36C8, ov107 is ARM. Its ov021 caller
 * func_021B5650 passes a 1-based slot minus one (wave A1 witness).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021F36C8(u32 idx)
{
    return d_021F42B0[idx];
}


int func_021F36D4(u32 a)
{
    return func_02047674(a)->f8->f4 << 12;
}


/*
 * Unlabelled tail-call leaf: forwards the second argument plus 0x3c.
 */
void func_021F36E4(u8 *a, u8 *b)
{
    func_021F3D2C(b + 0x3c);
}


void *func_021F36F0(void *a, u8 *b, u32 c)
{
    void *r;
    u32 *t;

    func_02188C84(b);
    r = func_020122C0(a, 0, func_021F3734, 0xd4);
    t = func_020124E8(r);
    t[0] = (u32)b;
    t[1] = (u32)a;
    t[2] = c;
    ((struct Obj07668 *)t)->fD0 = func_020056A0((void (*)(void))func_021F36E4, t, 0);
    return r;
}


int func_021F3734(void *a0, int *state, Work *p)
{
    int heap;
    int h;
    int a;
    int b;
    int c;

    heap = func_02188C84((u8 *)p->f0);
    switch (*state) {
    case 0:
        h = (int)func_02012944(func_020120F4((const struct Ctx *)p->f4));
        func_021F3B10((struct Obj *)p->obj, func_02188CB4((void *)p->f0), h, heap, p->idx);
        (*state)++;
        break;
    case 1:
        func_0218F0A8(func_02188C58((void *)p->f0));
        (*state)++;
        break;
    case 2:
        h = (int)func_02188C58((void *)p->f0);
        if (func_0218F0E8((u8 *)h) != 0) {
            break;
        }
        func_021F392C((struct Obj *)p->cam, h, heap, p->idx);
        func_021F3D60(p->f_c8, p->idx, heap);
        func_021F3890((u32 *)p->f_bc, func_0218DC6C((u8 *)func_02188C98((u8 *)p->f0)), p->idx);
        func_021F3BF0((u32 *)p->obj);
        p->task = (u32)func_021BB990(-1, (int *)func_02188D24((u8 *)p->f0), (const int *)d_021F42C0);
        *((void **)func_021BBA6C((const void *)p->task)) = p->obj;
        func_021F3CC4(p->obj, 1);
        func_021F3904((unsigned char **)p->f_bc);
        (*state)++;
        break;
    case 3:
        a = func_021F3A78(p->cam);
        func_021F3C84((u32 *)p->obj);
        b = func_021F3DB8((int **)p->f_c8);
        c = func_021F3918((void **)p->f_bc);
        if (a && c && b) {
            (*state)++;
        }
        break;
    case 4:
        func_021F3CC4(p->obj, 0);
        func_021BBA1C((int *)p->task);
        func_02030EAC(p->fd0);
        func_021F3C4C(p->obj);
        func_021F3D9C(p->f_c8);
        func_021F3A14(p->cam);
        func_021F38D4(p->f_bc);
        return 1;
    }
    return 0;
}
