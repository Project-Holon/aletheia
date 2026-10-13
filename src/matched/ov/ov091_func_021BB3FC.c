/*
 * function: PLIST_PLATE_GetTouchRect
 * address:  0x021BB3FC
 * packet:   pkt_ov091_021BB3FC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   gPlistPlateTileX  0x021BEC74  data  ov091  a1
 *   gPlistPlateTileY  0x021BEC75  data  ov091  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 gPlistPlateTileX[];
extern u8 gPlistPlateTileY[];

void PLIST_PLATE_GetTouchRect(int unused, u8 *s, u8 *out)
{
    out[2] = gPlistPlateTileX[s[4] * 2] << 3;
    out[0] = gPlistPlateTileY[s[4] * 2] << 3;
    out[3] = (gPlistPlateTileX[s[4] * 2] + 16) << 3;
    out[1] = (gPlistPlateTileY[s[4] * 2] + 6) << 3;
}
