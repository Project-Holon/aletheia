/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005430
 * packet:   pkt_020051D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GFL_USE_DoVramTransfer
 *
 * symbols:
 *   NNS_GfdDoVramTransfer  0x02061C44  arm
 *
 * One eight byte tail call, the shape
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes: a pool word and a
 * `bx`, no prologue, no argument set up.  sub_02005230 calls it as the first
 * half of its two step init.
 *
 * The range is one function wide because of its neighbours rather than
 * because of itself.  Immediately before it is the linker veneer at
 * 0x02005428, which is not compiled code at all and cannot be inside any
 * unit.  Immediately after it, sub_02005438 is the same eight byte shape
 * around CTRDG_DummyInit at 0x020911A0, and the only word in the image that
 * holds 0x020911A0 is that function's own pool word, so the `literal` class
 * discards its only witness and no cut can help.  See the near miss register
 * in the header of src/matched/unit_020056A0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02005430.c \
 *       --addr 0x02005430 --thumb
 */

/* ARM, and attested by a branch to it from an overlay. */
extern void NNS_GfdDoVramTransfer(void);

void GFL_USE_DoVramTransfer(void)
{
    NNS_GfdDoVramTransfer();
}
