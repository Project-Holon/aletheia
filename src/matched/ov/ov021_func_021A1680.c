/*
 * function: FIELD_3DBG_FreeBillboardTexture
 * address:  0x021A1680
 * packet:   pkt_ov021_021A1680
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_3DBG_IsTextureLoaded  0x021A1780  thumb  ov021
 *   FIELD_3DBG_FreeTexture  0x021A1750  thumb  ov021
 */

typedef unsigned char u8;

typedef unsigned int   u32;
u32 FIELD_3DBG_IsTextureLoaded(u8 *p);
int FIELD_3DBG_FreeTexture(u32 a);

void FIELD_3DBG_FreeBillboardTexture(u8 *p)
{
    if (FIELD_3DBG_IsTextureLoaded(p + 0x20) != 0)
        FIELD_3DBG_FreeTexture((u32)(p + 0x20));
}
