/*
 * file:     unit_021CD400.c
 * unit:     yes
 * function: func_021CD400, func_021CD440
 * address:  0x021CD400
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fld_trade_p01.c and fld_trade_p02.c (lane CL125b): no __FILE__ anchor, original unknown: zone-and-position lookup over d_021DB450 called by field_event_check.c, ov010 scrcmd_musical.c and ov016.
 *
 * symbols:
 *   d_021DB450  0x021DB450  data  ov021  a2
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 */
struct Obj00020;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* A 3x3-grid area of one zone that reports another zone id. */
typedef struct ZoneAreaEntry {
    u16 zoneId;
    u16 gridX;
    u16 gridZ;
    u16 areaZoneId;
} ZoneAreaEntry;

extern u16 func_02188C9C(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);

u32 func_021CD400(u32 zoneId, int gridX, int gridZ);
int func_021CD440(void *fieldmap, u16 *zoneIdOut);

extern const ZoneAreaEntry d_021DB450[];

/* Returns the area zone id of the entry covering (gridX, gridZ) in zoneId, or 0x1AB. */
u32 func_021CD400(u32 zoneId, int gridX, int gridZ)
{
    u32 i;
    const ZoneAreaEntry *entry = d_021DB450;

    for (i = 0; i < 4; i++, entry++) {
        if (entry->zoneId == zoneId && entry->gridX <= (u32)gridX && gridX < entry->gridX + 3 && entry->gridZ <= (u32)gridZ && gridZ < entry->gridZ + 3)
            return entry->areaZoneId;
    }
    return 0x1ab;
}

/*
 * Stores the area zone id at the player's position and returns 1; when no
 * area covers it, stores the current zone id and returns 0.
 */
int func_021CD440(void *fieldmap, u16 *zoneIdOut)
{
    u16 zoneId;
    void *player;
    u16 gridX;
    u16 gridZ;

    zoneId = func_02188C9C(fieldmap);
    player = func_021A3074(func_02188CB4(fieldmap));
    gridX = func_0216D83C(player);
    gridZ = func_0216D86C(player);
    *zoneIdOut = func_021CD400(zoneId, gridX, gridZ);
    if (*zoneIdOut != 0x1ab)
        return 1;
    *zoneIdOut = zoneId;
    return 0;
}
