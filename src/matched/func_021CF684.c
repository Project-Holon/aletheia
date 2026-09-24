/*
 * function: func_021CF684
 * address:  0x021CF684
 * packet:   pkt_021CF440
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CF684   0x021CF684  arm
 *
 * Tail-call func_02082D44 with the global object +0x440, v and 0x20.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CF684.c \
 *       --func func_021CF684 --addr 0x021CF684 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_02082D44(char *, unsigned int, unsigned int);

void func_021CF684(unsigned int v)
{
    func_02082D44(*(char **)0x021DE644 + 0x440, v, 0x20);
}
