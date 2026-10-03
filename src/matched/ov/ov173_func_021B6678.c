/*
 * function: func_021B6678
 * address: 0x021B6678
 * packet: pkt_ov173_021B6678
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B66A8 reads and 021B66AE writes hardware halfword.
 * symbols:
 *   func_02043598 0x02043598 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 */
typedef unsigned int   u32;
extern void func_02043598(u32 mask, u32 enable);
extern void func_020403F4(unsigned int);
extern void func_0203F9B4(void);
void func_021B6678(void)
{
    func_02043598(29, 0);
    func_020403F4(5);
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(4);
    func_020403F4(3);
    func_020403F4(2);
    *(volatile unsigned short *)0x04000304 |= 0x8000;
    func_0203F9B4();
}
