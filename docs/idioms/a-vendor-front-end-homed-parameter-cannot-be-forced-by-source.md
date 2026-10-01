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

## Refinement (wave 8): a nonzero-offset alias does force the frame

The frame can be recovered, if not the exact colouring, by adding a second
named pointer set **before** the branch and consumed **after** the call, with a
**nonzero** offset so it cannot copy-propagate into `lpframe`:

```c
psum = (unsigned short *)lpframe;
pend = (unsigned char *)psum + 6;   /* distinct SSA value, live across the call */
if (lpkey) { func_021BAC20(...); size += 8; } else { memcpy(...); }
pfh = (FRAMEHEADER *)lpframe;
memset(pfh, 0, 6);
...
pend = pend + size;
psum = (unsigned short *)pend;
```

That reaches the object's five live values and emits `sub sp,#8` with `id`
homed at `[sp,#4]` (192 B vs 196, 105 differing bytes). Writing
`pend = (unsigned char *)psum` with no offset copy-propagates away (184 B, no
frame) — and so does every offset-0 alias tried, including an
`unsigned long`-spelled one and a `volatile`-qualified one. The residual diff
is that the vendor's extra register holds `lpframe` itself (offset 0), so its
early move is `adds r4,r6,#0` and the `+6` lands in the end two adds, while
ours must carry `+6` in the live value (`adds r7,r5,#6`); that one offset
difference recolours the whole body. The missed coalesce is still the front
end's, but a distinct live pointer is the lever that gets the frame back.
