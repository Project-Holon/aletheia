/*
 * function: func_0217C14C
 * address:  0x0217C14C
 * packet:   pkt_ov018_0217C14C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   d_021835D4     0x021835D4  data   a4
 */

typedef unsigned short u16;

typedef struct {
    u16 h0;
    u16 h2;
    int w4;
} T;

typedef struct {
    int w[7];
    T t;
} S;

extern void *func_02188C7C(unsigned char *p);
typedef unsigned char  u8;
extern u16 func_02188C9C(u8 *p);
extern void func_0216CE60(int a, int b, int c);
extern const S d_021835D4;

void func_0217C14C(int a0, u16 a1, u16 a2, int a3)
{
    void *v;
    int c;
    S s;
    T *t;

    v = func_02188C7C((void *)a0);
    c = func_02188C9C((u8 *)a0);
    s = d_021835D4;
    t = &s.t;
    t->h0 = a1;
    t->h2 = a2;
    t->w4 = a3;
    func_0216CE60((int)v, (int)(&s), c);
}
