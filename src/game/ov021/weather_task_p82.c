/*
 * file:     weather_task_p82.c
 * unit:     yes
 * function: func_021A6B50, func_021A6B88, func_021A6B9C, func_021A6BAC, func_021A6BB4, func_021A6C30, func_021A6C4C, func_021A6C64, func_021A6C6C, func_021A6CB8, func_021A6D30, func_021A6D3C, func_021A6D48, func_021A6D58
 * address:  0x021A6B50
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
 *   func_0216D5D8  0x0216D5D8  thumb
 *   d_021D8AB0  0x021D8AB0  data  ov021  a4
 *   func_02082BCC  0x02082BCC  arm
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_0219E664  0x0219E664  thumb  ov021
 *   func_02162598  0x02162598  thumb  ov010
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CAC  0x02188CAC  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02188D40  0x02188D40  thumb  ov021
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AB8  0x02012AB8  thumb
 *   func_021A36B0  0x021A36B0  thumb  ov021
 *   func_021A36D4  0x021A36D4  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_021A305C  0x021A305C  thumb  ov021
 *   func_02188CA4  0x02188CA4  thumb  ov021
 *   func_021A6D9C  0x021A6D9C  thumb  ov021
 *   func_021A6DA4  0x021A6DA4  thumb  ov021
 *   func_021A3664  0x021A3664  thumb  ov021
 *   func_021A36A4  0x021A36A4  thumb  ov021
 *   func_021BB3AC  0x021BB3AC  thumb  ov021
 *   sub_02030734   0x02030734  arm
 *   data_021DDF1C  0x021DDF1C  data  a1
 */
#include "../../matched/include/Obj18062.h"
#include "../../matched/include/Obj01119.h"
#include "../../matched/include/Obj19810.h"

struct BigObj;
struct Ctx;
struct Q;
struct Obj00020;
struct H4;
struct Rec44;
struct SaveBlock;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    u8 b0;
    u8 b1;
    short h2;
} P;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u8 on : 1;
    u8 keep : 1;
    u8 flag : 1;
    u8 st : 5;
    u8 pad;
    s16 cnt;
    u32 val;
} St;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
    int f4;
} T;

typedef signed int     s32;

