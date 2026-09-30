# A vendor front end's homed parameter and live pointer copy cannot be forced by source

summary: When the vendor object was built by a front end the tree does not
have (Metrowerks 3.0.0.126), it can home an incoming parameter to a frame slot
and keep a redundant pointer copy live in a callee-saved register. Our nearest
front ends (`dsi/1.1p1`, `../2.0/sp1p2`) copy-propagate the redundant pointer
and leave the parameter in a register, so the frame and the spill never appear
and no source spelling recovers them. Park the row; do not re-derive the
spelling.

Found in: 0x021B9FE0 SetFrameData (libdwcutil.TWL.HYB.a(atermset.o), Thumb),
src/pending/ov_sdk/ov016_func_021B9FE0.c.

The vendor DWARF (`python tools/sdkobj.py SetFrameData --region ov016`) states
the object's allocation outright: `lpframe` r6, `size` r7, `dwsum` r5, `psum`
r4, and the parameter `id` homed at `[fb+4]`. The image is 196 B with a real
`sub sp, #8` frame; ours is 186 B with no frame. The object has **five** values
live across the `keywrap_encrypt`/`memcpy` call (lpframe, size, dwsum, the
`psum = lpframe` copy, and id), so `id` is spilled; ours has four because the
`psum` copy is rematerialised from `lpframe` after the call, so `id` stays in
r7.

Levers that all failed to raise the live count: declaring `psum` before the
`if` and advancing it after the call (one-step and two-step `+6` then `+size`),
spelling the copy through a separate `lpb` byte pointer, both declaration orders
of the six DWARF locals, and taking `lpframe` through `pfh`. Making `id`
`volatile` forces a home but overshoots to 202 B with a different prologue
(`push {r0-r3}` to spill the incoming register parameters). The copy is
recomputable from a value (`lpframe`) that stays live, so no C shape makes the
front end keep it. The same residue parks `scanFirst` (usbap.o); see
`docs/notes/vendor-debug-line-gives-statement-grouping.md` and
`docs/sessions/2026-09-29/reports/w5_s1.md`.
