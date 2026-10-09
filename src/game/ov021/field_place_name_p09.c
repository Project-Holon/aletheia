/*
 * file:     field_place_name_p09.c
 * unit:     yes
 * function: func_021BDD48, func_021BDD58, func_021BDD74, func_021BDD7C, func_021BDD9C, func_021BDDAC, func_021BDDC0, func_021BDEB4, func_021BDFB0
 * address:  0x021BDD48
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
 *   d_021DE37C     0x021DE37C  data  a4
 *   func_020307B0  0x020307B0  arm
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218FE80  0x0218FE80  thumb  ov021
 *   func_0218FE98  0x0218FE98  thumb  ov021
 *   func_021BE17C  0x021BE17C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021BE1B0  0x021BE1B0  thumb  ov021
 *   func_021A7B08  0x021A7B08  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0218FEA4  0x0218FEA4  thumb  ov021
 *   func_0218FE78  0x0218FE78  thumb  ov021
 *   func_021BE158  0x021BE158  thumb  ov021
 *   func_0218FEC0  0x0218FEC0  thumb  ov021
 *   func_021BE194  0x021BE194  thumb  ov021
 *   func_021BE148  0x021BE148  thumb  ov021
 */
#include "../../matched/include/Obj00282.h"
#include "../../matched/include/Obj03139.h"
#include "../../matched/include/Obj09656.h"

struct Obj00020;
struct V3;
struct VecFx32;
typedef struct Obj_021BDD48 {
    int f00;
    int f04;
    void *f08;
} Obj_021BDD48;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    void *f0;
    void *f4;
    char pad[0x5C];
    int f64;
} Obj_021BDD7C;

typedef struct {
    void *f0;
    char pad[0x50];
    void *f54;
} Obj_021BDD9C;

typedef struct {
    char pad[0x54];
    void *f54;
} Obj_021BDDAC;

typedef short          s16;

typedef struct {
    int x;
    int y;
    int z;
} Vec_021BDD48;

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

struct V3 {
    int x;
    int y;
    int z;
};

struct Q {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    struct V3 f40;
};

extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);
extern u32 func_020307B0(void *p);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_02188C58(void *a);
extern void *func_0218FE80(void *a);
extern void func_0218FE98(void);
extern u32 func_021BE17C(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern u16 func_021A3050(u8 *p);
extern int func_021BE1B0(u32 a);
extern void func_021A7B08(int a, struct V3 *b);
extern void func_021A3038(unsigned char *a, struct VecFx32 *out);
extern void func_0218FEA4(u32 a);
extern void func_0218FE78(u32 a, void *dst);
extern int func_021BE158(u32 a, u32 b);
extern void func_0218FEC0(u8 *o);
extern int func_021BE194(u32 a);
extern struct Q func_021BE148(int a);
int func_021BDD48(Obj_021BDD48 *o);
void *func_021BDD58(int a);
void func_021BDD74(void *p);
void func_021BDD7C(Obj_021BDD7C *p, void *a);
void func_021BDD9C(Obj_021BDD9C *p);
void func_021BDDAC(Obj_021BDDAC *p);
void func_021BDDC0(Obj_021BDDC0 *p);
void func_021BDEB4(A *a);
void func_021BDFB0(char *a);
extern int d_021DE37C;




int func_021BDD48(Obj_021BDD48 *o)
{
    if (o->f08 == 0) {
        return 1;
    }
    return 0;
}




void *func_021BDD58(int a)
{
    return func_02030734(a, 0x70, 0, (const char *)&d_021DE37C, 0x12A);
}




/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021BDD74(void *p)
{
    func_020307B0(p);
}




void func_021BDD7C(Obj_021BDD7C *p, void *a)
{
    func_02082BCC(p, 0, 0x70);
    p->f0 = a;
    p->f4 = func_02188C58(a);
    p->f64 = 0;
}




void func_021BDD9C(Obj_021BDD9C *p)
{
    p->f54 = func_0218FE80(p->f0);
}




void func_021BDDAC(Obj_021BDDAC *p)
{
    if (p->f54 != 0) {
        func_0218FE98();
        p->f54 = 0;
    }
}




/*
 * The unused `zero` vector is a dead initialised local: an initialiser keeps
 * its three stores (plain assignments are eliminated), and declaring it in an
 * inner block schedules them between the two func_0218FE78 calls.  The
 * rotation halfword is u16 (pool word 0x0000F5F7, not 0xFFFFF5F7).
 */
void func_021BDDC0(Obj_021BDDC0 *p)
{
    Sub *s = &p->s;
    Rot *t = &s->t;
    Vec_021BDD48 out;
    void *h;
    int mode;

    func_021BE17C((u8 *)p);
    h = func_02188CB4((struct Obj00020 *)p->f0);
    mode = func_021A3050(h);
    switch (mode) {
    case 2:
    case 3:
        p->f68 = 1;
        p->f6C = 0;
        break;
    case 0:
    case 1:
        p->f68 = 0;
        p->f6C = 0;
        break;
    }
    if (p->f68 == 0) {
        return;
    }
    s->f48 = 0;
    s->f44 = 0;
    if (func_021BE1B0((u32)p)) {
        func_021A7B08(p->f0, (struct V3 *)(&out));
    } else {
        func_021A3038(h, (struct VecFx32 *)&out);
    }
    func_0218FEA4(p->f54);
    func_0218FE78(p->f4, &s->f4);
    {
        Vec_021BDD48 zero = {0, 0, 0};
        func_0218FE78(p->f4, t);
    }
    switch (mode) {
    case 0:
        t->f4 = 0xB4000;
        break;
    case 1:
        break;
    case 2:
        t->f2 = 0xA09;
        break;
    case 3:
        t->f2 = -0xA09;
        break;
    }
    switch (mode) {
    case 0:
        s->f0 = 0;
        break;
    case 1:
        s->f0 = 0;
        break;
    case 2:
        s->f0 = 10;
        break;
    case 3:
        s->f0 = 10;
        break;
    }
}



/*
 * Same object layout as func_021BE068. The first switch's arms are laid
 * out in source order, cases 1-3 ahead of case 0 (its table entry for 0 is
 * the later block); the identical arms of the second switch are separate
 * blocks cross-jumped into the case-3 store.
 */
void func_021BDEB4(A *a)
{
    Vec_021BDEB4 v;
    u32 h;
    void *t;
    int m;
    S *s = &a->s;
    u8 *sub = s->sub;

    h = func_021BE17C((u8 *)a);
    t = func_02188CB4((struct Obj00020 *)a->obj);
    m = func_021A3050(t);
    switch (m) {
    case 1:
    case 2:
    case 3:
        a->f68 = 0;
        a->f6C = 1;
        break;
    case 0:
        a->f68 = 0;
        a->f6C = 0;
        break;
    }
    if (a->f6C == 0)
        return;
    s->f48 = 0;
    s->f44 = 0;
    if (func_021BE1B0((u32)a) != 0)
        func_021A7B08(a->obj, (struct V3 *)(&v));
    else
        func_021A3038(t, (struct VecFx32 *)&v);
    switch (m) {
    case 0:
        s->f00 = 0;
        break;
    case 1:
        s->f00 = 10;
        break;
    case 2:
        s->f00 = 10;
        break;
    case 3:
        s->f00 = 10;
        break;
    }
    if (func_021BE1B0((u32)a) != 0)
        func_021BE158(h, (u32)(&v));
    func_0218FEA4(a->f54);
    func_0218FE78(a->f04, &s->in);
    switch (m) {
    case 0:
        break;
    case 1:
        s->in.f08 = 0xB4000;
        break;
    case 2:
        s->in.f06 = 0xF5F7;
        break;
    case 3:
        s->in.f06 = 0xA09;
        break;
    }
    func_0218FE78(a->f04, sub);
    if (a->f6C != 0)
        func_0218FEC0((u8 *)a->f54);
}


void func_021BDFB0(char *a)
{
    char *r6 = a + 8;
    char *r4 = r6 + 0x24;
    struct Q q;
    void *r7;
    int t30;
    int x;
    int y;
    int z;

    func_021BE17C((unsigned char *)a);
    r7 = func_02188CB4((struct Obj00020 *)(*(unsigned char * *)&((struct Obj00282 *)a)->f0));
    func_021A3050(r7);
    q = func_021BE148(func_021BE194((u32)a));
    ((struct Obj09656 *)r6)->f48 = q.f3c;
    ((struct Obj09656 *)r6)->f44 = q.f38;
    t30 = q.f30;
    ((struct Obj00282 *)a)->f68 = t30;
    *(int *)&((struct Obj00282 *)a)->f6C = q.f34;
    if (t30 == 0) {
        return;
    }
    if (func_021BE1B0((u32)a) != 0) {
        func_021A7B08(*(int *)&((struct Obj00282 *)a)->f0, &q.f40);
    } else {
        func_021A3038(r7, (struct VecFx32 *)(&q.f40));
    }
    func_0218FEA4(*(int *)&((struct Obj00282 *)a)->f54);
    func_0218FE78(*(int *)&((struct Obj00282 *)a)->f4, r6 + 4);
    ((struct Obj09656 *)r6)->f0 = q.f2c;
    ((struct Obj03139 *)r4)->f0 = q.f4;
    ((struct Obj03139 *)r4)->f2 = q.f8;
    ((struct Obj03139 *)r4)->f4 = q.fc << 12;
    z = q.f28 << 12;
    y = q.f24 << 12;
    x = q.f20 << 12;
    ((struct Obj03139 *)r4)->f14 = x;
    ((struct Obj03139 *)r4)->f18 = y;
    ((struct Obj03139 *)r4)->f1C = z;
    if (q.f10 != 0) {
        z = q.f1c << 12;
        y = q.f18 << 12;
        x = q.f14 << 12;
        ((struct Obj03139 *)r4)->f8 = x;
        ((struct Obj03139 *)r4)->fC = y;
        ((struct Obj03139 *)r4)->f10 = z;
    } else {
        *(struct V3 *)(r4 + 8) = q.f40;
    }
}
