/*
 * function: gsLargeIntPowerMod
 * address:  0x0217E078
 * packet:   pkt_ov009_0217E078
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker: rewritten from the vendor listing, 11 aligned blocks, 1092 vs 1164 bytes.
 *          Recovered: TimerEnter(8) precedes the zero initialisers (so the eight
 *          0x104-byte structs live in an inner block), power == 0 stores 1 to both
 *          fields, the loop bit test is `(word & mask) == mask` with an unsigned
 *          word index, and power.mLength - 1 is a shared temporary.  Left: the object
 *          zero-initialises R twice (once with the other four at entry, again just
 *          before `R.mLength = mod.mLength + 1`, same stack slot); a shadowing inner
 *          R adds a ninth struct and moves the frame, and struct assignment from a
 *          compound literal compiles to memcpy loops.  The constants 1/0 are
 *          rematerialised in the object where this build keeps them in r4/r6.
 *
 * sdk:      gsLargeIntPowerMod (libdwcgscommon.TWL.HYB.a gslargeint.o)
 *
 * symbols:
 *   gsiLargeIntTimerEnter            0x0217D3AC arm
 *   func_02092344                    0x02092344 arm
 *   gsiLargeIntStripLeadingZeroes    0x0217D4D8 arm
 *   gsiLargeIntTimerExit             0x0217D3F8 arm
 *   gsiLargeIntCompare               0x0217D448 arm
 *   gsLargeIntDiv                    0x0217D8E0 arm
 *   gsiLargeIntInverseMod            0x0217E7C4 arm
 *   gsLargeIntSquareMod              0x0217DE94 arm
 *   gsiLargeIntMultM                 0x0217E504 arm
 */

struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
};

extern void gsiLargeIntTimerEnter(int id);
extern void func_02092344(void *dst, void *src, unsigned long size);
extern int gsiLargeIntStripLeadingZeroes(struct gsLargeInt_s *lint);
extern void gsiLargeIntTimerExit(int id);
extern int gsiLargeIntCompare(const unsigned int *data1, unsigned int len1,
                              const unsigned int *data2, unsigned int len2);
extern int gsLargeIntDiv(struct gsLargeInt_s *src1, struct gsLargeInt_s *divisor,
                         struct gsLargeInt_s *dest, struct gsLargeInt_s *remainder);
extern int gsiLargeIntInverseMod(struct gsLargeInt_s *mod, unsigned int *dest);
extern int gsLargeIntSquareMod(struct gsLargeInt_s *lint, struct gsLargeInt_s *mod,
                               struct gsLargeInt_s *dest);
extern int gsiLargeIntMultM(struct gsLargeInt_s *x, struct gsLargeInt_s *y,
                            struct gsLargeInt_s *m, unsigned int modPrime,
                            struct gsLargeInt_s *dest);

int gsLargeIntPowerMod(struct gsLargeInt_s *b, struct gsLargeInt_s *p,
                       struct gsLargeInt_s *m, struct gsLargeInt_s *dest)
{
    unsigned int mask;
    unsigned int expHighBit;
    unsigned int top;
    unsigned int modPrime;
    int i;

    gsiLargeIntTimerEnter(8);
    {
        struct gsLargeInt_s R = {0};
        struct gsLargeInt_s Rmod = {0};
        struct gsLargeInt_s R2mod = {0};
        struct gsLargeInt_s temp = {0};
        struct gsLargeInt_s xwiggle = {0};
        struct gsLargeInt_s base;
        struct gsLargeInt_s power;
        struct gsLargeInt_s mod;

        func_02092344(&base, b, sizeof(base));
        func_02092344(&power, p, sizeof(power));
        func_02092344(&mod, m, sizeof(mod));

        gsiLargeIntStripLeadingZeroes(&base);
        gsiLargeIntStripLeadingZeroes(&power);
        gsiLargeIntStripLeadingZeroes(&mod);

        if (mod.mLength == 0) {
            dest->mLength = 0;
            gsiLargeIntTimerExit(8);
            return 0;
        }
        if (mod.mLength == 1 && mod.mData[0] == 1) {
            dest->mLength = 0;
            dest->mData[0] = 0;
            gsiLargeIntTimerExit(8);
            return 1;
        }
        if (power.mLength == 0) {
            dest->mLength = 1;
            dest->mData[0] = 1;
            gsiLargeIntTimerExit(8);
            return 1;
        }
        if ((mod.mData[0] & 1) == 0) {
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

        top = power.mLength - 1;
        expHighBit = 0x20;
        while (!(power.mData[top] & (1u << (expHighBit - 1))))
            expHighBit--;
        expHighBit += top << 5;

        R.mLength = mod.mLength + 1;
        if (R.mLength > 0x40)
            return 0;
        R.mData[mod.mLength] = 1;

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

        func_02092344(dest, &Rmod, sizeof(*dest));

        for (i = expHighBit - 1; i >= 0; i--) {
            gsiLargeIntMultM(dest, dest, &mod, modPrime, dest);
            mask = 1u << (i & 0x1f);
            if ((power.mData[(unsigned int)i >> 5] & mask) == mask)
                gsiLargeIntMultM(dest, &xwiggle, &mod, modPrime, dest);
        }

        temp.mLength = 1;
        temp.mData[0] = 1;
        gsiLargeIntMultM(dest, &temp, &mod, modPrime, dest);

        gsiLargeIntTimerExit(8);
        return 1;

    }
}
