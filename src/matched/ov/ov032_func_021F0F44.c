/*
 * function: BEACON_VIEW_GetEntry
 * address: 0x021F0F44
 * packet: pkt_ov032_021F0F44
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 */

typedef unsigned char u8;
u8 *BEACON_VIEW_GetEntry(u8 *p, int a)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (a == p[i * 0x34 + 0x1b9])
            return p + 0x1b8 + i * 0x34;
    }
    return 0;
}
