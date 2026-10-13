/*
 * function: gsiLargeIntMult
 * address:  0x0217D750
 * packet:   pkt_ov009_0217D750
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiLargeIntMult (gslargeint.o)
 *
 * symbols:
 *   gsiLargeIntTimerEnter                  0x0217D3AC  arm  ov009
 *   gsiLargeIntTimerExit                  0x0217D3F8  arm  ov009
 *   memcpy                         0x02092344  arm
 */

struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
};

extern void gsiLargeIntTimerEnter(int id);
extern void gsiLargeIntTimerExit(int id);
extern void *memcpy(void *d, const void *s, unsigned int n);

static int gsiLargeIntMult(unsigned int *data1, unsigned int length1,
                         unsigned int *data2, unsigned int length2,
                         unsigned int *dest, unsigned int *lenout,
                         unsigned int maxlen)
{
    unsigned int i = 0;
    unsigned int k = 0;
    struct gsLargeInt_s temp = {0};
    unsigned long long carry;
    unsigned int digit;

    *lenout = 0;
    gsiLargeIntTimerEnter(0);

    for (i = 0; i < length2; i++) {
        if (data2[i] == 0)
            continue;
        for (k = 0; k < length1; k++) {
            carry = (unsigned long long)data1[k] * data2[i];
            digit = i + k;
            if (digit >= maxlen) {
                gsiLargeIntTimerExit(0);
                return 0;
            }
            while (carry != 0) {
                carry += temp.mData[digit];
                temp.mData[digit] = (unsigned int)carry;
                carry >>= 32;
                digit++;
                if (digit > maxlen || (digit == maxlen && carry != 0)) {
                    gsiLargeIntTimerExit(0);
                    return 0;
                }
            }
            if ((int)digit > (int)temp.mLength)
                temp.mLength = digit;
        }
    }

    while (temp.mLength != 0 && temp.mData[temp.mLength - 1] == 0)
        temp.mLength--;

    *lenout = temp.mLength;
    memcpy(dest, temp.mData, *lenout * 4);
    gsiLargeIntTimerExit(0);
    return 1;
}
