/*
 * function: COLOSSEUM_IsAnyFinished
 * address: 0x0217FEF4
 * packet: pkt_ov019_0217FEF4
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
int COLOSSEUM_IsAnyFinished(u8 *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (p[i + 0x162] == 1) return 1;
    }
    return 0;
}
