/*
 * file:     union_comm_p10.c
 * unit:     yes
 * function: func_0217365C, func_021736A0, func_021736C8, func_021736E0, func_02173744, func_021737A4, func_02173840, func_02173874, func_021738D4, func_0217391C, func_02173928
 * address:  0x0217365C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203D5AC  0x0203D5AC  arm
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   func_02012944  0x02012944  thumb
 *   func_020263D8  0x020263D8  thumb
 *   func_021653C4  0x021653C4  thumb  ov010
 *   d_02175610     0x02175610  data   ov012  a1
 *   d_02175614     0x02175614  data   ov012  a1
 *   func_02026474  0x02026474  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0201212C  0x0201212C  thumb
 *   func_020123C4  0x020123C4  thumb
 *   func_02174268  0x02174268  thumb  ov012
 *   func_0217B840  0x0217B840  thumb  ov019
 *   func_0217B75C  0x0217B75C  thumb  ov019
 *   func_0217B264  0x0217B264  thumb  ov019
 *   func_02012114 0x02012114 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02188BE8 0x02188BE8 thumb ov021
 *   func_021A2E44  0x021A2E44  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02013CC8  0x02013CC8  thumb
 *   func_0217B440  0x0217B440  thumb  ov019
 *   func_021676E4  0x021676E4  thumb  ov010
 *   func_0217505C  0x0217505C  thumb  ov012
 *   func_02167688  0x02167688  thumb  ov010
 */
#include "../../matched/include/Obj09359.h"
#include "../../matched/include/Obj04170.h"
#include "../../matched/include/Obj09360.h"
#include "../../matched/include/Obj00610.h"
#include "../../matched/include/Obj19233.h"
#include "../../matched/include/Obj19234.h"
#include "../../matched/include/Obj09361.h"
#include "../../matched/include/Obj19235.h"
#include "../../matched/include/Obj19236.h"
#include "../../matched/include/Obj07338.h"
#include "../../matched/include/Obj19237.h"
#include "../../matched/include/Obj19238.h"
#include "../../matched/include/Obj07339.h"
#include "../../matched/include/Obj12444.h"
#include "../../matched/include/Obj19239.h"
#include "../../matched/include/Obj19240.h"
#include "../../matched/include/Obj19241.h"

struct Ctx;
struct Comm;
struct Work;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct { u8 pad[0xc8]; u8 f : 1; } S_02173874;

typedef struct { u8 pad[0xc8]; u8 f : 1; u8 pad2[0]; } S0;

typedef struct { u8 pad[0xc8]; u8 f; u8 g; } S_021738D4;

typedef struct { u8 pad0[0x282A]; u8 a; u8 pad1[0x355C-0x282B]; S_021738D4 *b; } T;

