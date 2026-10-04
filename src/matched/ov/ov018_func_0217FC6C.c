/*
 * function: func_0217FC6C
 * address:  0x0217FC6C
 * packet:   pkt_ov018_0217FC6C
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
 *   func_0217545C  0x0217545C  thumb ov011
 *   func_0217FCAC  0x0217FCAC  thumb ov018
 */

typedef unsigned short u16;

typedef unsigned int   u32;
struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void func_02082BCC(void *p, int v, int n);
typedef unsigned char  u8;
void func_0217545C(u8 *p);
int func_0217FCAC(int x, int *st, int *obj);

void *func_0217FC6C(void *p, int a, int b, int c, int d, u16 e)
{
    void *r = func_020122C0(p, 0, func_0217FCAC, 0x10);
    int *q = func_020124E8(r);

    func_02082BCC(q, 0, 0x10);
    q[0] = a;
    q[1] = c;
    q[2] = d;
    *(u16 *)(q + 3) = e;
    func_0217545C((u8 *)b);
    return r;
}
