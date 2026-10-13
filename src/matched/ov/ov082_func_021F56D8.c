/*
 * function: FLD_FACEUP_SaveVisiblePlanes
 * address:  0x021F56D8
 * packet:   pkt_021F56D8
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_GetMainVisiblePlanes  0x02043658  arm
 */

typedef unsigned int   u32;
u32 BG_SYS_GetMainVisiblePlanes(void);

void FLD_FACEUP_SaveVisiblePlanes(int *p)
{
    p[1] = BG_SYS_GetMainVisiblePlanes();
}
