/*
 * function: INTRUDE_FIELD_IsListedZone
 * address: 0x0217C11C
 * packet: pkt_ov018_0217C11C
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: index declared before count preserves r3/r4 allocation.
 * symbols:
 *   INTRUDE_FIELD_gListedZoneCount 0x021700A4 data a4
 *   INTRUDE_FIELD_gListedZones 0x02170128 data a2
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern const u32 INTRUDE_FIELD_gListedZoneCount;
extern const u16 INTRUDE_FIELD_gListedZones[];
int INTRUDE_FIELD_IsListedZone(u32 value)
{
    u32 i;
    u32 count;
    count = INTRUDE_FIELD_gListedZoneCount;
    for (i = 0; i < count; ++i) {
        if (value == INTRUDE_FIELD_gListedZones[i])
            return 1;
    }
    return 0;
}
