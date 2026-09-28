/*
 * function: func_021616A4
 * address:  0x021616A4
 * packet:   pkt_021616A4
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator with callback, zero-fills the node, then fills link fields.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_021616F0  0x021616F0  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
void *func_020124E8(void *p);
int func_020120F4(void *p);
int func_02012EBC(int x);
void func_02082BCC(void *p, int v, int n);
void func_021616F0(void);

void *func_021616A4(void *p, int a1, int a2, int a3, int a4)
{
    void *r0v = func_020122C0(p, 0, func_021616F0, 0x1C);
    char *r4 = func_020124E8(r0v);

    func_02082BCC(r4, 0, 0x1C);
    *(int *)(r4 + 0xc) = a3;
    *(u16 *)(r4 + 0x10) = a2;
    *(int *)(r4 + 4) = (int)p;
    *(int *)(r4 + 8) = a1;
    *(int *)r4 = func_02012EBC(func_020120F4(p));
    *(int *)(r4 + 0x14) = a4;
    return r0v;
}
