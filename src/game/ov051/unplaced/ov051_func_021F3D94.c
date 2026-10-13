/*
 * function: FIELD_GIMMICK_D06_GetGimmickId
 * address:  0x021F3D94
 * packet:   pkt_ov051_021F3D94
 * region:   ov051
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Maps the ids 0xC3..0xC5 to 0x19..0x1B (0x19 otherwise). Called from ov051 0x021F375C, 0x021F388C and 0x021F3D1E.
 */

#include "../field_gimmick_d06_ids.h"

/* The gimmick id of the zone (the id of its save area); the first one for an unknown zone. */
int FIELD_GIMMICK_D06_GetGimmickId(int zoneId)
{
    switch (zoneId) {
    case GIMMICK_D06_ZONE_R0101:
        return GIMMICK_D06_GIMMICK_ID_R0101;
    case GIMMICK_D06_ZONE_R0102:
        return GIMMICK_D06_GIMMICK_ID_R0102;
    case GIMMICK_D06_ZONE_R0103:
        return GIMMICK_D06_GIMMICK_ID_R0103;
    }
    return GIMMICK_D06_GIMMICK_ID_R0101;
}
