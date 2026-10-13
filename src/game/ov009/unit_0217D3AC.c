/*
 * file:     unit_0217D3AC.c
 * unit:     yes
 * function: func_0217D3AC, gsiLargeIntTimerExit, gsiLargeIntCompare, gsiLargeIntStripLeadingZeroes, gsiLargeIntAdd, gsiLargeIntSub, gsiLargeIntMult, func_0217D8E0, func_0217D904, gsiLargeIntSubDivide, func_0217DE94, gsLargeIntPowerMod, func_0217E504, gsiLargeIntInverseMod, gsLargeIntSetFromHexString, func_0217E934, gsLargeIntAddToMD5, gsLargeIntGetByteLength, gsiMemoryMalloc, gsiMemoryFree, gsiMemoryRealloc
 * address:  0x0217D3AC
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
 *   current_time_hires               0x0217f28c arm
 *   gTimers                          0x021ad064 data
 *   func_0217D3AC  0x0217D3AC  arm  ov009
 *   func_02092344  0x02092344  arm
 *   gsiLargeIntTimerExit  0x0217D3F8  arm  ov009
 *   memcpy                         0x02092344  arm
 *   memset                         0x020923B0  arm
 *   _ll_udiv                       0x0209C00C  arm
 *   gsiLargeIntCompare               0x0217D448 arm
 *   gsLargeIntDiv                    0x0217D8E0 arm
 *   gsiLargeIntInverseMod            0x0217E7C4 arm
 *   gsLargeIntSquareMod              0x0217DE94 arm
 *   gsiLargeIntMultM                 0x0217E504 arm
 *   func_0209477C                  0x0209477C  arm
 *   func_0208CF34                  0x0208CF34  arm
 *   g_021A3728                     0x021A3728  data
 *   g_021A3720                     0x021A3720  data
 *   gsLargeIntReverseBytes           0x0217e934 arm
 *   GSMD5Update                      0x0218497c arm
 *   func_020913D0  0x020913D0  arm
 *   func_020913E8  0x020913E8  arm
 *   func_020913FC  0x020913FC  arm
 */
#include "../../matched/include/G_GSLintTimer.h"
#include "../../matched/arm9_sdk/libc/string.h"
#include "../../matched/arm9_sdk/libc/string.h"

struct GSMD5_CTX;
typedef unsigned int l_word;

typedef struct gsLargeInt_s {
    l_word mLength;
    l_word mData[64];
} gsLargeInt_t;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef int gsi_bool;

typedef unsigned int gsi_u32;

typedef int gsi_i32;

typedef unsigned char  u8;

extern unsigned int current_time_hires(void);
extern void func_0217D3AC(int id);
extern void gsiLargeIntTimerExit(int id);
extern void *func_02092344(void *dst, const void *src, u32 n);
extern gsi_i32 gsiLargeIntCompare(const l_word *data1, l_word len1,
                                  const l_word *data2, l_word len2);
extern int gsLargeIntDiv(gsLargeInt_t *src1, gsLargeInt_t *divisor,
                         gsLargeInt_t *dest, gsLargeInt_t *remainder);
extern int gsiLargeIntInverseMod(gsLargeInt_t *mod, l_word *dest);
extern int gsLargeIntSquareMod(gsLargeInt_t *lint, gsLargeInt_t *mod,
                               gsLargeInt_t *dest);
extern int gsiLargeIntMultM(gsLargeInt_t *x, gsLargeInt_t *y,
                            gsLargeInt_t *m, gsi_u32 modPrime,
                            gsLargeInt_t *dest);
