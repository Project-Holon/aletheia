# A real pointer parameter spilled so its twin can hold the higher callee-saved register is a front-end tie, not a source shape

summary: when two pointer parameters are both live across one loop and the
image homes them to `{lower-callee-saved, fp}` while our build homes the first
to `fp` and spills the second to a stack slot, the extra frame word and every
downstream temporary colour follow from which pointer the allocator keeps, and
no source spelling moves it. This is the genuine-spill sibling of
`a-dying-pointer-loads-scratch-colour-can-be-an-allocator-tie.md` (two dying
loads, no spill) and of
`a-vendor-front-end-homed-parameter-cannot-be-forced-by-source.md` (a
*redundant* live copy forced to a slot).

Found in: `src/pending/ov_sdk/ov172_func_021C1D8C.c` (0x021C1D8C, ov172,
`SSP_JpegEncoderResample`, libssp.TWL.HYB.a(jpegenc.o)), 376 B image / 388 B
ours.

The vendor DWARF states the homing outright: parameters `src r6`, `dst r11`
(`fp`); locals `fmt r5, yuyvBak r4, v r12(ip), u r3, y r0`. Ours homes `src`
to `fp` at `+0x10` (`mov fp, r0` where the image is `mov r6, r0`), so when
`dst` is needed across the first `_u32_div_f` call there is no callee-saved
register left and the allocator spills it (`str r3, [sp, #8]`, `sub sp,#0x1c`
vs `#0x18`). The spill is free in instruction count -- both frames total the
same 64 bytes, the image just pushes an extra filler `r3` -- but it drops the
inner-loop `y/u/v` temporaries into `r6/r7/lr` instead of the image's
`r0/r3/ip`, and from there the whole 230-byte body recolours.

Levers measured, each identical in size and byte count (388 B / 230 bytes):
`const` on the read-only `src`, `const` on `dst`, both; the reverse-DWARF
declaration order (and the forward one); a pointer-local copy `s = src; d =
dst;` declared in either order, which the coalescer propagates away; inlining
the row index so no `srcP`/`dstP` locals exist; a named `rowOfs` local for the
dst base. The eight declaration orders of lane U57 are the same result.

The practical rule: before spending a wave on a function whose first
divergence is `mov <reg>, rX` in the argument homing and whose frame differs by
one word, check whether the spilled value is a *recomputable copy* (then a
nonzero-offset alias can force the frame, per the refinement in the homed-
parameter idiom) or a *real live parameter* used through the body. If it is the
latter and every declaration/statement/qualifier permutation is inert, the
residue is the front end's allocator state; record the register set and park.
