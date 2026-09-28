/*
 * function: func_02012F14
 * address:  0x02012F14
 * packet:   pkt_02012F14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02009EC8  0x02009EC8  thumb
 *
 * Save-block getter through the handle's first word: tail call to
 * func_02009EC8 (block 0x1f).  Seeded from ov119 0x021E0226, 0x021E06D0,
 * 0x021E080C (tree_ov170_3).
 *
 * Addresses are Black-image addresses.
 */

extern void *func_02009EC8(void *sys);

void *func_02012F14(void **h)
{
    return func_02009EC8(*h);
}
