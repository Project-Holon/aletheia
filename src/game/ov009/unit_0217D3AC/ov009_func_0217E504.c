/*
 * function: func_0217E504
 * address:  0x0217E504
 * packet:   pkt_ov009_0217E504
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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

extern int func_0217D750(unsigned int *data1, unsigned int length1, unsigned int *data2, unsigned int length2, unsigned int *dest, unsigned int *lenout, unsigned int maxlen);
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
