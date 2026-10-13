/*
 * function: EVENT_FIELDMAP_CONTROL_GetFadeKind
 * address:  0x021BEA6C
 * packet:   pkt_ov021_021BEA6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

int EVENT_FIELDMAP_CONTROL_GetFadeKind(int x)
{
    switch (x) {
    case 0:
    default:
        return 3;
    case 1:
        return 12;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        return 2;
    }
}
