/*
 * function: gsiLargeIntInverseMod
 * address:  0x0217E7C4
 * packet:   pkt_ov009_0217E7C4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiLargeIntInverseMod (gslargeint.o)
 *
 * symbols:

 */

struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
};

int gsiLargeIntInverseMod(struct gsLargeInt_s *mod, unsigned int *dest)
{
    unsigned long long x = 2;
    unsigned long long y = 1;
    unsigned int i;

    for (i = 2; i <= 32; i++) {
        unsigned long long mask = (x << 1) - 1;
        unsigned long long p = (unsigned long long)mod->mData[0] * y;
        if (x < (p & mask))
            y += x;
        x <<= 1;
    }
    *dest = (unsigned int)(x - y);
    return 1;
}
