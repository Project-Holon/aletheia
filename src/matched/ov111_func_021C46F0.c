/*
 * function: func_021C46F0
 * address:  0x021C46F0
 * packet:   pkt_ov111_021C46F0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_02040618  0x02040618  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02040618(u32 bgId, u32 which, u32 value);
extern void func_020403F4(u32 bgId);
extern void func_0203F9B4(void);

void func_021C46F0(void)
{
    func_020434DC(0x1F, 0);
    func_02043598(0x1F, 0);
    func_02040618(5, 0, 0);
    func_02040618(5, 3, 0);
    func_02040618(3, 0, 0);
    func_02040618(3, 3, 0);
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(4);
    func_020403F4(5);
    func_020403F4(2);
    func_020403F4(3);
    func_0203F9B4();
}
