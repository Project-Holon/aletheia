/*
 * function: func_0217FD34
 * address:  0x0217FD34
 * packet:   pkt_ov018_0217FD34
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_0217FDA0  0x0217FDA0  thumb ov018
 *   func_021800A4  0x021800A4  thumb ov018
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int w[13];
} S52;

void *func_020122C0(void *p, int a, void *cb, int n);
void *func_020124E8(void *p);
void func_02082BCC(void *p, int v, int n);
void func_0217FDA0(int a, int *b, u8 *c, int d, int e, int f, int g);
int func_021800A4(void);

void *func_0217FD34(int a, int b, u8 *c, int d, int e, u16 f)
{
    void *r = func_020122C0((void *)a, 0, func_021800A4, 0x9c);
    u8 *q = func_020124E8(r);

    func_02082BCC(q, 0, 0x9c);
    func_0217FDA0(a, (int *)c, q, b, d, e, f);
    q[0x41] = c[0x11c];
    *(S52 *)(q + 0x44) = *(S52 *)(c + 0x120);
    return r;
}
