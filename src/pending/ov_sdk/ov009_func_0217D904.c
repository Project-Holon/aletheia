/*
 * function: gsiLargeIntDiv
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
 * codegen: SIZE 928 vs 936, 676 bytes differ. The algorithm and every call
 * are reproduced, but the object's 4.0.0.1025 toolchain schedules the
 * aggregate zero-inits (`struct gsLargeInt_s quotient = {0}` and
 * `unsigned int scopy[128] = {0}`) and the register allocation differently
 * from dsi/1.1p1, which sinks both zero blocks to the declaration point and
 * uses a different callee-saved set (r5=src/sl=len/r8=0 vs the original
 * r4=src/r5=len/r8=divisorData). The same bets on `memset(scopy,0,...)` are
 * worse: 1.1p1 emits `bx ip`/`bl memset` while the object inlines the zeros.
 * Deferred: matching it needs the 4.0.0.1025 toolchain.
 *
 * symbols:
 *   gsiLargeIntTimerEnter            0x0217d3ac arm
 *   memcpy                           0x02092344 arm
 *   gsiLargeIntTimerExit             0x0217d3f8 arm
 *   gsiLargeIntCompare               0x0217d448 arm
 *   memset                           0x020923b0 arm
 *   gsiLargeIntSubDivide             0x0217dca4 arm
 */

struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
};

extern void memcpy(void * dst, const void * src, unsigned int n);
extern void memset(void * dst, int c, unsigned int n);
extern void gsiLargeIntTimerEnter(int id);
extern void gsiLargeIntTimerExit(int id);
extern int gsiLargeIntCompare(unsigned int * data1, unsigned int len1, unsigned int * data2, unsigned int len2);
extern int gsiLargeIntSubDivide(unsigned int * src, unsigned int length, unsigned int * divisor, unsigned int dlen, int divisorHighBit, unsigned int * quotient);

static int gsiLargeIntDiv(unsigned int * src, int len, struct gsLargeInt_s * div, struct gsLargeInt_s * dest, struct gsLargeInt_s * remainder)
{
    int result;
    int divisorHighBit;
    int readIndex;
    int readLength;
    struct gsLargeInt_s quotient = {0};
    unsigned int scopy[128] = {0};
    unsigned int scopyLen;
    unsigned int * divisorData;
    unsigned int divisorLen;
    int endLoop;
    unsigned int quotientTemp;

    divisorData = div->mData;
    divisorLen = div->mLength;
    divisorHighBit = 31;
    endLoop = 0;

    gsiLargeIntTimerEnter(5);

    if (len > 64 && dest != 0)
        return 0;

    while (len != 0 && src[len - 1] == 0)
        len--;
    while (divisorLen != 0 && divisorData[divisorLen - 1] == 0)
        divisorLen--;

    scopyLen = len * 4;
    memcpy(scopy, src, scopyLen);

    if (len == 0 || divisorLen == 0)
    {
        if (dest)
        {
            dest->mLength = 0;
            dest->mData[0] = 0;
        }
        if (remainder)
        {
            remainder->mLength = 0;
            remainder->mData[0] = 0;
        }
        gsiLargeIntTimerExit(5);
        return (divisorLen != 0);
    }

    result = gsiLargeIntCompare(scopy, len, divisorData, divisorLen);
    if (result == -1)
    {
        if (dest)
        {
            dest->mLength = 0;
            dest->mData[0] = 0;
        }
        remainder->mLength = len;
        memcpy(remainder->mData, scopy, scopyLen);
        gsiLargeIntTimerExit(5);
        return 1;
    }

    divisorHighBit = 31;
    while (divisorHighBit >= 0 && !(divisorData[divisorLen - 1] & (1 << divisorHighBit)))
        divisorHighBit--;
    if (divisorHighBit == -1)
    {
        gsiLargeIntTimerExit(5);
        return 0;
    }

    readLength = divisorLen;
    divisorHighBit += (divisorLen - 1) * 32;
    len -= divisorLen;

    while (!endLoop)
    {
        result = gsiLargeIntCompare(&scopy[len], readLength, divisorData, divisorLen);
        if (result == -1)
        {
            if (len > 0)
            {
                len--;
                readLength++;
            }
            else
                endLoop = 1;
        }
        else if (result == 0)
        {
            memset(&scopy[len], 0, readLength * 4);
            quotient.mData[len]++;
            if (quotient.mLength < (unsigned int)(len + readLength))
                quotient.mLength = len + readLength;
            len -= readLength;
            readLength = 1;
            if (len < 0)
                endLoop = 1;
        }
        else
        {
            quotientTemp = 0;
            result = gsiLargeIntSubDivide(&scopy[len], readLength, divisorData, divisorLen, divisorHighBit, &quotientTemp);
            if (result == 0)
            {
                gsiLargeIntTimerExit(5);
                return 0;
            }
            quotient.mData[len] += quotientTemp;
            if (quotient.mLength < (unsigned int)(len + readLength))
                quotient.mLength = len + readLength;
            while (readLength > 1 && scopy[len + readLength - 1] == 0)
                readLength--;
            while (len > 1 && scopy[len + readLength - 1] == 0)
                len--;
        }
    }

    if (len < 0)
    {
        remainder->mLength = 0;
        remainder->mData[0] = 0;
    }
    else
    {
        memcpy(remainder->mData, &scopy[len], readLength * 4);
        remainder->mLength = readLength;
    }

    if (dest)
    {
        memcpy(dest->mData, quotient.mData, quotient.mLength * 4);
        dest->mLength = quotient.mLength;
    }

    gsiLargeIntTimerExit(5);
    return 1;
}
