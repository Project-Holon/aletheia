/*
 * file:     field_place_name_p07.c
 * unit:     yes
 * function: func_021BDC2C, func_021BDC80, func_021BDC94, func_021BDCB8, func_021BDCC8, func_021BDD20, func_021BDD34, func_021BDD40
 * address:  0x021BDC2C
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
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC550  0x021BC550  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021BDD58  0x021BDD58  thumb  ov021
 *   func_021BDD7C  0x021BDD7C  thumb  ov021
 *   func_021BDD9C  0x021BDD9C  thumb  ov021
 *   func_021BDDAC  0x021BDDAC  thumb  ov021
 *   func_021BDD74  0x021BDD74  thumb  ov021
 *   func_021BE184  0x021BE184  thumb  ov021
 *   func_0218FEA0  0x0218FEA0  thumb  ov021
 *   func_021BE1A0  0x021BE1A0  thumb  ov021
 *   func_021BDFB0  0x021BDFB0  thumb  ov021
 *   func_021BE068  0x021BE068  thumb  ov021
 *   func_021BDDC0  0x021BDDC0  thumb  ov021
 *   func_021BDEB4  0x021BDEB4  thumb  ov021
 *   func_021BE1C4  0x021BE1C4  thumb  ov021
 *   func_0218FF00  0x0218FF00  thumb  ov021
 *   func_0218FF20  0x0218FF20  thumb
 */
#include "../../matched/include/Obj05065.h"
#include "../../matched/include/Obj00282.h"
#include "../../matched/include/Obj18252.h"

struct Evt;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short s16;

typedef struct {
    char pad[0xC];
    void *fC;
    char pad2[0x10];
    s16 s20;
} Inner;

typedef struct {
    Inner *f0;
} Obj_021BDC2C;

typedef signed int     s32;

typedef struct {
    char pad[0x54];
    void *f54;
} Obj_021BDC94;

extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u32 func_02188D20(u8 *p);
extern void func_021BC550(void *p, int v);
extern u16 func_02188C84(u8 *p);
extern void *func_021BDD58(int a);
typedef struct {
    void *f0;
    void *f4;
    char pad[0x5C];
    int f64;
} Obj_021BDD7C;

extern void func_021BDD7C(Obj_021BDD7C *p, void *a);
extern void func_021BDD9C(void *r, void *x);
typedef struct {
    char pad[0x54];
    void *f54;
} Obj_021BDDAC;

extern void func_021BDDAC(Obj_021BDDAC *p);
extern void func_021BDD74(void *p);
typedef struct { int x, y, z; } Vec;

typedef struct {
    char pad[0x58];
    Vec v58;
} Obj;

extern void func_021BE184(Obj *p, const Vec *v);
extern void func_0218FEA0(u8 *p, u32 v);
extern int func_021BE1A0(u32 a);
extern void func_021BDFB0(char *a);
extern void func_021BE068(void *a);
typedef struct {
    u16 f0;
    u16 f2;
    int f4;
} Rot;

typedef struct {
    int f0;
    int f4;
    u8 pad8[0x24 - 0x8];
    Rot t;
    u8 pad2C[0x44 - 0x2C];
    int f44;
    int f48;
} Sub;

typedef struct {
    u32 f0;
    u32 f4;
    Sub s;
    u32 f54;
    u8 pad58[0x68 - 0x58];
    int f68;
    int f6C;
} Obj_021BDDC0;

extern void func_021BDDC0(Obj_021BDDC0 *p);
typedef struct { int x, y, z; } Vec_021BDEB4;

typedef struct {
    u16 f04;
    u16 f06;
    int f08;
    Vec_021BDEB4 pos;
    Vec_021BDEB4 rot;
} In;

typedef struct {
    u32 f00;
    In  in;
    u8  sub[0x20];
    int f44;
    int f48;
} S;

typedef struct {
    u32 obj;
    u32 f04;
    S   s;
    u32 f54;
    u32 pad58[4];
    u32 f68;
    u32 f6C;
} A;

extern void func_021BDEB4(A *a);
extern int func_021BE1C4(u32 a);
extern int func_0218FF00(u32 a);
extern void func_0218FF20(u8 *a);
void func_021BDC2C(u32 *ctx, u32 a);
void func_021BDC80(Obj_021BDC2C *p);
void *func_021BDC94(void *a);
void func_021BDCB8(u8 *p);
void func_021BDCC8(char *a, int *b);
void func_021BDD20(Obj_021BDC94 *p);
void func_021BDD34(u8 *p);
int func_021BDD40(void *a);



void func_021BDC2C(u32 *ctx, u32 a)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = ((struct Obj05065 *)p)->f4;
    u32 y = ((struct Obj05065 *)p)->fC;

    if (((struct Obj05065 *)p)->f40 != 0)
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, y, 3, 0, 0, p[0x44], p[0x45]));
    else
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, y, ((struct Obj05065 *)p)->f3C, 0, 1, 0, 0));
}



void func_021BDC80(Obj_021BDC2C *p)
{
    Inner *q = p->f0;

    func_021BC550((void *)func_02188D20(q->fC), q->s20);
}



void *func_021BDC94(void *a)
{
    void *x = (void *)func_02188C84(a);
    void *r = func_021BDD58((int)x);

    func_021BDD7C((Obj_021BDD7C *)r, a);
    func_021BDD9C(r, x);
    return r;
}



void func_021BDCB8(u8 *p)
{
    func_021BDDAC((Obj_021BDDAC *)p);
    func_021BDD74(p);
}



void func_021BDCC8(char *a, int *b)
{
    func_021BE184((Obj *)a, (Vec *)b);
    func_0218FEA0(((struct Obj00282 *)a)->f54, (u32)(a + 8));
    if (func_021BE1A0((u32)a) != 0) {
        switch (b[1]) {
        case 0:
            func_021BDFB0(a);
            break;
        case 1:
            func_021BE068(a);
            break;
        }
    } else {
        switch (b[1]) {
        case 0:
            func_021BDDC0((Obj_021BDDC0 *)a);
            break;
        case 1:
            func_021BDEB4((A *)a);
            break;
        }
    }
    ((struct Obj00282 *)a)->f64 = 1;
}



void func_021BDD20(Obj_021BDC94 *p)
{
    if (func_021BE1C4((u32)p)) {
        func_0218FF00((u32)p->f54);
    }
}



/*
 * Tail-call thunk: the object's word at +0x54.
 *
 * Addresses are Black-image addresses.
 */
void func_021BDD34(u8 *p)
{
    func_0218FF20((u8 *)(((struct Obj18252 *)p)->f54));
}



int func_021BDD40(void *a)
{
    return func_021BE1C4((u32)a);
}
