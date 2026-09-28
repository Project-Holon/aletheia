/*
 * function: func_021BE9A0
 * address:  0x021BE9A0
 * packet:   pkt_021BE9A0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator with callback, then link-node field setup with two byte fields and
 * two trailing stack arguments.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BEA6C  0x021BEA6C  thumb  ov021
 *   func_021BF0E4  0x021BF0E4  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
void *func_020124E8(void *p);
void *func_021BEA6C(int x);
void func_021BF0E4(void);

void *func_021BE9A0(void *p, int a1, int a2, int a3, int a4, int a5)
{
    void *r0v = func_020122C0(p, 0, func_021BF0E4, 0x2C);
    int *r4 = func_020124E8(r0v);

    r4[0] = (int)p;
    r4[1] = a1;
    r4[2] = 3;
    ((u8 *)r4)[0x20] = a2;
    ((u8 *)r4)[0x21] = a3;
    r4[3] = (int)func_021BEA6C(r4[2]);
    r4[9] = a4;
    r4[10] = a5;
    return r0v;
}
