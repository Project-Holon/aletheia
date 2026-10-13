/*
 * function: MAP_ATTR_IsSlopeXA
 * address: 0x021AB4A4
 * packet: pkt_ov021_021AB4A4
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/field_effect_p01.c and filed here.
 */

int MAP_ATTR_IsSlopeXA(int id);

int MAP_ATTR_IsSlopeXA(int id)
{
    if (id == 0x51 || id == 0x55 || id == 0x57)
        return 1;
    return 0;
}
