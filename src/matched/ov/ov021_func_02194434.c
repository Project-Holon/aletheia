/*
 * function: func_02194434
 * address:  0x02194434
 * packet:   pkt_ov021_02194434
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021D3F68     0x021D3F68  data  ov021  a4
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   func_02194588  0x02194588  thumb  ov021
 *   func_021945A0  0x021945A0  thumb  ov021
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DC98  0x0216DC98  thumb  ov010
 *   func_0216DB80  0x0216DB80  thumb  ov010
 *   func_0216DAE0  0x0216DAE0  thumb  ov010
 *   func_0216DC64  0x0216DC64  thumb  ov010
 *   func_0216DCCC  0x0216DCCC  thumb  ov010
 */

typedef unsigned short u16;
typedef struct { unsigned w[9]; } T;

extern T d_021D3F68;

extern void *func_0216CE60(void *a, void *b, int c);
extern void func_02194588(void *o, void *q, int d, int e, int f);
extern int func_021945A0(int x);
extern void func_0216E014(void *o, int d, int n);
extern void func_0216DB4C(void *o, int v);
extern void func_0216DC98(void *o, int v);
extern void func_0216DB80(unsigned int *p, unsigned int v);
extern void func_0216DAE0(unsigned int *p, unsigned int v);
extern void func_0216DC64(void *o, int v);
extern void func_0216DCCC(void *o, int v);

void *func_02194434(unsigned char *a, int x, u16 *q, int d, int e, int f)
{
    void *m = *(void **)(a + 4);
    T local = d_021D3F68;
    void *o;

    *(u16 *)((unsigned char *)&local + 2) = x;
    o = func_0216CE60(m, &local, 0);
    func_02194588(o, q, d, e, f);
    func_0216E014(o, d, func_021945A0(*q));
    func_0216DB4C(o, 1);
    func_0216DC98(o, 1);
    func_0216DB80(o, 1);
    func_0216DAE0(o, 0);
    func_0216DC64(o, 1);
    func_0216DCCC(o, 1);
    return o;
}
