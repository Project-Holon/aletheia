/*
 * function: FIELD_GIMMICK_ROTATING_ROOM_IsPosInside
 * address:  0x021F40D8
 * packet:   pkt_021F40D8
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */

int FIELD_GIMMICK_ROTATING_ROOM_IsPosInside(int *p)
{
    if (p[1] > 0x40000)
        return 0;
    if (p[0] >= 0x100000 && p[2] >= 0x1e0000)
        return 1;
    return 0;
}
