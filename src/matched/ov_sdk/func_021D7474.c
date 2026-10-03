/*
 * function: func_021D7474
 * address:  0x021D7474
 * packet:   pkt_021D7474
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D7474   0x021D7474  arm
 *
 * Tail-call func_0208C6A4 with the constant 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D7474.c \
 *       --func func_021D7474 --addr 0x021D7474 --region ov016 --cc dsi/1.1p1 --arm
 */

extern unsigned int func_0208C6A4(unsigned int pattern);

void func_021D7474(void)
{
    func_0208C6A4(1);
}
