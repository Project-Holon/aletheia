/*
 * function: func_021D0014
 * address:  0x021D0014
 * packet:   pkt_021D0014
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D0014   0x021D0014  arm
 *
 * Tail-call func_02072E7C with the global object +0xa0 and a zero.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D0014.c \
 *       --func func_021D0014 --addr 0x021D0014 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_02072E7C(char *, unsigned int);

void func_021D0014(void)
{
    func_02072E7C(*(char **)0x021DE648 + 0xa0, 0);
}
