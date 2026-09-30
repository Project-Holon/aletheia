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
 * status:   DIFF.  Now 704/704, 149 concrete bytes (was 184).  The defining
 *           vendor object is stamped 4.0.0.1025, which no tools/mwccarm build
 *           writes (sdkobj.py); dsi/1.1p1 (1024) is the closest.  The residue
 *           is the prologue register SET, not a body shape: the DWARF of the
 *           vendor object homes x=r7, y=r5, m=r4, temp=r8; 1024 picks y=r7,
 *           x=r8, temp=r6.  A declaration-order sweep is inert.
 *
 * RESIDUE (lane U34, re-confirmed): 704/704, 184 concrete bytes, then 149
 *           after the logB_r declaration reorder noted below (applied).  Tested
 *           this lane against the GameSpy upstream (scratch/U2/gs/.../gsLargeInt.c,
 *           gsiLargeIntMultM, NEWMULTM branch):
 *             - vendor body verbatim, `memset(temp, 0, sizeof(temp))`
 *               -> 636 bytes (memset is a CALL under 1.1p1; the image clears
 *               temp with an inline stm loop, so the source used `= {0}`).
 *             - vendor body + `temp[128] = {0}` + __builtin__clear
 *               -> 696 bytes / 455 (vendor's carry-propagation `for` is 8
 *               bytes short of the image's `while` form).
 *             - vendor statement order inside the loop (carry = 0 first)
 *               -> 704 / 184, inert.
 *             - `unsigned int logB_r = m->mLength;` moved to the FIRST
 *               declaration, before tempLen/temp -> 704 / 149.  This is
 *               progress: the image's order is logB_r (+0x28), tempLen=0
 *               (+0x38), temp clear (+0x44), which a `= {0}` on temp cannot
 *               give unless logB_r is declared first.
 *           Remaining 149: prologue homing order.  Image homes y (r5) then
 *           m (r4) then x (r7); this build homes m (r4) then y (r7) and puts
 *           x in r8 - a different register SET, not a rotation.  First
 * divergence: image `mov r5, r1` | ours `mov r4, r2`.
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
    unsigned int logB_r = m->mLength;
    unsigned int tempLen = 0;
    unsigned int temp[128] = {0};
    unsigned int *lasttnptr;
    unsigned int *lastnptr;
    unsigned int *tptr;
    unsigned int *nptr;
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
