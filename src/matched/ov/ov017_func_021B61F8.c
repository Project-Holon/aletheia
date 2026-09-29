/*
 * function: func_021B61F8
 * address:  0x021B61F8
 * packet:   pkt_ov017_021B61F8
 * region:   ov017
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D534  0x0207D534  arm
 *   func_020808F4  0x020808F4  arm
 *   func_020809A0  0x020809A0  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   func_0207D4B0  0x0207D4B0  arm
 *   func_021B6298  0x021B6298  thumb  ov017
 *   func_021B6368  0x021B6368  thumb  ov017
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0207D534(u32, int);
extern void func_020808F4(void);
extern void func_020809A0(void);
extern void func_0207FDCC(int);
extern void func_0207D4B0(int, int, int);
extern void func_021B6298(void);
extern void func_021B6368(int);

#define R32(a) (*(volatile u32 *)(a))
#define R16(a) (*(volatile u16 *)(a))

void func_021B61F8(int a)
{
    func_0207D534(0x0400006C, -16);
    func_0207D534(0x0400106C, -16);
    func_020808F4();
    func_020809A0();
    func_0207FDCC(4);
    func_0207D4B0(1, 0, 0);
    R32(0x04000000) = (R32(0x04000000) & 0xFFFFE0FF) | (1 << 9);
    R32(0x04000000) &= 0xFFFF1FFF;
    R16(0x0400000A) = (R16(0x0400000A) & 0x43) | 4;
    R16(0x0400000A) &= 0xFFBF;
    R32(0x04000014) = 0;
    R16(0x04000050) = 0;
    func_021B6298();
    func_021B6368(a);
    func_0207D534(0x0400006C, 0);
    func_0207D534(0x0400106C, 0x10);
}
