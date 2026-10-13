/*
 * function: MAP_ATTR_IsSlopeYB
 * address: 0x021AB474
 * packet: pkt_ov021_021AB474
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/field_effect_p01.c and filed here.
 */

int MAP_ATTR_IsSlopeYB(int id);

int MAP_ATTR_IsSlopeYB(int id)
{
    if (id == 0x54 || (unsigned short)(id + 0xFFA9) <= 1)
        return 1;
    return 0;
}
