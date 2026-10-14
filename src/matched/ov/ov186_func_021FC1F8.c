/*
 * function: BR_RES_ReleaseUiPalette
 * address:  0x021FC1F8
 * packet:   pkt_021FC1F8
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 */

typedef unsigned int   u32;
extern void CLACT_ReleasePalette(u32 i);

void BR_RES_ReleaseUiPalette(int *p, int i)
{
    CLACT_ReleasePalette(p[i]);
    p[i] = -1;
}
