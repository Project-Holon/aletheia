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
 *
 * symbols:
 *   BG_SYS_Get  0x020416D4  arm  arm9
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern u8 BG_SYS_Get(u32 layer);

void FLD3D_CI_SaveLayerPriorities(u8 *p)
{
    int i;

    for (i = 0; i < 4; i++)
        p[0x6C + i] = BG_SYS_Get((u8)i);
}
