/*
 * function: func_021BDDC0
 * address:  0x021BDDC0
 * packet:   pkt_ov021_021BDDC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The unused `zero` vector is a dead initialised local: an initialiser keeps
 * its three stores (plain assignments are eliminated), and declaring it in an
 * inner block schedules them between the two func_0218FE78 calls.  The
 * rotation halfword is u16 (pool word 0x0000F5F7, not 0xFFFFF5F7).
 *
 * symbols:
 *   func_021BE17C  0x021BE17C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021BE1B0  0x021BE1B0  thumb  ov021
 *   func_021A7B08  0x021A7B08  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0218FEA4  0x0218FEA4  thumb  ov021
 *   func_0218FE78  0x0218FE78  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
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
} Obj;

extern u32 func_021BE17C(Obj *p);
extern void *func_02188CB4(unsigned char *p);
extern int func_021A3050(u32 a);
extern int func_021BE1B0(Obj *p);
extern void func_021A7B08(u32 a, Vec *out);
extern void func_021A3038(u32 a, Vec *out);
extern void func_0218FEA4(u32 a);
extern void func_0218FE78(u32 a, void *dst);

void func_021BDDC0(Obj *p)
{
    Sub *s = &p->s;
    Rot *t = &s->t;
    Vec out;
    void *h;
    int mode;

    func_021BE17C(p);
    h = func_02188CB4(p->f0);
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
    if (func_021BE1B0(p)) {
        func_021A7B08(p->f0, &out);
    } else {
        func_021A3038(h, &out);
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
