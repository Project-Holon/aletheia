/*
 * function: PLIST_PLATE_SetPalette
 * address:  0x021BB050
 * packet:   pkt_ov091_021BB050
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three explicit calls to func_020413B0 (last argument 4 / 7 / k), which the
 * compiler cross-jumps at the table load; a shared `v` local set per arm
 * compiles to one call and is 20 bytes short.
 *
 * symbols:
 *   PLIST_PLATE_GetHpBarColor  0x021BB554  thumb  ov091
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   gPlistPlateTileX     0x021BEC74  data  ov091  a1
 *   gPlistPlateTileY     0x021BEC75  data  ov091  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int PLIST_PLATE_GetHpBarColor(u32 p);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 id);
extern const u8 gPlistPlateTileX[];
extern const u8 gPlistPlateTileY[];

void PLIST_PLATE_SetPalette(int unused, u8 *s, int k)
{
    if (k == 3 && PLIST_PLATE_GetHpBarColor((u32)s) == 3)
        func_020413B0(2, gPlistPlateTileX[s[4] * 2] + 0x10, gPlistPlateTileY[s[4] * 2], 0x10, 6, 4);
    else if (k == 6 && PLIST_PLATE_GetHpBarColor((u32)s) == 3)
        func_020413B0(2, gPlistPlateTileX[s[4] * 2] + 0x10, gPlistPlateTileY[s[4] * 2], 0x10, 6, 7);
    else
        func_020413B0(2, gPlistPlateTileX[s[4] * 2] + 0x10, gPlistPlateTileY[s[4] * 2], 0x10, 6, k);
    func_02041B6C(2);
}