extern int func_0209477C(const u8 *s);
extern int func_0208CF34(const char *src, const char *fmt, ...);
extern int gsLargeIntReverseBytes(gsLargeInt_t * lint);
extern void GSMD5Update(struct GSMD5_CTX * context, unsigned char * input, unsigned int inputLen);
int gsiLargeIntCompare(const u32 *a, u32 n, const u32 *b, u32 m);
int gsiLargeIntAdd(u32 *data1, u32 length1, u32 *data2, u32 length2, u32 *dest, u32 *lenout, u32 maxlen);
int gsiLargeIntSub(u32 *src1, u32 length1, u32 *src2, u32 length2, u32 *dest, u32 *lenout);
gsi_bool func_0217D8E0(const gsLargeInt_t *src1, const gsLargeInt_t *divisor, gsLargeInt_t *dest, gsLargeInt_t *remainder);
int func_0217D904(unsigned int *src, unsigned int len, gsLargeInt_t *div, gsLargeInt_t *dest, gsLargeInt_t *remainder);
int func_0217DE94(const gsLargeInt_t *lint, gsLargeInt_t *mod, gsLargeInt_t *dest);
int gsLargeIntPowerMod(gsLargeInt_t *b, gsLargeInt_t *p, gsLargeInt_t *m, gsLargeInt_t *dest);
int func_0217E504(gsLargeInt_t *x, gsLargeInt_t *y, const gsLargeInt_t *m, unsigned int modPrime, gsLargeInt_t *dest);
int gsiLargeIntInverseMod(gsLargeInt_t *mod, unsigned int *dest);
int gsLargeIntSetFromHexString(gsLargeInt_t *lint, char *hexstream);
int func_0217E934(char *p);
void gsLargeIntAddToMD5(gsLargeInt_t * _lint, struct GSMD5_CTX * md5);
unsigned int gsLargeIntGetByteLength(gsLargeInt_t * lint);
extern struct GSLintTimer gTimers[9];
extern char g_021A3728[];
extern char g_021A3720[];
extern void *func_020913D0(unsigned long heap);
extern void func_020913E8(void *p);
extern void *func_020913FC(unsigned long a0, unsigned long a1);
void *gsiMemoryMalloc(unsigned long size);
void gsiMemoryFree(void *p);
void *gsiMemoryRealloc(unsigned long block, unsigned long size);







static void gsiLargeIntTimerEnter(int id)
{
    if (gTimers[id].started == 0)
    {
        gTimers[id].entries++;
        gTimers[id].start = current_time_hires();
        gTimers[id].started = 1;
    }
}







static void gsiLargeIntTimerExit(int id)
{
    if (gTimers[id].started == 1)
    {
        gTimers[id].total += current_time_hires() - gTimers[id].start;
        gTimers[id].started = 0;
    }
}







/*
 * Big-number vector compare.  Both operands are little-endian limbs with the
 * length given separately; trailing zero limbs are trimmed off each operand
 * first, then the trimmed lengths decide, then the limbs are walked from the
 * top.  -1 / 1 / 0 as usual.
 */
int gsiLargeIntCompare(const u32 *a, u32 n, const u32 *b, u32 m)
{
    while (a[n - 1] == 0 && n != 0)
        n--;
    while (b[m - 1] == 0 && m != 0)
        m--;
    if (n < m)
        return -1;
    if (n > m)
        return 1;
    while (n != 0) {
        if (a[n - 1] < b[n - 1])
            return -1;
        if (a[n - 1] > b[n - 1])
            return 1;
        n--;
    }
    return 0;
}







static int gsiLargeIntStripLeadingZeroes(gsLargeInt_t * lint)
{
    while (lint->mLength != 0 && lint->mData[lint->mLength - 1] == 0)
        lint->mLength--;

    return 1;
}






/*
 * sdk:      gsiLargeIntAdd (libdwcgscommon.TWL.HYB.a(gslargeint.o))
 */
