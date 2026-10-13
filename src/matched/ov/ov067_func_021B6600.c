/*
 * function: TOUCHBAR_GetButton
 * address:  0x021B6600
 * packet:   pkt_ov067_021B6600
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to TOUCHBAR_FindButton.
 *
 * symbols:
 *   TOUCHBAR_FindButton  0x021B65C8  thumb  ov067
 */

void *TOUCHBAR_GetButton(unsigned char *p, unsigned int v)
{
    void *TOUCHBAR_FindButton(unsigned char *p, unsigned int v);
    return TOUCHBAR_FindButton(p, v);
}
