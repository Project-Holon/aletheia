/*
 * function: func_0218C2E4
 * address:  0x0218C2E4
 * packet:   pkt_ov021_0218C2E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Starts a group of slots, sets a parameter, marks them state 4.
 *
 * symbols:
 *   func_0218BCAC  0x0218BCAC  thumb  ov021
 *   func_020477A4  0x020477A4  arm
 *   func_02047790  0x02047790  arm
 *   func_02047674  0x02047674  arm
 *   func_0204784C  0x0204784C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *func_0218BCAC(u8 *p);
struct G3dSys;
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern int func_02047790(int *p, int i);
extern int func_02047674(int p);
typedef signed int     s32;
struct AnmCtl;
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);

void func_0218C2E4(u32 *st, int n)
{
    u8 *q = func_0218BCAC(*(u8 **)st[1]);
    int base = q[2] * n;
    int i;
    int v;

    for (i = 0; i < q[2]; i++) {
        func_020477A4((struct G3dSys *)st[0], (u16)(base + i));
        v = *(u16 *)(*(u8 **)(func_02047674((int)func_02047790((int *)st[0], (u16)(base + i))) + 8) + 4) << 12;
        func_0204784C((struct AnmCtl *)st[0], base + i, &v);
        (st + base)[2 + i] = 4;
    }
}
