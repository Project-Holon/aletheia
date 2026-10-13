/*
 * function: FLD_FACEUP_RestoreVisiblePlanes
 * address:  0x021F56FC
 * packet:   pkt_021F56FC
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 */

typedef unsigned int   u32;
void BG_SYS_SetMainVisiblePlanes(u32 planes);

void FLD_FACEUP_RestoreVisiblePlanes(int *p)
{
    BG_SYS_SetMainVisiblePlanes(p[1]);
}
