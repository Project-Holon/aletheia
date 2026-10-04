/*
 * function: func_021BCC94
 * address: 0x021BCC94
 * packet: pkt_ov209_021BCC94
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: pooled 0x43 is the linker-defined ov067 id, not an integer literal
 * volatile: BLDCNT hardware zero stores at 021BCCB0, 021BCCB2
 * symbols:
 *   ov067_id 0x00000043 data a1
 *   func_02034AC4 0x02034AC4 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0207D534 0x0207D534 arm
 *   func_0204363C 0x0204363C arm
 *   func_0203D34C 0x0203D34C arm
 *   func_021BC6C4 0x021BC6C4 thumb ov209
 *   func_021BC370 0x021BC370 thumb ov209
 *   func_021BC388 0x021BC388 thumb ov209
 *   func_021BC574 0x021BC574 thumb ov209
 *   func_021BC824 0x021BC824 thumb ov209
 *   func_021BD398 0x021BD398 thumb ov209
 *   func_021BD7F8 0x021BD7F8 thumb ov209
 *   func_021BC88C 0x021BC88C thumb ov209
 *   func_021BC9A8 0x021BC9A8 thumb ov209
 *   func_021BD628 0x021BD628 thumb ov209
 *   func_021BD704 0x021BD704 thumb ov209
 *   func_021BC7B8 0x021BC7B8 thumb ov209
 *   func_021BC7D0 0x021BC7D0 thumb ov209
 *   func_021BC8B4 0x021BC8B4 thumb ov209
 *   func_021BC298 0x021BC298 thumb ov209
 *   func_021BC2E4 0x021BC2E4 thumb ov209
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern const char ov067_id[];
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern int func_02034AC4(int);
extern void func_0204363C(u32);
extern void func_0203D34C(u32, u32);
extern void func_021BC370(void);
extern void func_021BC388(void);
extern void func_021BC574(void);
extern void func_021BC7B8(void);
extern void func_021BC6C4(char *);
extern void func_021BC824(char *);
extern void func_021BD398(char *);
extern void func_021BD7F8(char *);
extern void func_021BC88C(char *);
extern void func_021BC9A8(char *);
extern void func_021BD628(char *);
extern void func_021BD704(char *);
extern void func_021BC8B4(char *);
extern void func_021BC298(char *);
extern void func_021BC2E4(char *);
extern void func_021BC7D0(void);
int func_021BCC94(char *p)
{
    func_02034AC4((int)ov067_id);
    func_02043534(0);
    func_020435F4(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_0204363C(0);
    func_021BC6C4(p);
    func_021BC370();
    func_021BC388();
    func_021BC574();
    func_021BC824(p);
    func_021BD398(p);
    func_021BD7F8(p);
    func_021BC88C(p);
    func_021BC9A8(p);
    if (*(u16 *)(*(char **)p + 8) == 0) func_021BD628(p);
    else func_021BD704(p);
    func_0203D34C(1, 0x6B);
    func_021BC7B8();
    func_021BC7D0();
    func_021BC8B4(p);
    func_021BC298(p);
    func_021BC2E4(p);
    return 3;
}
