/*
 * function: func_02158DE8
 * address:  0x02158DE8
 * packet:   pkt_ov010_02158DE8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A5D4  0x0215A5D4  thumb  ov010
 *   func_0215A5D8  0x0215A5D8  thumb  ov010
 *   func_02158DBC  0x02158DBC  thumb  ov010
 *   d_02170374     0x02170374  data  ov010
 */

typedef unsigned char u8;

struct Bits { u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; };

struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void func_0215A5D4(int);
extern int func_0215A5D8(int);
extern void func_02158DBC(void);
extern struct Bits d_02170374[];

int func_02158DE8(int a, int b, int c, int idx)
{
    int m, r;
    func_0201210C((void *)c);
    func_0215A5D4(b);
    m = func_0215A5D8(b);
    r = 0;
    switch (m) {
    case 0: r = d_02170374[idx].b0; break;
    case 1: r = d_02170374[idx].b1; break;
    case 2: r = d_02170374[idx].b2; break;
    }
    if (r == 0)
        func_02158DBC();
    return r;
}
