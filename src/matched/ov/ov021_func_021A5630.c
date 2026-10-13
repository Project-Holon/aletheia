/*
 * function: FIELD_PLAYER_GRID_FindHopDir
 * address:  0x021A5630
 * packet:   pkt_ov021_021A5630
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetDirDisp  0x021A3920  thumb  ov021
 *   FIELD_PLAYER_GRID_GetAttrAtDir  0x021A5788  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   FIELD_PLAYER_GRID_IsHopTileKind  0x021A55DC  thumb  ov021
 *   MAP_ATTR_IsBlocked  0x021AB11C  thumb  ov021
 *   gFieldPlayerGridNextHopDirs  0x021D8A24  data  a2
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09571.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 FIELD_PLAYER_CORE_GetDirDisp(u8 *p);
extern int FIELD_PLAYER_GRID_GetAttrAtDir(u32, u32, u32 *);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern int FIELD_PLAYER_GRID_IsHopTileKind(int a);
extern int MAP_ATTR_IsBlocked(u32);
extern const u16 gFieldPlayerGridNextHopDirs[4];

u32 FIELD_PLAYER_GRID_FindHopDir(u32 a)
{
    u32 v;
    u16 t[4];
    u16 i;
    u32 x;
    u16 *p = t;
    t[0] = gFieldPlayerGridNextHopDirs[0];
    t[1] = gFieldPlayerGridNextHopDirs[1];
    t[2] = gFieldPlayerGridNextHopDirs[2];
    t[3] = gFieldPlayerGridNextHopDirs[3];
    x = FIELD_PLAYER_CORE_GetDirDisp((u8 *)(*(u32 *)&((struct Obj09571 *)a)->fC));
    i = 0;
    do {
        if (FIELD_PLAYER_GRID_GetAttrAtDir(a, x, &v) == 1) {
            if (FIELD_PLAYER_GRID_IsHopTileKind(MAP_ATTR_GetTerrainId(v)) == 0) {
                if (MAP_ATTR_IsBlocked(v) == 0) {
                    return x;
                }
            }
        }
        i = i + 1;
        x = p[x];
    } while (i < 4);
    return 9;
}
