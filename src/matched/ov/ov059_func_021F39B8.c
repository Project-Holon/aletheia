/*
 * function: func_021F39B8
 * address:  0x021F39B8
 * packet:   pkt_ov059_021F39B8
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     twin of ov059 func_021F3AA0. Returns func_020122C0's result (a
 *           void return moves the final store to r0/r1); d is const V *
 *           (without it the second struct copy loads w before d), and the
 *           sixth parameter is read with ldr, so it is int.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F3B90  0x021F3B90  thumb  ov059
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef struct {
    int b;
    V c;
    V d;
    int e;
    u16 f;
    u16 g;
} W;

typedef unsigned int   u32;
struct Ctx;
struct Desc;
extern void *func_0201210C(const struct Ctx *p);
extern W *func_021897BC(void *p, int i);
extern void *func_02188D2C(void *p);
extern void func_020061E4(u32 a);
extern V *func_021BE480(void *p, int i, u16 j);
extern void func_021BE4B4(void *p, int i, u16 j, int v);
extern u8 *func_021BE674(void *p, int i, u16 j, u16 k);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE700(void *p, int i, u16 j, u16 k, int flag);
extern void func_021BE6CC(void *p, int i, u16 j, u16 k, int flag);
extern int func_021F3B90(void *a);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);

void *func_021F39B8(void *a, int b, V *c, const V *d, int e, int f)
{
    int i;
    void *t;
    void *s;
    void *r;
    W *w;
    int flag;

    t = func_0201210C(a);
    flag = 1;
    w = func_021897BC(t, 1);
    s = func_02188D2C(t);
    if (b == 0) {
        flag = 0;
        func_020061E4(0x566);
    }
    *func_021BE480(s, 0, flag) = *c;
    func_021BE4B4(s, 0, flag, 0);
    for (i = 0; i < 3; i++) {
        func_021BE6B0(func_021BE674(s, 0, flag, i), 1);
        func_021BE700(s, 0, flag, i, 0);
        func_021BE6CC(s, 0, flag, i, 0);
    }
    w->c = *c;
    w->d = *d;
    w->f = f;
    w->g = 0;
    w->e = e;
    r = func_020122C0(a, 0, func_021F3B90, 0);
    w->b = b;
    return r;
}
