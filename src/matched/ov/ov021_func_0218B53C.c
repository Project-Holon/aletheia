/*
 * function: FIELD_EVENT_CHECK_SearchRailFrontMmdl
 * address:  0x0218B53C
 * packet:   pkt_ov021_0218B53C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_RAIL_GetFrontLocation  0x0219E634  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_RAIL_SearchMmdlByLocation  0x0219E570  thumb  ov021
 */
#include "../include/Obj19511.h"

void *FIELD_PLAYER_GetMmdl(unsigned char *p);
int FLDMMDL_RAIL_GetFrontLocation(void *a, int *buf);
void *FIELDMAP_GetMmdlSys(unsigned char *p);
typedef unsigned int   u32;
u32 FLDMMDL_RAIL_SearchMmdlByLocation(u32 o, u32 k, u32 flag);

int FIELD_EVENT_CHECK_SearchRailFrontMmdl(unsigned char *p, void *b)
{
    int buf[2];
    if (FLDMMDL_RAIL_GetFrontLocation(FIELD_PLAYER_GetMmdl(((struct Obj19511 *)p)->f18), buf) != 0)
        return FLDMMDL_RAIL_SearchMmdlByLocation((u32)FIELDMAP_GetMmdlSys(b), (u32)buf, 0);
    return 0;
}
