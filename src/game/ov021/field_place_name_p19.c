/*
 * file:     field_place_name_p19.c
 * unit:     yes
 * function: func_021BD5F8, func_021BD604, func_021BD648, func_021BD6C0, func_021BD704, func_021BD734
 * address:  0x021BD5F8
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
 *   func_02025774  0x02025774  thumb
 *   func_02045A98  0x02045A98  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D42C  0x0201D42C  thumb
 *   func_02045808  0x02045808  arm
 *   d_021D9BB0     0x021D9BB0  data  ov021  a4
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BD94C  0x021BD94C  thumb  ov021
 *   func_021BD988  0x021BD988  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021A7E3C  0x021A7E3C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_021BD8C0  0x021BD8C0  thumb  ov021
 *   func_021BD96C  0x021BD96C  thumb  ov021
 *   func_02161B1C  0x02161B1C  thumb  ov010
 *   func_02161B74  0x02161B74  thumb  ov010
 */
#include "../../matched/include/Obj18235.h"
#include "../../matched/include/Obj20132.h"
#include "../../matched/include/Obj12883.h"

struct StrObj;
struct U16Vec;
struct Strbuf;
struct Desc;
struct Obj;
struct Args;
struct Evt;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    void *f[6];
} Tbl;

typedef struct {
    int f00;
    void *f04;
    char pad08[8];
    unsigned int f10;
} Arg;

typedef struct {
    int f00;
    int f04;
    Arg *f08;
} Work;

extern void func_02025774(u8 *g, unsigned int a);
extern u16 func_02045A98(void);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *a, const u16 *b, u32 c);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void func_02045808(struct U16Vec *vec);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_021BD94C(u32 *);
extern void func_021BD988(u32 *, u32);
extern void func_020061E4(u32);
extern void *func_021A7E3C(struct Args *a);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u32 func_021BD8C0(u32 *ctx);
extern void func_021BD96C(u32 *, u32);
extern int func_02161B1C(void *a);
extern int func_02161B74(int a0);
void func_021BD5F8(void *p, unsigned int a);
void func_021BD604(u32 a, u16 b, u32 c, u8 *d, u8 *e);
void *func_021BD648(Arg *p);
u32 func_021BD6C0(u32 a, int *st, u32 *ctx);
int func_021BD704(u32 a, int *st, u32 *ctx);
u32 func_021BD734(u32 a, int *st, u32 *ctx);
extern Tbl d_021D9BB0;


/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD5F8(void *p, unsigned int a)
{
func_02025774((u8 *)((struct Obj18235 *)p)->fC, a);
}


void func_021BD604(u32 a, u16 b, u32 c, u8 *d, u8 *e)
{
    u16 buf[2];
    u32 h;

    buf[0] = b;
    buf[1] = func_02045A98();
    h = (u32)func_020457B0(2, c);
    func_02045994((struct Strbuf *)h, buf, 2);
    *d = func_0201D304((struct StrObj *)h, a, 0);
    *e = func_0201D42C((struct StrObj *)h, (void *)a);
    func_02045808((struct U16Vec *)h);
}


void *func_021BD648(Arg *p)
{
    Tbl t = d_021D9BB0;
    int i;
    void *task;
    Work *w;

    switch (p->f10) {
    case 0:
        i = 0;
        break;
    case 1:
        i = 0;
        break;
    case 2:
        i = 2;
        break;
    case 3:
        i = 1;
        break;
    case 4:
        i = 2;
        break;
    case 5:
        i = 3;
        break;
    case 6:
        i = 5;
        break;
    default:
        i = 4;
        break;
    }
    task = func_020122C0(p->f04, (void *)p->f00, t.f[i], 12);
    w = func_020124E8(task);
    w->f04 = 0;
    w->f08 = p;
    return task;
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_021BD6C0(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];

    switch (*st) {
    case 0:
        func_021BD94C(ctx);
        if (((struct Obj20132 *)p)->f38 != 2)
            func_020061E4(0x559);
        func_021BD988(ctx, a);
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}


int func_021BD704(u32 a, int *st, u32 *ctx)
{
    u32 p = ctx[2];

    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, func_021A7E3C((struct Args *)p));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}


u32 func_021BD734(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];
    u32 x = ((struct Obj12883 *)p)->fC;

    switch (*st) {
    case 0:
        if (func_021BD8C0(ctx))
            func_021BD96C(ctx, a);
        else
            func_021BD94C(ctx);
        ctx[1] = func_02161B1C((void *)x);
        (*st)++;
        break;
    case 1:
        if (func_02161B74(ctx[1])) {
            if (((struct Obj12883 *)p)->f38 != 2)
                func_020061E4(0x559);
            func_021BD988(ctx, a);
            (*st)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}
