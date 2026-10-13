/*
 * function: FLD3D_CI_SaveLayerPriorities
 * address:  0x021C27A4
 * packet:   pkt_ov021_021C27A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Saves the four layer priorities into p[0x6C..0x6F].
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern u8 func_020416D4(u32 layer);

void FLD3D_CI_SaveLayerPriorities(u8 *p)
{
    int i;

    for (i = 0; i < 4; i++)
        p[0x6C + i] = func_020416D4((u8)i);
}
