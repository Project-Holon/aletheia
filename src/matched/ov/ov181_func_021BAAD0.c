/*
 * function: STAFF_ROLL_CmdHidePlane
 * address:  0x021BAAD0
 * packet:   pkt_021BAAD0
 * region:   ov181
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 */

typedef unsigned int   u32;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

int STAFF_ROLL_CmdHidePlane(void)
{
    BG_SYS_SetMainPlaneVisible(1, 0);
    return 1;
}
