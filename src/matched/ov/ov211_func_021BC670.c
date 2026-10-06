/*
 * function: func_021BC670
 * address: 0x021BC670
 * packet: pkt_ov211_021BC670
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfword stores to 04000050 at 021BC684 and
 * 04001050 at 021BC688; original clears display blend controls.
 * symbols:
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0204363C 0x0204363C arm
 *   func_021BC2B0 0x021BC2B0 thumb ov211
 *   func_021BC318 0x021BC318 thumb ov211
 *   func_021BC474 0x021BC474 thumb ov211
 *   func_021BC5B0 0x021BC5B0 thumb ov211
 *   func_0203D34C 0x0203D34C arm
 *   func_02043598 0x02043598 arm
 *   func_021BC2F4 0x021BC2F4 thumb ov211
 *   func_021C93A8 0x021C93A8 thumb ov212
 */
extern void func_02043534(unsigned),func_020435F4(unsigned),func_0204363C(unsigned);
struct Object;
extern void func_021BC2B0(void);
extern void func_021BC318(void);
extern void func_021BC474(struct Object *p);
extern void func_021BC5B0(char *);
extern void func_0203D34C(unsigned,unsigned),func_02043598(unsigned,unsigned);
extern void func_021BC2F4(unsigned char *p);
extern void func_021C93A8(unsigned);
int func_021BC670(char *p)
{
    func_02043534(0);func_020435F4(0);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    func_0204363C(0);func_021BC2B0();func_021BC318();
    func_021BC474((struct Object *)p);func_021BC5B0(p);
    func_0203D34C(1,126);func_02043598(16,1);
    func_021BC2F4((unsigned char *)p);func_021C93A8(126);
    return 2;
}
