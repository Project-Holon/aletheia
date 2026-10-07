/*
 * file:     unit_0217D3AC_p03.c
 * unit:     yes
 * function: func_0217DCA4, func_0217DE94
 * address:  0x0217DCA4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217D3AC                  0x0217D3AC  arm  ov009
 *   func_0217D3F8                  0x0217D3F8  arm  ov009
 *   _ll_udiv                       0x0209C00C  arm
 *   func_0217D750                  0x0217D750  arm  ov009
 *   func_0217D448                  0x0217D448  arm  ov009
 *   func_0217D640                  0x0217D640  arm  ov009
 *   func_0217D508                  0x0217D508  arm  ov009
 *   func_0217D904                  0x0217D904  arm  ov009
 */
struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
};

extern void func_0217D3AC(int id);
extern void func_0217D3F8(int id);
extern int func_0217D750(unsigned int *data1, unsigned int length1,
                         unsigned int *data2, unsigned int length2,
                         unsigned int *dest, unsigned int *lenout,
                         unsigned int maxlen);
extern int func_0217D448(const unsigned int *a, unsigned int n,
                         const unsigned int *b, unsigned int m);
extern int func_0217D640(unsigned int *src1, unsigned int length1,
                         unsigned int *src2, unsigned int length2,
                         unsigned int *dest, unsigned int *lenout);
extern int func_0217D508(unsigned int *data1, unsigned int length1,
                         unsigned int *data2, unsigned int length2,
                         unsigned int *dest, unsigned int *lenout,
                         unsigned int maxlen);
extern int func_0217D904(unsigned int *src, unsigned int len,
                         struct gsLargeInt_s *div, struct gsLargeInt_s *dest,
                         struct gsLargeInt_s *remainder);
int func_0217DE94(const struct gsLargeInt_s *lint, struct gsLargeInt_s *mod, struct gsLargeInt_s *dest);


/*
 * sdk:      gsiLargeIntSubDivide (gslargeint.o)
 *
 * Note: DWARF lists five parameters, but the image reads quotient from the
 * sixth argument slot ([sp,#0x24c]); the caller gsiLargeIntDiv passes an
 * extra int before it. The unused int parameter reproduces that slot.
 * quotientCopy is zeroed after the division, so it is declared in an inner
 * block (C99) after the division.
 */
static int func_0217DCA4(unsigned int *src, unsigned int length,
                         unsigned int *divisor, unsigned int dlen,
                         int divisorHighBit, unsigned int *quotient)
{
    struct gsLargeInt_s temp;
    unsigned long long aboveBits;

    func_0217D3AC(6);

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

    if (!func_0217D750(divisor, dlen, quotientCopy.mData, quotientCopy.mLength,
                       temp.mData, &temp.mLength, 64)) {
        func_0217D3F8(6);
        return 0;
    }
    while (func_0217D448(temp.mData, temp.mLength, src, length) == 1) {
        quotientCopy.mData[0] >>= 1;
        if (!func_0217D750(divisor, dlen, quotientCopy.mData, quotientCopy.mLength,
                           temp.mData, &temp.mLength, 64)) {
            func_0217D3F8(6);
            return 0;
        }
    }
    func_0217D640(temp.mData, temp.mLength, src, length, src, &length);
    *quotient = quotientCopy.mData[0];
    func_0217D3F8(6);
    return 1;
    }
}


/*
 * The six-instruction prologue residue (`squareLen = 0` stored at [sp,#0x14])
 * is fixed by declaring the input `lint` parameter const: the front end then
 * keeps the whole prologue group in the image's order instead of sinking the
 * squareLen store to the frame setup.
 *
 * sdk:      gsLargeIntSquareMod (gslargeint.o)
 */
int func_0217DE94(const struct gsLargeInt_s *lint, struct gsLargeInt_s *mod,
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
    func_0217D3AC(7);
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
    func_0217D508(otherSums, squareLen, squareSums, squareLen, squareSums, &squareLen, 128);
    result = func_0217D904(squareSums, squareLen, mod, 0, dest);
    func_0217D3F8(7);
    return result;
    }
}
