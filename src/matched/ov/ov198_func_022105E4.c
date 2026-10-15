/*
 * function: B_PLIST_MAIN_ExitBg
 * address:  0x022105E4
 * packet:   pkt_022105E4
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_020403F4 0x020403F4 arm
 */

typedef unsigned int   u32;
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void func_020403F4(u32 i);

void B_PLIST_MAIN_ExitBg(void)
{
    BG_SYS_SetSubPlaneVisible(0x1f, 0);
    func_020403F4(4);
    func_020403F4(5);
    func_020403F4(6);
    func_020403F4(7);
}
