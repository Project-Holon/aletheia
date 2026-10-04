/*
 * function: func_021BCF8C
 * address:  0x021BCF8C
 * packet:   pkt_ov210_021BCF8C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   ov067_id  0x00000043  data
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0207D534  0x0207D534  arm
 *   func_0200CA70  0x0200CA70  thumb
 *   func_0203D34C  0x0203D34C  arm
 *   func_021BC3D4  0x021BC3D4  thumb  ov210
 *   func_021BC3F0  0x021BC3F0  thumb  ov210
 *   func_021BC5DC  0x021BC5DC  thumb  ov210
 *   func_021BC940  0x021BC940  thumb  ov210
 *   func_021BE368  0x021BE368  thumb  ov210
 *   func_021BED2C  0x021BED2C  thumb  ov210
 *   func_021BC9D0  0x021BC9D0  thumb  ov210
 *   func_021BCA20  0x021BCA20  thumb  ov210
 *   func_021BCDA4  0x021BCDA4  thumb  ov210
 *   func_021BC790  0x021BC790  thumb  ov210
 *   func_021BC82C  0x021BC82C  thumb  ov210
 *   func_021BCBB8  0x021BCBB8  thumb  ov210
 *   func_021BC8EC  0x021BC8EC  thumb  ov210
 *   func_021BC294  0x021BC294  thumb  ov210
 *   func_021BC318  0x021BC318  thumb  ov210
 *   func_021BCF0C  0x021BCF0C  thumb  ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern u8 ov067_id[];
extern int func_02034AC4(s32 handle);
extern void func_02043534(u32 a);
extern void func_020435F4(u32 a);
extern void func_0204363C(u32 a);
struct Blk37;
extern void func_0207D534(volatile u16 *reg, int brightness);
extern u32 func_0200CA70(struct Blk37 *p);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021BC3D4(void);
extern void func_021BC3F0(void);
extern void func_021BC5DC(void);
extern void func_021BC940(u8 *p);
extern void func_021BE368(u8 *p);
extern void func_021BED2C(int p);
extern void func_021BC9D0(int p);
extern void func_021BCA20(u8 *p);
extern void func_021BCDA4(u8 *p);
extern void func_021BC790(u8 *p);
extern void func_021BC82C(u8 *p, u32 a, u32 b);
extern void func_021BCBB8(u8 *p);
extern void func_021BC8EC(void);
extern void func_021BC294(u8 *p);
extern void func_021BC318(u8 *p);
extern void func_021BCF0C(u8 *p);

u32 func_021BCF8C(u8 *p)
{
    u32 z;
    u32 ra = 0x04000050;
    u32 rb = 0x04001050;
    int m;

    func_02034AC4((u32)ov067_id);
    z = 0;
    func_02043534(0);
    func_020435F4(0);
    *(volatile u16 *)ra = z;
    *(volatile u16 *)rb = z;
    func_0204363C(0);
    m = -16;
    func_0207D534((volatile u16 *)(ra + 0x1c), m);
    func_0207D534((volatile u16 *)(rb + 0x1c), m);
    if (func_0200CA70((struct Blk37 *)(*(u32 *)(*(u8 **)p + 4))) == 1) {
        *(u8 *)(*(u8 **)(*(u8 **)p + 8)) = z;
    } else {
        *(u8 *)(*(u8 **)(*(u8 **)p + 8)) = 1;
    }
    func_021BC3D4();
    func_021BC3F0();
    func_021BC5DC();
    func_021BC940(p);
    func_021BE368(p);
    func_021BED2C((int)p);
    func_021BC9D0((int)p);
    func_0203D34C(1, 0x7b);
    func_021BCA20(p);
    func_021BCDA4(p);
    func_021BC790(p);
    func_021BC82C(p, 16, 16);
    func_021BCBB8(p);
    func_021BC8EC();
    func_021BC294(p);
    func_021BC318(p);
    p[0x2b9] = 0xff;
    func_021BCF0C(p);
    return 3;
}
