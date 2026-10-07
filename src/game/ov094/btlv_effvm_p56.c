/*
 * file:     btlv_effvm_p56.c
 * unit:     yes
 * function: func_021FE690, func_021FE6A4, func_021FE750, func_021FE768
 * address:  0x021FE690
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
 *   func_02030EE8  0x02030EE8  arm
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_021F89BC  0x021F89BC  thumb  ov094
 *   func_021FE410  0x021FE410  thumb  ov094
 *   func_021FE4D0  0x021FE4D0  thumb  ov094
 *   func_021FE8D8  0x021FE8D8  thumb  ov094
 *   func_02200218  0x02200218  thumb  ov094
 *   d_0220AE68     0x0220AE68  data   ov094
 *   func_021F9220  0x021F9220  thumb  ov094
 *   func_0200F698  0x0200F698  thumb
 */
#include "../../matched/include/Obj21693.h"

struct S02030EE8;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct {
    unsigned int f0 : 10;
    unsigned int f10 : 1;
} Flags;

typedef struct {
    Flags fl;
    char pad04[4];
    int h;
} Obj;

typedef struct {
    Obj *obj;
    int a1, a2, a3;
    int a4, a5, a6;
    int cnt;
} Req;

extern u32 func_02030EE8(struct S02030EE8 *p);
extern int func_021F8694(void);
extern int func_021FE4D0(char *p);
extern int func_02200218(char *w, int a, int b, int c, int d, int e, int f);
extern void func_021FE410(Obj *o, int a, int b, int n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02030DA8(int owner, void *fn, void *arg, int n);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021F89BC(void *h);
extern void func_021FE8D8(void *h, Obj **pp);
extern void func_021F9220(int *p, int *d, int *lim, int *flag);
extern void func_0200F698(void *a, void *b);
void func_021FE690(void *h);
void func_021FE6A4(void *h, Req *r);
void func_021FE750(void *h);
void func_021FE768(void *h, int *s);
extern char d_0220AE68[];


void func_021FE690(void *h)
{
    unsigned int *p = *((unsigned int **)func_02030EE8(h));

    *p &= ~8u;
}


void func_021FE6A4(void *h, Req *r)
{
    int slot;
    Obj **cell;

    r->cnt--;
    if (r->cnt != 0)
        return;
    slot = func_021FE4D0((char *)r->obj);
    *(int *)((char *)r->obj + 0x26c + slot * 4) =
        func_02200218((char *)func_021F8694(), r->a1, r->a2, r->a3, r->a4, r->a5, r->a6);
    func_021FE410(r->obj, 0x7f000, 0x6b000, 10);
    if (!r->obj->fl.f10) {
        cell = func_02030734((u16)(((u16)((struct Obj21693 *)((char *)r->obj))->f238 & 0x7fff) | 0x8000), 4, 0, d_0220AE68, 0x1e6d);
        *cell = r->obj;
        func_021F896C((void *)func_02030DA8(r->obj->h, (void *)func_021FE8D8, cell, 0), 0, 0);
    }
    func_021F89BC(h);
}


void func_021FE750(void *h)
{
    unsigned int *p = *((unsigned int **)func_02030EE8(h));

    *p &= ~0x800u;
}


void func_021FE768(void *h, int *s)
{
    int flag = 1;

    func_021F9220(&s[1], &s[3], &s[2], &flag);
    func_0200F698((void *)0xffff, (void *)(s[1] >> 12));
    if (flag)
        func_021F89BC(h);
}
