/*
 * function: INTRUDE_COMM_ClearSessionEntries
 * address: 0x021757A8
 * packet: pkt_ov011_021757A8
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021757C2 precede existing 021757C4 code.
 */
typedef unsigned char u8;
void INTRUDE_COMM_ClearSessionEntries(u8 *p)
{
    int i;
    for (i = 0; i < 3; i++) p[i * 0x28 + 0x10] = 0;
}
