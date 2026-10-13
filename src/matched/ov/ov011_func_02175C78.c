/*
 * function: INTRUDE_COMM_FindFreeResultSlot
 * address: 0x02175C78
 * packet: pkt_ov011_02175C78
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
int INTRUDE_COMM_FindFreeResultSlot(u8 *p, void *b, int c)
{
    if (p[0xe0] == 4) return 0;
    return 3;
}
