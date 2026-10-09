/*
 * file:     ui_scene_p01.c
 * unit:     yes
 * function: func_021B6100, func_021B613C, func_021B6144, func_021B61F8, func_021B61FC, func_021B6200, func_021B6208, func_021B6284, func_021B629C, func_021B62E0, func_021B639C, func_021B63D0, func_021B6448, func_021B6470, func_021B6498, func_021B64A8, func_021B64D0, func_021B64F8, func_021B6520, func_021B6548, func_021B6558, func_021B6568, func_021B6578, func_021B6588, func_021B6598, func_021B65A8, func_021B65B4, func_021B65C8, func_021B6600, func_021B6608
 * address:  0x021B6100
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   d_021B9540     0x021B9540  data  a1
 *   func_020307B0 0x020307B0 arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B878  0x0204B878  arm
 *   func_021B67F8  0x021B67F8  thumb  ov067
 *   d_021B954C     0x021B954C  data  a1
 *   func_021B691C 0x021B691C thumb ov067
 *   func_021B66FC 0x021B66FC thumb ov067
 *   func_021B6934  0x021B6934  thumb  ov067
 *   func_021B69A4  0x021B69A4  thumb  ov067
 *   func_021B69B8  0x021B69B8  thumb
 *   func_021B69C8  0x021B69C8  thumb
 *   func_021B69BC  0x021B69BC  thumb
 *   func_021B6A1C  0x021B6A1C  thumb
 *   func_021B6A10  0x021B6A10  thumb
 *   func_021B69D0 0x021B69D0 thumb ov067
 *   func_021B69D4 0x021B69D4 thumb ov067
 *   func_021B69D8 0x021B69D8 thumb ov067
 *   func_021B69F8 0x021B69F8 thumb ov067
 *   func_020275E4  0x020275E4  thumb
 *   func_02027624  0x02027624  thumb
 *   func_02049B68  0x02049B68  arm
 *   func_02027628  0x02027628  thumb
 *   func_02049740  0x02049740  arm
 *   func_0202762C  0x0202762C  thumb
 *   func_021B6738  0x021B6738  thumb  ov067
 *   func_02027614  0x02027614  thumb
 *   func_02027618  0x02027618  thumb
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 */
#include "../../matched/include/Obj20596.h"
#include "../../matched/include/Obj20599.h"
#include "../../matched/include/Obj09859.h"
#include "../../matched/include/Obj09860.h"
#include "../../matched/include/Obj20600.h"
#include "../../matched/include/Obj20601.h"
#include "../../matched/include/Obj20602.h"
#include "../../matched/include/Obj20603.h"
#include "../../matched/include/Obj20604.h"
#include "../../matched/include/Obj07675.h"
#include "../../matched/include/Obj20605.h"

struct S_021B6144;
struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    void *arr;
    void *f4;
    u16 idx;
    u16 fA;
    u8 fC;
    u8 pad[3];
} S_021B6100;

typedef int (*cb_t)(struct S_021B6144 *s, void *arg);

struct Entry {
    cb_t cb0;
    cb_t cb1;
    cb_t cb2;
    cb_t cb3;
    cb_t cb4;
};

struct S_021B6144 {
    struct Entry *arr;
    void *f4;
    u16 idx;
    u16 fA;
    u8 _c;
    u8 d;
    u8 e;
};

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} Out;

typedef struct {
    int f0;
    u32 f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    u8 b1c;
    u8 b1d;
    u8 b1e;
} In;

typedef signed int     s32;

typedef struct {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
} Rect;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} P;

typedef struct {
    u8 *f0;
    u32 f4;
    int f8;
    u32 fC;
    u32 f10;
    u32 f14;
    int f18;
    int f1c;
} A;

typedef struct {
    int f0;
    u32 f4;
    int f8;
    u8 sub[0x14];
    u8 elem[1];
} R;

typedef struct Ent {
    u8 b[0x38];
} Ent;

