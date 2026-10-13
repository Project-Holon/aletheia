/*
 * function: func_021C4AF8
 * address: 0x021C4AF8
 * packet: pkt_ov136_021C4AF8
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_020434DC 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
typedef unsigned int   u32;
extern void func_020434DC(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
void func_021C4AF8(void)
{
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_020434DC(1, 0);
    func_020434DC(2, 0);
    func_020434DC(4, 0);
    func_020434DC(8, 0);
    func_020434DC(16, 0);
    func_020434DC(1, 0);
    BG_SYS_SetSubPlaneVisible(1, 0);
    BG_SYS_SetSubPlaneVisible(2, 0);
    BG_SYS_SetSubPlaneVisible(4, 0);
    BG_SYS_SetSubPlaneVisible(8, 0);
    BG_SYS_SetSubPlaneVisible(16, 0);
}
