/*
 * function: gpiRemoveProfile
 * address:  0x0218FF24
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call on the word at +0x5c8 of the block the object points at.
 *
 * symbols:
 *   TableRemove  0x021847BC  arm
 */

extern void TableRemove(int v);

void gpiRemoveProfile(const int *p, void *profile)
{
    TableRemove(*(const int *)(*p + 0x5c8));
}

