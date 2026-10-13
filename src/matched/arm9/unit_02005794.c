/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005794
 * packet:   pkt_02005768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GFL_USE_MuteSound, GFL_USE_UnmuteSound, GFL_USE_SetSleepVolumeHooks
 *
 * symbols:
 *   func_02072788  0x02072788  arm
 *   func_0203508C    0x0203508C  arm
 *
 * Two twelve byte thunks that set the master volume to its two extremes, and
 * the function that hands both of them to func_0203508C as a pair of
 * callbacks.  48 bytes, three sections, three literal pools.
 *
 * This range was the near miss recorded in the header of
 * src/matched/unit_020057DC.c, and what closes it is the `veneer` attestation
 * class.  Both thunks tail call 0x02072788, and the bytes there are not a
 * function the analysis can see:
 *
 *   02072788  E59FC000   ldr ip, [pc, #0]
 *   0207278C  E12FFF1C   bx  ip
 *   02072790  0208970C   .word SND_SetMasterVolume
 *
 * a linker veneer.  It has no prologue, so disasm.py's sweep never fires on
 * it and the listing prints the twelve bytes as data; nothing in the image
 * branches to it, so the `label` class has nothing to offer; and the only two
 * words in the 3.9 MB image that hold its address are the two pool words
 * inside this very range, so the `literal` class discards both.  The stub
 * itself is the evidence: a fixed twelve byte encoding that loads a constant
 * into ip and branches to it, with the constant naming SND_SetMasterVolume in
 * layout/symbols_sdk.txt, read entirely from outside the compared range.  See
 * "The veneer class" in docs/MATCHING.md and
 * docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md.
 *
 * The extern is declared at the veneer's address rather than at
 * SND_SetMasterVolume's, because that is the address the pool word holds and
 * a matched file has to reproduce the word the linker wrote.  It is declared
 * `arm`, which is what a veneer body is, so the ABS32 resolves with the Thumb
 * bit clear and the `bx r3` lands in ARM state.
 *
 * The function at 0x020057C4 immediately after this range stays open and is
 * not part of this file: it is the only caller of 0x02035108 anywhere in the
 * image, so the one witness for that call is the call itself and no cut can
 * put it outside the range under test.  It also needs GFL_USE_MuteSound local, for
 * the pool word at 0x020057D8, which is why it cannot simply be given a range
 * of its own either.  `python tools/match.py tu --src ... --suggest-split`
 * reports both constraints.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02005794.c \
 *       --addr 0x02005794 --thumb
 */

typedef unsigned int u32;

/* The linker veneer in front of SND_SetMasterVolume; ARM. */
extern void func_02072788(u32 volume);

/* Registers a pair of callbacks.  ARM, and in another packet's territory. */
extern void func_0203508C(u32 a, u32 b, u32 c);

void GFL_USE_MuteSound(void);
void GFL_USE_UnmuteSound(void);

void GFL_USE_MuteSound(void)
{
    func_02072788(0);
}

void GFL_USE_UnmuteSound(void)
{
    func_02072788(0x7F);
}

void GFL_USE_SetSleepVolumeHooks(void)
{
    func_0203508C((u32)GFL_USE_MuteSound, (u32)GFL_USE_UnmuteSound, 0);
}
