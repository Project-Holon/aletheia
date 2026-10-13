/*
 * function: sciSerializeInt8
 * address:  0x021E04FC
 * packet:   pkt_021E04FC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * variant w2
 */

char *sciSerializeInt8(char *dst, int value)
{
    *dst++ = value;
    return dst;
}

