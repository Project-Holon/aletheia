/*
 * function: C_GEAR_HideCommIndicator
 * address: 0x021F2D10
 * packet: pkt_ov029_021F2D10
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
void C_GEAR_HideCommIndicator(u8 *p)
{
    if (p[0x45d] != 0) {
        p[0x45d] = 0;
        p[0x45e] = 1;
        p[0x45f] = 0;
    }
}
