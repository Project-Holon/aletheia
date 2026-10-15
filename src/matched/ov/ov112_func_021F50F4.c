/*
 * function: MUSICAL_MCSS_GetIndex
 * address: 0x021F50F4
 * packet: pkt_ov112_021F50F4
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * leaf: Sole unresolved ov112 mapper for concrete-correct ov133 func_021B8444; root reserved ownership.
 */
int MUSICAL_MCSS_GetIndex(unsigned index)
{
    switch (index) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3:
    case 4: return 3;
    case 5: return 4;
    case 6: return 5;
    case 7: return 6;
    case 8: return 7;
    case 9: return 8;
    default: return 9;
    }
}
