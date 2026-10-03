/*
 * function: func_021B9630
 * address:  0x021B9630
 * packet:   pkt_021B9630
 * region:   ov181
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0207D534  0x0207D534  arm
 *   func_02005DAC  0x02005DAC  thumb
 *   func_021B98F4  0x021B98F4  thumb  ov181
 *   func_021B9908  0x021B9908  thumb  ov181
 *   func_021B99F8  0x021B99F8  thumb  ov181
 *   func_021B9B1C  0x021B9B1C  thumb  ov181
 *   func_021B9D34  0x021B9D34  thumb  ov181
 *   func_021B9E14  0x021B9E14  thumb  ov181
 *   func_021B9D04  0x021B9D04  thumb  ov181
 *   func_021B9AF8  0x021B9AF8  thumb  ov181
 *   ov067_id       0x00000043  data
 */
typedef unsigned char u8;
typedef unsigned short u16;

typedef signed int     s32;
typedef unsigned int   u32;
extern int func_02034AC4(s32 handle);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0204363C(u32 swap);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_02005DAC(int a);
extern void func_021B98F4(void);
extern void func_021B9908(void);
extern void func_021B99F8(void);
extern void func_021B9B1C(void *p);
extern void func_021B9D34(void *p);
extern void func_021B9E14(void *p);
extern void func_021B9D04(void *p);
extern void func_021B9AF8(void *p);
extern u8 ov067_id[];

int func_021B9630(u8 *p)
{
    func_02034AC4((int)ov067_id);
    func_02043534(0);
    func_020435F4(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_0204363C(1);
    func_0207D534((void *)0x0400006c, -0x10);
    func_0207D534((void *)0x0400106c, -0x10);
    func_021B98F4();
    func_021B9908();
    func_021B99F8();
    func_021B9B1C(p);
    func_021B9D34(p);
    func_021B9E14(p);
    func_021B9D04(p);
    func_021B9AF8(p);
    func_02005DAC(0x3f8);
    return 3;
}

