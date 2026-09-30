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
 * u1: family check done - ../2.0/base and ../2.0/sp1p2 give the identical 32 B / 17 B; ../1.2/sp3 44 B. Residue stands: the vendor's 4-move lr/ip argument shuffle before the len load.
 *
 * near miss (w2_s1): 17 bytes differ (36 vs 32); four argument-evaluation forms with local temporaries tried, all compile to the same 8-instruction body without the lr/ip shuffle.
 *
 * w9_nm: not moved: the parameter DWARF says divisor lives in r14 and dest in r12 (a vendor register shuffle). No new spelling tried beyond w4 to w7; the wall is the parallel-move order (mov lr,r1 / mov ip,r2 before the stack store).
 *
 * sdk:      gsLargeIntDiv (gslargeint.o)
 *
 * near miss: gsLargeIntDiv: 36 vs 32 bytes. Original moves divisor to lr and dest to ip (`mov lr,r1; mov ip,r2; str r3,[sp]; ldr r1,[r0],#4; mov r2,lr; mov r3,ip`); 1.1p1 stores the 5th arg first and uses only ip. Callee 0x0217D904 (gsiLargeIntDiv) is also unmatched.
 *
 * w4_nm tried: direct call args, static callee prototype, casts, &mData[0], and
 * compilers dsi/1.1, 1.2, 1.2p1, 1.6sp2, 2.0/sp1p2: all give the same 17-byte diff
 * (no lr/ip parameter shuffle).
 *
 * w6_nm tried: the static callee declared and defined in the same TU (after
 * the caller): the lr/ip parameter shuffle does not appear.
 *
 * w7_nm tried: `*p++` split (p from the struct base, len = *p++), `++p` in
 *           the call, divisor/dest copied to locals first; cc 1.1 to 1.6sp2 with
 *           -O4,p/-O4,s/-O3,p/-O2: always 32 B without the lr/ip copies.
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
    unsigned int *p = src1->mData;
    unsigned int len = src1->mLength;
    return func_0217D904(p, len, divisor, dest, remainder);
}
