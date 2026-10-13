/*
 * function: gsiLargeIntSubDivide
 * address:  0x0217DCA4
 * packet:   pkt_ov009_0217DCA4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiLargeIntSubDivide (gslargeint.o)
 *
 * Note: DWARF lists five parameters, but the image reads quotient from the
 * sixth argument slot ([sp,#0x24c]); the caller gsiLargeIntDiv passes an
 * extra int before it. The unused int parameter reproduces that slot.
 * quotientCopy is zeroed after the division, so it is declared in an inner
 * block (C99) after the division.
 *
 * symbols:
 *   gsiLargeIntTimerEnter                  0x0217D3AC  arm  ov009
 *   gsiLargeIntTimerExit                  0x0217D3F8  arm  ov009
 *   _ll_udiv                       0x0209C00C  arm
 *   gsiLargeIntMult                  0x0217D750  arm  ov009
 *   gsiLargeIntCompare                  0x0217D448  arm  ov009
 *   gsiLargeIntSub                  0x0217D640  arm  ov009
 */

struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
};

extern void gsiLargeIntTimerEnter(int id);
extern void gsiLargeIntTimerExit(int id);
extern int gsiLargeIntMult(unsigned int *data1, unsigned int length1,
                         unsigned int *data2, unsigned int length2,
                         unsigned int *dest, unsigned int *lenout,
                         unsigned int maxlen);
extern int gsiLargeIntCompare(const unsigned int *a, unsigned int n,
                         const unsigned int *b, unsigned int m);
extern int gsiLargeIntSub(unsigned int *src1, unsigned int length1,
                         unsigned int *src2, unsigned int length2,
                         unsigned int *dest, unsigned int *lenout);

static int gsiLargeIntSubDivide(unsigned int *src, unsigned int length,
                         unsigned int *divisor, unsigned int dlen,
                         int divisorHighBit, unsigned int *quotient)
{
    struct gsLargeInt_s temp;
    unsigned long long aboveBits;

    gsiLargeIntTimerEnter(6);

    if (length <= dlen)
        aboveBits = src[length - 1];
    else
        aboveBits = ((unsigned long long)src[length - 1] << 32)
                  | (src[length - 2] & divisor[dlen - 1]);
    aboveBits /= divisor[dlen - 1];

    {
    struct gsLargeInt_s quotientCopy = {0};

    quotientCopy.mData[0] = (unsigned int)aboveBits;
    quotientCopy.mData[1] = (unsigned int)(aboveBits >> 32);
    if (quotientCopy.mData[1] != 0) {
        quotientCopy.mData[0] = 0xFFFFFFFF;
        quotientCopy.mData[1] = 0;
    }
    quotientCopy.mLength = 1;

    if (!gsiLargeIntMult(divisor, dlen, quotientCopy.mData, quotientCopy.mLength,
                       temp.mData, &temp.mLength, 64)) {
        gsiLargeIntTimerExit(6);
        return 0;
    }
    while (gsiLargeIntCompare(temp.mData, temp.mLength, src, length) == 1) {
        quotientCopy.mData[0] >>= 1;
        if (!gsiLargeIntMult(divisor, dlen, quotientCopy.mData, quotientCopy.mLength,
                           temp.mData, &temp.mLength, 64)) {
            gsiLargeIntTimerExit(6);
            return 0;
        }
    }
    gsiLargeIntSub(temp.mData, temp.mLength, src, length, src, &length);
    *quotient = quotientCopy.mData[0];
    gsiLargeIntTimerExit(6);
    return 1;
    }
}
