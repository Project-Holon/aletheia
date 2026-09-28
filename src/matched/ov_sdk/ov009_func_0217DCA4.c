/*
 * function: func_0217DCA4
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
 *   func_0217D3AC                  0x0217D3AC  arm  ov009
 *   func_0217D3F8                  0x0217D3F8  arm  ov009
 *   _ll_udiv                       0x0209C00C  arm
 *   func_0217D750                  0x0217D750  arm  ov009
 *   func_0217D448                  0x0217D448  arm  ov009
 *   func_0217D640                  0x0217D640  arm  ov009
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
