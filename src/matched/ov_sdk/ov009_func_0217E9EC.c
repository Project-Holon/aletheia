/*
 * function: gsLargeIntGetByteLength
 * address:  0x0217E9EC
 * packet:   pkt_ov009_0217E9EC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      gsLargeIntGetByteLength (gslargeint.o)
 *
 * EXACT*: byte-identical (108 B); the listing extent runs to 144 B because
 * the unlabelled follower at 0x0217EA58 has no func_ label.
 */

struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
};

unsigned int gsLargeIntGetByteLength(struct gsLargeInt_s * lint)
{
    unsigned int mask;
    unsigned int i;
    int byteSize;
    int intSize;

    intSize = lint->mLength;
    while (intSize > 0 && lint->mData[intSize - 1] == 0)
        intSize--;

    if (intSize == 0)
        return 0;

    byteSize = intSize * 4;
    mask = 0xff;
    for (i = 1; i < 4; i++)
    {
        if (lint->mData[intSize - 1] <= mask)
            return byteSize - (4 - i);
        mask = (mask << 8) | 0xff;
    }

    return byteSize;
}
