/*
 * function: func_021F3998
 * address:  0x021F3998
 * packet:   pkt_ov052_021F3998
 * region:   ov052
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     void return (the callers' prototype) closes the earlier lane's
 *           base/offset register swap; the int-returning spelling was the DIFF.
 *
 * symbols:
 *   d_021F39DC     0x021F39DC  data  ov052  a4
 */

/* One zone table entry of the Battle Subway gimmick (field_gimmick_bsubway.c). */
typedef struct BsubwayZoneEntry {
    int zoneId;
    int slotId;
} BsubwayZoneEntry;

#define BSUBWAY_ZONE_ENTRY_COUNT 10

extern BsubwayZoneEntry d_021F39DC[];

/*
 * Looks the zone up in the zone table. Returns the gimmick work slot of the
 * zone and the table index (the index of its handlers); both 0 for an
 * unknown zone.
 */
void func_021F3998(int zoneId, int *slotId, int *handlerIndex)
{
    int i;
    for (i = 0; i < BSUBWAY_ZONE_ENTRY_COUNT; i++) {
        if (zoneId == d_021F39DC[i].zoneId) {
            *slotId = d_021F39DC[i].slotId;
            *handlerIndex = i;
            return;
        }
    }
    *slotId = 0;
    *handlerIndex = 0;
}
