/*
 * function: VIEWER_ACTOR_WrapAngle
 * address:  0x021C7C78
 * packet:   pkt_ov111_021C7C78
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */

int VIEWER_ACTOR_WrapAngle(int a, int b)
{
    if (a >= b) {
        return a % b;
    }
    if (a < 0) {
        a += 0x100000;
    }
    return a;
}
