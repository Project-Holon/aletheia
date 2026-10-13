/*
 * function: func_0217D904
 * address:  0x0217D904
 * packet:   pkt_ov009_0217D904
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiLargeIntDiv (gslargeint.o)
 *
 * lane 6 (wave 10): EXACT. The 5-byte residue closed by hoisting the divisor's top word into a
 *           named local declared before dlen (`unsigned int w; unsigned int dlen = divisorLen - 1;
 *           w = divisorData[dlen];`): the word temporary is then created first and takes the
 *           lower register, dlen the next. The residue note below is historical.
 *
 * lane U43 (2026-09-30): ported from the vendor's own source,
 *           scratch/U2/gs/src/GameSpy/common/gsLargeInt.c gsiLargeIntDiv.
 *           Size is now the image's 928 B (was 936 = SIZE) and 5 concrete
 *           bytes differ.  The port's tells, all measured:
 *             - `gsLargeInt_t quotient;` is declared BEFORE
 *               `l_word scopy[128]`; under 1.1p1 a later-declared aggregate
 *               lands lower, so this puts scopy at sp+0x10 and quotient at
 *               sp+0x210 exactly as the image has them (the parked draft
 *               had the two slots swapped and a 936-byte frame).
 *             - `l_word scopyLen = len;` as its own local (the strip loop
 *               decrements scopyLen, not the `len` parameter).
 *             - memset(scopy, 0, sizeof(scopy)) before the oversize check,
 *               memset(&quotient, 0, sizeof(quotient)) right after the
 *               memcpy - both arrive as the inlined stm zero loops only with
 *               memcpy/memset declared through a header literally named
 *               string.h (a local extern prototype emits real calls and
 *               costs 44 bytes).
 *             - `divisorLen - 1` must be held in a live local
 *               (`unsigned int dlen = divisorLen - 1;`) across the
 *               high-bit loop: written inline it is rematerialised after the
 *               loop and the row is 932 B.
 *           Residue (5 bytes, +01A0/+01A4/+01B4/+01E8): the allocator's
 *           choice of which of the two live temporaries takes the lower
 *           register - image `sub r2, sb, #1` / `ldr r1, [r8, r2, lsl #2]`
 *           (dlen in r2, loaded word in r1), ours `sub r1, sb, #1` /
 *           `ldr r2, [r8, r1, lsl #2]`.  `int dlen`, a function-scope dlen,
 *           a swapped mask expression, `(int)dlen * 32` and moving the add
 *           after readIndex/readLength were all measured and all keep the
 *           same exchange.
 *
 * symbols:
 *   func_0217D3AC                  0x0217D3AC  arm ov009
 *   memcpy                         0x02092344  arm
 *   gsiLargeIntTimerExit                  0x0217D3F8  arm ov009
 *   gsiLargeIntCompare                  0x0217D448  arm ov009
 *   memset                         0x020923B0  arm
 *   gsiLargeIntSubDivide                  0x0217DCA4  arm ov009
 */

typedef struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
} gsLargeInt_t;

#include "../../matched/arm9_sdk/libc/string.h"
extern void func_0217D3AC(int id);
extern void gsiLargeIntTimerExit(int id);
extern int gsiLargeIntCompare(const unsigned int *data1, unsigned int len1, const unsigned int *data2, unsigned int len2);
extern int gsiLargeIntSubDivide(unsigned int *src, unsigned int length, const unsigned int *divisor, unsigned int dlen, int divisorHighBit, unsigned int *quotient);

int func_0217D904(unsigned int *src, unsigned int len, gsLargeInt_t *div, gsLargeInt_t *dest, gsLargeInt_t *remainder)
{
    int result = 0;
    int divisorHighBit = 31;

    int readIndex = 0;
    int readLength = 0;

    gsLargeInt_t quotient;

    unsigned int scopy[128];
    unsigned int scopyLen = len;

    const unsigned int *divisorData = div->mData;
    unsigned int divisorLen = div->mLength;

    int endLoop = 0;

    func_0217D3AC(5);

    memset(scopy, 0, sizeof(scopy));

    if (scopyLen > 64 && dest != 0)
        return 0;

    while (scopyLen > 0 && src[scopyLen - 1] == 0)
        scopyLen--;
    while (divisorLen > 0 && divisorData[divisorLen - 1] == 0)
        divisorLen--;

    memcpy(scopy, src, scopyLen * sizeof(unsigned int));
    memset(&quotient, 0, sizeof(quotient));

    if (scopyLen == 0 || divisorLen == 0) {
        if (dest) {
            dest->mData[0] = 0;
            dest->mLength = 0;
        }
        if (remainder) {
            remainder->mData[0] = 0;
            remainder->mLength = 0;
        }
        gsiLargeIntTimerExit(5);
        if (divisorLen == 0)
            return 0;
        else
            return 1;
    }

    if (gsiLargeIntCompare(scopy, scopyLen, divisorData, divisorLen) == -1) {
        if (dest) {
            dest->mLength = 0;
            dest->mData[0] = 0;
        }
        remainder->mLength = scopyLen;
        memcpy(remainder->mData, scopy, scopyLen * sizeof(unsigned int));
        gsiLargeIntTimerExit(5);
        return 1;
    }

    {
        unsigned int w;
        unsigned int dlen = divisorLen - 1;
        w = divisorData[dlen];
        while ((w & (1 << divisorHighBit)) == 0 && divisorHighBit >= 0)
            divisorHighBit--;
        if (divisorHighBit == -1) {
            gsiLargeIntTimerExit(5);
            return 0;
        }
        divisorHighBit += dlen * 32;
    }

    readIndex = (int)(scopyLen - divisorLen);
    readLength = (int)divisorLen;

    do {
        result = gsiLargeIntCompare(&scopy[readIndex], (unsigned int)readLength, divisorData, divisorLen);
        if (result == -1) {
            if (readIndex > 0) {
                readIndex--;
                readLength++;
            } else {
                endLoop = 1;
            }
        } else if (result == 0) {
            memset(&scopy[readIndex], 0, readLength * sizeof(unsigned int));
            quotient.mData[readIndex] += 1;
            if (quotient.mLength < (unsigned int)(readIndex + readLength))
                quotient.mLength = (unsigned int)(readIndex + readLength);
            readIndex -= readLength;
            readLength = 1;
            if (readIndex < 0)
                endLoop = 1;
        } else {
            unsigned int quotientTemp = 0;
            if (gsiLargeIntSubDivide(&scopy[readIndex], (unsigned int)readLength, divisorData, divisorLen, (unsigned int)divisorHighBit, &quotientTemp) == 0) {
                gsiLargeIntTimerExit(5);
                return 0;
            }
            quotient.mData[readIndex] = (unsigned int)(quotient.mData[readIndex] + quotientTemp);
            if (quotient.mLength < (unsigned int)(readIndex + readLength))
                quotient.mLength = (unsigned int)(readIndex + readLength);
            while (scopy[readIndex + readLength - 1] == 0 && readLength > 1)
                readLength--;
            while (scopy[readIndex + readLength - 1] == 0 && readIndex > 1)
                readIndex--;
        }
    } while (endLoop == 0);

    if (readIndex >= 0) {
        memcpy(remainder->mData, &scopy[readIndex], readLength * sizeof(unsigned int));
        remainder->mLength = (unsigned int)readLength;
    } else {
        remainder->mData[0] = 0;
        remainder->mLength = 0;
    }

    if (dest) {
        memcpy(dest->mData, quotient.mData, quotient.mLength * sizeof(unsigned int));
        dest->mLength = quotient.mLength;
    }
    gsiLargeIntTimerExit(5);
    return 1;
}