extern void func_02082BCC(void *p, u32 v, u32 n);
extern void func_0203D5AC(int a, int b);
extern unsigned int func_02012138(const struct Ctx *a);
extern void *func_020120F4(const struct Ctx *p);
extern unsigned int func_02026454(void *obj);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 *func_02012944(void *p);
extern void func_020263D8(struct Comm *p, u32 a1, u32 a2);
extern void func_021653C4(void);
extern unsigned int func_02026474(void *obj);
extern void *func_02188C80(void *p);
extern u8 func_0201212C(const struct Ctx *p);
extern int func_020123C4(void *v);
extern int func_02174268(u8 *p);
extern int func_0217B840(char *base, int r1);
extern void func_0217B75C(char *p);
extern void func_0217B264(u8 *w, void *sys, void *q);
extern u32 func_02012114(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188BE8(void *a);
extern void func_021A2E44(int a, unsigned int v);
extern u16 func_02188C9C(u8 *p);
extern u32 func_02013CC8(u32 id);
extern void func_0217B440(char *base, int x, void *y);
extern void func_021676E4(struct Work *w);
extern void func_0217505C(int *p, int x);
extern void func_02167688(struct Work *w);
void func_0217365C(u8 *p);
void func_021736A0(u8 *a, volatile u16 *s);
void func_021736C8(u8 *a, int v);
void func_021736E0(unsigned int x);
void func_02173744(int a);
void func_021737A4(void *a, int b);
int func_02173840(u8 *p);
void func_02173874(int a, u8 *p, void *q);
void func_021738D4(int a, T *p);
int func_0217391C(u8 *p);
int func_02173928(u8 *p);
extern char d_02175610[];
extern char d_02175614[];


void func_0217365C(u8 *p)
{
    int i;
    int v;

    func_02082BCC(p, 0, 0x448);
    for (i = 0; i < 30; i++) {
        func_02082BCC(p + i * 0x24 + 0x1a, 0xff, 6);
    }
    v = -1;
    ((struct Obj09359 *)p)->f43C = v;
    ((struct Obj09359 *)p)->f440 = v;
    ((struct Obj09359 *)p)->f444 = v;
}


/*
 * Unlabelled leaf (no lr save), called from ov019 func_0217BD9C. The two
 * trailing halfwords are both loaded before either is stored, in source
 * order; only a volatile source pointer keeps the scheduler from hoisting
 * s[3]'s load above s[2]'s (plain temporaries swap r1/r2).
 */
void func_021736A0(u8 *a, volatile u16 *s)
{
    u8 *p = a + 0x2830;
    u16 x, y;
    ((struct Obj04170 *)p)->f4 = s[0];
    ((struct Obj04170 *)p)->f6 = s[1];
    x = s[2];
    y = s[3];
    ((struct Obj04170 *)p)->f8 = x;
    ((struct Obj04170 *)p)->fA = y;
    p[0xf] = 0;
    (((struct Obj04170 *)p)->fC)++;
    p[0xe] = 1;
}


/*
 * Unlabelled leaf (no lr save) in the ov012 listing; callee of ov031
 * func_021F00D4 (a blocker of its MATCH). Same +0x2830 block as
 * func_021736A0.
 */
void func_021736C8(u8 *a, int v)
{
    u8 *p = a + 0x2830;
    p[0xf] = v;
    (((struct Obj09360 *)p)->fC)++;
    p[0xe] = 1;
}


void func_021736E0(unsigned int x)
{
    switch (x) {
    case 0x14:
        func_0203D5AC(0x17, 5);
        break;
    case 0x15:
        func_0203D5AC(0x18, 5);
        break;
    case 0x16:
        func_0203D5AC(0x19, 5);
        break;
    case 0x17:
        func_0203D5AC(0x1a, 5);
        break;
    case 3:
        func_0203D5AC(0x16, 5);
        break;
    case 0x19:
        func_0203D5AC(0x1b, 5);
        break;
    }
}


void func_02173744(int a)
{
    int r5;
    int r7;
    int *p;

    r5 = func_02012138((const struct Ctx *)a);
    r7 = (int)func_020120F4((const struct Ctx *)a);
    if (func_02026454((void *)r5) != 0) {
        func_02034714(d_02175610, 0, d_02175610);
    }
    p = func_02030734(5, 0x10, 1, d_02175614, 0x37);
    p[0] = (int)func_02012944((void *)r7);
    p[1] = r5;
    p[2] = r7;
    p[3] = a;
    func_020263D8((struct Comm *)r5, 3, (u32)p);
    func_021653C4();
}


void func_021737A4(void *a, int b)
{
    u8 *r4;
    u8 s;

    if (func_02026454(a) != 3) {
        return;
    }
    r4 = (u8 *)func_02026474(a);
    if (r4 == 0) {
        func_02034714((void *)0x02175610, 0, (void *)0x02175610);
    }
    if (func_0201212C(func_02188C80((void *)b)) == 1) {
        return;
    }
    if (func_020123C4((void *)((struct Obj19233 *)(*(u8 * *)&((struct Obj00610 *)r4)->f0))->fC) == 1) {
        return;
    }
    if (func_02173840(r4) != 1) {
        return;
    }
    s = r4[0x2830];
    if (s >= 4 && s <= 0x17) {
        if (func_02174268(r4) != 0) {
            return;
        }
        func_0217B840((char *)r4, b);
        return;
    }
    if (s != 0 && s != 1) {
        return;
    }
    if (func_02174268(r4) != 0) {
        return;
    }
    func_0217B75C((char *)r4);
    func_0217B840((char *)r4, b);
    func_0217B264(r4, (void *)(((struct Obj19234 *)(*(u8 * *)&((struct Obj00610 *)r4)->f0))->f8), (void *)b);
}

int func_02173840(u8 *p) { if(p[0x282a]==1 && func_02012114(*(const struct Ctx * *)&((struct Obj19235 *)(*(u8 * *)&((struct Obj09361 *)p)->f0))->fC)==1 && func_02188BE8(func_0201210C(*(const struct Ctx * *)&((struct Obj19236 *)(*(u8 * *)&((struct Obj09361 *)p)->f0))->fC))==1) return 1; return 0; }


/*
 * func_021A2E44(q, v) takes a second argument (it stores r1 at +0xc); its 1
 * is CSE'd with the stored 1, which is what puts that constant in r1 and
 * fixes the prologue schedule. Bitfield at +0xc8 needs lsls/lsrs #0x1f.
 */
void func_02173874(int a, u8 *p, void *q)
{
    S_02173874 *r4;

    r4 = *(S_02173874 * *)&((struct Obj07338 *)p)->f355C;
    p[0x282A] = 1;
    if (p[0x3563] == 1) {
        func_021A2E44((int)q, 1);
    }
    if (func_02013CC8(func_02188C9C(q)) == 1) {
        func_0217B440((char *)p, (int)func_020120F4((const struct Ctx *)(((struct Obj19238 *)(*(u8 * *)&((struct Obj07338 *)p)->f0))->fC)), q);
    }
    if (r4 != 0 && r4->f == 1) {
        func_021676E4(((struct Obj19237 *)r4)->f0);
    }
}


void func_021738D4(int a, T *p)
{
    S_021738D4 *o;

    o = p->b;
    if (o != 0) {
        if (o->g == 1) {
            func_0217505C((int *)o, ((struct Obj19239 *)(*(u8 * *)&((struct Obj07339 *)p)->f0))->fC);
            p->b = 0;
        } else if (((S0 *)o)->f == 1) {
            func_02167688(((struct Obj12444 *)o)->f0);
        }
    }
    p->a = 0;
}


/*
 * Unlabelled leaf (a .word run in the ov012 listing): reads the word at
 * +0x3568.  Callee of ov021 func_0218A0E4.
 * Addresses are Black-image addresses.
 */
int func_0217391C(u8 *p)
{
    return ((struct Obj19240 *)p)->f3568;
}


/*
 * Unlabelled leaf (a .word run in the ov012 listing): reads the word at
 * +0x356C.  Callee of ov021 func_0218A0E4.
 * Addresses are Black-image addresses.
 */
int func_02173928(u8 *p)
{
    return ((struct Obj19241 *)p)->f356C;
}
