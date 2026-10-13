/*
 * function: FIELD_EVENT_CHECK_IsRailFrontFree
 * address:  0x0218B310
 * packet:   pkt_ov021_0218B310
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_RAIL_GetHitBitsDirNoAttr  0x0219E418  thumb  ov021
 */
#include "../include/Obj19510.h"

void *FIELD_PLAYER_GetMmdl(unsigned char *p);
typedef unsigned int   u32;
int FLDMMDL_RAIL_GetHitBitsDirNoAttr(u32 a, u32 b);

int FIELD_EVENT_CHECK_IsRailFrontFree(void *a, unsigned char *s)
{
    if ((FLDMMDL_RAIL_GetHitBitsDirNoAttr((u32)FIELD_PLAYER_GetMmdl(a), ((struct Obj19510 *)s)->f24) & 3) == 0)
        return 1;
    return 0;
}