typedef struct S_021B63D0 {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 pad0c[0x20 - 0x0c];
    Ent ent[1];
} S_021B63D0;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
} S_021B65C8;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern u32 func_020307B0(void *p);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204ACEC(void *h, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u32 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u32 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern void func_0204ADA4(unsigned int i);
extern void func_0204A8D4(unsigned int i);
extern void func_0204AFD8(unsigned int i);
extern struct Obj *func_0204B294(void *a, unsigned int b, unsigned int c, unsigned int d, const void *r, u16 e, u16 f);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021B67F8(void *a, u32 b, void *c, void *d, u32 e, u16 f);
extern void func_021B691C(void **p);
extern void func_021B66FC(u32 *p);
extern int func_021B6934(struct S_021B63D0 *p);
extern int func_021B69A4(void **p);
extern int func_021B69B8(void *e);
extern int func_021B69C8(void *p, int a);
extern void func_021B69BC(void *e, u32 v);
extern void func_021B6A1C(void *e, u32 v);
extern void func_021B6A10(void *e, u32 v);
extern void func_021B69D0(void *p, int v);
extern void func_021B69D4(void *p, int v);
extern void func_021B69D8(struct S *p, u32 v);
extern u32 func_021B69F8(u32 p);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern void func_02049B68(void *h, u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_02027628(void);
extern u32 func_02049740(void *h, u32 id, u32 layer, u32 ofs, u32 size, u32 heap);
extern u32 func_0202762C(void);
extern void func_021B6738(void *a0, u32 a1, u32 a2, u16 a3,
                          u8 k0, u8 k1, u8 k2, u8 k3, u8 k4, u8 k5, u8 k6, u8 k7,
                          u8 k8, u32 k9, u32 k10);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
S_021B6100 *func_021B6100(u32 heap, void *arr, u8 c, u16 idx, void *f4);
void func_021B613C(void *p);
int func_021B6144(struct S_021B6144 *s);
void func_021B61F8(unsigned char *task, int value);
unsigned func_021B61FC(const unsigned char *p);
void func_021B6200(unsigned char *p);
void func_021B6208(Out *out, In *in, int unused, u16 d);
void func_021B6284(unsigned int *p);
int func_021B629C(P *p, int a, u16 x, u16 y, u8 e, u16 f);
R *func_021B62E0(A *a, u16 heap);
void func_021B639C(u8 *p);
void func_021B63D0(S_021B63D0 *p);
int func_021B6448(u8 *p);
int func_021B6470(u8 *p);
int func_021B6498(u8 *p);
void func_021B64A8(u8 *p, u32 v);
void func_021B64D0(u8 *p, u32 v);
void func_021B64F8(u8 *p, u32 v);
void func_021B6520(u8 *p, u32 v);
int func_021B6548(unsigned char *p, unsigned int id, int v);
void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
void func_021B6568(unsigned char *p, unsigned int id, int v);
void func_021B6578(unsigned char *p, unsigned int id, int v);
void func_021B6588(unsigned char *p, unsigned int id, unsigned int v);
void func_021B6598(unsigned char *p, unsigned int id, unsigned int v);
int func_021B65A8(unsigned char *p, int id);
int func_021B65B4(unsigned char *p, unsigned int id);
void *func_021B65C8(u8 *p, u32 v);
void *func_021B6600(unsigned char *p, unsigned int v);
void func_021B6608(S_021B65C8 *p, u8 a1, u32 a2, u32 a3, u32 a4, u8 a5, u8 a6, u32 a7, u32 heap);
extern const char d_021B9540[];
extern const char d_021B954C[];



S_021B6100 *func_021B6100(u32 heap, void *arr, u8 c, u16 idx, void *f4)
{
    S_021B6100 *p;

    p = func_02030734(heap, 0x10, 0, d_021B9540, 0x4e);
    func_02082BCC(p, 0, 0x10);
    p->arr = arr;
    p->fC = c;
    p->f4 = f4;
    p->idx = idx;
    p->fA = 0xFFFF;
    return p;
}


void func_021B613C(void *p)
{
    func_020307B0(p);
}



int func_021B6144(struct S_021B6144 *s)
{
    struct Entry *e = (struct Entry *)((u8 *)s->arr + s->idx * 0x14);

    switch (s->d) {
    case 0:
        if (e->cb0 == 0) {
            s->d = 1;
        } else {
            if (e->cb0(s, s->f4) == 0)
                break;
            s->e = 0;
            s->d = 1;
            break;
        }
        /* fallthrough */
    case 1:
        if (e->cb1 != 0)
            e->cb1(s, s->f4);
        s->d = 2;
        /* fallthrough */
    case 2:
        if (e->cb2(s, s->f4) == 0)
            break;
        s->e = 0;
        if (e->cb3 != 0)
            e->cb3(s, s->f4);
        s->d = 3;
        break;
    case 3:
        if (e->cb4 == 0) {
            s->d = 4;
        } else {
            if (e->cb4(s, s->f4) == 0)
                break;
            s->e = 0;
            s->d = 4;
            break;
        }
        /* fallthrough */
    case 4: {
        u16 old = s->fA;

        s->fA = 0xFFFF;
        s->idx = old;
        if (old == 0xFFFE)
            return 1;
        s->d = 0;
        s->e = 0;
        break;
    }
    }
    return 0;
}


void func_021B61F8(unsigned char *task, int value)
{
    ((struct Obj20596 *)task)->fA = value;
}


unsigned func_021B61FC(const unsigned char *p)
{
    return p[14];
}


/*
 * witness: ov2139D80 receives the ov0676100 state object, reads its E byte via61FC and advances it here. Existing6144 is not a unit and lists neither helper.
 */
void func_021B6200(unsigned char *p)
{
    p[14]++;
}



void func_021B6208(Out *out, In *in, int unused, u16 d)
{
    int flag;
    void *h;

    flag = in->f4 & 2;
    h = func_020490F4(in->f8, d);
    if (in->f4 & 1)
        out->f4 = func_0204ACEC(h, in->fC, in->f0, (u16)(in->b1c << 5), d);
    else
        out->f4 = func_0204AC18(h, in->fC, in->f0, (u16)(in->b1c << 5), in->b1d, in->b1e, d);
    out->f0 = func_0204A6C8(h, in->f10, flag, in->f0, d);
    out->f8 = func_0204AF28(h, in->f14, in->f18, d);
    out->fC = in->f0;
    func_02049238(h);
}



void func_021B6284(unsigned int *p)
{
    func_0204ADA4(p[1]);
    func_0204A8D4(p[0]);
    func_0204AFD8(p[2]);
}



int func_021B629C(P *p, int a, u16 x, u16 y, u8 e, u16 f)
{
    Rect rc = {0, 0, 0, 0};
    int r;

    rc.x = x;
    rc.y = y;
    r = (int)func_0204B294((void *)a, p->f0, p->f4, p->f8, &rc, (u16)p->fC, f);
    func_0204B878((struct Obj *)r, e);
    return r;
}



R *func_021B62E0(A *a, u16 heap)
{
    u8 *q2;
    u8 *q1;
    int flag;
    R *p;
    int k;
    u32 size;
    u32 i;

    size = a->f4 * 0x38 + 0x20;
    p = func_02030734(heap, size, 0, d_021B954C, 0x123);
    flag = 0;
    func_02082BCC(p, 0, size);
    p->f4 = a->f4;
    p->f8 = flag;
    if (a->fC >= 4) {
        flag = 1;
        k = 4;
    } else {
        k = flag;
    }
    func_021B6608((S_021B65C8 *)p->sub, a->fC, flag, k, a->f18, a->f10, a->f14, a->f1c, heap);
    for (i = 0; i < p->f4; i++) {
        q1 = p->elem;
        q2 = p->sub;
        func_021B67F8(q1 + i * 0x38, a->f8, q2, a->f0 + i * 32, flag, heap);
    }
    return p;
}



void func_021B639C(u8 *p)
{
    u32 i;
    for (i = 0; i < ((struct Obj20599 *)p)->f4; i++)
        func_021B691C((void **)(p + 0x20 + i * 0x38));
    func_021B66FC((u32 *)(p + 0xC));
    func_020307B0(p);
}



void func_021B63D0(S_021B63D0 *p)
{
    u32 i;

    switch (p->f08) {
    case 0:
        p->f00 = -1;
        for (i = 0; i < p->f04; i++) {
            if (func_021B6934((struct S_021B63D0 *)(&p->ent[i]))) {
                p->f00 = i;
                p->f08 = 1;
                return;
            }
        }
        break;
    case 1:
        p->f08 = 2;
    case 2:
        if (func_021B69A4((void **)(&p->ent[p->f00]))) {
            p->f08 = 3;
        }
        break;
    case 3:
        p->f08 = 0;
        break;
    }
}



int func_021B6448(u8 *p)
{
    if (((struct Obj09859 *)p)->f8 == 3 && ((struct Obj09859 *)p)->f0 != 0xffffffff) {
        return func_021B69B8(p + 0x20 + ((struct Obj09859 *)p)->f0 * 0x38);
    }
    return -1;
}



int func_021B6470(u8 *p)
{
    if (((struct Obj09860 *)p)->f8 == 1 && ((struct Obj09860 *)p)->f0 != 0xffffffff) {
        return func_021B69B8(p + 0x20 + ((struct Obj09860 *)p)->f0 * 0x38);
    }
    return -1;
}


int func_021B6498(u8 *p)
{
    if (((struct Obj20600 *)p)->f8)
        return 1;
    return 0;
}



void func_021B64A8(u8 *p, u32 v)
{
    u32 i;

    for (i = 0; i < ((struct Obj20601 *)p)->f4; i++) {
        func_021B69C8(p + 0x20 + i * 0x38, v);
    }
}



void func_021B64D0(u8 *p, u32 v)
{
    u32 i;

    for (i = 0; i < ((struct Obj20602 *)p)->f4; i++) {
        func_021B69BC(p + 0x20 + i * 0x38, v);
    }
}



void func_021B64F8(u8 *p, u32 v)
{
    u32 i;

    for (i = 0; i < ((struct Obj20603 *)p)->f4; i++) {
        func_021B6A1C(p + 0x20 + i * 0x38, v);
    }
}



void func_021B6520(u8 *p, u32 v)
{
    u32 i;

    for (i = 0; i < ((struct Obj20604 *)p)->f4; i++) {
        func_021B6A10(p + 0x20 + i * 0x38, v);
    }
}



int func_021B6548(unsigned char *p, unsigned int id, int v)
{
    return func_021B69C8(func_021B65C8(p, id), v);
}



void func_021B6558(unsigned char *p, unsigned int id, unsigned int v)
{
    func_021B69BC(func_021B65C8(p, id), v);
}



void func_021B6568(unsigned char *p, unsigned int id, int v)
{
    func_021B69D0(func_021B65C8(p, id), v);
}



void func_021B6578(unsigned char *p, unsigned int id, int v)
{
    func_021B69D4(func_021B65C8(p, id), v);
}



void func_021B6588(unsigned char *p, unsigned int id, unsigned int v)
{
    func_021B6A1C(func_021B65C8(p, id), v);
}



void func_021B6598(unsigned char *p, unsigned int id, unsigned int v)
{
    func_021B69D8(func_021B65C8(p, id), v);
}



/*
 * Extent includes the unlabelled tail-call follower at 0x021B65B4.
 */
int func_021B65A8(unsigned char *p, int id)
{
    return func_021B69F8((u32)func_021B6600(p, id));
}



int func_021B65B4(unsigned char *p, unsigned int id)
{
    *(int *)&((struct Obj07675 *)p)->f8 = 0;
    *(int *)&((struct Obj07675 *)p)->f0 = -1;
    return func_021B6548(p, id, 1);
}



void *func_021B65C8(u8 *p, u32 v)
{
    u32 i;

    for (i = 0; i < ((struct Obj20605 *)p)->f4; i++) {
        if (func_021B69B8(p + 0x20 + i * 0x38) == v) {
            return (u8 *)(p + 0x20) + i * 0x38;
        }
    }
    return 0;
}

/*
 * Tail call to func_021B65C8.
 */
void *func_021B6600(unsigned char *p, unsigned int v)
{
    return func_021B65C8(p, v);
}



void func_021B6608(S_021B65C8 *p, u8 a1, u32 a2, u32 a3, u32 a4, u8 a5, u8 a6, u32 a7, u32 heap)
{
    void *h;
    u32 t;

    func_02082BCC(p, 0, 0x14);
    p->fC = a1;
    h = func_020490F4(func_020275E4(), heap);
    if (a7 == 0) {
        func_02049B68(h, func_02027624(), a3, a5 << 5, 0x20, heap);
        p->f10 = func_02049740(h, func_02027628(), p->fC, 0x800, 0, heap);
        func_021B6738(h, func_0202762C(), p->fC, p->f10,
                      0, 0x15, 0x20, 0x18, 0, 0x15, 0x20, 3, a5, 0, heap);
    }
    p->f0 = func_0204AC18(h, func_02027614(), a2, (u16)(a6 << 5), 0, 3, heap);
    p->f4 = func_0204A6C8(h, func_02027618(), 0, a2, heap);
    t = func_0202761C(a4);
    p->f8 = func_0204AF28(h, t, func_02027620(a4), heap);
    func_02049238(h);
}
