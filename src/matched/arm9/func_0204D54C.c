/*
 * function: CLACT_ResetVramAnim
 * address:  0x0204D54C
 * packet:   pkt_0204D54C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * Tear the actor down and release the sub-object at +0x40: CLACT_ResetCellAnim on
 * the actor itself, then NNSi_G2dMCAnimUpdateBank on the tail.
 *
 * Both call sites resolve from `matched` witnesses, which is what this file
 * waited for while it sat parked in src/pending/ with both PC24s wildcarded.
 * The trailing star is the listing extent only: the next func_ label after
 * 0x0204D54C is 540 bytes away, so the harness compares the 32 bytes this
 * body compiles to and reports the disagreement rather than a concrete diff.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ResetVramAnim.c \
 *       --func CLACT_ResetVramAnim --addr 0x0204D54C --cc 1.1p1 --arm
 *
 * symbols:
 *   CLACT_ResetCellAnim  0x0204D52C  arm
 *   NNSi_G2dMCAnimUpdateBank  0x02064C10  arm
 */

typedef unsigned char u8;

extern void CLACT_ResetCellAnim(void *p);
struct Obj02064C10;
extern void NNSi_G2dMCAnimUpdateBank(struct Obj02064C10 *x);

void CLACT_ResetVramAnim(void *p)
{
    CLACT_ResetCellAnim(p);
    NNSi_G2dMCAnimUpdateBank((struct Obj02064C10 *)((u8 *)p + 0x40));
}
