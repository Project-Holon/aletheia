/*
 * function: func_021B0B08
 * address:  0x021B0B08
 * packet:   pkt_ov021_021B0B08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B0B08  0x021B0B08  thumb
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0215A63C  0x0215A63C  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_0215A66C  0x0215A66C  thumb  ov010
 *   func_021B0960  0x021B0960  thumb
 */

typedef unsigned short u16;

typedef struct V3 {
    int x, y, z;
} V3;

typedef struct S {
    u16 id;
    u16 pad;
    V3 sum;
    V3 a;
    V3 b;
} S;

extern void *func_0215A5EC(void *);
extern S *func_0215A63C(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Ctx;
extern void *func_0216DE94(void *map, u32 id);
extern u16 func_0216D5F8(void *p);
extern void func_0216D88C(void *, V3 *);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188C58(void *);
extern u32 func_0218EC2C(u8 *p);
extern u8 func_0215A66C(u8 *p);
extern void func_021B0960(V3 *, V3 *, int, int, int);

void func_021B0B08(void *a, int b)
{
    void *t = func_0215A5EC(a);
    S *s = func_0215A63C(a);
    void *o = func_0216DE94(t, s->id);
    V3 v;
    if (o != 0) {
        func_0216D5F8(o);
        func_0216D88C(o, &v);
        if (b == 1 || v.x != s->a.x || v.y != s->a.y || v.z != s->a.z) {
            int p, q;
            s->a = v;
            p = func_02188C58(func_0201210C(func_0215A5DC(a)));
            q = func_0218EC2C((void *)p);
            func_021B0960(&s->a, &s->b, q, p, func_0215A66C(a));
        }
        s->sum.x = s->a.x + s->b.x;
        s->sum.y = s->a.y + s->b.y;
        s->sum.z = s->a.z + s->b.z;
    }
}
