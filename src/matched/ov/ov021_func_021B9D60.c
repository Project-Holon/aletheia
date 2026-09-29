/*
 * function: func_021B9D60
 * address:  0x021B9D60
 * packet:   pkt_ov021_021B9D60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of func_021B9B7C and func_021B9C28: position from the +0x30 vectors
 * of the func_021B833C/func_021B834C objects through func_021B9B24, then a
 * sideways push along the normalised direction (the segment's cross with
 * d_021D9A60 when the direction has a zero x or z).
 * Both call results go to u8 * locals and the two +0x30 pointers are
 * formed from them after the second call: `(V *)(call + 0x30)` hoists a's
 * add above the second call, and reassigning a/b in place swaps p and b
 * between r4 and r5. d_021D9A60 carries no ov021 token (sole-ref/data
 * resolves it; with the token it has no outside witness).
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
 *   d_021D9A60     0x021D9A60  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef long long      s64;

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
extern V d_021D9A60;

void func_021B9D60(void *p, V *out)
{
    V c;
    V d;
    V e;
    V g;
    V f;
    V h;
    V i;
    V w;
    int s;
    V *a;
    V *b;
    u8 *q;
    u8 *ta;
    u8 *tb;
    int r;

    func_021B82F4(p);
    ta = func_021B833C(p);
    tb = func_021B834C(p);
    a = (V *)(ta + 0x30);
    b = (V *)(tb + 0x30);
    s = func_0207C768(func_021B82F8(p) << 12, func_021B82FC(p) << 12);
    q = func_021B835C(p);
    c.x = *(int *)(q + 4);
    c.y = *(int *)(q + 8);
    c.z = *(int *)(q + 0xc);
    func_0207CA00(a, &c, &d);
    func_0207CA00(b, &c, &e);
    func_0207CA00(&e, &d, &f);
    func_0207CCA4(&f, &f);
    func_021B9B24(&g, &d, &e, s);
    func_0207C9D0(&c, &g, out);
    r = (int)(((s64)(func_021B8300(p) << 12) * func_021B8308(p) + 0x800) >> 12);
    if (g.x != 0 && g.z != 0) {
        g.y = 0;
    } else {
        w = d_021D9A60;
        func_0207CA00(b, a, &g);
        func_0207CAE8(&g, &w, &g);
    }
    func_0207CCA4(&g, &h);
    func_0207CAE8(&h, &f, &i);
    if (i.y < 0) {
        func_0207CEE4(-r, &h, out, out);
    } else {
        func_0207CEE4(r, &h, out, out);
    }
}
