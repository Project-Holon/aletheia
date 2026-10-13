/*
 * function: INTRUDE_COMM_ConsumeAreaNoticeSeen
 * address:  0x0217689C
 * packet:   pkt_ov011_0217689C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZONEDATA_IsZoneGroup118To120  0x02013D9C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

#include "../intrude_comm_types.h"

extern u32 ZONEDATA_IsZoneGroup118To120(u32 id);

/*
 * Consumes the areaNoticeSeen flag (set by the partner's zone report);
 * returns 1 when it was set and the zone is in the special zone group
 * (ZONEDATA_IsZoneGroup118To120).
 */
int INTRUDE_COMM_ConsumeAreaNoticeSeen(IntrudeCommSys *linkState, int zoneId)
{
    int wasPending = linkState->areaNoticeSeen;
    linkState->areaNoticeSeen = 0;
    if (wasPending == 1) {
        if (ZONEDATA_IsZoneGroup118To120(zoneId) == 1)
            return 1;
    }
    return 0;
}
