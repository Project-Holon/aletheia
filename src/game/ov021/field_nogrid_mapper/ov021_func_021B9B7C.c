/*
 * function: func_021B9B7C
 * address:  0x021B9B7C
 * packet:   pkt_ov021_021B9B7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The +0x30 vector of the func_021B833C object replaces the object pointer
 * in place (`adds r4,#0x30` after the func_021B834C call).  That needs the
 * second call's result bound to a local and the `a += 0x30` as its own
 * statement after it: inline in the argument list the add is hoisted ahead
 * of the call, and without reassigning `a` the compiler keeps both a and
 * a + 0x30 and swaps the s/a registers.
 *
 * symbols:
 *   func_021B82F4  0x021B82F4  thumb  ov021
 *   func_021B82F8  0x021B82F8  thumb  ov021
 *   func_021B82FC  0x021B82FC  thumb  ov021
 *   func_021B8300  0x021B8300  thumb  ov021
 *   func_021B8308  0x021B8308  thumb  ov021
 *   func_021B833C  0x021B833C  thumb  ov021
 *   func_021B834C  0x021B834C  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CEE4  0x0207CEE4  arm
 *   _ll_mul        0x0209C054  arm
 *   d_021D9A54     0x021D9A54  data  ov021  a4
 */

typedef unsigned char  u8;
typedef long long      s64;

typedef struct { int x, y, z; } V;

typedef unsigned int   u32;
u32 func_021B82F4(u8 *p);
u32 func_021B82F8(u8 *p);
u32 func_021B82FC(u8 *p);
u32 func_021B8300(u8 *p);
u32 func_021B8308(u8 *p);
u8 *func_021B833C(u8 *p);
u8 *func_021B834C(u8 *p);
u32 func_0207C768(u32 a, u32 b);
void func_0207CA00(V *a, V *b, V *c);
void func_0207CAE8(V *a, V *b, V *c);
void func_0207CCA4(V *a, V *b);
void func_0207CEE4(int s, V *a, V *b, V *c);
extern V d_021D9A54;

void func_021B9B7C(void *p, V *out)
{
    V t;
    V w;
    V u;
    int s;
    V *a;
    u8 *b;
    int m;
    int k;

    func_021B82F4(p);
    s = func_0207C768(func_021B82F8(p) << 12, func_021B82FC(p) << 12);
    a = (V *)func_021B833C(p);
    b = func_021B834C(p);
    a = (V *)((u8 *)a + 0x30);
    func_0207CA00((V *)(b + 0x30), a, &t);
    func_0207CEE4(s, &t, a, out);
    w = d_021D9A54;
    m = func_021B8300(p);
    k = func_021B8308(p);
    func_0207CAE8(&t, &w, &u);
    func_0207CCA4(&u, &u);
    func_0207CEE4((int)(((s64)(m << 12) * k + 0x800) >> 12), &u, out, out);
}
