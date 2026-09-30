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
 * blocker:  front-end register allocation, not source shape. 1.1p1 resolves the
 *      4->5 argument rotation (incoming divisor r1, dest r2, remainder r3 ->
 *      outgoing r2, r3, [sp]) with ONE scratch: str r3,[sp] first frees r3, so
 *      dest goes straight to r3 and only divisor needs ip (mov ip,r1; mov r3,r2;
 *      ldr r1,[r0],#4; mov r2,ip). The vendor parks BOTH incoming pointers first
 *      (mov lr,r1; mov ip,r2; str r3,[sp]; ...; mov r2,lr; mov r3,ip) and pays
 *      one extra mov. The same object does emit the lr park when an earlier
 *      computation keeps the incoming args live across it (WCMi_Notify,
 *      src/matched/ov_sdk/ov009_func_021659B4.c); here the only earlier work is
 *      the len load, which schedules after the stack store. Vendor one-liner and
 *      all spellings tried (w2/w4/w6/w7/w9/u31, const/locals/casts/order here)
 *      give 32 B.
 * u21: the defining object gslargeint.o is .comment 4.0.0.1025, a stamp no local build writes.
 *      Object listing (tools/sdkobj.py) = the image instruction for instruction, including the
 *      DWARF parameter registers (src1 r0, divisor r14, dest r12): the vendor keeps the divisor in
 *      lr and copies dest to ip (mov lr,r1 / mov ip,r2 / mov r2,lr / mov r3,ip) and pays one extra
 *      instruction for it (36 vs 32). 1.1p1 copies dest straight to r3 and parks the divisor in
 *      ip, which is the whole 17-byte diff. First divergence +0004 image `mov lr, r1` |
 *      ours `str r3, [sp]`. ../2.0/base and ../2.0/sp1p2 both 32 B / 17 B.
 * u1: family check done - ../2.0/base and ../2.0/sp1p2 give the identical 32 B / 17 B; ../1.2/sp3 44 B. Residue stands: the vendor's 4-move lr/ip argument shuffle before the len load.
 *
 * near miss (w2_s1): 17 bytes differ (36 vs 32); four argument-evaluation forms with local temporaries tried, all compile to the same 8-instruction body without the lr/ip shuffle.
 *
 * w9_nm: not moved: the parameter DWARF says divisor lives in r14 and dest in r12 (a vendor register shuffle). No new spelling tried beyond w4 to w7; the wall is the parallel-move order (mov lr,r1 / mov ip,r2 before the stack store).
 *
 * u31: the vendor one-liner from gslargeint.c (callee named gsiLargeIntDiv as the
 * object labels it, the object's own non-const signatures) compiles byte-for-byte
 * to the parked draft: 32 B / 17 B. So do locals in either order, &src1->mData[0],
 * a `const` src1, and a length-only local. The image's extra `mov lr, r1` (its
 * argument move sequencer saves both r1 and r2 before the length load) is a
 * 4.0.0.1025 codegen artefact; ../2.0/* builds agree with 1.1p1 at 32 B.
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
