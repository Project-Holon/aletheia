/*
 * function: FIELD_RAIL_KEY_TurnRight
 * address:  0x021B9404
 * packet:   pkt_021B9404
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

int FIELD_RAIL_KEY_TurnRight(int dir)
{
    switch (dir) {
    case 1: return 2;
    case 3: return 4;
    case 4: return 1;
    case 2: return 3;
    }
    return 0;
}
