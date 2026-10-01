/*
 * function: func_0217E504
 * address:  0x0217E504
 * packet:   pkt_ov009_0217E504
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * status:   DIFF.  704/704, 107 concrete bytes.  The prologue, Mult call,
 *           memset of the tail, Montgomery loop entry and the whole
 *           Compare/Sub/memcpy/clear epilogue are now byte-identical.  The
 *           residue is a register rotation inside the Montgomery inner loop.
 *
 * blocker:  the 64-bit multiply-add in the inner loop.  Image colours
 *           mi=sb, carry-lo=sl, tiptr=r7, zero=r8; this build colours
 *           mi=sl, carry-lo=r7, tiptr=r8, zero=sb -- a cyclic rotation of
 *           exactly {r7,r8,sb,sl}.  Same opcodes, same schedule, same
 *           instruction count; only the four-register assignment differs.  It
 *           is an allocator tie (see the new idiom
 *           `const-on-a-readonly-struct-parameter-recolours-the-register-set`),
 *           not a body shape.
 *
 * WHAT FIXED 149 -> 107 (WAVE8): `const` on the modulus parameter.  Upstream
 *           `gsiLargeIntMultM` declares `const gsLargeInt_t *mod`, and the
 *           vendor object was built from that source.  Making `m` const (and
 *           `func_0217D640`'s `src1`/`src2` and `lastnptr`/`nptr` const to
 *           accept it) recolours the parameter SET: the prologue now homes
 *           y=r5, m=r4, x=r7, temp=r8 exactly as the image, and everything
 *           through +00E4 matches.  This overturns the earlier "the register
 *           SET cannot be forced" claim for the *prologue*; it CAN, and the
 *           lever is `const` on the read-only struct parameter.
 *
 * REMAINING 107 (tried, inert): statement order in the inner loop
 *           (`tiptr = tptr;` before/after `carry = 0;` -> 107/108); `mi` as
 *           `unsigned long long`, `const unsigned int`, declared at function
 *           top or inside the outer loop, or as an initialiser; operand order
 *           `mi**nptr + *tiptr`, `*tiptr + mi**nptr`, `prod` local; `const`
 *           `modPrime`; `temp[128]` declared last; `const` x and/or y (all
 *           worse: 124/159).  The 107 is the inner-loop rotation alone.
 *
 * sdk:      gsiLargeIntMultM (gslargeint.o)
 *
 * notes: the image zeroes temp with an inline stm loop: __builtin__clear gives
 *   exactly that (memset is a call under every dsi build). The memcpy source
 *   is spelled (unsigned int *)temp + logB_r: &temp[logB_r] lets mwcc reuse
 *   the Compare pointer, which the image does not.
 *
 * symbols:
 *   func_0217D750                  0x0217D750  arm  ov009
 *   func_0217D448                  0x0217D448  arm  ov009
 *   func_0217D640                  0x0217D640  arm  ov009
 *   memset                         0x020923B0  arm
 *   memcpy                         0x02092344  arm
 */

struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
};

extern int func_0217D750(const unsigned int *data1, unsigned int length1,
                         const unsigned int *data2, unsigned int length2,
                         unsigned int *dest, unsigned int *lenout,
                         unsigned int maxlen);
extern int func_0217D448(const unsigned int *a, unsigned int n,
                         const unsigned int *b, unsigned int m);
extern int func_0217D640(const unsigned int *src1, unsigned int length1,
                         const unsigned int *src2, unsigned int length2,
                         unsigned int *dest, unsigned int *lenout);
extern void *memset(void *d, int c, unsigned int n);
extern void *memcpy(void *d, const void *s, unsigned int n);

int func_0217E504(struct gsLargeInt_s *x, struct gsLargeInt_s *y,
                  const struct gsLargeInt_s *m, unsigned int modPrime,
                  struct gsLargeInt_s *dest)
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

    if (!func_0217D750(x->mData, x->mLength, y->mData, y->mLength, temp, &tempLen, 128))
        return 0;

    lasttnptr = &temp[m->mLength - 1];
    lastnptr = &m->mData[m->mLength - 1];

    if (tempLen < m->mLength * 2) {
        memset(&temp[tempLen], 0, (m->mLength * 2 - tempLen) * 4);
        tempLen = m->mLength * 2;
    }

    for (tptr = temp; tptr <= lasttnptr; tptr++) {
        mi = (unsigned int)((unsigned long long)modPrime * *tptr);
        tiptr = tptr;
        carry = 0;
        for (nptr = m->mData; nptr <= lastnptr; nptr++) {
            carry = (unsigned long long)mi * *nptr + *tiptr + (carry >> 32);
            *tiptr++ = (unsigned int)carry;
        }
        carry >>= 32;
        while (carry != 0 && tiptr <= &temp[tempLen - 1]) {
            carry += *tiptr;
            *tiptr++ = (unsigned int)carry;
            carry >>= 32;
        }
        if (carry != 0) {
            *tiptr = (unsigned int)carry;
            tempLen++;
        }
    }

    tiptr = &temp[logB_r];
    if (func_0217D448(tiptr, tempLen - logB_r, m->mData, m->mLength) != -1) {
        if (!func_0217D640(m->mData, m->mLength, tiptr, tempLen - logB_r,
                           dest->mData, &dest->mLength)) {
            __builtin__clear(temp, sizeof(temp));
            memset(dest, 0, sizeof(struct gsLargeInt_s));
            return 0;
        }
    } else {
        memset(dest, 0, sizeof(struct gsLargeInt_s));
        dest->mLength = m->mLength;
        memcpy(dest->mData, (unsigned int *)temp + logB_r, (tempLen - logB_r) * 4);
        __builtin__clear(temp, sizeof(temp));
    }
    return 1;
}
