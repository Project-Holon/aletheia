/*
 * function: BTL_SERVER_FLOW_QueryMainFlag
 * address:  0x021C82B8
 * packet:   pkt_021C82B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_ReturnZero  0x021B911C  thumb  ov093
 */

void BTL_MAIN_ReturnZero(int);

void BTL_SERVER_FLOW_QueryMainFlag(int *p)
{
    BTL_MAIN_ReturnZero(p[1]);
}
