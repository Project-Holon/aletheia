/*
 * function: HAND_FIELD_GetHandlersMudSport
 * address: 0x0689814C
 * packet: pkt_ov095_0689814C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: 12-byte leaf, followed by labelled HAND_FIELD_MudSportWeakenElectric.
 * symbols:
 *   gHandFieldMudSportHandlers 0x0689D610 data a4
 */
extern unsigned char gHandFieldMudSportHandlers[];
void *HAND_FIELD_GetHandlersMudSport(int *p)
{
    *p = 1;
    return gHandFieldMudSportHandlers;
}
