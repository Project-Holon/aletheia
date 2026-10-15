/*
 * function: CTVT_TALK_GetMic
 * address:  0x021B9F98
 * packet:   pkt_ov172_021B9F98
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the word at +0x10 of the second argument.
 *
 * Addresses are Black-image addresses.
 */

int CTVT_TALK_GetMic(int unused, int *p)
{
    return p[4];
}