extern void func_0216D5D8(int a, int b);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern int func_0216D3CC(int a0);
extern void *func_021A3960(unsigned char *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012844(const struct BigObj *p);
extern int func_0219E664(void *o, u32 k, void *buf);
extern int func_02162598(char *p, struct Q *q);
extern void *func_02188C58(void *p);
extern u32 func_02188C5C(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern u16 func_02188C84(u8 *p);
extern void func_02188CAC(u8 *p, u32 v);
extern void *func_021A3074(u8 *p);
extern void *func_0216D888(void *p);
extern void func_02188D40(u8 *p, u32 v);
extern void *func_020127A4(struct SaveBlock *p);
extern struct H4 *func_02012AB8(struct Rec44 *p);
extern void func_021A36B0(u8 *p, void *v);
extern void func_021A36D4(u8 *p, u32 v);
extern void func_021A3044(u8 *p, void *v);
extern void func_021A305C(char *p, u32 b);
extern u32 func_02188CA4(u8 *p);
extern void func_021A6D9C(void);
extern void func_021A6DA4(void);
extern void func_021A3664(u32 *p, u32 heap);
extern u32 func_021A36A4(u8 *p);
extern void func_021BB3AC(u8 *p, u32 b);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void func_021A6B50(P *p, int a);
int func_021A6B88(void *a);
void func_021A6B9C(u8 *a);
int func_021A6BAC(void *a);
void func_021A6BB4(St *p, u32 a1, u32 a2);
void func_021A6C30(T *t);
int func_021A6C4C(T *t, int x);
u32 func_021A6C64(u8 *p);
int func_021A6C6C(u8 *p, u32 k);
void func_021A6CB8(struct Obj00020 *a, u32 b, u32 c);
void func_021A6D30(u8 *a0);
void func_021A6D3C(u8 *a0);
int func_021A6D48(u32 a, u32 b, u32 c, u32 d);
u32 *func_021A6D58(void *a, u32 heap);
extern const u8 d_021D8AB0[][4];
extern const char data_021DDF1C[];


void func_021A6B50(P *p, int a)
{
    if (p->b0) {
        p->h2 = (p->h2 + 1) % 4;
        func_0216D5D8(a, d_021D8AB0[p->b1][p->h2]);
    }
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A6B88(void *a)
{
    func_02082BCC(a, 0, 8);
    ((struct Obj18062 *)a)->f4 = 9;
    return 9;
}


void func_021A6B9C(u8 *a)
{
    *a = (1 | (*a & ~1));
}


/*
 * Tail-call thunk: forwards to func_021A6B88 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_021A6BAC(void *a)
{
    return func_021A6B88(a);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A6BB4(St *p, u32 a1, u32 a2)
{
    if (p->on) {
        if (p->st != 0) {
            if (a1 != 9) {
                p->cnt = 0;
                p->st = 0;
                if (p->keep)
                    p->val = a1;
            }
        } else if (a1 == 9) {
            if (p->cnt < 30)
                p->cnt = p->cnt + 1;
            else
                p->st = 1;
        }
        if (func_0216D3CC(a2) == 1) {
            if (p->st == 0) {
                p->keep = 0;
                p->flag = 0;
            } else {
                p->keep = 1;
                p->flag = 1;
            }
        }
    }
}


void func_021A6C30(T *t)
{
    if (t->b2) {
        t->b2 = 0;
    }
    if (!t->b1) {
        t->f4 = 9;
    }
}


int func_021A6C4C(T *t, int x)
{
    int r;
    if (t->b2) {
        return 1;
    }
    r = t->f4;
    if (r == 9) {
        r = x;
    }
    return r;
}


u32 func_021A6C64(u8 *p)
{
    return ((u32)*p << 30) >> 31;
}


int func_021A6C6C(u8 *p, u32 k)
{
    u32 buf[2];
    void *o = func_021A3960(*(unsigned char * *)&((struct Obj01119 *)p)->f14);
    u32 r4;

    r4 = func_02012844(func_020120F4(func_02188C80(*(u8 * *)&((struct Obj01119 *)p)->f18)));
    func_0219E664(o, k, buf);
    return func_02162598((char *)r4, (struct Q *)buf) != 0xFFFF;
}


void func_021A6CB8(struct Obj00020 *a, u32 b, u32 c)
{
    u8 *r4;

    func_02188C58(a);
    func_02188C5C((u8 *)a);
    r4 = func_02188CB4(a);
    func_02188CAC((u8 *)a, (u32)func_021A6D58(a, func_02188C84((u8 *)a)));
    func_02188D40((u8 *)a, (u32)func_0216D888(func_021A3074(r4)));
    func_021A36B0(r4, func_02012AB8(func_020127A4(func_020120F4(func_02188C80(a)))));
    func_021A36D4(r4, b);
    func_021A3044(r4, (void *)b);
    func_021A305C((char *)r4, c);
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6D30(u8 *a0)
{
    func_02188CA4(a0);
    func_021A6D9C();
}


void func_021A6D3C(u8 *a0)
{
    func_02188CA4(a0);
    func_021A6DA4();
}


int func_021A6D48(u32 a, u32 b, u32 c, u32 d)
{
return (int)func_0216D888(func_021A3074(func_02188CB4((struct Obj00020 *)a)));
}


u32 *func_021A6D58(void *a, u32 heap)
{
    u32 r7 = func_02188C5C(a);
    u32 *p = sub_02030734(heap, 8, 1, data_021DDF1C, 0x3e);
    void *r6 = func_02188CB4(a);

    ((struct Obj19810 *)p)->f0 = r6;
    func_021A3664(r6, heap);
    func_021BB3AC((u8 *)r7, func_021A36A4(r6));
    return p;
}
