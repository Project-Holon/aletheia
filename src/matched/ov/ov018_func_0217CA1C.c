/*
 * function: INTRUDE_SUBDISP_CreatePalaceWarpEvent
 * address: 0x0217CA1C
 * packet: pkt_ov018_0217CA1C
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_FIELD_GetZoneAnchor 0x0217BED4 thumb ov018
 *   EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset 0x02185588 thumb ov020
 */
typedef struct { int x, y, z; } V12;
extern int INTRUDE_FIELD_GetZoneAnchor(int, V12 *);
typedef unsigned short u16;
struct V3;
extern void *EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset(void *owner, u16 id, const struct V3 *pos);
void *INTRUDE_SUBDISP_CreatePalaceWarpEvent(void *p)
{
    V12 v;
    INTRUDE_FIELD_GetZoneAnchor(0x117, &v);
    return EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset(p, 0x117, (const struct V3 *)(&v));
}
