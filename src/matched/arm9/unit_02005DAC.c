/*
 * One function of a translation unit, matched as a byte range.  Written
 * from the disassembly in asm/arm9/src/000_02004000.s.
 *
 * It is recorded as a unit rather than as a single function because its
 * section is 54 bytes and the next function starts at 0x02005DE4, so the
 * extent disasm.py infers for it runs two bytes long over the linker's
 * `00 00` fill and a per-function entry would read EXACT*.  The byte range
 * comparison is over the 54 bytes the section actually occupies.
 *
 * unit:     yes
 * address:  0x02005DAC
 * packet:   pkt_02005DAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GFL_USE_PlayFanfare
 *
 * symbols:
 *   GFL_USE_LoadBgmData   0x02005924  thumb
 *   GFL_USE_GetCurrentSndHandle   0x0200590C  thumb
 *   GFL_USE_IsSeqStartAllowed   0x02005CE0  thumb
 *   GFL_USE_StopBgm   0x02005D14  thumb
 *   GFL_USE_CancelBgmChange   0x02005F90  thumb
 *   NNS_SndArcPlayerStartSeqEx  0x020755A8  arm
 *
 * Two guarded steps of a wireless session teardown, each abandoning the
 * function when its predicate comes back zero, and a five argument call
 * whose fifth argument goes on the stack.
 *
 * The detail worth recording is the two -1 arguments.  The original builds
 * them as
 *
 *   movs r1, #6
 *   subs r2, r1, #7
 *   adds r3, r2, #0
 *
 * that is, it derives -1 from the 6 it has just materialised for the
 * previous argument rather than spending a `movs`/`mvns` pair on it.  That
 * is a peephole on two constants that happen to be live at the same time and
 * says nothing about the source, which is a plain call with the literals
 * written out.
 *
 * The near miss this header used to record ran 0x02005DE4 through
 * 0x02005E64 and is now mostly closed.  Three of the four calls involved
 * reach NNS_SndHandleMoveVolume, from 0x02005E16 and 0x02005E22 inside GFL_USE_FadeInBgm
 * and from 0x02005E40 inside GFL_USE_FadeOutBgm, so they are not short of evidence
 * at all: they are short of a cut.  Matched as one range all three witnesses
 * are inside the bytes under test; cut between the two functions, each file
 * is the other's witness.  That is src/matched/unit_02005DF8.c and
 * src/matched/unit_02005E30.c, both EXACT, and `python tools/match.py tu
 * --suggest-split` is what found the cut.  GFL_USE_IsBgmFading was already matched
 * on its own as src/matched/GFL_USE_IsBgmFading.c.
 *
 * GFL_USE_SetBgmPaused, 20 bytes, stays open, and no cut can help: it is the only
 * caller of 0x02072E8C anywhere in the 3.9 MB image, overlays included, so
 * the single witness for that call is the call itself.  It closes the day
 * the image acquires a second caller.  See "The honesty rule" in
 * docs/MATCHING.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_USE_PlayFanfare.c \
 *       --func GFL_USE_PlayFanfare --addr 0x02005DAC --cc 1.1p1 --thumb
 */

extern int GFL_USE_LoadBgmData(unsigned int a);
typedef unsigned int   u32;
extern u32 *GFL_USE_GetCurrentSndHandle(void);
extern int   GFL_USE_IsSeqStartAllowed(void *arg);
extern void  GFL_USE_StopBgm(void);
extern void  GFL_USE_CancelBgmChange(void);

extern u32 NNS_SndArcPlayerStartSeqEx(u32 obj, int a, int b, int c, u32 arg);

void GFL_USE_PlayFanfare(void *arg)
{
    GFL_USE_CancelBgmChange();
    if (GFL_USE_IsSeqStartAllowed(arg) == 0) {
        return;
    }
    GFL_USE_StopBgm();
    if (GFL_USE_LoadBgmData((unsigned int)arg) == 0) {
        return;
    }
    NNS_SndArcPlayerStartSeqEx((u32)GFL_USE_GetCurrentSndHandle(), 6, -1, -1, (u32)arg);
}
