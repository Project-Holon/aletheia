/*
 * function: sakeCreateRecord
 * address:  0x021DD358
 * packet:   pkt_021DD358
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
 * Register the 0x021DE024 callback with sakeiRunRequest: forwards the four
 * incoming register arguments and appends (0, callback).
 */

extern void sakeiRunRequest(int, int, int, int, int, int);

void sakeCreateRecord(int a, int b, int c, int d)
{
    sakeiRunRequest(a, b, c, d, 0, 0x021DE024);
}

