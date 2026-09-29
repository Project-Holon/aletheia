/*
 * function: func_0217FC08
 * address:  0x0217FC08
 * packet:   pkt_ov018_0217FC08
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_0217FDA0  0x0217FDA0  thumb ov018
 *   func_0217538C  0x0217538C  thumb  ov011
 *   func_02175368  0x02175368  thumb  ov011
 *   func_021803F0  0x021803F0  thumb  ov018
 *   func_0217FE6C  0x0217FE6C  thumb  ov018
 */

typedef unsigned char u8;
typedef unsigned short u16;

void *func_020122C0(void *p, int a, void *cb, int n);
void *func_020124E8(void *p);
void func_02082BCC(void *p, int v, int n);
void func_0217FDA0(int a, int *b, u8 *c, int d, int e, int f, int g);
void func_0217538C(u8 *w, int a);
void func_02175368(u8 *w);
int func_021803F0(u8 *a, u8 *b);
int func_0217FE6C(void);

void *func_0217FC08(int a, int b, u8 *c, int d, int e, u16 f)
{
    void *r = func_020122C0((void *)a, 0, func_0217FE6C, 0x9c);
    u8 *q = func_020124E8(r);

    func_02082BCC(q, 0, 0x9c);
    func_0217FDA0(a, (int *)c, q, b, d, e, f);
    func_0217538C(c, e);
    func_02175368(c);
    q[0x41] = func_021803F0(q, c);
    return r;
}
