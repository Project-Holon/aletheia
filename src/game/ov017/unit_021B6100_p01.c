/*
 * file:     unit_021B6100_p01.c
 * unit:     yes
 * function: func_021B6100, func_021B61F8
 * address:  0x021B6100
 * region:   ov017
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_020053EC  0x020053EC  thumb
 *   func_02034F5C  0x02034F5C  arm
 *   func_021B641C  0x021B641C  thumb  ov017
 *   func_0207D534  0x0207D534  arm
 *   func_020808F4  0x020808F4  arm
 *   func_020809A0  0x020809A0  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   func_0207D4B0  0x0207D4B0  arm
 *   func_021B6298  0x021B6298  thumb  ov017
 *   func_021B6368  0x021B6368  thumb  ov017
 */
#define R32(a) (*(volatile u32 *)(a))
#define R16(a) (*(volatile u16 *)(a))
typedef unsigned short u16;

typedef unsigned int   u32;

extern u32 func_0202EB0C(void);
extern void func_020053EC(void);
extern void func_02034F5C(void);
extern void func_021B641C(void);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern int func_020808F4(void);
extern int func_020809A0(void);
extern void func_0207FDCC(int);
extern void func_0207D4B0(int, int, int);
extern void func_021B6298(void);
extern void func_021B6368(int);
void func_021B6100(void);
void func_021B61F8(int a);


static inline u16 ReadKeys(void)
{
    u16 k = (u16)(((*(volatile u16 *)0x04000130 | *(volatile u16 *)0x02FFFFA8) ^ 0x2FFF) & 0x2FFF);
    k = (u16)(k & ~((k & 0x40) << 1) & ~((k & 0x20) >> 1));
    return k;
}


void func_021B6100(void)
{
    func_021B61F8(func_0202EB0C() ? 0x2A : 0x10);
    while (ReadKeys() & 3) {
        func_020053EC();
        func_02034F5C();
    }
    while (!(ReadKeys() & 3)) {
        func_020053EC();
        func_02034F5C();
    }
    func_021B641C();
}


void func_021B61F8(int a)
{
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
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
    func_0207D534((volatile u16 *)0x0400006C, 0);
    func_0207D534((volatile u16 *)0x0400106C, 0x10);
}
