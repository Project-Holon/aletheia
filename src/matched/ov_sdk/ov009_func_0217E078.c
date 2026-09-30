/*
 * function: gsLargeIntPowerMod
 * address:  0x0217E078
 * packet:   pkt_ov009_0217E078
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsLargeIntPowerMod (libdwcgscommon.TWL.HYB.a gslargeint.o)
 *
 * Montgomery modular exponentiation.  Filed from the vendor's own
 * gsLargeInt.c (the non-NEWEXP arm, upstream GameSpy), which supplies both
 * non-obvious spellings this row needed: the five zero-inits are literal
 * memset() calls on the local structs (they inline to the image's rolled
 * stm zero-fill loop only when memset is declared through a string.h-named
 * header), and the exponent-bit test computes its digit index and bit with
 * `(gsi_u32)i / 32` and `(gsi_u32)i % 32` so the front end emits the image's
 * `lsr r0, sb, #5` / `and r1, sb, #0x1f` instead of the signed divide
 * sequence.  R is zeroed twice, at entry with the other four and again just
 * before R.mLength = mod.mLength + 1, on the same stack slot.
 *
 * symbols:
 *   gsiLargeIntTimerEnter            0x0217D3AC arm
 *   memcpy                           0x02092344 arm
 *   gsiLargeIntStripLeadingZeroes    0x0217D4D8 arm
 *   gsiLargeIntTimerExit             0x0217D3F8 arm
 *   gsiLargeIntCompare               0x0217D448 arm
 *   gsLargeIntDiv                    0x0217D8E0 arm
 *   gsiLargeIntInverseMod            0x0217E7C4 arm
 *   gsLargeIntSquareMod              0x0217DE94 arm
 *   gsiLargeIntMultM                 0x0217E504 arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_0217E078.c \
 *     --func gsLargeIntPowerMod --addr 0x0217E078 --region ov009 --arm \
 *     --cc dsi/1.1p1 --lang c99
 */

#include "../../matched/arm9_sdk/libc/string.h"

typedef unsigned int l_word;
typedef unsigned int gsi_u32;
typedef int gsi_i32;

struct gsLargeInt_s {
    l_word mLength;
    l_word mData[64];
};

extern void gsiLargeIntTimerEnter(int id);
extern int gsiLargeIntStripLeadingZeroes(struct gsLargeInt_s *lint);
extern void gsiLargeIntTimerExit(int id);
extern gsi_i32 gsiLargeIntCompare(const l_word *data1, l_word len1,
                                  const l_word *data2, l_word len2);
extern int gsLargeIntDiv(struct gsLargeInt_s *src1, struct gsLargeInt_s *divisor,
                         struct gsLargeInt_s *dest, struct gsLargeInt_s *remainder);
extern int gsiLargeIntInverseMod(struct gsLargeInt_s *mod, l_word *dest);
extern int gsLargeIntSquareMod(struct gsLargeInt_s *lint, struct gsLargeInt_s *mod,
                               struct gsLargeInt_s *dest);
extern int gsiLargeIntMultM(struct gsLargeInt_s *x, struct gsLargeInt_s *y,
                            struct gsLargeInt_s *m, gsi_u32 modPrime,
                            struct gsLargeInt_s *dest);

int gsLargeIntPowerMod(struct gsLargeInt_s *b, struct gsLargeInt_s *p,
                       struct gsLargeInt_s *m, struct gsLargeInt_s *dest)
{
    int i = 0;
    gsi_u32 digitNum = 0;
    gsi_u32 digitBit = 0;

    l_word modPrime;

    gsi_u32 expHighBit;

    struct gsLargeInt_s R;
    struct gsLargeInt_s Rmod;
    struct gsLargeInt_s R2mod;
    struct gsLargeInt_s temp;
    struct gsLargeInt_s xwiggle;

    struct gsLargeInt_s base;
    struct gsLargeInt_s power;
    struct gsLargeInt_s mod;

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

    memcpy(dest, &Rmod, sizeof(struct gsLargeInt_s));
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
