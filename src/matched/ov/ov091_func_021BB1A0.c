/*
 * function: PLIST_PLATE_ClearSlideTrail
 * address:  0x021BB1A0
 * packet:   pkt_ov091_021BB1A0
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02041300  0x02041300  arm
 *   gPlistPlateTileX     0x021BEC74  data  ov091  a1
 *   gPlistPlateTileY     0x021BEC75  data  ov091  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02041300(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6);
extern u8 gPlistPlateTileX[];
extern u8 gPlistPlateTileY[];

void PLIST_PLATE_ClearSlideTrail(int unused, u8 *s, int d)
{
    int i = s[4];
    int x = gPlistPlateTileX[i * 2];
    u8 y = gPlistPlateTileY[i * 2];
    int z;

    if (i % 2 == 0)
        d = -d;
    z = x + 0x10 + d;
    func_02041300(2, 0, z, y, 0x10, 6, 5);
    func_02041300(1, 0, z, y, 0x10, 6, 5);
}
