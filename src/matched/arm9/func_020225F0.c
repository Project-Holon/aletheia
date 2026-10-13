/*
 * function: WIPE_DummyHBlank
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
 * WIPE_InitHBlankSlots is initialised with: a single `bx lr` plus two bytes of
 * section padding.  It has no branch reference anywhere in the image, only
 * the ABS32 pool word at 0x02022474 that takes its address, so an EXACT
 * entry here is what lets WIPE_InitHBlankSlots resolve that pool word on the
 * `matched` class.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/WIPE_DummyHBlank.c \
 *       --addr 0x020225F0 --thumb
 */
void WIPE_DummyHBlank(void)
{
}
