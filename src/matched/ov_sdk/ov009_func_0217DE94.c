/*
 * function: gsLargeIntSquareMod
 * address:  0x0217DE94
 * packet:   pkt_ov009_0217DE94
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The six-instruction prologue residue (`squareLen = 0` stored at [sp,#0x14])
 * is fixed by declaring the input `lint` parameter const: the front end then
 * keeps the whole prologue group in the image's order instead of sinking the
 * squareLen store to the frame setup.
 *
 * sdk:      gsLargeIntSquareMod (gslargeint.o)
 *
 * symbols:
 *   gsiLargeIntTimerEnter                  0x0217D3AC  arm  ov009
 *   gsiLargeIntTimerExit                  0x0217D3F8  arm  ov009
 *   gsiLargeIntAdd                  0x0217D508  arm  ov009
 *   gsiLargeIntDiv                  0x0217D904  arm  ov009
 */

struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
};

extern void gsiLargeIntTimerEnter(int id);
extern void gsiLargeIntTimerExit(int id);
extern int gsiLargeIntAdd(unsigned int *data1, unsigned int length1,
                         unsigned int *data2, unsigned int length2,
                         unsigned int *dest, unsigned int *lenout,
                         unsigned int maxlen);
extern int gsiLargeIntDiv(unsigned int *src, unsigned int len,
                         struct gsLargeInt_s *div, struct gsLargeInt_s *dest,
                         struct gsLargeInt_s *remainder);

int gsLargeIntSquareMod(const struct gsLargeInt_s *lint, struct gsLargeInt_s *mod,
                  struct gsLargeInt_s *dest)
{
    int i;
    int k;
    int len;
    unsigned long long carry = 0;
    int oldShiftBit = 0;
    int result;
    unsigned int squareLen = 0;

    len = (int)lint->mLength;
    gsiLargeIntTimerEnter(7);
    {
    unsigned int squareSums[128] = {0};
    unsigned int otherSums[128] = {0};

    for (i = 1; i < len; i++) {
        for (k = 0; k < i; k++) {
            carry += (unsigned long long)lint->mData[i] * lint->mData[k] + otherSums[i + k];
            otherSums[i + k] = (unsigned int)carry;
            carry >>= 32;
        }
        if (carry != 0) {
            otherSums[i + k] = (unsigned int)carry;
            carry >>= 32;
        }
    }

    for (i = 0; i < len * 2; i++) {
        k = (otherSums[i] & 0x80000000) == 0x80000000 ? 1 : 0;
        otherSums[i] = (otherSums[i] << 1) + oldShiftBit;
        oldShiftBit = k;
    }

    for (i = 0; i < len; i++) {
        carry = (unsigned long long)lint->mData[i] * lint->mData[i];
        squareSums[i * 2] = (unsigned int)carry;
        squareSums[i * 2 + 1] = (unsigned int)(carry >> 32);
    }

    squareLen = (unsigned int)(len * 2);
    gsiLargeIntAdd(otherSums, squareLen, squareSums, squareLen, squareSums, &squareLen, 128);
    result = gsiLargeIntDiv(squareSums, squareLen, mod, 0, dest);
    gsiLargeIntTimerExit(7);
    return result;
    }
}
