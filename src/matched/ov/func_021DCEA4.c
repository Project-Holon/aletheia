/*
 * function: func_021DCEA4
 * address:  0x021DCEA4
 * packet:   pkt_021DCEA4
 * region:   ov171
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
 *   func_0203D34C  0x0203D34C  arm
 *   func_021DCCC8  0x021DCCC8  thumb  ov171
 *   func_021DC910  0x021DC910  thumb  ov171
 *   func_021DC92C  0x021DC92C  thumb  ov171
 *   func_021DCA7C  0x021DCA7C  thumb  ov171
 *   func_021DCB70  0x021DCB70  thumb  ov171
 *   func_021DCC24  0x021DCC24  thumb  ov171
 *   func_021DD874  0x021DD874  thumb  ov171
 *   func_021DDFE8  0x021DDFE8  thumb  ov171
 *   func_021DD0E8  0x021DD0E8  thumb  ov171
 *   func_021DCC0C  0x021DCC0C  thumb  ov171
 *   func_021DC8B8  0x021DC8B8  thumb  ov171
 *   func_021DD4A4  0x021DD4A4  thumb  ov171
 *   ov067_id       0x00000043  data
 */
typedef unsigned char u8;
typedef unsigned short u16;

extern void func_02034AC4(int a);
extern void func_02043534(int a);
extern void func_020435F4(int a);
extern void func_0204363C(int a);
extern void func_0207D534(void *p, int n);
extern void func_0203D34C(int a, int b);
extern void func_021DCCC8(void *p);
extern void func_021DC910(void);
extern void func_021DC92C(void);
extern void func_021DCA7C(void);
extern void func_021DCB70(void *p);
extern void func_021DCC24(void *p);
extern void func_021DD874(void *p);
extern void func_021DDFE8(void *p);
extern void func_021DD0E8(void *p);
extern void func_021DCC0C(void);
extern void func_021DC8B8(void *p);
extern void func_021DD4A4(void *p, int a);
extern u8 ov067_id[];

void func_021DCEA4(u8 *p)
{
    func_02034AC4((int)ov067_id);
    func_02043534(0);
    func_020435F4(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_0204363C(0);
    func_0207D534((void *)0x0400006c, -0x10);
    func_0207D534((void *)0x0400106c, -0x10);
    func_021DCCC8(p);
    func_021DC910();
    func_021DC92C();
    func_021DCA7C();
    func_021DCB70(p);
    func_021DCC24(p);
    func_021DD874(p);
    func_021DDFE8(p);
    func_021DD0E8(p);
    func_021DCC0C();
    func_0203D34C(1, 0x8c);
    func_021DC8B8(p);
    func_021DD4A4(p, 4);
}
