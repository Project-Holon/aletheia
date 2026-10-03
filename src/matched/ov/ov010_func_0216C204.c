/*
 * function: func_0216C204
 * address:  0x0216C204
 * packet:   pkt_ov010_0216C204
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_0218FE80  0x0218FE80  thumb  ov021
 *   func_0218FEA0  0x0218FEA0  thumb  ov021
 *   func_0216C0E8  0x0216C0E8  thumb  ov010
 *   d_02172528     0x02172528  data  ov010  a4
 */

typedef struct B32 { int w[8]; } B32;

extern int func_020122C0(int, int, void *, int);
extern int *func_020124E8(int task);
extern int func_02188C58(int);
extern int func_02188D38(int);
extern int func_0218FE80(int);
extern void func_0218FEA0(int, int *);
typedef unsigned int   u32;
struct Work;
extern int func_0216C0E8(void *evt, u32 *state, struct Work *w);
extern B32 d_02172528;

int func_0216C204(int a, int b)
{
    int r = func_020122C0(a, 0, (void *)func_0216C0E8, 0x64);
    int *p = func_020124E8(r);
    p[0] = a;
    p[1] = b;
    p[4] = 0;
    p[2] = func_02188C58(b);
    p[3] = func_02188D38(b);
    p[5] = 0x14;
    *(B32 *)(p + 14) = d_02172528;
    p[22] = 1;
    p[23] = 1;
    p[24] = func_0218FE80(b);
    func_0218FEA0(p[24], p + 5);
    return r;
}
