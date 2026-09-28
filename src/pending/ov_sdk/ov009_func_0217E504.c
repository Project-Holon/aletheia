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
 * sdk:      gsiLargeIntMultM (gslargeint.o)
 *
 * notes: the prologue, Mult call, memset of the tail and the whole
 *   Compare/Sub/memcpy/clear epilogue line up (bar a 3-instruction Sub
 *   argument schedule). The residue is the Montgomery inner loop: the image
 *   colours tiptr r7, carry sl, mi sb, zero-hi r8, and keeps the post-loop
 *   carry in sl with hi in r3; ours gives r8, r7, sl, sb and copies the
 *   carry to r1 after the loop. Tried: carry += form, (u32)carry add,
 *   (carry >> 32) inside the propagation loop, while/for/comma loop forms.
 *   The image zeroes temp with an inline stm loop: __builtin__clear gives
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

extern int func_0217D750(unsigned int *data1, unsigned int length1,
                         unsigned int *data2, unsigned int length2,
                         unsigned int *dest, unsigned int *lenout,
                         unsigned int maxlen);
extern int func_0217D448(const unsigned int *a, unsigned int n,
                         const unsigned int *b, unsigned int m);
extern int func_0217D640(unsigned int *src1, unsigned int length1,
                         unsigned int *src2, unsigned int length2,
                         unsigned int *dest, unsigned int *lenout);
extern void *memset(void *d, int c, unsigned int n);
extern void *memcpy(void *d, const void *s, unsigned int n);

int func_0217E504(struct gsLargeInt_s *x, struct gsLargeInt_s *y,
                  struct gsLargeInt_s *m, unsigned int modPrime,
                  struct gsLargeInt_s *dest)
{
    unsigned int tempLen = 0;
    unsigned int temp[128] = {0};
    unsigned int *lasttnptr;
    unsigned int *lastnptr;
    unsigned int *tptr;
    unsigned int *nptr;
    unsigned int *tiptr;
    unsigned long long carry;
    unsigned int mi;
    unsigned int logB_r = m->mLength;

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
        carry = 0;
        tiptr = tptr;
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
