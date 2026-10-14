/*
 * function: ZUKAN_DETAIL_TOUCHBAR_GetRightPalette
 * address: 0x021BE378
 * packet: pkt_ov208_021BE378
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BE3C2..021BE3C4 is two-byte zero alignment padding.
 */
unsigned ZUKAN_DETAIL_TOUCHBAR_GetRightPalette(unsigned n)
{
    switch(n) {
    case 0: break;
    case 6: case 15: return 0;
    case 7: case 16: return 1;
    case 8: case 17: return 2;
    case 9: case 18: return 3;
    default: break;
    }
    return 4;
}
