/*
 * function: gsiLargeIntStripLeadingZeroes
 * address:  0x0217D4D8
 * packet:   pkt_ov009_0217D4D8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiLargeIntStripLeadingZeroes (gslargeint.o)
 */

struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
};

static int gsiLargeIntStripLeadingZeroes(struct gsLargeInt_s * lint)
{
    while (lint->mLength != 0 && lint->mData[lint->mLength - 1] == 0)
        lint->mLength--;

    return 1;
}
