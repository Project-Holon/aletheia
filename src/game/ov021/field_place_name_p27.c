/*
 * file:     field_place_name_p27.c
 * unit:     yes
 * function: func_021BDD48, func_021BDD58, func_021BDD74, func_021BDD7C, func_021BDD9C, func_021BDDAC, func_021BDDC0
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
 */
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
} Vec;

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
int func_021BDD48(Obj_021BDD48 *o);
void *func_021BDD58(int a);
void func_021BDD74(void *p);
void func_021BDD7C(Obj_021BDD7C *p, void *a);
void func_021BDD9C(Obj_021BDD9C *p);
void func_021BDDAC(Obj_021BDDAC *p);
void func_021BDDC0(Obj_021BDDC0 *p);
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
    Vec out;
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
        Vec zero = {0, 0, 0};
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
