/*
 * function: func_021BB4BC
 * address:  0x021BB4BC
 * packet:   pkt_ov021_021BB4BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   func_0204767C  0x0204767C  arm
 *   d_021D9A6C     0x021D9A6C  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern u32 func_021ABE24(u32);
extern u32 func_02046E24(u32, u32);
extern int func_02046FF8(int *self);
extern u32 func_02047400(u32, u32, u32);
extern u32 func_0204767C(u32, u32, u32);
extern u32 d_021D9A6C[];

void func_021BB4BC(u32 *p)
{
    u32 h = func_021ABE24(p[0]);
    int i;

    for (i = 0; i < 4; i++) {
        p[1 + i] = func_02046E24(h, d_021D9A6C[i]);
        func_02046FF8((int *)p[1 + i]);
        p[5 + i] = func_02047400(p[1 + i], 0, p[1 + i]);
        p[9 + i] = func_0204767C(p[5 + i], 0, 0);
    }
    *(u16 *)((char *)p + 0x34) = 4;
}
