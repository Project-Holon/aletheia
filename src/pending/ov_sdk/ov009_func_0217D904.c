/*
 * function: func_0217D904
 * address:  0x0217D904
 * packet:   pkt_ov009_0217D904
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gsiLargeIntDiv (gslargeint.o)
 *
 * DIFF (lane w2_o2, rewritten from the object; the earlier lane's draft used
 * `int len`, the DWARF says unsigned int, which is where the bls compare comes
 * from). What still differs: (1) stack order: the object has scopy at sp+0x10
 * and quotient at sp+0x210 with scopy zeroed right after
 * gsiLargeIntTimerEnter and quotient zeroed only after the memcpy of src; under
 * 1.1p1 a later-declared (or inner-block) aggregate always lands lower, so the
 * two init points and the two slots cannot both be had (flat declarations give
 * the slots but hoist both zero loops; nested blocks give the init points and
 * swap the slots; a compound-literal assignment spills a 0x400 temp; mixed
 * declarations are a c99 syntax error here). (2) register colouring follows:
 * parameters land in r8/sb/r5/r6 instead of r5/r4/r8/sb. (3) divisorLen - 1
 * from the high-bit loop is kept live in the object and recomputed here.
 *
 * symbols:
 *   func_0217D3AC                  0x0217D3AC  arm ov009
 *   memcpy                         0x02092344  arm
 *   func_0217D3F8                  0x0217D3F8  arm ov009
 *   func_0217D448                  0x0217D448  arm ov009
 *   memset                         0x020923B0  arm
 *   func_0217DCA4                  0x0217DCA4  arm ov009
 */

typedef struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
} gsLargeInt_t;

extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void *memset(void *dst, int c, unsigned int n);
extern void func_0217D3AC(int id);
extern void func_0217D3F8(int id);
extern int func_0217D448(unsigned int *data1, unsigned int len1, unsigned int *data2, unsigned int len2);
extern int func_0217DCA4(unsigned int *src, unsigned int length, unsigned int *divisor, unsigned int dlen, int divisorHighBit, unsigned int *quotient);

int func_0217D904(unsigned int *src, unsigned int len, gsLargeInt_t *div, gsLargeInt_t *dest, gsLargeInt_t *remainder)
{
    int result;
    int divisorHighBit = 31;
    int readIndex;
    int readLength;
    unsigned int *divisorData = div->mData;
    unsigned int divisorLen = div->mLength;
    unsigned int scopyLen;
    int endLoop = 0;
    unsigned int quotientTemp;

    func_0217D3AC(5);
    {
        unsigned int scopy[128] = {0};

        if (len > 64 && dest != 0)
            return 0;

        while (len > 0 && src[len - 1] == 0)
            len--;
        while (divisorLen > 0 && divisorData[divisorLen - 1] == 0)
            divisorLen--;

        scopyLen = len * 4;
        memcpy(scopy, src, scopyLen);
        {
            gsLargeInt_t quotient = {0};

            if (len == 0 || divisorLen == 0) {
                if (dest) {
                    dest->mData[0] = 0;
                    dest->mLength = 0;
                }
                if (remainder) {
                    remainder->mData[0] = 0;
                    remainder->mLength = 0;
                }
                func_0217D3F8(5);
                return (divisorLen != 0) ? 1 : 0;
            }

            result = func_0217D448(scopy, len, divisorData, divisorLen);
            if (result == -1) {
                if (dest) {
                    dest->mLength = 0;
                    dest->mData[0] = 0;
                }
                remainder->mLength = len;
                memcpy(remainder->mData, scopy, scopyLen);
                func_0217D3F8(5);
                return 1;
            }

            while (!(divisorData[divisorLen - 1] & (1 << divisorHighBit)) && divisorHighBit >= 0)
                divisorHighBit--;
            if (divisorHighBit == -1) {
                func_0217D3F8(5);
                return 0;
            }

            readLength = divisorLen;
            divisorHighBit += (divisorLen - 1) * 32;
            readIndex = len - divisorLen;

            while (!endLoop) {
                result = func_0217D448(&scopy[readIndex], readLength, divisorData, divisorLen);
                if (result == -1) {
                    if (readIndex > 0) {
                        readIndex--;
                        readLength++;
                    } else {
                        endLoop = 1;
                    }
                } else if (result == 0) {
                    memset(&scopy[readIndex], 0, readLength * 4);
                    quotient.mData[readIndex]++;
                    if (quotient.mLength < readIndex + readLength)
                        quotient.mLength = readIndex + readLength;
                    readIndex -= readLength;
                    readLength = 1;
                    if (readIndex < 0)
                        endLoop = 1;
                } else {
                    quotientTemp = 0;
                    result = func_0217DCA4(&scopy[readIndex], readLength, divisorData, divisorLen, divisorHighBit, &quotientTemp);
                    if (result == 0) {
                        func_0217D3F8(5);
                        return 0;
                    }
                    quotient.mData[readIndex] += quotientTemp;
                    if (quotient.mLength < readIndex + readLength)
                        quotient.mLength = readIndex + readLength;
                    while (scopy[readIndex + readLength - 1] == 0 && readLength > 1)
                        readLength--;
                    while (scopy[readIndex + readLength - 1] == 0 && readIndex > 1)
                        readIndex--;
                }
            }

            if (readIndex < 0) {
                remainder->mData[0] = 0;
                remainder->mLength = 0;
            } else {
                memcpy(remainder->mData, &scopy[readIndex], readLength * 4);
                remainder->mLength = readLength;
            }

            if (dest) {
                memcpy(dest->mData, quotient.mData, quotient.mLength * 4);
                dest->mLength = quotient.mLength;
            }
        }
    }
    func_0217D3F8(5);
    return 1;
}
