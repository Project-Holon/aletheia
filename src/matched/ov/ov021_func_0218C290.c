/*
 * function: func_0218C290
 * address:  0x0218C290
 * packet:   pkt_ov021_0218C290
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Starts a group of slots and marks them state 1.
 *
 * symbols:
 *   func_0218BCAC  0x0218BCAC  thumb  ov021
 *   func_020477A4  0x020477A4  arm
 *   func_02047804  0x02047804  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *func_0218BCAC(u8 *p);
extern void func_020477A4(u32 h, u16 i);
extern void func_02047804(u32 h, u16 i);

void func_0218C290(u32 *st, int n)
{
    u8 *q = func_0218BCAC(*(u8 **)st[1]);
    int base = q[2] * n;
    int i;

    for (i = 0; i < q[2]; i++) {
        func_020477A4(st[0], base + i);
        func_02047804(st[0], base + i);
        (st + base)[2 + i] = 1;
    }
}
