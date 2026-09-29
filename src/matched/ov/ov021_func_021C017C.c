/*
 * function: func_021C017C
 * address:  0x021C017C
 * packet:   pkt_ov021_021C017C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218FE80  0x0218FE80  thumb  ov021
 *   func_0218FEA0  0x0218FEA0  thumb  ov021
 *   func_0218FEA4  0x0218FEA4  thumb  ov021
 *   func_0218FE78  0x0218FE78  thumb  ov021
 *   func_0218FEC0  0x0218FEC0  thumb  ov021
 *   func_0218FF00  0x0218FF00  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct { u32 w[8]; } Blk32;

extern u32 func_02188C58(u32 a);
extern u32 func_0218FE80(u32 a);
extern void func_0218FEA0(u32 a, u8 *b);
extern void func_0218FEA4(u32 a);
extern void func_0218FE78(u32 a, u8 *b);
extern void func_0218FEC0(u32 a);
extern void func_0218FF00(u32 a);

void func_021C017C(u8 *p)
{
    u32 a;
    u32 b;

    a = func_02188C58(*(u32 *)(p + 4));
    b = func_0218FE80(*(u32 *)(p + 4));
    *(u32 *)(p + 0x24) = 0x3c;
    *(u32 *)(p + 0x68) = 1;
    *(u32 *)(p + 0x6c) = 1;
    *(u32 *)(p + 0x70) = b;
    func_0218FEA0(b, p + 0x24);
    func_0218FEA4(*(u32 *)(p + 0x70));
    func_0218FE78(a, p + 0x28);
    *(Blk32 *)(p + 0x48) = *(Blk32 *)(p + 0x28);
    *(u32 *)(p + 0x4c) -= 0x64000;
    func_0218FEC0(*(u32 *)(p + 0x70));
    func_0218FF00(*(u32 *)(p + 0x70));
}
