/*
 * function: PLIST_PLATE_GetCenterPos
 * address: 0x021BB3D4
 * packet: pkt_ov091_021BB3D4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gPlistPlateTileX 0x021BEC74 data ov091 a1
 *   gPlistPlateTileY 0x021BEC75 data ov091 a1
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u8 gPlistPlateTileX[];
extern u8 gPlistPlateTileY[];
void PLIST_PLATE_GetCenterPos(void *a,u8 *s,u16 *out) { out[0]=(gPlistPlateTileX[s[4]*2]+8)<<3; out[1]=(gPlistPlateTileY[s[4]*2]+3)<<3; }
