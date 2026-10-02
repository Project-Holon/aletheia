/*
 * function: func_021BDEB4
 * address:  0x021BDEB4
 * packet:   pkt_ov021_021BDEB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE17C  0x021BE17C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021BE1B0  0x021BE1B0  thumb  ov021
 *   func_021A7B08  0x021A7B08  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021BE158  0x021BE158  thumb  ov021
 *   func_0218FEA4  0x0218FEA4  thumb  ov021
 *   func_0218FE78  0x0218FE78  thumb  ov021
 *   func_0218FEC0  0x0218FEC0  thumb  ov021
 *
 * Same object layout as func_021BE068. The first switch's arms are laid
 * out in source order, cases 1-3 ahead of case 0 (its table entry for 0 is
 * the later block); the identical arms of the second switch are separate
 * blocks cross-jumped into the case-3 store.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec;

typedef struct {
    u16 f04;
    u16 f06;
    int f08;
    Vec pos;
    Vec rot;
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

extern u32 func_021BE17C(A *a);
extern void *func_02188CB4(unsigned char *p);
extern int func_021A3050(void *t);
extern int func_021BE1B0(A *a);
extern void func_021A7B08(u32 o, Vec *v);
extern void func_021A3038(void *t, Vec *v);
extern void func_021BE158(u32 h, Vec *v);
extern void func_0218FEA4(u32 p);
extern void func_0218FE78(u32 p, void *sub);
extern void func_0218FEC0(u32 p);

void func_021BDEB4(A *a)
{
    Vec v;
    u32 h;
    void *t;
    int m;
    S *s = &a->s;
    u8 *sub = s->sub;

    h = func_021BE17C(a);
    t = func_02188CB4((unsigned char *)a->obj);
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
    if (func_021BE1B0(a) != 0)
        func_021A7B08(a->obj, &v);
    else
        func_021A3038(t, &v);
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
    if (func_021BE1B0(a) != 0)
        func_021BE158(h, &v);
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
        func_0218FEC0(a->f54);
}
