/*
 * function: MUSICAL_MCSS_GetElemField
 * address: 0x021F4EE0
 * packet: pkt_ov112_021F4EE0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: six-byte body, two zero alignment bytes before separately filed 021F4EE8.
 */
typedef unsigned short u16;
void MUSICAL_MCSS_GetElemField(int unused, u16 *p, u16 *out)
{
    *out = p[1];
}
