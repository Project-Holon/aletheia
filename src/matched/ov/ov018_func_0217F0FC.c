/*
 * function: INTRUDE_SUBDISP_IsTownBlinking
 * address: 0x0217F0FC
 * packet: pkt_ov018_0217F0FC
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x0217F116.
 */
typedef unsigned char u8;
int INTRUDE_SUBDISP_IsTownBlinking(u8 *p)
{
    if (p[0x114] == 1 && p[0x115] < 10) return 1;
    return 0;
}
