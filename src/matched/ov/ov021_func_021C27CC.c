/*
 * function: FLD3D_CI_RestoreLayerPriorities
 * address:  0x021C27CC
 * packet:   pkt_ov021_021C27CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Restores the four saved layer priorities (EXACT*: unlabelled follower).
 */

typedef unsigned char u8;

extern void func_0204047C(int idx, unsigned short val);

void FLD3D_CI_RestoreLayerPriorities(u8 *p)
{
    int i;

    for (i = 0; i < 4; i++)
        func_0204047C((u8)i, p[0x6C + i]);
}
