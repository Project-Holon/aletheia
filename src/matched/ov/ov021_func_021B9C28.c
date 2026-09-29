/*
 * function: func_021B9C28
 * address:  0x021B9C28
 * packet:   pkt_ov021_021B9C28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of func_021B9B7C: height interpolated between the two +0x30 vectors
 * of the func_021B833C/func_021B834C objects, then func_021B9B24 on the
 * flattened offsets and a sideways push along the normalised result.
 *
 * t1/t2 stay raw in [sp]/[sp,#4] and are shifted `<< 12` at every use
 * because the first call spells the shift over `(u32)` and the second over
 * the plain int: the two shifts are different expressions, so 1.1p1 does not
 * CSE them into a saved fx value (which cost a fourth stack slot).
 *
 * symbols:
 *   func_021B82F4  0x021B82F4  thumb  ov021
 *   func_021B82F8  0x021B82F8  thumb  ov021
 *   func_021B82FC  0x021B82FC  thumb  ov021
 *   func_021B8300  0x021B8300  thumb  ov021
 *   func_021B8308  0x021B8308  thumb  ov021
 *   func_021B833C  0x021B833C  thumb  ov021
 *   func_021B834C  0x021B834C  thumb  ov021
 *   func_021B835C  0x021B835C  thumb  ov021
 *   func_021B9B24  0x021B9B24  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CEE4  0x0207CEE4  arm
 *   _ll_mul        0x0209C054  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef long long      s64;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

void func_021B82F4(void *p);
int func_021B82F8(void *p);
int func_021B82FC(void *p);
int func_021B8300(void *p);
int func_021B8308(void *p);
u8 *func_021B833C(void *p);
u8 *func_021B834C(void *p);
u8 *func_021B835C(void *p);
void func_021B9B24(V *a, V *b, V *c, int k);
int func_0207C768(int a, int b);
void func_0207C9D0(V *a, V *b, V *c);
void func_0207CA00(V *a, V *b, V *c);
void func_0207CAE8(V *a, V *b, V *c);
void func_0207CCA4(V *a, V *b);
void func_0207CEE4(int s, V *a, V *b, V *c);

static inline int FX_Mul(int a, int b)
{
    return (int)(((s64)a * b + 0x800) >> 12);
}

void func_021B9C28(void *p, V *out)
{
    V c;
    V d;
    V e;
    V g;
    V f;
    V h;
    V i;
    int s;
    int t2;
    int t1;
    V *a;
    V *b;
    u8 *q;
    int r;

    func_021B82F4(p);
    a = (V *)func_021B833C(p);
    b = (V *)func_021B834C(p);
    a = (V *)((u8 *)a + 0x30);
    b = (V *)((u8 *)b + 0x30);
    t1 = func_021B82F8(p);
    t2 = func_021B82FC(p);
    s = func_0207C768((u32)t1 << 12, (u32)t2 << 12);
    out->y = b->y - a->y;
    out->y = func_0207C768(FX_Mul(out->y, t1 << 12), t2 << 12);
    out->y += a->y;
    q = func_021B835C(p);
    c.x = *(int *)(q + 4);
    c.y = out->y;
    c.z = *(int *)(q + 0xc);
    func_0207CA00(a, &c, &d);
    func_0207CA00(b, &c, &e);
    d.y = 0;
    e.y = 0;
    func_0207CA00(&e, &d, &f);
    f.y = 0;
    func_0207CCA4(&f, &f);
    func_021B9B24(&g, &d, &e, s);
    func_0207C9D0(&c, &g, out);
    r = (int)(((s64)(func_021B8300(p) << 12) * func_021B8308(p) + 0x800) >> 12);
    func_0207CCA4(&g, &h);
    func_0207CAE8(&h, &f, &i);
    if (i.y < 0) {
        func_0207CEE4(-r, &h, out, out);
    } else {
        func_0207CEE4(r, &h, out, out);
    }
}
