/*
 * function: QuartToTrip
 * address:  0x0217F7D0
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * QuartToTrip: pack up to four signed bytes into three (6-6-6-6 base64
 * bit groups folded into 6-6-2+6 layout).  `char` is signed under the pinned
 * flags, so the loads are ldrsb and the shifts arithmetic.
 */

void QuartToTrip(char *quart, char *trip, int inlen)
{
    if (inlen >= 2)
        trip[0] = (char)(quart[0] << 2 | quart[1] >> 4);
    if (inlen >= 3)
        trip[1] = (char)((quart[1] & 0x0F) << 4 | quart[2] >> 2);
    if (inlen >= 4)
        trip[2] = (char)((quart[2] & 0x3) << 6 | quart[3]);
}
