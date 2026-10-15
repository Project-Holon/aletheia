/*
 * function: NNS_SndBoot
 * address:  0x02072758
 * packet:   pkt_02071DD4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Not a member of the 0x02071CDC constructor family: the subsystem's boot
 * sequence. Spins until SND_RecvCommandReply(0) reports ready, runs the three
 * initialisers, then hands 0 to func_02089B38.
 *
 * PINNED ../2.0/sp2 on the "kept constants" tell (docs/FRONTEND-PINS.md).
 * The image rematerialises the last call's zero argument, `mov r0, #0`
 * (`00 00 a0 e3`) at 0x0207277C, although the spin loop is still holding a
 * zero live in the callee-saved r4 it set up at 0x0207275C; dsi/1.1p1 -O4,p
 * reuses it and emits `mov r0, r4` (`04 00 a0 e1`) instead, the same 48
 * bytes with exactly those 2 concrete bytes out. Five spellings measured in
 * docs/notes/pkt_02071DD4.c.txt (a `z` local, a bare literal 0, a
 * `for (z = 0; ...)` head, passing the same `z` to the last call, and the
 * truthiness form `while (f(0))`) all share the constant. Under the pin the
 * same C is 48 bytes, 0 mismatches: BYTE-CORRECT, and the 2-byte codegen
 * difference is gone.
 *
 * CAPPED AT MATCH for lack of an outside witness, not for codegen. Three of
 * the five PC24 sites (NNS_SndPlayerMain, NNS_SndMain, NNSi_SndArcPlayerUpdate) have no
 * branch anywhere in the image outside this function's own 48 bytes, and
 * nothing under src/matched/ reproduces the ranges that define them, so the
 * `label` and `matched` classes both refuse. There is nothing to split: this
 * is one function, and it is the sole caller of all three. It promotes to
 * EXACT unchanged the moment any one of 0x020731E0, 0x02073D7C, 0x02075858
 * is filed EXACT elsewhere, or a second caller of one is decompiled.
 *
 * symbols:
 *   SND_RecvCommandReply  0x02089978  arm
 *   NNS_SndPlayerMain  0x020731E0  arm
 *   NNS_SndMain  0x02073D7C  arm
 *   NNSi_SndArcPlayerUpdate  0x02075858  arm
 *   func_02089B38  0x02089B38  arm
  *
 * 2026-09-21, unblock lane: ONE OF THE THREE BLOCKING SITES IS NOW CLEARED.
 * NNS_SndPlayerMain (the +0x18 site) was promoted to src/matched/ this pass and
 * resolves `matched x1`; the file is now MATCH* with 3 of 5 relocations
 * resolved.  The two that remain are +0x1C (NNS_SndMain, 128 bytes at
 * 0x02073D7C) and +0x20 (NNSi_SndArcPlayerUpdate, 272 bytes at 0x02075858), neither of
 * which has any branch outside this function's own bytes.  Both must be
 * written and filed EXACT in their own right -- there is no second caller to
 * find for either -- and then this file promotes with no change to the C.
 * Verify it with `--cc ../2.0/sp2 --arm`, not the default 1.1p1.
*/
typedef int s32;

typedef unsigned int   u32;
struct SNDCommand;
extern const struct SNDCommand *SND_RecvCommandReply(u32 flags);
extern void NNS_SndPlayerMain(void);
extern void NNS_SndMain(void);
extern void NNSi_SndArcPlayerUpdate(void);
extern void func_02089B38(s32 a);

void NNS_SndBoot(void)
{
    while (SND_RecvCommandReply(0) != 0)
        ;

    NNS_SndPlayerMain();
    NNS_SndMain();
    NNSi_SndArcPlayerUpdate();
    func_02089B38(0);
}
