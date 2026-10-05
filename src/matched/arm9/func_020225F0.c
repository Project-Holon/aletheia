/*
 * function: func_020225F0
 * address:  0x020225F0
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The do-nothing default handler the two-entry callback table in
 * func_02022458 is initialised with: a single `bx lr` plus two bytes of
 * section padding.  It has no branch reference anywhere in the image, only
 * the ABS32 pool word at 0x02022474 that takes its address, so an EXACT
 * entry here is what lets func_02022458 resolve that pool word on the
 * `matched` class.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_020225F0.c \
 *       --addr 0x020225F0 --thumb
 */
void func_020225F0(void)
{
}
