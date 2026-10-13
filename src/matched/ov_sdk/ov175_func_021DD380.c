/*
 * function: sakeUpdateRecord
 * address:  0x021DD380
 * packet:   pkt_021DD380
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sakeiRunRequest  0x021DD2D4  arm
 *
 * Register the 0x021DE0D4 callback with sakeiRunRequest: forwards the four
 * incoming register arguments and appends (1, callback).
 */

extern void sakeiRunRequest(int, int, int, int, int, int);

void sakeUpdateRecord(int a, int b, int c, int d)
{
    sakeiRunRequest(a, b, c, d, 1, 0x021DE0D4);
}

