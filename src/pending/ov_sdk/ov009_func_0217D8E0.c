/*
 * function: gsLargeIntDiv
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
 * codegen: SIZE 36 vs 32. Every byte is otherwise in place; the original
 * saves `divisor` in lr (DWARF: divisor r14) and `dest` in ip, then emits
 * `str r3,[sp]; ldr r1,[r0],#4; mov r2,lr; mov r3,ip`. 1.1p1 instead keeps
 * only ip as scratch and stores the 5th arg first, so it drops the extra
 * `mov lr,r1`. Not affected by declaration order, a local copy of any
 * argument, or a local src/len; this is an allocator/scheduling difference
 * of the object's 4.0.0.1025 toolchain, not a C-shape issue.
 *
 * symbols:
 *   gsiLargeIntDiv                   0x0217d904 arm
 */

struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
};

extern int gsiLargeIntDiv(unsigned int * src, unsigned int len, struct gsLargeInt_s * div, struct gsLargeInt_s * dest, struct gsLargeInt_s * remainder);

int gsLargeIntDiv(struct gsLargeInt_s * src1, struct gsLargeInt_s * divisor, struct gsLargeInt_s * dest, struct gsLargeInt_s * remainder)
{
    return gsiLargeIntDiv(src1->mData, src1->mLength, divisor, dest, remainder);
}
