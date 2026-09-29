/*
 * function: func_021C8FF0
 * address:  0x021C8FF0
 * packet:   pkt_ov021_021C8FF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204784C  0x0204784C  arm
 *   func_020478B8  0x020478B8  arm
 *   func_02047828  0x02047828  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_02047AC8  0x02047AC8  arm
 *   d_021DABCC     0x021DABCC  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef struct T { int w[15]; } T;

extern T d_021DABCC;

extern void func_0204784C(u32 h, u32 i, u32 *v);
extern int func_020478B8(u32 h, u32 i, int v);
extern int func_02047828(u32 h, u32 i, u32 *v);
extern void func_0207ADC4(int *m);
extern void func_021AC1B8(u32 a, T *t);
extern void func_02047AC8(u32 a, T *t);

void func_021C8FF0(u32 a, u32 *b)
{
    T t;
    u32 h;

    if (b[2] == 0) {
        t = d_021DABCC;
        h = *(u32 *)(b[0] + 0x30);
        func_0204784C(h, 0, b + 1);
        if (func_020478B8(h, 0, 0x1000) == 0) {
            b[2] = 1;
        }
        if (func_02047828(h, 0, b + 1) == 0) {
            b[2] = 1;
        }
        func_0207ADC4(&t.w[6]);
        func_021AC1B8(a, &t);
        func_02047AC8(h, &t);
    }
}
