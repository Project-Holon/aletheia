/*
 * function: func_021DCB48
 * address: 0x021DCB48
 * packet: pkt_ov170_021DCB48
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 */
extern void BG_SYS_SetMainPlaneVisible(unsigned, unsigned);
extern void BG_SYS_SetSubPlaneVisible(unsigned, unsigned);
extern void func_020403F4(unsigned);
extern void func_0203F9B4(void);
void func_021DCB48(void *p)
{
    BG_SYS_SetMainPlaneVisible(15, 0);
    BG_SYS_SetSubPlaneVisible(7, 0);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_0203F9B4();
}
