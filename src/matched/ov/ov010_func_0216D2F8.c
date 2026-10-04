/*
 * function: func_0216D2F8
 * address:  0x0216D2F8
 * packet:   pkt_ov010_0216D2F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D244  0x0216D244  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D268  0x0216D268  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216D730  0x0216D730  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216DAA0  0x0216DAA0  thumb  ov010
 *   func_0216E114  0x0216E114  thumb  ov010
 *   func_0216D794  0x0216D794  thumb  ov010
 *   func_0216E174  0x0216E174  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216DD1C(u32 x, u8 **o, int *n);
extern void func_0216D244(u32 x, u8 *o);
extern int func_0216D55C(int a0, int a1);
extern int func_0216D268(int a0, int a1);
extern u32 func_0216D57C(void *p, u32 v);
extern void func_0216D730(void *a0);
extern void func_0216D570(u8 *o, u32 v);
extern int func_0216DAA0(void *a0);
extern void func_0216E114(u8 *o);
extern void func_0216D794(void *a0);
extern void func_0216E174(u8 *o);

void func_0216D2F8(u32 x)
{
    int n;
    u8 *o;
    u32 a = 1;
    u32 b = 4;
    u32 c = 2;

    n = 0;
    if (func_0216DD1C(x, &o, &n) == 1) {
        do {
            func_0216D244(x, o);
            if (func_0216D55C((int)o, c) == 0)
                func_0216D268(x, (int)o);
            if (func_0216D57C(o, a)) {
                func_0216D730(o);
                func_0216D570(o, a);
            }
            if (func_0216DAA0(o) == 0)
                func_0216E114(o);
            if (func_0216D57C(o, b)) {
                func_0216D794(o);
                func_0216D570(o, b);
            }
            func_0216E174(o);
        } while (func_0216DD1C(x, &o, &n) == 1);
    }
}