int gsiLargeIntAdd(u32 *data1, u32 length1, u32 *data2, u32 length2, u32 *dest, u32 *lenout, u32 maxlen)
{
    u64 carry;
    u32 i;
    u32 *longerSrc;
    u32 longerLen;
    u32 shorterLen;

    i = 0;
    carry = 0;
    func_0217D3AC(3);
    if (maxlen < length1 || maxlen < length2)
        return 0;

    if (length1 < length2) {
        shorterLen = length1;
        longerSrc = data2;
        longerLen = length2;
    } else {
        shorterLen = length2;
        longerLen = length1;
        longerSrc = data1;
    }

    for (; i < shorterLen; i++) {
        carry = (u64)data1[i] + data2[i] + carry;
        dest[i] = (u32)carry;
        carry >>= 32;
    }
    while (carry != 0 && i < longerLen) {
        carry = carry + longerSrc[i];
        dest[i] = (u32)carry;
        carry >>= 32;
        i++;
    }
    if (carry != 0) {
        if (maxlen <= i)
            return 0;
        dest[i] = (u32)carry;
        carry = 0;
        i++;
    }
    if (i < longerLen) {
        if (&dest[i] != &longerSrc[i])
            func_02092344(&dest[i], &longerSrc[i], (longerLen - i) * 4);
        i = longerLen;
    }
    *lenout = i;
    gsiLargeIntTimerExit(3);
    return carry == 0;
}






/*
 * sdk:      gsiLargeIntSub (libdwcgscommon.TWL.HYB.a(gslargeint.o))
 */
int gsiLargeIntSub(u32 *src1, u32 length1, u32 *src2, u32 length2, u32 *dest, u32 *lenout)
{
    u64 borrow = 0;
    u32 i;
    u32 shorter = (length1 < length2) ? length1 : length2;
    i = 0;

    func_0217D3AC(4);
    for (; i < shorter; i++) {
        borrow = (u64)src2[i] - src1[i] - borrow;
        dest[i] = (u32)borrow;
        borrow = (borrow >> 63);
    }
    for (; i < length2; i++) {
        borrow = (u64)src2[i] - borrow;
        dest[i] = (u32)borrow;
        borrow = (borrow >> 63);
    }
    if (borrow != 0) {
        gsiLargeIntTimerExit(4);
        return 0;
    }
    for (; i < length1; i++) {
        if (src1[i] != 0) {
            gsiLargeIntTimerExit(4);
            return 0;
        }
    }
    *lenout = length2;
    gsiLargeIntTimerExit(4);
    return 1;
}





/*
 * sdk:      gsiLargeIntMult (gslargeint.o)
 */
