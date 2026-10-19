/*
 * file:     field_area_zone.c
 * unit:     yes
 * function: FIELD_GetAreaZoneId, FIELD_GetPlayerAreaZoneId
 * address:  0x021CD400
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fld_trade_p01.c and fld_trade_p02.c (lane CL125b): no __FILE__ anchor, original unknown: zone-and-position lookup over gZoneAreaTable called by field_event_check.c, ov010 scrcmd_musical.c and ov016.
 *
 * symbols:
 *   gZoneAreaTable  0x021DB450  data  ov021  a2
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 */
struct FieldMap;
struct FieldPlayer;
struct Mmdl;

#include "../types.h"

#define ZONE_AREA_COUNT 4
#define ZONE_AREA_NONE 0x1ab

/* A 3x3-grid area of one zone that reports another zone id. */
typedef struct ZoneAreaEntry {
    u16 zoneId;
    u16 gridX;
    u16 gridZ;
    u16 areaZoneId;
} ZoneAreaEntry;

extern u16 FIELDMAP_GetZoneId(struct FieldMap *fieldMap);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);
extern struct Mmdl *FIELD_PLAYER_GetMmdl(struct FieldPlayer *player);
extern int FLDMMDL_GetGridNowX(struct Mmdl *mmdl);
extern int FLDMMDL_GetGridNowZ(struct Mmdl *mmdl);

u32 FIELD_GetAreaZoneId(u32 zoneId, int gridX, int gridZ);
int FIELD_GetPlayerAreaZoneId(struct FieldMap *fieldMap, u16 *zoneIdOut);

extern const ZoneAreaEntry gZoneAreaTable[];

/* Returns the area zone id of the entry covering (gridX, gridZ) in zoneId, or ZONE_AREA_NONE. */
u32 FIELD_GetAreaZoneId(u32 zoneId, int gridX, int gridZ)
{
    u32 index;
    const ZoneAreaEntry *entry = gZoneAreaTable;

    for (index = 0; index < ZONE_AREA_COUNT; index++, entry++) {
        if (entry->zoneId == zoneId && entry->gridX <= (u32)gridX && gridX < entry->gridX + 3 && entry->gridZ <= (u32)gridZ && gridZ < entry->gridZ + 3)
            return entry->areaZoneId;
    }
    return ZONE_AREA_NONE;
}

/*
 * Stores the area zone id at the player's position and returns 1; when no
 * area covers it, stores the current zone id and returns 0.
 */
int FIELD_GetPlayerAreaZoneId(struct FieldMap *fieldMap, u16 *zoneIdOut)
{
    u16 zoneId;
    struct Mmdl *player;
    u16 gridX;
    u16 gridZ;

    zoneId = FIELDMAP_GetZoneId(fieldMap);
    player = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
    gridX = FLDMMDL_GetGridNowX(player);
    gridZ = FLDMMDL_GetGridNowZ(player);
    *zoneIdOut = FIELD_GetAreaZoneId(zoneId, gridX, gridZ);
    if (*zoneIdOut != ZONE_AREA_NONE)
        return 1;
    *zoneIdOut = zoneId;
    return 0;
}
