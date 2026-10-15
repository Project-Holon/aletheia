/*
 * function: CDEMO_MAIN_HidePlane
 * address:  0x021B6220
 * packet:   pkt_ov179_021B6220
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 */
typedef unsigned int   u32;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

void CDEMO_MAIN_HidePlane(void)
{
    BG_SYS_SetMainPlaneVisible(12, 0);
}
