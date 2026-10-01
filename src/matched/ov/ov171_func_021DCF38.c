/*
 * function: func_021DCF38
 * address: 0x021DCF38
 * packet: pkt_ov171_021DCF38
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DC8D4 0x021DC8D4 thumb ov171
 *   func_021DE014 0x021DE014 thumb ov171
 *   func_021DD8BC 0x021DD8BC thumb ov171
 *   func_021DCC88 0x021DCC88 thumb ov171
 *   func_021DCB8C 0x021DCB8C thumb ov171
 *   func_021DCA40 0x021DCA40 thumb ov171
 *   func_021DCE28 0x021DCE28 thumb ov171
 *   func_0207D534 0x0207D534 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data
 */
extern int func_021DC8D4(int *);
extern void func_021DE014(int *);
extern void func_021DD8BC(int *);
extern void func_021DCC88(int *);
extern void func_021DCB8C(int *);
extern void func_021DCA40(void);
extern void func_021DCE28(int *);
extern void func_0207D534(void *, int);
extern void func_02043534(int);
extern void func_020435F4(int);
extern void func_02034A5C(int);
extern char ov067_id[];
int func_021DCF38(int *p)
{
    func_021DC8D4(p);
    func_021DE014(p);
    func_021DD8BC(p);
    func_021DCC88(p);
    func_021DCB8C(p);
    func_021DCA40();
    func_021DCE28(p);
    func_0207D534((void *)0x0400006c, -16);
    func_0207D534((void *)0x0400106c, -16);
    *(unsigned short *)0x04000050 = 0;
    *(unsigned short *)0x04001050 = 0;
    func_02043534(0);
    func_020435F4(0);
    func_02034A5C((int)ov067_id);
    return 11;
}
