/*
 * function: FIELD_PLAYER_GRID_CheckForcedMoveTile
 * address:  0x021A5458
 * packet:   pkt_ov021_021A5458
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_GetNowAttr  0x0216D7DC  thumb  ov010
 *   FIELD_PLAYER_GRID_HasFlag  0x021A5318  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_IsForcedSlide  0x021AB348  thumb  ov021
 */
#include "../include/Obj19803.h"

typedef unsigned int u32;

void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
typedef unsigned short u16;
u32 FLDMMDL_GetNowAttr(void *p);
int FIELD_PLAYER_GRID_HasFlag(u32 *p, u32 m);
u16 MAP_ATTR_GetTerrainId(u32 attr);
int MAP_ATTR_IsForcedSlide(u32 id);

int FIELD_PLAYER_GRID_CheckForcedMoveTile(u32 *p)
{
    int x = FLDMMDL_GetNowAttr(FIELD_PLAYER_CORE_GetMmdl(*(unsigned char * *)&((struct Obj19803 *)p)->fC));

    if (FIELD_PLAYER_GRID_HasFlag(p, 2) == 0 && MAP_ATTR_IsForcedSlide(MAP_ATTR_GetTerrainId(x)) == 1)
        return 1;
    return 0;
}
