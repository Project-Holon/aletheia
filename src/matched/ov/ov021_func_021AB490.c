/*
 * function: MAP_ATTR_IsSlopeXB
 * address: 0x021AB490
 * packet: pkt_ov021_021AB490
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/field_effect_p01.c and filed here.
 */

int MAP_ATTR_IsSlopeXB(int id);

int MAP_ATTR_IsSlopeXB(int id)
{
    if (id == 0x52 || id == 0x56 || id == 0x58)
        return 1;
    return 0;
}
