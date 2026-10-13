/*
 * function: HAND_FIELD_GetHandlersWaterSport
 * address: 0x06898104
 * packet: pkt_ov095_06898104
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: 12-byte leaf, followed by labelled HAND_FIELD_WaterSportWeakenFire.
 * symbols:
 *   gHandFieldWaterSportHandlers 0x0689D620 data a4
 */
extern unsigned char gHandFieldWaterSportHandlers[];
void *HAND_FIELD_GetHandlersWaterSport(int *p)
{
    *p = 1;
    return gHandFieldWaterSportHandlers;
}
