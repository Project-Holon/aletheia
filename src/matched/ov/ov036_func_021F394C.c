/*
 * function: DAILY_LAYOUT_GetPoolCell
 * address: 0x021F394C
 * packet: pkt_ov036_021F394C
 * region: ov036
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
int DAILY_LAYOUT_GetPoolCell(u8 *p, int i)
{
    if (i > p[0x1f]) return -1;
    return p[i];
}
