/*
 * function: func_0217D8E0
 * address:  0x0217D8E0
 * packet:   pkt_ov009_0217D8E0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gsLargeIntDiv (gslargeint.o)
 *
 * near miss: gsLargeIntDiv: 36 vs 32 bytes. Original moves divisor to lr and dest to ip (`mov lr,r1; mov ip,r2; str r3,[sp]; ldr r1,[r0],#4; mov r2,lr; mov r3,ip`); 1.1p1 stores the 5th arg first and uses only ip. Callee 0x0217D904 (gsiLargeIntDiv) is also unmatched.
 *
 * symbols:
 *   func_0217D904                  0x0217D904  arm ov009
 */

struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
};

extern int func_0217D904(unsigned int *src, unsigned int len, struct gsLargeInt_s *div, struct gsLargeInt_s *dest, struct gsLargeInt_s *remainder);

int func_0217D8E0(struct gsLargeInt_s *src1, struct gsLargeInt_s *divisor, struct gsLargeInt_s *dest, struct gsLargeInt_s *remainder)
{
    return func_0217D904(src1->mData, src1->mLength, divisor, dest, remainder);
}