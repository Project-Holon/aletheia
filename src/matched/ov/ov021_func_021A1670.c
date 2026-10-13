/*
 * function: FIELD_3DBG_ReleaseBillboardTextureVram
 * address:  0x021A1670
 * packet:   pkt_ov021_021A1670
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_3DBG_ReleaseTextureVram  0x021A1768  thumb  ov021
 */

typedef unsigned char u8;

void FIELD_3DBG_ReleaseTextureVram(u8 *p);

void FIELD_3DBG_ReleaseBillboardTextureVram(u8 *p)
{
    if (p != 0)
        FIELD_3DBG_ReleaseTextureVram(p + 0x20);
}