static int gsiLargeIntMult(unsigned int *data1, unsigned int length1,
                         unsigned int *data2, unsigned int length2,
                         unsigned int *dest, unsigned int *lenout,
                         unsigned int maxlen)
{
    unsigned int i = 0;
    unsigned int k = 0;
    gsLargeInt_t temp = {0};
    unsigned long long carry;
    unsigned int digit;

    *lenout = 0;
    func_0217D3AC(0);

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





/*
 * sdk:      gsLargeIntDiv (gslargeint.o)
 */
gsi_bool func_0217D8E0(const gsLargeInt_t *src1, const gsLargeInt_t *divisor, gsLargeInt_t *dest, gsLargeInt_t *remainder)
{
    return func_0217D904((unsigned int *)src1->mData, src1->mLength, (gsLargeInt_t *)divisor, dest, remainder);
}





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
            if (gsiLargeIntSubDivide(&scopy[readIndex], (unsigned int)readLength, (unsigned int *)divisorData, divisorLen, (unsigned int)divisorHighBit, &quotientTemp) == 0) {
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





/*
 * sdk:      gsiLargeIntSubDivide (gslargeint.o)
 *
 * Note: DWARF lists five parameters, but the image reads quotient from the
 * sixth argument slot ([sp,#0x24c]); the caller gsiLargeIntDiv passes an
 * extra int before it. The unused int parameter reproduces that slot.
 * quotientCopy is zeroed after the division, so it is declared in an inner
 * block (C99) after the division.
 */
static int gsiLargeIntSubDivide(unsigned int *src, unsigned int length,
                         unsigned int *divisor, unsigned int dlen,
                         int divisorHighBit, unsigned int *quotient)
{
    gsLargeInt_t temp;
    unsigned long long aboveBits;

    func_0217D3AC(6);

    if (length <= dlen)
        aboveBits = src[length - 1];
    else
        aboveBits = ((unsigned long long)src[length - 1] << 32)
                  | (src[length - 2] & divisor[dlen - 1]);
    aboveBits /= divisor[dlen - 1];

    {
    gsLargeInt_t quotientCopy = {0};

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





/*
 * The six-instruction prologue residue (`squareLen = 0` stored at [sp,#0x14])
 * is fixed by declaring the input `lint` parameter const: the front end then
 * keeps the whole prologue group in the image's order instead of sinking the
 * squareLen store to the frame setup.
 *
 * sdk:      gsLargeIntSquareMod (gslargeint.o)
 */
int func_0217DE94(const gsLargeInt_t *lint, gsLargeInt_t *mod,
                  gsLargeInt_t *dest)
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
    gsiLargeIntAdd(otherSums, squareLen, squareSums, squareLen, squareSums, &squareLen, 128);
    result = func_0217D904(squareSums, squareLen, mod, 0, dest);
    gsiLargeIntTimerExit(7);
    return result;
    }
}




int gsLargeIntPowerMod(gsLargeInt_t *b, gsLargeInt_t *p,
                       gsLargeInt_t *m, gsLargeInt_t *dest)
{
    int i = 0;
    gsi_u32 digitNum = 0;
    gsi_u32 digitBit = 0;

    l_word modPrime;

    gsi_u32 expHighBit;

    gsLargeInt_t R;
    gsLargeInt_t Rmod;
    gsLargeInt_t R2mod;
    gsLargeInt_t temp;
    gsLargeInt_t xwiggle;

    gsLargeInt_t base;
    gsLargeInt_t power;
    gsLargeInt_t mod;

    gsiLargeIntTimerEnter(8);

    memset(&R, 0, sizeof(R));
    memset(&Rmod, 0, sizeof(Rmod));
    memset(&R2mod, 0, sizeof(R2mod));
    memset(&temp, 0, sizeof(temp));
    memset(&xwiggle, 0, sizeof(xwiggle));

    memcpy(&base, b, sizeof(base));
    memcpy(&power, p, sizeof(power));
    memcpy(&mod, m, sizeof(mod));

    gsiLargeIntStripLeadingZeroes(&base);
    gsiLargeIntStripLeadingZeroes(&power);
    gsiLargeIntStripLeadingZeroes(&mod);

    if (mod.mLength == 0) {
        dest->mLength = 0;
        gsiLargeIntTimerExit(8);
        return 0;
    } else if (mod.mLength == 1 && mod.mData[0] == 1) {
        dest->mLength = 0;
        dest->mData[0] = 0;
        gsiLargeIntTimerExit(8);
        return 1;
    } else if (power.mLength == 0) {
        dest->mLength = 1;
        dest->mData[0] = 1;
        gsiLargeIntTimerExit(8);
        return 1;
    } else if ((mod.mData[0] & 1) == 0) {
        dest->mLength = 0;
        dest->mData[0] = 0;
        gsiLargeIntTimerExit(8);
        return 0;
    }
    if (gsiLargeIntCompare(base.mData, base.mLength, mod.mData, mod.mLength) != -1)
        gsLargeIntDiv(&base, &mod, 0, &base);
    if (base.mLength == 0) {
        dest->mLength = 0;
        dest->mData[0] = 0;
        gsiLargeIntTimerExit(8);
        return 1;
    }

    expHighBit = 32;
    while (((1 << (expHighBit - 1)) & power.mData[power.mLength - 1]) == 0)
        expHighBit--;
    expHighBit += (power.mLength - 1) * 32;

    memset(&R, 0, sizeof(R));
    R.mLength = mod.mLength + 1;
    if (R.mLength > 64)
        return 0;
    R.mData[R.mLength - 1] = 1;

    gsiLargeIntInverseMod(&mod, &modPrime);

    if (gsLargeIntDiv(&R, &mod, 0, &Rmod) == 0) {
        gsiLargeIntTimerExit(8);
        return 0;
    }
    if (gsLargeIntSquareMod(&Rmod, &mod, &R2mod) == 0) {
        gsiLargeIntTimerExit(8);
        return 0;
    }
    if (gsiLargeIntMultM(&base, &R2mod, &mod, modPrime, &xwiggle) == 0) {
        gsiLargeIntTimerExit(8);
        return 0;
    }

    memcpy(dest, &Rmod, sizeof(gsLargeInt_t));
    for (i = (int)(expHighBit - 1); i >= 0; i--) {
        gsiLargeIntMultM(dest, dest, &mod, modPrime, dest);
        digitNum = (gsi_u32)i / 32;
        digitBit = (gsi_u32)i % 32;
        {
            l_word digit = power.mData[digitNum];
            l_word mask = 1 << digitBit;
            l_word masked = digit & mask;

            if (mask == masked)
                gsiLargeIntMultM(dest, &xwiggle, &mod, modPrime, dest);
        }
    }

    temp.mLength = 1;
    temp.mData[0] = 1;
    gsiLargeIntMultM(dest, &temp, &mod, modPrime, dest);

    gsiLargeIntTimerExit(8);
    return 1;
}



/*
 * 2026-10-01: closed. The carry is propagated as `carry >> 32` (upstream
 *   gsLargeInt style): the inner sum adds `(unsigned int)(carry >> 32)`, the
 *   tail loop tests `(carry >> 32) != 0` and computes
 *   `carry = (u64)*tiptr + (unsigned int)(carry >> 32)`, and the final store is
 *   `*tiptr = (unsigned int)(carry >> 32)`. That fixed the {r7,r8,sb,sl}
 *   rotation. `carry = 0` comes before `mi`, and the inner loop sits under an
 *   explicit `if (nptr <= lastnptr)` guard (the image's `cmp; ...; cmpls`
 *   double test). `const` on the modulus parameter stays (wave 8 lever).
 *
 * notes: the image zeroes temp with an inline stm loop: __builtin__clear gives
 *   exactly that (memset is a call under every dsi build). The memcpy source
 *   is spelled (unsigned int *)temp + logB_r: &temp[logB_r] lets mwcc reuse
 *   the Compare pointer, which the image does not.
 */
int func_0217E504(gsLargeInt_t *x, gsLargeInt_t *y,
                  const gsLargeInt_t *m, unsigned int modPrime,
                  gsLargeInt_t *dest)
{
    unsigned int logB_r = m->mLength;
    unsigned int tempLen = 0;
    unsigned int temp[128] = {0};
    unsigned int *lasttnptr;
    const unsigned int *lastnptr;
    unsigned int *tptr;
    const unsigned int *nptr;
    unsigned int *tiptr;
    unsigned long long carry;
    unsigned int mi;

    if (!gsiLargeIntMult(x->mData, x->mLength, y->mData, y->mLength, temp, &tempLen, 128))
        return 0;

    lasttnptr = &temp[m->mLength - 1];
    lastnptr = &m->mData[m->mLength - 1];

    if (tempLen < m->mLength * 2) {
        memset(&temp[tempLen], 0, (m->mLength * 2 - tempLen) * 4);
        tempLen = m->mLength * 2;
    }

    for (tptr = temp; tptr <= lasttnptr; tptr++) {
        carry = 0;
        mi = (unsigned int)((unsigned long long)modPrime * *tptr);
        tiptr = tptr;
        nptr = m->mData;
        if (nptr <= lastnptr) {
            for (; nptr <= lastnptr; nptr++) {
                carry = (unsigned long long)mi * *nptr + *tiptr + (unsigned int)(carry >> 32);
                *tiptr++ = (unsigned int)carry;
            }
        }
        while ((carry >> 32) != 0 && tiptr <= &temp[tempLen - 1]) {
            carry = (unsigned long long)*tiptr + (unsigned int)(carry >> 32);
            *tiptr++ = (unsigned int)carry;
        }
        if ((carry >> 32) != 0) {
            *tiptr = (unsigned int)(carry >> 32);
            tempLen++;
        }
    }

    tiptr = &temp[logB_r];
    if (gsiLargeIntCompare(tiptr, tempLen - logB_r, m->mData, m->mLength) != -1) {
        if (!gsiLargeIntSub((u32 *)m->mData, m->mLength, (u32 *)tiptr, tempLen - logB_r, dest->mData, &dest->mLength)) {
            __builtin__clear(temp, sizeof(temp));
            memset(dest, 0, sizeof(gsLargeInt_t));
            return 0;
        }
    } else {
        memset(dest, 0, sizeof(gsLargeInt_t));
        dest->mLength = m->mLength;
        memcpy(dest->mData, (unsigned int *)temp + logB_r, (tempLen - logB_r) * 4);
        __builtin__clear(temp, sizeof(temp));
    }
    return 1;
}




/*
 * sdk:      gsiLargeIntInverseMod (gslargeint.o)
 */
int gsiLargeIntInverseMod(gsLargeInt_t *mod, unsigned int *dest)
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



/*
 * sdk:      gsLargeIntSetFromHexString (gslargeint.o)
 */
int gsLargeIntSetFromHexString(gsLargeInt_t *lint, char *hexstream)
{
    unsigned int *writePos = lint->mData;
    unsigned int temp;
    unsigned int len;
    int byteIndex = 0;
    unsigned int n;

    len = func_0209477C((const u8 *)hexstream);
    if (len == 0) {
        lint->mLength = 0;
        lint->mData[0] = 0;
        return 1;
    }
    if (len / 2 > 256)
        return 0;
    lint->mLength = (len + 7) / 8;
    lint->mData[lint->mLength - 1] = 0;
    while (len != 0) {
        if (len >= 2)
            func_0208CF34(hexstream + len - 2, g_021A3720, &temp);
        else
            func_0208CF34(hexstream + len - 1, g_021A3728, &temp);
        if (byteIndex == 0)
            *writePos = 0;
        *writePos |= temp << (8 * byteIndex);
        byteIndex++;
        if (byteIndex == 4) {
            byteIndex = 0;
            writePos++;
        }
        n = 2;
        if (len <= 2)
            n = len;
        len -= n;
    }
    return 1;
}


/*
 * Reverses the n*4-byte payload that follows the count word, in place.
 */
int func_0217E934(char *p)
{
    int n = *(int *)p;
    char *a = p + 4;
    char *b = a + n * 4 - 1;

    if (n == 0) return 1;
    while (a < b) {
        char t = *a;

        *a++ = *b;
        *b-- = t;
    }
    return 1;
}



void gsLargeIntAddToMD5(gsLargeInt_t * _lint, struct GSMD5_CTX * md5)
{
    gsLargeInt_t lint;
    int byteLength;
    unsigned char * dataStart;

    memcpy(&lint, _lint, sizeof(lint));
    byteLength = gsLargeIntGetByteLength(&lint);
    if (byteLength == 0)
        return;

    dataStart = (unsigned char *)&lint.mData;
    if (byteLength & 3)
        dataStart += 4 - (byteLength & 3);

    gsLargeIntReverseBytes(&lint);
    GSMD5Update(md5, dataStart, byteLength);
    gsLargeIntReverseBytes(&lint);
}



unsigned int gsLargeIntGetByteLength(gsLargeInt_t * lint)
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

void *gsiMemoryMalloc(unsigned long size)
{
    return func_020913D0(size);
}

void gsiMemoryFree(void *p)
{
    func_020913E8(p);
}

void *gsiMemoryRealloc(unsigned long block, unsigned long size)
{
    return func_020913FC(block, size);
}
