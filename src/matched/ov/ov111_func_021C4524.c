/*
 * unit:     yes
 * function: VIEWER_MAIN_GetBgParamA, VIEWER_MAIN_GetBgParamB
 * address:  0x021C4524
 * packet:   pkt_021C4524
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two ternaries selecting between two constants.
 */

int VIEWER_MAIN_GetBgParamA(int x)
{
    return x == 0x14 ? 0x20 : 0x1C;
}

int VIEWER_MAIN_GetBgParamB(int x)
{
    return x == 0x14 ? 0x2A : 0x29;
}
